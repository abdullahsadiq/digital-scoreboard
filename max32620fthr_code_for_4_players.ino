/*
Just an example for the scoreboard with 4 players. 
To use it, simply change 'numPlayers' to 4 in the XMC2Go code and upload, then upload this code to the MAX32620FTHR. 
Then connect everything according to the connection diagram and test.
*/

#include <Wire.h>
#include "rgb_lcd.h"

int input;
int currentPlayer;
int score1 = 0;
int score2 = 0;
int score3 = 0;
int score4 = 0;

rgb_lcd lcd;

void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  const int colorR = 255;
  const int colorG = 255;
  const int colorB = 255;

  Serial.begin(9600);
  Serial2.begin(9600);

  lcd.setRGB(colorR, colorG, colorB);
  lcd.setCursor(5, 0);
  lcd.print("Digital");
  lcd.setCursor(3, 1);
  lcd.print("Scoreboard");

  delay(1700);
}

void loop()
{

  input = Serial2.parseInt();
  if (input == 99999) {
    currentPlayer = Serial2.parseInt();
    score1 = Serial2.parseInt();
    score2 = Serial2.parseInt();
    score3 = Serial2.parseInt();
    score4 = Serial2.parseInt();
  }

  Serial.print(currentPlayer);
  Serial.print(",");
  Serial.print(score1);
  Serial.print(",");
  Serial.print(score2);
  Serial.print(",");
  Serial.print(score3);
  Serial.print(",");
  Serial.println(score4);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("P1:");
  lcd.print(score1);
  lcd.setCursor(10, 0);
  lcd.print("P2:");
  lcd.print(score2);
  lcd.setCursor(0, 1);
  lcd.print("P3:");
  lcd.print(score3);
  lcd.setCursor(10, 1);
  lcd.print("P4:");
  lcd.print(score4);

  switch (currentPlayer) {
    case 1:
      {
        lcd.setRGB(102, 178, 255);
        lcd.setCursor(6, 0);
        lcd.print("<=");
        break;
      }
    case 2:
      {
        lcd.setRGB(178, 102, 255);
        lcd.setCursor(7, 0);
        lcd.print("=>");
        break;
      }
    case 3:
      {
        lcd.setRGB(255, 102, 102);
        lcd.setCursor(6, 1);
        lcd.print("<=");
        break;
      }
    case 4:
      {
        lcd.setRGB(102, 255, 178);
        lcd.setCursor(7, 1);
        lcd.print("=>");
        break;
      }
  }
}
