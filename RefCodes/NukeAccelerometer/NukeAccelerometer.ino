int x,y,z;
void setup() 
{
 pinMode(A1,INPUT);
 pinMode(A2,INPUT);
 pinMode(A3,INPUT);
 Serial.begin(9600);
}

void loop() 
{
 x=analogRead(A1);
 y=analogRead(A2);
 z=analogRead(A3);
 Serial.print("(x,y,z):");
 Serial.print(x);
 Serial.print(y);
 Serial.print(z);
}
