#include "bq25798_component.h"
#include "esphome/core/log.h"
#include "esphome/core/hal.h"

namespace esphome {
namespace bq25798 {

static const char* TAG = "bq25798.component";

void BQ25798Component::setup() {
  ESP_LOGCONFIG(TAG, "Setting up BQ25798...");

  this->bq25798_noi2c_ = new BQ25798NoI2C();
  this->bq25798_noi2c_->begin(this->address_); // no-op

  int pn = get_pn_enum_int(true);
  if (pn != static_cast<int>(BQ25798NoI2C::PN_t::PN_BQ25798)) {
    ESP_LOGE(TAG, "BQ25798 chip not found at address 0x%02X. Read signature: %d", this->address_, pn);
    this->mark_failed();
    return;
  }

  int dev_rev = get_dev_rev_enum_int(true);
  if (dev_rev != static_cast<int>(BQ25798NoI2C::DEV_REV_t::DEV_REV_BQ25798)) {
    ESP_LOGE(TAG, "BQ25798 chip at address 0x%02X has unexpected device revision: %d", this->address_, dev_rev);
    this->mark_failed();
    return;
  }

  ESP_LOGCONFIG(TAG, "Resetting the chip...");
  this->set_reg_rst_bool(true, true);
  while (this->get_reg_rst_bool(true)) {
    delay(1); // wait for the chip to reset
  }
  ESP_LOGCONFIG(TAG, "Chip reset complete.");

  ESP_LOGCONFIG(TAG, "BQ25798 initialized successfully at address 0x%02X", this->address_);

  delay(1);
}

void BQ25798Component::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798 configuration...");
  LOG_I2C_DEVICE(this);
  if (this->is_failed()) {
    return;
  }
  LOG_UPDATE_INTERVAL(this);
}

float BQ25798Component::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798Component::update() {
  if (this->is_failed()) {
    return;
  }
  // Refresh watchdog timer
  this->set_wd_rst_bool(true, true);
}

// VSYSMIN - Minimal System Voltage
uint16_t BQ25798Component::get_vsysmin_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG00_Minimal_System_Voltage, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG00_Minimal_System_Voltage\") value: 0x%02X", REG00_Minimal_System_Voltage, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(6);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (6 bits) raw value: 0x%04X", raw_value);

    this->last_vsysmin_raw_ = raw_value;
  }

  return this->last_vsysmin_raw_;
}

void BQ25798Component::set_vsysmin_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vsysmin_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VSYSMIN to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG00_Minimal_System_Voltage, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG00_Minimal_System_Voltage\") value: 0x%02X", REG00_Minimal_System_Voltage,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(6) << 0);
  // ESP_LOGD(TAG, "  masked (6 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(6)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG00_Minimal_System_Voltage, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_vsysmin_int(bool read_from_i2c) {
  uint16_t raw = get_vsysmin_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VSYSMIN);
}


void BQ25798Component::set_vsysmin_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VSYSMIN to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VSYSMIN);
  this->set_vsysmin_raw(raw_value, write_to_i2c);
};


// VREG - Charge Voltage Limit
uint16_t BQ25798Component::get_vreg_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG01_Charge_Voltage_Limit, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(11);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (11 bits) raw value: 0x%04X", raw_value);

    this->last_vreg_raw_ = raw_value;
  }

  return this->last_vreg_raw_;
}

void BQ25798Component::set_vreg_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vreg_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VREG to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint16_t reg_value;
  if (!this->read_byte_16(REG01_Charge_Voltage_Limit, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 16-bit register %02X value: 0x%04X", REG01_Charge_Voltage_Limit, reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(11) << 0);
  //ESP_LOGD(TAG, "  masked register value: 0x%04X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(11)) << 0);
  //ESP_LOGD(TAG, "  new register value: 0x%04X", reg_value);

  if (!this->write_byte_16(REG01_Charge_Voltage_Limit, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_vreg_int(bool read_from_i2c) {
  uint16_t raw = get_vreg_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VREG);
}


void BQ25798Component::set_vreg_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VREG to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VREG);
  this->set_vreg_raw(raw_value, write_to_i2c);
};


// ICHG - Charge Current Limit
uint16_t BQ25798Component::get_ichg_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG03_Charge_Current_Limit, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(9);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (9 bits) raw value: 0x%04X", raw_value);

    this->last_ichg_raw_ = raw_value;
  }

  return this->last_ichg_raw_;
}

void BQ25798Component::set_ichg_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_ichg_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s ICHG to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint16_t reg_value;
  if (!this->read_byte_16(REG03_Charge_Current_Limit, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 16-bit register %02X value: 0x%04X", REG03_Charge_Current_Limit, reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(9) << 0);
  //ESP_LOGD(TAG, "  masked register value: 0x%04X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(9)) << 0);
  //ESP_LOGD(TAG, "  new register value: 0x%04X", reg_value);

  if (!this->write_byte_16(REG03_Charge_Current_Limit, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_ichg_int(bool read_from_i2c) {
  uint16_t raw = get_ichg_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ICHG);
}


void BQ25798Component::set_ichg_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting ICHG to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->ICHG);
  this->set_ichg_raw(raw_value, write_to_i2c);
};


// VINDPM - Input Voltage Limit
uint16_t BQ25798Component::get_vindpm_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG05_Input_Voltage_Limit, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG05_Input_Voltage_Limit\") value: 0x%02X", REG05_Input_Voltage_Limit, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(8);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (8 bits) raw value: 0x%04X", raw_value);

    this->last_vindpm_raw_ = raw_value;
  }

  return this->last_vindpm_raw_;
}

void BQ25798Component::set_vindpm_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vindpm_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VINDPM to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG05_Input_Voltage_Limit, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG05_Input_Voltage_Limit\") value: 0x%02X", REG05_Input_Voltage_Limit,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(8) << 0);
  // ESP_LOGD(TAG, "  masked (8 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(8)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG05_Input_Voltage_Limit, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_vindpm_int(bool read_from_i2c) {
  uint16_t raw = get_vindpm_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VINDPM);
}


void BQ25798Component::set_vindpm_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VINDPM to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VINDPM);
  this->set_vindpm_raw(raw_value, write_to_i2c);
};


// IINDPM - Input Current Limit
uint16_t BQ25798Component::get_iindpm_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG06_Input_Current_Limit, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(9);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (9 bits) raw value: 0x%04X", raw_value);

    this->last_iindpm_raw_ = raw_value;
  }

  return this->last_iindpm_raw_;
}

void BQ25798Component::set_iindpm_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_iindpm_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s IINDPM to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint16_t reg_value;
  if (!this->read_byte_16(REG06_Input_Current_Limit, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 16-bit register %02X value: 0x%04X", REG06_Input_Current_Limit, reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(9) << 0);
  //ESP_LOGD(TAG, "  masked register value: 0x%04X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(9)) << 0);
  //ESP_LOGD(TAG, "  new register value: 0x%04X", reg_value);

  if (!this->write_byte_16(REG06_Input_Current_Limit, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_iindpm_int(bool read_from_i2c) {
  uint16_t raw = get_iindpm_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->IINDPM);
}


void BQ25798Component::set_iindpm_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting IINDPM to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->IINDPM);
  this->set_iindpm_raw(raw_value, write_to_i2c);
};


// VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
uint16_t BQ25798Component::get_vbat_lowv_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG08_Precharge_Control\") value: 0x%02X", REG08_Precharge_Control, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_vbat_lowv_raw_ = raw_value;
  }

  return this->last_vbat_lowv_raw_;
}

void BQ25798Component::set_vbat_lowv_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vbat_lowv_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VBAT_LOWV to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG08_Precharge_Control\") value: 0x%02X", REG08_Precharge_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG08_Precharge_Control, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_vbat_lowv_enum_int(bool read_from_i2c) {
  uint16_t raw = get_vbat_lowv_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBAT_LOWV);
}
const char* BQ25798Component::get_vbat_lowv_enum_string(bool read_from_i2c) {
  uint16_t raw = get_vbat_lowv_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VBAT_LOWV);
}




void BQ25798Component::set_vbat_lowv_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VBAT_LOWV to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VBAT_LOWV);
  this->set_vbat_lowv_raw(raw_value, write_to_i2c);
};
// IPRECHG - Precharge Current Limit
uint16_t BQ25798Component::get_iprechg_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG08_Precharge_Control\") value: 0x%02X", REG08_Precharge_Control, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(6);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (6 bits) raw value: 0x%04X", raw_value);

    this->last_iprechg_raw_ = raw_value;
  }

  return this->last_iprechg_raw_;
}

void BQ25798Component::set_iprechg_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_iprechg_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s IPRECHG to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG08_Precharge_Control\") value: 0x%02X", REG08_Precharge_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(6) << 0);
  // ESP_LOGD(TAG, "  masked (6 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(6)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG08_Precharge_Control, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_iprechg_int(bool read_from_i2c) {
  uint16_t raw = get_iprechg_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->IPRECHG);
}


void BQ25798Component::set_iprechg_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting IPRECHG to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->IPRECHG);
  this->set_iprechg_raw(raw_value, write_to_i2c);
};


// REG_RST - Reset registers to default values and reset timer
uint16_t BQ25798Component::get_reg_rst_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_reg_rst_raw_ = raw_value;
  }

  return this->last_reg_rst_raw_;
}

void BQ25798Component::set_reg_rst_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_reg_rst_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s REG_RST to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG09_Termination_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_reg_rst_bool(bool read_from_i2c) {
  uint16_t raw = get_reg_rst_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->REG_RST);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_reg_rst_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting REG_RST to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->REG_RST);
  this->set_reg_rst_raw(raw_value, write_to_i2c);
};



// STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
uint16_t BQ25798Component::get_stop_wd_chg_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_stop_wd_chg_raw_ = raw_value;
  }

  return this->last_stop_wd_chg_raw_;
}

void BQ25798Component::set_stop_wd_chg_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_stop_wd_chg_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s STOP_WD_CHG to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG09_Termination_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_stop_wd_chg_bool(bool read_from_i2c) {
  uint16_t raw = get_stop_wd_chg_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->STOP_WD_CHG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_stop_wd_chg_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting STOP_WD_CHG to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->STOP_WD_CHG);
  this->set_stop_wd_chg_raw(raw_value, write_to_i2c);
};



// ITERM - Termination Current Limit
uint16_t BQ25798Component::get_iterm_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(5);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (5 bits) raw value: 0x%04X", raw_value);

    this->last_iterm_raw_ = raw_value;
  }

  return this->last_iterm_raw_;
}

void BQ25798Component::set_iterm_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_iterm_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s ITERM to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(5) << 0);
  // ESP_LOGD(TAG, "  masked (5 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(5)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG09_Termination_Control, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_iterm_int(bool read_from_i2c) {
  uint16_t raw = get_iterm_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ITERM);
}


void BQ25798Component::set_iterm_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting ITERM to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->ITERM);
  this->set_iterm_raw(raw_value, write_to_i2c);
};


// CELL - Battery cell count
uint16_t BQ25798Component::get_cell_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_cell_raw_ = raw_value;
  }

  return this->last_cell_raw_;
}

void BQ25798Component::set_cell_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_cell_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s CELL to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_cell_enum_int(bool read_from_i2c) {
  uint16_t raw = get_cell_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->CELL);
}
const char* BQ25798Component::get_cell_enum_string(bool read_from_i2c) {
  uint16_t raw = get_cell_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->CELL);
}




void BQ25798Component::set_cell_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting CELL to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->CELL);
  this->set_cell_raw(raw_value, write_to_i2c);
};
// TRECHG - Battery recharge delay time
uint16_t BQ25798Component::get_trechg_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_trechg_raw_ = raw_value;
  }

  return this->last_trechg_raw_;
}

void BQ25798Component::set_trechg_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_trechg_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s TRECHG to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_trechg_enum_int(bool read_from_i2c) {
  uint16_t raw = get_trechg_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TRECHG);
}
const char* BQ25798Component::get_trechg_enum_string(bool read_from_i2c) {
  uint16_t raw = get_trechg_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TRECHG);
}




void BQ25798Component::set_trechg_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting TRECHG to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->TRECHG);
  this->set_trechg_raw(raw_value, write_to_i2c);
};
// VRECHG - Battery Recharge Threshold Offset (Below VREG)
uint16_t BQ25798Component::get_vrechg_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(4);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (4 bits) raw value: 0x%04X", raw_value);

    this->last_vrechg_raw_ = raw_value;
  }

  return this->last_vrechg_raw_;
}

void BQ25798Component::set_vrechg_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vrechg_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VRECHG to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(4) << 0);
  // ESP_LOGD(TAG, "  masked (4 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(4)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_vrechg_int(bool read_from_i2c) {
  uint16_t raw = get_vrechg_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VRECHG);
}


void BQ25798Component::set_vrechg_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VRECHG to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VRECHG);
  this->set_vrechg_raw(raw_value, write_to_i2c);
};


// VOTG - OTG mode regulation voltage
uint16_t BQ25798Component::get_votg_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG0B_VOTG_regulation, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(11);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (11 bits) raw value: 0x%04X", raw_value);

    this->last_votg_raw_ = raw_value;
  }

  return this->last_votg_raw_;
}

void BQ25798Component::set_votg_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_votg_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VOTG to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint16_t reg_value;
  if (!this->read_byte_16(REG0B_VOTG_regulation, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 16-bit register %02X value: 0x%04X", REG0B_VOTG_regulation, reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(11) << 0);
  //ESP_LOGD(TAG, "  masked register value: 0x%04X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(11)) << 0);
  //ESP_LOGD(TAG, "  new register value: 0x%04X", reg_value);

  if (!this->write_byte_16(REG0B_VOTG_regulation, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_votg_int(bool read_from_i2c) {
  uint16_t raw = get_votg_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VOTG);
}


void BQ25798Component::set_votg_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VOTG to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VOTG);
  this->set_votg_raw(raw_value, write_to_i2c);
};


// PRECHG_TMR - Pre-charge safety timer setting
uint16_t BQ25798Component::get_prechg_tmr_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0D_IOTG_regulation\") value: 0x%02X", REG0D_IOTG_regulation, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_prechg_tmr_raw_ = raw_value;
  }

  return this->last_prechg_tmr_raw_;
}

