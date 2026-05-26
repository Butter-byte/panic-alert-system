#define BUTTON_PIN 18

void setup() {

  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.println("Button system ready");
}

void loop() {

  static bool lastState = HIGH;

  bool currentState = digitalRead(BUTTON_PIN);

  if(currentState != lastState) {

    if(currentState == LOW) {

      Serial.println("EMERGENCY ACTIVE");
    }
    else {

      Serial.println("EMERGENCY CLEARED");
    }

    lastState = currentState;

    delay(100);
  }
}