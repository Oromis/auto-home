//
// Created by David on 8/23/2020.
//

#ifndef AUTO_HOME_ANIMATION_H
#define AUTO_HOME_ANIMATION_H

class PositionedLed;

class Animation {
public:
  static constexpr int PRIORITY_FALLBACK = 0;
  static constexpr int PRIORITY_TRANSITION = 10;
  static constexpr int PRIORITY_EFFECT = 20;

  /**
   * Progresses the animation by the specified amount of time
   * @param deltaTime The time to advance the animation by in seconds
   */
  virtual void tick(float deltaTime) = 0;

  /**
   * Calculates and sets the color of the specified LED at the current point in time
   * @param led The LED to configure
   * @return true if the color has been set, false if this animation doesn't affect the LED
   */
  virtual bool computeColor(PositionedLed& led) = 0;

  /**
   * @return This animation's priority value. Higher values take precedence.
   */
  virtual int getPriority() const = 0;

  /**
   * @return true if this animation is finished and false if the animation should be kept running
   */
  virtual bool isDone() const = 0;
};

#endif //AUTO_HOME_ANIMATION_H