void BQ25798Component::set_prechg_tmr_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_prechg_tmr_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s PRECHG_TMR to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0D_IOTG_regulation\") value: 0x%02X", REG0D_IOTG_regulation,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0D_IOTG_regulation, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_prechg_tmr_bool(bool read_from_i2c) {
  uint16_t raw = get_prechg_tmr_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PRECHG_TMR);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_prechg_tmr_enum_int(bool read_from_i2c) {
  uint16_t raw = get_prechg_tmr_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->PRECHG_TMR);
}
const char* BQ25798Component::get_prechg_tmr_enum_string(bool read_from_i2c) {
  uint16_t raw = get_prechg_tmr_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->PRECHG_TMR);
}

void BQ25798Component::set_prechg_tmr_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting PRECHG_TMR to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->PRECHG_TMR);
  this->set_prechg_tmr_raw(raw_value, write_to_i2c);
};



void BQ25798Component::set_prechg_tmr_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting PRECHG_TMR to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->PRECHG_TMR);
  this->set_prechg_tmr_raw(raw_value, write_to_i2c);
};
// IOTG - OTG current limit
uint16_t BQ25798Component::get_iotg_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0D_IOTG_regulation\") value: 0x%02X", REG0D_IOTG_regulation, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(7);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (7 bits) raw value: 0x%04X", raw_value);

    this->last_iotg_raw_ = raw_value;
  }

  return this->last_iotg_raw_;
}

void BQ25798Component::set_iotg_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_iotg_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s IOTG to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0D_IOTG_regulation\") value: 0x%02X", REG0D_IOTG_regulation,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(7) << 0);
  // ESP_LOGD(TAG, "  masked (7 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(7)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0D_IOTG_regulation, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_iotg_int(bool read_from_i2c) {
  uint16_t raw = get_iotg_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->IOTG);
}


void BQ25798Component::set_iotg_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting IOTG to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->IOTG);
  this->set_iotg_raw(raw_value, write_to_i2c);
};


// TOPOFF_TMR - Top-off timer control
uint16_t BQ25798Component::get_topoff_tmr_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_topoff_tmr_raw_ = raw_value;
  }

  return this->last_topoff_tmr_raw_;
}

void BQ25798Component::set_topoff_tmr_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_topoff_tmr_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s TOPOFF_TMR to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_topoff_tmr_enum_int(bool read_from_i2c) {
  uint16_t raw = get_topoff_tmr_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TOPOFF_TMR);
}
const char* BQ25798Component::get_topoff_tmr_enum_string(bool read_from_i2c) {
  uint16_t raw = get_topoff_tmr_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TOPOFF_TMR);
}




void BQ25798Component::set_topoff_tmr_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting TOPOFF_TMR to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->TOPOFF_TMR);
  this->set_topoff_tmr_raw(raw_value, write_to_i2c);
};
// EN_TRICHG_TMR - Trickle charge timer enable
uint16_t BQ25798Component::get_en_trichg_tmr_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_trichg_tmr_raw_ = raw_value;
  }

  return this->last_en_trichg_tmr_raw_;
}

void BQ25798Component::set_en_trichg_tmr_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_trichg_tmr_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_TRICHG_TMR to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_trichg_tmr_bool(bool read_from_i2c) {
  uint16_t raw = get_en_trichg_tmr_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_TRICHG_TMR);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_trichg_tmr_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_TRICHG_TMR to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_TRICHG_TMR);
  this->set_en_trichg_tmr_raw(raw_value, write_to_i2c);
};



// EN_PRECHG_TMR - Precharge timer enable
uint16_t BQ25798Component::get_en_prechg_tmr_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_prechg_tmr_raw_ = raw_value;
  }

  return this->last_en_prechg_tmr_raw_;
}

void BQ25798Component::set_en_prechg_tmr_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_prechg_tmr_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_PRECHG_TMR to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_prechg_tmr_bool(bool read_from_i2c) {
  uint16_t raw = get_en_prechg_tmr_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_PRECHG_TMR);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_prechg_tmr_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_PRECHG_TMR to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_PRECHG_TMR);
  this->set_en_prechg_tmr_raw(raw_value, write_to_i2c);
};



// EN_CHG_TMR - Fast charge timer enable
uint16_t BQ25798Component::get_en_chg_tmr_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_chg_tmr_raw_ = raw_value;
  }

  return this->last_en_chg_tmr_raw_;
}

void BQ25798Component::set_en_chg_tmr_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_chg_tmr_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_CHG_TMR to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_chg_tmr_bool(bool read_from_i2c) {
  uint16_t raw = get_en_chg_tmr_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_CHG_TMR);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_chg_tmr_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_CHG_TMR to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_CHG_TMR);
  this->set_en_chg_tmr_raw(raw_value, write_to_i2c);
};



// CHG_TMR - Fast charge timer setting
uint16_t BQ25798Component::get_chg_tmr_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_chg_tmr_raw_ = raw_value;
  }

  return this->last_chg_tmr_raw_;
}

void BQ25798Component::set_chg_tmr_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_chg_tmr_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s CHG_TMR to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 1) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_chg_tmr_enum_int(bool read_from_i2c) {
  uint16_t raw = get_chg_tmr_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->CHG_TMR);
}
const char* BQ25798Component::get_chg_tmr_enum_string(bool read_from_i2c) {
  uint16_t raw = get_chg_tmr_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->CHG_TMR);
}




void BQ25798Component::set_chg_tmr_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting CHG_TMR to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->CHG_TMR);
  this->set_chg_tmr_raw(raw_value, write_to_i2c);
};
// TMR2X_EN - 2x slower charging in DPM enable
uint16_t BQ25798Component::get_tmr2x_en_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_tmr2x_en_raw_ = raw_value;
  }

  return this->last_tmr2x_en_raw_;
}

void BQ25798Component::set_tmr2x_en_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_tmr2x_en_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s TMR2X_EN to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_tmr2x_en_bool(bool read_from_i2c) {
  uint16_t raw = get_tmr2x_en_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TMR2X_EN);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_tmr2x_en_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting TMR2X_EN to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->TMR2X_EN);
  this->set_tmr2x_en_raw(raw_value, write_to_i2c);
};



// EN_AUTO_IBATDIS - Enable the auto battery discharging during the battery OVP fault
uint16_t BQ25798Component::get_en_auto_ibatdis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_auto_ibatdis_raw_ = raw_value;
  }

  return this->last_en_auto_ibatdis_raw_;
}

void BQ25798Component::set_en_auto_ibatdis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_auto_ibatdis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_AUTO_IBATDIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_auto_ibatdis_bool(bool read_from_i2c) {
  uint16_t raw = get_en_auto_ibatdis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_AUTO_IBATDIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_auto_ibatdis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_AUTO_IBATDIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_AUTO_IBATDIS);
  this->set_en_auto_ibatdis_raw(raw_value, write_to_i2c);
};



// FORCE_IBATDIS - Force the battery discharging current
uint16_t BQ25798Component::get_force_ibatdis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_force_ibatdis_raw_ = raw_value;
  }

  return this->last_force_ibatdis_raw_;
}

void BQ25798Component::set_force_ibatdis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_force_ibatdis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s FORCE_IBATDIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_force_ibatdis_bool(bool read_from_i2c) {
  uint16_t raw = get_force_ibatdis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->FORCE_IBATDIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_force_ibatdis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting FORCE_IBATDIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->FORCE_IBATDIS);
  this->set_force_ibatdis_raw(raw_value, write_to_i2c);
};



// EN_CHG - Enable the charger
uint16_t BQ25798Component::get_en_chg_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_chg_raw_ = raw_value;
  }

  return this->last_en_chg_raw_;
}

void BQ25798Component::set_en_chg_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_chg_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_CHG to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_chg_bool(bool read_from_i2c) {
  uint16_t raw = get_en_chg_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_CHG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_chg_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_CHG to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_CHG);
  this->set_en_chg_raw(raw_value, write_to_i2c);
};



// EN_ICO - Enable the ICO (Input Current Optimizer)
uint16_t BQ25798Component::get_en_ico_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_ico_raw_ = raw_value;
  }

  return this->last_en_ico_raw_;
}

void BQ25798Component::set_en_ico_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_ico_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_ICO to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_ico_bool(bool read_from_i2c) {
  uint16_t raw = get_en_ico_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_ICO);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_ico_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_ICO to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_ICO);
  this->set_en_ico_raw(raw_value, write_to_i2c);
};



// FORCE_ICO - Force the ICO (Input Current Optimizer)
uint16_t BQ25798Component::get_force_ico_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_force_ico_raw_ = raw_value;
  }

  return this->last_force_ico_raw_;
}

void BQ25798Component::set_force_ico_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_force_ico_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s FORCE_ICO to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_force_ico_bool(bool read_from_i2c) {
  uint16_t raw = get_force_ico_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->FORCE_ICO);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_force_ico_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting FORCE_ICO to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->FORCE_ICO);
  this->set_force_ico_raw(raw_value, write_to_i2c);
};



// EN_HIZ - Enable the high impedance mode
uint16_t BQ25798Component::get_en_hiz_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_hiz_raw_ = raw_value;
  }

  return this->last_en_hiz_raw_;
}

void BQ25798Component::set_en_hiz_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_hiz_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_HIZ to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_hiz_bool(bool read_from_i2c) {
  uint16_t raw = get_en_hiz_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_HIZ);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_hiz_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_HIZ to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_HIZ);
  this->set_en_hiz_raw(raw_value, write_to_i2c);
};



// EN_TERM - Enable the termination
uint16_t BQ25798Component::get_en_term_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_term_raw_ = raw_value;
  }

  return this->last_en_term_raw_;
}

void BQ25798Component::set_en_term_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_term_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_TERM to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_term_bool(bool read_from_i2c) {
  uint16_t raw = get_en_term_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_TERM);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_term_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_TERM to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_TERM);
  this->set_en_term_raw(raw_value, write_to_i2c);
};



// EN_BACKUP - Enable the backup (auto OTG) mode
uint16_t BQ25798Component::get_en_backup_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_backup_raw_ = raw_value;
  }

  return this->last_en_backup_raw_;
}

void BQ25798Component::set_en_backup_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_backup_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_BACKUP to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_backup_bool(bool read_from_i2c) {
  uint16_t raw = get_en_backup_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_BACKUP);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_backup_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_BACKUP to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_BACKUP);
  this->set_en_backup_raw(raw_value, write_to_i2c);
};



// VBUS_BACKUP - The thresholds to trigger the backup mode, defined as a ratio of VINDPM
uint16_t BQ25798Component::get_vbus_backup_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_vbus_backup_raw_ = raw_value;
  }

  return this->last_vbus_backup_raw_;
}

void BQ25798Component::set_vbus_backup_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vbus_backup_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VBUS_BACKUP to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_vbus_backup_enum_int(bool read_from_i2c) {
  uint16_t raw = get_vbus_backup_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBUS_BACKUP);
}
const char* BQ25798Component::get_vbus_backup_enum_string(bool read_from_i2c) {
  uint16_t raw = get_vbus_backup_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VBUS_BACKUP);
}




void BQ25798Component::set_vbus_backup_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VBUS_BACKUP to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VBUS_BACKUP);
  this->set_vbus_backup_raw(raw_value, write_to_i2c);
};
// VAC_OVP - Over voltage protection thresholds
uint16_t BQ25798Component::get_vac_ovp_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_vac_ovp_raw_ = raw_value;
  }

  return this->last_vac_ovp_raw_;
}

void BQ25798Component::set_vac_ovp_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vac_ovp_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VAC_OVP to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_vac_ovp_enum_int(bool read_from_i2c) {
  uint16_t raw = get_vac_ovp_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VAC_OVP);
}
const char* BQ25798Component::get_vac_ovp_enum_string(bool read_from_i2c) {
  uint16_t raw = get_vac_ovp_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VAC_OVP);
}




void BQ25798Component::set_vac_ovp_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VAC_OVP to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VAC_OVP);
  this->set_vac_ovp_raw(raw_value, write_to_i2c);
};
// WD_RST - I2C watch dog timer reset
uint16_t BQ25798Component::get_wd_rst_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_wd_rst_raw_ = raw_value;
  }

  return this->last_wd_rst_raw_;
}

void BQ25798Component::set_wd_rst_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_wd_rst_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s WD_RST to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_wd_rst_bool(bool read_from_i2c) {
  uint16_t raw = get_wd_rst_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->WD_RST);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_wd_rst_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting WD_RST to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->WD_RST);
  this->set_wd_rst_raw(raw_value, write_to_i2c);
};



// WATCHDOG - Watchdog timer settings
uint16_t BQ25798Component::get_watchdog_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (3 bits) raw value: 0x%04X", raw_value);

    this->last_watchdog_raw_ = raw_value;
  }

  return this->last_watchdog_raw_;
}

void BQ25798Component::set_watchdog_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_watchdog_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s WATCHDOG to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(3) << 0);
  // ESP_LOGD(TAG, "  masked (3 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_watchdog_enum_int(bool read_from_i2c) {
  uint16_t raw = get_watchdog_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->WATCHDOG);
}
const char* BQ25798Component::get_watchdog_enum_string(bool read_from_i2c) {
  uint16_t raw = get_watchdog_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->WATCHDOG);
}




void BQ25798Component::set_watchdog_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting WATCHDOG to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->WATCHDOG);
  this->set_watchdog_raw(raw_value, write_to_i2c);
};
// FORCE_INDET - Force D+/D- detection
uint16_t BQ25798Component::get_force_indet_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_force_indet_raw_ = raw_value;
  }

  return this->last_force_indet_raw_;
}

void BQ25798Component::set_force_indet_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_force_indet_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s FORCE_INDET to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_force_indet_bool(bool read_from_i2c) {
  uint16_t raw = get_force_indet_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->FORCE_INDET);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_force_indet_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting FORCE_INDET to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->FORCE_INDET);
  this->set_force_indet_raw(raw_value, write_to_i2c);
};



