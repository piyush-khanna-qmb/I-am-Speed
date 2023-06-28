//Lagataar stream of data. Python khud decide karega doosre end pe baaki ka hisaab. Ye zyada easy hai


//------------------------------COMPLETED! WORKING CORRECTLY!-------------------------------------
int xPin = A0,  yPin = A1, sPin = 8;
int xVal, yVal, sVal;
String gear;

String gearCheck(int x, int y)
{
  if (x <= 428 && x >= 0)
  {
    if (y >= 0 && y <= 432)
      gear = "Gear1";
    else if (y >= 592 && y <= 1023)
      gear = "Gear2";
  }
  else if (x >= 429 && x <= 591)
  {
    if (y >= 0 && y <= 432)
      gear = "Gear3";
    else if (y >= 592 && y <= 1023)
      gear = "Gear4";
  }
  else if (x >= 592 && x <= 1023)
  {
    if (y >= 0 && y <= 432)
      gear = "Gear5";
    else if (y >= 592 && y <= 1023)
      gear = "Gear6";
  }
  return gear;
}

void setup()
{
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  digitalWrite(sPin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  sVal = digitalRead(sPin);
  if (sVal == 0)
    delay(700);
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  gear = gearCheck(xVal, yVal);
  if (sVal == 0 && gear == "Gear6")
  {
    gear = "GearR";
    delay(1000);
    sVal=1;
  }
  else if (sVal == 0 && gear == "Gear5")
  {
    gear = "Gear7";
    delay(1000);
    sVal=1;
  }
  else if (sVal == 0)
  {
    gear = "GearN";
  }
  Serial.println(gear);
  delay(200); //python se connect hone pe del kardiyo ye step
}
