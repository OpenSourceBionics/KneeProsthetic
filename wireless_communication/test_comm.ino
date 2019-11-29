void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop() {
  String readString = "";
  
  while (!Serial.available()) {}
  
  while (Serial.available())
  {
    delay(30);
    if (Serial.available() > 0)
    {
      char c = Serial.read();
      readString += c;
    }
  }

  if (readString.length() > 0)
  {
    Serial.println(readString);
  }
}
