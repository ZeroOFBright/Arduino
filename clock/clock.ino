#include "LedControl.h"
#include "FontLEDClock.h" 
#define b1 4
#define b2 5
#define b3 6
#define b4 7
#define speaker 3
#define light 8
LedControl lc=LedControl(11,13,10,4);
int timer1_counter;
void plot(uint8_t,uint8_t,uint8_t);
void print_normal_char(uint8_t,uint8_t,char);
void clearled();
char dot1 = 28 ;
char dot2 = 28 ;

//variable
int mode=1;
int sec_digit1=0;
char c_sec_digit1;
int sec_digit2=0;
char c_sec_digit2;

int mi_digit1=0;
char c_mi_digit1;
int mi_digit2=0;
char c_mi_digit2;

int hr_digit1=0;
char c_hr_digit1=0;
int hr_digit2=0;
char c_hr_digit2=0;

int a_mi_digit1=0;
char c_a_mi_digit1;
int a_mi_digit2=0;
char c_a_mi_digit2;

int a_hr_digit1=1;
char c_a_hr_digit1=0;
int a_hr_digit2=2;
char c_a_hr_digit2=0;


int t_mi_digit1=0;
char c_t_mi_digit1;
int t_mi_digit2=0;
char c_t_mi_digit2;
int t_sec_digit1=0;
char c_t_sec_digit1;
int t_sec_digit2=0;
char c_t_sec_digit2;

int timer=0;
int s_mode=0;
int a_mode=0;

//debounce
int buttonstate4; 
int buttonstate3;
int buttonstate2;
int buttonstate1;

int lastbuttonstate3 = LOW;
int lastbuttonstate2 = LOW;
int lastbuttonstate1 = LOW;
int lastbuttonstate4 = LOW;

unsigned long lastdebouncetime3 = 0;
unsigned long lastdebouncetime2 = 0;
unsigned long lastdebouncetime1 = 0;
unsigned long lastdebouncetime4 = 0;

unsigned long debouncedelay = 25;




void setup()
{
  
  Serial.begin(9600);
  int devices=lc.getDeviceCount();
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
  digitalWrite(light,LOW);
 for(int address=0;address<=devices;address++){
 lc.shutdown(address,false);
 lc.setIntensity(address,8);
 lc.clearDisplay(address);

 noTone(speaker);
 }
  
  // initialize timer1 
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  timer1_counter = 3036;   // preload timer 65536-16MHz/256/1Hz
  
  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts
}


ISR(TIMER1_OVF_vect)        // interrupt service routine 
{
  TCNT1 = timer1_counter;   // preload timer
  sec_digit1++;
  if(mode == 4 && s_mode == 1){
    Serial.println("Mode 4 and timer is on");
    timer--;
  }
  Serial.println(sec_digit1);
}


