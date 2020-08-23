//
// Created by David on 8/23/2020.
//

#include "PositionedLed.h"

#include <utility>

PositionedLed::PositionedLed(CRGB& rgb, Position position) : rgb(rgb), position(std::move(position)) {}
