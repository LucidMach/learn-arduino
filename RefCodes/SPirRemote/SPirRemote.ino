#include<SPIRremote.h>
SPIRremote remote(A5);
int irv;
void setup() 
{
remote.begin();
}

void loop() 
{
 irv=remote.receive();
 if(irv==1)
  {
   //........
  }
}
