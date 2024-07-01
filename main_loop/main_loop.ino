void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("*** This message will only show up on start or reset. ***");
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("-- Arduino at the start of the loop. --");
  Serial.println("---------------------------------------");
  delay(2000);
  Serial.println("Executing instructions in the main loop.");
  delay(2000);
  Serial.println("Arduino now at the bottom of the main loop.\r\n");

}
