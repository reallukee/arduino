#include <LiquidCrystal.h>
#include <dht_nonblocking.h>

#define TIME  10000
#define DHT11 2

LiquidCrystal   lcd(7, 8, 10, 11, 12, 13);
DHT_nonblocking dht_sensor(DHT11, DHT_TYPE_11);

unsigned long time          = 0;
float         temperature   = 0;
float         humidity      = 0;

void setup()
{
  lcd.begin(16, 2);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(temperature);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print(humidity);
  lcd.print("%");
}

void loop()
{
  if (time == 0)
  {
    time = millis();
  }

  if (millis() - time > TIME)
  {
    dht_sensor.measure(&temperature, &humidity);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(temperature);
    lcd.print("C");
    lcd.setCursor(0, 1);
    lcd.print(humidity);
    lcd.print("%");

    time = 0;
  }
}
