#define LED1  2
#define LED2  3
#define LED3  4
#define LED4  5
#define LED5  6

void setup()
{
  Serial.begin(9600);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  digitalWrite(LED_BUILTIN, LOW);
}

bool evaluate(byte data, byte bit)
{
  return (data >> bit) & 1;
}

void loop()
{
  if (Serial.available() > 1)
  {
    int data = Serial.readString().toInt();

    digitalWrite(LED1, evaluate(data, 0));
    digitalWrite(LED2, evaluate(data, 1));
    digitalWrite(LED3, evaluate(data, 2));
    digitalWrite(LED4, evaluate(data, 3));
    digitalWrite(LED5, evaluate(data, 4));
  }
}
