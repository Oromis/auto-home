//
// Created by David on 8/23/2020.
//

#ifndef AUTO_HOME_POSITIONEDLED_H
#define AUTO_HOME_POSITIONEDLED_H

#include "../../main/Vector.h"
#include "FastLED.h"

class ColorProvider;

class PositionedLed {
public:
  PositionedLed(CRGB& rgb, Position position);

  CRGB& rgb;
  Position position;
};

#endif //AUTO_HOME_POSITIONEDLED_H
