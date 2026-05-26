#include <WiFi.h>

const char* WIFI_NAME = "Airtel_amit_0005";
const char* WIFI_PASSWORD = "Air@58842";

void setup() {

  Serial.begin(115200);

  Serial.println("Starting WiFi connection...");

  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);

    Serial.println("Connecting to WiFi...");
  }

  Serial.println("WiFi connected!");

  Serial.print("ESP32 IP Address: ");

  Serial.println(WiFi.localIP());
}

void loop() {

}