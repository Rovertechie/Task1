#include <Wire.h>


#define SLAVE_ADDRESS 8 
String receivedData = "";


void setup() {
  Wire.begin(SLAVE_ADDRESS);  
  Wire.onReceive(receiveEvent);  
  Serial.begin(9600);  
}

void loop() {
}

void receiveEvent(int numBytes) {
while (Wire.available()) {
    char c = Wire.read(); 
    receivedData += c; 

    if (c == '\n') { 
      Serial.print(receivedData); 
      receivedData = ""; 
    }
  }
}









