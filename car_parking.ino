#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "akshaypradheepdc.firebaseio.com"
#define FIREBASE_AUTH "vfUtznfQTNsjBnwNw5VTrNEldJVydp5CgNMfTjk5"
#define WIFI_SSID "NodeNet"
#define WIFI_PASSWORD "nodemcu8266"
int maxn;


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
  Firebase.setFloat("maximum", 5);//temp
  maxn = Firebase.getInt("maximum");
}
void loop(){

	int password[maxn];
	for (int i = 0; i < maxn; i++)
	{
		String passNum = String(i);
		password[i]= Firebase.getFloat(passNum);
	}
	for (int i = 0; i < maxn; i++)
	{
		Serial.println(password[i]);
	}
	
}