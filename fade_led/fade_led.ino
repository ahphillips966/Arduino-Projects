int LED = 11; //digital pin 11 is set as the LED pin

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); //LED pin is set to output
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int fade = 0; fade <= 255; fade += 5){
    analogWrite(LED, fade);
    delay(100);
    if(fade == 255){
      for(int negFade = 255; negFade >=0; negFade -= 5){
        analogWrite(LED, negFade);
        delay(100);
      }
    }
  }
}
