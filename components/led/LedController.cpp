//
// Created by David on 8/23/2020.
//

#include <Arduino.h>

#include "LedController.h"
#include "Animation.h"

LedController::LedController(std::initializer_list<LinearLedStrip> strips) : strips(strips) {

}

void LedController::tick() {
  const auto delta = this->calcDeltaSeconds();

  for (auto it = this->animations.begin(); it != this->animations.end(); ) {
    auto& animation = *it;
    animation->tick(delta);
    if (animation->isDone()) {
      it = this->animations.erase(it);
    } else {
      ++it;
    }
  }

  for (auto& strip : this->strips) {
    for (auto led : strip) {
      for (auto& animation : this->animations) {
        if (animation->computeColor(led)) {
          break;
        }
      }
    }
  }
}

void LedController::addAnimation(const std::shared_ptr<Animation>& animation) {
  this->animations.push_back(animation);
  std::sort(this->animations.begin(), this->animations.end(), [] (const auto& a, const auto& b) {
    return b->getPriority() < a->getPriority();
  });
}

float LedController::calcDeltaSeconds() {
  const auto now = millis();
  auto delta = static_cast<float>(now - this->lastTickTime) / 1000.f;
  this->lastTickTime = now;
  return delta;
}
