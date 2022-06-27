#include<VarSpeedServo.h>
VarSpeedServo g,p;
int x,z,a,b,ax,bz;
void setup() 
{
 pinMode(A1,INPUT);//x=phone
 pinMode(A3,INPUT);//z=gripper
 p.attach(10);
 g.attach(12);
}

void loop() 
{
 x=analogRead(A1);
 z=analogRead(A3);
 corx();
 cory();
}

void corx()//assuming x = 90 in stable condition 
{
 a=p.read();
 while(x>90)
  ax=a-x+90;
 while(x<90)
  ax=a+x-90; 
 p.write(ax,100);
}
void cory()//assuming z = 90 in stable condition 
{
 b=p.read();
 while(z>90)
  bz=b-z+90;
 while(z<90)
  bz=b+z-90;
 p.write(bz,100);
}
