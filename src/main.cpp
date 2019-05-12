#include "header.h"

void setup(){

	irrecv.enableIRIn();
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
	pinMode(9, OUTPUT);
	digitalWrite(9,HIGH);

	for(int i = 0; i < 5; i++){
		digitalWrite(9, 0);
		delay(100);
		digitalWrite(9, 1);
		delay(100);
	}
	delay(4000);
}



void loop(){
bool play=0;
	byte check = irRemoute();
 if (check != 0)
{
	play=1;
  // Tutaj podajemy co ma wykonać dalej z zmienną check jeżeli nie jest ona zerem
}
while(play){
	while(!digitalRead(sensorB)){


		goBackward();
	}
	while(!digitalRead(sensorF)){


		goBackward();
	}

		spin();


}

}
