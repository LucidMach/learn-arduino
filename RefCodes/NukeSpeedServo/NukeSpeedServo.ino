#include<VarSpeedServo.h>
VarSpeedServo s;
void setup() 
{
  s.attach(10);//(pinNumber)
  s.write(90,100);//(angle,percentSpeed)
}

void loop() 
{

}

void flex(int x=180,int t=2000)
{
  s.write(0,100);
  delay(t);
  s.write(90,100);
  delay(t);
  s.write(x,100);
  delay(t);
}

void sweep(int t=20)
{
  for(int x=0;x<=180;x++)
  {
    s.write(x,100);
    delay(t);
  }
  for(int x=180;x>=0;x--)
  {
    s.write(x,100);
    delay(t);
  }
}
