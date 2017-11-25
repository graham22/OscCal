//OSCCAL inicial start
int osccal_val = 50;

//configurations
int bt_plus = 5;
int bt_less = 4;
int remote_less = 6;
int remote_plus = 7;
//pwm out
int pwm_pin = 3;

void setup() {
  Serial.begin(9600);
  //botões de controlo (arduino)
  pinMode(bt_plus, INPUT_PULLUP); //bt plus
  pinMode(bt_less, INPUT_PULLUP); //bt less
  
  //saida de controlo (Attiny)
  pinMode(remote_plus, OUTPUT); //remote plus
  pinMode(remote_less, OUTPUT); //remove less

  //pwm out
  pinMode(pwm_pin, OUTPUT);
}

void loop() {
  //send PWM out sample for refecence (always the same)
  analogWrite(pwm_pin, 100);

  //buttons state
  int res_bt_plus = digitalRead(bt_plus);
  int res_bt_less = digitalRead(bt_less);

  //increment osccal
  if (res_bt_plus == LOW) {
    digitalWrite(remote_plus, HIGH);
    delay(500);
    digitalWrite(remote_plus, LOW);
    
    osccal_val = osccal_val + 1;
  }
  //decrement osccal
  if (res_bt_less == LOW) {
   digitalWrite(remote_less, HIGH);
    delay(500);
    digitalWrite(remote_less, LOW);
    
    osccal_val = osccal_val - 1;
  }
  
  //print out the OSCAL value
  Serial.print("Oscal: ");
  Serial.println(osccal_val);
  
  //wait until new button press
  while(digitalRead(bt_plus) == HIGH && digitalRead(bt_less) == HIGH)  ;
}