// AUTO_INDET_EN - Enable automatic D+/D- detection
uint16_t BQ25798Component::get_auto_indet_en_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_auto_indet_en_raw_ = raw_value;
  }

  return this->last_auto_indet_en_raw_;
}

void BQ25798Component::set_auto_indet_en_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_auto_indet_en_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s AUTO_INDET_EN to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_auto_indet_en_bool(bool read_from_i2c) {
  uint16_t raw = get_auto_indet_en_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->AUTO_INDET_EN);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_auto_indet_en_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting AUTO_INDET_EN to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->AUTO_INDET_EN);
  this->set_auto_indet_en_raw(raw_value, write_to_i2c);
};



// EN_12V - Enable 12V output in HVDCP
uint16_t BQ25798Component::get_en_12v_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_12v_raw_ = raw_value;
  }

  return this->last_en_12v_raw_;
}

void BQ25798Component::set_en_12v_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_12v_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_12V to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_12v_bool(bool read_from_i2c) {
  uint16_t raw = get_en_12v_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_12V);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_12v_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_12V to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_12V);
  this->set_en_12v_raw(raw_value, write_to_i2c);
};



// EN_9V - Enable 9V output in HVDCP
uint16_t BQ25798Component::get_en_9v_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_9v_raw_ = raw_value;
  }

  return this->last_en_9v_raw_;
}

void BQ25798Component::set_en_9v_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_9v_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_9V to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_9v_bool(bool read_from_i2c) {
  uint16_t raw = get_en_9v_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_9V);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_9v_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_9V to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_9V);
  this->set_en_9v_raw(raw_value, write_to_i2c);
};



// HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
uint16_t BQ25798Component::get_hvdcp_en_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_hvdcp_en_raw_ = raw_value;
  }

  return this->last_hvdcp_en_raw_;
}

void BQ25798Component::set_hvdcp_en_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_hvdcp_en_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s HVDCP_EN to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_hvdcp_en_bool(bool read_from_i2c) {
  uint16_t raw = get_hvdcp_en_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->HVDCP_EN);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_hvdcp_en_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting HVDCP_EN to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->HVDCP_EN);
  this->set_hvdcp_en_raw(raw_value, write_to_i2c);
};



// SDRV_CTRL - Enable external Ship FET control
uint16_t BQ25798Component::get_sdrv_ctrl_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_sdrv_ctrl_raw_ = raw_value;
  }

  return this->last_sdrv_ctrl_raw_;
}

void BQ25798Component::set_sdrv_ctrl_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_sdrv_ctrl_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s SDRV_CTRL to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 1) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_sdrv_ctrl_enum_int(bool read_from_i2c) {
  uint16_t raw = get_sdrv_ctrl_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->SDRV_CTRL);
}
const char* BQ25798Component::get_sdrv_ctrl_enum_string(bool read_from_i2c) {
  uint16_t raw = get_sdrv_ctrl_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->SDRV_CTRL);
}




void BQ25798Component::set_sdrv_ctrl_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting SDRV_CTRL to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->SDRV_CTRL);
  this->set_sdrv_ctrl_raw(raw_value, write_to_i2c);
};
// SDRV_DLY - Delay for SDRV control
uint16_t BQ25798Component::get_sdrv_dly_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_sdrv_dly_raw_ = raw_value;
  }

  return this->last_sdrv_dly_raw_;
}

void BQ25798Component::set_sdrv_dly_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_sdrv_dly_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s SDRV_DLY to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_sdrv_dly_bool(bool read_from_i2c) {
  uint16_t raw = get_sdrv_dly_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->SDRV_DLY);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_sdrv_dly_enum_int(bool read_from_i2c) {
  uint16_t raw = get_sdrv_dly_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->SDRV_DLY);
}
const char* BQ25798Component::get_sdrv_dly_enum_string(bool read_from_i2c) {
  uint16_t raw = get_sdrv_dly_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->SDRV_DLY);
}

void BQ25798Component::set_sdrv_dly_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting SDRV_DLY to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->SDRV_DLY);
  this->set_sdrv_dly_raw(raw_value, write_to_i2c);
};



void BQ25798Component::set_sdrv_dly_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting SDRV_DLY to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->SDRV_DLY);
  this->set_sdrv_dly_raw(raw_value, write_to_i2c);
};
// DIS_ACDRV - Disable both AC1 and AC2 drivers
uint16_t BQ25798Component::get_dis_acdrv_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_dis_acdrv_raw_ = raw_value;
  }

  return this->last_dis_acdrv_raw_;
}

void BQ25798Component::set_dis_acdrv_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_dis_acdrv_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s DIS_ACDRV to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_dis_acdrv_bool(bool read_from_i2c) {
  uint16_t raw = get_dis_acdrv_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DIS_ACDRV);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dis_acdrv_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting DIS_ACDRV to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DIS_ACDRV);
  this->set_dis_acdrv_raw(raw_value, write_to_i2c);
};



// EN_OTG - Enable OTG mode
uint16_t BQ25798Component::get_en_otg_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_otg_raw_ = raw_value;
  }

  return this->last_en_otg_raw_;
}

void BQ25798Component::set_en_otg_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_otg_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_OTG to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_otg_bool(bool read_from_i2c) {
  uint16_t raw = get_en_otg_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_OTG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_otg_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_OTG to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_OTG);
  this->set_en_otg_raw(raw_value, write_to_i2c);
};



// PFM_OTG_DIS - Disable PFM in OTG mode
uint16_t BQ25798Component::get_pfm_otg_dis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_pfm_otg_dis_raw_ = raw_value;
  }

  return this->last_pfm_otg_dis_raw_;
}

void BQ25798Component::set_pfm_otg_dis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_pfm_otg_dis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s PFM_OTG_DIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_pfm_otg_dis_bool(bool read_from_i2c) {
  uint16_t raw = get_pfm_otg_dis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PFM_OTG_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_pfm_otg_dis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting PFM_OTG_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->PFM_OTG_DIS);
  this->set_pfm_otg_dis_raw(raw_value, write_to_i2c);
};



// PFM_FWD_DIS - Disable PFM in forward mode
uint16_t BQ25798Component::get_pfm_fwd_dis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_pfm_fwd_dis_raw_ = raw_value;
  }

  return this->last_pfm_fwd_dis_raw_;
}

void BQ25798Component::set_pfm_fwd_dis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_pfm_fwd_dis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s PFM_FWD_DIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_pfm_fwd_dis_bool(bool read_from_i2c) {
  uint16_t raw = get_pfm_fwd_dis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PFM_FWD_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_pfm_fwd_dis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting PFM_FWD_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->PFM_FWD_DIS);
  this->set_pfm_fwd_dis_raw(raw_value, write_to_i2c);
};



// WKUP_DLY - Wakeup (Ship FET) delay
uint16_t BQ25798Component::get_wkup_dly_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_wkup_dly_raw_ = raw_value;
  }

  return this->last_wkup_dly_raw_;
}

void BQ25798Component::set_wkup_dly_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_wkup_dly_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s WKUP_DLY to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_wkup_dly_bool(bool read_from_i2c) {
  uint16_t raw = get_wkup_dly_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->WKUP_DLY);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_wkup_dly_enum_int(bool read_from_i2c) {
  uint16_t raw = get_wkup_dly_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->WKUP_DLY);
}
const char* BQ25798Component::get_wkup_dly_enum_string(bool read_from_i2c) {
  uint16_t raw = get_wkup_dly_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->WKUP_DLY);
}

void BQ25798Component::set_wkup_dly_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting WKUP_DLY to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->WKUP_DLY);
  this->set_wkup_dly_raw(raw_value, write_to_i2c);
};



void BQ25798Component::set_wkup_dly_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting WKUP_DLY to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->WKUP_DLY);
  this->set_wkup_dly_raw(raw_value, write_to_i2c);
};
// DIS_LDO - Disable BATFET LDO mode in precharge state
uint16_t BQ25798Component::get_dis_ldo_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_dis_ldo_raw_ = raw_value;
  }

  return this->last_dis_ldo_raw_;
}

void BQ25798Component::set_dis_ldo_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_dis_ldo_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s DIS_LDO to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_dis_ldo_bool(bool read_from_i2c) {
  uint16_t raw = get_dis_ldo_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DIS_LDO);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dis_ldo_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting DIS_LDO to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DIS_LDO);
  this->set_dis_ldo_raw(raw_value, write_to_i2c);
};



// DIS_OTG_OOA - Disable OOA in OTG mode
uint16_t BQ25798Component::get_dis_otg_ooa_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_dis_otg_ooa_raw_ = raw_value;
  }

  return this->last_dis_otg_ooa_raw_;
}

void BQ25798Component::set_dis_otg_ooa_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_dis_otg_ooa_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s DIS_OTG_OOA to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_dis_otg_ooa_bool(bool read_from_i2c) {
  uint16_t raw = get_dis_otg_ooa_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DIS_OTG_OOA);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dis_otg_ooa_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting DIS_OTG_OOA to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DIS_OTG_OOA);
  this->set_dis_otg_ooa_raw(raw_value, write_to_i2c);
};



// DIS_FWD_OOA - Disable OOA in forward mode
uint16_t BQ25798Component::get_dis_fwd_ooa_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_dis_fwd_ooa_raw_ = raw_value;
  }

  return this->last_dis_fwd_ooa_raw_;
}

void BQ25798Component::set_dis_fwd_ooa_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_dis_fwd_ooa_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s DIS_FWD_OOA to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_dis_fwd_ooa_bool(bool read_from_i2c) {
  uint16_t raw = get_dis_fwd_ooa_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DIS_FWD_OOA);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dis_fwd_ooa_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting DIS_FWD_OOA to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DIS_FWD_OOA);
  this->set_dis_fwd_ooa_raw(raw_value, write_to_i2c);
};



// EN_ACDRV2 - Enable AC2 gate driver control
uint16_t BQ25798Component::get_en_acdrv2_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_acdrv2_raw_ = raw_value;
  }

  return this->last_en_acdrv2_raw_;
}

void BQ25798Component::set_en_acdrv2_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_acdrv2_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_ACDRV2 to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_acdrv2_bool(bool read_from_i2c) {
  uint16_t raw = get_en_acdrv2_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_ACDRV2);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_acdrv2_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_ACDRV2 to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_ACDRV2);
  this->set_en_acdrv2_raw(raw_value, write_to_i2c);
};



// EN_ACDRV1 - Enable AC1 gate driver control
uint16_t BQ25798Component::get_en_acdrv1_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_acdrv1_raw_ = raw_value;
  }

  return this->last_en_acdrv1_raw_;
}

void BQ25798Component::set_en_acdrv1_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_acdrv1_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_ACDRV1 to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_acdrv1_bool(bool read_from_i2c) {
  uint16_t raw = get_en_acdrv1_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_ACDRV1);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_acdrv1_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_ACDRV1 to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_ACDRV1);
  this->set_en_acdrv1_raw(raw_value, write_to_i2c);
};



// PWM_FREQ - PWM frequency setting
uint16_t BQ25798Component::get_pwm_freq_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_pwm_freq_raw_ = raw_value;
  }

  return this->last_pwm_freq_raw_;
}

void BQ25798Component::set_pwm_freq_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_pwm_freq_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s PWM_FREQ to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_pwm_freq_bool(bool read_from_i2c) {
  uint16_t raw = get_pwm_freq_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PWM_FREQ);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_pwm_freq_enum_int(bool read_from_i2c) {
  uint16_t raw = get_pwm_freq_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->PWM_FREQ);
}
const char* BQ25798Component::get_pwm_freq_enum_string(bool read_from_i2c) {
  uint16_t raw = get_pwm_freq_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->PWM_FREQ);
}

void BQ25798Component::set_pwm_freq_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting PWM_FREQ to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->PWM_FREQ);
  this->set_pwm_freq_raw(raw_value, write_to_i2c);
};



void BQ25798Component::set_pwm_freq_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting PWM_FREQ to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->PWM_FREQ);
  this->set_pwm_freq_raw(raw_value, write_to_i2c);
};
// DIS_STAT - Disable STAT pin output
uint16_t BQ25798Component::get_dis_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_dis_stat_raw_ = raw_value;
  }

  return this->last_dis_stat_raw_;
}

void BQ25798Component::set_dis_stat_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_dis_stat_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s DIS_STAT to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_dis_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_dis_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DIS_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dis_stat_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting DIS_STAT to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DIS_STAT);
  this->set_dis_stat_raw(raw_value, write_to_i2c);
};



// DIS_VSYS_SHORT - Disable VSYS short hiccup protection
uint16_t BQ25798Component::get_dis_vsys_short_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_dis_vsys_short_raw_ = raw_value;
  }

  return this->last_dis_vsys_short_raw_;
}

void BQ25798Component::set_dis_vsys_short_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_dis_vsys_short_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s DIS_VSYS_SHORT to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_dis_vsys_short_bool(bool read_from_i2c) {
  uint16_t raw = get_dis_vsys_short_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DIS_VSYS_SHORT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dis_vsys_short_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting DIS_VSYS_SHORT to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DIS_VSYS_SHORT);
  this->set_dis_vsys_short_raw(raw_value, write_to_i2c);
};



// DIS_VOTG_UVP - Disable VOTG under voltage hiccup protection
uint16_t BQ25798Component::get_dis_votg_uvp_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_dis_votg_uvp_raw_ = raw_value;
  }

  return this->last_dis_votg_uvp_raw_;
}

void BQ25798Component::set_dis_votg_uvp_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_dis_votg_uvp_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s DIS_VOTG_UVP to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_dis_votg_uvp_bool(bool read_from_i2c) {
  uint16_t raw = get_dis_votg_uvp_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DIS_VOTG_UVP);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dis_votg_uvp_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting DIS_VOTG_UVP to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DIS_VOTG_UVP);
  this->set_dis_votg_uvp_raw(raw_value, write_to_i2c);
};



