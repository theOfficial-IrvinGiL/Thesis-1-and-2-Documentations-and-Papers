#include <Keypad.h> // for keypad
#include <SPI.h>    // for oled
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <SPI.h> // for sdcard

// code for sd card component
#include <SD.h>
File myFile;

// code for defining the size of the Array
#define ARRAY_SIZE(x) sizeof(x) / sizeof(x[0])

#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C
const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {A0, A1, A2, A3};

// object instantiation for the OLED display
Adafruit_SH1106 display(OLED_RESET);

#if (SH1106_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SH1106.h!");
#endif

// object instantiation for the keypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

// variable declarations are coded here
// for getting administrator passcode
char admin_input[8];
short admin_fixedInput = 0;

unsigned short setCursorCollumn = 0; // used as reference point for the cursor when writting

char contact_input[11];
char passcode_input[4];

int addressOnEEPROM = 0;
short fixedNumberOfInputs = 0;
char codeFromEEPROM[4];
String predefined_adminpass[] = {"77351071", "27326699", "82736918", "61835240"};

/**
  variables  used for identifying different modes for execution
*/
boolean accessGranted = true;
void showMainUnit()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20, 10);
  display.println(" MAIN ");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20, 40);
  display.println(" UNIT ");
  display.display();
  delay(4000);
  display.clearDisplay();
}

// method to show the "input admin passcode" on display
void showInputPasscode()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 6);
  display.println("Input Admin Passcode: ");
  display.display();
}
// method for showing characters from user input
void displayChar_input(char input, short setcursor_Collumn)
{
  display.setTextSize(2);
  display.setCursor(setcursor_Collumn, 30);
  display.println(input);
  display.display();
}
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  showMainUnit();
  delay(2000);
}

// int contactNumber [];
// int fixedContactNumber = 0;

void loop()
{
start_Point:
  char keyValue = customKeypad.getKey();
  showInputPasscode();

  while (true)
  {
    if (accessGranted = true)
    {
      char keyValue = customKeypad.getKey();
      if (keyValue)
      {
        switch (keyValue)
        {
          case 'A':
            // loop to look and compare values obtained from user to the predefined admin passcodes
            for (int x = 0; x < 10; x++)
            {
              String str_admin = admin_input;
              // determine if the user input stored in array is equal to one to the contents in the adminpass array
              if (str_admin.compareTo(predefined_adminpass[x]) == 1)
              {
                display.clearDisplay();
                display.setTextSize(2);
                display.setTextColor(WHITE);
                display.setCursor(10, 10);
                display.println("> GREAT <");
                display.setTextSize(2);
                display.setTextColor(WHITE);
                display.setCursor(5, 40);
                display.println("> THANKS <");
                display.display();
                delay(2000);
              }
              else 
              showInputPasscode();
            }

            break;

          case 'B':
            break;

          default:
            // first method for user input entry, number input from user for administrator authentication
            if (admin_fixedInput < sizeof(admin_input))
            {
              admin_input[admin_fixedInput] = keyValue;
              admin_fixedInput++;

              // display the user input into the oled
              displayChar_input(keyValue, setCursorCollumn);
              setCursorCollumn += 12;
            }
            break;
        }
      }
    }
    else
    {
      break;
    }
  }
}
