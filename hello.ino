#define PORTA 2

bool click = false;

void setup()
{
  Serial.begin(9600);

  pinMode(PORTA, INPUT);

  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
  if (digitalRead(PORTA) == HIGH)
  {
    click = true;
  }

  if (digitalRead(PORTA) == LOW)
  {
    if (click)
    {
      Serial.println("Hello!");
      
      click = false;
    }
  }
}
