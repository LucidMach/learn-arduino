int lp=5;
int ln=3;
int rp=6;
int rn=11;
int ir;
int h=HIGH;
int l=LOW;
void setup() 
{
 pinMode(lp, OUTPUT);
 pinMode(ln, OUTPUT);
 pinMode(rp, OUTPUT);
 pinMode(rn, OUTPUT);
 pinMode(8, INPUT);
 
}

void loop() 
{
  ir=digitalRead(8);
  
 if(ir==l)
   {
    forward();
    delay(100);
   }
  else if(ir==h)
  {
    right();
    delay(600); 
  }
}

void forward()
{
 analogWrite(lp,155);
 analogWrite(ln,0);
 analogWrite(rp,155);
 analogWrite(rn,0);
}

void rev()
{
 analogWrite(lp,0);
 analogWrite(ln,155);
 analogWrite(rp,0);
 analogWrite(rn,155);
 

}
void left()
{
 analogWrite(lp,0);
 analogWrite(ln,155);
 analogWrite(rp,155);
 analogWrite(rn,0);
} 
void right()
{
 analogWrite(lp,155);
 analogWrite(ln,0);
 analogWrite(rp,0);
 analogWrite(rn,155);
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
  analogWrite(lp,155);
  analogWrite(ln,0);
  analogWrite(rp,0);
  analogWrite(rn,0);
}

void stopleft()
{
  analogWrite(lp,0);
  analogWrite(ln,0);
  analogWrite(rp,155);
  analogWrite(rn,0);
}
