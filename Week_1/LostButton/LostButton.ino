const int buttonPin = 12;
const int ledPin = 3;
const int loserPin = 4;

int brightness = 255;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(loserPin, OUTPUT);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (buttonState == false)
  {
    brightness = 255;
  }
  else 
  {
    brightness = brightness - 1;
  }

  if (brightness < 0)
  {
    analogWrite(ledPin, 0);
    digitalWrite(loserPin, HIGH);
  }
  else 
  {
    analogWrite(ledPin, brightness);
    digitalWrite(loserPin, LOW);
  }

  delay(10);

}




