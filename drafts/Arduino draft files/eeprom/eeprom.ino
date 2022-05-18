#include <EEPROM.h>

void writeStringIntoEEPROM(int address, String str) {
  byte len = str.length();
  EEPROM.write(address, len);
  for (int i = 0; i < len; i++) {
    EEPROM.write(address + 1 + i, str[i]);
  }
}
String readStringFromEEPROM(int address)
{
  //  int len = EEPROM.read(address);
  int len = 15;
  char data[len + 1];
  for (int i = 0; i < len; i++) {
    data[i] = EEPROM.read(address  + i);
  }
  data[len] = '\0';
  return String(data);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //  writeStringIntoEEPROM(15, "Hello Arduino!");
  int y = 0;
  for (int x = 0; x <= 5 ; x++) {
    Serial.println ( readStringFromEEPROM(y));
    y += 15;
  }


}

void loop() {
  // put your main code here, to run repeatedly:

}
