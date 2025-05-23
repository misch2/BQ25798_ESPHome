#include "bq25798_sensor.h"

#include "esphome/core/log.h"

namespace esphome {
namespace bq25798 {

static const char* const TAG = "bq25798.sensor";

float BQ25798Sensor::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798Sensor::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798Sensor configuration...");
  if (this->parent_->is_failed()) {
    return;
  }

  if (this->sensor_vsysmin_ != nullptr) {
    LOG_SENSOR("  ", "VSYSMIN", this->sensor_vsysmin_);
  }
  if (this->sensor_vreg_ != nullptr) {
    LOG_SENSOR("  ", "VREG", this->sensor_vreg_);
  }
  if (this->sensor_ichg_ != nullptr) {
    LOG_SENSOR("  ", "ICHG", this->sensor_ichg_);
  }
  if (this->sensor_vindpm_ != nullptr) {
    LOG_SENSOR("  ", "VINDPM", this->sensor_vindpm_);
  }
  if (this->sensor_iindpm_ != nullptr) {
    LOG_SENSOR("  ", "IINDPM", this->sensor_iindpm_);
  }
  if (this->sensor_vbat_lowv_ != nullptr) {
    LOG_SENSOR("  ", "VBAT_LOWV", this->sensor_vbat_lowv_);
  }
  if (this->sensor_iprechg_ != nullptr) {
    LOG_SENSOR("  ", "IPRECHG", this->sensor_iprechg_);
  }
  if (this->sensor_iterm_ != nullptr) {
    LOG_SENSOR("  ", "ITERM", this->sensor_iterm_);
  }
  if (this->sensor_cell_ != nullptr) {
    LOG_SENSOR("  ", "CELL", this->sensor_cell_);
  }
  if (this->sensor_trechg_ != nullptr) {
    LOG_SENSOR("  ", "TRECHG", this->sensor_trechg_);
  }
  if (this->sensor_vrechg_ != nullptr) {
    LOG_SENSOR("  ", "VRECHG", this->sensor_vrechg_);
  }
  if (this->sensor_votg_ != nullptr) {
    LOG_SENSOR("  ", "VOTG", this->sensor_votg_);
  }
  if (this->sensor_prechg_tmr_ != nullptr) {
    LOG_SENSOR("  ", "PRECHG_TMR", this->sensor_prechg_tmr_);
  }
  if (this->sensor_iotg_ != nullptr) {
    LOG_SENSOR("  ", "IOTG", this->sensor_iotg_);
  }
  if (this->sensor_topoff_tmr_ != nullptr) {
    LOG_SENSOR("  ", "TOPOFF_TMR", this->sensor_topoff_tmr_);
  }
  if (this->sensor_chg_tmr_ != nullptr) {
    LOG_SENSOR("  ", "CHG_TMR", this->sensor_chg_tmr_);
  }
  if (this->sensor_vbus_backup_ != nullptr) {
    LOG_SENSOR("  ", "VBUS_BACKUP", this->sensor_vbus_backup_);
  }
  if (this->sensor_vac_ovp_ != nullptr) {
    LOG_SENSOR("  ", "VAC_OVP", this->sensor_vac_ovp_);
  }
  if (this->sensor_watchdog_ != nullptr) {
    LOG_SENSOR("  ", "WATCHDOG", this->sensor_watchdog_);
  }
  if (this->sensor_sdrv_ctrl_ != nullptr) {
    LOG_SENSOR("  ", "SDRV_CTRL", this->sensor_sdrv_ctrl_);
  }
  if (this->sensor_sdrv_dly_ != nullptr) {
    LOG_SENSOR("  ", "SDRV_DLY", this->sensor_sdrv_dly_);
  }
  if (this->sensor_wkup_dly_ != nullptr) {
    LOG_SENSOR("  ", "WKUP_DLY", this->sensor_wkup_dly_);
  }
  if (this->sensor_pwm_freq_ != nullptr) {
    LOG_SENSOR("  ", "PWM_FREQ", this->sensor_pwm_freq_);
  }
  if (this->sensor_ibat_reg_ != nullptr) {
    LOG_SENSOR("  ", "IBAT_REG", this->sensor_ibat_reg_);
  }
  if (this->sensor_voc_pct_ != nullptr) {
    LOG_SENSOR("  ", "VOC_PCT", this->sensor_voc_pct_);
  }
  if (this->sensor_voc_dly_ != nullptr) {
    LOG_SENSOR("  ", "VOC_DLY", this->sensor_voc_dly_);
  }
  if (this->sensor_voc_rate_ != nullptr) {
    LOG_SENSOR("  ", "VOC_RATE", this->sensor_voc_rate_);
  }
  if (this->sensor_treg_ != nullptr) {
    LOG_SENSOR("  ", "TREG", this->sensor_treg_);
  }
  if (this->sensor_tshut_ != nullptr) {
    LOG_SENSOR("  ", "TSHUT", this->sensor_tshut_);
  }
  if (this->sensor_bkup_acfet1_on_ != nullptr) {
    LOG_SENSOR("  ", "BKUP_ACFET1_ON", this->sensor_bkup_acfet1_on_);
  }
  if (this->sensor_jeita_vset_ != nullptr) {
    LOG_SENSOR("  ", "JEITA_VSET", this->sensor_jeita_vset_);
  }
  if (this->sensor_jeita_iseth_ != nullptr) {
    LOG_SENSOR("  ", "JEITA_ISETH", this->sensor_jeita_iseth_);
  }
  if (this->sensor_jeita_isetc_ != nullptr) {
    LOG_SENSOR("  ", "JEITA_ISETC", this->sensor_jeita_isetc_);
  }
  if (this->sensor_ts_cool_ != nullptr) {
    LOG_SENSOR("  ", "TS_COOL", this->sensor_ts_cool_);
  }
  if (this->sensor_ts_warm_ != nullptr) {
    LOG_SENSOR("  ", "TS_WARM", this->sensor_ts_warm_);
  }
  if (this->sensor_bhot_ != nullptr) {
    LOG_SENSOR("  ", "BHOT", this->sensor_bhot_);
  }
  if (this->sensor_bcold_ != nullptr) {
    LOG_SENSOR("  ", "BCOLD", this->sensor_bcold_);
  }
  if (this->sensor_ico_ilim_ != nullptr) {
    LOG_SENSOR("  ", "ICO_ILIM", this->sensor_ico_ilim_);
  }
  if (this->sensor_iindpm_stat_ != nullptr) {
    LOG_SENSOR("  ", "IINDPM_STAT", this->sensor_iindpm_stat_);
  }
  if (this->sensor_vindpm_stat_ != nullptr) {
    LOG_SENSOR("  ", "VINDPM_STAT", this->sensor_vindpm_stat_);
  }
  if (this->sensor_wd_stat_ != nullptr) {
    LOG_SENSOR("  ", "WD_STAT", this->sensor_wd_stat_);
  }
  if (this->sensor_pg_stat_ != nullptr) {
    LOG_SENSOR("  ", "PG_STAT", this->sensor_pg_stat_);
  }
  if (this->sensor_ac2_present_stat_ != nullptr) {
    LOG_SENSOR("  ", "AC2_PRESENT_STAT", this->sensor_ac2_present_stat_);
  }
  if (this->sensor_ac1_present_stat_ != nullptr) {
    LOG_SENSOR("  ", "AC1_PRESENT_STAT", this->sensor_ac1_present_stat_);
  }
  if (this->sensor_vbus_present_stat_ != nullptr) {
    LOG_SENSOR("  ", "VBUS_PRESENT_STAT", this->sensor_vbus_present_stat_);
  }
  if (this->sensor_chg_stat_ != nullptr) {
    LOG_SENSOR("  ", "CHG_STAT", this->sensor_chg_stat_);
  }
  if (this->sensor_vbus_stat_ != nullptr) {
    LOG_SENSOR("  ", "VBUS_STAT", this->sensor_vbus_stat_);
  }
  if (this->sensor_ico_stat_ != nullptr) {
    LOG_SENSOR("  ", "ICO_STAT", this->sensor_ico_stat_);
  }
  if (this->sensor_treg_stat_ != nullptr) {
    LOG_SENSOR("  ", "TREG_STAT", this->sensor_treg_stat_);
  }
  if (this->sensor_dpdm_stat_ != nullptr) {
    LOG_SENSOR("  ", "DPDM_STAT", this->sensor_dpdm_stat_);
  }
  if (this->sensor_vbat_present_stat_ != nullptr) {
    LOG_SENSOR("  ", "VBAT_PRESENT_STAT", this->sensor_vbat_present_stat_);
  }
  if (this->sensor_acrb2_stat_ != nullptr) {
    LOG_SENSOR("  ", "ACRB2_STAT", this->sensor_acrb2_stat_);
  }
  if (this->sensor_acrb1_stat_ != nullptr) {
    LOG_SENSOR("  ", "ACRB1_STAT", this->sensor_acrb1_stat_);
  }
  if (this->sensor_vsys_stat_ != nullptr) {
    LOG_SENSOR("  ", "VSYS_STAT", this->sensor_vsys_stat_);
  }
  if (this->sensor_chg_tmr_stat_ != nullptr) {
    LOG_SENSOR("  ", "CHG_TMR_STAT", this->sensor_chg_tmr_stat_);
  }
  if (this->sensor_trichg_tmr_stat_ != nullptr) {
    LOG_SENSOR("  ", "TRICHG_TMR_STAT", this->sensor_trichg_tmr_stat_);
  }
  if (this->sensor_prechg_tmr_stat_ != nullptr) {
    LOG_SENSOR("  ", "PRECHG_TMR_STAT", this->sensor_prechg_tmr_stat_);
  }
  if (this->sensor_vbatotg_low_stat_ != nullptr) {
    LOG_SENSOR("  ", "VBATOTG_LOW_STAT", this->sensor_vbatotg_low_stat_);
  }
  if (this->sensor_ts_cold_stat_ != nullptr) {
    LOG_SENSOR("  ", "TS_COLD_STAT", this->sensor_ts_cold_stat_);
  }
  if (this->sensor_ts_cool_stat_ != nullptr) {
    LOG_SENSOR("  ", "TS_COOL_STAT", this->sensor_ts_cool_stat_);
  }
  if (this->sensor_ts_warm_stat_ != nullptr) {
    LOG_SENSOR("  ", "TS_WARM_STAT", this->sensor_ts_warm_stat_);
  }
  if (this->sensor_ts_hot_stat_ != nullptr) {
    LOG_SENSOR("  ", "TS_HOT_STAT", this->sensor_ts_hot_stat_);
  }
  if (this->sensor_adc_rate_ != nullptr) {
    LOG_SENSOR("  ", "ADC_RATE", this->sensor_adc_rate_);
  }
  if (this->sensor_adc_sample_ != nullptr) {
    LOG_SENSOR("  ", "ADC_SAMPLE", this->sensor_adc_sample_);
  }
  if (this->sensor_adc_avg_ != nullptr) {
    LOG_SENSOR("  ", "ADC_AVG", this->sensor_adc_avg_);
  }
  if (this->sensor_ibus_adc_ != nullptr) {
    LOG_SENSOR("  ", "IBUS_ADC", this->sensor_ibus_adc_);
  }
  if (this->sensor_ibat_adc_ != nullptr) {
    LOG_SENSOR("  ", "IBAT_ADC", this->sensor_ibat_adc_);
  }
  if (this->sensor_vbus_adc_ != nullptr) {
    LOG_SENSOR("  ", "VBUS_ADC", this->sensor_vbus_adc_);
  }
  if (this->sensor_vac1_adc_ != nullptr) {
    LOG_SENSOR("  ", "VAC1_ADC", this->sensor_vac1_adc_);
  }
  if (this->sensor_vac2_adc_ != nullptr) {
    LOG_SENSOR("  ", "VAC2_ADC", this->sensor_vac2_adc_);
  }
  if (this->sensor_vbat_adc_ != nullptr) {
    LOG_SENSOR("  ", "VBAT_ADC", this->sensor_vbat_adc_);
  }
  if (this->sensor_vsys_adc_ != nullptr) {
    LOG_SENSOR("  ", "VSYS_ADC", this->sensor_vsys_adc_);
  }
  if (this->sensor_ts_adc_ != nullptr) {
    LOG_SENSOR("  ", "TS_ADC", this->sensor_ts_adc_);
  }
  if (this->sensor_tdie_adc_ != nullptr) {
    LOG_SENSOR("  ", "TDIE_ADC", this->sensor_tdie_adc_);
  }
  if (this->sensor_dplus_adc_ != nullptr) {
    LOG_SENSOR("  ", "DPLUS_ADC", this->sensor_dplus_adc_);
  }
  if (this->sensor_dminus_adc_ != nullptr) {
    LOG_SENSOR("  ", "DMINUS_ADC", this->sensor_dminus_adc_);
  }
  if (this->sensor_dplus_dac_ != nullptr) {
    LOG_SENSOR("  ", "DPLUS_DAC", this->sensor_dplus_dac_);
  }
  if (this->sensor_dminus_dac_ != nullptr) {
    LOG_SENSOR("  ", "DMINUS_DAC", this->sensor_dminus_dac_);
  }
  if (this->sensor_pn_ != nullptr) {
    LOG_SENSOR("  ", "PN", this->sensor_pn_);
  }
  if (this->sensor_dev_rev_ != nullptr) {
    LOG_SENSOR("  ", "DEV_REV", this->sensor_dev_rev_);
  }

