const int LED_PIN = 9;

volatile int brightness = 0;
volatile int step = 10;
volatile int tickCount = 0;
const int TICKS_PER_STEP = 6;

ISR(TIMER2_COMPA_vect) {
  tickCount++;
  if (tickCount < TICKS_PER_STEP) return;
  tickCount = 0;

  brightness += step;

  if (brightness >= 999) {
    brightness = 999;
    step = -10;
  } else if (brightness <= 0) {
    brightness = 0;
    step = 10;
  }

  OCR1A = brightness;
}

void setup() {
  pinMode(LED_PIN, OUTPUT);

  TCCR1A = (1 << COM1A1) | (1 << WGM11);
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);
  ICR1   = 999;
  OCR1A  = 0;

  TCCR2A = (1 << WGM21);
  TCCR2B = (1 << CS22) | (1 << CS21) | (1 << CS20); 
  OCR2A  = 255;
  TIMSK2 = (1 << OCIE2A);

  sei(); 
}

void loop() {
}