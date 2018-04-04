#define floorFL  	//front left 
#define floorFR		//front right
#define floorBL		//back
#define floorBR

#define sensorF 	//distance sensor front
#define sensorFL
#define sensorFR
#define sensorB
#define sensorBL
#define sensorBR



bool direction = true;
int speed; 



void setup(){
	//czujniki podłogowe
	pinMode(floorFL, INPUT);
	pinMode(floorFR, INPUT);
	pinMode(floorBL, INPUT);
	pinMode(floorBR, INPUT);

	//czujniki odległości
	pinMode(sensorF, INPUT);
	pinMode(sensorFL, INPUT);
	pinMode(sensorFR, INPUT);
	pinMode(sensorB, INPUT);
	pinMode(sensorBR, INPUT);
	pinMode(sensorBL, INPUT);

	
}

void loop{

	if(!touchFloor){													//jeżeli nie dotykasz krawędzi
		if(!seeEnemy){													//jeśli nie widzisz przeciwnika
			go(direction, speed);
		}
		else if(!digitalRead(sensorB) || !digitalRead(sensorF)){ 		//jeżeli nie widać go z przodu bądź tyłu
			//zrób tak, żeby było go widać z przodu lub tyłu
			toSeeEnemyFront();
		}
		else go(direction, speed /*szybko*/);
	}
	else{
		//stop zmiana kierunku
		stop();
		if(direction) direction = false;
		else direction = true;
	}

}



bool touchFloor{
	return 	digitalRead(floorFL) 	||
			digitalRead(floorFR) 	|| 
			digitalRead(floorBR) 	|| 
			digitalRead(floorBL);
}
bool seeEnemy{
	return 	digitalRead(sensorF) 	||
			digitalRead(sensorFL) 	|| 
			digitalRead(sensorFR) 	||
			digitalRead(sensorB) 	||
			digitalRead(sensorBL) 	|| 
			digitalRead(floorBR);
}

void toSeeEnemyFront(){
	//jest tutaj pętna w której nie sprawdzamy czy wyleciał z ringu.
	//do{
		if(digitalRead(sensorFL)) goFowardLeft(/*slow*/);		//skręć w lewo przodem az sensorF is true
		if(digitalRead(sensorFP)) goFowardRight(/*slow*/);		//skręć w prawo przodem az sensorF is true
		if(digitalRead(sensorBL)) goBackwardLeft(/*slow*/); 	//skręć w lewo tyłem az sensorB is true		
		if(digitalRead(sensorBR)) goBackwordRight(/*slow*/);	//skręć w prawo tyłem az sensorB is true		
	//}while(digitalRead(sensorB) || digitalRead(sensorF))
}

//sterowanie silnika
void goFoward(int speed){}
void goFowardLeft(int speed){}
void goFowardRight(int speed){}
void goBackword(int speed){}
void goBackwordLeft(int speed){}
void goBackwordRight(int speed){}
void stop(bool direction){} //zatrzymywanie się tyłem przodem???? jest jakaś różnica?


void go(bool direction, speed){ //jak pobrać zmienną globalną???
	if(direction) goFoward(speed);
	else goBackword(speed);
}