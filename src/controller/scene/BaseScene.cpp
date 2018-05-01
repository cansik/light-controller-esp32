//
// Created by Florian on 28.11.17.
//

#include "BaseScene.h"
#include "../BaseController.h"

BaseScene::BaseScene(const char *name) {
    this->name = name;
}

void BaseScene::setup() {
    BaseController::setup();
}

void BaseScene::loop() {
    BaseController::loop();
}

const char * BaseScene::getName() const {
    return name;
}
