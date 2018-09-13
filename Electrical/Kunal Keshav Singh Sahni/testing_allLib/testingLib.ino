#include <allLib.h>
#include<Servo.h>
#include<Stepper.h>

BaseMotors base(2,3,12,5,7,6,8,9);
Led l(13);
Pneumatics p(10,11);

void setup() {
 // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
 Serial.println("...");// put your main code here, to run repeatedly:

  
// testing the base

 base.set_speed(100,100,100,100);
 base.forward();
 Serial.println("Forward");
 delay(10000);
 base.backward();
 Serial.println("Backward");
 delay(10000);
 base.sideWayRight();
 Serial.println("Side right");
 delay(10000);
 base.sideWayLeft();
 Serial.println("side left");
 delay(10000);
 base.diagonal();
 Serial.println("diagonal");
 delay(10000);
 base.Stop();
 Serial.println("stop");
 delay(10000);

 // testing the led
    l.on();
    delay(1000);
    l.off();
    delay(1000);


 // testing the pneumatic  
    p.out();
    delay(1000);
    p.in();
    delay(1000);
     
}
