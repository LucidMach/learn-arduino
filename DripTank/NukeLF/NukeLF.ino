int lp=5;
int ln=3;
int rp=6;
int rn=11;
int ir;
int irl;
int irr;
int h=HIGH;
int l=LOW;
void setup() 
{
 pinMode(lp, OUTPUT);
 pinMode(ln, OUTPUT);
 pinMode(rp, OUTPUT);
 pinMode(rn, OUTPUT);
 pinMode(8, INPUT);
 pinMode(9, INPUT);
 pinMode(7, INPUT);
}

void loop() 
{
  ir=digitalRead(8);
 irl=digitalRead(9);
 irr=digitalRead(7);
 
 if(irl==l && ir==l && irr==l)
   {
    stp();
   }
 else if(irl==l && ir==h && irr==l)
    {
      right(); delay(600);
    }
 else if(irl==h && ir==l && irr==l)
   {
    right(); delay(600);
   }
 else if(irl==l && ir==l && irr==h)
    {
      left(); delay(600);
    }
 else if(irl==h && ir==l && irr==h)
    {
      stopright();
    }
 else if(irl==l && ir==h && irr==h)
    {
      left(); delay(600);
    }
 else if(irl==h && ir==h && irr==l)
    {
      right(); delay(600);
    }
 else if(irl==h && ir==h && irr==h)
    {
      stopleft();
    }
}

void forward()
{
 analogWrite(lp,255);
 analogWrite(ln,0);
 analogWrite(rp,255);
 analogWrite(rn,0);
}

void rev()
{
 analogWrite(lp,0);
 analogWrite(ln,255);
 analogWrite(rp,0);
 analogWrite(rn,255);
 

}
void left()
{
 analogWrite(lp,0);
 analogWrite(ln,255);
 analogWrite(rp,255);
 analogWrite(rn,0);
} 
void right()
{
 analogWrite(lp,255);
 analogWrite(ln,0);
 analogWrite(rp,0);
 analogWrite(rn,255);
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
  analogWrite(lp,255);
  analogWrite(ln,0);
  analogWrite(rp,0);
  analogWrite(rn,0);
}

void stopleft()
{
  analogWrite(lp,0);
  analogWrite(ln,0);
  analogWrite(rp,255);
  analogWrite(rn,0);
}
