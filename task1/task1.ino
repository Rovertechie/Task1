 int GREEN = 9;
 int RED = 10;
 int POTVAL = A0;


void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(POTVAL, INPUT);
}

}

void loop() {
  int potValue = analogRead(POTVAL);
  int Half = 512; 
  if (potValue <= Half) {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  }
  if (potValue > Half) {
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);

}
