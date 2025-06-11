#include "bq25798_select.h"

#include "esphome/core/log.h"

namespace esphome {
namespace bq25798 {

static const char* const TAG = "bq25798.select";


// VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
float BQ25798VbatLowvSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VbatLowvSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VbatLowvSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "VBAT_LOWV", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VbatLowvSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798VbatLowvSelect...");
  uint8_t num_value = this->parent_->get_vbat_lowv_enum_int();
  std::string str_value = BQ25798VbatLowvSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798VbatLowvSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VbatLowvSelect...");

  uint8_t num_value = BQ25798VbatLowvSelect_ENUM_TO_INT.at(value);
  this->parent_->set_vbat_lowv_enum_int(num_value);

  this->publish_state(value);
}


// CELL - Battery cell count
float BQ25798CellSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798CellSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798CellSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "CELL", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798CellSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798CellSelect...");
  uint8_t num_value = this->parent_->get_cell_enum_int();
  std::string str_value = BQ25798CellSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798CellSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798CellSelect...");

  uint8_t num_value = BQ25798CellSelect_ENUM_TO_INT.at(value);
  this->parent_->set_cell_enum_int(num_value);

  this->publish_state(value);
}


// TRECHG - Battery recharge delay time
float BQ25798TrechgSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TrechgSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TrechgSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "TRECHG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TrechgSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798TrechgSelect...");
  uint8_t num_value = this->parent_->get_trechg_enum_int();
  std::string str_value = BQ25798TrechgSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798TrechgSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798TrechgSelect...");

  uint8_t num_value = BQ25798TrechgSelect_ENUM_TO_INT.at(value);
  this->parent_->set_trechg_enum_int(num_value);

  this->publish_state(value);
}


// PRECHG_TMR - Pre-charge safety timer setting
float BQ25798PrechgTmrSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798PrechgTmrSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798PrechgTmrSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "PRECHG_TMR", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798PrechgTmrSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798PrechgTmrSelect...");
  uint8_t num_value = this->parent_->get_prechg_tmr_enum_int();
  std::string str_value = BQ25798PrechgTmrSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798PrechgTmrSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798PrechgTmrSelect...");

  uint8_t num_value = BQ25798PrechgTmrSelect_ENUM_TO_INT.at(value);
  this->parent_->set_prechg_tmr_enum_int(num_value);

  this->publish_state(value);
}


// TOPOFF_TMR - Top-off timer control
float BQ25798TopoffTmrSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TopoffTmrSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TopoffTmrSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "TOPOFF_TMR", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TopoffTmrSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798TopoffTmrSelect...");
  uint8_t num_value = this->parent_->get_topoff_tmr_enum_int();
  std::string str_value = BQ25798TopoffTmrSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798TopoffTmrSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798TopoffTmrSelect...");

  uint8_t num_value = BQ25798TopoffTmrSelect_ENUM_TO_INT.at(value);
  this->parent_->set_topoff_tmr_enum_int(num_value);

  this->publish_state(value);
}


// CHG_TMR - Fast charge timer setting
float BQ25798ChgTmrSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798ChgTmrSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798ChgTmrSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "CHG_TMR", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798ChgTmrSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798ChgTmrSelect...");
  uint8_t num_value = this->parent_->get_chg_tmr_enum_int();
  std::string str_value = BQ25798ChgTmrSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798ChgTmrSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798ChgTmrSelect...");

  uint8_t num_value = BQ25798ChgTmrSelect_ENUM_TO_INT.at(value);
  this->parent_->set_chg_tmr_enum_int(num_value);

  this->publish_state(value);
}


// VBUS_BACKUP - The thresholds to trigger the backup mode, defined as a ratio of VINDPM
float BQ25798VbusBackupSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VbusBackupSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VbusBackupSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "VBUS_BACKUP", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VbusBackupSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798VbusBackupSelect...");
  uint8_t num_value = this->parent_->get_vbus_backup_enum_int();
  std::string str_value = BQ25798VbusBackupSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798VbusBackupSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VbusBackupSelect...");

  uint8_t num_value = BQ25798VbusBackupSelect_ENUM_TO_INT.at(value);
  this->parent_->set_vbus_backup_enum_int(num_value);

  this->publish_state(value);
}


// VAC_OVP - Over voltage protection thresholds
float BQ25798VacOvpSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VacOvpSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VacOvpSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "VAC_OVP", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VacOvpSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798VacOvpSelect...");
  uint8_t num_value = this->parent_->get_vac_ovp_enum_int();
  std::string str_value = BQ25798VacOvpSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798VacOvpSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VacOvpSelect...");

  uint8_t num_value = BQ25798VacOvpSelect_ENUM_TO_INT.at(value);
  this->parent_->set_vac_ovp_enum_int(num_value);

  this->publish_state(value);
}


