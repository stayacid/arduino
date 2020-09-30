boolean btn_flag = false;
boolean btn;
boolean led_flag = false;
unsigned long last_press;
byte led_counter = 4;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT_PULLUP); // button
  Serial.begin(9600);
  pinMode(4, OUTPUT); // diod
  pinMode(5, OUTPUT); // diod
  pinMode(6, OUTPUT); // diod
  pinMode(7, OUTPUT); // diod
  pinMode(8, OUTPUT); // diod
  pinMode(9, OUTPUT); // diod
  digitalWrite(4, false);
  digitalWrite(5, false);
  digitalWrite(6, false);
  digitalWrite(7, false);
  digitalWrite(8, false);
  digitalWrite(9, false);
}

void loop() {
  // put your main code here, to run repeatedly:
  btn = !digitalRead(A0);

  if (btn && btn_flag == false && millis() - last_press > 50) {
    btn_flag = true;
    Serial.print("Led: " + led_counter);Serial.print(led_counter);Serial.println(" Button pressed");
    //led_flag = !led_flag;
    digitalWrite(led_counter, true); // on/off diod
    led_counter++;
    if (led_counter > 8) {
      while (led_counter > 4) {
        --led_counter;
        digitalWrite(led_counter, false);
      }
    }
    last_press = millis();
  }
  
  if (!btn && btn_flag == true ) {
    btn_flag = false;
    Serial.println("Button released");
  }

}
