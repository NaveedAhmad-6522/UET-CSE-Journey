/*
 * Real-Time Object Detection, Tracking, and Speed Estimation
 * Using Arduino-Based Ultrasonic Radar System
 * with Bare-Metal ATmega328P Register Programming
 *
 * Hardware:
 *   HC-SR04 Trigger -> D10 (PB2)
 *   HC-SR04 Echo    -> D11 (PB3)
 *   SG90 Servo      -> D12 (PB4)
 *   UART TX         -> D1  (PD1)  [9600 baud to Processing GUI]
 *
 * Output format (compatible with Processing radar sketch):
 *   angle,distance.
 *   e.g.  45,32.
 */

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>

// ============================================================================
//  CONFIGURATION
// ============================================================================

#define BAUD_RATE           9600UL
#define UBRR_VALUE          ((F_CPU / (16UL * BAUD_RATE)) - 1)   // = 103

// Timer1 runs at F_CPU/8 = 2 MHz  ->  1 count = 0.5 us
// For 50 Hz servo PWM we need a 20 ms period:
//   TOP = (20000 us / 0.5 us) - 1 = 39999
#define SERVO_TIMER_TOP     39999

// SG90 pulse widths mapped to Timer1 counts (1 count = 0.5 us):
//   0 deg   = 1000 us = 2000 counts
//   180 deg = 2000 us = 4000 counts
#define SERVO_PULSE_0DEG    2000
#define SERVO_PULSE_180DEG  4000

// Sweep limits and step delay
#define SWEEP_MIN_ANGLE     15
#define SWEEP_MAX_ANGLE     165
#define SERVO_STEP_DELAY_MS 30      // ms to wait after each 1-degree move

// HC-SR04 valid echo range
#define ECHO_MIN_US         116UL   // ~2 cm
#define ECHO_MAX_US         23200UL // ~400 cm

// ============================================================================
//  SHARED STATE  (written by ISRs, read by main loop)
// ============================================================================

volatile uint32_t g_micros       = 0;     // incremented every 1 us by Timer0
volatile uint32_t g_echo_rise_us = 0;     // timestamp of echo rising edge
volatile uint32_t g_echo_fall_us = 0;     // timestamp of echo falling edge
volatile bool     g_echo_active  = false; // true while echo pin is HIGH
volatile bool     g_echo_ready   = false; // true when a full pulse is captured

// ============================================================================
//  INTERRUPT SERVICE ROUTINES
// ============================================================================

/*
 * Timer0 Compare Match A  —  fires every 1 us
 *
 * Timer0 is configured in CTC mode with prescaler /8 and OCR0A = 1.
 * At 16 MHz / 8 = 2 MHz clock, the counter ticks every 0.5 us.
 * With TOP = 1 the counter resets every 2 ticks = 1 us.
 * This gives us a software microsecond counter equivalent to Arduino's micros().
 */
ISR(TIMER0_COMPA_vect)
{
    g_micros++;
}

/*
 * Timer1 Overflow  —  fires at the START of every 20 ms servo PWM frame
 *
 * In Fast PWM Mode 14 (TOP = ICR1), the overflow flag sets when TCNT1
 * wraps from ICR1 back to 0.  We use this moment to drive the servo
 * signal pin HIGH, beginning the pulse.
 */
ISR(TIMER1_OVF_vect)
{
    PORTB |= (1 << PB4);   // servo signal HIGH — pulse begins
}

/*
 * Timer1 Compare Match A  —  fires when TCNT1 reaches OCR1A
 *
 * OCR1A holds the pulse-width value for the current servo angle.
 * When the counter reaches this value we drive the servo pin LOW,
 * ending the pulse.  The pin stays LOW for the rest of the 20 ms frame.
 */
ISR(TIMER1_COMPA_vect)
{
    PORTB &= ~(1 << PB4);  // servo signal LOW — pulse ends
}

/*
 * Pin Change Interrupt — Port B  (PCINT0_vect handles PB0..PB7)
 *
 * We have enabled only PCINT3 (PB3 = D11 = ECHO pin).
 * This ISR fires on both the rising edge (echo start) and the
 * falling edge (echo end).  We read PINB to determine which edge
 * just occurred, then record the current microsecond timestamp.
 *
 * The pulse duration (g_echo_fall_us - g_echo_rise_us) is later
 * converted to a distance in the main loop.
 */
ISR(PCINT0_vect)
{
    if (PINB & (1 << PB3))
    {
        // Rising edge: HC-SR04 began sending the echo
        g_echo_rise_us = g_micros;
        g_echo_active  = true;
        g_echo_ready   = false;
    }
    else if (g_echo_active)
    {
        // Falling edge: echo reception complete
        g_echo_fall_us = g_micros;
        g_echo_active  = false;
        g_echo_ready   = true;
    }
}

