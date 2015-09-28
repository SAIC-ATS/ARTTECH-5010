// Define how many pins we are using.
const int NUM_PINS = 8;

// Define all of the PWM pins. //You will probably have to change these
const int LED_PINS[NUM_PINS] = {6, 7, 8, 9, 10, 11, 12, 13};

// LED Brightness values.
int ledValues[NUM_PINS] = {0, 0, 0, 0, 0, 0};

// Define our analog intput potentiometer pin.
const int POT_PIN = A0;

// This is a variable that keeps the time (in milliseconds) when next transition should happen.
long nextTransitionTime = 0;

// This is a variable that keeps track of how often values are decremented.
long nextDecrementTime = 0;

// This is the current timer interval.
long timerInterval = 0;

// The decrement timer in milliseconds.
long decrementInterval = 2;

// This is the current pin that is completely illuminated.
int currentPin = 0;

// This tells us whether we are going up the array, or down the array.
bool goingUp = true;

void setup() {
}

void loop() {
  checkInput();
  checkTransition();
  updateValues();
  setOuput();
}

void checkInput() {
  timerInterval = analogRead(POT_PIN);
}

void checkTransition() {

  long now = millis();

  if (now > nextTransitionTime)
  {
    nextTransitionTime = now + timerInterval;

    if (goingUp) {
      currentPin = currentPin + 1;

      if (currentPin >= NUM_PINS) {
        goingUp = false;
        currentPin = NUM_PINS - 1;
      }

    } else {
      currentPin = currentPin - 1;
      if (currentPin < 0) {
        goingUp = true;
        currentPin = 1;
      }
    }

    ledValues[currentPin] = 255;
  }
}

void updateValues() {
  long now = millis();

  if (now > nextDecrementTime)
  {
    nextDecrementTime = now + decrementInterval;

    for (int i = 0; i < NUM_PINS; i++)
    {
      ledValues[i] = constrain(ledValues[i] - 1, 0, 255);
    }
  }
}

void setOuput() {
  for (int i = 0; i < NUM_PINS; i++)
  {
    analogWrite(LED_PINS[i], ledValues[i]);
  }
}
