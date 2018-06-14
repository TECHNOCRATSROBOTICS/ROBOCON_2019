/*
 LED intensity Control Using PWM
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function on a digital pin which is used for producing a PWM Pulse
 
 This example code is in the public domain.
 */
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Hardware Initialization 
int led = 9;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is              (Generally tis value will vary between 0 and 255 as they are the PWM MIN and the PWM MAX values respectively
int fadeAmount = 5;    // how many points to fade the LED by (Jump number i.e 0,0+fadeammount,.........,255) for fading the LED

// the setup routine runs once when you press reset:

void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);//If we do not include this line the LED will not glow as pin 9 dosent output anything.
  Serial.begin(9600);  //This is used to start the Serial monitor at a baud rate of 9600 to display the relevant data on the screen.
  Serial.println('///////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n');
  Serial.println('LED IS initialized on PIN:\t');
  Serial.print(led);
  Serial.println('The Initial Brightness(PWM) is:\t');
  Serial.print(brightness);
  Serial.println('The Fade Amount is:\t');
  Serial.print(fadeAmount);
  Serial.println('///////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n');
  Serial.println('Execution Starts Now:\n');
}
 
// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
    //Initially this will be set to 0 in the start of the loop then as the program proceeds the LED will start increasing its intensity and reach the maximum
  analogWrite(led, brightness);//Here we are doing analog Write on a Digital Pin which is the procedure for producing a pwm pulse (generally for normal use we apply Analogwrite on analog pins and DigitalWrite for Digital Pins Only)
 
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;//This will Increase the Brightness or decrease it as per the stp set above in the initialization part
 
  // reverse the direction of the fading at the ends of the fade: (This occurs when the LED either reaches the max or the min pwm value as we need to reverse the direction of change.
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;//Sign change is done here for reversal of direction
  }

  Serial.println('The Current PWM Value is:\t ');   //Prints the current pwm value in the Serial Monitor so that you can analyse whats going on
  Serial.print(brightness);
  
  // wait for 30 milliseconds to see the dimming effect (Can be modified as per your liking)
  delay(30);//Increasing this will make it slower and decreasing it will make the fading faster.
}
