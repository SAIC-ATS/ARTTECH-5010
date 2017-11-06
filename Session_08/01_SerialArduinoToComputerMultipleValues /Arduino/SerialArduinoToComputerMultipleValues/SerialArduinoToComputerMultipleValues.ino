// The pin for the potentiometer input.
const int POT_PIN_0 = A0;

// The pin for the first button input.
const int BUTTON_PIN_0 = 12;

// The pin for the second button input.
const int BUTTON_PIN_1 = 11;

void setup() {

  // Set up the first button.
  pinMode(BUTTON_PIN_0, INPUT_PULLUP);

  // Set up the second button.
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  
  // Start our Serial device.
  Serial.begin(9600);
}

void loop() {
  // Read the potentiometer value.
  int potValue = analogRead(POT_PIN_0);

  // Read the first button value.
  int buttonValue_0 = digitalRead(BUTTON_PIN_0);

  // Read the second button value.
  int buttonValue_1 = digitalRead(BUTTON_PIN_1);

  // Send the potentiometer value.
  // This can only send values between 0 - 1023.
  Serial.print(potValue);
  Serial.print(",");

  // Send the first button value.
  // This can only send values between 0 - 1.
  Serial.print(buttonValue_0);
  Serial.print(",");

  // Send the second button value.
  // This can only send values between 0 - 1.
  Serial.print(buttonValue_1);

  // Send the line feed character indicating that we are done sending this "packet".
  Serial.print('\n');

  // Delay to make sure the serial buffers aren't overwhelmed.
  delay(20);
}

