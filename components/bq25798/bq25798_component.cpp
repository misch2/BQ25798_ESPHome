#include "bq25798_component.h"
#include "esphome/core/log.h"
#include "esphome/core/hal.h"

#include <array>
#include <map>

namespace esphome {
namespace bq25798 {

static const char* TAG = "bq25798.component";

void BQ25798Component::setup() {
  ESP_LOGCONFIG(TAG, "Setting up BQ25798...");

  this->bq25798_noi2c_ = new BQ25798NoI2C();
  this->bq25798_noi2c_->begin(this->address_); // no-op

  this->clear_registers();
  this->update(); // read the registers

  int pn = get_pn_enum_int();
  if (pn != static_cast<int>(BQ25798NoI2C::PN_t::PN_BQ25798)) {
    ESP_LOGE(TAG, "BQ25798 chip not found at address 0x%02X. Read signature: %d", this->address_, pn);
    this->clear_registers();
    this->mark_failed();
    return;
  }

  int dev_rev = get_dev_rev_enum_int();
  if (dev_rev != static_cast<int>(BQ25798NoI2C::DEV_REV_t::DEV_REV_BQ25798)) {
    ESP_LOGE(TAG, "BQ25798 chip at address 0x%02X has unexpected device revision: %d", this->address_, dev_rev);
    this->clear_registers();
    this->mark_failed();
    return;
  }

  ESP_LOGCONFIG(TAG, "Resetting the chip...");
  this->set_reg_rst_bool(true);
  while (this->get_reg_rst_bool()) {
    this->update(); // read the registers again
    delay(10); // wait for the chip to reset
  }
  ESP_LOGCONFIG(TAG, "Chip reset complete.");

  ESP_LOGCONFIG(TAG, "BQ25798 initialized successfully at address 0x%02X", this->address_);
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

static std::array<uint8_t, 73> _reg_values = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

static const std::map<uint8_t, uint8_t> _regaddr_to_index = {
    { REG00_Minimal_System_Voltage, 0 }, 
    { REG01_Charge_Voltage_Limit, 1 }, 
    { REG02_dummy_fill, 2 }, 
    { REG03_Charge_Current_Limit, 3 }, 
    { REG04_dummy_fill, 4 }, 
    { REG05_Input_Voltage_Limit, 5 }, 
    { REG06_Input_Current_Limit, 6 }, 
    { REG07_dummy_fill, 7 }, 
    { REG08_Precharge_Control, 8 }, 
    { REG09_Termination_Control, 9 }, 
    { REG0A_Recharge_Control, 10 }, 
    { REG0B_VOTG_regulation, 11 }, 
    { REG0C_dummy_fill, 12 }, 
    { REG0D_IOTG_regulation, 13 }, 
    { REG0E_Timer_Control, 14 }, 
    { REG0F_Charger_Control_0, 15 }, 
    { REG10_Charger_Control_1, 16 }, 
    { REG11_Charger_Control_2, 17 }, 
    { REG12_Charger_Control_3, 18 }, 
    { REG13_Charger_Control_4, 19 }, 
    { REG14_Charger_Control_5, 20 }, 
    { REG15_MPPT_Control, 21 }, 
    { REG16_Temperature_Control, 22 }, 
    { REG17_NTC_Control_0, 23 }, 
    { REG18_NTC_Control_1, 24 }, 
    { REG19_ICO_Current_Limit, 25 }, 
    { REG1A_dummy_fill, 26 }, 
    { REG1B_Charger_Status_0, 27 }, 
    { REG1C_Charger_Status_1, 28 }, 
    { REG1D_Charger_Status_2, 29 }, 
    { REG1E_Charger_Status_3, 30 }, 
    { REG1F_Charger_Status_4, 31 }, 
    { REG20_FAULT_Status_0, 32 }, 
    { REG21_FAULT_Status_1, 33 }, 
    { REG22_Charger_Flag_0, 34 }, 
    { REG23_Charger_Flag_1, 35 }, 
    { REG24_Charger_Flag_2, 36 }, 
    { REG25_Charger_Flag_3, 37 }, 
    { REG26_FAULT_Flag_0, 38 }, 
    { REG27_FAULT_Flag_1, 39 }, 
    { REG28_Charger_Mask_0, 40 }, 
    { REG29_Charger_Mask_1, 41 }, 
    { REG2A_Charger_Mask_2, 42 }, 
    { REG2B_Charger_Mask_3, 43 }, 
    { REG2C_FAULT_Mask_0, 44 }, 
    { REG2D_FAULT_Mask_1, 45 }, 
    { REG2E_ADC_Control, 46 }, 
    { REG2F_ADC_Function_Disable_0, 47 }, 
    { REG30_ADC_Function_Disable_1, 48 }, 
    { REG31_IBUS_ADC, 49 }, 
    { REG32_dummy_fill, 50 }, 
    { REG33_IBAT_ADC, 51 }, 
    { REG34_dummy_fill, 52 }, 
    { REG35_VBUS_ADC, 53 }, 
    { REG36_dummy_fill, 54 }, 
    { REG37_VAC1_ADC, 55 }, 
    { REG38_dummy_fill, 56 }, 
    { REG39_VAC2_ADC, 57 }, 
    { REG3A_dummy_fill, 58 }, 
    { REG3B_VBAT_ADC, 59 }, 
    { REG3C_dummy_fill, 60 }, 
    { REG3D_VSYS_ADC, 61 }, 
    { REG3E_dummy_fill, 62 }, 
    { REG3F_TS_ADC, 63 }, 
    { REG40_dummy_fill, 64 }, 
    { REG41_TDIE_ADC, 65 }, 
    { REG42_dummy_fill, 66 }, 
    { REG43_DPLUS_ADC, 67 }, 
    { REG44_dummy_fill, 68 }, 
    { REG45_DMINUS_ADC, 69 }, 
    { REG46_dummy_fill, 70 }, 
    { REG47_DPDM_Driver, 71 }, 
    { REG48_Part_Information, 72 }
};

static const std::map<uint8_t, uint8_t> _regindex_to_addr = {
    { 0, REG00_Minimal_System_Voltage }, 
    { 1, REG01_Charge_Voltage_Limit }, 
    { 2, REG02_dummy_fill }, 
    { 3, REG03_Charge_Current_Limit }, 
    { 4, REG04_dummy_fill }, 
    { 5, REG05_Input_Voltage_Limit }, 
    { 6, REG06_Input_Current_Limit }, 
    { 7, REG07_dummy_fill }, 
    { 8, REG08_Precharge_Control }, 
    { 9, REG09_Termination_Control }, 
    { 10, REG0A_Recharge_Control }, 
    { 11, REG0B_VOTG_regulation }, 
    { 12, REG0C_dummy_fill }, 
    { 13, REG0D_IOTG_regulation }, 
    { 14, REG0E_Timer_Control }, 
    { 15, REG0F_Charger_Control_0 }, 
    { 16, REG10_Charger_Control_1 }, 
    { 17, REG11_Charger_Control_2 }, 
    { 18, REG12_Charger_Control_3 }, 
    { 19, REG13_Charger_Control_4 }, 
    { 20, REG14_Charger_Control_5 }, 
    { 21, REG15_MPPT_Control }, 
    { 22, REG16_Temperature_Control }, 
    { 23, REG17_NTC_Control_0 }, 
    { 24, REG18_NTC_Control_1 }, 
    { 25, REG19_ICO_Current_Limit }, 
    { 26, REG1A_dummy_fill }, 
    { 27, REG1B_Charger_Status_0 }, 
    { 28, REG1C_Charger_Status_1 }, 
    { 29, REG1D_Charger_Status_2 }, 
    { 30, REG1E_Charger_Status_3 }, 
    { 31, REG1F_Charger_Status_4 }, 
    { 32, REG20_FAULT_Status_0 }, 
    { 33, REG21_FAULT_Status_1 }, 
    { 34, REG22_Charger_Flag_0 }, 
    { 35, REG23_Charger_Flag_1 }, 
    { 36, REG24_Charger_Flag_2 }, 
    { 37, REG25_Charger_Flag_3 }, 
    { 38, REG26_FAULT_Flag_0 }, 
    { 39, REG27_FAULT_Flag_1 }, 
    { 40, REG28_Charger_Mask_0 }, 
    { 41, REG29_Charger_Mask_1 }, 
    { 42, REG2A_Charger_Mask_2 }, 
    { 43, REG2B_Charger_Mask_3 }, 
    { 44, REG2C_FAULT_Mask_0 }, 
    { 45, REG2D_FAULT_Mask_1 }, 
    { 46, REG2E_ADC_Control }, 
    { 47, REG2F_ADC_Function_Disable_0 }, 
    { 48, REG30_ADC_Function_Disable_1 }, 
    { 49, REG31_IBUS_ADC }, 
    { 50, REG32_dummy_fill }, 
    { 51, REG33_IBAT_ADC }, 
    { 52, REG34_dummy_fill }, 
    { 53, REG35_VBUS_ADC }, 
    { 54, REG36_dummy_fill }, 
    { 55, REG37_VAC1_ADC }, 
    { 56, REG38_dummy_fill }, 
    { 57, REG39_VAC2_ADC }, 
    { 58, REG3A_dummy_fill }, 
    { 59, REG3B_VBAT_ADC }, 
    { 60, REG3C_dummy_fill }, 
    { 61, REG3D_VSYS_ADC }, 
    { 62, REG3E_dummy_fill }, 
    { 63, REG3F_TS_ADC }, 
    { 64, REG40_dummy_fill }, 
    { 65, REG41_TDIE_ADC }, 
    { 66, REG42_dummy_fill }, 
    { 67, REG43_DPLUS_ADC }, 
    { 68, REG44_dummy_fill }, 
    { 69, REG45_DMINUS_ADC }, 
    { 70, REG46_dummy_fill }, 
    { 71, REG47_DPDM_Driver }, 
    { 72, REG48_Part_Information }
};

void BQ25798Component::update() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  // Read all registers
  for (int i = 0; i < 73; i++) {
    if (!this->read_byte(_regindex_to_addr.at(i), &_reg_values[i])) {
      ESP_LOGE(TAG, "Failed to read register 0x%02X", _regindex_to_addr.at(i));
      this->clear_registers();
      this->mark_failed();
      return;
    }
  }

  // Refresh watchdog timer
  this->set_wd_rst_bool(true);
}

// To visibly indicate that the component is not ready to use, we clear all registers
void BQ25798Component::clear_registers() {
  ESP_LOGD(TAG, "Clearing all cached registers");
  for (int i = 0; i < 73; i++) {
    _reg_values[i] = 0;
  }
}

// VSYSMIN - Minimal System Voltage
uint16_t BQ25798Component::get_vsysmin_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG00_Minimal_System_Voltage);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(6);
}

void BQ25798Component::set_vsysmin_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VSYSMIN to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG00_Minimal_System_Voltage);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(6) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(6)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG00_Minimal_System_Voltage (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG00_Minimal_System_Voltage, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_vsysmin_int() {
  uint16_t raw = get_vsysmin_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VSYSMIN);
}

void BQ25798Component::set_vsysmin_int(int value) {
  ESP_LOGD(TAG, "Setting VSYSMIN to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VSYSMIN);
  this->set_vsysmin_raw(raw_value);
};

// VREG - Charge Voltage Limit
uint16_t BQ25798Component::get_vreg_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG01_Charge_Voltage_Limit);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(11);
}

void BQ25798Component::set_vreg_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VREG to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG01_Charge_Voltage_Limit);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  reg_value &= ~(BITLENGTH_TO_MASK(11) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(11)) << 0);
  _reg_values[ reg_addr ] = reg_value >> 8;
  _reg_values[ reg_addr + 1 ] = reg_value & 0xFF;

  ESP_LOGD(TAG, "  Writing register REG01_Charge_Voltage_Limit (0x%02X): 0x%02X 0x%02X", reg_addr, _reg_values[ reg_addr ], _reg_values[ reg_addr + 1 ]);
  if (!this->write_byte_16(REG01_Charge_Voltage_Limit, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_vreg_int() {
  uint16_t raw = get_vreg_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VREG);
}

void BQ25798Component::set_vreg_int(int value) {
  ESP_LOGD(TAG, "Setting VREG to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VREG);
  this->set_vreg_raw(raw_value);
};

// ICHG - Charge Current Limit
uint16_t BQ25798Component::get_ichg_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG03_Charge_Current_Limit);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(9);
}

void BQ25798Component::set_ichg_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting ICHG to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG03_Charge_Current_Limit);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  reg_value &= ~(BITLENGTH_TO_MASK(9) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(9)) << 0);
  _reg_values[ reg_addr ] = reg_value >> 8;
  _reg_values[ reg_addr + 1 ] = reg_value & 0xFF;

  ESP_LOGD(TAG, "  Writing register REG03_Charge_Current_Limit (0x%02X): 0x%02X 0x%02X", reg_addr, _reg_values[ reg_addr ], _reg_values[ reg_addr + 1 ]);
  if (!this->write_byte_16(REG03_Charge_Current_Limit, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_ichg_int() {
  uint16_t raw = get_ichg_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ICHG);
}

void BQ25798Component::set_ichg_int(int value) {
  ESP_LOGD(TAG, "Setting ICHG to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->ICHG);
  this->set_ichg_raw(raw_value);
};

// VINDPM - Input Voltage Limit
uint16_t BQ25798Component::get_vindpm_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG05_Input_Voltage_Limit);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(8);
}

void BQ25798Component::set_vindpm_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VINDPM to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG05_Input_Voltage_Limit);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(8) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(8)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG05_Input_Voltage_Limit (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG05_Input_Voltage_Limit, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_vindpm_int() {
  uint16_t raw = get_vindpm_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VINDPM);
}

void BQ25798Component::set_vindpm_int(int value) {
  ESP_LOGD(TAG, "Setting VINDPM to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VINDPM);
  this->set_vindpm_raw(raw_value);
};

// IINDPM - Input Current Limit
uint16_t BQ25798Component::get_iindpm_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG06_Input_Current_Limit);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(9);
}

