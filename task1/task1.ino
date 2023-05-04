int greenPin = 11;
int bluePin = 10;
int potPin = A2;

void setup() {
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);  
  int greenValue, blueValue;

  if (potValue < 512) {  
    greenValue = map(potValue, 0, 511, 0, 255);  
    blueValue = 0;  
  } else {  
    int potRange = 1023 - 512; 
    int potAdjusted = potValue - 512;
    blueValue = map(potAdjusted, 0, potRange, 0, 255); 
    greenValue = 0;  
  }

  analogWrite(greenPin, greenValue);  
  analogWrite(bluePin, blueValue);  
}
