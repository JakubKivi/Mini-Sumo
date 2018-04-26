const int F = 4;
const int FR = 3;
const int FL = 0;
const int B = 2;
const int BL = 7;
const int BR = 1;
const int PWMA = 5;
const int PWMB = 6;

const int TFL = A3;
const int TFR = A2;
const int TBL = A1;
const int TBR = A0;
int t = 3;
int MAX = 255;

bool direction = 1; 

void goFront(int x){
  direction = true;
  digitalWrite(PWMA, x);
  digitalWrite(PWMB, x);  
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  delay(t);
}
void goBack(int x){
  direction = false;
  digitalWrite(PWMA, x);
  digitalWrite(PWMB, x);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(t);
}
void goLeft(){
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(t);
}
void goRight(){
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  delay(t);
}

void go(bool x, int y){
  if(x)goFront(y);
  else goBack(y);
}

void stop(){
       digitalWrite(10, LOW);
       digitalWrite(11, LOW);
       digitalWrite(12, LOW);
       digitalWrite(13, LOW);
}


void follow(){
  if(digitalRead(F)==LOW)   goFront(MAX);   
  else if(digitalRead(B)==LOW)   goBack(MAX);    
  else if(digitalRead(FL)==LOW)  goLeft();   
  else if(digitalRead(FR)==LOW)  goRight();  
  else if(digitalRead(BR)==LOW)  goRight();  
  else if(digitalRead(BL)==LOW)  goLeft();  
  
}

bool endF(){
  return analogRead(TFL) < 100 || analogRead(TFR) < 100;
}
bool endB(){
  return analogRead(TBL) < 100 || analogRead(TBR) < 100;
}

bool see(){
  return digitalRead(F) || digitalRead(B) || digitalRead(FR) ||digitalRead(FL) ||digitalRead(BL) ||digitalRead(BR);
}



