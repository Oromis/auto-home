//
// Created by David on 8/23/2020.
//

#include "StaticUniformColor.h"
#include "PositionedLed.h"

void StaticUniformColor::tick(float deltaTime) {
  // Intentionally left blank - this component doesn't need to keep track of time
}

bool StaticUniformColor::computeColor(PositionedLed& led) {
  led.rgb = color;
  return true;
}

int StaticUniformColor::getPriority() const {
  return PRIORITY_FALLBACK;
}

bool StaticUniformColor::isDone() const {
  return false;
}

const CRGB& StaticUniformColor::getColor() const {
  return color;
}

void StaticUniformColor::setColor(const CRGB& newColor) {
  this->color = newColor;
}
