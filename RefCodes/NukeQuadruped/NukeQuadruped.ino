#include<VarSpeedServo.h>
VarSpeedServo l1,l2,l3,l4,b1,b2,b3,b4;

void setup() 
{
 b1.attach(3);
 b2.attach(4);
 b3.attach(6);
 b4.attach(8);
 
 l1.attach(2);
 l2.attach(5);
 l3.attach(7);
 l4.attach(9);
 stand();
 delay(1000);
}

void loop() 
{
 
}

void stand()
{
 b1.write(90,100);
 b2.write(90,100);
 b3.write(90,100);
 b4.write(90,100);
 
 l1.write(60,100);
 l2.write(60,100);
 l3.write(60,100);
 l4.write(60,100);  
}
void movit(VarSpeedServo l,int n,VarSpeedServo b,int m)
{
  l.write(n,100);
  b.write(m,100);
}
