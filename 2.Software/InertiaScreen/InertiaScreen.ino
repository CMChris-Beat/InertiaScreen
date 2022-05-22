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
	pinMode(D6, OUTPUT);
	pinMode(D7, OUTPUT);
	digitalWrite(D6, LOW);
	analogWrite(D7, 255);
	BLINKER_DEBUG.stream(Serial);
	Blinker.begin(auth, ssid, pswd);
	Button1.attach(button1_callback);
	Button2.attach(button2_callback);
	Button3.attach(button3_callback);
}

void loop() {
	Blinker.run();
	parseData(input);
}

void parseData(String data) {
	switch (data.toInt()) {
		case 1: // Slow
			analogWrite(D7, 80);
			running = 1;
			break;
		case 2: // Medium
			analogWrite(D7, 150);
			running = 1;
			break;
		case 3: // Quick
			analogWrite(D7, 255);
			running = 1;
			break;
		default:
			running = 0;
			break;
	}
}