void BQ25798Component::set_iindpm_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting IINDPM to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG06_Input_Current_Limit);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  reg_value &= ~(BITLENGTH_TO_MASK(9) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(9)) << 0);
  _reg_values[ reg_addr ] = reg_value >> 8;
  _reg_values[ reg_addr + 1 ] = reg_value & 0xFF;

  ESP_LOGD(TAG, "  Writing register REG06_Input_Current_Limit (0x%02X): 0x%02X 0x%02X", reg_addr, _reg_values[ reg_addr ], _reg_values[ reg_addr + 1 ]);
  if (!this->write_byte_16(REG06_Input_Current_Limit, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_iindpm_int() {
  uint16_t raw = get_iindpm_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->IINDPM);
}

void BQ25798Component::set_iindpm_int(int value) {
  ESP_LOGD(TAG, "Setting IINDPM to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->IINDPM);
  this->set_iindpm_raw(raw_value);
};

// VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
uint16_t BQ25798Component::get_vbat_lowv_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG08_Precharge_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_vbat_lowv_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VBAT_LOWV to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG08_Precharge_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG08_Precharge_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG08_Precharge_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_vbat_lowv_enum_int() {
  uint16_t raw = get_vbat_lowv_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBAT_LOWV);
}
const char* BQ25798Component::get_vbat_lowv_enum_string() {
  uint16_t raw = get_vbat_lowv_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VBAT_LOWV);
}

void BQ25798Component::set_vbat_lowv_enum_int(int value) {
  ESP_LOGD(TAG, "Setting VBAT_LOWV to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VBAT_LOWV);
  this->set_vbat_lowv_raw(raw_value);
};

// IPRECHG - Precharge Current Limit
uint16_t BQ25798Component::get_iprechg_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG08_Precharge_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(6);
}

void BQ25798Component::set_iprechg_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting IPRECHG to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG08_Precharge_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(6) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(6)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG08_Precharge_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG08_Precharge_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_iprechg_int() {
  uint16_t raw = get_iprechg_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->IPRECHG);
}

void BQ25798Component::set_iprechg_int(int value) {
  ESP_LOGD(TAG, "Setting IPRECHG to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->IPRECHG);
  this->set_iprechg_raw(raw_value);
};

// REG_RST - Reset registers to default values and reset timer
uint16_t BQ25798Component::get_reg_rst_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG09_Termination_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_reg_rst_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting REG_RST to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG09_Termination_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG09_Termination_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG09_Termination_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_reg_rst_bool() {
  uint16_t raw = get_reg_rst_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->REG_RST);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_reg_rst_bool(bool value) {
  ESP_LOGD(TAG, "Setting REG_RST to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->REG_RST);
  this->set_reg_rst_raw(raw_value);
};

// STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
uint16_t BQ25798Component::get_stop_wd_chg_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG09_Termination_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_stop_wd_chg_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting STOP_WD_CHG to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG09_Termination_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG09_Termination_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG09_Termination_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_stop_wd_chg_bool() {
  uint16_t raw = get_stop_wd_chg_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->STOP_WD_CHG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_stop_wd_chg_bool(bool value) {
  ESP_LOGD(TAG, "Setting STOP_WD_CHG to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->STOP_WD_CHG);
  this->set_stop_wd_chg_raw(raw_value);
};

// ITERM - Termination Current Limit
uint16_t BQ25798Component::get_iterm_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG09_Termination_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(5);
}

void BQ25798Component::set_iterm_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting ITERM to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG09_Termination_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(5) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(5)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG09_Termination_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG09_Termination_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_iterm_int() {
  uint16_t raw = get_iterm_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ITERM);
}

void BQ25798Component::set_iterm_int(int value) {
  ESP_LOGD(TAG, "Setting ITERM to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->ITERM);
  this->set_iterm_raw(raw_value);
};

// CELL - Battery cell count
uint16_t BQ25798Component::get_cell_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0A_Recharge_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_cell_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting CELL to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0A_Recharge_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0A_Recharge_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_cell_enum_int() {
  uint16_t raw = get_cell_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->CELL);
}
const char* BQ25798Component::get_cell_enum_string() {
  uint16_t raw = get_cell_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->CELL);
}

void BQ25798Component::set_cell_enum_int(int value) {
  ESP_LOGD(TAG, "Setting CELL to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->CELL);
  this->set_cell_raw(raw_value);
};

// TRECHG - Battery recharge delay time
uint16_t BQ25798Component::get_trechg_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0A_Recharge_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_trechg_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting TRECHG to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0A_Recharge_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0A_Recharge_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_trechg_enum_int() {
  uint16_t raw = get_trechg_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TRECHG);
}
const char* BQ25798Component::get_trechg_enum_string() {
  uint16_t raw = get_trechg_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TRECHG);
}

void BQ25798Component::set_trechg_enum_int(int value) {
  ESP_LOGD(TAG, "Setting TRECHG to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->TRECHG);
  this->set_trechg_raw(raw_value);
};

// VRECHG - Battery Recharge Threshold Offset (Below VREG)
uint16_t BQ25798Component::get_vrechg_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0A_Recharge_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(4);
}

void BQ25798Component::set_vrechg_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VRECHG to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0A_Recharge_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(4) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(4)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0A_Recharge_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_vrechg_int() {
  uint16_t raw = get_vrechg_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VRECHG);
}

void BQ25798Component::set_vrechg_int(int value) {
  ESP_LOGD(TAG, "Setting VRECHG to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VRECHG);
  this->set_vrechg_raw(raw_value);
};

// VOTG - OTG mode regulation voltage
uint16_t BQ25798Component::get_votg_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0B_VOTG_regulation);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(11);
}

void BQ25798Component::set_votg_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VOTG to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0B_VOTG_regulation);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  reg_value &= ~(BITLENGTH_TO_MASK(11) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(11)) << 0);
  _reg_values[ reg_addr ] = reg_value >> 8;
  _reg_values[ reg_addr + 1 ] = reg_value & 0xFF;

  ESP_LOGD(TAG, "  Writing register REG0B_VOTG_regulation (0x%02X): 0x%02X 0x%02X", reg_addr, _reg_values[ reg_addr ], _reg_values[ reg_addr + 1 ]);
  if (!this->write_byte_16(REG0B_VOTG_regulation, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_votg_int() {
  uint16_t raw = get_votg_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VOTG);
}

void BQ25798Component::set_votg_int(int value) {
  ESP_LOGD(TAG, "Setting VOTG to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VOTG);
  this->set_votg_raw(raw_value);
};

// PRECHG_TMR - Pre-charge safety timer setting
uint16_t BQ25798Component::get_prechg_tmr_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0D_IOTG_regulation);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_prechg_tmr_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting PRECHG_TMR to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0D_IOTG_regulation);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0D_IOTG_regulation (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0D_IOTG_regulation, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_prechg_tmr_bool() {
  uint16_t raw = get_prechg_tmr_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PRECHG_TMR);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_prechg_tmr_enum_int() {
  uint16_t raw = get_prechg_tmr_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->PRECHG_TMR);
}
const char* BQ25798Component::get_prechg_tmr_enum_string() {
  uint16_t raw = get_prechg_tmr_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->PRECHG_TMR);
}

void BQ25798Component::set_prechg_tmr_bool(bool value) {
  ESP_LOGD(TAG, "Setting PRECHG_TMR to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->PRECHG_TMR);
  this->set_prechg_tmr_raw(raw_value);
};

void BQ25798Component::set_prechg_tmr_enum_int(int value) {
  ESP_LOGD(TAG, "Setting PRECHG_TMR to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->PRECHG_TMR);
  this->set_prechg_tmr_raw(raw_value);
};

// IOTG - OTG current limit
uint16_t BQ25798Component::get_iotg_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0D_IOTG_regulation);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(7);
}

void BQ25798Component::set_iotg_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting IOTG to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0D_IOTG_regulation);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(7) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(7)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0D_IOTG_regulation (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0D_IOTG_regulation, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_iotg_int() {
  uint16_t raw = get_iotg_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->IOTG);
}

void BQ25798Component::set_iotg_int(int value) {
  ESP_LOGD(TAG, "Setting IOTG to %d", value);
  uint16_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->IOTG);
  this->set_iotg_raw(raw_value);
};

// TOPOFF_TMR - Top-off timer control
uint16_t BQ25798Component::get_topoff_tmr_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0E_Timer_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_topoff_tmr_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting TOPOFF_TMR to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0E_Timer_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0E_Timer_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_topoff_tmr_enum_int() {
  uint16_t raw = get_topoff_tmr_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TOPOFF_TMR);
}
const char* BQ25798Component::get_topoff_tmr_enum_string() {
  uint16_t raw = get_topoff_tmr_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TOPOFF_TMR);
}

void BQ25798Component::set_topoff_tmr_enum_int(int value) {
  ESP_LOGD(TAG, "Setting TOPOFF_TMR to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->TOPOFF_TMR);
  this->set_topoff_tmr_raw(raw_value);
};

// EN_TRICHG_TMR - Trickle charge timer enable
uint16_t BQ25798Component::get_en_trichg_tmr_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0E_Timer_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_trichg_tmr_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_TRICHG_TMR to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0E_Timer_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0E_Timer_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_trichg_tmr_bool() {
  uint16_t raw = get_en_trichg_tmr_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_TRICHG_TMR);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_trichg_tmr_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_TRICHG_TMR to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_TRICHG_TMR);
  this->set_en_trichg_tmr_raw(raw_value);
};

// EN_PRECHG_TMR - Precharge timer enable
uint16_t BQ25798Component::get_en_prechg_tmr_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0E_Timer_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_prechg_tmr_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_PRECHG_TMR to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0E_Timer_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0E_Timer_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_prechg_tmr_bool() {
  uint16_t raw = get_en_prechg_tmr_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_PRECHG_TMR);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_prechg_tmr_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_PRECHG_TMR to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_PRECHG_TMR);
  this->set_en_prechg_tmr_raw(raw_value);
};

// EN_CHG_TMR - Fast charge timer enable
uint16_t BQ25798Component::get_en_chg_tmr_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0E_Timer_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_chg_tmr_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_CHG_TMR to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0E_Timer_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0E_Timer_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_chg_tmr_bool() {
  uint16_t raw = get_en_chg_tmr_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_CHG_TMR);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_chg_tmr_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_CHG_TMR to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_CHG_TMR);
  this->set_en_chg_tmr_raw(raw_value);
};

// CHG_TMR - Fast charge timer setting
uint16_t BQ25798Component::get_chg_tmr_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0E_Timer_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_chg_tmr_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting CHG_TMR to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0E_Timer_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0E_Timer_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_chg_tmr_enum_int() {
  uint16_t raw = get_chg_tmr_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->CHG_TMR);
}
const char* BQ25798Component::get_chg_tmr_enum_string() {
  uint16_t raw = get_chg_tmr_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->CHG_TMR);
}

void BQ25798Component::set_chg_tmr_enum_int(int value) {
  ESP_LOGD(TAG, "Setting CHG_TMR to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->CHG_TMR);
  this->set_chg_tmr_raw(raw_value);
};

// TMR2X_EN - 2x slower charging in DPM enable
uint16_t BQ25798Component::get_tmr2x_en_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0E_Timer_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_tmr2x_en_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting TMR2X_EN to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0E_Timer_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0E_Timer_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_tmr2x_en_bool() {
  uint16_t raw = get_tmr2x_en_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TMR2X_EN);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_tmr2x_en_bool(bool value) {
  ESP_LOGD(TAG, "Setting TMR2X_EN to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->TMR2X_EN);
  this->set_tmr2x_en_raw(raw_value);
};

// EN_AUTO_IBATDIS - Enable the auto battery discharging during the battery OVP fault
uint16_t BQ25798Component::get_en_auto_ibatdis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_auto_ibatdis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_AUTO_IBATDIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0F_Charger_Control_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_auto_ibatdis_bool() {
  uint16_t raw = get_en_auto_ibatdis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_AUTO_IBATDIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_auto_ibatdis_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_AUTO_IBATDIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_AUTO_IBATDIS);
  this->set_en_auto_ibatdis_raw(raw_value);
};

// FORCE_IBATDIS - Force the battery discharging current
uint16_t BQ25798Component::get_force_ibatdis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_force_ibatdis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting FORCE_IBATDIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0F_Charger_Control_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_force_ibatdis_bool() {
  uint16_t raw = get_force_ibatdis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->FORCE_IBATDIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_force_ibatdis_bool(bool value) {
  ESP_LOGD(TAG, "Setting FORCE_IBATDIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->FORCE_IBATDIS);
  this->set_force_ibatdis_raw(raw_value);
};

// EN_CHG - Enable the charger
uint16_t BQ25798Component::get_en_chg_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_chg_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_CHG to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0F_Charger_Control_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_chg_bool() {
  uint16_t raw = get_en_chg_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_CHG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_chg_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_CHG to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_CHG);
  this->set_en_chg_raw(raw_value);
};

// EN_ICO - Enable the ICO (Input Current Optimizer)
uint16_t BQ25798Component::get_en_ico_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_ico_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_ICO to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0F_Charger_Control_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_ico_bool() {
  uint16_t raw = get_en_ico_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_ICO);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_ico_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_ICO to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_ICO);
  this->set_en_ico_raw(raw_value);
};

// FORCE_ICO - Force the ICO (Input Current Optimizer)
uint16_t BQ25798Component::get_force_ico_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_force_ico_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting FORCE_ICO to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0F_Charger_Control_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_force_ico_bool() {
  uint16_t raw = get_force_ico_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->FORCE_ICO);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_force_ico_bool(bool value) {
  ESP_LOGD(TAG, "Setting FORCE_ICO to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->FORCE_ICO);
  this->set_force_ico_raw(raw_value);
};

// EN_HIZ - Enable the high impedance mode
uint16_t BQ25798Component::get_en_hiz_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_hiz_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_HIZ to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0F_Charger_Control_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_hiz_bool() {
  uint16_t raw = get_en_hiz_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_HIZ);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_hiz_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_HIZ to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_HIZ);
  this->set_en_hiz_raw(raw_value);
};

// EN_TERM - Enable the termination
uint16_t BQ25798Component::get_en_term_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_term_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_TERM to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0F_Charger_Control_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_term_bool() {
  uint16_t raw = get_en_term_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_TERM);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_term_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_TERM to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_TERM);
  this->set_en_term_raw(raw_value);
};

