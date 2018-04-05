#define floorFL  1	//front left 
#define floorFR	2//front right
#define floorBL	3	//back
#define floorBR 4

#define sensorF 5	//distance sensor front
#define sensorFL 6
#define sensorFR 7
#define sensorB 8
#define sensorBL 9
#define sensorBR 10



void setup() {
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

void loop() {
	if(!touchFloor){
		//jedzie sobie
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



bool touchFloor() {
	if      (digitalRead(floorFL) 	||
			digitalRead(floorFR) 	|| 
			digitalRead(floorBR) 	|| 
			digitalRead(floorBL))
	        return 1;
	else    return 0;
}
bool seeEnemy() {
    if      (digitalRead(sensorF) 	||
            digitalRead(sensorFL) 	||
            digitalRead(sensorFR) 	||
            digitalRead(sensorB) 	||
            digitalRead(sensorBL))
            return 1;
    else    return 0;
}

/*void toSeeEnemyFront() {
	if(sensorFL){
		//skręć w lewo az sensorF is true
		do{

		}while()
	}
	if(sensorFP)//skręć w prawo
	if(sensorBL)//skręć w lewo tyłem
	if(sensorBR)//skręć w prawo tyłem 
}*/ //nie podoba mi się to wcale ~Kivi
