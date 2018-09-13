#ifndef allLib_h
#define allLib_h

#include "Arduino.h"

class BaseMotors{
	public:
	BaseMotors(int dir1,int pwm1,int dir2,int pwm2,int dir3,int pwm3,int dir4,int pwm4);
	int forward();
	int backward();
	int stop();
	// setting zero by default 
	int set_speed(int speed1 = 0, int speed2 = 0 , int speed3 = 0 , int speed4 = 0);
	int sideWayLeft();
	int sideWayRight();
	int diagonal();
	int Stop();
	// many more functions to come
	private :
	int _dir1,_pwm1,_dir2,_pwm2,_dir3,_pwm3,_dir4,_pwm4;
};

class Pneumatics
{
public:
	Pneumatics(int pneumaticPin1 , int pneumaticPin2);
	int out();
	int in();
	private :
	int _pneumaticPin1,_pneumaticPin2;
};

class Led{
public:
	Led(int ledPin);
	int on();
	int off();
private:
	int _ledPin;
};

#endif 



