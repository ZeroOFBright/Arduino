#include <LedControl.h>
//HARDWARE 
LedControl lc = LedControl(13,11,10,1);
const int b_right = 3;
const int b_left = 5;

//debounce VAR
int lastass = HIGH;
unsigned long lastdebouceASS = 0;
int ass;
int lastbss = HIGH;
unsigned long lastdebouceBSS = 0;
int bss;
unsigned long deboucetime = 50;
unsigned long prevTime = 0;                        
unsigned long delayTime = 500;                  

//VARIABLE
int x,a,b;
int life = 3;
int side,roof;
//function prototype
void de_bar(int x);
void draw_bar(int x);
void draw_ball(int a,int b);
void de_ball(int a,int b);
void ball();


long hlong1;
long hlong2;
long hlong3;


void setup() {
 Serial.begin(9600);
  lc.shutdown(0,false);
  lc.clearDisplay(0);
  randomSeed(analogRead(5));
  pinMode(3,INPUT);
  pinMode(5,INPUT);
  x=2;
  a = 0;
  b = random(0,8);
  roof = 0;
}

void loop() {
  
 if(life>0){
   movebar();
   ball();
  
 }
 else if(life==0){
  lc.clearDisplay(0);
  Serial.print("LOSE");
 }
}


//lc.setLed(0,row,column,T/F)
void draw_bar(int x){
  lc.setLed(0,7,x,true);
  lc.setLed(0,7,x+1,true);
  lc.setLed(0,7,x+2,true);  
}

void de_bar(int x){
  lc.setLed(0,7,x,false);
  lc.setLed(0,7,x+1,false);
  lc.setLed(0,7,x+2,false);  
}

void draw_ball(int a,int b){
  lc.setLed(0,a,b,true); 
}

void de_ball(int a,int b){
  lc.setLed(0,a,b,false);
}

void movebar(){
  int Aass = digitalRead(5);
  if(Aass != lastass){lastdebouceASS = millis();}
  if ((millis() - lastdebouceASS) > deboucetime) {
    if (Aass != ass) {ass = Aass; if(ass==LOW&&x>0){de_bar(x);draw_bar(--x);}}}  
  lastass = Aass;
  int Bbss = digitalRead(3);
  if(Bbss != lastbss){lastdebouceBSS = millis();}
  if ((millis() - lastdebouceBSS) > deboucetime) {
    if (Bbss != bss) {bss = Bbss; if(bss==LOW&&x+2<7){de_bar(x);draw_bar(++x);}}}
  lastbss = Bbss;
  draw_bar(x);
}

void ball(){

  hlong1=millis();
if(millis()-hlong1>100){

  if(side == 0){
    ++b;
    if(b==7){
      side = 1;
    }
  }
  else if(side == 1){
    --b;
    if(b==0){
      side = 1;
    }
  }
  if(roof == 0){
    ++a;
    if(a==6&&b==x){side=1;roof=1;}
    else if(a==6&&b==x+1){roof=1;}
    else if(a==6&&b==x+2){side=0;roof=1;}
    else if(a==7){life--; b = random(0,8);a = 0;}
    }
  else if(roof == 1){
    --a;
    if(a==0){roof = 0;}
  }
}

draw_ball(a,b);
}


