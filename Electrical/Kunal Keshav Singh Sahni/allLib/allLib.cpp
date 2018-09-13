#include "Arduino.h"
#include "allLib.h"

BaseMotors :: BaseMotors(int dir1,int pwm1,int dir2,int pwm2,int dir3,int pwm3,int dir4,int pwm4)
{
	pinMode(dir1,OUTPUT);
	pinMode(pwm1,OUTPUT);
	pinMode(dir2,OUTPUT);
	pinMode(pwm2,OUTPUT);
	pinMode(dir3,OUTPUT);
	pinMode(pwm3,OUTPUT);
	pinMode(dir4,OUTPUT);
	pinMode(pwm4,OUTPUT);
	_dir1 = dir1;
	_pwm1 = pwm1;
	_dir2 = dir2;
	_pwm2 = pwm2;
	_dir3 = dir3;
	_pwm3 = pwm3;
	_dir4 = dir4;
	_pwm4 = pwm4;
}

int BaseMotors::forward(){
  digitalWrite(_dir1,HIGH);
  digitalWrite(_dir2,HIGH); // 2 forward when low
  digitalWrite(_dir3,HIGH); // 3 forward when low
  digitalWrite(_dir4,HIGH);


}

int BaseMotors::backward(){
  digitalWrite(_dir1,LOW);
  digitalWrite(_dir2,LOW); // 2 forward when low
  digitalWrite(_dir3,LOW); // 3 forward when low
  digitalWrite(_dir4,LOW);

}

int BaseMotors::set_speed(int speed1 = 0, int speed2 = 0 , int speed3 = 0 , int speed4 = 0){
	analogWrite(_pwm1,speed1);
	analogWrite(_pwm2,speed2);
	analogWrite(_pwm3,speed3);
	analogWrite(_pwm4,speed4);

}

int BaseMotors::sideWayLeft(){
  digitalWrite(_dir1,LOW);
  digitalWrite(_dir2,HIGH);
  digitalWrite(_dir3,HIGH);
  digitalWrite(_dir4,LOW);
}

int BaseMotors::sideWayRight(){
  digitalWrite(_dir1,HIGH);
  digitalWrite(_dir2,LOW);
  digitalWrite(_dir3,LOW);
  digitalWrite(_dir4,HIGH);
}

int BaseMotors::diagonal(){
   BaseMotors::backward();
   BaseMotors::set_speed(0,100,0,100);
}

int BaseMotors::Stop(){
	 BaseMotors::backward();
	BaseMotors::set_speed(0,0,0,0);
}

Pneumatics :: Pneumatics(int pneumaticPin1, int pneumaticPin2)
{
	pinMode(pneumaticPin1,OUTPUT);
	pinMode(pneumaticPin2,OUTPUT);
	_pneumaticPin1 = pneumaticPin1;
	_pneumaticPin2 = pneumaticPin2;
}

int Pneumatics::out(){
digitalWrite(_pneumaticPin1,HIGH);
digitalWrite(_pneumaticPin2,LOW);
}

int Pneumatics::in(){
digitalWrite(_pneumaticPin1,LOW);
digitalWrite(_pneumaticPin2,HIGH);
}

Led::Led(int ledPin){
	pinMode(ledPin,OUTPUT);
	_ledPin = ledPin;
}
int Led::on(){
	digitalWrite(_ledPin,HIGH);
}
int Led::off(){
	digitalWrite(_ledPin,LOW);
}


