//this is a sketch for self balancing algorithm of a two tired buggy robo using ultrasonic sensor and MPU6050
// much of the code and idea are referenced from http://www.instructables.com/id/Arduino-Self-Balancing-Robot-1/ 
// please visit the site above for complete conceptual reference
//this is not a complete code rather just the algorithm for self balancing

#include<Wire.h>
#include<I2Cdev.h>
#include<MPU6050.h>
#include<math.h>

int16_t accX,accY,accZ; //int_16t is refered for 16bit integers (which is mostly default int)

int16_t gyroX, gyroRate;
float gyroAngle=0;
unsigned long currTime, prevTime=0, loopTime;

float accAngle; //

MPU6050 mpu;

void setup() {
  // put your setup code here, to run once:

  mpu.initialize();
  Serial.begin(9600);

//setting offset values for tuning
mpu.setYAccelOffset(1593);
mpu.setZAccelOffset(963);
mpu.setXGyroOffset(40);

//setting PID Values
#define Kp  40
#define Kd  0.05
#define Ki  40
#define sampleTime  0.005
#define targetAngle -2.5


}

void loop() {
  // put your main code here, to run repeatedly: 
  //getting accelerometer values:
       accZ = mpu.getAccelerationZ();
       accY = mpu.getAccelerationY();
   
       accAngle = atan2(accY, accZ)*RAD_TO_DEG;
  
  if(isnan(accAngle));
  else
    Serial.println(accAngle);

  // now getting gyroscope values
   currTime = millis();
  loopTime = currTime - prevTime;
  prevTime = currTime;
  
  gyroX = mpu.getRotationX();
  gyroRate = map(gyroX, -32768, 32767, -250, 250);

  gyroAngle = gyroAngle + (float)gyroRate*loopTime/1000;
  
  Serial.println(gyroAngle);
 


  currentAngle = 0.9934 * (previousAngle + gyroAngle) + 0.0066 * (accAngle)  //as found on data sheet (referred to as applying complimentary filter)


  //PID Calculations

  error = currentAngle - targetAngle;
  errorSum = errorSum + error;  
  errorSum = constrain(errorSum, -300, 300);
  //calculate output from P, I and D values
  motorPower = Kp*(error) + Ki*(errorSum)*sampleTime - Kd*(currentAngle-prevAngle)/sampleTime;
  prevAngle = currentAngle;

}
