#include "bq25798_number.h"

#include "esphome/core/log.h"

namespace esphome {
namespace bq25798 {

static const char* const TAG = "bq25798.number";


// VSYSMIN - Minimal System Voltage
float BQ25798VsysminNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VsysminNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VsysminNumber configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_NUMBER("  ", "VSYSMIN", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VsysminNumber::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  //ESP_LOGD(TAG, "Updating BQ25798VsysminNumber...");
  this->publish_state(this->parent_->get_vsysmin_int(true));
}

void BQ25798VsysminNumber::control(float new_value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VsysminNumber...");
  this->parent_->set_vsysmin_int(new_value, true);
  this->publish_state(new_value);
}




// VREG - Charge Voltage Limit
float BQ25798VregNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VregNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VregNumber configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_NUMBER("  ", "VREG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VregNumber::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  //ESP_LOGD(TAG, "Updating BQ25798VregNumber...");
  this->publish_state(this->parent_->get_vreg_int(true));
}

void BQ25798VregNumber::control(float new_value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VregNumber...");
  this->parent_->set_vreg_int(new_value, true);
  this->publish_state(new_value);
}




// ICHG - Charge Current Limit
float BQ25798IchgNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798IchgNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798IchgNumber configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_NUMBER("  ", "ICHG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798IchgNumber::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  //ESP_LOGD(TAG, "Updating BQ25798IchgNumber...");
  this->publish_state(this->parent_->get_ichg_int(true));
}

void BQ25798IchgNumber::control(float new_value) {
  //ESP_LOGD(TAG, "Controlling BQ25798IchgNumber...");
  this->parent_->set_ichg_int(new_value, true);
  this->publish_state(new_value);
}




// VINDPM - Input Voltage Limit
float BQ25798VindpmNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VindpmNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VindpmNumber configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_NUMBER("  ", "VINDPM", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VindpmNumber::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  //ESP_LOGD(TAG, "Updating BQ25798VindpmNumber...");
  this->publish_state(this->parent_->get_vindpm_int(true));
}

void BQ25798VindpmNumber::control(float new_value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VindpmNumber...");
  this->parent_->set_vindpm_int(new_value, true);
  this->publish_state(new_value);
}




// IINDPM - Input Current Limit
float BQ25798IindpmNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798IindpmNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798IindpmNumber configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_NUMBER("  ", "IINDPM", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798IindpmNumber::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  //ESP_LOGD(TAG, "Updating BQ25798IindpmNumber...");
  this->publish_state(this->parent_->get_iindpm_int(true));
}

void BQ25798IindpmNumber::control(float new_value) {
  //ESP_LOGD(TAG, "Controlling BQ25798IindpmNumber...");
  this->parent_->set_iindpm_int(new_value, true);
  this->publish_state(new_value);
}




// IPRECHG - Precharge Current Limit
float BQ25798IprechgNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798IprechgNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798IprechgNumber configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_NUMBER("  ", "IPRECHG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798IprechgNumber::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  //ESP_LOGD(TAG, "Updating BQ25798IprechgNumber...");
  this->publish_state(this->parent_->get_iprechg_int(true));
}

void BQ25798IprechgNumber::control(float new_value) {
  //ESP_LOGD(TAG, "Controlling BQ25798IprechgNumber...");
  this->parent_->set_iprechg_int(new_value, true);
  this->publish_state(new_value);
}




// ITERM - Termination Current Limit
float BQ25798ItermNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798ItermNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798ItermNumber configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_NUMBER("  ", "ITERM", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798ItermNumber::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  //ESP_LOGD(TAG, "Updating BQ25798ItermNumber...");
  this->publish_state(this->parent_->get_iterm_int(true));
}

void BQ25798ItermNumber::control(float new_value) {
  //ESP_LOGD(TAG, "Controlling BQ25798ItermNumber...");
  this->parent_->set_iterm_int(new_value, true);
  this->publish_state(new_value);
}




// VRECHG - Battery Recharge Threshold Offset (Below VREG)
float BQ25798VrechgNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VrechgNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VrechgNumber configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_NUMBER("  ", "VRECHG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VrechgNumber::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  //ESP_LOGD(TAG, "Updating BQ25798VrechgNumber...");
  this->publish_state(this->parent_->get_vrechg_int(true));
}

void BQ25798VrechgNumber::control(float new_value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VrechgNumber...");
  this->parent_->set_vrechg_int(new_value, true);
  this->publish_state(new_value);
}




// VOTG - OTG mode regulation voltage
float BQ25798VotgNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VotgNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VotgNumber configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_NUMBER("  ", "VOTG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VotgNumber::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  //ESP_LOGD(TAG, "Updating BQ25798VotgNumber...");
  this->publish_state(this->parent_->get_votg_int(true));
}

void BQ25798VotgNumber::control(float new_value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VotgNumber...");
  this->parent_->set_votg_int(new_value, true);
  this->publish_state(new_value);
}




// IOTG - OTG current limit
float BQ25798IotgNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798IotgNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798IotgNumber configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_NUMBER("  ", "IOTG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798IotgNumber::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  //ESP_LOGD(TAG, "Updating BQ25798IotgNumber...");
  this->publish_state(this->parent_->get_iotg_int(true));
}

void BQ25798IotgNumber::control(float new_value) {
  //ESP_LOGD(TAG, "Controlling BQ25798IotgNumber...");
  this->parent_->set_iotg_int(new_value, true);
  this->publish_state(new_value);
}




}  // namespace bq25798
}  // namespace esphome