void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
//pinMode(2,OUTPUT);
//pinMode(3,OUTPUT);
pinMode(13,OUTPUT);
}

//int hat_up,hat_down,hat_left,hat_right,up,down,left,right,start,back,front_left,front_right,left_x,left_y,right_x,right_y,front_x,front_y;


void loop() {
  // put your main code here, to run repeatedly
  while(Serial.available()){
    String s = Serial.readString();
    int str_len = s.length() + 1; 
    // Prepare the character array (the buffer) 
    char char_array[str_len];
    
    // Copy it over 
    s.toCharArray(char_array, str_len);
    //   Serial.write(char_array[15]);

    // getting all the values 
    char hat_up = char_array[0];
    char hat_down = char_array[1];
    char hat_left = char_array[2];
    char hat_right = char_array[3];
    char up = char_array[4];
    char down = char_array[5];
    char left = char_array[6];
    char right = char_array[7];
    char start = char_array[8];
    char back = char_array[9];
    char front_left = char_array[10];
    char front_right = char_array[11];
    char left_x = char_array[12];
    char left_y = char_array[13];
    char right_x = char_array[14];
    char right_y = char_array[15];
    char front_x = char_array[16];
    char front_y = char_array[17];

    // performming the functions accordingly
    if(hat_up == '1'){
      digitalWrite(13,HIGH);
    }
    if(hat_up == '0'){
      digitalWrite(13,LOW);
    }
    
    


    
   
}
}
