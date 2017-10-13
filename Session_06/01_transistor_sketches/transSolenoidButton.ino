//Press a button to trigger a solenoid


//pin are button is on
const int buttonPin = 2;

//..for reference/debug
const int led = 13;

//pin our output/transistor is hooked up to
const int outputPin = 7;


//debouncing stuff
unsigned long lastDebounceTime = 0;
unsigned long bounceDelay = 10;

int buttonState = LOW;
int lastButtonState = LOW;

//unsigned long now=0;

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(outputPin, OUTPUT);
  pinMode(led, OUTPUT);
  
}

void loop() 
{
    unsigned long now = millis();
    
    //read the value form out button pin
    int reading = digitalRead(buttonPin);

    //did it change?
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
  
  digitalWrite(outputPin, HIGH);
}

void buttonReleased()
{
  
  digitalWrite(outputPin, LOW);
  
}






