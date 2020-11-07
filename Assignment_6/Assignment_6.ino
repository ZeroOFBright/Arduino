#include <SoftwareSerial.h>
String inputString = ""; // a string to hold incoming data
SoftwareSerial mySerial(3,4); // SoftwareSerial(rxPin, txPin)
const int hammer      = 10; //sw
const int scissor     = 9; //sw
const int paper       = 8;   //sw
const int lose_lc     = 11; //led
const int draw_lc     = 12; //led
const int win_lc      = 13;  //led
const int standBy_lc  = 7; //led
char input            = 'f';
char outSource        = 'x';
char re;
char me; char outs    = 'x';
int mod               = 0;
unsigned long timer; void blinkk();
void setup(){
  pinMode(hammer,INPUT_PULLUP);
  pinMode(scissor,INPUT_PULLUP);
  pinMode(paper,INPUT_PULLUP);
  pinMode(lose_lc,OUTPUT);
  pinMode(draw_lc,OUTPUT);
  pinMode(win_lc,OUTPUT);
  pinMode(standBy_lc,OUTPUT);
 // Open serial communications and wait for port to open:
 Serial.begin(4800);
 Serial.println("Connecting");
 // set the data rate for the SoftwareSerialport
 mySerial.begin(4800); // recommentlow speed
 // attachInterrupt(interrupt, ISR, mode) interrupt-> 1(pin3)
 attachInterrupt(1,SoftwareSerialEvent,FALLING);
 mySerial.println("Software Serial->Connected");
}
void loop(){
  do{
      if      (digitalRead(hammer)==LOW)        {input = '1'; mySerial.write(input);}
      else if (digitalRead(scissor)==LOW)       {input = '2'; mySerial.write(input);}
      else if (digitalRead(paper)==LOW)         {input = '3'; mySerial.write(input);} digitalWrite(standBy_lc,HIGH);
  }while(input == 'f'); digitalWrite(standBy_lc,LOW);
  Serial.println("line 32 : Succeed"); //Debugging 1
  timer=millis();
  while(outSource != '1' && outSource != '2' && outSource != '3'){Serial.print('x');} outs=outSource;
  Serial.println(""); Serial.println("line 35 : Succeed"); //Debugging 2
  Serial.print(input); Serial.print(" "); Serial.println(outs);
  if(millis()-timer < 200){
    Serial.println("pass");
          if(input == '1' && outs == '2')                 {me='w'; re='l';}
          if(input == '1' && outs == '3')                 {me='l'; re='w';}
          if(input == '2' && outs == '3')                 {me='w'; re='l';}
          if(input == '2' && outs == '1')                 {me='l'; re='w';}
          if(input == '3' && outs == '1')                 {me='w'; re='l';}
          if(input == '3' && outs == '2')                 {me='l'; re='w';}
          if(input == outs)                               {me='d'; re='d';}
  }
  else{
    Serial.println("not pass");
          me='f'; re='f';
  }
  Serial.print(me);Serial.print(" ");Serial.println(re);
  mySerial.write(re);
  while(outSource != 'w' && outSource != 'l' && outSource != 'd' && outSource != 'f'){Serial.print('x');} 
  re = outSource; Serial.println("");Serial.print(me);Serial.print(" ");Serial.println(re);
  Serial.println("line 54 : Succeed"); //Debugging 3
  if(re == me){
          if(me == 'w') {Serial.println("win"); digitalWrite(win_lc,HIGH);}
          if(me == 'l') {Serial.println("lose");digitalWrite(lose_lc,HIGH);}
          if(me == 'd') {Serial.println("draw");digitalWrite(draw_lc,HIGH);}
          if(me == 'f') {Serial.println("foul"); blinkk();}
  }
  else {Serial.println("Result not match"); blinkk();}
  input = 'f';
  outSource = 'x';
  re = '0';
  me = '0';
  mod = '0';
  outs = 'x';
  delay(3000);
  digitalWrite(win_lc,LOW); digitalWrite(draw_lc,LOW); digitalWrite(lose_lc,LOW); digitalWrite(standBy_lc,LOW);
  Serial.println("NEXT");
}
void SoftwareSerialEvent(){
   if(mySerial.available()) // test this condition by connecting pin rxsoftware with pin'0'(Rx)
 {
    outSource = (char)mySerial.read();
    Serial.print(outSource);
 }
}
void blinkk(){
  for(int n=0;n<5;n++){digitalWrite(standBy_lc,HIGH); delay(100); digitalWrite(standBy_lc,LOW); delay(100);}
}
