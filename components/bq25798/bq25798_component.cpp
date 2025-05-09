#include "bq25798_component.h"
#include "esphome/core/log.h"
#include "esphome/core/hal.h"

namespace esphome {
namespace bq25798 {

static const char* TAG = "bq25798.component";

void BQ25798Component::setup() {
  ESP_LOGCONFIG(TAG, "Setting up BQ25798...");

  bq25798_noi2c = new BQ25798NoI2C();
  bq25798_noi2c->begin(this->address_); // no-op

  int pn = get_pn(true);
  if (pn != static_cast<int>(BQ25798NoI2C::PN_t::PN_BQ25798)) {
    ESP_LOGE(TAG, "BQ25798 chip not found at address 0x%02X. Read signature: %d", this->address_, pn);
    this->mark_failed();
    return;
  }

  int dev_rev = get_dev_rev(true);
  if (dev_rev != static_cast<int>(BQ25798NoI2C::DEV_REV_t::DEV_REV_BQ25798)) {
    ESP_LOGE(TAG, "BQ25798 chip at address 0x%02X has unexpected device revision: %d", this->address_, dev_rev);
    this->mark_failed();
    return;
  }

  ESP_LOGCONFIG(TAG, "Resetting the chip...");
  set_reg_rst(true, true);
  while (get_reg_rst(true)) {
    delay(1); // wait for the chip to reset
  }
  ESP_LOGCONFIG(TAG, "Chip reset complete.");

  // Set the values for all the settings specified in the YAML config
  if (on_init_set_vsysmin_) {
    set_vsysmin(last_value_vsysmin, true);
  }
  if (on_init_set_vreg_) {
    set_vreg(last_value_vreg, true);
  }
  if (on_init_set_ichg_) {
    set_ichg(last_value_ichg, true);
  }
  if (on_init_set_vindpm_) {
    set_vindpm(last_value_vindpm, true);
  }
  if (on_init_set_iindpm_) {
    set_iindpm(last_value_iindpm, true);
  }
  if (on_init_set_vbat_lowv_) {
    set_vbat_lowv(last_value_vbat_lowv, true);
  }
  if (on_init_set_iprechg_) {
    set_iprechg(last_value_iprechg, true);
  }
  if (on_init_set_reg_rst_) {
    set_reg_rst(last_value_reg_rst, true);
  }
  if (on_init_set_stop_wd_chg_) {
    set_stop_wd_chg(last_value_stop_wd_chg, true);
  }
  if (on_init_set_iterm_) {
    set_iterm(last_value_iterm, true);
  }
  if (on_init_set_cell_) {
    set_cell(last_value_cell, true);
  }
  if (on_init_set_trechg_) {
    set_trechg(last_value_trechg, true);
  }
  if (on_init_set_vrechg_) {
    set_vrechg(last_value_vrechg, true);
  }
  if (on_init_set_votg_) {
    set_votg(last_value_votg, true);
  }
  if (on_init_set_prechg_tmr_) {
    set_prechg_tmr(last_value_prechg_tmr, true);
  }
  if (on_init_set_iotg_) {
    set_iotg(last_value_iotg, true);
  }
  if (on_init_set_topoff_tmr_) {
    set_topoff_tmr(last_value_topoff_tmr, true);
  }
  if (on_init_set_en_trichg_tmr_) {
    set_en_trichg_tmr(last_value_en_trichg_tmr, true);
  }
  if (on_init_set_en_prechg_tmr_) {
    set_en_prechg_tmr(last_value_en_prechg_tmr, true);
  }
  if (on_init_set_en_chg_tmr_) {
    set_en_chg_tmr(last_value_en_chg_tmr, true);
  }
  if (on_init_set_chg_tmr_) {
    set_chg_tmr(last_value_chg_tmr, true);
  }
  if (on_init_set_tmr2x_en_) {
    set_tmr2x_en(last_value_tmr2x_en, true);
  }
  if (on_init_set_en_auto_ibatdis_) {
    set_en_auto_ibatdis(last_value_en_auto_ibatdis, true);
  }
  if (on_init_set_force_ibatdis_) {
    set_force_ibatdis(last_value_force_ibatdis, true);
  }
  if (on_init_set_en_chg_) {
    set_en_chg(last_value_en_chg, true);
  }
  if (on_init_set_en_ico_) {
    set_en_ico(last_value_en_ico, true);
  }
  if (on_init_set_force_ico_) {
    set_force_ico(last_value_force_ico, true);
  }
  if (on_init_set_en_hiz_) {
    set_en_hiz(last_value_en_hiz, true);
  }
  if (on_init_set_en_term_) {
    set_en_term(last_value_en_term, true);
  }
  if (on_init_set_en_backup_) {
    set_en_backup(last_value_en_backup, true);
  }
  if (on_init_set_vbus_backup_) {
    set_vbus_backup(last_value_vbus_backup, true);
  }
  if (on_init_set_vac_ovp_) {
    set_vac_ovp(last_value_vac_ovp, true);
  }
  if (on_init_set_wd_rst_) {
    set_wd_rst(last_value_wd_rst, true);
  }
  if (on_init_set_watchdog_) {
    set_watchdog(last_value_watchdog, true);
  }
  if (on_init_set_force_indet_) {
    set_force_indet(last_value_force_indet, true);
  }
  if (on_init_set_auto_indet_en_) {
    set_auto_indet_en(last_value_auto_indet_en, true);
  }
  if (on_init_set_en_12v_) {
    set_en_12v(last_value_en_12v, true);
  }
  if (on_init_set_en_9v_) {
    set_en_9v(last_value_en_9v, true);
  }
  if (on_init_set_hvdcp_en_) {
    set_hvdcp_en(last_value_hvdcp_en, true);
  }
  if (on_init_set_sdrv_ctrl_) {
    set_sdrv_ctrl(last_value_sdrv_ctrl, true);
  }
  if (on_init_set_sdrv_dly_) {
    set_sdrv_dly(last_value_sdrv_dly, true);
  }
  if (on_init_set_dis_acdrv_) {
    set_dis_acdrv(last_value_dis_acdrv, true);
  }
  if (on_init_set_en_otg_) {
    set_en_otg(last_value_en_otg, true);
  }
  if (on_init_set_pfm_otg_dis_) {
    set_pfm_otg_dis(last_value_pfm_otg_dis, true);
  }
  if (on_init_set_pfm_fwd_dis_) {
    set_pfm_fwd_dis(last_value_pfm_fwd_dis, true);
  }
  if (on_init_set_wkup_dly_) {
    set_wkup_dly(last_value_wkup_dly, true);
  }
  if (on_init_set_dis_ldo_) {
    set_dis_ldo(last_value_dis_ldo, true);
  }
  if (on_init_set_dis_otg_ooa_) {
    set_dis_otg_ooa(last_value_dis_otg_ooa, true);
  }
  if (on_init_set_dis_fwd_ooa_) {
    set_dis_fwd_ooa(last_value_dis_fwd_ooa, true);
  }
  if (on_init_set_en_acdrv2_) {
    set_en_acdrv2(last_value_en_acdrv2, true);
  }
  if (on_init_set_en_acdrv1_) {
    set_en_acdrv1(last_value_en_acdrv1, true);
  }
  if (on_init_set_pwm_freq_) {
    set_pwm_freq(last_value_pwm_freq, true);
  }
  if (on_init_set_dis_stat_) {
    set_dis_stat(last_value_dis_stat, true);
  }
  if (on_init_set_dis_vsys_short_) {
    set_dis_vsys_short(last_value_dis_vsys_short, true);
  }
  if (on_init_set_dis_votg_uvp_) {
    set_dis_votg_uvp(last_value_dis_votg_uvp, true);
  }
  if (on_init_set_force_vindpm_det_) {
    set_force_vindpm_det(last_value_force_vindpm_det, true);
  }
  if (on_init_set_en_ibus_ocp_) {
    set_en_ibus_ocp(last_value_en_ibus_ocp, true);
  }
  if (on_init_set_sfet_present_) {
    set_sfet_present(last_value_sfet_present, true);
  }
  if (on_init_set_en_ibat_) {
    set_en_ibat(last_value_en_ibat, true);
  }
  if (on_init_set_ibat_reg_) {
    set_ibat_reg(last_value_ibat_reg, true);
  }
  if (on_init_set_en_iindpm_) {
    set_en_iindpm(last_value_en_iindpm, true);
  }
  if (on_init_set_en_extilim_) {
    set_en_extilim(last_value_en_extilim, true);
  }
  if (on_init_set_en_batoc_) {
    set_en_batoc(last_value_en_batoc, true);
  }
  if (on_init_set_voc_pct_) {
    set_voc_pct(last_value_voc_pct, true);
  }
  if (on_init_set_voc_dly_) {
    set_voc_dly(last_value_voc_dly, true);
  }
  if (on_init_set_voc_rate_) {
    set_voc_rate(last_value_voc_rate, true);
  }
  if (on_init_set_en_mppt_) {
    set_en_mppt(last_value_en_mppt, true);
  }
  if (on_init_set_treg_) {
    set_treg(last_value_treg, true);
  }
  if (on_init_set_tshut_) {
    set_tshut(last_value_tshut, true);
  }
  if (on_init_set_vbus_pd_en_) {
    set_vbus_pd_en(last_value_vbus_pd_en, true);
  }
  if (on_init_set_vac1_pd_en_) {
    set_vac1_pd_en(last_value_vac1_pd_en, true);
  }
  if (on_init_set_vac2_pd_en_) {
    set_vac2_pd_en(last_value_vac2_pd_en, true);
  }
  if (on_init_set_bkup_acfet1_on_) {
    set_bkup_acfet1_on(last_value_bkup_acfet1_on, true);
  }
  if (on_init_set_jeita_vset_) {
    set_jeita_vset(last_value_jeita_vset, true);
  }
  if (on_init_set_jeita_iseth_) {
    set_jeita_iseth(last_value_jeita_iseth, true);
  }
  if (on_init_set_jeita_isetc_) {
    set_jeita_isetc(last_value_jeita_isetc, true);
  }
  if (on_init_set_ts_cool_) {
    set_ts_cool(last_value_ts_cool, true);
  }
  if (on_init_set_ts_warm_) {
    set_ts_warm(last_value_ts_warm, true);
  }
  if (on_init_set_bhot_) {
    set_bhot(last_value_bhot, true);
  }
  if (on_init_set_bcold_) {
    set_bcold(last_value_bcold, true);
  }
  if (on_init_set_ts_ignore_) {
    set_ts_ignore(last_value_ts_ignore, true);
  }
  if (on_init_set_adc_en_) {
    set_adc_en(last_value_adc_en, true);
  }
  if (on_init_set_adc_rate_) {
    set_adc_rate(last_value_adc_rate, true);
  }
  if (on_init_set_adc_sample_) {
    set_adc_sample(last_value_adc_sample, true);
  }
  if (on_init_set_adc_avg_) {
    set_adc_avg(last_value_adc_avg, true);
  }
  if (on_init_set_adc_avg_init_) {
    set_adc_avg_init(last_value_adc_avg_init, true);
  }
  if (on_init_set_ibus_adc_dis_) {
    set_ibus_adc_dis(last_value_ibus_adc_dis, true);
  }
  if (on_init_set_ibat_adc_dis_) {
    set_ibat_adc_dis(last_value_ibat_adc_dis, true);
  }
  if (on_init_set_vbus_adc_dis_) {
    set_vbus_adc_dis(last_value_vbus_adc_dis, true);
  }
  if (on_init_set_vbat_adc_dis_) {
    set_vbat_adc_dis(last_value_vbat_adc_dis, true);
  }
  if (on_init_set_vsys_adc_dis_) {
    set_vsys_adc_dis(last_value_vsys_adc_dis, true);
  }
  if (on_init_set_ts_adc_dis_) {
    set_ts_adc_dis(last_value_ts_adc_dis, true);
  }
  if (on_init_set_tdie_adc_dis_) {
    set_tdie_adc_dis(last_value_tdie_adc_dis, true);
  }
  if (on_init_set_dplus_adc_dis_) {
    set_dplus_adc_dis(last_value_dplus_adc_dis, true);
  }
  if (on_init_set_dminus_adc_dis_) {
    set_dminus_adc_dis(last_value_dminus_adc_dis, true);
  }
  if (on_init_set_vac2_adc_dis_) {
    set_vac2_adc_dis(last_value_vac2_adc_dis, true);
  }
  if (on_init_set_vac1_adc_dis_) {
    set_vac1_adc_dis(last_value_vac1_adc_dis, true);
  }
  if (on_init_set_dplus_dac_) {
    set_dplus_dac(last_value_dplus_dac, true);
  }
  if (on_init_set_dminus_dac_) {
    set_dminus_dac(last_value_dminus_dac, true);
  }

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
  // Refresh watchdog timer
  this->set_wd_rst(true, true);
}

// VSYSMIN - Minimal System Voltage
int BQ25798Component::get_vsysmin(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG00_Minimal_System_Voltage, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG00_Minimal_System_Voltage\") value: 0x%02X", REG00_Minimal_System_Voltage, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(6);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (6 bits) raw value: 0x%04X", raw_value);

    last_value_vsysmin = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYSMIN);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vsysmin;
} // getter


void BQ25798Component::on_init_set_vsysmin(bool value) {
  on_init_set_vsysmin_ = value;
}

void BQ25798Component::set_vsysmin(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VSYSMIN to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_vsysmin = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VSYSMIN);

