#include "Arduino.h"

//distance sensor front
#define sensorF 5
#define sensorFL 0
#define sensorFR 2
#define sensorB 1
#define sensorBL 8
#define sensorBR 4

//motor

#define AIN1 9
#define AIN2 10
#define BIN1 11
#define	BIN2 12

bool direction = true;
int speed;
int p=50;         //============== 50 jest chwilowe potem ustalimy na pods testów ======================\\

bool check(int pin){
  if (analogRead(pin)>500) return 1;
  else return 0;
}
void error(int x){
  while(true);
}
void slowStop(){
  digitalWrite(AIN1, 0);
  digitalWrite(AIN2, 0);
  digitalWrite(BIN1, 0);
  digitalWrite(BIN2, 0);
}

void hardStop(){
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 1);
  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 1);
}

void goForward(){
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 0);
  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 0);
}

void goBackward(){
  digitalWrite(AIN1, 0);
  digitalWrite(AIN2, 1);
  digitalWrite(BIN1, 0);
  digitalWrite(BIN2, 1);
}

//sterowanie silnika
bool go(int x){   //0 - full   1 - optimal 2 -  left 3 -right
  if(x==0){
        direction?goForward():goBackward();
  }else if(x==1){

        if(direction){

              goForward();
            //  if(floorSensors(direction)) return 0;
              delayMicroseconds(p);
              slowStop();
            //  if(floorSensors(direction)) return 0;
              delayMicroseconds(100-p);

        }else if(!direction){

              goBackward();
            //  if(floorSensors(direction)) return 0;
              delayMicroseconds(p);
              slowStop();
          //    if(floorSensors(direction)) return 0;
              delayMicroseconds(100-p);

        }else error(9);

  }else if(x==2){

        if(direction){
            goForward();
          //  if(floorSensors(direction)) return 0;
            delayMicroseconds(100);
            slowStop();
            digitalWrite(AIN1, 1);
        //    if(floorSensors(direction)) return 0;
            delay(1);
            slowStop();
        ///    if(floorSensors(direction)) return 0;
            delayMicroseconds(100);

        }else if(!direction){
          goBackward();
        //  if(floorSensors(direction)) return 0;
          delayMicroseconds(100);
          slowStop();

          digitalWrite(AIN1, 1);
        //  if(floorSensors(direction)) return 0;
          delay(1);
          slowStop();
        //  if(floorSensors(direction)) return 0;
          delayMicroseconds(100);
        }else error(11);

  }else if (x==3){

        if(direction){
            goForward();
          ///  if(floorSensors(direction)) return 0;
            delayMicroseconds(100);
            slowStop();

            digitalWrite(AIN2, 1);
            //if(floorSensors(direction)) return 0;
            delay(1);
            slowStop();
          //  if(floorSensors(direction)) return 0;
            delayMicroseconds(100);
        }else if(!direction){
            goBackward();
            //if(floorSensors(direction)) return 0;
            delayMicroseconds(100);
            slowStop();

            digitalWrite(BIN1, 1);
            //if(floorSensors(direction)) return 0;
            delay(1);
            slowStop();
            //if(floorSensors(direction)) return 0;
            delayMicroseconds(100);
        }else error(12);

  }
  else if(x==4){
    if(direction){
      for(int i = p; i < 101; i++){
        goForward();
        //if(floorSensors(direction)) return 0;
        delayMicroseconds(p);
        slowStop();
        //if(floorSensors(direction)) return 0;
        delayMicroseconds(100-p);
      }
    }
    else if(!direction){
      for(int i = p; i < 101; i++){
        goBackward();
        //if(floorSensors(direction)) return 0;
        delayMicroseconds(p);
        slowStop();
        //if(floorSensors(direction)) return 0;
        delayMicroseconds(100-p);
      }
    }
    else error(15);

  }
  else error(13);
  return 1;
}


bool seeEnemy(){                  //czy widzi przeciwnika
  return  digitalRead(sensorF)  ||
      digitalRead(sensorFR)     ||
      digitalRead(sensorB)      ||
      digitalRead(sensorBL);
}

bool toSeeFront(){

    //if(!disA || !disB) return 1;
  if(sensorF && sensorFL && sensorFR && sensorB && sensorBR && sensorBR) return 0;

  if(!sensorFR || !sensorBR) direction=0;
  else if(!sensorFR || !sensorFL) direction=1;

  if(!sensorFL||!sensorBR){
    while(sensorF && sensorB){
      if(!go(2)) return 0;
    }
    return 1;
  }

  else if(!sensorFR||!sensorBL){
    while(sensorF && sensorB){
      if(!go(3)) return 0;
    }
    return 1;
  }
}
