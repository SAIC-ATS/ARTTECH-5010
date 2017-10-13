// Press a button to trigger a solenoid

// Pin are button is on
const int BUTTON_PIN = 2;

//..for reference/debug
const int LED_PIN = 13;

//pin our output/transistor is hooked up to
const int OUTPUT_PIN = 7;


//debouncing stuff
unsigned long lastDebounceTime = 0;
unsigned long bounceDelay = 10;

int buttonState = LOW;
int lastButtonState = LOW;


void setup()
{
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(OUTPUT_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  
}

void loop() 
{
    unsigned long now = millis();
    
    // read the value form out button pin
    int reading = digitalRead(BUTTON_PIN);

    // did it change?
    if (reading != lastButtonState)
    {
      lastDebounceTime = now;
    }

    if ((now-lastDebounceTime)> bounceDelay)
    {
      if (reading != buttonState)
      {
        buttonState = reading;

        if (buttonState == LOW)
        {
          buttonPressed();
        } else {
          buttonReleased();
        }
      }
    }

    lastButtonState = reading;
  
}

void buttonPressed()
{
  digitalWrite(OUTPUT_PIN, HIGH);
}

void buttonReleased()
{
  digitalWrite(OUTPUT_PIN, LOW); 
}






