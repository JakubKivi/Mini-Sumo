#include "header.h"

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

	//silnik
	pinMode(AIN1, OUTPUT);
	pinMode(AIN2, OUTPUT);
	pinMode(BIN1, OUTPUT);
	pinMode(BIN2, OUTPUT);
	pinMode(PWMA, OUTPUT);
	pinMode(PWMB, OUTPUT);
	pinMode(STBY, OUTPUT);

}

void loop(){
	if(!touchFloor){													//jeżeli nie dotykasz krawędzi
		if(seeEnemieNotFront()){													//jeśli nie widzisz przeciwnika
			toSeeEnemyFront();    
		}else if((seeEnemy)){ 		//jeżeli nie widać go z przodu bądź tyłu
			go();		
		}else //wogóle nie mam pojęcia gdzie jest ziomek przeciwnik
      goRandomly();
	}else{  //jak jestem na liniiii
		//zmiana kierunku
		if(direction) direction = false;
		else direction = true;
    outOfLine();
    //zrobić coś żeby nie było akcji że jedzie wzdłóż linii (np skręć zależy)
	}
}











