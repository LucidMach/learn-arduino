int lp=5;
int ln=3;
int rp=6;
int rn=11;

int key;
void setup()
{
 pinMode(lp, OUTPUT);
 pinMode(ln, OUTPUT);
 pinMode(rp, OUTPUT);
 pinMode(rn, OUTPUT);
 
 Serial.begin(9600);
}

void loop() 
{
 key=Serial.read();
 if(key=='w')
   forward();
 else if(key=='a')
   left();
 else if(key=='s')
   stp();
 else if(key=='d')
   right();
 else if(key=='q')
   stopleft();
 else if(key=='e')
   stopright();          
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


