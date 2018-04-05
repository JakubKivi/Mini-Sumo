
bool direction = true;
int speed; 
bool touchFloor; 					//czy dotyka podłogi
bool seeEnemy;						//czy widzi przeciwnika
void toSeeEnemyFront(speed);		//zrób tak żeby przeciwnik był nawprost
void go(bool direction, speed); 	//jedź just jedź				jak pobrać zmienną globalną???





//sterowanie silnika
void goFoward(int speed);
void goFowardLeft(int speed);
void goFowardRight(int speed);
void goBackword(int speed);
void goBackwordLeft(int speed);
void goBackwordRight(int speed);
void stop(bool direction); //zatrzymywanie się tyłem przodem???? jest jakaś różnica?