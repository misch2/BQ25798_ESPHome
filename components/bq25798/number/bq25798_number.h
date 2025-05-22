
#pragma once

#include "esphome/components/number/number.h"
#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

#include "../bq25798_component.h"

namespace esphome {
namespace bq25798 {


// VSYSMIN - Minimal System Voltage
class BQ25798VsysminNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VsysminNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// VREG - Charge Voltage Limit
class BQ25798VregNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VregNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// ICHG - Charge Current Limit
class BQ25798IchgNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798IchgNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// VINDPM - Input Voltage Limit
class BQ25798VindpmNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VindpmNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// IINDPM - Input Current Limit
class BQ25798IindpmNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798IindpmNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// IPRECHG - Precharge Current Limit
class BQ25798IprechgNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798IprechgNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// ITERM - Termination Current Limit
class BQ25798ItermNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798ItermNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// VRECHG - Battery Recharge Threshold Offset (Below VREG)
class BQ25798VrechgNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VrechgNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// VOTG - OTG mode regulation voltage
class BQ25798VotgNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VotgNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// IOTG - OTG current limit
class BQ25798IotgNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798IotgNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


}  // namespace bq25798
}  // namespace esphome