// FORCE_VINDPM_DET - Force VINDPM detection (settable only when VBAT>VSYSMIN)
uint16_t BQ25798Component::get_force_vindpm_det_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_force_vindpm_det_raw_ = raw_value;
  }

  return this->last_force_vindpm_det_raw_;
}

void BQ25798Component::set_force_vindpm_det_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_force_vindpm_det_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s FORCE_VINDPM_DET to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_force_vindpm_det_bool(bool read_from_i2c) {
  uint16_t raw = get_force_vindpm_det_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->FORCE_VINDPM_DET);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_force_vindpm_det_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting FORCE_VINDPM_DET to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->FORCE_VINDPM_DET);
  this->set_force_vindpm_det_raw(raw_value, write_to_i2c);
};



// EN_IBUS_OCP - Enable input over current protection in forward mode
uint16_t BQ25798Component::get_en_ibus_ocp_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_ibus_ocp_raw_ = raw_value;
  }

  return this->last_en_ibus_ocp_raw_;
}

void BQ25798Component::set_en_ibus_ocp_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_ibus_ocp_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_IBUS_OCP to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_ibus_ocp_bool(bool read_from_i2c) {
  uint16_t raw = get_en_ibus_ocp_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_IBUS_OCP);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_ibus_ocp_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_IBUS_OCP to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_IBUS_OCP);
  this->set_en_ibus_ocp_raw(raw_value, write_to_i2c);
};



// SFET_PRESENT - Ship FET present
uint16_t BQ25798Component::get_sfet_present_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_sfet_present_raw_ = raw_value;
  }

  return this->last_sfet_present_raw_;
}

void BQ25798Component::set_sfet_present_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_sfet_present_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s SFET_PRESENT to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_sfet_present_bool(bool read_from_i2c) {
  uint16_t raw = get_sfet_present_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->SFET_PRESENT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_sfet_present_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting SFET_PRESENT to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->SFET_PRESENT);
  this->set_sfet_present_raw(raw_value, write_to_i2c);
};



// EN_IBAT - Enable battery discharge current sensing
uint16_t BQ25798Component::get_en_ibat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_ibat_raw_ = raw_value;
  }

  return this->last_en_ibat_raw_;
}

void BQ25798Component::set_en_ibat_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_ibat_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_IBAT to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_ibat_bool(bool read_from_i2c) {
  uint16_t raw = get_en_ibat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_IBAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_ibat_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_IBAT to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_IBAT);
  this->set_en_ibat_raw(raw_value, write_to_i2c);
};



// IBAT_REG - Battery discharge current regulation in OTG mode
uint16_t BQ25798Component::get_ibat_reg_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_ibat_reg_raw_ = raw_value;
  }

  return this->last_ibat_reg_raw_;
}

void BQ25798Component::set_ibat_reg_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_ibat_reg_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s IBAT_REG to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 3);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 3) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 3);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_ibat_reg_enum_int(bool read_from_i2c) {
  uint16_t raw = get_ibat_reg_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->IBAT_REG);
}
const char* BQ25798Component::get_ibat_reg_enum_string(bool read_from_i2c) {
  uint16_t raw = get_ibat_reg_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->IBAT_REG);
}




void BQ25798Component::set_ibat_reg_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting IBAT_REG to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->IBAT_REG);
  this->set_ibat_reg_raw(raw_value, write_to_i2c);
};
// EN_IINDPM - Enable input current regulation
uint16_t BQ25798Component::get_en_iindpm_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_iindpm_raw_ = raw_value;
  }

  return this->last_en_iindpm_raw_;
}

void BQ25798Component::set_en_iindpm_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_iindpm_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_IINDPM to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_iindpm_bool(bool read_from_i2c) {
  uint16_t raw = get_en_iindpm_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_IINDPM);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_iindpm_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_IINDPM to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_IINDPM);
  this->set_en_iindpm_raw(raw_value, write_to_i2c);
};



// EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
uint16_t BQ25798Component::get_en_extilim_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_extilim_raw_ = raw_value;
  }

  return this->last_en_extilim_raw_;
}

void BQ25798Component::set_en_extilim_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_extilim_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_EXTILIM to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_extilim_bool(bool read_from_i2c) {
  uint16_t raw = get_en_extilim_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_EXTILIM);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_extilim_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_EXTILIM to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_EXTILIM);
  this->set_en_extilim_raw(raw_value, write_to_i2c);
};



// EN_BATOC - Enable battery discharging over current protection
uint16_t BQ25798Component::get_en_batoc_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_batoc_raw_ = raw_value;
  }

  return this->last_en_batoc_raw_;
}

void BQ25798Component::set_en_batoc_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_batoc_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_BATOC to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_batoc_bool(bool read_from_i2c) {
  uint16_t raw = get_en_batoc_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_BATOC);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_batoc_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_BATOC to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_BATOC);
  this->set_en_batoc_raw(raw_value, write_to_i2c);
};



// VOC_PCT - Set VINDPM as a percentage of the VBUS open circuit voltage when the VOC measurement is done
uint16_t BQ25798Component::get_voc_pct_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);

    this->last_voc_pct_raw_ = raw_value;
  }

  return this->last_voc_pct_raw_;
}

void BQ25798Component::set_voc_pct_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_voc_pct_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VOC_PCT to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
  // ESP_LOGD(TAG, "  masked (3 bits shifted by 5) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_voc_pct_enum_int(bool read_from_i2c) {
  uint16_t raw = get_voc_pct_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VOC_PCT);
}
const char* BQ25798Component::get_voc_pct_enum_string(bool read_from_i2c) {
  uint16_t raw = get_voc_pct_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VOC_PCT);
}




void BQ25798Component::set_voc_pct_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VOC_PCT to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VOC_PCT);
  this->set_voc_pct_raw(raw_value, write_to_i2c);
};
// VOC_DLY - After the converter stops switching, the time delay before the VOC is measured
uint16_t BQ25798Component::get_voc_dly_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_voc_dly_raw_ = raw_value;
  }

  return this->last_voc_dly_raw_;
}

void BQ25798Component::set_voc_dly_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_voc_dly_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VOC_DLY to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_voc_dly_enum_int(bool read_from_i2c) {
  uint16_t raw = get_voc_dly_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VOC_DLY);
}
const char* BQ25798Component::get_voc_dly_enum_string(bool read_from_i2c) {
  uint16_t raw = get_voc_dly_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VOC_DLY);
}




void BQ25798Component::set_voc_dly_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VOC_DLY to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VOC_DLY);
  this->set_voc_dly_raw(raw_value, write_to_i2c);
};
// VOC_RATE - The time interval between two consecutive VOC measurements
uint16_t BQ25798Component::get_voc_rate_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_voc_rate_raw_ = raw_value;
  }

  return this->last_voc_rate_raw_;
}

void BQ25798Component::set_voc_rate_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_voc_rate_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VOC_RATE to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 2);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 2) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 2);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_voc_rate_enum_int(bool read_from_i2c) {
  uint16_t raw = get_voc_rate_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VOC_RATE);
}
const char* BQ25798Component::get_voc_rate_enum_string(bool read_from_i2c) {
  uint16_t raw = get_voc_rate_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VOC_RATE);
}




void BQ25798Component::set_voc_rate_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VOC_RATE to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VOC_RATE);
  this->set_voc_rate_raw(raw_value, write_to_i2c);
};
// EN_MPPT - Enable MPPT (Maximum Power Point Tracking)
uint16_t BQ25798Component::get_en_mppt_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_en_mppt_raw_ = raw_value;
  }

  return this->last_en_mppt_raw_;
}

void BQ25798Component::set_en_mppt_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_en_mppt_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s EN_MPPT to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_mppt_bool(bool read_from_i2c) {
  uint16_t raw = get_en_mppt_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_MPPT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_mppt_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting EN_MPPT to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_MPPT);
  this->set_en_mppt_raw(raw_value, write_to_i2c);
};



// TREG - Thermal regulation thresholds
uint16_t BQ25798Component::get_treg_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_treg_raw_ = raw_value;
  }

  return this->last_treg_raw_;
}

void BQ25798Component::set_treg_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_treg_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s TREG to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_treg_enum_int(bool read_from_i2c) {
  uint16_t raw = get_treg_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TREG);
}
const char* BQ25798Component::get_treg_enum_string(bool read_from_i2c) {
  uint16_t raw = get_treg_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TREG);
}




void BQ25798Component::set_treg_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting TREG to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->TREG);
  this->set_treg_raw(raw_value, write_to_i2c);
};
// TSHUT - Thermal shutdown thresholds
uint16_t BQ25798Component::get_tshut_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_tshut_raw_ = raw_value;
  }

  return this->last_tshut_raw_;
}

void BQ25798Component::set_tshut_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_tshut_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s TSHUT to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_tshut_enum_int(bool read_from_i2c) {
  uint16_t raw = get_tshut_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TSHUT);
}
const char* BQ25798Component::get_tshut_enum_string(bool read_from_i2c) {
  uint16_t raw = get_tshut_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TSHUT);
}




void BQ25798Component::set_tshut_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting TSHUT to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->TSHUT);
  this->set_tshut_raw(raw_value, write_to_i2c);
};
// VBUS_PD_EN - Enable VBUS pull down resistor (6 kOhm)
uint16_t BQ25798Component::get_vbus_pd_en_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vbus_pd_en_raw_ = raw_value;
  }

  return this->last_vbus_pd_en_raw_;
}

void BQ25798Component::set_vbus_pd_en_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vbus_pd_en_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VBUS_PD_EN to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_vbus_pd_en_bool(bool read_from_i2c) {
  uint16_t raw = get_vbus_pd_en_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBUS_PD_EN);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vbus_pd_en_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VBUS_PD_EN to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VBUS_PD_EN);
  this->set_vbus_pd_en_raw(raw_value, write_to_i2c);
};



// VAC1_PD_EN - Enable VAC1 pull down resistor
uint16_t BQ25798Component::get_vac1_pd_en_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vac1_pd_en_raw_ = raw_value;
  }

  return this->last_vac1_pd_en_raw_;
}

void BQ25798Component::set_vac1_pd_en_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vac1_pd_en_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VAC1_PD_EN to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_vac1_pd_en_bool(bool read_from_i2c) {
  uint16_t raw = get_vac1_pd_en_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC1_PD_EN);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vac1_pd_en_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VAC1_PD_EN to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VAC1_PD_EN);
  this->set_vac1_pd_en_raw(raw_value, write_to_i2c);
};



// VAC2_PD_EN - Enable VAC2 pull down resistor
uint16_t BQ25798Component::get_vac2_pd_en_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vac2_pd_en_raw_ = raw_value;
  }

  return this->last_vac2_pd_en_raw_;
}

void BQ25798Component::set_vac2_pd_en_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vac2_pd_en_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VAC2_PD_EN to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_vac2_pd_en_bool(bool read_from_i2c) {
  uint16_t raw = get_vac2_pd_en_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC2_PD_EN);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vac2_pd_en_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VAC2_PD_EN to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VAC2_PD_EN);
  this->set_vac2_pd_en_raw(raw_value, write_to_i2c);
};



// BKUP_ACFET1_ON - Enable ACFET1 in backup mode (exit backup mode)
uint16_t BQ25798Component::get_bkup_acfet1_on_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_bkup_acfet1_on_raw_ = raw_value;
  }

  return this->last_bkup_acfet1_on_raw_;
}

void BQ25798Component::set_bkup_acfet1_on_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_bkup_acfet1_on_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s BKUP_ACFET1_ON to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_bkup_acfet1_on_bool(bool read_from_i2c) {
  uint16_t raw = get_bkup_acfet1_on_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->BKUP_ACFET1_ON);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_bkup_acfet1_on_enum_int(bool read_from_i2c) {
  uint16_t raw = get_bkup_acfet1_on_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->BKUP_ACFET1_ON);
}
const char* BQ25798Component::get_bkup_acfet1_on_enum_string(bool read_from_i2c) {
  uint16_t raw = get_bkup_acfet1_on_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->BKUP_ACFET1_ON);
}

void BQ25798Component::set_bkup_acfet1_on_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting BKUP_ACFET1_ON to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->BKUP_ACFET1_ON);
  this->set_bkup_acfet1_on_raw(raw_value, write_to_i2c);
};



void BQ25798Component::set_bkup_acfet1_on_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting BKUP_ACFET1_ON to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->BKUP_ACFET1_ON);
  this->set_bkup_acfet1_on_raw(raw_value, write_to_i2c);
};
// JEITA_VSET - JEITA high temperature range (TWARN - THOT) charge voltage setting
uint16_t BQ25798Component::get_jeita_vset_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);

    this->last_jeita_vset_raw_ = raw_value;
  }

  return this->last_jeita_vset_raw_;
}

void BQ25798Component::set_jeita_vset_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_jeita_vset_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s JEITA_VSET to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
  // ESP_LOGD(TAG, "  masked (3 bits shifted by 5) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_jeita_vset_enum_int(bool read_from_i2c) {
  uint16_t raw = get_jeita_vset_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->JEITA_VSET);
}
const char* BQ25798Component::get_jeita_vset_enum_string(bool read_from_i2c) {
  uint16_t raw = get_jeita_vset_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->JEITA_VSET);
}




void BQ25798Component::set_jeita_vset_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting JEITA_VSET to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->JEITA_VSET);
  this->set_jeita_vset_raw(raw_value, write_to_i2c);
};
// JEITA_ISETH - JEITA high temperature range (TWARN - THOT) charge current setting
uint16_t BQ25798Component::get_jeita_iseth_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_jeita_iseth_raw_ = raw_value;
  }

  return this->last_jeita_iseth_raw_;
}

void BQ25798Component::set_jeita_iseth_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_jeita_iseth_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s JEITA_ISETH to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 3);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 3) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 3);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_jeita_iseth_enum_int(bool read_from_i2c) {
  uint16_t raw = get_jeita_iseth_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->JEITA_ISETH);
}
const char* BQ25798Component::get_jeita_iseth_enum_string(bool read_from_i2c) {
  uint16_t raw = get_jeita_iseth_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->JEITA_ISETH);
}




