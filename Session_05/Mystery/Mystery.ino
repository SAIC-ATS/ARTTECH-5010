// Define how many pins we are using.
const int NUM_PINS = 6;

// Define all of the PWM pins.
const int LED_PINS[NUM_PINS] = {3, 5, 6, 9, 10, 11};

// This is a variable that keeps the time (in milliseconds) when next transition should happen.
unsigned long nextTransitionTime = 0;

unsigned long timerInterval = 1000;

// this number will range from 0 - 6
int myBinaryNumber = 0;

void setup() {
  for (int i = 0; i < NUM_PINS; i++)
  {
    pinMode(LED_PINS[i], OUTPUT);
  }
}

void loop() {
  unsigned long now = millis();

  if (now > nextTransitionTime)
  {
    nextTransitionTime = now + timerInterval;

    myBinaryNumber = myBinaryNumber + 1;

    if (myBinaryNumber > 63)
    {
      myBinaryNumber = 0;
    }
  }

  for (int i = 0; i < NUM_PINS; i++)
  {
    digitalWrite(LED_PINS[i], bitRead(myBinaryNumber, i));
  }

}
