#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"


RF24 radio(9, 10); // CE, CSN
const byte addresses [][6] = {"00001", "00002"};    //Setting the two addresses. One for transmitting and one for receiving
//const byte address1[6] = "00001"; // the address the the module
//const byte address2[6] = "00002";


void setup() {

  Serial.begin(9600);
  radio.begin();

  radio.setAutoAck(false);
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  radio.setRetries(15, 15);
  radio.openWritingPipe(addresses[0]);      //Setting the address at which we will send the data
  radio.openReadingPipe(1, addresses[1]);   //Setting the address at which we will receive the data
  //radio.openReadingPipe(0, address1);
  //radio.openWritingPipe(address2);
  radio.setPALevel(RF24_PA_MAX);

}
void loop() {
  radio.startListening();
  if (radio.available()) { // if nrf has any incoming data
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
    radio.stopListening();
    delay(3000);
 
    const char data[] = "Meter to Main";
    radio.write(&data, sizeof(data));
    delay(1000);
  }
}
