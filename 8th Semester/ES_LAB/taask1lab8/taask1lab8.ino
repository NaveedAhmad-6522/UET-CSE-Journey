void setup(){
  pinMode(13,OUTPUT);
  TCCR1A=0;
  TCCR1B=0;
  TCNT1=0;
  TCCR1B |=(1<<CS12)|(1<<CS10);
   }
  void loop(){
    if(TCNT1>15625){
      TCNT1=0;
      digitalWrite(13,!digitalRead(13));
  }
}