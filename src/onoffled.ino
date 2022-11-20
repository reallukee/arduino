#define LED       2
#define OFF       0
#define ON        1

int data  = 0;

void setup()
{
  Serial.begin(9600);

  while (!Serial);

  pinMode(LED, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0)
  {
    data = Serial.read();

    switch (data - 48)
    {
      case OFF:
        digitalWrite(LED, LOW);
        Serial.println("LED SPENTO!");
        break;

      case ON:
        digitalWrite(LED, HIGH);
        Serial.println("LED ACCESO!");
        break;
    }
  }
}
