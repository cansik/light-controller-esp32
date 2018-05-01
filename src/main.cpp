#include <Arduino.h>
#include <ESP8266mDNS.h>
#include <util/PlatformConstants.h>
#include <controller/BaseController.h>
#include <controller/network/NetworkController.h>
#include <controller/network/OTAController.h>
#include <controller/network/OscController.h>
#include <Wire.h>

// global
#define LED_COUNT 30

// serial
#define BAUD_RATE 115200

// network
#define DEVICE_NAME "ann-a-master"

#define SSID_NAME "ann-a"
#define SSID_PASSWORD "AnnaUndIsmael"

#define OTA_PASSWORD "ann-a"
#define OTA_PORT 8266

#define OSC_OUT_PORT 9000
#define OSC_IN_PORT 8000

// typedefs
typedef BaseController *BaseControllerPtr;

// controllers
auto network = NetworkController(DEVICE_NAME, SSID_NAME, SSID_PASSWORD, WIFI_AP);
auto ota = OTAController(DEVICE_NAME, OTA_PASSWORD, OTA_PORT);
auto osc = OscController(OSC_IN_PORT, OSC_OUT_PORT);

// controller list
BaseControllerPtr controllers[] = {
        &network,
        &ota,
        &osc
};

void setup() {
    Serial.begin(BAUD_RATE);

    // wait 3000 seconds for debugging
    delay(3000);

    // setup wire
    Wire.begin(D2, D1);

    // setup controllers
    for (auto &controller : controllers) {
        controller->setup();
    }

    // add osc mdns
    MDNS.addService("osc", "udp", OSC_IN_PORT);

    Serial.println("setup finished!");
    osc.send("/ann-a/status", "setup finished!");
}

void loop() {
    // loop controllers
    for (auto &controller : controllers) {
        controller->loop();
    }
}