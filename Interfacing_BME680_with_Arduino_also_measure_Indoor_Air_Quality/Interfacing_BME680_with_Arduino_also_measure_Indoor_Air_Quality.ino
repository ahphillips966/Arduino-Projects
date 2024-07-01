#include <Wire.h>
//including the BME680 sensor libraries
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
 
#define SEALEVELPRESSURE_HPA (1013.25)
 
Adafruit_BME680 bme; // I2C
 
void setup() 
{
  Serial.begin(9600);
  while (!Serial);
  Serial.println(F("BME680 test"));
 
  if (!bme.begin()) 
  {
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    while (1);
  }
 
  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms
}
 
void loop() 
{
  if (! bme.performReading()) 
  {
    Serial.println("Failed to perform reading :(");
    return;
  }
  
  float temperature = bme.temperature;
  float pressure = bme.pressure / 100.0;
  float altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  float humidity = bme.humidity;
  float gas = bme.gas_resistance / 1000.0;
  double dewPoint = dewPointFast(temperature, humidity);
  
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" *C");
 
  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");
 
  Serial.print("Pressure = "); 
  Serial.print(pressure); 
  Serial.println(" hPa");
 
  Serial.print("Dew Point = ");
  Serial.print(dewPoint);
  Serial.println(" *C");
 
  Serial.print("Approx. Altitude = ");
  Serial.print(altitude);
  Serial.println(" m");
 
  Serial.print("Gas = ");
  Serial.print(gas);
  Serial.println(" KOhms");
  Serial.println();
  delay(2000);
}
 
double dewPointFast(double celsius, double humidity)
{
  double a = 17.271;
  double b = 237.7;
  double temp = (a * celsius) / (b + celsius) + log(humidity * 0.01);
  double Td = (b * temp) / (a - temp);
  return Td;
}
