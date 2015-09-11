const int redLightPin = 12; // Set the red light's pin number.
const int yellowLightPin = 11; // Set the yellow light's pin number.
const int greenLightPin = 10; // Set the green light's pin number.

// Create constant values (they can't be changed) that represent our 3 discrete states.
const int STATE_RED = 0;
const int STATE_GREEN = 1;
const int STATE_YELLOW = 2;

// Keep a variable that represents the current state and start it out with the red state.
int state = STATE_RED;

// This is a variable that keeps the time (in milliseconds) when next transition should happen.
long nextTransitionTime = 0;

void setup() {
  pinMode(redLightPin, OUTPUT); // Tell the Arduino that the redLightPin is an output pin.
  pinMode(yellowLightPin, OUTPUT); // Tell the Arduino that the yellowLightPin is an output pin.
  pinMode(greenLightPin, OUTPUT); // Tell the Arduino that the greenLightPin is an output pin.
}

void loop() {
  checkTransition(); // Call our main check transition function.
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
      // ... transition to red.
      transitionToRed();
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
}


void transitionToGreen() {
  long timeNow = millis(); // Sets the timeNow variable to the current number of elapsed milliseconds since the program start.
  nextTransitionTime = timeNow + 2000; // Add 2000 ms to the timeNow and that will be our next transition time.
  state = STATE_GREEN;

  digitalWrite(redLightPin, LOW); // Turn off the red light.
  digitalWrite(yellowLightPin, LOW); // Turn off the yellow light.
  digitalWrite(greenLightPin, HIGH); // Turn ON the green light.
}


void transitionToYellow() {
  long timeNow = millis(); // Sets the timeNow variable to the current number of elapsed milliseconds since the program start.
  nextTransitionTime = timeNow + 500; // Add 500 ms to the timeNow and that will be our next transition time.
  state = STATE_YELLOW;

  digitalWrite(redLightPin, LOW); // Turn off the red light.
  digitalWrite(yellowLightPin, HIGH); // Turn ON the yellow light.
  digitalWrite(greenLightPin, LOW); // Turn off the green light.
}


void transitionToRed() {
  long timeNow = millis(); // Sets the timeNow variable to the current number of elapsed milliseconds since the program start.
  nextTransitionTime = timeNow + 2000; // Add 2000 ms to the timeNow and that will be our next transition time.
  state = STATE_RED;

  digitalWrite(redLightPin, HIGH); // Turn ON the red light.
  digitalWrite(yellowLightPin, LOW); // Turn off the yellow light.
  digitalWrite(greenLightPin, LOW); // Turn off the green light.
}


bool timerComplete() {
  long timeNow = millis(); // Sets the timeNow variable to the current number of elapsed milliseconds since the program start.

  // If the timeNow is great than the nextTransitionTime, then ...
  if (timeNow > nextTransitionTime)
  {
    // ... return true.
    return true;
  }
  else // ... otherwise ...
  {
    /// ... return false.
    return false;
  }
}

