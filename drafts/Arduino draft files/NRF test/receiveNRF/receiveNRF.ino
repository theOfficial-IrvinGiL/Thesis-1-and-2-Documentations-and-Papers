//task assigned to: @lyndon
//this code is for the main unit in receiving data from the meter unit via RF

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"


RF24 radio(9, 10); // CE, CSN
const byte address[6] = "ABCDE"; // the address the the module
#define led A0

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  radio.begin();

  radio.setAutoAck(false);
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  radio.setRetries(15, 15);
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
}
void loop() {
  if (radio.available()) { // if nrf has any incoming data
    digitalWrite(led, HIGH);
    char text[32] = "";
    radio.read(&text, sizeof(text));

//    radio.stopListening();
    Serial.write(text, sizeof(text));
    delay(500);
    digitalWrite(led, LOW);
  }
  else {
    digitalWrite(led, LOW);
  }


}
