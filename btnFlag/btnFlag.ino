boolean btn_flag = false;
boolean btn;
boolean led_flag = false;
unsigned long last_press;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  btn = !digitalRead(3);

  if (btn && btn_flag == false && millis() - last_press > 50) {
    btn_flag = true;
    Serial.println("Button pressed");
    led_flag = !led_flag;
    digitalWrite(13, led_flag);
    last_press = millis();
  }
  
  if (!btn && btn_flag == true ) {
    btn_flag = false;
    Serial.println("Button released");
  }

}
