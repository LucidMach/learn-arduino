int r=2,g=3,b=4;
void setup()
{
  // put your setup code here, to run once:
pinMode(r,OUTPUT);
pinMode(g,OUTPUT);
pinMode(b,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
/*digitalWrite(r,LOW);
delay(1000)
//digitalWrite(r,HIGH);
digitalWrite(g,LOW);
delay(1000);
//digitalWrite(g,HIGH);
digitalWrite(b,LOW);
delay(1000);
//digitalWrite(b,HIGH);*/
ledColour(r);
ledColour(g);
ledColour(b);
}

void ledColour(int pin)
{
digitalWrite(r,HIGH);
digitalWrite(g,HIGH);
digitalWrite(b,HIGH);
delay(1000);
digitalWrite(pin,LOW);
}
