#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(9, 10); // CE, CSN
const byte address[6] = "ABCDE"; // the address the the module
unsigned long shit = 0;


void setup() {
radio.begin();
Serial.begin(9600);

radio.setAutoAck(false);
SPI.setClockDivider(SPI_CLOCK_DIV4);
radio.setRetries(15,15);
radio.openWritingPipe(address);
radio.setPALevel(RF24_PA_MAX);
radio.stopListening();

}

void loop() 
{

const char text[] = "WASSUP"; 
radio.write(&text, sizeof(text));
Serial.println(text);
delay(800);

}
