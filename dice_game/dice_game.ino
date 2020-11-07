#define b_guess 13
#define b_roll 12
#define t 11
#define f 10
int i = 0;
void setup() {
 Serial.begin(9600);
  pinMode(b_guess,INPUT);
  pinMode(b_roll,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  random(7);
  clearled();
}
int show[6][7] = {
   {1,0,0,1,1,1,1}, //print 1
   {0,0,1,0,0,1,0}, //print 2
   {0,0,0,0,1,1,0}, //print 3
   {1,0,0,1,1,0,0}, //print 4
   {0,1,0,0,1,0,0}, //print 5
   {0,1,0,0,0,0,0} //print 6
  };

//int beep[7] = {

void clearled()
{
  for (int y = 0; y < 7; y++)
  {
    digitalWrite(y + 2, 1);
  }
  delay(1000);
}

void loading(){
  for(int x=0;x<=5;x++){
   digitalWrite(x+2,0); 
   delay(100);
   digitalWrite(x+2,1);
   delay(100); 
  }
}

int num=5;

 
void loop() {
  
  // 7 SEGMENT DISPLAY
    int c_b_guess = digitalRead(13); 
    if(c_b_guess == LOW){
    while (digitalRead(b_guess) == LOW);
      if(num<5){
      num++;
    }
      else{
      num=0;
    }
      for(i=0;i<=6;i++){
        digitalWrite(i+2,show[num][i]);
      }
    delay(250);

    }
   // random function
   
    int c_b_roll = digitalRead(12);
    if(c_b_roll == LOW){
     while (digitalRead(b_guess) == LOW);
      clearled();
      loading();
      for(int a=0;a<=6;a++){
      }
      int r_roll = random(0,6);
      for(i=0;i<=6;i++){
        digitalWrite(i+2,show[r_roll][i]);
      }
    //check 
    if(r_roll == num){
      
      digitalWrite(11,HIGH);
      delay(100);
      digitalWrite(11,LOW);
      delay(100);
      digitalWrite(11,HIGH);
      delay(100);
      digitalWrite(11,LOW);
      delay(100);
      digitalWrite(11,HIGH);
      delay(100);
      digitalWrite(11,LOW);
      delay(100);
      digitalWrite(11,HIGH);
      delay(100);
      digitalWrite(11,LOW);
      delay(100);
      digitalWrite(11,HIGH);
      delay(100);
      digitalWrite(11,LOW);
      delay(100);
    }
    else{
      digitalWrite(10,HIGH);
      delay(100);
      digitalWrite(10,LOW);
      delay(100);
      digitalWrite(10,HIGH);
      delay(100);
      digitalWrite(10,LOW);
      delay(100);
      digitalWrite(10,HIGH);
      delay(100);
      digitalWrite(10,LOW);
      delay(100);
      digitalWrite(10,HIGH);
      delay(100);
      digitalWrite(10,LOW);
      delay(100);
      digitalWrite(10,HIGH);
      delay(100);
      digitalWrite(10,LOW);
      delay(100);
      }
       clearled();
       num = 5;
    }
   
   }
  

