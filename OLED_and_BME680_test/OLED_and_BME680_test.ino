#include "DFRobot_BME680_I2C.h" //DFRobot BME680 library
#include "Wire.h" //Library for use with I2C protocol
#include <Arduino.h>
#include <SPI.h> //Library for SPI protocol
#include <U8g2lib.h> //Lobrary for drawing on OLED
DFRobot_BME680_I2C bme(0x76); //Create a bme object and write to IIC address

//OLED constructor
U8G2_SSD1309_128X64_NONAME0_1_4W_SW_SPI u8g2(U8G2_R0, /*clock*/ 13, /*data*/ 11, /*cs*/ 10, /*dc*/ 9, /*reset*/ 8);

void setup() {
  // put your setup code here, to run once:

  u8g2.begin();
  u8g2.enableUTF8Print();
  
  uint8_t rslt = 1; //initialising test result to not 0
  Serial.begin(9600);
  bme.begin();
   /*
   while (!Serial);
  delay(1000); //for the duration of time the serial port is not running, do nothing
  Serial.println();
  while (rslt != 0) {
    rslt = bme.begin();
    if (rslt != 0) {
      Serial.println("bme begin failure"); //If the bme.begin does not return 0 then the sensor did not start
      delay(2000);
    }
  }
  Serial.println("bme begin successful");
  */
}

void loop() {
  // put your main code here, to run repeatedly:

bme.startConvert();
delay(1000);
bme.update();
float fltTemp = bme.readTemperature()/100; 
String strTemp = String(fltTemp, 1);

u8g2.firstPage();
do {
  u8g2.setFont(u8g2_font_9x15B_tf);
  u8g2.setCursor(0,10);
  u8g2.print("Temperature: ");
  u8g2.setCursor(0,40);
  u8g2.print(strTemp + "°C");
} while(u8g2.nextPage());
delay(1000);

}
