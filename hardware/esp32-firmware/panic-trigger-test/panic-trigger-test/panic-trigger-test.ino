#include <WiFi.h>
#include <HTTPClient.h>

#define BUTTON_PIN 18

const char* WIFI_NAME = "Airtel_amit_0005";
const char* WIFI_PASSWORD = "Air@58842";

const char* SERVER_URL = "http://192.168.1.6:3000/emergency";

void sendEvent(String eventType) {

  HTTPClient http;

  http.begin(SERVER_URL);

  http.addHeader("Content-Type", "application/json");

  String jsonData = "{\"device\":\"ESP32\",\"event\":\"" + eventType + "\"}";

  int responseCode = http.POST(jsonData);

  Serial.print("HTTP Response Code: ");

  Serial.println(responseCode);

  http.end();
}

void setup() {

  Serial.begin(115200);

  delay(3000);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

  Serial.println("Connecting to WiFi...");

  while(WiFi.status() != WL_CONNECTED) {

    delay(1000);

    Serial.println("Still connecting...");
  }

  Serial.println("WiFi connected!");
}

void loop() {

  static bool lastState = HIGH;

  bool currentState = digitalRead(BUTTON_PIN);

  if(currentState != lastState) {

    if(currentState == LOW) {

      Serial.println("EMERGENCY ACTIVE");

      sendEvent("EMERGENCY_ACTIVE");
    }
    else {

      Serial.println("EMERGENCY CLEARED");

      sendEvent("EMERGENCY_CLEARED");
    }

    lastState = currentState;

    delay(100);
  }
}