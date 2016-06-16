/*   
Wirelessly Tracking Temperature Data with the MKR1000 WiFi and PubNub
 */

#include <SPI.h>
#include <WiFi101.h>
#include <PubNub.h>
#include <DHT.h>

#define DHTPIN 6 //set sensor pin
#define DHTTYPE DHT22 //set sensor type

char ssid[] = "network-id"; //  your network SSID (name)
char pass[] = "network-password"; // your network password
char pubkey[] = "demo"; //PubNub publish key
char subkey[] = "demo"; //PubNub subscribe key
char channelt[] = "temperature"; //channel for temperature data
char channelh[] = "humidity"; //channel for humidity data
int status = WL_IDLE_STATUS;
DHT dht(DHTPIN, DHTTYPE); //initialize sensor

char *dtostrf (double val, signed char width, unsigned char dec, char *s) { //convert floats to strings
    char m[20];
    sprintf(m, "%%%d.%df", width, dec);
    sprintf(s, m, val);
    return s;
  }

char longString[100];
char *joinStrings(char* string1, char* string2, char* string3) { //combine multiple long strings
 longString[0] = 0;
 strcat(longString, string1);
 strcat (longString, string2);
 strcat (longString, string3);
 return longString;
}

void setup() {
  Serial.begin(9600);
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(10000);
    dht.begin();
  }
  printWifiStatus(); 
  PubNub.begin(pubkey, subkey); //initialize PubNub
  Serial.println("PubNub connection established");
}


void loop() {
  Serial.println();
  publishTempData();
  publishHumData();
  delay(5000);
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
}


void publishTempData() {
  float f = dht.readTemperature(true); //Read temperature as Fahrenheit

  // Check if any reads failed and exit early (to try again).
  if (isnan(f)) {
    Serial.println("Failed to read temperature from DHT sensor");
    return;
  }
  
  char msg[200];
  dtostrf(f, 7, 2, msg); //convert temperature data to string
  
  //publish temperature data as json
  WiFiClient *client = PubNub.publish(channelt, joinStrings("{\"eon\":{\"SoMa\":\"", msg, "\"}}")); 
  while (client->connected()) {
    char c = client->read();
    Serial.print(c);
  }
  client->stop();
  Serial.println();
  
  if (!client) {
    Serial.println("publishing error");
    delay(1000);
    return;
  }
}


void publishHumData() {
  float h = dht.readHumidity();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h)) {
    Serial.println("Failed to read humidity from DHT sensor!");
    return;
  }
  
  char msg[200];
  dtostrf(h, 7, 2, msg);

  //publish humidity data as json
  WiFiClient *client = PubNub.publish(channelh, joinStrings("{\"eon\":{\"SoMa\":\"", msg, "\"}}"));
  while (client->connected()) {
    char c = client->read();
    Serial.print(c);
  }
  client->stop();
  Serial.println();
  
  if (!client) {
    Serial.println("publishing error");
    delay(1000);
    return;
  }
}
