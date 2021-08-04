/*
This is the code for the XMC2Go. To add more players, change the variable 'numPlayers' to whatever you want. You may also need to change the size of the arrays 'tempScore' and 'score'.
*/

#include <Tle493d_w2b6.h>
const float pi = (22.0 / 7.0);
float previousAngle = 0.0;   
bool switchPressed;
int numPlayers = 2;   //Change this to add more players
int currentPlayer;

//If you add more players, you will need to change the size of both these arrays
float tempScore[4];
int score[4];

Tle493d_w2b6 Tle493dMagnetic3DSensor = Tle493d_w2b6();
void setup() {
  Serial.begin(9600);
  Tle493dMagnetic3DSensor.begin();
  Tle493dMagnetic3DSensor.begin();
  for (int i = 0; i < numPlayers; i++) {
    tempScore[i] = 0;
    score[i] = 0;
  }
}

void loop() {
  Tle493dMagnetic3DSensor.updateData();
  delay(100);
  isSwitchPressed();

  float angle = pi + Tle493dMagnetic3DSensor.getAzimuth();

  if (!switchPressed) {
    for (int i = 0; i <= numPlayers; i++) {
      if (angle > ((2 * pi) / numPlayers)*i && angle < ((2 * pi) / numPlayers) * (i + 1)) {
        currentPlayer = i + 1;
      }
    }
  } else if (switchPressed) {
    //Serial.println("Switch pressed");
    if (angle - previousAngle < 0) {
      increaseScore();
    }
    else if (angle - previousAngle > 0) {
      decreaseScore();
    }
  }

    Serial.print("99999");
    Serial.print(",");
    Serial.print(currentPlayer);
    Serial.print(",");
    for (int i = 0; i < numPlayers; i++) {
      Serial.print(score[i]);
      if (i + 1 != numPlayers) {
        Serial.print(",");
      }
    }
    Serial.println();

  previousAngle = angle;
}

void isSwitchPressed() {
  if (Tle493dMagnetic3DSensor.getNorm() < 55) {
    switchPressed = false;
  }
  else if (Tle493dMagnetic3DSensor.getNorm() > 85) {
    switchPressed = true;
  }
}

void increaseScore() {
  for (int i = 0; i < numPlayers; i++) {
    if (i + 1  == currentPlayer) {
      tempScore[i] = tempScore[i] + 0.17;
      score[i] = tempScore[i];
    }
  }
}

void decreaseScore() {
  for (int i = 0; i < numPlayers; i++) {
    if (i + 1  == currentPlayer) {
      tempScore[i] = tempScore[i] - 0.17;
      if (tempScore[i] < 0) {
        tempScore[i] = 0;
      }
      score[i] = tempScore[i];
    }
  }
}
