
String text[] = {"one", "two", "three", "four", "five"};
int index = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  String var =text[index];
    char mess[32];
  for (int x = 0; x < 32; x++) {
    mess[x] = var[x];
  }
  
  Serial.write(mess);
  if (index >=  5) {
    index = 0;
  }
//  memset(mess, 0, sizeof(mess)); //not working ang memset na code ps.
  index++;
//  for(int = 0; y < sizeof()
  delay(3000);
}
