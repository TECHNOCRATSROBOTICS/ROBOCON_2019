
// all pins
int fl_dir = 46; // 7
int fr_dir = 40; // 4
int bl_dir = 4;
int br_dir = 7;
int fr_pwm = 12;
int fl_pwm = 10;  // pwm 12 10 for ek cytron and 8 5 pwm for dusra cytron
int bl_pwm = 5; 
int br_pwm = 8;
int last_val=0;
int last_left=0;
int last_right= 0;


// rack 
int rack_dir = 15;
int rack_pwm = 3;
int rackSpeed= 180;
    int val_fl;

// flipper
int flip_dir = 30;
int flip_pwm = 9; 

// gripper
int grip_dir = 34;
int grip_pwm = 11; 
int gripSpeed = 150;

// Pneumatics
int pin1 = 21;
int pin2 = 20;


void setup() {
  // put your setup code here, to run once:
 
pinMode(fl_dir,OUTPUT);
pinMode(fr_dir,OUTPUT);
pinMode(bl_dir,OUTPUT);
pinMode(br_dir,OUTPUT);
pinMode(fl_pwm,OUTPUT);
pinMode(fr_pwm,OUTPUT);
pinMode(bl_pwm,OUTPUT);
pinMode(br_pwm,OUTPUT);
Serial.begin(115200);


// rack 
pinMode(rack_dir,OUTPUT);
pinMode(rack_pwm,OUTPUT);


// grip
pinMode(grip_dir,OUTPUT);
pinMode(grip_pwm,OUTPUT);

//pneumatics
pinMode(pin1,OUTPUT);
pinMode(pin2,OUTPUT);

     digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
}



void Speed(int val1,int val2,int val3,int val4){
  analogWrite(fl_pwm,val1);
  analogWrite(fr_pwm,val2);
  analogWrite(bl_pwm,val3);
  analogWrite(br_pwm,val4);
}


void Stop(){
  analogWrite(fl_pwm,0);
  analogWrite(fr_pwm,0);
  analogWrite(bl_pwm,0);
  analogWrite(br_pwm,0);
}

void speed_reset(){
  Stop();
  analogWrite(rack_pwm,0);
  analogWrite(grip_pwm,0);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
}

void check(int left_x_dir,int left_y_dir,int right_x_dir,int right_y_dir){
  if((left_x_dir == 1) && (left_y_dir == 0) && ((right_x_dir == 2) && (right_y_dir == 1))){
    Forward(); 
  }
    if((left_x_dir == 1) && (left_y_dir == 0) && (right_x_dir == 0) && (right_y_dir == 1)){
    Forward(); 
  }
    if((left_x_dir == 1) && (left_y_dir == 2) && (right_x_dir == 2) && (right_y_dir == 1)){
    Backward(); 
  }
    if((left_x_dir == 1) && (left_y_dir == 2) && (right_x_dir == 0) && (right_y_dir == 1) ){
    Backward();
  }
  
  }
int prevDown = 0 ;
int change_mode = 0;

// all the fucking variables 
int hat_up,hat_down,hat_left,hat_right,up,down,left,right,start,back,front_left,front_right,left_x,left_y,right_x,right_y,lt1,rt1,left_x_dir,left_y_dir,right_x_dir,right_y_dir;

void Digitest(){
  if(hat_up == 1){
    Backward();
    Speed(200,200,200,200);}
 else if(hat_left == 1){
    SideWayLeft();
    Speed(200,200,200,200);
  }
  else if(hat_right == 1){
    SideWayRight();
    Speed(200,200,200,200);
  }
  else if(hat_down == 1){
    Forward();
    Speed(200,200,200,200);
  }
  else{
    Speed(0,0,0,0);
  }
}

void Diagonal(){
  digitalWrite(fl_dir,LOW);
  digitalWrite(br_dir,LOW);
  analogWrite(fl_pwm,180);
  analogWrite(br_pwm,180);
  analogWrite(fr_pwm,0);
  analogWrite(bl_pwm,0);
}

