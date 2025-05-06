#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

#include "esphome/components/sensor/sensor.h"

#include "../bq25798_component.h"

namespace esphome {
namespace bq25798 {

class BQ25798Sensor : public sensor::Sensor,
                      // public PollingComponent, // FIXME?
                      public Component,
                      public Parented<BQ25798Component> {
 public:
  // void update() override;
  // void dump_config() override;

 protected:
};

}  // namespace bq25798
}  // namespace esphome