void BQ25798Component::set_jeita_iseth_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting JEITA_ISETH to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->JEITA_ISETH);
  this->set_jeita_iseth_raw(raw_value, write_to_i2c);
};
// JEITA_ISETC - JEITA low temperature range (TCOLD - TWARN) charge current setting
uint16_t BQ25798Component::get_jeita_isetc_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_jeita_isetc_raw_ = raw_value;
  }

  return this->last_jeita_isetc_raw_;
}

void BQ25798Component::set_jeita_isetc_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_jeita_isetc_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s JEITA_ISETC to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 1) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_jeita_isetc_enum_int(bool read_from_i2c) {
  uint16_t raw = get_jeita_isetc_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->JEITA_ISETC);
}
const char* BQ25798Component::get_jeita_isetc_enum_string(bool read_from_i2c) {
  uint16_t raw = get_jeita_isetc_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->JEITA_ISETC);
}




void BQ25798Component::set_jeita_isetc_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting JEITA_ISETC to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->JEITA_ISETC);
  this->set_jeita_isetc_raw(raw_value, write_to_i2c);
};
// TS_COOL - JEITA VT2 comparator voltage rising thresholds as a percentage of REGN.
uint16_t BQ25798Component::get_ts_cool_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_ts_cool_raw_ = raw_value;
  }

  return this->last_ts_cool_raw_;
}

void BQ25798Component::set_ts_cool_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_ts_cool_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s TS_COOL to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_ts_cool_enum_int(bool read_from_i2c) {
  uint16_t raw = get_ts_cool_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TS_COOL);
}
const char* BQ25798Component::get_ts_cool_enum_string(bool read_from_i2c) {
  uint16_t raw = get_ts_cool_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TS_COOL);
}




void BQ25798Component::set_ts_cool_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting TS_COOL to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->TS_COOL);
  this->set_ts_cool_raw(raw_value, write_to_i2c);
};
// TS_WARM - JEITA VT3 comparator voltage falling thresholds as a percentage of REGN.
uint16_t BQ25798Component::get_ts_warm_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_ts_warm_raw_ = raw_value;
  }

  return this->last_ts_warm_raw_;
}

void BQ25798Component::set_ts_warm_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_ts_warm_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s TS_WARM to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_ts_warm_enum_int(bool read_from_i2c) {
  uint16_t raw = get_ts_warm_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TS_WARM);
}
const char* BQ25798Component::get_ts_warm_enum_string(bool read_from_i2c) {
  uint16_t raw = get_ts_warm_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TS_WARM);
}




void BQ25798Component::set_ts_warm_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting TS_WARM to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->TS_WARM);
  this->set_ts_warm_raw(raw_value, write_to_i2c);
};
// BHOT - OTG mode TS HOT temperature threshold
uint16_t BQ25798Component::get_bhot_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_bhot_raw_ = raw_value;
  }

  return this->last_bhot_raw_;
}

void BQ25798Component::set_bhot_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_bhot_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s BHOT to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 2);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 2) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 2);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_bhot_enum_int(bool read_from_i2c) {
  uint16_t raw = get_bhot_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->BHOT);
}
const char* BQ25798Component::get_bhot_enum_string(bool read_from_i2c) {
  uint16_t raw = get_bhot_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->BHOT);
}




void BQ25798Component::set_bhot_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting BHOT to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->BHOT);
  this->set_bhot_raw(raw_value, write_to_i2c);
};
// BCOLD - OTG mode TS COLD temperature threshold
uint16_t BQ25798Component::get_bcold_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_bcold_raw_ = raw_value;
  }

  return this->last_bcold_raw_;
}

void BQ25798Component::set_bcold_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_bcold_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s BCOLD to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_bcold_bool(bool read_from_i2c) {
  uint16_t raw = get_bcold_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->BCOLD);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_bcold_enum_int(bool read_from_i2c) {
  uint16_t raw = get_bcold_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->BCOLD);
}
const char* BQ25798Component::get_bcold_enum_string(bool read_from_i2c) {
  uint16_t raw = get_bcold_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->BCOLD);
}

void BQ25798Component::set_bcold_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting BCOLD to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->BCOLD);
  this->set_bcold_raw(raw_value, write_to_i2c);
};



void BQ25798Component::set_bcold_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting BCOLD to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->BCOLD);
  this->set_bcold_raw(raw_value, write_to_i2c);
};
// TS_IGNORE - Ignore TS detection (the charger considers the TS is always good)
uint16_t BQ25798Component::get_ts_ignore_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ts_ignore_raw_ = raw_value;
  }

  return this->last_ts_ignore_raw_;
}

void BQ25798Component::set_ts_ignore_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_ts_ignore_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s TS_IGNORE to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_ts_ignore_bool(bool read_from_i2c) {
  uint16_t raw = get_ts_ignore_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_IGNORE);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_ts_ignore_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting TS_IGNORE to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->TS_IGNORE);
  this->set_ts_ignore_raw(raw_value, write_to_i2c);
};



// ICO_ILIM - Input Current Limit obtained from ICO or ILIM_HIZ pin setting
uint16_t BQ25798Component::get_ico_ilim_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG19_ICO_Current_Limit, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(9);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (9 bits) raw value: 0x%04X", raw_value);

    this->last_ico_ilim_raw_ = raw_value;
  }

  return this->last_ico_ilim_raw_;
}


int BQ25798Component::get_ico_ilim_int(bool read_from_i2c) {
  uint16_t raw = get_ico_ilim_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ICO_ILIM);
}

// IINDPM_STAT - IINDPM status (forward mode) or IOTG status (OTG mode)
uint16_t BQ25798Component::get_iindpm_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_iindpm_stat_raw_ = raw_value;
  }

  return this->last_iindpm_stat_raw_;
}


bool BQ25798Component::get_iindpm_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_iindpm_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IINDPM_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_iindpm_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_iindpm_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->IINDPM_STAT);
}
const char* BQ25798Component::get_iindpm_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_iindpm_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->IINDPM_STAT);
}

// VINDPM_STAT - VINDPM status (forward mode) or VOTG status (OTG mode)
uint16_t BQ25798Component::get_vindpm_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vindpm_stat_raw_ = raw_value;
  }

  return this->last_vindpm_stat_raw_;
}


bool BQ25798Component::get_vindpm_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_vindpm_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VINDPM_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_vindpm_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_vindpm_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VINDPM_STAT);
}
const char* BQ25798Component::get_vindpm_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_vindpm_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VINDPM_STAT);
}

// WD_STAT - Watchdog timer status
uint16_t BQ25798Component::get_wd_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_wd_stat_raw_ = raw_value;
  }

  return this->last_wd_stat_raw_;
}


bool BQ25798Component::get_wd_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_wd_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->WD_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_wd_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_wd_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->WD_STAT);
}
const char* BQ25798Component::get_wd_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_wd_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->WD_STAT);
}

// PG_STAT - Power good status
uint16_t BQ25798Component::get_pg_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_pg_stat_raw_ = raw_value;
  }

  return this->last_pg_stat_raw_;
}


bool BQ25798Component::get_pg_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_pg_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PG_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_pg_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_pg_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->PG_STAT);
}
const char* BQ25798Component::get_pg_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_pg_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->PG_STAT);
}

// AC2_PRESENT_STAT - VAC2 present status
uint16_t BQ25798Component::get_ac2_present_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ac2_present_stat_raw_ = raw_value;
  }

  return this->last_ac2_present_stat_raw_;
}


bool BQ25798Component::get_ac2_present_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_ac2_present_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->AC2_PRESENT_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_ac2_present_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_ac2_present_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->AC2_PRESENT_STAT);
}
const char* BQ25798Component::get_ac2_present_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_ac2_present_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->AC2_PRESENT_STAT);
}

// AC1_PRESENT_STAT - VAC1 present status
uint16_t BQ25798Component::get_ac1_present_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ac1_present_stat_raw_ = raw_value;
  }

  return this->last_ac1_present_stat_raw_;
}


bool BQ25798Component::get_ac1_present_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_ac1_present_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->AC1_PRESENT_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_ac1_present_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_ac1_present_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->AC1_PRESENT_STAT);
}
const char* BQ25798Component::get_ac1_present_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_ac1_present_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->AC1_PRESENT_STAT);
}

// VBUS_PRESENT_STAT - VBUS present status
uint16_t BQ25798Component::get_vbus_present_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vbus_present_stat_raw_ = raw_value;
  }

  return this->last_vbus_present_stat_raw_;
}


bool BQ25798Component::get_vbus_present_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_vbus_present_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBUS_PRESENT_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_vbus_present_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_vbus_present_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBUS_PRESENT_STAT);
}
const char* BQ25798Component::get_vbus_present_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_vbus_present_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VBUS_PRESENT_STAT);
}

// CHG_STAT - Charge Status bits
uint16_t BQ25798Component::get_chg_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1C_Charger_Status_1\") value: 0x%02X", REG1C_Charger_Status_1, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);

    this->last_chg_stat_raw_ = raw_value;
  }

  return this->last_chg_stat_raw_;
}


int BQ25798Component::get_chg_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_chg_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->CHG_STAT);
}
const char* BQ25798Component::get_chg_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_chg_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->CHG_STAT);
}

// VBUS_STAT - VBUS status bits
uint16_t BQ25798Component::get_vbus_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1C_Charger_Status_1\") value: 0x%02X", REG1C_Charger_Status_1, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(4);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (4 bits) raw value: 0x%04X", raw_value);

    this->last_vbus_stat_raw_ = raw_value;
  }

  return this->last_vbus_stat_raw_;
}


int BQ25798Component::get_vbus_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_vbus_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBUS_STAT);
}
const char* BQ25798Component::get_vbus_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_vbus_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VBUS_STAT);
}

// BC12_DONE_STAT - BC1.2 detection done status
uint16_t BQ25798Component::get_bc12_done_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1C_Charger_Status_1\") value: 0x%02X", REG1C_Charger_Status_1, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_bc12_done_stat_raw_ = raw_value;
  }

  return this->last_bc12_done_stat_raw_;
}


bool BQ25798Component::get_bc12_done_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_bc12_done_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->BC12_DONE_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// ICO_STAT - Input Current Optimizer (ICO) status
uint16_t BQ25798Component::get_ico_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1D_Charger_Status_2\") value: 0x%02X", REG1D_Charger_Status_2, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_ico_stat_raw_ = raw_value;
  }

  return this->last_ico_stat_raw_;
}


int BQ25798Component::get_ico_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_ico_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ICO_STAT);
}
const char* BQ25798Component::get_ico_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_ico_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->ICO_STAT);
}

// TREG_STAT - IC thermal regulation status
uint16_t BQ25798Component::get_treg_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1D_Charger_Status_2\") value: 0x%02X", REG1D_Charger_Status_2, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_treg_stat_raw_ = raw_value;
  }

  return this->last_treg_stat_raw_;
}


bool BQ25798Component::get_treg_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_treg_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TREG_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_treg_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_treg_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TREG_STAT);
}
const char* BQ25798Component::get_treg_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_treg_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TREG_STAT);
}

// DPDM_STAT - D+/D- detection status
uint16_t BQ25798Component::get_dpdm_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1D_Charger_Status_2\") value: 0x%02X", REG1D_Charger_Status_2, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_dpdm_stat_raw_ = raw_value;
  }

  return this->last_dpdm_stat_raw_;
}


bool BQ25798Component::get_dpdm_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_dpdm_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DPDM_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_dpdm_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_dpdm_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->DPDM_STAT);
}
const char* BQ25798Component::get_dpdm_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_dpdm_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->DPDM_STAT);
}

// VBAT_PRESENT_STAT - Battery present status
uint16_t BQ25798Component::get_vbat_present_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1D_Charger_Status_2\") value: 0x%02X", REG1D_Charger_Status_2, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vbat_present_stat_raw_ = raw_value;
  }

  return this->last_vbat_present_stat_raw_;
}


bool BQ25798Component::get_vbat_present_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_vbat_present_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBAT_PRESENT_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_vbat_present_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_vbat_present_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBAT_PRESENT_STAT);
}
const char* BQ25798Component::get_vbat_present_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_vbat_present_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VBAT_PRESENT_STAT);
}

// ACRB2_STAT - The ACFET2-RBFET2 status
uint16_t BQ25798Component::get_acrb2_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_acrb2_stat_raw_ = raw_value;
  }

  return this->last_acrb2_stat_raw_;
}


bool BQ25798Component::get_acrb2_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_acrb2_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ACRB2_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_acrb2_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_acrb2_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ACRB2_STAT);
}
const char* BQ25798Component::get_acrb2_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_acrb2_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->ACRB2_STAT);
}

// ACRB1_STAT - The ACFET1-RBFET1 status
uint16_t BQ25798Component::get_acrb1_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_acrb1_stat_raw_ = raw_value;
  }

  return this->last_acrb1_stat_raw_;
}


bool BQ25798Component::get_acrb1_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_acrb1_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ACRB1_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_acrb1_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_acrb1_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ACRB1_STAT);
}
const char* BQ25798Component::get_acrb1_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_acrb1_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->ACRB1_STAT);
}

// ADC_DONE_STAT - ADC Conversion Status
uint16_t BQ25798Component::get_adc_done_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_adc_done_stat_raw_ = raw_value;
  }

  return this->last_adc_done_stat_raw_;
}


bool BQ25798Component::get_adc_done_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_adc_done_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ADC_DONE_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VSYS_STAT - VSYS Regulation Status
uint16_t BQ25798Component::get_vsys_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vsys_stat_raw_ = raw_value;
  }

  return this->last_vsys_stat_raw_;
}


bool BQ25798Component::get_vsys_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_vsys_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VSYS_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_vsys_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_vsys_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VSYS_STAT);
}
const char* BQ25798Component::get_vsys_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_vsys_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VSYS_STAT);
}

// CHG_TMR_STAT - Fast charge timer status
uint16_t BQ25798Component::get_chg_tmr_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_chg_tmr_stat_raw_ = raw_value;
  }

  return this->last_chg_tmr_stat_raw_;
}


