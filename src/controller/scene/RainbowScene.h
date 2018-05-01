//
// Created by Florian on 13.12.17.
//

#ifndef SILVA_STARSCENE_H
#define SILVA_STARSCENE_H


#include <model/LEDChain.h>
#include "BaseScene.h"

class RainbowScene : public BaseScene {

protected:
    LEDChain *ledChain;

    CRGBPalette16 currentPalette;
    TBlendType currentBlending;

    uint8_t startIndex = 0;
    uint8_t brightness = 255;

public:
    RainbowScene(LEDChain* ledChain);

    void setup() override;

    void loop() override;
};


#endif //SILVA_STARSCENE_H
