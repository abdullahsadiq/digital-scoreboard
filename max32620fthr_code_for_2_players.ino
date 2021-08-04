#include <Wire.h>
#include "rgb_lcd.h"

int input;
int currentPlayer;
int score1 = 0;
int score2 = 0;

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
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Player1:");
  lcd.print(score1);
  lcd.setCursor(0, 1);
  lcd.print("Player2:");
  lcd.print(score2);

  switch (currentPlayer) {
    case 1:
      {
        lcd.setRGB(102, 178, 255);
        lcd.setCursor(13, 0);
        lcd.print("<=");
        break;
      }
    case 2:
      {
        lcd.setRGB(255, 102, 102);
        lcd.setCursor(13, 1);
        lcd.print("<=");
        break;
      }
  }
}