    uint8_t reg_value;
     if (!this->read_byte(REG00_Minimal_System_Voltage, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG00_Minimal_System_Voltage\") value: 0x%02X", REG00_Minimal_System_Voltage,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(6) << 0);
     // ESP_LOGD(TAG, "  masked (6 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(6)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG00_Minimal_System_Voltage, reg_value)) {
       this->mark_failed();
     }
  }
};

// VREG - Charge Voltage Limit
int BQ25798Component::get_vreg(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG01_Charge_Voltage_Limit, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(11);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (11 bits) raw value: 0x%04X", raw_value);

    last_value_vreg = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VREG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vreg;
} // getter


void BQ25798Component::on_init_set_vreg(bool value) {
  on_init_set_vreg_ = value;
}

void BQ25798Component::set_vreg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VREG to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_vreg = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VREG);

    uint16_t reg_value;
    if (!this->read_byte_16(REG01_Charge_Voltage_Limit, &reg_value)) {
      this->mark_failed();
      return;
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register %02X value: 0x%04X", REG01_Charge_Voltage_Limit, reg_value);
    // mask out the bits we are going to change
    reg_value &= ~(BITLENGTH_TO_MASK(11) << 0);
    //ESP_LOGD(TAG, "  masked register value: 0x%04X", reg_value);
    // shift the new value into place and mask it
    reg_value |= ((raw_value & BITLENGTH_TO_MASK(11)) << 0);
    //ESP_LOGD(TAG, "  new register value: 0x%04X", reg_value);
    if (!this->write_byte_16(REG01_Charge_Voltage_Limit, reg_value)) {
      this->mark_failed();
    }
  }
};

// ICHG - Charge Current Limit
int BQ25798Component::get_ichg(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG03_Charge_Current_Limit, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(9);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (9 bits) raw value: 0x%04X", raw_value);

    last_value_ichg = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICHG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ichg;
} // getter


void BQ25798Component::on_init_set_ichg(bool value) {
  on_init_set_ichg_ = value;
}

void BQ25798Component::set_ichg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ICHG to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_ichg = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ICHG);

    uint16_t reg_value;
    if (!this->read_byte_16(REG03_Charge_Current_Limit, &reg_value)) {
      this->mark_failed();
      return;
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register %02X value: 0x%04X", REG03_Charge_Current_Limit, reg_value);
    // mask out the bits we are going to change
    reg_value &= ~(BITLENGTH_TO_MASK(9) << 0);
    //ESP_LOGD(TAG, "  masked register value: 0x%04X", reg_value);
    // shift the new value into place and mask it
    reg_value |= ((raw_value & BITLENGTH_TO_MASK(9)) << 0);
    //ESP_LOGD(TAG, "  new register value: 0x%04X", reg_value);
    if (!this->write_byte_16(REG03_Charge_Current_Limit, reg_value)) {
      this->mark_failed();
    }
  }
};

// VINDPM - Input Voltage Limit
int BQ25798Component::get_vindpm(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG05_Input_Voltage_Limit, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG05_Input_Voltage_Limit\") value: 0x%02X", REG05_Input_Voltage_Limit, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(8);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (8 bits) raw value: 0x%04X", raw_value);

    last_value_vindpm = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VINDPM);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vindpm;
} // getter


void BQ25798Component::on_init_set_vindpm(bool value) {
  on_init_set_vindpm_ = value;
}

void BQ25798Component::set_vindpm(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VINDPM to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_vindpm = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VINDPM);

    uint8_t reg_value;
     if (!this->read_byte(REG05_Input_Voltage_Limit, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG05_Input_Voltage_Limit\") value: 0x%02X", REG05_Input_Voltage_Limit,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(8) << 0);
     // ESP_LOGD(TAG, "  masked (8 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(8)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG05_Input_Voltage_Limit, reg_value)) {
       this->mark_failed();
     }
  }
};

// IINDPM - Input Current Limit
int BQ25798Component::get_iindpm(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG06_Input_Current_Limit, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(9);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (9 bits) raw value: 0x%04X", raw_value);

    last_value_iindpm = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IINDPM);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_iindpm;
} // getter


void BQ25798Component::on_init_set_iindpm(bool value) {
  on_init_set_iindpm_ = value;
}

void BQ25798Component::set_iindpm(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IINDPM to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_iindpm = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IINDPM);

    uint16_t reg_value;
    if (!this->read_byte_16(REG06_Input_Current_Limit, &reg_value)) {
      this->mark_failed();
      return;
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register %02X value: 0x%04X", REG06_Input_Current_Limit, reg_value);
    // mask out the bits we are going to change
    reg_value &= ~(BITLENGTH_TO_MASK(9) << 0);
    //ESP_LOGD(TAG, "  masked register value: 0x%04X", reg_value);
    // shift the new value into place and mask it
    reg_value |= ((raw_value & BITLENGTH_TO_MASK(9)) << 0);
    //ESP_LOGD(TAG, "  new register value: 0x%04X", reg_value);
    if (!this->write_byte_16(REG06_Input_Current_Limit, reg_value)) {
      this->mark_failed();
    }
  }
};

// VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
int BQ25798Component::get_vbat_lowv(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG08_Precharge_Control\") value: 0x%02X", REG08_Precharge_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_vbat_lowv = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_LOWV);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbat_lowv;
} // getter

const char* BQ25798Component::get_vbat_lowv_string(bool read_from_i2c) {
  int value = get_vbat_lowv(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VBAT_LOWV_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_vbat_lowv(bool value) {
  on_init_set_vbat_lowv_ = value;
}

void BQ25798Component::set_vbat_lowv(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBAT_LOWV to %d (<VBAT_LOWV_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_vbat_lowv = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VBAT_LOWV);

    uint8_t reg_value;
     if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG08_Precharge_Control\") value: 0x%02X", REG08_Precharge_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG08_Precharge_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// IPRECHG - Precharge Current Limit
int BQ25798Component::get_iprechg(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG08_Precharge_Control\") value: 0x%02X", REG08_Precharge_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(6);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (6 bits) raw value: 0x%04X", raw_value);

    last_value_iprechg = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IPRECHG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_iprechg;
} // getter


void BQ25798Component::on_init_set_iprechg(bool value) {
  on_init_set_iprechg_ = value;
}

void BQ25798Component::set_iprechg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IPRECHG to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_iprechg = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IPRECHG);

    uint8_t reg_value;
     if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG08_Precharge_Control\") value: 0x%02X", REG08_Precharge_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(6) << 0);
     // ESP_LOGD(TAG, "  masked (6 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(6)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG08_Precharge_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// REG_RST - Reset registers to default values and reset timer
bool BQ25798Component::get_reg_rst(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_reg_rst = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->REG_RST);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_reg_rst;
} // getter


void BQ25798Component::on_init_set_reg_rst(bool value) {
  on_init_set_reg_rst_ = value;
}

void BQ25798Component::set_reg_rst(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s REG_RST to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_reg_rst = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->REG_RST);

    uint8_t reg_value;
     if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG09_Termination_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
bool BQ25798Component::get_stop_wd_chg(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_stop_wd_chg = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->STOP_WD_CHG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_stop_wd_chg;
} // getter


void BQ25798Component::on_init_set_stop_wd_chg(bool value) {
  on_init_set_stop_wd_chg_ = value;
}

void BQ25798Component::set_stop_wd_chg(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s STOP_WD_CHG to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_stop_wd_chg = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->STOP_WD_CHG);

    uint8_t reg_value;
     if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG09_Termination_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// ITERM - Termination Current Limit
int BQ25798Component::get_iterm(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(5);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (5 bits) raw value: 0x%04X", raw_value);

    last_value_iterm = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ITERM);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_iterm;
} // getter


void BQ25798Component::on_init_set_iterm(bool value) {
  on_init_set_iterm_ = value;
}

void BQ25798Component::set_iterm(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ITERM to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_iterm = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ITERM);

    uint8_t reg_value;
     if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(5) << 0);
     // ESP_LOGD(TAG, "  masked (5 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(5)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG09_Termination_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// CELL - Battery cell count
int BQ25798Component::get_cell(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_cell = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CELL);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_cell;
} // getter

