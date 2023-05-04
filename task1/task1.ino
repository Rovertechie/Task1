int greenPin = 9;
int redPin = 10;
int potPin = A0;
// Setup the pins for output
void setup() {
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}
void loop() {
  int potValue = analogRead(potPin); 
  if (potValue < 512) {
    int greenValue = potValue / 2;
    int redValue = 0;
  }
  else {
    // Set green LED brightness to maximum (255)
    int greenValue = 255;
    int redValue = (potValue - 512) / 2;
  }
  analogWrite(greenPin, greenValue);
  analogWrite(redPin, redValue);
}