bool BQ25798Component::get_chg_tmr_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_chg_tmr_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->CHG_TMR_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_chg_tmr_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_chg_tmr_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->CHG_TMR_STAT);
}
const char* BQ25798Component::get_chg_tmr_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_chg_tmr_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->CHG_TMR_STAT);
}

// TRICHG_TMR_STAT - Trickle charge timer status
uint16_t BQ25798Component::get_trichg_tmr_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_trichg_tmr_stat_raw_ = raw_value;
  }

  return this->last_trichg_tmr_stat_raw_;
}


bool BQ25798Component::get_trichg_tmr_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_trichg_tmr_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TRICHG_TMR_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_trichg_tmr_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_trichg_tmr_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TRICHG_TMR_STAT);
}
const char* BQ25798Component::get_trichg_tmr_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_trichg_tmr_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TRICHG_TMR_STAT);
}

// PRECHG_TMR_STAT - Pre-charge timer status
uint16_t BQ25798Component::get_prechg_tmr_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_prechg_tmr_stat_raw_ = raw_value;
  }

  return this->last_prechg_tmr_stat_raw_;
}


bool BQ25798Component::get_prechg_tmr_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_prechg_tmr_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PRECHG_TMR_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_prechg_tmr_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_prechg_tmr_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->PRECHG_TMR_STAT);
}
const char* BQ25798Component::get_prechg_tmr_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_prechg_tmr_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->PRECHG_TMR_STAT);
}

// VBATOTG_LOW_STAT - VBAT too low to enable OTG flag
uint16_t BQ25798Component::get_vbatotg_low_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vbatotg_low_stat_raw_ = raw_value;
  }

  return this->last_vbatotg_low_stat_raw_;
}


bool BQ25798Component::get_vbatotg_low_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_vbatotg_low_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBATOTG_LOW_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_vbatotg_low_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_vbatotg_low_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBATOTG_LOW_STAT);
}
const char* BQ25798Component::get_vbatotg_low_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_vbatotg_low_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VBATOTG_LOW_STAT);
}

// TS_COLD_STAT - The TS temperature is in the cold range
uint16_t BQ25798Component::get_ts_cold_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ts_cold_stat_raw_ = raw_value;
  }

  return this->last_ts_cold_stat_raw_;
}


bool BQ25798Component::get_ts_cold_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_ts_cold_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_COLD_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_ts_cold_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_ts_cold_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TS_COLD_STAT);
}
const char* BQ25798Component::get_ts_cold_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_ts_cold_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TS_COLD_STAT);
}

// TS_COOL_STAT - The TS temperature is in the cool range
uint16_t BQ25798Component::get_ts_cool_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ts_cool_stat_raw_ = raw_value;
  }

  return this->last_ts_cool_stat_raw_;
}


bool BQ25798Component::get_ts_cool_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_ts_cool_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_COOL_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_ts_cool_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_ts_cool_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TS_COOL_STAT);
}
const char* BQ25798Component::get_ts_cool_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_ts_cool_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TS_COOL_STAT);
}

// TS_WARM_STAT - The TS temperature is in the warm range
uint16_t BQ25798Component::get_ts_warm_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ts_warm_stat_raw_ = raw_value;
  }

  return this->last_ts_warm_stat_raw_;
}


bool BQ25798Component::get_ts_warm_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_ts_warm_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_WARM_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_ts_warm_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_ts_warm_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TS_WARM_STAT);
}
const char* BQ25798Component::get_ts_warm_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_ts_warm_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TS_WARM_STAT);
}

// TS_HOT_STAT - The TS temperature is in the hot range
uint16_t BQ25798Component::get_ts_hot_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ts_hot_stat_raw_ = raw_value;
  }

  return this->last_ts_hot_stat_raw_;
}


bool BQ25798Component::get_ts_hot_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_ts_hot_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_HOT_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_ts_hot_stat_enum_int(bool read_from_i2c) {
  uint16_t raw = get_ts_hot_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TS_HOT_STAT);
}
const char* BQ25798Component::get_ts_hot_stat_enum_string(bool read_from_i2c) {
  uint16_t raw = get_ts_hot_stat_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TS_HOT_STAT);
}

// IBAT_REG_STAT - In battery discharging current regulation
uint16_t BQ25798Component::get_ibat_reg_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ibat_reg_stat_raw_ = raw_value;
  }

  return this->last_ibat_reg_stat_raw_;
}


bool BQ25798Component::get_ibat_reg_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_ibat_reg_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBAT_REG_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VBUS_OVP_STAT - VBUS over-voltage status
uint16_t BQ25798Component::get_vbus_ovp_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vbus_ovp_stat_raw_ = raw_value;
  }

  return this->last_vbus_ovp_stat_raw_;
}


bool BQ25798Component::get_vbus_ovp_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_vbus_ovp_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBUS_OVP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VBAT_OVP_STAT - VBAT over-voltage status
uint16_t BQ25798Component::get_vbat_ovp_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vbat_ovp_stat_raw_ = raw_value;
  }

  return this->last_vbat_ovp_stat_raw_;
}


bool BQ25798Component::get_vbat_ovp_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_vbat_ovp_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBAT_OVP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// IBUS_OCP_STAT - IBUS over-current status
uint16_t BQ25798Component::get_ibus_ocp_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ibus_ocp_stat_raw_ = raw_value;
  }

  return this->last_ibus_ocp_stat_raw_;
}


bool BQ25798Component::get_ibus_ocp_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_ibus_ocp_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBUS_OCP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// IBAT_OCP_STAT - IBAT over-current status
uint16_t BQ25798Component::get_ibat_ocp_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ibat_ocp_stat_raw_ = raw_value;
  }

  return this->last_ibat_ocp_stat_raw_;
}


bool BQ25798Component::get_ibat_ocp_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_ibat_ocp_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBAT_OCP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// CONV_OCP_STAT - Converter over-current status
uint16_t BQ25798Component::get_conv_ocp_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_conv_ocp_stat_raw_ = raw_value;
  }

  return this->last_conv_ocp_stat_raw_;
}


bool BQ25798Component::get_conv_ocp_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_conv_ocp_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->CONV_OCP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VAC2_OVP_STAT - VAC2 over-voltage status
uint16_t BQ25798Component::get_vac2_ovp_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vac2_ovp_stat_raw_ = raw_value;
  }

  return this->last_vac2_ovp_stat_raw_;
}


bool BQ25798Component::get_vac2_ovp_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_vac2_ovp_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC2_OVP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VAC1_OVP_STAT - VAC1 over-voltage status
uint16_t BQ25798Component::get_vac1_ovp_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vac1_ovp_stat_raw_ = raw_value;
  }

  return this->last_vac1_ovp_stat_raw_;
}


bool BQ25798Component::get_vac1_ovp_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_vac1_ovp_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC1_OVP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VSYS_SHORT_STAT - VSYS short circuit status
uint16_t BQ25798Component::get_vsys_short_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vsys_short_stat_raw_ = raw_value;
  }

  return this->last_vsys_short_stat_raw_;
}


bool BQ25798Component::get_vsys_short_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_vsys_short_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VSYS_SHORT_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VSYS_OVP_STAT - VSYS over-voltage status
uint16_t BQ25798Component::get_vsys_ovp_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vsys_ovp_stat_raw_ = raw_value;
  }

  return this->last_vsys_ovp_stat_raw_;
}


bool BQ25798Component::get_vsys_ovp_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_vsys_ovp_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VSYS_OVP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// OTG_OVP_STAT - OTG over-voltage status
uint16_t BQ25798Component::get_otg_ovp_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_otg_ovp_stat_raw_ = raw_value;
  }

  return this->last_otg_ovp_stat_raw_;
}


bool BQ25798Component::get_otg_ovp_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_otg_ovp_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->OTG_OVP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// OTG_UVP_STAT - OTG under-voltage status
uint16_t BQ25798Component::get_otg_uvp_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_otg_uvp_stat_raw_ = raw_value;
  }

  return this->last_otg_uvp_stat_raw_;
}


bool BQ25798Component::get_otg_uvp_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_otg_uvp_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->OTG_UVP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// TSHUT_STAT - IC thermal shutdown status
uint16_t BQ25798Component::get_tshut_stat_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_tshut_stat_raw_ = raw_value;
  }

  return this->last_tshut_stat_raw_;
}


bool BQ25798Component::get_tshut_stat_bool(bool read_from_i2c) {
  uint16_t raw = get_tshut_stat_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TSHUT_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// IINDPM_FLAG - In IINDPM / IOTG regulation
uint16_t BQ25798Component::get_iindpm_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_iindpm_flag_raw_ = raw_value;
  }

  return this->last_iindpm_flag_raw_;
}


bool BQ25798Component::get_iindpm_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_iindpm_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IINDPM_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_iindpm_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VINDPM_FLAG - In VINDPM / VOTG regulation
uint16_t BQ25798Component::get_vindpm_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vindpm_flag_raw_ = raw_value;
  }

  return this->last_vindpm_flag_raw_;
}


bool BQ25798Component::get_vindpm_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_vindpm_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VINDPM_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_vindpm_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// WD_FLAG - Watchdog timer expired
uint16_t BQ25798Component::get_wd_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_wd_flag_raw_ = raw_value;
  }

  return this->last_wd_flag_raw_;
}


bool BQ25798Component::get_wd_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_wd_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->WD_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_wd_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// POORSRC_FLAG - Poor source detected
uint16_t BQ25798Component::get_poorsrc_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_poorsrc_flag_raw_ = raw_value;
  }

  return this->last_poorsrc_flag_raw_;
}


bool BQ25798Component::get_poorsrc_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_poorsrc_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->POORSRC_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_poorsrc_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// PG_FLAG - Power status changed
uint16_t BQ25798Component::get_pg_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_pg_flag_raw_ = raw_value;
  }

  return this->last_pg_flag_raw_;
}


bool BQ25798Component::get_pg_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_pg_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PG_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_pg_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// AC2_PRESENT_FLAG - AC2 present status changed
uint16_t BQ25798Component::get_ac2_present_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ac2_present_flag_raw_ = raw_value;
  }

  return this->last_ac2_present_flag_raw_;
}


bool BQ25798Component::get_ac2_present_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_ac2_present_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->AC2_PRESENT_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_ac2_present_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// AC1_PRESENT_FLAG - AC1 present status changed
uint16_t BQ25798Component::get_ac1_present_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ac1_present_flag_raw_ = raw_value;
  }

  return this->last_ac1_present_flag_raw_;
}


bool BQ25798Component::get_ac1_present_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_ac1_present_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->AC1_PRESENT_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_ac1_present_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VBUS_PRESENT_FLAG - VBUS present status changed
uint16_t BQ25798Component::get_vbus_present_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vbus_present_flag_raw_ = raw_value;
  }

  return this->last_vbus_present_flag_raw_;
}


bool BQ25798Component::get_vbus_present_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_vbus_present_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBUS_PRESENT_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_vbus_present_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// CHG_FLAG - Charging status changed
uint16_t BQ25798Component::get_chg_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_chg_flag_raw_ = raw_value;
  }

  return this->last_chg_flag_raw_;
}


bool BQ25798Component::get_chg_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_chg_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->CHG_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_chg_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// ICO_FLAG - ICO status changed
uint16_t BQ25798Component::get_ico_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ico_flag_raw_ = raw_value;
  }

  return this->last_ico_flag_raw_;
}


bool BQ25798Component::get_ico_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_ico_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ICO_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_ico_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VBUS_FLAG - VBUS status changed
uint16_t BQ25798Component::get_vbus_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vbus_flag_raw_ = raw_value;
  }

  return this->last_vbus_flag_raw_;
}


bool BQ25798Component::get_vbus_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_vbus_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBUS_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_vbus_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// TREG_FLAG - TREG signal rising threshold detected
uint16_t BQ25798Component::get_treg_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_treg_flag_raw_ = raw_value;
  }

  return this->last_treg_flag_raw_;
}


bool BQ25798Component::get_treg_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_treg_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TREG_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_treg_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VBAT_PRESENT_FLAG - Battery present status changed
uint16_t BQ25798Component::get_vbat_present_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vbat_present_flag_raw_ = raw_value;
  }

  return this->last_vbat_present_flag_raw_;
}


bool BQ25798Component::get_vbat_present_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_vbat_present_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBAT_PRESENT_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_vbat_present_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// BC1_2_DONE_FLAG - BC1.2 detection status changed
uint16_t BQ25798Component::get_bc1_2_done_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_bc1_2_done_flag_raw_ = raw_value;
  }

  return this->last_bc1_2_done_flag_raw_;
}


bool BQ25798Component::get_bc1_2_done_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_bc1_2_done_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->BC1_2_DONE_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_bc1_2_done_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// DPDM_DONE_FLAG - D+/D- detection is completed
uint16_t BQ25798Component::get_dpdm_done_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_dpdm_done_flag_raw_ = raw_value;
  }

  return this->last_dpdm_done_flag_raw_;
}


bool BQ25798Component::get_dpdm_done_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_dpdm_done_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DPDM_DONE_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_dpdm_done_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// ADC_DONE_FLAG - ADC conversion is completed
uint16_t BQ25798Component::get_adc_done_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_adc_done_flag_raw_ = raw_value;
  }

  return this->last_adc_done_flag_raw_;
}


bool BQ25798Component::get_adc_done_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_adc_done_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ADC_DONE_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_adc_done_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VSYS_FLAG - Entered or existed VSYSMIN regulation
uint16_t BQ25798Component::get_vsys_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vsys_flag_raw_ = raw_value;
  }

  return this->last_vsys_flag_raw_;
}


bool BQ25798Component::get_vsys_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_vsys_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VSYS_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_vsys_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// CHG_TMR_FLAG - Fast charge timer expired rising edge detected
uint16_t BQ25798Component::get_chg_tmr_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_chg_tmr_flag_raw_ = raw_value;
  }

  return this->last_chg_tmr_flag_raw_;
}


