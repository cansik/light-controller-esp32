//
// Created by Florian on 01.05.18.
//

#include "ArtnetScene.h"

ArtnetScene::ArtnetScene(LEDChain *ledChain) : BaseScene("ArtNet Scene") {
    this->ledChain = ledChain;
}

void ArtnetScene::setup() {
    BaseScene::setup();

    artnet.begin();

    artnet.setArtDmxCallback(onDmxFrame);
    artnet.setArtSyncCallback(onSync);
}

void ArtnetScene::loop() {
    BaseScene::loop();

    artnet.read();
}

void ArtnetScene::onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t *data, IPAddress remoteIP) {
    for (int i = 0; i < length / 3; i++)
    {
        int led = i + (universe - startUniverse) * (previousDataLength / 3);
        if (led < ledChain->length)
        {
            ledChain->leds[led] = CRGB(data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
        }
    }
    previousDataLength = length;
}

void ArtnetScene::onSync(IPAddress remoteIP) {

}
