//
// Created by David on 8/22/2020.
//

#ifndef AUTO_HOME_VECTOR_H
#define AUTO_HOME_VECTOR_H

class Vector {
public:
  // -----------------------------------------------------------------------------------
  // Instance methods
  // -----------------------------------------------------------------------------------

  Vector();
  Vector(const Vector& other);
  Vector(float x, float y, float z);

  float length() const;
  float lengthSquared() const;

  // -----------------------------------------------------------------------------------
  // Fields
  // -----------------------------------------------------------------------------------

  float x = 0;
  float y = 0;
  float z = 0;
};

Vector operator + (const Vector& a, const Vector& b);
Vector operator - (const Vector& a, const Vector& b);

class Direction final : public Vector {
public:
  static Direction xNeg();
  static Direction yPos();
  static Direction yNeg();
  static Direction zPos();
  static Direction xPos();
  static Direction zNeg();

  explicit Direction(const Vector& other);
  Direction(float x, float y, float z);

  void normalize();

  Direction operator - () const;
};

Direction operator + (const Direction& a, const Direction& b);
Direction operator - (const Direction& a, const Direction& b);
Direction operator * (float scalar, const Direction& direction);
Direction operator * (const Direction& direction, float scalar);
Direction operator / (const Direction& direction, float scalar);

class Position final : public Vector {
public:
  static Position origin();

  using Vector::Vector;
};

Position operator+(const Position& pos, const Direction& dir);
Position operator-(const Position& pos, const Direction& dir);

#endif //AUTO_HOME_VECTOR_H
