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
  LOG_TEXT_SENSOR("  ", "all_flags", this->text_sensor_all_flags_);

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
    this->text_sensor_vbat_lowv_->publish_state(this->parent_->get_vbat_lowv_enum_string());   
  }   
   
  // IPRECHG - Precharge Current Limit
   
  // REG_RST - Reset registers to default values and reset timer
   
  // STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
   
  // ITERM - Termination Current Limit
   
  // CELL - Battery cell count
  if (this->text_sensor_cell_ != nullptr) {   
    this->text_sensor_cell_->publish_state(this->parent_->get_cell_enum_string());   
  }   
   
  // TRECHG - Battery recharge delay time
  if (this->text_sensor_trechg_ != nullptr) {   
    this->text_sensor_trechg_->publish_state(this->parent_->get_trechg_enum_string());   
  }   
   
  // VRECHG - Battery Recharge Threshold Offset (Below VREG)
   
  // VOTG - OTG mode regulation voltage
   
  // PRECHG_TMR - Pre-charge safety timer setting
  if (this->text_sensor_prechg_tmr_ != nullptr) {   
    this->text_sensor_prechg_tmr_->publish_state(this->parent_->get_prechg_tmr_enum_string());   
  }   
   
  // IOTG - OTG current limit
   
  // TOPOFF_TMR - Top-off timer control
  if (this->text_sensor_topoff_tmr_ != nullptr) {   
    this->text_sensor_topoff_tmr_->publish_state(this->parent_->get_topoff_tmr_enum_string());   
  }   
   
  // EN_TRICHG_TMR - Trickle charge timer enable
   
  // EN_PRECHG_TMR - Precharge timer enable
   
  // EN_CHG_TMR - Fast charge timer enable
   
  // CHG_TMR - Fast charge timer setting
  if (this->text_sensor_chg_tmr_ != nullptr) {   
    this->text_sensor_chg_tmr_->publish_state(this->parent_->get_chg_tmr_enum_string());   
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
    this->text_sensor_vbus_backup_->publish_state(this->parent_->get_vbus_backup_enum_string());   
  }   
   
  // VAC_OVP - Over voltage protection thresholds
  if (this->text_sensor_vac_ovp_ != nullptr) {   
    this->text_sensor_vac_ovp_->publish_state(this->parent_->get_vac_ovp_enum_string());   
  }   
   
  // WD_RST - I2C watch dog timer reset
   
  // WATCHDOG - Watchdog timer settings
  if (this->text_sensor_watchdog_ != nullptr) {   
    this->text_sensor_watchdog_->publish_state(this->parent_->get_watchdog_enum_string());   
  }   
   
  // FORCE_INDET - Force D+/D- detection
   
  // AUTO_INDET_EN - Enable automatic D+/D- detection
   
  // EN_12V - Enable 12V output in HVDCP
   
  // EN_9V - Enable 9V output in HVDCP
   
  // HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
   
  // SDRV_CTRL - Enable external Ship FET control
  if (this->text_sensor_sdrv_ctrl_ != nullptr) {   
    this->text_sensor_sdrv_ctrl_->publish_state(this->parent_->get_sdrv_ctrl_enum_string());   
  }   
   
  // SDRV_DLY - Delay for SDRV control
  if (this->text_sensor_sdrv_dly_ != nullptr) {   
    this->text_sensor_sdrv_dly_->publish_state(this->parent_->get_sdrv_dly_enum_string());   
  }   
   
  // DIS_ACDRV - Disable both AC1 and AC2 drivers
   
  // EN_OTG - Enable OTG mode
   
  // PFM_OTG_DIS - Disable PFM in OTG mode
   
  // PFM_FWD_DIS - Disable PFM in forward mode
   
  // WKUP_DLY - Wakeup (Ship FET) delay
  if (this->text_sensor_wkup_dly_ != nullptr) {   
    this->text_sensor_wkup_dly_->publish_state(this->parent_->get_wkup_dly_enum_string());   
  }   
   
  // DIS_LDO - Disable BATFET LDO mode in precharge state
   
  // DIS_OTG_OOA - Disable OOA in OTG mode
   
  // DIS_FWD_OOA - Disable OOA in forward mode
   
  // EN_ACDRV2 - Enable AC2 gate driver control
   
  // EN_ACDRV1 - Enable AC1 gate driver control
   
  // PWM_FREQ - PWM frequency setting
  if (this->text_sensor_pwm_freq_ != nullptr) {   
    this->text_sensor_pwm_freq_->publish_state(this->parent_->get_pwm_freq_enum_string());   
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
    this->text_sensor_ibat_reg_->publish_state(this->parent_->get_ibat_reg_enum_string());   
  }   
   
  // EN_IINDPM - Enable input current regulation
   
  // EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
   
  // EN_BATOC - Enable battery discharging over current protection
   
  // VOC_PCT - Set VINDPM as a percentage of the VBUS open circuit voltage when the VOC measurement is done
  if (this->text_sensor_voc_pct_ != nullptr) {   
    this->text_sensor_voc_pct_->publish_state(this->parent_->get_voc_pct_enum_string());   
  }   
   
  // VOC_DLY - After the converter stops switching, the time delay before the VOC is measured
  if (this->text_sensor_voc_dly_ != nullptr) {   
    this->text_sensor_voc_dly_->publish_state(this->parent_->get_voc_dly_enum_string());   
  }   
   
  // VOC_RATE - The time interval between two consecutive VOC measurements
  if (this->text_sensor_voc_rate_ != nullptr) {   
    this->text_sensor_voc_rate_->publish_state(this->parent_->get_voc_rate_enum_string());   
  }   
   
  // EN_MPPT - Enable MPPT (Maximum Power Point Tracking)
   
  // TREG - Thermal regulation thresholds
  if (this->text_sensor_treg_ != nullptr) {   
    this->text_sensor_treg_->publish_state(this->parent_->get_treg_enum_string());   
  }   
   
  // TSHUT - Thermal shutdown thresholds
  if (this->text_sensor_tshut_ != nullptr) {   
    this->text_sensor_tshut_->publish_state(this->parent_->get_tshut_enum_string());   
  }   
   
  // VBUS_PD_EN - Enable VBUS pull down resistor (6 kOhm)
   
  // VAC1_PD_EN - Enable VAC1 pull down resistor
   
  // VAC2_PD_EN - Enable VAC2 pull down resistor
   
  // BKUP_ACFET1_ON - Enable ACFET1 in backup mode (exit backup mode)
  if (this->text_sensor_bkup_acfet1_on_ != nullptr) {   
    this->text_sensor_bkup_acfet1_on_->publish_state(this->parent_->get_bkup_acfet1_on_enum_string());   
  }   
   
  // JEITA_VSET - JEITA high temperature range (TWARN - THOT) charge voltage setting
  if (this->text_sensor_jeita_vset_ != nullptr) {   
    this->text_sensor_jeita_vset_->publish_state(this->parent_->get_jeita_vset_enum_string());   
  }   
   
  // JEITA_ISETH - JEITA high temperature range (TWARN - THOT) charge current setting
  if (this->text_sensor_jeita_iseth_ != nullptr) {   
    this->text_sensor_jeita_iseth_->publish_state(this->parent_->get_jeita_iseth_enum_string());   
  }   
   
  // JEITA_ISETC - JEITA low temperature range (TCOLD - TWARN) charge current setting
  if (this->text_sensor_jeita_isetc_ != nullptr) {   
    this->text_sensor_jeita_isetc_->publish_state(this->parent_->get_jeita_isetc_enum_string());   
  }   
   
  // TS_COOL - JEITA VT2 comparator voltage rising thresholds as a percentage of REGN.
  if (this->text_sensor_ts_cool_ != nullptr) {   
    this->text_sensor_ts_cool_->publish_state(this->parent_->get_ts_cool_enum_string());   
  }   
   
  // TS_WARM - JEITA VT3 comparator voltage falling thresholds as a percentage of REGN.
  if (this->text_sensor_ts_warm_ != nullptr) {   
    this->text_sensor_ts_warm_->publish_state(this->parent_->get_ts_warm_enum_string());   
  }   
   
  // BHOT - OTG mode TS HOT temperature threshold
  if (this->text_sensor_bhot_ != nullptr) {   
    this->text_sensor_bhot_->publish_state(this->parent_->get_bhot_enum_string());   
  }   
   
  // BCOLD - OTG mode TS COLD temperature threshold
  if (this->text_sensor_bcold_ != nullptr) {   
    this->text_sensor_bcold_->publish_state(this->parent_->get_bcold_enum_string());   
  }   
   
  // TS_IGNORE - Ignore TS detection (the charger considers the TS is always good)
   
  // ICO_ILIM - Input Current Limit obtained from ICO or ILIM_HIZ pin setting
   
  // IINDPM_STAT - IINDPM status (forward mode) or IOTG status (OTG mode)
  if (this->text_sensor_iindpm_stat_ != nullptr) {   
    this->text_sensor_iindpm_stat_->publish_state(this->parent_->get_iindpm_stat_enum_string());   
  }   
   
  // VINDPM_STAT - VINDPM status (forward mode) or VOTG status (OTG mode)
  if (this->text_sensor_vindpm_stat_ != nullptr) {   
    this->text_sensor_vindpm_stat_->publish_state(this->parent_->get_vindpm_stat_enum_string());   
  }   
   
  // WD_STAT - Watchdog timer status
  if (this->text_sensor_wd_stat_ != nullptr) {   
    this->text_sensor_wd_stat_->publish_state(this->parent_->get_wd_stat_enum_string());   
  }   
   
  // PG_STAT - Power good status
  if (this->text_sensor_pg_stat_ != nullptr) {   
    this->text_sensor_pg_stat_->publish_state(this->parent_->get_pg_stat_enum_string());   
  }   
   
  // AC2_PRESENT_STAT - VAC2 present status
  if (this->text_sensor_ac2_present_stat_ != nullptr) {   
    this->text_sensor_ac2_present_stat_->publish_state(this->parent_->get_ac2_present_stat_enum_string());   
  }   
   
  // AC1_PRESENT_STAT - VAC1 present status
  if (this->text_sensor_ac1_present_stat_ != nullptr) {   
    this->text_sensor_ac1_present_stat_->publish_state(this->parent_->get_ac1_present_stat_enum_string());   
  }   
   
  // VBUS_PRESENT_STAT - VBUS present status
  if (this->text_sensor_vbus_present_stat_ != nullptr) {   
    this->text_sensor_vbus_present_stat_->publish_state(this->parent_->get_vbus_present_stat_enum_string());   
  }   
   
  // CHG_STAT - Charge Status bits
  if (this->text_sensor_chg_stat_ != nullptr) {   
    this->text_sensor_chg_stat_->publish_state(this->parent_->get_chg_stat_enum_string());   
  }   
   
  // VBUS_STAT - VBUS status bits
  if (this->text_sensor_vbus_stat_ != nullptr) {   
    this->text_sensor_vbus_stat_->publish_state(this->parent_->get_vbus_stat_enum_string());   
  }   
   
  // BC12_DONE_STAT - BC1.2 detection done status
   
  // ICO_STAT - Input Current Optimizer (ICO) status
  if (this->text_sensor_ico_stat_ != nullptr) {   
    this->text_sensor_ico_stat_->publish_state(this->parent_->get_ico_stat_enum_string());   
  }   
   
  // TREG_STAT - IC thermal regulation status
  if (this->text_sensor_treg_stat_ != nullptr) {   
    this->text_sensor_treg_stat_->publish_state(this->parent_->get_treg_stat_enum_string());   
  }   
   
  // DPDM_STAT - D+/D- detection status
  if (this->text_sensor_dpdm_stat_ != nullptr) {   
    this->text_sensor_dpdm_stat_->publish_state(this->parent_->get_dpdm_stat_enum_string());   
  }   
   
  // VBAT_PRESENT_STAT - Battery present status
  if (this->text_sensor_vbat_present_stat_ != nullptr) {   
    this->text_sensor_vbat_present_stat_->publish_state(this->parent_->get_vbat_present_stat_enum_string());   
  }   
   
  // ACRB2_STAT - The ACFET2-RBFET2 status
  if (this->text_sensor_acrb2_stat_ != nullptr) {   
    this->text_sensor_acrb2_stat_->publish_state(this->parent_->get_acrb2_stat_enum_string());   
  }   
   
  // ACRB1_STAT - The ACFET1-RBFET1 status
  if (this->text_sensor_acrb1_stat_ != nullptr) {   
    this->text_sensor_acrb1_stat_->publish_state(this->parent_->get_acrb1_stat_enum_string());   
  }   
   
  // ADC_DONE_STAT - ADC Conversion Status
   
  // VSYS_STAT - VSYS Regulation Status
  if (this->text_sensor_vsys_stat_ != nullptr) {   
    this->text_sensor_vsys_stat_->publish_state(this->parent_->get_vsys_stat_enum_string());   
  }   
   
  // CHG_TMR_STAT - Fast charge timer status
  if (this->text_sensor_chg_tmr_stat_ != nullptr) {   
    this->text_sensor_chg_tmr_stat_->publish_state(this->parent_->get_chg_tmr_stat_enum_string());   
  }   
   
  // TRICHG_TMR_STAT - Trickle charge timer status
  if (this->text_sensor_trichg_tmr_stat_ != nullptr) {   
    this->text_sensor_trichg_tmr_stat_->publish_state(this->parent_->get_trichg_tmr_stat_enum_string());   
  }   
   
  // PRECHG_TMR_STAT - Pre-charge timer status
  if (this->text_sensor_prechg_tmr_stat_ != nullptr) {   
    this->text_sensor_prechg_tmr_stat_->publish_state(this->parent_->get_prechg_tmr_stat_enum_string());   
  }   
   
  // VBATOTG_LOW_STAT - The battery voltage is too low to enable OTG mode
  if (this->text_sensor_vbatotg_low_stat_ != nullptr) {   
    this->text_sensor_vbatotg_low_stat_->publish_state(this->parent_->get_vbatotg_low_stat_enum_string());   
  }   
   
  // TS_COLD_STAT - The TS temperature is in the cold range
  if (this->text_sensor_ts_cold_stat_ != nullptr) {   
    this->text_sensor_ts_cold_stat_->publish_state(this->parent_->get_ts_cold_stat_enum_string());   
  }   
   
  // TS_COOL_STAT - The TS temperature is in the cool range
  if (this->text_sensor_ts_cool_stat_ != nullptr) {   
    this->text_sensor_ts_cool_stat_->publish_state(this->parent_->get_ts_cool_stat_enum_string());   
  }   
   
  // TS_WARM_STAT - The TS temperature is in the warm range
  if (this->text_sensor_ts_warm_stat_ != nullptr) {   
    this->text_sensor_ts_warm_stat_->publish_state(this->parent_->get_ts_warm_stat_enum_string());   
  }   
   
  // TS_HOT_STAT - The TS temperature is in the hot range
  if (this->text_sensor_ts_hot_stat_ != nullptr) {   
    this->text_sensor_ts_hot_stat_->publish_state(this->parent_->get_ts_hot_stat_enum_string());   
  }   
   
  // IBAT_REG_STAT - In battery discharging current regulation
   
  // VBUS_OVP_STAT - VBUS over-voltage status
   
  // VBAT_OVP_STAT - VBAT over-voltage status
   
  // IBUS_OCP_STAT - IBUS over-current status
   
  // IBAT_OCP_STAT - IBAT over-current status
   
  // CONV_OCP_STAT - Converter over-current status
   
  // VAC2_OVP_STAT - VAC2 over-voltage status
   
  // VAC1_OVP_STAT - VAC1 over-voltage status
   
  // VSYS_SHORT_STAT - VSYS short circuit status
   
  // VSYS_OVP_STAT - VSYS over-voltage status
   
  // OTG_OVP_STAT - OTG over-voltage status
   
  // OTG_UVP_STAT - OTG under-voltage status
   
  // TSHUT_STAT - IC thermal shutdown status
   
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
   
  // TREG_FLAG - TREG signal rising threshold detected
   
  // VBAT_PRESENT_FLAG - Battery present status changed
   
  // BC1_2_DONE_FLAG - BC1.2 detection status changed
   
  // DPDM_DONE_FLAG - D+/D- detection is completed
   
  // ADC_DONE_FLAG - ADC conversion is completed
   
  // VSYS_FLAG - Entered or existed VSYSMIN regulation
   
  // CHG_TMR_FLAG - Fast charge timer expired rising edge detected
   
  // TRICHG_TMR_FLAG - Trickle charge timer expired rising edge detected
   
  // PRECHG_TMR_FLAG - Pre-charge timer expired rising edge detected
   
  // TOPOFF_TMR_FLAG - Top-off timer expired rising edge detected
   
  // VBATOTG_LOW_FLAG - VBAT falls below the threshold to enable the OTG mode
   
  // TS_COLD_FLAG - TS across cold temperature (T1) is detected
   
  // TS_COOL_FLAG - TS across cool temperature (T2) is detected
   
  // TS_WARM_FLAG - TS across warm temperature (T3) is detected
   
  // TS_HOT_FLAG - TS across hot temperature (T5) is detected
   
  // IBAT_REG_FLAG - Enter or exit IBAT regulation
   
  // VBUS_OVP_FLAG - Enter VBUS OVP
   
  // VBAT_OVP_FLAG - Enter VBAT OVP
   
  // IBUS_OCP_FLAG - Enter IBUS OCP
   
  // IBAT_OCP_FLAG - Enter discharged OCP
   
  // CONV_OCP_FLAG - Enter converter OCP
   
  // VAC2_OVP_FLAG - Enter VAC2 OVP
   
  // VAC1_OVP_FLAG - Enter VAC1 OVP
   
  // VSYS_SHORT_FLAG - Stop switching due to system short
   
  // VSYS_OVP_FLAG - Stop switching due to system over-voltage
   
  // OTG_OVP_FLAG - Stop OTG due to VBUS over voltage
   
  // OTG_UVP_FLAG - Stop OTG due to VBUS under voltage
   
  // TSHUT_FLAG - TS shutdown signal rising threshold detected
   
  // ADC_EN - ADC enable
   
  // ADC_RATE - ADC conversion rate
  if (this->text_sensor_adc_rate_ != nullptr) {   
    this->text_sensor_adc_rate_->publish_state(this->parent_->get_adc_rate_enum_string());   
  }   
   
  // ADC_SAMPLE - ADC sample speed
  if (this->text_sensor_adc_sample_ != nullptr) {   
    this->text_sensor_adc_sample_->publish_state(this->parent_->get_adc_sample_enum_string());   
  }   
   
  // ADC_AVG - ADC averaging
  if (this->text_sensor_adc_avg_ != nullptr) {   
    this->text_sensor_adc_avg_->publish_state(this->parent_->get_adc_avg_enum_string());   
  }   
   
  // ADC_AVG_INIT - ADC average initialization
   
  // IBUS_ADC_DIS - IBUS ADC disable
   
  // IBAT_ADC_DIS - IBAT ADC disable
   
  // VBUS_ADC_DIS - VBUS ADC disable
   
  // VBAT_ADC_DIS - VBAT ADC disable
   
  // VSYS_ADC_DIS - VSYS ADC disable
   
  // TS_ADC_DIS - TS ADC disable
   
  // TDIE_ADC_DIS - TDIE ADC disable
   
  // DPLUS_ADC_DIS - D+ ADC disable
   
  // DMINUS_ADC_DIS - D- ADC disable
   
  // VAC2_ADC_DIS - VAC2 ADC disable
   
  // VAC1_ADC_DIS - VAC1 ADC disable
   
  // IBUS_ADC - IBUS ADC reading
   
  // IBAT_ADC - IBAT ADC reading
   
  // VBUS_ADC - VBUS ADC reading
   
  // VAC1_ADC - VAC1 ADC reading
   
  // VAC2_ADC - VAC2 ADC reading
   
  // VBAT_ADC - VBAT ADC reading
   
  // VSYS_ADC - VSYS ADC reading
   
  // TS_ADC - TS ADC reading
   
  // TDIE_ADC - TDIE ADC reading
   
  // DPLUS_ADC - D+ ADC reading
   
  // DMINUS_ADC - D- ADC reading
   
  // DPLUS_DAC - D+ Output Driver
  if (this->text_sensor_dplus_dac_ != nullptr) {   
    this->text_sensor_dplus_dac_->publish_state(this->parent_->get_dplus_dac_enum_string());   
  }   
   
  // DMINUS_DAC - D- Output Driver
  if (this->text_sensor_dminus_dac_ != nullptr) {   
    this->text_sensor_dminus_dac_->publish_state(this->parent_->get_dminus_dac_enum_string());   
  }   
   
  // PN - Part number
  if (this->text_sensor_pn_ != nullptr) {   
    this->text_sensor_pn_->publish_state(this->parent_->get_pn_enum_string());   
  }   
   
  // DEV_REV - Device revision
  if (this->text_sensor_dev_rev_ != nullptr) {   
    this->text_sensor_dev_rev_->publish_state(this->parent_->get_dev_rev_enum_string());   
  }   
   
  if (this->text_sensor_all_flags_ != nullptr) {
    this->text_sensor_all_flags_->publish_state(this->get_all_flags_string());
  }
}

