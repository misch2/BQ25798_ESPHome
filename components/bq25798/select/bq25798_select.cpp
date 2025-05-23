#include "bq25798_select.h"

#include "esphome/core/log.h"

#include <map>

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

static const std::map<uint8_t, std::string> BQ25798VbatLowvSelect_INT_TO_ENUM {
  { 0, "VBAT_LOWV_PCT_15" },
  { 1, "VBAT_LOWV_PCT_62" },
  { 2, "VBAT_LOWV_PCT_67" },
  { 3, "VBAT_LOWV_PCT_71" },
};

static const std::map<std::string, uint8_t> BQ25798VbatLowvSelect_ENUM_TO_INT {
  { "VBAT_LOWV_PCT_15", 0 },
  { "VBAT_LOWV_PCT_62", 1 },
  { "VBAT_LOWV_PCT_67", 2 },
  { "VBAT_LOWV_PCT_71", 3 },
};


void BQ25798VbatLowvSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798VbatLowvSelect...");
  uint8_t num_value = this->parent_->get_vbat_lowv_enum_int(true);
  std::string str_value = BQ25798VbatLowvSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798VbatLowvSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VbatLowvSelect...");

  uint8_t num_value = BQ25798VbatLowvSelect_ENUM_TO_INT.at(value);
  this->parent_->set_vbat_lowv_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798CellSelect_INT_TO_ENUM {
  { 0, "CELL_1S" },
  { 1, "CELL_2S" },
  { 2, "CELL_3S" },
  { 3, "CELL_4S" },
};

static const std::map<std::string, uint8_t> BQ25798CellSelect_ENUM_TO_INT {
  { "CELL_1S", 0 },
  { "CELL_2S", 1 },
  { "CELL_3S", 2 },
  { "CELL_4S", 3 },
};


void BQ25798CellSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798CellSelect...");
  uint8_t num_value = this->parent_->get_cell_enum_int(true);
  std::string str_value = BQ25798CellSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798CellSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798CellSelect...");

  uint8_t num_value = BQ25798CellSelect_ENUM_TO_INT.at(value);
  this->parent_->set_cell_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798TrechgSelect_INT_TO_ENUM {
  { 0, "TRECHG_64MS" },
  { 1, "TRECHG_256MS" },
  { 2, "TRECHG_1024MS" },
  { 3, "TRECHG_2048MS" },
};

static const std::map<std::string, uint8_t> BQ25798TrechgSelect_ENUM_TO_INT {
  { "TRECHG_64MS", 0 },
  { "TRECHG_256MS", 1 },
  { "TRECHG_1024MS", 2 },
  { "TRECHG_2048MS", 3 },
};


void BQ25798TrechgSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798TrechgSelect...");
  uint8_t num_value = this->parent_->get_trechg_enum_int(true);
  std::string str_value = BQ25798TrechgSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798TrechgSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798TrechgSelect...");

  uint8_t num_value = BQ25798TrechgSelect_ENUM_TO_INT.at(value);
  this->parent_->set_trechg_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798PrechgTmrSelect_INT_TO_ENUM {
  { 0, "PRECHG_TMR_2HRS" },
  { 1, "PRECHG_TMR_30MIN" },
};

static const std::map<std::string, uint8_t> BQ25798PrechgTmrSelect_ENUM_TO_INT {
  { "PRECHG_TMR_2HRS", 0 },
  { "PRECHG_TMR_30MIN", 1 },
};


void BQ25798PrechgTmrSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798PrechgTmrSelect...");
  uint8_t num_value = this->parent_->get_prechg_tmr_enum_int(true);
  std::string str_value = BQ25798PrechgTmrSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798PrechgTmrSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798PrechgTmrSelect...");

  uint8_t num_value = BQ25798PrechgTmrSelect_ENUM_TO_INT.at(value);
  this->parent_->set_prechg_tmr_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798TopoffTmrSelect_INT_TO_ENUM {
  { 0, "TOPOFF_TMR_DISABLED" },
  { 1, "TOPOFF_TMR_15MIN" },
  { 2, "TOPOFF_TMR_30MIN" },
  { 3, "TOPOFF_TMR_45MIN" },
};

static const std::map<std::string, uint8_t> BQ25798TopoffTmrSelect_ENUM_TO_INT {
  { "TOPOFF_TMR_DISABLED", 0 },
  { "TOPOFF_TMR_15MIN", 1 },
  { "TOPOFF_TMR_30MIN", 2 },
  { "TOPOFF_TMR_45MIN", 3 },
};


