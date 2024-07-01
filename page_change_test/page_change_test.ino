int btn1;
int btn2;
int pageNum=1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  btn1 = digitalRead(2);
  btn2 = digitalRead(3);

  if(btn2==LOW) {
    pageNum++;
    if(pageNum == 5){
      pageNum = 1;
    }
    if(pageNum == 0) {
      pageNum = 4;
    }
  }

  if(btn1==LOW) {
    pageNum--;
    if(pageNum == 5){
      pageNum = 1;
    }
    if(pageNum == 0) {
      pageNum = 4;
    }
  }

  switch(pageNum) {
    case 1: 
      Serial.println("You are on page 1");
      delay(1000);
      break;
    case 2:
      Serial.println("You are on page 2");
      delay(1000);
      break;
    case 3:
      Serial.println("You are on page 3");
      delay(1000);
      break;
    case 4:
      Serial.println("You are on page 4");
      delay(1000);
      break; 
  }
}
