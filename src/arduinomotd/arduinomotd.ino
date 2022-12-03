#include <LiquidCrystal.h>

#define         TIME      2000

LiquidCrystal   lcd(7, 8, 10, 11, 12, 13);

String          text     = "";

void setup()
{
  Serial.begin(9600);

  lcd.begin(16, 2);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("= Arduino Motd =");
  lcd.setCursor(0, 1);
  lcd.print("Waiting...");

  while (!Serial);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("= Arduino Motd =");
  lcd.setCursor(0, 1);
  lcd.print("Ready!");

  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("= Arduino Motd =");
  lcd.setCursor(0, 1);
  lcd.print("Hello, World!");
}

void loop()
{
  if (Serial.available() > 0)
  {
    text = Serial.readString();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("= Arduino Motd =");
    lcd.setCursor(0, 1);
    lcd.print(text);
  }
}
