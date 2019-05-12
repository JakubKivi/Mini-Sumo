#include "Arduino.h"
#include "../lib/IRremote/IRremote.h"

IRrecv irrecv(8);
decode_results results;

//distance sensor front
#define sensorF 0
#define sensorFL 3
#define sensorFR 2
#define sensorB 7
#define sensorBL 1
#define sensorBR 4

#define floorBL 13
#define floorBR 12
#define floorFL 11
#define floorFR 10		//nie jestem pewny czy dobrze są lewy prawy ale to nieważne

//motor

#define AIN1 12
#define AIN2 13
#define BIN1 10
#define	BIN2 11



bool direction = true;
#define direction_TOG direction ^= true;
int speed;
int p=0;         //============== 50 jest chwilowe potem ustalimy na pods testów ======================\\

void error(int errorNr){
		digitalWrite(AIN1, 0);
		digitalWrite(AIN2, 0);
    digitalWrite(BIN1, 0);
    digitalWrite(BIN2, 0);

		while(true){
			for (int i = 0; i < errorNr; ++i){
				digitalWrite(9,LOW);
				delay(200);
				digitalWrite(9,HIGH);
				delay(200);
			}
			delay(2000);

			//Serial.println(program);
		}
	}

bool check(int pin){
  if (analogRead(pin)>500) return 1;
  else return 0;
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

void goBackward(){
  digitalWrite(AIN1, 0);
  digitalWrite(AIN2, 1);
  digitalWrite(BIN1, 0);
  digitalWrite(BIN2, 1);
}

void goForward(){
  digitalWrite(AIN1, 1);
  digitalWrite(AIN2, 0);
  digitalWrite(BIN1, 1);
  digitalWrite(BIN2, 0);
}

void spin(){
    /*Ma1_OFF;
    Ma2_ON;
    Mb1_ON;
    Mb2_OFF;*/
    digitalWrite(AIN1, 1);
    digitalWrite(AIN2, 0);
    digitalWrite(BIN1, 0);
    digitalWrite(BIN2, 1);
    delay(1);
    slowStop();
    delay(3);
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

  }else if(x==3){

        if(direction){
            goForward();
          	delay(100);
						slowStop();
						digitalWrite(BIN2, 1);
						delay(100);
						slowStop();
						delay(1);
        }else if(!direction){
						goBackward();
						delay(100);
						slowStop();
						digitalWrite(AIN1, 1);
						delay(100);
						slowStop();
						delay(1);
        }else error(11);

  }else if (x==2){

        if(direction){
						goForward();
						delay(100);
						slowStop();
						digitalWrite(AIN2, 1);
						delay(100);
						slowStop();
						delay(1);
        }else if(!direction){
						goBackward();
						delay(100);
						slowStop();
						digitalWrite(BIN1, 1);
						delay(100);
						slowStop();
						delay(1);
        }else error(12);

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
  if(digitalRead(sensorF) && digitalRead(sensorFL) && digitalRead(sensorFR) && digitalRead(sensorB) ) return 0;
	return 1;
  /*if(!digitalRead(sensorFR) || !digitalRead(sensorBR)) direction=0;
  else if(!sensorFR || !sensorFL) direction=1;

  if(!digitalRead(sensorFL)||!digitalRead(sensorBR)){
    while(sensorF && sensorB){
      if(!go(2)) return 0;
    }
    return 1;
  }

  else if(!digitalRead(sensorFR)||!digitalRead(sensorBL)){
    while(sensorF && sensorB){
      if(!go(3)) return 0;
    }
    return 1;
  }*/
}


byte irRemoute ()
{
byte dane=0;
  while(dane==0)
{
   if (irrecv.decode(&results)) // sprawdza, czy otrzymano sygna� IR
{
       unsigned long odczyt = results.value; // sygnał zapisuje jako odczyt
switch (odczyt)
       {
case 1857: //power
  dane = 1;
break;
         case 3905: //eneter
dane = 1;
    break;

default:
         dane=0;
}
      irrecv.resume(); // reseruje czujnik
}
   else
{
    dane=0;
}
  }
return dane ;
}
