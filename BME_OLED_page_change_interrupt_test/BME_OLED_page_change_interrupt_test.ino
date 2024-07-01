#include "DFRobot_BME680_I2C.h" //DFRobot BME680 library
#include "Wire.h" //Library for use with I2C protocol
#include <Arduino.h>
#include <SPI.h> //Library for SPI protocol
#include <U8g2lib.h> //Lobrary for drawing on OLED
DFRobot_BME680_I2C bme(0x76); //Create a bme object and write to IIC address

//OLED constructor
U8G2_SSD1309_128X64_NONAME0_2_4W_SW_SPI u8g2(U8G2_R0, /*clock*/ 13, /*data*/ 11, /*cs*/ 10, /*dc*/ 9, /*reset*/ 8);

int btn1;
int btn2;
int lstbtn1 = HIGH;
int lstbtn2 = HIGH;
int pageNum=1;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

float fltTemp;
String strTemp;

float fltRH;
String strRH;

float fltPres;
String strPres;

float fltGas;
String strGas;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  
  u8g2.begin();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_9x15B_tf);

  bme.begin();

  attachInterrupt(digitalPinToInterrupt(2), turnPage, LOW);
  attachInterrupt(digitalPinToInterrupt(3), turnPage, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  bme.startConvert();
  delay(1000);
  bme.update();

  fltTemp = bme.readTemperature()/100;
  strTemp = String(fltTemp, 1);

  fltRH = bme.readHumidity()/1000;
  strRH = String(fltRH, 1);

  fltPres = bme.readPressure()/100;
  strPres = String(fltPres, 1);

  fltGas = bme.readGasResistance()/1000;
  strGas = String(fltGas, 1);

  switch(pageNum) {
    case 1:
      u8g2.firstPage();
      do {
        u8g2.setCursor(0, 10);
        u8g2.print("Temperature: ");
        u8g2.setCursor(0, 40);
        u8g2.print(strTemp + "°C");        
      } while(u8g2.nextPage());
      delay(1000);
      break;
    case 2:
      u8g2.firstPage();
      do {
        u8g2.setCursor(0, 10);
        u8g2.print("Humidity: ");
        u8g2.setCursor(0, 40);
        u8g2.print(strRH + "%");
      } while(u8g2.nextPage());
      delay(1000);
      break;
    case 3:
      u8g2.firstPage();
      do {
        u8g2.setCursor(0, 10);
        u8g2.print("Pressure: ");
        u8g2.setCursor(0, 40);
        u8g2.print(strPres + " hPa");
      } while(u8g2.nextPage());
      delay(1000);
      break;
    case 4:
      u8g2.firstPage();
      do {
        u8g2.setCursor(0, 10);
        u8g2.print("Gas Resistance: ");
        u8g2.setCursor(0, 40);
        u8g2.print(strGas + "kOhm");
      } while(u8g2.nextPage());
      delay(1000);
      break;
  }
}

void turnPage(){

  btn1 = digitalRead(2);
  btn2 = digitalRead(3);

  if((millis() - lastDebounceTime) > debounceDelay) {
  
    if(btn1==LOW) {
      pageNum--;
      if(pageNum == 5){
        pageNum = 1;
      }
      if(pageNum == 0) {
        pageNum = 4;
      }
      lastDebounceTime = millis();
    }
  
    if(btn2==LOW) {
      pageNum++;
      if(pageNum == 5){
        pageNum = 1;
      }
      if(pageNum == 0) {
        pageNum = 4;
      }
      lastDebounceTime = millis();
    }
  }
}
