#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

#include "esphome/components/binary_sensor/binary_sensor.h"

#include "../bq25798_component.h"

namespace esphome {
namespace bq25798 {

class BQ25798BinarySensor : public sensor::Sensor,
                            public Component,
                            public Parented<BQ25798Component> {
 public:
 protected:
};

}  // namespace bq25798
}  // namespace esphome