// ============================================================================
//  UART  (9600 8N1, TX only, bare register implementation)
// ============================================================================

static void uart_init(void)
{
    // Set baud rate registers
    // UBRR = F_CPU / (16 * baud) - 1 = 103 for 9600 baud @ 16 MHz
    UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
    UBRR0L = (uint8_t)(UBRR_VALUE);

    // UCSR0A: normal speed (U2X0 = 0), no multi-processor mode
    UCSR0A = 0x00;

    // UCSR0B: enable transmitter only
    UCSR0B = (1 << TXEN0);

    // UCSR0C: asynchronous UART, no parity, 1 stop bit, 8 data bits
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

// Block until the UART data register is empty, then send one byte
static void uart_transmit_byte(uint8_t byte)
{
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = byte;
}

// Transmit a uint16_t as decimal ASCII characters (no leading zeros)
static void uart_transmit_number(uint16_t value)
{
    char    digits[6];   // max 5 digits for uint16 + null terminator
    int8_t  index = 4;

    digits[5] = '\0';

    if (value == 0)
    {
        uart_transmit_byte('0');
        return;
    }

    while (value > 0 && index >= 0)
    {
        digits[index--] = '0' + (uint8_t)(value % 10);
        value /= 10;
    }

    // Send digits from first significant digit to index 4
    for (int8_t i = index + 1; i <= 4; i++)
        uart_transmit_byte((uint8_t)digits[i]);
}

// Send one radar data line:  "angle,distance.\r\n"
static void uart_send_radar_line(uint8_t angle, uint16_t distance_cm)
{
    uart_transmit_number(angle);
    uart_transmit_byte(',');
    uart_transmit_number(distance_cm);
    uart_transmit_byte('.');
    uart_transmit_byte('\r');
    uart_transmit_byte('\n');
}

// ============================================================================
//  MICROSECOND TIMER  (Timer0, replaces Arduino micros() and delay())
// ============================================================================

static void timer0_init(void)
{
    // CTC mode: TCNT0 counts 0, 1 then resets to 0 (TOP = OCR0A = 1)
    TCCR0A = (1 << WGM01);

    // TOP value: ISR fires every (OCR0A + 1) * prescaler / F_CPU seconds
    //   = 2 * 8 / 16000000 = 1 us
    OCR0A  = 1;

    // Clock select: prescaler /8
    TCCR0B = (1 << CS01);

    // Enable Output Compare Match A interrupt
    TIMSK0 = (1 << OCIE0A);
}

// Atomically read the 32-bit microsecond counter
static uint32_t micros_get(void)
{
    uint32_t value;
    cli();
    value = g_micros;
    sei();
    return value;
}

// Busy-wait for the requested number of microseconds
static void delay_microseconds(uint32_t us)
{
    uint32_t start = micros_get();
    while ((micros_get() - start) < us);
}

// Busy-wait for the requested number of milliseconds
static void delay_milliseconds(uint32_t ms)
{
    delay_microseconds(ms * 1000UL);
}

// ============================================================================
//  SERVO  (SG90, 50 Hz PWM via Timer1 Fast PWM Mode 14)
// ============================================================================

static void timer1_servo_init(void)
{
    // Fast PWM Mode 14: WGM13=1 WGM12=1 WGM11=1 WGM10=0, TOP = ICR1
    // OC1A pin (PB1/D9) is disconnected (COM1A = 00) because our servo
    // is on PB4 (D12), which is not a hardware OC pin.
    // We toggle PB4 manually from the OVF and COMPA ISRs instead.
    TCCR1A = (1 << WGM11);
    TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);  // prescaler /8

    // Set TOP for 20 ms PWM period  (50 Hz)
    ICR1 = SERVO_TIMER_TOP;

    // Set initial pulse width for 15 degrees
    OCR1A = SERVO_PULSE_0DEG +
            ((uint32_t)SWEEP_MIN_ANGLE * 
             (SERVO_PULSE_180DEG - SERVO_PULSE_0DEG)) / 180;

    // Enable Overflow interrupt (pulse start) and Compare Match A (pulse end)
    TIMSK1 = (1 << TOIE1) | (1 << OCIE1A);
}

// Convert an angle (0-180 degrees) to Timer1 counts and update OCR1A
static void servo_write(uint8_t angle)
{
    uint16_t pulse_counts = SERVO_PULSE_0DEG +
                            ((uint32_t)angle *
                             (SERVO_PULSE_180DEG - SERVO_PULSE_0DEG)) / 180;
    // 16-bit register write must be atomic on AVR
    cli();
    OCR1A = pulse_counts;
    sei();
}

