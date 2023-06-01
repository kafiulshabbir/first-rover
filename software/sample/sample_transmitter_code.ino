#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//https://nrf24.github.io/RF24/

/*
 * This program sends a string
 * "0-Hello World"
 * "1-Hello World"
 * ...
 * "9-Hello World"
 * "0-Hello World"
 * Every 1000ms
 */
 
RF24 radio(9, 10); // CE, CSN


void setup() {
  radio.begin();
  radio.setChannel(13);
  radio.setDataRate(RF24_250KBPS); //1MBPS AND 2MBPS
  radio.setPALevel(RF24_PA_HIGH); // Can be MIN LOW HIGH and MAX
  radio.openWritingPipe(0x1234567890LL);
  //radio.openReadingPipe(0, address);
  radio.stopListening();
}

int i = 0;
void loop() {
  char text[] = "N-Hello World";
  i = (++i) % 10;
  text[0] = '0' + i;
 
  radio.write(&text, sizeof(text));
  delay(1000);
}
