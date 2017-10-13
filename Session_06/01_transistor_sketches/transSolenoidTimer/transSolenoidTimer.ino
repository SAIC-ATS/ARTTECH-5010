//Button on and off state
//solenoid will repeatedly trigger during button on state

const int BUTTON_PIN = 12;
const int OUTPUT_PIN = 6;

unsigned long lastDebounceTime = 0;
unsigned long bounceDelay = 10;

int buttonState = LOW;
int lastButtonState = LOW;

unsigned long now = 0;
unsigned long previousMillis = 0;

// This is what sets how quickly you are switching
// your output pin between HIGH and LOW.
// Maybe we can set the speed with a potentiometer?
int timer = 250; // Duration between HIGH states, milliseconds.
int timerPlus = timer + 250; // How is the pin HIGH

void setup()
{
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(OUTPUT_PIN, OUTPUT);
}

void loop() 
{
    now = millis();
    
    // Read the value form our button pin.
    int reading = digitalRead(BUTTON_PIN);

    // Did it change?
    if (reading != lastButtonState)
    {
      lastDebounceTime = now;
    }

    if ((now-lastDebounceTime) > bounceDelay)
    {
      if (reading != buttonState)
      {
        buttonState = reading;
      }
    }

    lastButtonState = reading;
    
    checktime();
}


void checktime() 
{
  if (now - previousMillis >= timerPlus)
  {   
      digitalWrite(OUTPUT_PIN, LOW);
      
      previousMillis = now;     
  } 
  else if (now - previousMillis >= timer)
  {
    if (buttonState)
    {
      digitalWrite(OUTPUT_PIN, HIGH);
    }
  }
  else
  {
     digitalWrite(OUTPUT_PIN, LOW);
  } 
}




