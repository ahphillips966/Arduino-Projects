int LED = 11; //port 11 is where the LED is attached

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT); //LED pin set to output 
}

char rx_byte = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    rx_byte = Serial.read();
    
    switch(rx_byte) {
      case '1':
        Serial.println("--------- MENU ---------");
        Serial.println("1. This menu");
        Serial.println("2. LED fade in and out");
        Serial.println("3. LED flash twice");
        Serial.println("4. LED flash SOS");
        Serial.println("------------------------");
      break;
      
      case '2':
        Serial.println("LED Fading");
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
      break;
      
      case '3':
        Serial.println("LED flashing");
        digitalWrite(LED, HIGH);
        delay(1000);
        digitalWrite(LED, LOW);
        delay(1000);
        digitalWrite(LED, HIGH);
        delay(1000);
        digitalWrite(LED, LOW);
        delay(1000);
      break;
      
      case '4':
        Serial.println("SOS");
        for(int i = 0; i < 9; i++){
          if(i <= 2){
            digitalWrite(LED, HIGH);
            delay(500);
            digitalWrite(LED, LOW);
            delay(500);
          }
          if(i > 2 && i <= 5){
            digitalWrite(LED, HIGH);
            delay(1000);
            digitalWrite(LED, LOW);
            delay(500);
          }
          if(i > 5 && i <= 8){
            digitalWrite(LED, HIGH);
            delay(500);
            digitalWrite(LED, LOW);
            delay(500);
          }
        }
      break;
      
      //default:
        //Serial.println("Invalid input");
      //break;
      
    } //end switch(rx_byte)
  } //end if(Serial.available())
} //end loop
