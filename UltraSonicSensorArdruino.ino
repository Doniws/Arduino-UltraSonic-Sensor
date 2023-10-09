int trigPin = 7;
int echoPin = 6;
int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(8);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float jarakCm = duration * 0.0343 / 2;

  Serial.print("Jarak Cm : ");
  Serial.print(jarakCm);
  Serial.println("cm");

  if(jarakCm < 10) {  
    digitalWrite(ledPin , HIGH);
  }else if(jarakCm < 50){
    digitalWrite(ledPin , HIGH);
    delay(70);
    digitalWrite(ledPin , LOW);
    delay(70);
  }else{
    digitalWrite(ledPin , LOW);
  }
  delay(1000);
}