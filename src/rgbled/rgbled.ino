#define RED		4
#define BLUE	3
#define GREEN	2

int red   = 128;
int blue  = 64;
int green = 32;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  
  randomSeed(analogRead(0));
}

void loop()
{
  red = random(256);
  blue = random(256);
  green = random(256);

  analogWrite(RED, red);
  analogWrite(BLUE, blue);
  analogWrite(GREEN, green);

  delay(2500);
}
