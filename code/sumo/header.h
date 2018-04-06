

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
#define AIN2 12       //na razie a to Lewy b to Prawy 1 to przód 2 tył
#define BIN1 13
#define	BIN2 14
#define PWMA 15 
#define PWMB 16
#define STBY 17

bool direction = true;
int speed; 
int d=50;         //============== 50 jest chwilowe potem ustalimy na pods testów ======================//

//sterowanie silnika
void goForward(){
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  
  analogWrite(PWMA, speed);  
  analogWrite(PWMB, speed); 
 }

void goForwardLeft(){
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  
  analogWrite(PWMA, speed-d);  
  analogWrite(PWMB, speed); 
  }
  
void goForwardRight(){
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  
  analogWrite(PWMB, speed-d); 
  analogWrite(PWMA, speed);
  }
void goBackword(){
  digitalWrite(AIN2, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(BIN1, LOW);
  
  analogWrite(PWMA, speed);
  analogWrite(PWMB, speed);
  }
void goBackwardLeft(){
  digitalWrite(AIN2, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(BIN1, LOW);
  
  analogWrite(PWMA, speed-d);  
  analogWrite(PWMB, speed);
  }
void goBackwardRight(){
  digitalWrite(AIN2, HIGH);
  digitalWrite(AIN1, LOW);
  digitalWrite(BIN2, HIGH);
  digitalWrite(BIN1, LOW);
  
  analogWrite(PWMB, speed-d);  
  analogWrite(PWMA, speed);
  }
void goRandomly(){
  bool vector= random(0, 1);
  if(direction){  
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    if(vector){
        analogWrite(PWMB, speed-d);
        analogWrite(PWMA, speed);
    }else{
      analogWrite(PWMB, speed);
      analogWrite(PWMA, speed-d);
    }
  }else{
    digitalWrite(AIN2, HIGH);
    digitalWrite(AIN1, LOW);
    digitalWrite(BIN2, HIGH);
    digitalWrite(BIN1, LOW);
    if(vector){
      analogWrite(PWMB, speed-d);
      analogWrite(PWMA, speed);
    }else{
      analogWrite(PWMB, speed);
      analogWrite(PWMA, speed-d);
    }
  }
  }
void outOfLine(){
     if(digitalRead(floorFL)^digitalRead(floorBL)^digitalRead(floorFR)^digitalRead(floorBR)){
        if(digitalRead(floorFL)) goBackwardRight();
        if(digitalRead(floorFR)) goBackwardLeft();
        if(digitalRead(floorBL)) goForwardRight();
        if(digitalRead(floorBR)) goForwardLeft();
    else if(digitalRead(floorFL)&&digitalRead(floorBL)) 
    else if(digitalRead(floorFL)&&digitalRead(floorFR)) goBackward();
    else if(digitalRead(floorFR)&&digitalRead(floorBR)) 
    else if(digitalRead(floorBR)&&digitalRead(floorBL)) goForward();
    
     }
    /*if((digitalRead(floorFL)||digitalRead(floorBL))&&(digitalRead(sensorB)||digitalRead(sensorBR)||digitalRead(sensorBL)))
    goBackwardRight();
    
    else if((digitalRead(floorFL)||digitalRead(floorBL))&&(digitalRead(sensorF)||digitalRead(sensorFR)||digitalRead(sensorFL)))
    goBackwardRight();
    
    else if((digitalRead(floorFR)||digitalRead(floorBR))&&(digitalRead(sensorB)||digitalRead(sensorBR)||digitalRead(sensorBL)))
    goForwardLeft();
    
    else if((digitalRead(floorFR)||digitalRead(floorBR))&&(digitalRead(sensorF)||digitalRead(sensorFR)||digitalRead(sensorFL)))
    goBackwardLeft();*/
    
}

void go(){   //jedź just jedź        
  if(direction) goForward();
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
    if(digitalRead(sensorFL)) goForwardLeft();    //skręć w lewo przodem az sensorF is true
    if(digitalRead(sensorFR)) goForwardRight();   //skręć w prawo przodem az sensorF is true
    if(digitalRead(sensorBL)) goBackwardLeft();  //skręć w lewo tyłem az sensorB is true   
    if(digitalRead(sensorBR)) goBackwardRight(); //skręć w prawo tyłem az sensorB is true    

}