bool BQ25798Component::get_chg_tmr_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_chg_tmr_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->CHG_TMR_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_chg_tmr_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// TRICHG_TMR_FLAG - Trickle charge timer expired rising edge detected
uint16_t BQ25798Component::get_trichg_tmr_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_trichg_tmr_flag_raw_ = raw_value;
  }

  return this->last_trichg_tmr_flag_raw_;
}


bool BQ25798Component::get_trichg_tmr_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_trichg_tmr_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TRICHG_TMR_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_trichg_tmr_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// PRECHG_TMR_FLAG - Pre-charge timer expired rising edge detected
uint16_t BQ25798Component::get_prechg_tmr_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_prechg_tmr_flag_raw_ = raw_value;
  }

  return this->last_prechg_tmr_flag_raw_;
}


bool BQ25798Component::get_prechg_tmr_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_prechg_tmr_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PRECHG_TMR_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_prechg_tmr_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// TOPOFF_TMR_FLAG - Top-off timer expired rising edge detected
uint16_t BQ25798Component::get_topoff_tmr_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_topoff_tmr_flag_raw_ = raw_value;
  }

  return this->last_topoff_tmr_flag_raw_;
}


bool BQ25798Component::get_topoff_tmr_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_topoff_tmr_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TOPOFF_TMR_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_topoff_tmr_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VBATOTG_LOW_FLAG - VBAT falls below the threshold to enable the OTG mode
uint16_t BQ25798Component::get_vbatotg_low_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vbatotg_low_flag_raw_ = raw_value;
  }

  return this->last_vbatotg_low_flag_raw_;
}


bool BQ25798Component::get_vbatotg_low_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_vbatotg_low_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBATOTG_LOW_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_vbatotg_low_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// TS_COLD_FLAG - TS across cold temperature (T1) is detected
uint16_t BQ25798Component::get_ts_cold_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ts_cold_flag_raw_ = raw_value;
  }

  return this->last_ts_cold_flag_raw_;
}


bool BQ25798Component::get_ts_cold_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_ts_cold_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_COLD_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_ts_cold_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// TS_COOL_FLAG - TS across cool temperature (T2) is detected
uint16_t BQ25798Component::get_ts_cool_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ts_cool_flag_raw_ = raw_value;
  }

  return this->last_ts_cool_flag_raw_;
}


bool BQ25798Component::get_ts_cool_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_ts_cool_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_COOL_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_ts_cool_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// TS_WARM_FLAG - TS across warm temperature (T3) is detected
uint16_t BQ25798Component::get_ts_warm_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ts_warm_flag_raw_ = raw_value;
  }

  return this->last_ts_warm_flag_raw_;
}


bool BQ25798Component::get_ts_warm_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_ts_warm_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_WARM_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_ts_warm_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// TS_HOT_FLAG - TS across hot temperature (T5) is detected
uint16_t BQ25798Component::get_ts_hot_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ts_hot_flag_raw_ = raw_value;
  }

  return this->last_ts_hot_flag_raw_;
}


bool BQ25798Component::get_ts_hot_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_ts_hot_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_HOT_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_ts_hot_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// IBAT_REG_FLAG - Enter or exit IBAT regulation
uint16_t BQ25798Component::get_ibat_reg_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ibat_reg_flag_raw_ = raw_value;
  }

  return this->last_ibat_reg_flag_raw_;
}


bool BQ25798Component::get_ibat_reg_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_ibat_reg_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBAT_REG_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_ibat_reg_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VBUS_OVP_FLAG - Enter VBUS OVP
uint16_t BQ25798Component::get_vbus_ovp_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vbus_ovp_flag_raw_ = raw_value;
  }

  return this->last_vbus_ovp_flag_raw_;
}


bool BQ25798Component::get_vbus_ovp_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_vbus_ovp_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBUS_OVP_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_vbus_ovp_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VBAT_OVP_FLAG - Enter VBAT OVP
uint16_t BQ25798Component::get_vbat_ovp_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vbat_ovp_flag_raw_ = raw_value;
  }

  return this->last_vbat_ovp_flag_raw_;
}


bool BQ25798Component::get_vbat_ovp_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_vbat_ovp_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBAT_OVP_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_vbat_ovp_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// IBUS_OCP_FLAG - Enter IBUS OCP
uint16_t BQ25798Component::get_ibus_ocp_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ibus_ocp_flag_raw_ = raw_value;
  }

  return this->last_ibus_ocp_flag_raw_;
}


bool BQ25798Component::get_ibus_ocp_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_ibus_ocp_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBUS_OCP_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_ibus_ocp_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// IBAT_OCP_FLAG - Enter discharged OCP
uint16_t BQ25798Component::get_ibat_ocp_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ibat_ocp_flag_raw_ = raw_value;
  }

  return this->last_ibat_ocp_flag_raw_;
}


bool BQ25798Component::get_ibat_ocp_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_ibat_ocp_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBAT_OCP_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_ibat_ocp_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// CONV_OCP_FLAG - Enter converter OCP
uint16_t BQ25798Component::get_conv_ocp_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_conv_ocp_flag_raw_ = raw_value;
  }

  return this->last_conv_ocp_flag_raw_;
}


bool BQ25798Component::get_conv_ocp_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_conv_ocp_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->CONV_OCP_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_conv_ocp_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VAC2_OVP_FLAG - Enter VAC2 OVP
uint16_t BQ25798Component::get_vac2_ovp_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vac2_ovp_flag_raw_ = raw_value;
  }

  return this->last_vac2_ovp_flag_raw_;
}


bool BQ25798Component::get_vac2_ovp_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_vac2_ovp_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC2_OVP_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_vac2_ovp_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VAC1_OVP_FLAG - Enter VAC1 OVP
uint16_t BQ25798Component::get_vac1_ovp_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vac1_ovp_flag_raw_ = raw_value;
  }

  return this->last_vac1_ovp_flag_raw_;
}


bool BQ25798Component::get_vac1_ovp_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_vac1_ovp_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC1_OVP_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_vac1_ovp_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VSYS_SHORT_FLAG - Stop switching due to system short
uint16_t BQ25798Component::get_vsys_short_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vsys_short_flag_raw_ = raw_value;
  }

  return this->last_vsys_short_flag_raw_;
}


bool BQ25798Component::get_vsys_short_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_vsys_short_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VSYS_SHORT_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_vsys_short_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VSYS_OVP_FLAG - Stop switching due to system over-voltage
uint16_t BQ25798Component::get_vsys_ovp_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vsys_ovp_flag_raw_ = raw_value;
  }

  return this->last_vsys_ovp_flag_raw_;
}


bool BQ25798Component::get_vsys_ovp_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_vsys_ovp_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VSYS_OVP_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_vsys_ovp_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// OTG_OVP_FLAG - Stop OTG due to VBUS over voltage
uint16_t BQ25798Component::get_otg_ovp_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_otg_ovp_flag_raw_ = raw_value;
  }

  return this->last_otg_ovp_flag_raw_;
}


bool BQ25798Component::get_otg_ovp_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_otg_ovp_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->OTG_OVP_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_otg_ovp_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// OTG_UVP_FLAG - Stop OTG due to VBUS under voltage
uint16_t BQ25798Component::get_otg_uvp_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_otg_uvp_flag_raw_ = raw_value;
  }

  return this->last_otg_uvp_flag_raw_;
}


bool BQ25798Component::get_otg_uvp_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_otg_uvp_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->OTG_UVP_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_otg_uvp_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// TSHUT_FLAG - TS shutdown signal rising threshold detected
uint16_t BQ25798Component::get_tshut_flag_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_tshut_flag_raw_ = raw_value;
  }

  return this->last_tshut_flag_raw_;
}


bool BQ25798Component::get_tshut_flag_bool(bool read_from_i2c) {
  uint16_t raw = get_tshut_flag_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TSHUT_FLAG);
  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (bool_val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    this->raise_flag_tshut_flag();
  }
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// ADC_EN - ADC enable
uint16_t BQ25798Component::get_adc_en_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_adc_en_raw_ = raw_value;
  }

  return this->last_adc_en_raw_;
}

void BQ25798Component::set_adc_en_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_adc_en_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s ADC_EN to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_adc_en_bool(bool read_from_i2c) {
  uint16_t raw = get_adc_en_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ADC_EN);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_adc_en_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting ADC_EN to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->ADC_EN);
  this->set_adc_en_raw(raw_value, write_to_i2c);
};



// ADC_RATE - ADC conversion rate
uint16_t BQ25798Component::get_adc_rate_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_adc_rate_raw_ = raw_value;
  }

  return this->last_adc_rate_raw_;
}

void BQ25798Component::set_adc_rate_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_adc_rate_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s ADC_RATE to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_adc_rate_bool(bool read_from_i2c) {
  uint16_t raw = get_adc_rate_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ADC_RATE);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_adc_rate_enum_int(bool read_from_i2c) {
  uint16_t raw = get_adc_rate_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ADC_RATE);
}
const char* BQ25798Component::get_adc_rate_enum_string(bool read_from_i2c) {
  uint16_t raw = get_adc_rate_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->ADC_RATE);
}

void BQ25798Component::set_adc_rate_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting ADC_RATE to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->ADC_RATE);
  this->set_adc_rate_raw(raw_value, write_to_i2c);
};



void BQ25798Component::set_adc_rate_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting ADC_RATE to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->ADC_RATE);
  this->set_adc_rate_raw(raw_value, write_to_i2c);
};
// ADC_SAMPLE - ADC sample speed
uint16_t BQ25798Component::get_adc_sample_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);

    this->last_adc_sample_raw_ = raw_value;
  }

  return this->last_adc_sample_raw_;
}

void BQ25798Component::set_adc_sample_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_adc_sample_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s ADC_SAMPLE to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
  // ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_adc_sample_enum_int(bool read_from_i2c) {
  uint16_t raw = get_adc_sample_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ADC_SAMPLE);
}
const char* BQ25798Component::get_adc_sample_enum_string(bool read_from_i2c) {
  uint16_t raw = get_adc_sample_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->ADC_SAMPLE);
}




void BQ25798Component::set_adc_sample_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting ADC_SAMPLE to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->ADC_SAMPLE);
  this->set_adc_sample_raw(raw_value, write_to_i2c);
};
// ADC_AVG - ADC averaging
uint16_t BQ25798Component::get_adc_avg_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_adc_avg_raw_ = raw_value;
  }

  return this->last_adc_avg_raw_;
}

void BQ25798Component::set_adc_avg_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_adc_avg_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s ADC_AVG to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_adc_avg_bool(bool read_from_i2c) {
  uint16_t raw = get_adc_avg_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ADC_AVG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}
int BQ25798Component::get_adc_avg_enum_int(bool read_from_i2c) {
  uint16_t raw = get_adc_avg_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ADC_AVG);
}
const char* BQ25798Component::get_adc_avg_enum_string(bool read_from_i2c) {
  uint16_t raw = get_adc_avg_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->ADC_AVG);
}

void BQ25798Component::set_adc_avg_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting ADC_AVG to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->ADC_AVG);
  this->set_adc_avg_raw(raw_value, write_to_i2c);
};



void BQ25798Component::set_adc_avg_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting ADC_AVG to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->ADC_AVG);
  this->set_adc_avg_raw(raw_value, write_to_i2c);
};
// ADC_AVG_INIT - ADC average initialization
uint16_t BQ25798Component::get_adc_avg_init_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_adc_avg_init_raw_ = raw_value;
  }

  return this->last_adc_avg_init_raw_;
}

void BQ25798Component::set_adc_avg_init_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_adc_avg_init_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s ADC_AVG_INIT to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_adc_avg_init_bool(bool read_from_i2c) {
  uint16_t raw = get_adc_avg_init_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ADC_AVG_INIT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_adc_avg_init_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting ADC_AVG_INIT to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->ADC_AVG_INIT);
  this->set_adc_avg_init_raw(raw_value, write_to_i2c);
};



// IBUS_ADC_DIS - IBUS ADC disable
uint16_t BQ25798Component::get_ibus_adc_dis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ibus_adc_dis_raw_ = raw_value;
  }

  return this->last_ibus_adc_dis_raw_;
}

void BQ25798Component::set_ibus_adc_dis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_ibus_adc_dis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s IBUS_ADC_DIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_ibus_adc_dis_bool(bool read_from_i2c) {
  uint16_t raw = get_ibus_adc_dis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBUS_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_ibus_adc_dis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting IBUS_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->IBUS_ADC_DIS);
  this->set_ibus_adc_dis_raw(raw_value, write_to_i2c);
};



// IBAT_ADC_DIS - IBAT ADC disable
uint16_t BQ25798Component::get_ibat_adc_dis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ibat_adc_dis_raw_ = raw_value;
  }

  return this->last_ibat_adc_dis_raw_;
}

void BQ25798Component::set_ibat_adc_dis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_ibat_adc_dis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s IBAT_ADC_DIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_ibat_adc_dis_bool(bool read_from_i2c) {
  uint16_t raw = get_ibat_adc_dis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBAT_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_ibat_adc_dis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting IBAT_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->IBAT_ADC_DIS);
  this->set_ibat_adc_dis_raw(raw_value, write_to_i2c);
};



// VBUS_ADC_DIS - VBUS ADC disable
uint16_t BQ25798Component::get_vbus_adc_dis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vbus_adc_dis_raw_ = raw_value;
  }

  return this->last_vbus_adc_dis_raw_;
}

void BQ25798Component::set_vbus_adc_dis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vbus_adc_dis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VBUS_ADC_DIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_vbus_adc_dis_bool(bool read_from_i2c) {
  uint16_t raw = get_vbus_adc_dis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBUS_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vbus_adc_dis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VBUS_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VBUS_ADC_DIS);
  this->set_vbus_adc_dis_raw(raw_value, write_to_i2c);
};



// VBAT_ADC_DIS - VBAT ADC disable
uint16_t BQ25798Component::get_vbat_adc_dis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vbat_adc_dis_raw_ = raw_value;
  }

  return this->last_vbat_adc_dis_raw_;
}

