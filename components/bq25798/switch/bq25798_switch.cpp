#include "bq25798_switch.h"

#include "esphome/core/log.h"

namespace esphome {
namespace bq25798 {

static const char* const TAG = "bq25798.switch";


// REG_RST - Reset registers to default values and reset timer
float BQ25798RegRstSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798RegRstSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798RegRstSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "REG_RST", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798RegRstSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_reg_rst(true));
}

void BQ25798RegRstSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_reg_rst(state, true);
  this->publish_state(state);
}




// STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
float BQ25798StopWdChgSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798StopWdChgSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798StopWdChgSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "STOP_WD_CHG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798StopWdChgSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_stop_wd_chg(true));
}

void BQ25798StopWdChgSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_stop_wd_chg(state, true);
  this->publish_state(state);
}




// EN_TRICHG_TMR - Trickle charge timer enable
float BQ25798EnTrichgTmrSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnTrichgTmrSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnTrichgTmrSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_TRICHG_TMR", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnTrichgTmrSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_trichg_tmr(true));
}

void BQ25798EnTrichgTmrSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_trichg_tmr(state, true);
  this->publish_state(state);
}




// EN_PRECHG_TMR - Precharge timer enable
float BQ25798EnPrechgTmrSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnPrechgTmrSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnPrechgTmrSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_PRECHG_TMR", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnPrechgTmrSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_prechg_tmr(true));
}

void BQ25798EnPrechgTmrSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_prechg_tmr(state, true);
  this->publish_state(state);
}




// EN_CHG_TMR - Fast charge timer enable
float BQ25798EnChgTmrSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnChgTmrSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnChgTmrSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_CHG_TMR", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnChgTmrSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_chg_tmr(true));
}

void BQ25798EnChgTmrSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_chg_tmr(state, true);
  this->publish_state(state);
}




// TMR2X_EN - 2x slower charging in DPM enable
float BQ25798Tmr2xEnSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798Tmr2xEnSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798Tmr2xEnSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "TMR2X_EN", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798Tmr2xEnSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_tmr2x_en(true));
}

void BQ25798Tmr2xEnSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_tmr2x_en(state, true);
  this->publish_state(state);
}




// EN_AUTO_IBATDIS - Enable the auto battery discharging during the battery OVP fault
float BQ25798EnAutoIbatdisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnAutoIbatdisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnAutoIbatdisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_AUTO_IBATDIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnAutoIbatdisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_auto_ibatdis(true));
}

void BQ25798EnAutoIbatdisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_auto_ibatdis(state, true);
  this->publish_state(state);
}




// FORCE_IBATDIS - Force the battery discharging current
float BQ25798ForceIbatdisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798ForceIbatdisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798ForceIbatdisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "FORCE_IBATDIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798ForceIbatdisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_force_ibatdis(true));
}

void BQ25798ForceIbatdisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_force_ibatdis(state, true);
  this->publish_state(state);
}




// EN_CHG - Enable the charger
float BQ25798EnChgSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnChgSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnChgSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_CHG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnChgSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_chg(true));
}

void BQ25798EnChgSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_chg(state, true);
  this->publish_state(state);
}




// EN_ICO - Enable the ICO (Input Current Optimizer)
float BQ25798EnIcoSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnIcoSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnIcoSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_ICO", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnIcoSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_ico(true));
}

void BQ25798EnIcoSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_ico(state, true);
  this->publish_state(state);
}




// FORCE_ICO - Force the ICO (Input Current Optimizer)
float BQ25798ForceIcoSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798ForceIcoSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798ForceIcoSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "FORCE_ICO", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798ForceIcoSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_force_ico(true));
}

void BQ25798ForceIcoSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_force_ico(state, true);
  this->publish_state(state);
}




// EN_HIZ - Enable the high impedance mode
float BQ25798EnHizSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnHizSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnHizSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_HIZ", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnHizSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_hiz(true));
}

void BQ25798EnHizSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_hiz(state, true);
  this->publish_state(state);
}




// EN_TERM - Enable the termination
float BQ25798EnTermSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnTermSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnTermSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_TERM", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnTermSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_term(true));
}

void BQ25798EnTermSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_term(state, true);
  this->publish_state(state);
}




// EN_BACKUP - Enable the backup (auto OTG) mode
float BQ25798EnBackupSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnBackupSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnBackupSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_BACKUP", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnBackupSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_backup(true));
}

void BQ25798EnBackupSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_backup(state, true);
  this->publish_state(state);
}




// WD_RST - I2C watch dog timer reset
float BQ25798WdRstSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798WdRstSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798WdRstSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "WD_RST", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798WdRstSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_wd_rst(true));
}

