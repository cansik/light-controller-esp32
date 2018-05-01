#define FASTLED_ESP8266_RAW_PIN_ORDER

#include <Arduino.h>
#include <ESP8266mDNS.h>
#include <util/PlatformConstants.h>
#include <controller/BaseController.h>
#include <controller/network/NetworkController.h>
#include <controller/network/OTAController.h>
#include <controller/network/OscController.h>
#include <Wire.h>
#include <controller/scene/RainbowScene.h>
#include <controller/scene/SceneController.h>
#include <renderer/BaseRenderer.h>
#include <renderer/FastLEDRenderer.h>
#include <controller/scene/ArtnetScene.h>

// global

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

// Fast LED
#define NUM_LEDS 30
#define LED_DATA_PIN D4

#define UPDATES_PER_SECOND 100

// typedefs
typedef BaseController *BaseControllerPtr;

// led chain
auto ledChain = LEDChain(NUM_LEDS);

// controllers
auto network = NetworkController(DEVICE_NAME, SSID_NAME, SSID_PASSWORD, WIFI_AP);
auto ota = OTAController(DEVICE_NAME, OTA_PASSWORD, OTA_PORT);
auto osc = OscController(OSC_IN_PORT, OSC_OUT_PORT);
auto ledRenderer = FastLEDRenderer(UPDATES_PER_SECOND);

// scenes
auto rainbowScene = RainbowScene(&ledChain);
auto artnetScene = ArtnetScene(&ledChain);
auto sceneController = SceneController(&artnetScene);

// controller list
BaseControllerPtr controllers[] = {
        &network,
        &ota,
        &osc,
        &sceneController,
        &ledRenderer
};

void setup() {
    Serial.begin(BAUD_RATE);

    // wait 3000 seconds for debugging
    delay(3000);

    // setup wire
    Wire.begin(D2, D1);

    // setup strips
    ledChain.setup<LED_DATA_PIN>();
    ledChain.all(CRGB::Black);

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