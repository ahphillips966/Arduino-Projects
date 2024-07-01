#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>

//Constructor
U8G2_SSD1309_128X64_NONAME0_1_4W_SW_SPI u8g2(U8G2_R0, /*clock*/ 13, /*data*/ 11, /*cs*/ 10, /*dc*/ 9, /*reset*/ 8);

void setup() {
  // put your setup code here, to run once:
  u8g2.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_timR18_tf);
    u8g2.drawStr(0,30,"'Sup Bitches");
  } while(u8g2.nextPage());
  delay(1000);
}
