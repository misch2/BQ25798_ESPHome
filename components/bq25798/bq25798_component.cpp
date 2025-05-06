#include "bq25798_component.h"
#include "esphome/core/log.h"
#include "esphome/core/hal.h"

namespace esphome {
namespace bq25798 {

static const char* TAG = "bq25798.component";

// FIXME
// BQ25798 bqlib = BQ25798();

void BQ25798Component::setup() {
  ESP_LOGCONFIG(TAG, "Setting up BQ25798...");

  bq25798 = new BQ25798ESPHome(this->i2c_, this->address_);
  if (!bq25798->begin()) {
    ESP_LOGE(TAG, "Failed to initialize BQ25798!");
    this->mark_failed();
    return;
  }

  //   uint16_t value;
  //   if (!this->read_byte_16(ADS1115_REGISTER_CONVERSION, &value)) {
  //     this->mark_failed();
  //     return;
  //   }
}

void BQ25798Component::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798 configuration...");

  LOG_I2C_DEVICE(this);
  if (this->is_failed()) {
    ESP_LOGE(TAG, "Communication with BQ25798 failed!");
    return;
  }

  LOG_UPDATE_INTERVAL(this);
  LOG_SENSOR("  ", "VSYSMIN", this->vsysmin_);
  LOG_SENSOR("  ", "VREG", this->vreg_);
  LOG_SENSOR("  ", "ICHG", this->ichg_);
  LOG_SENSOR("  ", "VINDPM", this->vindpm_);
  LOG_SENSOR("  ", "IINDPM", this->iindpm_);
  LOG_SENSOR("  ", "VBAT_LOWV", this->vbat_lowv_);
  LOG_SENSOR("  ", "IPRECHG", this->iprechg_);
  LOG_SENSOR("  ", "REG_RST", this->reg_rst_);
  LOG_SENSOR("  ", "STOP_WD_CHG", this->stop_wd_chg_);
  LOG_SENSOR("  ", "ITERM", this->iterm_);
  LOG_SENSOR("  ", "CELL", this->cell_);
  LOG_SENSOR("  ", "TRECHG", this->trechg_);
  LOG_SENSOR("  ", "VRECHG", this->vrechg_);
  LOG_SENSOR("  ", "VOTG", this->votg_);
  LOG_SENSOR("  ", "PRECHG_TMR", this->prechg_tmr_);
  LOG_SENSOR("  ", "IOTG", this->iotg_);
  LOG_SENSOR("  ", "TOPOFF_TMR", this->topoff_tmr_);
  LOG_SENSOR("  ", "EN_TRICHG_TMR", this->en_trichg_tmr_);
  LOG_SENSOR("  ", "EN_PRECHG_TMR", this->en_prechg_tmr_);
  LOG_SENSOR("  ", "EN_CHG_TMR", this->en_chg_tmr_);
  LOG_SENSOR("  ", "CHG_TMR", this->chg_tmr_);
  LOG_SENSOR("  ", "TMR2X_EN", this->tmr2x_en_);
  LOG_SENSOR("  ", "EN_AUTO_IBATDIS", this->en_auto_ibatdis_);
  LOG_SENSOR("  ", "FORCE_IBATDIS", this->force_ibatdis_);
  LOG_SENSOR("  ", "EN_CHG", this->en_chg_);
  LOG_SENSOR("  ", "EN_ICO", this->en_ico_);
  LOG_SENSOR("  ", "FORCE_ICO", this->force_ico_);
  LOG_SENSOR("  ", "EN_HIZ", this->en_hiz_);
  LOG_SENSOR("  ", "EN_TERM", this->en_term_);
  LOG_SENSOR("  ", "EN_BACKUP", this->en_backup_);
  LOG_SENSOR("  ", "VBUS_BACKUP", this->vbus_backup_);
  LOG_SENSOR("  ", "VAC_OVP", this->vac_ovp_);
  LOG_SENSOR("  ", "WD_RST", this->wd_rst_);
  LOG_SENSOR("  ", "WATCHDOG", this->watchdog_);
  LOG_SENSOR("  ", "FORCE_INDET", this->force_indet_);
  LOG_SENSOR("  ", "AUTO_INDET_EN", this->auto_indet_en_);
  LOG_SENSOR("  ", "EN_12V", this->en_12v_);
  LOG_SENSOR("  ", "EN_9V", this->en_9v_);
  LOG_SENSOR("  ", "HVDCP_EN", this->hvdcp_en_);
  LOG_SENSOR("  ", "SDRV_CTRL", this->sdrv_ctrl_);
  LOG_SENSOR("  ", "SDRV_DLY", this->sdrv_dly_);
  LOG_SENSOR("  ", "DIS_ACDRV", this->dis_acdrv_);
  LOG_SENSOR("  ", "EN_OTG", this->en_otg_);
  LOG_SENSOR("  ", "PFM_OTG_DIS", this->pfm_otg_dis_);
  LOG_SENSOR("  ", "PFM_FWD_DIS", this->pfm_fwd_dis_);
  LOG_SENSOR("  ", "WKUP_DLY", this->wkup_dly_);
  LOG_SENSOR("  ", "DIS_LDO", this->dis_ldo_);
  LOG_SENSOR("  ", "DIS_OTG_OOA", this->dis_otg_ooa_);
  LOG_SENSOR("  ", "DIS_FWD_OOA", this->dis_fwd_ooa_);
  LOG_SENSOR("  ", "EN_ACDRV2", this->en_acdrv2_);
  LOG_SENSOR("  ", "EN_ACDRV1", this->en_acdrv1_);
  LOG_SENSOR("  ", "PWM_FREQ", this->pwm_freq_);
  LOG_SENSOR("  ", "DIS_STAT", this->dis_stat_);
  LOG_SENSOR("  ", "DIS_VSYS_SHORT", this->dis_vsys_short_);
  LOG_SENSOR("  ", "DIS_VOTG_UVP", this->dis_votg_uvp_);
  LOG_SENSOR("  ", "FORCE_VINDPM_DET", this->force_vindpm_det_);
  LOG_SENSOR("  ", "EN_IBUS_OCP", this->en_ibus_ocp_);
  LOG_SENSOR("  ", "SFET_PRESENT", this->sfet_present_);
  LOG_SENSOR("  ", "EN_IBAT", this->en_ibat_);
  LOG_SENSOR("  ", "IBAT_REG", this->ibat_reg_);
  LOG_SENSOR("  ", "EN_IINDPM", this->en_iindpm_);
  LOG_SENSOR("  ", "EN_EXTILIM", this->en_extilim_);
  LOG_SENSOR("  ", "EN_BATOC", this->en_batoc_);
  LOG_SENSOR("  ", "VOC_PCT", this->voc_pct_);
  LOG_SENSOR("  ", "VOC_DLY", this->voc_dly_);
  LOG_SENSOR("  ", "VOC_RATE", this->voc_rate_);
  LOG_SENSOR("  ", "EN_MPPT", this->en_mppt_);
  LOG_SENSOR("  ", "TREG", this->treg_);
  LOG_SENSOR("  ", "TSHUT", this->tshut_);
  LOG_SENSOR("  ", "VBUS_PD_EN", this->vbus_pd_en_);
  LOG_SENSOR("  ", "VAC1_PD_EN", this->vac1_pd_en_);
  LOG_SENSOR("  ", "VAC2_PD_EN", this->vac2_pd_en_);
  LOG_SENSOR("  ", "BKUP_ACFET1_ON", this->bkup_acfet1_on_);
  LOG_SENSOR("  ", "JEITA_VSET", this->jeita_vset_);
  LOG_SENSOR("  ", "JEITA_ISETH", this->jeita_iseth_);
  LOG_SENSOR("  ", "JEITA_ISETC", this->jeita_isetc_);
  LOG_SENSOR("  ", "TS_COOL", this->ts_cool_);
  LOG_SENSOR("  ", "TS_WARM", this->ts_warm_);
  LOG_SENSOR("  ", "BHOT", this->bhot_);
  LOG_SENSOR("  ", "BCOLD", this->bcold_);
  LOG_SENSOR("  ", "TS_IGNORE", this->ts_ignore_);
  LOG_SENSOR("  ", "ICO_ILIM", this->ico_ilim_);
  LOG_SENSOR("  ", "IINDPM_STAT", this->iindpm_stat_);
  LOG_SENSOR("  ", "VINDPM_STAT", this->vindpm_stat_);
  LOG_SENSOR("  ", "WD_STAT", this->wd_stat_);
  LOG_SENSOR("  ", "PG_STAT", this->pg_stat_);
  LOG_SENSOR("  ", "AC2_PRESENT_STAT", this->ac2_present_stat_);
  LOG_SENSOR("  ", "AC1_PRESENT_STAT", this->ac1_present_stat_);
  LOG_SENSOR("  ", "VBUS_PRESENT_STAT", this->vbus_present_stat_);
  LOG_SENSOR("  ", "CHG_STAT", this->chg_stat_);
  LOG_SENSOR("  ", "VBUS_STAT", this->vbus_stat_);
  LOG_SENSOR("  ", "BC12_DONE_STAT", this->bc12_done_stat_);
  LOG_SENSOR("  ", "ICO_STAT", this->ico_stat_);
  LOG_SENSOR("  ", "TREG_STAT", this->treg_stat_);
  LOG_SENSOR("  ", "DPDM_STAT", this->dpdm_stat_);
  LOG_SENSOR("  ", "VBAT_PRESENT_STAT", this->vbat_present_stat_);
  LOG_SENSOR("  ", "ACRB2_STAT", this->acrb2_stat_);
  LOG_SENSOR("  ", "ACRB1_STAT", this->acrb1_stat_);
  LOG_SENSOR("  ", "ADC_DONE_STAT", this->adc_done_stat_);
  LOG_SENSOR("  ", "VSYS_STAT", this->vsys_stat_);
  LOG_SENSOR("  ", "CHG_TMR_STAT", this->chg_tmr_stat_);
  LOG_SENSOR("  ", "TRICHG_TMR_STAT", this->trichg_tmr_stat_);
  LOG_SENSOR("  ", "PRECHG_TMR_STAT", this->prechg_tmr_stat_);
  LOG_SENSOR("  ", "VBATOTG_LOW_STAT", this->vbatotg_low_stat_);
  LOG_SENSOR("  ", "TS_COLD_STAT", this->ts_cold_stat_);
  LOG_SENSOR("  ", "TS_COOL_STAT", this->ts_cool_stat_);
  LOG_SENSOR("  ", "TS_WARM_STAT", this->ts_warm_stat_);
  LOG_SENSOR("  ", "TS_HOT_STAT", this->ts_hot_stat_);
  LOG_SENSOR("  ", "IBAT_REG_STAT", this->ibat_reg_stat_);
  LOG_SENSOR("  ", "VBUS_OVP_STAT", this->vbus_ovp_stat_);
  LOG_SENSOR("  ", "VBAT_OVP_STAT", this->vbat_ovp_stat_);
  LOG_SENSOR("  ", "IBUS_OCP_STAT", this->ibus_ocp_stat_);
  LOG_SENSOR("  ", "IBAT_OCP_STAT", this->ibat_ocp_stat_);
  LOG_SENSOR("  ", "CONV_OCP_STAT", this->conv_ocp_stat_);
  LOG_SENSOR("  ", "VAC2_OVP_STAT", this->vac2_ovp_stat_);
  LOG_SENSOR("  ", "VAC1_OVP_STAT", this->vac1_ovp_stat_);
  LOG_SENSOR("  ", "VSYS_SHORT_STAT", this->vsys_short_stat_);
  LOG_SENSOR("  ", "VSYS_OVP_STAT", this->vsys_ovp_stat_);
  LOG_SENSOR("  ", "OTG_OVP_STAT", this->otg_ovp_stat_);
  LOG_SENSOR("  ", "OTG_UVP_STAT", this->otg_uvp_stat_);
  LOG_SENSOR("  ", "TSHUT_STAT", this->tshut_stat_);
  LOG_SENSOR("  ", "IINDPM_FLAG", this->iindpm_flag_);
  LOG_SENSOR("  ", "VINDPM_FLAG", this->vindpm_flag_);
  LOG_SENSOR("  ", "WD_FLAG", this->wd_flag_);
  LOG_SENSOR("  ", "POORSRC_FLAG", this->poorsrc_flag_);
  LOG_SENSOR("  ", "PG_FLAG", this->pg_flag_);
  LOG_SENSOR("  ", "AC2_PRESENT_FLAG", this->ac2_present_flag_);
  LOG_SENSOR("  ", "AC1_PRESENT_FLAG", this->ac1_present_flag_);
  LOG_SENSOR("  ", "VBUS_PRESENT_FLAG", this->vbus_present_flag_);
  LOG_SENSOR("  ", "CHG_FLAG", this->chg_flag_);
  LOG_SENSOR("  ", "ICO_FLAG", this->ico_flag_);
  LOG_SENSOR("  ", "VBUS_FLAG", this->vbus_flag_);
  LOG_SENSOR("  ", "TREG_FLAG", this->treg_flag_);
  LOG_SENSOR("  ", "VBAT_PRESENT_FLAG", this->vbat_present_flag_);
  LOG_SENSOR("  ", "BC1_2_DONE_FLAG", this->bc1_2_done_flag_);
  LOG_SENSOR("  ", "DPDM_DONE_FLAG", this->dpdm_done_flag_);
  LOG_SENSOR("  ", "ADC_DONE_FLAG", this->adc_done_flag_);
  LOG_SENSOR("  ", "VSYS_FLAG", this->vsys_flag_);
  LOG_SENSOR("  ", "CHG_TMR_FLAG", this->chg_tmr_flag_);
  LOG_SENSOR("  ", "TRICHG_TMR_FLAG", this->trichg_tmr_flag_);
  LOG_SENSOR("  ", "PRECHG_TMR_FLAG", this->prechg_tmr_flag_);
  LOG_SENSOR("  ", "TOPOFF_TMR_FLAG", this->topoff_tmr_flag_);
  LOG_SENSOR("  ", "VBATOTG_LOW_FLAG", this->vbatotg_low_flag_);
  LOG_SENSOR("  ", "TS_COLD_FLAG", this->ts_cold_flag_);
  LOG_SENSOR("  ", "TS_COOL_FLAG", this->ts_cool_flag_);
  LOG_SENSOR("  ", "TS_WARM_FLAG", this->ts_warm_flag_);
  LOG_SENSOR("  ", "TS_HOT_FLAG", this->ts_hot_flag_);
  LOG_SENSOR("  ", "IBAT_REG_FLAG", this->ibat_reg_flag_);
  LOG_SENSOR("  ", "VBUS_OVP_FLAG", this->vbus_ovp_flag_);
  LOG_SENSOR("  ", "VBAT_OVP_FLAG", this->vbat_ovp_flag_);
  LOG_SENSOR("  ", "IBUS_OCP_FLAG", this->ibus_ocp_flag_);
  LOG_SENSOR("  ", "IBAT_OCP_FLAG", this->ibat_ocp_flag_);
  LOG_SENSOR("  ", "CONV_OCP_FLAG", this->conv_ocp_flag_);
  LOG_SENSOR("  ", "VAC2_OVP_FLAG", this->vac2_ovp_flag_);
  LOG_SENSOR("  ", "VAC1_OVP_FLAG", this->vac1_ovp_flag_);
  LOG_SENSOR("  ", "VSYS_SHORT_FLAG", this->vsys_short_flag_);
  LOG_SENSOR("  ", "VSYS_OVP_FLAG", this->vsys_ovp_flag_);
  LOG_SENSOR("  ", "OTG_OVP_FLAG", this->otg_ovp_flag_);
  LOG_SENSOR("  ", "OTG_UVP_FLAG", this->otg_uvp_flag_);
  LOG_SENSOR("  ", "TSHUT_FLAG", this->tshut_flag_);
  LOG_SENSOR("  ", "ADC_EN", this->adc_en_);
  LOG_SENSOR("  ", "ADC_RATE", this->adc_rate_);
  LOG_SENSOR("  ", "ADC_SAMPLE", this->adc_sample_);
  LOG_SENSOR("  ", "ADC_AVG", this->adc_avg_);
  LOG_SENSOR("  ", "ADC_AVG_INIT", this->adc_avg_init_);
  LOG_SENSOR("  ", "IBUS_ADC_DIS", this->ibus_adc_dis_);
  LOG_SENSOR("  ", "IBAT_ADC_DIS", this->ibat_adc_dis_);
  LOG_SENSOR("  ", "VBUS_ADC_DIS", this->vbus_adc_dis_);
  LOG_SENSOR("  ", "VBAT_ADC_DIS", this->vbat_adc_dis_);
  LOG_SENSOR("  ", "VSYS_ADC_DIS", this->vsys_adc_dis_);
  LOG_SENSOR("  ", "TS_ADC_DIS", this->ts_adc_dis_);
  LOG_SENSOR("  ", "TDIE_ADC_DIS", this->tdie_adc_dis_);
  LOG_SENSOR("  ", "DPLUS_ADC_DIS", this->dplus_adc_dis_);
  LOG_SENSOR("  ", "DMINUS_ADC_DIS", this->dminus_adc_dis_);
  LOG_SENSOR("  ", "VAC2_ADC_DIS", this->vac2_adc_dis_);
  LOG_SENSOR("  ", "VAC1_ADC_DIS", this->vac1_adc_dis_);
  LOG_SENSOR("  ", "IBUS_ADC", this->ibus_adc_);
  LOG_SENSOR("  ", "IBAT_ADC", this->ibat_adc_);
  LOG_SENSOR("  ", "VBUS_ADC", this->vbus_adc_);
  LOG_SENSOR("  ", "VAC1_ADC", this->vac1_adc_);
  LOG_SENSOR("  ", "VAC2_ADC", this->vac2_adc_);
  LOG_SENSOR("  ", "VBAT_ADC", this->vbat_adc_);
  LOG_SENSOR("  ", "VSYS_ADC", this->vsys_adc_);
  LOG_SENSOR("  ", "TS_ADC", this->ts_adc_);
  LOG_SENSOR("  ", "TDIE_ADC", this->tdie_adc_);
  LOG_SENSOR("  ", "DPLUS_ADC", this->dplus_adc_);
  LOG_SENSOR("  ", "DMINUS_ADC", this->dminus_adc_);
  LOG_SENSOR("  ", "DPLUS_DAC", this->dplus_dac_);
  LOG_SENSOR("  ", "DMINUS_DAC", this->dminus_dac_);
  LOG_SENSOR("  ", "PN", this->pn_);
  LOG_SENSOR("  ", "DEV_REV", this->dev_rev_);

}

float BQ25798Component::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798Component::update() {
  // FIXME ESP_LOGD(TAG, "Updating BQ25798...");
  if (this->vsysmin_sensor_ != nullptr) {
  }

  if (this->vreg_sensor_ != nullptr) {
  }

  if (this->ichg_sensor_ != nullptr) {
  }

  if (this->vindpm_sensor_ != nullptr) {
  }

  if (this->iindpm_sensor_ != nullptr) {
  }

  if (this->vbat_lowv_sensor_ != nullptr) {
  }

  if (this->iprechg_sensor_ != nullptr) {
  }

  if (this->reg_rst_sensor_ != nullptr) {
    bool value = this->bq25798->getREG_RST();
    this->reg_rst_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->stop_wd_chg_sensor_ != nullptr) {
    bool value = this->bq25798->getSTOP_WD_CHG();
    this->stop_wd_chg_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->iterm_sensor_ != nullptr) {
  }

  if (this->cell_sensor_ != nullptr) {
  }

  if (this->trechg_sensor_ != nullptr) {
  }

  if (this->vrechg_sensor_ != nullptr) {
  }

  if (this->votg_sensor_ != nullptr) {
  }

  if (this->prechg_tmr_sensor_ != nullptr) {
  }

  if (this->iotg_sensor_ != nullptr) {
  }

  if (this->topoff_tmr_sensor_ != nullptr) {
  }

  if (this->en_trichg_tmr_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_TRICHG_TMR();
    this->en_trichg_tmr_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_prechg_tmr_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_PRECHG_TMR();
    this->en_prechg_tmr_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_chg_tmr_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_CHG_TMR();
    this->en_chg_tmr_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->chg_tmr_sensor_ != nullptr) {
  }

  if (this->tmr2x_en_sensor_ != nullptr) {
    bool value = this->bq25798->getTMR2X_EN();
    this->tmr2x_en_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_auto_ibatdis_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_AUTO_IBATDIS();
    this->en_auto_ibatdis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->force_ibatdis_sensor_ != nullptr) {
    bool value = this->bq25798->getFORCE_IBATDIS();
    this->force_ibatdis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_chg_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_CHG();
    this->en_chg_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_ico_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_ICO();
    this->en_ico_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->force_ico_sensor_ != nullptr) {
    bool value = this->bq25798->getFORCE_ICO();
    this->force_ico_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_hiz_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_HIZ();
    this->en_hiz_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_term_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_TERM();
    this->en_term_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_backup_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_BACKUP();
    this->en_backup_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vbus_backup_sensor_ != nullptr) {
  }

  if (this->vac_ovp_sensor_ != nullptr) {
  }

  if (this->wd_rst_sensor_ != nullptr) {
    bool value = this->bq25798->getWD_RST();
    this->wd_rst_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->watchdog_sensor_ != nullptr) {
  }

  if (this->force_indet_sensor_ != nullptr) {
    bool value = this->bq25798->getFORCE_INDET();
    this->force_indet_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->auto_indet_en_sensor_ != nullptr) {
    bool value = this->bq25798->getAUTO_INDET_EN();
    this->auto_indet_en_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_12v_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_12V();
    this->en_12v_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_9v_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_9V();
    this->en_9v_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->hvdcp_en_sensor_ != nullptr) {
    bool value = this->bq25798->getHVDCP_EN();
    this->hvdcp_en_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->sdrv_ctrl_sensor_ != nullptr) {
  }

  if (this->sdrv_dly_sensor_ != nullptr) {
  }

  if (this->dis_acdrv_sensor_ != nullptr) {
    bool value = this->bq25798->getDIS_ACDRV();
    this->dis_acdrv_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_otg_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_OTG();
    this->en_otg_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->pfm_otg_dis_sensor_ != nullptr) {
    bool value = this->bq25798->getPFM_OTG_DIS();
    this->pfm_otg_dis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->pfm_fwd_dis_sensor_ != nullptr) {
    bool value = this->bq25798->getPFM_FWD_DIS();
    this->pfm_fwd_dis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->wkup_dly_sensor_ != nullptr) {
  }

  if (this->dis_ldo_sensor_ != nullptr) {
    bool value = this->bq25798->getDIS_LDO();
    this->dis_ldo_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->dis_otg_ooa_sensor_ != nullptr) {
    bool value = this->bq25798->getDIS_OTG_OOA();
    this->dis_otg_ooa_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->dis_fwd_ooa_sensor_ != nullptr) {
    bool value = this->bq25798->getDIS_FWD_OOA();
    this->dis_fwd_ooa_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_acdrv2_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_ACDRV2();
    this->en_acdrv2_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_acdrv1_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_ACDRV1();
    this->en_acdrv1_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->pwm_freq_sensor_ != nullptr) {
  }

  if (this->dis_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getDIS_STAT();
    this->dis_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->dis_vsys_short_sensor_ != nullptr) {
    bool value = this->bq25798->getDIS_VSYS_SHORT();
    this->dis_vsys_short_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->dis_votg_uvp_sensor_ != nullptr) {
    bool value = this->bq25798->getDIS_VOTG_UVP();
    this->dis_votg_uvp_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->force_vindpm_det_sensor_ != nullptr) {
    bool value = this->bq25798->getFORCE_VINDPM_DET();
    this->force_vindpm_det_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_ibus_ocp_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_IBUS_OCP();
    this->en_ibus_ocp_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->sfet_present_sensor_ != nullptr) {
    bool value = this->bq25798->getSFET_PRESENT();
    this->sfet_present_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_ibat_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_IBAT();
    this->en_ibat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ibat_reg_sensor_ != nullptr) {
  }

  if (this->en_iindpm_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_IINDPM();
    this->en_iindpm_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_extilim_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_EXTILIM();
    this->en_extilim_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->en_batoc_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_BATOC();
    this->en_batoc_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->voc_pct_sensor_ != nullptr) {
  }

  if (this->voc_dly_sensor_ != nullptr) {
  }

  if (this->voc_rate_sensor_ != nullptr) {
  }

  if (this->en_mppt_sensor_ != nullptr) {
    bool value = this->bq25798->getEN_MPPT();
    this->en_mppt_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->treg_sensor_ != nullptr) {
  }

  if (this->tshut_sensor_ != nullptr) {
  }

  if (this->vbus_pd_en_sensor_ != nullptr) {
    bool value = this->bq25798->getVBUS_PD_EN();
    this->vbus_pd_en_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vac1_pd_en_sensor_ != nullptr) {
    bool value = this->bq25798->getVAC1_PD_EN();
    this->vac1_pd_en_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vac2_pd_en_sensor_ != nullptr) {
    bool value = this->bq25798->getVAC2_PD_EN();
    this->vac2_pd_en_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->bkup_acfet1_on_sensor_ != nullptr) {
  }

  if (this->jeita_vset_sensor_ != nullptr) {
  }

  if (this->jeita_iseth_sensor_ != nullptr) {
  }

  if (this->jeita_isetc_sensor_ != nullptr) {
  }

  if (this->ts_cool_sensor_ != nullptr) {
  }

  if (this->ts_warm_sensor_ != nullptr) {
  }

  if (this->bhot_sensor_ != nullptr) {
  }

  if (this->bcold_sensor_ != nullptr) {
  }

  if (this->ts_ignore_sensor_ != nullptr) {
    bool value = this->bq25798->getTS_IGNORE();
    this->ts_ignore_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ico_ilim_sensor_ != nullptr) {
  }

  if (this->iindpm_stat_sensor_ != nullptr) {
  }

  if (this->vindpm_stat_sensor_ != nullptr) {
  }

  if (this->wd_stat_sensor_ != nullptr) {
  }

  if (this->pg_stat_sensor_ != nullptr) {
  }

  if (this->ac2_present_stat_sensor_ != nullptr) {
  }

  if (this->ac1_present_stat_sensor_ != nullptr) {
  }

  if (this->vbus_present_stat_sensor_ != nullptr) {
  }

  if (this->chg_stat_sensor_ != nullptr) {
  }

  if (this->vbus_stat_sensor_ != nullptr) {
  }

  if (this->bc12_done_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getBC12_DONE_STAT();
    this->bc12_done_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ico_stat_sensor_ != nullptr) {
  }

  if (this->treg_stat_sensor_ != nullptr) {
  }

  if (this->dpdm_stat_sensor_ != nullptr) {
  }

  if (this->vbat_present_stat_sensor_ != nullptr) {
  }

  if (this->acrb2_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getACRB2_STAT();
    this->acrb2_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->acrb1_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getACRB1_STAT();
    this->acrb1_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->adc_done_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getADC_DONE_STAT();
    this->adc_done_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vsys_stat_sensor_ != nullptr) {
  }

  if (this->chg_tmr_stat_sensor_ != nullptr) {
  }

  if (this->trichg_tmr_stat_sensor_ != nullptr) {
  }

  if (this->prechg_tmr_stat_sensor_ != nullptr) {
  }

  if (this->vbatotg_low_stat_sensor_ != nullptr) {
  }

  if (this->ts_cold_stat_sensor_ != nullptr) {
  }

  if (this->ts_cool_stat_sensor_ != nullptr) {
  }

  if (this->ts_warm_stat_sensor_ != nullptr) {
  }

  if (this->ts_hot_stat_sensor_ != nullptr) {
  }

  if (this->ibat_reg_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getIBAT_REG_STAT();
    this->ibat_reg_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vbus_ovp_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getVBUS_OVP_STAT();
    this->vbus_ovp_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vbat_ovp_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getVBAT_OVP_STAT();
    this->vbat_ovp_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ibus_ocp_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getIBUS_OCP_STAT();
    this->ibus_ocp_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ibat_ocp_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getIBAT_OCP_STAT();
    this->ibat_ocp_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->conv_ocp_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getCONV_OCP_STAT();
    this->conv_ocp_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vac2_ovp_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getVAC2_OVP_STAT();
    this->vac2_ovp_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vac1_ovp_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getVAC1_OVP_STAT();
    this->vac1_ovp_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vsys_short_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getVSYS_SHORT_STAT();
    this->vsys_short_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vsys_ovp_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getVSYS_OVP_STAT();
    this->vsys_ovp_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->otg_ovp_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getOTG_OVP_STAT();
    this->otg_ovp_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->otg_uvp_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getOTG_UVP_STAT();
    this->otg_uvp_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->tshut_stat_sensor_ != nullptr) {
    bool value = this->bq25798->getTSHUT_STAT();
    this->tshut_stat_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->iindpm_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getIINDPM_FLAG();
    this->iindpm_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vindpm_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getVINDPM_FLAG();
    this->vindpm_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->wd_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getWD_FLAG();
    this->wd_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->poorsrc_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getPOORSRC_FLAG();
    this->poorsrc_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->pg_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getPG_FLAG();
    this->pg_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ac2_present_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getAC2_PRESENT_FLAG();
    this->ac2_present_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ac1_present_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getAC1_PRESENT_FLAG();
    this->ac1_present_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vbus_present_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getVBUS_PRESENT_FLAG();
    this->vbus_present_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->chg_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getCHG_FLAG();
    this->chg_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ico_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getICO_FLAG();
    this->ico_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vbus_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getVBUS_FLAG();
    this->vbus_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->treg_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getTREG_FLAG();
    this->treg_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vbat_present_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getVBAT_PRESENT_FLAG();
    this->vbat_present_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->bc1_2_done_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getBC1_2_DONE_FLAG();
    this->bc1_2_done_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->dpdm_done_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getDPDM_DONE_FLAG();
    this->dpdm_done_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->adc_done_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getADC_DONE_FLAG();
    this->adc_done_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vsys_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getVSYS_FLAG();
    this->vsys_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->chg_tmr_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getCHG_TMR_FLAG();
    this->chg_tmr_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->trichg_tmr_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getTRICHG_TMR_FLAG();
    this->trichg_tmr_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->prechg_tmr_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getPRECHG_TMR_FLAG();
    this->prechg_tmr_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->topoff_tmr_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getTOPOFF_TMR_FLAG();
    this->topoff_tmr_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vbatotg_low_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getVBATOTG_LOW_FLAG();
    this->vbatotg_low_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ts_cold_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getTS_COLD_FLAG();
    this->ts_cold_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ts_cool_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getTS_COOL_FLAG();
    this->ts_cool_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ts_warm_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getTS_WARM_FLAG();
    this->ts_warm_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ts_hot_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getTS_HOT_FLAG();
    this->ts_hot_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ibat_reg_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getIBAT_REG_FLAG();
    this->ibat_reg_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vbus_ovp_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getVBUS_OVP_FLAG();
    this->vbus_ovp_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vbat_ovp_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getVBAT_OVP_FLAG();
    this->vbat_ovp_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ibus_ocp_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getIBUS_OCP_FLAG();
    this->ibus_ocp_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ibat_ocp_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getIBAT_OCP_FLAG();
    this->ibat_ocp_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->conv_ocp_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getCONV_OCP_FLAG();
    this->conv_ocp_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vac2_ovp_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getVAC2_OVP_FLAG();
    this->vac2_ovp_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vac1_ovp_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getVAC1_OVP_FLAG();
    this->vac1_ovp_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vsys_short_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getVSYS_SHORT_FLAG();
    this->vsys_short_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vsys_ovp_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getVSYS_OVP_FLAG();
    this->vsys_ovp_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->otg_ovp_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getOTG_OVP_FLAG();
    this->otg_ovp_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->otg_uvp_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getOTG_UVP_FLAG();
    this->otg_uvp_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->tshut_flag_sensor_ != nullptr) {
    bool value = this->bq25798->getTSHUT_FLAG();
    this->tshut_flag_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->adc_en_sensor_ != nullptr) {
    bool value = this->bq25798->getADC_EN();
    this->adc_en_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->adc_rate_sensor_ != nullptr) {
  }

  if (this->adc_sample_sensor_ != nullptr) {
  }

  if (this->adc_avg_sensor_ != nullptr) {
  }

  if (this->adc_avg_init_sensor_ != nullptr) {
    bool value = this->bq25798->getADC_AVG_INIT();
    this->adc_avg_init_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ibus_adc_dis_sensor_ != nullptr) {
    bool value = this->bq25798->getIBUS_ADC_DIS();
    this->ibus_adc_dis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ibat_adc_dis_sensor_ != nullptr) {
    bool value = this->bq25798->getIBAT_ADC_DIS();
    this->ibat_adc_dis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vbus_adc_dis_sensor_ != nullptr) {
    bool value = this->bq25798->getVBUS_ADC_DIS();
    this->vbus_adc_dis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vbat_adc_dis_sensor_ != nullptr) {
    bool value = this->bq25798->getVBAT_ADC_DIS();
    this->vbat_adc_dis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vsys_adc_dis_sensor_ != nullptr) {
    bool value = this->bq25798->getVSYS_ADC_DIS();
    this->vsys_adc_dis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ts_adc_dis_sensor_ != nullptr) {
    bool value = this->bq25798->getTS_ADC_DIS();
    this->ts_adc_dis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->tdie_adc_dis_sensor_ != nullptr) {
    bool value = this->bq25798->getTDIE_ADC_DIS();
    this->tdie_adc_dis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->dplus_adc_dis_sensor_ != nullptr) {
    bool value = this->bq25798->getDPLUS_ADC_DIS();
    this->dplus_adc_dis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->dminus_adc_dis_sensor_ != nullptr) {
    bool value = this->bq25798->getDMINUS_ADC_DIS();
    this->dminus_adc_dis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vac2_adc_dis_sensor_ != nullptr) {
    bool value = this->bq25798->getVAC2_ADC_DIS();
    this->vac2_adc_dis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->vac1_adc_dis_sensor_ != nullptr) {
    bool value = this->bq25798->getVAC1_ADC_DIS();
    this->vac1_adc_dis_sensor_->publish_state(value);
    if (this->bq25798->lastError()) {
      this->status_set_warning();
      this->bq25798->clearError();
      return;
    }
  }

  if (this->ibus_adc_sensor_ != nullptr) {
  }

  if (this->ibat_adc_sensor_ != nullptr) {
  }

  if (this->vbus_adc_sensor_ != nullptr) {
  }

  if (this->vac1_adc_sensor_ != nullptr) {
  }

  if (this->vac2_adc_sensor_ != nullptr) {
  }

  if (this->vbat_adc_sensor_ != nullptr) {
  }

  if (this->vsys_adc_sensor_ != nullptr) {
  }

  if (this->ts_adc_sensor_ != nullptr) {
  }

  if (this->tdie_adc_sensor_ != nullptr) {
  }

  if (this->dplus_adc_sensor_ != nullptr) {
  }

  if (this->dminus_adc_sensor_ != nullptr) {
  }

  if (this->dplus_dac_sensor_ != nullptr) {
  }

  if (this->dminus_dac_sensor_ != nullptr) {
  }

  if (this->pn_sensor_ != nullptr) {
  }

  if (this->dev_rev_sensor_ != nullptr) {
  }

}
void BQ25798Component::set_vsysmin(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VSYSMIN", value, "mV");
  // FIXME
}
void BQ25798Component::set_vreg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VREG", value, "mV");
  // FIXME
}
void BQ25798Component::set_ichg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "ICHG", value, "mA");
  // FIXME
}
void BQ25798Component::set_vindpm(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VINDPM", value, "mV");
  // FIXME
}
void BQ25798Component::set_iindpm(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "IINDPM", value, "mA");
  // FIXME
}
void BQ25798Component::set_vbat_lowv(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VBAT_LOWV_t)", "VBAT_LOWV", value);
  // FIXME
}
void BQ25798Component::set_iprechg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "IPRECHG", value, "mA");
  // FIXME
}
void BQ25798Component::set_reg_rst(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "REG_RST", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_reg_rst() {
  ESP_LOGD(TAG, "Getting %s", "REG_RST");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_stop_wd_chg(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "STOP_WD_CHG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_stop_wd_chg() {
  ESP_LOGD(TAG, "Getting %s", "STOP_WD_CHG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_iterm(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "ITERM", value, "mA");
  // FIXME
}
void BQ25798Component::set_cell(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (CELL_t)", "CELL", value);
  // FIXME
}
void BQ25798Component::set_trechg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TRECHG_t)", "TRECHG", value);
  // FIXME
}
void BQ25798Component::set_vrechg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VRECHG", value, "mV");
  // FIXME
}
void BQ25798Component::set_votg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VOTG", value, "mV");
  // FIXME
}
void BQ25798Component::set_prechg_tmr(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (PRECHG_TMR_t)", "PRECHG_TMR", value);
  // FIXME
}
void BQ25798Component::set_iotg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "IOTG", value, "mA");
  // FIXME
}
void BQ25798Component::set_topoff_tmr(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TOPOFF_TMR_t)", "TOPOFF_TMR", value);
  // FIXME
}
void BQ25798Component::set_en_trichg_tmr(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_TRICHG_TMR", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_trichg_tmr() {
  ESP_LOGD(TAG, "Getting %s", "EN_TRICHG_TMR");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_prechg_tmr(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_PRECHG_TMR", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_prechg_tmr() {
  ESP_LOGD(TAG, "Getting %s", "EN_PRECHG_TMR");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_chg_tmr(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_CHG_TMR", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_chg_tmr() {
  ESP_LOGD(TAG, "Getting %s", "EN_CHG_TMR");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_chg_tmr(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (CHG_TMR_t)", "CHG_TMR", value);
  // FIXME
}
void BQ25798Component::set_tmr2x_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TMR2X_EN", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_tmr2x_en() {
  ESP_LOGD(TAG, "Getting %s", "TMR2X_EN");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_auto_ibatdis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_AUTO_IBATDIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_auto_ibatdis() {
  ESP_LOGD(TAG, "Getting %s", "EN_AUTO_IBATDIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_force_ibatdis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "FORCE_IBATDIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_force_ibatdis() {
  ESP_LOGD(TAG, "Getting %s", "FORCE_IBATDIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_chg(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_CHG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_chg() {
  ESP_LOGD(TAG, "Getting %s", "EN_CHG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_ico(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_ICO", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_ico() {
  ESP_LOGD(TAG, "Getting %s", "EN_ICO");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_force_ico(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "FORCE_ICO", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_force_ico() {
  ESP_LOGD(TAG, "Getting %s", "FORCE_ICO");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_hiz(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_HIZ", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_hiz() {
  ESP_LOGD(TAG, "Getting %s", "EN_HIZ");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_term(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_TERM", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_term() {
  ESP_LOGD(TAG, "Getting %s", "EN_TERM");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_backup(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_BACKUP", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_backup() {
  ESP_LOGD(TAG, "Getting %s", "EN_BACKUP");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vbus_backup(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VBUS_BACKUP_t)", "VBUS_BACKUP", value);
  // FIXME
}
void BQ25798Component::set_vac_ovp(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VAC_OVP_t)", "VAC_OVP", value);
  // FIXME
}
void BQ25798Component::set_wd_rst(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "WD_RST", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_wd_rst() {
  ESP_LOGD(TAG, "Getting %s", "WD_RST");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_watchdog(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (WATCHDOG_t)", "WATCHDOG", value);
  // FIXME
}
void BQ25798Component::set_force_indet(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "FORCE_INDET", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_force_indet() {
  ESP_LOGD(TAG, "Getting %s", "FORCE_INDET");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_auto_indet_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "AUTO_INDET_EN", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_auto_indet_en() {
  ESP_LOGD(TAG, "Getting %s", "AUTO_INDET_EN");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_12v(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_12V", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_12v() {
  ESP_LOGD(TAG, "Getting %s", "EN_12V");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_9v(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_9V", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_9v() {
  ESP_LOGD(TAG, "Getting %s", "EN_9V");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_hvdcp_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "HVDCP_EN", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_hvdcp_en() {
  ESP_LOGD(TAG, "Getting %s", "HVDCP_EN");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_sdrv_ctrl(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (SDRV_CTRL_t)", "SDRV_CTRL", value);
  // FIXME
}
void BQ25798Component::set_sdrv_dly(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (SDRV_DLY_t)", "SDRV_DLY", value);
  // FIXME
}
void BQ25798Component::set_dis_acdrv(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_ACDRV", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_dis_acdrv() {
  ESP_LOGD(TAG, "Getting %s", "DIS_ACDRV");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_otg(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_OTG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_otg() {
  ESP_LOGD(TAG, "Getting %s", "EN_OTG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_pfm_otg_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "PFM_OTG_DIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_pfm_otg_dis() {
  ESP_LOGD(TAG, "Getting %s", "PFM_OTG_DIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_pfm_fwd_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "PFM_FWD_DIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_pfm_fwd_dis() {
  ESP_LOGD(TAG, "Getting %s", "PFM_FWD_DIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_wkup_dly(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (WKUP_DLY_t)", "WKUP_DLY", value);
  // FIXME
}
void BQ25798Component::set_dis_ldo(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_LDO", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_dis_ldo() {
  ESP_LOGD(TAG, "Getting %s", "DIS_LDO");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_dis_otg_ooa(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_OTG_OOA", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_dis_otg_ooa() {
  ESP_LOGD(TAG, "Getting %s", "DIS_OTG_OOA");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_dis_fwd_ooa(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_FWD_OOA", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_dis_fwd_ooa() {
  ESP_LOGD(TAG, "Getting %s", "DIS_FWD_OOA");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_acdrv2(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_ACDRV2", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_acdrv2() {
  ESP_LOGD(TAG, "Getting %s", "EN_ACDRV2");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_acdrv1(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_ACDRV1", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_acdrv1() {
  ESP_LOGD(TAG, "Getting %s", "EN_ACDRV1");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_pwm_freq(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (PWM_FREQ_t)", "PWM_FREQ", value);
  // FIXME
}
void BQ25798Component::set_dis_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_dis_stat() {
  ESP_LOGD(TAG, "Getting %s", "DIS_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_dis_vsys_short(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_VSYS_SHORT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_dis_vsys_short() {
  ESP_LOGD(TAG, "Getting %s", "DIS_VSYS_SHORT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_dis_votg_uvp(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_VOTG_UVP", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_dis_votg_uvp() {
  ESP_LOGD(TAG, "Getting %s", "DIS_VOTG_UVP");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_force_vindpm_det(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "FORCE_VINDPM_DET", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_force_vindpm_det() {
  ESP_LOGD(TAG, "Getting %s", "FORCE_VINDPM_DET");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_ibus_ocp(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_IBUS_OCP", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_ibus_ocp() {
  ESP_LOGD(TAG, "Getting %s", "EN_IBUS_OCP");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_sfet_present(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "SFET_PRESENT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_sfet_present() {
  ESP_LOGD(TAG, "Getting %s", "SFET_PRESENT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_ibat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_IBAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_ibat() {
  ESP_LOGD(TAG, "Getting %s", "EN_IBAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ibat_reg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (IBAT_REG_t)", "IBAT_REG", value);
  // FIXME
}
void BQ25798Component::set_en_iindpm(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_IINDPM", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_iindpm() {
  ESP_LOGD(TAG, "Getting %s", "EN_IINDPM");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_extilim(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_EXTILIM", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_extilim() {
  ESP_LOGD(TAG, "Getting %s", "EN_EXTILIM");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_en_batoc(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_BATOC", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_batoc() {
  ESP_LOGD(TAG, "Getting %s", "EN_BATOC");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_voc_pct(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VOC_PCT_t)", "VOC_PCT", value);
  // FIXME
}
void BQ25798Component::set_voc_dly(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VOC_DLY_t)", "VOC_DLY", value);
  // FIXME
}
void BQ25798Component::set_voc_rate(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VOC_RATE_t)", "VOC_RATE", value);
  // FIXME
}
void BQ25798Component::set_en_mppt(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_MPPT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_en_mppt() {
  ESP_LOGD(TAG, "Getting %s", "EN_MPPT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_treg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TREG_t)", "TREG", value);
  // FIXME
}
void BQ25798Component::set_tshut(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TSHUT_t)", "TSHUT", value);
  // FIXME
}
void BQ25798Component::set_vbus_pd_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_PD_EN", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vbus_pd_en() {
  ESP_LOGD(TAG, "Getting %s", "VBUS_PD_EN");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vac1_pd_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC1_PD_EN", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vac1_pd_en() {
  ESP_LOGD(TAG, "Getting %s", "VAC1_PD_EN");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vac2_pd_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC2_PD_EN", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vac2_pd_en() {
  ESP_LOGD(TAG, "Getting %s", "VAC2_PD_EN");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_bkup_acfet1_on(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (BKUP_ACFET1_ON_t)", "BKUP_ACFET1_ON", value);
  // FIXME
}
void BQ25798Component::set_jeita_vset(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (JEITA_VSET_t)", "JEITA_VSET", value);
  // FIXME
}
void BQ25798Component::set_jeita_iseth(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (JEITA_ISETH_t)", "JEITA_ISETH", value);
  // FIXME
}
void BQ25798Component::set_jeita_isetc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (JEITA_ISETC_t)", "JEITA_ISETC", value);
  // FIXME
}
void BQ25798Component::set_ts_cool(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TS_COOL_t)", "TS_COOL", value);
  // FIXME
}
void BQ25798Component::set_ts_warm(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TS_WARM_t)", "TS_WARM", value);
  // FIXME
}
void BQ25798Component::set_bhot(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (BHOT_t)", "BHOT", value);
  // FIXME
}
void BQ25798Component::set_bcold(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (BCOLD_t)", "BCOLD", value);
  // FIXME
}
void BQ25798Component::set_ts_ignore(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_IGNORE", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ts_ignore() {
  ESP_LOGD(TAG, "Getting %s", "TS_IGNORE");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ico_ilim(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "ICO_ILIM", value, "mA");
  // FIXME
}
void BQ25798Component::set_iindpm_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (IINDPM_STAT_t)", "IINDPM_STAT", value);
  // FIXME
}
void BQ25798Component::set_vindpm_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VINDPM_STAT_t)", "VINDPM_STAT", value);
  // FIXME
}
void BQ25798Component::set_wd_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (WD_STAT_t)", "WD_STAT", value);
  // FIXME
}
void BQ25798Component::set_pg_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (PG_STAT_t)", "PG_STAT", value);
  // FIXME
}
void BQ25798Component::set_ac2_present_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (AC2_PRESENT_STAT_t)", "AC2_PRESENT_STAT", value);
  // FIXME
}
void BQ25798Component::set_ac1_present_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (AC1_PRESENT_STAT_t)", "AC1_PRESENT_STAT", value);
  // FIXME
}
void BQ25798Component::set_vbus_present_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VBUS_PRESENT_STAT_t)", "VBUS_PRESENT_STAT", value);
  // FIXME
}
void BQ25798Component::set_chg_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (CHG_STAT_t)", "CHG_STAT", value);
  // FIXME
}
void BQ25798Component::set_vbus_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VBUS_STAT_t)", "VBUS_STAT", value);
  // FIXME
}
void BQ25798Component::set_bc12_done_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "BC12_DONE_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_bc12_done_stat() {
  ESP_LOGD(TAG, "Getting %s", "BC12_DONE_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ico_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (ICO_STAT_t)", "ICO_STAT", value);
  // FIXME
}
void BQ25798Component::set_treg_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TREG_STAT_t)", "TREG_STAT", value);
  // FIXME
}
void BQ25798Component::set_dpdm_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (DPDM_STAT_t)", "DPDM_STAT", value);
  // FIXME
}
void BQ25798Component::set_vbat_present_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VBAT_PRESENT_STAT_t)", "VBAT_PRESENT_STAT", value);
  // FIXME
}
void BQ25798Component::set_acrb2_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ACRB2_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_acrb2_stat() {
  ESP_LOGD(TAG, "Getting %s", "ACRB2_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_acrb1_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ACRB1_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_acrb1_stat() {
  ESP_LOGD(TAG, "Getting %s", "ACRB1_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_adc_done_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ADC_DONE_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_adc_done_stat() {
  ESP_LOGD(TAG, "Getting %s", "ADC_DONE_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vsys_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VSYS_STAT_t)", "VSYS_STAT", value);
  // FIXME
}
void BQ25798Component::set_chg_tmr_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (CHG_TMR_STAT_t)", "CHG_TMR_STAT", value);
  // FIXME
}
void BQ25798Component::set_trichg_tmr_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TRICHG_TMR_STAT_t)", "TRICHG_TMR_STAT", value);
  // FIXME
}
void BQ25798Component::set_prechg_tmr_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (PRECHG_TMR_STAT_t)", "PRECHG_TMR_STAT", value);
  // FIXME
}
void BQ25798Component::set_vbatotg_low_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (VBATOTG_LOW_STAT_t)", "VBATOTG_LOW_STAT", value);
  // FIXME
}
void BQ25798Component::set_ts_cold_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TS_COLD_STAT_t)", "TS_COLD_STAT", value);
  // FIXME
}
void BQ25798Component::set_ts_cool_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TS_COOL_STAT_t)", "TS_COOL_STAT", value);
  // FIXME
}
void BQ25798Component::set_ts_warm_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TS_WARM_STAT_t)", "TS_WARM_STAT", value);
  // FIXME
}
void BQ25798Component::set_ts_hot_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (TS_HOT_STAT_t)", "TS_HOT_STAT", value);
  // FIXME
}
void BQ25798Component::set_ibat_reg_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_REG_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ibat_reg_stat() {
  ESP_LOGD(TAG, "Getting %s", "IBAT_REG_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vbus_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_OVP_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vbus_ovp_stat() {
  ESP_LOGD(TAG, "Getting %s", "VBUS_OVP_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vbat_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBAT_OVP_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vbat_ovp_stat() {
  ESP_LOGD(TAG, "Getting %s", "VBAT_OVP_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ibus_ocp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBUS_OCP_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ibus_ocp_stat() {
  ESP_LOGD(TAG, "Getting %s", "IBUS_OCP_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ibat_ocp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_OCP_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ibat_ocp_stat() {
  ESP_LOGD(TAG, "Getting %s", "IBAT_OCP_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_conv_ocp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "CONV_OCP_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_conv_ocp_stat() {
  ESP_LOGD(TAG, "Getting %s", "CONV_OCP_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vac2_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC2_OVP_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vac2_ovp_stat() {
  ESP_LOGD(TAG, "Getting %s", "VAC2_OVP_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vac1_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC1_OVP_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vac1_ovp_stat() {
  ESP_LOGD(TAG, "Getting %s", "VAC1_OVP_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vsys_short_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_SHORT_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vsys_short_stat() {
  ESP_LOGD(TAG, "Getting %s", "VSYS_SHORT_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vsys_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_OVP_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vsys_ovp_stat() {
  ESP_LOGD(TAG, "Getting %s", "VSYS_OVP_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_otg_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "OTG_OVP_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_otg_ovp_stat() {
  ESP_LOGD(TAG, "Getting %s", "OTG_OVP_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_otg_uvp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "OTG_UVP_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_otg_uvp_stat() {
  ESP_LOGD(TAG, "Getting %s", "OTG_UVP_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_tshut_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TSHUT_STAT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_tshut_stat() {
  ESP_LOGD(TAG, "Getting %s", "TSHUT_STAT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_iindpm_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IINDPM_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_iindpm_flag() {
  ESP_LOGD(TAG, "Getting %s", "IINDPM_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vindpm_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VINDPM_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vindpm_flag() {
  ESP_LOGD(TAG, "Getting %s", "VINDPM_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_wd_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "WD_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_wd_flag() {
  ESP_LOGD(TAG, "Getting %s", "WD_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_poorsrc_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "POORSRC_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_poorsrc_flag() {
  ESP_LOGD(TAG, "Getting %s", "POORSRC_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_pg_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "PG_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_pg_flag() {
  ESP_LOGD(TAG, "Getting %s", "PG_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ac2_present_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "AC2_PRESENT_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ac2_present_flag() {
  ESP_LOGD(TAG, "Getting %s", "AC2_PRESENT_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ac1_present_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "AC1_PRESENT_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ac1_present_flag() {
  ESP_LOGD(TAG, "Getting %s", "AC1_PRESENT_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vbus_present_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_PRESENT_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vbus_present_flag() {
  ESP_LOGD(TAG, "Getting %s", "VBUS_PRESENT_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_chg_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "CHG_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_chg_flag() {
  ESP_LOGD(TAG, "Getting %s", "CHG_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ico_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ICO_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ico_flag() {
  ESP_LOGD(TAG, "Getting %s", "ICO_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vbus_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vbus_flag() {
  ESP_LOGD(TAG, "Getting %s", "VBUS_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_treg_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TREG_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_treg_flag() {
  ESP_LOGD(TAG, "Getting %s", "TREG_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vbat_present_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBAT_PRESENT_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vbat_present_flag() {
  ESP_LOGD(TAG, "Getting %s", "VBAT_PRESENT_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_bc1_2_done_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "BC1_2_DONE_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_bc1_2_done_flag() {
  ESP_LOGD(TAG, "Getting %s", "BC1_2_DONE_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_dpdm_done_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DPDM_DONE_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_dpdm_done_flag() {
  ESP_LOGD(TAG, "Getting %s", "DPDM_DONE_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_adc_done_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ADC_DONE_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_adc_done_flag() {
  ESP_LOGD(TAG, "Getting %s", "ADC_DONE_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vsys_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vsys_flag() {
  ESP_LOGD(TAG, "Getting %s", "VSYS_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_chg_tmr_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "CHG_TMR_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_chg_tmr_flag() {
  ESP_LOGD(TAG, "Getting %s", "CHG_TMR_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_trichg_tmr_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TRICHG_TMR_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_trichg_tmr_flag() {
  ESP_LOGD(TAG, "Getting %s", "TRICHG_TMR_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_prechg_tmr_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "PRECHG_TMR_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_prechg_tmr_flag() {
  ESP_LOGD(TAG, "Getting %s", "PRECHG_TMR_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_topoff_tmr_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TOPOFF_TMR_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_topoff_tmr_flag() {
  ESP_LOGD(TAG, "Getting %s", "TOPOFF_TMR_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vbatotg_low_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBATOTG_LOW_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vbatotg_low_flag() {
  ESP_LOGD(TAG, "Getting %s", "VBATOTG_LOW_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ts_cold_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_COLD_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ts_cold_flag() {
  ESP_LOGD(TAG, "Getting %s", "TS_COLD_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ts_cool_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_COOL_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ts_cool_flag() {
  ESP_LOGD(TAG, "Getting %s", "TS_COOL_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ts_warm_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_WARM_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ts_warm_flag() {
  ESP_LOGD(TAG, "Getting %s", "TS_WARM_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ts_hot_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_HOT_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ts_hot_flag() {
  ESP_LOGD(TAG, "Getting %s", "TS_HOT_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ibat_reg_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_REG_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ibat_reg_flag() {
  ESP_LOGD(TAG, "Getting %s", "IBAT_REG_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vbus_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_OVP_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vbus_ovp_flag() {
  ESP_LOGD(TAG, "Getting %s", "VBUS_OVP_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vbat_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBAT_OVP_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vbat_ovp_flag() {
  ESP_LOGD(TAG, "Getting %s", "VBAT_OVP_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ibus_ocp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBUS_OCP_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ibus_ocp_flag() {
  ESP_LOGD(TAG, "Getting %s", "IBUS_OCP_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ibat_ocp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_OCP_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ibat_ocp_flag() {
  ESP_LOGD(TAG, "Getting %s", "IBAT_OCP_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_conv_ocp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "CONV_OCP_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_conv_ocp_flag() {
  ESP_LOGD(TAG, "Getting %s", "CONV_OCP_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vac2_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC2_OVP_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vac2_ovp_flag() {
  ESP_LOGD(TAG, "Getting %s", "VAC2_OVP_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vac1_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC1_OVP_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vac1_ovp_flag() {
  ESP_LOGD(TAG, "Getting %s", "VAC1_OVP_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vsys_short_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_SHORT_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vsys_short_flag() {
  ESP_LOGD(TAG, "Getting %s", "VSYS_SHORT_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vsys_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_OVP_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vsys_ovp_flag() {
  ESP_LOGD(TAG, "Getting %s", "VSYS_OVP_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_otg_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "OTG_OVP_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_otg_ovp_flag() {
  ESP_LOGD(TAG, "Getting %s", "OTG_OVP_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_otg_uvp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "OTG_UVP_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_otg_uvp_flag() {
  ESP_LOGD(TAG, "Getting %s", "OTG_UVP_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_tshut_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TSHUT_FLAG", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_tshut_flag() {
  ESP_LOGD(TAG, "Getting %s", "TSHUT_FLAG");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_adc_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ADC_EN", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_adc_en() {
  ESP_LOGD(TAG, "Getting %s", "ADC_EN");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_adc_rate(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (ADC_RATE_t)", "ADC_RATE", value);
  // FIXME
}
void BQ25798Component::set_adc_sample(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (ADC_SAMPLE_t)", "ADC_SAMPLE", value);
  // FIXME
}
void BQ25798Component::set_adc_avg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (ADC_AVG_t)", "ADC_AVG", value);
  // FIXME
}
void BQ25798Component::set_adc_avg_init(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ADC_AVG_INIT", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_adc_avg_init() {
  ESP_LOGD(TAG, "Getting %s", "ADC_AVG_INIT");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ibus_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBUS_ADC_DIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ibus_adc_dis() {
  ESP_LOGD(TAG, "Getting %s", "IBUS_ADC_DIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ibat_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_ADC_DIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ibat_adc_dis() {
  ESP_LOGD(TAG, "Getting %s", "IBAT_ADC_DIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vbus_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_ADC_DIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vbus_adc_dis() {
  ESP_LOGD(TAG, "Getting %s", "VBUS_ADC_DIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vbat_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBAT_ADC_DIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vbat_adc_dis() {
  ESP_LOGD(TAG, "Getting %s", "VBAT_ADC_DIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vsys_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_ADC_DIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vsys_adc_dis() {
  ESP_LOGD(TAG, "Getting %s", "VSYS_ADC_DIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ts_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_ADC_DIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_ts_adc_dis() {
  ESP_LOGD(TAG, "Getting %s", "TS_ADC_DIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_tdie_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TDIE_ADC_DIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_tdie_adc_dis() {
  ESP_LOGD(TAG, "Getting %s", "TDIE_ADC_DIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_dplus_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DPLUS_ADC_DIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_dplus_adc_dis() {
  ESP_LOGD(TAG, "Getting %s", "DPLUS_ADC_DIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_dminus_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DMINUS_ADC_DIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_dminus_adc_dis() {
  ESP_LOGD(TAG, "Getting %s", "DMINUS_ADC_DIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vac2_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC2_ADC_DIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vac2_adc_dis() {
  ESP_LOGD(TAG, "Getting %s", "VAC2_ADC_DIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_vac1_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC1_ADC_DIS", value ? "True" : "False");
  // FIXME
}
bool BQ25798Component::get_vac1_adc_dis() {
  ESP_LOGD(TAG, "Getting %s", "VAC1_ADC_DIS");
  return false;  // FIXME
  // FIXME
}
void BQ25798Component::set_ibus_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "IBUS_ADC", value, "mA");
  // FIXME
}
void BQ25798Component::set_ibat_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "IBAT_ADC", value, "mA");
  // FIXME
}
void BQ25798Component::set_vbus_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VBUS_ADC", value, "mV");
  // FIXME
}
void BQ25798Component::set_vac1_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VAC1_ADC", value, "mV");
  // FIXME
}
void BQ25798Component::set_vac2_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VAC2_ADC", value, "mV");
  // FIXME
}
void BQ25798Component::set_vbat_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VBAT_ADC", value, "mV");
  // FIXME
}
void BQ25798Component::set_vsys_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "VSYS_ADC", value, "mV");
  // FIXME
}
void BQ25798Component::set_ts_adc(float value) {
  ESP_LOGD(TAG, "Setting %s to %f %s", "TS_ADC", value, "%");
  // FIXME
}
void BQ25798Component::set_tdie_adc(float value) {
  ESP_LOGD(TAG, "Setting %s to %f %s", "TDIE_ADC", value, "degC");
  // FIXME
}
void BQ25798Component::set_dplus_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "DPLUS_ADC", value, "mV");
  // FIXME
}
void BQ25798Component::set_dminus_adc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "DMINUS_ADC", value, "mV");
  // FIXME
}
void BQ25798Component::set_dplus_dac(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (DPLUS_DAC_t)", "DPLUS_DAC", value);
  // FIXME
}
void BQ25798Component::set_dminus_dac(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (DMINUS_DAC_t)", "DMINUS_DAC", value);
  // FIXME
}
void BQ25798Component::set_pn(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (PN_t)", "PN", value);
  // FIXME
}
void BQ25798Component::set_dev_rev(int value) {
  ESP_LOGD(TAG, "Setting %s to %d (DEV_REV_t)", "DEV_REV", value);
  // FIXME
}

}  // namespace bq25798
}  // namespace esphome