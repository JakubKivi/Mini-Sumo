

//floor sensor
#define floorFL A0 	//front left 
#define floorFR	A1	//front right
#define floorBL	A2	//back
#define floorBR A3
//distance sensor front
#define sensorFR 3
#define sensorBR 4
#define sensorB 2
#define sensorBL 1
#define sensorFL 7
#define sensorF 0

//motor
#define AIN1 9
#define AIN2 10
#define BIN1 12
#define	BIN2 13
#define PWMA 8 
#define PWMB 7

bool direction = true;
int speed; 
int d=50;         //=== 50 jest chwilowe potem ustalimy na pods testów ===\\

bool check(int pin){
  if (analogRead(pin)>10) return 1;
  else return 0;
}

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
  digitalWrite(AIN1, LOW);
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
  digitalWrite(BIN2, LOW);
  digitalWrite(BIN1, LOW);
  
  analogWrite(PWMA, speed-d);  
  analogWrite(PWMB, speed);
  }
void goBackwardRight(){
  digitalWrite(AIN2, LOW);
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
    digitalWrite(BIN2, LOW);   //jade w przód
    if(vector){
        analogWrite(PWMB, speed-d);
        analogWrite(PWMA, speed); //ale skręcam trochę w lewo
    }else{
      analogWrite(PWMB, speed);
      analogWrite(PWMA, speed-d);   //albo troche w prawo
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

    /*if((digitalRead(floorFL)||digitalRead(floorBL))&&(digitalRead(sensorB)||digitalRead(sensorBR)||digitalRead(sensorBL)))
    goBackwardRight();
    
    else if((digitalRead(floorFL)||digitalRead(floorBL))&&(digitalRead(sensorF)||digitalRead(sensorFR)||digitalRead(sensorFL)))
    goBackwardRight();
    
    else if((digitalRead(floorFR)||digitalRead(floorBR))&&(digitalRead(sensorB)||digitalRead(sensorBR)||digitalRead(sensorBL)))
    goForwardLeft();
    
    else if((digitalRead(floorFR)||digitalRead(floorBR))&&(digitalRead(sensorF)||digitalRead(sensorFR)||digitalRead(sensorFL)))
    goBackwardLeft();*/
    


void go(){   //jedź just jedź        
  if(direction) goForward();
  else goBackword();
}

bool touchFloor(){                //czy dotyka podłogi
  return  check(floorFL)  ||
      check(floorFR)  ||
      check(floorBR)  ||
      check(floorBL);
}

bool seeEnemy(){                  //czy widzi przeciwnika
  return  digitalRead(sensorF)  ||
      check(sensorFL)     ||
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

void outOfLine(){
     if(check(floorFL)^check(floorBL)^check(floorFR)^check(floorBR)){
        if(check(floorFL)) goBackwardRight();
        if(check(floorFR)) goBackwardLeft();
        if(check(floorBL)) goForwardRight();
        if(check(floorBR)) goForwardLeft();
     }else if(check(floorFL)&&check(floorBL)){
      if(seeEnemy){
        
      }else{
          digitalWrite(AIN2, HIGH);
          digitalWrite(AIN1, LOW);
          digitalWrite(BIN2, LOW);
          digitalWrite(BIN1, HIGH);
  
          analogWrite(PWMB, speed);  
          analogWrite(PWMA, speed);
      }
      
    }
    else if(check(floorFL)&&check(floorFR)) goBackword();
    else if(check(floorBR)&&check(floorBL)) goForward();
    else{ 
      digitalWrite(AIN2, HIGH);
      digitalWrite(AIN1, LOW);
      digitalWrite(BIN2, LOW);
      digitalWrite(BIN1, HIGH);
  
      analogWrite(PWMB, speed);  
      analogWrite(PWMA, speed);
    }
}


