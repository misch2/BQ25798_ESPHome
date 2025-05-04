#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

#include "esphome/components/sensor/sensor.h"
#include "esphome/components/voltage_sampler/voltage_sampler.h"

#include "../bq25798.h"

namespace esphome {
namespace bq25798 {

/// Internal holder class that is in instance of Sensor so that the hub can
/// create individual sensors.
class BQ25798Sensor : public sensor::Sensor,
                      public PollingComponent,
                      public voltage_sampler::VoltageSampler,
                      public Parented<BQ25798Component> {
 public:
  void update() override;
  //   void set_multiplexer(ADS1115Multiplexer multiplexer) { this->multiplexer_
  //   = multiplexer; }
  float sample() override;

  void dump_config() override;

 protected:
  //   ADS1115Multiplexer multiplexer_;
};

}  // namespace bq25798
}  // namespace esphome