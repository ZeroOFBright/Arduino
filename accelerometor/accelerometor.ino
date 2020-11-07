#define a A0
#define b A4
void setup()
{
 Serial.begin(9600);

}
void loop()
{
 int xaccel = analogRead(A3);
 int yaccel = analogRead(A2);
 int zaccel = analogRead(A1);
 unsigned long timevar = millis();

 Serial.print(timevar);
 Serial.print(" ");
 Serial.print(xaccel);
 Serial.print(" ");
 Serial.print(yaccel);
 Serial.print(" ");
 Serial.println(zaccel);
 
}
