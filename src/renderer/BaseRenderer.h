//
// Created by Florian on 06.12.17.
//

#ifndef SILVA_LIGHTRENDERER_H
#define SILVA_LIGHTRENDERER_H

#include "../controller/BaseController.h"

class BaseRenderer : public BaseController {
protected:
    explicit BaseRenderer();

public:
    void setup() override;

    void loop() override;

    virtual void render();
};


#endif //SILVA_LIGHTRENDERER_H
