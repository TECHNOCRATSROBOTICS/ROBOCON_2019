// base motors

// BASE
int pwm0 = 5;
int dir0 = 4;
int pwm1 = 6;
int dir1 = 7;


void setup() {
  // put your setup code here, to run once:
// motors
  pinMode(dir1,OUTPUT);
  pinMode(dir0,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(pwm0,OUTPUT);  

   analogWrite(pwm1,100);
   analogWrite(pwm0,100);

     digitalWrite(dir0,HIGH);
    digitalWrite(dir1,LOW);
    delay(300);
}
void Forward(){
     digitalWrite(dir0,HIGH);
    digitalWrite(dir1,LOW);
    analogWrite(pwm1,250);
   analogWrite(pwm0,250);

}

void Left(){
       //digitalWrite(dir0,LOW);
    //digitalWrite(dir1,LOW);
analogWrite(pwm0,190);
}

void Right(){
      // digitalWrite(dir0,HIGH);++
    //digitalWrite(dir1,HIGH);
analogWrite(pwm1,200);

}

void loop() {
  // put your main code here, to run repeatedly:
  Forward();
  delay(500);
  Left();
  delay(105);
  Forward();
  delay(100);
  Right();
  delay(100
  );
  
  
}
