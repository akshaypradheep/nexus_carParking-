#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "akshaypradheepdc.firebaseio.com"
#define FIREBASE_AUTH "vfUtznfQTNsjBnwNw5VTrNEldJVydp5CgNMfTjk5"
#define WIFI_SSID "NodeNet"
#define WIFI_PASSWORD "nodemcu8266"

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  int maxn = Firebase.getInt("maximum");
  int password[maxn];
}
void loop(){
	

}