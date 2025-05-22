
#include "bq25798_text_sensor.h"

#include "esphome/core/log.h"

namespace esphome {
namespace bq25798 {

static const char* const TAG = "bq25798.text_sensor";

float BQ25798TextSensor::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TextSensor::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TextSensor configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  if (this->text_sensor_vbat_lowv_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "VBAT_LOWV", this->text_sensor_vbat_lowv_);
  }
  if (this->text_sensor_cell_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "CELL", this->text_sensor_cell_);
  }
  if (this->text_sensor_trechg_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "TRECHG", this->text_sensor_trechg_);
  }
  if (this->text_sensor_prechg_tmr_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "PRECHG_TMR", this->text_sensor_prechg_tmr_);
  }
  if (this->text_sensor_topoff_tmr_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "TOPOFF_TMR", this->text_sensor_topoff_tmr_);
  }
  if (this->text_sensor_chg_tmr_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "CHG_TMR", this->text_sensor_chg_tmr_);
  }
  if (this->text_sensor_vbus_backup_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "VBUS_BACKUP", this->text_sensor_vbus_backup_);
  }
  if (this->text_sensor_vac_ovp_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "VAC_OVP", this->text_sensor_vac_ovp_);
  }
  if (this->text_sensor_watchdog_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "WATCHDOG", this->text_sensor_watchdog_);
  }
  if (this->text_sensor_sdrv_ctrl_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "SDRV_CTRL", this->text_sensor_sdrv_ctrl_);
  }
  if (this->text_sensor_sdrv_dly_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "SDRV_DLY", this->text_sensor_sdrv_dly_);
  }
  if (this->text_sensor_wkup_dly_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "WKUP_DLY", this->text_sensor_wkup_dly_);
  }
  if (this->text_sensor_pwm_freq_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "PWM_FREQ", this->text_sensor_pwm_freq_);
  }
  if (this->text_sensor_ibat_reg_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "IBAT_REG", this->text_sensor_ibat_reg_);
  }
  if (this->text_sensor_voc_pct_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "VOC_PCT", this->text_sensor_voc_pct_);
  }
  if (this->text_sensor_voc_dly_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "VOC_DLY", this->text_sensor_voc_dly_);
  }
  if (this->text_sensor_voc_rate_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "VOC_RATE", this->text_sensor_voc_rate_);
  }
  if (this->text_sensor_treg_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "TREG", this->text_sensor_treg_);
  }
  if (this->text_sensor_tshut_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "TSHUT", this->text_sensor_tshut_);
  }
  if (this->text_sensor_bkup_acfet1_on_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "BKUP_ACFET1_ON", this->text_sensor_bkup_acfet1_on_);
  }
  if (this->text_sensor_jeita_vset_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "JEITA_VSET", this->text_sensor_jeita_vset_);
  }
  if (this->text_sensor_jeita_iseth_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "JEITA_ISETH", this->text_sensor_jeita_iseth_);
  }
  if (this->text_sensor_jeita_isetc_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "JEITA_ISETC", this->text_sensor_jeita_isetc_);
  }
  if (this->text_sensor_ts_cool_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "TS_COOL", this->text_sensor_ts_cool_);
  }
  if (this->text_sensor_ts_warm_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "TS_WARM", this->text_sensor_ts_warm_);
  }
  if (this->text_sensor_bhot_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "BHOT", this->text_sensor_bhot_);
  }
  if (this->text_sensor_bcold_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "BCOLD", this->text_sensor_bcold_);
  }
  if (this->text_sensor_iindpm_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "IINDPM_STAT", this->text_sensor_iindpm_stat_);
  }
  if (this->text_sensor_vindpm_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "VINDPM_STAT", this->text_sensor_vindpm_stat_);
  }
  if (this->text_sensor_wd_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "WD_STAT", this->text_sensor_wd_stat_);
  }
  if (this->text_sensor_pg_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "PG_STAT", this->text_sensor_pg_stat_);
  }
  if (this->text_sensor_ac2_present_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "AC2_PRESENT_STAT", this->text_sensor_ac2_present_stat_);
  }
  if (this->text_sensor_ac1_present_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "AC1_PRESENT_STAT", this->text_sensor_ac1_present_stat_);
  }
  if (this->text_sensor_vbus_present_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "VBUS_PRESENT_STAT", this->text_sensor_vbus_present_stat_);
  }
  if (this->text_sensor_chg_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "CHG_STAT", this->text_sensor_chg_stat_);
  }
  if (this->text_sensor_vbus_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "VBUS_STAT", this->text_sensor_vbus_stat_);
  }
  if (this->text_sensor_ico_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "ICO_STAT", this->text_sensor_ico_stat_);
  }
  if (this->text_sensor_treg_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "TREG_STAT", this->text_sensor_treg_stat_);
  }
  if (this->text_sensor_dpdm_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "DPDM_STAT", this->text_sensor_dpdm_stat_);
  }
  if (this->text_sensor_vbat_present_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "VBAT_PRESENT_STAT", this->text_sensor_vbat_present_stat_);
  }
  if (this->text_sensor_acrb2_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "ACRB2_STAT", this->text_sensor_acrb2_stat_);
  }
  if (this->text_sensor_acrb1_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "ACRB1_STAT", this->text_sensor_acrb1_stat_);
  }
  if (this->text_sensor_vsys_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "VSYS_STAT", this->text_sensor_vsys_stat_);
  }
  if (this->text_sensor_chg_tmr_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "CHG_TMR_STAT", this->text_sensor_chg_tmr_stat_);
  }
  if (this->text_sensor_trichg_tmr_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "TRICHG_TMR_STAT", this->text_sensor_trichg_tmr_stat_);
  }
  if (this->text_sensor_prechg_tmr_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "PRECHG_TMR_STAT", this->text_sensor_prechg_tmr_stat_);
  }
  if (this->text_sensor_vbatotg_low_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "VBATOTG_LOW_STAT", this->text_sensor_vbatotg_low_stat_);
  }
  if (this->text_sensor_ts_cold_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "TS_COLD_STAT", this->text_sensor_ts_cold_stat_);
  }
  if (this->text_sensor_ts_cool_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "TS_COOL_STAT", this->text_sensor_ts_cool_stat_);
  }
  if (this->text_sensor_ts_warm_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "TS_WARM_STAT", this->text_sensor_ts_warm_stat_);
  }
  if (this->text_sensor_ts_hot_stat_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "TS_HOT_STAT", this->text_sensor_ts_hot_stat_);
  }
  if (this->text_sensor_adc_rate_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "ADC_RATE", this->text_sensor_adc_rate_);
  }
  if (this->text_sensor_adc_sample_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "ADC_SAMPLE", this->text_sensor_adc_sample_);
  }
  if (this->text_sensor_adc_avg_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "ADC_AVG", this->text_sensor_adc_avg_);
  }
  if (this->text_sensor_dplus_dac_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "DPLUS_DAC", this->text_sensor_dplus_dac_);
  }
  if (this->text_sensor_dminus_dac_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "DMINUS_DAC", this->text_sensor_dminus_dac_);
  }
  if (this->text_sensor_pn_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "PN", this->text_sensor_pn_);
  }
  if (this->text_sensor_dev_rev_ != nullptr) {
    LOG_TEXT_SENSOR("  ", "DEV_REV", this->text_sensor_dev_rev_);
  }

  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TextSensor::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  // VSYSMIN - Minimal System Voltage
   
  // VREG - Charge Voltage Limit
   
  // ICHG - Charge Current Limit
   
  // VINDPM - Input Voltage Limit
   
  // IINDPM - Input Current Limit
   
  // VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
   
  if (this->text_sensor_vbat_lowv_ != nullptr) {   
    this->text_sensor_vbat_lowv_->publish_state(this->parent_->get_vbat_lowv_string(true));   
  }   
   
  // IPRECHG - Precharge Current Limit
   
  // REG_RST - Reset registers to default values and reset timer
   
  // STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
   
  // ITERM - Termination Current Limit
   
  // CELL - Battery cell count
   
  if (this->text_sensor_cell_ != nullptr) {   
    this->text_sensor_cell_->publish_state(this->parent_->get_cell_string(true));   
  }   
   
  // TRECHG - Battery recharge delay time
   
  if (this->text_sensor_trechg_ != nullptr) {   
    this->text_sensor_trechg_->publish_state(this->parent_->get_trechg_string(true));   
  }   
   
  // VRECHG - Battery Recharge Threshold Offset (Below VREG)
   
  // VOTG - OTG mode regulation voltage
   
  // PRECHG_TMR - Pre-charge safety timer setting
   
  if (this->text_sensor_prechg_tmr_ != nullptr) {   
    this->text_sensor_prechg_tmr_->publish_state(this->parent_->get_prechg_tmr_string(true));   
  }   
   
  // IOTG - OTG current limit
   
  // TOPOFF_TMR - Top-off timer control
   
  if (this->text_sensor_topoff_tmr_ != nullptr) {   
    this->text_sensor_topoff_tmr_->publish_state(this->parent_->get_topoff_tmr_string(true));   
  }   
   
  // EN_TRICHG_TMR - Trickle charge timer enable
   
  // EN_PRECHG_TMR - Precharge timer enable
   
  // EN_CHG_TMR - Fast charge timer enable
   
  // CHG_TMR - Fast charge timer setting
   
  if (this->text_sensor_chg_tmr_ != nullptr) {   
    this->text_sensor_chg_tmr_->publish_state(this->parent_->get_chg_tmr_string(true));   
  }   
   
  // TMR2X_EN - 2x slower charging in DPM enable
   
  // EN_AUTO_IBATDIS - Enable the auto battery discharging during the battery OVP fault
   
  // FORCE_IBATDIS - Force the battery discharging current
   
  // EN_CHG - Enable the charger
   
  // EN_ICO - Enable the ICO (Input Current Optimizer)
   
  // FORCE_ICO - Force the ICO (Input Current Optimizer)
   
  // EN_HIZ - Enable the high impedance mode
   
  // EN_TERM - Enable the termination
   
  // EN_BACKUP - Enable the backup (auto OTG) mode
   
  // VBUS_BACKUP - The thresholds to trigger the backup mode, defined as a ratio of VINDPM
   
  if (this->text_sensor_vbus_backup_ != nullptr) {   
    this->text_sensor_vbus_backup_->publish_state(this->parent_->get_vbus_backup_string(true));   
  }   
   
  // VAC_OVP - Over voltage protection thresholds
   
  if (this->text_sensor_vac_ovp_ != nullptr) {   
    this->text_sensor_vac_ovp_->publish_state(this->parent_->get_vac_ovp_string(true));   
  }   
   
  // WD_RST - I2C watch dog timer reset
   
  // WATCHDOG - Watchdog timer settings
   
  if (this->text_sensor_watchdog_ != nullptr) {   
    this->text_sensor_watchdog_->publish_state(this->parent_->get_watchdog_string(true));   
  }   
   
  // FORCE_INDET - Force D+/D- detection
   
  // AUTO_INDET_EN - Enable automatic D+/D- detection
   
  // EN_12V - Enable 12V output in HVDCP
   
  // EN_9V - Enable 9V output in HVDCP
   
  // HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
   
  // SDRV_CTRL - Enable external Ship FET control
   
  if (this->text_sensor_sdrv_ctrl_ != nullptr) {   
    this->text_sensor_sdrv_ctrl_->publish_state(this->parent_->get_sdrv_ctrl_string(true));   
  }   
   
  // SDRV_DLY - Delay for SDRV control
   
  if (this->text_sensor_sdrv_dly_ != nullptr) {   
    this->text_sensor_sdrv_dly_->publish_state(this->parent_->get_sdrv_dly_string(true));   
  }   
   
  // DIS_ACDRV - Disable both AC1 and AC2 drivers
   
  // EN_OTG - Enable OTG mode
   
  // PFM_OTG_DIS - Disable PFM in OTG mode
   
  // PFM_FWD_DIS - Disable PFM in forward mode
   
  // WKUP_DLY - Wakeup (Ship FET) delay
   
  if (this->text_sensor_wkup_dly_ != nullptr) {   
    this->text_sensor_wkup_dly_->publish_state(this->parent_->get_wkup_dly_string(true));   
  }   
   
  // DIS_LDO - Disable BATFET LDO mode in precharge state
   
  // DIS_OTG_OOA - Disable OOA in OTG mode
   
  // DIS_FWD_OOA - Disable OOA in forward mode
   
  // EN_ACDRV2 - Enable AC2 gate driver control
   
  // EN_ACDRV1 - Enable AC1 gate driver control
   
  // PWM_FREQ - PWM frequency setting
   
  if (this->text_sensor_pwm_freq_ != nullptr) {   
    this->text_sensor_pwm_freq_->publish_state(this->parent_->get_pwm_freq_string(true));   
  }   
   
  // DIS_STAT - Disable STAT pin output
   
  // DIS_VSYS_SHORT - Disable VSYS short hiccup protection
   
  // DIS_VOTG_UVP - Disable VOTG under voltage hiccup protection
   
  // FORCE_VINDPM_DET - Force VINDPM detection (settable only when VBAT>VSYSMIN)
   
  // EN_IBUS_OCP - Enable input over current protection in forward mode
   
  // SFET_PRESENT - Ship FET present
   
  // EN_IBAT - Enable battery discharge current sensing
   
  // IBAT_REG - Battery discharge current regulation in OTG mode
   
  if (this->text_sensor_ibat_reg_ != nullptr) {   
    this->text_sensor_ibat_reg_->publish_state(this->parent_->get_ibat_reg_string(true));   
  }   
   
  // EN_IINDPM - Enable input current regulation
   
  // EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
   
  // EN_BATOC - Enable battery discharging over current protection
   
  // VOC_PCT - 
   
  if (this->text_sensor_voc_pct_ != nullptr) {   
    this->text_sensor_voc_pct_->publish_state(this->parent_->get_voc_pct_string(true));   
  }   
   
  // VOC_DLY - 
   
  if (this->text_sensor_voc_dly_ != nullptr) {   
    this->text_sensor_voc_dly_->publish_state(this->parent_->get_voc_dly_string(true));   
  }   
   
  // VOC_RATE - 
   
  if (this->text_sensor_voc_rate_ != nullptr) {   
    this->text_sensor_voc_rate_->publish_state(this->parent_->get_voc_rate_string(true));   
  }   
   
  // EN_MPPT - 
   
  // TREG - 
   
  if (this->text_sensor_treg_ != nullptr) {   
    this->text_sensor_treg_->publish_state(this->parent_->get_treg_string(true));   
  }   
   
  // TSHUT - 
   
  if (this->text_sensor_tshut_ != nullptr) {   
    this->text_sensor_tshut_->publish_state(this->parent_->get_tshut_string(true));   
  }   
   
  // VBUS_PD_EN - 
   
  // VAC1_PD_EN - 
   
  // VAC2_PD_EN - 
   
  // BKUP_ACFET1_ON - 
   
  if (this->text_sensor_bkup_acfet1_on_ != nullptr) {   
    this->text_sensor_bkup_acfet1_on_->publish_state(this->parent_->get_bkup_acfet1_on_string(true));   
  }   
   
  // JEITA_VSET - 
   
  if (this->text_sensor_jeita_vset_ != nullptr) {   
    this->text_sensor_jeita_vset_->publish_state(this->parent_->get_jeita_vset_string(true));   
  }   
   
  // JEITA_ISETH - 
   
  if (this->text_sensor_jeita_iseth_ != nullptr) {   
    this->text_sensor_jeita_iseth_->publish_state(this->parent_->get_jeita_iseth_string(true));   
  }   
   
  // JEITA_ISETC - 
   
  if (this->text_sensor_jeita_isetc_ != nullptr) {   
    this->text_sensor_jeita_isetc_->publish_state(this->parent_->get_jeita_isetc_string(true));   
  }   
   
  // TS_COOL - 
   
  if (this->text_sensor_ts_cool_ != nullptr) {   
    this->text_sensor_ts_cool_->publish_state(this->parent_->get_ts_cool_string(true));   
  }   
   
  // TS_WARM - 
   
  if (this->text_sensor_ts_warm_ != nullptr) {   
    this->text_sensor_ts_warm_->publish_state(this->parent_->get_ts_warm_string(true));   
  }   
   
  // BHOT - 
   
  if (this->text_sensor_bhot_ != nullptr) {   
    this->text_sensor_bhot_->publish_state(this->parent_->get_bhot_string(true));   
  }   
   
  // BCOLD - 
   
  if (this->text_sensor_bcold_ != nullptr) {   
    this->text_sensor_bcold_->publish_state(this->parent_->get_bcold_string(true));   
  }   
   
  // TS_IGNORE - 
   
  // ICO_ILIM - 
   
  // IINDPM_STAT - 
   
  if (this->text_sensor_iindpm_stat_ != nullptr) {   
    this->text_sensor_iindpm_stat_->publish_state(this->parent_->get_iindpm_stat_string(true));   
  }   
   
  // VINDPM_STAT - 
   
  if (this->text_sensor_vindpm_stat_ != nullptr) {   
    this->text_sensor_vindpm_stat_->publish_state(this->parent_->get_vindpm_stat_string(true));   
  }   
   
  // WD_STAT - 
   
  if (this->text_sensor_wd_stat_ != nullptr) {   
    this->text_sensor_wd_stat_->publish_state(this->parent_->get_wd_stat_string(true));   
  }   
   
  // PG_STAT - 
   
  if (this->text_sensor_pg_stat_ != nullptr) {   
    this->text_sensor_pg_stat_->publish_state(this->parent_->get_pg_stat_string(true));   
  }   
   
  // AC2_PRESENT_STAT - 
   
  if (this->text_sensor_ac2_present_stat_ != nullptr) {   
    this->text_sensor_ac2_present_stat_->publish_state(this->parent_->get_ac2_present_stat_string(true));   
  }   
   
  // AC1_PRESENT_STAT - 
   
  if (this->text_sensor_ac1_present_stat_ != nullptr) {   
    this->text_sensor_ac1_present_stat_->publish_state(this->parent_->get_ac1_present_stat_string(true));   
  }   
   
  // VBUS_PRESENT_STAT - 
   
  if (this->text_sensor_vbus_present_stat_ != nullptr) {   
    this->text_sensor_vbus_present_stat_->publish_state(this->parent_->get_vbus_present_stat_string(true));   
  }   
   
  // CHG_STAT - Charge Status bits
   
  if (this->text_sensor_chg_stat_ != nullptr) {   
    this->text_sensor_chg_stat_->publish_state(this->parent_->get_chg_stat_string(true));   
  }   
   
  // VBUS_STAT - VBUS status bits
   
  if (this->text_sensor_vbus_stat_ != nullptr) {   
    this->text_sensor_vbus_stat_->publish_state(this->parent_->get_vbus_stat_string(true));   
  }   
   
  // BC12_DONE_STAT - 
   
  // ICO_STAT - 
   
  if (this->text_sensor_ico_stat_ != nullptr) {   
    this->text_sensor_ico_stat_->publish_state(this->parent_->get_ico_stat_string(true));   
  }   
   
  // TREG_STAT - 
   
  if (this->text_sensor_treg_stat_ != nullptr) {   
    this->text_sensor_treg_stat_->publish_state(this->parent_->get_treg_stat_string(true));   
  }   
   
  // DPDM_STAT - 
   
  if (this->text_sensor_dpdm_stat_ != nullptr) {   
    this->text_sensor_dpdm_stat_->publish_state(this->parent_->get_dpdm_stat_string(true));   
  }   
   
  // VBAT_PRESENT_STAT - 
   
  if (this->text_sensor_vbat_present_stat_ != nullptr) {   
    this->text_sensor_vbat_present_stat_->publish_state(this->parent_->get_vbat_present_stat_string(true));   
  }   
   
  // ACRB2_STAT - The ACFET2-RBFET2 status
   
  if (this->text_sensor_acrb2_stat_ != nullptr) {   
    this->text_sensor_acrb2_stat_->publish_state(this->parent_->get_acrb2_stat_string(true));   
  }   
   
  // ACRB1_STAT - The ACFET1-RBFET1 status
   
  if (this->text_sensor_acrb1_stat_ != nullptr) {   
    this->text_sensor_acrb1_stat_->publish_state(this->parent_->get_acrb1_stat_string(true));   
  }   
   
  // ADC_DONE_STAT - ADC Conversion Status
   
  // VSYS_STAT - VSYS Regulation Status
   
  if (this->text_sensor_vsys_stat_ != nullptr) {   
    this->text_sensor_vsys_stat_->publish_state(this->parent_->get_vsys_stat_string(true));   
  }   
   
  // CHG_TMR_STAT - Fast charge timer status
   
  if (this->text_sensor_chg_tmr_stat_ != nullptr) {   
    this->text_sensor_chg_tmr_stat_->publish_state(this->parent_->get_chg_tmr_stat_string(true));   
  }   
   
  // TRICHG_TMR_STAT - Trickle charge timer status
   
  if (this->text_sensor_trichg_tmr_stat_ != nullptr) {   
    this->text_sensor_trichg_tmr_stat_->publish_state(this->parent_->get_trichg_tmr_stat_string(true));   
  }   
   
  // PRECHG_TMR_STAT - Pre-charge timer status
   
  if (this->text_sensor_prechg_tmr_stat_ != nullptr) {   
    this->text_sensor_prechg_tmr_stat_->publish_state(this->parent_->get_prechg_tmr_stat_string(true));   
  }   
   
  // VBATOTG_LOW_STAT - VBAT too low to enable OTG flag
   
  if (this->text_sensor_vbatotg_low_stat_ != nullptr) {   
    this->text_sensor_vbatotg_low_stat_->publish_state(this->parent_->get_vbatotg_low_stat_string(true));   
  }   
   
  // TS_COLD_STAT - The TS temperature is in the cold range
   
  if (this->text_sensor_ts_cold_stat_ != nullptr) {   
    this->text_sensor_ts_cold_stat_->publish_state(this->parent_->get_ts_cold_stat_string(true));   
  }   
   
  // TS_COOL_STAT - The TS temperature is in the cool range
   
  if (this->text_sensor_ts_cool_stat_ != nullptr) {   
    this->text_sensor_ts_cool_stat_->publish_state(this->parent_->get_ts_cool_stat_string(true));   
  }   
   
  // TS_WARM_STAT - The TS temperature is in the warm range
   
  if (this->text_sensor_ts_warm_stat_ != nullptr) {   
    this->text_sensor_ts_warm_stat_->publish_state(this->parent_->get_ts_warm_stat_string(true));   
  }   
   
  // TS_HOT_STAT - The TS temperature is in the hot range
   
  if (this->text_sensor_ts_hot_stat_ != nullptr) {   
    this->text_sensor_ts_hot_stat_->publish_state(this->parent_->get_ts_hot_stat_string(true));   
  }   
   
  // IBAT_REG_STAT - IBAT regulation status
   
  // VBUS_OVP_STAT - VBUS over-voltage status
   
  // VBAT_OVP_STAT - VBAT over-voltage status
   
  // IBUS_OCP_STAT - IBUS over-current status
   
  // IBAT_OCP_STAT - IBAT over-current status
   
  // CONV_OCP_STAT - Converter over-current status
   
  // VAC2_OVP_STAT - VAC2 over-voltage status
   
  // VAC1_OVP_STAT - VAC1 over-voltage status
   
  // VSYS_SHORT_STAT - 
   
  // VSYS_OVP_STAT - 
   
  // OTG_OVP_STAT - 
   
  // OTG_UVP_STAT - 
   
  // TSHUT_STAT - 
   
  // IINDPM_FLAG - In IINDPM / IOTG regulation
   
  // VINDPM_FLAG - In VINDPM / VOTG regulation
   
  // WD_FLAG - Watchdog timer expired
   
  // POORSRC_FLAG - Poor source detected
   
  // PG_FLAG - Power status changed
   
  // AC2_PRESENT_FLAG - AC2 present status changed
   
  // AC1_PRESENT_FLAG - AC1 present status changed
   
  // VBUS_PRESENT_FLAG - VBUS present status changed
   
  // CHG_FLAG - Charging status changed
   
  // ICO_FLAG - ICO status changed
   
  // VBUS_FLAG - VBUS status changed
   
  // TREG_FLAG - 
   
  // VBAT_PRESENT_FLAG - 
   
  // BC1_2_DONE_FLAG - 
   
  // DPDM_DONE_FLAG - 
   
  // ADC_DONE_FLAG - 
   
  // VSYS_FLAG - 
   
  // CHG_TMR_FLAG - 
   
  // TRICHG_TMR_FLAG - 
   
  // PRECHG_TMR_FLAG - 
   
  // TOPOFF_TMR_FLAG - 
   
  // VBATOTG_LOW_FLAG - 
   
  // TS_COLD_FLAG - 
   
  // TS_COOL_FLAG - 
   
  // TS_WARM_FLAG - 
   
  // TS_HOT_FLAG - 
   
  // IBAT_REG_FLAG - 
   
  // VBUS_OVP_FLAG - 
   
  // VBAT_OVP_FLAG - 
   
  // IBUS_OCP_FLAG - 
   
  // IBAT_OCP_FLAG - 
   
  // CONV_OCP_FLAG - 
   
  // VAC2_OVP_FLAG - 
   
  // VAC1_OVP_FLAG - 
   
  // VSYS_SHORT_FLAG - 
   
  // VSYS_OVP_FLAG - 
   
  // OTG_OVP_FLAG - 
   
  // OTG_UVP_FLAG - 
   
  // TSHUT_FLAG - 
   
  // ADC_EN - 
   
  // ADC_RATE - 
   
  if (this->text_sensor_adc_rate_ != nullptr) {   
    this->text_sensor_adc_rate_->publish_state(this->parent_->get_adc_rate_string(true));   
  }   
   
  // ADC_SAMPLE - 
   
  if (this->text_sensor_adc_sample_ != nullptr) {   
    this->text_sensor_adc_sample_->publish_state(this->parent_->get_adc_sample_string(true));   
  }   
   
  // ADC_AVG - 
   
  if (this->text_sensor_adc_avg_ != nullptr) {   
    this->text_sensor_adc_avg_->publish_state(this->parent_->get_adc_avg_string(true));   
  }   
   
  // ADC_AVG_INIT - 
   
  // IBUS_ADC_DIS - 
   
  // IBAT_ADC_DIS - 
   
  // VBUS_ADC_DIS - 
   
  // VBAT_ADC_DIS - 
   
  // VSYS_ADC_DIS - 
   
  // TS_ADC_DIS - 
   
  // TDIE_ADC_DIS - 
   
  // DPLUS_ADC_DIS - 
   
  // DMINUS_ADC_DIS - 
   
  // VAC2_ADC_DIS - 
   
  // VAC1_ADC_DIS - 
   
  // IBUS_ADC - 
   
  // IBAT_ADC - 
   
  // VBUS_ADC - 
   
  // VAC1_ADC - 
   
  // VAC2_ADC - 
   
  // VBAT_ADC - 
   
  // VSYS_ADC - 
   
  // TS_ADC - 
   
  // TDIE_ADC - TDIE ADC reading
   
  // DPLUS_ADC - D+ ADC reading
   
  // DMINUS_ADC - D- ADC reading
   
  // DPLUS_DAC - D+ Output Driver
   
  if (this->text_sensor_dplus_dac_ != nullptr) {   
    this->text_sensor_dplus_dac_->publish_state(this->parent_->get_dplus_dac_string(true));   
  }   
   
  // DMINUS_DAC - D- Output Driver
   
  if (this->text_sensor_dminus_dac_ != nullptr) {   
    this->text_sensor_dminus_dac_->publish_state(this->parent_->get_dminus_dac_string(true));   
  }   
   
  // PN - 
   
  if (this->text_sensor_pn_ != nullptr) {   
    this->text_sensor_pn_->publish_state(this->parent_->get_pn_string(true));   
  }   
   
  // DEV_REV - 
   
  if (this->text_sensor_dev_rev_ != nullptr) {   
    this->text_sensor_dev_rev_->publish_state(this->parent_->get_dev_rev_string(true));   
  }   
   
}


