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
  do{
    //u8g2.drawBox(32,16,64,32);
    //u8g2.setFont(u8g2_font_adventurer_tf);
    //u8g2.drawButtonUTF8(64, 32, U8G2_BTN_HCENTER|U8G2_BTN_BW2|U8G2_BTN_SHADOW2, 0, 3, 3, "Dig Bick");
    u8g2.setFont(u8g2_font_unifont_t_symbols);
    u8g2.drawGlyph(5,10,0x2608);  
  } while(u8g2.nextPage());
  delay(1000);
  

  
}
