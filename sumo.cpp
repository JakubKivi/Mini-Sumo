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
	pinMode(floorFL, INPUT);
	pinMode(floorFR, INPUT);
	pinMode(floorBL, INPUT);
	pinMode(floorBR, INPUT);
	
}

void loop{
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
	if(sensorFL){
		//skręć w lewo az sensorF is true
		do{

		}while()
	}
	if(sensorFP)//skręć w prawo
	if(sensorBL)//skręć w lewo tyłem
	if(sensorBR)//skręć w prawo tyłem 
}