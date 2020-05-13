void setup() {
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello...");
}

void loop() {
  Serial.print("RPM: ");Serial.println(analogRead(2));
  analogWrite(2, 150);

}
