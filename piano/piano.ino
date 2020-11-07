
//note
#define NOTE_C4 262 // เสียงโด (กลาง)
#define NOTE_D4 294 // เสียงเร (กลาง)
#define NOTE_E4 330 // เสียงมี (กลาง)
#define NOTE_F4 349 // เสียงฟา (กลาง)
#define NOTE_G4 392 // เสียงซอล (กลาง)
#define NOTE_A4 440 // เสียงลา (กลาง)
#define NOTE_B4 494 // เสียงที (กลาง)
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
//button
#define c 2
#define d 12
#define e 4
#define f 5
#define g 6
#define a 7
#define b 8
#define C 9
#define D 10 
#define E 11

//speaker
#define speaker 3


void setup() {
Serial.begin(9600); 
pinMode(2,INPUT);
pinMode(12,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);
pinMode(9,INPUT);
pinMode(10,INPUT);
pinMode(11,INPUT);
pinMode(3,OUTPUT);
}

void loop() {


  if(digitalRead(2) == LOW ){
      tone(3,262);
      Serial.print("HOLD");
     
      
  }

  else if(digitalRead(12) == LOW ){ 
      tone(3,294);
      Serial.print("HOLD2");
      delay(100);
  }
 
  else if(digitalRead(4) == LOW ){
      tone(3,330);
      Serial.print("HOLD3");
  }
  else if(digitalRead(5) == LOW ){
      tone(3,349);
      Serial.print("HOLD4");
}
 
  else if(digitalRead(6) == LOW ){
      tone(3,392);
      Serial.print("HOLD5");
}

  else if(digitalRead(7) == LOW ){
      tone(3,440);
      Serial.print("HOLD6");
}
 
  else if(digitalRead(8) == LOW ){
      tone(3,494);
      Serial.print("HOLD7");
}

  else if(digitalRead(9) == LOW ){
      tone(3,523);
      Serial.print("HOLD8");
}

  else if(digitalRead(10) == LOW ){
      tone(3,587);
      Serial.print("HOLD9");
}
 
  else if(digitalRead(11) == LOW ){
      tone(3,659);
      Serial.print("HOLD10");
}
  else{
    noTone(3);
    Serial.print("noHOLD");
  }
}

  


