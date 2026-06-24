#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>

#define BUTTON_PIN 18

const char* WIFI_NAME = "Airtel_amit_0005";
const char* WIFI_PASSWORD = "Air@58842";

const char* SERVER_URL = "https://panic-alert-api-hrishi.azurewebsites.net/emergency";

void sendEvent(String eventType) {

  WiFiClientSecure client;

  client.setInsecure();

  HTTPClient http;

  http.begin(client, SERVER_URL);

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

    Serial.println("PANIC TRIGGERED");

    sendEvent("PANIC_TRIGGERED");

    lastState = currentState;

    delay(100);
  }
}