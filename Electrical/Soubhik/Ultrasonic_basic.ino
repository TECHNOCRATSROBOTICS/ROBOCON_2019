/*Sensors like ultrasonic sensor, IR sensor etc. can be interfaced using microcontollers like arduino. We build the code here to operate the sensor according to its input and ouput
characteristics. This is a code to operate Ultrasonic Sensor. To work with it we need a arduino board, breadboard, LED, resistor(300ohms), jumping wire and a system. 
Upload the code to the arduino and run it.    */
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
//Serial.print(echoPin);
if(distance<10)
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
}
else if(distance>10&&distance<500)
{
 digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); 
}
else
digitalWrite(LED_BUILTIN, HIGH);
}