void BQ25798TopoffTmrSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798TopoffTmrSelect...");
  uint8_t num_value = this->parent_->get_topoff_tmr_enum_int(true);
  std::string str_value = BQ25798TopoffTmrSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798TopoffTmrSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798TopoffTmrSelect...");

  uint8_t num_value = BQ25798TopoffTmrSelect_ENUM_TO_INT.at(value);
  this->parent_->set_topoff_tmr_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798ChgTmrSelect_INT_TO_ENUM {
  { 0, "CHG_TMR_5HRS" },
  { 1, "CHG_TMR_8HRS" },
  { 2, "CHG_TMR_12HRS" },
  { 3, "CHG_TMR_24HRS" },
};

static const std::map<std::string, uint8_t> BQ25798ChgTmrSelect_ENUM_TO_INT {
  { "CHG_TMR_5HRS", 0 },
  { "CHG_TMR_8HRS", 1 },
  { "CHG_TMR_12HRS", 2 },
  { "CHG_TMR_24HRS", 3 },
};


void BQ25798ChgTmrSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798ChgTmrSelect...");
  uint8_t num_value = this->parent_->get_chg_tmr_enum_int(true);
  std::string str_value = BQ25798ChgTmrSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798ChgTmrSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798ChgTmrSelect...");

  uint8_t num_value = BQ25798ChgTmrSelect_ENUM_TO_INT.at(value);
  this->parent_->set_chg_tmr_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798VbusBackupSelect_INT_TO_ENUM {
  { 0, "PCT_VBUS_BACKUP_40" },
  { 1, "PCT_VBUS_BACKUP_60" },
  { 2, "PCT_VBUS_BACKUP_80" },
  { 3, "PCT_VBUS_BACKUP_100" },
};

static const std::map<std::string, uint8_t> BQ25798VbusBackupSelect_ENUM_TO_INT {
  { "PCT_VBUS_BACKUP_40", 0 },
  { "PCT_VBUS_BACKUP_60", 1 },
  { "PCT_VBUS_BACKUP_80", 2 },
  { "PCT_VBUS_BACKUP_100", 3 },
};


void BQ25798VbusBackupSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798VbusBackupSelect...");
  uint8_t num_value = this->parent_->get_vbus_backup_enum_int(true);
  std::string str_value = BQ25798VbusBackupSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798VbusBackupSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VbusBackupSelect...");

  uint8_t num_value = BQ25798VbusBackupSelect_ENUM_TO_INT.at(value);
  this->parent_->set_vbus_backup_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798VacOvpSelect_INT_TO_ENUM {
  { 0, "VAC_OVP_26V" },
  { 1, "VAC_OVP_22V" },
  { 2, "VAC_OVP_12V" },
  { 3, "VAC_OVP_7V" },
};

static const std::map<std::string, uint8_t> BQ25798VacOvpSelect_ENUM_TO_INT {
  { "VAC_OVP_26V", 0 },
  { "VAC_OVP_22V", 1 },
  { "VAC_OVP_12V", 2 },
  { "VAC_OVP_7V", 3 },
};


void BQ25798VacOvpSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798VacOvpSelect...");
  uint8_t num_value = this->parent_->get_vac_ovp_enum_int(true);
  std::string str_value = BQ25798VacOvpSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798VacOvpSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VacOvpSelect...");

  uint8_t num_value = BQ25798VacOvpSelect_ENUM_TO_INT.at(value);
  this->parent_->set_vac_ovp_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798WatchdogSelect_INT_TO_ENUM {
  { 0, "WATCHDOG_DISABLE" },
  { 1, "WATCHDOG_05S" },
  { 2, "WATCHDOG_1S" },
  { 3, "WATCHDOG_2S" },
  { 4, "WATCHDOG_20S" },
  { 5, "WATCHDOG_40S" },
  { 6, "WATCHDOG_80S" },
  { 7, "WATCHDOG_160S" },
};

static const std::map<std::string, uint8_t> BQ25798WatchdogSelect_ENUM_TO_INT {
  { "WATCHDOG_DISABLE", 0 },
  { "WATCHDOG_05S", 1 },
  { "WATCHDOG_1S", 2 },
  { "WATCHDOG_2S", 3 },
  { "WATCHDOG_20S", 4 },
  { "WATCHDOG_40S", 5 },
  { "WATCHDOG_80S", 6 },
  { "WATCHDOG_160S", 7 },
};