void BQ25798Component::set_vbat_adc_dis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vbat_adc_dis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VBAT_ADC_DIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_vbat_adc_dis_bool(bool read_from_i2c) {
  uint16_t raw = get_vbat_adc_dis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBAT_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vbat_adc_dis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VBAT_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VBAT_ADC_DIS);
  this->set_vbat_adc_dis_raw(raw_value, write_to_i2c);
};



// VSYS_ADC_DIS - VSYS ADC disable
uint16_t BQ25798Component::get_vsys_adc_dis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vsys_adc_dis_raw_ = raw_value;
  }

  return this->last_vsys_adc_dis_raw_;
}

void BQ25798Component::set_vsys_adc_dis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vsys_adc_dis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VSYS_ADC_DIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_vsys_adc_dis_bool(bool read_from_i2c) {
  uint16_t raw = get_vsys_adc_dis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VSYS_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vsys_adc_dis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VSYS_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VSYS_ADC_DIS);
  this->set_vsys_adc_dis_raw(raw_value, write_to_i2c);
};



// TS_ADC_DIS - TS ADC disable
uint16_t BQ25798Component::get_ts_adc_dis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_ts_adc_dis_raw_ = raw_value;
  }

  return this->last_ts_adc_dis_raw_;
}

void BQ25798Component::set_ts_adc_dis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_ts_adc_dis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s TS_ADC_DIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_ts_adc_dis_bool(bool read_from_i2c) {
  uint16_t raw = get_ts_adc_dis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_ts_adc_dis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting TS_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->TS_ADC_DIS);
  this->set_ts_adc_dis_raw(raw_value, write_to_i2c);
};



// TDIE_ADC_DIS - TDIE ADC disable
uint16_t BQ25798Component::get_tdie_adc_dis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_tdie_adc_dis_raw_ = raw_value;
  }

  return this->last_tdie_adc_dis_raw_;
}

void BQ25798Component::set_tdie_adc_dis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_tdie_adc_dis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s TDIE_ADC_DIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_tdie_adc_dis_bool(bool read_from_i2c) {
  uint16_t raw = get_tdie_adc_dis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TDIE_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_tdie_adc_dis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting TDIE_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->TDIE_ADC_DIS);
  this->set_tdie_adc_dis_raw(raw_value, write_to_i2c);
};



// DPLUS_ADC_DIS - D+ ADC disable
uint16_t BQ25798Component::get_dplus_adc_dis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);

    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_dplus_adc_dis_raw_ = raw_value;
  }

  return this->last_dplus_adc_dis_raw_;
}

void BQ25798Component::set_dplus_adc_dis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_dplus_adc_dis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s DPLUS_ADC_DIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_dplus_adc_dis_bool(bool read_from_i2c) {
  uint16_t raw = get_dplus_adc_dis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DPLUS_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dplus_adc_dis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting DPLUS_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DPLUS_ADC_DIS);
  this->set_dplus_adc_dis_raw(raw_value, write_to_i2c);
};



// DMINUS_ADC_DIS - D- ADC disable
uint16_t BQ25798Component::get_dminus_adc_dis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);

    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_dminus_adc_dis_raw_ = raw_value;
  }

  return this->last_dminus_adc_dis_raw_;
}

void BQ25798Component::set_dminus_adc_dis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_dminus_adc_dis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s DMINUS_ADC_DIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_dminus_adc_dis_bool(bool read_from_i2c) {
  uint16_t raw = get_dminus_adc_dis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DMINUS_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dminus_adc_dis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting DMINUS_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DMINUS_ADC_DIS);
  this->set_dminus_adc_dis_raw(raw_value, write_to_i2c);
};



// VAC2_ADC_DIS - VAC2 ADC disable
uint16_t BQ25798Component::get_vac2_adc_dis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vac2_adc_dis_raw_ = raw_value;
  }

  return this->last_vac2_adc_dis_raw_;
}

void BQ25798Component::set_vac2_adc_dis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vac2_adc_dis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VAC2_ADC_DIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_vac2_adc_dis_bool(bool read_from_i2c) {
  uint16_t raw = get_vac2_adc_dis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC2_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vac2_adc_dis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VAC2_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VAC2_ADC_DIS);
  this->set_vac2_adc_dis_raw(raw_value, write_to_i2c);
};



// VAC1_ADC_DIS - VAC1 ADC disable
uint16_t BQ25798Component::get_vac1_adc_dis_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);

    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    this->last_vac1_adc_dis_raw_ = raw_value;
  }

  return this->last_vac1_adc_dis_raw_;
}

void BQ25798Component::set_vac1_adc_dis_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_vac1_adc_dis_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s VAC1_ADC_DIS to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
  // ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    this->mark_failed();
  }
}

bool BQ25798Component::get_vac1_adc_dis_bool(bool read_from_i2c) {
  uint16_t raw = get_vac1_adc_dis_raw(read_from_i2c);
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC1_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vac1_adc_dis_bool(bool value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting VAC1_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VAC1_ADC_DIS);
  this->set_vac1_adc_dis_raw(raw_value, write_to_i2c);
};



// IBUS_ADC - IBUS ADC reading
uint16_t BQ25798Component::get_ibus_adc_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG31_IBUS_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    this->last_ibus_adc_raw_ = raw_value;
  }

  return this->last_ibus_adc_raw_;
}


int BQ25798Component::get_ibus_adc_int(bool read_from_i2c) {
  uint16_t raw = get_ibus_adc_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->IBUS_ADC);
}

// IBAT_ADC - IBAT ADC reading
uint16_t BQ25798Component::get_ibat_adc_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG33_IBAT_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    this->last_ibat_adc_raw_ = raw_value;
  }

  return this->last_ibat_adc_raw_;
}


int BQ25798Component::get_ibat_adc_int(bool read_from_i2c) {
  uint16_t raw = get_ibat_adc_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->IBAT_ADC);
}

// VBUS_ADC - VBUS ADC reading
uint16_t BQ25798Component::get_vbus_adc_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG35_VBUS_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    this->last_vbus_adc_raw_ = raw_value;
  }

  return this->last_vbus_adc_raw_;
}


int BQ25798Component::get_vbus_adc_int(bool read_from_i2c) {
  uint16_t raw = get_vbus_adc_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBUS_ADC);
}

// VAC1_ADC - VAC1 ADC reading
uint16_t BQ25798Component::get_vac1_adc_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG37_VAC1_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    this->last_vac1_adc_raw_ = raw_value;
  }

  return this->last_vac1_adc_raw_;
}


int BQ25798Component::get_vac1_adc_int(bool read_from_i2c) {
  uint16_t raw = get_vac1_adc_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VAC1_ADC);
}

// VAC2_ADC - VAC2 ADC reading
uint16_t BQ25798Component::get_vac2_adc_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG39_VAC2_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    this->last_vac2_adc_raw_ = raw_value;
  }

  return this->last_vac2_adc_raw_;
}


int BQ25798Component::get_vac2_adc_int(bool read_from_i2c) {
  uint16_t raw = get_vac2_adc_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VAC2_ADC);
}

// VBAT_ADC - VBAT ADC reading
uint16_t BQ25798Component::get_vbat_adc_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG3B_VBAT_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    this->last_vbat_adc_raw_ = raw_value;
  }

  return this->last_vbat_adc_raw_;
}


int BQ25798Component::get_vbat_adc_int(bool read_from_i2c) {
  uint16_t raw = get_vbat_adc_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBAT_ADC);
}

// VSYS_ADC - VSYS ADC reading
uint16_t BQ25798Component::get_vsys_adc_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG3D_VSYS_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    this->last_vsys_adc_raw_ = raw_value;
  }

  return this->last_vsys_adc_raw_;
}


int BQ25798Component::get_vsys_adc_int(bool read_from_i2c) {
  uint16_t raw = get_vsys_adc_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VSYS_ADC);
}

// TS_ADC - TS ADC reading
uint16_t BQ25798Component::get_ts_adc_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG3F_TS_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    this->last_ts_adc_raw_ = raw_value;
  }

  return this->last_ts_adc_raw_;
}


float BQ25798Component::get_ts_adc_float(bool read_from_i2c) {
  uint16_t raw = get_ts_adc_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToFloat(raw, this->bq25798_noi2c_->TS_ADC);
}

// TDIE_ADC - TDIE ADC reading
uint16_t BQ25798Component::get_tdie_adc_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG41_TDIE_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    this->last_tdie_adc_raw_ = raw_value;
  }

  return this->last_tdie_adc_raw_;
}


float BQ25798Component::get_tdie_adc_float(bool read_from_i2c) {
  uint16_t raw = get_tdie_adc_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToFloat(raw, this->bq25798_noi2c_->TDIE_ADC);
}

// DPLUS_ADC - D+ ADC reading
uint16_t BQ25798Component::get_dplus_adc_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG43_DPLUS_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    this->last_dplus_adc_raw_ = raw_value;
  }

  return this->last_dplus_adc_raw_;
}


int BQ25798Component::get_dplus_adc_int(bool read_from_i2c) {
  uint16_t raw = get_dplus_adc_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->DPLUS_ADC);
}

// DMINUS_ADC - D- ADC reading
uint16_t BQ25798Component::get_dminus_adc_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint16_t reg_value;
    if (!this->read_byte_16(REG45_DMINUS_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    this->last_dminus_adc_raw_ = raw_value;
  }

  return this->last_dminus_adc_raw_;
}


int BQ25798Component::get_dminus_adc_int(bool read_from_i2c) {
  uint16_t raw = get_dminus_adc_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->DMINUS_ADC);
}

// DPLUS_DAC - D+ Output Driver
uint16_t BQ25798Component::get_dplus_dac_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG47_DPDM_Driver\") value: 0x%02X", REG47_DPDM_Driver, reg_value);

    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);

    this->last_dplus_dac_raw_ = raw_value;
  }

  return this->last_dplus_dac_raw_;
}

void BQ25798Component::set_dplus_dac_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_dplus_dac_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s DPLUS_DAC to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG47_DPDM_Driver\") value: 0x%02X", REG47_DPDM_Driver,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
  // ESP_LOGD(TAG, "  masked (3 bits shifted by 5) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG47_DPDM_Driver, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_dplus_dac_enum_int(bool read_from_i2c) {
  uint16_t raw = get_dplus_dac_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->DPLUS_DAC);
}
const char* BQ25798Component::get_dplus_dac_enum_string(bool read_from_i2c) {
  uint16_t raw = get_dplus_dac_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->DPLUS_DAC);
}




void BQ25798Component::set_dplus_dac_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting DPLUS_DAC to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->DPLUS_DAC);
  this->set_dplus_dac_raw(raw_value, write_to_i2c);
};
// DMINUS_DAC - D- Output Driver
uint16_t BQ25798Component::get_dminus_dac_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG47_DPDM_Driver\") value: 0x%02X", REG47_DPDM_Driver, reg_value);

    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (3 bits) raw value: 0x%04X", raw_value);

    this->last_dminus_dac_raw_ = raw_value;
  }

  return this->last_dminus_dac_raw_;
}

void BQ25798Component::set_dminus_dac_raw(uint16_t raw_value, bool write_to_i2c) {
  this->last_dminus_dac_raw_ = raw_value;
  if (this->is_failed()) {
    return;
  }

  bool _write = write_to_i2c && this->bq25798_noi2c_ != nullptr;
  ESP_LOGD(TAG, "%s DMINUS_DAC to 0x%04X", _write ? "Setting and writing" : "Will eventually set", raw_value);
  if (!_write) {
    return;
  }

  uint8_t reg_value;
  if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
    this->mark_failed();
    return;
  }
  // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG47_DPDM_Driver\") value: 0x%02X", REG47_DPDM_Driver,    reg_value);

  reg_value &= ~(BITLENGTH_TO_MASK(3) << 2);
  // ESP_LOGD(TAG, "  masked (3 bits shifted by 2) register value: 0x%02X", reg_value);

  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 2);
  // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG47_DPDM_Driver, reg_value)) {
    this->mark_failed();
  }
}

int BQ25798Component::get_dminus_dac_enum_int(bool read_from_i2c) {
  uint16_t raw = get_dminus_dac_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->DMINUS_DAC);
}
const char* BQ25798Component::get_dminus_dac_enum_string(bool read_from_i2c) {
  uint16_t raw = get_dminus_dac_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->DMINUS_DAC);
}




void BQ25798Component::set_dminus_dac_enum_int(int value, bool write_to_i2c) {
  ESP_LOGD(TAG, "Setting DMINUS_DAC to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->DMINUS_DAC);
  this->set_dminus_dac_raw(raw_value, write_to_i2c);
};
// PN - Part number
uint16_t BQ25798Component::get_pn_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG48_Part_Information, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG48_Part_Information\") value: 0x%02X", REG48_Part_Information, reg_value);

    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (3 bits) raw value: 0x%04X", raw_value);

    this->last_pn_raw_ = raw_value;
  }

  return this->last_pn_raw_;
}


int BQ25798Component::get_pn_enum_int(bool read_from_i2c) {
  uint16_t raw = get_pn_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->PN);
}
const char* BQ25798Component::get_pn_enum_string(bool read_from_i2c) {
  uint16_t raw = get_pn_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->PN);
}

// DEV_REV - Device revision
uint16_t BQ25798Component::get_dev_rev_raw(bool read_from_i2c) {
  if (this->is_failed()) {
    return 0;
  }

  if (read_from_i2c && this->bq25798_noi2c_ != nullptr) {
    uint8_t reg_value;
    if (!this->read_byte(REG48_Part_Information, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG48_Part_Information\") value: 0x%02X", REG48_Part_Information, reg_value);

    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (3 bits) raw value: 0x%04X", raw_value);

    this->last_dev_rev_raw_ = raw_value;
  }

  return this->last_dev_rev_raw_;
}


int BQ25798Component::get_dev_rev_enum_int(bool read_from_i2c) {
  uint16_t raw = get_dev_rev_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->DEV_REV);
}
const char* BQ25798Component::get_dev_rev_enum_string(bool read_from_i2c) {
  uint16_t raw = get_dev_rev_raw(read_from_i2c);
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->DEV_REV);
}


}  // namespace bq25798
}  // namespace esphome