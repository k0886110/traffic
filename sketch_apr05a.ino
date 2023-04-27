#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 5
#define westGreen 4
#define eastRed 12
#define eastYellow 11
#define eastGreen 10
#define pedButton 7  // defining all the west, east and pedistrian lights and buttons
#define pedBlue 6
/*Code that displays traffic lights on a 2 way bridge being west traffic and east traffic going across, while there is also 
pedestrians crossing the bridge as well, we have buttons for each west, east, and pedestrians to go only 1 of these will go at a time. */
//Bugs
//after peds go west will always go next no matter what.
//going from east to ped, west yellow light flashes once then ped goes

#define yellowBlinkTime 500

bool trafficWest = true;  // west = true, east = false
bool pedButtonPushed = false;
int flowTime = 10000;   //10000
int changeDelay = 2000;  // 2000
int walkTime = 10000;   //10000
void yellowFlash(int);   //defining function 1
void turnLightRed(int);   // defining function 2
void shutDownTraffic(int);  //defining function 3


void setup() {    // setting our outputs and inputs
  pinMode(westButton, INPUT);
  pinMode(eastButton, INPUT);
  pinMode(pedButton, INPUT);
  pinMode(pedBlue, OUTPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);
              
  digitalWrite(westRed, LOW);       // setting out traffic lights, we have west traffic GREEN first while east and pedestrians are RED/BLUE.
  digitalWrite(westYellow, LOW);
  digitalWrite(westGreen, HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
  digitalWrite(pedBlue, LOW);
}

void loop() {
  if ((digitalRead(westButton) == HIGH) || (pedButtonPushed))  //West traffic, shutting down east and turning west on.
  {
    if (trafficWest == false) {

      trafficWest = true;
      delay(flowTime);
      digitalWrite(eastGreen, LOW);
      if (!pedButtonPushed)
        turnLightRed(eastRed, eastYellow);  //function 2
      delay(changeDelay);
      yellowFlash(westYellow);  //function 1
    }
    digitalWrite(westYellow, LOW);
    digitalWrite(westRed, LOW);
    digitalWrite(westGreen, HIGH);
    pedButtonPushed = false;
  }

  if ((digitalRead(eastButton) == HIGH) || (pedButtonPushed))  //West traffic, shutting down west and turning east on.
  {
    if (trafficWest == true) {
      trafficWest = false;
      delay(flowTime);
      digitalWrite(westGreen, LOW);
      if (!pedButtonPushed)
        turnLightRed(westRed, westYellow);  // function 2
      delay(changeDelay);
      yellowFlash(eastYellow);  //function 1
    }
    digitalWrite(eastYellow, LOW);
    digitalWrite(eastRed, LOW);
    digitalWrite(eastGreen, HIGH);
    pedButtonPushed = false;
  }

  if (digitalRead(pedButton) == HIGH)  //  pedestrian traffic shutting down traffic both ways and letting pedestrian goes.
  {
    if (trafficWest == false) {
      trafficWest = true;
      delay(flowTime);
      shutDownTraffic(eastRed, eastYellow, eastGreen);  //Function 3
    }
    if (trafficWest == true) {
      trafficWest = false;
      delay(flowTime);
      shutDownTraffic(westRed, westYellow, westGreen);  //Function 3
    }
    digitalWrite(pedBlue, HIGH);
    delay(walkTime);
    for (int a = 0; a < 5; a++) {
      digitalWrite(pedBlue, LOW);
      delay(yellowBlinkTime);
      digitalWrite(pedBlue, HIGH);
      delay(yellowBlinkTime);
    }
    digitalWrite(pedBlue, LOW);
    pedButtonPushed = true;
  }
}
void yellowFlash(int yellowLight)  //Function 1, function for the flashing yellow light when traffic goes from stop to go.
{
  for (int a = 0; a < 5; a++) {
    digitalWrite(yellowLight, HIGH);
    delay(yellowBlinkTime);
    digitalWrite(yellowLight, LOW);
    delay(yellowBlinkTime);
  }
}
void turnLightRed(int redLight, int yellowLight)  //Function 2, function that turns opposite traffic lights red to let the other traffic go.
{
  digitalWrite(yellowLight, HIGH);
  delay(changeDelay);
  digitalWrite(yellowLight, LOW);
  digitalWrite(redLight, HIGH);
}
void shutDownTraffic(int redLight, int yellowLight, int greenLight)  //Function 3, function that shuts down traffic for pedestrians to go.
{
  digitalWrite(greenLight, LOW);
  digitalWrite(yellowLight, HIGH);
  delay(changeDelay);
  digitalWrite(yellowLight, LOW);
  digitalWrite(redLight, HIGH);
}