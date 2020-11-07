int enA = 10;
int in2 = 9;
int in1 = 8;

int enB = 5;
int in3 = 6;
int in4 = 7;
void setup()
{
Serial.begin(9600);
// set all the motor control pins to outputs
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
}
int count = 0;
void loop()
{
// this function will run the motors in both directions at a fixed speed
// turn on motor A
if(count <= 5){
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
analogWrite(enA, 100); // Speed Control
// set speed to 200 out of possible range 0~255
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enB, 100);
delay(2000);
count++;
Serial.println(count);
}
else if(count>5&&count<7){
  Serial.println(count);
  Serial.println("count>5");
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  count++;
  delay(2000);
}
else{
  Serial.println("count>7");
  count=0;
}

}
