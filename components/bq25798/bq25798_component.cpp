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

  uint8_t raw_value;
  if (!this->read_byte(REG00_Minimal_System_Voltage, &raw_value)) {
     this->mark_failed();
     return;
  }

  delay(1);
}

void BQ25798Component::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798 configuration...");

  LOG_I2C_DEVICE(this);
  if (this->is_failed()) {
    ESP_LOGE(TAG, "Communication with BQ25798 failed!");
    return;
  }

  LOG_UPDATE_INTERVAL(this);
  LOG_SENSOR("  ", "VSYSMIN", this->vsysmin_sensor_);
  LOG_SENSOR("  ", "VREG", this->vreg_sensor_);
  LOG_SENSOR("  ", "ICHG", this->ichg_sensor_);
  LOG_SENSOR("  ", "VINDPM", this->vindpm_sensor_);
  LOG_SENSOR("  ", "IINDPM", this->iindpm_sensor_);
  LOG_SENSOR("  ", "VBAT_LOWV", this->vbat_lowv_sensor_);
  LOG_SENSOR("  ", "IPRECHG", this->iprechg_sensor_);
  LOG_SENSOR("  ", "ITERM", this->iterm_sensor_);
  LOG_SENSOR("  ", "CELL", this->cell_sensor_);
  LOG_SENSOR("  ", "TRECHG", this->trechg_sensor_);
  LOG_SENSOR("  ", "VRECHG", this->vrechg_sensor_);
  LOG_SENSOR("  ", "VOTG", this->votg_sensor_);
  LOG_SENSOR("  ", "PRECHG_TMR", this->prechg_tmr_sensor_);
  LOG_SENSOR("  ", "IOTG", this->iotg_sensor_);
  LOG_SENSOR("  ", "TOPOFF_TMR", this->topoff_tmr_sensor_);
  LOG_SENSOR("  ", "CHG_TMR", this->chg_tmr_sensor_);
  LOG_SENSOR("  ", "VBUS_BACKUP", this->vbus_backup_sensor_);
  LOG_SENSOR("  ", "VAC_OVP", this->vac_ovp_sensor_);
  LOG_SENSOR("  ", "WATCHDOG", this->watchdog_sensor_);
  LOG_SENSOR("  ", "SDRV_CTRL", this->sdrv_ctrl_sensor_);
  LOG_SENSOR("  ", "SDRV_DLY", this->sdrv_dly_sensor_);
  LOG_SENSOR("  ", "WKUP_DLY", this->wkup_dly_sensor_);
  LOG_SENSOR("  ", "PWM_FREQ", this->pwm_freq_sensor_);
  LOG_SENSOR("  ", "IBAT_REG", this->ibat_reg_sensor_);
  LOG_SENSOR("  ", "VOC_PCT", this->voc_pct_sensor_);
  LOG_SENSOR("  ", "VOC_DLY", this->voc_dly_sensor_);
  LOG_SENSOR("  ", "VOC_RATE", this->voc_rate_sensor_);
  LOG_SENSOR("  ", "TREG", this->treg_sensor_);
  LOG_SENSOR("  ", "TSHUT", this->tshut_sensor_);
  LOG_SENSOR("  ", "BKUP_ACFET1_ON", this->bkup_acfet1_on_sensor_);
  LOG_SENSOR("  ", "JEITA_VSET", this->jeita_vset_sensor_);
  LOG_SENSOR("  ", "JEITA_ISETH", this->jeita_iseth_sensor_);
  LOG_SENSOR("  ", "JEITA_ISETC", this->jeita_isetc_sensor_);
  LOG_SENSOR("  ", "TS_COOL", this->ts_cool_sensor_);
  LOG_SENSOR("  ", "TS_WARM", this->ts_warm_sensor_);
  LOG_SENSOR("  ", "BHOT", this->bhot_sensor_);
  LOG_SENSOR("  ", "BCOLD", this->bcold_sensor_);
  LOG_SENSOR("  ", "ICO_ILIM", this->ico_ilim_sensor_);
  LOG_SENSOR("  ", "IINDPM_STAT", this->iindpm_stat_sensor_);
  LOG_SENSOR("  ", "VINDPM_STAT", this->vindpm_stat_sensor_);
  LOG_SENSOR("  ", "WD_STAT", this->wd_stat_sensor_);
  LOG_SENSOR("  ", "PG_STAT", this->pg_stat_sensor_);
  LOG_SENSOR("  ", "AC2_PRESENT_STAT", this->ac2_present_stat_sensor_);
  LOG_SENSOR("  ", "AC1_PRESENT_STAT", this->ac1_present_stat_sensor_);
  LOG_SENSOR("  ", "VBUS_PRESENT_STAT", this->vbus_present_stat_sensor_);
  LOG_SENSOR("  ", "CHG_STAT", this->chg_stat_sensor_);
  LOG_SENSOR("  ", "VBUS_STAT", this->vbus_stat_sensor_);
  LOG_SENSOR("  ", "ICO_STAT", this->ico_stat_sensor_);
  LOG_SENSOR("  ", "TREG_STAT", this->treg_stat_sensor_);
  LOG_SENSOR("  ", "DPDM_STAT", this->dpdm_stat_sensor_);
  LOG_SENSOR("  ", "VBAT_PRESENT_STAT", this->vbat_present_stat_sensor_);
  LOG_SENSOR("  ", "VSYS_STAT", this->vsys_stat_sensor_);
  LOG_SENSOR("  ", "CHG_TMR_STAT", this->chg_tmr_stat_sensor_);
  LOG_SENSOR("  ", "TRICHG_TMR_STAT", this->trichg_tmr_stat_sensor_);
  LOG_SENSOR("  ", "PRECHG_TMR_STAT", this->prechg_tmr_stat_sensor_);
  LOG_SENSOR("  ", "VBATOTG_LOW_STAT", this->vbatotg_low_stat_sensor_);
  LOG_SENSOR("  ", "TS_COLD_STAT", this->ts_cold_stat_sensor_);
  LOG_SENSOR("  ", "TS_COOL_STAT", this->ts_cool_stat_sensor_);
  LOG_SENSOR("  ", "TS_WARM_STAT", this->ts_warm_stat_sensor_);
  LOG_SENSOR("  ", "TS_HOT_STAT", this->ts_hot_stat_sensor_);
  LOG_SENSOR("  ", "ADC_RATE", this->adc_rate_sensor_);
  LOG_SENSOR("  ", "ADC_SAMPLE", this->adc_sample_sensor_);
  LOG_SENSOR("  ", "ADC_AVG", this->adc_avg_sensor_);
  LOG_SENSOR("  ", "IBUS_ADC", this->ibus_adc_sensor_);
  LOG_SENSOR("  ", "IBAT_ADC", this->ibat_adc_sensor_);
  LOG_SENSOR("  ", "VBUS_ADC", this->vbus_adc_sensor_);
  LOG_SENSOR("  ", "VAC1_ADC", this->vac1_adc_sensor_);
  LOG_SENSOR("  ", "VAC2_ADC", this->vac2_adc_sensor_);
  LOG_SENSOR("  ", "VBAT_ADC", this->vbat_adc_sensor_);
  LOG_SENSOR("  ", "VSYS_ADC", this->vsys_adc_sensor_);
  LOG_SENSOR("  ", "TS_ADC", this->ts_adc_sensor_);
  LOG_SENSOR("  ", "TDIE_ADC", this->tdie_adc_sensor_);
  LOG_SENSOR("  ", "DPLUS_ADC", this->dplus_adc_sensor_);
  LOG_SENSOR("  ", "DMINUS_ADC", this->dminus_adc_sensor_);
  LOG_SENSOR("  ", "DPLUS_DAC", this->dplus_dac_sensor_);
  LOG_SENSOR("  ", "DMINUS_DAC", this->dminus_dac_sensor_);
  LOG_SENSOR("  ", "PN", this->pn_sensor_);
  LOG_SENSOR("  ", "DEV_REV", this->dev_rev_sensor_);

}