// WATCHDOG - Watchdog timer settings
float BQ25798WatchdogSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798WatchdogSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798WatchdogSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "WATCHDOG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798WatchdogSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798WatchdogSelect...");
  uint8_t num_value = this->parent_->get_watchdog_enum_int();
  std::string str_value = BQ25798WatchdogSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798WatchdogSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798WatchdogSelect...");

  uint8_t num_value = BQ25798WatchdogSelect_ENUM_TO_INT.at(value);
  this->parent_->set_watchdog_enum_int(num_value);

  this->publish_state(value);
}


// SDRV_CTRL - Enable external Ship FET control
float BQ25798SdrvCtrlSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798SdrvCtrlSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798SdrvCtrlSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "SDRV_CTRL", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798SdrvCtrlSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798SdrvCtrlSelect...");
  uint8_t num_value = this->parent_->get_sdrv_ctrl_enum_int();
  std::string str_value = BQ25798SdrvCtrlSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798SdrvCtrlSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798SdrvCtrlSelect...");

  uint8_t num_value = BQ25798SdrvCtrlSelect_ENUM_TO_INT.at(value);
  this->parent_->set_sdrv_ctrl_enum_int(num_value);

  this->publish_state(value);
}


// SDRV_DLY - Delay for SDRV control
float BQ25798SdrvDlySelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798SdrvDlySelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798SdrvDlySelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "SDRV_DLY", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798SdrvDlySelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798SdrvDlySelect...");
  uint8_t num_value = this->parent_->get_sdrv_dly_enum_int();
  std::string str_value = BQ25798SdrvDlySelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798SdrvDlySelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798SdrvDlySelect...");

  uint8_t num_value = BQ25798SdrvDlySelect_ENUM_TO_INT.at(value);
  this->parent_->set_sdrv_dly_enum_int(num_value);

  this->publish_state(value);
}


// WKUP_DLY - Wakeup (Ship FET) delay
float BQ25798WkupDlySelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798WkupDlySelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798WkupDlySelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "WKUP_DLY", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798WkupDlySelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798WkupDlySelect...");
  uint8_t num_value = this->parent_->get_wkup_dly_enum_int();
  std::string str_value = BQ25798WkupDlySelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798WkupDlySelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798WkupDlySelect...");

  uint8_t num_value = BQ25798WkupDlySelect_ENUM_TO_INT.at(value);
  this->parent_->set_wkup_dly_enum_int(num_value);

  this->publish_state(value);
}


// PWM_FREQ - PWM frequency setting
float BQ25798PwmFreqSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798PwmFreqSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798PwmFreqSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "PWM_FREQ", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798PwmFreqSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798PwmFreqSelect...");
  uint8_t num_value = this->parent_->get_pwm_freq_enum_int();
  std::string str_value = BQ25798PwmFreqSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798PwmFreqSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798PwmFreqSelect...");

  uint8_t num_value = BQ25798PwmFreqSelect_ENUM_TO_INT.at(value);
  this->parent_->set_pwm_freq_enum_int(num_value);

  this->publish_state(value);
}


// IBAT_REG - Battery discharge current regulation in OTG mode
float BQ25798IbatRegSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798IbatRegSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798IbatRegSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "IBAT_REG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798IbatRegSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798IbatRegSelect...");
  uint8_t num_value = this->parent_->get_ibat_reg_enum_int();
  std::string str_value = BQ25798IbatRegSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798IbatRegSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798IbatRegSelect...");

  uint8_t num_value = BQ25798IbatRegSelect_ENUM_TO_INT.at(value);
  this->parent_->set_ibat_reg_enum_int(num_value);

  this->publish_state(value);
}


// VOC_PCT - Set VINDPM as a percentage of the VBUS open circuit voltage when the VOC measurement is done
float BQ25798VocPctSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VocPctSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VocPctSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "VOC_PCT", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VocPctSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798VocPctSelect...");
  uint8_t num_value = this->parent_->get_voc_pct_enum_int();
  std::string str_value = BQ25798VocPctSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798VocPctSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VocPctSelect...");

  uint8_t num_value = BQ25798VocPctSelect_ENUM_TO_INT.at(value);
  this->parent_->set_voc_pct_enum_int(num_value);

  this->publish_state(value);
}


