const int NUM_LEDS = 6;
const int LED_PINS[NUM_LEDS] = { 11, 10, 9, 6, 5, 3 };

int ledValue = 0;

void setup() {
  for (int i = 0; i < NUM_LEDS; i++)
  {
    pinMode(LED_PINS[i], OUTPUT);
  }
}

void loop() {
  ledValue++;

  if (ledValue > 255)
  {
    ledValue = 0;
  }

  for (int i = 0; i < NUM_LEDS; i++)
  {
    analogWrite(LED_PINS[i], ledValue);
  }

  delay(10);
}