float BQ25798Component::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798Component::update() {
  if (this->vsysmin_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG00_Minimal_System_Voltage, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYSMIN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsysmin_sensor_->publish_state(value);
  }

  if (this->vreg_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG01_Charge_Voltage_Limit, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VREG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vreg_sensor_->publish_state(value);
  }

  if (this->ichg_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG03_Charge_Current_Limit, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICHG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ichg_sensor_->publish_state(value);
  }

  if (this->vindpm_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG05_Input_Voltage_Limit, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VINDPM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vindpm_sensor_->publish_state(value);
  }

  if (this->iindpm_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG06_Input_Current_Limit, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IINDPM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->iindpm_sensor_->publish_state(value);
  }

  if (this->vbat_lowv_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG08_Precharge_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBAT_LOWV);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_lowv_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_LOWV);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_lowv_sensor_->publish_state(value);
  }

  if (this->iprechg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG08_Precharge_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IPRECHG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->iprechg_sensor_->publish_state(value);
  }

  if (this->reg_rst_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG09_Termination_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->REG_RST);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->reg_rst_sensor_->publish_state(value);
  }

  if (this->stop_wd_chg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG09_Termination_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->STOP_WD_CHG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->stop_wd_chg_sensor_->publish_state(value);
  }

  if (this->iterm_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG09_Termination_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ITERM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->iterm_sensor_->publish_state(value);
  }

  if (this->cell_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0A_Recharge_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->CELL);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->cell_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CELL);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->cell_sensor_->publish_state(value);
  }

  if (this->trechg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0A_Recharge_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TRECHG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->trechg_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TRECHG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->trechg_sensor_->publish_state(value);
  }

  if (this->vrechg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0A_Recharge_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VRECHG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vrechg_sensor_->publish_state(value);
  }

  if (this->votg_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG0B_VOTG_regulation, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOTG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->votg_sensor_->publish_state(value);
  }

  if (this->prechg_tmr_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0D_IOTG_regulation, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PRECHG_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->prechg_tmr_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PRECHG_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->prechg_tmr_sensor_->publish_state(value);
  }

  if (this->iotg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0D_IOTG_regulation, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IOTG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->iotg_sensor_->publish_state(value);
  }

  if (this->topoff_tmr_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0E_Timer_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TOPOFF_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->topoff_tmr_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TOPOFF_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->topoff_tmr_sensor_->publish_state(value);
  }

  if (this->en_trichg_tmr_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0E_Timer_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_TRICHG_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_trichg_tmr_sensor_->publish_state(value);
  }

  if (this->en_prechg_tmr_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0E_Timer_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_PRECHG_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_prechg_tmr_sensor_->publish_state(value);
  }

  if (this->en_chg_tmr_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0E_Timer_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_CHG_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_chg_tmr_sensor_->publish_state(value);
  }

  if (this->chg_tmr_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0E_Timer_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->CHG_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_tmr_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_tmr_sensor_->publish_state(value);
  }

  if (this->tmr2x_en_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0E_Timer_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TMR2X_EN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->tmr2x_en_sensor_->publish_state(value);
  }

  if (this->en_auto_ibatdis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_AUTO_IBATDIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_auto_ibatdis_sensor_->publish_state(value);
  }

  if (this->force_ibatdis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_IBATDIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->force_ibatdis_sensor_->publish_state(value);
  }

  if (this->en_chg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_CHG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_chg_sensor_->publish_state(value);
  }

  if (this->en_ico_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ICO);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_ico_sensor_->publish_state(value);
  }

  if (this->force_ico_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_ICO);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->force_ico_sensor_->publish_state(value);
  }

  if (this->en_hiz_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_HIZ);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_hiz_sensor_->publish_state(value);
  }

  if (this->en_term_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_TERM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_term_sensor_->publish_state(value);
  }

  if (this->en_backup_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_BACKUP);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_backup_sensor_->publish_state(value);
  }

  if (this->vbus_backup_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG10_Charger_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBUS_BACKUP);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_backup_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_BACKUP);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_backup_sensor_->publish_state(value);
  }

  if (this->vac_ovp_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG10_Charger_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VAC_OVP);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac_ovp_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC_OVP);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac_ovp_sensor_->publish_state(value);
  }

  if (this->wd_rst_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG10_Charger_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->WD_RST);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->wd_rst_sensor_->publish_state(value);
  }

  if (this->watchdog_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG10_Charger_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->WATCHDOG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->watchdog_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WATCHDOG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->watchdog_sensor_->publish_state(value);
  }

  if (this->force_indet_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG11_Charger_Control_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_INDET);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->force_indet_sensor_->publish_state(value);
  }

  if (this->auto_indet_en_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG11_Charger_Control_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AUTO_INDET_EN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->auto_indet_en_sensor_->publish_state(value);
  }

  if (this->en_12v_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG11_Charger_Control_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_12V);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_12v_sensor_->publish_state(value);
  }

  if (this->en_9v_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG11_Charger_Control_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_9V);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_9v_sensor_->publish_state(value);
  }

  if (this->hvdcp_en_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG11_Charger_Control_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->HVDCP_EN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->hvdcp_en_sensor_->publish_state(value);
  }

  if (this->sdrv_ctrl_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG11_Charger_Control_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->SDRV_CTRL);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->sdrv_ctrl_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->SDRV_CTRL);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->sdrv_ctrl_sensor_->publish_state(value);
  }

  if (this->sdrv_dly_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG11_Charger_Control_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->SDRV_DLY);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->sdrv_dly_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->SDRV_DLY);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->sdrv_dly_sensor_->publish_state(value);
  }

  if (this->dis_acdrv_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_ACDRV);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dis_acdrv_sensor_->publish_state(value);
  }

  if (this->en_otg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_OTG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_otg_sensor_->publish_state(value);
  }

  if (this->pfm_otg_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PFM_OTG_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pfm_otg_dis_sensor_->publish_state(value);
  }

  if (this->pfm_fwd_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PFM_FWD_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pfm_fwd_dis_sensor_->publish_state(value);
  }

  if (this->wkup_dly_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->WKUP_DLY);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->wkup_dly_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WKUP_DLY);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->wkup_dly_sensor_->publish_state(value);
  }

  if (this->dis_ldo_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_LDO);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dis_ldo_sensor_->publish_state(value);
  }

  if (this->dis_otg_ooa_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_OTG_OOA);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dis_otg_ooa_sensor_->publish_state(value);
  }

  if (this->dis_fwd_ooa_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_FWD_OOA);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dis_fwd_ooa_sensor_->publish_state(value);
  }

  if (this->en_acdrv2_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ACDRV2);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_acdrv2_sensor_->publish_state(value);
  }

  if (this->en_acdrv1_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ACDRV1);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_acdrv1_sensor_->publish_state(value);
  }

  if (this->pwm_freq_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PWM_FREQ);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pwm_freq_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PWM_FREQ);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pwm_freq_sensor_->publish_state(value);
  }

  if (this->dis_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dis_stat_sensor_->publish_state(value);
  }

  if (this->dis_vsys_short_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_VSYS_SHORT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dis_vsys_short_sensor_->publish_state(value);
  }

  if (this->dis_votg_uvp_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_VOTG_UVP);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dis_votg_uvp_sensor_->publish_state(value);
  }

  if (this->force_vindpm_det_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_VINDPM_DET);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->force_vindpm_det_sensor_->publish_state(value);
  }

  if (this->en_ibus_ocp_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IBUS_OCP);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_ibus_ocp_sensor_->publish_state(value);
  }

  if (this->sfet_present_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG14_Charger_Control_5, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->SFET_PRESENT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->sfet_present_sensor_->publish_state(value);
  }

  if (this->en_ibat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG14_Charger_Control_5, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IBAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_ibat_sensor_->publish_state(value);
  }

  if (this->ibat_reg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG14_Charger_Control_5, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->IBAT_REG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_reg_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBAT_REG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_reg_sensor_->publish_state(value);
  }

  if (this->en_iindpm_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG14_Charger_Control_5, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IINDPM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_iindpm_sensor_->publish_state(value);
  }

  if (this->en_extilim_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG14_Charger_Control_5, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_EXTILIM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_extilim_sensor_->publish_state(value);
  }

  if (this->en_batoc_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG14_Charger_Control_5, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_BATOC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_batoc_sensor_->publish_state(value);
  }

  if (this->voc_pct_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG15_MPPT_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VOC_PCT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->voc_pct_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_PCT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->voc_pct_sensor_->publish_state(value);
  }

  if (this->voc_dly_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG15_MPPT_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VOC_DLY);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->voc_dly_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_DLY);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->voc_dly_sensor_->publish_state(value);
  }

  if (this->voc_rate_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG15_MPPT_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VOC_RATE);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->voc_rate_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_RATE);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->voc_rate_sensor_->publish_state(value);
  }

  if (this->en_mppt_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG15_MPPT_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_MPPT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_mppt_sensor_->publish_state(value);
  }

  if (this->treg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG16_Temperature_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TREG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->treg_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TREG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->treg_sensor_->publish_state(value);
  }

  if (this->tshut_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG16_Temperature_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TSHUT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->tshut_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TSHUT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->tshut_sensor_->publish_state(value);
  }

  if (this->vbus_pd_en_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG16_Temperature_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_PD_EN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_pd_en_sensor_->publish_state(value);
  }

  if (this->vac1_pd_en_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG16_Temperature_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_PD_EN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac1_pd_en_sensor_->publish_state(value);
  }

  if (this->vac2_pd_en_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG16_Temperature_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_PD_EN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac2_pd_en_sensor_->publish_state(value);
  }

  if (this->bkup_acfet1_on_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG16_Temperature_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->BKUP_ACFET1_ON);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bkup_acfet1_on_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BKUP_ACFET1_ON);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bkup_acfet1_on_sensor_->publish_state(value);
  }

  if (this->jeita_vset_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG17_NTC_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->JEITA_VSET);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->jeita_vset_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_VSET);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->jeita_vset_sensor_->publish_state(value);
  }

  if (this->jeita_iseth_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG17_NTC_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->JEITA_ISETH);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->jeita_iseth_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_ISETH);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->jeita_iseth_sensor_->publish_state(value);
  }

  if (this->jeita_isetc_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG17_NTC_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->JEITA_ISETC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->jeita_isetc_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_ISETC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->jeita_isetc_sensor_->publish_state(value);
  }

  if (this->ts_cool_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG18_NTC_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_COOL);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cool_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COOL);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cool_sensor_->publish_state(value);
  }

  if (this->ts_warm_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG18_NTC_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_WARM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_warm_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_WARM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_warm_sensor_->publish_state(value);
  }

  if (this->bhot_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG18_NTC_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->BHOT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bhot_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BHOT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bhot_sensor_->publish_state(value);
  }

  if (this->bcold_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG18_NTC_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->BCOLD);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bcold_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BCOLD);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bcold_sensor_->publish_state(value);
  }

  if (this->ts_ignore_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG18_NTC_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_IGNORE);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_ignore_sensor_->publish_state(value);
  }

  if (this->ico_ilim_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG19_ICO_Current_Limit, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICO_ILIM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ico_ilim_sensor_->publish_state(value);
  }

  if (this->iindpm_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->IINDPM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->iindpm_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IINDPM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->iindpm_stat_sensor_->publish_state(value);
  }

  if (this->vindpm_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VINDPM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vindpm_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VINDPM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vindpm_stat_sensor_->publish_state(value);
  }

  if (this->wd_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->WD_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->wd_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WD_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->wd_stat_sensor_->publish_state(value);
  }

  if (this->pg_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PG_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pg_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PG_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pg_stat_sensor_->publish_state(value);
  }

  if (this->ac2_present_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->AC2_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ac2_present_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->AC2_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ac2_present_stat_sensor_->publish_state(value);
  }

  if (this->ac1_present_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->AC1_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ac1_present_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->AC1_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ac1_present_stat_sensor_->publish_state(value);
  }

  if (this->vbus_present_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBUS_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_present_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_present_stat_sensor_->publish_state(value);
  }

  if (this->chg_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->CHG_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_stat_sensor_->publish_state(value);
  }

  if (this->vbus_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBUS_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_stat_sensor_->publish_state(value);
  }

  if (this->bc12_done_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->BC12_DONE_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bc12_done_stat_sensor_->publish_state(value);
  }

  if (this->ico_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->ICO_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ico_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICO_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ico_stat_sensor_->publish_state(value);
  }

  if (this->treg_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TREG_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->treg_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TREG_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->treg_stat_sensor_->publish_state(value);
  }

  if (this->dpdm_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->DPDM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dpdm_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPDM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dpdm_stat_sensor_->publish_state(value);
  }

  if (this->vbat_present_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBAT_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_present_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_present_stat_sensor_->publish_state(value);
  }

  if (this->acrb2_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ACRB2_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->acrb2_stat_sensor_->publish_state(value);
  }

  if (this->acrb1_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ACRB1_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->acrb1_stat_sensor_->publish_state(value);
  }

  if (this->adc_done_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_DONE_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_done_stat_sensor_->publish_state(value);
  }

  if (this->vsys_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VSYS_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYS_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_stat_sensor_->publish_state(value);
  }

  if (this->chg_tmr_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->CHG_TMR_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_tmr_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_TMR_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_tmr_stat_sensor_->publish_state(value);
  }

  if (this->trichg_tmr_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TRICHG_TMR_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->trichg_tmr_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TRICHG_TMR_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->trichg_tmr_stat_sensor_->publish_state(value);
  }

  if (this->prechg_tmr_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PRECHG_TMR_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->prechg_tmr_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PRECHG_TMR_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->prechg_tmr_stat_sensor_->publish_state(value);
  }

  if (this->vbatotg_low_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBATOTG_LOW_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbatotg_low_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBATOTG_LOW_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbatotg_low_stat_sensor_->publish_state(value);
  }

  if (this->ts_cold_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_COLD_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cold_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COLD_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cold_stat_sensor_->publish_state(value);
  }

  if (this->ts_cool_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_COOL_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cool_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COOL_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cool_stat_sensor_->publish_state(value);
  }

  if (this->ts_warm_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_WARM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_warm_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_WARM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_warm_stat_sensor_->publish_state(value);
  }

  if (this->ts_hot_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_HOT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_hot_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_HOT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_hot_stat_sensor_->publish_state(value);
  }

  if (this->ibat_reg_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_REG_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_reg_stat_sensor_->publish_state(value);
  }

  if (this->vbus_ovp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_OVP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_ovp_stat_sensor_->publish_state(value);
  }

  if (this->vbat_ovp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_OVP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_ovp_stat_sensor_->publish_state(value);
  }

  if (this->ibus_ocp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_OCP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibus_ocp_stat_sensor_->publish_state(value);
  }

  if (this->ibat_ocp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_OCP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_ocp_stat_sensor_->publish_state(value);
  }

  if (this->conv_ocp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CONV_OCP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->conv_ocp_stat_sensor_->publish_state(value);
  }

  if (this->vac2_ovp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_OVP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac2_ovp_stat_sensor_->publish_state(value);
  }

  if (this->vac1_ovp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_OVP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac1_ovp_stat_sensor_->publish_state(value);
  }

  if (this->vsys_short_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_SHORT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_short_stat_sensor_->publish_state(value);
  }

  if (this->vsys_ovp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_OVP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_ovp_stat_sensor_->publish_state(value);
  }

  if (this->otg_ovp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_OVP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->otg_ovp_stat_sensor_->publish_state(value);
  }

  if (this->otg_uvp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_UVP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->otg_uvp_stat_sensor_->publish_state(value);
  }

  if (this->tshut_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TSHUT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->tshut_stat_sensor_->publish_state(value);
  }

  if (this->iindpm_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IINDPM_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->iindpm_flag_sensor_->publish_state(value);
  }

  if (this->vindpm_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VINDPM_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vindpm_flag_sensor_->publish_state(value);
  }

  if (this->wd_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->WD_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->wd_flag_sensor_->publish_state(value);
  }

  if (this->poorsrc_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->POORSRC_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->poorsrc_flag_sensor_->publish_state(value);
  }

  if (this->pg_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PG_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pg_flag_sensor_->publish_state(value);
  }

  if (this->ac2_present_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AC2_PRESENT_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ac2_present_flag_sensor_->publish_state(value);
  }

  if (this->ac1_present_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AC1_PRESENT_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ac1_present_flag_sensor_->publish_state(value);
  }

  if (this->vbus_present_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_PRESENT_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_present_flag_sensor_->publish_state(value);
  }

  if (this->chg_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CHG_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_flag_sensor_->publish_state(value);
  }

  if (this->ico_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ICO_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ico_flag_sensor_->publish_state(value);
  }

  if (this->vbus_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_flag_sensor_->publish_state(value);
  }

  if (this->treg_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TREG_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->treg_flag_sensor_->publish_state(value);
  }

  if (this->vbat_present_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_PRESENT_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_present_flag_sensor_->publish_state(value);
  }

  if (this->bc1_2_done_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->BC1_2_DONE_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bc1_2_done_flag_sensor_->publish_state(value);
  }

  if (this->dpdm_done_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DPDM_DONE_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dpdm_done_flag_sensor_->publish_state(value);
  }

  if (this->adc_done_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_DONE_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_done_flag_sensor_->publish_state(value);
  }

  if (this->vsys_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_flag_sensor_->publish_state(value);
  }

  if (this->chg_tmr_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CHG_TMR_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_tmr_flag_sensor_->publish_state(value);
  }

  if (this->trichg_tmr_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TRICHG_TMR_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->trichg_tmr_flag_sensor_->publish_state(value);
  }

  if (this->prechg_tmr_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PRECHG_TMR_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->prechg_tmr_flag_sensor_->publish_state(value);
  }

  if (this->topoff_tmr_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TOPOFF_TMR_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->topoff_tmr_flag_sensor_->publish_state(value);
  }

  if (this->vbatotg_low_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBATOTG_LOW_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbatotg_low_flag_sensor_->publish_state(value);
  }

  if (this->ts_cold_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_COLD_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cold_flag_sensor_->publish_state(value);
  }

  if (this->ts_cool_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_COOL_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cool_flag_sensor_->publish_state(value);
  }

  if (this->ts_warm_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_WARM_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_warm_flag_sensor_->publish_state(value);
  }

  if (this->ts_hot_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_HOT_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_hot_flag_sensor_->publish_state(value);
  }

  if (this->ibat_reg_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_REG_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_reg_flag_sensor_->publish_state(value);
  }

  if (this->vbus_ovp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_OVP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_ovp_flag_sensor_->publish_state(value);
  }

  if (this->vbat_ovp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_OVP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_ovp_flag_sensor_->publish_state(value);
  }

  if (this->ibus_ocp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_OCP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibus_ocp_flag_sensor_->publish_state(value);
  }

  if (this->ibat_ocp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_OCP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_ocp_flag_sensor_->publish_state(value);
  }

  if (this->conv_ocp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CONV_OCP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->conv_ocp_flag_sensor_->publish_state(value);
  }

  if (this->vac2_ovp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_OVP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac2_ovp_flag_sensor_->publish_state(value);
  }

  if (this->vac1_ovp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_OVP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac1_ovp_flag_sensor_->publish_state(value);
  }

  if (this->vsys_short_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_SHORT_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_short_flag_sensor_->publish_state(value);
  }

  if (this->vsys_ovp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_OVP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_ovp_flag_sensor_->publish_state(value);
  }

  if (this->otg_ovp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_OVP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->otg_ovp_flag_sensor_->publish_state(value);
  }

  if (this->otg_uvp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_UVP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->otg_uvp_flag_sensor_->publish_state(value);
  }

  if (this->tshut_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TSHUT_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->tshut_flag_sensor_->publish_state(value);
  }

  if (this->adc_en_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2E_ADC_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_EN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_en_sensor_->publish_state(value);
  }

  if (this->adc_rate_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2E_ADC_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->ADC_RATE);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_rate_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_RATE);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_rate_sensor_->publish_state(value);
  }

  if (this->adc_sample_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2E_ADC_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->ADC_SAMPLE);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_sample_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_SAMPLE);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_sample_sensor_->publish_state(value);
  }

  if (this->adc_avg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2E_ADC_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->ADC_AVG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_avg_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_AVG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_avg_sensor_->publish_state(value);
  }

  if (this->adc_avg_init_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2E_ADC_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_AVG_INIT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_avg_init_sensor_->publish_state(value);
  }

  if (this->ibus_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibus_adc_dis_sensor_->publish_state(value);
  }

  if (this->ibat_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_adc_dis_sensor_->publish_state(value);
  }

  if (this->vbus_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_adc_dis_sensor_->publish_state(value);
  }

  if (this->vbat_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_adc_dis_sensor_->publish_state(value);
  }

  if (this->vsys_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_adc_dis_sensor_->publish_state(value);
  }

  if (this->ts_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_adc_dis_sensor_->publish_state(value);
  }

  if (this->tdie_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TDIE_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->tdie_adc_dis_sensor_->publish_state(value);
  }

  if (this->dplus_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DPLUS_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dplus_adc_dis_sensor_->publish_state(value);
  }

  if (this->dminus_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DMINUS_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dminus_adc_dis_sensor_->publish_state(value);
  }

  if (this->vac2_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac2_adc_dis_sensor_->publish_state(value);
  }

  if (this->vac1_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac1_adc_dis_sensor_->publish_state(value);
  }

  if (this->ibus_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG31_IBUS_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBUS_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibus_adc_sensor_->publish_state(value);
  }

  if (this->ibat_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG33_IBAT_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBAT_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_adc_sensor_->publish_state(value);
  }

  if (this->vbus_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG35_VBUS_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_adc_sensor_->publish_state(value);
  }

  if (this->vac1_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG37_VAC1_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC1_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac1_adc_sensor_->publish_state(value);
  }

  if (this->vac2_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG39_VAC2_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC2_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac2_adc_sensor_->publish_state(value);
  }

  if (this->vbat_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG3B_VBAT_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_adc_sensor_->publish_state(value);
  }

  if (this->vsys_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG3D_VSYS_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYS_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_adc_sensor_->publish_state(value);
  }

  if (this->ts_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG3F_TS_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    float value = this->bq25798_noi2c->rawToFloat(raw_value, this->bq25798_noi2c->TS_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_adc_sensor_->publish_state(value);
  }

  if (this->tdie_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG41_TDIE_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    float value = this->bq25798_noi2c->rawToFloat(raw_value, this->bq25798_noi2c->TDIE_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->tdie_adc_sensor_->publish_state(value);
  }

  if (this->dplus_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG43_DPLUS_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPLUS_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dplus_adc_sensor_->publish_state(value);
  }

  if (this->dminus_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG45_DMINUS_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DMINUS_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dminus_adc_sensor_->publish_state(value);
  }

  if (this->dplus_dac_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG47_DPDM_Driver, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->DPLUS_DAC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dplus_dac_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPLUS_DAC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dplus_dac_sensor_->publish_state(value);
  }

  if (this->dminus_dac_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG47_DPDM_Driver, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->DMINUS_DAC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dminus_dac_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DMINUS_DAC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dminus_dac_sensor_->publish_state(value);
  }

  if (this->pn_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG48_Part_Information, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pn_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pn_sensor_->publish_state(value);
  }

  if (this->dev_rev_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG48_Part_Information, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->DEV_REV);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dev_rev_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DEV_REV);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dev_rev_sensor_->publish_state(value);
  }

}