void BQ25798WdRstSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_wd_rst(state, true);
  this->publish_state(state);
}




// FORCE_INDET - Force D+/D- detection
float BQ25798ForceIndetSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798ForceIndetSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798ForceIndetSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "FORCE_INDET", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798ForceIndetSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_force_indet(true));
}

void BQ25798ForceIndetSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_force_indet(state, true);
  this->publish_state(state);
}




// AUTO_INDET_EN - Enable automatic D+/D- detection
float BQ25798AutoIndetEnSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798AutoIndetEnSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798AutoIndetEnSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "AUTO_INDET_EN", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798AutoIndetEnSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_auto_indet_en(true));
}

void BQ25798AutoIndetEnSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_auto_indet_en(state, true);
  this->publish_state(state);
}




// EN_12V - Enable 12V output in HVDCP
float BQ25798En12vSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798En12vSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798En12vSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_12V", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798En12vSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_12v(true));
}

void BQ25798En12vSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_12v(state, true);
  this->publish_state(state);
}




// EN_9V - Enable 9V output in HVDCP
float BQ25798En9vSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798En9vSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798En9vSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_9V", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798En9vSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_9v(true));
}

void BQ25798En9vSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_9v(state, true);
  this->publish_state(state);
}




// HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
float BQ25798HvdcpEnSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798HvdcpEnSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798HvdcpEnSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "HVDCP_EN", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798HvdcpEnSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_hvdcp_en(true));
}

void BQ25798HvdcpEnSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_hvdcp_en(state, true);
  this->publish_state(state);
}




// DIS_ACDRV - Disable both AC1 and AC2 drivers
float BQ25798DisAcdrvSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798DisAcdrvSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798DisAcdrvSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "DIS_ACDRV", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798DisAcdrvSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_dis_acdrv(true));
}

void BQ25798DisAcdrvSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_dis_acdrv(state, true);
  this->publish_state(state);
}




// EN_OTG - Enable OTG mode
float BQ25798EnOtgSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnOtgSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnOtgSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_OTG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnOtgSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_otg(true));
}

void BQ25798EnOtgSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_otg(state, true);
  this->publish_state(state);
}




// PFM_OTG_DIS - Disable PFM in OTG mode
float BQ25798PfmOtgDisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798PfmOtgDisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798PfmOtgDisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "PFM_OTG_DIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798PfmOtgDisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_pfm_otg_dis(true));
}

void BQ25798PfmOtgDisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_pfm_otg_dis(state, true);
  this->publish_state(state);
}




// PFM_FWD_DIS - Disable PFM in forward mode
float BQ25798PfmFwdDisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798PfmFwdDisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798PfmFwdDisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "PFM_FWD_DIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798PfmFwdDisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_pfm_fwd_dis(true));
}

void BQ25798PfmFwdDisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_pfm_fwd_dis(state, true);
  this->publish_state(state);
}




// DIS_LDO - Disable BATFET LDO mode in precharge state
float BQ25798DisLdoSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798DisLdoSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798DisLdoSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "DIS_LDO", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798DisLdoSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_dis_ldo(true));
}

void BQ25798DisLdoSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_dis_ldo(state, true);
  this->publish_state(state);
}




// DIS_OTG_OOA - Disable OOA in OTG mode
float BQ25798DisOtgOoaSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798DisOtgOoaSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798DisOtgOoaSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "DIS_OTG_OOA", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798DisOtgOoaSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_dis_otg_ooa(true));
}

void BQ25798DisOtgOoaSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_dis_otg_ooa(state, true);
  this->publish_state(state);
}




// DIS_FWD_OOA - Disable OOA in forward mode
float BQ25798DisFwdOoaSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798DisFwdOoaSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798DisFwdOoaSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "DIS_FWD_OOA", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798DisFwdOoaSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_dis_fwd_ooa(true));
}

void BQ25798DisFwdOoaSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_dis_fwd_ooa(state, true);
  this->publish_state(state);
}




// EN_ACDRV2 - Enable AC2 gate driver control
float BQ25798EnAcdrv2Switch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnAcdrv2Switch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnAcdrv2Switch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_ACDRV2", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnAcdrv2Switch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_acdrv2(true));
}

void BQ25798EnAcdrv2Switch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_acdrv2(state, true);
  this->publish_state(state);
}




// EN_ACDRV1 - Enable AC1 gate driver control
float BQ25798EnAcdrv1Switch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnAcdrv1Switch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnAcdrv1Switch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_ACDRV1", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnAcdrv1Switch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_acdrv1(true));
}

void BQ25798EnAcdrv1Switch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_acdrv1(state, true);
  this->publish_state(state);
}