void BQ25798WatchdogSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798WatchdogSelect...");
  uint8_t num_value = this->parent_->get_watchdog_enum_int(true);
  std::string str_value = BQ25798WatchdogSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798WatchdogSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798WatchdogSelect...");

  uint8_t num_value = BQ25798WatchdogSelect_ENUM_TO_INT.at(value);
  this->parent_->set_watchdog_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798SdrvCtrlSelect_INT_TO_ENUM {
  { 0, "SDRV_CTRL_IDLE" },
  { 1, "SDRV_CTRL_SHUTDOWN" },
  { 2, "SDRV_CTRL_SHIP" },
  { 3, "SDRV_CTRL_SYS_PWR_RST" },
};

static const std::map<std::string, uint8_t> BQ25798SdrvCtrlSelect_ENUM_TO_INT {
  { "SDRV_CTRL_IDLE", 0 },
  { "SDRV_CTRL_SHUTDOWN", 1 },
  { "SDRV_CTRL_SHIP", 2 },
  { "SDRV_CTRL_SYS_PWR_RST", 3 },
};


void BQ25798SdrvCtrlSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798SdrvCtrlSelect...");
  uint8_t num_value = this->parent_->get_sdrv_ctrl_enum_int(true);
  std::string str_value = BQ25798SdrvCtrlSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798SdrvCtrlSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798SdrvCtrlSelect...");

  uint8_t num_value = BQ25798SdrvCtrlSelect_ENUM_TO_INT.at(value);
  this->parent_->set_sdrv_ctrl_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798SdrvDlySelect_INT_TO_ENUM {
  { 0, "SDRV_DLY_10S" },
  { 1, "SDRV_DLY_0S" },
};

static const std::map<std::string, uint8_t> BQ25798SdrvDlySelect_ENUM_TO_INT {
  { "SDRV_DLY_10S", 0 },
  { "SDRV_DLY_0S", 1 },
};


void BQ25798SdrvDlySelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798SdrvDlySelect...");
  uint8_t num_value = this->parent_->get_sdrv_dly_enum_int(true);
  std::string str_value = BQ25798SdrvDlySelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798SdrvDlySelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798SdrvDlySelect...");

  uint8_t num_value = BQ25798SdrvDlySelect_ENUM_TO_INT.at(value);
  this->parent_->set_sdrv_dly_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798WkupDlySelect_INT_TO_ENUM {
  { 0, "WKUP_DLY_1S" },
  { 1, "WKUP_DLY_15MS" },
};

static const std::map<std::string, uint8_t> BQ25798WkupDlySelect_ENUM_TO_INT {
  { "WKUP_DLY_1S", 0 },
  { "WKUP_DLY_15MS", 1 },
};


void BQ25798WkupDlySelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798WkupDlySelect...");
  uint8_t num_value = this->parent_->get_wkup_dly_enum_int(true);
  std::string str_value = BQ25798WkupDlySelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798WkupDlySelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798WkupDlySelect...");

  uint8_t num_value = BQ25798WkupDlySelect_ENUM_TO_INT.at(value);
  this->parent_->set_wkup_dly_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798PwmFreqSelect_INT_TO_ENUM {
  { 0, "PWM_FREQ_1_5MHZ" },
  { 1, "PWM_FREQ_750KHZ" },
};

static const std::map<std::string, uint8_t> BQ25798PwmFreqSelect_ENUM_TO_INT {
  { "PWM_FREQ_1_5MHZ", 0 },
  { "PWM_FREQ_750KHZ", 1 },
};


void BQ25798PwmFreqSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798PwmFreqSelect...");
  uint8_t num_value = this->parent_->get_pwm_freq_enum_int(true);
  std::string str_value = BQ25798PwmFreqSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798PwmFreqSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798PwmFreqSelect...");

  uint8_t num_value = BQ25798PwmFreqSelect_ENUM_TO_INT.at(value);
  this->parent_->set_pwm_freq_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798IbatRegSelect_INT_TO_ENUM {
  { 0, "IBAT_REG_3A" },
  { 1, "IBAT_REG_4A" },
  { 2, "IBAT_REG_5A" },
  { 3, "IBAT_REG_DISABLE" },
};

static const std::map<std::string, uint8_t> BQ25798IbatRegSelect_ENUM_TO_INT {
  { "IBAT_REG_3A", 0 },
  { "IBAT_REG_4A", 1 },
  { "IBAT_REG_5A", 2 },
  { "IBAT_REG_DISABLE", 3 },
};


void BQ25798IbatRegSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798IbatRegSelect...");
  uint8_t num_value = this->parent_->get_ibat_reg_enum_int(true);
  std::string str_value = BQ25798IbatRegSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798IbatRegSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798IbatRegSelect...");

  uint8_t num_value = BQ25798IbatRegSelect_ENUM_TO_INT.at(value);
  this->parent_->set_ibat_reg_enum_int(num_value, true);

  this->publish_state(value);
}




