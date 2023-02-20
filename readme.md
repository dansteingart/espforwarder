# espforwarder

The internet of things is just the best. But you have a lot of old arduino/µC code that "just works" over serial, and you don't want to break stuff by hacking in MQTT and wifi? Or maybe you realilzed that there's significant overhead in waiting for a `client.loop()` / `client.publish()` to clear and you just want the analog side of things to not be bothered. Or something else where you want to seperated the webby/digital side from the serial/analog side. Whatever the case, I got you.

You might ask: don't the adafruit airlifts already do this? Sort of, but they're designed to be suborbinate and in the loop of the analog µC. While their firmware can be flashed to accomplish what we accomplish here, we can do it here without swapping modes and with [parts](https://www.amazon.com/HiLetgo-Wireless-Transceiver-Development-Compatible/dp/B010N1ROQS/) that cost < $3/piece on amazon.

ESPForwarder is a cousin to [nodeforwarder](https://github.com/dansteingart/nodeforwarder) that allows you to take any µC with serial RX/TX, quickly pair it with an ESP8266/ESP32 controller (the cheapest ones are fine!) and get your project on the internet and up and running with MQTT.

To use, just
1. Make sure you have `PubSubClient` installed.
2. Edit `settings.h.example` and copy to `settings.h`
3. Compile `espforwarder.ino` in your favorite arduino client.
4. Upload to your ESPXXXX of choice.


More to come.