const char* BQ25798Component::get_cell_string(bool read_from_i2c) {
  int value = get_cell(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->CELL_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_cell(bool value) {
  on_init_set_cell_ = value;
}

void BQ25798Component::set_cell(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s CELL to %d (<CELL_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_cell = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->CELL);

    uint8_t reg_value;
     if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// TRECHG - Battery recharge delay time
int BQ25798Component::get_trechg(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_trechg = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TRECHG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_trechg;
} // getter

const char* BQ25798Component::get_trechg_string(bool read_from_i2c) {
  int value = get_trechg(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TRECHG_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_trechg(bool value) {
  on_init_set_trechg_ = value;
}

void BQ25798Component::set_trechg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TRECHG to %d (<TRECHG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_trechg = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TRECHG);

    uint8_t reg_value;
     if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// VRECHG - Battery Recharge Threshold Offset (Below VREG)
int BQ25798Component::get_vrechg(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(4);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (4 bits) raw value: 0x%04X", raw_value);

    last_value_vrechg = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VRECHG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vrechg;
} // getter


void BQ25798Component::on_init_set_vrechg(bool value) {
  on_init_set_vrechg_ = value;
}

void BQ25798Component::set_vrechg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VRECHG to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_vrechg = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VRECHG);

    uint8_t reg_value;
     if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(4) << 0);
     // ESP_LOGD(TAG, "  masked (4 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(4)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// VOTG - OTG mode regulation voltage
int BQ25798Component::get_votg(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG0B_VOTG_regulation, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(11);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (11 bits) raw value: 0x%04X", raw_value);

    last_value_votg = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOTG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_votg;
} // getter


void BQ25798Component::on_init_set_votg(bool value) {
  on_init_set_votg_ = value;
}

void BQ25798Component::set_votg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VOTG to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_votg = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOTG);

    uint16_t reg_value;
    if (!this->read_byte_16(REG0B_VOTG_regulation, &reg_value)) {
      this->mark_failed();
      return;
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register %02X value: 0x%04X", REG0B_VOTG_regulation, reg_value);
    // mask out the bits we are going to change
    reg_value &= ~(BITLENGTH_TO_MASK(11) << 0);
    //ESP_LOGD(TAG, "  masked register value: 0x%04X", reg_value);
    // shift the new value into place and mask it
    reg_value |= ((raw_value & BITLENGTH_TO_MASK(11)) << 0);
    //ESP_LOGD(TAG, "  new register value: 0x%04X", reg_value);
    if (!this->write_byte_16(REG0B_VOTG_regulation, reg_value)) {
      this->mark_failed();
    }
  }
};

// PRECHG_TMR - Pre-charge safety timer setting
int BQ25798Component::get_prechg_tmr(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0D_IOTG_regulation\") value: 0x%02X", REG0D_IOTG_regulation, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_prechg_tmr = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PRECHG_TMR);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_prechg_tmr;
} // getter

const char* BQ25798Component::get_prechg_tmr_string(bool read_from_i2c) {
  int value = get_prechg_tmr(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->PRECHG_TMR_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_prechg_tmr(bool value) {
  on_init_set_prechg_tmr_ = value;
}

void BQ25798Component::set_prechg_tmr(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s PRECHG_TMR to %d (<PRECHG_TMR_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_prechg_tmr = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->PRECHG_TMR);

    uint8_t reg_value;
     if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0D_IOTG_regulation\") value: 0x%02X", REG0D_IOTG_regulation,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0D_IOTG_regulation, reg_value)) {
       this->mark_failed();
     }
  }
};

// IOTG - OTG current limit
int BQ25798Component::get_iotg(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0D_IOTG_regulation\") value: 0x%02X", REG0D_IOTG_regulation, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(7);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (7 bits) raw value: 0x%04X", raw_value);

    last_value_iotg = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IOTG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_iotg;
} // getter


void BQ25798Component::on_init_set_iotg(bool value) {
  on_init_set_iotg_ = value;
}

void BQ25798Component::set_iotg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IOTG to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_iotg = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IOTG);

    uint8_t reg_value;
     if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0D_IOTG_regulation\") value: 0x%02X", REG0D_IOTG_regulation,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(7) << 0);
     // ESP_LOGD(TAG, "  masked (7 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(7)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0D_IOTG_regulation, reg_value)) {
       this->mark_failed();
     }
  }
};

// TOPOFF_TMR - Top-off timer control
int BQ25798Component::get_topoff_tmr(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_topoff_tmr = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TOPOFF_TMR);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_topoff_tmr;
} // getter

const char* BQ25798Component::get_topoff_tmr_string(bool read_from_i2c) {
  int value = get_topoff_tmr(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TOPOFF_TMR_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_topoff_tmr(bool value) {
  on_init_set_topoff_tmr_ = value;
}

void BQ25798Component::set_topoff_tmr(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TOPOFF_TMR to %d (<TOPOFF_TMR_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_topoff_tmr = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TOPOFF_TMR);

    uint8_t reg_value;
     if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_TRICHG_TMR - Trickle charge timer enable
bool BQ25798Component::get_en_trichg_tmr(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_trichg_tmr = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_TRICHG_TMR);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_trichg_tmr;
} // getter


void BQ25798Component::on_init_set_en_trichg_tmr(bool value) {
  on_init_set_en_trichg_tmr_ = value;
}

void BQ25798Component::set_en_trichg_tmr(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_TRICHG_TMR to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_trichg_tmr = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_TRICHG_TMR);

    uint8_t reg_value;
     if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_PRECHG_TMR - Precharge timer enable
bool BQ25798Component::get_en_prechg_tmr(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_prechg_tmr = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_PRECHG_TMR);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_prechg_tmr;
} // getter


void BQ25798Component::on_init_set_en_prechg_tmr(bool value) {
  on_init_set_en_prechg_tmr_ = value;
}

void BQ25798Component::set_en_prechg_tmr(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_PRECHG_TMR to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_prechg_tmr = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_PRECHG_TMR);

    uint8_t reg_value;
     if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_CHG_TMR - Fast charge timer enable
bool BQ25798Component::get_en_chg_tmr(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_chg_tmr = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_CHG_TMR);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_chg_tmr;
} // getter


void BQ25798Component::on_init_set_en_chg_tmr(bool value) {
  on_init_set_en_chg_tmr_ = value;
}

void BQ25798Component::set_en_chg_tmr(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_CHG_TMR to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_chg_tmr = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_CHG_TMR);

    uint8_t reg_value;
     if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// CHG_TMR - Fast charge timer setting
int BQ25798Component::get_chg_tmr(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_chg_tmr = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_TMR);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_chg_tmr;
} // getter

const char* BQ25798Component::get_chg_tmr_string(bool read_from_i2c) {
  int value = get_chg_tmr(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->CHG_TMR_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_chg_tmr(bool value) {
  on_init_set_chg_tmr_ = value;
}

void BQ25798Component::set_chg_tmr(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s CHG_TMR to %d (<CHG_TMR_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_chg_tmr = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->CHG_TMR);

    uint8_t reg_value;
     if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 1) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// TMR2X_EN - 2x slower charging in DPM enable
bool BQ25798Component::get_tmr2x_en(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_tmr2x_en = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TMR2X_EN);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_tmr2x_en;
} // getter


void BQ25798Component::on_init_set_tmr2x_en(bool value) {
  on_init_set_tmr2x_en_ = value;
}

void BQ25798Component::set_tmr2x_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TMR2X_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_tmr2x_en = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TMR2X_EN);

    uint8_t reg_value;
     if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_AUTO_IBATDIS - Enable the auto battery discharging during the battery OVP fault
bool BQ25798Component::get_en_auto_ibatdis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_auto_ibatdis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_AUTO_IBATDIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_auto_ibatdis;
} // getter


void BQ25798Component::on_init_set_en_auto_ibatdis(bool value) {
  on_init_set_en_auto_ibatdis_ = value;
}

void BQ25798Component::set_en_auto_ibatdis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_AUTO_IBATDIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_auto_ibatdis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_AUTO_IBATDIS);

    uint8_t reg_value;
     if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// FORCE_IBATDIS - Force the battery discharging current
bool BQ25798Component::get_force_ibatdis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_force_ibatdis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_IBATDIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_force_ibatdis;
} // getter


void BQ25798Component::on_init_set_force_ibatdis(bool value) {
  on_init_set_force_ibatdis_ = value;
}

void BQ25798Component::set_force_ibatdis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s FORCE_IBATDIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_force_ibatdis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_IBATDIS);

    uint8_t reg_value;
     if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_CHG - Enable the charger
bool BQ25798Component::get_en_chg(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_chg = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_CHG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_chg;
} // getter


void BQ25798Component::on_init_set_en_chg(bool value) {
  on_init_set_en_chg_ = value;
}

void BQ25798Component::set_en_chg(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_CHG to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_chg = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_CHG);

    uint8_t reg_value;
     if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_ICO - Enable the ICO (Input Current Optimizer)
bool BQ25798Component::get_en_ico(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_ico = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ICO);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_ico;
} // getter


void BQ25798Component::on_init_set_en_ico(bool value) {
  on_init_set_en_ico_ = value;
}

void BQ25798Component::set_en_ico(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_ICO to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_ico = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_ICO);

    uint8_t reg_value;
     if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// FORCE_ICO - Force the ICO (Input Current Optimizer)
bool BQ25798Component::get_force_ico(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_force_ico = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_ICO);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_force_ico;
} // getter


void BQ25798Component::on_init_set_force_ico(bool value) {
  on_init_set_force_ico_ = value;
}

void BQ25798Component::set_force_ico(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s FORCE_ICO to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_force_ico = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_ICO);

    uint8_t reg_value;
     if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_HIZ - Enable the high impedance mode
bool BQ25798Component::get_en_hiz(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_hiz = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_HIZ);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_hiz;
} // getter


void BQ25798Component::on_init_set_en_hiz(bool value) {
  on_init_set_en_hiz_ = value;
}

void BQ25798Component::set_en_hiz(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_HIZ to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_hiz = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_HIZ);

    uint8_t reg_value;
     if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_TERM - Enable the termination
bool BQ25798Component::get_en_term(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_term = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_TERM);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_term;
} // getter


void BQ25798Component::on_init_set_en_term(bool value) {
  on_init_set_en_term_ = value;
}

void BQ25798Component::set_en_term(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_TERM to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_term = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_TERM);

    uint8_t reg_value;
     if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_BACKUP - Enable the backup (auto OTG) mode
bool BQ25798Component::get_en_backup(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_backup = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_BACKUP);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_backup;
} // getter


void BQ25798Component::on_init_set_en_backup(bool value) {
  on_init_set_en_backup_ = value;
}

void BQ25798Component::set_en_backup(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_BACKUP to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_backup = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_BACKUP);

    uint8_t reg_value;
     if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// VBUS_BACKUP - The thresholds to trigger the backup mode, defined as a ratio of VINDPM
int BQ25798Component::get_vbus_backup(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_vbus_backup = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_BACKUP);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbus_backup;
} // getter

const char* BQ25798Component::get_vbus_backup_string(bool read_from_i2c) {
  int value = get_vbus_backup(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VBUS_BACKUP_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_vbus_backup(bool value) {
  on_init_set_vbus_backup_ = value;
}

void BQ25798Component::set_vbus_backup(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBUS_BACKUP to %d (<VBUS_BACKUP_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_vbus_backup = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VBUS_BACKUP);

    uint8_t reg_value;
     if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
       this->mark_failed();
     }
  }
};

// VAC_OVP - Over voltage protection thresholds
int BQ25798Component::get_vac_ovp(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_vac_ovp = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC_OVP);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vac_ovp;
} // getter

const char* BQ25798Component::get_vac_ovp_string(bool read_from_i2c) {
  int value = get_vac_ovp(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VAC_OVP_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_vac_ovp(bool value) {
  on_init_set_vac_ovp_ = value;
}

void BQ25798Component::set_vac_ovp(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC_OVP to %d (<VAC_OVP_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_vac_ovp = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VAC_OVP);

    uint8_t reg_value;
     if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
       this->mark_failed();
     }
  }
};

