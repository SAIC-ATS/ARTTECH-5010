const int buttonPin = 4;
const int countdownLedPin = 11;
const int gameOveLedPin = 12;

int brightness = 255;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(countdownLedPin, OUTPUT);
  pinMode(gameOveLedPin, OUTPUT);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  // This is somewhat unintuitive. Normally this would be
  // HIGH if the button is pressed, but when using INPUT_PULLUP
  // the behavior is inverted.
  if (buttonState == LOW)
  {
    brightness = 255;
  }
  else
  {
    // If the brightness is above zero, decrement it.
    if (brightness > 0)
    {
      brightness = brightness - 1;
    }
  }

  if (brightness > 0)
  {
    analogWrite(countdownLedPin, brightness);
    digitalWrite(gameOveLedPin, LOW);
  }
  else 
  {
    analogWrite(gameOveLedPin, 0);
    digitalWrite(countdownLedPin, HIGH);
  }

  delay(10);

}

