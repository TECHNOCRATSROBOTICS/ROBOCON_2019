#include<PS2X_lib.h>

PS2X ps2x;

#define PS2_DAT        13 
#define PS2_CMD        11 
#define PS2_SEL        10  
#define PS2_CLK        12  

int green=0; int red=0; int blue=0; int pink=0;
int L1=0; int L2=0; int R1=0; int R2=0;
int UP=0; int DOWN=0; int LEFT=0; int RIGHT=0;
int SELECT=0; int START=0;
int c=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0; //Counters

void setup() {
  Serial.begin(9600);
  ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);
  delay(5000);
}
void loop() {
   ps2x.read_gamepad();
   
   green=ps2x.ButtonPressed(PSB_GREEN);
   red=ps2x.ButtonPressed(PSB_RED);
   blue=ps2x.ButtonPressed(PSB_BLUE);
   pink=ps2x.ButtonPressed(PSB_PINK);
   L1=ps2x.ButtonPressed(PSB_L1);
   L2=ps2x.ButtonPressed(PSB_L2);
   R1=ps2x.ButtonPressed(PSB_R1);
   R2=ps2x.ButtonPressed(PSB_R2);
   UP=ps2x.ButtonPressed(PSB_PAD_UP);
   DOWN=ps2x.ButtonPressed(PSB_PAD_DOWN);
   LEFT=ps2x.ButtonPressed(PSB_PAD_LEFT);
   RIGHT=ps2x.ButtonPressed(PSB_PAD_RIGHT);
   SELECT=ps2x.ButtonPressed(PSB_SELECT);
   START=ps2x.ButtonPressed(PSB_START);

   if(green==1 && R1==0 && c==0)
   {
      Serial.println("Green Activated");
      c=1;
      red=0;
    }
   else if(green==1 && R1==0 && c==1)
   {
     Serial.println("Green DeActivated"); 
     c=0;
     red=0;
 
   }
  // red button
   if(red==1 && c3==0)
   {
    Serial.println("RED Activated"); 
    c3=1;
    blue=0;
   }
   else if(red==1 & c3==1)
   {
    Serial.println("RED DeActivated"); 
    c3=0;
      blue=0;
   }
   //blue button for pnuematic3
   if(blue==1 && c1==0)
   {
    pink=0;
    c1=1;
   Serial.println("BLUE Activated"); 
   }
   else if(blue==1 && c1==1)
   {
    pink=0;
    c1=0;
   Serial.println("BLUE DeActivated"); 
   }
   //pink button for pnuematic4
   if(pink==1 && c2==0)
   {
    c2=1;
   Serial.println("Pink Activated"); 
   }
   else if(pink==1 && c2==1)
   {
     c2=0;
     Serial.println("Pink DeActivated"); 
   }
  
if(L1==1 && R2==0 && c4==0){
   R1=0;
   c4=1;
   Serial.println("L1 Activated"); 
   }
 else if(L1==1 & R2==0 && c4==1){
   R1=0;
   c4=0;
   Serial.println("L1 DeActivated"); 
 }
}
