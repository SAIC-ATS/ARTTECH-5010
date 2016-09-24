const int NUM_LEDS = 6;
const int LED_PINS[NUM_LEDS] = { 11, 10, 9, 6, 5, 3 };
const int NUM_BUTTONS = 6;
const int BUTTON_PINS[NUM_BUTTONS] = { 13, 12, 8, 7, 4, 2 };

int ledBrightnesses[NUM_LEDS] = { 0, 0, 0, 0, 0, 0 };

void setup() {
  for (int i = 0; i < NUM_LEDS; i++)
  {
    pinMode(LED_PINS[i], OUTPUT);
  }

  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
  }

  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    if (digitalRead(BUTTON_PINS[i]) == false)
    {
      ledBrightnesses[i] = 255;
    }
    else
    {
      ledBrightnesses[i]++;

      if (ledBrightnesses[i] > 255)
      {
        ledBrightnesses[i] = 0;
      }
    }

    Serial.print(ledBrightnesses[i]);
    Serial.print(",");


    Serial.println();
  }




  for (int i = 0; i < NUM_LEDS; i++)
  {

    analogWrite(LED_PINS[i], ledBrightnesses[i]);
  }


  delay(10);
}