  LOG_UPDATE_INTERVAL(this);
}

void BQ25798Sensor::update() {
  if (this->parent_->is_failed()) {
    return;
  }

  // VSYSMIN - Minimal System Voltage
  if (this->sensor_vsysmin_ != nullptr) {
    this->sensor_vsysmin_->publish_state(this->parent_->get_vsysmin_int(true));
  }
  // VREG - Charge Voltage Limit
  if (this->sensor_vreg_ != nullptr) {
    this->sensor_vreg_->publish_state(this->parent_->get_vreg_int(true));
  }
  // ICHG - Charge Current Limit
  if (this->sensor_ichg_ != nullptr) {
    this->sensor_ichg_->publish_state(this->parent_->get_ichg_int(true));
  }
  // VINDPM - Input Voltage Limit
  if (this->sensor_vindpm_ != nullptr) {
    this->sensor_vindpm_->publish_state(this->parent_->get_vindpm_int(true));
  }
  // IINDPM - Input Current Limit
  if (this->sensor_iindpm_ != nullptr) {
    this->sensor_iindpm_->publish_state(this->parent_->get_iindpm_int(true));
  }
  // VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
  if (this->sensor_vbat_lowv_ != nullptr) {
    this->sensor_vbat_lowv_->publish_state(this->parent_->get_vbat_lowv_enum_int(true));
  }
  // IPRECHG - Precharge Current Limit
  if (this->sensor_iprechg_ != nullptr) {
    this->sensor_iprechg_->publish_state(this->parent_->get_iprechg_int(true));
  }
  // REG_RST - Reset registers to default values and reset timer
  // STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
  // ITERM - Termination Current Limit
  if (this->sensor_iterm_ != nullptr) {
    this->sensor_iterm_->publish_state(this->parent_->get_iterm_int(true));
  }
  // CELL - Battery cell count
  if (this->sensor_cell_ != nullptr) {
    this->sensor_cell_->publish_state(this->parent_->get_cell_enum_int(true));
  }
  // TRECHG - Battery recharge delay time
  if (this->sensor_trechg_ != nullptr) {
    this->sensor_trechg_->publish_state(this->parent_->get_trechg_enum_int(true));
  }
  // VRECHG - Battery Recharge Threshold Offset (Below VREG)
  if (this->sensor_vrechg_ != nullptr) {
    this->sensor_vrechg_->publish_state(this->parent_->get_vrechg_int(true));
  }
  // VOTG - OTG mode regulation voltage
  if (this->sensor_votg_ != nullptr) {
    this->sensor_votg_->publish_state(this->parent_->get_votg_int(true));
  }
  // PRECHG_TMR - Pre-charge safety timer setting
  if (this->sensor_prechg_tmr_ != nullptr) {
    this->sensor_prechg_tmr_->publish_state(this->parent_->get_prechg_tmr_enum_int(true));
  }
  // IOTG - OTG current limit
  if (this->sensor_iotg_ != nullptr) {
    this->sensor_iotg_->publish_state(this->parent_->get_iotg_int(true));
  }
  // TOPOFF_TMR - Top-off timer control
  if (this->sensor_topoff_tmr_ != nullptr) {
    this->sensor_topoff_tmr_->publish_state(this->parent_->get_topoff_tmr_enum_int(true));
  }
  // EN_TRICHG_TMR - Trickle charge timer enable
  // EN_PRECHG_TMR - Precharge timer enable
  // EN_CHG_TMR - Fast charge timer enable
  // CHG_TMR - Fast charge timer setting
  if (this->sensor_chg_tmr_ != nullptr) {
    this->sensor_chg_tmr_->publish_state(this->parent_->get_chg_tmr_enum_int(true));
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
  if (this->sensor_vbus_backup_ != nullptr) {
    this->sensor_vbus_backup_->publish_state(this->parent_->get_vbus_backup_enum_int(true));
  }
  // VAC_OVP - Over voltage protection thresholds
  if (this->sensor_vac_ovp_ != nullptr) {
    this->sensor_vac_ovp_->publish_state(this->parent_->get_vac_ovp_enum_int(true));
  }
  // WD_RST - I2C watch dog timer reset
  // WATCHDOG - Watchdog timer settings
  if (this->sensor_watchdog_ != nullptr) {
    this->sensor_watchdog_->publish_state(this->parent_->get_watchdog_enum_int(true));
  }
  // FORCE_INDET - Force D+/D- detection
  // AUTO_INDET_EN - Enable automatic D+/D- detection
  // EN_12V - Enable 12V output in HVDCP
  // EN_9V - Enable 9V output in HVDCP
  // HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
  // SDRV_CTRL - Enable external Ship FET control
  if (this->sensor_sdrv_ctrl_ != nullptr) {
    this->sensor_sdrv_ctrl_->publish_state(this->parent_->get_sdrv_ctrl_enum_int(true));
  }
  // SDRV_DLY - Delay for SDRV control
  if (this->sensor_sdrv_dly_ != nullptr) {
    this->sensor_sdrv_dly_->publish_state(this->parent_->get_sdrv_dly_enum_int(true));
  }
  // DIS_ACDRV - Disable both AC1 and AC2 drivers
  // EN_OTG - Enable OTG mode
  // PFM_OTG_DIS - Disable PFM in OTG mode
  // PFM_FWD_DIS - Disable PFM in forward mode
  // WKUP_DLY - Wakeup (Ship FET) delay
  if (this->sensor_wkup_dly_ != nullptr) {
    this->sensor_wkup_dly_->publish_state(this->parent_->get_wkup_dly_enum_int(true));
  }
  // DIS_LDO - Disable BATFET LDO mode in precharge state
  // DIS_OTG_OOA - Disable OOA in OTG mode
  // DIS_FWD_OOA - Disable OOA in forward mode
  // EN_ACDRV2 - Enable AC2 gate driver control
  // EN_ACDRV1 - Enable AC1 gate driver control
  // PWM_FREQ - PWM frequency setting
  if (this->sensor_pwm_freq_ != nullptr) {
    this->sensor_pwm_freq_->publish_state(this->parent_->get_pwm_freq_enum_int(true));
  }
  // DIS_STAT - Disable STAT pin output
  // DIS_VSYS_SHORT - Disable VSYS short hiccup protection
  // DIS_VOTG_UVP - Disable VOTG under voltage hiccup protection
  // FORCE_VINDPM_DET - Force VINDPM detection (settable only when VBAT>VSYSMIN)
  // EN_IBUS_OCP - Enable input over current protection in forward mode
  // SFET_PRESENT - Ship FET present
  // EN_IBAT - Enable battery discharge current sensing
  // IBAT_REG - Battery discharge current regulation in OTG mode
  if (this->sensor_ibat_reg_ != nullptr) {
    this->sensor_ibat_reg_->publish_state(this->parent_->get_ibat_reg_enum_int(true));
  }
  // EN_IINDPM - Enable input current regulation
  // EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
  // EN_BATOC - Enable battery discharging over current protection
  // VOC_PCT - Set VINDPM as a percentage of the VBUS open circuit voltage when the VOC measurement is done
  if (this->sensor_voc_pct_ != nullptr) {
    this->sensor_voc_pct_->publish_state(this->parent_->get_voc_pct_enum_int(true));
  }
  // VOC_DLY - After the converter stops switching, the time delay before the VOC is measured
  if (this->sensor_voc_dly_ != nullptr) {
    this->sensor_voc_dly_->publish_state(this->parent_->get_voc_dly_enum_int(true));
  }
  // VOC_RATE - The time interval between two consecutive VOC measurements
  if (this->sensor_voc_rate_ != nullptr) {
    this->sensor_voc_rate_->publish_state(this->parent_->get_voc_rate_enum_int(true));
  }
  // EN_MPPT - Enable MPPT (Maximum Power Point Tracking)
  // TREG - Thermal regulation thresholds
  if (this->sensor_treg_ != nullptr) {
    this->sensor_treg_->publish_state(this->parent_->get_treg_enum_int(true));
  }
  // TSHUT - Thermal shutdown thresholds
  if (this->sensor_tshut_ != nullptr) {
    this->sensor_tshut_->publish_state(this->parent_->get_tshut_enum_int(true));
  }
  // VBUS_PD_EN - Enable VBUS pull down resistor (6 kOhm)
  // VAC1_PD_EN - Enable VAC1 pull down resistor
  // VAC2_PD_EN - Enable VAC2 pull down resistor
  // BKUP_ACFET1_ON - Enable ACFET1 in backup mode (exit backup mode)
  if (this->sensor_bkup_acfet1_on_ != nullptr) {
    this->sensor_bkup_acfet1_on_->publish_state(this->parent_->get_bkup_acfet1_on_enum_int(true));
  }
  // JEITA_VSET - JEITA high temperature range (TWARN - THOT) charge voltage setting
  if (this->sensor_jeita_vset_ != nullptr) {
    this->sensor_jeita_vset_->publish_state(this->parent_->get_jeita_vset_enum_int(true));
  }
  // JEITA_ISETH - JEITA high temperature range (TWARN - THOT) charge current setting
  if (this->sensor_jeita_iseth_ != nullptr) {
    this->sensor_jeita_iseth_->publish_state(this->parent_->get_jeita_iseth_enum_int(true));
  }
  // JEITA_ISETC - JEITA low temperature range (TCOLD - TWARN) charge current setting
  if (this->sensor_jeita_isetc_ != nullptr) {
    this->sensor_jeita_isetc_->publish_state(this->parent_->get_jeita_isetc_enum_int(true));
  }
  // TS_COOL - JEITA VT2 comparator voltage rising thresholds as a percentage of REGN.
  if (this->sensor_ts_cool_ != nullptr) {
    this->sensor_ts_cool_->publish_state(this->parent_->get_ts_cool_enum_int(true));
  }
  // TS_WARM - JEITA VT3 comparator voltage falling thresholds as a percentage of REGN.
  if (this->sensor_ts_warm_ != nullptr) {
    this->sensor_ts_warm_->publish_state(this->parent_->get_ts_warm_enum_int(true));
  }
  // BHOT - OTG mode TS HOT temperature threshold
  if (this->sensor_bhot_ != nullptr) {
    this->sensor_bhot_->publish_state(this->parent_->get_bhot_enum_int(true));
  }
  // BCOLD - OTG mode TS COLD temperature threshold
  if (this->sensor_bcold_ != nullptr) {
    this->sensor_bcold_->publish_state(this->parent_->get_bcold_enum_int(true));
  }
  // TS_IGNORE - Ignore TS detection (the charger considers the TS is always good)
  // ICO_ILIM - Input Current Limit obtained from ICO or ILIM_HIZ pin setting
  if (this->sensor_ico_ilim_ != nullptr) {
    this->sensor_ico_ilim_->publish_state(this->parent_->get_ico_ilim_int(true));
  }
  // IINDPM_STAT - IINDPM status (forward mode) or IOTG status (OTG mode)
  if (this->sensor_iindpm_stat_ != nullptr) {
    this->sensor_iindpm_stat_->publish_state(this->parent_->get_iindpm_stat_enum_int(true));
  }
  // VINDPM_STAT - VINDPM status (forward mode) or VOTG status (OTG mode)
  if (this->sensor_vindpm_stat_ != nullptr) {
    this->sensor_vindpm_stat_->publish_state(this->parent_->get_vindpm_stat_enum_int(true));
  }
  // WD_STAT - Watchdog timer status
  if (this->sensor_wd_stat_ != nullptr) {
    this->sensor_wd_stat_->publish_state(this->parent_->get_wd_stat_enum_int(true));
  }
  // PG_STAT - Power good status
  if (this->sensor_pg_stat_ != nullptr) {
    this->sensor_pg_stat_->publish_state(this->parent_->get_pg_stat_enum_int(true));
  }
  // AC2_PRESENT_STAT - VAC2 present status
  if (this->sensor_ac2_present_stat_ != nullptr) {
    this->sensor_ac2_present_stat_->publish_state(this->parent_->get_ac2_present_stat_enum_int(true));
  }
  // AC1_PRESENT_STAT - VAC1 present status
  if (this->sensor_ac1_present_stat_ != nullptr) {
    this->sensor_ac1_present_stat_->publish_state(this->parent_->get_ac1_present_stat_enum_int(true));
  }
  // VBUS_PRESENT_STAT - VBUS present status
  if (this->sensor_vbus_present_stat_ != nullptr) {
    this->sensor_vbus_present_stat_->publish_state(this->parent_->get_vbus_present_stat_enum_int(true));
  }
  // CHG_STAT - Charge Status bits
  if (this->sensor_chg_stat_ != nullptr) {
    this->sensor_chg_stat_->publish_state(this->parent_->get_chg_stat_enum_int(true));
  }
  // VBUS_STAT - VBUS status bits
  if (this->sensor_vbus_stat_ != nullptr) {
    this->sensor_vbus_stat_->publish_state(this->parent_->get_vbus_stat_enum_int(true));
  }
  // BC12_DONE_STAT - BC1.2 detection done status
  // ICO_STAT - Input Current Optimizer (ICO) status
  if (this->sensor_ico_stat_ != nullptr) {
    this->sensor_ico_stat_->publish_state(this->parent_->get_ico_stat_enum_int(true));
  }
  // TREG_STAT - IC thermal regulation status
  if (this->sensor_treg_stat_ != nullptr) {
    this->sensor_treg_stat_->publish_state(this->parent_->get_treg_stat_enum_int(true));
  }
  // DPDM_STAT - D+/D- detection status
  if (this->sensor_dpdm_stat_ != nullptr) {
    this->sensor_dpdm_stat_->publish_state(this->parent_->get_dpdm_stat_enum_int(true));
  }
  // VBAT_PRESENT_STAT - Battery present status
  if (this->sensor_vbat_present_stat_ != nullptr) {
    this->sensor_vbat_present_stat_->publish_state(this->parent_->get_vbat_present_stat_enum_int(true));
  }
  // ACRB2_STAT - The ACFET2-RBFET2 status
  if (this->sensor_acrb2_stat_ != nullptr) {
    this->sensor_acrb2_stat_->publish_state(this->parent_->get_acrb2_stat_enum_int(true));
  }
  // ACRB1_STAT - The ACFET1-RBFET1 status
  if (this->sensor_acrb1_stat_ != nullptr) {
    this->sensor_acrb1_stat_->publish_state(this->parent_->get_acrb1_stat_enum_int(true));
  }
  // ADC_DONE_STAT - ADC Conversion Status
  // VSYS_STAT - VSYS Regulation Status
  if (this->sensor_vsys_stat_ != nullptr) {
    this->sensor_vsys_stat_->publish_state(this->parent_->get_vsys_stat_enum_int(true));
  }
  // CHG_TMR_STAT - Fast charge timer status
  if (this->sensor_chg_tmr_stat_ != nullptr) {
    this->sensor_chg_tmr_stat_->publish_state(this->parent_->get_chg_tmr_stat_enum_int(true));
  }
  // TRICHG_TMR_STAT - Trickle charge timer status
  if (this->sensor_trichg_tmr_stat_ != nullptr) {
    this->sensor_trichg_tmr_stat_->publish_state(this->parent_->get_trichg_tmr_stat_enum_int(true));
  }
  // PRECHG_TMR_STAT - Pre-charge timer status
  if (this->sensor_prechg_tmr_stat_ != nullptr) {
    this->sensor_prechg_tmr_stat_->publish_state(this->parent_->get_prechg_tmr_stat_enum_int(true));
  }
  // VBATOTG_LOW_STAT - VBAT too low to enable OTG flag
  if (this->sensor_vbatotg_low_stat_ != nullptr) {
    this->sensor_vbatotg_low_stat_->publish_state(this->parent_->get_vbatotg_low_stat_enum_int(true));
  }
  // TS_COLD_STAT - The TS temperature is in the cold range
  if (this->sensor_ts_cold_stat_ != nullptr) {
    this->sensor_ts_cold_stat_->publish_state(this->parent_->get_ts_cold_stat_enum_int(true));
  }
  // TS_COOL_STAT - The TS temperature is in the cool range
  if (this->sensor_ts_cool_stat_ != nullptr) {
    this->sensor_ts_cool_stat_->publish_state(this->parent_->get_ts_cool_stat_enum_int(true));
  }
  // TS_WARM_STAT - The TS temperature is in the warm range
  if (this->sensor_ts_warm_stat_ != nullptr) {
    this->sensor_ts_warm_stat_->publish_state(this->parent_->get_ts_warm_stat_enum_int(true));
  }
  // TS_HOT_STAT - The TS temperature is in the hot range
  if (this->sensor_ts_hot_stat_ != nullptr) {
    this->sensor_ts_hot_stat_->publish_state(this->parent_->get_ts_hot_stat_enum_int(true));
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
  if (this->sensor_adc_rate_ != nullptr) {
    this->sensor_adc_rate_->publish_state(this->parent_->get_adc_rate_enum_int(true));
  }
  // ADC_SAMPLE - ADC sample speed
  if (this->sensor_adc_sample_ != nullptr) {
    this->sensor_adc_sample_->publish_state(this->parent_->get_adc_sample_enum_int(true));
  }
  // ADC_AVG - ADC averaging
  if (this->sensor_adc_avg_ != nullptr) {
    this->sensor_adc_avg_->publish_state(this->parent_->get_adc_avg_enum_int(true));
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
  if (this->sensor_ibus_adc_ != nullptr) {
    this->sensor_ibus_adc_->publish_state(this->parent_->get_ibus_adc_int(true));
  }
  // IBAT_ADC - IBAT ADC reading
  if (this->sensor_ibat_adc_ != nullptr) {
    this->sensor_ibat_adc_->publish_state(this->parent_->get_ibat_adc_int(true));
  }
  // VBUS_ADC - VBUS ADC reading
  if (this->sensor_vbus_adc_ != nullptr) {
    this->sensor_vbus_adc_->publish_state(this->parent_->get_vbus_adc_int(true));
  }
  // VAC1_ADC - VAC1 ADC reading
  if (this->sensor_vac1_adc_ != nullptr) {
    this->sensor_vac1_adc_->publish_state(this->parent_->get_vac1_adc_int(true));
  }
  // VAC2_ADC - VAC2 ADC reading
  if (this->sensor_vac2_adc_ != nullptr) {
    this->sensor_vac2_adc_->publish_state(this->parent_->get_vac2_adc_int(true));
  }
  // VBAT_ADC - VBAT ADC reading
  if (this->sensor_vbat_adc_ != nullptr) {
    this->sensor_vbat_adc_->publish_state(this->parent_->get_vbat_adc_int(true));
  }
  // VSYS_ADC - VSYS ADC reading
  if (this->sensor_vsys_adc_ != nullptr) {
    this->sensor_vsys_adc_->publish_state(this->parent_->get_vsys_adc_int(true));
  }
  // TS_ADC - TS ADC reading
  if (this->sensor_ts_adc_ != nullptr) {
    this->sensor_ts_adc_->publish_state(this->parent_->get_ts_adc_float(true));
  }
  // TDIE_ADC - TDIE ADC reading
  if (this->sensor_tdie_adc_ != nullptr) {
    this->sensor_tdie_adc_->publish_state(this->parent_->get_tdie_adc_float(true));
  }
  // DPLUS_ADC - D+ ADC reading
  if (this->sensor_dplus_adc_ != nullptr) {
    this->sensor_dplus_adc_->publish_state(this->parent_->get_dplus_adc_int(true));
  }
  // DMINUS_ADC - D- ADC reading
  if (this->sensor_dminus_adc_ != nullptr) {
    this->sensor_dminus_adc_->publish_state(this->parent_->get_dminus_adc_int(true));
  }
  // DPLUS_DAC - D+ Output Driver
  if (this->sensor_dplus_dac_ != nullptr) {
    this->sensor_dplus_dac_->publish_state(this->parent_->get_dplus_dac_enum_int(true));
  }
  // DMINUS_DAC - D- Output Driver
  if (this->sensor_dminus_dac_ != nullptr) {
    this->sensor_dminus_dac_->publish_state(this->parent_->get_dminus_dac_enum_int(true));
  }
  // PN - Part number
  if (this->sensor_pn_ != nullptr) {
    this->sensor_pn_->publish_state(this->parent_->get_pn_enum_int(true));
  }
  // DEV_REV - Device revision
  if (this->sensor_dev_rev_ != nullptr) {
    this->sensor_dev_rev_->publish_state(this->parent_->get_dev_rev_enum_int(true));
  }
}

void BQ25798Sensor::assign_sensor_vsysmin(sensor::Sensor *sensor) {
  this->sensor_vsysmin_ = sensor;
}
void BQ25798Sensor::assign_sensor_vreg(sensor::Sensor *sensor) {
  this->sensor_vreg_ = sensor;
}
void BQ25798Sensor::assign_sensor_ichg(sensor::Sensor *sensor) {
  this->sensor_ichg_ = sensor;
}
void BQ25798Sensor::assign_sensor_vindpm(sensor::Sensor *sensor) {
  this->sensor_vindpm_ = sensor;
}
void BQ25798Sensor::assign_sensor_iindpm(sensor::Sensor *sensor) {
  this->sensor_iindpm_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbat_lowv(sensor::Sensor *sensor) {
  this->sensor_vbat_lowv_ = sensor;
}
void BQ25798Sensor::assign_sensor_iprechg(sensor::Sensor *sensor) {
  this->sensor_iprechg_ = sensor;
}
void BQ25798Sensor::assign_sensor_iterm(sensor::Sensor *sensor) {
  this->sensor_iterm_ = sensor;
}
void BQ25798Sensor::assign_sensor_cell(sensor::Sensor *sensor) {
  this->sensor_cell_ = sensor;
}
void BQ25798Sensor::assign_sensor_trechg(sensor::Sensor *sensor) {
  this->sensor_trechg_ = sensor;
}
void BQ25798Sensor::assign_sensor_vrechg(sensor::Sensor *sensor) {
  this->sensor_vrechg_ = sensor;
}
void BQ25798Sensor::assign_sensor_votg(sensor::Sensor *sensor) {
  this->sensor_votg_ = sensor;
}
void BQ25798Sensor::assign_sensor_prechg_tmr(sensor::Sensor *sensor) {
  this->sensor_prechg_tmr_ = sensor;
}
void BQ25798Sensor::assign_sensor_iotg(sensor::Sensor *sensor) {
  this->sensor_iotg_ = sensor;
}
void BQ25798Sensor::assign_sensor_topoff_tmr(sensor::Sensor *sensor) {
  this->sensor_topoff_tmr_ = sensor;
}
void BQ25798Sensor::assign_sensor_chg_tmr(sensor::Sensor *sensor) {
  this->sensor_chg_tmr_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_backup(sensor::Sensor *sensor) {
  this->sensor_vbus_backup_ = sensor;
}
void BQ25798Sensor::assign_sensor_vac_ovp(sensor::Sensor *sensor) {
  this->sensor_vac_ovp_ = sensor;
}
void BQ25798Sensor::assign_sensor_watchdog(sensor::Sensor *sensor) {
  this->sensor_watchdog_ = sensor;
}
void BQ25798Sensor::assign_sensor_sdrv_ctrl(sensor::Sensor *sensor) {
  this->sensor_sdrv_ctrl_ = sensor;
}
void BQ25798Sensor::assign_sensor_sdrv_dly(sensor::Sensor *sensor) {
  this->sensor_sdrv_dly_ = sensor;
}
void BQ25798Sensor::assign_sensor_wkup_dly(sensor::Sensor *sensor) {
  this->sensor_wkup_dly_ = sensor;
}
void BQ25798Sensor::assign_sensor_pwm_freq(sensor::Sensor *sensor) {
  this->sensor_pwm_freq_ = sensor;
}
void BQ25798Sensor::assign_sensor_ibat_reg(sensor::Sensor *sensor) {
  this->sensor_ibat_reg_ = sensor;
}
void BQ25798Sensor::assign_sensor_voc_pct(sensor::Sensor *sensor) {
  this->sensor_voc_pct_ = sensor;
}
void BQ25798Sensor::assign_sensor_voc_dly(sensor::Sensor *sensor) {
  this->sensor_voc_dly_ = sensor;
}
void BQ25798Sensor::assign_sensor_voc_rate(sensor::Sensor *sensor) {
  this->sensor_voc_rate_ = sensor;
}
void BQ25798Sensor::assign_sensor_treg(sensor::Sensor *sensor) {
  this->sensor_treg_ = sensor;
}
void BQ25798Sensor::assign_sensor_tshut(sensor::Sensor *sensor) {
  this->sensor_tshut_ = sensor;
}
void BQ25798Sensor::assign_sensor_bkup_acfet1_on(sensor::Sensor *sensor) {
  this->sensor_bkup_acfet1_on_ = sensor;
}
void BQ25798Sensor::assign_sensor_jeita_vset(sensor::Sensor *sensor) {
  this->sensor_jeita_vset_ = sensor;
}
void BQ25798Sensor::assign_sensor_jeita_iseth(sensor::Sensor *sensor) {
  this->sensor_jeita_iseth_ = sensor;
}
void BQ25798Sensor::assign_sensor_jeita_isetc(sensor::Sensor *sensor) {
  this->sensor_jeita_isetc_ = sensor;
}
void BQ25798Sensor::assign_sensor_ts_cool(sensor::Sensor *sensor) {
  this->sensor_ts_cool_ = sensor;
}
void BQ25798Sensor::assign_sensor_ts_warm(sensor::Sensor *sensor) {
  this->sensor_ts_warm_ = sensor;
}
void BQ25798Sensor::assign_sensor_bhot(sensor::Sensor *sensor) {
  this->sensor_bhot_ = sensor;
}
void BQ25798Sensor::assign_sensor_bcold(sensor::Sensor *sensor) {
  this->sensor_bcold_ = sensor;
}
void BQ25798Sensor::assign_sensor_ico_ilim(sensor::Sensor *sensor) {
  this->sensor_ico_ilim_ = sensor;
}
void BQ25798Sensor::assign_sensor_iindpm_stat(sensor::Sensor *sensor) {
  this->sensor_iindpm_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_vindpm_stat(sensor::Sensor *sensor) {
  this->sensor_vindpm_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_wd_stat(sensor::Sensor *sensor) {
  this->sensor_wd_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_pg_stat(sensor::Sensor *sensor) {
  this->sensor_pg_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_ac2_present_stat(sensor::Sensor *sensor) {
  this->sensor_ac2_present_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_ac1_present_stat(sensor::Sensor *sensor) {
  this->sensor_ac1_present_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_present_stat(sensor::Sensor *sensor) {
  this->sensor_vbus_present_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_chg_stat(sensor::Sensor *sensor) {
  this->sensor_chg_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_stat(sensor::Sensor *sensor) {
  this->sensor_vbus_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_ico_stat(sensor::Sensor *sensor) {
  this->sensor_ico_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_treg_stat(sensor::Sensor *sensor) {
  this->sensor_treg_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_dpdm_stat(sensor::Sensor *sensor) {
  this->sensor_dpdm_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbat_present_stat(sensor::Sensor *sensor) {
  this->sensor_vbat_present_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_acrb2_stat(sensor::Sensor *sensor) {
  this->sensor_acrb2_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_acrb1_stat(sensor::Sensor *sensor) {
  this->sensor_acrb1_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_vsys_stat(sensor::Sensor *sensor) {
  this->sensor_vsys_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_chg_tmr_stat(sensor::Sensor *sensor) {
  this->sensor_chg_tmr_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_trichg_tmr_stat(sensor::Sensor *sensor) {
  this->sensor_trichg_tmr_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_prechg_tmr_stat(sensor::Sensor *sensor) {
  this->sensor_prechg_tmr_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbatotg_low_stat(sensor::Sensor *sensor) {
  this->sensor_vbatotg_low_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_ts_cold_stat(sensor::Sensor *sensor) {
  this->sensor_ts_cold_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_ts_cool_stat(sensor::Sensor *sensor) {
  this->sensor_ts_cool_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_ts_warm_stat(sensor::Sensor *sensor) {
  this->sensor_ts_warm_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_ts_hot_stat(sensor::Sensor *sensor) {
  this->sensor_ts_hot_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_adc_rate(sensor::Sensor *sensor) {
  this->sensor_adc_rate_ = sensor;
}
void BQ25798Sensor::assign_sensor_adc_sample(sensor::Sensor *sensor) {
  this->sensor_adc_sample_ = sensor;
}
void BQ25798Sensor::assign_sensor_adc_avg(sensor::Sensor *sensor) {
  this->sensor_adc_avg_ = sensor;
}
void BQ25798Sensor::assign_sensor_ibus_adc(sensor::Sensor *sensor) {
  this->sensor_ibus_adc_ = sensor;
}
void BQ25798Sensor::assign_sensor_ibat_adc(sensor::Sensor *sensor) {
  this->sensor_ibat_adc_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_adc(sensor::Sensor *sensor) {
  this->sensor_vbus_adc_ = sensor;
}
void BQ25798Sensor::assign_sensor_vac1_adc(sensor::Sensor *sensor) {
  this->sensor_vac1_adc_ = sensor;
}
void BQ25798Sensor::assign_sensor_vac2_adc(sensor::Sensor *sensor) {
  this->sensor_vac2_adc_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbat_adc(sensor::Sensor *sensor) {
  this->sensor_vbat_adc_ = sensor;
}
void BQ25798Sensor::assign_sensor_vsys_adc(sensor::Sensor *sensor) {
  this->sensor_vsys_adc_ = sensor;
}
void BQ25798Sensor::assign_sensor_ts_adc(sensor::Sensor *sensor) {
  this->sensor_ts_adc_ = sensor;
}
void BQ25798Sensor::assign_sensor_tdie_adc(sensor::Sensor *sensor) {
  this->sensor_tdie_adc_ = sensor;
}
void BQ25798Sensor::assign_sensor_dplus_adc(sensor::Sensor *sensor) {
  this->sensor_dplus_adc_ = sensor;
}
void BQ25798Sensor::assign_sensor_dminus_adc(sensor::Sensor *sensor) {
  this->sensor_dminus_adc_ = sensor;
}
void BQ25798Sensor::assign_sensor_dplus_dac(sensor::Sensor *sensor) {
  this->sensor_dplus_dac_ = sensor;
}
void BQ25798Sensor::assign_sensor_dminus_dac(sensor::Sensor *sensor) {
  this->sensor_dminus_dac_ = sensor;
}
void BQ25798Sensor::assign_sensor_pn(sensor::Sensor *sensor) {
  this->sensor_pn_ = sensor;
}
void BQ25798Sensor::assign_sensor_dev_rev(sensor::Sensor *sensor) {
  this->sensor_dev_rev_ = sensor;
}

}  // namespace bq25798
}  // namespace esphome