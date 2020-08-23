//
// Created by David on 8/23/2020.
//

#ifndef AUTO_HOME_STATICUNIFORMCOLOR_H
#define AUTO_HOME_STATICUNIFORMCOLOR_H

#include <FastLED.h>

#include "Animation.h"

class StaticUniformColor : public Animation {
public:
  void tick(float deltaTime) override;

  bool computeColor(PositionedLed& led) override;

  int getPriority() const override;

  bool isDone() const override;

  const CRGB& getColor() const;
  void setColor(const CRGB& newColor);

private:
  CRGB color;
};

#endif //AUTO_HOME_STATICUNIFORMCOLOR_H
