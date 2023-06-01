#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

namespace pins
{
	const int joystick1_x = A1;
	const int joystick1_y = A2;
	const int joystick1_z = 7;
	const int joystick2_x = A3;
	const int joystick2_y = A4;
	const int joystick2_z = 6;
	const int buttonpin = 5;
	const int potent = A0; 
}


RF24 radio(9, 10);

void setup()
{
	Serial.begin(9600);
	pinMode(pins::buttonpin, INPUT);
	pinMode(pins::joystick1_z, INPUT_PULLUP);
	pinMode(pins::joystick2_z, INPUT_PULLUP);
	radio.begin();
	radio.setChannel(13);
	radio.setDataRate(RF24_250KBPS); 
	radio.setPALevel(RF24_PA_HIGH);
	radio.openWritingPipe(0x1234567890LL);
	radio.stopListening();
}

int i = 0;
void loop()
{
	//button
	const bool val = digitalRead(pins::buttonpin);  
	Serial.print("butp=");
	Serial.print(val);
	//potentiometer
	int potent_value =analogRead(pins::potent);
	Serial.print("potv=");
	Serial.print(potent_value);

	//joystick1
	int x1 = analogRead(pins::joystick1_x);
	int y1 = analogRead(pins::joystick1_y);
	int z1 = digitalRead(pins::joystick1_z);
	Serial.print("jx1=");
	Serial.print(x1);
	Serial.print(" jy1=");
	Serial.print(y1);
	Serial.print(" jz1=");
	Serial.print(z1);

//joystick2
	int x2 = analogRead(pins::joystick2_x);
	int y2 = analogRead(pins::joystick2_y);
	int z2 = digitalRead(pins::joystick2_z);
	Serial.print(" jx2=");
	Serial.print(x2);
	Serial.print(" jy2=");
	Serial.print(y2);
	Serial.print(" jz2=");
	Serial.print(z2);
	Serial.println(" ");
	delay(500);
}