// EN_BACKUP - Enable the backup (auto OTG) mode
uint16_t BQ25798Component::get_en_backup_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_backup_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_BACKUP to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG0F_Charger_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG0F_Charger_Control_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_backup_bool() {
  uint16_t raw = get_en_backup_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_BACKUP);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_backup_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_BACKUP to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_BACKUP);
  this->set_en_backup_raw(raw_value);
};

// VBUS_BACKUP - The thresholds to trigger the backup mode, defined as a ratio of VINDPM
uint16_t BQ25798Component::get_vbus_backup_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG10_Charger_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_vbus_backup_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VBUS_BACKUP to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG10_Charger_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG10_Charger_Control_1 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_vbus_backup_enum_int() {
  uint16_t raw = get_vbus_backup_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBUS_BACKUP);
}
const char* BQ25798Component::get_vbus_backup_enum_string() {
  uint16_t raw = get_vbus_backup_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VBUS_BACKUP);
}

void BQ25798Component::set_vbus_backup_enum_int(int value) {
  ESP_LOGD(TAG, "Setting VBUS_BACKUP to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VBUS_BACKUP);
  this->set_vbus_backup_raw(raw_value);
};

// VAC_OVP - Over voltage protection thresholds
uint16_t BQ25798Component::get_vac_ovp_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG10_Charger_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_vac_ovp_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VAC_OVP to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG10_Charger_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG10_Charger_Control_1 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_vac_ovp_enum_int() {
  uint16_t raw = get_vac_ovp_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VAC_OVP);
}
const char* BQ25798Component::get_vac_ovp_enum_string() {
  uint16_t raw = get_vac_ovp_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VAC_OVP);
}

void BQ25798Component::set_vac_ovp_enum_int(int value) {
  ESP_LOGD(TAG, "Setting VAC_OVP to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VAC_OVP);
  this->set_vac_ovp_raw(raw_value);
};

// WD_RST - I2C watch dog timer reset
uint16_t BQ25798Component::get_wd_rst_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG10_Charger_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_wd_rst_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting WD_RST to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG10_Charger_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG10_Charger_Control_1 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_wd_rst_bool() {
  uint16_t raw = get_wd_rst_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->WD_RST);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_wd_rst_bool(bool value) {
  ESP_LOGD(TAG, "Setting WD_RST to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->WD_RST);
  this->set_wd_rst_raw(raw_value);
};

// WATCHDOG - Watchdog timer settings
uint16_t BQ25798Component::get_watchdog_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG10_Charger_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(3);
}

void BQ25798Component::set_watchdog_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting WATCHDOG to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG10_Charger_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG10_Charger_Control_1 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_watchdog_enum_int() {
  uint16_t raw = get_watchdog_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->WATCHDOG);
}
const char* BQ25798Component::get_watchdog_enum_string() {
  uint16_t raw = get_watchdog_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->WATCHDOG);
}

void BQ25798Component::set_watchdog_enum_int(int value) {
  ESP_LOGD(TAG, "Setting WATCHDOG to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->WATCHDOG);
  this->set_watchdog_raw(raw_value);
};

// FORCE_INDET - Force D+/D- detection
uint16_t BQ25798Component::get_force_indet_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG11_Charger_Control_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_force_indet_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting FORCE_INDET to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG11_Charger_Control_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG11_Charger_Control_2 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_force_indet_bool() {
  uint16_t raw = get_force_indet_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->FORCE_INDET);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_force_indet_bool(bool value) {
  ESP_LOGD(TAG, "Setting FORCE_INDET to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->FORCE_INDET);
  this->set_force_indet_raw(raw_value);
};

// AUTO_INDET_EN - Enable automatic D+/D- detection
uint16_t BQ25798Component::get_auto_indet_en_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG11_Charger_Control_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_auto_indet_en_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting AUTO_INDET_EN to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG11_Charger_Control_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG11_Charger_Control_2 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_auto_indet_en_bool() {
  uint16_t raw = get_auto_indet_en_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->AUTO_INDET_EN);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_auto_indet_en_bool(bool value) {
  ESP_LOGD(TAG, "Setting AUTO_INDET_EN to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->AUTO_INDET_EN);
  this->set_auto_indet_en_raw(raw_value);
};

// EN_12V - Enable 12V output in HVDCP
uint16_t BQ25798Component::get_en_12v_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG11_Charger_Control_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_12v_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_12V to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG11_Charger_Control_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG11_Charger_Control_2 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_12v_bool() {
  uint16_t raw = get_en_12v_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_12V);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_12v_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_12V to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_12V);
  this->set_en_12v_raw(raw_value);
};

// EN_9V - Enable 9V output in HVDCP
uint16_t BQ25798Component::get_en_9v_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG11_Charger_Control_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_9v_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_9V to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG11_Charger_Control_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG11_Charger_Control_2 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_9v_bool() {
  uint16_t raw = get_en_9v_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_9V);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_9v_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_9V to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_9V);
  this->set_en_9v_raw(raw_value);
};

// HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
uint16_t BQ25798Component::get_hvdcp_en_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG11_Charger_Control_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_hvdcp_en_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting HVDCP_EN to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG11_Charger_Control_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG11_Charger_Control_2 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_hvdcp_en_bool() {
  uint16_t raw = get_hvdcp_en_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->HVDCP_EN);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_hvdcp_en_bool(bool value) {
  ESP_LOGD(TAG, "Setting HVDCP_EN to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->HVDCP_EN);
  this->set_hvdcp_en_raw(raw_value);
};

// SDRV_CTRL - Enable external Ship FET control
uint16_t BQ25798Component::get_sdrv_ctrl_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG11_Charger_Control_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_sdrv_ctrl_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting SDRV_CTRL to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG11_Charger_Control_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG11_Charger_Control_2 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_sdrv_ctrl_enum_int() {
  uint16_t raw = get_sdrv_ctrl_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->SDRV_CTRL);
}
const char* BQ25798Component::get_sdrv_ctrl_enum_string() {
  uint16_t raw = get_sdrv_ctrl_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->SDRV_CTRL);
}

void BQ25798Component::set_sdrv_ctrl_enum_int(int value) {
  ESP_LOGD(TAG, "Setting SDRV_CTRL to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->SDRV_CTRL);
  this->set_sdrv_ctrl_raw(raw_value);
};

// SDRV_DLY - Delay for SDRV control
uint16_t BQ25798Component::get_sdrv_dly_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG11_Charger_Control_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_sdrv_dly_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting SDRV_DLY to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG11_Charger_Control_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG11_Charger_Control_2 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_sdrv_dly_bool() {
  uint16_t raw = get_sdrv_dly_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->SDRV_DLY);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_sdrv_dly_enum_int() {
  uint16_t raw = get_sdrv_dly_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->SDRV_DLY);
}
const char* BQ25798Component::get_sdrv_dly_enum_string() {
  uint16_t raw = get_sdrv_dly_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->SDRV_DLY);
}

void BQ25798Component::set_sdrv_dly_bool(bool value) {
  ESP_LOGD(TAG, "Setting SDRV_DLY to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->SDRV_DLY);
  this->set_sdrv_dly_raw(raw_value);
};

void BQ25798Component::set_sdrv_dly_enum_int(int value) {
  ESP_LOGD(TAG, "Setting SDRV_DLY to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->SDRV_DLY);
  this->set_sdrv_dly_raw(raw_value);
};

// DIS_ACDRV - Disable both AC1 and AC2 drivers
uint16_t BQ25798Component::get_dis_acdrv_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_dis_acdrv_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting DIS_ACDRV to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG12_Charger_Control_3 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_dis_acdrv_bool() {
  uint16_t raw = get_dis_acdrv_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DIS_ACDRV);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dis_acdrv_bool(bool value) {
  ESP_LOGD(TAG, "Setting DIS_ACDRV to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DIS_ACDRV);
  this->set_dis_acdrv_raw(raw_value);
};

// EN_OTG - Enable OTG mode
uint16_t BQ25798Component::get_en_otg_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_otg_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_OTG to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG12_Charger_Control_3 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_otg_bool() {
  uint16_t raw = get_en_otg_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_OTG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_otg_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_OTG to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_OTG);
  this->set_en_otg_raw(raw_value);
};

// PFM_OTG_DIS - Disable PFM in OTG mode
uint16_t BQ25798Component::get_pfm_otg_dis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_pfm_otg_dis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting PFM_OTG_DIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG12_Charger_Control_3 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_pfm_otg_dis_bool() {
  uint16_t raw = get_pfm_otg_dis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PFM_OTG_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_pfm_otg_dis_bool(bool value) {
  ESP_LOGD(TAG, "Setting PFM_OTG_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->PFM_OTG_DIS);
  this->set_pfm_otg_dis_raw(raw_value);
};

// PFM_FWD_DIS - Disable PFM in forward mode
uint16_t BQ25798Component::get_pfm_fwd_dis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_pfm_fwd_dis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting PFM_FWD_DIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG12_Charger_Control_3 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_pfm_fwd_dis_bool() {
  uint16_t raw = get_pfm_fwd_dis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PFM_FWD_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_pfm_fwd_dis_bool(bool value) {
  ESP_LOGD(TAG, "Setting PFM_FWD_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->PFM_FWD_DIS);
  this->set_pfm_fwd_dis_raw(raw_value);
};

// WKUP_DLY - Wakeup (Ship FET) delay
uint16_t BQ25798Component::get_wkup_dly_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_wkup_dly_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting WKUP_DLY to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG12_Charger_Control_3 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_wkup_dly_bool() {
  uint16_t raw = get_wkup_dly_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->WKUP_DLY);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_wkup_dly_enum_int() {
  uint16_t raw = get_wkup_dly_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->WKUP_DLY);
}
const char* BQ25798Component::get_wkup_dly_enum_string() {
  uint16_t raw = get_wkup_dly_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->WKUP_DLY);
}

void BQ25798Component::set_wkup_dly_bool(bool value) {
  ESP_LOGD(TAG, "Setting WKUP_DLY to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->WKUP_DLY);
  this->set_wkup_dly_raw(raw_value);
};

void BQ25798Component::set_wkup_dly_enum_int(int value) {
  ESP_LOGD(TAG, "Setting WKUP_DLY to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->WKUP_DLY);
  this->set_wkup_dly_raw(raw_value);
};

// DIS_LDO - Disable BATFET LDO mode in precharge state
uint16_t BQ25798Component::get_dis_ldo_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_dis_ldo_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting DIS_LDO to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG12_Charger_Control_3 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_dis_ldo_bool() {
  uint16_t raw = get_dis_ldo_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DIS_LDO);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dis_ldo_bool(bool value) {
  ESP_LOGD(TAG, "Setting DIS_LDO to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DIS_LDO);
  this->set_dis_ldo_raw(raw_value);
};

// DIS_OTG_OOA - Disable OOA in OTG mode
uint16_t BQ25798Component::get_dis_otg_ooa_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_dis_otg_ooa_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting DIS_OTG_OOA to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG12_Charger_Control_3 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_dis_otg_ooa_bool() {
  uint16_t raw = get_dis_otg_ooa_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DIS_OTG_OOA);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dis_otg_ooa_bool(bool value) {
  ESP_LOGD(TAG, "Setting DIS_OTG_OOA to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DIS_OTG_OOA);
  this->set_dis_otg_ooa_raw(raw_value);
};

// DIS_FWD_OOA - Disable OOA in forward mode
uint16_t BQ25798Component::get_dis_fwd_ooa_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_dis_fwd_ooa_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting DIS_FWD_OOA to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG12_Charger_Control_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG12_Charger_Control_3 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_dis_fwd_ooa_bool() {
  uint16_t raw = get_dis_fwd_ooa_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DIS_FWD_OOA);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dis_fwd_ooa_bool(bool value) {
  ESP_LOGD(TAG, "Setting DIS_FWD_OOA to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DIS_FWD_OOA);
  this->set_dis_fwd_ooa_raw(raw_value);
};

// EN_ACDRV2 - Enable AC2 gate driver control
uint16_t BQ25798Component::get_en_acdrv2_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_acdrv2_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_ACDRV2 to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG13_Charger_Control_4 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_acdrv2_bool() {
  uint16_t raw = get_en_acdrv2_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_ACDRV2);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_acdrv2_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_ACDRV2 to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_ACDRV2);
  this->set_en_acdrv2_raw(raw_value);
};

// EN_ACDRV1 - Enable AC1 gate driver control
uint16_t BQ25798Component::get_en_acdrv1_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_acdrv1_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_ACDRV1 to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG13_Charger_Control_4 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_acdrv1_bool() {
  uint16_t raw = get_en_acdrv1_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_ACDRV1);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_acdrv1_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_ACDRV1 to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_ACDRV1);
  this->set_en_acdrv1_raw(raw_value);
};

// PWM_FREQ - PWM frequency setting
uint16_t BQ25798Component::get_pwm_freq_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_pwm_freq_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting PWM_FREQ to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG13_Charger_Control_4 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_pwm_freq_bool() {
  uint16_t raw = get_pwm_freq_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PWM_FREQ);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_pwm_freq_enum_int() {
  uint16_t raw = get_pwm_freq_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->PWM_FREQ);
}
const char* BQ25798Component::get_pwm_freq_enum_string() {
  uint16_t raw = get_pwm_freq_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->PWM_FREQ);
}

void BQ25798Component::set_pwm_freq_bool(bool value) {
  ESP_LOGD(TAG, "Setting PWM_FREQ to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->PWM_FREQ);
  this->set_pwm_freq_raw(raw_value);
};

void BQ25798Component::set_pwm_freq_enum_int(int value) {
  ESP_LOGD(TAG, "Setting PWM_FREQ to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->PWM_FREQ);
  this->set_pwm_freq_raw(raw_value);
};

// DIS_STAT - Disable STAT pin output
uint16_t BQ25798Component::get_dis_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_dis_stat_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting DIS_STAT to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG13_Charger_Control_4 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_dis_stat_bool() {
  uint16_t raw = get_dis_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DIS_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dis_stat_bool(bool value) {
  ESP_LOGD(TAG, "Setting DIS_STAT to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DIS_STAT);
  this->set_dis_stat_raw(raw_value);
};

// DIS_VSYS_SHORT - Disable VSYS short hiccup protection
uint16_t BQ25798Component::get_dis_vsys_short_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_dis_vsys_short_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting DIS_VSYS_SHORT to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG13_Charger_Control_4 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_dis_vsys_short_bool() {
  uint16_t raw = get_dis_vsys_short_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DIS_VSYS_SHORT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dis_vsys_short_bool(bool value) {
  ESP_LOGD(TAG, "Setting DIS_VSYS_SHORT to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DIS_VSYS_SHORT);
  this->set_dis_vsys_short_raw(raw_value);
};

// DIS_VOTG_UVP - Disable VOTG under voltage hiccup protection
uint16_t BQ25798Component::get_dis_votg_uvp_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_dis_votg_uvp_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting DIS_VOTG_UVP to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG13_Charger_Control_4 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_dis_votg_uvp_bool() {
  uint16_t raw = get_dis_votg_uvp_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DIS_VOTG_UVP);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dis_votg_uvp_bool(bool value) {
  ESP_LOGD(TAG, "Setting DIS_VOTG_UVP to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DIS_VOTG_UVP);
  this->set_dis_votg_uvp_raw(raw_value);
};

// FORCE_VINDPM_DET - Force VINDPM detection (settable only when VBAT>VSYSMIN)
uint16_t BQ25798Component::get_force_vindpm_det_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_force_vindpm_det_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting FORCE_VINDPM_DET to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG13_Charger_Control_4 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_force_vindpm_det_bool() {
  uint16_t raw = get_force_vindpm_det_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->FORCE_VINDPM_DET);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_force_vindpm_det_bool(bool value) {
  ESP_LOGD(TAG, "Setting FORCE_VINDPM_DET to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->FORCE_VINDPM_DET);
  this->set_force_vindpm_det_raw(raw_value);
};

// EN_IBUS_OCP - Enable input over current protection in forward mode
uint16_t BQ25798Component::get_en_ibus_ocp_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_ibus_ocp_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_IBUS_OCP to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG13_Charger_Control_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG13_Charger_Control_4 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_ibus_ocp_bool() {
  uint16_t raw = get_en_ibus_ocp_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_IBUS_OCP);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_ibus_ocp_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_IBUS_OCP to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_IBUS_OCP);
  this->set_en_ibus_ocp_raw(raw_value);
};

// SFET_PRESENT - Ship FET present
uint16_t BQ25798Component::get_sfet_present_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG14_Charger_Control_5);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_sfet_present_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting SFET_PRESENT to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG14_Charger_Control_5);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG14_Charger_Control_5 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_sfet_present_bool() {
  uint16_t raw = get_sfet_present_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->SFET_PRESENT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_sfet_present_bool(bool value) {
  ESP_LOGD(TAG, "Setting SFET_PRESENT to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->SFET_PRESENT);
  this->set_sfet_present_raw(raw_value);
};

// EN_IBAT - Enable battery discharge current sensing
uint16_t BQ25798Component::get_en_ibat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG14_Charger_Control_5);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_ibat_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_IBAT to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG14_Charger_Control_5);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG14_Charger_Control_5 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_ibat_bool() {
  uint16_t raw = get_en_ibat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_IBAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_ibat_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_IBAT to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_IBAT);
  this->set_en_ibat_raw(raw_value);
};

// IBAT_REG - Battery discharge current regulation in OTG mode
uint16_t BQ25798Component::get_ibat_reg_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG14_Charger_Control_5);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_ibat_reg_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting IBAT_REG to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG14_Charger_Control_5);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 3);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 3);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG14_Charger_Control_5 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_ibat_reg_enum_int() {
  uint16_t raw = get_ibat_reg_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->IBAT_REG);
}
const char* BQ25798Component::get_ibat_reg_enum_string() {
  uint16_t raw = get_ibat_reg_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->IBAT_REG);
}

