#include <Wire.h>

#define SLAVE_ADDRESS 8  

void setup() {
  Wire.begin();  
  Serial.begin(9600);  
}
void loop() {
  Wire.beginTransmission(SLAVE_ADDRESS);  
  delay(1000); 
  Wire.write("Hello,Arduino2!\n");  
  Wire.endTransmission();  

  delay(1000);  
}

