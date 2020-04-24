// This example sends data along with timestamp in POSIX ms standard
// to a variable to Ubidots API through HTTP, TCP or UDP protocol.

/****************************************
 * Include Libraries
 ****************************************/

#include "Ubidots.h"
#define FAllING_Flag_bin D1
/****************************************
 * Define Instances and Constants
 ****************************************/

const char* UBIDOTS_TOKEN = "BBFF-AtT65GJBSHujQAMMbutbPpbPcdyqgl";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "WE_E73434";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "jbq0878@wifi";      // Put here your Wi-Fi password
Ubidots ubidots(UBIDOTS_TOKEN);

/****************************************
 * Auxiliar Functions
 ****************************************/

// Put here your auxiliar functions

/****************************************
 * Main Functions
 ****************************************/

void setup() {
  Serial.begin(9600);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  ubidots.setDebug(true);  // Uncomment this line for printing debug messages
  pinMode(FAllING_Flag_bin,INPUT);

}

void loop() {
  int  falling_flag = digitalRead(FAllING_Flag_bin);
  
  unsigned long timestamp_seconds = 1571615253L;  // Put here your timestamp in seconds
  unsigned int timestamp_milliseconds = 0;        // Put here the number of milliseconds to shift your timestamp

  ubidots.add("falling_flag", falling_flag , NULL, timestamp_seconds, timestamp_milliseconds);  // Change for your variable name

  bool bufferSent = false;
  bufferSent = ubidots.send();  // Will send data to a device label that matches the device Id

  if (bufferSent) {
    // Do something if values were sent properly
    Serial.println("Values sent by the device");
  }
  Serial.println(falling_flag);
  delay(1000);
}
