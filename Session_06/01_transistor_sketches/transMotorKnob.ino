//contol speed of a motor.
// pot on a0 contols PWM 
//Chris, you might want to rewrite this?

const int controlPin = 6;
int outputValue = 0;

int potValue= 0;

//smoothing out values from our pot
float smoothValue = 0;
float smoothAmount = 0.5; // How smooth do we want it?

void setup() 
{
  pinMode(controlPin, OUTPUT);
 

}

void loop() 
{
  //Get the reading from our potentiometer on A0
  potValue=analogRead(A0);
  
  //smooth out the reading to elemenate noise/fast changes
  smoothValue = potValue * (1 - smoothAmount) + smoothValue*smoothAmount;
  
  //map our value (from 0-1023) to our output range (0-255)
  outputValue = map(smoothValue, 0, 1023, 0, 255);

  //write that value to our output pin, which is controling the voltage going into the transistor
  analogWrite(controlPin, outputValue);
  
  delay(10);
  
}