// WD_RST - I2C watch dog timer reset
bool BQ25798Component::get_wd_rst(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_wd_rst = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->WD_RST);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_wd_rst;
} // getter


void BQ25798Component::on_init_set_wd_rst(bool value) {
  on_init_set_wd_rst_ = value;
}

void BQ25798Component::set_wd_rst(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s WD_RST to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_wd_rst = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->WD_RST);

    uint8_t reg_value;
     if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
       this->mark_failed();
     }
  }
};

// WATCHDOG - Watchdog timer settings
int BQ25798Component::get_watchdog(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (3 bits) raw value: 0x%04X", raw_value);

    last_value_watchdog = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WATCHDOG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_watchdog;
} // getter

const char* BQ25798Component::get_watchdog_string(bool read_from_i2c) {
  int value = get_watchdog(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->WATCHDOG_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_watchdog(bool value) {
  on_init_set_watchdog_ = value;
}

void BQ25798Component::set_watchdog(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s WATCHDOG to %d (<WATCHDOG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_watchdog = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->WATCHDOG);

    uint8_t reg_value;
     if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(3) << 0);
     // ESP_LOGD(TAG, "  masked (3 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
       this->mark_failed();
     }
  }
};

// FORCE_INDET - Force D+/D- detection
bool BQ25798Component::get_force_indet(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_force_indet = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_INDET);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_force_indet;
} // getter


void BQ25798Component::on_init_set_force_indet(bool value) {
  on_init_set_force_indet_ = value;
}

void BQ25798Component::set_force_indet(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s FORCE_INDET to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_force_indet = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_INDET);

    uint8_t reg_value;
     if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
       this->mark_failed();
     }
  }
};

// AUTO_INDET_EN - Enable automatic D+/D- detection
bool BQ25798Component::get_auto_indet_en(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_auto_indet_en = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AUTO_INDET_EN);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_auto_indet_en;
} // getter


void BQ25798Component::on_init_set_auto_indet_en(bool value) {
  on_init_set_auto_indet_en_ = value;
}

void BQ25798Component::set_auto_indet_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s AUTO_INDET_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_auto_indet_en = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->AUTO_INDET_EN);

    uint8_t reg_value;
     if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_12V - Enable 12V output in HVDCP
bool BQ25798Component::get_en_12v(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_12v = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_12V);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_12v;
} // getter


void BQ25798Component::on_init_set_en_12v(bool value) {
  on_init_set_en_12v_ = value;
}

void BQ25798Component::set_en_12v(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_12V to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_12v = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_12V);

    uint8_t reg_value;
     if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_9V - Enable 9V output in HVDCP
bool BQ25798Component::get_en_9v(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_9v = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_9V);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_9v;
} // getter


void BQ25798Component::on_init_set_en_9v(bool value) {
  on_init_set_en_9v_ = value;
}

void BQ25798Component::set_en_9v(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_9V to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_9v = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_9V);

    uint8_t reg_value;
     if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
       this->mark_failed();
     }
  }
};

// HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
bool BQ25798Component::get_hvdcp_en(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_hvdcp_en = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->HVDCP_EN);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_hvdcp_en;
} // getter


void BQ25798Component::on_init_set_hvdcp_en(bool value) {
  on_init_set_hvdcp_en_ = value;
}

void BQ25798Component::set_hvdcp_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s HVDCP_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_hvdcp_en = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->HVDCP_EN);

    uint8_t reg_value;
     if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
       this->mark_failed();
     }
  }
};

// SDRV_CTRL - Enable external Ship FET control
int BQ25798Component::get_sdrv_ctrl(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_sdrv_ctrl = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->SDRV_CTRL);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_sdrv_ctrl;
} // getter

const char* BQ25798Component::get_sdrv_ctrl_string(bool read_from_i2c) {
  int value = get_sdrv_ctrl(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->SDRV_CTRL_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_sdrv_ctrl(bool value) {
  on_init_set_sdrv_ctrl_ = value;
}

void BQ25798Component::set_sdrv_ctrl(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s SDRV_CTRL to %d (<SDRV_CTRL_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_sdrv_ctrl = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->SDRV_CTRL);

    uint8_t reg_value;
     if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 1) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
       this->mark_failed();
     }
  }
};

// SDRV_DLY - Delay for SDRV control
int BQ25798Component::get_sdrv_dly(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_sdrv_dly = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->SDRV_DLY);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_sdrv_dly;
} // getter

const char* BQ25798Component::get_sdrv_dly_string(bool read_from_i2c) {
  int value = get_sdrv_dly(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->SDRV_DLY_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_sdrv_dly(bool value) {
  on_init_set_sdrv_dly_ = value;
}

void BQ25798Component::set_sdrv_dly(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s SDRV_DLY to %d (<SDRV_DLY_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_sdrv_dly = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->SDRV_DLY);

    uint8_t reg_value;
     if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
       this->mark_failed();
     }
  }
};

// DIS_ACDRV - Disable both AC1 and AC2 drivers
bool BQ25798Component::get_dis_acdrv(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_dis_acdrv = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_ACDRV);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dis_acdrv;
} // getter


void BQ25798Component::on_init_set_dis_acdrv(bool value) {
  on_init_set_dis_acdrv_ = value;
}

void BQ25798Component::set_dis_acdrv(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_ACDRV to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_dis_acdrv = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_ACDRV);

    uint8_t reg_value;
     if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_OTG - Enable OTG mode
bool BQ25798Component::get_en_otg(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_otg = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_OTG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_otg;
} // getter


void BQ25798Component::on_init_set_en_otg(bool value) {
  on_init_set_en_otg_ = value;
}

void BQ25798Component::set_en_otg(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_OTG to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_otg = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_OTG);

    uint8_t reg_value;
     if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
       this->mark_failed();
     }
  }
};

// PFM_OTG_DIS - Disable PFM in OTG mode
bool BQ25798Component::get_pfm_otg_dis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_pfm_otg_dis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PFM_OTG_DIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_pfm_otg_dis;
} // getter


void BQ25798Component::on_init_set_pfm_otg_dis(bool value) {
  on_init_set_pfm_otg_dis_ = value;
}

void BQ25798Component::set_pfm_otg_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s PFM_OTG_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_pfm_otg_dis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->PFM_OTG_DIS);

    uint8_t reg_value;
     if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
       this->mark_failed();
     }
  }
};

// PFM_FWD_DIS - Disable PFM in forward mode
bool BQ25798Component::get_pfm_fwd_dis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_pfm_fwd_dis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PFM_FWD_DIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_pfm_fwd_dis;
} // getter


void BQ25798Component::on_init_set_pfm_fwd_dis(bool value) {
  on_init_set_pfm_fwd_dis_ = value;
}

void BQ25798Component::set_pfm_fwd_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s PFM_FWD_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_pfm_fwd_dis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->PFM_FWD_DIS);

    uint8_t reg_value;
     if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
       this->mark_failed();
     }
  }
};

// WKUP_DLY - Wakeup (Ship FET) delay
int BQ25798Component::get_wkup_dly(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_wkup_dly = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WKUP_DLY);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_wkup_dly;
} // getter

const char* BQ25798Component::get_wkup_dly_string(bool read_from_i2c) {
  int value = get_wkup_dly(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->WKUP_DLY_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_wkup_dly(bool value) {
  on_init_set_wkup_dly_ = value;
}

void BQ25798Component::set_wkup_dly(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s WKUP_DLY to %d (<WKUP_DLY_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_wkup_dly = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->WKUP_DLY);

    uint8_t reg_value;
     if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
       this->mark_failed();
     }
  }
};

// DIS_LDO - Disable BATFET LDO mode in precharge state
bool BQ25798Component::get_dis_ldo(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_dis_ldo = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_LDO);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dis_ldo;
} // getter


void BQ25798Component::on_init_set_dis_ldo(bool value) {
  on_init_set_dis_ldo_ = value;
}

void BQ25798Component::set_dis_ldo(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_LDO to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_dis_ldo = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_LDO);

    uint8_t reg_value;
     if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
       this->mark_failed();
     }
  }
};

// DIS_OTG_OOA - Disable OOA in OTG mode
bool BQ25798Component::get_dis_otg_ooa(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_dis_otg_ooa = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_OTG_OOA);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dis_otg_ooa;
} // getter


void BQ25798Component::on_init_set_dis_otg_ooa(bool value) {
  on_init_set_dis_otg_ooa_ = value;
}

void BQ25798Component::set_dis_otg_ooa(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_OTG_OOA to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_dis_otg_ooa = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_OTG_OOA);

    uint8_t reg_value;
     if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
       this->mark_failed();
     }
  }
};

// DIS_FWD_OOA - Disable OOA in forward mode
bool BQ25798Component::get_dis_fwd_ooa(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_dis_fwd_ooa = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_FWD_OOA);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dis_fwd_ooa;
} // getter


void BQ25798Component::on_init_set_dis_fwd_ooa(bool value) {
  on_init_set_dis_fwd_ooa_ = value;
}

void BQ25798Component::set_dis_fwd_ooa(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_FWD_OOA to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_dis_fwd_ooa = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_FWD_OOA);

    uint8_t reg_value;
     if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_ACDRV2 - Enable AC2 gate driver control
bool BQ25798Component::get_en_acdrv2(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_acdrv2 = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ACDRV2);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_acdrv2;
} // getter


void BQ25798Component::on_init_set_en_acdrv2(bool value) {
  on_init_set_en_acdrv2_ = value;
}

void BQ25798Component::set_en_acdrv2(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_ACDRV2 to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_acdrv2 = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_ACDRV2);

    uint8_t reg_value;
     if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_ACDRV1 - Enable AC1 gate driver control
bool BQ25798Component::get_en_acdrv1(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_acdrv1 = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ACDRV1);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_acdrv1;
} // getter


void BQ25798Component::on_init_set_en_acdrv1(bool value) {
  on_init_set_en_acdrv1_ = value;
}

void BQ25798Component::set_en_acdrv1(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_ACDRV1 to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_acdrv1 = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_ACDRV1);

    uint8_t reg_value;
     if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
       this->mark_failed();
     }
  }
};

// PWM_FREQ - PWM frequency setting
int BQ25798Component::get_pwm_freq(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_pwm_freq = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PWM_FREQ);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_pwm_freq;
} // getter

const char* BQ25798Component::get_pwm_freq_string(bool read_from_i2c) {
  int value = get_pwm_freq(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->PWM_FREQ_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_pwm_freq(bool value) {
  on_init_set_pwm_freq_ = value;
}

void BQ25798Component::set_pwm_freq(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s PWM_FREQ to %d (<PWM_FREQ_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_pwm_freq = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->PWM_FREQ);

    uint8_t reg_value;
     if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
       this->mark_failed();
     }
  }
};

// DIS_STAT - Disable STAT pin output
bool BQ25798Component::get_dis_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_dis_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dis_stat;
} // getter


void BQ25798Component::on_init_set_dis_stat(bool value) {
  on_init_set_dis_stat_ = value;
}

void BQ25798Component::set_dis_stat(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_STAT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_dis_stat = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_STAT);

    uint8_t reg_value;
     if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
       this->mark_failed();
     }
  }
};

// DIS_VSYS_SHORT - Disable VSYS short hiccup protection
bool BQ25798Component::get_dis_vsys_short(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_dis_vsys_short = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_VSYS_SHORT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dis_vsys_short;
} // getter