// DIS_STAT - Disable STAT pin output
float BQ25798DisStatSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798DisStatSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798DisStatSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "DIS_STAT", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798DisStatSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_dis_stat(true));
}

void BQ25798DisStatSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_dis_stat(state, true);
  this->publish_state(state);
}




// DIS_VSYS_SHORT - Disable VSYS short hiccup protection
float BQ25798DisVsysShortSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798DisVsysShortSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798DisVsysShortSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "DIS_VSYS_SHORT", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798DisVsysShortSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_dis_vsys_short(true));
}

void BQ25798DisVsysShortSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_dis_vsys_short(state, true);
  this->publish_state(state);
}




// DIS_VOTG_UVP - Disable VOTG under voltage hiccup protection
float BQ25798DisVotgUvpSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798DisVotgUvpSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798DisVotgUvpSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "DIS_VOTG_UVP", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798DisVotgUvpSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_dis_votg_uvp(true));
}

void BQ25798DisVotgUvpSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_dis_votg_uvp(state, true);
  this->publish_state(state);
}




// FORCE_VINDPM_DET - Force VINDPM detection (settable only when VBAT>VSYSMIN)
float BQ25798ForceVindpmDetSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798ForceVindpmDetSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798ForceVindpmDetSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "FORCE_VINDPM_DET", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798ForceVindpmDetSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_force_vindpm_det(true));
}

void BQ25798ForceVindpmDetSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_force_vindpm_det(state, true);
  this->publish_state(state);
}




// EN_IBUS_OCP - Enable input over current protection in forward mode
float BQ25798EnIbusOcpSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnIbusOcpSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnIbusOcpSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_IBUS_OCP", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnIbusOcpSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_ibus_ocp(true));
}

void BQ25798EnIbusOcpSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_ibus_ocp(state, true);
  this->publish_state(state);
}




// SFET_PRESENT - Ship FET present
float BQ25798SfetPresentSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798SfetPresentSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798SfetPresentSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "SFET_PRESENT", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798SfetPresentSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_sfet_present(true));
}

void BQ25798SfetPresentSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_sfet_present(state, true);
  this->publish_state(state);
}




// EN_IBAT - Enable battery discharge current sensing
float BQ25798EnIbatSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnIbatSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnIbatSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_IBAT", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnIbatSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_ibat(true));
}

void BQ25798EnIbatSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_ibat(state, true);
  this->publish_state(state);
}




// EN_IINDPM - Enable input current regulation
float BQ25798EnIindpmSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnIindpmSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnIindpmSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_IINDPM", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnIindpmSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_iindpm(true));
}

void BQ25798EnIindpmSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_iindpm(state, true);
  this->publish_state(state);
}




// EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
float BQ25798EnExtilimSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnExtilimSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnExtilimSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_EXTILIM", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnExtilimSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_extilim(true));
}

void BQ25798EnExtilimSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_extilim(state, true);
  this->publish_state(state);
}




// EN_BATOC - Enable battery discharging over current protection
float BQ25798EnBatocSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnBatocSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnBatocSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_BATOC", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnBatocSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_batoc(true));
}

void BQ25798EnBatocSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_batoc(state, true);
  this->publish_state(state);
}




// EN_MPPT - 
float BQ25798EnMpptSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798EnMpptSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798EnMpptSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "EN_MPPT", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798EnMpptSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_en_mppt(true));
}

void BQ25798EnMpptSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_en_mppt(state, true);
  this->publish_state(state);
}




// VBUS_PD_EN - 
float BQ25798VbusPdEnSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VbusPdEnSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VbusPdEnSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "VBUS_PD_EN", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VbusPdEnSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_vbus_pd_en(true));
}

void BQ25798VbusPdEnSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_vbus_pd_en(state, true);
  this->publish_state(state);
}




// VAC1_PD_EN - 
float BQ25798Vac1PdEnSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798Vac1PdEnSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798Vac1PdEnSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "VAC1_PD_EN", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798Vac1PdEnSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_vac1_pd_en(true));
}

void BQ25798Vac1PdEnSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_vac1_pd_en(state, true);
  this->publish_state(state);
}




// VAC2_PD_EN - 
float BQ25798Vac2PdEnSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798Vac2PdEnSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798Vac2PdEnSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "VAC2_PD_EN", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798Vac2PdEnSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_vac2_pd_en(true));
}

void BQ25798Vac2PdEnSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_vac2_pd_en(state, true);
  this->publish_state(state);
}




// TS_IGNORE - 
float BQ25798TsIgnoreSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TsIgnoreSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TsIgnoreSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "TS_IGNORE", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TsIgnoreSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_ts_ignore(true));
}

