#include "U8glib.h"
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);

void draw() {
  u8g.setFont(u8g_font_profont12);
  u8g.setPrintPos(0, 10);
  u8g.print("THIS IS THE\"");
  u8g.setPrintPos(0, 25);
  u8g.print("TEAM SOLID");
  u8g.setPrintPos(0, 40);
  u8g.print("HUSSLE HARD BOYS!.");
}

void draw2(void) {
  u8g.setFont(u8g_font_profont12);
  u8g.setPrintPos(0, 10);
  u8g.print("Check out the project");
  u8g.setPrintPos(0, 25);
  u8g.print("and review on");
  u8g.setPrintPos(0, 40);
  u8g.setFont(u8g_font_profont10);
  u8g.print("pornhub.com");
}

void setup(void) {
}

void loop(void) {
  u8g.firstPage();
  do {
    draw();
  } while (u8g.nextPage() );
  delay(3500);
  u8g.firstPage();
  do {
    draw2();
  } while (u8g.nextPage());
  delay(3500);
}
