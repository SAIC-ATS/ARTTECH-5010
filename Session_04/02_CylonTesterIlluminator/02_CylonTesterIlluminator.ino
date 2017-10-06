const int NUM_LEDS = 6;
const int LED_PINS[NUM_LEDS] = { 11, 10, 9, 6, 5, 3 };

int ledBrightnesses[NUM_LEDS] = { 0, 10, 20, 30, 40, 50 };

void setup()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    pinMode(LED_PINS[i], OUTPUT);
  }

  Serial.begin(9600);
}

void loop()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    ledBrightnesses[i]++;

    if (ledBrightnesses[i] > 255)
    {
      ledBrightnesses[i] = 0;
    }

    Serial.print(ledBrightnesses[i]);
    Serial.print(",");

    analogWrite(LED_PINS[i], ledBrightnesses[i]);
  }

    Serial.println();


  delay(10);
}