void BQ25798TsIgnoreSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_ts_ignore(state, true);
  this->publish_state(state);
}




// ADC_EN - 
float BQ25798AdcEnSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798AdcEnSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798AdcEnSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "ADC_EN", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798AdcEnSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_adc_en(true));
}

void BQ25798AdcEnSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_adc_en(state, true);
  this->publish_state(state);
}




// ADC_AVG_INIT - 
float BQ25798AdcAvgInitSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798AdcAvgInitSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798AdcAvgInitSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "ADC_AVG_INIT", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798AdcAvgInitSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_adc_avg_init(true));
}

void BQ25798AdcAvgInitSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_adc_avg_init(state, true);
  this->publish_state(state);
}




// IBUS_ADC_DIS - 
float BQ25798IbusAdcDisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798IbusAdcDisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798IbusAdcDisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "IBUS_ADC_DIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798IbusAdcDisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_ibus_adc_dis(true));
}

void BQ25798IbusAdcDisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_ibus_adc_dis(state, true);
  this->publish_state(state);
}




// IBAT_ADC_DIS - 
float BQ25798IbatAdcDisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798IbatAdcDisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798IbatAdcDisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "IBAT_ADC_DIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798IbatAdcDisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_ibat_adc_dis(true));
}

void BQ25798IbatAdcDisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_ibat_adc_dis(state, true);
  this->publish_state(state);
}




// VBUS_ADC_DIS - 
float BQ25798VbusAdcDisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VbusAdcDisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VbusAdcDisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "VBUS_ADC_DIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VbusAdcDisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_vbus_adc_dis(true));
}

void BQ25798VbusAdcDisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_vbus_adc_dis(state, true);
  this->publish_state(state);
}




// VBAT_ADC_DIS - 
float BQ25798VbatAdcDisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VbatAdcDisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VbatAdcDisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "VBAT_ADC_DIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VbatAdcDisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_vbat_adc_dis(true));
}

void BQ25798VbatAdcDisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_vbat_adc_dis(state, true);
  this->publish_state(state);
}




// VSYS_ADC_DIS - 
float BQ25798VsysAdcDisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VsysAdcDisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VsysAdcDisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "VSYS_ADC_DIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VsysAdcDisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_vsys_adc_dis(true));
}

void BQ25798VsysAdcDisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_vsys_adc_dis(state, true);
  this->publish_state(state);
}




// TS_ADC_DIS - 
float BQ25798TsAdcDisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TsAdcDisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TsAdcDisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "TS_ADC_DIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TsAdcDisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_ts_adc_dis(true));
}

void BQ25798TsAdcDisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_ts_adc_dis(state, true);
  this->publish_state(state);
}




// TDIE_ADC_DIS - 
float BQ25798TdieAdcDisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TdieAdcDisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TdieAdcDisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "TDIE_ADC_DIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TdieAdcDisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_tdie_adc_dis(true));
}

void BQ25798TdieAdcDisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_tdie_adc_dis(state, true);
  this->publish_state(state);
}




// DPLUS_ADC_DIS - 
float BQ25798DplusAdcDisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798DplusAdcDisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798DplusAdcDisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "DPLUS_ADC_DIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798DplusAdcDisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_dplus_adc_dis(true));
}

void BQ25798DplusAdcDisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_dplus_adc_dis(state, true);
  this->publish_state(state);
}




// DMINUS_ADC_DIS - 
float BQ25798DminusAdcDisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798DminusAdcDisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798DminusAdcDisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "DMINUS_ADC_DIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798DminusAdcDisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_dminus_adc_dis(true));
}

void BQ25798DminusAdcDisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_dminus_adc_dis(state, true);
  this->publish_state(state);
}




// VAC2_ADC_DIS - 
float BQ25798Vac2AdcDisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798Vac2AdcDisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798Vac2AdcDisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "VAC2_ADC_DIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798Vac2AdcDisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_vac2_adc_dis(true));
}

void BQ25798Vac2AdcDisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_vac2_adc_dis(state, true);
  this->publish_state(state);
}




// VAC1_ADC_DIS - 
float BQ25798Vac1AdcDisSwitch::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798Vac1AdcDisSwitch::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798Vac1AdcDisSwitch configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  LOG_SWITCH("  ", "VAC1_ADC_DIS", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798Vac1AdcDisSwitch::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  this->publish_state(this->parent_->get_vac1_adc_dis(true));
}

void BQ25798Vac1AdcDisSwitch::write_state(bool state) {
  if (this->parent_->is_failed()) {
    return;
  }

  this->parent_->set_vac1_adc_dis(state, true);
  this->publish_state(state);
}




}  // namespace bq25798
}  // namespace esphome