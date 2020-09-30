void setup() {
  // put your setup code here, to run once:
  pinMode(A5, INPUT_PULLUP);
  pinMode(13, OUTPUT); // тут светодиод L на плате

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  boolean button1 = !digitalRead(A5);

  if (button1) {
    digitalWrite(13, 1);
  } else {
    digitalWrite(13, 0);
  }

  Serial.print("Button1: ");Serial.println(button1);
}
