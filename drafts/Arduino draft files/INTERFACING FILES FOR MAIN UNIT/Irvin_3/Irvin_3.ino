/**Enter Contact number
   to delist:

   A - Enter
   B - Clear
*/

#include <Keypad.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <SPI.h>

#define ARRAY-SIZE(x) sizeof(x) / sizeof(x[0])
#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C
const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys [ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {A0, A1, A2, A3};

Adafruit_SH1106 display (OLED_RESET);
#if (SH1106_LCDHEIGHT != 64)
#error ("Height incorrect, please fix Adafruit_SH1106.h!")
#endif

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void delistContactMessage() {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(2, 1); //(collumn, row)
  display.print("Enter Contact number");
  display.setCursor(2, 10);
  display.print("to delist:");
  display.setCursor(2, 45);
  display.print("A - Enter");
  display.setCursor(2, 56);
  display.print("B - Clear");
  display.display();
}
void showDelistContactInput(char value, int collumnPosition) {
  display. setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(collumnPosition, 25);
  display.print(value);
  display.display();

}

//variables
unsigned short setCursorCollumn = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  delistContactMessage();
}

void loop() {
  // put your main code here, to run repeatedly:
  char keyValue = customKeypad.getKey();
  if (keyValue) {
    switch (keyValue) {
      case 'A':
        display.clearDisplay(); //clear the dislays on the OLED
        delistContactMessage();
        setCursorCollumn = 0;
        break;
      default:
        showDelistContactInput(keyValue, setCursorCollumn);
        setCursorCollumn += 7;
        break;
    }
  }
}
