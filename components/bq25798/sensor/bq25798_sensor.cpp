#include "bq25798_sensor.h"

#include "esphome/core/log.h"

namespace esphome {
namespace bq25798 {

static const char* const TAG = "bq25798.sensor";

float BQ25798Sensor::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798Sensor::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798Sensor configuration...");

  if (this->sensor_vsysmin != nullptr) {
    LOG_SENSOR("  ", "VSYSMIN", this->sensor_vsysmin);
  }
  if (this->sensor_vreg != nullptr) {
    LOG_SENSOR("  ", "VREG", this->sensor_vreg);
  }
  if (this->sensor_ichg != nullptr) {
    LOG_SENSOR("  ", "ICHG", this->sensor_ichg);
  }
  if (this->sensor_vindpm != nullptr) {
    LOG_SENSOR("  ", "VINDPM", this->sensor_vindpm);
  }
  if (this->sensor_iindpm != nullptr) {
    LOG_SENSOR("  ", "IINDPM", this->sensor_iindpm);
  }
  if (this->sensor_vbat_lowv != nullptr) {
    LOG_SENSOR("  ", "VBAT_LOWV", this->sensor_vbat_lowv);
  }
  if (this->sensor_iprechg != nullptr) {
    LOG_SENSOR("  ", "IPRECHG", this->sensor_iprechg);
  }
  if (this->sensor_iterm != nullptr) {
    LOG_SENSOR("  ", "ITERM", this->sensor_iterm);
  }
  if (this->sensor_cell != nullptr) {
    LOG_SENSOR("  ", "CELL", this->sensor_cell);
  }
  if (this->sensor_trechg != nullptr) {
    LOG_SENSOR("  ", "TRECHG", this->sensor_trechg);
  }
  if (this->sensor_vrechg != nullptr) {
    LOG_SENSOR("  ", "VRECHG", this->sensor_vrechg);
  }
  if (this->sensor_votg != nullptr) {
    LOG_SENSOR("  ", "VOTG", this->sensor_votg);
  }
  if (this->sensor_prechg_tmr != nullptr) {
    LOG_SENSOR("  ", "PRECHG_TMR", this->sensor_prechg_tmr);
  }
  if (this->sensor_iotg != nullptr) {
    LOG_SENSOR("  ", "IOTG", this->sensor_iotg);
  }
  if (this->sensor_topoff_tmr != nullptr) {
    LOG_SENSOR("  ", "TOPOFF_TMR", this->sensor_topoff_tmr);
  }
  if (this->sensor_chg_tmr != nullptr) {
    LOG_SENSOR("  ", "CHG_TMR", this->sensor_chg_tmr);
  }
  if (this->sensor_vbus_backup != nullptr) {
    LOG_SENSOR("  ", "VBUS_BACKUP", this->sensor_vbus_backup);
  }
  if (this->sensor_vac_ovp != nullptr) {
    LOG_SENSOR("  ", "VAC_OVP", this->sensor_vac_ovp);
  }
  if (this->sensor_watchdog != nullptr) {
    LOG_SENSOR("  ", "WATCHDOG", this->sensor_watchdog);
  }
  if (this->sensor_sdrv_ctrl != nullptr) {
    LOG_SENSOR("  ", "SDRV_CTRL", this->sensor_sdrv_ctrl);
  }
  if (this->sensor_sdrv_dly != nullptr) {
    LOG_SENSOR("  ", "SDRV_DLY", this->sensor_sdrv_dly);
  }
  if (this->sensor_wkup_dly != nullptr) {
    LOG_SENSOR("  ", "WKUP_DLY", this->sensor_wkup_dly);
  }
  if (this->sensor_pwm_freq != nullptr) {
    LOG_SENSOR("  ", "PWM_FREQ", this->sensor_pwm_freq);
  }
  if (this->sensor_ibat_reg != nullptr) {
    LOG_SENSOR("  ", "IBAT_REG", this->sensor_ibat_reg);
  }
  if (this->sensor_voc_pct != nullptr) {
    LOG_SENSOR("  ", "VOC_PCT", this->sensor_voc_pct);
  }
  if (this->sensor_voc_dly != nullptr) {
    LOG_SENSOR("  ", "VOC_DLY", this->sensor_voc_dly);
  }
  if (this->sensor_voc_rate != nullptr) {
    LOG_SENSOR("  ", "VOC_RATE", this->sensor_voc_rate);
  }
  if (this->sensor_treg != nullptr) {
    LOG_SENSOR("  ", "TREG", this->sensor_treg);
  }
  if (this->sensor_tshut != nullptr) {
    LOG_SENSOR("  ", "TSHUT", this->sensor_tshut);
  }
  if (this->sensor_bkup_acfet1_on != nullptr) {
    LOG_SENSOR("  ", "BKUP_ACFET1_ON", this->sensor_bkup_acfet1_on);
  }
  if (this->sensor_jeita_vset != nullptr) {
    LOG_SENSOR("  ", "JEITA_VSET", this->sensor_jeita_vset);
  }
  if (this->sensor_jeita_iseth != nullptr) {
    LOG_SENSOR("  ", "JEITA_ISETH", this->sensor_jeita_iseth);
  }
  if (this->sensor_jeita_isetc != nullptr) {
    LOG_SENSOR("  ", "JEITA_ISETC", this->sensor_jeita_isetc);
  }
  if (this->sensor_ts_cool != nullptr) {
    LOG_SENSOR("  ", "TS_COOL", this->sensor_ts_cool);
  }
  if (this->sensor_ts_warm != nullptr) {
    LOG_SENSOR("  ", "TS_WARM", this->sensor_ts_warm);
  }
  if (this->sensor_bhot != nullptr) {
    LOG_SENSOR("  ", "BHOT", this->sensor_bhot);
  }
  if (this->sensor_bcold != nullptr) {
    LOG_SENSOR("  ", "BCOLD", this->sensor_bcold);
  }
  if (this->sensor_ico_ilim != nullptr) {
    LOG_SENSOR("  ", "ICO_ILIM", this->sensor_ico_ilim);
  }
  if (this->sensor_iindpm_stat != nullptr) {
    LOG_SENSOR("  ", "IINDPM_STAT", this->sensor_iindpm_stat);
  }
  if (this->sensor_vindpm_stat != nullptr) {
    LOG_SENSOR("  ", "VINDPM_STAT", this->sensor_vindpm_stat);
  }
  if (this->sensor_wd_stat != nullptr) {
    LOG_SENSOR("  ", "WD_STAT", this->sensor_wd_stat);
  }
  if (this->sensor_pg_stat != nullptr) {
    LOG_SENSOR("  ", "PG_STAT", this->sensor_pg_stat);
  }
  if (this->sensor_ac2_present_stat != nullptr) {
    LOG_SENSOR("  ", "AC2_PRESENT_STAT", this->sensor_ac2_present_stat);
  }
  if (this->sensor_ac1_present_stat != nullptr) {
    LOG_SENSOR("  ", "AC1_PRESENT_STAT", this->sensor_ac1_present_stat);
  }
  if (this->sensor_vbus_present_stat != nullptr) {
    LOG_SENSOR("  ", "VBUS_PRESENT_STAT", this->sensor_vbus_present_stat);
  }
  if (this->sensor_chg_stat != nullptr) {
    LOG_SENSOR("  ", "CHG_STAT", this->sensor_chg_stat);
  }
  if (this->sensor_vbus_stat != nullptr) {
    LOG_SENSOR("  ", "VBUS_STAT", this->sensor_vbus_stat);
  }
  if (this->sensor_ico_stat != nullptr) {
    LOG_SENSOR("  ", "ICO_STAT", this->sensor_ico_stat);
  }
  if (this->sensor_treg_stat != nullptr) {
    LOG_SENSOR("  ", "TREG_STAT", this->sensor_treg_stat);
  }
  if (this->sensor_dpdm_stat != nullptr) {
    LOG_SENSOR("  ", "DPDM_STAT", this->sensor_dpdm_stat);
  }
  if (this->sensor_vbat_present_stat != nullptr) {
    LOG_SENSOR("  ", "VBAT_PRESENT_STAT", this->sensor_vbat_present_stat);
  }
  if (this->sensor_vsys_stat != nullptr) {
    LOG_SENSOR("  ", "VSYS_STAT", this->sensor_vsys_stat);
  }
  if (this->sensor_chg_tmr_stat != nullptr) {
    LOG_SENSOR("  ", "CHG_TMR_STAT", this->sensor_chg_tmr_stat);
  }
  if (this->sensor_trichg_tmr_stat != nullptr) {
    LOG_SENSOR("  ", "TRICHG_TMR_STAT", this->sensor_trichg_tmr_stat);
  }
  if (this->sensor_prechg_tmr_stat != nullptr) {
    LOG_SENSOR("  ", "PRECHG_TMR_STAT", this->sensor_prechg_tmr_stat);
  }
  if (this->sensor_vbatotg_low_stat != nullptr) {
    LOG_SENSOR("  ", "VBATOTG_LOW_STAT", this->sensor_vbatotg_low_stat);
  }
  if (this->sensor_ts_cold_stat != nullptr) {
    LOG_SENSOR("  ", "TS_COLD_STAT", this->sensor_ts_cold_stat);
  }
  if (this->sensor_ts_cool_stat != nullptr) {
    LOG_SENSOR("  ", "TS_COOL_STAT", this->sensor_ts_cool_stat);
  }
  if (this->sensor_ts_warm_stat != nullptr) {
    LOG_SENSOR("  ", "TS_WARM_STAT", this->sensor_ts_warm_stat);
  }
  if (this->sensor_ts_hot_stat != nullptr) {
    LOG_SENSOR("  ", "TS_HOT_STAT", this->sensor_ts_hot_stat);
  }
  if (this->sensor_adc_rate != nullptr) {
    LOG_SENSOR("  ", "ADC_RATE", this->sensor_adc_rate);
  }
  if (this->sensor_adc_sample != nullptr) {
    LOG_SENSOR("  ", "ADC_SAMPLE", this->sensor_adc_sample);
  }
  if (this->sensor_adc_avg != nullptr) {
    LOG_SENSOR("  ", "ADC_AVG", this->sensor_adc_avg);
  }
  if (this->sensor_ibus_adc != nullptr) {
    LOG_SENSOR("  ", "IBUS_ADC", this->sensor_ibus_adc);
  }
  if (this->sensor_ibat_adc != nullptr) {
    LOG_SENSOR("  ", "IBAT_ADC", this->sensor_ibat_adc);
  }
  if (this->sensor_vbus_adc != nullptr) {
    LOG_SENSOR("  ", "VBUS_ADC", this->sensor_vbus_adc);
  }
  if (this->sensor_vac1_adc != nullptr) {
    LOG_SENSOR("  ", "VAC1_ADC", this->sensor_vac1_adc);
  }
  if (this->sensor_vac2_adc != nullptr) {
    LOG_SENSOR("  ", "VAC2_ADC", this->sensor_vac2_adc);
  }
  if (this->sensor_vbat_adc != nullptr) {
    LOG_SENSOR("  ", "VBAT_ADC", this->sensor_vbat_adc);
  }
  if (this->sensor_vsys_adc != nullptr) {
    LOG_SENSOR("  ", "VSYS_ADC", this->sensor_vsys_adc);
  }
  if (this->sensor_ts_adc != nullptr) {
    LOG_SENSOR("  ", "TS_ADC", this->sensor_ts_adc);
  }
  if (this->sensor_tdie_adc != nullptr) {
    LOG_SENSOR("  ", "TDIE_ADC", this->sensor_tdie_adc);
  }
  if (this->sensor_dplus_adc != nullptr) {
    LOG_SENSOR("  ", "DPLUS_ADC", this->sensor_dplus_adc);
  }
  if (this->sensor_dminus_adc != nullptr) {
    LOG_SENSOR("  ", "DMINUS_ADC", this->sensor_dminus_adc);
  }
  if (this->sensor_dplus_dac != nullptr) {
    LOG_SENSOR("  ", "DPLUS_DAC", this->sensor_dplus_dac);
  }
  if (this->sensor_dminus_dac != nullptr) {
    LOG_SENSOR("  ", "DMINUS_DAC", this->sensor_dminus_dac);
  }
  if (this->sensor_pn != nullptr) {
    LOG_SENSOR("  ", "PN", this->sensor_pn);
  }
  if (this->sensor_dev_rev != nullptr) {
    LOG_SENSOR("  ", "DEV_REV", this->sensor_dev_rev);
  }

