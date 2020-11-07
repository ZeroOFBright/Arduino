//กำหนดตัวแปร เพื่อเก็บค่าเวลา
long Hlong1 = 0;
long Hlong2 = 0;
long Hlong3 = 0;
void setup() {
  // put your setup code here, to run once:
  // บอกช่อง อิน เอ้า ที่ใช้
  pinMode (10,INPUT);
  pinMode (11,INPUT);
  pinMode (12,INPUT);
  pinMode (2,OUTPUT);
  pinMode (3,OUTPUT);
  pinMode (4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.begin(9600);
bool s10=digitalRead(10);
bool s11=digitalRead(11);
bool s12=digitalRead(12);
//GREEN

if(digitalRead(4)==LOW)
{
  if(digitalRead(10)==LOW&&digitalRead(2)==LOW)
  {digitalWrite(2,HIGH);Hlong1=millis(); delay(250);}

 if(digitalRead(10)==LOW&&digitalRead(2)==HIGH)
  {digitalWrite(2,LOW); delay(200);}
  
 if(millis()-Hlong1>=2550)
 {digitalWrite(2,LOW);}
}  

//YELLOW
if(digitalRead(2)==LOW&&digitalRead(4)==LOW)
{
  if(digitalRead(11)==LOW&&digitalRead(3)==LOW)
    {digitalWrite(3,HIGH); Hlong2=millis();}
  if(millis()-Hlong2==500)
    {digitalWrite(3,LOW);}  
  if(millis()-Hlong2==1000)
    {digitalWrite(3,HIGH);}
  if(millis()-Hlong2==1500)
    {digitalWrite(3,LOW);}  
}   
 //RED
if(digitalRead(12)==HIGH&&digitalRead(4)==LOW)
  {digitalWrite(4,HIGH); Hlong3=millis(); delay(250);}
if(digitalRead(12)==HIGH&&digitalRead(4)==HIGH)
 {digitalWrite(4,LOW); delay(200);}
if(millis()-Hlong3>=2550)
 {digitalWrite(4,LOW);}
}
