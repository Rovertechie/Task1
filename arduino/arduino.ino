#define Speed  9
 int Dir = 7;


void motorControl(){
  if (Serial.available() > 0) {
    int input = Serial.parseInt();

    if (input == 0) {
      rotateforward();
    } else if (input == 1) {
      rotatebackward();
    }
  }
}
void rotateforward() {
  for (int speed = 0; speed <= 255; speed++) {
    analogWrite(Speed, speed);
    digitalWrite(Dir, HIGH);
    delay(10);
  }
}

void rotatebackward() {
  for (int speed = 0; speed <= 255; speed++) {
    analogWrite(Speed, speed);
    digitalWrite(Dir, LOW);
    delay(10);
  }
}


void setup() {
  Serial.begin(9600);
  pinMode(Speed, OUTPUT);
  pinMode(Dir, OUTPUT);
}

void loop() {
  motorControl();
}




