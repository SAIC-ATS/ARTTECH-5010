int brightness = 0;

void setup() 
{
  // We don't configure PWM pins.
}

void loop() 
{
  // Increase the brightness by 1.
  brightness = brightness + 1;

  // If the brightness is greater than 255, set it back to 0.
  if (brightness > 255)
  {
    brightness = 0;
  }


  // Write the brightness to each pin.
  analogWrite(10, brightness);
  analogWrite(11, brightness);
  analogWrite(12, brightness);

  // Wait 100 milliseconds.
  delay(100);

}