// VOC_PCT - 
float BQ25798VocPctSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VocPctSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VocPctSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "VOC_PCT", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798VocPctSelect_INT_TO_ENUM {
  { 0, "VOC_PCT_0_5625" },
  { 1, "VOC_PCT_0_625" },
  { 2, "VOC_PCT_0_6875" },
  { 3, "VOC_PCT_0_75" },
  { 4, "VOC_PCT_0_8125" },
  { 5, "VOC_PCT_0_875" },
  { 6, "VOC_PCT_0_9375" },
  { 7, "VOC_PCT_1" },
};

static const std::map<std::string, uint8_t> BQ25798VocPctSelect_ENUM_TO_INT {
  { "VOC_PCT_0_5625", 0 },
  { "VOC_PCT_0_625", 1 },
  { "VOC_PCT_0_6875", 2 },
  { "VOC_PCT_0_75", 3 },
  { "VOC_PCT_0_8125", 4 },
  { "VOC_PCT_0_875", 5 },
  { "VOC_PCT_0_9375", 6 },
  { "VOC_PCT_1", 7 },
};


void BQ25798VocPctSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798VocPctSelect...");
  uint8_t num_value = this->parent_->get_voc_pct_enum_int(true);
  std::string str_value = BQ25798VocPctSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798VocPctSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VocPctSelect...");

  uint8_t num_value = BQ25798VocPctSelect_ENUM_TO_INT.at(value);
  this->parent_->set_voc_pct_enum_int(num_value, true);

  this->publish_state(value);
}




// VOC_DLY - 
float BQ25798VocDlySelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VocDlySelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VocDlySelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "VOC_DLY", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798VocDlySelect_INT_TO_ENUM {
  { 0, "VOC_DLY_50MS" },
  { 1, "VOC_DLY_300MS" },
  { 2, "VOC_DLY_2S" },
  { 3, "VOC_DLY_5S" },
};

static const std::map<std::string, uint8_t> BQ25798VocDlySelect_ENUM_TO_INT {
  { "VOC_DLY_50MS", 0 },
  { "VOC_DLY_300MS", 1 },
  { "VOC_DLY_2S", 2 },
  { "VOC_DLY_5S", 3 },
};


void BQ25798VocDlySelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798VocDlySelect...");
  uint8_t num_value = this->parent_->get_voc_dly_enum_int(true);
  std::string str_value = BQ25798VocDlySelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798VocDlySelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VocDlySelect...");

  uint8_t num_value = BQ25798VocDlySelect_ENUM_TO_INT.at(value);
  this->parent_->set_voc_dly_enum_int(num_value, true);

  this->publish_state(value);
}




// VOC_RATE - 
float BQ25798VocRateSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VocRateSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VocRateSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "VOC_RATE", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798VocRateSelect_INT_TO_ENUM {
  { 0, "VOC_RATE_30S" },
  { 1, "VOC_RATE_2MIN" },
  { 2, "VOC_RATE_10MIN" },
  { 3, "VOC_RATE_30MIN" },
};

static const std::map<std::string, uint8_t> BQ25798VocRateSelect_ENUM_TO_INT {
  { "VOC_RATE_30S", 0 },
  { "VOC_RATE_2MIN", 1 },
  { "VOC_RATE_10MIN", 2 },
  { "VOC_RATE_30MIN", 3 },
};


void BQ25798VocRateSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798VocRateSelect...");
  uint8_t num_value = this->parent_->get_voc_rate_enum_int(true);
  std::string str_value = BQ25798VocRateSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798VocRateSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798VocRateSelect...");

  uint8_t num_value = BQ25798VocRateSelect_ENUM_TO_INT.at(value);
  this->parent_->set_voc_rate_enum_int(num_value, true);

  this->publish_state(value);
}




// TREG - 
float BQ25798TregSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TregSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TregSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "TREG", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798TregSelect_INT_TO_ENUM {
  { 0, "TREG_60" },
  { 1, "TREG_80" },
  { 2, "TREG_100" },
  { 3, "TREG_120" },
};

static const std::map<std::string, uint8_t> BQ25798TregSelect_ENUM_TO_INT {
  { "TREG_60", 0 },
  { "TREG_80", 1 },
  { "TREG_100", 2 },
  { "TREG_120", 3 },
};


void BQ25798TregSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798TregSelect...");
  uint8_t num_value = this->parent_->get_treg_enum_int(true);
  std::string str_value = BQ25798TregSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798TregSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798TregSelect...");

  uint8_t num_value = BQ25798TregSelect_ENUM_TO_INT.at(value);
  this->parent_->set_treg_enum_int(num_value, true);

  this->publish_state(value);
}




