//
// Created by David on 8/22/2020.
//

#include "Vector.h"

#include <cmath>

template<typename R>
R add(const Vector& a, const Vector& b) {
  return { a.x + b.x, a.y + b.y, a.z + b.z };
}

template<typename R>
R sub(const Vector& a, const Vector& b) {
  return { a.x - b.x, a.y - b.y, a.z - b.z };
}

// -----------------------------------------------------------------------------------
// Vector
// -----------------------------------------------------------------------------------

Vector::Vector() {}

Vector::Vector(const Vector &other) : x(other.x), y(other.y), z(other.z) {}

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {}

float Vector::length() const {
  return sqrtf(this->lengthSquared());
}

float Vector::lengthSquared() const {
  return (x * x) + (y * y) + (z * z);
}

Vector operator+(const Vector& a, const Vector& b) {
  return add<Vector>(a, b);
}

Vector operator-(const Vector& a, const Vector& b) {
  return sub<Vector>(a, b);
}

// -----------------------------------------------------------------------------------
// Direction
// -----------------------------------------------------------------------------------

Direction Direction::xPos() {
  return {1, 0, 0};
}

Direction Direction::xNeg() {
  return {-1, 0, 0};
}

Direction Direction::yPos() {
  return {0, 1, 0};
}

Direction Direction::yNeg() {
  return {0, -1, 0};
}

Direction Direction::zPos() {
  return {0, 0, 1};
}

Direction Direction::zNeg() {
  return {0, 0, -1};
}

Direction::Direction(const Vector &other) : Vector(other) {}

Direction::Direction(float x, float y, float z) : Vector(x, y, z) {}

void Direction::normalize() {
  const auto len = this->length();
  if (len != 0) {
    this->x = this->x / len;
    this->y = this->y / len;
    this->z = this->z / len;
  }
}

Direction Direction::operator-() const {
  return { -x, -y, -z };
}

Direction operator*(float scalar, const Direction& direction) {
  return { direction.x * scalar, direction.y * scalar, direction.z * scalar };
}

Direction operator*(const Direction& direction, float scalar) {
  return scalar * direction;
}

Direction operator/(const Direction& direction, float scalar) {
  return (1.f / scalar) * direction;
}

Direction operator+(const Direction& a, const Direction& b) {
  return add<Direction>(a, b);
}

Direction operator-(const Direction& a, const Direction& b) {
  return sub<Direction>(a, b);
}

Position operator+(const Position& pos, const Direction& dir) {
  return add<Position>(pos, dir);
}

Position operator-(const Position& pos, const Direction& dir) {
  return sub<Position>(pos, dir);
}

Position Position::origin() {
  return { 0, 0, 0 };
}
