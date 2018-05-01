#include "LEDChain.h"

LEDChain::LEDChain(int length, Direction direction) {
    this->length = length;
    this->direction = direction;

    leds = new CRGB[length];

    // clear arrays
    for (int i = 0; i < length; ++i)
        leds[i] = CRGB::Black;
}

void LEDChain::all(CRGB color) {
    set(color, 0.0, 1.0);
}

void LEDChain::set(CRGB color, float startIndex, float endIndex) {
    int s = mapIndex(startIndex);
    int e = mapIndex(endIndex);
    int count = e - s;

    for (uint8_t i = 0; i < count; i++) {
        leds[(directionalIndex(i) + s) % length] = color;
    }
}

int LEDChain::mapIndex(float index) { return round(length * index); }

int LEDChain::directionalIndex(int index) {
    if (direction == Direction::Inverted)
        return length - index;

    return index;
}
