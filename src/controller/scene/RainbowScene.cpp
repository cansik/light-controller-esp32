//
// Created by Florian on 13.12.17.
//

#include "RainbowScene.h"

void RainbowScene::setup() {
    BaseScene::setup();
}

void RainbowScene::loop() {
    BaseScene::loop();

    // change led
    ledChain->all(CRGB::Cyan);
}

RainbowScene::RainbowScene(LEDChain *ledChain) : BaseScene("RainbowScene") {
    this->ledChain = ledChain;
}
