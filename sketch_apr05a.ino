#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define wpedButton 9 // defining the West pedestrian button & LED
#define wpedBlue 8
#define epedButton 6 // defining the East pedestrian button & LED
#define epedBlue 7


#define yellowBlinkTime 500

boolean trafficWest = true; // west = true, east = false
int flowTime = 1000; //10000
int changeDelay = 200; // 2000



void setup()
{
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  pinMode(epedButton, INPUT);
  pinMode(wpedButton, INPUT);
  pinMode(epedBlue, OUTPUT);
  pinMode(wpedBlue, OUTPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);

  digitalWrite(westRed, LOW);
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
  digitalWrite(epedBlue, LOW);
  digitalWrite(wpedBlue, LOW);
  digitalWrite(epedButton, LOW);
}

void loop()
{
  if ( digitalRead(westButton) == HIGH)
  {
    if ( trafficWest != true)
    {
      trafficWest = true;
      delay(flowTime);
      digitalWrite(eastGreen, LOW);

      digitalWrite(eastYellow, HIGH);
      delay(changeDelay);
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, HIGH);
      delay(changeDelay);
      for ( int a = 0; a < 5; a++)
      {
        digitalWrite(westYellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(westYellow, HIGH);
        delay(yellowBlinkTime);
      }
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, LOW);
      digitalWrite(westGreen, HIGH);

    }
  }
  if ( digitalRead(eastButton) == HIGH)
  {
    if ( trafficWest == true)
    {
      trafficWest = false;
      delay(flowTime);
      digitalWrite(westGreen, LOW);
      digitalWrite(westYellow, HIGH);
      delay(changeDelay);
      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, HIGH);
      delay(changeDelay);
      for ( int a = 0; a < 5; a++)
      {
        digitalWrite(eastYellow, LOW);
        delay(yellowBlinkTime);
        digitalWrite(eastYellow, HIGH);
        delay(yellowBlinkTime);
      }
      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, LOW);
      digitalWrite(eastGreen, HIGH);
    }
  }
    if ( digitalRead(epedButton) == HIGH) // East pedestrian button funtion
    {

      {
        delay(flowTime);
        digitalWrite(westGreen, LOW);
        digitalWrite(eastGreen, LOW);
        digitalWrite(westRed, HIGH);
        digitalWrite(eastRed, HIGH);
        digitalWrite(epedBlue, HIGH);
        delay(10000);
        for ( int a = 0; a < 5; a++)
        {
          digitalWrite(epedBlue, LOW);
          delay(1000);
        }

      }
    }
    if ( digitalRead(wpedButton) == HIGH) // East pedestrian button funtion
    {

      {
        delay(flowTime);
        digitalWrite(westGreen, LOW);
        digitalWrite(eastGreen, LOW);
        digitalWrite(westRed, HIGH);
        digitalWrite(eastRed, HIGH);
        digitalWrite(wpedBlue, HIGH);
        delay(10000);
        for ( int a = 0; a < 5; a++)
        {
          digitalWrite(wpedBlue, LOW);
          delay(1000);
        }
      
    }
  }
}
