/* Simulator encorporating Gearbox and Steering wheel*/
//-----------LAST MODEL WITH PERFECT WORKING-------------

//---------Pins------------
int xPin = A0,  yPin = A1, sPin = 8;
int DT= 4, CLK=5;
int red=9, green=10;
int nitro =3;
int up= 6, down =7;
//---------/Pins------------


//---------Vars------------
int xVal, yVal, sVal;
String gear;
int c=0;
int prevCLK, currCLK;
int pmils, cmils;
String encdir, steer;
String st;
int upSt, downSt, nitroSt;
//---------/Vars------------

//---------Auxiliary Functions------------
String gearCheck(int x, int y)
{
  if (x <= 428 && x >= 0)
  {
    if (y >= 0 && y <= 432)
      gear = "G1";
    else if (y >= 592 && y <= 1023)
      gear = "G2";
  }
  else if (x >= 429 && x <= 591)
  {
    if (y >= 0 && y <= 432)
      gear = "G3";
    else if (y >= 592 && y <= 1023)
      gear = "G4";
  }
  else if (x >= 592 && x <= 1023)
  {
    if (y >= 0 && y <= 432)
      gear = "G5";
    else if (y >= 592 && y <= 1023)
      gear = "G6";
  }
  return gear;
}

String LCRcheck()
{
  currCLK= digitalRead(CLK);
  if (currCLK!= prevCLK)
  {
    if(digitalRead(DT)!=currCLK)
    {
      c--;
    }
    else
    {
      c++;
    }
   }
  if (c<-2)
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      encdir= "R";
    }
    else if(c>2)
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      encdir= "L";
    }
    else
    {
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
      encdir = "C";
    }
    prevCLK=currCLK;   
    return encdir;
}

//---------/Auxiliary Functions------------


void setup()
{
  Serial.begin(9600);
  pinMode(DT, INPUT);
  pinMode(CLK, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  prevCLK= digitalRead(CLK);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  digitalWrite(sPin, HIGH);
  pinMode(nitro, INPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  digitalWrite(nitro, HIGH);
  digitalWrite(up, HIGH);
  digitalWrite(down, HIGH);
  st="";
  pmils=0;
}


void loop()
{
  st="";
  //----------Gearbox------->
  sVal = digitalRead(sPin);
  if (sVal == 0)
    delay(700);
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  gear = gearCheck(xVal, yVal);
  if (sVal == 0 && gear == "G6")
  {
    gear = "GR";
    delay(1000);
    sVal=1;
  }
  else if (sVal == 0 && gear == "G5")
  {
    gear = "G7";
    delay(1000);
    sVal=1;
  }
  else if (sVal == 0)
  {
    gear = "GN";
  }
  if(gear=="")
    gear="GN";
  st=st+gear;
  
  //----------Steering------->

  steer= LCRcheck();
  st= st+steer;

  //----------Valves------->
  upSt= digitalRead(up);
  downSt= digitalRead(down);
  nitroSt= digitalRead(nitro);
  st= st+ String(upSt);
  st= st+ String(downSt);
  st= st+ String(nitroSt);

  //----------Output------->
  cmils=millis();
  if(cmils-pmils > 150)
  {
    Serial.println(st);
    pmils=cmils;
  }
}