void loop()
{
 
   c_sec_digit1 = sec_digit1 + 48;
   c_sec_digit2 = sec_digit2 + 48;
   c_mi_digit1 = mi_digit1 + 48;
   c_mi_digit2 = mi_digit2 + 48;
   c_hr_digit1 = hr_digit1 + 48;
   c_hr_digit2 = hr_digit2 + 48;
   c_a_mi_digit1 = a_mi_digit1 + 48;
   c_a_mi_digit2 = a_mi_digit2 + 48;
   c_a_hr_digit1 = a_hr_digit1 + 48;
   c_a_hr_digit2 = a_hr_digit2 + 48;
   
   t_mi_digit2=timer/600;
   t_mi_digit1=(timer%600)/60; 
   t_sec_digit2 = (((timer%600)%60)/10); 
   t_sec_digit1 = (((timer%600)%60)%10);

   c_t_mi_digit1 = t_mi_digit1 + 48;
   c_t_mi_digit2 = t_mi_digit2 + 48;
   c_t_sec_digit1 = t_sec_digit1 + 48;
   c_t_sec_digit2 = t_sec_digit2 + 48;
   

//debounce button
//////////////////////////////////////////////////////////////////////////button4
  int reading4 = digitalRead(7);
  if(reading4 != lastbuttonstate4){
    lastdebouncetime4 = millis();}
    
  if(millis() - lastdebouncetime4 > debouncedelay){
    
    if(reading4 != buttonstate4){
      buttonstate4 = reading4; 
      
      if(mode == 4 && buttonstate4 == LOW && s_mode == 0){
        s_mode = 1;
        Serial.println("smode from 0 to 1");
        
      }
      else if(mode == 4 && buttonstate4 == LOW && s_mode == 1){
        s_mode = 0;
        Serial.println("smode from 1 to 0"); 
        
      }
      else if(mode == 4 && buttonstate4 == LOW && s_mode == 2){
        s_mode = 0; 
        Serial.println("smode from 2 to 0");
        
      }
      else if(mode == 3 && buttonstate4 == LOW && a_mode == 0){
        a_mode = 1;
        Serial.println("amode from 0 to 1");
        digitalWrite(light,HIGH);

      }
      else if(mode == 3 && buttonstate4 == LOW && a_mode == 1){
        
        Serial.println("amode frome 1 to 0");
        digitalWrite(light,LOW);
      }
      else if(mode == 3 && buttonstate4 == LOW && a_mode == 2){
        a_mode = 0;
        Serial.println("amode from 2 to 0");
        digitalWrite(light,LOW);
        
      }
      
    }
  }
    lastbuttonstate4 = reading4;

/////////////////////////////////////////////////////////////////////////////button3
  int reading3 = digitalRead(6);
  if(reading3 != lastbuttonstate3){
    lastdebouncetime3= millis();}
    
  if(millis() - lastdebouncetime3 > debouncedelay){
    
    if(reading3 != buttonstate3){
      buttonstate3 = reading3; 
       
      if(buttonstate3 == LOW&& s_mode == 0){
      mode = mode+1;  
      timer = 0;
      clearled();
      
      }
    }
  }
  
  lastbuttonstate3 = reading3;
//////////////////////////////////////////////////////////////////////////button2
  int reading2 = digitalRead(5);
  if(reading2 != lastbuttonstate2){
    lastdebouncetime2 = millis();
  }
  
  if(millis() - lastdebouncetime2 > debouncedelay){
    
    if(reading2 != buttonstate2) {
      buttonstate2 = reading2;
      
      if(buttonstate2 == HIGH && mode == 3 && a_mode == 0){
        a_mi_digit1 = a_mi_digit1 + 1;
        Serial.println("button2 press a_mi digit1+1");
      }

      else if(buttonstate2 == HIGH && mode == 2 ){
        mi_digit1 = mi_digit1 + 1;
        
      }

      else if(buttonstate2 == HIGH && mode==4 && s_mode == 0){
        timer = timer + 1 ;
      }
    }
   }
  
  lastbuttonstate2 = reading2;
////////////////////////////////////////////////////////////////////// button1 
  int reading1 = digitalRead(4);
  if(reading1 != lastbuttonstate1){
    lastdebouncetime1 = millis();
  }
  if(millis() - lastdebouncetime1 > debouncedelay){
    
    if(reading1 != buttonstate1){
      buttonstate1 = reading1;
      
      if(buttonstate1 == HIGH && mode == 2){
        hr_digit1 = hr_digit1 + 1;
      }
      
      else if(buttonstate1 == HIGH && mode == 3 && a_mode == 0){
        a_hr_digit1 = a_hr_digit1 + 1;
      }

      else if(buttonstate1 == HIGH && mode == 4 && s_mode == 0){
        timer = timer + 60;
      }
    }
  }
  
  lastbuttonstate1 = reading1;
///////////////////////////////////////////////////////////////////////////////////////////////////

//system setting 
    if(sec_digit1 == 10){ sec_digit1 = 0; sec_digit2 = sec_digit2+1;
       if(sec_digit2 == 6){sec_digit2=0;mi_digit1 = mi_digit1 + 1;lc.clearDisplay(1);}}

    if(mi_digit1 == 10){mi_digit1 = 0; mi_digit2 = mi_digit2+1;}
    
    if(mi_digit2 == 6){mi_digit2 =0; hr_digit1 = hr_digit1+1;}

    if(hr_digit1 == 10){hr_digit1= 0; hr_digit2 = hr_digit2 + 1;}
    
    if(hr_digit2 == 2 && hr_digit1 == 4){hr_digit1 = 0;hr_digit2 = 0;}

    if(a_mi_digit1 == 10){a_mi_digit1 = 0; a_mi_digit2 = a_mi_digit2+1;}
    
    if(a_mi_digit2 == 6){a_mi_digit2 = 0; a_hr_digit1 = a_hr_digit1+1;}

    if(a_hr_digit1 == 10){a_hr_digit1 = 0; a_hr_digit2 = a_hr_digit2 + 1;}
    
    if(a_hr_digit2 == 2){if(a_hr_digit1==4){a_hr_digit1 = 0; a_hr_digit2 = 0;}}

    if(a_mode == 1 && a_hr_digit1 == hr_digit1 && a_hr_digit2 == hr_digit2 
        && a_mi_digit1 == mi_digit1 && a_mi_digit2 == mi_digit2){
        a_mode = 2;
    }
    
    if(mode == 4 && timer == 0 && s_mode == 1){s_mode = 2;}

    if(mode == 5){mode = 1;}

    if(s_mode == 2){Serial.println("smode from 1 to 2");if(sec_digit1%2==0){tone(speaker,262);}else{noTone(speaker);}} 

    else if(a_mode == 2){Serial.println("amode from 1 to 2");if(sec_digit1%2==0){tone(speaker,248);}else{noTone(speaker);}}
      
    else {noTone(speaker);}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
   // mode sec
   if(mode == 1){
      plot(0,6,1);
      print_normal_char(27, 1, c_sec_digit1);  
       
      if(sec_digit2!=0){
        print_normal_char(19, 1, c_sec_digit2);}
      }
      

  //mode minute 
  else if(mode == 2){
    plot(0,6,1);
    plot(0,4,1);
    print_normal_char(27, 1, c_mi_digit1);
    print_normal_char(19, 1, c_mi_digit2);
    print_normal_char(11,  1, c_hr_digit1);
    print_normal_char(3,  1, c_hr_digit2);
    
    
  }
  // alarm mode
   
  else if(mode == 3){
    plot(0,6,1);
    plot(0,4,1);
    plot(0,2,1);
    print_normal_char(27, 1, c_a_mi_digit1);
    print_normal_char(19, 1, c_a_mi_digit2);
    print_normal_char(11, 1, c_a_hr_digit1);
    print_normal_char(3,  1, c_a_hr_digit2);
    print_tiny_char(16, 2, ':'); 
  }

  else if(mode == 4){
    plot(0,6,1);
    plot(0,4,1);
    plot(0,2,1);
    plot(0,0,1);
    print_normal_char(3,  1, c_t_mi_digit2);
    print_normal_char(11,  1, c_t_mi_digit1);
    print_normal_char(19, 1, c_t_sec_digit2);
    print_normal_char(27, 1, c_t_sec_digit1); 
    print_tiny_char(16, 2, ':'); 
  }

    
}

