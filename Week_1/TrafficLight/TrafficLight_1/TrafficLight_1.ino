const int redLightPin = 12; // Set the red light's pin number.
const int yellowLightPin = 11; // Set the yellow light's pin number.
const int greenLightPin = 10; // Set the green light's pin number.

const int pedestrianRedLightPin = 3;
const int pedestrianGreenLightPin = 2;

const int buttonPin = 4;

// Create constant values (they can't be changed) that represent our 4 discrete states.
const int STATE_RED = 0;
const int STATE_GREEN = 1;
const int STATE_YELLOW = 2;
const int STATE_PEDESTRIAN_GREEN = 3;

// Keep a variable that represents the current state and start it out with the red state.
int state = STATE_RED;

// This is a variable that keeps the time (in milliseconds) when next transition should happen.
long nextTransitionTime = 0;

bool wasButtonPressed = false;

void setup() {
  pinMode(redLightPin, OUTPUT); // Tell the Arduino that the redLightPin is an output pin.
  pinMode(yellowLightPin, OUTPUT); // Tell the Arduino that the yellowLightPin is an output pin.
  pinMode(greenLightPin, OUTPUT); // Tell the Arduino that the greenLightPin is an output pin.

  pinMode(pedestrianRedLightPin, OUTPUT); // Tell the Arduino that the pedestrianRedLightPin is an output pin.
  pinMode(pedestrianGreenLightPin, OUTPUT); // Tell the Arduino that the pedestrianGreenLightPin is an output pin.

  pinMode(buttonPin, INPUT); // Tell the Arduinot that the buttonPin is an input pin.
}

void loop() {
  checkButton();
  checkTransition(); // Call our main check transition function.
}


void checkButton() {
  if (wasButtonPressed == false)
  {
    wasButtonPressed = digitalRead(buttonPin);
  }
}

void checkTransition() {
  // If the state is red ...
  if (state == STATE_RED)
  {
    // ... and the timer is complete ...
    if (timerComplete() == true)
    {
      // ... transition to green.
      transitionToGreen();
    }
  }
  else if (state == STATE_YELLOW) // ... otherwise if the state is yellow ...
  {
    // ... and the timer is complete ...
    if (timerComplete() == true)
    {
      if (wasButtonPressed == true)
      {
        transitionToPedestrianGreen();
      }
      else
      {
        // ... transition to red.
        transitionToRed();
      }
    }
  }
  else if (state == STATE_GREEN) // ... otherwise if the state is green ...
  {
    // ... and the timer is complete ...
    if (timerComplete() == true)
    {
      // ... transition to yellow.
      transitionToYellow();
    }
  }
  else if (state == STATE_PEDESTRIAN_GREEN)
  {
    if (timerComplete() == true)
    {
      transitionToGreen();
    }
  }
}


void transitionToGreen() {
  long timeNow = millis(); // Sets the timeNow variable to the current number of elapsed milliseconds since the program start.
  nextTransitionTime = timeNow + 2000; // Add 2000 ms to the timeNow and that will be our next transition time.
  state = STATE_GREEN;

  digitalWrite(redLightPin, LOW); // Turn off the red light.
  digitalWrite(yellowLightPin, LOW); // Turn off the yellow light.
  digitalWrite(greenLightPin, HIGH); // Turn ON the green light.

  digitalWrite(pedestrianRedLightPin, HIGH); // Turn OFF the yellow light.
  digitalWrite(pedestrianGreenLightPin, LOW); // Turn off the green light.
}


void transitionToYellow() {
  long timeNow = millis(); // Sets the timeNow variable to the current number of elapsed milliseconds since the program start.
  nextTransitionTime = timeNow + 500; // Add 500 ms to the timeNow and that will be our next transition time.
  state = STATE_YELLOW;

  digitalWrite(redLightPin, LOW); // Turn off the red light.
  digitalWrite(yellowLightPin, HIGH); // Turn ON the yellow light.
  digitalWrite(greenLightPin, LOW); // Turn off the green light.

  digitalWrite(pedestrianRedLightPin, HIGH); // Turn OFF the yellow light.
  digitalWrite(pedestrianGreenLightPin, LOW); // Turn off the green light.
}


void transitionToRed() {
  long timeNow = millis(); // Sets the timeNow variable to the current number of elapsed milliseconds since the program start.
  nextTransitionTime = timeNow + 2000; // Add 2000 ms to the timeNow and that will be our next transition time.
  state = STATE_RED;

  digitalWrite(redLightPin, HIGH); // Turn ON the red light.
  digitalWrite(yellowLightPin, LOW); // Turn off the yellow light.
  digitalWrite(greenLightPin, LOW); // Turn off the green light.

  digitalWrite(pedestrianRedLightPin, HIGH); // Turn OFF the yellow light.
  digitalWrite(pedestrianGreenLightPin, LOW); // Turn off the green light.
}


void transitionToPedestrianGreen() {
  long timeNow = millis(); // Sets the timeNow variable to the current number of elapsed milliseconds since the program start.
  nextTransitionTime = timeNow + 5000; // Add 5000 ms to the timeNow and that will be our next transition time.
  state = STATE_PEDESTRIAN_GREEN;

  digitalWrite(redLightPin, HIGH); // Turn ON the red light.
  digitalWrite(yellowLightPin, LOW); // Turn off the yellow light.
  digitalWrite(greenLightPin, LOW); // Turn off the green light.

  digitalWrite(pedestrianRedLightPin, LOW); // Turn off the yellow light.
  digitalWrite(pedestrianGreenLightPin, HIGH); // Turn on the green light.

  wasButtonPressed = false;
}

bool timerComplete() {
  long timeNow = millis(); // Sets the timeNow variable to the current number of elapsed milliseconds since the program start.

  // If the timeNow is great than the nextTransitionTime, then ...
  if (timeNow > nextTransitionTime) {

    // ... return true.
    return true;
  }
  else // ... otherwise ...
  {
    /// ... return false.
    return false;
  }
}

