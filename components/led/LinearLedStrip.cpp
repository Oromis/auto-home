//
// Created by David on 8/22/2020.
//

#include "LinearLedStrip.h"

#include <utility>
#include <HardwareSerial.h>

LinearLedStrip::LinearLedStrip(Position origin, Direction direction, float spacing, CRGB* leds, int count) :
    origin(std::move(origin)), direction(std::move(direction)), spacing(spacing), leds(leds), count(count) {
}

LinearLedStrip::Iterator LinearLedStrip::begin() {
  return LinearLedStrip::Iterator(*this);
}

LinearLedStrip::Iterator LinearLedStrip::end() {
  return LinearLedStrip::Iterator(*this, this->count);
}

// -----------------------------------------------------------------------------------
// Iterator
// -----------------------------------------------------------------------------------

LinearLedStrip::Iterator::Iterator(LinearLedStrip& strip, int index) : strip(strip), index(index) {}

LinearLedStrip::Iterator::Iterator(const Iterator& other) : strip(other.strip), index(other.index) {}

LinearLedStrip::Iterator& LinearLedStrip::Iterator::operator++() {
  ++this->index;
  return *this;
}

const LinearLedStrip::Iterator LinearLedStrip::Iterator::operator++(int)& {
  Iterator copy(*this);
  this->operator++();
  return copy;
}

LinearLedStrip::Iterator& LinearLedStrip::Iterator::operator--() {
  if (this->index > 0) {
    --this->index;
  }
  return *this;
}

const LinearLedStrip::Iterator LinearLedStrip::Iterator::operator--(int)& {
  Iterator copy(*this);
  this->operator--();
  return copy;
}

bool LinearLedStrip::Iterator::operator==(const LinearLedStrip::Iterator& other) const {
  return (&this->strip == &other.strip) && (this->index == other.index);
}

bool LinearLedStrip::Iterator::operator!=(const LinearLedStrip::Iterator& other) const {
  return !this->operator==(other);
}

PositionedLed LinearLedStrip::Iterator::operator*() const {
  if (this->index >= this->strip.count) {
    Serial.printf("Illegal iterator access: Index = %d, item count = %d\n", this->index, this->strip.count);
    abort();
  }

  return {
      this->strip.leds[std::max(this->index, this->strip.count)],
      this->strip.origin + ((static_cast<float>(this->index) * this->strip.spacing) * this->strip.direction)
  };
}
