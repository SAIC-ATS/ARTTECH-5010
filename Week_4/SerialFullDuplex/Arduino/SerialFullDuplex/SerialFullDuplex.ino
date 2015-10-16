const int POT_PIN_0 = A0;
const int LED_PIN_0 = 11;

// Our input buffer.
String buffer; 

// The brightness of the LED.
int ledBrightness = 0;

void setup() {
  // No pinModes because analog in / out only.

  // Start our Serial device.
  Serial.begin(9600);
}

void loop() {
  readSerialData();
  writeSerialData();
  delay(50); // Delay to keep the refresh rates reasonable.
}


void readSerialData() {
  while (Serial.available() > 0)
  {
    int myByte = Serial.read();

    if (myByte != '\n') // If the character is not a new line character ...
    {
      buffer += (char)myByte; // Add an ASCII byte to the buffer.
    }
    else // ... otherwise, the buffer is complete and should be converted to numbers.
    {
      // Do something with our buffer.
      // In cases where there are several values seperated by commas you can use
      // String operators to find the commas and parse them.
      // See this example for more:
      // http://stackoverflow.com/a/14306981/1518329
      //
      // For now, we just parse a single integer.
      ledBrightness = buffer.toInt(); // Convert the buffer to a single integer.
      buffer = ""; // Reset the buffer.

      // Set the brighness of the LED with the latest value.
      analogWrite(LED_PIN_0, ledBrightness);
    }
  }
}

void writeSerialData() {
  int potValue = analogRead(POT_PIN_0); // Read the pot value.

  String outBuffer = String(potValue); // Convert the pot value to an ASCII string.
  outBuffer += '\n'; // Add the new line character.

  // Here we send the output buffer as an array of ASCII encoded bytes.
  Serial.write(outBuffer.c_str(), outBuffer.length());

  // The above is equivalent to:
  // int potValue = analogRead(POT_PIN_0); // Read the pot value.
  // Serial.println(potValue);
  // 
  // In the first version, we simply use serial write to better 
  // match our openFrameworks code.
}

