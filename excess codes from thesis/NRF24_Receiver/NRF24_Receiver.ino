#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "ABCDE"; // the address the the module
void setup() {
  
Serial.begin(9600);
radio.begin();

//radio.setAutoAck(false);
//SPI.setClockDivider(SPI_CLOCK_DIV4);
//radio.setRetries(15,15);
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_MIN);
radio.startListening();
}
void loop() {
if (radio.available()) { // if nrf has any incoming data
char text[32] = "";
radio.read(&text, sizeof(text));
Serial.println(text);
delay(5);
}
}
