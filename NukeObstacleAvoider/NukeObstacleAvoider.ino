int ln=3;
int lp=5;
int rn=11;
int rp=6;
int ir;
int irl;
int irr;

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
 
 if(ir==HIGH && irl==HIGH && irr==HIGH)
  {
    rev();
    delay(200);
    right();
    delay(400);
  }
 else if(irl==HIGH && ir==HIGH )
   {
    right();
    delay(200);
   }
else if(ir==HIGH && irr==HIGH)
   {
    left();
    delay(200);
   }
else if(irl==HIGH && irr==HIGH)
 {
  rev();
  delay(200);
  right();
  delay(200);
 }
else if(irl==HIGH)
 {
  right();
  delay(200);
 }
else if(ir==HIGH)
  {
   right();
   delay(200);
  }
else if(irr==HIGH)
 {
  left();
  delay(200);
 }
else
 {
  forward();
  delay(200);
 }
}

void forward()
{
 analogWrite(lp,200);
 analogWrite(ln,0);
 analogWrite(rp,200);
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