// TSHUT - 
float BQ25798TshutSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TshutSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TshutSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "TSHUT", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798TshutSelect_INT_TO_ENUM {
  { 0, "TSHUT_150" },
  { 1, "TSHUT_130" },
  { 2, "TSHUT_120" },
  { 3, "TSHUT_85" },
};

static const std::map<std::string, uint8_t> BQ25798TshutSelect_ENUM_TO_INT {
  { "TSHUT_150", 0 },
  { "TSHUT_130", 1 },
  { "TSHUT_120", 2 },
  { "TSHUT_85", 3 },
};


void BQ25798TshutSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798TshutSelect...");
  uint8_t num_value = this->parent_->get_tshut_enum_int(true);
  std::string str_value = BQ25798TshutSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798TshutSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798TshutSelect...");

  uint8_t num_value = BQ25798TshutSelect_ENUM_TO_INT.at(value);
  this->parent_->set_tshut_enum_int(num_value, true);

  this->publish_state(value);
}




// BKUP_ACFET1_ON - 
float BQ25798BkupAcfet1OnSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798BkupAcfet1OnSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798BkupAcfet1OnSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "BKUP_ACFET1_ON", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798BkupAcfet1OnSelect_INT_TO_ENUM {
  { 0, "BKUP_ACFET1_ON_IDLE" },
  { 1, "BKUP_ACFET1_ON_TURN_ON" },
};

static const std::map<std::string, uint8_t> BQ25798BkupAcfet1OnSelect_ENUM_TO_INT {
  { "BKUP_ACFET1_ON_IDLE", 0 },
  { "BKUP_ACFET1_ON_TURN_ON", 1 },
};


void BQ25798BkupAcfet1OnSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798BkupAcfet1OnSelect...");
  uint8_t num_value = this->parent_->get_bkup_acfet1_on_enum_int(true);
  std::string str_value = BQ25798BkupAcfet1OnSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798BkupAcfet1OnSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798BkupAcfet1OnSelect...");

  uint8_t num_value = BQ25798BkupAcfet1OnSelect_ENUM_TO_INT.at(value);
  this->parent_->set_bkup_acfet1_on_enum_int(num_value, true);

  this->publish_state(value);
}




// JEITA_VSET - 
float BQ25798JeitaVsetSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798JeitaVsetSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798JeitaVsetSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "JEITA_VSET", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798JeitaVsetSelect_INT_TO_ENUM {
  { 0, "JEITA_VSET_CHARGE_SUSPEND" },
  { 1, "JEITA_VSET_SET_VREG_TO_VREG_800MV" },
  { 2, "JEITA_VSET_SET_VREG_TO_VREG_600MV" },
  { 3, "JEITA_VSET_SET_VREG_TO_VREG_400MV" },
  { 4, "JEITA_VSET_SET_VREG_TO_VREG_300MV" },
  { 5, "JEITA_VSET_SET_VREG_TO_VREG_200MV" },
  { 6, "JEITA_VSET_SET_VREG_TO_VREG_100MV" },
  { 7, "JEITA_VSET_VREG_UNCHANGED" },
};

static const std::map<std::string, uint8_t> BQ25798JeitaVsetSelect_ENUM_TO_INT {
  { "JEITA_VSET_CHARGE_SUSPEND", 0 },
  { "JEITA_VSET_SET_VREG_TO_VREG_800MV", 1 },
  { "JEITA_VSET_SET_VREG_TO_VREG_600MV", 2 },
  { "JEITA_VSET_SET_VREG_TO_VREG_400MV", 3 },
  { "JEITA_VSET_SET_VREG_TO_VREG_300MV", 4 },
  { "JEITA_VSET_SET_VREG_TO_VREG_200MV", 5 },
  { "JEITA_VSET_SET_VREG_TO_VREG_100MV", 6 },
  { "JEITA_VSET_VREG_UNCHANGED", 7 },
};


void BQ25798JeitaVsetSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798JeitaVsetSelect...");
  uint8_t num_value = this->parent_->get_jeita_vset_enum_int(true);
  std::string str_value = BQ25798JeitaVsetSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798JeitaVsetSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798JeitaVsetSelect...");

  uint8_t num_value = BQ25798JeitaVsetSelect_ENUM_TO_INT.at(value);
  this->parent_->set_jeita_vset_enum_int(num_value, true);

  this->publish_state(value);
}




// JEITA_ISETH - 
float BQ25798JeitaIsethSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798JeitaIsethSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798JeitaIsethSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "JEITA_ISETH", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798JeitaIsethSelect_INT_TO_ENUM {
  { 0, "JEITA_ISETH_CHARGE_SUSPEND" },
  { 1, "JEITA_ISETH_SET_ICHG_TO_20" },
  { 2, "JEITA_ISETH_SET_ICHG_TO_40" },
  { 3, "JEITA_ISETH_ICHG_UNCHANGED" },
};

