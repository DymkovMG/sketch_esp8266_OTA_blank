#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>

//#define DEBUG 
#ifdef DEBUG
  #define DEBUG_PRINT(x) Serial.print  (x)
  #define DEBUG_PRINTDEC(x) Serial.print  (x,DEC)
  #define DEBUG_PRINTLN(x) Serial.println  (x)
#else  
  #define DEBUG_PRINT(x) 
  #define DEBUG_PRINTDEC(x) 
  #define DEBUG_PRINTLN(x) 
#endif

#ifndef STASSID
#define STASSID "FALK"
#define STAPSK  "3199431994"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;




void setup(void) 
{
  #ifdef DEBUG
    Serial.begin(115200);// initialize serial communication 
  #endif  
  DEBUG_PRINTLN("Start initialization.");

  pinMode(LED_BUILTIN, OUTPUT);

  //digitalWrite(LED_BUILTIN, LOW);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    DEBUG_PRINT("*");
  }
  DEBUG_PRINTLN("");
  DEBUG_PRINT("Connected to ");
  DEBUG_PRINTLN(ssid);
  DEBUG_PRINT("IP address: ");
  DEBUG_PRINTLN(WiFi.localIP());


  
  ArduinoOTA.setHostname("ESP8266_TEST");
  // No authentication by default
  // ArduinoOTA.setPassword("admin");
  ArduinoOTA.begin();
  
  digitalWrite(LED_BUILTIN, HIGH);//откл светодиод
  DEBUG_PRINTLN("Initialization..OK");
}

void loop(void) 
{
  ArduinoOTA.handle();
  
  
}
