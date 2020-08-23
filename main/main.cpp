/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <cstdio>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "Arduino.h"
#include "FastLED.h"

#include "../components/led/LedController.h"
#include "../components/led/LinearLedStrip.h"

CRGB leds[30];

std::unique_ptr<LedController> ledController;

void initLeds() {
  CFastLED::addLeds<NEOPIXEL, 12>(leds, 30);
  FastLED.setTemperature(Tungsten100W);

  LedController ledController1({ LinearLedStrip(Position::origin(), Direction::xPos(), 0.01f, leds, 30) });
//  ledController = std::make_unique<LedController>({ LinearLedStrip(Position::origin(), Direction::xPos(), 0.01f, leds, 30) });
}

extern "C" [[noreturn]] void app_main()
{
  initArduino();

  initLeds();
  Serial.begin(115200, SERIAL_8N1);

  Serial.printf("Hello from Arduino!\n");
  int cycle_count = 0;
  uint8_t hue = 0;

  while (true) {
    delay(33);
    ++cycle_count;

    FastLED.showColor(CHSV(++hue, 255, 255), 64);
  }
}
