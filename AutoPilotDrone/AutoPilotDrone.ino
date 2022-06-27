//https://www.electronicwings.com/arduino/mpu6050-interfacing-with-arduino-uno

#include <Wire.h>
#include <MPU6050.h>
#include <VarSpeedServo.h>
// VarSpeedServo.write(angle,percent);

MPU6050 mpu;
VarSpeedServo FR;
VarSpeedServo FL;
VarSpeedServo BR;
VarSpeedServo BL;

#define fr 3
#define fl 5
#define br 6
#define bl 9

int u = 50;
int v;
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
  FR.attach(fr);
  FL.attach(fl);
  BR.attach(br);
  BL.attach(bl);
  
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
    v = u+1;
    dleanback(v);
  }
  while(p < 0){
    v = u+1;
    dleanfront(v);
  }
  while(r > 0){
    v = u+1;
    dtiltright(v);
  }
  while(r > 0){
    v = u+1;
    dtiltleft(v);
  }
  v = u;  
}

void dleanback(int v){
  BR.write(180,v);
  BL.write(180,v);
  FR.write(180,u);
  FL.write(180,u);
}
void dleanfront(int v){
  BR.write(180,u);
  BL.write(180,u);
  FR.write(180,v);
  FL.write(180,v);
}
void dtiltright(int v){
  BR.write(180,v);
  BL.write(180,u);
  FR.write(180,v);
  FL.write(180,u);  
}
void dtiltleft(int v){
  BR.write(180,u);
  BL.write(180,v);
  FR.write(180,u);
  FL.write(180,v);
}
