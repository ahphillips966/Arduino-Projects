#include "DFRobot_BME680_I2C.h" //DFRobot BME680 library
#include "Wire.h" //Library for use with I2C protocol
DFRobot_BME680_I2C bme(0x76); //Create a bme object and write to IIC address

void setup() {
  // put your setup code here, to run once:
  uint8_t rslt = 1; //initialising test result to not 0
  Serial.begin(9600);
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
}

void loop() {
  // put your main code here, to run repeatedly:
  bme.startConvert();
  delay(1000);
  bme.update();
  float temperature = bme.readTemperature();
  Serial.println(temperature/100,1);
}
