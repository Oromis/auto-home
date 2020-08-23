//
// Created by David on 8/23/2020.
//

#ifndef AUTO_HOME_LEDCONTROLLER_H
#define AUTO_HOME_LEDCONTROLLER_H

#include <vector>
#include <list>
#include <memory>

#include "LinearLedStrip.h"

/**
 * An animation affects one or more LEDs, creating large-scale effects
 */
class Animation;

class LedController {
public:
  LedController(std::initializer_list<LinearLedStrip> strips);

  void addAnimation(const std::shared_ptr<Animation>& animation);

  void tick();

private:
  float calcDeltaSeconds();

  std::vector<LinearLedStrip> strips;

  /// List of all currently active animations. Sorted by highest priority first.
  std::list<std::shared_ptr<Animation>> animations;

  uint8_t brightness = 128;
  unsigned long lastTickTime = 0;
};

#endif //AUTO_HOME_LEDCONTROLLER_H