// VOC_DLY - After the converter stops switching, the time delay before the VOC is measured
float BQ25798VocDlySelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VocDlySelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VocDlySelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "VOC_DLY", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VocDlySelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798VocDlySelect...");
  uint8_t num_value = this->parent_->get_voc_dly_enum_int();
  std::string str_value = BQ25798VocDlySelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798VocDlySelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VocDlySelect...");

  uint8_t num_value = BQ25798VocDlySelect_ENUM_TO_INT.at(value);
  this->parent_->set_voc_dly_enum_int(num_value);

  this->publish_state(value);
}


// VOC_RATE - The time interval between two consecutive VOC measurements
float BQ25798VocRateSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VocRateSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VocRateSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "VOC_RATE", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VocRateSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798VocRateSelect...");
  uint8_t num_value = this->parent_->get_voc_rate_enum_int();
  std::string str_value = BQ25798VocRateSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798VocRateSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VocRateSelect...");

  uint8_t num_value = BQ25798VocRateSelect_ENUM_TO_INT.at(value);
  this->parent_->set_voc_rate_enum_int(num_value);

  this->publish_state(value);
}


// TREG - Thermal regulation thresholds
float BQ25798TregSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TregSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TregSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "TREG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TregSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798TregSelect...");
  uint8_t num_value = this->parent_->get_treg_enum_int();
  std::string str_value = BQ25798TregSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798TregSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798TregSelect...");

  uint8_t num_value = BQ25798TregSelect_ENUM_TO_INT.at(value);
  this->parent_->set_treg_enum_int(num_value);

  this->publish_state(value);
}


// TSHUT - Thermal shutdown thresholds
float BQ25798TshutSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TshutSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TshutSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "TSHUT", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TshutSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798TshutSelect...");
  uint8_t num_value = this->parent_->get_tshut_enum_int();
  std::string str_value = BQ25798TshutSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798TshutSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798TshutSelect...");

  uint8_t num_value = BQ25798TshutSelect_ENUM_TO_INT.at(value);
  this->parent_->set_tshut_enum_int(num_value);

  this->publish_state(value);
}


// JEITA_VSET - JEITA high temperature range (TWARN - THOT) charge voltage setting
float BQ25798JeitaVsetSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798JeitaVsetSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798JeitaVsetSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "JEITA_VSET", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798JeitaVsetSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798JeitaVsetSelect...");
  uint8_t num_value = this->parent_->get_jeita_vset_enum_int();
  std::string str_value = BQ25798JeitaVsetSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798JeitaVsetSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798JeitaVsetSelect...");

  uint8_t num_value = BQ25798JeitaVsetSelect_ENUM_TO_INT.at(value);
  this->parent_->set_jeita_vset_enum_int(num_value);

  this->publish_state(value);
}


// JEITA_ISETH - JEITA high temperature range (TWARN - THOT) charge current setting
float BQ25798JeitaIsethSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798JeitaIsethSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798JeitaIsethSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "JEITA_ISETH", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798JeitaIsethSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798JeitaIsethSelect...");
  uint8_t num_value = this->parent_->get_jeita_iseth_enum_int();
  std::string str_value = BQ25798JeitaIsethSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798JeitaIsethSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798JeitaIsethSelect...");

  uint8_t num_value = BQ25798JeitaIsethSelect_ENUM_TO_INT.at(value);
  this->parent_->set_jeita_iseth_enum_int(num_value);

  this->publish_state(value);
}


// JEITA_ISETC - JEITA low temperature range (TCOLD - TWARN) charge current setting
float BQ25798JeitaIsetcSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798JeitaIsetcSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798JeitaIsetcSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "JEITA_ISETC", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798JeitaIsetcSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798JeitaIsetcSelect...");
  uint8_t num_value = this->parent_->get_jeita_isetc_enum_int();
  std::string str_value = BQ25798JeitaIsetcSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798JeitaIsetcSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798JeitaIsetcSelect...");

  uint8_t num_value = BQ25798JeitaIsetcSelect_ENUM_TO_INT.at(value);
  this->parent_->set_jeita_isetc_enum_int(num_value);

  this->publish_state(value);
}


// TS_COOL - JEITA VT2 comparator voltage rising thresholds as a percentage of REGN.
float BQ25798TsCoolSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TsCoolSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TsCoolSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "TS_COOL", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TsCoolSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798TsCoolSelect...");
  uint8_t num_value = this->parent_->get_ts_cool_enum_int();
  std::string str_value = BQ25798TsCoolSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798TsCoolSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798TsCoolSelect...");

  uint8_t num_value = BQ25798TsCoolSelect_ENUM_TO_INT.at(value);
  this->parent_->set_ts_cool_enum_int(num_value);

  this->publish_state(value);
}


