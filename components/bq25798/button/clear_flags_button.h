#pragma once

#include "esphome/components/button/button.h"
#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

#include "../bq25798_component.h"

namespace esphome {
namespace bq25798 {

class ClearFlagsButton : public button::Button,
                         public Component,
                         public Parented<BQ25798Component> {
 public:
 protected:
  void press_action() override;
};

}  // namespace bq25798
}  // namespace esphome