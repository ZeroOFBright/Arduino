#include <ST7735_TEE.h>
TEE_ST7735 lcd(9, 10, 11, 12, 13);

void drawball(int,int);
void draw_bar(int);
void ball();
void de_bar(int);
void de_ball(int,int);
void movebar();
void deathscreen();
void interface(char,char);
void clearnum();
void deathscreen();

int x,a,b;
int bar;
int roof,side;
int l=3;


const int right = 3;
const int left = 5; 
const int PIN_ANALOG_X = 0;
const int start = 6;

char life[]="LIFE:";
char lose[]="LOSE";
char num=l+48;
char one = '1';

long hlong1;


void setup() {
  Serial.begin(9600);
  hlong1=millis();
  pinMode(left, INPUT);
  digitalWrite(left, HIGH);

  pinMode(right, INPUT);
  digitalWrite(right, HIGH);
  pinMode(start, INPUT);
  digitalWrite(start,HIGH);
  roof = 0;
  a = 65;
  b = 20;
  x = 50;
}

void loop() {
  num=l+48;
 if(l>0){
  lcd.init(lcd.VERTICAL);
  lcd.fillScreen(0x0000);
  interface(life,num); 
  draw_bar(x);
  while(l!=0){
   movebar();
   de_ball(a,b);
   ball();
   draw_ball(a,b);
  }
 }
 else if(l==0){
  deathscreen();
  while(l==0){
    if(digitalRead(start)==LOW){
      Serial.print("check press start button");
      l = 3;
    }
  }
  Serial.print("death");
 }
}

void draw_bar(int a){
  lcd.drawRect(a,155,28,3,0xFFFF);
}

void de_bar(int a){
  lcd.fillRect(a,155,28,3,0x0000);
}

void draw_ball(int a,int b){
  lcd.fillCircle(a,b,4,0xF800);
}

void de_ball(int a,int b){
  lcd.fillCircle(a,b,4,0x0000);
}

void movebar(){
 if((digitalRead(left)==LOW&&x>1)||(analogRead(PIN_ANALOG_X)<322&&x>1)){de_bar(x);draw_bar(x=x-7);}  
 
 if((digitalRead(right)==LOW&&x+28<127)||(analogRead(PIN_ANALOG_X)>722&&x+28<127)){de_bar(x);draw_bar(x=x+7);}
    
}

void ball(){
if(l!=0){
 
if(millis()-hlong1>50){

  if(side == 0){a=a+5;if(a==120){side = 1;}}
  else if(side == 1){a=a-5;if(a==5){side = 0;}}
  
  if(roof == 0){
  b=b+5;
    if(b == 150 && a>=x && a<=x+28){side=random(0,2);roof=1;}
    else if(b > 150){clearnum(); l--;  num = l+48; interface(life,num); a = 65; b = 20;}
  }
  else if(roof == 1){
  b=b-5;
    if(b==20){roof = 0;}
  }
   hlong1=millis();
}
}
}

void clearnum(){
  lcd.fillRect(60,0,15,14,0x0000);
  
}

void interface(char *life,char num){
  lcd.drawRect(0,15,128,145,0xFFFF);
  lcd.drawString(0,0,life,0xFFFF,2);
  lcd.drawChar(60,0,num,0xFFFF,2);
}

void deathscreen(){
char game[]="GAME";
char over[]="OVER";
  lcd.fillRect(0,0,128,160,0x0000);
  lcd.drawString(5,5,game,0xFFFF,5);
  lcd.drawString(5,60,over,0xFFFF,5);
}
