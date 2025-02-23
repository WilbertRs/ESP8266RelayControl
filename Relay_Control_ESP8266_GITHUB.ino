//Dari Wilbert❤️ SMPN 8 Yogyakarta//

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
char auth[] = "Masukkan Blynk Auth Token"; //Gunakan library Blynk V1.2.0
char ssid[] = "SSID WI-FI"; //Wi-Fi Rumah atau Hotspot
char pass[] = "PASSWORD WI-FI"; //Password Wi-Fi Rumah atau Hotspot

bool Relay1 = 0;
bool Relay2 = 0;
bool Relay3 = 0;

#define relay1 D5
#define relay2 D2
#define relay3 D7

void setup() {
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, HIGH);

  pinMode(relay2, OUTPUT);
  digitalWrite(relay2, HIGH);

  pinMode(relay3, OUTPUT);
  digitalWrite(relay3, HIGH);
  
  Blynk.begin(auth, ssid, pass, "serverlocalanda.com", 8181); //Jangan lupa masukkan server lokal dan portnya

}

BLYNK_WRITE(V1) {
  Relay1 = param.asInt();
 
  if (Relay1 == 1) {
    digitalWrite(relay1, LOW);
 
  } else {
    digitalWrite(relay1, HIGH);
  }
}

BLYNK_WRITE(V2) {
  Relay2 = param.asInt();
 
  if (Relay2 == 1) {
    digitalWrite(relay2, LOW);
 
  } else {
    digitalWrite(relay2, HIGH);
  }
}

BLYNK_WRITE(V3) {
  Relay3 = param.asInt();
 
  if (Relay3 == 1) {
    digitalWrite(relay3, LOW);
 
  } else {
    digitalWrite(relay3, HIGH);
  }
}
 
void loop() {
  Blynk.run();
}