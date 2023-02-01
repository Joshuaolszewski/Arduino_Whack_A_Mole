int sX = A0;
int sSX; 
int sS; 

int rNum;
int wins = 0; 
int highScore = 0; 

const int easy = 1000;
const int medium = 500; 
const int hard = 325; 
const int insane = 250; 

int ledPins[] = {6, 5, 7, 8, 4};
int pinCount = 5; 

void setup()
{
  Serial.begin(9600);
  pinMode(sX, INPUT);

  for(int thisPin = 0; thisPin < pinCount; thisPin++)
  {
    pinMode(ledPins[thisPin], OUTPUT);
  }
}

void loop() 
{
  rNum = random(2);
  delay(1000);
  digitalWrite(ledPins[rNum], HIGH);

  if(wins <= 5)
  {
    delay(easy);
  }
  else if(wins <= 10)
  {
    delay(medium);
  }
  else if(wins <= 25)
  {
    delay(hard);
  }
  else
  {
    delay(insane);
  }
  

  sSX = analogRead(sX);
  delay(100);

  sS = 0; 
  
  if(sSX > 868)
  {
    sS = 2; 
  }
  else if(sSX < 284)
  {
    sS = 1;
  }

  digitalWrite(ledPins[rNum], LOW);

  if(sS-1 == rNum)
  {
    wins++; 
    for(int k=0; k<=3; k++)
    {
      digitalWrite(ledPins[3], HIGH);
      delay(50);
      digitalWrite(ledPins[3], LOW);
      delay(50);
    }
  }
  else
  {
     for(int i=0; i<=3; i++)
     {
       digitalWrite(ledPins[2], HIGH);
       delay(50);
       digitalWrite(ledPins[2], LOW);
       delay(50);
      
     }
     if(wins > highScore)
     {
      highScore = wins;
      for(int w=0; w<highScore; w++)
      {
       digitalWrite(ledPins[4], HIGH);
       delay(100);
       digitalWrite(ledPins[4], LOW);
       delay(100);
      
      }
     }
     wins = 0; 
  }
}
