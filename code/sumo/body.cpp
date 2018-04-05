#include "header.h"



bool touchFloor{								//czy dotyka podłogi
	return 	digitalRead(floorFL) 	||
			digitalRead(floorFR) 	|| 
			digitalRead(floorBR) 	|| 
			digitalRead(floorBL);
}

bool seeEnemy{									//czy widzi przeciwnika
	return 	digitalRead(sensorF) 	||
			digitalRead(sensorFL) 	|| 
			digitalRead(sensorFR) 	||
			digitalRead(sensorB) 	||
			digitalRead(sensorBL) 	|| 
			digitalRead(floorBR);
}

void toSeeEnemyFront(speed){							//zrób tak żeby przeciwnik był nawprost
	//jest tutaj pętna w której nie sprawdzamy czy wyleciał z ringu.
	//do{
		if(digitalRead(sensorFL)) goFowardLeft(speed/*slow*/);		//skręć w lewo przodem az sensorF is true
		if(digitalRead(sensorFP)) goFowardRight(speed/*slow*/);		//skręć w prawo przodem az sensorF is true
		if(digitalRead(sensorBL)) goBackwardLeft(speed/*slow*/); 	//skręć w lewo tyłem az sensorB is true		
		if(digitalRead(sensorBR)) goBackwordRight(speed/*slow*/);	//skręć w prawo tyłem az sensorB is true		
	//}while(digitalRead(sensorB) || digitalRead(sensorF))
}

void go(bool direction, speed){ 	//jedź just jedź				
	if(direction) goFoward(speed);
	else goBackword(speed);
}

//sterowanie silnika
void goFoward(int speed){}
void goFowardLeft(int speed){}
void goFowardRight(int speed){}
void goBackword(int speed){}
void goBackwordLeft(int speed){}
void goBackwordRight(int speed){}
void stop(bool direction){} //zatrzymywanie się tyłem przodem???? jest jakaś różnica?