int range_map(int s){
   int val = s - '0';
   if(0<=val && val<= 6 ){
    return map(val,0,6,0,100);
   }
   else{
    return map(val,7,9,120,180);
   }
}


int range_map_lr(int s){
   int val = s - '0';
   if(0<=val && val<= 6 ){
    return map(val,0,6,0,120);
   }
   else{
    return map(val,7,9,120,210);
   }
}


  void North_West(int val_north, int val_west){
    digitalWrite(fr_dir,HIGH);
    digitalWrite(bl_dir,HIGH);
    analogWrite(fl_pwm,0);
    analogWrite(br_pwm,0);
    analogWrite(fr_pwm,val_north);
    analogWrite(bl_pwm,val_west);
  }

    void North_East(int val_north, int val_east){
    digitalWrite(fl_dir,HIGH);
    digitalWrite(br_dir,HIGH);
    analogWrite(fr_pwm,0);
    analogWrite(fr_pwm,0);
    analogWrite(bl_pwm,0);
    analogWrite(fl_pwm,val_north);
    analogWrite(br_pwm,val_east);
  }

    void South_West(int val_north, int val_west){
    digitalWrite(fl_dir,LOW);
    digitalWrite(br_dir,LOW);
    analogWrite(fr_pwm,0);
    analogWrite(bl_pwm,0);
    analogWrite(fl_pwm,val_north);
    analogWrite(br_pwm,val_west);
  }

    void South_East(int val_north, int val_west){
    digitalWrite(fr_dir,LOW);
    digitalWrite(bl_dir,LOW);
    analogWrite(fl_pwm,0);
    analogWrite(br_pwm,0);
    analogWrite(fr_pwm,val_north);
    analogWrite(bl_pwm,val_west);
  }

  void Forward(){
    digitalWrite(fl_dir,LOW);
    digitalWrite(fr_dir,LOW);
    digitalWrite(bl_dir,LOW);
    digitalWrite(br_dir,LOW);    
  }
void Backward(){
    digitalWrite(fl_dir,HIGH);
    digitalWrite(fr_dir,HIGH);
    digitalWrite(bl_dir,HIGH);
    digitalWrite(br_dir,HIGH);
}

 void SideWayRight(){
    digitalWrite(fl_dir,HIGH);
    digitalWrite(fr_dir,LOW);
    digitalWrite(bl_dir,LOW);
    digitalWrite(br_dir,HIGH);
 }

 void SideWayLeft(){
    digitalWrite(fl_dir,LOW);
    digitalWrite(fr_dir,HIGH);
    digitalWrite(bl_dir,HIGH);
    digitalWrite(br_dir,LOW);
 }

void ClockWise(){
    digitalWrite(fl_dir,LOW);
    digitalWrite(fr_dir,HIGH);
    digitalWrite(bl_dir,LOW);
    digitalWrite(br_dir,HIGH);
    Speed(180,180,180,180);
}

void AntiClockWise(){
     digitalWrite(fl_dir,HIGH);
    digitalWrite(fr_dir,LOW);
    digitalWrite(bl_dir,HIGH);
    digitalWrite(br_dir,LOW);
    Speed(180,180,180,180);
}