std::string BQ25798TextSensor::get_all_flags_string() {
  std::string ret;
  if (this->parent_->get_iindpm_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "IINDPM";
  }
  if (this->parent_->get_vindpm_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "VINDPM";
  }
  if (this->parent_->get_wd_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "WD";
  }
  if (this->parent_->get_poorsrc_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "POORSRC";
  }
  if (this->parent_->get_pg_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "PG";
  }
  if (this->parent_->get_ac2_present_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "AC2_PRESENT";
  }
  if (this->parent_->get_ac1_present_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "AC1_PRESENT";
  }
  if (this->parent_->get_vbus_present_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "VBUS_PRESENT";
  }
  if (this->parent_->get_chg_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "CHG";
  }
  if (this->parent_->get_ico_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "ICO";
  }
  if (this->parent_->get_vbus_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "VBUS";
  }
  if (this->parent_->get_treg_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "TREG";
  }
  if (this->parent_->get_vbat_present_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "VBAT_PRESENT";
  }
  if (this->parent_->get_bc1_2_done_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "BC1_2_DONE";
  }
  if (this->parent_->get_dpdm_done_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "DPDM_DONE";
  }
  if (this->parent_->get_adc_done_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "ADC_DONE";
  }
  if (this->parent_->get_vsys_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "VSYS";
  }
  if (this->parent_->get_chg_tmr_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "CHG_TMR";
  }
  if (this->parent_->get_trichg_tmr_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "TRICHG_TMR";
  }
  if (this->parent_->get_prechg_tmr_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "PRECHG_TMR";
  }
  if (this->parent_->get_topoff_tmr_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "TOPOFF_TMR";
  }
  if (this->parent_->get_vbatotg_low_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "VBATOTG_LOW";
  }
  if (this->parent_->get_ts_cold_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "TS_COLD";
  }
  if (this->parent_->get_ts_cool_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "TS_COOL";
  }
  if (this->parent_->get_ts_warm_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "TS_WARM";
  }
  if (this->parent_->get_ts_hot_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "TS_HOT";
  }
  if (this->parent_->get_ibat_reg_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "IBAT_REG";
  }
  if (this->parent_->get_vbus_ovp_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "VBUS_OVP";
  }
  if (this->parent_->get_vbat_ovp_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "VBAT_OVP";
  }
  if (this->parent_->get_ibus_ocp_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "IBUS_OCP";
  }
  if (this->parent_->get_ibat_ocp_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "IBAT_OCP";
  }
  if (this->parent_->get_conv_ocp_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "CONV_OCP";
  }
  if (this->parent_->get_vac2_ovp_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "VAC2_OVP";
  }
  if (this->parent_->get_vac1_ovp_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "VAC1_OVP";
  }
  if (this->parent_->get_vsys_short_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "VSYS_SHORT";
  }
  if (this->parent_->get_vsys_ovp_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "VSYS_OVP";
  }
  if (this->parent_->get_otg_ovp_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "OTG_OVP";
  }
  if (this->parent_->get_otg_uvp_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "OTG_UVP";
  }
  if (this->parent_->get_tshut_flag_flag()) {
    if (!ret.empty()) {
      ret += ", ";
    }
    ret += "TSHUT";
  }
  return ret;
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
void BQ25798TextSensor::assign_text_sensor_all_flags(text_sensor::TextSensor *sensor) {
  this->text_sensor_all_flags_ = sensor;
}
}  // namespace bq25798
}  // namespace esphome