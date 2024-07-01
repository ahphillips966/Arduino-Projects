const int LED = 11;
const int button = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  int btnpress = digitalRead(button);

  while(btnpress == LOW) {
    Serial.println("Button is pressed");
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
}
