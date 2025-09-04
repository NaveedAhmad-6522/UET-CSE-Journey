<x-mail::message>
# Booking Confirmed!

Dear {{ $user->name }},

Your booking has been <strong>confirmed</strong>! Here are your booking details:

---
**Booking ID:** #{{ $booking->Booking_ID }}  
**Flight:** {{ $flight->Airline_Name }}  
**Route:** {{ $flight->departureAirport->Code }} → {{ $flight->arrivalAirport->Code }}  
**Date:** {{ $flight->Departure_Time->format('M d, Y') }}  
**Time:** {{ $flight->Departure_Time->format('H:i') }} - {{ $flight->Arrival_Time->format('H:i') }}  
**Passengers:** {{ $booking->passenger_count }}  
**Seat Class:** {{ ucfirst($booking->seat_class) }}  
**Total Amount:** ${{ number_format($totalAmount, 2) }}
---

<x-mail::button :url="url('/')">
View Your Booking
</x-mail::button>

Thank you for choosing SkyWay Airlines!

Best regards,<br>
SkyWay Airlines Team
</x-mail::message>
