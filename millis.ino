const int ledPin1 = 2;
const int ledPin2 = 3;

int delayTime1 = 1000;  // Delay time for LED 1 (in milliseconds)
int delayTime2 = 500;   // Delay time for LED 2 (in milliseconds)

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // Blink LED 1
  digitalWrite(ledPin1, HIGH);
  delay(delayTime1);
  digitalWrite(ledPin1, LOW);
  delay(delayTime1);

  // Blink LED 2
  digitalWrite(ledPin2, HIGH);
  delay(delayTime2);
  digitalWrite(ledPin2, LOW);
  delay(delayTime2);
}
