const int encoderPinA = 3;       
const int encoderPinB = 2;       
volatile int encoderTicks = 0;   
volatile int motorRpm = 0;
unsigned long previousTime = 0;
const int currentTime = 1000;
volatile int deltaTime = 0;
volatile int prevTime = 0;

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
   float motorRpm=(float)(encoderTicks*600.0)/996.0;
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
  double deltaTime = (currentTime2 - prevTime) / 1000.0; 
  input = motorRpm;
  double error = setpoint - input;
  double proportional = kp * error;
  double integral += ki * errorSum;
  double derivative = kd * (error - prevError) / deltaTime;
  output = proportional + integral + derivative;
  output = constrain(output, MIN_SPEED, MAX_SPEED);
  if (output >= 0) {
    digitalWrite(DIR_PIN, HIGH); 
    analogWrite(PWM_PIN, output); 
  } else {
    digitalWrite(DIR_PIN, LOW); 
    analogWrite(PWM_PIN, -output); 
  }
  prevError = error;
  prevTime = currentTime;

  delay(dt * 1000); 
}
void handleEncoderInterrupt() {
  encoderCount++;
  }






