#define walkbutton 4
#define we_button 3
#define ns_button 2

#define walk_r 11
#define walk_g 12

#define ns_r 5
#define ns_y 6
#define ns_g 7

#define we_r 8
#define we_y 9
#define we_g 10

#define goS 0
#define waitS 1
#define goW 2
#define waitW 3
#define walkG 4 
#define walkW 5

struct State {
 unsigned long ST_Out; // 6-bit pattern to street output
 unsigned long Time; // delay in ms units
 unsigned long Next[8];}; // next state for inputs 0,1,2,3
 typedef const struct State SType;

SType FSM[6]={
{0x79,2000,{goS,waitS,waitS,waitS,goS,waitS,waitS,waitS}},
{0x75,150,{goW,walkG,goW,walkG,goW,walkG,goW,goW}},
{0xCD,2000,{goW,waitW,goW,waitW,waitW,waitW,waitW,waitW}},
{0xAD,150,{goS,walkG,goS,walkG,goS,walkG,goS,walkG}},
{0x6E,2000,{walkG,walkG,walkW,walkW,walkW,walkW,walkW,walkW}},
{0x6D,150,{goS,goS,goW,goW,goS,goS,goS,goS}}
};

unsigned long S=0; // index to the current state
void setup() {
 pinMode(ns_r, OUTPUT);
 pinMode(ns_y, OUTPUT);
 pinMode(ns_g, OUTPUT);
 pinMode(ns_button, INPUT);

 pinMode(we_r, OUTPUT);
 pinMode(we_y, OUTPUT);
 pinMode(we_g, OUTPUT);
 pinMode(we_button, INPUT);

 pinMode(walk_r,OUTPUT);
 pinMode(walk_g,OUTPUT);
 pinMode(walkbutton,INPUT);
 
}

int input,input1, input2, input3;
void loop() {
 digitalWrite(walk_g, FSM[S].ST_Out & B00000001);
 digitalWrite(walk_r, FSM[S].ST_Out & B00000010);
 digitalWrite(ns_g, FSM[S].ST_Out & B00000100);
 digitalWrite(ns_y, FSM[S].ST_Out & B00001000);
 digitalWrite(ns_r, FSM[S].ST_Out & B00010000);
 digitalWrite(we_g, FSM[S].ST_Out & B00100000);
 digitalWrite(we_y, FSM[S].ST_Out & B01000000);
 digitalWrite(we_r, FSM[S].ST_Out & B10000000);
 delay(FSM[S].Time);

 if((S == 4 && digitalRead(we_button) != LOW)||(S == 4 && digitalRead(ns_button) != LOW)){
   for(int i=0;i<=3;i++){
 digitalWrite(walk_g,HIGH);
 delay(100);
 digitalWrite(walk_g,LOW);
 delay(100);
 }
 }

 input1 = digitalRead(walkbutton);
 input2 = digitalRead(we_button);
 input3 = digitalRead(ns_button);
 input = input3*4+input2*2+input1;
 S = FSM[S].Next[input];


}
