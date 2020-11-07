#define b1 12 // link to r
#define b2 11 // link to y
#define b3 10 // link to g
#define r 2
#define y 3
#define g 4
int x;
unsigned long savetimeR, savetimeG, savetimeY;
void setup() {
  Serial.begin(9600);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(y, OUTPUT);
}

void loop() {
  Serial.print(digitalRead(b1));
  Serial.print(",");
  Serial.print(digitalRead(b2));
  Serial.print(",");
  Serial.println(digitalRead(b3));
  int read1 = digitalRead(r);
  if (read1 == LOW && digitalRead(b1) == HIGH) { // check LED ON OR OFF
    while (digitalRead(b1) == HIGH);
    digitalWrite(r, HIGH);
    savetimeR = millis();

  }
  else if (read1 == HIGH) { // press same button to turn off the LED

    if (digitalRead(b1) == HIGH) {
      while (digitalRead(b1) == HIGH);
      digitalWrite(r, LOW);
      Serial.println("RedClose");
    }

  }
  if ((millis() - savetimeR) >= 3000) {
    digitalWrite(r, LOW);
    savetimeR = millis();
  }


  int read3 = digitalRead(g);
  if (read1 == LOW &&  digitalRead(b3) == HIGH && read3 == LOW)  { // when red is off
    while (digitalRead(b3) == HIGH);
    digitalWrite(g, HIGH);
    savetimeG = millis();

  }
  else if (read1 == LOW && digitalRead(b3) == HIGH && read3 == HIGH) { // press same button to turn off the LED
    while (digitalRead(b3) == HIGH);
    digitalWrite(g, LOW);
    Serial.println("GreenClose");
  }
  if ((millis() - savetimeG) >= 3000) {
    digitalWrite(g, LOW);
    savetimeG = millis();
  }
  // yellow pulldown
   int read2 = digitalRead(y);
    if(read1 == LOW && read3 == LOW){
      if(read2 == LOW && digitalRead(b2)==HIGH){
        savetimeY = millis();
        digitalWrite(y,HIGH);
        x = 4;
        }
      }
  if(millis()-savetimeY > 500){
    if(x>0)
    {
      if(x%2==0)
        digitalWrite(y,LOW);
      else
        digitalWrite(y,HIGH);
      x--;
      savetimeY = millis();
    }
   if(x==0)
      digitalWrite(y,LOW);       
  }



}