void BQ25798Component::on_init_set_dis_vsys_short(bool value) {
  on_init_set_dis_vsys_short_ = value;
}

void BQ25798Component::set_dis_vsys_short(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_VSYS_SHORT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_dis_vsys_short = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_VSYS_SHORT);

    uint8_t reg_value;
     if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
       this->mark_failed();
     }
  }
};

// DIS_VOTG_UVP - Disable VOTG under voltage hiccup protection
bool BQ25798Component::get_dis_votg_uvp(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_dis_votg_uvp = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_VOTG_UVP);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dis_votg_uvp;
} // getter


void BQ25798Component::on_init_set_dis_votg_uvp(bool value) {
  on_init_set_dis_votg_uvp_ = value;
}

void BQ25798Component::set_dis_votg_uvp(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_VOTG_UVP to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_dis_votg_uvp = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_VOTG_UVP);

    uint8_t reg_value;
     if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
       this->mark_failed();
     }
  }
};

// FORCE_VINDPM_DET - Force VINDPM detection (settable only when VBAT>VSYSMIN)
bool BQ25798Component::get_force_vindpm_det(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_force_vindpm_det = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_VINDPM_DET);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_force_vindpm_det;
} // getter


void BQ25798Component::on_init_set_force_vindpm_det(bool value) {
  on_init_set_force_vindpm_det_ = value;
}

void BQ25798Component::set_force_vindpm_det(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s FORCE_VINDPM_DET to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_force_vindpm_det = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_VINDPM_DET);

    uint8_t reg_value;
     if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_IBUS_OCP - Enable input over current protection in forward mode
bool BQ25798Component::get_en_ibus_ocp(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_ibus_ocp = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IBUS_OCP);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_ibus_ocp;
} // getter


void BQ25798Component::on_init_set_en_ibus_ocp(bool value) {
  on_init_set_en_ibus_ocp_ = value;
}

void BQ25798Component::set_en_ibus_ocp(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_IBUS_OCP to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_ibus_ocp = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_IBUS_OCP);

    uint8_t reg_value;
     if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
       this->mark_failed();
     }
  }
};

// SFET_PRESENT - Ship FET present
bool BQ25798Component::get_sfet_present(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_sfet_present = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->SFET_PRESENT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_sfet_present;
} // getter


void BQ25798Component::on_init_set_sfet_present(bool value) {
  on_init_set_sfet_present_ = value;
}

void BQ25798Component::set_sfet_present(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s SFET_PRESENT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_sfet_present = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->SFET_PRESENT);

    uint8_t reg_value;
     if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_IBAT - Enable battery discharge current sensing
bool BQ25798Component::get_en_ibat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_ibat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IBAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_ibat;
} // getter


void BQ25798Component::on_init_set_en_ibat(bool value) {
  on_init_set_en_ibat_ = value;
}

void BQ25798Component::set_en_ibat(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_IBAT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_ibat = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_IBAT);

    uint8_t reg_value;
     if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
       this->mark_failed();
     }
  }
};

// IBAT_REG - Battery discharge current regulation in OTG mode
int BQ25798Component::get_ibat_reg(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_ibat_reg = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBAT_REG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ibat_reg;
} // getter

const char* BQ25798Component::get_ibat_reg_string(bool read_from_i2c) {
  int value = get_ibat_reg(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->IBAT_REG_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_ibat_reg(bool value) {
  on_init_set_ibat_reg_ = value;
}

void BQ25798Component::set_ibat_reg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IBAT_REG to %d (<IBAT_REG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_ibat_reg = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IBAT_REG);

    uint8_t reg_value;
     if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 3);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 3) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 3);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_IINDPM - Enable input current regulation
bool BQ25798Component::get_en_iindpm(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_iindpm = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IINDPM);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_iindpm;
} // getter


void BQ25798Component::on_init_set_en_iindpm(bool value) {
  on_init_set_en_iindpm_ = value;
}

void BQ25798Component::set_en_iindpm(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_IINDPM to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_iindpm = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_IINDPM);

    uint8_t reg_value;
     if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
bool BQ25798Component::get_en_extilim(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_extilim = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_EXTILIM);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_extilim;
} // getter


void BQ25798Component::on_init_set_en_extilim(bool value) {
  on_init_set_en_extilim_ = value;
}

void BQ25798Component::set_en_extilim(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_EXTILIM to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_extilim = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_EXTILIM);

    uint8_t reg_value;
     if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_BATOC - Enable battery discharging over current protection
bool BQ25798Component::get_en_batoc(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_batoc = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_BATOC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_batoc;
} // getter


void BQ25798Component::on_init_set_en_batoc(bool value) {
  on_init_set_en_batoc_ = value;
}

void BQ25798Component::set_en_batoc(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_BATOC to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_batoc = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_BATOC);

    uint8_t reg_value;
     if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
       this->mark_failed();
     }
  }
};

// VOC_PCT - 
int BQ25798Component::get_voc_pct(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);

    last_value_voc_pct = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_PCT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_voc_pct;
} // getter

const char* BQ25798Component::get_voc_pct_string(bool read_from_i2c) {
  int value = get_voc_pct(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VOC_PCT_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_voc_pct(bool value) {
  on_init_set_voc_pct_ = value;
}

void BQ25798Component::set_voc_pct(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VOC_PCT to %d (<VOC_PCT_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_voc_pct = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOC_PCT);

    uint8_t reg_value;
     if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
     // ESP_LOGD(TAG, "  masked (3 bits shifted by 5) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// VOC_DLY - 
int BQ25798Component::get_voc_dly(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_voc_dly = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_DLY);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_voc_dly;
} // getter

const char* BQ25798Component::get_voc_dly_string(bool read_from_i2c) {
  int value = get_voc_dly(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VOC_DLY_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_voc_dly(bool value) {
  on_init_set_voc_dly_ = value;
}

void BQ25798Component::set_voc_dly(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VOC_DLY to %d (<VOC_DLY_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_voc_dly = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOC_DLY);

    uint8_t reg_value;
     if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// VOC_RATE - 
int BQ25798Component::get_voc_rate(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_voc_rate = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_RATE);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_voc_rate;
} // getter

const char* BQ25798Component::get_voc_rate_string(bool read_from_i2c) {
  int value = get_voc_rate(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VOC_RATE_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_voc_rate(bool value) {
  on_init_set_voc_rate_ = value;
}

void BQ25798Component::set_voc_rate(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VOC_RATE to %d (<VOC_RATE_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_voc_rate = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOC_RATE);

    uint8_t reg_value;
     if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 2);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 2) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 2);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// EN_MPPT - 
bool BQ25798Component::get_en_mppt(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_en_mppt = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_MPPT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_en_mppt;
} // getter


void BQ25798Component::on_init_set_en_mppt(bool value) {
  on_init_set_en_mppt_ = value;
}

void BQ25798Component::set_en_mppt(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_MPPT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_en_mppt = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_MPPT);

    uint8_t reg_value;
     if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// TREG - 
int BQ25798Component::get_treg(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_treg = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TREG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_treg;
} // getter

const char* BQ25798Component::get_treg_string(bool read_from_i2c) {
  int value = get_treg(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TREG_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_treg(bool value) {
  on_init_set_treg_ = value;
}

void BQ25798Component::set_treg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TREG to %d (<TREG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_treg = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TREG);

    uint8_t reg_value;
     if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// TSHUT - 
int BQ25798Component::get_tshut(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_tshut = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TSHUT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_tshut;
} // getter

const char* BQ25798Component::get_tshut_string(bool read_from_i2c) {
  int value = get_tshut(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TSHUT_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_tshut(bool value) {
  on_init_set_tshut_ = value;
}

void BQ25798Component::set_tshut(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TSHUT to %d (<TSHUT_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_tshut = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TSHUT);

    uint8_t reg_value;
     if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// VBUS_PD_EN - 
bool BQ25798Component::get_vbus_pd_en(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vbus_pd_en = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_PD_EN);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbus_pd_en;
} // getter


void BQ25798Component::on_init_set_vbus_pd_en(bool value) {
  on_init_set_vbus_pd_en_ = value;
}

void BQ25798Component::set_vbus_pd_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBUS_PD_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_vbus_pd_en = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBUS_PD_EN);

    uint8_t reg_value;
     if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// VAC1_PD_EN - 
bool BQ25798Component::get_vac1_pd_en(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vac1_pd_en = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_PD_EN);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vac1_pd_en;
} // getter


void BQ25798Component::on_init_set_vac1_pd_en(bool value) {
  on_init_set_vac1_pd_en_ = value;
}

void BQ25798Component::set_vac1_pd_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC1_PD_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_vac1_pd_en = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC1_PD_EN);

    uint8_t reg_value;
     if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// VAC2_PD_EN - 
bool BQ25798Component::get_vac2_pd_en(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vac2_pd_en = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_PD_EN);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vac2_pd_en;
} // getter


void BQ25798Component::on_init_set_vac2_pd_en(bool value) {
  on_init_set_vac2_pd_en_ = value;
}

void BQ25798Component::set_vac2_pd_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC2_PD_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_vac2_pd_en = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC2_PD_EN);

    uint8_t reg_value;
     if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// BKUP_ACFET1_ON - 
int BQ25798Component::get_bkup_acfet1_on(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_bkup_acfet1_on = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BKUP_ACFET1_ON);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_bkup_acfet1_on;
} // getter

const char* BQ25798Component::get_bkup_acfet1_on_string(bool read_from_i2c) {
  int value = get_bkup_acfet1_on(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->BKUP_ACFET1_ON_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_bkup_acfet1_on(bool value) {
  on_init_set_bkup_acfet1_on_ = value;
}

void BQ25798Component::set_bkup_acfet1_on(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s BKUP_ACFET1_ON to %d (<BKUP_ACFET1_ON_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_bkup_acfet1_on = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->BKUP_ACFET1_ON);

    uint8_t reg_value;
     if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// JEITA_VSET - 
int BQ25798Component::get_jeita_vset(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);

    last_value_jeita_vset = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_VSET);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_jeita_vset;
} // getter

const char* BQ25798Component::get_jeita_vset_string(bool read_from_i2c) {
  int value = get_jeita_vset(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->JEITA_VSET_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_jeita_vset(bool value) {
  on_init_set_jeita_vset_ = value;
}

void BQ25798Component::set_jeita_vset(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s JEITA_VSET to %d (<JEITA_VSET_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_jeita_vset = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->JEITA_VSET);

    uint8_t reg_value;
     if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
     // ESP_LOGD(TAG, "  masked (3 bits shifted by 5) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// JEITA_ISETH - 
int BQ25798Component::get_jeita_iseth(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_jeita_iseth = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_ISETH);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_jeita_iseth;
} // getter

const char* BQ25798Component::get_jeita_iseth_string(bool read_from_i2c) {
  int value = get_jeita_iseth(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->JEITA_ISETH_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_jeita_iseth(bool value) {
  on_init_set_jeita_iseth_ = value;
}

void BQ25798Component::set_jeita_iseth(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s JEITA_ISETH to %d (<JEITA_ISETH_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_jeita_iseth = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->JEITA_ISETH);

    uint8_t reg_value;
     if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 3);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 3) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 3);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// JEITA_ISETC - 
int BQ25798Component::get_jeita_isetc(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_jeita_isetc = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_ISETC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_jeita_isetc;
} // getter

const char* BQ25798Component::get_jeita_isetc_string(bool read_from_i2c) {
  int value = get_jeita_isetc(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->JEITA_ISETC_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_jeita_isetc(bool value) {
  on_init_set_jeita_isetc_ = value;
}

void BQ25798Component::set_jeita_isetc(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s JEITA_ISETC to %d (<JEITA_ISETC_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_jeita_isetc = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->JEITA_ISETC);

    uint8_t reg_value;
     if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 1) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// TS_COOL - 
int BQ25798Component::get_ts_cool(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_ts_cool = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COOL);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ts_cool;
} // getter

const char* BQ25798Component::get_ts_cool_string(bool read_from_i2c) {
  int value = get_ts_cool(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TS_COOL_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_ts_cool(bool value) {
  on_init_set_ts_cool_ = value;
}

void BQ25798Component::set_ts_cool(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TS_COOL to %d (<TS_COOL_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_ts_cool = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TS_COOL);

    uint8_t reg_value;
     if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
       this->mark_failed();
     }
  }
};

// TS_WARM - 
int BQ25798Component::get_ts_warm(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_ts_warm = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_WARM);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ts_warm;
} // getter

const char* BQ25798Component::get_ts_warm_string(bool read_from_i2c) {
  int value = get_ts_warm(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TS_WARM_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_ts_warm(bool value) {
  on_init_set_ts_warm_ = value;
}

void BQ25798Component::set_ts_warm(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TS_WARM to %d (<TS_WARM_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_ts_warm = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TS_WARM);

    uint8_t reg_value;
     if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
       this->mark_failed();
     }
  }
};

// BHOT - 
int BQ25798Component::get_bhot(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_bhot = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BHOT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_bhot;
} // getter

const char* BQ25798Component::get_bhot_string(bool read_from_i2c) {
  int value = get_bhot(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->BHOT_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_bhot(bool value) {
  on_init_set_bhot_ = value;
}

void BQ25798Component::set_bhot(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s BHOT to %d (<BHOT_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_bhot = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->BHOT);

    uint8_t reg_value;
     if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 2);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 2) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 2);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
       this->mark_failed();
     }
  }
};

// BCOLD - 
int BQ25798Component::get_bcold(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_bcold = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BCOLD);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_bcold;
} // getter

const char* BQ25798Component::get_bcold_string(bool read_from_i2c) {
  int value = get_bcold(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->BCOLD_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_bcold(bool value) {
  on_init_set_bcold_ = value;
}

void BQ25798Component::set_bcold(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s BCOLD to %d (<BCOLD_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_bcold = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->BCOLD);

    uint8_t reg_value;
     if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
       this->mark_failed();
     }
  }
};

// TS_IGNORE - 
bool BQ25798Component::get_ts_ignore(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ts_ignore = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_IGNORE);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ts_ignore;
} // getter


