#include "bq25798_text_sensor.h"

#include "esphome/core/log.h"

namespace esphome {
namespace bq25798 {

static const char* const TAG = "bq25798.text_sensor";

float BQ25798TextSensor::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798TextSensor::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798TextSensor configuration...");

  if (this->text_sensor_vbat_lowv != nullptr) {
    LOG_TEXT_SENSOR("  ", "VBAT_LOWV", this->text_sensor_vbat_lowv);
  }
  if (this->text_sensor_cell != nullptr) {
    LOG_TEXT_SENSOR("  ", "CELL", this->text_sensor_cell);
  }
  if (this->text_sensor_trechg != nullptr) {
    LOG_TEXT_SENSOR("  ", "TRECHG", this->text_sensor_trechg);
  }
  if (this->text_sensor_prechg_tmr != nullptr) {
    LOG_TEXT_SENSOR("  ", "PRECHG_TMR", this->text_sensor_prechg_tmr);
  }
  if (this->text_sensor_topoff_tmr != nullptr) {
    LOG_TEXT_SENSOR("  ", "TOPOFF_TMR", this->text_sensor_topoff_tmr);
  }
  if (this->text_sensor_chg_tmr != nullptr) {
    LOG_TEXT_SENSOR("  ", "CHG_TMR", this->text_sensor_chg_tmr);
  }
  if (this->text_sensor_vbus_backup != nullptr) {
    LOG_TEXT_SENSOR("  ", "VBUS_BACKUP", this->text_sensor_vbus_backup);
  }
  if (this->text_sensor_vac_ovp != nullptr) {
    LOG_TEXT_SENSOR("  ", "VAC_OVP", this->text_sensor_vac_ovp);
  }
  if (this->text_sensor_watchdog != nullptr) {
    LOG_TEXT_SENSOR("  ", "WATCHDOG", this->text_sensor_watchdog);
  }
  if (this->text_sensor_sdrv_ctrl != nullptr) {
    LOG_TEXT_SENSOR("  ", "SDRV_CTRL", this->text_sensor_sdrv_ctrl);
  }
  if (this->text_sensor_sdrv_dly != nullptr) {
    LOG_TEXT_SENSOR("  ", "SDRV_DLY", this->text_sensor_sdrv_dly);
  }
  if (this->text_sensor_wkup_dly != nullptr) {
    LOG_TEXT_SENSOR("  ", "WKUP_DLY", this->text_sensor_wkup_dly);
  }
  if (this->text_sensor_pwm_freq != nullptr) {
    LOG_TEXT_SENSOR("  ", "PWM_FREQ", this->text_sensor_pwm_freq);
  }
  if (this->text_sensor_ibat_reg != nullptr) {
    LOG_TEXT_SENSOR("  ", "IBAT_REG", this->text_sensor_ibat_reg);
  }
  if (this->text_sensor_voc_pct != nullptr) {
    LOG_TEXT_SENSOR("  ", "VOC_PCT", this->text_sensor_voc_pct);
  }
  if (this->text_sensor_voc_dly != nullptr) {
    LOG_TEXT_SENSOR("  ", "VOC_DLY", this->text_sensor_voc_dly);
  }
  if (this->text_sensor_voc_rate != nullptr) {
    LOG_TEXT_SENSOR("  ", "VOC_RATE", this->text_sensor_voc_rate);
  }
  if (this->text_sensor_treg != nullptr) {
    LOG_TEXT_SENSOR("  ", "TREG", this->text_sensor_treg);
  }
  if (this->text_sensor_tshut != nullptr) {
    LOG_TEXT_SENSOR("  ", "TSHUT", this->text_sensor_tshut);
  }
  if (this->text_sensor_bkup_acfet1_on != nullptr) {
    LOG_TEXT_SENSOR("  ", "BKUP_ACFET1_ON", this->text_sensor_bkup_acfet1_on);
  }
  if (this->text_sensor_jeita_vset != nullptr) {
    LOG_TEXT_SENSOR("  ", "JEITA_VSET", this->text_sensor_jeita_vset);
  }
  if (this->text_sensor_jeita_iseth != nullptr) {
    LOG_TEXT_SENSOR("  ", "JEITA_ISETH", this->text_sensor_jeita_iseth);
  }
  if (this->text_sensor_jeita_isetc != nullptr) {
    LOG_TEXT_SENSOR("  ", "JEITA_ISETC", this->text_sensor_jeita_isetc);
  }
  if (this->text_sensor_ts_cool != nullptr) {
    LOG_TEXT_SENSOR("  ", "TS_COOL", this->text_sensor_ts_cool);
  }
  if (this->text_sensor_ts_warm != nullptr) {
    LOG_TEXT_SENSOR("  ", "TS_WARM", this->text_sensor_ts_warm);
  }
  if (this->text_sensor_bhot != nullptr) {
    LOG_TEXT_SENSOR("  ", "BHOT", this->text_sensor_bhot);
  }
  if (this->text_sensor_bcold != nullptr) {
    LOG_TEXT_SENSOR("  ", "BCOLD", this->text_sensor_bcold);
  }
  if (this->text_sensor_iindpm_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "IINDPM_STAT", this->text_sensor_iindpm_stat);
  }
  if (this->text_sensor_vindpm_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "VINDPM_STAT", this->text_sensor_vindpm_stat);
  }
  if (this->text_sensor_wd_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "WD_STAT", this->text_sensor_wd_stat);
  }
  if (this->text_sensor_pg_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "PG_STAT", this->text_sensor_pg_stat);
  }
  if (this->text_sensor_ac2_present_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "AC2_PRESENT_STAT", this->text_sensor_ac2_present_stat);
  }
  if (this->text_sensor_ac1_present_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "AC1_PRESENT_STAT", this->text_sensor_ac1_present_stat);
  }
  if (this->text_sensor_vbus_present_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "VBUS_PRESENT_STAT", this->text_sensor_vbus_present_stat);
  }
  if (this->text_sensor_chg_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "CHG_STAT", this->text_sensor_chg_stat);
  }
  if (this->text_sensor_vbus_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "VBUS_STAT", this->text_sensor_vbus_stat);
  }
  if (this->text_sensor_ico_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "ICO_STAT", this->text_sensor_ico_stat);
  }
  if (this->text_sensor_treg_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "TREG_STAT", this->text_sensor_treg_stat);
  }
  if (this->text_sensor_dpdm_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "DPDM_STAT", this->text_sensor_dpdm_stat);
  }
  if (this->text_sensor_vbat_present_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "VBAT_PRESENT_STAT", this->text_sensor_vbat_present_stat);
  }
  if (this->text_sensor_vsys_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "VSYS_STAT", this->text_sensor_vsys_stat);
  }
  if (this->text_sensor_chg_tmr_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "CHG_TMR_STAT", this->text_sensor_chg_tmr_stat);
  }
  if (this->text_sensor_trichg_tmr_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "TRICHG_TMR_STAT", this->text_sensor_trichg_tmr_stat);
  }
  if (this->text_sensor_prechg_tmr_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "PRECHG_TMR_STAT", this->text_sensor_prechg_tmr_stat);
  }
  if (this->text_sensor_vbatotg_low_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "VBATOTG_LOW_STAT", this->text_sensor_vbatotg_low_stat);
  }
  if (this->text_sensor_ts_cold_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "TS_COLD_STAT", this->text_sensor_ts_cold_stat);
  }
  if (this->text_sensor_ts_cool_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "TS_COOL_STAT", this->text_sensor_ts_cool_stat);
  }
  if (this->text_sensor_ts_warm_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "TS_WARM_STAT", this->text_sensor_ts_warm_stat);
  }
  if (this->text_sensor_ts_hot_stat != nullptr) {
    LOG_TEXT_SENSOR("  ", "TS_HOT_STAT", this->text_sensor_ts_hot_stat);
  }
  if (this->text_sensor_adc_rate != nullptr) {
    LOG_TEXT_SENSOR("  ", "ADC_RATE", this->text_sensor_adc_rate);
  }
  if (this->text_sensor_adc_sample != nullptr) {
    LOG_TEXT_SENSOR("  ", "ADC_SAMPLE", this->text_sensor_adc_sample);
  }
  if (this->text_sensor_adc_avg != nullptr) {
    LOG_TEXT_SENSOR("  ", "ADC_AVG", this->text_sensor_adc_avg);
  }
  if (this->text_sensor_dplus_dac != nullptr) {
    LOG_TEXT_SENSOR("  ", "DPLUS_DAC", this->text_sensor_dplus_dac);
  }
  if (this->text_sensor_dminus_dac != nullptr) {
    LOG_TEXT_SENSOR("  ", "DMINUS_DAC", this->text_sensor_dminus_dac);
  }
  if (this->text_sensor_pn != nullptr) {
    LOG_TEXT_SENSOR("  ", "PN", this->text_sensor_pn);
  }
  if (this->text_sensor_dev_rev != nullptr) {
    LOG_TEXT_SENSOR("  ", "DEV_REV", this->text_sensor_dev_rev);
  }

  LOG_UPDATE_INTERVAL(this);
}

