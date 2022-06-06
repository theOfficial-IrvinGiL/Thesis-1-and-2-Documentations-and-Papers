void MainUnitDisplay()
{
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,10);
  display.println("> MAIN <");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20,40);
  display.println("> UNIT <");
  display.display();
  delay(2000);
}

void GenerateRandomNumber() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  randNumber = random(1000,9999);
  Serial.println(randNumber);
  delay(50);
}

void Menu()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20, 10);
  display.println("- - MENU - -");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(5, 20);
  display.println("A. Register User");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(5, 30);
  display.println("B. Delist User");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(5, 40);
  display.println("C. View User List");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(5, 50);
  display.println("D. Switch To Control Mode");
  display.display();
}
