//
// Created by David on 8/22/2020.
//

#ifndef AUTO_HOME_LINEARLEDSTRIP_H
#define AUTO_HOME_LINEARLEDSTRIP_H

#include <iterator>
#include <memory>

#include <FastLED.h>

#include "../../main/Vector.h"
#include "PositionedLed.h"

class LinearLedStrip {
public:
  class Iterator : public std::iterator<std::bidirectional_iterator_tag, PositionedLed, int> {
  public:
    explicit Iterator(LinearLedStrip& strip, int index = 0);
    Iterator(const Iterator& other);

    Iterator& operator++();
    const Iterator operator++(int) &;
    Iterator& operator--();
    const Iterator operator--(int) &;

    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;

    PositionedLed operator*() const;

  private:
    LinearLedStrip& strip;
    int index;
  };

  LinearLedStrip(Position origin, Direction direction, float spacing, CRGB* leds, int count);

  Iterator begin();
  Iterator end();

private:
  Position origin;
  Direction direction;
  float spacing;
  CRGB* leds;
  int count;
};

#endif //AUTO_HOME_LINEARLEDSTRIP_H