void BQ25798Component::set_ibat_reg_enum_int(int value) {
  ESP_LOGD(TAG, "Setting IBAT_REG to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->IBAT_REG);
  this->set_ibat_reg_raw(raw_value);
};

// EN_IINDPM - Enable input current regulation
uint16_t BQ25798Component::get_en_iindpm_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG14_Charger_Control_5);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_iindpm_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_IINDPM to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG14_Charger_Control_5);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG14_Charger_Control_5 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_iindpm_bool() {
  uint16_t raw = get_en_iindpm_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_IINDPM);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_iindpm_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_IINDPM to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_IINDPM);
  this->set_en_iindpm_raw(raw_value);
};

// EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
uint16_t BQ25798Component::get_en_extilim_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG14_Charger_Control_5);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_extilim_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_EXTILIM to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG14_Charger_Control_5);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG14_Charger_Control_5 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_extilim_bool() {
  uint16_t raw = get_en_extilim_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_EXTILIM);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_extilim_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_EXTILIM to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_EXTILIM);
  this->set_en_extilim_raw(raw_value);
};

// EN_BATOC - Enable battery discharging over current protection
uint16_t BQ25798Component::get_en_batoc_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG14_Charger_Control_5);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_batoc_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_BATOC to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG14_Charger_Control_5);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG14_Charger_Control_5 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_batoc_bool() {
  uint16_t raw = get_en_batoc_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_BATOC);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_batoc_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_BATOC to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_BATOC);
  this->set_en_batoc_raw(raw_value);
};

// VOC_PCT - Set VINDPM as a percentage of the VBUS open circuit voltage when the VOC measurement is done
uint16_t BQ25798Component::get_voc_pct_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG15_MPPT_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(3);
}

void BQ25798Component::set_voc_pct_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VOC_PCT to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG15_MPPT_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG15_MPPT_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_voc_pct_enum_int() {
  uint16_t raw = get_voc_pct_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VOC_PCT);
}
const char* BQ25798Component::get_voc_pct_enum_string() {
  uint16_t raw = get_voc_pct_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VOC_PCT);
}

void BQ25798Component::set_voc_pct_enum_int(int value) {
  ESP_LOGD(TAG, "Setting VOC_PCT to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VOC_PCT);
  this->set_voc_pct_raw(raw_value);
};

// VOC_DLY - After the converter stops switching, the time delay before the VOC is measured
uint16_t BQ25798Component::get_voc_dly_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG15_MPPT_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_voc_dly_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VOC_DLY to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG15_MPPT_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG15_MPPT_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_voc_dly_enum_int() {
  uint16_t raw = get_voc_dly_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VOC_DLY);
}
const char* BQ25798Component::get_voc_dly_enum_string() {
  uint16_t raw = get_voc_dly_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VOC_DLY);
}

void BQ25798Component::set_voc_dly_enum_int(int value) {
  ESP_LOGD(TAG, "Setting VOC_DLY to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VOC_DLY);
  this->set_voc_dly_raw(raw_value);
};

// VOC_RATE - The time interval between two consecutive VOC measurements
uint16_t BQ25798Component::get_voc_rate_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG15_MPPT_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_voc_rate_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VOC_RATE to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG15_MPPT_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 2);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 2);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG15_MPPT_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_voc_rate_enum_int() {
  uint16_t raw = get_voc_rate_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VOC_RATE);
}
const char* BQ25798Component::get_voc_rate_enum_string() {
  uint16_t raw = get_voc_rate_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VOC_RATE);
}

void BQ25798Component::set_voc_rate_enum_int(int value) {
  ESP_LOGD(TAG, "Setting VOC_RATE to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->VOC_RATE);
  this->set_voc_rate_raw(raw_value);
};

// EN_MPPT - Enable MPPT (Maximum Power Point Tracking)
uint16_t BQ25798Component::get_en_mppt_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG15_MPPT_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_en_mppt_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting EN_MPPT to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG15_MPPT_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG15_MPPT_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_en_mppt_bool() {
  uint16_t raw = get_en_mppt_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->EN_MPPT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_en_mppt_bool(bool value) {
  ESP_LOGD(TAG, "Setting EN_MPPT to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->EN_MPPT);
  this->set_en_mppt_raw(raw_value);
};

// TREG - Thermal regulation thresholds
uint16_t BQ25798Component::get_treg_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG16_Temperature_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_treg_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting TREG to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG16_Temperature_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG16_Temperature_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_treg_enum_int() {
  uint16_t raw = get_treg_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TREG);
}
const char* BQ25798Component::get_treg_enum_string() {
  uint16_t raw = get_treg_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TREG);
}

void BQ25798Component::set_treg_enum_int(int value) {
  ESP_LOGD(TAG, "Setting TREG to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->TREG);
  this->set_treg_raw(raw_value);
};

// TSHUT - Thermal shutdown thresholds
uint16_t BQ25798Component::get_tshut_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG16_Temperature_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_tshut_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting TSHUT to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG16_Temperature_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG16_Temperature_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_tshut_enum_int() {
  uint16_t raw = get_tshut_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TSHUT);
}
const char* BQ25798Component::get_tshut_enum_string() {
  uint16_t raw = get_tshut_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TSHUT);
}

void BQ25798Component::set_tshut_enum_int(int value) {
  ESP_LOGD(TAG, "Setting TSHUT to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->TSHUT);
  this->set_tshut_raw(raw_value);
};

// VBUS_PD_EN - Enable VBUS pull down resistor (6 kOhm)
uint16_t BQ25798Component::get_vbus_pd_en_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG16_Temperature_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_vbus_pd_en_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VBUS_PD_EN to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG16_Temperature_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG16_Temperature_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_vbus_pd_en_bool() {
  uint16_t raw = get_vbus_pd_en_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBUS_PD_EN);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vbus_pd_en_bool(bool value) {
  ESP_LOGD(TAG, "Setting VBUS_PD_EN to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VBUS_PD_EN);
  this->set_vbus_pd_en_raw(raw_value);
};

// VAC1_PD_EN - Enable VAC1 pull down resistor
uint16_t BQ25798Component::get_vac1_pd_en_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG16_Temperature_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_vac1_pd_en_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VAC1_PD_EN to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG16_Temperature_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG16_Temperature_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_vac1_pd_en_bool() {
  uint16_t raw = get_vac1_pd_en_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC1_PD_EN);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vac1_pd_en_bool(bool value) {
  ESP_LOGD(TAG, "Setting VAC1_PD_EN to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VAC1_PD_EN);
  this->set_vac1_pd_en_raw(raw_value);
};

// VAC2_PD_EN - Enable VAC2 pull down resistor
uint16_t BQ25798Component::get_vac2_pd_en_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG16_Temperature_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_vac2_pd_en_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VAC2_PD_EN to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG16_Temperature_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG16_Temperature_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_vac2_pd_en_bool() {
  uint16_t raw = get_vac2_pd_en_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC2_PD_EN);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vac2_pd_en_bool(bool value) {
  ESP_LOGD(TAG, "Setting VAC2_PD_EN to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VAC2_PD_EN);
  this->set_vac2_pd_en_raw(raw_value);
};

// BKUP_ACFET1_ON - Enable ACFET1 in backup mode (exit backup mode)
uint16_t BQ25798Component::get_bkup_acfet1_on_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG16_Temperature_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_bkup_acfet1_on_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting BKUP_ACFET1_ON to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG16_Temperature_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG16_Temperature_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_bkup_acfet1_on_bool() {
  uint16_t raw = get_bkup_acfet1_on_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->BKUP_ACFET1_ON);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_bkup_acfet1_on_bool(bool value) {
  ESP_LOGD(TAG, "Setting BKUP_ACFET1_ON to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->BKUP_ACFET1_ON);
  this->set_bkup_acfet1_on_raw(raw_value);
};

// JEITA_VSET - JEITA high temperature range (TWARN - THOT) charge voltage setting
uint16_t BQ25798Component::get_jeita_vset_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG17_NTC_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(3);
}

void BQ25798Component::set_jeita_vset_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting JEITA_VSET to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG17_NTC_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG17_NTC_Control_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_jeita_vset_enum_int() {
  uint16_t raw = get_jeita_vset_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->JEITA_VSET);
}
const char* BQ25798Component::get_jeita_vset_enum_string() {
  uint16_t raw = get_jeita_vset_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->JEITA_VSET);
}

void BQ25798Component::set_jeita_vset_enum_int(int value) {
  ESP_LOGD(TAG, "Setting JEITA_VSET to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->JEITA_VSET);
  this->set_jeita_vset_raw(raw_value);
};

// JEITA_ISETH - JEITA high temperature range (TWARN - THOT) charge current setting
uint16_t BQ25798Component::get_jeita_iseth_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG17_NTC_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_jeita_iseth_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting JEITA_ISETH to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG17_NTC_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 3);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 3);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG17_NTC_Control_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_jeita_iseth_enum_int() {
  uint16_t raw = get_jeita_iseth_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->JEITA_ISETH);
}
const char* BQ25798Component::get_jeita_iseth_enum_string() {
  uint16_t raw = get_jeita_iseth_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->JEITA_ISETH);
}

void BQ25798Component::set_jeita_iseth_enum_int(int value) {
  ESP_LOGD(TAG, "Setting JEITA_ISETH to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->JEITA_ISETH);
  this->set_jeita_iseth_raw(raw_value);
};

// JEITA_ISETC - JEITA low temperature range (TCOLD - TWARN) charge current setting
uint16_t BQ25798Component::get_jeita_isetc_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG17_NTC_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_jeita_isetc_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting JEITA_ISETC to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG17_NTC_Control_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG17_NTC_Control_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_jeita_isetc_enum_int() {
  uint16_t raw = get_jeita_isetc_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->JEITA_ISETC);
}
const char* BQ25798Component::get_jeita_isetc_enum_string() {
  uint16_t raw = get_jeita_isetc_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->JEITA_ISETC);
}

void BQ25798Component::set_jeita_isetc_enum_int(int value) {
  ESP_LOGD(TAG, "Setting JEITA_ISETC to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->JEITA_ISETC);
  this->set_jeita_isetc_raw(raw_value);
};

// TS_COOL - JEITA VT2 comparator voltage rising thresholds as a percentage of REGN.
uint16_t BQ25798Component::get_ts_cool_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG18_NTC_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_ts_cool_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting TS_COOL to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG18_NTC_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG18_NTC_Control_1 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_ts_cool_enum_int() {
  uint16_t raw = get_ts_cool_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TS_COOL);
}
const char* BQ25798Component::get_ts_cool_enum_string() {
  uint16_t raw = get_ts_cool_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TS_COOL);
}

