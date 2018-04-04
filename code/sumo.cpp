//floor sensor
#define floorFL  	//front left 
#define floorFR		//front right
#define floorBL		//back
#define floorBR
//distance sensor front
#define sensorF 	
#define sensorFL
#define sensorFR
#define sensorB
#define sensorBL
#define sensorBR

//motor
#define AIN1
#define AIN2
#define BIN1
#define	BIN2
#define PWMA
#define PWMB
#define STBY


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











