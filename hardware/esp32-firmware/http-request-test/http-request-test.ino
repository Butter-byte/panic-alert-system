#include <WiFi.h>
#include <HTTPClient.h>

const char* WIFI_NAME = "Airtel_amit_0005";
const char* WIFI_PASSWORD = "Air@58842";

const char* SERVER_URL = "https://webhook.site/80681856-ee38-427b-80fd-201ecb6bca22";

void setup() {

  Serial.begin(115200);

  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

  Serial.println("Connecting to WiFi...");

  while(WiFi.status() != WL_CONNECTED) {

    delay(1000);

    Serial.println("Still connecting...");
  }

  Serial.println("WiFi connected!");

  HTTPClient http;

  http.begin(SERVER_URL);

  http.addHeader("Content-Type", "application/json");

  String jsonData = "{\"device\":\"ESP32\",\"event\":\"panic_button_test\"}";

  int httpResponseCode = http.POST(jsonData);

  Serial.print("HTTP Response Code: ");

  Serial.println(httpResponseCode);

  String response = http.getString();

  Serial.println("Server Response:");

  Serial.println(response);

  http.end();
}

void loop() {

}