void BQ25798Component::set_ts_cool_enum_int(int value) {
  ESP_LOGD(TAG, "Setting TS_COOL to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->TS_COOL);
  this->set_ts_cool_raw(raw_value);
};

// TS_WARM - JEITA VT3 comparator voltage falling thresholds as a percentage of REGN.
uint16_t BQ25798Component::get_ts_warm_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG18_NTC_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_ts_warm_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting TS_WARM to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG18_NTC_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG18_NTC_Control_1 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_ts_warm_enum_int() {
  uint16_t raw = get_ts_warm_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TS_WARM);
}
const char* BQ25798Component::get_ts_warm_enum_string() {
  uint16_t raw = get_ts_warm_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TS_WARM);
}

void BQ25798Component::set_ts_warm_enum_int(int value) {
  ESP_LOGD(TAG, "Setting TS_WARM to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->TS_WARM);
  this->set_ts_warm_raw(raw_value);
};

// BHOT - OTG mode TS HOT temperature threshold
uint16_t BQ25798Component::get_bhot_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG18_NTC_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_bhot_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting BHOT to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG18_NTC_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 2);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 2);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG18_NTC_Control_1 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_bhot_enum_int() {
  uint16_t raw = get_bhot_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->BHOT);
}
const char* BQ25798Component::get_bhot_enum_string() {
  uint16_t raw = get_bhot_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->BHOT);
}

void BQ25798Component::set_bhot_enum_int(int value) {
  ESP_LOGD(TAG, "Setting BHOT to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->BHOT);
  this->set_bhot_raw(raw_value);
};

// BCOLD - OTG mode TS COLD temperature threshold
uint16_t BQ25798Component::get_bcold_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG18_NTC_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_bcold_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting BCOLD to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG18_NTC_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG18_NTC_Control_1 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_bcold_bool() {
  uint16_t raw = get_bcold_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->BCOLD);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_bcold_enum_int() {
  uint16_t raw = get_bcold_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->BCOLD);
}
const char* BQ25798Component::get_bcold_enum_string() {
  uint16_t raw = get_bcold_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->BCOLD);
}

void BQ25798Component::set_bcold_bool(bool value) {
  ESP_LOGD(TAG, "Setting BCOLD to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->BCOLD);
  this->set_bcold_raw(raw_value);
};

void BQ25798Component::set_bcold_enum_int(int value) {
  ESP_LOGD(TAG, "Setting BCOLD to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->BCOLD);
  this->set_bcold_raw(raw_value);
};

// TS_IGNORE - Ignore TS detection (the charger considers the TS is always good)
uint16_t BQ25798Component::get_ts_ignore_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG18_NTC_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_ts_ignore_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting TS_IGNORE to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG18_NTC_Control_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG18_NTC_Control_1 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_ts_ignore_bool() {
  uint16_t raw = get_ts_ignore_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_IGNORE);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_ts_ignore_bool(bool value) {
  ESP_LOGD(TAG, "Setting TS_IGNORE to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->TS_IGNORE);
  this->set_ts_ignore_raw(raw_value);
};

// ICO_ILIM - Input Current Limit obtained from ICO or ILIM_HIZ pin setting
uint16_t BQ25798Component::get_ico_ilim_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG19_ICO_Current_Limit);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(9);
}

int BQ25798Component::get_ico_ilim_int() {
  uint16_t raw = get_ico_ilim_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ICO_ILIM);
}

// IINDPM_STAT - IINDPM status (forward mode) or IOTG status (OTG mode)
uint16_t BQ25798Component::get_iindpm_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1B_Charger_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_iindpm_stat_bool() {
  uint16_t raw = get_iindpm_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IINDPM_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_iindpm_stat_enum_int() {
  uint16_t raw = get_iindpm_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->IINDPM_STAT);
}
const char* BQ25798Component::get_iindpm_stat_enum_string() {
  uint16_t raw = get_iindpm_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->IINDPM_STAT);
}

// VINDPM_STAT - VINDPM status (forward mode) or VOTG status (OTG mode)
uint16_t BQ25798Component::get_vindpm_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1B_Charger_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vindpm_stat_bool() {
  uint16_t raw = get_vindpm_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VINDPM_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_vindpm_stat_enum_int() {
  uint16_t raw = get_vindpm_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VINDPM_STAT);
}
const char* BQ25798Component::get_vindpm_stat_enum_string() {
  uint16_t raw = get_vindpm_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VINDPM_STAT);
}

// WD_STAT - Watchdog timer status
uint16_t BQ25798Component::get_wd_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1B_Charger_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_wd_stat_bool() {
  uint16_t raw = get_wd_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->WD_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_wd_stat_enum_int() {
  uint16_t raw = get_wd_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->WD_STAT);
}
const char* BQ25798Component::get_wd_stat_enum_string() {
  uint16_t raw = get_wd_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->WD_STAT);
}

// PG_STAT - Power good status
uint16_t BQ25798Component::get_pg_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1B_Charger_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_pg_stat_bool() {
  uint16_t raw = get_pg_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PG_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_pg_stat_enum_int() {
  uint16_t raw = get_pg_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->PG_STAT);
}
const char* BQ25798Component::get_pg_stat_enum_string() {
  uint16_t raw = get_pg_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->PG_STAT);
}

// AC2_PRESENT_STAT - VAC2 present status
uint16_t BQ25798Component::get_ac2_present_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1B_Charger_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ac2_present_stat_bool() {
  uint16_t raw = get_ac2_present_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->AC2_PRESENT_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_ac2_present_stat_enum_int() {
  uint16_t raw = get_ac2_present_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->AC2_PRESENT_STAT);
}
const char* BQ25798Component::get_ac2_present_stat_enum_string() {
  uint16_t raw = get_ac2_present_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->AC2_PRESENT_STAT);
}

// AC1_PRESENT_STAT - VAC1 present status
uint16_t BQ25798Component::get_ac1_present_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1B_Charger_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ac1_present_stat_bool() {
  uint16_t raw = get_ac1_present_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->AC1_PRESENT_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_ac1_present_stat_enum_int() {
  uint16_t raw = get_ac1_present_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->AC1_PRESENT_STAT);
}
const char* BQ25798Component::get_ac1_present_stat_enum_string() {
  uint16_t raw = get_ac1_present_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->AC1_PRESENT_STAT);
}

// VBUS_PRESENT_STAT - VBUS present status
uint16_t BQ25798Component::get_vbus_present_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1B_Charger_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vbus_present_stat_bool() {
  uint16_t raw = get_vbus_present_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBUS_PRESENT_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_vbus_present_stat_enum_int() {
  uint16_t raw = get_vbus_present_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBUS_PRESENT_STAT);
}
const char* BQ25798Component::get_vbus_present_stat_enum_string() {
  uint16_t raw = get_vbus_present_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VBUS_PRESENT_STAT);
}

// CHG_STAT - Charge Status bits
uint16_t BQ25798Component::get_chg_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1C_Charger_Status_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(3);
}

int BQ25798Component::get_chg_stat_enum_int() {
  uint16_t raw = get_chg_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->CHG_STAT);
}
const char* BQ25798Component::get_chg_stat_enum_string() {
  uint16_t raw = get_chg_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->CHG_STAT);
}

// VBUS_STAT - VBUS status bits
uint16_t BQ25798Component::get_vbus_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1C_Charger_Status_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(4);
}

int BQ25798Component::get_vbus_stat_enum_int() {
  uint16_t raw = get_vbus_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBUS_STAT);
}
const char* BQ25798Component::get_vbus_stat_enum_string() {
  uint16_t raw = get_vbus_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VBUS_STAT);
}

// BC12_DONE_STAT - BC1.2 detection done status
uint16_t BQ25798Component::get_bc12_done_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1C_Charger_Status_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_bc12_done_stat_bool() {
  uint16_t raw = get_bc12_done_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->BC12_DONE_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// ICO_STAT - Input Current Optimizer (ICO) status
uint16_t BQ25798Component::get_ico_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1D_Charger_Status_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(2);
}

int BQ25798Component::get_ico_stat_enum_int() {
  uint16_t raw = get_ico_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ICO_STAT);
}
const char* BQ25798Component::get_ico_stat_enum_string() {
  uint16_t raw = get_ico_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->ICO_STAT);
}

// TREG_STAT - IC thermal regulation status
uint16_t BQ25798Component::get_treg_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1D_Charger_Status_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_treg_stat_bool() {
  uint16_t raw = get_treg_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TREG_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_treg_stat_enum_int() {
  uint16_t raw = get_treg_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TREG_STAT);
}
const char* BQ25798Component::get_treg_stat_enum_string() {
  uint16_t raw = get_treg_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TREG_STAT);
}

// DPDM_STAT - D+/D- detection status
uint16_t BQ25798Component::get_dpdm_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1D_Charger_Status_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_dpdm_stat_bool() {
  uint16_t raw = get_dpdm_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DPDM_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_dpdm_stat_enum_int() {
  uint16_t raw = get_dpdm_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->DPDM_STAT);
}
const char* BQ25798Component::get_dpdm_stat_enum_string() {
  uint16_t raw = get_dpdm_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->DPDM_STAT);
}

// VBAT_PRESENT_STAT - Battery present status
uint16_t BQ25798Component::get_vbat_present_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1D_Charger_Status_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vbat_present_stat_bool() {
  uint16_t raw = get_vbat_present_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBAT_PRESENT_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_vbat_present_stat_enum_int() {
  uint16_t raw = get_vbat_present_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBAT_PRESENT_STAT);
}
const char* BQ25798Component::get_vbat_present_stat_enum_string() {
  uint16_t raw = get_vbat_present_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VBAT_PRESENT_STAT);
}

// ACRB2_STAT - The ACFET2-RBFET2 status
uint16_t BQ25798Component::get_acrb2_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1E_Charger_Status_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_acrb2_stat_bool() {
  uint16_t raw = get_acrb2_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ACRB2_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_acrb2_stat_enum_int() {
  uint16_t raw = get_acrb2_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ACRB2_STAT);
}
const char* BQ25798Component::get_acrb2_stat_enum_string() {
  uint16_t raw = get_acrb2_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->ACRB2_STAT);
}

// ACRB1_STAT - The ACFET1-RBFET1 status
uint16_t BQ25798Component::get_acrb1_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1E_Charger_Status_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_acrb1_stat_bool() {
  uint16_t raw = get_acrb1_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ACRB1_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_acrb1_stat_enum_int() {
  uint16_t raw = get_acrb1_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ACRB1_STAT);
}
const char* BQ25798Component::get_acrb1_stat_enum_string() {
  uint16_t raw = get_acrb1_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->ACRB1_STAT);
}

// ADC_DONE_STAT - ADC Conversion Status
uint16_t BQ25798Component::get_adc_done_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1E_Charger_Status_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_adc_done_stat_bool() {
  uint16_t raw = get_adc_done_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ADC_DONE_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VSYS_STAT - VSYS Regulation Status
uint16_t BQ25798Component::get_vsys_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1E_Charger_Status_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vsys_stat_bool() {
  uint16_t raw = get_vsys_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VSYS_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_vsys_stat_enum_int() {
  uint16_t raw = get_vsys_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VSYS_STAT);
}
const char* BQ25798Component::get_vsys_stat_enum_string() {
  uint16_t raw = get_vsys_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VSYS_STAT);
}

// CHG_TMR_STAT - Fast charge timer status
uint16_t BQ25798Component::get_chg_tmr_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1E_Charger_Status_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_chg_tmr_stat_bool() {
  uint16_t raw = get_chg_tmr_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->CHG_TMR_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_chg_tmr_stat_enum_int() {
  uint16_t raw = get_chg_tmr_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->CHG_TMR_STAT);
}
const char* BQ25798Component::get_chg_tmr_stat_enum_string() {
  uint16_t raw = get_chg_tmr_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->CHG_TMR_STAT);
}

// TRICHG_TMR_STAT - Trickle charge timer status
uint16_t BQ25798Component::get_trichg_tmr_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1E_Charger_Status_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_trichg_tmr_stat_bool() {
  uint16_t raw = get_trichg_tmr_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TRICHG_TMR_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_trichg_tmr_stat_enum_int() {
  uint16_t raw = get_trichg_tmr_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TRICHG_TMR_STAT);
}
const char* BQ25798Component::get_trichg_tmr_stat_enum_string() {
  uint16_t raw = get_trichg_tmr_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TRICHG_TMR_STAT);
}

// PRECHG_TMR_STAT - Pre-charge timer status
uint16_t BQ25798Component::get_prechg_tmr_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1E_Charger_Status_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_prechg_tmr_stat_bool() {
  uint16_t raw = get_prechg_tmr_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PRECHG_TMR_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_prechg_tmr_stat_enum_int() {
  uint16_t raw = get_prechg_tmr_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->PRECHG_TMR_STAT);
}
const char* BQ25798Component::get_prechg_tmr_stat_enum_string() {
  uint16_t raw = get_prechg_tmr_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->PRECHG_TMR_STAT);
}

// VBATOTG_LOW_STAT - The battery voltage is too low to enable OTG mode
uint16_t BQ25798Component::get_vbatotg_low_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1F_Charger_Status_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vbatotg_low_stat_bool() {
  uint16_t raw = get_vbatotg_low_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBATOTG_LOW_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_vbatotg_low_stat_enum_int() {
  uint16_t raw = get_vbatotg_low_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBATOTG_LOW_STAT);
}
const char* BQ25798Component::get_vbatotg_low_stat_enum_string() {
  uint16_t raw = get_vbatotg_low_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->VBATOTG_LOW_STAT);
}

// TS_COLD_STAT - The TS temperature is in the cold range
uint16_t BQ25798Component::get_ts_cold_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1F_Charger_Status_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ts_cold_stat_bool() {
  uint16_t raw = get_ts_cold_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_COLD_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_ts_cold_stat_enum_int() {
  uint16_t raw = get_ts_cold_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TS_COLD_STAT);
}
const char* BQ25798Component::get_ts_cold_stat_enum_string() {
  uint16_t raw = get_ts_cold_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TS_COLD_STAT);
}

// TS_COOL_STAT - The TS temperature is in the cool range
uint16_t BQ25798Component::get_ts_cool_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1F_Charger_Status_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ts_cool_stat_bool() {
  uint16_t raw = get_ts_cool_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_COOL_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_ts_cool_stat_enum_int() {
  uint16_t raw = get_ts_cool_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TS_COOL_STAT);
}
const char* BQ25798Component::get_ts_cool_stat_enum_string() {
  uint16_t raw = get_ts_cool_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TS_COOL_STAT);
}