void BQ25798Component::on_init_set_ts_ignore(bool value) {
  on_init_set_ts_ignore_ = value;
}

void BQ25798Component::set_ts_ignore(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TS_IGNORE to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_ts_ignore = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TS_IGNORE);

    uint8_t reg_value;
     if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
       this->mark_failed();
     }
  }
};

// ICO_ILIM - 
int BQ25798Component::get_ico_ilim(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG19_ICO_Current_Limit, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(9);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (9 bits) raw value: 0x%04X", raw_value);

    last_value_ico_ilim = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICO_ILIM);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ico_ilim;
} // getter

// IINDPM_STAT - 
int BQ25798Component::get_iindpm_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_iindpm_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IINDPM_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_iindpm_stat;
} // getter

const char* BQ25798Component::get_iindpm_stat_string(bool read_from_i2c) {
  int value = get_iindpm_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->IINDPM_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// VINDPM_STAT - 
int BQ25798Component::get_vindpm_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vindpm_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VINDPM_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vindpm_stat;
} // getter

const char* BQ25798Component::get_vindpm_stat_string(bool read_from_i2c) {
  int value = get_vindpm_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VINDPM_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// WD_STAT - 
int BQ25798Component::get_wd_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_wd_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WD_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_wd_stat;
} // getter

const char* BQ25798Component::get_wd_stat_string(bool read_from_i2c) {
  int value = get_wd_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->WD_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// PG_STAT - 
int BQ25798Component::get_pg_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_pg_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PG_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_pg_stat;
} // getter

const char* BQ25798Component::get_pg_stat_string(bool read_from_i2c) {
  int value = get_pg_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->PG_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// AC2_PRESENT_STAT - 
int BQ25798Component::get_ac2_present_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ac2_present_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->AC2_PRESENT_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ac2_present_stat;
} // getter

const char* BQ25798Component::get_ac2_present_stat_string(bool read_from_i2c) {
  int value = get_ac2_present_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->AC2_PRESENT_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// AC1_PRESENT_STAT - 
int BQ25798Component::get_ac1_present_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ac1_present_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->AC1_PRESENT_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ac1_present_stat;
} // getter

const char* BQ25798Component::get_ac1_present_stat_string(bool read_from_i2c) {
  int value = get_ac1_present_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->AC1_PRESENT_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// VBUS_PRESENT_STAT - 
int BQ25798Component::get_vbus_present_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vbus_present_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_PRESENT_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbus_present_stat;
} // getter

const char* BQ25798Component::get_vbus_present_stat_string(bool read_from_i2c) {
  int value = get_vbus_present_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VBUS_PRESENT_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// CHG_STAT - Charge Status bits
int BQ25798Component::get_chg_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1C_Charger_Status_1\") value: 0x%02X", REG1C_Charger_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);

    last_value_chg_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_chg_stat;
} // getter

const char* BQ25798Component::get_chg_stat_string(bool read_from_i2c) {
  int value = get_chg_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->CHG_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// VBUS_STAT - VBUS status bits
int BQ25798Component::get_vbus_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1C_Charger_Status_1\") value: 0x%02X", REG1C_Charger_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(4);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (4 bits) raw value: 0x%04X", raw_value);

    last_value_vbus_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbus_stat;
} // getter

const char* BQ25798Component::get_vbus_stat_string(bool read_from_i2c) {
  int value = get_vbus_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VBUS_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// BC12_DONE_STAT - 
bool BQ25798Component::get_bc12_done_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1C_Charger_Status_1\") value: 0x%02X", REG1C_Charger_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_bc12_done_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->BC12_DONE_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_bc12_done_stat;
} // getter

// ICO_STAT - 
int BQ25798Component::get_ico_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1D_Charger_Status_2\") value: 0x%02X", REG1D_Charger_Status_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_ico_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICO_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ico_stat;
} // getter

const char* BQ25798Component::get_ico_stat_string(bool read_from_i2c) {
  int value = get_ico_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->ICO_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// TREG_STAT - 
int BQ25798Component::get_treg_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1D_Charger_Status_2\") value: 0x%02X", REG1D_Charger_Status_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_treg_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TREG_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_treg_stat;
} // getter

const char* BQ25798Component::get_treg_stat_string(bool read_from_i2c) {
  int value = get_treg_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TREG_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// DPDM_STAT - 
int BQ25798Component::get_dpdm_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1D_Charger_Status_2\") value: 0x%02X", REG1D_Charger_Status_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_dpdm_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPDM_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dpdm_stat;
} // getter

const char* BQ25798Component::get_dpdm_stat_string(bool read_from_i2c) {
  int value = get_dpdm_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->DPDM_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// VBAT_PRESENT_STAT - 
int BQ25798Component::get_vbat_present_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1D_Charger_Status_2\") value: 0x%02X", REG1D_Charger_Status_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vbat_present_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_PRESENT_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbat_present_stat;
} // getter

const char* BQ25798Component::get_vbat_present_stat_string(bool read_from_i2c) {
  int value = get_vbat_present_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VBAT_PRESENT_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// ACRB2_STAT - The ACFET2-RBFET2 status
bool BQ25798Component::get_acrb2_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_acrb2_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ACRB2_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_acrb2_stat;
} // getter

// ACRB1_STAT - The ACFET1-RBFET1 status
bool BQ25798Component::get_acrb1_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_acrb1_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ACRB1_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_acrb1_stat;
} // getter

// ADC_DONE_STAT - ADC Conversion Status
bool BQ25798Component::get_adc_done_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_adc_done_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_DONE_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_adc_done_stat;
} // getter

// VSYS_STAT - VSYS Regulation Status
int BQ25798Component::get_vsys_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vsys_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYS_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vsys_stat;
} // getter

const char* BQ25798Component::get_vsys_stat_string(bool read_from_i2c) {
  int value = get_vsys_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VSYS_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// CHG_TMR_STAT - Fast charge timer status
int BQ25798Component::get_chg_tmr_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_chg_tmr_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_TMR_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_chg_tmr_stat;
} // getter

const char* BQ25798Component::get_chg_tmr_stat_string(bool read_from_i2c) {
  int value = get_chg_tmr_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->CHG_TMR_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// TRICHG_TMR_STAT - Trickle charge timer status
int BQ25798Component::get_trichg_tmr_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_trichg_tmr_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TRICHG_TMR_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_trichg_tmr_stat;
} // getter

const char* BQ25798Component::get_trichg_tmr_stat_string(bool read_from_i2c) {
  int value = get_trichg_tmr_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TRICHG_TMR_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// PRECHG_TMR_STAT - Pre-charge timer status
int BQ25798Component::get_prechg_tmr_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_prechg_tmr_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PRECHG_TMR_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_prechg_tmr_stat;
} // getter

const char* BQ25798Component::get_prechg_tmr_stat_string(bool read_from_i2c) {
  int value = get_prechg_tmr_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->PRECHG_TMR_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// VBATOTG_LOW_STAT - VBAT too low to enable OTG flag
int BQ25798Component::get_vbatotg_low_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vbatotg_low_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBATOTG_LOW_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbatotg_low_stat;
} // getter

const char* BQ25798Component::get_vbatotg_low_stat_string(bool read_from_i2c) {
  int value = get_vbatotg_low_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VBATOTG_LOW_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// TS_COLD_STAT - The TS temperature is in the cold range
int BQ25798Component::get_ts_cold_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ts_cold_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COLD_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ts_cold_stat;
} // getter

const char* BQ25798Component::get_ts_cold_stat_string(bool read_from_i2c) {
  int value = get_ts_cold_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TS_COLD_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// TS_COOL_STAT - The TS temperature is in the cool range
int BQ25798Component::get_ts_cool_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ts_cool_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COOL_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ts_cool_stat;
} // getter

const char* BQ25798Component::get_ts_cool_stat_string(bool read_from_i2c) {
  int value = get_ts_cool_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TS_COOL_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// TS_WARM_STAT - The TS temperature is in the warm range
int BQ25798Component::get_ts_warm_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ts_warm_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_WARM_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ts_warm_stat;
} // getter

const char* BQ25798Component::get_ts_warm_stat_string(bool read_from_i2c) {
  int value = get_ts_warm_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TS_WARM_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// TS_HOT_STAT - The TS temperature is in the hot range
int BQ25798Component::get_ts_hot_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ts_hot_stat = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_HOT_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ts_hot_stat;
} // getter

