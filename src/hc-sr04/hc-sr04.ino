#include "SR04.h"

#define ECHO      12
#define TRIG      11
#define LED       2
#define BUZZER    3
#define DISTANCE  100
#define TIME      100

SR04 sr04     = SR04(12, 11);

long distance = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
  distance = sr04.Distance();

  if (distance <= DISTANCE)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);
  }

  delay(TIME);
}
