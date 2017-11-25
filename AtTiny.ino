byte osccal_val = 50; //OSCCAL inicial start
byte remote_less = 3; //remote arduino tells to decrement
byte remote_plus = 4; //remote arduino tells to increment

void setup()  {
  //pwm sample pin
  pinMode(1, OUTPUT);
  
  //remote OSCCAL inclement
  pinMode(remote_plus, INPUT); //remote plus
  pinMode(remote_less, INPUT); //remove less
} 

void loop()  {
  OSCCAL = osccal_val;
  analogWrite(1, 100); //send PWM out sample (always the same)
  
  //don't move until something changes
  while(digitalRead(remote_plus) == LOW && digitalRead(remote_less) == LOW)
    ;
  
  if(digitalRead(remote_plus) == HIGH){
    osccal_val = osccal_val + 1;
    
    //wait until gets LOW again
    while(digitalRead(remote_plus) == HIGH)
      ;
  }
  
  if(digitalRead(remote_less) == HIGH){
    osccal_val = osccal_val -1;
    
    //wait until gets LOW again
    while(digitalRead(remote_less) == HIGH)
      ;
  }
}
