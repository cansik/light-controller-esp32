//
// Created by Florian on 13.12.17.
//

#include "RainbowScene.h"

void RainbowScene::setup() {
    BaseScene::setup();

    currentBlending = LINEARBLEND;
    currentPalette = RainbowColors_p;
}

void RainbowScene::loop() {
    BaseScene::loop();

    startIndex = (startIndex + 1) % 14400; /* motion speed */

    uint8_t colorIndex = startIndex;
    for(uint8_t i = 0; i < ledChain->length; i++)
    {
        ledChain->leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}

RainbowScene::RainbowScene(LEDChain *ledChain) : BaseScene("RainbowScene") {
    this->ledChain = ledChain;
}
