const int ledPin1 = 8;
const int ledPin2 = 11;
void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}
void loop() {
  unsigned long currentTime = millis();
  if (currentTime - previousTime1 >= delayTime1) {
    digitalWrite(ledPin1, !digitalRead(ledPin1));
    previousTime1 = currentTime;
  }
  if (currentTime - previousTime2 >= delayTime2) {
    digitalWrite(ledPin2, !digitalRead(ledPin2));
    previousTime2 = currentTime;
  }
}
