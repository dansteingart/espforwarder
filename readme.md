# ESPForwarder

The internet of things is just the best. But you have a lot of old arduino/µC code that "just works" over serial, and you don't want to break stuff by hacking in MQTT and wifi? Got you.

ESPForwarder is a cousin to [nodeforwarder](https://github.com/dansteingart/nodeforwarder) that allows you to take any µC with serial RX/TX, quickly pair it with an ESP8266/ESP32 controller (the cheapest ones are fine!) and get your project on the internet and up and running with MQTT.

To use, just
1. Make sure you have `PubSubClient` installed.
2. Edit `settings.h.example` and copy to `settings.h`
3. Compile `espforwarder.ino` in your favorite arduino client.
4. Upload to your ESPXXXX of choice.


More to come.