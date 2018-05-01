//
// Created by Florian on 06.12.17.
//

#include "BaseRenderer.h"
#include "../controller/BaseController.h"

BaseRenderer::BaseRenderer() {
}

void BaseRenderer::setup() {
    BaseController::setup();
}

void BaseRenderer::loop() {
    BaseController::loop();
    render();
}

void BaseRenderer::render() {
    // send out data
}
