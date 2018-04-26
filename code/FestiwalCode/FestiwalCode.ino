#include "header.h"

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
  
  //goFront(((MAX/4)*3));  
}




void loop() {
  
  if(analogRead(TFL) < 100 || analogRead(TFR) < 100){
    stop();
    if(direction) direction = false;
    else direction = true;
    go(direction, MAX);
    delay(500);
  } 
  else if(analogRead(TBL) < 100 || analogRead(TBR) < 100){
    stop();
    if(direction) direction = false;
    else direction = true;
    go(direction, MAX);
    delay(500);
  }
  else if(see) follow();
  //else go(direction, MAX);
  
  stop();
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


