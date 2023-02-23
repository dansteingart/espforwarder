#include <WiFi.h>
#include <PubSubClient.h>
#include "settings.h"

#define RXD2 13
#define TXD2 12

WiFiClient espClient;
PubSubClient client(espClient);
void callback(char* topic, byte* payload, unsigned int length);

const int MESSAGE_COUNT_THRESHOLD = 100;
unsigned long last_message_time = 0;
int message_count = 0;

void setup() {
  Serial.begin(115200);
   Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);

  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  // Connect to MQTT broker
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  reconnect();
}


void reconnect()
{
    while (!client.connected()) {
    Serial.println("Connecting to MQTT broker...");
    if (client.connect(mqtt_name)) {
      Serial.println("Connected to MQTT broker");
    client.subscribe(mqtt_recv);
      Serial.print("Subscribed to topic: ");

    } else {
      Serial.print("Failed to connect to MQTT broker, rc=");
      Serial.print(client.state());
      Serial.println(" retrying in 5 seconds");
      delay(5000);
    }
  }

}


void loop() {
  if (Serial2.available() > 0) {
    // Read the incoming message
    String message = Serial2.readStringUntil('\n');
    message.trim();
    Serial.println(message);

    // Check if 1 second has passed since the last message was sent
      if (millis() - last_message_time >= 1000) {
        // Publish the message to the MQTT broker
        client.publish(mqtt_send, message.c_str());

        // Reset the last message time
        last_message_time = millis();
      }
    }
  

  // Check for incoming MQTT messages
  if (!client.connected()) reconnect();
  client.loop();
}

void callback(char* topic, byte* payload, unsigned int length) {
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
    Serial2.print((char)payload[i]);

  }
  
  Serial.println();
  Serial2.println();
  

}

