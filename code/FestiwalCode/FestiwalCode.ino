#include "header.h"
 int lol = 250;
void setup() { 
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(F, INPUT);
  pinMode(B, INPUT);
  pinMode(FL, INPUT);
  pinMode(FR, INPUT);
  pinMode(BL, INPUT);
  pinMode(BR, INPUT);
 /* bool elo(){
    return (analogRead(TBL) < 100 || analogRead(TBR) < 100  || analogRead(TFL) < 100 || analogRead(TFR) < 100) == LOW || (digitalRead(F) && digitalRead(B) && digitalRead(FR) && digitalRead(FL) &&digitalRead(BL) && digitalRead(BR)) == true);
  }*/
  //goFront(((MAX/4)*3));
  delay(5000);
  while(((analogRead(TBL) < 100 || analogRead(TBR) < 100  || analogRead(TFL) < 100 || analogRead(TFR) < 100) == false) && (digitalRead(F) && digitalRead(B) && digitalRead(FR) && digitalRead(FL) &&digitalRead(BL) && digitalRead(BR)) == true){
    go(direction, MAX);
  }
}




void loop() {
 
 if(analogRead(TFL) < 100 || analogRead(TFR) < 100){
    stop();
    if(direction) direction = false;
    else direction = true;
    go(direction, MAX);
    delay(lol);
    
  } 
  else if(analogRead(TBL) < 100 || analogRead(TBR) < 100){
    stop();
    if(direction) direction = false;
    else direction = true;
    go(direction, MAX);
    delay(lol);
    
  }
  else if(see){ 
    stop();
    follow();
    
  }
  else{
    stop();
    while(((analogRead(TBL) < 100 || analogRead(TBR) < 100  || analogRead(TFL) < 100 || analogRead(TFR) < 100) == false) && (digitalRead(F) &&
    digitalRead(B) && digitalRead(FR) && digitalRead(FL) &&digitalRead(BL) && digitalRead(BR)) == true){
      go(direction, MAX);
    }

  }
  
  
  /*if(endF){
    go(direction, MAX);
    if(direction) direction=0;
    else direction = 1;
  }
  else if(endB){
    go(direction, MAX);
    if(direction) direction=0;
    else direction = 1;
  }
  else if(see){
    follow();
  }
  else{
    go(direction, ((MAX/4)*3));
  }*/
  
  
  /*if(endF)        goBack(MAX);
  else if(endB)   goFront(MAX);
  follow();
  stop();*/
}


