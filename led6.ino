const int ledPin = 13;      
const int Pin = 2;    
volatile int toggleCount = 0;
unsigned long int  lastInterruptTime = 0; 
void setup() {
  pinMode(ledPin, OUTPUT);           
  pinMode(Pin, INPUT_PULLUP); 
  attachInterrupt(digitalPinToInterrupt(Pin), interruptHandler , HIGH);
  Serial.begin(9600); 
}
void loop() {
  unsigned long startTime = millis();
  Serial.println("loop starts");
  while (millis() - startTime < 20000) { 
    digitalWrite(ledPin, HIGH);  
    delay(1000);                   
    digitalWrite(ledPin, LOW);    
    delay(1000); 
    Serial.println("Start print");                  
  }
  Serial.println(toggleCount); 
  for (int i = 0; i < toggleCount; i++) {
    digitalWrite(ledPin, HIGH);  
    delay(1000);                  
    digitalWrite(ledPin, LOW);   
    delay(1000); 
    Serial.println("Afterburn");
    delay(500);                 
  }
  toggleCount = 0;
}

  
  void interruptHandler()
{
  
  if ((millis() - lastInterruptTime) >= 2000)
  {
    toggleCount++;
    lastInterruptTime = millis();
  }
}


