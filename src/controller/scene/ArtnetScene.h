//
// Created by Florian on 01.05.18.
//

#ifndef ANN_A_ARTNETSCENE_H
#define ANN_A_ARTNETSCENE_H

#include <artnet/Artnet.h>
#include <model/LEDChain.h>
#include "BaseScene.h"

class ArtnetScene : public BaseScene {

protected:
    LEDChain *ledChain;

    Artnet artnet;
    const int startUniverse = 0; // CHANGE FOR YOUR SETUP most software this is 1, some software send out artnet first universe as 0.
    int previousDataLength = 0;

public:
    ArtnetScene(LEDChain *ledChain);

    void setup() override;

    void loop() override;

    void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data, IPAddress remoteIP);

    void onSync(IPAddress remoteIP);

    static void onDmxFrameStatic(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t *data, IPAddress remoteIP);

    static void onSyncStatic(IPAddress remoteIP);
};


#endif //ANN_A_ARTNETSCENE_H

static ArtnetScene *instance = new ArtnetScene(new LEDChain(10));