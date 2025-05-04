#include "bq25798.h"
#include "esphome/core/log.h"

namespace esphome {
namespace bq25798 {

static const char* TAG = "bq25798";

// BQ25798 bqlib = BQ25798();

void BQ25798Component::setup() {
  ESP_LOGCONFIG(TAG, "Setting up BQ25798...");

  //   uint16_t value;
  //   if (!this->read_byte_16(ADS1115_REGISTER_CONVERSION, &value)) {
  //     this->mark_failed();
  //     return;
  //   }
}

void BQ25798Component::loop() {}

void BQ25798Component::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798 configuration...");
  LOG_I2C_DEVICE(this);
  if (this->is_failed()) {
    ESP_LOGE(TAG, "Communication with BQ25798 failed!");
  }
}

}  // namespace bq25798
}  // namespace esphome