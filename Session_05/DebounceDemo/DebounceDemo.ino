const int BUTTON_PIN = 2;
const int LED_PIN = 11;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers
int buttonState = LOW;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

void setup()
{
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{

  unsigned long now = millis();

  // Read the instantaneous value.
  int reading = digitalRead(BUTTON_PIN); // gives us a high or low.

  // Did it change since we last recorded it?
  if (reading != lastButtonState)
  {
    lastDebounceTime = now;
  }

  // We can
  if ((now - lastDebounceTime) > debounceDelay)
  {
    if (reading != buttonState)
    {
      buttonState = reading;

      if (buttonState == LOW)
      {
        buttonPressed();
      }
      else
      {
        buttonReleased();
      }
    }
  }

  lastButtonState = reading;
}


void buttonPressed()
{
  // This stuff happens when the button is pressed.
}


void buttonReleased()
{
  // This stuff happens when the button is realeased.
}