const char* BQ25798Component::get_ts_hot_stat_string(bool read_from_i2c) {
  int value = get_ts_hot_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TS_HOT_STAT_strings);  // not nice, should not access toString() and strings array directly
}
// IBAT_REG_STAT - IBAT regulation status
bool BQ25798Component::get_ibat_reg_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ibat_reg_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_REG_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ibat_reg_stat;
} // getter

// VBUS_OVP_STAT - VBUS over-voltage status
bool BQ25798Component::get_vbus_ovp_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vbus_ovp_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_OVP_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbus_ovp_stat;
} // getter

// VBAT_OVP_STAT - VBAT over-voltage status
bool BQ25798Component::get_vbat_ovp_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vbat_ovp_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_OVP_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbat_ovp_stat;
} // getter

// IBUS_OCP_STAT - IBUS over-current status
bool BQ25798Component::get_ibus_ocp_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ibus_ocp_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_OCP_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ibus_ocp_stat;
} // getter

// IBAT_OCP_STAT - IBAT over-current status
bool BQ25798Component::get_ibat_ocp_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ibat_ocp_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_OCP_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ibat_ocp_stat;
} // getter

// CONV_OCP_STAT - Converter over-current status
bool BQ25798Component::get_conv_ocp_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_conv_ocp_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CONV_OCP_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_conv_ocp_stat;
} // getter

// VAC2_OVP_STAT - VAC2 over-voltage status
bool BQ25798Component::get_vac2_ovp_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vac2_ovp_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_OVP_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vac2_ovp_stat;
} // getter

// VAC1_OVP_STAT - VAC1 over-voltage status
bool BQ25798Component::get_vac1_ovp_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vac1_ovp_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_OVP_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vac1_ovp_stat;
} // getter

// VSYS_SHORT_STAT - 
bool BQ25798Component::get_vsys_short_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vsys_short_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_SHORT_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vsys_short_stat;
} // getter

// VSYS_OVP_STAT - 
bool BQ25798Component::get_vsys_ovp_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vsys_ovp_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_OVP_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vsys_ovp_stat;
} // getter

// OTG_OVP_STAT - 
bool BQ25798Component::get_otg_ovp_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_otg_ovp_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_OVP_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_otg_ovp_stat;
} // getter

// OTG_UVP_STAT - 
bool BQ25798Component::get_otg_uvp_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_otg_uvp_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_UVP_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_otg_uvp_stat;
} // getter

// TSHUT_STAT - 
bool BQ25798Component::get_tshut_stat(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_tshut_stat = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TSHUT_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_tshut_stat;
} // getter

// IINDPM_FLAG - In IINDPM / IOTG regulation
bool BQ25798Component::get_iindpm_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_iindpm_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IINDPM_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_iindpm_flag;
} // getter

// VINDPM_FLAG - In VINDPM / VOTG regulation
bool BQ25798Component::get_vindpm_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vindpm_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VINDPM_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vindpm_flag;
} // getter

// WD_FLAG - Watchdog timer expired
bool BQ25798Component::get_wd_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_wd_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->WD_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_wd_flag;
} // getter

// POORSRC_FLAG - Poor source detected
bool BQ25798Component::get_poorsrc_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_poorsrc_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->POORSRC_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_poorsrc_flag;
} // getter

// PG_FLAG - Power status changed
bool BQ25798Component::get_pg_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_pg_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PG_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_pg_flag;
} // getter

// AC2_PRESENT_FLAG - AC2 present status changed
bool BQ25798Component::get_ac2_present_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ac2_present_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AC2_PRESENT_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ac2_present_flag;
} // getter

// AC1_PRESENT_FLAG - AC1 present status changed
bool BQ25798Component::get_ac1_present_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ac1_present_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AC1_PRESENT_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ac1_present_flag;
} // getter

// VBUS_PRESENT_FLAG - VBUS present status changed
bool BQ25798Component::get_vbus_present_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vbus_present_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_PRESENT_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbus_present_flag;
} // getter

// CHG_FLAG - Charging status changed
bool BQ25798Component::get_chg_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_chg_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CHG_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_chg_flag;
} // getter

// ICO_FLAG - ICO status changed
bool BQ25798Component::get_ico_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ico_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ICO_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ico_flag;
} // getter

// VBUS_FLAG - VBUS status changed
bool BQ25798Component::get_vbus_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vbus_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbus_flag;
} // getter

// TREG_FLAG - 
bool BQ25798Component::get_treg_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_treg_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TREG_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_treg_flag;
} // getter

// VBAT_PRESENT_FLAG - 
bool BQ25798Component::get_vbat_present_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vbat_present_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_PRESENT_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbat_present_flag;
} // getter

// BC1_2_DONE_FLAG - 
bool BQ25798Component::get_bc1_2_done_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_bc1_2_done_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->BC1_2_DONE_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_bc1_2_done_flag;
} // getter

// DPDM_DONE_FLAG - 
bool BQ25798Component::get_dpdm_done_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_dpdm_done_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DPDM_DONE_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dpdm_done_flag;
} // getter

// ADC_DONE_FLAG - 
bool BQ25798Component::get_adc_done_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_adc_done_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_DONE_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_adc_done_flag;
} // getter

// VSYS_FLAG - 
bool BQ25798Component::get_vsys_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vsys_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vsys_flag;
} // getter

// CHG_TMR_FLAG - 
bool BQ25798Component::get_chg_tmr_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_chg_tmr_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CHG_TMR_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_chg_tmr_flag;
} // getter

// TRICHG_TMR_FLAG - 
bool BQ25798Component::get_trichg_tmr_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_trichg_tmr_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TRICHG_TMR_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_trichg_tmr_flag;
} // getter

// PRECHG_TMR_FLAG - 
bool BQ25798Component::get_prechg_tmr_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_prechg_tmr_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PRECHG_TMR_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_prechg_tmr_flag;
} // getter

// TOPOFF_TMR_FLAG - 
bool BQ25798Component::get_topoff_tmr_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_topoff_tmr_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TOPOFF_TMR_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_topoff_tmr_flag;
} // getter

// VBATOTG_LOW_FLAG - 
bool BQ25798Component::get_vbatotg_low_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vbatotg_low_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBATOTG_LOW_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbatotg_low_flag;
} // getter

// TS_COLD_FLAG - 
bool BQ25798Component::get_ts_cold_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ts_cold_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_COLD_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ts_cold_flag;
} // getter

// TS_COOL_FLAG - 
bool BQ25798Component::get_ts_cool_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ts_cool_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_COOL_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ts_cool_flag;
} // getter

// TS_WARM_FLAG - 
bool BQ25798Component::get_ts_warm_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ts_warm_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_WARM_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ts_warm_flag;
} // getter

// TS_HOT_FLAG - 
bool BQ25798Component::get_ts_hot_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ts_hot_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_HOT_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ts_hot_flag;
} // getter

// IBAT_REG_FLAG - 
bool BQ25798Component::get_ibat_reg_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ibat_reg_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_REG_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ibat_reg_flag;
} // getter

// VBUS_OVP_FLAG - 
bool BQ25798Component::get_vbus_ovp_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vbus_ovp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_OVP_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbus_ovp_flag;
} // getter

// VBAT_OVP_FLAG - 
bool BQ25798Component::get_vbat_ovp_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vbat_ovp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_OVP_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbat_ovp_flag;
} // getter

// IBUS_OCP_FLAG - 
bool BQ25798Component::get_ibus_ocp_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ibus_ocp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_OCP_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ibus_ocp_flag;
} // getter

// IBAT_OCP_FLAG - 
bool BQ25798Component::get_ibat_ocp_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ibat_ocp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_OCP_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ibat_ocp_flag;
} // getter

// CONV_OCP_FLAG - 
bool BQ25798Component::get_conv_ocp_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_conv_ocp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CONV_OCP_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_conv_ocp_flag;
} // getter

// VAC2_OVP_FLAG - 
bool BQ25798Component::get_vac2_ovp_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vac2_ovp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_OVP_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vac2_ovp_flag;
} // getter

// VAC1_OVP_FLAG - 
bool BQ25798Component::get_vac1_ovp_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vac1_ovp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_OVP_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vac1_ovp_flag;
} // getter

// VSYS_SHORT_FLAG - 
bool BQ25798Component::get_vsys_short_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vsys_short_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_SHORT_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vsys_short_flag;
} // getter

// VSYS_OVP_FLAG - 
bool BQ25798Component::get_vsys_ovp_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vsys_ovp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_OVP_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vsys_ovp_flag;
} // getter

// OTG_OVP_FLAG - 
bool BQ25798Component::get_otg_ovp_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_otg_ovp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_OVP_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_otg_ovp_flag;
} // getter

// OTG_UVP_FLAG - 
bool BQ25798Component::get_otg_uvp_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_otg_uvp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_UVP_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_otg_uvp_flag;
} // getter

// TSHUT_FLAG - 
bool BQ25798Component::get_tshut_flag(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_tshut_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TSHUT_FLAG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_tshut_flag;
} // getter

// ADC_EN - 
bool BQ25798Component::get_adc_en(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_adc_en = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_EN);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_adc_en;
} // getter


void BQ25798Component::on_init_set_adc_en(bool value) {
  on_init_set_adc_en_ = value;
}

void BQ25798Component::set_adc_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_adc_en = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->ADC_EN);

    uint8_t reg_value;
     if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// ADC_RATE - 
int BQ25798Component::get_adc_rate(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_adc_rate = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_RATE);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_adc_rate;
} // getter

const char* BQ25798Component::get_adc_rate_string(bool read_from_i2c) {
  int value = get_adc_rate(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->ADC_RATE_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_adc_rate(bool value) {
  on_init_set_adc_rate_ = value;
}

void BQ25798Component::set_adc_rate(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_RATE to %d (<ADC_RATE_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_adc_rate = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ADC_RATE);

    uint8_t reg_value;
     if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// ADC_SAMPLE - 
int BQ25798Component::get_adc_sample(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);

    last_value_adc_sample = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_SAMPLE);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_adc_sample;
} // getter

const char* BQ25798Component::get_adc_sample_string(bool read_from_i2c) {
  int value = get_adc_sample(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->ADC_SAMPLE_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_adc_sample(bool value) {
  on_init_set_adc_sample_ = value;
}

void BQ25798Component::set_adc_sample(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_SAMPLE to %d (<ADC_SAMPLE_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_adc_sample = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ADC_SAMPLE);

    uint8_t reg_value;
     if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
     // ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// ADC_AVG - 
int BQ25798Component::get_adc_avg(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_adc_avg = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_AVG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_adc_avg;
} // getter

const char* BQ25798Component::get_adc_avg_string(bool read_from_i2c) {
  int value = get_adc_avg(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->ADC_AVG_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_adc_avg(bool value) {
  on_init_set_adc_avg_ = value;
}

void BQ25798Component::set_adc_avg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_AVG to %d (<ADC_AVG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_adc_avg = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ADC_AVG);

    uint8_t reg_value;
     if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// ADC_AVG_INIT - 
bool BQ25798Component::get_adc_avg_init(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_adc_avg_init = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_AVG_INIT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_adc_avg_init;
} // getter


void BQ25798Component::on_init_set_adc_avg_init(bool value) {
  on_init_set_adc_avg_init_ = value;
}

void BQ25798Component::set_adc_avg_init(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_AVG_INIT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_adc_avg_init = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->ADC_AVG_INIT);

    uint8_t reg_value;
     if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
       this->mark_failed();
     }
  }
};

// IBUS_ADC_DIS - 
bool BQ25798Component::get_ibus_adc_dis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ibus_adc_dis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_ADC_DIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ibus_adc_dis;
} // getter


void BQ25798Component::on_init_set_ibus_adc_dis(bool value) {
  on_init_set_ibus_adc_dis_ = value;
}

void BQ25798Component::set_ibus_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IBUS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_ibus_adc_dis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IBUS_ADC_DIS);

    uint8_t reg_value;
     if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// IBAT_ADC_DIS - 
bool BQ25798Component::get_ibat_adc_dis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ibat_adc_dis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_ADC_DIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ibat_adc_dis;
} // getter


