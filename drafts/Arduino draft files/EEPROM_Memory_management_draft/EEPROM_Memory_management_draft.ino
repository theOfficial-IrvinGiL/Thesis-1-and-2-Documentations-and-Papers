#include <EEPROM.h>

//write function to eeprom
void writeStringToEEPROM(int address, String str) {
  byte len = str.length();
  EEPROM.write(address, len);

  for (int i = 0; i < len, i++) {
    EEPROM.write(address + 1 + i, str[i]);
  }
}
//read funtion from eeprom
String readStringFromEEPROM(int address) {

  int len = EEPROM.read(address);
  char data[len + 1];

  for (int i = 0; i < len; i++) {
    data[i] = EEPROM.read(address + 1 + i);
  }

  data[len] = '\0';
  return String(data);
}





void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  writeStringToEEPROM(15, "Hello Arduino!");
  Serial.println(readStringFromEEPROM(15));
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
