#define redLeft 8
#define yellowLeft 9
#define greenLeft 10

#define redRight 5
#define yellowRight 6 
#define greenRight 7 

void setup() {
Serial.begin(9600);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);

digitalWrite(5,HIGH);
digitalWrite(6,HIGH);
digitalWrite(7,HIGH);
digitalWrite(8,HIGH);
digitalWrite(9,HIGH);
digitalWrite(10,HIGH);  
//กุใช้high เพราะจำได้ว่ามันต่อlowมั้ง ถ้าไม่ใช่ก็สลับhigh เป็นlowเอาละกัน
}

void loop() {
  if(เงื่อนไข เดินหน้า){
    digitalWrite(greenLeft,LOW);
    digitalWrite(greenRight,LOW);
    digitalWrite(yellowLeft,HIGH);
    digitalWrite(yellowRight,HIGH);
    digitalWrite(redLeft,HIGH);
    digitalWrite(redRight,HIGH);    
  } 
  else if(เงื่อนไขจะเลี้ยวซ้าย){
    digitalWrite(greenLeft,HIGH);
    digitalWrite(greenRight,HIGH);
    digitalWrite(yellowLeft,HIGH);
    digitalWrite(yellowRight,HIGH);
    digitalWrite(redLeft,HIGH);
    digitalWrite(redRight,HIGH);    
    for(int i=0; i<4; i++){
      digitalWrite(yellowLeft,LOW);
      delay(100);
      digitalWrite(yellowLeft,HIGH);
      delay(100);
    }
  }
  else if(เงื่อนไขเลี้ยวขวา){
    digitalWrite(greenLeft,HIGH);
    digitalWrite(greenRight,HIGH);
    digitalWrite(yellowLeft,HIGH);
    digitalWrite(yellowRight,HIGH);
    digitalWrite(redLeft,HIGH);
    digitalWrite(redRight,HIGH); 
    
    for(int i=0; i<4; i++){
      digitalWrite(yellowRight,LOW);
      delay(100);
      digitalWrite(yellowRight,HIGH);
      delay(100);
    }
  }
  else if(เงื่อนไขถอยหลัง){
    digitalWrite(greenLeft,HIGH);
    digitalWrite(greenRight,HIGH);
    digitalWrite(yellowLeft,HIGH);
    digitalWrite(yellowRight,HIGH);
    digitalWrite(redLeft,LOW);
    digitalWrite(redRight,LOW);    
  }


}