// TS_WARM_STAT - The TS temperature is in the warm range
uint16_t BQ25798Component::get_ts_warm_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1F_Charger_Status_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ts_warm_stat_bool() {
  uint16_t raw = get_ts_warm_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_WARM_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_ts_warm_stat_enum_int() {
  uint16_t raw = get_ts_warm_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TS_WARM_STAT);
}
const char* BQ25798Component::get_ts_warm_stat_enum_string() {
  uint16_t raw = get_ts_warm_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TS_WARM_STAT);
}

// TS_HOT_STAT - The TS temperature is in the hot range
uint16_t BQ25798Component::get_ts_hot_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG1F_Charger_Status_4);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ts_hot_stat_bool() {
  uint16_t raw = get_ts_hot_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_HOT_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_ts_hot_stat_enum_int() {
  uint16_t raw = get_ts_hot_stat_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->TS_HOT_STAT);
}
const char* BQ25798Component::get_ts_hot_stat_enum_string() {
  uint16_t raw = get_ts_hot_stat_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->TS_HOT_STAT);
}

// IBAT_REG_STAT - In battery discharging current regulation
uint16_t BQ25798Component::get_ibat_reg_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG20_FAULT_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ibat_reg_stat_bool() {
  uint16_t raw = get_ibat_reg_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBAT_REG_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VBUS_OVP_STAT - VBUS over-voltage status
uint16_t BQ25798Component::get_vbus_ovp_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG20_FAULT_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vbus_ovp_stat_bool() {
  uint16_t raw = get_vbus_ovp_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBUS_OVP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VBAT_OVP_STAT - VBAT over-voltage status
uint16_t BQ25798Component::get_vbat_ovp_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG20_FAULT_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vbat_ovp_stat_bool() {
  uint16_t raw = get_vbat_ovp_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBAT_OVP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// IBUS_OCP_STAT - IBUS over-current status
uint16_t BQ25798Component::get_ibus_ocp_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG20_FAULT_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ibus_ocp_stat_bool() {
  uint16_t raw = get_ibus_ocp_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBUS_OCP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// IBAT_OCP_STAT - IBAT over-current status
uint16_t BQ25798Component::get_ibat_ocp_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG20_FAULT_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ibat_ocp_stat_bool() {
  uint16_t raw = get_ibat_ocp_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBAT_OCP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// CONV_OCP_STAT - Converter over-current status
uint16_t BQ25798Component::get_conv_ocp_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG20_FAULT_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_conv_ocp_stat_bool() {
  uint16_t raw = get_conv_ocp_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->CONV_OCP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VAC2_OVP_STAT - VAC2 over-voltage status
uint16_t BQ25798Component::get_vac2_ovp_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG20_FAULT_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vac2_ovp_stat_bool() {
  uint16_t raw = get_vac2_ovp_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC2_OVP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VAC1_OVP_STAT - VAC1 over-voltage status
uint16_t BQ25798Component::get_vac1_ovp_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG20_FAULT_Status_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vac1_ovp_stat_bool() {
  uint16_t raw = get_vac1_ovp_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC1_OVP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VSYS_SHORT_STAT - VSYS short circuit status
uint16_t BQ25798Component::get_vsys_short_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG21_FAULT_Status_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vsys_short_stat_bool() {
  uint16_t raw = get_vsys_short_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VSYS_SHORT_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// VSYS_OVP_STAT - VSYS over-voltage status
uint16_t BQ25798Component::get_vsys_ovp_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG21_FAULT_Status_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vsys_ovp_stat_bool() {
  uint16_t raw = get_vsys_ovp_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VSYS_OVP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// OTG_OVP_STAT - OTG over-voltage status
uint16_t BQ25798Component::get_otg_ovp_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG21_FAULT_Status_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_otg_ovp_stat_bool() {
  uint16_t raw = get_otg_ovp_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->OTG_OVP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// OTG_UVP_STAT - OTG under-voltage status
uint16_t BQ25798Component::get_otg_uvp_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG21_FAULT_Status_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_otg_uvp_stat_bool() {
  uint16_t raw = get_otg_uvp_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->OTG_UVP_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// TSHUT_STAT - IC thermal shutdown status
uint16_t BQ25798Component::get_tshut_stat_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG21_FAULT_Status_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_tshut_stat_bool() {
  uint16_t raw = get_tshut_stat_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TSHUT_STAT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

// IINDPM_FLAG - IINDPM / IOTG flag
uint16_t BQ25798Component::get_iindpm_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG22_Charger_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_iindpm_flag_flag() {
  uint16_t raw = get_iindpm_flag_raw();
  ESP_LOGD(TAG, "Read IINDPM_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IINDPM_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  IINDPM_FLAG: raising cached flag");
    this->raise_flag_iindpm_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_iindpm_flag_;
  ESP_LOGD(TAG, "  IINDPM_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// VINDPM_FLAG - VINDPM / VOTG Flag
uint16_t BQ25798Component::get_vindpm_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG22_Charger_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vindpm_flag_flag() {
  uint16_t raw = get_vindpm_flag_raw();
  ESP_LOGD(TAG, "Read VINDPM_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VINDPM_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  VINDPM_FLAG: raising cached flag");
    this->raise_flag_vindpm_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_vindpm_flag_;
  ESP_LOGD(TAG, "  VINDPM_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// WD_FLAG - I2C watchdog timer flag
uint16_t BQ25798Component::get_wd_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG22_Charger_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_wd_flag_flag() {
  uint16_t raw = get_wd_flag_raw();
  ESP_LOGD(TAG, "Read WD_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->WD_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  WD_FLAG: raising cached flag");
    this->raise_flag_wd_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_wd_flag_;
  ESP_LOGD(TAG, "  WD_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// POORSRC_FLAG - Poor source detection flag
uint16_t BQ25798Component::get_poorsrc_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG22_Charger_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_poorsrc_flag_flag() {
  uint16_t raw = get_poorsrc_flag_raw();
  ESP_LOGD(TAG, "Read POORSRC_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->POORSRC_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  POORSRC_FLAG: raising cached flag");
    this->raise_flag_poorsrc_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_poorsrc_flag_;
  ESP_LOGD(TAG, "  POORSRC_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// PG_FLAG - Poor source detection flag
uint16_t BQ25798Component::get_pg_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG22_Charger_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_pg_flag_flag() {
  uint16_t raw = get_pg_flag_raw();
  ESP_LOGD(TAG, "Read PG_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PG_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  PG_FLAG: raising cached flag");
    this->raise_flag_pg_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_pg_flag_;
  ESP_LOGD(TAG, "  PG_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// AC2_PRESENT_FLAG - VAC2 present flag
uint16_t BQ25798Component::get_ac2_present_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG22_Charger_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ac2_present_flag_flag() {
  uint16_t raw = get_ac2_present_flag_raw();
  ESP_LOGD(TAG, "Read AC2_PRESENT_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->AC2_PRESENT_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  AC2_PRESENT_FLAG: raising cached flag");
    this->raise_flag_ac2_present_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_ac2_present_flag_;
  ESP_LOGD(TAG, "  AC2_PRESENT_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// AC1_PRESENT_FLAG - VAC1 present flag
uint16_t BQ25798Component::get_ac1_present_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG22_Charger_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ac1_present_flag_flag() {
  uint16_t raw = get_ac1_present_flag_raw();
  ESP_LOGD(TAG, "Read AC1_PRESENT_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->AC1_PRESENT_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  AC1_PRESENT_FLAG: raising cached flag");
    this->raise_flag_ac1_present_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_ac1_present_flag_;
  ESP_LOGD(TAG, "  AC1_PRESENT_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// VBUS_PRESENT_FLAG - VBUS present flag
uint16_t BQ25798Component::get_vbus_present_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG22_Charger_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vbus_present_flag_flag() {
  uint16_t raw = get_vbus_present_flag_raw();
  ESP_LOGD(TAG, "Read VBUS_PRESENT_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBUS_PRESENT_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  VBUS_PRESENT_FLAG: raising cached flag");
    this->raise_flag_vbus_present_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_vbus_present_flag_;
  ESP_LOGD(TAG, "  VBUS_PRESENT_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// CHG_FLAG - Charge status flag
uint16_t BQ25798Component::get_chg_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG23_Charger_Flag_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_chg_flag_flag() {
  uint16_t raw = get_chg_flag_raw();
  ESP_LOGD(TAG, "Read CHG_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->CHG_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  CHG_FLAG: raising cached flag");
    this->raise_flag_chg_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_chg_flag_;
  ESP_LOGD(TAG, "  CHG_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// ICO_FLAG - ICO status flag
uint16_t BQ25798Component::get_ico_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG23_Charger_Flag_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ico_flag_flag() {
  uint16_t raw = get_ico_flag_raw();
  ESP_LOGD(TAG, "Read ICO_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ICO_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  ICO_FLAG: raising cached flag");
    this->raise_flag_ico_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_ico_flag_;
  ESP_LOGD(TAG, "  ICO_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// VBUS_FLAG - VBUS status flag
uint16_t BQ25798Component::get_vbus_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG23_Charger_Flag_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vbus_flag_flag() {
  uint16_t raw = get_vbus_flag_raw();
  ESP_LOGD(TAG, "Read VBUS_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBUS_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  VBUS_FLAG: raising cached flag");
    this->raise_flag_vbus_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_vbus_flag_;
  ESP_LOGD(TAG, "  VBUS_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// TREG_FLAG - IC thermal regulation flag
uint16_t BQ25798Component::get_treg_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG23_Charger_Flag_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_treg_flag_flag() {
  uint16_t raw = get_treg_flag_raw();
  ESP_LOGD(TAG, "Read TREG_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TREG_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  TREG_FLAG: raising cached flag");
    this->raise_flag_treg_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_treg_flag_;
  ESP_LOGD(TAG, "  TREG_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// VBAT_PRESENT_FLAG - VBAT present flag
uint16_t BQ25798Component::get_vbat_present_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG23_Charger_Flag_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vbat_present_flag_flag() {
  uint16_t raw = get_vbat_present_flag_raw();
  ESP_LOGD(TAG, "Read VBAT_PRESENT_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBAT_PRESENT_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  VBAT_PRESENT_FLAG: raising cached flag");
    this->raise_flag_vbat_present_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_vbat_present_flag_;
  ESP_LOGD(TAG, "  VBAT_PRESENT_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// BC1_2_DONE_FLAG - BC1.2 status Flag
uint16_t BQ25798Component::get_bc1_2_done_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG23_Charger_Flag_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_bc1_2_done_flag_flag() {
  uint16_t raw = get_bc1_2_done_flag_raw();
  ESP_LOGD(TAG, "Read BC1_2_DONE_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->BC1_2_DONE_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  BC1_2_DONE_FLAG: raising cached flag");
    this->raise_flag_bc1_2_done_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_bc1_2_done_flag_;
  ESP_LOGD(TAG, "  BC1_2_DONE_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// DPDM_DONE_FLAG - D+/D- detection is done flag.
uint16_t BQ25798Component::get_dpdm_done_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG24_Charger_Flag_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_dpdm_done_flag_flag() {
  uint16_t raw = get_dpdm_done_flag_raw();
  ESP_LOGD(TAG, "Read DPDM_DONE_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DPDM_DONE_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  DPDM_DONE_FLAG: raising cached flag");
    this->raise_flag_dpdm_done_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_dpdm_done_flag_;
  ESP_LOGD(TAG, "  DPDM_DONE_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// ADC_DONE_FLAG - ADC conversion flag (only in one-shot mode)
uint16_t BQ25798Component::get_adc_done_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG24_Charger_Flag_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_adc_done_flag_flag() {
  uint16_t raw = get_adc_done_flag_raw();
  ESP_LOGD(TAG, "Read ADC_DONE_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ADC_DONE_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  ADC_DONE_FLAG: raising cached flag");
    this->raise_flag_adc_done_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_adc_done_flag_;
  ESP_LOGD(TAG, "  ADC_DONE_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// VSYS_FLAG - VSYSMIN regulation flag
uint16_t BQ25798Component::get_vsys_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG24_Charger_Flag_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vsys_flag_flag() {
  uint16_t raw = get_vsys_flag_raw();
  ESP_LOGD(TAG, "Read VSYS_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VSYS_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  VSYS_FLAG: raising cached flag");
    this->raise_flag_vsys_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_vsys_flag_;
  ESP_LOGD(TAG, "  VSYS_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// CHG_TMR_FLAG - Fast charge timer flag
uint16_t BQ25798Component::get_chg_tmr_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG24_Charger_Flag_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_chg_tmr_flag_flag() {
  uint16_t raw = get_chg_tmr_flag_raw();
  ESP_LOGD(TAG, "Read CHG_TMR_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->CHG_TMR_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  CHG_TMR_FLAG: raising cached flag");
    this->raise_flag_chg_tmr_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_chg_tmr_flag_;
  ESP_LOGD(TAG, "  CHG_TMR_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// TRICHG_TMR_FLAG - Trickle charge timer flag
uint16_t BQ25798Component::get_trichg_tmr_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG24_Charger_Flag_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_trichg_tmr_flag_flag() {
  uint16_t raw = get_trichg_tmr_flag_raw();
  ESP_LOGD(TAG, "Read TRICHG_TMR_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TRICHG_TMR_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  TRICHG_TMR_FLAG: raising cached flag");
    this->raise_flag_trichg_tmr_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_trichg_tmr_flag_;
  ESP_LOGD(TAG, "  TRICHG_TMR_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// PRECHG_TMR_FLAG - Pre-charge timer flag
uint16_t BQ25798Component::get_prechg_tmr_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG24_Charger_Flag_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_prechg_tmr_flag_flag() {
  uint16_t raw = get_prechg_tmr_flag_raw();
  ESP_LOGD(TAG, "Read PRECHG_TMR_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->PRECHG_TMR_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  PRECHG_TMR_FLAG: raising cached flag");
    this->raise_flag_prechg_tmr_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_prechg_tmr_flag_;
  ESP_LOGD(TAG, "  PRECHG_TMR_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// TOPOFF_TMR_FLAG - Top off timer flag
uint16_t BQ25798Component::get_topoff_tmr_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG24_Charger_Flag_2);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_topoff_tmr_flag_flag() {
  uint16_t raw = get_topoff_tmr_flag_raw();
  ESP_LOGD(TAG, "Read TOPOFF_TMR_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TOPOFF_TMR_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  TOPOFF_TMR_FLAG: raising cached flag");
    this->raise_flag_topoff_tmr_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_topoff_tmr_flag_;
  ESP_LOGD(TAG, "  TOPOFF_TMR_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// VBATOTG_LOW_FLAG - VBAT too low to enable OTG flag
uint16_t BQ25798Component::get_vbatotg_low_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG25_Charger_Flag_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vbatotg_low_flag_flag() {
  uint16_t raw = get_vbatotg_low_flag_raw();
  ESP_LOGD(TAG, "Read VBATOTG_LOW_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBATOTG_LOW_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  VBATOTG_LOW_FLAG: raising cached flag");
    this->raise_flag_vbatotg_low_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_vbatotg_low_flag_;
  ESP_LOGD(TAG, "  VBATOTG_LOW_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// TS_COLD_FLAG - TS cold temperature flag
uint16_t BQ25798Component::get_ts_cold_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG25_Charger_Flag_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ts_cold_flag_flag() {
  uint16_t raw = get_ts_cold_flag_raw();
  ESP_LOGD(TAG, "Read TS_COLD_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_COLD_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  TS_COLD_FLAG: raising cached flag");
    this->raise_flag_ts_cold_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_ts_cold_flag_;
  ESP_LOGD(TAG, "  TS_COLD_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// TS_COOL_FLAG - TS cool temperature flag
uint16_t BQ25798Component::get_ts_cool_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG25_Charger_Flag_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ts_cool_flag_flag() {
  uint16_t raw = get_ts_cool_flag_raw();
  ESP_LOGD(TAG, "Read TS_COOL_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_COOL_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  TS_COOL_FLAG: raising cached flag");
    this->raise_flag_ts_cool_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_ts_cool_flag_;
  ESP_LOGD(TAG, "  TS_COOL_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// TS_WARM_FLAG - TS warm temperature flag
uint16_t BQ25798Component::get_ts_warm_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG25_Charger_Flag_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ts_warm_flag_flag() {
  uint16_t raw = get_ts_warm_flag_raw();
  ESP_LOGD(TAG, "Read TS_WARM_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_WARM_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  TS_WARM_FLAG: raising cached flag");
    this->raise_flag_ts_warm_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_ts_warm_flag_;
  ESP_LOGD(TAG, "  TS_WARM_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// TS_HOT_FLAG - TS hot temperature flag
uint16_t BQ25798Component::get_ts_hot_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG25_Charger_Flag_3);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ts_hot_flag_flag() {
  uint16_t raw = get_ts_hot_flag_raw();
  ESP_LOGD(TAG, "Read TS_HOT_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_HOT_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  TS_HOT_FLAG: raising cached flag");
    this->raise_flag_ts_hot_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_ts_hot_flag_;
  ESP_LOGD(TAG, "  TS_HOT_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// IBAT_REG_FLAG - IBAT regulation flag
uint16_t BQ25798Component::get_ibat_reg_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG26_FAULT_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ibat_reg_flag_flag() {
  uint16_t raw = get_ibat_reg_flag_raw();
  ESP_LOGD(TAG, "Read IBAT_REG_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBAT_REG_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  IBAT_REG_FLAG: raising cached flag");
    this->raise_flag_ibat_reg_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_ibat_reg_flag_;
  ESP_LOGD(TAG, "  IBAT_REG_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// VBUS_OVP_FLAG - VBUS over-voltage flag
uint16_t BQ25798Component::get_vbus_ovp_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG26_FAULT_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vbus_ovp_flag_flag() {
  uint16_t raw = get_vbus_ovp_flag_raw();
  ESP_LOGD(TAG, "Read VBUS_OVP_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBUS_OVP_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  VBUS_OVP_FLAG: raising cached flag");
    this->raise_flag_vbus_ovp_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_vbus_ovp_flag_;
  ESP_LOGD(TAG, "  VBUS_OVP_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// VBAT_OVP_FLAG - VBAT over-voltage flag
uint16_t BQ25798Component::get_vbat_ovp_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG26_FAULT_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vbat_ovp_flag_flag() {
  uint16_t raw = get_vbat_ovp_flag_raw();
  ESP_LOGD(TAG, "Read VBAT_OVP_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBAT_OVP_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  VBAT_OVP_FLAG: raising cached flag");
    this->raise_flag_vbat_ovp_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_vbat_ovp_flag_;
  ESP_LOGD(TAG, "  VBAT_OVP_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// IBUS_OCP_FLAG - IBUS over-current flag
uint16_t BQ25798Component::get_ibus_ocp_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG26_FAULT_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ibus_ocp_flag_flag() {
  uint16_t raw = get_ibus_ocp_flag_raw();
  ESP_LOGD(TAG, "Read IBUS_OCP_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBUS_OCP_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  IBUS_OCP_FLAG: raising cached flag");
    this->raise_flag_ibus_ocp_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_ibus_ocp_flag_;
  ESP_LOGD(TAG, "  IBUS_OCP_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// IBAT_OCP_FLAG - IBAT over-current flag
uint16_t BQ25798Component::get_ibat_ocp_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG26_FAULT_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_ibat_ocp_flag_flag() {
  uint16_t raw = get_ibat_ocp_flag_raw();
  ESP_LOGD(TAG, "Read IBAT_OCP_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBAT_OCP_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  IBAT_OCP_FLAG: raising cached flag");
    this->raise_flag_ibat_ocp_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_ibat_ocp_flag_;
  ESP_LOGD(TAG, "  IBAT_OCP_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// CONV_OCP_FLAG - Converter over-current flag
uint16_t BQ25798Component::get_conv_ocp_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG26_FAULT_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_conv_ocp_flag_flag() {
  uint16_t raw = get_conv_ocp_flag_raw();
  ESP_LOGD(TAG, "Read CONV_OCP_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->CONV_OCP_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  CONV_OCP_FLAG: raising cached flag");
    this->raise_flag_conv_ocp_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_conv_ocp_flag_;
  ESP_LOGD(TAG, "  CONV_OCP_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// VAC2_OVP_FLAG - VAC2 over-voltage flag
uint16_t BQ25798Component::get_vac2_ovp_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG26_FAULT_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vac2_ovp_flag_flag() {
  uint16_t raw = get_vac2_ovp_flag_raw();
  ESP_LOGD(TAG, "Read VAC2_OVP_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC2_OVP_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  VAC2_OVP_FLAG: raising cached flag");
    this->raise_flag_vac2_ovp_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_vac2_ovp_flag_;
  ESP_LOGD(TAG, "  VAC2_OVP_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// VAC1_OVP_FLAG - VAC1 over-voltage flag
uint16_t BQ25798Component::get_vac1_ovp_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG26_FAULT_Flag_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vac1_ovp_flag_flag() {
  uint16_t raw = get_vac1_ovp_flag_raw();
  ESP_LOGD(TAG, "Read VAC1_OVP_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC1_OVP_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  VAC1_OVP_FLAG: raising cached flag");
    this->raise_flag_vac1_ovp_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_vac1_ovp_flag_;
  ESP_LOGD(TAG, "  VAC1_OVP_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// VSYS_SHORT_FLAG - VSYS short circuit flag
uint16_t BQ25798Component::get_vsys_short_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG27_FAULT_Flag_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vsys_short_flag_flag() {
  uint16_t raw = get_vsys_short_flag_raw();
  ESP_LOGD(TAG, "Read VSYS_SHORT_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VSYS_SHORT_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  VSYS_SHORT_FLAG: raising cached flag");
    this->raise_flag_vsys_short_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_vsys_short_flag_;
  ESP_LOGD(TAG, "  VSYS_SHORT_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// VSYS_OVP_FLAG - VSYS over-voltage flag
uint16_t BQ25798Component::get_vsys_ovp_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG27_FAULT_Flag_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_vsys_ovp_flag_flag() {
  uint16_t raw = get_vsys_ovp_flag_raw();
  ESP_LOGD(TAG, "Read VSYS_OVP_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VSYS_OVP_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  VSYS_OVP_FLAG: raising cached flag");
    this->raise_flag_vsys_ovp_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_vsys_ovp_flag_;
  ESP_LOGD(TAG, "  VSYS_OVP_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// OTG_OVP_FLAG - OTG over-voltage flag
uint16_t BQ25798Component::get_otg_ovp_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG27_FAULT_Flag_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_otg_ovp_flag_flag() {
  uint16_t raw = get_otg_ovp_flag_raw();
  ESP_LOGD(TAG, "Read OTG_OVP_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->OTG_OVP_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  OTG_OVP_FLAG: raising cached flag");
    this->raise_flag_otg_ovp_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_otg_ovp_flag_;
  ESP_LOGD(TAG, "  OTG_OVP_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// OTG_UVP_FLAG - OTG under-voltage flag
uint16_t BQ25798Component::get_otg_uvp_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG27_FAULT_Flag_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_otg_uvp_flag_flag() {
  uint16_t raw = get_otg_uvp_flag_raw();
  ESP_LOGD(TAG, "Read OTG_UVP_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->OTG_UVP_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  OTG_UVP_FLAG: raising cached flag");
    this->raise_flag_otg_uvp_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_otg_uvp_flag_;
  ESP_LOGD(TAG, "  OTG_UVP_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// TSHUT_FLAG - IC thermal shutdown flag
uint16_t BQ25798Component::get_tshut_flag_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG27_FAULT_Flag_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

bool BQ25798Component::get_tshut_flag_flag() {
  uint16_t raw = get_tshut_flag_raw();
  ESP_LOGD(TAG, "Read TSHUT_FLAG flag: raw=0x%04X", raw);

  bool val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TSHUT_FLAG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }

  // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
  if (val) {  // only set the flag if it is on. All the flags need to be cleared explicitly
    ESP_LOGD(TAG, "  TSHUT_FLAG: raising cached flag");
    this->raise_flag_tshut_flag();
  }

  // Always return the value of the flag, never the current register value
  val = this->last_tshut_flag_;
  ESP_LOGD(TAG, "  TSHUT_FLAG: returning %s", val ? "true" : "false");
  return val;
}

// ADC_EN - ADC enable
uint16_t BQ25798Component::get_adc_en_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG2E_ADC_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_adc_en_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting ADC_EN to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG2E_ADC_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG2E_ADC_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_adc_en_bool() {
  uint16_t raw = get_adc_en_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ADC_EN);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_adc_en_bool(bool value) {
  ESP_LOGD(TAG, "Setting ADC_EN to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->ADC_EN);
  this->set_adc_en_raw(raw_value);
};

// ADC_RATE - ADC conversion rate
uint16_t BQ25798Component::get_adc_rate_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG2E_ADC_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_adc_rate_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting ADC_RATE to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG2E_ADC_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG2E_ADC_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_adc_rate_bool() {
  uint16_t raw = get_adc_rate_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ADC_RATE);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_adc_rate_enum_int() {
  uint16_t raw = get_adc_rate_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ADC_RATE);
}
const char* BQ25798Component::get_adc_rate_enum_string() {
  uint16_t raw = get_adc_rate_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->ADC_RATE);
}

void BQ25798Component::set_adc_rate_bool(bool value) {
  ESP_LOGD(TAG, "Setting ADC_RATE to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->ADC_RATE);
  this->set_adc_rate_raw(raw_value);
};

void BQ25798Component::set_adc_rate_enum_int(int value) {
  ESP_LOGD(TAG, "Setting ADC_RATE to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->ADC_RATE);
  this->set_adc_rate_raw(raw_value);
};

// ADC_SAMPLE - ADC sample speed
uint16_t BQ25798Component::get_adc_sample_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG2E_ADC_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(2);
}

void BQ25798Component::set_adc_sample_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting ADC_SAMPLE to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG2E_ADC_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG2E_ADC_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_adc_sample_enum_int() {
  uint16_t raw = get_adc_sample_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ADC_SAMPLE);
}
const char* BQ25798Component::get_adc_sample_enum_string() {
  uint16_t raw = get_adc_sample_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->ADC_SAMPLE);
}

void BQ25798Component::set_adc_sample_enum_int(int value) {
  ESP_LOGD(TAG, "Setting ADC_SAMPLE to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->ADC_SAMPLE);
  this->set_adc_sample_raw(raw_value);
};

// ADC_AVG - ADC averaging
uint16_t BQ25798Component::get_adc_avg_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG2E_ADC_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_adc_avg_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting ADC_AVG to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG2E_ADC_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG2E_ADC_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_adc_avg_bool() {
  uint16_t raw = get_adc_avg_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ADC_AVG);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

int BQ25798Component::get_adc_avg_enum_int() {
  uint16_t raw = get_adc_avg_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->ADC_AVG);
}
const char* BQ25798Component::get_adc_avg_enum_string() {
  uint16_t raw = get_adc_avg_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->ADC_AVG);
}

void BQ25798Component::set_adc_avg_bool(bool value) {
  ESP_LOGD(TAG, "Setting ADC_AVG to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->ADC_AVG);
  this->set_adc_avg_raw(raw_value);
};

void BQ25798Component::set_adc_avg_enum_int(int value) {
  ESP_LOGD(TAG, "Setting ADC_AVG to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->ADC_AVG);
  this->set_adc_avg_raw(raw_value);
};

// ADC_AVG_INIT - ADC average initialization
uint16_t BQ25798Component::get_adc_avg_init_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG2E_ADC_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_adc_avg_init_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting ADC_AVG_INIT to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG2E_ADC_Control);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG2E_ADC_Control (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_adc_avg_init_bool() {
  uint16_t raw = get_adc_avg_init_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->ADC_AVG_INIT);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_adc_avg_init_bool(bool value) {
  ESP_LOGD(TAG, "Setting ADC_AVG_INIT to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->ADC_AVG_INIT);
  this->set_adc_avg_init_raw(raw_value);
};

// IBUS_ADC_DIS - IBUS ADC disable
uint16_t BQ25798Component::get_ibus_adc_dis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG2F_ADC_Function_Disable_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_ibus_adc_dis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting IBUS_ADC_DIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG2F_ADC_Function_Disable_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG2F_ADC_Function_Disable_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_ibus_adc_dis_bool() {
  uint16_t raw = get_ibus_adc_dis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBUS_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_ibus_adc_dis_bool(bool value) {
  ESP_LOGD(TAG, "Setting IBUS_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->IBUS_ADC_DIS);
  this->set_ibus_adc_dis_raw(raw_value);
};

// IBAT_ADC_DIS - IBAT ADC disable
uint16_t BQ25798Component::get_ibat_adc_dis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG2F_ADC_Function_Disable_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_ibat_adc_dis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting IBAT_ADC_DIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG2F_ADC_Function_Disable_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG2F_ADC_Function_Disable_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_ibat_adc_dis_bool() {
  uint16_t raw = get_ibat_adc_dis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->IBAT_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_ibat_adc_dis_bool(bool value) {
  ESP_LOGD(TAG, "Setting IBAT_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->IBAT_ADC_DIS);
  this->set_ibat_adc_dis_raw(raw_value);
};

// VBUS_ADC_DIS - VBUS ADC disable
uint16_t BQ25798Component::get_vbus_adc_dis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG2F_ADC_Function_Disable_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_vbus_adc_dis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VBUS_ADC_DIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG2F_ADC_Function_Disable_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG2F_ADC_Function_Disable_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_vbus_adc_dis_bool() {
  uint16_t raw = get_vbus_adc_dis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBUS_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vbus_adc_dis_bool(bool value) {
  ESP_LOGD(TAG, "Setting VBUS_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VBUS_ADC_DIS);
  this->set_vbus_adc_dis_raw(raw_value);
};

// VBAT_ADC_DIS - VBAT ADC disable
uint16_t BQ25798Component::get_vbat_adc_dis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG2F_ADC_Function_Disable_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_vbat_adc_dis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VBAT_ADC_DIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG2F_ADC_Function_Disable_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG2F_ADC_Function_Disable_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_vbat_adc_dis_bool() {
  uint16_t raw = get_vbat_adc_dis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VBAT_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vbat_adc_dis_bool(bool value) {
  ESP_LOGD(TAG, "Setting VBAT_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VBAT_ADC_DIS);
  this->set_vbat_adc_dis_raw(raw_value);
};

// VSYS_ADC_DIS - VSYS ADC disable
uint16_t BQ25798Component::get_vsys_adc_dis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG2F_ADC_Function_Disable_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_vsys_adc_dis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VSYS_ADC_DIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG2F_ADC_Function_Disable_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG2F_ADC_Function_Disable_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_vsys_adc_dis_bool() {
  uint16_t raw = get_vsys_adc_dis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VSYS_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vsys_adc_dis_bool(bool value) {
  ESP_LOGD(TAG, "Setting VSYS_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VSYS_ADC_DIS);
  this->set_vsys_adc_dis_raw(raw_value);
};

// TS_ADC_DIS - TS ADC disable
uint16_t BQ25798Component::get_ts_adc_dis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG2F_ADC_Function_Disable_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_ts_adc_dis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting TS_ADC_DIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG2F_ADC_Function_Disable_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG2F_ADC_Function_Disable_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_ts_adc_dis_bool() {
  uint16_t raw = get_ts_adc_dis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TS_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_ts_adc_dis_bool(bool value) {
  ESP_LOGD(TAG, "Setting TS_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->TS_ADC_DIS);
  this->set_ts_adc_dis_raw(raw_value);
};

// TDIE_ADC_DIS - TDIE ADC disable
uint16_t BQ25798Component::get_tdie_adc_dis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG2F_ADC_Function_Disable_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 1) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_tdie_adc_dis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting TDIE_ADC_DIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG2F_ADC_Function_Disable_0);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG2F_ADC_Function_Disable_0 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_tdie_adc_dis_bool() {
  uint16_t raw = get_tdie_adc_dis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->TDIE_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_tdie_adc_dis_bool(bool value) {
  ESP_LOGD(TAG, "Setting TDIE_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->TDIE_ADC_DIS);
  this->set_tdie_adc_dis_raw(raw_value);
};

// DPLUS_ADC_DIS - D+ ADC disable
uint16_t BQ25798Component::get_dplus_adc_dis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG30_ADC_Function_Disable_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 7) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_dplus_adc_dis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting DPLUS_ADC_DIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG30_ADC_Function_Disable_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG30_ADC_Function_Disable_1 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_dplus_adc_dis_bool() {
  uint16_t raw = get_dplus_adc_dis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DPLUS_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dplus_adc_dis_bool(bool value) {
  ESP_LOGD(TAG, "Setting DPLUS_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DPLUS_ADC_DIS);
  this->set_dplus_adc_dis_raw(raw_value);
};

// DMINUS_ADC_DIS - D- ADC disable
uint16_t BQ25798Component::get_dminus_adc_dis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG30_ADC_Function_Disable_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 6) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_dminus_adc_dis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting DMINUS_ADC_DIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG30_ADC_Function_Disable_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG30_ADC_Function_Disable_1 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_dminus_adc_dis_bool() {
  uint16_t raw = get_dminus_adc_dis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->DMINUS_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_dminus_adc_dis_bool(bool value) {
  ESP_LOGD(TAG, "Setting DMINUS_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->DMINUS_ADC_DIS);
  this->set_dminus_adc_dis_raw(raw_value);
};

// VAC2_ADC_DIS - VAC2 ADC disable
uint16_t BQ25798Component::get_vac2_adc_dis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG30_ADC_Function_Disable_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_vac2_adc_dis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VAC2_ADC_DIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG30_ADC_Function_Disable_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG30_ADC_Function_Disable_1 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_vac2_adc_dis_bool() {
  uint16_t raw = get_vac2_adc_dis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC2_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vac2_adc_dis_bool(bool value) {
  ESP_LOGD(TAG, "Setting VAC2_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VAC2_ADC_DIS);
  this->set_vac2_adc_dis_raw(raw_value);
};

// VAC1_ADC_DIS - VAC1 ADC disable
uint16_t BQ25798Component::get_vac1_adc_dis_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG30_ADC_Function_Disable_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 4) & BITLENGTH_TO_MASK(1);
}

void BQ25798Component::set_vac1_adc_dis_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting VAC1_ADC_DIS to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG30_ADC_Function_Disable_1);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG30_ADC_Function_Disable_1 (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

bool BQ25798Component::get_vac1_adc_dis_bool() {
  uint16_t raw = get_vac1_adc_dis_raw();
  bool bool_val = this->bq25798_noi2c_->rawToBool(raw, this->bq25798_noi2c_->VAC1_ADC_DIS);
  if (this->bq25798_noi2c_->lastError()) {
    this->status_set_warning();
    this->bq25798_noi2c_->clearError();
  }
  return bool_val;
}

void BQ25798Component::set_vac1_adc_dis_bool(bool value) {
  ESP_LOGD(TAG, "Setting VAC1_ADC_DIS to %s", value ? "true" : "false");
  uint16_t raw_value = this->bq25798_noi2c_->boolToRaw(value, this->bq25798_noi2c_->VAC1_ADC_DIS);
  this->set_vac1_adc_dis_raw(raw_value);
};

// IBUS_ADC - IBUS ADC reading
uint16_t BQ25798Component::get_ibus_adc_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG31_IBUS_ADC);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(16);
}

int BQ25798Component::get_ibus_adc_int() {
  uint16_t raw = get_ibus_adc_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->IBUS_ADC);
}

// IBAT_ADC - IBAT ADC reading
uint16_t BQ25798Component::get_ibat_adc_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG33_IBAT_ADC);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(16);
}

int BQ25798Component::get_ibat_adc_int() {
  uint16_t raw = get_ibat_adc_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->IBAT_ADC);
}

// VBUS_ADC - VBUS ADC reading
uint16_t BQ25798Component::get_vbus_adc_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG35_VBUS_ADC);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(16);
}

int BQ25798Component::get_vbus_adc_int() {
  uint16_t raw = get_vbus_adc_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBUS_ADC);
}

// VAC1_ADC - VAC1 ADC reading
uint16_t BQ25798Component::get_vac1_adc_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG37_VAC1_ADC);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(16);
}

int BQ25798Component::get_vac1_adc_int() {
  uint16_t raw = get_vac1_adc_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VAC1_ADC);
}

// VAC2_ADC - VAC2 ADC reading
uint16_t BQ25798Component::get_vac2_adc_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG39_VAC2_ADC);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(16);
}

int BQ25798Component::get_vac2_adc_int() {
  uint16_t raw = get_vac2_adc_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VAC2_ADC);
}

// VBAT_ADC - VBAT ADC reading
uint16_t BQ25798Component::get_vbat_adc_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG3B_VBAT_ADC);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(16);
}

int BQ25798Component::get_vbat_adc_int() {
  uint16_t raw = get_vbat_adc_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VBAT_ADC);
}

// VSYS_ADC - VSYS ADC reading
uint16_t BQ25798Component::get_vsys_adc_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG3D_VSYS_ADC);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(16);
}

int BQ25798Component::get_vsys_adc_int() {
  uint16_t raw = get_vsys_adc_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->VSYS_ADC);
}

// TS_ADC - TS ADC reading
uint16_t BQ25798Component::get_ts_adc_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG3F_TS_ADC);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(16);
}

float BQ25798Component::get_ts_adc_float() {
  uint16_t raw = get_ts_adc_raw();
  return this->bq25798_noi2c_->rawToFloat(raw, this->bq25798_noi2c_->TS_ADC);
}

// TDIE_ADC - TDIE ADC reading
uint16_t BQ25798Component::get_tdie_adc_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG41_TDIE_ADC);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(16);
}

float BQ25798Component::get_tdie_adc_float() {
  uint16_t raw = get_tdie_adc_raw();
  return this->bq25798_noi2c_->rawToFloat(raw, this->bq25798_noi2c_->TDIE_ADC);
}

// DPLUS_ADC - D+ ADC reading
uint16_t BQ25798Component::get_dplus_adc_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG43_DPLUS_ADC);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(16);
}

int BQ25798Component::get_dplus_adc_int() {
  uint16_t raw = get_dplus_adc_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->DPLUS_ADC);
}

// DMINUS_ADC - D- ADC reading
uint16_t BQ25798Component::get_dminus_adc_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG45_DMINUS_ADC);
  uint16_t reg_value = (_reg_values[ reg_addr ] << 8) |
                        _reg_values[ reg_addr + 1 ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(16);
}

int BQ25798Component::get_dminus_adc_int() {
  uint16_t raw = get_dminus_adc_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->DMINUS_ADC);
}

// DPLUS_DAC - D+ Output Driver
uint16_t BQ25798Component::get_dplus_dac_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG47_DPDM_Driver);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 5) & BITLENGTH_TO_MASK(3);
}

void BQ25798Component::set_dplus_dac_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting DPLUS_DAC to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG47_DPDM_Driver);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG47_DPDM_Driver (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG47_DPDM_Driver, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_dplus_dac_enum_int() {
  uint16_t raw = get_dplus_dac_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->DPLUS_DAC);
}
const char* BQ25798Component::get_dplus_dac_enum_string() {
  uint16_t raw = get_dplus_dac_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->DPLUS_DAC);
}

void BQ25798Component::set_dplus_dac_enum_int(int value) {
  ESP_LOGD(TAG, "Setting DPLUS_DAC to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->DPLUS_DAC);
  this->set_dplus_dac_raw(raw_value);
};

// DMINUS_DAC - D- Output Driver
uint16_t BQ25798Component::get_dminus_dac_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG47_DPDM_Driver);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 2) & BITLENGTH_TO_MASK(3);
}

void BQ25798Component::set_dminus_dac_raw(uint16_t raw_value) {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return;
  }

  ESP_LOGD(TAG, " Setting DMINUS_DAC to raw 0x%04X", raw_value);

  uint8_t reg_addr = _regaddr_to_index.at(REG47_DPDM_Driver);
  uint8_t reg_value = _reg_values[ reg_addr ];
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 2);
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 2);
  _reg_values[ reg_addr ] = reg_value;

  ESP_LOGD(TAG, "  Writing register REG47_DPDM_Driver (0x%02X): 0x%02X", reg_addr, reg_value);
  if (!this->write_byte(REG47_DPDM_Driver, reg_value)) {
    ESP_LOGE(TAG, "Failed to write register 0x%02X", reg_addr);
    this->clear_registers();
    this->mark_failed();
  }
}

int BQ25798Component::get_dminus_dac_enum_int() {
  uint16_t raw = get_dminus_dac_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->DMINUS_DAC);
}
const char* BQ25798Component::get_dminus_dac_enum_string() {
  uint16_t raw = get_dminus_dac_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->DMINUS_DAC);
}

void BQ25798Component::set_dminus_dac_enum_int(int value) {
  ESP_LOGD(TAG, "Setting DMINUS_DAC to %d", value);
  uint8_t raw_value = this->bq25798_noi2c_->intToRaw(value, this->bq25798_noi2c_->DMINUS_DAC);
  this->set_dminus_dac_raw(raw_value);
};

// PN - Part number
uint16_t BQ25798Component::get_pn_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG48_Part_Information);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 3) & BITLENGTH_TO_MASK(3);
}

int BQ25798Component::get_pn_enum_int() {
  uint16_t raw = get_pn_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->PN);
}
const char* BQ25798Component::get_pn_enum_string() {
  uint16_t raw = get_pn_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->PN);
}

// DEV_REV - Device revision
uint16_t BQ25798Component::get_dev_rev_raw() {
  if (this->is_failed() || this->bq25798_noi2c_ == nullptr) {
    return 0;
  }

  uint8_t reg_addr = _regaddr_to_index.at(REG48_Part_Information);
  uint8_t reg_value = _reg_values[ reg_addr ];
  return (reg_value >> 0) & BITLENGTH_TO_MASK(3);
}

int BQ25798Component::get_dev_rev_enum_int() {
  uint16_t raw = get_dev_rev_raw();
  return this->bq25798_noi2c_->rawToInt(raw, this->bq25798_noi2c_->DEV_REV);
}
const char* BQ25798Component::get_dev_rev_enum_string() {
  uint16_t raw = get_dev_rev_raw();
  return this->bq25798_noi2c_->rawToString(raw, this->bq25798_noi2c_->DEV_REV);
}


}  // namespace bq25798
}  // namespace esphome