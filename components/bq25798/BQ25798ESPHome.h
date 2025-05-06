#ifndef BQ25798_ESPHOME_H
#define BQ25798_ESPHOME_H

#include "I2CESPHome.h"

#include "BQ25798Core/BQ25798Core.h"

class BQ25798ESPHome : public BQ25798Core<I2CESPHome> {
 public:
  BQ25798ESPHome() {};
};

#endif