void BQ25798TextSensor::update() {
  // VSYSMIN - Minimal System Voltage
   
  // VREG - Charge Voltage Limit
   
  // ICHG - Charge Current Limit
   
  // VINDPM - Input Voltage Limit
   
  // IINDPM - Input Current Limit
   
  // VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
   
  if (this->text_sensor_vbat_lowv != nullptr) {   
    this->text_sensor_vbat_lowv->publish_state(this->parent_->get_vbat_lowv_string(true));   
  }   
   
  // IPRECHG - Precharge Current Limit
   
  // REG_RST - Reset registers to default values and reset timer
   
  // STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
   
  // ITERM - Termination Current Limit
   
  // CELL - Battery cell count
   
  if (this->text_sensor_cell != nullptr) {   
    this->text_sensor_cell->publish_state(this->parent_->get_cell_string(true));   
  }   
   
  // TRECHG - Battery recharge delay time
   
  if (this->text_sensor_trechg != nullptr) {   
    this->text_sensor_trechg->publish_state(this->parent_->get_trechg_string(true));   
  }   
   
  // VRECHG - Battery Recharge Threshold Offset (Below VREG)
   
  // VOTG - OTG mode regulation voltage
   
  // PRECHG_TMR - Pre-charge safety timer setting
   
  if (this->text_sensor_prechg_tmr != nullptr) {   
    this->text_sensor_prechg_tmr->publish_state(this->parent_->get_prechg_tmr_string(true));   
  }   
   
  // IOTG - OTG current limit
   
  // TOPOFF_TMR - Top-off timer control
   
  if (this->text_sensor_topoff_tmr != nullptr) {   
    this->text_sensor_topoff_tmr->publish_state(this->parent_->get_topoff_tmr_string(true));   
  }   
   
  // EN_TRICHG_TMR - Trickle charge timer enable
   
  // EN_PRECHG_TMR - Precharge timer enable
   
  // EN_CHG_TMR - Fast charge timer enable
   
  // CHG_TMR - Fast charge timer setting
   
  if (this->text_sensor_chg_tmr != nullptr) {   
    this->text_sensor_chg_tmr->publish_state(this->parent_->get_chg_tmr_string(true));   
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
   
  if (this->text_sensor_vbus_backup != nullptr) {   
    this->text_sensor_vbus_backup->publish_state(this->parent_->get_vbus_backup_string(true));   
  }   
   
  // VAC_OVP - Over voltage protection thresholds
   
  if (this->text_sensor_vac_ovp != nullptr) {   
    this->text_sensor_vac_ovp->publish_state(this->parent_->get_vac_ovp_string(true));   
  }   
   
  // WD_RST - I2C watch dog timer reset
   
  // WATCHDOG - Watchdog timer settings
   
  if (this->text_sensor_watchdog != nullptr) {   
    this->text_sensor_watchdog->publish_state(this->parent_->get_watchdog_string(true));   
  }   
   
  // FORCE_INDET - Force D+/D- detection
   
  // AUTO_INDET_EN - Enable automatic D+/D- detection
   
  // EN_12V - Enable 12V output in HVDCP
   
  // EN_9V - Enable 9V output in HVDCP
   
  // HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
   
  // SDRV_CTRL - Enable external Ship FET control
   
  if (this->text_sensor_sdrv_ctrl != nullptr) {   
    this->text_sensor_sdrv_ctrl->publish_state(this->parent_->get_sdrv_ctrl_string(true));   
  }   
   
  // SDRV_DLY - Delay for SDRV control
   
  if (this->text_sensor_sdrv_dly != nullptr) {   
    this->text_sensor_sdrv_dly->publish_state(this->parent_->get_sdrv_dly_string(true));   
  }   
   
  // DIS_ACDRV - Disable both AC1 and AC2 drivers
   
  // EN_OTG - Enable OTG mode
   
  // PFM_OTG_DIS - Disable PFM in OTG mode
   
  // PFM_FWD_DIS - Disable PFM in forward mode
   
  // WKUP_DLY - Wakeup (Ship FET) delay
   
  if (this->text_sensor_wkup_dly != nullptr) {   
    this->text_sensor_wkup_dly->publish_state(this->parent_->get_wkup_dly_string(true));   
  }   
   
  // DIS_LDO - Disable BATFET LDO mode in precharge state
   
  // DIS_OTG_OOA - Disable OOA in OTG mode
   
  // DIS_FWD_OOA - Disable OOA in forward mode
   
  // EN_ACDRV2 - Enable AC2 gate driver control
   
  // EN_ACDRV1 - Enable AC1 gate driver control
   
  // PWM_FREQ - PWM frequency setting
   
  if (this->text_sensor_pwm_freq != nullptr) {   
    this->text_sensor_pwm_freq->publish_state(this->parent_->get_pwm_freq_string(true));   
  }   
   
  // DIS_STAT - Disable STAT pin output
   
  // DIS_VSYS_SHORT - Disable VSYS short hiccup protection
   
  // DIS_VOTG_UVP - Disable VOTG under voltage hiccup protection
   
  // FORCE_VINDPM_DET - Force VINDPM detection (settable only when VBAT>VSYSMIN)
   
  // EN_IBUS_OCP - Enable input over current protection in forward mode
   
  // SFET_PRESENT - Ship FET present
   
  // EN_IBAT - Enable battery discharge current sensing
   
  // IBAT_REG - Battery discharge current regulation in OTG mode
   
  if (this->text_sensor_ibat_reg != nullptr) {   
    this->text_sensor_ibat_reg->publish_state(this->parent_->get_ibat_reg_string(true));   
  }   
   
  // EN_IINDPM - Enable input current regulation
   
  // EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
   
  // EN_BATOC - Enable battery discharging over current protection
   
  // VOC_PCT - 
   
  if (this->text_sensor_voc_pct != nullptr) {   
    this->text_sensor_voc_pct->publish_state(this->parent_->get_voc_pct_string(true));   
  }   
   
  // VOC_DLY - 
   
  if (this->text_sensor_voc_dly != nullptr) {   
    this->text_sensor_voc_dly->publish_state(this->parent_->get_voc_dly_string(true));   
  }   
   
  // VOC_RATE - 
   
  if (this->text_sensor_voc_rate != nullptr) {   
    this->text_sensor_voc_rate->publish_state(this->parent_->get_voc_rate_string(true));   
  }   
   
  // EN_MPPT - 
   
  // TREG - 
   
  if (this->text_sensor_treg != nullptr) {   
    this->text_sensor_treg->publish_state(this->parent_->get_treg_string(true));   
  }   
   
  // TSHUT - 
   
  if (this->text_sensor_tshut != nullptr) {   
    this->text_sensor_tshut->publish_state(this->parent_->get_tshut_string(true));   
  }   
   
  // VBUS_PD_EN - 
   
  // VAC1_PD_EN - 
   
  // VAC2_PD_EN - 
   
  // BKUP_ACFET1_ON - 
   
  if (this->text_sensor_bkup_acfet1_on != nullptr) {   
    this->text_sensor_bkup_acfet1_on->publish_state(this->parent_->get_bkup_acfet1_on_string(true));   
  }   
   
  // JEITA_VSET - 
   
  if (this->text_sensor_jeita_vset != nullptr) {   
    this->text_sensor_jeita_vset->publish_state(this->parent_->get_jeita_vset_string(true));   
  }   
   
  // JEITA_ISETH - 
   
  if (this->text_sensor_jeita_iseth != nullptr) {   
    this->text_sensor_jeita_iseth->publish_state(this->parent_->get_jeita_iseth_string(true));   
  }   
   
  // JEITA_ISETC - 
   
  if (this->text_sensor_jeita_isetc != nullptr) {   
    this->text_sensor_jeita_isetc->publish_state(this->parent_->get_jeita_isetc_string(true));   
  }   
   
  // TS_COOL - 
   
  if (this->text_sensor_ts_cool != nullptr) {   
    this->text_sensor_ts_cool->publish_state(this->parent_->get_ts_cool_string(true));   
  }   
   
  // TS_WARM - 
   
  if (this->text_sensor_ts_warm != nullptr) {   
    this->text_sensor_ts_warm->publish_state(this->parent_->get_ts_warm_string(true));   
  }   
   
  // BHOT - 
   
  if (this->text_sensor_bhot != nullptr) {   
    this->text_sensor_bhot->publish_state(this->parent_->get_bhot_string(true));   
  }   
   
  // BCOLD - 
   
  if (this->text_sensor_bcold != nullptr) {   
    this->text_sensor_bcold->publish_state(this->parent_->get_bcold_string(true));   
  }   
   
  // TS_IGNORE - 
   
  // ICO_ILIM - 
   
  // IINDPM_STAT - 
   
  if (this->text_sensor_iindpm_stat != nullptr) {   
    this->text_sensor_iindpm_stat->publish_state(this->parent_->get_iindpm_stat_string(true));   
  }   
   
  // VINDPM_STAT - 
   
  if (this->text_sensor_vindpm_stat != nullptr) {   
    this->text_sensor_vindpm_stat->publish_state(this->parent_->get_vindpm_stat_string(true));   
  }   
   
  // WD_STAT - 
   
  if (this->text_sensor_wd_stat != nullptr) {   
    this->text_sensor_wd_stat->publish_state(this->parent_->get_wd_stat_string(true));   
  }   
   
  // PG_STAT - 
   
  if (this->text_sensor_pg_stat != nullptr) {   
    this->text_sensor_pg_stat->publish_state(this->parent_->get_pg_stat_string(true));   
  }   
   
  // AC2_PRESENT_STAT - 
   
  if (this->text_sensor_ac2_present_stat != nullptr) {   
    this->text_sensor_ac2_present_stat->publish_state(this->parent_->get_ac2_present_stat_string(true));   
  }   
   
  // AC1_PRESENT_STAT - 
   
  if (this->text_sensor_ac1_present_stat != nullptr) {   
    this->text_sensor_ac1_present_stat->publish_state(this->parent_->get_ac1_present_stat_string(true));   
  }   
   
  // VBUS_PRESENT_STAT - 
   
  if (this->text_sensor_vbus_present_stat != nullptr) {   
    this->text_sensor_vbus_present_stat->publish_state(this->parent_->get_vbus_present_stat_string(true));   
  }   
   
  // CHG_STAT - Charge Status bits
   
  if (this->text_sensor_chg_stat != nullptr) {   
    this->text_sensor_chg_stat->publish_state(this->parent_->get_chg_stat_string(true));   
  }   
   
  // VBUS_STAT - VBUS status bits
   
  if (this->text_sensor_vbus_stat != nullptr) {   
    this->text_sensor_vbus_stat->publish_state(this->parent_->get_vbus_stat_string(true));   
  }   
   
  // BC12_DONE_STAT - 
   
  // ICO_STAT - 
   
  if (this->text_sensor_ico_stat != nullptr) {   
    this->text_sensor_ico_stat->publish_state(this->parent_->get_ico_stat_string(true));   
  }   
   
  // TREG_STAT - 
   
  if (this->text_sensor_treg_stat != nullptr) {   
    this->text_sensor_treg_stat->publish_state(this->parent_->get_treg_stat_string(true));   
  }   
   
  // DPDM_STAT - 
   
  if (this->text_sensor_dpdm_stat != nullptr) {   
    this->text_sensor_dpdm_stat->publish_state(this->parent_->get_dpdm_stat_string(true));   
  }   
   
  // VBAT_PRESENT_STAT - 
   
  if (this->text_sensor_vbat_present_stat != nullptr) {   
    this->text_sensor_vbat_present_stat->publish_state(this->parent_->get_vbat_present_stat_string(true));   
  }   
   
  // ACRB2_STAT - The ACFET2-RBFET2 status
   
  // ACRB1_STAT - The ACFET1-RBFET1 status
   
  // ADC_DONE_STAT - ADC Conversion Status
   
  // VSYS_STAT - VSYS Regulation Status
   
  if (this->text_sensor_vsys_stat != nullptr) {   
    this->text_sensor_vsys_stat->publish_state(this->parent_->get_vsys_stat_string(true));   
  }   
   
  // CHG_TMR_STAT - Fast charge timer status
   
  if (this->text_sensor_chg_tmr_stat != nullptr) {   
    this->text_sensor_chg_tmr_stat->publish_state(this->parent_->get_chg_tmr_stat_string(true));   
  }   
   
  // TRICHG_TMR_STAT - Trickle charge timer status
   
  if (this->text_sensor_trichg_tmr_stat != nullptr) {   
    this->text_sensor_trichg_tmr_stat->publish_state(this->parent_->get_trichg_tmr_stat_string(true));   
  }   
   
  // PRECHG_TMR_STAT - Pre-charge timer status
   
  if (this->text_sensor_prechg_tmr_stat != nullptr) {   
    this->text_sensor_prechg_tmr_stat->publish_state(this->parent_->get_prechg_tmr_stat_string(true));   
  }   
   
  // VBATOTG_LOW_STAT - VBAT too low to enable OTG flag
   
  if (this->text_sensor_vbatotg_low_stat != nullptr) {   
    this->text_sensor_vbatotg_low_stat->publish_state(this->parent_->get_vbatotg_low_stat_string(true));   
  }   
   
  // TS_COLD_STAT - The TS temperature is in the cold range
   
  if (this->text_sensor_ts_cold_stat != nullptr) {   
    this->text_sensor_ts_cold_stat->publish_state(this->parent_->get_ts_cold_stat_string(true));   
  }   
   
  // TS_COOL_STAT - The TS temperature is in the cool range
   
  if (this->text_sensor_ts_cool_stat != nullptr) {   
    this->text_sensor_ts_cool_stat->publish_state(this->parent_->get_ts_cool_stat_string(true));   
  }   
   
  // TS_WARM_STAT - The TS temperature is in the warm range
   
  if (this->text_sensor_ts_warm_stat != nullptr) {   
    this->text_sensor_ts_warm_stat->publish_state(this->parent_->get_ts_warm_stat_string(true));   
  }   
   
  // TS_HOT_STAT - The TS temperature is in the hot range
   
  if (this->text_sensor_ts_hot_stat != nullptr) {   
    this->text_sensor_ts_hot_stat->publish_state(this->parent_->get_ts_hot_stat_string(true));   
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
   
  if (this->text_sensor_adc_rate != nullptr) {   
    this->text_sensor_adc_rate->publish_state(this->parent_->get_adc_rate_string(true));   
  }   
   
  // ADC_SAMPLE - 
   
  if (this->text_sensor_adc_sample != nullptr) {   
    this->text_sensor_adc_sample->publish_state(this->parent_->get_adc_sample_string(true));   
  }   
   
  // ADC_AVG - 
   
  if (this->text_sensor_adc_avg != nullptr) {   
    this->text_sensor_adc_avg->publish_state(this->parent_->get_adc_avg_string(true));   
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
   
  if (this->text_sensor_dplus_dac != nullptr) {   
    this->text_sensor_dplus_dac->publish_state(this->parent_->get_dplus_dac_string(true));   
  }   
   
  // DMINUS_DAC - D- Output Driver
   
  if (this->text_sensor_dminus_dac != nullptr) {   
    this->text_sensor_dminus_dac->publish_state(this->parent_->get_dminus_dac_string(true));   
  }   
   
  // PN - 
   
  if (this->text_sensor_pn != nullptr) {   
    this->text_sensor_pn->publish_state(this->parent_->get_pn_string(true));   
  }   
   
  // DEV_REV - 
   
  if (this->text_sensor_dev_rev != nullptr) {   
    this->text_sensor_dev_rev->publish_state(this->parent_->get_dev_rev_string(true));   
  }   
   
}


void BQ25798TextSensor::assign_text_sensor_vbat_lowv(text_sensor::TextSensor *sensor) {
  text_sensor_vbat_lowv = sensor;
}
void BQ25798TextSensor::assign_text_sensor_cell(text_sensor::TextSensor *sensor) {
  text_sensor_cell = sensor;
}
void BQ25798TextSensor::assign_text_sensor_trechg(text_sensor::TextSensor *sensor) {
  text_sensor_trechg = sensor;
}
void BQ25798TextSensor::assign_text_sensor_prechg_tmr(text_sensor::TextSensor *sensor) {
  text_sensor_prechg_tmr = sensor;
}
void BQ25798TextSensor::assign_text_sensor_topoff_tmr(text_sensor::TextSensor *sensor) {
  text_sensor_topoff_tmr = sensor;
}
void BQ25798TextSensor::assign_text_sensor_chg_tmr(text_sensor::TextSensor *sensor) {
  text_sensor_chg_tmr = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vbus_backup(text_sensor::TextSensor *sensor) {
  text_sensor_vbus_backup = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vac_ovp(text_sensor::TextSensor *sensor) {
  text_sensor_vac_ovp = sensor;
}
void BQ25798TextSensor::assign_text_sensor_watchdog(text_sensor::TextSensor *sensor) {
  text_sensor_watchdog = sensor;
}
void BQ25798TextSensor::assign_text_sensor_sdrv_ctrl(text_sensor::TextSensor *sensor) {
  text_sensor_sdrv_ctrl = sensor;
}
void BQ25798TextSensor::assign_text_sensor_sdrv_dly(text_sensor::TextSensor *sensor) {
  text_sensor_sdrv_dly = sensor;
}
void BQ25798TextSensor::assign_text_sensor_wkup_dly(text_sensor::TextSensor *sensor) {
  text_sensor_wkup_dly = sensor;
}
void BQ25798TextSensor::assign_text_sensor_pwm_freq(text_sensor::TextSensor *sensor) {
  text_sensor_pwm_freq = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ibat_reg(text_sensor::TextSensor *sensor) {
  text_sensor_ibat_reg = sensor;
}
void BQ25798TextSensor::assign_text_sensor_voc_pct(text_sensor::TextSensor *sensor) {
  text_sensor_voc_pct = sensor;
}
void BQ25798TextSensor::assign_text_sensor_voc_dly(text_sensor::TextSensor *sensor) {
  text_sensor_voc_dly = sensor;
}
void BQ25798TextSensor::assign_text_sensor_voc_rate(text_sensor::TextSensor *sensor) {
  text_sensor_voc_rate = sensor;
}
void BQ25798TextSensor::assign_text_sensor_treg(text_sensor::TextSensor *sensor) {
  text_sensor_treg = sensor;
}
void BQ25798TextSensor::assign_text_sensor_tshut(text_sensor::TextSensor *sensor) {
  text_sensor_tshut = sensor;
}
void BQ25798TextSensor::assign_text_sensor_bkup_acfet1_on(text_sensor::TextSensor *sensor) {
  text_sensor_bkup_acfet1_on = sensor;
}
void BQ25798TextSensor::assign_text_sensor_jeita_vset(text_sensor::TextSensor *sensor) {
  text_sensor_jeita_vset = sensor;
}
void BQ25798TextSensor::assign_text_sensor_jeita_iseth(text_sensor::TextSensor *sensor) {
  text_sensor_jeita_iseth = sensor;
}
void BQ25798TextSensor::assign_text_sensor_jeita_isetc(text_sensor::TextSensor *sensor) {
  text_sensor_jeita_isetc = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ts_cool(text_sensor::TextSensor *sensor) {
  text_sensor_ts_cool = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ts_warm(text_sensor::TextSensor *sensor) {
  text_sensor_ts_warm = sensor;
}
void BQ25798TextSensor::assign_text_sensor_bhot(text_sensor::TextSensor *sensor) {
  text_sensor_bhot = sensor;
}
void BQ25798TextSensor::assign_text_sensor_bcold(text_sensor::TextSensor *sensor) {
  text_sensor_bcold = sensor;
}
void BQ25798TextSensor::assign_text_sensor_iindpm_stat(text_sensor::TextSensor *sensor) {
  text_sensor_iindpm_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vindpm_stat(text_sensor::TextSensor *sensor) {
  text_sensor_vindpm_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_wd_stat(text_sensor::TextSensor *sensor) {
  text_sensor_wd_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_pg_stat(text_sensor::TextSensor *sensor) {
  text_sensor_pg_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ac2_present_stat(text_sensor::TextSensor *sensor) {
  text_sensor_ac2_present_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ac1_present_stat(text_sensor::TextSensor *sensor) {
  text_sensor_ac1_present_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vbus_present_stat(text_sensor::TextSensor *sensor) {
  text_sensor_vbus_present_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_chg_stat(text_sensor::TextSensor *sensor) {
  text_sensor_chg_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vbus_stat(text_sensor::TextSensor *sensor) {
  text_sensor_vbus_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ico_stat(text_sensor::TextSensor *sensor) {
  text_sensor_ico_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_treg_stat(text_sensor::TextSensor *sensor) {
  text_sensor_treg_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_dpdm_stat(text_sensor::TextSensor *sensor) {
  text_sensor_dpdm_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vbat_present_stat(text_sensor::TextSensor *sensor) {
  text_sensor_vbat_present_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vsys_stat(text_sensor::TextSensor *sensor) {
  text_sensor_vsys_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_chg_tmr_stat(text_sensor::TextSensor *sensor) {
  text_sensor_chg_tmr_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_trichg_tmr_stat(text_sensor::TextSensor *sensor) {
  text_sensor_trichg_tmr_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_prechg_tmr_stat(text_sensor::TextSensor *sensor) {
  text_sensor_prechg_tmr_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_vbatotg_low_stat(text_sensor::TextSensor *sensor) {
  text_sensor_vbatotg_low_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ts_cold_stat(text_sensor::TextSensor *sensor) {
  text_sensor_ts_cold_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ts_cool_stat(text_sensor::TextSensor *sensor) {
  text_sensor_ts_cool_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ts_warm_stat(text_sensor::TextSensor *sensor) {
  text_sensor_ts_warm_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_ts_hot_stat(text_sensor::TextSensor *sensor) {
  text_sensor_ts_hot_stat = sensor;
}
void BQ25798TextSensor::assign_text_sensor_adc_rate(text_sensor::TextSensor *sensor) {
  text_sensor_adc_rate = sensor;
}
void BQ25798TextSensor::assign_text_sensor_adc_sample(text_sensor::TextSensor *sensor) {
  text_sensor_adc_sample = sensor;
}
void BQ25798TextSensor::assign_text_sensor_adc_avg(text_sensor::TextSensor *sensor) {
  text_sensor_adc_avg = sensor;
}
void BQ25798TextSensor::assign_text_sensor_dplus_dac(text_sensor::TextSensor *sensor) {
  text_sensor_dplus_dac = sensor;
}
void BQ25798TextSensor::assign_text_sensor_dminus_dac(text_sensor::TextSensor *sensor) {
  text_sensor_dminus_dac = sensor;
}
void BQ25798TextSensor::assign_text_sensor_pn(text_sensor::TextSensor *sensor) {
  text_sensor_pn = sensor;
}
void BQ25798TextSensor::assign_text_sensor_dev_rev(text_sensor::TextSensor *sensor) {
  text_sensor_dev_rev = sensor;
}

}  // namespace bq25798
}  // namespace esphome