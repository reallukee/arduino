#include <Servo.h>

#define SERVO   12
#define BUTTON1 2
#define BUTTON2 3

Servo servo;

void setup()
{
  pinMode(SERVO, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  
  digitalWrite(LED_BUILTIN, LOW);

  servo.attach(SERVO);
}

void loop()
{
  if (digitalRead(BUTTON1) == HIGH)
  {
    servo.write(0);
  }

  if (digitalRead(BUTTON2) == HIGH)
  {
    servo.write(180);
  }
}