void BQ25798TextSensor::assign_text_sensor_vbat_lowv(text_sensor::TextSensor *sensor) {
  this->text_sensor_vbat_lowv_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_cell(text_sensor::TextSensor *sensor) {
  this->text_sensor_cell_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_trechg(text_sensor::TextSensor *sensor) {
  this->text_sensor_trechg_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_prechg_tmr(text_sensor::TextSensor *sensor) {
  this->text_sensor_prechg_tmr_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_topoff_tmr(text_sensor::TextSensor *sensor) {
  this->text_sensor_topoff_tmr_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_chg_tmr(text_sensor::TextSensor *sensor) {
  this->text_sensor_chg_tmr_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vbus_backup(text_sensor::TextSensor *sensor) {
  this->text_sensor_vbus_backup_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vac_ovp(text_sensor::TextSensor *sensor) {
  this->text_sensor_vac_ovp_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_watchdog(text_sensor::TextSensor *sensor) {
  this->text_sensor_watchdog_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_sdrv_ctrl(text_sensor::TextSensor *sensor) {
  this->text_sensor_sdrv_ctrl_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_sdrv_dly(text_sensor::TextSensor *sensor) {
  this->text_sensor_sdrv_dly_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_wkup_dly(text_sensor::TextSensor *sensor) {
  this->text_sensor_wkup_dly_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_pwm_freq(text_sensor::TextSensor *sensor) {
  this->text_sensor_pwm_freq_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ibat_reg(text_sensor::TextSensor *sensor) {
  this->text_sensor_ibat_reg_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_voc_pct(text_sensor::TextSensor *sensor) {
  this->text_sensor_voc_pct_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_voc_dly(text_sensor::TextSensor *sensor) {
  this->text_sensor_voc_dly_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_voc_rate(text_sensor::TextSensor *sensor) {
  this->text_sensor_voc_rate_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_treg(text_sensor::TextSensor *sensor) {
  this->text_sensor_treg_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_tshut(text_sensor::TextSensor *sensor) {
  this->text_sensor_tshut_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_bkup_acfet1_on(text_sensor::TextSensor *sensor) {
  this->text_sensor_bkup_acfet1_on_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_jeita_vset(text_sensor::TextSensor *sensor) {
  this->text_sensor_jeita_vset_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_jeita_iseth(text_sensor::TextSensor *sensor) {
  this->text_sensor_jeita_iseth_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_jeita_isetc(text_sensor::TextSensor *sensor) {
  this->text_sensor_jeita_isetc_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ts_cool(text_sensor::TextSensor *sensor) {
  this->text_sensor_ts_cool_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ts_warm(text_sensor::TextSensor *sensor) {
  this->text_sensor_ts_warm_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_bhot(text_sensor::TextSensor *sensor) {
  this->text_sensor_bhot_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_bcold(text_sensor::TextSensor *sensor) {
  this->text_sensor_bcold_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_iindpm_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_iindpm_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vindpm_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_vindpm_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_wd_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_wd_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_pg_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_pg_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ac2_present_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_ac2_present_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ac1_present_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_ac1_present_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vbus_present_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_vbus_present_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_chg_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_chg_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vbus_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_vbus_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ico_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_ico_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_treg_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_treg_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_dpdm_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_dpdm_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vbat_present_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_vbat_present_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_acrb2_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_acrb2_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_acrb1_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_acrb1_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vsys_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_vsys_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_chg_tmr_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_chg_tmr_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_trichg_tmr_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_trichg_tmr_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_prechg_tmr_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_prechg_tmr_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vbatotg_low_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_vbatotg_low_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ts_cold_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_ts_cold_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ts_cool_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_ts_cool_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ts_warm_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_ts_warm_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ts_hot_stat(text_sensor::TextSensor *sensor) {
  this->text_sensor_ts_hot_stat_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_adc_rate(text_sensor::TextSensor *sensor) {
  this->text_sensor_adc_rate_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_adc_sample(text_sensor::TextSensor *sensor) {
  this->text_sensor_adc_sample_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_adc_avg(text_sensor::TextSensor *sensor) {
  this->text_sensor_adc_avg_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_dplus_dac(text_sensor::TextSensor *sensor) {
  this->text_sensor_dplus_dac_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_dminus_dac(text_sensor::TextSensor *sensor) {
  this->text_sensor_dminus_dac_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_pn(text_sensor::TextSensor *sensor) {
  this->text_sensor_pn_ = sensor;
}
void BQ25798TextSensor::assign_text_sensor_dev_rev(text_sensor::TextSensor *sensor) {
  this->text_sensor_dev_rev_ = sensor;
}

}  // namespace bq25798
}  // namespace esphome