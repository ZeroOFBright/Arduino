#define speaker 3
#define bl 2
#define br 1
const unsigned int X_AXIS_PIN = 2;
const unsigned int Y_AXIS_PIN = 1;
const unsigned int Z_AXIS_PIN = 0;
const unsigned int NUM_AXES = 3;
const unsigned int PINS[NUM_AXES] = {
 X_AXIS_PIN, Y_AXIS_PIN, Z_AXIS_PIN
};

const unsigned int BUFFER_SIZE = 16;
const unsigned int BAUD_RATE = 9600;
int buffer[NUM_AXES][BUFFER_SIZE];
int buffer_pos[NUM_AXES] = { 0 };


void setup() { 
  
  Serial.begin(BAUD_RATE); 
  pinMode(2,INPUT);
  pinMode(1,INPUT);
  pinMode(3,OUTPUT);
  }
  
int get_axis(const int axis) {
 delay(1);
 buffer[axis][buffer_pos[axis]] = analogRead(PINS[axis]);
 buffer_pos[axis] = (buffer_pos[axis] + 1) % BUFFER_SIZE;
 long sum = 0;
 for (unsigned int i = 0; i < BUFFER_SIZE; i++)
 sum += buffer[axis][i];
 return round(sum / BUFFER_SIZE);

}
int get_x() { return get_axis(0); }
int get_y() { return get_axis(1); }
int get_z() { return get_axis(2); }

int savex;
int savey;
int savez;
int alarm = 0;
int mode=0;
void loop() {
 Serial.print(get_x());
 Serial.print(" ");
 Serial.print(get_y());
 Serial.print(" ");
 Serial.println(get_z());

 // check button
int pressl = digitalRead(bl);
if(pressl == HIGH){
 savex=get_x();
 savey=get_y();
 savez=get_z();
 mode=1;
 Serial.print("KUAY");
}

//check alarm
if(mode == 1){
  if(get_x()>savex+100 ||get_y()>savex+100 ||get_z()>savex+100 ||get_x()<savex-100||get_y()<savey-100||get_z()<savez-100 ){
    alarm = 1;
  }
}

 //alarm sound 
  if(alarm == 1){
      tone(3,294,500);
     
 }

}

