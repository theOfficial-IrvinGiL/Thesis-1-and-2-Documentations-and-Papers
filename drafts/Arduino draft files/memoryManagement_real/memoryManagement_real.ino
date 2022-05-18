//code to demonstrate and draft the memory management features  of the main unit
//being able to add, delete and clear the entire eeprom memory of the microcontrolller


#include <EEPROM.h>

String contact = "";
String passcode = "";

//Important notes:
// 1. you must not enter a passcode that start with *0

void addContact(int address, String str) {
  byte len = str.length();
  EEPROM.write(address, len);

  for (int i = 0; i < len; i++) {
    EEPROM.write(address + 1 + i, str[i]);
  }

}

//function to locate
int searchVacantEEPROM() {
  //  int vacantAddress = 0;
  //  for (int x = 0; x < 230; x + 15) {
  //    if (EEPROM.read(x) == vacantAddress) {
  //      return x;
  //    }
  //  }
  int searchCounter = 0;
  while (EEPROM.read(searchCounter) != 0) {
    searchCounter += 15;
  }
  return searchCounter;
}

String readEepromData(int address) {
  //int len = EEPROM.read(address);
  int len = 15;
  char data[len + 1];

  for (int i = 0; i < address + 15; i++) {
    data[i] = EEPROM.read(address + i);
  }

  data[len] = '\0';
  return String(data);
}

int scanAddressDelete(int address, String user_input) {
  int len = 11;
  char data[len + 1];

  for (int i = 0; i < address + 15; i++) {
    data[i] = EEPROM.read(address + 4 + i);
  }

  data[len] = '\0';


  if (String(data) == user_input) {
    return address;
  }
  else {
    return 0; //this means the address have not been found
  }

}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(" ");
  //prompt menu options
  Serial.println("Menu: A-Add contact B-Delete contact C-Clear EEPROM D-Display values");
  //wait function to wait for user input
  while (Serial.available() == 0)
  { //Wait for user input  }
  }
  char choice = Serial.read();    //Reading the Input string from Serial port.

  if (choice == ('A')) {
    Serial.println(" ");
    //code for getting user contact input
    Serial.println("Enter contact number: ");
    while (Serial.available() == 0)
    { //Wait for user input
    }
    contact = Serial.readString();
    Serial.println("Enter 4-digit passcode: ");
    while (Serial.available() == 0 ) {}
    passcode = Serial.readString();
    //instantiate code for locating which eeprom memory addrss is empty
    int emptyAddress = searchVacantEEPROM();
    //calling the function to add the values into eeprom
    addContact(emptyAddress, passcode + contact);

    //after storing new values into the eeprom.

    //We can display it on Serial monitor to know the contents
    Serial.println("Existing data: ");
    int loopCounter = 0;
    while (EEPROM.read(loopCounter) != 0) {
      Serial.println(readEepromData(loopCounter));
      loopCounter += 15;
    }
  }
  else if (choice == 'B'|| choice == 'b') {
    String contactDelete = "";
    //command serial to ask for user input
    Serial.println(" ");
    Serial.println("Enter contact number to delete: ");
    while (Serial.available() == 0)
    { //Wait for user input
    }
    contactDelete = Serial.readString();
    int findAdd_counter = 0;
    while (true) {
      int decide = scanAddressDelete(findAdd_counter, contactDelete);
      if (decide != 0) {
        //code to delete data from eeprom
        for (int i = decide ; i < decide + 15; i++) {
          EEPROM.write(i, 0);
        }
        break;
      }
      else {
        continue;
      }
      findAdd_counter += 15;
    }

  }
  else if (choice == 'C' || choice == 'c') {
    //clear eeprom option
    for (int i = 0 ; i < EEPROM.length() ; i++) {
      EEPROM.write(i, 0);
    }
    Serial.println("EEPROM has been cleared successfully!");
  }
  else {
    Serial.println("Existing data: ");
    int loopCounter = 0;
    while (EEPROM.read(loopCounter) != 0) {
      Serial.println(readEepromData(loopCounter));
      loopCounter += 15;
    }
    Serial.println(choice);

  }
}
