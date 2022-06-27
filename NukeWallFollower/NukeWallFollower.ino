int lp=5;
int ln=3;
int rp=6;
int rn=11;
int L=600;
int ir;
int irl;
int irr;
int x;

void setup() 
{
 pinMode(lp, OUTPUT);
 pinMode(ln, OUTPUT);
 pinMode(rp, OUTPUT);
 pinMode(rn, OUTPUT);
 pinMode(8, INPUT);
 pinMode(7, INPUT);
x=0;
checkmode();
}

void loop() 
{
 ir=digitalRead(8);
 irl=digitalRead(7);
 irr=digitalRead(6);
 
if(x=1)
{
  if(irl==LOW && ir==LOW)
  {
    stopleft();
    delay(150);
  }
  else if(irl==HIGH && ir==LOW)
  {
    stopright();
    delay(150);
  }
  else if(irl==LOW && ir==HIGH)
  {
    right();
    delay(L);
  }
  else if(irl==HIGH && ir==HIGH)
  {
    right();
    delay(L);
  }
}
else if(x=2)
{
  
  if(irr==LOW && ir==LOW)
  {
    stopright();
    delay(150);
  }
  else if(irr==HIGH && ir==LOW)
  {
    stopleft();
    delay(150);
  }
  else if(irr==LOW && ir==HIGH)
  {
    left();
    delay(L);
  }
  else if(irr==HIGH && ir==HIGH)
  {
    left();
    delay(L);
  }
}
}

void checkmode()
{
 do
 {
  if(irl==HIGH)
   {
    x=1;
   }
 
  else if(irr==HIGH)
    {
      x=2;   
    }
}
while(irr==LOW && irl==LOW);

}
void forward()
{
 analogWrite(lp,150);
 analogWrite(ln,0);
 analogWrite(rp,150);
 analogWrite(rn,0);
}

void rev()
{
 analogWrite(lp,0);
 analogWrite(ln,150);
 analogWrite(rp,0);
 analogWrite(rn,150);
 

}
void left()
{
 analogWrite(lp,0);
 analogWrite(ln,150);
 analogWrite(rp,150);
 analogWrite(rn,0);
} 
void right()
{
 analogWrite(lp,150);
 analogWrite(ln,0);
 analogWrite(rp,0);
 analogWrite(rn,150);
}

void stp()
{
  analogWrite(lp,0);
  analogWrite(ln,0);
  analogWrite(rp,0);
  analogWrite(rn,0);
}


void stopright()
{
  analogWrite(lp,150);
  analogWrite(ln,0);
  analogWrite(rp,0);
  analogWrite(rn,0);
}


void stopleft()
{
  analogWrite(lp,0);
  analogWrite(ln,0);
  analogWrite(rp,150);
  analogWrite(rn,0);
}
