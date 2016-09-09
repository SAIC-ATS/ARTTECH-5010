const int redLedPin = 12;

long lastTransitionTime = 0; // Last time that we moved from one state to another state.
long onDuration = 500; // In milliseconds.
long offDuration = 1000; // In milliseconds.

const int STATE_OFF = 0;
const int STATE_ON = 1;

int currentState = STATE_ON; // Begin the program in the ON state.

void setup() {
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  checkState();
}

void checkState()
{
  if (currentState == STATE_ON)
  {
    /// These are the things wer are going to check if we are in STATE_ON.
    if (getElapsedTime() > onDuration)
    {
      transitionOff();
    }
  }
  else if (currentState == STATE_OFF)
  {
    /// These are the things we are going to check if we are in STATE_OF.
    if (getElapsedTime() > offDuration)
    {
      transitionOn();
    }
  }
}

void transitionOn()
{
  currentState = STATE_ON;
  digitalWrite(redLedPin, HIGH);
  Serial.println("Transition On.");
}

void transitionOff()
{
  currentState = STATE_OFF;
  long now = millis();
  lastTransitionTime = now;
  digitalWrite(redLedPin, LOW);
  Serial.println("Transition Off.");
}

long getElapsedTime()
{
  long now = millis();
  long elapsedTime = now - lastTransitionTime;
  return elapsedTime;
}

