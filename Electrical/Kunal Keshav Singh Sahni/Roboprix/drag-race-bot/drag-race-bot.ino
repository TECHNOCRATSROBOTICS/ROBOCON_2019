// roboprix DRAG_RACE_BOT

int dir1 = 22;
int pwm1 = 3;
int dir2 = 24;
int pwm2 = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);  

  // main setting
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  for(int i = 0 ; i<255;i+=5){
    analogWrite(pwm1,i);
    analogWrite(pwm2,i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
