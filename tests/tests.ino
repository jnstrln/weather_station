#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SDA_PIN 21
#define SCL_PIN 22

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN); // même pins que ton câblage
  Serial.begin(115200);
  delay(1000);
  Serial.println("🔍 Scan I2C en cours...");
  byte error, address;
  int devices = 0;

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("✅ Capteur détecté à l'adresse 0x");
      Serial.println(address, HEX);
      devices++;
    }
  }

  if (devices == 0) Serial.println("❌ Aucun périphérique I2C détecté !");
  else Serial.println("✅ Scan terminé !");
}

void loop() {}