void BQ25798Component::on_init_set_ibat_adc_dis(bool value) {
  on_init_set_ibat_adc_dis_ = value;
}

void BQ25798Component::set_ibat_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IBAT_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_ibat_adc_dis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IBAT_ADC_DIS);

    uint8_t reg_value;
     if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// VBUS_ADC_DIS - 
bool BQ25798Component::get_vbus_adc_dis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vbus_adc_dis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_ADC_DIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbus_adc_dis;
} // getter


void BQ25798Component::on_init_set_vbus_adc_dis(bool value) {
  on_init_set_vbus_adc_dis_ = value;
}

void BQ25798Component::set_vbus_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBUS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_vbus_adc_dis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBUS_ADC_DIS);

    uint8_t reg_value;
     if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// VBAT_ADC_DIS - 
bool BQ25798Component::get_vbat_adc_dis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vbat_adc_dis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_ADC_DIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbat_adc_dis;
} // getter


void BQ25798Component::on_init_set_vbat_adc_dis(bool value) {
  on_init_set_vbat_adc_dis_ = value;
}

void BQ25798Component::set_vbat_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBAT_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_vbat_adc_dis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBAT_ADC_DIS);

    uint8_t reg_value;
     if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// VSYS_ADC_DIS - 
bool BQ25798Component::get_vsys_adc_dis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vsys_adc_dis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_ADC_DIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vsys_adc_dis;
} // getter


void BQ25798Component::on_init_set_vsys_adc_dis(bool value) {
  on_init_set_vsys_adc_dis_ = value;
}

void BQ25798Component::set_vsys_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VSYS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_vsys_adc_dis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VSYS_ADC_DIS);

    uint8_t reg_value;
     if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// TS_ADC_DIS - 
bool BQ25798Component::get_ts_adc_dis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_ts_adc_dis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_ADC_DIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ts_adc_dis;
} // getter


void BQ25798Component::on_init_set_ts_adc_dis(bool value) {
  on_init_set_ts_adc_dis_ = value;
}

void BQ25798Component::set_ts_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_ts_adc_dis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TS_ADC_DIS);

    uint8_t reg_value;
     if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// TDIE_ADC_DIS - 
bool BQ25798Component::get_tdie_adc_dis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_tdie_adc_dis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TDIE_ADC_DIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_tdie_adc_dis;
} // getter


void BQ25798Component::on_init_set_tdie_adc_dis(bool value) {
  on_init_set_tdie_adc_dis_ = value;
}

void BQ25798Component::set_tdie_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TDIE_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_tdie_adc_dis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TDIE_ADC_DIS);

    uint8_t reg_value;
     if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
       this->mark_failed();
     }
  }
};

// DPLUS_ADC_DIS - 
bool BQ25798Component::get_dplus_adc_dis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_dplus_adc_dis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DPLUS_ADC_DIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dplus_adc_dis;
} // getter


void BQ25798Component::on_init_set_dplus_adc_dis(bool value) {
  on_init_set_dplus_adc_dis_ = value;
}

void BQ25798Component::set_dplus_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DPLUS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_dplus_adc_dis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DPLUS_ADC_DIS);

    uint8_t reg_value;
     if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
       this->mark_failed();
     }
  }
};

// DMINUS_ADC_DIS - 
bool BQ25798Component::get_dminus_adc_dis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_dminus_adc_dis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DMINUS_ADC_DIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dminus_adc_dis;
} // getter


void BQ25798Component::on_init_set_dminus_adc_dis(bool value) {
  on_init_set_dminus_adc_dis_ = value;
}

void BQ25798Component::set_dminus_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DMINUS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_dminus_adc_dis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DMINUS_ADC_DIS);

    uint8_t reg_value;
     if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
       this->mark_failed();
     }
  }
};

// VAC2_ADC_DIS - 
bool BQ25798Component::get_vac2_adc_dis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vac2_adc_dis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_ADC_DIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vac2_adc_dis;
} // getter


void BQ25798Component::on_init_set_vac2_adc_dis(bool value) {
  on_init_set_vac2_adc_dis_ = value;
}

void BQ25798Component::set_vac2_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC2_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_vac2_adc_dis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC2_ADC_DIS);

    uint8_t reg_value;
     if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
       this->mark_failed();
     }
  }
};

// VAC1_ADC_DIS - 
bool BQ25798Component::get_vac1_adc_dis(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    last_value_vac1_adc_dis = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_ADC_DIS);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vac1_adc_dis;
} // getter


void BQ25798Component::on_init_set_vac1_adc_dis(bool value) {
  on_init_set_vac1_adc_dis_ = value;
}

void BQ25798Component::set_vac1_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC1_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  last_value_vac1_adc_dis = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC1_ADC_DIS);

    uint8_t reg_value;
     if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
     // ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
       this->mark_failed();
     }
  }
};

// IBUS_ADC - 
int BQ25798Component::get_ibus_adc(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG31_IBUS_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    last_value_ibus_adc = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBUS_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ibus_adc;
} // getter

// IBAT_ADC - 
int BQ25798Component::get_ibat_adc(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG33_IBAT_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    last_value_ibat_adc = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBAT_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ibat_adc;
} // getter

// VBUS_ADC - 
int BQ25798Component::get_vbus_adc(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG35_VBUS_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    last_value_vbus_adc = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbus_adc;
} // getter

// VAC1_ADC - 
int BQ25798Component::get_vac1_adc(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG37_VAC1_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    last_value_vac1_adc = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC1_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vac1_adc;
} // getter

// VAC2_ADC - 
int BQ25798Component::get_vac2_adc(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG39_VAC2_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    last_value_vac2_adc = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC2_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vac2_adc;
} // getter

// VBAT_ADC - 
int BQ25798Component::get_vbat_adc(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG3B_VBAT_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    last_value_vbat_adc = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vbat_adc;
} // getter

// VSYS_ADC - 
int BQ25798Component::get_vsys_adc(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG3D_VSYS_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    last_value_vsys_adc = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYS_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_vsys_adc;
} // getter

// TS_ADC - 
float BQ25798Component::get_ts_adc(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG3F_TS_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    last_value_ts_adc = this->bq25798_noi2c->rawToFloat(raw_value, this->bq25798_noi2c->TS_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_ts_adc;
} // getter

// TDIE_ADC - TDIE ADC reading
float BQ25798Component::get_tdie_adc(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG41_TDIE_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    last_value_tdie_adc = this->bq25798_noi2c->rawToFloat(raw_value, this->bq25798_noi2c->TDIE_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_tdie_adc;
} // getter

// DPLUS_ADC - D+ ADC reading
int BQ25798Component::get_dplus_adc(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG43_DPLUS_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    last_value_dplus_adc = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPLUS_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dplus_adc;
} // getter

// DMINUS_ADC - D- ADC reading
int BQ25798Component::get_dminus_adc(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG45_DMINUS_ADC, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);

    last_value_dminus_adc = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DMINUS_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dminus_adc;
} // getter

// DPLUS_DAC - D+ Output Driver
int BQ25798Component::get_dplus_dac(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG47_DPDM_Driver\") value: 0x%02X", REG47_DPDM_Driver, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);

    last_value_dplus_dac = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPLUS_DAC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dplus_dac;
} // getter

const char* BQ25798Component::get_dplus_dac_string(bool read_from_i2c) {
  int value = get_dplus_dac(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->DPLUS_DAC_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_dplus_dac(bool value) {
  on_init_set_dplus_dac_ = value;
}

void BQ25798Component::set_dplus_dac(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DPLUS_DAC to %d (<DPLUS_DAC_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_dplus_dac = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->DPLUS_DAC);

    uint8_t reg_value;
     if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG47_DPDM_Driver\") value: 0x%02X", REG47_DPDM_Driver,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
     // ESP_LOGD(TAG, "  masked (3 bits shifted by 5) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG47_DPDM_Driver, reg_value)) {
       this->mark_failed();
     }
  }
};

// DMINUS_DAC - D- Output Driver
int BQ25798Component::get_dminus_dac(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG47_DPDM_Driver\") value: 0x%02X", REG47_DPDM_Driver, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (3 bits) raw value: 0x%04X", raw_value);

    last_value_dminus_dac = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DMINUS_DAC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dminus_dac;
} // getter

const char* BQ25798Component::get_dminus_dac_string(bool read_from_i2c) {
  int value = get_dminus_dac(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->DMINUS_DAC_strings);  // not nice, should not access toString() and strings array directly
}

void BQ25798Component::on_init_set_dminus_dac(bool value) {
  on_init_set_dminus_dac_ = value;
}

void BQ25798Component::set_dminus_dac(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DMINUS_DAC to %d (<DMINUS_DAC_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  last_value_dminus_dac = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->DMINUS_DAC);

    uint8_t reg_value;
     if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
       this->mark_failed();
       return;
     }
     // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG47_DPDM_Driver\") value: 0x%02X", REG47_DPDM_Driver,    reg_value);
     // mask out the bits we are going to change
     reg_value &= ~(BITLENGTH_TO_MASK(3) << 2);
     // ESP_LOGD(TAG, "  masked (3 bits shifted by 2) register value: 0x%02X", reg_value);
     // shift the new value into place and mask it
     reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 2);
     // ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
     if (!this->write_byte(REG47_DPDM_Driver, reg_value)) {
       this->mark_failed();
     }
  }
};

// PN - 
int BQ25798Component::get_pn(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG48_Part_Information, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG48_Part_Information\") value: 0x%02X", REG48_Part_Information, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (3 bits) raw value: 0x%04X", raw_value);

    last_value_pn = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PN);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_pn;
} // getter

const char* BQ25798Component::get_pn_string(bool read_from_i2c) {
  int value = get_pn(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->PN_strings);  // not nice, should not access toString() and strings array directly
}
// DEV_REV - 
int BQ25798Component::get_dev_rev(bool read_from_i2c) {
  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG48_Part_Information, &reg_value)) {
      this->mark_failed();
    }
    // ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG48_Part_Information\") value: 0x%02X", REG48_Part_Information, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (3 bits) raw value: 0x%04X", raw_value);

    last_value_dev_rev = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DEV_REV);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return last_value_dev_rev;
} // getter

const char* BQ25798Component::get_dev_rev_string(bool read_from_i2c) {
  int value = get_dev_rev(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->DEV_REV_strings);  // not nice, should not access toString() and strings array directly
}

}  // namespace bq25798
}  // namespace esphome