static const std::map<std::string, uint8_t> BQ25798JeitaIsethSelect_ENUM_TO_INT {
  { "JEITA_ISETH_CHARGE_SUSPEND", 0 },
  { "JEITA_ISETH_SET_ICHG_TO_20", 1 },
  { "JEITA_ISETH_SET_ICHG_TO_40", 2 },
  { "JEITA_ISETH_ICHG_UNCHANGED", 3 },
};


void BQ25798JeitaIsethSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798JeitaIsethSelect...");
  uint8_t num_value = this->parent_->get_jeita_iseth_enum_int(true);
  std::string str_value = BQ25798JeitaIsethSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798JeitaIsethSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798JeitaIsethSelect...");

  uint8_t num_value = BQ25798JeitaIsethSelect_ENUM_TO_INT.at(value);
  this->parent_->set_jeita_iseth_enum_int(num_value, true);

  this->publish_state(value);
}




// JEITA_ISETC - 
float BQ25798JeitaIsetcSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798JeitaIsetcSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798JeitaIsetcSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "JEITA_ISETC", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798JeitaIsetcSelect_INT_TO_ENUM {
  { 0, "JEITA_ISETC_CHARGE_SUSPEND" },
  { 1, "JEITA_ISETC_SET_ICHG_TO_20" },
  { 2, "JEITA_ISETC_SET_ICHG_TO_40" },
  { 3, "JEITA_ISETC_ICHG_UNCHANGED" },
};

static const std::map<std::string, uint8_t> BQ25798JeitaIsetcSelect_ENUM_TO_INT {
  { "JEITA_ISETC_CHARGE_SUSPEND", 0 },
  { "JEITA_ISETC_SET_ICHG_TO_20", 1 },
  { "JEITA_ISETC_SET_ICHG_TO_40", 2 },
  { "JEITA_ISETC_ICHG_UNCHANGED", 3 },
};


void BQ25798JeitaIsetcSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798JeitaIsetcSelect...");
  uint8_t num_value = this->parent_->get_jeita_isetc_enum_int(true);
  std::string str_value = BQ25798JeitaIsetcSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798JeitaIsetcSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798JeitaIsetcSelect...");

  uint8_t num_value = BQ25798JeitaIsetcSelect_ENUM_TO_INT.at(value);
  this->parent_->set_jeita_isetc_enum_int(num_value, true);

  this->publish_state(value);
}




// TS_COOL - 
float BQ25798TsCoolSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TsCoolSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TsCoolSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "TS_COOL", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798TsCoolSelect_INT_TO_ENUM {
  { 0, "TS_COOL_5" },
  { 1, "TS_COOL_10" },
  { 2, "TS_COOL_15" },
  { 3, "TS_COOL_20" },
};

static const std::map<std::string, uint8_t> BQ25798TsCoolSelect_ENUM_TO_INT {
  { "TS_COOL_5", 0 },
  { "TS_COOL_10", 1 },
  { "TS_COOL_15", 2 },
  { "TS_COOL_20", 3 },
};


void BQ25798TsCoolSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798TsCoolSelect...");
  uint8_t num_value = this->parent_->get_ts_cool_enum_int(true);
  std::string str_value = BQ25798TsCoolSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798TsCoolSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798TsCoolSelect...");

  uint8_t num_value = BQ25798TsCoolSelect_ENUM_TO_INT.at(value);
  this->parent_->set_ts_cool_enum_int(num_value, true);

  this->publish_state(value);
}




// TS_WARM - 
float BQ25798TsWarmSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TsWarmSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TsWarmSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "TS_WARM", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798TsWarmSelect_INT_TO_ENUM {
  { 0, "TS_WARM_40" },
  { 1, "TS_WARM_45" },
  { 2, "TS_WARM_50" },
  { 3, "TS_WARM_55" },
};

static const std::map<std::string, uint8_t> BQ25798TsWarmSelect_ENUM_TO_INT {
  { "TS_WARM_40", 0 },
  { "TS_WARM_45", 1 },
  { "TS_WARM_50", 2 },
  { "TS_WARM_55", 3 },
};


void BQ25798TsWarmSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798TsWarmSelect...");
  uint8_t num_value = this->parent_->get_ts_warm_enum_int(true);
  std::string str_value = BQ25798TsWarmSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798TsWarmSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798TsWarmSelect...");

  uint8_t num_value = BQ25798TsWarmSelect_ENUM_TO_INT.at(value);
  this->parent_->set_ts_warm_enum_int(num_value, true);

  this->publish_state(value);
}




