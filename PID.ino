const int encoderPinA = 3;       
const int encoderPinB = 2;       
volatile int encoderCount = 0;   
volatile int motorRpm = 0;
unsigned long previousTime = 0;
const int currentTime = 1000;
volatile int deltaTime = 0;
volatile int prevTime = 0;
const int setpoint = 1000;
volatile int proportional = 0;
volatile int integral = 0;
volatile int derivative = 0;
volatile int prevError = 0;
#define kp 2.0
#define kd 2.0
#define ki 2.0
#define MIN_SPEED 0
#define MAX_SPEED 255


void setup() {
    pinMode(encoderPinA, INPUT);
    pinMode(encoderPinB, INPUT);
    Serial.begin(9600);
    attachInterrupt(digitalPinToInterrupt(encoderPinA), handleEncoderInterrupt,CHANGE);
}
void encoder() {
 unsigned long previousTime=millis();
 if(millis-previousTime>=currentTime){
   detachInterrupt(digitalPinToInterrupt(encoderPinA));
   float motorRpm=(float)(encoderCount*600.0)/996.0;
 Serial.print("RPM is:");
 Serial.println(motorRpm);
 previousTime=millis();
 encoderCount=0;
 attachInterrupt(digitalPinToInterrupt(encoderPinA),handleEncoderInterrupt, CHANGE);
 delay(100);
 }
}


void loop() {
 
  unsigned long currentTime2 = millis();
  double deltaTime = (currentTime2 - prevTime) / 60000.0; 
   int input = motorRpm;
  double error = setpoint - input;
  double proportional = kp * error;
  double integral =+ ki * error;
  double derivative = kd * (error - prevError) / deltaTime;
  double output = proportional + integral + derivative;
  output = constrain(output, MIN_SPEED, MAX_SPEED);
  if (output >= 0) {
    digitalWrite(encoderPinA, HIGH); 
    analogWrite(encoderPinB, output); 
  } else {
    digitalWrite(encoderPinA, LOW); 
    analogWrite(encoderPinB, -output); 
  }
  prevError = error;
  prevTime = currentTime;

  delay(1000); 
}
void handleEncoderInterrupt() {
  encoderCount++;
  }





