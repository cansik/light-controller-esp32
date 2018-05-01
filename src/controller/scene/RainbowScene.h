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

public:
    RainbowScene(LEDChain* ledChain);

    void setup() override;

    void loop() override;
};


#endif //SILVA_STARSCENE_H
