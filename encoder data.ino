const int encoderPinA = 3;       
const int encoderPinB = 2;       
volatile int encoderTicks = 0;   
volatile int motorRpm = 0;
unsigned long previousTime = 0;
const int currentTime = 1000;


void setup() {
    pinMode(encoderPinA, INPUT);
    pinMode(encoderPinB, INPUT);
    Serial.begin(9600);
    attachInterrupt(digitalPinToInterrupt(encoderPinA), handleEncoderInterrupt,CHANGE);
}
void loop() {
 unsigned long previousTime=millis();
 if(millis-previousTime>=currentTime){
   detachInterrupt(digitalPinToInterrupt(encoderPinA));s
   float motorRpm=(float)(encoderTicks*600.0)/996.0;
 Serial.print("RPM is:");
 Serial.println(motorRpm);
 previousTime=millis();
 encoderTicks=0;
 attachInterrupt(digitalPinToInterrupt(encoderPinA),handleEncoderInterrupt, CHANGE);
 delay(100);
 }
}
void handleEncoderInterrupt() {
  encoderTicks++;
  }