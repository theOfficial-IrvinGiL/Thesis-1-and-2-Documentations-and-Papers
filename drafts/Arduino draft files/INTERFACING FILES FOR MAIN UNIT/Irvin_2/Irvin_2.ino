/**Contact Delisted
 * Successfully
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

void displayText() {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(15, 30);
  display.print("Contact Delisted");
  display.setCursor(25, 40);
  display.print("Successfully!");
  display.display();
}

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  displayText();
}

void loop() {
  // put your main code here, to run repeatedly:

}
