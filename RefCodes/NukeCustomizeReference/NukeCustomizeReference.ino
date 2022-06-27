int lp=5;
int ln=3;
int rp=6;
int rn=11;
int ir;
int irl;
int irr;
int P=150;

void setup() 
{
 pinMode(lp, OUTPUT);
 pinMode(ln, OUTPUT);
 pinMode(rp, OUTPUT);
 pinMode(rn, OUTPUT);
 pinMode(8, INPUT);
 pinMode(7, INPUT);
 pinMode(9, INPUT);
}

void loop() 
{
  ir=digitalRead(8);
 irl=digitalRead(7);
 irr=digitalRead(9);
 
}

void forward()
{
 analogWrite(lp,P);
 analogWrite(ln,0);
 analogWrite(rp,P);
 analogWrite(rn,0);
}

void rev()
{
 analogWrite(lp,0);
 analogWrite(ln,P);
 analogWrite(rp,0);
 analogWrite(rn,P);
 

}
void left()
{
 analogWrite(lp,0);
 analogWrite(ln,P);
 analogWrite(rp,P);
 analogWrite(rn,0);
} 
void right()
{
 analogWrite(lp,P);
 analogWrite(ln,0);
 analogWrite(rp,0);
 analogWrite(rn,P);
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
  analogWrite(lp,P);
  analogWrite(ln,0);
  analogWrite(rp,0);
  analogWrite(rn,0);
}

void stopleft()
{
  analogWrite(lp,0);
  analogWrite(ln,0);
  analogWrite(rp,P);
  analogWrite(rn,0);
}


