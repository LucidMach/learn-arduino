#define LED 13
int io;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT); 
}

void loop()
{
  io = Serial.read();
  delay(200);
  if(io=='1')
  {
    digitalWrite(LED,HIGH);
  }
  if(io=='0')
  {
    digitalWrite(LED,0);
  }
}
