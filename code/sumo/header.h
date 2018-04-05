//floor sensor
#define floorFL 1 	//front left 
#define floorFR	2	//front right
#define floorBL	3	//back
#define floorBR 4
//distance sensor front
#define sensorF 5	
#define sensorFL 6
#define sensorFR 7
#define sensorB 8
#define sensorBL 9
#define sensorBR 10

//motor
#define AIN1 11
#define AIN2 12
#define BIN1 13
#define	BIN2 14
#define PWMA 15 
#define PWMB 16
#define STBY 17

//sterowanie silnika
void goFowardLeft(){}
void goFowardRight(){}
void goBackword(){}
void goBackwardLeft(){}
void goBackwardRight(){}
void goRandomly(){}
void outOfLine(){}
void stop(){} 
void goFoward(){}

bool direction = true;
int speed; 

void go(){   //jedź just jedź        
  if(direction) goFoward();
  else goBackword();
}

bool touchFloor(){                //czy dotyka podłogi
  return  digitalRead(floorFL)  ||
      digitalRead(floorFR)  ||
      digitalRead(floorBR)  ||
      digitalRead(floorBL);
}

bool seeEnemy(){                  //czy widzi przeciwnika
  return  digitalRead(sensorF)  ||
      digitalRead(sensorFL)     ||
      digitalRead(sensorFR)     ||
      digitalRead(sensorB)      ||
      digitalRead(sensorBL)     ||
      digitalRead(floorBR);
}

bool seeEnemieNotFront(){
  return 
      (digitalRead(sensorFL)    ||
      digitalRead(sensorFR)     ||
      digitalRead(sensorBL)     ||
      digitalRead(floorBR)     )&&
      !digitalRead(sensorB)     &&
      !digitalRead(sensorF);      
}

void toSeeEnemyFront(){              //zrób tak żeby przeciwnik był nawprost
    if(digitalRead(sensorFL)) goFowardLeft();    //skręć w lewo przodem az sensorF is true
    if(digitalRead(sensorFR)) goFowardRight();   //skręć w prawo przodem az sensorF is true
    if(digitalRead(sensorBL)) goBackwardLeft();  //skręć w lewo tyłem az sensorB is true   
    if(digitalRead(sensorBR)) goBackwardRight(); //skręć w prawo tyłem az sensorB is true    

}



