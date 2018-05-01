//
// Created by Florian on 01.05.18.
//

#ifndef ANN_A_FASTLEDRENDERER_H
#define ANN_A_FASTLEDRENDERER_H


#include "BaseRenderer.h"

class FastLEDRenderer : public BaseRenderer {
protected:
    explicit FastLEDRenderer(const unsigned long updatesPerSecond);
    unsigned long updatesPerSecond;

public:
    void setup() override;

    virtual void render();
};


#endif //ANN_A_FASTLEDRENDERER_H
