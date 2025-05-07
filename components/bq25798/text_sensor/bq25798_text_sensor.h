#pragma once

#include "esphome/components/text_sensor/text_sensor.h"
#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

#include "../bq25798_component.h"

namespace esphome {
namespace bq25798 {

class BQ25798TextSensor : public sensor::Sensor,
                          public Component,
                          public Parented<BQ25798Component> {
 public:
 protected:
};

}  // namespace bq25798
}  // namespace esphome