void BQ25798Component::set_vsysmin(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VSYSMIN", value, "mV");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VSYSMIN);

  if (!this->write_byte(REG00_Minimal_System_Voltage, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vreg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VREG", value, "mV");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VREG);

  if (!this->write_byte_16(REG01_Charge_Voltage_Limit, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ichg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "ICHG", value, "mA");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ICHG);

  if (!this->write_byte_16(REG03_Charge_Current_Limit, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vindpm(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VINDPM", value, "mV");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VINDPM);

  if (!this->write_byte(REG05_Input_Voltage_Limit, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_iindpm(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "IINDPM", value, "mA");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IINDPM);

  if (!this->write_byte_16(REG06_Input_Current_Limit, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbat_lowv(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VBAT_LOWV_t)", "VBAT_LOWV", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VBAT_LOWV);
  if (!this->write_byte(REG08_Precharge_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_iprechg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "IPRECHG", value, "mA");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IPRECHG);

  if (!this->write_byte(REG08_Precharge_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_reg_rst(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "REG_RST", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->REG_RST);

  if (!this->write_byte(REG09_Termination_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_stop_wd_chg(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "STOP_WD_CHG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->STOP_WD_CHG);

  if (!this->write_byte(REG09_Termination_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_iterm(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "ITERM", value, "mA");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ITERM);

  if (!this->write_byte(REG09_Termination_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_cell(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (CELL_t)", "CELL", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->CELL);
  if (!this->write_byte(REG0A_Recharge_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_trechg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TRECHG_t)", "TRECHG", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TRECHG);
  if (!this->write_byte(REG0A_Recharge_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vrechg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VRECHG", value, "mV");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VRECHG);

  if (!this->write_byte(REG0A_Recharge_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_votg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VOTG", value, "mV");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOTG);

  if (!this->write_byte_16(REG0B_VOTG_regulation, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_prechg_tmr(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (PRECHG_TMR_t)", "PRECHG_TMR", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->PRECHG_TMR);
  if (!this->write_byte(REG0D_IOTG_regulation, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_iotg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "IOTG", value, "mA");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IOTG);

  if (!this->write_byte(REG0D_IOTG_regulation, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_topoff_tmr(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TOPOFF_TMR_t)", "TOPOFF_TMR", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TOPOFF_TMR);
  if (!this->write_byte(REG0E_Timer_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_trichg_tmr(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_TRICHG_TMR", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_TRICHG_TMR);

  if (!this->write_byte(REG0E_Timer_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_prechg_tmr(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_PRECHG_TMR", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_PRECHG_TMR);

  if (!this->write_byte(REG0E_Timer_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_chg_tmr(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_CHG_TMR", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_CHG_TMR);

  if (!this->write_byte(REG0E_Timer_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_chg_tmr(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (CHG_TMR_t)", "CHG_TMR", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->CHG_TMR);
  if (!this->write_byte(REG0E_Timer_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_tmr2x_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TMR2X_EN", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TMR2X_EN);

  if (!this->write_byte(REG0E_Timer_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_auto_ibatdis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_AUTO_IBATDIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_AUTO_IBATDIS);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_force_ibatdis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "FORCE_IBATDIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_IBATDIS);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_chg(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_CHG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_CHG);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_ico(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_ICO", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_ICO);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_force_ico(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "FORCE_ICO", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_ICO);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_hiz(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_HIZ", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_HIZ);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_term(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_TERM", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_TERM);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_backup(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_BACKUP", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_BACKUP);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbus_backup(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VBUS_BACKUP_t)", "VBUS_BACKUP", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VBUS_BACKUP);
  if (!this->write_byte(REG10_Charger_Control_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vac_ovp(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VAC_OVP_t)", "VAC_OVP", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VAC_OVP);
  if (!this->write_byte(REG10_Charger_Control_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_wd_rst(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "WD_RST", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->WD_RST);

  if (!this->write_byte(REG10_Charger_Control_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_watchdog(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (WATCHDOG_t)", "WATCHDOG", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->WATCHDOG);
  if (!this->write_byte(REG10_Charger_Control_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_force_indet(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "FORCE_INDET", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_INDET);

  if (!this->write_byte(REG11_Charger_Control_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_auto_indet_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "AUTO_INDET_EN", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->AUTO_INDET_EN);

  if (!this->write_byte(REG11_Charger_Control_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_12v(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_12V", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_12V);

  if (!this->write_byte(REG11_Charger_Control_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_9v(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_9V", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_9V);

  if (!this->write_byte(REG11_Charger_Control_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_hvdcp_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "HVDCP_EN", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->HVDCP_EN);

  if (!this->write_byte(REG11_Charger_Control_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_sdrv_ctrl(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (SDRV_CTRL_t)", "SDRV_CTRL", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->SDRV_CTRL);
  if (!this->write_byte(REG11_Charger_Control_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_sdrv_dly(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (SDRV_DLY_t)", "SDRV_DLY", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->SDRV_DLY);
  if (!this->write_byte(REG11_Charger_Control_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dis_acdrv(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_ACDRV", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_ACDRV);

  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_otg(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_OTG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_OTG);

  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_pfm_otg_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "PFM_OTG_DIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->PFM_OTG_DIS);

  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_pfm_fwd_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "PFM_FWD_DIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->PFM_FWD_DIS);

  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_wkup_dly(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (WKUP_DLY_t)", "WKUP_DLY", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->WKUP_DLY);
  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dis_ldo(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_LDO", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_LDO);

  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dis_otg_ooa(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_OTG_OOA", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_OTG_OOA);

  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dis_fwd_ooa(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_FWD_OOA", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_FWD_OOA);

  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_acdrv2(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_ACDRV2", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_ACDRV2);

  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_acdrv1(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_ACDRV1", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_ACDRV1);

  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_pwm_freq(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (PWM_FREQ_t)", "PWM_FREQ", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->PWM_FREQ);
  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dis_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_STAT);

  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dis_vsys_short(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_VSYS_SHORT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_VSYS_SHORT);

  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dis_votg_uvp(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_VOTG_UVP", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_VOTG_UVP);

  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_force_vindpm_det(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "FORCE_VINDPM_DET", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_VINDPM_DET);

  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_ibus_ocp(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_IBUS_OCP", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_IBUS_OCP);

  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_sfet_present(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "SFET_PRESENT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->SFET_PRESENT);

  if (!this->write_byte(REG14_Charger_Control_5, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_ibat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_IBAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_IBAT);

  if (!this->write_byte(REG14_Charger_Control_5, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ibat_reg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (IBAT_REG_t)", "IBAT_REG", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IBAT_REG);
  if (!this->write_byte(REG14_Charger_Control_5, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_iindpm(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_IINDPM", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_IINDPM);

  if (!this->write_byte(REG14_Charger_Control_5, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_extilim(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_EXTILIM", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_EXTILIM);

  if (!this->write_byte(REG14_Charger_Control_5, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_batoc(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_BATOC", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_BATOC);

  if (!this->write_byte(REG14_Charger_Control_5, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_voc_pct(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VOC_PCT_t)", "VOC_PCT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOC_PCT);
  if (!this->write_byte(REG15_MPPT_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_voc_dly(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VOC_DLY_t)", "VOC_DLY", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOC_DLY);
  if (!this->write_byte(REG15_MPPT_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_voc_rate(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VOC_RATE_t)", "VOC_RATE", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOC_RATE);
  if (!this->write_byte(REG15_MPPT_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_en_mppt(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_MPPT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_MPPT);

  if (!this->write_byte(REG15_MPPT_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_treg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TREG_t)", "TREG", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TREG);
  if (!this->write_byte(REG16_Temperature_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_tshut(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TSHUT_t)", "TSHUT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TSHUT);
  if (!this->write_byte(REG16_Temperature_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbus_pd_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_PD_EN", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBUS_PD_EN);

  if (!this->write_byte(REG16_Temperature_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vac1_pd_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC1_PD_EN", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC1_PD_EN);

  if (!this->write_byte(REG16_Temperature_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vac2_pd_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC2_PD_EN", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC2_PD_EN);

  if (!this->write_byte(REG16_Temperature_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_bkup_acfet1_on(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (BKUP_ACFET1_ON_t)", "BKUP_ACFET1_ON", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->BKUP_ACFET1_ON);
  if (!this->write_byte(REG16_Temperature_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_jeita_vset(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (JEITA_VSET_t)", "JEITA_VSET", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->JEITA_VSET);
  if (!this->write_byte(REG17_NTC_Control_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_jeita_iseth(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (JEITA_ISETH_t)", "JEITA_ISETH", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->JEITA_ISETH);
  if (!this->write_byte(REG17_NTC_Control_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_jeita_isetc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (JEITA_ISETC_t)", "JEITA_ISETC", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->JEITA_ISETC);
  if (!this->write_byte(REG17_NTC_Control_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ts_cool(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TS_COOL_t)", "TS_COOL", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TS_COOL);
  if (!this->write_byte(REG18_NTC_Control_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ts_warm(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TS_WARM_t)", "TS_WARM", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TS_WARM);
  if (!this->write_byte(REG18_NTC_Control_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_bhot(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (BHOT_t)", "BHOT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->BHOT);
  if (!this->write_byte(REG18_NTC_Control_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_bcold(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (BCOLD_t)", "BCOLD", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->BCOLD);
  if (!this->write_byte(REG18_NTC_Control_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ts_ignore(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_IGNORE", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TS_IGNORE);

  if (!this->write_byte(REG18_NTC_Control_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ico_ilim(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "ICO_ILIM", value, "mA");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ICO_ILIM);

  if (!this->write_byte_16(REG19_ICO_Current_Limit, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_iindpm_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (IINDPM_STAT_t)", "IINDPM_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IINDPM_STAT);
  if (!this->write_byte(REG1B_Charger_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vindpm_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VINDPM_STAT_t)", "VINDPM_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VINDPM_STAT);
  if (!this->write_byte(REG1B_Charger_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_wd_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (WD_STAT_t)", "WD_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->WD_STAT);
  if (!this->write_byte(REG1B_Charger_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_pg_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (PG_STAT_t)", "PG_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->PG_STAT);
  if (!this->write_byte(REG1B_Charger_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ac2_present_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (AC2_PRESENT_STAT_t)", "AC2_PRESENT_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->AC2_PRESENT_STAT);
  if (!this->write_byte(REG1B_Charger_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ac1_present_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (AC1_PRESENT_STAT_t)", "AC1_PRESENT_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->AC1_PRESENT_STAT);
  if (!this->write_byte(REG1B_Charger_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbus_present_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VBUS_PRESENT_STAT_t)", "VBUS_PRESENT_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VBUS_PRESENT_STAT);
  if (!this->write_byte(REG1B_Charger_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_chg_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (CHG_STAT_t)", "CHG_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->CHG_STAT);
  if (!this->write_byte(REG1C_Charger_Status_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbus_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VBUS_STAT_t)", "VBUS_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VBUS_STAT);
  if (!this->write_byte(REG1C_Charger_Status_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_bc12_done_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "BC12_DONE_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->BC12_DONE_STAT);

  if (!this->write_byte(REG1C_Charger_Status_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ico_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (ICO_STAT_t)", "ICO_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ICO_STAT);
  if (!this->write_byte(REG1D_Charger_Status_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_treg_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TREG_STAT_t)", "TREG_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TREG_STAT);
  if (!this->write_byte(REG1D_Charger_Status_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dpdm_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (DPDM_STAT_t)", "DPDM_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->DPDM_STAT);
  if (!this->write_byte(REG1D_Charger_Status_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbat_present_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VBAT_PRESENT_STAT_t)", "VBAT_PRESENT_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VBAT_PRESENT_STAT);
  if (!this->write_byte(REG1D_Charger_Status_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_acrb2_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ACRB2_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->ACRB2_STAT);

  if (!this->write_byte(REG1E_Charger_Status_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_acrb1_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ACRB1_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->ACRB1_STAT);

  if (!this->write_byte(REG1E_Charger_Status_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_adc_done_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ADC_DONE_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->ADC_DONE_STAT);

  if (!this->write_byte(REG1E_Charger_Status_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vsys_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VSYS_STAT_t)", "VSYS_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VSYS_STAT);
  if (!this->write_byte(REG1E_Charger_Status_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_chg_tmr_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (CHG_TMR_STAT_t)", "CHG_TMR_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->CHG_TMR_STAT);
  if (!this->write_byte(REG1E_Charger_Status_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_trichg_tmr_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TRICHG_TMR_STAT_t)", "TRICHG_TMR_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TRICHG_TMR_STAT);
  if (!this->write_byte(REG1E_Charger_Status_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_prechg_tmr_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (PRECHG_TMR_STAT_t)", "PRECHG_TMR_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->PRECHG_TMR_STAT);
  if (!this->write_byte(REG1E_Charger_Status_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbatotg_low_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VBATOTG_LOW_STAT_t)", "VBATOTG_LOW_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VBATOTG_LOW_STAT);
  if (!this->write_byte(REG1F_Charger_Status_4, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ts_cold_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TS_COLD_STAT_t)", "TS_COLD_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TS_COLD_STAT);
  if (!this->write_byte(REG1F_Charger_Status_4, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ts_cool_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TS_COOL_STAT_t)", "TS_COOL_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TS_COOL_STAT);
  if (!this->write_byte(REG1F_Charger_Status_4, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ts_warm_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TS_WARM_STAT_t)", "TS_WARM_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TS_WARM_STAT);
  if (!this->write_byte(REG1F_Charger_Status_4, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ts_hot_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TS_HOT_STAT_t)", "TS_HOT_STAT", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TS_HOT_STAT);
  if (!this->write_byte(REG1F_Charger_Status_4, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ibat_reg_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_REG_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IBAT_REG_STAT);

  if (!this->write_byte(REG20_FAULT_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbus_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_OVP_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBUS_OVP_STAT);

  if (!this->write_byte(REG20_FAULT_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbat_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBAT_OVP_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBAT_OVP_STAT);

  if (!this->write_byte(REG20_FAULT_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ibus_ocp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBUS_OCP_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IBUS_OCP_STAT);

  if (!this->write_byte(REG20_FAULT_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ibat_ocp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_OCP_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IBAT_OCP_STAT);

  if (!this->write_byte(REG20_FAULT_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_conv_ocp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "CONV_OCP_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->CONV_OCP_STAT);

  if (!this->write_byte(REG20_FAULT_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vac2_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC2_OVP_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC2_OVP_STAT);

  if (!this->write_byte(REG20_FAULT_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vac1_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC1_OVP_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC1_OVP_STAT);

  if (!this->write_byte(REG20_FAULT_Status_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vsys_short_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_SHORT_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VSYS_SHORT_STAT);

  if (!this->write_byte(REG21_FAULT_Status_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vsys_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_OVP_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VSYS_OVP_STAT);

  if (!this->write_byte(REG21_FAULT_Status_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_otg_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "OTG_OVP_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->OTG_OVP_STAT);

  if (!this->write_byte(REG21_FAULT_Status_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_otg_uvp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "OTG_UVP_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->OTG_UVP_STAT);

  if (!this->write_byte(REG21_FAULT_Status_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_tshut_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TSHUT_STAT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TSHUT_STAT);

  if (!this->write_byte(REG21_FAULT_Status_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_iindpm_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IINDPM_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IINDPM_FLAG);

  if (!this->write_byte(REG22_Charger_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vindpm_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VINDPM_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VINDPM_FLAG);

  if (!this->write_byte(REG22_Charger_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_wd_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "WD_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->WD_FLAG);

  if (!this->write_byte(REG22_Charger_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_poorsrc_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "POORSRC_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->POORSRC_FLAG);

  if (!this->write_byte(REG22_Charger_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_pg_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "PG_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->PG_FLAG);

  if (!this->write_byte(REG22_Charger_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ac2_present_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "AC2_PRESENT_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->AC2_PRESENT_FLAG);

  if (!this->write_byte(REG22_Charger_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ac1_present_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "AC1_PRESENT_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->AC1_PRESENT_FLAG);

  if (!this->write_byte(REG22_Charger_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbus_present_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_PRESENT_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBUS_PRESENT_FLAG);

  if (!this->write_byte(REG22_Charger_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_chg_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "CHG_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->CHG_FLAG);

  if (!this->write_byte(REG23_Charger_Flag_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ico_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ICO_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->ICO_FLAG);

  if (!this->write_byte(REG23_Charger_Flag_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbus_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBUS_FLAG);

  if (!this->write_byte(REG23_Charger_Flag_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_treg_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TREG_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TREG_FLAG);

  if (!this->write_byte(REG23_Charger_Flag_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbat_present_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBAT_PRESENT_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBAT_PRESENT_FLAG);

  if (!this->write_byte(REG23_Charger_Flag_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_bc1_2_done_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "BC1_2_DONE_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->BC1_2_DONE_FLAG);

  if (!this->write_byte(REG23_Charger_Flag_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dpdm_done_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DPDM_DONE_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DPDM_DONE_FLAG);

  if (!this->write_byte(REG24_Charger_Flag_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_adc_done_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ADC_DONE_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->ADC_DONE_FLAG);

  if (!this->write_byte(REG24_Charger_Flag_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vsys_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VSYS_FLAG);

  if (!this->write_byte(REG24_Charger_Flag_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_chg_tmr_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "CHG_TMR_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->CHG_TMR_FLAG);

  if (!this->write_byte(REG24_Charger_Flag_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_trichg_tmr_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TRICHG_TMR_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TRICHG_TMR_FLAG);

  if (!this->write_byte(REG24_Charger_Flag_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_prechg_tmr_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "PRECHG_TMR_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->PRECHG_TMR_FLAG);

  if (!this->write_byte(REG24_Charger_Flag_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_topoff_tmr_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TOPOFF_TMR_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TOPOFF_TMR_FLAG);

  if (!this->write_byte(REG24_Charger_Flag_2, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbatotg_low_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBATOTG_LOW_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBATOTG_LOW_FLAG);

  if (!this->write_byte(REG25_Charger_Flag_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ts_cold_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_COLD_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TS_COLD_FLAG);

  if (!this->write_byte(REG25_Charger_Flag_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ts_cool_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_COOL_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TS_COOL_FLAG);

  if (!this->write_byte(REG25_Charger_Flag_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ts_warm_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_WARM_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TS_WARM_FLAG);

  if (!this->write_byte(REG25_Charger_Flag_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ts_hot_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_HOT_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TS_HOT_FLAG);

  if (!this->write_byte(REG25_Charger_Flag_3, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ibat_reg_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_REG_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IBAT_REG_FLAG);

  if (!this->write_byte(REG26_FAULT_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbus_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_OVP_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBUS_OVP_FLAG);

  if (!this->write_byte(REG26_FAULT_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbat_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBAT_OVP_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBAT_OVP_FLAG);

  if (!this->write_byte(REG26_FAULT_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ibus_ocp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBUS_OCP_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IBUS_OCP_FLAG);

  if (!this->write_byte(REG26_FAULT_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ibat_ocp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_OCP_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IBAT_OCP_FLAG);

  if (!this->write_byte(REG26_FAULT_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_conv_ocp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "CONV_OCP_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->CONV_OCP_FLAG);

  if (!this->write_byte(REG26_FAULT_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vac2_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC2_OVP_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC2_OVP_FLAG);

  if (!this->write_byte(REG26_FAULT_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vac1_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC1_OVP_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC1_OVP_FLAG);

  if (!this->write_byte(REG26_FAULT_Flag_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vsys_short_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_SHORT_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VSYS_SHORT_FLAG);

  if (!this->write_byte(REG27_FAULT_Flag_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vsys_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_OVP_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VSYS_OVP_FLAG);

  if (!this->write_byte(REG27_FAULT_Flag_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_otg_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "OTG_OVP_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->OTG_OVP_FLAG);

  if (!this->write_byte(REG27_FAULT_Flag_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_otg_uvp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "OTG_UVP_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->OTG_UVP_FLAG);

  if (!this->write_byte(REG27_FAULT_Flag_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_tshut_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TSHUT_FLAG", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TSHUT_FLAG);

  if (!this->write_byte(REG27_FAULT_Flag_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_adc_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ADC_EN", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->ADC_EN);

  if (!this->write_byte(REG2E_ADC_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_adc_rate(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (ADC_RATE_t)", "ADC_RATE", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ADC_RATE);
  if (!this->write_byte(REG2E_ADC_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_adc_sample(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (ADC_SAMPLE_t)", "ADC_SAMPLE", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ADC_SAMPLE);
  if (!this->write_byte(REG2E_ADC_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_adc_avg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (ADC_AVG_t)", "ADC_AVG", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ADC_AVG);
  if (!this->write_byte(REG2E_ADC_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_adc_avg_init(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ADC_AVG_INIT", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->ADC_AVG_INIT);

  if (!this->write_byte(REG2E_ADC_Control, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ibus_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBUS_ADC_DIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IBUS_ADC_DIS);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ibat_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_ADC_DIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IBAT_ADC_DIS);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbus_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_ADC_DIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBUS_ADC_DIS);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbat_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBAT_ADC_DIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBAT_ADC_DIS);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vsys_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_ADC_DIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VSYS_ADC_DIS);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ts_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_ADC_DIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TS_ADC_DIS);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_tdie_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TDIE_ADC_DIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TDIE_ADC_DIS);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dplus_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DPLUS_ADC_DIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DPLUS_ADC_DIS);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dminus_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DMINUS_ADC_DIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DMINUS_ADC_DIS);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vac2_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC2_ADC_DIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC2_ADC_DIS);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vac1_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC1_ADC_DIS", value ? "True" : "False");
  uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC1_ADC_DIS);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ibus_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "IBUS_ADC", value, "mA");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IBUS_ADC);

  if (!this->write_byte_16(REG31_IBUS_ADC, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ibat_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "IBAT_ADC", value, "mA");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IBAT_ADC);

  if (!this->write_byte_16(REG33_IBAT_ADC, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbus_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VBUS_ADC", value, "mV");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VBUS_ADC);

  if (!this->write_byte_16(REG35_VBUS_ADC, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vac1_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VAC1_ADC", value, "mV");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VAC1_ADC);

  if (!this->write_byte_16(REG37_VAC1_ADC, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vac2_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VAC2_ADC", value, "mV");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VAC2_ADC);

  if (!this->write_byte_16(REG39_VAC2_ADC, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vbat_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VBAT_ADC", value, "mV");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VBAT_ADC);

  if (!this->write_byte_16(REG3B_VBAT_ADC, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_vsys_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VSYS_ADC", value, "mV");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VSYS_ADC);

  if (!this->write_byte_16(REG3D_VSYS_ADC, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_ts_adc(float value) {
  ESP_LOGD(TAG, "Setting %s to %f %s", "TS_ADC", value, "%");
  uint16_t raw_value = this->bq25798_noi2c->floatToRaw(value, this->bq25798_noi2c->TS_ADC);

  if (!this->write_byte_16(REG3F_TS_ADC, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_tdie_adc(float value) {
  ESP_LOGD(TAG, "Setting %s to %f %s", "TDIE_ADC", value, "degC");
  uint16_t raw_value = this->bq25798_noi2c->floatToRaw(value, this->bq25798_noi2c->TDIE_ADC);

  if (!this->write_byte_16(REG41_TDIE_ADC, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dplus_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "DPLUS_ADC", value, "mV");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->DPLUS_ADC);

  if (!this->write_byte_16(REG43_DPLUS_ADC, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dminus_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "DMINUS_ADC", value, "mV");
  uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->DMINUS_ADC);

  if (!this->write_byte_16(REG45_DMINUS_ADC, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dplus_dac(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (DPLUS_DAC_t)", "DPLUS_DAC", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->DPLUS_DAC);
  if (!this->write_byte(REG47_DPDM_Driver, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dminus_dac(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (DMINUS_DAC_t)", "DMINUS_DAC", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->DMINUS_DAC);
  if (!this->write_byte(REG47_DPDM_Driver, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_pn(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (PN_t)", "PN", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->PN);
  if (!this->write_byte(REG48_Part_Information, raw_value)) {
    this->mark_failed();
  }
};

void BQ25798Component::set_dev_rev(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (DEV_REV_t)", "DEV_REV", value);
  uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->DEV_REV);
  if (!this->write_byte(REG48_Part_Information, raw_value)) {
    this->mark_failed();
  }
};

}  // namespace bq25798
}  // namespace esphome