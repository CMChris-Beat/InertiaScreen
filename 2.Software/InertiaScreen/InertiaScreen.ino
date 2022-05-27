/*
 Name:		InertiaScreen.ino
 Created:	2022/5/19
 Author:	YLEglo
*/


#include <BlinkerESPMQTT.h>
#include <BlinkerAssistant.h>
#include <Blinker.h>
#include <dummy.h>
#include "ISBlinker.h"

bool running = 0;

void parseData(String data);

void setup() {
	analogWriteRange(1023);
	analogWriteFreq(100);
	pinMode(D6, OUTPUT);
	pinMode(D7, OUTPUT);
	// digitalWrite(D6, HIGH);
	analogWrite(D6, speed);
	digitalWrite(D7, LOW);
	BLINKER_DEBUG.stream(Serial);
	Blinker.begin(auth, ssid, pswd);
	Button1.attach(button1_callback);
	Button2.attach(button2_callback);
	Button3.attach(button3_callback);
}

void loop() {
	Blinker.run();
	parseData(input);
	if (running == 0) analogWrite(D6, 0);
	else analogWrite(D6, speed);
}

void parseData(String data) {
	switch (data.toInt()) {
		case 1: // Slow
			if (speed >= 10) speed -= 10;
			running = 1;
			break;
		case 2: // Quick
			if (speed <= 1013) speed += 10;
			running = 1;
			break;
		case 3: // Stop
			running = !running;
			break;
		default:
			running = 0;
			break;
	}
}