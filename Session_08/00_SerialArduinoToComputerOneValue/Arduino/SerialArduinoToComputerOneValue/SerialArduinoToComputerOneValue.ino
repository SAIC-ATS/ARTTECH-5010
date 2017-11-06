// The pin for the potentiometer input.
const int POT_PIN_0 = A0;

void setup() {
  // Start our Serial device.
  Serial.begin(9600);
}

void loop() {
  // Read the potentiometer value.
  int potValue = analogRead(POT_PIN_0);

  // Send the potentiometer value.
  // This can only send values between 0 - 1023.
  Serial.print(potValue);

  // Send the line feed character indicating that we are done sending this "packet".
  Serial.print('\n');

  // Delay to make sure the serial buffers aren't overwhelmed.
  delay(20);
}

