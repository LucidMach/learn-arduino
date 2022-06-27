//https://www.electronicwings.com/arduino/mpu6050-interfacing-with-arduino-uno

#include <Wire.h>
#include <MPU6050.h>
#include <VarSpeedServo.h>
// VarSpeedServo.write(angle,percent);

MPU6050 mpu;
VarSpeedServo RW;
VarSpeedServo LW;
VarSpeedServo E;

#define rw 3
#define lw 6
#define e 9

int t1 = 90; //initial angle out of 180
int t2;
void setup() 
{
  Serial.begin(115200);

  // Connecting MPU6050
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Connecting....");
    delay(500);
  }

  // Connecting BLDC motors
  RW.attach(rw);
  LW.attach(lw);
  E.attach(e);
}

void loop()
{
  // Read normalized values 
  Vector normAccel = mpu.readNormalizeAccel();

  // Calculate Pitch & Roll
  int pitch = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis*normAccel.YAxis + normAccel.ZAxis*normAccel.ZAxis))*180.0)/M_PI;
  int roll = (atan2(normAccel.YAxis, normAccel.ZAxis)*180.0)/M_PI;

  // Output Pitch & Roll Values
  Serial.print(" Pitch = ");
  Serial.print(pitch);
  Serial.print(" Roll = ");
  Serial.print(roll);
  Serial.println();

  stabilize(pitch,roll);
}

void stabilize(int p, int r){
  while(p > 0){
    t2 = t1-1;
    dleanback(t2);
  }
  while(p < 0){
    t2 = t1+1;
    dleanfront(t2);
  }
  while(r > 0){
    t2 = t1+1;
    dtiltright(t2);
  }
  while(r > 0){
    t2 = t1+1;
    dtiltleft(t2);
  }
  t2 = t1;  
}
void dleanback(int t){
  RW.write(90,50);
  LW.write(90,50);
  E.write(t,50);
}
void dleanfront(int t){
  RW.write(90,50);
  LW.write(90,50);
  E.write(t,50);
}
void dtiltright(int t){
  RW.write(t,50);
  LW.write(90,50);
  E.write(90,50);
}
void dtiltleft(int t)
{
  RW.write(90,50);
  LW.write(t,50);
  E.write(90,50);
}
