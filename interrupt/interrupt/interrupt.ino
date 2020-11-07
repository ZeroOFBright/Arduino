#define button 2
#define ledPin 13
void setup()
{
 pinMode(button,INPUT_PULLUP);
 pinMode(ledPin, OUTPUT);
 attachInterrupt(0, EXTI0_ISR, FALLING);
}
void loop()
{
}
void EXTI0_ISR()
{
 digitalWrite(ledPin, !digitalRead(ledPin)); // Toggle LED
 delay(150);
}
