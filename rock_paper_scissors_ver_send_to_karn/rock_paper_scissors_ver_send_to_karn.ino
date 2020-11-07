#include <SoftwareSerial.h>

#define rock 8
#define paper 9
#define scissors 10


#define red 11
#define yellow 12
#define green 13

void fr();
void fp();
void fs();
void clearled();
void win();
void lose();
void draw();
void error();
SoftwareSerial mySerial(3,4);

char input1;
int mode;
char state;
unsigned long savetime1=0;
unsigned long savetime2=0;
char a;
int i;

void setup() {
  
  Serial.begin(4800);
  mySerial.begin(4800);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  clearled();
  mode = 0;
  a='q';
  input1 = 'q';
  i=0;
}


void loop() {
  
// button press

 if(mode == 0){
    if(digitalRead(8) == HIGH){
    input1 = 'r';
    fr();
    mode = 1;
    savetime1=millis();
    }
    else if(digitalRead(9) == HIGH){
    input1 = 'p';
    fp();
    mode = 1;
    savetime1=millis();
    }
    else if(digitalRead(10) == HIGH){
    input1 = 's';
    fs();
    mode = 1;
    savetime1=millis();
    }   
  }

if(mySerial.available()&&i==0){
  savetime2=millis();
  Serial.println("Another press");
  i=1;
}
  
//process
while(mode == 1){
  if(mySerial.available()) {
    a=mySerial.read();
    Serial.println(a);
    if(millis()-savetime1<4000&&millis()-savetime2<4000&&a!='q'&&input1!='q'){
      if(a == 'r' && input1 == 'p'){win();clearled();mode=0;}
      else if(a == 'r' && input1 == 's'){lose();clearled();mode = 0;a='q';input1='q';}
      else if(a == 's' && input1 == 'r'){win();clearled();mode = 0;a='q';input1='q';}
      else if(a == 's' && input1 == 'p'){lose();clearled();mode = 0;a='q';input1='q';}
      else if(a == 'p' && input1 == 's'){win();clearled();mode = 0;a='q';input1='q';}
      else if(a == 'p' && input1 == 'r'){lose();clearled();mode = 0;a='q';input1='q';}
      else{draw();clearled();mode=0;a='q';input1='q';}
    }
    else if(millis()-savetime1>2000||millis()-savetime2>2000){
      error();
      mode=0;
      a='q';
      input1='q';
    }
  }
}
}


void fr(){ // rock
  delay(110);
  for(int i=0;i<=2;i++){
  digitalWrite(12,LOW);
  delay(100);
  digitalWrite(12,HIGH);
  }
  Serial.println("ROCK");
  mySerial.println('r');
 
  
}

void fp(){ //paper
  delay(100);
  for(int i=0;i<=2;i++){
  digitalWrite(12,LOW);
  delay(100);
  digitalWrite(12,HIGH);
  }
 Serial.println("PAPER");
 mySerial.println('p');
}

void fs(){ // scissors
  delay(100);
  for(int i=0;i<=2;i++){
  digitalWrite(12,LOW);
  delay(100);
  digitalWrite(12,HIGH);
  }
 Serial.println("SCISSOR");
 mySerial.println('s');
}
void win(){
  Serial.println("WIN");
  digitalWrite(13,LOW);
  delay(2000);
}

void lose (){
  Serial.println("LOSE");
  digitalWrite(11,LOW);
  delay(2000);
}

void draw(){
  Serial.println("DRAW");
  digitalWrite(12,LOW);
  delay(2000);
}

void clearled(){
  Serial.println("clear LED");
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
}

void error(){
  Serial.println("error");
  for(int i=0;i<3;i++){
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  delay(250);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  delay(250);
  }
}