// TS_WARM - JEITA VT3 comparator voltage falling thresholds as a percentage of REGN.
float BQ25798TsWarmSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TsWarmSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TsWarmSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "TS_WARM", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TsWarmSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798TsWarmSelect...");
  uint8_t num_value = this->parent_->get_ts_warm_enum_int();
  std::string str_value = BQ25798TsWarmSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798TsWarmSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798TsWarmSelect...");

  uint8_t num_value = BQ25798TsWarmSelect_ENUM_TO_INT.at(value);
  this->parent_->set_ts_warm_enum_int(num_value);

  this->publish_state(value);
}


// BHOT - OTG mode TS HOT temperature threshold
float BQ25798BhotSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798BhotSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798BhotSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "BHOT", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798BhotSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798BhotSelect...");
  uint8_t num_value = this->parent_->get_bhot_enum_int();
  std::string str_value = BQ25798BhotSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798BhotSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798BhotSelect...");

  uint8_t num_value = BQ25798BhotSelect_ENUM_TO_INT.at(value);
  this->parent_->set_bhot_enum_int(num_value);

  this->publish_state(value);
}


// BCOLD - OTG mode TS COLD temperature threshold
float BQ25798BcoldSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798BcoldSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798BcoldSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "BCOLD", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798BcoldSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798BcoldSelect...");
  uint8_t num_value = this->parent_->get_bcold_enum_int();
  std::string str_value = BQ25798BcoldSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798BcoldSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798BcoldSelect...");

  uint8_t num_value = BQ25798BcoldSelect_ENUM_TO_INT.at(value);
  this->parent_->set_bcold_enum_int(num_value);

  this->publish_state(value);
}


// ADC_RATE - ADC conversion rate
float BQ25798AdcRateSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798AdcRateSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798AdcRateSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "ADC_RATE", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798AdcRateSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798AdcRateSelect...");
  uint8_t num_value = this->parent_->get_adc_rate_enum_int();
  std::string str_value = BQ25798AdcRateSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798AdcRateSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798AdcRateSelect...");

  uint8_t num_value = BQ25798AdcRateSelect_ENUM_TO_INT.at(value);
  this->parent_->set_adc_rate_enum_int(num_value);

  this->publish_state(value);
}


// ADC_SAMPLE - ADC sample speed
float BQ25798AdcSampleSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798AdcSampleSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798AdcSampleSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "ADC_SAMPLE", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798AdcSampleSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798AdcSampleSelect...");
  uint8_t num_value = this->parent_->get_adc_sample_enum_int();
  std::string str_value = BQ25798AdcSampleSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798AdcSampleSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798AdcSampleSelect...");

  uint8_t num_value = BQ25798AdcSampleSelect_ENUM_TO_INT.at(value);
  this->parent_->set_adc_sample_enum_int(num_value);

  this->publish_state(value);
}


// ADC_AVG - ADC averaging
float BQ25798AdcAvgSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798AdcAvgSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798AdcAvgSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "ADC_AVG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798AdcAvgSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798AdcAvgSelect...");
  uint8_t num_value = this->parent_->get_adc_avg_enum_int();
  std::string str_value = BQ25798AdcAvgSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798AdcAvgSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798AdcAvgSelect...");

  uint8_t num_value = BQ25798AdcAvgSelect_ENUM_TO_INT.at(value);
  this->parent_->set_adc_avg_enum_int(num_value);

  this->publish_state(value);
}


// DPLUS_DAC - D+ Output Driver
float BQ25798DplusDacSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798DplusDacSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798DplusDacSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "DPLUS_DAC", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798DplusDacSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798DplusDacSelect...");
  uint8_t num_value = this->parent_->get_dplus_dac_enum_int();
  std::string str_value = BQ25798DplusDacSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798DplusDacSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798DplusDacSelect...");

  uint8_t num_value = BQ25798DplusDacSelect_ENUM_TO_INT.at(value);
  this->parent_->set_dplus_dac_enum_int(num_value);

  this->publish_state(value);
}


// DMINUS_DAC - D- Output Driver
float BQ25798DminusDacSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798DminusDacSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798DminusDacSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "DMINUS_DAC", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798DminusDacSelect::update() {
  if (this->parent_->is_failed()) {
    this->publish_state(this->at(0).value_or("I2C device failed"));
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798DminusDacSelect...");
  uint8_t num_value = this->parent_->get_dminus_dac_enum_int();
  std::string str_value = BQ25798DminusDacSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798DminusDacSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798DminusDacSelect...");

  uint8_t num_value = BQ25798DminusDacSelect_ENUM_TO_INT.at(value);
  this->parent_->set_dminus_dac_enum_int(num_value);

  this->publish_state(value);
}


}  // namespace bq25798
}  // namespace esphome