// ============================================================================
//  HC-SR04 ULTRASONIC SENSOR
// ============================================================================

static void echo_interrupt_init(void)
{
    // Enable Pin Change Interrupts for Port B (covers PB0..PB7)
    PCICR  |= (1 << PCIE0);

    // Unmask only PB3 (D11, ECHO pin) within Port B
    PCMSK0 |= (1 << PCINT3);
}

// Send a 10 us HIGH pulse on the TRIG pin to start a measurement
static void hcsr04_trigger(void)
{
    PORTB &= ~(1 << PB2);   // ensure TRIG is LOW before trigger
    delay_microseconds(2);

    PORTB |=  (1 << PB2);   // TRIG HIGH for 10 us
    delay_microseconds(10);

    PORTB &= ~(1 << PB2);   // TRIG LOW — sensor begins measurement
}

/*
 * Trigger one HC-SR04 measurement and return distance in centimetres.
 *
 * The sensor responds by driving ECHO HIGH for a duration proportional
 * to the round-trip time of the ultrasonic pulse.
 * Distance (cm) = echo_duration_us / 58
 *
 * Returns 0 if no echo is received within 30 ms (out of range or absent).
 */
static uint16_t hcsr04_measure_cm(void)
{
    // Clear any leftover echo state from a previous measurement
    cli();
    g_echo_ready  = false;
    g_echo_active = false;
    sei();

    hcsr04_trigger();

    // Wait for the PCINT ISR to capture the complete echo pulse
    uint32_t timeout_start = micros_get();
    while (!g_echo_ready)
    {
        if ((micros_get() - timeout_start) > 30000UL)
            return 0;   // 30 ms timeout — nothing detected in range
    }

    // Safely read the captured pulse duration
    cli();
    uint32_t echo_duration_us = g_echo_fall_us - g_echo_rise_us;
    sei();

    // Reject implausible values (below 2 cm or above 400 cm)
    if (echo_duration_us < ECHO_MIN_US || echo_duration_us > ECHO_MAX_US)
        return 0;

    // Convert to centimetres: distance = duration / 58
    // (speed of sound ~343 m/s, round trip divided by 2)
    return (uint16_t)(echo_duration_us / 58UL);
}

// ============================================================================
//  GPIO INITIALISATION
// ============================================================================

static void gpio_init(void)
{
    // TRIG (PB2 / D10): output, starts LOW
    DDRB  |=  (1 << PB2);
    PORTB &= ~(1 << PB2);

    // ECHO (PB3 / D11): input, no pull-up (HC-SR04 drives this line)
    DDRB  &= ~(1 << PB3);
    PORTB &= ~(1 << PB3);

    // SERVO (PB4 / D12): output, starts LOW
    DDRB  |=  (1 << PB4);
    PORTB &= ~(1 << PB4);

    // UART TX (PD1 / D1): must be set as output even though USART
    // takes over the line once TXEN0 is set (per ATmega328P datasheet)
    DDRD  |=  (1 << PD1);
}

// ============================================================================
//  MAIN
// ============================================================================

int main(void)
{
    // Initialise all peripherals
    gpio_init();
    uart_init();
    timer0_init();
    timer1_servo_init();
    echo_interrupt_init();

    // Enable global interrupts — required for Timer0, Timer1, and PCINT ISRs
    sei();

    // Give the servo time to reach the starting position before sweeping
    delay_milliseconds(500);

    while (1)
    {
        // ── Forward sweep: 15° → 165° ────────────────────────────────────
        for (uint8_t angle = SWEEP_MIN_ANGLE; angle <= SWEEP_MAX_ANGLE; angle++)
        {
            servo_write(angle);
            delay_milliseconds(SERVO_STEP_DELAY_MS);

            uint16_t distance_cm = hcsr04_measure_cm();
            uart_send_radar_line(angle, distance_cm);
        }

        // ── Reverse sweep: 165° → 15° ────────────────────────────────────
        // Use int16_t to avoid uint8_t underflow when decrementing past 0
        for (int16_t angle = SWEEP_MAX_ANGLE; angle >= SWEEP_MIN_ANGLE; angle--)
        {
            servo_write((uint8_t)angle);
            delay_milliseconds(SERVO_STEP_DELAY_MS);

            uint16_t distance_cm = hcsr04_measure_cm();
            uart_send_radar_line((uint8_t)angle, distance_cm);
        }
    }

    return 0;
}
