// Better than SteeringWheel
//Streams value of c when changed
// We're making it more precise, green ligth limit is -1,1

int DT= 4, CLK=5;
int red=9, green=10;
String strc, result;
int c=0;
int prevCLK, currCLK;
String encdir;

void setup()
{
  pinMode(DT, INPUT);
  pinMode(CLK, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
  prevCLK= digitalRead(CLK);
}

void loop()
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
    if (c<-1)
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      char bhej[7];
      sprintf(bhej, "left%d", c);
      Serial.println(bhej);
    }
    else if(c>1)
    {
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      char bhej[7];
      sprintf(bhej, "right%d", c);
      Serial.println(bhej);
    }
    else
    {
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
      Serial.println("centre");
    }
   }
  prevCLK=currCLK;
}