void loop() {
  // put your main code here, to run repeatedly:

  // MAGIC FUNCTION 
int s[22];
  int i=0;
  while(1){
  if(Serial.available()){
  s[i] = Serial.read(); 
//  Serial.print(s[i]);
  if(s[i]==110){
    i=-1;
  }
  i++;
  if(i==0){
    break;
  }
  if(i>=22){
    i=0;
    break;
  }

  }
  }
  // all the buttons 
  hat_up = s[0] - '0';
  hat_down = s[1] - '0';
  hat_left = s[2] - '0';
  hat_right = s[3] - '0';
  left = s[4] - '0';
  down = s[5] - '0';
  left = s[6] - '0';
  right = s[7] - '0';
  front_right = s[8] - '0';
  front_left = s[9] - '0';
  up = s[10] - '0';
  //front_right = s[11] - '0';
  left_x_dir = s[18] - '0';
  left_y_dir = s[19] - '0';
  right_x_dir = s[20] - '0';
  right_y_dir = s[21] - '0';


// changing the mode
if(down){
  //prevDown=down;
  change_mode= !(change_mode);
  //break; 
  }



if(change_mode == 0){
  
 // all the axis 

//check( left_x_dir, left_y_dir, right_x_dir, right_y_dir); 

// ALL THY MOVEMENT LOGIC .....
if((left_x_dir==1) && (left_y_dir==1) && (right_x_dir==1) && (right_y_dir==1))
{
  /*
  for(i=last_val;i>=0;i-=4){
//  last_val=0;
  analogWrite(fl_pwm,i);
  analogWrite(fr_pwm,i);
  analogWrite(bl_pwm,i);
  analogWrite(br_pwm,i);
  delay(5);
  }
  last_val=0;*/
  Stop();
}
/*
if((left_x_dir == 0) && (left_y_dir==0)),
int val_west = range_map(s[12]);//map((s[12]-'0'),0,9,0,255);
   North_West(val_north,val_west);
}
if((left_x_dir == 2) && (left_y_dir==0)){
   int val_north = range_map(s[13]);//map((s[13]-'0'),0,9,0,255);
   int val_west = range_map(s[12])//map((s[12]-'0'),0,9,0,255);
   North_East(val_north,val_west);
}
if((left_x_dir == 0) && (left_y_dir==2)){
   int val_north = range_map(s[13])//map((s[13]-'0'),0,9,0,255);
   int val_west = range_map(s[12])//map((s[12]-'0'),0,9,0,255);
   South_West(val_north,val_west);
}
if((left_x_dir == 2) && (left_y_dir==2)){
   int val_north = range_map(s[13])//map((s[13]-'0'),0,9,0,255);
   int val_west = range_map(s[12])//map((s[12]-'0'),0,9,0,255);
   South_East(val_north,val_west);
}
*/


if((right_x_dir == 0)&& (right_y_dir ==1)){
SideWayRight();
/*
int rightt = range_map(s[16])/2;
int j;
for(j=last_right;j<rightt;j+=2){
Speed(val_fl,val_fl-j,val_fl,val_fl-j);
delay(5);
}*/
//last_right = rightt;
//  
//  int val_fl = range_map_lr(s[16]);//map((s[16]-'0'),0,9,0,217);
//  int val_fr = range_map_lr(s[16]);//map((s[16]-'0'),0,9,0,229);
//  int val_bl = range_map_lr(s[16]);//map((s[16]-'0'),0,9,0,255);
//  int val_br = range_map_lr(s[16]);//map((s[16]-'0'),0,9,0,235);
  //Speed(val_fl,val_fr,val_bl,val_br);
Speed(100,100,100,100);
  //}
}
 
if((left_y_dir == 0)&&(left_x_dir == 1) ){
  //SideWayRight();
  Forward();
//Backward();
  
  //int i=0;
  int val_fl = range_map(s[13])*(1.2);//map((s[13]-'0'),0,9,0,217);
  int val_fr = range_map(s[13])*(1.11);//map((s[13]-'0'),0,9,0,229);
  int val_bl = range_map(s[13])*(1.2);//map((s[13]-'0'),0,9,0,255);
  int val_br = range_map(s[13])*(1.11);//map((s[13]-'0'),0,9,0,235);
  
  /*for(i=last_val;i<val_fl;i=i+4){ 
  Speed(i,i,i,i);
  delay(5);
  }
  last_val=val_fl;
  */
//  for(int i = 0;i<=10;i++){
//    Speed(val_fl*i,val_fr*i,val_bl*i,val_br*i);
//    delay(100);
//  }
 Speed(val_fl,val_fr,val_bl,val_br);
}

if((left_y_dir == 2)&&(left_x_dir == 1) ){
  //Forward();
Backward();
  int val_fl = range_map(s[13])*1.2;//map((s[13]-'0'),0,9,0,217);
  int val_fr = range_map(s[13])*1.1;//map((s[13]-'0'),0,9,0,229);
  int val_bl = range_map(s[13])*1.2;//map((s[13]-'0'),0,9,0,255);
  int val_br = range_map(s[13])*1.1;//map((s[13]-'0'),0,9,0,235);
  Speed(val_fl,val_fr,val_bl,val_br);
}

if((right_x_dir == 2)&&(right_y_dir == 1) ){
/*  
int leftt = range_map(s[17])/2;
int j;
for(j=last_left;j<leftt;j+=2){
Speed(val_fl-j,val_fl,val_fl-j,val_fl);
delay(5);
}
last_left = leftt;
 */
 SideWayLeft();
 //Diagonal();
 Speed(100,100,100,100);
}

if(front_right == 1){
  //SideWayLeft();
  ClockWise();
  for(i=80;i<120;i=i+10){ 
  Speed(i,i,i,i);
  delay(8);
  }
  //Speed(180,180,180,180);
}

if(front_left == 1){
  //SideWayRight();
  AntiClockWise();
  for(i=80;i<120;i=i+10){ 
  Speed(i,i,i,i);
  delay(8);
  }
  //Speed(180,180,180,180);
}
 
 //Digitest();

// ALL THY OPERATIONAL LOGIC .....

}

// rotating the gripper
else if(change_mode == 1){
  //Motor_rotor();
   if((left_y_dir == 0)&&(left_x_dir == 1) ){
    digitalWrite(flip_dir,LOW);
    int val = map(s[13] - '0',0,9,0,100);
    analogWrite(flip_pwm,val);
   }
  if((left_y_dir == 2)&&(left_x_dir == 1) ){
    digitalWrite(flip_dir,HIGH);
    int val = map(s[13] - '0',0,9,0,100);
    analogWrite(flip_pwm,val);
  }
    if((left_y_dir == 1)&&(left_x_dir == 1) ){
    analogWrite(flip_pwm,0);
  }

  
// RACK AND PINION
//DIGITAL RACK MODE 
/*
 if(hat_up==1){
digitalWrite(rack_dir,LOW);
analogWrite(rack_pwm,rackSpeed);
  }
  
if(hat_down==1){
digitalWrite(rack_dir,HIGH);
analogWrite(rack_pwm,rackSpeed);
}

if((hat_up == 0)&& (hat_down == 0)){
  analogWrite(rack_pwm,0);
}*/

// ANALOG RACK MODE
  if((right_y_dir == 2)&&(right_x_dir == 1) ){
    digitalWrite(rack_dir,LOW);
    int val = map(s[15] - '0',0,9,0,200);
    analogWrite(rack_pwm,val);
   }
  if((right_y_dir == 0)&&(right_x_dir == 1) ){
    digitalWrite(rack_dir,HIGH);
    int val = map(s[15] - '0',0,9,0,200);
    analogWrite(rack_pwm,val);
  }
    if((right_y_dir == 1)&&(right_x_dir == 1) ){
    analogWrite(rack_pwm,0);
  }


// PNEUMATICS
if(front_left ==1){
  digitalWrite(21,HIGH);
    digitalWrite(20,LOW);
   // delay(1000);
}

if(front_right == 1){
  digitalWrite(21,LOW);
    digitalWrite(20,HIGH);
    //delay(1000);
}

// GRIPPING
                        
  if((right_y_dir == 1)&&(right_x_dir == 0) ){
    digitalWrite(grip_dir,LOW);
    int val = map(s[16] - '0',0,9,0,100);
    analogWrite(grip_pwm,val);
   }
  if((right_y_dir == 1)&&(right_x_dir == 2) ){
    digitalWrite(grip_dir,HIGH);
    int val = map(s[17] - '0',0,9,0,100);
    analogWrite(grip_pwm,val);
  }
    if((right_y_dir == 1)&&(right_x_dir == 1) ){
    analogWrite(grip_pwm,0);
  }

}


}

 
 //Digitest();