//plot a point on the display
void plot (uint8_t x, uint8_t y, uint8_t value) {

  //select which matrix depending on the x coord
  uint8_t address;
  if (x >= 0 && x <= 7)   { address = 3; }
  if (x >= 8 && x <= 15)  { address = 2; x = x - 8; }
  if (x >= 16 && x <= 23) { address = 1; x = x - 16;}
  if (x >= 24 && x <= 31) { address = 0; x = x - 24;}

  if (value == 1) {
    lc.setLed(address, y, x, true);
  } 
  else {
    lc.setLed(address, y, x, false);
  }
}


void clearled(){
 int devices=lc.getDeviceCount();
 for(int address=0;address<=devices;address++){
 lc.clearDisplay(address);
}
}


void print_normal_char(uint8_t x, uint8_t y, char c){

  uint8_t dots;

 if (c >= '0' && c <= '9') { c = (c - '0') + 31; }
 else if (c == ':') { c = 28; } // colon 
  
  for (uint8_t col = 0; col < 5; col++) {
    dots = pgm_read_byte_near(&myfont[c][col]);
    for (uint8_t row = 0; row < 7; row++) {
      if (dots & (64 >> row)) {   // only 7 rows.
        plot(x + col, y + row, 1);
      } 
      else {
        plot(x + col, y + row, 0);
      }
    }
  }
}

void print_tiny_char(uint8_t x, uint8_t y, char c){
  uint8_t dots;
  if (c >= 'A' && c <= 'Z' || (c >= 'a' && c <= 'z') ) { c &= 0x1F; }  // A-Z maps to 1-26 
  else if (c >= '0' && c <= '9') { c = (c - '0') + 32; }
  else if (c == ' ') { c = 0;  } // space 
  else if (c == '.') { c = 27; } // full stop 
  else if (c == ':') { c = 28; } // colon 
  else if (c == '\''){ c = 29; } // single quote mark 
  else if (c == '!') { c = 30; } // single quote mark 
  else if (c == '?') { c = 31; } // single quote mark 

  for (uint8_t col = 0; col < 3; col++) {
    dots = pgm_read_byte_near(&mytinyfont[c][col]);
    for (uint8_t row = 0; row < 5; row++) {
      if (dots & (16 >> row))
        plot(x + col, y + row, 1);
      else
        plot(x + col, y + row, 0);
    }
  }
}
