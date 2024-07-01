void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  int button1 = digitalRead(2);
  int button2 = digitalRead(3);

  if(button1==LOW){
    Serial.println("Button 1 was pushed");
  }

  if(button2==LOW){
    Serial.println("Button 2 was pushed");
  }

  else {
    Serial.println("No button is pressed");
    delay(1000);
  }
}