// BHOT - 
float BQ25798BhotSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798BhotSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798BhotSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "BHOT", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798BhotSelect_INT_TO_ENUM {
  { 0, "TS_BHOT_55" },
  { 1, "TS_BHOT_60" },
  { 2, "TS_BHOT_65" },
  { 3, "TS_BHOT_DISABLE" },
};

static const std::map<std::string, uint8_t> BQ25798BhotSelect_ENUM_TO_INT {
  { "TS_BHOT_55", 0 },
  { "TS_BHOT_60", 1 },
  { "TS_BHOT_65", 2 },
  { "TS_BHOT_DISABLE", 3 },
};


void BQ25798BhotSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798BhotSelect...");
  uint8_t num_value = this->parent_->get_bhot_enum_int(true);
  std::string str_value = BQ25798BhotSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798BhotSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798BhotSelect...");

  uint8_t num_value = BQ25798BhotSelect_ENUM_TO_INT.at(value);
  this->parent_->set_bhot_enum_int(num_value, true);

  this->publish_state(value);
}




// BCOLD - 
float BQ25798BcoldSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798BcoldSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798BcoldSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "BCOLD", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798BcoldSelect_INT_TO_ENUM {
  { 0, "TS_BCOLD_MINUS_10" },
  { 1, "TS_BCOLD_MINUS_20" },
};

static const std::map<std::string, uint8_t> BQ25798BcoldSelect_ENUM_TO_INT {
  { "TS_BCOLD_MINUS_10", 0 },
  { "TS_BCOLD_MINUS_20", 1 },
};


void BQ25798BcoldSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798BcoldSelect...");
  uint8_t num_value = this->parent_->get_bcold_enum_int(true);
  std::string str_value = BQ25798BcoldSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798BcoldSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798BcoldSelect...");

  uint8_t num_value = BQ25798BcoldSelect_ENUM_TO_INT.at(value);
  this->parent_->set_bcold_enum_int(num_value, true);

  this->publish_state(value);
}




// ADC_RATE - 
float BQ25798AdcRateSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798AdcRateSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798AdcRateSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "ADC_RATE", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798AdcRateSelect_INT_TO_ENUM {
  { 0, "ADC_RATE_CONTINUOUS" },
  { 1, "ADC_RATE_ONESHOT" },
};

static const std::map<std::string, uint8_t> BQ25798AdcRateSelect_ENUM_TO_INT {
  { "ADC_RATE_CONTINUOUS", 0 },
  { "ADC_RATE_ONESHOT", 1 },
};


void BQ25798AdcRateSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798AdcRateSelect...");
  uint8_t num_value = this->parent_->get_adc_rate_enum_int(true);
  std::string str_value = BQ25798AdcRateSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798AdcRateSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798AdcRateSelect...");

  uint8_t num_value = BQ25798AdcRateSelect_ENUM_TO_INT.at(value);
  this->parent_->set_adc_rate_enum_int(num_value, true);

  this->publish_state(value);
}




// ADC_SAMPLE - 
float BQ25798AdcSampleSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798AdcSampleSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798AdcSampleSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "ADC_SAMPLE", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798AdcSampleSelect_INT_TO_ENUM {
  { 0, "ADC_SAMPLE_15BIT" },
  { 1, "ADC_SAMPLE_14BIT" },
  { 2, "ADC_SAMPLE_13BIT" },
  { 3, "ADC_SAMPLE_12BIT" },
};

static const std::map<std::string, uint8_t> BQ25798AdcSampleSelect_ENUM_TO_INT {
  { "ADC_SAMPLE_15BIT", 0 },
  { "ADC_SAMPLE_14BIT", 1 },
  { "ADC_SAMPLE_13BIT", 2 },
  { "ADC_SAMPLE_12BIT", 3 },
};


void BQ25798AdcSampleSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798AdcSampleSelect...");
  uint8_t num_value = this->parent_->get_adc_sample_enum_int(true);
  std::string str_value = BQ25798AdcSampleSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798AdcSampleSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798AdcSampleSelect...");

  uint8_t num_value = BQ25798AdcSampleSelect_ENUM_TO_INT.at(value);
  this->parent_->set_adc_sample_enum_int(num_value, true);

  this->publish_state(value);
}




// ADC_AVG - 
float BQ25798AdcAvgSelect::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798AdcAvgSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798AdcAvgSelect configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SELECT("  ", "ADC_AVG", this);
  LOG_UPDATE_INTERVAL(this);
}

