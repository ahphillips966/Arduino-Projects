#include "DFRobot_BME680_I2C.h" //DFRobot BME680 library
#include "Wire.h" //Library for use with I2C protocol
#include <Arduino.h>
#include <SPI.h> //Library for SPI protocol
#include <U8g2lib.h> //Library for drawing on OLED
DFRobot_BME680_I2C bme(0x76); //Create a bme object and write to IIC address

//OLED constructor
U8G2_SSD1309_128X64_NONAME0_2_4W_SW_SPI u8g2(U8G2_R0, /*clock*/ 13, /*data*/ 11, /*cs*/ 10, /*dc*/ 9, /*reset*/ 8);

unsigned long currentTime; 
float presTend[3];
//float fltPres;
const long period = 10000;
unsigned long prevTime = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  u8g2.begin();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_9x15B_tf);
  bme.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  currentTime = millis();

  bme.startConvert();
  bme.update();

  /* if(currentTime - prevTime >= period) {
    prevTime = currentTime;
    presTend[0] = presTend[1];
    presTend[1] = presTend[2];
    presTend[2] = bme.readPressure()/100;
 
    for(int i = 0; i < 3; i++){
      Serial.print(presTend[i]);
      Serial.print(", ");
      if(i == 2){
        Serial.println();
      }
    }
  } */

  presTend[0] = 0;
  presTend[1] = 1;
  presTend[2] = 3;
  pressureTendancy(presTend[0], presTend[1], presTend[2]);

}

void pressureTendancy(float x, float y, float z){
  if(y-x > 0 && z-y < 0 && z > x){ //code 0 v1
    u8g2.firstPage();
    do {
      u8g2.setCursor(0, 10);
      u8g2.print("5appp:");
      u8g2.drawHLine(15, 42, 98);
      u8g2.drawLine(43, 42, 63, 22);
      u8g2.drawLine(63, 22, 84, 27);
    } while(u8g2.nextPage()); 
  }

  if(y-x > 0 && z-y < 0 && z == x){ //code 0 v2
    u8g2.firstPage();
    do {
      u8g2.setCursor(0, 10);
      u8g2.print("5appp:");
      u8g2.drawHLine(15, 42, 98);
      u8g2.drawLine(43, 42, 63, 22);
      u8g2.drawLine(63, 22, 84, 42);
    } while(u8g2.nextPage());
  } 

  if(y-x > 0 && z == y){ //code 1 v1
    u8g2.firstPage();
    do {
      u8g2.setCursor(0, 10);
      u8g2.print("5appp:");
      u8g2.drawHLine(15, 42, 98);
      u8g2.drawLine(43, 42, 63, 22);
      u8g2.drawLine(63, 22, 84, 22);
    } while(u8g2.nextPage());
  }

  if(y-x > 0 && z-y > 0 && (y-x) > (z-y)){ //code 1 v2
    u8g2.firstPage();
    do {
      u8g2.setCursor(0, 10);
      u8g2.print("5appp:");
      u8g2.drawHLine(15, 42, 98);
      u8g2.drawLine(43, 42, 63, 27);
      u8g2.drawLine(63, 27, 84, 22);
    } while(u8g2.nextPage());
  }

  if(y-x > 0 && z-y > 0 && (y-x) == (z-y)){ //code 2
    u8g2.firstPage();
    do {
      u8g2.setCursor(0, 10);
      u8g2.print("5appp:");
      u8g2.drawHLine(15, 42, 98);
      u8g2.drawLine(43, 42, 84, 22);
    } while(u8g2.nextPage());
  }

  if(y-x < 0 && z-y > 0 && z > x){ //code 3 v1
    u8g2.firstPage();
    do {
      u8g2.setCursor(0, 10);
      u8g2.print("5appp:");
      u8g2.drawHLine(15, 42, 98);
      u8g2.drawLine(43, 42, 63, 51);
      u8g2.drawLine(63, 51, 84, 22);
    } while(u8g2.nextPage());
  }

  if(y == x && z-y > 0){ //code 3 v2
    u8g2.firstPage();
    do {
      u8g2.setCursor(0, 10);
      u8g2.print("5appp:");
      u8g2.drawHLine(15, 42, 98);
      u8g2.drawLine(43, 41, 63, 41);
      u8g2.drawLine(63, 41, 84, 22);
    } while(u8g2.nextPage());
  }

  if(y-x > 0 && z-y > 0 && (y-x) < (z-y)){ //code 3 v3
    u8g2.firstPage();
    do {
      u8g2.setCursor(0, 10);
      u8g2.print("5appp:");
      u8g2.drawHLine(15, 42, 98);
      u8g2.drawLine(43, 42, 63, 36);
      u8g2.drawLine(63, 36, 84, 22);
    } while(u8g2.nextPage());
  }

  if(y == x && z == y){ //code 4
    
  }

  if(y-x < 0 && z-y >0 && z<x){ //code 5 v1
    
  }

  if(y-x < 0 && z-y>0 && z == x){ //code 5 v2
    
  }

  if(y-x < 0 && z == y){ //code 6 v1
    
  }

  if(y-x < 0 && z-y < 0 && (y-x) < (z-y)){ //code 6 v2
    
  }

  if(y-x < 0 && z-y < 0 && (y-x) == (z-y)){ //code 7
    
  }

  if(y == x && z-y < 0){ //code 8 v1
    
  }

  if(y-x > 0 && z-y < 0 && z < x){ //code 8 v2
    
  }

  if(y-x < 0 && z-y < 0 && (y-x) > (z-y)){ //code 8 v3
    
  }
}
