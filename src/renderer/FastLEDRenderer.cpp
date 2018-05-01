//
// Created by Florian on 01.05.18.
//

#include "FastLEDRenderer.h"
#include <FastLED.h>

FastLEDRenderer::FastLEDRenderer(const unsigned long updatesPerSecond) {
    this->updatesPerSecond = updatesPerSecond;
}

void FastLEDRenderer::setup() {
    BaseRenderer::setup();
}

void FastLEDRenderer::render() {
    BaseRenderer::render();

    FastLED.show();
    FastLED.delay(1000 / updatesPerSecond);
}
