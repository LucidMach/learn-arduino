int irr,ircr,ircl,irl,cr,cl;
int lp=5;
int ln=3;
int rp=6;
int rn=11;
int h=HIGH,l=LOW,p=255;

void setup() 
{
 pinMode(lp, OUTPUT);
 pinMode(ln, OUTPUT);
 pinMode(rp, OUTPUT);
 pinMode(rn, OUTPUT);
 pinMode(7, INPUT);
 pinMode(8, INPUT);
 pinMode(9, INPUT);
 pinMode(10,INPUT);
 cr=analogRead(7);
 cl=analogRead(9);
}

void loop() 
{
 irr=digitalRead(8);
 ircr=analogRead(7);
 ircl=analogRead(9);
 irl=digitalRead(10);

 while(ircr==cr && ircl==cl)
    forward();
 while(cr<ircr && cl>ircl)
    stopright();
 while(cr>ircr && cl<ircl)
    stopleft();
 
 if(ircr==cr && irr==l)
 {
  forward();
  delay(100);
  if(ircr==cr)
    forward();
  else
    right();
 }
 if(ircl==cl && irl==l)
 {
  forward();
  delay(100);
  if(ircl==cl)
    forward();
  else
    left();
 }
          
}

void forward()
{
 analogWrite(lp,p);
 analogWrite(ln,0);
 analogWrite(rp,p);
 analogWrite(rn,0);
}

void rev()
{
 analogWrite(lp,0);
 analogWrite(ln,p);
 analogWrite(rp,0);
 analogWrite(rn,p);
 

}
void left()
{
 analogWrite(lp,0);
 analogWrite(ln,p);
 analogWrite(rp,p);
 analogWrite(rn,0);
} 
void right()
{
 analogWrite(lp,p);
 analogWrite(ln,0);
 analogWrite(rp,0);
 analogWrite(rn,p);
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
  analogWrite(lp,p);
  analogWrite(ln,0);
  analogWrite(rp,0);
  analogWrite(rn,0);
}

void stopleft()
{
  analogWrite(lp,0);
  analogWrite(ln,0);
  analogWrite(rp,p);
  analogWrite(rn,0);
}