static const std::map<uint8_t, std::string> BQ25798AdcAvgSelect_INT_TO_ENUM {
  { 0, "ADC_AVG_NO_AVERAGING" },
  { 1, "ADC_AVG_RUNNING_AVERAGE" },
};

static const std::map<std::string, uint8_t> BQ25798AdcAvgSelect_ENUM_TO_INT {
  { "ADC_AVG_NO_AVERAGING", 0 },
  { "ADC_AVG_RUNNING_AVERAGE", 1 },
};


void BQ25798AdcAvgSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798AdcAvgSelect...");
  uint8_t num_value = this->parent_->get_adc_avg_enum_int(true);
  std::string str_value = BQ25798AdcAvgSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798AdcAvgSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798AdcAvgSelect...");

  uint8_t num_value = BQ25798AdcAvgSelect_ENUM_TO_INT.at(value);
  this->parent_->set_adc_avg_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798DplusDacSelect_INT_TO_ENUM {
  { 0, "DPLUS_DAC_HIZ" },
  { 1, "DPLUS_DAC_VOUT_0" },
  { 2, "DPLUS_DAC_VOUT_0_6" },
  { 3, "DPLUS_DAC_VOUT_1_2" },
  { 4, "DPLUS_DAC_VOUT_2_0" },
  { 5, "DPLUS_DAC_VOUT_2_7" },
  { 6, "DPLUS_DAC_VOUT_3_3" },
  { 7, "DPLUS_DAC_DPLUS_DMINUS_SHORT" },
};

static const std::map<std::string, uint8_t> BQ25798DplusDacSelect_ENUM_TO_INT {
  { "DPLUS_DAC_HIZ", 0 },
  { "DPLUS_DAC_VOUT_0", 1 },
  { "DPLUS_DAC_VOUT_0_6", 2 },
  { "DPLUS_DAC_VOUT_1_2", 3 },
  { "DPLUS_DAC_VOUT_2_0", 4 },
  { "DPLUS_DAC_VOUT_2_7", 5 },
  { "DPLUS_DAC_VOUT_3_3", 6 },
  { "DPLUS_DAC_DPLUS_DMINUS_SHORT", 7 },
};


void BQ25798DplusDacSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798DplusDacSelect...");
  uint8_t num_value = this->parent_->get_dplus_dac_enum_int(true);
  std::string str_value = BQ25798DplusDacSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798DplusDacSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798DplusDacSelect...");

  uint8_t num_value = BQ25798DplusDacSelect_ENUM_TO_INT.at(value);
  this->parent_->set_dplus_dac_enum_int(num_value, true);

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

static const std::map<uint8_t, std::string> BQ25798DminusDacSelect_INT_TO_ENUM {
  { 0, "DMINUS_DAC_HIZ" },
  { 1, "DMINUS_DAC_VOUT_0" },
  { 2, "DMINUS_DAC_VOUT_0_6" },
  { 3, "DMINUS_DAC_VOUT_1_2" },
  { 4, "DMINUS_DAC_VOUT_2_0" },
  { 5, "DMINUS_DAC_VOUT_2_7" },
  { 6, "DMINUS_DAC_VOUT_3_3" },
  { 7, "DMINUS_DAC_RESERVED" },
};

static const std::map<std::string, uint8_t> BQ25798DminusDacSelect_ENUM_TO_INT {
  { "DMINUS_DAC_HIZ", 0 },
  { "DMINUS_DAC_VOUT_0", 1 },
  { "DMINUS_DAC_VOUT_0_6", 2 },
  { "DMINUS_DAC_VOUT_1_2", 3 },
  { "DMINUS_DAC_VOUT_2_0", 4 },
  { "DMINUS_DAC_VOUT_2_7", 5 },
  { "DMINUS_DAC_VOUT_3_3", 6 },
  { "DMINUS_DAC_RESERVED", 7 },
};


void BQ25798DminusDacSelect::update() {
  if (this->parent_->is_failed()) {
    return;
  }

//ESP_LOGD(TAG, "Updating BQ25798DminusDacSelect...");
  uint8_t num_value = this->parent_->get_dminus_dac_enum_int(true);
  std::string str_value = BQ25798DminusDacSelect_INT_TO_ENUM.at(num_value);
  
  this->publish_state(str_value);
}

void BQ25798DminusDacSelect::control(const std::string &value) {
  //ESP_LOGD(TAG, "Controlling BQ25798DminusDacSelect...");

  uint8_t num_value = BQ25798DminusDacSelect_ENUM_TO_INT.at(value);
  this->parent_->set_dminus_dac_enum_int(num_value, true);

  this->publish_state(value);
}




}  // namespace bq25798
}  // namespace esphome