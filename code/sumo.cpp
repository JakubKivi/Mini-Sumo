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
	if(!touchFloor){
		if(!seeEnemy){
			//jedź se do przodu
		}
		else{
			//zrób tak, żeby było go widać z przodu
		}
	}
	else{
		//stop zmiana kierunku 
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

	//Tutaj jest taki przypix, że będzie się w kółko kręcił

	if(digitalRead(sensorFL)){
		do{										//skręć w lewo przodem az sensorF is true
			goFowardLeft(/*slow*/);
		}while(digitalRead(sensorF))
	}
	if(digitalRead(sensorFP)){				
		do{										//skręć w prawo przodem az sensorF is true
			goFowardRight(/*slow*/);
		}while(digitalRead(sensorF))
	}
	if(digitalRead(sensorBL)){
		do{										//skręć w lewo tyłem az sensorB is true
			goBackwardLeft(/*slow*/);
		}while(digitalRead(sensorB))
	}				
	if(digitalRead(sensorBR)){
		do{										//skręć w prawo tyłem az sensorB is true
			goBackwordRight(/*slow*/);
		}while(digitalRead(sensorB))
	}					
}

//sterowanie silnika
void goFoward(int speed){}
void goFowardLeft(int speed){}
void goFowardRight(int speed){}
void goBackword(int speed){}
void goBackwordLeft(int speed){}
void goBackwordRight(int speed){}