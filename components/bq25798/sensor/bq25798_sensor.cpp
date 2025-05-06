#include "bq25798_sensor.h"

#include "esphome/core/log.h"

namespace esphome {
namespace bq25798 {

static const char* const TAG = "bq25798.sensor";

// // float BQ25798Sensor::sample() {
// //   // return this->parent_->request_measurement(this->multiplexer_);
// // }

// void BQ25798Sensor::update() {
//   // float v = this->sample();
//   // if (!std::isnan(v)) {
//   //   ESP_LOGD(TAG, "'%s': Got Voltage=%fV", this->get_name().c_str(), v);
//   //   this->publish_state(v);
//   // }
// }

// void BQ25798Sensor::dump_config() {
//   LOG_SENSOR("  ", "BQ25798 Sensor", this);
//   // ESP_LOGCONFIG(TAG, "    Multiplexer: %u", this->multiplexer_);
//   // ESP_LOGCONFIG(TAG, "    Gain: %u", this->gain_);
//   // ESP_LOGCONFIG(TAG, "    Resolution: %u", this->resolution_);
//   // ESP_LOGCONFIG(TAG, "    Sample rate: %u", this->samplerate_);
// }

}  // namespace bq25798
}  // namespace esphome