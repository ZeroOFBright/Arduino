int enA = 10;
int in2 = 9;
int in1 = 8;

int turn = 150;

int enB = 5;
int in3 = 6;
int in4 = 7;
int L,R,C;
int M =730;
int m=800;
int p=0;
void setup() {
Serial.begin(9600);
pinMode(enA, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(A0, INPUT);
pinMode(A4, INPUT);
pinMode(A5, INPUT);
}


void loop() {
  R = analogRead(A0);
  L = analogRead(A5);
  C = analogRead(A4);
   Serial.println(C);
  /* if(analogRead(A0)<M && analogRead(A5)<M){
 
     digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
    }
    else if(analogRead(A0)>M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 100);
  
    }
    else if(analogRead(A0)>M && analogRead(A5)>M&& analogRead(A4)>M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 100);
  
    }
    else if(analogRead(A0)<M && analogRead(A5)>M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 100); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
    
    }*/
if(p==0){
    if(analogRead(A0)<M && analogRead(A5)<M){
 
     digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
    }
   else  if(analogRead(A0)>m && analogRead(A5)<M && analogRead(A4)>M){
         digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);

         digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 80); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 80);
     delay(350);

     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);
     analogWrite(enA, 200); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 200);
     delay(180);
     
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     p=1;
    }
    else if(analogRead(A0)>M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, turn);
  
    }
    else if(analogRead(A0)<M && analogRead(A5)>M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA,turn); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
    
    }
}
else if(p==1){
    if(analogRead(A0)<M && analogRead(A5)<M){//เดินหน้า
     digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
    }
    else if(analogRead(A0)>M && analogRead(A5)<M && analogRead(A4)>M){
  digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(500); 
        digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 100); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 132);
      delay(200);
    }
    else if(analogRead(A0)>M&& analogRead(A5)>M && analogRead(A4)>M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000); 
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
    delay(300);

    digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     p=2;
    
    }
    else if(analogRead(A0)>M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, turn);
  
    }
    else if(analogRead(A0)<M && analogRead(A5)>M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, turn); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
    
    }
}
else if(p==2){
   if(analogRead(A0)<m && analogRead(A5)<M && analogRead(A4)<M){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 0); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 0);
    delay(1000);
    
     digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 100); 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 132);
    delay(1300);

      digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 0); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 0);
    delay(1000);
    p=3;
    }
}
else if(p==3){
  if(analogRead(A0)<M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
  }
     else  if(analogRead(A0)>m && analogRead(A5)<M && analogRead(A4)>M){
         digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 80); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 80);
     delay(350);

     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);
     analogWrite(enA, 200); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 200);
     delay(175);
     
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     p=4;
    }
     else if(analogRead(A0)>M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, turn);
  
    }
    else if(analogRead(A0)<M && analogRead(A5)>M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, turn); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
    
    }
}
else if(p==4){
  if(analogRead(A0)<M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
  }
   else if(analogRead(A0)<m && analogRead(A5)>M && analogRead(A4)>M){
         digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
   }
  else if(analogRead(A0)>m && analogRead(A5)>M && analogRead(A4)>M){
       digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     
    digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 80); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 80);
     delay(350);

     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 200); 
     digitalWrite(in3, HIGH);
     digitalWrite(in4, LOW);
     analogWrite(enB, 200);
     delay(190);
     
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     p=5;
  }
   else if(analogRead(A0)>M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, turn);
  
    }
    else if(analogRead(A0)<M && analogRead(A5)>M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, turn); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
    
    }
}
else if(p==5){
  if(analogRead(A0)<M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
  }
  else if(analogRead(A0)<m && analogRead(A5)>M && analogRead(A4)>M){
         digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
   }
  else if(analogRead(A0)>m && analogRead(A5)>M && analogRead(A4)>M){
       digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     
    digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 80); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 80);
     delay(350);

     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 200); 
     digitalWrite(in3, HIGH);
     digitalWrite(in4, LOW);
     analogWrite(enB, 200);
     delay(190);
     
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     p=6;
  }
   else if(analogRead(A0)>M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, turn);
  
    }
    else if(analogRead(A0)<M && analogRead(A5)>M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, turn); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
    
    }
}
else if(p==6){
  if(analogRead(A0)<M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
  }
  else if(analogRead(A0)>m && analogRead(A5)>M && analogRead(A4)>M){
       digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     
    digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 80); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 80);
     delay(350);

     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 200); 
     digitalWrite(in3, HIGH);
     digitalWrite(in4, LOW);
     analogWrite(enB, 200);
     delay(175);
     
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     p=7;
  }
   else if(analogRead(A0)>M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, turn);
  
    }
    else if(analogRead(A0)<M && analogRead(A5)>M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, turn); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
    
    }
}
else if(p==7){
 if(analogRead(A0)<M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
    }
    else if(analogRead(A0)>m && analogRead(A5)>M && analogRead(A4)>M){
     digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
    delay(400);
       digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
    p=8;
    }
    else if(analogRead(A0)>M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, turn);
  
    }
    else if(analogRead(A0)<M && analogRead(A5)>M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, turn); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
    
    }
}
else if(p==8){
   if(analogRead(A0)<m && analogRead(A5)<M && analogRead(A4)<M){

     digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 100); 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 132);
    delay(1100);

         digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 0); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 0);
    delay(1000);
    p=9;
    }
}
else if(p==9){
 if(analogRead(A0)<M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
  }
       else if(analogRead(A0)>M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, turn);
  
    }
    else if(analogRead(A0)<M && analogRead(A5)>M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, turn); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
    
    }
    else  if(analogRead(A0)>m && analogRead(A5)>M && analogRead(A4)>M){
      digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 80); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 80);
     delay(350);

     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);
     analogWrite(enA, 200); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 200);
     delay(330);
     
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     p=10;
    }
}
else if(p==10){
   if(analogRead(A0)<M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
    }
    else if(analogRead(A0)>m && analogRead(A5)>M && analogRead(A4)>M){
      digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 80); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 80);
     delay(350);

     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);
     analogWrite(enA, 200); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 200);
     delay(160);
     
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     p=11;
    }
    else if(analogRead(A0)>M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB,turn);
  
    }
    else if(analogRead(A0)<M && analogRead(A5)>M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, turn); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
    
    }
}
else if(p==11){
  if(analogRead(A0)<M && analogRead(A5)<M){
     digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 100); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 132);
    }
    else if(analogRead(A0)>m && analogRead(A5)>M && analogRead(A4)>M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 80); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 80);
     delay(800);

     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
     delay(1000);
     p=12;
    }
    else if(analogRead(A0)>M && analogRead(A4)<M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, 0); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, turn);
  
    }
    else if(analogRead(A0)<M && analogRead(A4)>M){
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     analogWrite(enA, turn); 
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);
     analogWrite(enB, 0);
    
    }
}
}
