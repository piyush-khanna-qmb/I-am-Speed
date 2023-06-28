int nitro =3;
int up= 6, down =7;

void setup() 
{
  // put your setup code here, to run once:
  pinMode(nitro, INPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  digitalWrite(nitro, HIGH);
  digitalWrite(up, HIGH);
  digitalWrite(down, HIGH);
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  Serial.print("Nitro: ");
  Serial.print(digitalRead(nitro));
  Serial.print("   ");
  Serial.print("Up: ");
  Serial.print(digitalRead(up));
  Serial.print("   ");
  Serial.print("Down: ");
  Serial.print(digitalRead(down));
  Serial.println();
}
