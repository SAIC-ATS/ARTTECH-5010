// The pin for the potentiometer input.
const int POT_PIN_0 = A0;

// The pin for the first button input.
const int BUTTON_PIN_0 = 12;

// The pin for the second button input.
const int BUTTON_PIN_1 = 11;

// The pin for the first led.
const int LED_PIN_0 = 5;

// The pin for the second led.
const int LED_PIN_1 = 6;

// The pin for the third led.
const int LED_PIN_2 = 9;

// The led brightness 0 set from the computer.
int ledBrightness_0 = 0;

// The led brightness 1 set from the computer.
int ledBrightness_1 = 0;

// The led brightness 2 set from the computer.
int ledBrightness_2 = 0;

// The input buffer.
String buffer;

void setup() {
  // Set up the first button.
  pinMode(BUTTON_PIN_0, INPUT_PULLUP);

  // Set up the second button.
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);

  // Start our Serial device.
  Serial.begin(9600);
}

void loop() {
  readSerialData();
  writeSerialData();
}


void readSerialData()
{
  // As long as there is serial data available to read, repeat.
  while (Serial.available() > 0)
  {
    // Read the byte.
    char b = Serial.read();

    // End of line character.
    if (b == '\n')
    {
      int firstCommaIndex = buffer.indexOf(",", 0);
      int secondCommaIndex = buffer.indexOf(",", firstCommaIndex + 1);

      // The comma positions must be greater than -1.
      if (firstCommaIndex > -1 and secondCommaIndex > -1)
      {
        ledBrightness_0 = buffer.substring(0, firstCommaIndex).toInt();
        ledBrightness_1 = buffer.substring(firstCommaIndex + 1, secondCommaIndex).toInt();
        ledBrightness_2 = buffer.substring(secondCommaIndex + 1).toInt();

        analogWrite(LED_PIN_0, ledBrightness_0);
        analogWrite(LED_PIN_1, ledBrightness_1);
        analogWrite(LED_PIN_2, ledBrightness_1);
      }

      // Clear the buffer.
      buffer = "";
    }
    else
    {
      // If it's not the line feed character, add it to the buffer.
      buffer += b;
    }
  }
}



void writeSerialData()
{
  // Read the potentiometer value.
  int potValue = analogRead(POT_PIN_0);

  // Read the first button value.
  int buttonValue_0 = digitalRead(BUTTON_PIN_0);

  // Read the second button value.
  int buttonValue_1 = digitalRead(BUTTON_PIN_1);

  // Send the potentiometer value.
  // This can only send values between 0 - 1023.
  Serial.print(potValue);
  Serial.print(",");

  // Send the first button value.
  // This can only send values between 0 - 1.
  Serial.print(buttonValue_0);
  Serial.print(",");

  // Send the second button value.
  // This can only send values between 0 - 1.
  Serial.print(buttonValue_1);

  // Send the line feed character indicating that we are done sending this "packet".
  Serial.print('\n');
}

