#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN
//const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setChannel(13);
  radio.setDataRate(RF24_250KBPS); //1MBPS AND 2MBPS
  radio.setPALevel(RF24_PA_HIGH); // Can be MIN LOW HIGH and MAX
  radio.openReadingPipe(0, 0x1234567890LL);
  //radio.openReadingPipe(0, address);
  radio.startListening();
}

void loop() {
  if(radio.available())
  {
    char incoming[100];
    radio.read(&incoming, sizeof(incoming));
    //Serial.println("nigga");
    Serial.println(incoming);
   // Serial.println(incoming[1]);
   // delay(500);
  }
  else
  {
    //Serial.println("no connection");
  }
}
