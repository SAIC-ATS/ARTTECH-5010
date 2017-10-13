//Button on and off state
//solenoid will repeatedly trigger during button on state


const int buttonPin = 2;
const int led = 13;
const int outputPin = 7;

unsigned long lastDebounceTime = 0;
unsigned long bounceDelay = 10;

int buttonState = LOW;
int lastButtonState = LOW;
boolean onState = false;

unsigned long now=0;
unsigned long previousMillis = 0;

//this is what sets how quikly you are switching
//your output pin between HIGH and LOW
//maybe we can set the speed with a potentiometer?
int timer = 250; //  in ms-- how long between the HIGH states
int timerPlus = timer + 250; // how is the pin HIGH

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(outputPin, OUTPUT);
  pinMode(led, OUTPUT);
  
}

void loop() 
{
    now = millis();
    
    //read the value form our button pin
    int reading = digitalRead(buttonPin);

    //did it change?
    if (reading != lastButtonState)
    {
      lastDebounceTime = now;
    }

    if ((now-lastDebounceTime) > bounceDelay)
    {
      if (reading != buttonState)
      {
        buttonState = reading;
        if (buttonState == LOW)
        if (onState)
        {
          onState = false;
        } else {
          onState = true;
        }
        
      }
    }

    lastButtonState = reading;
    
    checktime();
}


void checktime() 
{
  if (now - previousMillis >= timerPlus)
  {   
      digitalWrite(led, LOW);
      digitalWrite(outputPin, LOW);
      
      previousMillis = now;     
  } 
  else if (now - previousMillis >= timer)
  {
    if (onState)
    {
      digitalWrite(led, HIGH);
      digitalWrite(outputPin, HIGH);
    }
  }
  else
  {
    digitalWrite(led, LOW);
    digitalWrite(outputPin, LOW);
  } 
}




