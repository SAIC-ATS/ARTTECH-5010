int ledValue = 1;
// float
// bool ...

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  digitalWrite(10, ledValue);
  digitalWrite(11, ledValue);
  digitalWrite(12, ledValue);

  if (ledValue == 0)
  {
    ledValue = 1;
  }
  else
  {
    ledValue = 0;
  }

  delay(1000);
}
