/* * uncomment ps2
   change rx and tx pins
   Forward Left
   Backward Right
   Right Backward

*/
#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h>
int currValue;
int Select = 1, Start = 1, Ps2_UP = 1, Ps2_LEFT = 1, Ps2_DOWN = 1, Ps2_RIGHT = 1, Ps2_LEFT1 = 1, Ps2_LEFT2 = 1, Ps2_RIGHT1 = 1, Ps2_RIGHT2 = 1, Ps2_TRIANGLE = 1, Ps2_CIRCLE = 1, Ps2_CROSS = 1, Ps2_SQUARE = 1;
Cytron_PS2Shield ps2(2, 3);

//Cytron_PS2Shield ps2;
int lf_pwm = 11;
int lf_dir = 9;

int rf_pwm = 10;
int rf_dir = 8;

int lb_pwm = 5;
int lb_dir = 4;

int rb_pwm = 6;
int rb_dir = 7;



// BASE
int currVal = 0;
void setup()
{
  ps2.begin(9600);
  // This baudrate must same with the jumper setting at PS2 shield
  Serial.begin(9600);
  delay(2000);
  Serial.println("Initialized");

 // BASE PINS 
 pinMode(lf_pwm,OUTPUT);
 pinMode(lf_dir,OUTPUT);
 
 pinMode(lb_pwm,OUTPUT);
 pinMode(lb_dir,OUTPUT);

 pinMode(rf_pwm,OUTPUT);
 pinMode(rf_dir,OUTPUT);

 pinMode(rb_pwm,OUTPUT);
 pinMode(rb_dir,OUTPUT);


  // initial Speeds
  analogWrite(lf_pwm,0);
  analogWrite(rf_pwm,0);
  analogWrite(lb_pwm,0);
  analogWrite(rb_pwm,0);

  // initial directions (Forward)
  digitalWrite(lf_dir,LOW);
  digitalWrite(rf_dir,LOW);
  digitalWrite(lb_dir,HIGH);
  digitalWrite(rb_dir,HIGH);
  

}
void loop()
{
  Select = ps2.readButton(PS2_SELECT);
  Start = ps2.readButton(PS2_START);
  Ps2_UP = ps2.readButton(PS2_UP);
  Ps2_DOWN = ps2.readButton(PS2_DOWN);
  Ps2_RIGHT = ps2.readButton(PS2_RIGHT);
  Ps2_LEFT = ps2.readButton(PS2_LEFT);
  Ps2_LEFT1 = ps2.readButton(PS2_LEFT_1);
  Ps2_LEFT2 = ps2.readButton(PS2_LEFT_2);
  Ps2_RIGHT1 = ps2.readButton(PS2_RIGHT_1);
  Ps2_RIGHT2 = ps2.readButton(PS2_RIGHT_2);
  Ps2_TRIANGLE = ps2.readButton(PS2_TRIANGLE);
  Ps2_CIRCLE = ps2.readButton(PS2_CIRCLE);
  Ps2_CROSS = ps2.readButton(PS2_CROSS);
  Ps2_SQUARE = ps2.readButton(PS2_SQUARE);

  // Forward
  /*
  // initial Speeds
  analogWrite(lf_pwm,250);
  analogWrite(rf_pwm,250);
  analogWrite(lb_pwm,250);
  analogWrite(rb_pwm,250);

  // initial directions (Forward)
  digitalWrite(lf_dir,LOW);
  digitalWrite(rf_dir,LOW);
  digitalWrite(lb_dir,HIGH);
  digitalWrite(rb_dir,HIGH);*/
    analogWrite(lf_pwm,0);
  analogWrite(lb_pwm,0);
  analogWrite(rf_pwm,0);
  analogWrite(rb_pwm,0);
  
  if(Ps2_UP == 0){
   digitalWrite(lf_dir,LOW);
  digitalWrite(rf_dir,LOW);
  digitalWrite(lb_dir,HIGH);
  digitalWrite(rb_dir,HIGH);
    analogWrite(lf_pwm,250);
  analogWrite(rf_pwm,250);
  analogWrite(lb_pwm,250);
  analogWrite(rb_pwm,250);
  }

  else if(Ps2_DOWN == 0){
  digitalWrite(lf_dir,HIGH);
  digitalWrite(rf_dir,HIGH);
  digitalWrite(lb_dir,LOW);
  digitalWrite(rb_dir,LOW);
  analogWrite(lf_pwm,250);
  analogWrite(rf_pwm,250);
  analogWrite(lb_pwm,250);
  analogWrite(rb_pwm,250);
  }

// circle right square left
 else if(Ps2_SQUARE == 0){
    digitalWrite(lf_dir,HIGH);
  digitalWrite(rf_dir,LOW);
  digitalWrite(lb_dir,LOW);
  digitalWrite(rb_dir,HIGH);
  analogWrite(lf_pwm,150);
  analogWrite(lb_pwm,150);
  analogWrite(rf_pwm,200);
  analogWrite(rb_pwm,200);
  }

 else if(Ps2_CIRCLE == 0){
    digitalWrite(lf_dir,LOW);
  digitalWrite(rf_dir,HIGH);
  digitalWrite(lb_dir,HIGH);
  digitalWrite(rb_dir,LOW);
  analogWrite(lf_pwm,200);
  analogWrite(lb_pwm,200);
  analogWrite(rf_pwm,150);
  analogWrite(rb_pwm,150);
  }
 
 else if(Ps2_TRIANGLE == 0){
   digitalWrite(lf_dir,LOW);
  digitalWrite(rf_dir,LOW);
  digitalWrite(lb_dir,HIGH);
  digitalWrite(rb_dir,HIGH);
  analogWrite(lf_pwm,200);
  analogWrite(lb_pwm,0);
  analogWrite(rf_pwm,250);
  analogWrite(rb_pwm,0);
  }
   else if(Ps2_CROSS == 0){
   digitalWrite(lf_dir,LOW);
  digitalWrite(rf_dir,LOW);
  digitalWrite(lb_dir,HIGH);
  digitalWrite(rb_dir,HIGH);
  analogWrite(lf_pwm,0);
  analogWrite(lb_pwm,250);
  analogWrite(rf_pwm,0);
  analogWrite(rb_pwm,250);
  }
 
  
}
