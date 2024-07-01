void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));
  int coin = random() % 2;

  if(coin == 1) {
    Serial.println("Heads");
  }
  else {
    Serial.println("Tails");
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