  LOG_UPDATE_INTERVAL(this);
}

void BQ25798Sensor::update() {
  // VSYSMIN - Minimal System Voltage
  if (this->sensor_vsysmin != nullptr) {   
    this->sensor_vsysmin->publish_state(this->parent_->get_vsysmin(true));   
  }   
   
  // VREG - Charge Voltage Limit
  if (this->sensor_vreg != nullptr) {   
    this->sensor_vreg->publish_state(this->parent_->get_vreg(true));   
  }   
   
  // ICHG - Charge Current Limit
  if (this->sensor_ichg != nullptr) {   
    this->sensor_ichg->publish_state(this->parent_->get_ichg(true));   
  }   
   
  // VINDPM - Input Voltage Limit
  if (this->sensor_vindpm != nullptr) {   
    this->sensor_vindpm->publish_state(this->parent_->get_vindpm(true));   
  }   
   
  // IINDPM - Input Current Limit
  if (this->sensor_iindpm != nullptr) {   
    this->sensor_iindpm->publish_state(this->parent_->get_iindpm(true));   
  }   
   
  // VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
  if (this->sensor_vbat_lowv != nullptr) {   
    this->sensor_vbat_lowv->publish_state(this->parent_->get_vbat_lowv(true));   
  }   
   
  // IPRECHG - Precharge Current Limit
  if (this->sensor_iprechg != nullptr) {   
    this->sensor_iprechg->publish_state(this->parent_->get_iprechg(true));   
  }   
   
  // REG_RST - Reset registers to default values and reset timer
   
  // STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
   
  // ITERM - Termination Current Limit
  if (this->sensor_iterm != nullptr) {   
    this->sensor_iterm->publish_state(this->parent_->get_iterm(true));   
  }   
   
  // CELL - Battery cell count
  if (this->sensor_cell != nullptr) {   
    this->sensor_cell->publish_state(this->parent_->get_cell(true));   
  }   
   
  // TRECHG - Battery recharge delay time
  if (this->sensor_trechg != nullptr) {   
    this->sensor_trechg->publish_state(this->parent_->get_trechg(true));   
  }   
   
  // VRECHG - Battery Recharge Threshold Offset (Below VREG)
  if (this->sensor_vrechg != nullptr) {   
    this->sensor_vrechg->publish_state(this->parent_->get_vrechg(true));   
  }   
   
  // VOTG - OTG mode regulation voltage
  if (this->sensor_votg != nullptr) {   
    this->sensor_votg->publish_state(this->parent_->get_votg(true));   
  }   
   
  // PRECHG_TMR - Pre-charge safety timer setting
  if (this->sensor_prechg_tmr != nullptr) {   
    this->sensor_prechg_tmr->publish_state(this->parent_->get_prechg_tmr(true));   
  }   
   
  // IOTG - OTG current limit
  if (this->sensor_iotg != nullptr) {   
    this->sensor_iotg->publish_state(this->parent_->get_iotg(true));   
  }   
   
  // TOPOFF_TMR - Top-off timer control
  if (this->sensor_topoff_tmr != nullptr) {   
    this->sensor_topoff_tmr->publish_state(this->parent_->get_topoff_tmr(true));   
  }   
   
  // EN_TRICHG_TMR - Trickle charge timer enable
   
  // EN_PRECHG_TMR - Precharge timer enable
   
  // EN_CHG_TMR - Fast charge timer enable
   
  // CHG_TMR - Fast charge timer setting
  if (this->sensor_chg_tmr != nullptr) {   
    this->sensor_chg_tmr->publish_state(this->parent_->get_chg_tmr(true));   
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
  if (this->sensor_vbus_backup != nullptr) {   
    this->sensor_vbus_backup->publish_state(this->parent_->get_vbus_backup(true));   
  }   
   
  // VAC_OVP - Over voltage protection thresholds
  if (this->sensor_vac_ovp != nullptr) {   
    this->sensor_vac_ovp->publish_state(this->parent_->get_vac_ovp(true));   
  }   
   
  // WD_RST - I2C watch dog timer reset
   
  // WATCHDOG - Watchdog timer settings
  if (this->sensor_watchdog != nullptr) {   
    this->sensor_watchdog->publish_state(this->parent_->get_watchdog(true));   
  }   
   
  // FORCE_INDET - Force D+/D- detection
   
  // AUTO_INDET_EN - Enable automatic D+/D- detection
   
  // EN_12V - Enable 12V output in HVDCP
   
  // EN_9V - Enable 9V output in HVDCP
   
  // HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
   
  // SDRV_CTRL - Enable external Ship FET control
  if (this->sensor_sdrv_ctrl != nullptr) {   
    this->sensor_sdrv_ctrl->publish_state(this->parent_->get_sdrv_ctrl(true));   
  }   
   
  // SDRV_DLY - Delay for SDRV control
  if (this->sensor_sdrv_dly != nullptr) {   
    this->sensor_sdrv_dly->publish_state(this->parent_->get_sdrv_dly(true));   
  }   
   
  // DIS_ACDRV - Disable both AC1 and AC2 drivers
   
  // EN_OTG - Enable OTG mode
   
  // PFM_OTG_DIS - Disable PFM in OTG mode
   
  // PFM_FWD_DIS - Disable PFM in forward mode
   
  // WKUP_DLY - Wakeup (Ship FET) delay
  if (this->sensor_wkup_dly != nullptr) {   
    this->sensor_wkup_dly->publish_state(this->parent_->get_wkup_dly(true));   
  }   
   
  // DIS_LDO - Disable BATFET LDO mode in precharge state
   
  // DIS_OTG_OOA - Disable OOA in OTG mode
   
  // DIS_FWD_OOA - Disable OOA in forward mode
   
  // EN_ACDRV2 - Enable AC2 gate driver control
   
  // EN_ACDRV1 - Enable AC1 gate driver control
   
  // PWM_FREQ - PWM frequency setting
  if (this->sensor_pwm_freq != nullptr) {   
    this->sensor_pwm_freq->publish_state(this->parent_->get_pwm_freq(true));   
  }   
   
  // DIS_STAT - Disable STAT pin output
   
  // DIS_VSYS_SHORT - Disable VSYS short hiccup protection
   
  // DIS_VOTG_UVP - Disable VOTG under voltage hiccup protection
   
  // FORCE_VINDPM_DET - Force VINDPM detection (settable only when VBAT>VSYSMIN)
   
  // EN_IBUS_OCP - Enable input over current protection in forward mode
   
  // SFET_PRESENT - Ship FET present
   
  // EN_IBAT - Enable battery discharge current sensing
   
  // IBAT_REG - Battery discharge current regulation in OTG mode
  if (this->sensor_ibat_reg != nullptr) {   
    this->sensor_ibat_reg->publish_state(this->parent_->get_ibat_reg(true));   
  }   
   
  // EN_IINDPM - Enable input current regulation
   
  // EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
   
  // EN_BATOC - Enable battery discharging over current protection
   
  // VOC_PCT - 
  if (this->sensor_voc_pct != nullptr) {   
    this->sensor_voc_pct->publish_state(this->parent_->get_voc_pct(true));   
  }   
   
  // VOC_DLY - 
  if (this->sensor_voc_dly != nullptr) {   
    this->sensor_voc_dly->publish_state(this->parent_->get_voc_dly(true));   
  }   
   
  // VOC_RATE - 
  if (this->sensor_voc_rate != nullptr) {   
    this->sensor_voc_rate->publish_state(this->parent_->get_voc_rate(true));   
  }   
   
  // EN_MPPT - 
   
  // TREG - 
  if (this->sensor_treg != nullptr) {   
    this->sensor_treg->publish_state(this->parent_->get_treg(true));   
  }   
   
  // TSHUT - 
  if (this->sensor_tshut != nullptr) {   
    this->sensor_tshut->publish_state(this->parent_->get_tshut(true));   
  }   
   
  // VBUS_PD_EN - 
   
  // VAC1_PD_EN - 
   
  // VAC2_PD_EN - 
   
  // BKUP_ACFET1_ON - 
  if (this->sensor_bkup_acfet1_on != nullptr) {   
    this->sensor_bkup_acfet1_on->publish_state(this->parent_->get_bkup_acfet1_on(true));   
  }   
   
  // JEITA_VSET - 
  if (this->sensor_jeita_vset != nullptr) {   
    this->sensor_jeita_vset->publish_state(this->parent_->get_jeita_vset(true));   
  }   
   
  // JEITA_ISETH - 
  if (this->sensor_jeita_iseth != nullptr) {   
    this->sensor_jeita_iseth->publish_state(this->parent_->get_jeita_iseth(true));   
  }   
   
  // JEITA_ISETC - 
  if (this->sensor_jeita_isetc != nullptr) {   
    this->sensor_jeita_isetc->publish_state(this->parent_->get_jeita_isetc(true));   
  }   
   
  // TS_COOL - 
  if (this->sensor_ts_cool != nullptr) {   
    this->sensor_ts_cool->publish_state(this->parent_->get_ts_cool(true));   
  }   
   
  // TS_WARM - 
  if (this->sensor_ts_warm != nullptr) {   
    this->sensor_ts_warm->publish_state(this->parent_->get_ts_warm(true));   
  }   
   
  // BHOT - 
  if (this->sensor_bhot != nullptr) {   
    this->sensor_bhot->publish_state(this->parent_->get_bhot(true));   
  }   
   
  // BCOLD - 
  if (this->sensor_bcold != nullptr) {   
    this->sensor_bcold->publish_state(this->parent_->get_bcold(true));   
  }   
   
  // TS_IGNORE - 
   
  // ICO_ILIM - 
  if (this->sensor_ico_ilim != nullptr) {   
    this->sensor_ico_ilim->publish_state(this->parent_->get_ico_ilim(true));   
  }   
   
  // IINDPM_STAT - 
  if (this->sensor_iindpm_stat != nullptr) {   
    this->sensor_iindpm_stat->publish_state(this->parent_->get_iindpm_stat(true));   
  }   
   
  // VINDPM_STAT - 
  if (this->sensor_vindpm_stat != nullptr) {   
    this->sensor_vindpm_stat->publish_state(this->parent_->get_vindpm_stat(true));   
  }   
   
  // WD_STAT - 
  if (this->sensor_wd_stat != nullptr) {   
    this->sensor_wd_stat->publish_state(this->parent_->get_wd_stat(true));   
  }   
   
  // PG_STAT - 
  if (this->sensor_pg_stat != nullptr) {   
    this->sensor_pg_stat->publish_state(this->parent_->get_pg_stat(true));   
  }   
   
  // AC2_PRESENT_STAT - 
  if (this->sensor_ac2_present_stat != nullptr) {   
    this->sensor_ac2_present_stat->publish_state(this->parent_->get_ac2_present_stat(true));   
  }   
   
  // AC1_PRESENT_STAT - 
  if (this->sensor_ac1_present_stat != nullptr) {   
    this->sensor_ac1_present_stat->publish_state(this->parent_->get_ac1_present_stat(true));   
  }   
   
  // VBUS_PRESENT_STAT - 
  if (this->sensor_vbus_present_stat != nullptr) {   
    this->sensor_vbus_present_stat->publish_state(this->parent_->get_vbus_present_stat(true));   
  }   
   
  // CHG_STAT - Charge Status bits
  if (this->sensor_chg_stat != nullptr) {   
    this->sensor_chg_stat->publish_state(this->parent_->get_chg_stat(true));   
  }   
   
  // VBUS_STAT - VBUS status bits
  if (this->sensor_vbus_stat != nullptr) {   
    this->sensor_vbus_stat->publish_state(this->parent_->get_vbus_stat(true));   
  }   
   
  // BC12_DONE_STAT - 
   
  // ICO_STAT - 
  if (this->sensor_ico_stat != nullptr) {   
    this->sensor_ico_stat->publish_state(this->parent_->get_ico_stat(true));   
  }   
   
  // TREG_STAT - 
  if (this->sensor_treg_stat != nullptr) {   
    this->sensor_treg_stat->publish_state(this->parent_->get_treg_stat(true));   
  }   
   
  // DPDM_STAT - 
  if (this->sensor_dpdm_stat != nullptr) {   
    this->sensor_dpdm_stat->publish_state(this->parent_->get_dpdm_stat(true));   
  }   
   
  // VBAT_PRESENT_STAT - 
  if (this->sensor_vbat_present_stat != nullptr) {   
    this->sensor_vbat_present_stat->publish_state(this->parent_->get_vbat_present_stat(true));   
  }   
   
  // ACRB2_STAT - The ACFET2-RBFET2 status
   
  // ACRB1_STAT - The ACFET1-RBFET1 status
   
  // ADC_DONE_STAT - ADC Conversion Status
   
  // VSYS_STAT - VSYS Regulation Status
  if (this->sensor_vsys_stat != nullptr) {   
    this->sensor_vsys_stat->publish_state(this->parent_->get_vsys_stat(true));   
  }   
   
  // CHG_TMR_STAT - Fast charge timer status
  if (this->sensor_chg_tmr_stat != nullptr) {   
    this->sensor_chg_tmr_stat->publish_state(this->parent_->get_chg_tmr_stat(true));   
  }   
   
  // TRICHG_TMR_STAT - Trickle charge timer status
  if (this->sensor_trichg_tmr_stat != nullptr) {   
    this->sensor_trichg_tmr_stat->publish_state(this->parent_->get_trichg_tmr_stat(true));   
  }   
   
  // PRECHG_TMR_STAT - Pre-charge timer status
  if (this->sensor_prechg_tmr_stat != nullptr) {   
    this->sensor_prechg_tmr_stat->publish_state(this->parent_->get_prechg_tmr_stat(true));   
  }   
   
  // VBATOTG_LOW_STAT - VBAT too low to enable OTG flag
  if (this->sensor_vbatotg_low_stat != nullptr) {   
    this->sensor_vbatotg_low_stat->publish_state(this->parent_->get_vbatotg_low_stat(true));   
  }   
   
  // TS_COLD_STAT - The TS temperature is in the cold range
  if (this->sensor_ts_cold_stat != nullptr) {   
    this->sensor_ts_cold_stat->publish_state(this->parent_->get_ts_cold_stat(true));   
  }   
   
  // TS_COOL_STAT - The TS temperature is in the cool range
  if (this->sensor_ts_cool_stat != nullptr) {   
    this->sensor_ts_cool_stat->publish_state(this->parent_->get_ts_cool_stat(true));   
  }   
   
  // TS_WARM_STAT - The TS temperature is in the warm range
  if (this->sensor_ts_warm_stat != nullptr) {   
    this->sensor_ts_warm_stat->publish_state(this->parent_->get_ts_warm_stat(true));   
  }   
   
  // TS_HOT_STAT - The TS temperature is in the hot range
  if (this->sensor_ts_hot_stat != nullptr) {   
    this->sensor_ts_hot_stat->publish_state(this->parent_->get_ts_hot_stat(true));   
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
  if (this->sensor_adc_rate != nullptr) {   
    this->sensor_adc_rate->publish_state(this->parent_->get_adc_rate(true));   
  }   
   
  // ADC_SAMPLE - 
  if (this->sensor_adc_sample != nullptr) {   
    this->sensor_adc_sample->publish_state(this->parent_->get_adc_sample(true));   
  }   
   
  // ADC_AVG - 
  if (this->sensor_adc_avg != nullptr) {   
    this->sensor_adc_avg->publish_state(this->parent_->get_adc_avg(true));   
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
  if (this->sensor_ibus_adc != nullptr) {   
    this->sensor_ibus_adc->publish_state(this->parent_->get_ibus_adc(true));   
  }   
   
  // IBAT_ADC - 
  if (this->sensor_ibat_adc != nullptr) {   
    this->sensor_ibat_adc->publish_state(this->parent_->get_ibat_adc(true));   
  }   
   
  // VBUS_ADC - 
  if (this->sensor_vbus_adc != nullptr) {   
    this->sensor_vbus_adc->publish_state(this->parent_->get_vbus_adc(true));   
  }   
   
  // VAC1_ADC - 
  if (this->sensor_vac1_adc != nullptr) {   
    this->sensor_vac1_adc->publish_state(this->parent_->get_vac1_adc(true));   
  }   
   
  // VAC2_ADC - 
  if (this->sensor_vac2_adc != nullptr) {   
    this->sensor_vac2_adc->publish_state(this->parent_->get_vac2_adc(true));   
  }   
   
  // VBAT_ADC - 
  if (this->sensor_vbat_adc != nullptr) {   
    this->sensor_vbat_adc->publish_state(this->parent_->get_vbat_adc(true));   
  }   
   
  // VSYS_ADC - 
  if (this->sensor_vsys_adc != nullptr) {   
    this->sensor_vsys_adc->publish_state(this->parent_->get_vsys_adc(true));   
  }   
   
  // TS_ADC - 
  if (this->sensor_ts_adc != nullptr) {   
    this->sensor_ts_adc->publish_state(this->parent_->get_ts_adc(true));   
  }   
   
  // TDIE_ADC - TDIE ADC reading
  if (this->sensor_tdie_adc != nullptr) {   
    this->sensor_tdie_adc->publish_state(this->parent_->get_tdie_adc(true));   
  }   
   
  // DPLUS_ADC - D+ ADC reading
  if (this->sensor_dplus_adc != nullptr) {   
    this->sensor_dplus_adc->publish_state(this->parent_->get_dplus_adc(true));   
  }   
   
  // DMINUS_ADC - D- ADC reading
  if (this->sensor_dminus_adc != nullptr) {   
    this->sensor_dminus_adc->publish_state(this->parent_->get_dminus_adc(true));   
  }   
   
  // DPLUS_DAC - D+ Output Driver
  if (this->sensor_dplus_dac != nullptr) {   
    this->sensor_dplus_dac->publish_state(this->parent_->get_dplus_dac(true));   
  }   
   
  // DMINUS_DAC - D- Output Driver
  if (this->sensor_dminus_dac != nullptr) {   
    this->sensor_dminus_dac->publish_state(this->parent_->get_dminus_dac(true));   
  }   
   
  // PN - 
  if (this->sensor_pn != nullptr) {   
    this->sensor_pn->publish_state(this->parent_->get_pn(true));   
  }   
   
  // DEV_REV - 
  if (this->sensor_dev_rev != nullptr) {   
    this->sensor_dev_rev->publish_state(this->parent_->get_dev_rev(true));   
  }   
   
}


void BQ25798Sensor::assign_sensor_vsysmin(sensor::Sensor *sensor) {
  sensor_vsysmin = sensor;
}
void BQ25798Sensor::assign_sensor_vreg(sensor::Sensor *sensor) {
  sensor_vreg = sensor;
}
void BQ25798Sensor::assign_sensor_ichg(sensor::Sensor *sensor) {
  sensor_ichg = sensor;
}
void BQ25798Sensor::assign_sensor_vindpm(sensor::Sensor *sensor) {
  sensor_vindpm = sensor;
}
void BQ25798Sensor::assign_sensor_iindpm(sensor::Sensor *sensor) {
  sensor_iindpm = sensor;
}
void BQ25798Sensor::assign_sensor_vbat_lowv(sensor::Sensor *sensor) {
  sensor_vbat_lowv = sensor;
}
void BQ25798Sensor::assign_sensor_iprechg(sensor::Sensor *sensor) {
  sensor_iprechg = sensor;
}
void BQ25798Sensor::assign_sensor_iterm(sensor::Sensor *sensor) {
  sensor_iterm = sensor;
}
void BQ25798Sensor::assign_sensor_cell(sensor::Sensor *sensor) {
  sensor_cell = sensor;
}
void BQ25798Sensor::assign_sensor_trechg(sensor::Sensor *sensor) {
  sensor_trechg = sensor;
}
void BQ25798Sensor::assign_sensor_vrechg(sensor::Sensor *sensor) {
  sensor_vrechg = sensor;
}
void BQ25798Sensor::assign_sensor_votg(sensor::Sensor *sensor) {
  sensor_votg = sensor;
}
void BQ25798Sensor::assign_sensor_prechg_tmr(sensor::Sensor *sensor) {
  sensor_prechg_tmr = sensor;
}
void BQ25798Sensor::assign_sensor_iotg(sensor::Sensor *sensor) {
  sensor_iotg = sensor;
}
void BQ25798Sensor::assign_sensor_topoff_tmr(sensor::Sensor *sensor) {
  sensor_topoff_tmr = sensor;
}
void BQ25798Sensor::assign_sensor_chg_tmr(sensor::Sensor *sensor) {
  sensor_chg_tmr = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_backup(sensor::Sensor *sensor) {
  sensor_vbus_backup = sensor;
}
void BQ25798Sensor::assign_sensor_vac_ovp(sensor::Sensor *sensor) {
  sensor_vac_ovp = sensor;
}
void BQ25798Sensor::assign_sensor_watchdog(sensor::Sensor *sensor) {
  sensor_watchdog = sensor;
}
void BQ25798Sensor::assign_sensor_sdrv_ctrl(sensor::Sensor *sensor) {
  sensor_sdrv_ctrl = sensor;
}
void BQ25798Sensor::assign_sensor_sdrv_dly(sensor::Sensor *sensor) {
  sensor_sdrv_dly = sensor;
}
void BQ25798Sensor::assign_sensor_wkup_dly(sensor::Sensor *sensor) {
  sensor_wkup_dly = sensor;
}
void BQ25798Sensor::assign_sensor_pwm_freq(sensor::Sensor *sensor) {
  sensor_pwm_freq = sensor;
}
void BQ25798Sensor::assign_sensor_ibat_reg(sensor::Sensor *sensor) {
  sensor_ibat_reg = sensor;
}
void BQ25798Sensor::assign_sensor_voc_pct(sensor::Sensor *sensor) {
  sensor_voc_pct = sensor;
}
void BQ25798Sensor::assign_sensor_voc_dly(sensor::Sensor *sensor) {
  sensor_voc_dly = sensor;
}
void BQ25798Sensor::assign_sensor_voc_rate(sensor::Sensor *sensor) {
  sensor_voc_rate = sensor;
}
void BQ25798Sensor::assign_sensor_treg(sensor::Sensor *sensor) {
  sensor_treg = sensor;
}
void BQ25798Sensor::assign_sensor_tshut(sensor::Sensor *sensor) {
  sensor_tshut = sensor;
}
void BQ25798Sensor::assign_sensor_bkup_acfet1_on(sensor::Sensor *sensor) {
  sensor_bkup_acfet1_on = sensor;
}
void BQ25798Sensor::assign_sensor_jeita_vset(sensor::Sensor *sensor) {
  sensor_jeita_vset = sensor;
}
void BQ25798Sensor::assign_sensor_jeita_iseth(sensor::Sensor *sensor) {
  sensor_jeita_iseth = sensor;
}
void BQ25798Sensor::assign_sensor_jeita_isetc(sensor::Sensor *sensor) {
  sensor_jeita_isetc = sensor;
}
void BQ25798Sensor::assign_sensor_ts_cool(sensor::Sensor *sensor) {
  sensor_ts_cool = sensor;
}
void BQ25798Sensor::assign_sensor_ts_warm(sensor::Sensor *sensor) {
  sensor_ts_warm = sensor;
}
void BQ25798Sensor::assign_sensor_bhot(sensor::Sensor *sensor) {
  sensor_bhot = sensor;
}
void BQ25798Sensor::assign_sensor_bcold(sensor::Sensor *sensor) {
  sensor_bcold = sensor;
}
void BQ25798Sensor::assign_sensor_ico_ilim(sensor::Sensor *sensor) {
  sensor_ico_ilim = sensor;
}
void BQ25798Sensor::assign_sensor_iindpm_stat(sensor::Sensor *sensor) {
  sensor_iindpm_stat = sensor;
}
void BQ25798Sensor::assign_sensor_vindpm_stat(sensor::Sensor *sensor) {
  sensor_vindpm_stat = sensor;
}
void BQ25798Sensor::assign_sensor_wd_stat(sensor::Sensor *sensor) {
  sensor_wd_stat = sensor;
}
void BQ25798Sensor::assign_sensor_pg_stat(sensor::Sensor *sensor) {
  sensor_pg_stat = sensor;
}
void BQ25798Sensor::assign_sensor_ac2_present_stat(sensor::Sensor *sensor) {
  sensor_ac2_present_stat = sensor;
}
void BQ25798Sensor::assign_sensor_ac1_present_stat(sensor::Sensor *sensor) {
  sensor_ac1_present_stat = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_present_stat(sensor::Sensor *sensor) {
  sensor_vbus_present_stat = sensor;
}
void BQ25798Sensor::assign_sensor_chg_stat(sensor::Sensor *sensor) {
  sensor_chg_stat = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_stat(sensor::Sensor *sensor) {
  sensor_vbus_stat = sensor;
}
void BQ25798Sensor::assign_sensor_ico_stat(sensor::Sensor *sensor) {
  sensor_ico_stat = sensor;
}
void BQ25798Sensor::assign_sensor_treg_stat(sensor::Sensor *sensor) {
  sensor_treg_stat = sensor;
}
void BQ25798Sensor::assign_sensor_dpdm_stat(sensor::Sensor *sensor) {
  sensor_dpdm_stat = sensor;
}
void BQ25798Sensor::assign_sensor_vbat_present_stat(sensor::Sensor *sensor) {
  sensor_vbat_present_stat = sensor;
}
void BQ25798Sensor::assign_sensor_vsys_stat(sensor::Sensor *sensor) {
  sensor_vsys_stat = sensor;
}
void BQ25798Sensor::assign_sensor_chg_tmr_stat(sensor::Sensor *sensor) {
  sensor_chg_tmr_stat = sensor;
}
void BQ25798Sensor::assign_sensor_trichg_tmr_stat(sensor::Sensor *sensor) {
  sensor_trichg_tmr_stat = sensor;
}
void BQ25798Sensor::assign_sensor_prechg_tmr_stat(sensor::Sensor *sensor) {
  sensor_prechg_tmr_stat = sensor;
}
void BQ25798Sensor::assign_sensor_vbatotg_low_stat(sensor::Sensor *sensor) {
  sensor_vbatotg_low_stat = sensor;
}
void BQ25798Sensor::assign_sensor_ts_cold_stat(sensor::Sensor *sensor) {
  sensor_ts_cold_stat = sensor;
}
void BQ25798Sensor::assign_sensor_ts_cool_stat(sensor::Sensor *sensor) {
  sensor_ts_cool_stat = sensor;
}
void BQ25798Sensor::assign_sensor_ts_warm_stat(sensor::Sensor *sensor) {
  sensor_ts_warm_stat = sensor;
}
void BQ25798Sensor::assign_sensor_ts_hot_stat(sensor::Sensor *sensor) {
  sensor_ts_hot_stat = sensor;
}
void BQ25798Sensor::assign_sensor_adc_rate(sensor::Sensor *sensor) {
  sensor_adc_rate = sensor;
}
void BQ25798Sensor::assign_sensor_adc_sample(sensor::Sensor *sensor) {
  sensor_adc_sample = sensor;
}
void BQ25798Sensor::assign_sensor_adc_avg(sensor::Sensor *sensor) {
  sensor_adc_avg = sensor;
}
void BQ25798Sensor::assign_sensor_ibus_adc(sensor::Sensor *sensor) {
  sensor_ibus_adc = sensor;
}
void BQ25798Sensor::assign_sensor_ibat_adc(sensor::Sensor *sensor) {
  sensor_ibat_adc = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_adc(sensor::Sensor *sensor) {
  sensor_vbus_adc = sensor;
}
void BQ25798Sensor::assign_sensor_vac1_adc(sensor::Sensor *sensor) {
  sensor_vac1_adc = sensor;
}
void BQ25798Sensor::assign_sensor_vac2_adc(sensor::Sensor *sensor) {
  sensor_vac2_adc = sensor;
}
void BQ25798Sensor::assign_sensor_vbat_adc(sensor::Sensor *sensor) {
  sensor_vbat_adc = sensor;
}
void BQ25798Sensor::assign_sensor_vsys_adc(sensor::Sensor *sensor) {
  sensor_vsys_adc = sensor;
}
void BQ25798Sensor::assign_sensor_ts_adc(sensor::Sensor *sensor) {
  sensor_ts_adc = sensor;
}
void BQ25798Sensor::assign_sensor_tdie_adc(sensor::Sensor *sensor) {
  sensor_tdie_adc = sensor;
}
void BQ25798Sensor::assign_sensor_dplus_adc(sensor::Sensor *sensor) {
  sensor_dplus_adc = sensor;
}
void BQ25798Sensor::assign_sensor_dminus_adc(sensor::Sensor *sensor) {
  sensor_dminus_adc = sensor;
}
void BQ25798Sensor::assign_sensor_dplus_dac(sensor::Sensor *sensor) {
  sensor_dplus_dac = sensor;
}
void BQ25798Sensor::assign_sensor_dminus_dac(sensor::Sensor *sensor) {
  sensor_dminus_dac = sensor;
}
void BQ25798Sensor::assign_sensor_pn(sensor::Sensor *sensor) {
  sensor_pn = sensor;
}
void BQ25798Sensor::assign_sensor_dev_rev(sensor::Sensor *sensor) {
  sensor_dev_rev = sensor;
}

}  // namespace bq25798
}  // namespace esphome