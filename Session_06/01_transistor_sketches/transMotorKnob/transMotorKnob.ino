// Control PWM via a transistor.
// Potentiometer on A0 contols PWM 

const int POT_PIN = A0;
const int PWM_CONTROL_PIN = 6;

// Smoothed value.
float smoothedValue = 0;

// The amount 0-1 to smooth.
float smoothAmount = 0.5;

void setup() 
{
}

void loop() 
{
  // Get the reading from our potentiometer on A0.
  int potValue = analogRead(POT_PIN);
  
  // Smooth out the reading to elemenate noise/fast changes.
  smoothedValue = potValue * (1 - smoothAmount) + smoothedValue * smoothAmount;
  
  // Map our value (from 0 - 1023) to our output range (0 - 255).
  int outputValue = map(smoothedValue, 0, 1023, 0, 255);

  // Write that value to our output pin, which is controling the voltage going into the transistor.
  analogWrite(PWM_CONTROL_PIN, outputValue);
  
  delay(10);
  
}

