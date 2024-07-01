#include "DFRobot_BME680_I2C.h" //DFRobot BME680 library
#include "Wire.h" //Library for use with I2C protocol
//#define CALIBRATE_PRESSURE //use an accurate altitude to calibrate sea level air pressure
DFRobot_BME680_I2C bme(0x76); //Create a bme object and write to IIC address
//float seaLevel;

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
  //bme.supportIAQ();
  //#ifdef CALIBRATE_PRESSURE
  //bme.startConvert();
  //delay(1000);
  //bme.update();
  /*You can use an accurate altitude to calibrate sea level air pressure.
    And then use this calibrated sea level pressure as a reference to obtain the calibrated altitude.
  */
  //seaLevel = bme.readSeaLevel(21.0); //21 m seems to get the same SLP as shearwater METAR
  //Serial.print("seaLevel :");
  //Serial.println(seaLevel / 100, 1);
  //#endif
}

void loop() {
  // put your main code here, to run repeatedly:
  bme.startConvert();
  delay(1000);
  bme.update();
  Serial.println();
  Serial.print("Temperature: ");
  Serial.print(bme.readTemperature()/100, 1);
  Serial.println("°C");
  Serial.print("Humidity: ");
  Serial.print(bme.readHumidity()/1000, 1);
  Serial.println("%");
  Serial.print("Station Pressure: ");
  Serial.print(bme.readPressure()/100, 1);
  Serial.println("hPa");
  Serial.print("MSLP: ");
  Serial.print(bme.readSeaLevel(21.0)/100, 1); //haven't determined accurate altitude of apartment
  Serial.println("hPa");
  Serial.print("Uncalibrated altitude: ");
  Serial.print(bme.readAltitude());
  Serial.println("m");
  Serial.print("Gas resistance: ");
  Serial.print(bme.readGasResistance());
  Serial.println("Ω");
}
