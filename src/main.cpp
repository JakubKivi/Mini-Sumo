#include "header.h"

void setup(){
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

	//Led
	pinMode(8, OUTPUT);

	slowStop(); //for safety
}

void loop(){
	builtLed1_ON;
	delay(3000);
	builtLed1_OFF;

	go(2);
	delay(1000);
	go(3);
	delay(1000);
	direction_TOG;
	go(2);
	delay(1000);
	go(3);
	delay(1000);
	direction_TOG;


}
