const int playerOneButtonPin = 4;
const int playerTwoButtonPin = 3;
const int playerOneWinningPin = 12;
const int playerTwoWinningPin = 11;
const int countdownLedPin = 10;
const int gameOverLedPin = 9;

int timer = 255;
bool playerOneWinning = false;
bool playerTwoWinning = false;

void setup() {
  pinMode(playerOneButtonPin, INPUT_PULLUP);
  pinMode(playerTwoButtonPin, INPUT_PULLUP);

  pinMode(playerOneWinningPin, OUTPUT);
  pinMode(playerTwoWinningPin, OUTPUT);

  pinMode(gameOverLedPin, OUTPUT);
}

void loop() {
  bool playerOneButtonState = digitalRead(playerOneButtonPin);
  bool playerTwoButtonState = digitalRead(playerTwoButtonPin);

  if (playerOneButtonState == LOW)
  {
    playerOneWinning = true;
    playerTwoWinning = false;
    timer = 255;
  }
  else if (playerTwoButtonState == LOW)
  {
    playerOneWinning = true;
    playerTwoWinning = false;
    timer = 255;
  }
  else 
  {
      if (timer > 0)
      {
        timer = timer - 1;
      }
  }
  

  // Render the variables!
  digitalWrite(playerOneWinningPin, playerOneWinning);
  digitalWrite(playerTwoWinningPin, playerTwoWinning);
  analogWrite(countdownLedPin, timer);

  if (timer > 0)
  {
    digitalWrite(gameOverLedPin, LOW);
  }
  else 
  {
    digitalWrite(gameOverLedPin, HIGH);
  }

  delay(10);
}

