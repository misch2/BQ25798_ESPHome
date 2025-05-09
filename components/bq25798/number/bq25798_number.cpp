#include "bq25798_number.h"

#include "esphome/core/log.h"

namespace esphome {
namespace bq25798 {

static const char* const TAG = "bq25798.number";


// VSYSMIN - Minimal System Voltage
float BQ25798VsysminNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VsysminNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VsysminNumber configuration...");
  LOG_NUMBER("  ", "VSYSMIN", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VsysminNumber::update() {
  this->publish_state(this->parent_->get_vsysmin(true));
}

void BQ25798VsysminNumber::control(float new_value) {
  this->parent_->set_vsysmin(new_value, true);
  this->publish_state(state);
}




// VREG - Charge Voltage Limit
float BQ25798VregNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VregNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VregNumber configuration...");
  LOG_NUMBER("  ", "VREG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VregNumber::update() {
  this->publish_state(this->parent_->get_vreg(true));
}

void BQ25798VregNumber::control(float new_value) {
  this->parent_->set_vreg(new_value, true);
  this->publish_state(state);
}




// ICHG - Charge Current Limit
float BQ25798IchgNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798IchgNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798IchgNumber configuration...");
  LOG_NUMBER("  ", "ICHG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798IchgNumber::update() {
  this->publish_state(this->parent_->get_ichg(true));
}

void BQ25798IchgNumber::control(float new_value) {
  this->parent_->set_ichg(new_value, true);
  this->publish_state(state);
}




// VINDPM - Input Voltage Limit
float BQ25798VindpmNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VindpmNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VindpmNumber configuration...");
  LOG_NUMBER("  ", "VINDPM", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VindpmNumber::update() {
  this->publish_state(this->parent_->get_vindpm(true));
}

void BQ25798VindpmNumber::control(float new_value) {
  this->parent_->set_vindpm(new_value, true);
  this->publish_state(state);
}




// IINDPM - Input Current Limit
float BQ25798IindpmNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798IindpmNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798IindpmNumber configuration...");
  LOG_NUMBER("  ", "IINDPM", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798IindpmNumber::update() {
  this->publish_state(this->parent_->get_iindpm(true));
}

void BQ25798IindpmNumber::control(float new_value) {
  this->parent_->set_iindpm(new_value, true);
  this->publish_state(state);
}




// VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
float BQ25798VbatLowvNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VbatLowvNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VbatLowvNumber configuration...");
  LOG_NUMBER("  ", "VBAT_LOWV", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VbatLowvNumber::update() {
  this->publish_state(this->parent_->get_vbat_lowv(true));
}

void BQ25798VbatLowvNumber::control(float new_value) {
  this->parent_->set_vbat_lowv(new_value, true);
  this->publish_state(state);
}




// IPRECHG - Precharge Current Limit
float BQ25798IprechgNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798IprechgNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798IprechgNumber configuration...");
  LOG_NUMBER("  ", "IPRECHG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798IprechgNumber::update() {
  this->publish_state(this->parent_->get_iprechg(true));
}

void BQ25798IprechgNumber::control(float new_value) {
  this->parent_->set_iprechg(new_value, true);
  this->publish_state(state);
}




// ITERM - Termination Current Limit
float BQ25798ItermNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798ItermNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798ItermNumber configuration...");
  LOG_NUMBER("  ", "ITERM", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798ItermNumber::update() {
  this->publish_state(this->parent_->get_iterm(true));
}

void BQ25798ItermNumber::control(float new_value) {
  this->parent_->set_iterm(new_value, true);
  this->publish_state(state);
}




// CELL - Battery cell count
float BQ25798CellNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798CellNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798CellNumber configuration...");
  LOG_NUMBER("  ", "CELL", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798CellNumber::update() {
  this->publish_state(this->parent_->get_cell(true));
}

void BQ25798CellNumber::control(float new_value) {
  this->parent_->set_cell(new_value, true);
  this->publish_state(state);
}




// TRECHG - Battery recharge delay time
float BQ25798TrechgNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TrechgNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TrechgNumber configuration...");
  LOG_NUMBER("  ", "TRECHG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TrechgNumber::update() {
  this->publish_state(this->parent_->get_trechg(true));
}

void BQ25798TrechgNumber::control(float new_value) {
  this->parent_->set_trechg(new_value, true);
  this->publish_state(state);
}




// VRECHG - Battery Recharge Threshold Offset (Below VREG)
float BQ25798VrechgNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VrechgNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VrechgNumber configuration...");
  LOG_NUMBER("  ", "VRECHG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VrechgNumber::update() {
  this->publish_state(this->parent_->get_vrechg(true));
}

void BQ25798VrechgNumber::control(float new_value) {
  this->parent_->set_vrechg(new_value, true);
  this->publish_state(state);
}




// VOTG - OTG mode regulation voltage
float BQ25798VotgNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VotgNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VotgNumber configuration...");
  LOG_NUMBER("  ", "VOTG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VotgNumber::update() {
  this->publish_state(this->parent_->get_votg(true));
}

void BQ25798VotgNumber::control(float new_value) {
  this->parent_->set_votg(new_value, true);
  this->publish_state(state);
}




// PRECHG_TMR - Pre-charge safety timer setting
float BQ25798PrechgTmrNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798PrechgTmrNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798PrechgTmrNumber configuration...");
  LOG_NUMBER("  ", "PRECHG_TMR", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798PrechgTmrNumber::update() {
  this->publish_state(this->parent_->get_prechg_tmr(true));
}

void BQ25798PrechgTmrNumber::control(float new_value) {
  this->parent_->set_prechg_tmr(new_value, true);
  this->publish_state(state);
}




// IOTG - OTG current limit
float BQ25798IotgNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798IotgNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798IotgNumber configuration...");
  LOG_NUMBER("  ", "IOTG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798IotgNumber::update() {
  this->publish_state(this->parent_->get_iotg(true));
}

void BQ25798IotgNumber::control(float new_value) {
  this->parent_->set_iotg(new_value, true);
  this->publish_state(state);
}




// TOPOFF_TMR - Top-off timer control
float BQ25798TopoffTmrNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TopoffTmrNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TopoffTmrNumber configuration...");
  LOG_NUMBER("  ", "TOPOFF_TMR", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TopoffTmrNumber::update() {
  this->publish_state(this->parent_->get_topoff_tmr(true));
}

void BQ25798TopoffTmrNumber::control(float new_value) {
  this->parent_->set_topoff_tmr(new_value, true);
  this->publish_state(state);
}




// CHG_TMR - Fast charge timer setting
float BQ25798ChgTmrNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798ChgTmrNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798ChgTmrNumber configuration...");
  LOG_NUMBER("  ", "CHG_TMR", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798ChgTmrNumber::update() {
  this->publish_state(this->parent_->get_chg_tmr(true));
}

void BQ25798ChgTmrNumber::control(float new_value) {
  this->parent_->set_chg_tmr(new_value, true);
  this->publish_state(state);
}




// VBUS_BACKUP - The thresholds to trigger the backup mode, defined as a ratio of VINDPM
float BQ25798VbusBackupNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VbusBackupNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VbusBackupNumber configuration...");
  LOG_NUMBER("  ", "VBUS_BACKUP", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VbusBackupNumber::update() {
  this->publish_state(this->parent_->get_vbus_backup(true));
}

void BQ25798VbusBackupNumber::control(float new_value) {
  this->parent_->set_vbus_backup(new_value, true);
  this->publish_state(state);
}




// VAC_OVP - Over voltage protection thresholds
float BQ25798VacOvpNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VacOvpNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VacOvpNumber configuration...");
  LOG_NUMBER("  ", "VAC_OVP", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VacOvpNumber::update() {
  this->publish_state(this->parent_->get_vac_ovp(true));
}

void BQ25798VacOvpNumber::control(float new_value) {
  this->parent_->set_vac_ovp(new_value, true);
  this->publish_state(state);
}




// WATCHDOG - Watchdog timer settings
float BQ25798WatchdogNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798WatchdogNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798WatchdogNumber configuration...");
  LOG_NUMBER("  ", "WATCHDOG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798WatchdogNumber::update() {
  this->publish_state(this->parent_->get_watchdog(true));
}

void BQ25798WatchdogNumber::control(float new_value) {
  this->parent_->set_watchdog(new_value, true);
  this->publish_state(state);
}




// SDRV_CTRL - Enable external Ship FET control
float BQ25798SdrvCtrlNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798SdrvCtrlNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798SdrvCtrlNumber configuration...");
  LOG_NUMBER("  ", "SDRV_CTRL", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798SdrvCtrlNumber::update() {
  this->publish_state(this->parent_->get_sdrv_ctrl(true));
}

void BQ25798SdrvCtrlNumber::control(float new_value) {
  this->parent_->set_sdrv_ctrl(new_value, true);
  this->publish_state(state);
}




// SDRV_DLY - Delay for SDRV control
float BQ25798SdrvDlyNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798SdrvDlyNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798SdrvDlyNumber configuration...");
  LOG_NUMBER("  ", "SDRV_DLY", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798SdrvDlyNumber::update() {
  this->publish_state(this->parent_->get_sdrv_dly(true));
}

void BQ25798SdrvDlyNumber::control(float new_value) {
  this->parent_->set_sdrv_dly(new_value, true);
  this->publish_state(state);
}




// WKUP_DLY - Wakeup (Ship FET) delay
float BQ25798WkupDlyNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798WkupDlyNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798WkupDlyNumber configuration...");
  LOG_NUMBER("  ", "WKUP_DLY", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798WkupDlyNumber::update() {
  this->publish_state(this->parent_->get_wkup_dly(true));
}

void BQ25798WkupDlyNumber::control(float new_value) {
  this->parent_->set_wkup_dly(new_value, true);
  this->publish_state(state);
}




// PWM_FREQ - PWM frequency setting
float BQ25798PwmFreqNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798PwmFreqNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798PwmFreqNumber configuration...");
  LOG_NUMBER("  ", "PWM_FREQ", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798PwmFreqNumber::update() {
  this->publish_state(this->parent_->get_pwm_freq(true));
}

void BQ25798PwmFreqNumber::control(float new_value) {
  this->parent_->set_pwm_freq(new_value, true);
  this->publish_state(state);
}




// IBAT_REG - Battery discharge current regulation in OTG mode
float BQ25798IbatRegNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798IbatRegNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798IbatRegNumber configuration...");
  LOG_NUMBER("  ", "IBAT_REG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798IbatRegNumber::update() {
  this->publish_state(this->parent_->get_ibat_reg(true));
}

void BQ25798IbatRegNumber::control(float new_value) {
  this->parent_->set_ibat_reg(new_value, true);
  this->publish_state(state);
}




// VOC_PCT - 
float BQ25798VocPctNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VocPctNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VocPctNumber configuration...");
  LOG_NUMBER("  ", "VOC_PCT", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VocPctNumber::update() {
  this->publish_state(this->parent_->get_voc_pct(true));
}

void BQ25798VocPctNumber::control(float new_value) {
  this->parent_->set_voc_pct(new_value, true);
  this->publish_state(state);
}




// VOC_DLY - 
float BQ25798VocDlyNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VocDlyNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VocDlyNumber configuration...");
  LOG_NUMBER("  ", "VOC_DLY", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VocDlyNumber::update() {
  this->publish_state(this->parent_->get_voc_dly(true));
}

void BQ25798VocDlyNumber::control(float new_value) {
  this->parent_->set_voc_dly(new_value, true);
  this->publish_state(state);
}




// VOC_RATE - 
float BQ25798VocRateNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798VocRateNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798VocRateNumber configuration...");
  LOG_NUMBER("  ", "VOC_RATE", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798VocRateNumber::update() {
  this->publish_state(this->parent_->get_voc_rate(true));
}

void BQ25798VocRateNumber::control(float new_value) {
  this->parent_->set_voc_rate(new_value, true);
  this->publish_state(state);
}




// TREG - 
float BQ25798TregNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TregNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TregNumber configuration...");
  LOG_NUMBER("  ", "TREG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TregNumber::update() {
  this->publish_state(this->parent_->get_treg(true));
}

void BQ25798TregNumber::control(float new_value) {
  this->parent_->set_treg(new_value, true);
  this->publish_state(state);
}




// TSHUT - 
float BQ25798TshutNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TshutNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TshutNumber configuration...");
  LOG_NUMBER("  ", "TSHUT", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TshutNumber::update() {
  this->publish_state(this->parent_->get_tshut(true));
}

void BQ25798TshutNumber::control(float new_value) {
  this->parent_->set_tshut(new_value, true);
  this->publish_state(state);
}




// BKUP_ACFET1_ON - 
float BQ25798BkupAcfet1OnNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798BkupAcfet1OnNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798BkupAcfet1OnNumber configuration...");
  LOG_NUMBER("  ", "BKUP_ACFET1_ON", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798BkupAcfet1OnNumber::update() {
  this->publish_state(this->parent_->get_bkup_acfet1_on(true));
}

void BQ25798BkupAcfet1OnNumber::control(float new_value) {
  this->parent_->set_bkup_acfet1_on(new_value, true);
  this->publish_state(state);
}




// JEITA_VSET - 
float BQ25798JeitaVsetNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798JeitaVsetNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798JeitaVsetNumber configuration...");
  LOG_NUMBER("  ", "JEITA_VSET", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798JeitaVsetNumber::update() {
  this->publish_state(this->parent_->get_jeita_vset(true));
}

void BQ25798JeitaVsetNumber::control(float new_value) {
  this->parent_->set_jeita_vset(new_value, true);
  this->publish_state(state);
}




// JEITA_ISETH - 
float BQ25798JeitaIsethNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798JeitaIsethNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798JeitaIsethNumber configuration...");
  LOG_NUMBER("  ", "JEITA_ISETH", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798JeitaIsethNumber::update() {
  this->publish_state(this->parent_->get_jeita_iseth(true));
}

void BQ25798JeitaIsethNumber::control(float new_value) {
  this->parent_->set_jeita_iseth(new_value, true);
  this->publish_state(state);
}




// JEITA_ISETC - 
float BQ25798JeitaIsetcNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798JeitaIsetcNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798JeitaIsetcNumber configuration...");
  LOG_NUMBER("  ", "JEITA_ISETC", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798JeitaIsetcNumber::update() {
  this->publish_state(this->parent_->get_jeita_isetc(true));
}

void BQ25798JeitaIsetcNumber::control(float new_value) {
  this->parent_->set_jeita_isetc(new_value, true);
  this->publish_state(state);
}




// TS_COOL - 
float BQ25798TsCoolNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TsCoolNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TsCoolNumber configuration...");
  LOG_NUMBER("  ", "TS_COOL", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TsCoolNumber::update() {
  this->publish_state(this->parent_->get_ts_cool(true));
}

void BQ25798TsCoolNumber::control(float new_value) {
  this->parent_->set_ts_cool(new_value, true);
  this->publish_state(state);
}




// TS_WARM - 
float BQ25798TsWarmNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TsWarmNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TsWarmNumber configuration...");
  LOG_NUMBER("  ", "TS_WARM", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TsWarmNumber::update() {
  this->publish_state(this->parent_->get_ts_warm(true));
}

void BQ25798TsWarmNumber::control(float new_value) {
  this->parent_->set_ts_warm(new_value, true);
  this->publish_state(state);
}




// BHOT - 
float BQ25798BhotNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798BhotNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798BhotNumber configuration...");
  LOG_NUMBER("  ", "BHOT", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798BhotNumber::update() {
  this->publish_state(this->parent_->get_bhot(true));
}

void BQ25798BhotNumber::control(float new_value) {
  this->parent_->set_bhot(new_value, true);
  this->publish_state(state);
}




// BCOLD - 
float BQ25798BcoldNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798BcoldNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798BcoldNumber configuration...");
  LOG_NUMBER("  ", "BCOLD", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798BcoldNumber::update() {
  this->publish_state(this->parent_->get_bcold(true));
}

void BQ25798BcoldNumber::control(float new_value) {
  this->parent_->set_bcold(new_value, true);
  this->publish_state(state);
}




// ADC_RATE - 
float BQ25798AdcRateNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798AdcRateNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798AdcRateNumber configuration...");
  LOG_NUMBER("  ", "ADC_RATE", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798AdcRateNumber::update() {
  this->publish_state(this->parent_->get_adc_rate(true));
}

void BQ25798AdcRateNumber::control(float new_value) {
  this->parent_->set_adc_rate(new_value, true);
  this->publish_state(state);
}




// ADC_SAMPLE - 
float BQ25798AdcSampleNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798AdcSampleNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798AdcSampleNumber configuration...");
  LOG_NUMBER("  ", "ADC_SAMPLE", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798AdcSampleNumber::update() {
  this->publish_state(this->parent_->get_adc_sample(true));
}

void BQ25798AdcSampleNumber::control(float new_value) {
  this->parent_->set_adc_sample(new_value, true);
  this->publish_state(state);
}




// ADC_AVG - 
float BQ25798AdcAvgNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798AdcAvgNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798AdcAvgNumber configuration...");
  LOG_NUMBER("  ", "ADC_AVG", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798AdcAvgNumber::update() {
  this->publish_state(this->parent_->get_adc_avg(true));
}

void BQ25798AdcAvgNumber::control(float new_value) {
  this->parent_->set_adc_avg(new_value, true);
  this->publish_state(state);
}




// DPLUS_DAC - D+ Output Driver
float BQ25798DplusDacNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798DplusDacNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798DplusDacNumber configuration...");
  LOG_NUMBER("  ", "DPLUS_DAC", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798DplusDacNumber::update() {
  this->publish_state(this->parent_->get_dplus_dac(true));
}

void BQ25798DplusDacNumber::control(float new_value) {
  this->parent_->set_dplus_dac(new_value, true);
  this->publish_state(state);
}




// DMINUS_DAC - D- Output Driver
float BQ25798DminusDacNumber::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798DminusDacNumber::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798DminusDacNumber configuration...");
  LOG_NUMBER("  ", "DMINUS_DAC", this);
  LOG_UPDATE_INTERVAL(this);
}

void BQ25798DminusDacNumber::update() {
  this->publish_state(this->parent_->get_dminus_dac(true));
}

void BQ25798DminusDacNumber::control(float new_value) {
  this->parent_->set_dminus_dac(new_value, true);
  this->publish_state(state);
}




}  // namespace bq25798
}  // namespace esphome