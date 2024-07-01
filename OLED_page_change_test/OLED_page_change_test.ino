#include <Arduino.h>
#include <SPI.h> //Library for SPI protocol
#include <U8g2lib.h> //Lobrary for drawing on OLED

U8G2_SSD1309_128X64_NONAME0_1_4W_SW_SPI u8g2(U8G2_R0, /*clock*/ 13, /*data*/ 11, /*cs*/ 10, /*dc*/ 9, /*reset*/ 8);

int btn1;
int btn2;
int pageNum=1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  
  u8g2.begin();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_9x15B_tf);
}

void loop() {
  // put your main code here, to run repeatedly:
 btn1 = digitalRead(2);
 btn2 = digitalRead(3);

 if(btn2==LOW) {
   pageNum++;
   if(pageNum == 5){
     pageNum = 1;
   }
   if(pageNum == 0) {
     pageNum = 4;
   }
 }

 if(btn1==LOW) {
   pageNum--;
   if(pageNum == 5){
     pageNum = 1;
   }
   if(pageNum == 0) {
     pageNum = 4;
   }
 }

 switch(pageNum) {
   case 1: 
     u8g2.firstPage();
     do {
      u8g2.setCursor(0, 15);
      u8g2.print("Page 1");
     } while(u8g2.nextPage());
     delay(1000);
     break;
   case 2:
     u8g2.firstPage();
     do {
      u8g2.setCursor(0, 15);
      u8g2.print("Page 2");
     } while(u8g2.nextPage());
     delay(1000);
     break;
   case 3:
     u8g2.firstPage();
     do {
      u8g2.setCursor(0, 15);
      u8g2.print("Page 3");
     } while(u8g2.nextPage());
     delay(1000);
     break;
   case 4:
     u8g2.firstPage();
     do {
      u8g2.setCursor(0, 15);
      u8g2.print("Page 4");
     } while(u8g2.nextPage());
     delay(1000);
     break; 
 }
}
