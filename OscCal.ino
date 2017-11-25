#include <SoftwareSerial.h>
byte osccal_val = 0x31; //OSCCAL inicial start
const int Rx = 3; // this is physical pin 2
const int Tx = 4; // this is physical pin 3

SoftwareSerial swSerial(Rx, Tx);
char temp[16];
int countdown = 10;
boolean decrement;
#define RANGE 10

void setup() {
	swSerial.begin(115200);
	decrement = true;
	countdown = RANGE;
	osccal_val = OSCCAL;
	unsigned int v = OSCCAL;
	swSerial.print(" OSCCAL: "); swSerial.println(utoa(v, temp, 10));
	delay(1000);
}

void loop() {
	OSCCAL = osccal_val;
	delay(1000);

	countdown--;
	if (countdown < 0) {
		countdown = RANGE*2;
		decrement = !decrement;
	}
	if (decrement) {
		osccal_val--;
	}
	else {
		osccal_val++;
	}

	unsigned int v = OSCCAL;
	unsigned int w = osccal_val;
	swSerial.print("*** OSCCAL: "); swSerial.println(utoa(v, temp, 10));

	swSerial.println("The quick brown fox jumped over the lazy dogs back 0123456789 The quick brown fox jumped over the lazy dogs back 0123456789 ");
	swSerial.println("The quick brown fox jumped over the lazy dogs back 0123456789 The quick brown fox jumped over the lazy dogs back 0123456789 ");
}
