
#include "bq25798_binary_sensor.h"

#include "esphome/core/log.h"

namespace esphome {
namespace bq25798 {

static const char* const TAG = "bq25798.binary_sensor";

float BQ25798BinarySensor::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798BinarySensor::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798BinarySensor configuration...");

  if (this->binary_sensor_reg_rst_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "REG_RST", this->binary_sensor_reg_rst_);
  }
  if (this->binary_sensor_stop_wd_chg_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "STOP_WD_CHG", this->binary_sensor_stop_wd_chg_);
  }
  if (this->binary_sensor_prechg_tmr_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "PRECHG_TMR", this->binary_sensor_prechg_tmr_);
  }
  if (this->binary_sensor_en_trichg_tmr_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_TRICHG_TMR", this->binary_sensor_en_trichg_tmr_);
  }
  if (this->binary_sensor_en_prechg_tmr_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_PRECHG_TMR", this->binary_sensor_en_prechg_tmr_);
  }
  if (this->binary_sensor_en_chg_tmr_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_CHG_TMR", this->binary_sensor_en_chg_tmr_);
  }
  if (this->binary_sensor_tmr2x_en_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TMR2X_EN", this->binary_sensor_tmr2x_en_);
  }
  if (this->binary_sensor_en_auto_ibatdis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_AUTO_IBATDIS", this->binary_sensor_en_auto_ibatdis_);
  }
  if (this->binary_sensor_force_ibatdis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "FORCE_IBATDIS", this->binary_sensor_force_ibatdis_);
  }
  if (this->binary_sensor_en_chg_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_CHG", this->binary_sensor_en_chg_);
  }
  if (this->binary_sensor_en_ico_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_ICO", this->binary_sensor_en_ico_);
  }
  if (this->binary_sensor_force_ico_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "FORCE_ICO", this->binary_sensor_force_ico_);
  }
  if (this->binary_sensor_en_hiz_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_HIZ", this->binary_sensor_en_hiz_);
  }
  if (this->binary_sensor_en_term_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_TERM", this->binary_sensor_en_term_);
  }
  if (this->binary_sensor_en_backup_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_BACKUP", this->binary_sensor_en_backup_);
  }
  if (this->binary_sensor_wd_rst_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "WD_RST", this->binary_sensor_wd_rst_);
  }
  if (this->binary_sensor_force_indet_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "FORCE_INDET", this->binary_sensor_force_indet_);
  }
  if (this->binary_sensor_auto_indet_en_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "AUTO_INDET_EN", this->binary_sensor_auto_indet_en_);
  }
  if (this->binary_sensor_en_12v_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_12V", this->binary_sensor_en_12v_);
  }
  if (this->binary_sensor_en_9v_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_9V", this->binary_sensor_en_9v_);
  }
  if (this->binary_sensor_hvdcp_en_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "HVDCP_EN", this->binary_sensor_hvdcp_en_);
  }
  if (this->binary_sensor_sdrv_dly_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "SDRV_DLY", this->binary_sensor_sdrv_dly_);
  }
  if (this->binary_sensor_dis_acdrv_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "DIS_ACDRV", this->binary_sensor_dis_acdrv_);
  }
  if (this->binary_sensor_en_otg_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_OTG", this->binary_sensor_en_otg_);
  }
  if (this->binary_sensor_pfm_otg_dis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "PFM_OTG_DIS", this->binary_sensor_pfm_otg_dis_);
  }
  if (this->binary_sensor_pfm_fwd_dis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "PFM_FWD_DIS", this->binary_sensor_pfm_fwd_dis_);
  }
  if (this->binary_sensor_wkup_dly_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "WKUP_DLY", this->binary_sensor_wkup_dly_);
  }
  if (this->binary_sensor_dis_ldo_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "DIS_LDO", this->binary_sensor_dis_ldo_);
  }
  if (this->binary_sensor_dis_otg_ooa_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "DIS_OTG_OOA", this->binary_sensor_dis_otg_ooa_);
  }
  if (this->binary_sensor_dis_fwd_ooa_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "DIS_FWD_OOA", this->binary_sensor_dis_fwd_ooa_);
  }
  if (this->binary_sensor_en_acdrv2_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_ACDRV2", this->binary_sensor_en_acdrv2_);
  }
  if (this->binary_sensor_en_acdrv1_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_ACDRV1", this->binary_sensor_en_acdrv1_);
  }
  if (this->binary_sensor_pwm_freq_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "PWM_FREQ", this->binary_sensor_pwm_freq_);
  }
  if (this->binary_sensor_dis_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "DIS_STAT", this->binary_sensor_dis_stat_);
  }
  if (this->binary_sensor_dis_vsys_short_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "DIS_VSYS_SHORT", this->binary_sensor_dis_vsys_short_);
  }
  if (this->binary_sensor_dis_votg_uvp_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "DIS_VOTG_UVP", this->binary_sensor_dis_votg_uvp_);
  }
  if (this->binary_sensor_force_vindpm_det_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "FORCE_VINDPM_DET", this->binary_sensor_force_vindpm_det_);
  }
  if (this->binary_sensor_en_ibus_ocp_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_IBUS_OCP", this->binary_sensor_en_ibus_ocp_);
  }
  if (this->binary_sensor_sfet_present_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "SFET_PRESENT", this->binary_sensor_sfet_present_);
  }
  if (this->binary_sensor_en_ibat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_IBAT", this->binary_sensor_en_ibat_);
  }
  if (this->binary_sensor_en_iindpm_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_IINDPM", this->binary_sensor_en_iindpm_);
  }
  if (this->binary_sensor_en_extilim_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_EXTILIM", this->binary_sensor_en_extilim_);
  }
  if (this->binary_sensor_en_batoc_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_BATOC", this->binary_sensor_en_batoc_);
  }
  if (this->binary_sensor_en_mppt_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "EN_MPPT", this->binary_sensor_en_mppt_);
  }
  if (this->binary_sensor_vbus_pd_en_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VBUS_PD_EN", this->binary_sensor_vbus_pd_en_);
  }
  if (this->binary_sensor_vac1_pd_en_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VAC1_PD_EN", this->binary_sensor_vac1_pd_en_);
  }
  if (this->binary_sensor_vac2_pd_en_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VAC2_PD_EN", this->binary_sensor_vac2_pd_en_);
  }
  if (this->binary_sensor_bkup_acfet1_on_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "BKUP_ACFET1_ON", this->binary_sensor_bkup_acfet1_on_);
  }
  if (this->binary_sensor_bcold_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "BCOLD", this->binary_sensor_bcold_);
  }
  if (this->binary_sensor_ts_ignore_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TS_IGNORE", this->binary_sensor_ts_ignore_);
  }
  if (this->binary_sensor_iindpm_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "IINDPM_STAT", this->binary_sensor_iindpm_stat_);
  }
  if (this->binary_sensor_vindpm_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VINDPM_STAT", this->binary_sensor_vindpm_stat_);
  }
  if (this->binary_sensor_wd_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "WD_STAT", this->binary_sensor_wd_stat_);
  }
  if (this->binary_sensor_pg_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "PG_STAT", this->binary_sensor_pg_stat_);
  }
  if (this->binary_sensor_ac2_present_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "AC2_PRESENT_STAT", this->binary_sensor_ac2_present_stat_);
  }
  if (this->binary_sensor_ac1_present_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "AC1_PRESENT_STAT", this->binary_sensor_ac1_present_stat_);
  }
  if (this->binary_sensor_vbus_present_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VBUS_PRESENT_STAT", this->binary_sensor_vbus_present_stat_);
  }
  if (this->binary_sensor_bc12_done_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "BC12_DONE_STAT", this->binary_sensor_bc12_done_stat_);
  }
  if (this->binary_sensor_treg_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TREG_STAT", this->binary_sensor_treg_stat_);
  }
  if (this->binary_sensor_dpdm_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "DPDM_STAT", this->binary_sensor_dpdm_stat_);
  }
  if (this->binary_sensor_vbat_present_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VBAT_PRESENT_STAT", this->binary_sensor_vbat_present_stat_);
  }
  if (this->binary_sensor_acrb2_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "ACRB2_STAT", this->binary_sensor_acrb2_stat_);
  }
  if (this->binary_sensor_acrb1_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "ACRB1_STAT", this->binary_sensor_acrb1_stat_);
  }
  if (this->binary_sensor_adc_done_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "ADC_DONE_STAT", this->binary_sensor_adc_done_stat_);
  }
  if (this->binary_sensor_vsys_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VSYS_STAT", this->binary_sensor_vsys_stat_);
  }
  if (this->binary_sensor_chg_tmr_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "CHG_TMR_STAT", this->binary_sensor_chg_tmr_stat_);
  }
  if (this->binary_sensor_trichg_tmr_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TRICHG_TMR_STAT", this->binary_sensor_trichg_tmr_stat_);
  }
  if (this->binary_sensor_prechg_tmr_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "PRECHG_TMR_STAT", this->binary_sensor_prechg_tmr_stat_);
  }
  if (this->binary_sensor_vbatotg_low_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VBATOTG_LOW_STAT", this->binary_sensor_vbatotg_low_stat_);
  }
  if (this->binary_sensor_ts_cold_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TS_COLD_STAT", this->binary_sensor_ts_cold_stat_);
  }
  if (this->binary_sensor_ts_cool_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TS_COOL_STAT", this->binary_sensor_ts_cool_stat_);
  }
  if (this->binary_sensor_ts_warm_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TS_WARM_STAT", this->binary_sensor_ts_warm_stat_);
  }
  if (this->binary_sensor_ts_hot_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TS_HOT_STAT", this->binary_sensor_ts_hot_stat_);
  }
  if (this->binary_sensor_ibat_reg_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "IBAT_REG_STAT", this->binary_sensor_ibat_reg_stat_);
  }
  if (this->binary_sensor_vbus_ovp_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VBUS_OVP_STAT", this->binary_sensor_vbus_ovp_stat_);
  }
  if (this->binary_sensor_vbat_ovp_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VBAT_OVP_STAT", this->binary_sensor_vbat_ovp_stat_);
  }
  if (this->binary_sensor_ibus_ocp_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "IBUS_OCP_STAT", this->binary_sensor_ibus_ocp_stat_);
  }
  if (this->binary_sensor_ibat_ocp_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "IBAT_OCP_STAT", this->binary_sensor_ibat_ocp_stat_);
  }
  if (this->binary_sensor_conv_ocp_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "CONV_OCP_STAT", this->binary_sensor_conv_ocp_stat_);
  }
  if (this->binary_sensor_vac2_ovp_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VAC2_OVP_STAT", this->binary_sensor_vac2_ovp_stat_);
  }
  if (this->binary_sensor_vac1_ovp_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VAC1_OVP_STAT", this->binary_sensor_vac1_ovp_stat_);
  }
  if (this->binary_sensor_vsys_short_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VSYS_SHORT_STAT", this->binary_sensor_vsys_short_stat_);
  }
  if (this->binary_sensor_vsys_ovp_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VSYS_OVP_STAT", this->binary_sensor_vsys_ovp_stat_);
  }
  if (this->binary_sensor_otg_ovp_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "OTG_OVP_STAT", this->binary_sensor_otg_ovp_stat_);
  }
  if (this->binary_sensor_otg_uvp_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "OTG_UVP_STAT", this->binary_sensor_otg_uvp_stat_);
  }
  if (this->binary_sensor_tshut_stat_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TSHUT_STAT", this->binary_sensor_tshut_stat_);
  }
  if (this->binary_sensor_iindpm_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "IINDPM_FLAG", this->binary_sensor_iindpm_flag_);
  }
  if (this->binary_sensor_vindpm_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VINDPM_FLAG", this->binary_sensor_vindpm_flag_);
  }
  if (this->binary_sensor_wd_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "WD_FLAG", this->binary_sensor_wd_flag_);
  }
  if (this->binary_sensor_poorsrc_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "POORSRC_FLAG", this->binary_sensor_poorsrc_flag_);
  }
  if (this->binary_sensor_pg_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "PG_FLAG", this->binary_sensor_pg_flag_);
  }
  if (this->binary_sensor_ac2_present_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "AC2_PRESENT_FLAG", this->binary_sensor_ac2_present_flag_);
  }
  if (this->binary_sensor_ac1_present_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "AC1_PRESENT_FLAG", this->binary_sensor_ac1_present_flag_);
  }
  if (this->binary_sensor_vbus_present_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VBUS_PRESENT_FLAG", this->binary_sensor_vbus_present_flag_);
  }
  if (this->binary_sensor_chg_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "CHG_FLAG", this->binary_sensor_chg_flag_);
  }
  if (this->binary_sensor_ico_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "ICO_FLAG", this->binary_sensor_ico_flag_);
  }
  if (this->binary_sensor_vbus_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VBUS_FLAG", this->binary_sensor_vbus_flag_);
  }
  if (this->binary_sensor_treg_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TREG_FLAG", this->binary_sensor_treg_flag_);
  }
  if (this->binary_sensor_vbat_present_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VBAT_PRESENT_FLAG", this->binary_sensor_vbat_present_flag_);
  }
  if (this->binary_sensor_bc1_2_done_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "BC1_2_DONE_FLAG", this->binary_sensor_bc1_2_done_flag_);
  }
  if (this->binary_sensor_dpdm_done_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "DPDM_DONE_FLAG", this->binary_sensor_dpdm_done_flag_);
  }
  if (this->binary_sensor_adc_done_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "ADC_DONE_FLAG", this->binary_sensor_adc_done_flag_);
  }
  if (this->binary_sensor_vsys_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VSYS_FLAG", this->binary_sensor_vsys_flag_);
  }
  if (this->binary_sensor_chg_tmr_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "CHG_TMR_FLAG", this->binary_sensor_chg_tmr_flag_);
  }
  if (this->binary_sensor_trichg_tmr_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TRICHG_TMR_FLAG", this->binary_sensor_trichg_tmr_flag_);
  }
  if (this->binary_sensor_prechg_tmr_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "PRECHG_TMR_FLAG", this->binary_sensor_prechg_tmr_flag_);
  }
  if (this->binary_sensor_topoff_tmr_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TOPOFF_TMR_FLAG", this->binary_sensor_topoff_tmr_flag_);
  }
  if (this->binary_sensor_vbatotg_low_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VBATOTG_LOW_FLAG", this->binary_sensor_vbatotg_low_flag_);
  }
  if (this->binary_sensor_ts_cold_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TS_COLD_FLAG", this->binary_sensor_ts_cold_flag_);
  }
  if (this->binary_sensor_ts_cool_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TS_COOL_FLAG", this->binary_sensor_ts_cool_flag_);
  }
  if (this->binary_sensor_ts_warm_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TS_WARM_FLAG", this->binary_sensor_ts_warm_flag_);
  }
  if (this->binary_sensor_ts_hot_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TS_HOT_FLAG", this->binary_sensor_ts_hot_flag_);
  }
  if (this->binary_sensor_ibat_reg_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "IBAT_REG_FLAG", this->binary_sensor_ibat_reg_flag_);
  }
  if (this->binary_sensor_vbus_ovp_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VBUS_OVP_FLAG", this->binary_sensor_vbus_ovp_flag_);
  }
  if (this->binary_sensor_vbat_ovp_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VBAT_OVP_FLAG", this->binary_sensor_vbat_ovp_flag_);
  }
  if (this->binary_sensor_ibus_ocp_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "IBUS_OCP_FLAG", this->binary_sensor_ibus_ocp_flag_);
  }
  if (this->binary_sensor_ibat_ocp_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "IBAT_OCP_FLAG", this->binary_sensor_ibat_ocp_flag_);
  }
  if (this->binary_sensor_conv_ocp_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "CONV_OCP_FLAG", this->binary_sensor_conv_ocp_flag_);
  }
  if (this->binary_sensor_vac2_ovp_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VAC2_OVP_FLAG", this->binary_sensor_vac2_ovp_flag_);
  }
  if (this->binary_sensor_vac1_ovp_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VAC1_OVP_FLAG", this->binary_sensor_vac1_ovp_flag_);
  }
  if (this->binary_sensor_vsys_short_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VSYS_SHORT_FLAG", this->binary_sensor_vsys_short_flag_);
  }
  if (this->binary_sensor_vsys_ovp_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VSYS_OVP_FLAG", this->binary_sensor_vsys_ovp_flag_);
  }
  if (this->binary_sensor_otg_ovp_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "OTG_OVP_FLAG", this->binary_sensor_otg_ovp_flag_);
  }
  if (this->binary_sensor_otg_uvp_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "OTG_UVP_FLAG", this->binary_sensor_otg_uvp_flag_);
  }
  if (this->binary_sensor_tshut_flag_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TSHUT_FLAG", this->binary_sensor_tshut_flag_);
  }
  if (this->binary_sensor_adc_en_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "ADC_EN", this->binary_sensor_adc_en_);
  }
  if (this->binary_sensor_adc_rate_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "ADC_RATE", this->binary_sensor_adc_rate_);
  }
  if (this->binary_sensor_adc_avg_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "ADC_AVG", this->binary_sensor_adc_avg_);
  }
  if (this->binary_sensor_adc_avg_init_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "ADC_AVG_INIT", this->binary_sensor_adc_avg_init_);
  }
  if (this->binary_sensor_ibus_adc_dis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "IBUS_ADC_DIS", this->binary_sensor_ibus_adc_dis_);
  }
  if (this->binary_sensor_ibat_adc_dis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "IBAT_ADC_DIS", this->binary_sensor_ibat_adc_dis_);
  }
  if (this->binary_sensor_vbus_adc_dis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VBUS_ADC_DIS", this->binary_sensor_vbus_adc_dis_);
  }
  if (this->binary_sensor_vbat_adc_dis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VBAT_ADC_DIS", this->binary_sensor_vbat_adc_dis_);
  }
  if (this->binary_sensor_vsys_adc_dis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VSYS_ADC_DIS", this->binary_sensor_vsys_adc_dis_);
  }
  if (this->binary_sensor_ts_adc_dis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TS_ADC_DIS", this->binary_sensor_ts_adc_dis_);
  }
  if (this->binary_sensor_tdie_adc_dis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "TDIE_ADC_DIS", this->binary_sensor_tdie_adc_dis_);
  }
  if (this->binary_sensor_dplus_adc_dis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "DPLUS_ADC_DIS", this->binary_sensor_dplus_adc_dis_);
  }
  if (this->binary_sensor_dminus_adc_dis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "DMINUS_ADC_DIS", this->binary_sensor_dminus_adc_dis_);
  }
  if (this->binary_sensor_vac2_adc_dis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VAC2_ADC_DIS", this->binary_sensor_vac2_adc_dis_);
  }
  if (this->binary_sensor_vac1_adc_dis_ != nullptr) {
    LOG_BINARY_SENSOR("  ", "VAC1_ADC_DIS", this->binary_sensor_vac1_adc_dis_);
  }

  LOG_UPDATE_INTERVAL(this);
}

void BQ25798BinarySensor::update() {
  // VSYSMIN - Minimal System Voltage
  
  // VREG - Charge Voltage Limit
  
  // ICHG - Charge Current Limit
  
  // VINDPM - Input Voltage Limit
  
  // IINDPM - Input Current Limit
  
  // VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
  
  // IPRECHG - Precharge Current Limit
  
  // REG_RST - Reset registers to default values and reset timer
  
  if (this->binary_sensor_reg_rst_ != nullptr) {
    this->binary_sensor_reg_rst_->publish_state(this->parent_->get_reg_rst_bool(true));
  }
  // STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
  
  if (this->binary_sensor_stop_wd_chg_ != nullptr) {
    this->binary_sensor_stop_wd_chg_->publish_state(this->parent_->get_stop_wd_chg_bool(true));
  }
  // ITERM - Termination Current Limit
  
  // CELL - Battery cell count
  
  // TRECHG - Battery recharge delay time
  
  // VRECHG - Battery Recharge Threshold Offset (Below VREG)
  
  // VOTG - OTG mode regulation voltage
  
  // PRECHG_TMR - Pre-charge safety timer setting
  
  if (this->binary_sensor_prechg_tmr_ != nullptr) {
    this->binary_sensor_prechg_tmr_->publish_state(this->parent_->get_prechg_tmr_bool(true));
  }
  // IOTG - OTG current limit
  
  // TOPOFF_TMR - Top-off timer control
  
  // EN_TRICHG_TMR - Trickle charge timer enable
  
  if (this->binary_sensor_en_trichg_tmr_ != nullptr) {
    this->binary_sensor_en_trichg_tmr_->publish_state(this->parent_->get_en_trichg_tmr_bool(true));
  }
  // EN_PRECHG_TMR - Precharge timer enable
  
  if (this->binary_sensor_en_prechg_tmr_ != nullptr) {
    this->binary_sensor_en_prechg_tmr_->publish_state(this->parent_->get_en_prechg_tmr_bool(true));
  }
  // EN_CHG_TMR - Fast charge timer enable
  
  if (this->binary_sensor_en_chg_tmr_ != nullptr) {
    this->binary_sensor_en_chg_tmr_->publish_state(this->parent_->get_en_chg_tmr_bool(true));
  }
  // CHG_TMR - Fast charge timer setting
  
  // TMR2X_EN - 2x slower charging in DPM enable
  
  if (this->binary_sensor_tmr2x_en_ != nullptr) {
    this->binary_sensor_tmr2x_en_->publish_state(this->parent_->get_tmr2x_en_bool(true));
  }
  // EN_AUTO_IBATDIS - Enable the auto battery discharging during the battery OVP fault
  
  if (this->binary_sensor_en_auto_ibatdis_ != nullptr) {
    this->binary_sensor_en_auto_ibatdis_->publish_state(this->parent_->get_en_auto_ibatdis_bool(true));
  }
  // FORCE_IBATDIS - Force the battery discharging current
  
  if (this->binary_sensor_force_ibatdis_ != nullptr) {
    this->binary_sensor_force_ibatdis_->publish_state(this->parent_->get_force_ibatdis_bool(true));
  }
  // EN_CHG - Enable the charger
  
  if (this->binary_sensor_en_chg_ != nullptr) {
    this->binary_sensor_en_chg_->publish_state(this->parent_->get_en_chg_bool(true));
  }
  // EN_ICO - Enable the ICO (Input Current Optimizer)
  
  if (this->binary_sensor_en_ico_ != nullptr) {
    this->binary_sensor_en_ico_->publish_state(this->parent_->get_en_ico_bool(true));
  }
  // FORCE_ICO - Force the ICO (Input Current Optimizer)
  
  if (this->binary_sensor_force_ico_ != nullptr) {
    this->binary_sensor_force_ico_->publish_state(this->parent_->get_force_ico_bool(true));
  }
  // EN_HIZ - Enable the high impedance mode
  
  if (this->binary_sensor_en_hiz_ != nullptr) {
    this->binary_sensor_en_hiz_->publish_state(this->parent_->get_en_hiz_bool(true));
  }
  // EN_TERM - Enable the termination
  
  if (this->binary_sensor_en_term_ != nullptr) {
    this->binary_sensor_en_term_->publish_state(this->parent_->get_en_term_bool(true));
  }
  // EN_BACKUP - Enable the backup (auto OTG) mode
  
  if (this->binary_sensor_en_backup_ != nullptr) {
    this->binary_sensor_en_backup_->publish_state(this->parent_->get_en_backup_bool(true));
  }
  // VBUS_BACKUP - The thresholds to trigger the backup mode, defined as a ratio of VINDPM
  
  // VAC_OVP - Over voltage protection thresholds
  
  // WD_RST - I2C watch dog timer reset
  
  if (this->binary_sensor_wd_rst_ != nullptr) {
    this->binary_sensor_wd_rst_->publish_state(this->parent_->get_wd_rst_bool(true));
  }
  // WATCHDOG - Watchdog timer settings
  
  // FORCE_INDET - Force D+/D- detection
  
  if (this->binary_sensor_force_indet_ != nullptr) {
    this->binary_sensor_force_indet_->publish_state(this->parent_->get_force_indet_bool(true));
  }
  // AUTO_INDET_EN - Enable automatic D+/D- detection
  
  if (this->binary_sensor_auto_indet_en_ != nullptr) {
    this->binary_sensor_auto_indet_en_->publish_state(this->parent_->get_auto_indet_en_bool(true));
  }
  // EN_12V - Enable 12V output in HVDCP
  
  if (this->binary_sensor_en_12v_ != nullptr) {
    this->binary_sensor_en_12v_->publish_state(this->parent_->get_en_12v_bool(true));
  }
  // EN_9V - Enable 9V output in HVDCP
  
  if (this->binary_sensor_en_9v_ != nullptr) {
    this->binary_sensor_en_9v_->publish_state(this->parent_->get_en_9v_bool(true));
  }
  // HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
  
  if (this->binary_sensor_hvdcp_en_ != nullptr) {
    this->binary_sensor_hvdcp_en_->publish_state(this->parent_->get_hvdcp_en_bool(true));
  }
  // SDRV_CTRL - Enable external Ship FET control
  
  // SDRV_DLY - Delay for SDRV control
  
  if (this->binary_sensor_sdrv_dly_ != nullptr) {
    this->binary_sensor_sdrv_dly_->publish_state(this->parent_->get_sdrv_dly_bool(true));
  }
  // DIS_ACDRV - Disable both AC1 and AC2 drivers
  
  if (this->binary_sensor_dis_acdrv_ != nullptr) {
    this->binary_sensor_dis_acdrv_->publish_state(this->parent_->get_dis_acdrv_bool(true));
  }
  // EN_OTG - Enable OTG mode
  
  if (this->binary_sensor_en_otg_ != nullptr) {
    this->binary_sensor_en_otg_->publish_state(this->parent_->get_en_otg_bool(true));
  }
  // PFM_OTG_DIS - Disable PFM in OTG mode
  
  if (this->binary_sensor_pfm_otg_dis_ != nullptr) {
    this->binary_sensor_pfm_otg_dis_->publish_state(this->parent_->get_pfm_otg_dis_bool(true));
  }
  // PFM_FWD_DIS - Disable PFM in forward mode
  
  if (this->binary_sensor_pfm_fwd_dis_ != nullptr) {
    this->binary_sensor_pfm_fwd_dis_->publish_state(this->parent_->get_pfm_fwd_dis_bool(true));
  }
  // WKUP_DLY - Wakeup (Ship FET) delay
  
  if (this->binary_sensor_wkup_dly_ != nullptr) {
    this->binary_sensor_wkup_dly_->publish_state(this->parent_->get_wkup_dly_bool(true));
  }
  // DIS_LDO - Disable BATFET LDO mode in precharge state
  
  if (this->binary_sensor_dis_ldo_ != nullptr) {
    this->binary_sensor_dis_ldo_->publish_state(this->parent_->get_dis_ldo_bool(true));
  }
  // DIS_OTG_OOA - Disable OOA in OTG mode
  
  if (this->binary_sensor_dis_otg_ooa_ != nullptr) {
    this->binary_sensor_dis_otg_ooa_->publish_state(this->parent_->get_dis_otg_ooa_bool(true));
  }
  // DIS_FWD_OOA - Disable OOA in forward mode
  
  if (this->binary_sensor_dis_fwd_ooa_ != nullptr) {
    this->binary_sensor_dis_fwd_ooa_->publish_state(this->parent_->get_dis_fwd_ooa_bool(true));
  }
  // EN_ACDRV2 - Enable AC2 gate driver control
  
  if (this->binary_sensor_en_acdrv2_ != nullptr) {
    this->binary_sensor_en_acdrv2_->publish_state(this->parent_->get_en_acdrv2_bool(true));
  }
  // EN_ACDRV1 - Enable AC1 gate driver control
  
  if (this->binary_sensor_en_acdrv1_ != nullptr) {
    this->binary_sensor_en_acdrv1_->publish_state(this->parent_->get_en_acdrv1_bool(true));
  }
  // PWM_FREQ - PWM frequency setting
  
  if (this->binary_sensor_pwm_freq_ != nullptr) {
    this->binary_sensor_pwm_freq_->publish_state(this->parent_->get_pwm_freq_bool(true));
  }
  // DIS_STAT - Disable STAT pin output
  
  if (this->binary_sensor_dis_stat_ != nullptr) {
    this->binary_sensor_dis_stat_->publish_state(this->parent_->get_dis_stat_bool(true));
  }
  // DIS_VSYS_SHORT - Disable VSYS short hiccup protection
  
  if (this->binary_sensor_dis_vsys_short_ != nullptr) {
    this->binary_sensor_dis_vsys_short_->publish_state(this->parent_->get_dis_vsys_short_bool(true));
  }
  // DIS_VOTG_UVP - Disable VOTG under voltage hiccup protection
  
  if (this->binary_sensor_dis_votg_uvp_ != nullptr) {
    this->binary_sensor_dis_votg_uvp_->publish_state(this->parent_->get_dis_votg_uvp_bool(true));
  }
  // FORCE_VINDPM_DET - Force VINDPM detection (settable only when VBAT>VSYSMIN)
  
  if (this->binary_sensor_force_vindpm_det_ != nullptr) {
    this->binary_sensor_force_vindpm_det_->publish_state(this->parent_->get_force_vindpm_det_bool(true));
  }
  // EN_IBUS_OCP - Enable input over current protection in forward mode
  
  if (this->binary_sensor_en_ibus_ocp_ != nullptr) {
    this->binary_sensor_en_ibus_ocp_->publish_state(this->parent_->get_en_ibus_ocp_bool(true));
  }
  // SFET_PRESENT - Ship FET present
  
  if (this->binary_sensor_sfet_present_ != nullptr) {
    this->binary_sensor_sfet_present_->publish_state(this->parent_->get_sfet_present_bool(true));
  }
  // EN_IBAT - Enable battery discharge current sensing
  
  if (this->binary_sensor_en_ibat_ != nullptr) {
    this->binary_sensor_en_ibat_->publish_state(this->parent_->get_en_ibat_bool(true));
  }
  // IBAT_REG - Battery discharge current regulation in OTG mode
  
  // EN_IINDPM - Enable input current regulation
  
  if (this->binary_sensor_en_iindpm_ != nullptr) {
    this->binary_sensor_en_iindpm_->publish_state(this->parent_->get_en_iindpm_bool(true));
  }
  // EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
  
  if (this->binary_sensor_en_extilim_ != nullptr) {
    this->binary_sensor_en_extilim_->publish_state(this->parent_->get_en_extilim_bool(true));
  }
  // EN_BATOC - Enable battery discharging over current protection
  
  if (this->binary_sensor_en_batoc_ != nullptr) {
    this->binary_sensor_en_batoc_->publish_state(this->parent_->get_en_batoc_bool(true));
  }
  // VOC_PCT - 
  
  // VOC_DLY - 
  
  // VOC_RATE - 
  
  // EN_MPPT - 
  
  if (this->binary_sensor_en_mppt_ != nullptr) {
    this->binary_sensor_en_mppt_->publish_state(this->parent_->get_en_mppt_bool(true));
  }
  // TREG - 
  
  // TSHUT - 
  
  // VBUS_PD_EN - 
  
  if (this->binary_sensor_vbus_pd_en_ != nullptr) {
    this->binary_sensor_vbus_pd_en_->publish_state(this->parent_->get_vbus_pd_en_bool(true));
  }
  // VAC1_PD_EN - 
  
  if (this->binary_sensor_vac1_pd_en_ != nullptr) {
    this->binary_sensor_vac1_pd_en_->publish_state(this->parent_->get_vac1_pd_en_bool(true));
  }
  // VAC2_PD_EN - 
  
  if (this->binary_sensor_vac2_pd_en_ != nullptr) {
    this->binary_sensor_vac2_pd_en_->publish_state(this->parent_->get_vac2_pd_en_bool(true));
  }
  // BKUP_ACFET1_ON - 
  
  if (this->binary_sensor_bkup_acfet1_on_ != nullptr) {
    this->binary_sensor_bkup_acfet1_on_->publish_state(this->parent_->get_bkup_acfet1_on_bool(true));
  }
  // JEITA_VSET - 
  
  // JEITA_ISETH - 
  
  // JEITA_ISETC - 
  
  // TS_COOL - 
  
  // TS_WARM - 
  
  // BHOT - 
  
  // BCOLD - 
  
  if (this->binary_sensor_bcold_ != nullptr) {
    this->binary_sensor_bcold_->publish_state(this->parent_->get_bcold_bool(true));
  }
  // TS_IGNORE - 
  
  if (this->binary_sensor_ts_ignore_ != nullptr) {
    this->binary_sensor_ts_ignore_->publish_state(this->parent_->get_ts_ignore_bool(true));
  }
  // ICO_ILIM - 
  
  // IINDPM_STAT - 
  
  if (this->binary_sensor_iindpm_stat_ != nullptr) {
    this->binary_sensor_iindpm_stat_->publish_state(this->parent_->get_iindpm_stat_bool(true));
  }
  // VINDPM_STAT - 
  
  if (this->binary_sensor_vindpm_stat_ != nullptr) {
    this->binary_sensor_vindpm_stat_->publish_state(this->parent_->get_vindpm_stat_bool(true));
  }
  // WD_STAT - 
  
  if (this->binary_sensor_wd_stat_ != nullptr) {
    this->binary_sensor_wd_stat_->publish_state(this->parent_->get_wd_stat_bool(true));
  }
  // PG_STAT - 
  
  if (this->binary_sensor_pg_stat_ != nullptr) {
    this->binary_sensor_pg_stat_->publish_state(this->parent_->get_pg_stat_bool(true));
  }
  // AC2_PRESENT_STAT - 
  
  if (this->binary_sensor_ac2_present_stat_ != nullptr) {
    this->binary_sensor_ac2_present_stat_->publish_state(this->parent_->get_ac2_present_stat_bool(true));
  }
  // AC1_PRESENT_STAT - 
  
  if (this->binary_sensor_ac1_present_stat_ != nullptr) {
    this->binary_sensor_ac1_present_stat_->publish_state(this->parent_->get_ac1_present_stat_bool(true));
  }
  // VBUS_PRESENT_STAT - 
  
  if (this->binary_sensor_vbus_present_stat_ != nullptr) {
    this->binary_sensor_vbus_present_stat_->publish_state(this->parent_->get_vbus_present_stat_bool(true));
  }
  // CHG_STAT - Charge Status bits
  
  // VBUS_STAT - VBUS status bits
  
  // BC12_DONE_STAT - 
  
  if (this->binary_sensor_bc12_done_stat_ != nullptr) {
    this->binary_sensor_bc12_done_stat_->publish_state(this->parent_->get_bc12_done_stat_bool(true));
  }
  // ICO_STAT - 
  
  // TREG_STAT - 
  
  if (this->binary_sensor_treg_stat_ != nullptr) {
    this->binary_sensor_treg_stat_->publish_state(this->parent_->get_treg_stat_bool(true));
  }
  // DPDM_STAT - 
  
  if (this->binary_sensor_dpdm_stat_ != nullptr) {
    this->binary_sensor_dpdm_stat_->publish_state(this->parent_->get_dpdm_stat_bool(true));
  }
  // VBAT_PRESENT_STAT - 
  
  if (this->binary_sensor_vbat_present_stat_ != nullptr) {
    this->binary_sensor_vbat_present_stat_->publish_state(this->parent_->get_vbat_present_stat_bool(true));
  }
  // ACRB2_STAT - The ACFET2-RBFET2 status
  
  if (this->binary_sensor_acrb2_stat_ != nullptr) {
    this->binary_sensor_acrb2_stat_->publish_state(this->parent_->get_acrb2_stat_bool(true));
  }
  // ACRB1_STAT - The ACFET1-RBFET1 status
  
  if (this->binary_sensor_acrb1_stat_ != nullptr) {
    this->binary_sensor_acrb1_stat_->publish_state(this->parent_->get_acrb1_stat_bool(true));
  }
  // ADC_DONE_STAT - ADC Conversion Status
  
  if (this->binary_sensor_adc_done_stat_ != nullptr) {
    this->binary_sensor_adc_done_stat_->publish_state(this->parent_->get_adc_done_stat_bool(true));
  }
  // VSYS_STAT - VSYS Regulation Status
  
  if (this->binary_sensor_vsys_stat_ != nullptr) {
    this->binary_sensor_vsys_stat_->publish_state(this->parent_->get_vsys_stat_bool(true));
  }
  // CHG_TMR_STAT - Fast charge timer status
  
  if (this->binary_sensor_chg_tmr_stat_ != nullptr) {
    this->binary_sensor_chg_tmr_stat_->publish_state(this->parent_->get_chg_tmr_stat_bool(true));
  }
  // TRICHG_TMR_STAT - Trickle charge timer status
  
  if (this->binary_sensor_trichg_tmr_stat_ != nullptr) {
    this->binary_sensor_trichg_tmr_stat_->publish_state(this->parent_->get_trichg_tmr_stat_bool(true));
  }
  // PRECHG_TMR_STAT - Pre-charge timer status
  
  if (this->binary_sensor_prechg_tmr_stat_ != nullptr) {
    this->binary_sensor_prechg_tmr_stat_->publish_state(this->parent_->get_prechg_tmr_stat_bool(true));
  }
  // VBATOTG_LOW_STAT - VBAT too low to enable OTG flag
  
  if (this->binary_sensor_vbatotg_low_stat_ != nullptr) {
    this->binary_sensor_vbatotg_low_stat_->publish_state(this->parent_->get_vbatotg_low_stat_bool(true));
  }
  // TS_COLD_STAT - The TS temperature is in the cold range
  
  if (this->binary_sensor_ts_cold_stat_ != nullptr) {
    this->binary_sensor_ts_cold_stat_->publish_state(this->parent_->get_ts_cold_stat_bool(true));
  }
  // TS_COOL_STAT - The TS temperature is in the cool range
  
  if (this->binary_sensor_ts_cool_stat_ != nullptr) {
    this->binary_sensor_ts_cool_stat_->publish_state(this->parent_->get_ts_cool_stat_bool(true));
  }
  // TS_WARM_STAT - The TS temperature is in the warm range
  
  if (this->binary_sensor_ts_warm_stat_ != nullptr) {
    this->binary_sensor_ts_warm_stat_->publish_state(this->parent_->get_ts_warm_stat_bool(true));
  }
  // TS_HOT_STAT - The TS temperature is in the hot range
  
  if (this->binary_sensor_ts_hot_stat_ != nullptr) {
    this->binary_sensor_ts_hot_stat_->publish_state(this->parent_->get_ts_hot_stat_bool(true));
  }
  // IBAT_REG_STAT - IBAT regulation status
  
  if (this->binary_sensor_ibat_reg_stat_ != nullptr) {
    this->binary_sensor_ibat_reg_stat_->publish_state(this->parent_->get_ibat_reg_stat_bool(true));
  }
  // VBUS_OVP_STAT - VBUS over-voltage status
  
  if (this->binary_sensor_vbus_ovp_stat_ != nullptr) {
    this->binary_sensor_vbus_ovp_stat_->publish_state(this->parent_->get_vbus_ovp_stat_bool(true));
  }
  // VBAT_OVP_STAT - VBAT over-voltage status
  
  if (this->binary_sensor_vbat_ovp_stat_ != nullptr) {
    this->binary_sensor_vbat_ovp_stat_->publish_state(this->parent_->get_vbat_ovp_stat_bool(true));
  }
  // IBUS_OCP_STAT - IBUS over-current status
  
  if (this->binary_sensor_ibus_ocp_stat_ != nullptr) {
    this->binary_sensor_ibus_ocp_stat_->publish_state(this->parent_->get_ibus_ocp_stat_bool(true));
  }
  // IBAT_OCP_STAT - IBAT over-current status
  
  if (this->binary_sensor_ibat_ocp_stat_ != nullptr) {
    this->binary_sensor_ibat_ocp_stat_->publish_state(this->parent_->get_ibat_ocp_stat_bool(true));
  }
  // CONV_OCP_STAT - Converter over-current status
  
  if (this->binary_sensor_conv_ocp_stat_ != nullptr) {
    this->binary_sensor_conv_ocp_stat_->publish_state(this->parent_->get_conv_ocp_stat_bool(true));
  }
  // VAC2_OVP_STAT - VAC2 over-voltage status
  
  if (this->binary_sensor_vac2_ovp_stat_ != nullptr) {
    this->binary_sensor_vac2_ovp_stat_->publish_state(this->parent_->get_vac2_ovp_stat_bool(true));
  }
  // VAC1_OVP_STAT - VAC1 over-voltage status
  
  if (this->binary_sensor_vac1_ovp_stat_ != nullptr) {
    this->binary_sensor_vac1_ovp_stat_->publish_state(this->parent_->get_vac1_ovp_stat_bool(true));
  }
  // VSYS_SHORT_STAT - 
  
  if (this->binary_sensor_vsys_short_stat_ != nullptr) {
    this->binary_sensor_vsys_short_stat_->publish_state(this->parent_->get_vsys_short_stat_bool(true));
  }
  // VSYS_OVP_STAT - 
  
  if (this->binary_sensor_vsys_ovp_stat_ != nullptr) {
    this->binary_sensor_vsys_ovp_stat_->publish_state(this->parent_->get_vsys_ovp_stat_bool(true));
  }
  // OTG_OVP_STAT - 
  
  if (this->binary_sensor_otg_ovp_stat_ != nullptr) {
    this->binary_sensor_otg_ovp_stat_->publish_state(this->parent_->get_otg_ovp_stat_bool(true));
  }
  // OTG_UVP_STAT - 
  
  if (this->binary_sensor_otg_uvp_stat_ != nullptr) {
    this->binary_sensor_otg_uvp_stat_->publish_state(this->parent_->get_otg_uvp_stat_bool(true));
  }
  // TSHUT_STAT - 
  
  if (this->binary_sensor_tshut_stat_ != nullptr) {
    this->binary_sensor_tshut_stat_->publish_state(this->parent_->get_tshut_stat_bool(true));
  }
  // IINDPM_FLAG - In IINDPM / IOTG regulation
  
  if (this->binary_sensor_iindpm_flag_ != nullptr) {
    this->binary_sensor_iindpm_flag_->publish_state(this->parent_->get_iindpm_flag_bool(true));
  }
  // VINDPM_FLAG - In VINDPM / VOTG regulation
  
  if (this->binary_sensor_vindpm_flag_ != nullptr) {
    this->binary_sensor_vindpm_flag_->publish_state(this->parent_->get_vindpm_flag_bool(true));
  }
  // WD_FLAG - Watchdog timer expired
  
  if (this->binary_sensor_wd_flag_ != nullptr) {
    this->binary_sensor_wd_flag_->publish_state(this->parent_->get_wd_flag_bool(true));
  }
  // POORSRC_FLAG - Poor source detected
  
  if (this->binary_sensor_poorsrc_flag_ != nullptr) {
    this->binary_sensor_poorsrc_flag_->publish_state(this->parent_->get_poorsrc_flag_bool(true));
  }
  // PG_FLAG - Power status changed
  
  if (this->binary_sensor_pg_flag_ != nullptr) {
    this->binary_sensor_pg_flag_->publish_state(this->parent_->get_pg_flag_bool(true));
  }
  // AC2_PRESENT_FLAG - AC2 present status changed
  
  if (this->binary_sensor_ac2_present_flag_ != nullptr) {
    this->binary_sensor_ac2_present_flag_->publish_state(this->parent_->get_ac2_present_flag_bool(true));
  }
  // AC1_PRESENT_FLAG - AC1 present status changed
  
  if (this->binary_sensor_ac1_present_flag_ != nullptr) {
    this->binary_sensor_ac1_present_flag_->publish_state(this->parent_->get_ac1_present_flag_bool(true));
  }
  // VBUS_PRESENT_FLAG - VBUS present status changed
  
  if (this->binary_sensor_vbus_present_flag_ != nullptr) {
    this->binary_sensor_vbus_present_flag_->publish_state(this->parent_->get_vbus_present_flag_bool(true));
  }
  // CHG_FLAG - Charging status changed
  
  if (this->binary_sensor_chg_flag_ != nullptr) {
    this->binary_sensor_chg_flag_->publish_state(this->parent_->get_chg_flag_bool(true));
  }
  // ICO_FLAG - ICO status changed
  
  if (this->binary_sensor_ico_flag_ != nullptr) {
    this->binary_sensor_ico_flag_->publish_state(this->parent_->get_ico_flag_bool(true));
  }
  // VBUS_FLAG - VBUS status changed
  
  if (this->binary_sensor_vbus_flag_ != nullptr) {
    this->binary_sensor_vbus_flag_->publish_state(this->parent_->get_vbus_flag_bool(true));
  }
  // TREG_FLAG - 
  
  if (this->binary_sensor_treg_flag_ != nullptr) {
    this->binary_sensor_treg_flag_->publish_state(this->parent_->get_treg_flag_bool(true));
  }
  // VBAT_PRESENT_FLAG - 
  
  if (this->binary_sensor_vbat_present_flag_ != nullptr) {
    this->binary_sensor_vbat_present_flag_->publish_state(this->parent_->get_vbat_present_flag_bool(true));
  }
  // BC1_2_DONE_FLAG - 
  
  if (this->binary_sensor_bc1_2_done_flag_ != nullptr) {
    this->binary_sensor_bc1_2_done_flag_->publish_state(this->parent_->get_bc1_2_done_flag_bool(true));
  }
  // DPDM_DONE_FLAG - 
  
  if (this->binary_sensor_dpdm_done_flag_ != nullptr) {
    this->binary_sensor_dpdm_done_flag_->publish_state(this->parent_->get_dpdm_done_flag_bool(true));
  }
  // ADC_DONE_FLAG - 
  
  if (this->binary_sensor_adc_done_flag_ != nullptr) {
    this->binary_sensor_adc_done_flag_->publish_state(this->parent_->get_adc_done_flag_bool(true));
  }
  // VSYS_FLAG - 
  
  if (this->binary_sensor_vsys_flag_ != nullptr) {
    this->binary_sensor_vsys_flag_->publish_state(this->parent_->get_vsys_flag_bool(true));
  }
  // CHG_TMR_FLAG - 
  
  if (this->binary_sensor_chg_tmr_flag_ != nullptr) {
    this->binary_sensor_chg_tmr_flag_->publish_state(this->parent_->get_chg_tmr_flag_bool(true));
  }
  // TRICHG_TMR_FLAG - 
  
  if (this->binary_sensor_trichg_tmr_flag_ != nullptr) {
    this->binary_sensor_trichg_tmr_flag_->publish_state(this->parent_->get_trichg_tmr_flag_bool(true));
  }
  // PRECHG_TMR_FLAG - 
  
  if (this->binary_sensor_prechg_tmr_flag_ != nullptr) {
    this->binary_sensor_prechg_tmr_flag_->publish_state(this->parent_->get_prechg_tmr_flag_bool(true));
  }
  // TOPOFF_TMR_FLAG - 
  
  if (this->binary_sensor_topoff_tmr_flag_ != nullptr) {
    this->binary_sensor_topoff_tmr_flag_->publish_state(this->parent_->get_topoff_tmr_flag_bool(true));
  }
  // VBATOTG_LOW_FLAG - 
  
  if (this->binary_sensor_vbatotg_low_flag_ != nullptr) {
    this->binary_sensor_vbatotg_low_flag_->publish_state(this->parent_->get_vbatotg_low_flag_bool(true));
  }
  // TS_COLD_FLAG - 
  
  if (this->binary_sensor_ts_cold_flag_ != nullptr) {
    this->binary_sensor_ts_cold_flag_->publish_state(this->parent_->get_ts_cold_flag_bool(true));
  }
  // TS_COOL_FLAG - 
  
  if (this->binary_sensor_ts_cool_flag_ != nullptr) {
    this->binary_sensor_ts_cool_flag_->publish_state(this->parent_->get_ts_cool_flag_bool(true));
  }
  // TS_WARM_FLAG - 
  
  if (this->binary_sensor_ts_warm_flag_ != nullptr) {
    this->binary_sensor_ts_warm_flag_->publish_state(this->parent_->get_ts_warm_flag_bool(true));
  }
  // TS_HOT_FLAG - 
  
  if (this->binary_sensor_ts_hot_flag_ != nullptr) {
    this->binary_sensor_ts_hot_flag_->publish_state(this->parent_->get_ts_hot_flag_bool(true));
  }
  // IBAT_REG_FLAG - 
  
  if (this->binary_sensor_ibat_reg_flag_ != nullptr) {
    this->binary_sensor_ibat_reg_flag_->publish_state(this->parent_->get_ibat_reg_flag_bool(true));
  }
  // VBUS_OVP_FLAG - 
  
  if (this->binary_sensor_vbus_ovp_flag_ != nullptr) {
    this->binary_sensor_vbus_ovp_flag_->publish_state(this->parent_->get_vbus_ovp_flag_bool(true));
  }
  // VBAT_OVP_FLAG - 
  
  if (this->binary_sensor_vbat_ovp_flag_ != nullptr) {
    this->binary_sensor_vbat_ovp_flag_->publish_state(this->parent_->get_vbat_ovp_flag_bool(true));
  }
  // IBUS_OCP_FLAG - 
  
  if (this->binary_sensor_ibus_ocp_flag_ != nullptr) {
    this->binary_sensor_ibus_ocp_flag_->publish_state(this->parent_->get_ibus_ocp_flag_bool(true));
  }
  // IBAT_OCP_FLAG - 
  
  if (this->binary_sensor_ibat_ocp_flag_ != nullptr) {
    this->binary_sensor_ibat_ocp_flag_->publish_state(this->parent_->get_ibat_ocp_flag_bool(true));
  }
  // CONV_OCP_FLAG - 
  
  if (this->binary_sensor_conv_ocp_flag_ != nullptr) {
    this->binary_sensor_conv_ocp_flag_->publish_state(this->parent_->get_conv_ocp_flag_bool(true));
  }
  // VAC2_OVP_FLAG - 
  
  if (this->binary_sensor_vac2_ovp_flag_ != nullptr) {
    this->binary_sensor_vac2_ovp_flag_->publish_state(this->parent_->get_vac2_ovp_flag_bool(true));
  }
  // VAC1_OVP_FLAG - 
  
  if (this->binary_sensor_vac1_ovp_flag_ != nullptr) {
    this->binary_sensor_vac1_ovp_flag_->publish_state(this->parent_->get_vac1_ovp_flag_bool(true));
  }
  // VSYS_SHORT_FLAG - 
  
  if (this->binary_sensor_vsys_short_flag_ != nullptr) {
    this->binary_sensor_vsys_short_flag_->publish_state(this->parent_->get_vsys_short_flag_bool(true));
  }
  // VSYS_OVP_FLAG - 
  
  if (this->binary_sensor_vsys_ovp_flag_ != nullptr) {
    this->binary_sensor_vsys_ovp_flag_->publish_state(this->parent_->get_vsys_ovp_flag_bool(true));
  }
  // OTG_OVP_FLAG - 
  
  if (this->binary_sensor_otg_ovp_flag_ != nullptr) {
    this->binary_sensor_otg_ovp_flag_->publish_state(this->parent_->get_otg_ovp_flag_bool(true));
  }
  // OTG_UVP_FLAG - 
  
  if (this->binary_sensor_otg_uvp_flag_ != nullptr) {
    this->binary_sensor_otg_uvp_flag_->publish_state(this->parent_->get_otg_uvp_flag_bool(true));
  }
  // TSHUT_FLAG - 
  
  if (this->binary_sensor_tshut_flag_ != nullptr) {
    this->binary_sensor_tshut_flag_->publish_state(this->parent_->get_tshut_flag_bool(true));
  }
  // ADC_EN - 
  
  if (this->binary_sensor_adc_en_ != nullptr) {
    this->binary_sensor_adc_en_->publish_state(this->parent_->get_adc_en_bool(true));
  }
  // ADC_RATE - 
  
  if (this->binary_sensor_adc_rate_ != nullptr) {
    this->binary_sensor_adc_rate_->publish_state(this->parent_->get_adc_rate_bool(true));
  }
  // ADC_SAMPLE - 
  
  // ADC_AVG - 
  
  if (this->binary_sensor_adc_avg_ != nullptr) {
    this->binary_sensor_adc_avg_->publish_state(this->parent_->get_adc_avg_bool(true));
  }
  // ADC_AVG_INIT - 
  
  if (this->binary_sensor_adc_avg_init_ != nullptr) {
    this->binary_sensor_adc_avg_init_->publish_state(this->parent_->get_adc_avg_init_bool(true));
  }
  // IBUS_ADC_DIS - 
  
  if (this->binary_sensor_ibus_adc_dis_ != nullptr) {
    this->binary_sensor_ibus_adc_dis_->publish_state(this->parent_->get_ibus_adc_dis_bool(true));
  }
  // IBAT_ADC_DIS - 
  
  if (this->binary_sensor_ibat_adc_dis_ != nullptr) {
    this->binary_sensor_ibat_adc_dis_->publish_state(this->parent_->get_ibat_adc_dis_bool(true));
  }
  // VBUS_ADC_DIS - 
  
  if (this->binary_sensor_vbus_adc_dis_ != nullptr) {
    this->binary_sensor_vbus_adc_dis_->publish_state(this->parent_->get_vbus_adc_dis_bool(true));
  }
  // VBAT_ADC_DIS - 
  
  if (this->binary_sensor_vbat_adc_dis_ != nullptr) {
    this->binary_sensor_vbat_adc_dis_->publish_state(this->parent_->get_vbat_adc_dis_bool(true));
  }
  // VSYS_ADC_DIS - 
  
  if (this->binary_sensor_vsys_adc_dis_ != nullptr) {
    this->binary_sensor_vsys_adc_dis_->publish_state(this->parent_->get_vsys_adc_dis_bool(true));
  }
  // TS_ADC_DIS - 
  
  if (this->binary_sensor_ts_adc_dis_ != nullptr) {
    this->binary_sensor_ts_adc_dis_->publish_state(this->parent_->get_ts_adc_dis_bool(true));
  }
  // TDIE_ADC_DIS - 
  
  if (this->binary_sensor_tdie_adc_dis_ != nullptr) {
    this->binary_sensor_tdie_adc_dis_->publish_state(this->parent_->get_tdie_adc_dis_bool(true));
  }
  // DPLUS_ADC_DIS - 
  
  if (this->binary_sensor_dplus_adc_dis_ != nullptr) {
    this->binary_sensor_dplus_adc_dis_->publish_state(this->parent_->get_dplus_adc_dis_bool(true));
  }
  // DMINUS_ADC_DIS - 
  
  if (this->binary_sensor_dminus_adc_dis_ != nullptr) {
    this->binary_sensor_dminus_adc_dis_->publish_state(this->parent_->get_dminus_adc_dis_bool(true));
  }
  // VAC2_ADC_DIS - 
  
  if (this->binary_sensor_vac2_adc_dis_ != nullptr) {
    this->binary_sensor_vac2_adc_dis_->publish_state(this->parent_->get_vac2_adc_dis_bool(true));
  }
  // VAC1_ADC_DIS - 
  
  if (this->binary_sensor_vac1_adc_dis_ != nullptr) {
    this->binary_sensor_vac1_adc_dis_->publish_state(this->parent_->get_vac1_adc_dis_bool(true));
  }
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
  
  // DMINUS_DAC - D- Output Driver
  
  // PN - 
  
  // DEV_REV - 
  
}


void BQ25798BinarySensor::assign_binary_sensor_reg_rst(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_reg_rst_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_stop_wd_chg(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_stop_wd_chg_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_prechg_tmr(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_prechg_tmr_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_trichg_tmr(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_trichg_tmr_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_prechg_tmr(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_prechg_tmr_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_chg_tmr(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_chg_tmr_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_tmr2x_en(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_tmr2x_en_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_auto_ibatdis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_auto_ibatdis_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_force_ibatdis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_force_ibatdis_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_chg(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_chg_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_ico(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_ico_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_force_ico(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_force_ico_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_hiz(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_hiz_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_term(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_term_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_backup(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_backup_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_wd_rst(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_wd_rst_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_force_indet(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_force_indet_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_auto_indet_en(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_auto_indet_en_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_12v(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_12v_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_9v(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_9v_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_hvdcp_en(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_hvdcp_en_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_sdrv_dly(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_sdrv_dly_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_dis_acdrv(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_dis_acdrv_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_otg(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_otg_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_pfm_otg_dis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_pfm_otg_dis_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_pfm_fwd_dis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_pfm_fwd_dis_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_wkup_dly(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_wkup_dly_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_dis_ldo(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_dis_ldo_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_dis_otg_ooa(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_dis_otg_ooa_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_dis_fwd_ooa(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_dis_fwd_ooa_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_acdrv2(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_acdrv2_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_acdrv1(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_acdrv1_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_pwm_freq(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_pwm_freq_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_dis_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_dis_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_dis_vsys_short(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_dis_vsys_short_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_dis_votg_uvp(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_dis_votg_uvp_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_force_vindpm_det(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_force_vindpm_det_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_ibus_ocp(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_ibus_ocp_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_sfet_present(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_sfet_present_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_ibat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_ibat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_iindpm(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_iindpm_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_extilim(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_extilim_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_batoc(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_batoc_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_en_mppt(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_en_mppt_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vbus_pd_en(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vbus_pd_en_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vac1_pd_en(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vac1_pd_en_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vac2_pd_en(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vac2_pd_en_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_bkup_acfet1_on(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_bkup_acfet1_on_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_bcold(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_bcold_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ts_ignore(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ts_ignore_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_iindpm_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_iindpm_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vindpm_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vindpm_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_wd_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_wd_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_pg_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_pg_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ac2_present_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ac2_present_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ac1_present_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ac1_present_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vbus_present_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vbus_present_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_bc12_done_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_bc12_done_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_treg_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_treg_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_dpdm_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_dpdm_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vbat_present_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vbat_present_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_acrb2_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_acrb2_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_acrb1_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_acrb1_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_adc_done_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_adc_done_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vsys_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vsys_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_chg_tmr_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_chg_tmr_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_trichg_tmr_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_trichg_tmr_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_prechg_tmr_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_prechg_tmr_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vbatotg_low_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vbatotg_low_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ts_cold_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ts_cold_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ts_cool_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ts_cool_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ts_warm_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ts_warm_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ts_hot_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ts_hot_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ibat_reg_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ibat_reg_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vbus_ovp_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vbus_ovp_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vbat_ovp_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vbat_ovp_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ibus_ocp_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ibus_ocp_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ibat_ocp_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ibat_ocp_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_conv_ocp_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_conv_ocp_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vac2_ovp_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vac2_ovp_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vac1_ovp_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vac1_ovp_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vsys_short_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vsys_short_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vsys_ovp_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vsys_ovp_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_otg_ovp_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_otg_ovp_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_otg_uvp_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_otg_uvp_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_tshut_stat(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_tshut_stat_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_iindpm_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_iindpm_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vindpm_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vindpm_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_wd_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_wd_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_poorsrc_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_poorsrc_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_pg_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_pg_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ac2_present_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ac2_present_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ac1_present_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ac1_present_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vbus_present_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vbus_present_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_chg_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_chg_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ico_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ico_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vbus_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vbus_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_treg_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_treg_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vbat_present_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vbat_present_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_bc1_2_done_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_bc1_2_done_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_dpdm_done_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_dpdm_done_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_adc_done_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_adc_done_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vsys_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vsys_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_chg_tmr_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_chg_tmr_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_trichg_tmr_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_trichg_tmr_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_prechg_tmr_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_prechg_tmr_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_topoff_tmr_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_topoff_tmr_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vbatotg_low_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vbatotg_low_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ts_cold_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ts_cold_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ts_cool_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ts_cool_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ts_warm_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ts_warm_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ts_hot_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ts_hot_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ibat_reg_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ibat_reg_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vbus_ovp_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vbus_ovp_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vbat_ovp_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vbat_ovp_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ibus_ocp_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ibus_ocp_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ibat_ocp_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ibat_ocp_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_conv_ocp_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_conv_ocp_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vac2_ovp_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vac2_ovp_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vac1_ovp_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vac1_ovp_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vsys_short_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vsys_short_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vsys_ovp_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vsys_ovp_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_otg_ovp_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_otg_ovp_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_otg_uvp_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_otg_uvp_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_tshut_flag(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_tshut_flag_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_adc_en(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_adc_en_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_adc_rate(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_adc_rate_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_adc_avg(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_adc_avg_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_adc_avg_init(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_adc_avg_init_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ibus_adc_dis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ibus_adc_dis_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ibat_adc_dis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ibat_adc_dis_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vbus_adc_dis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vbus_adc_dis_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vbat_adc_dis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vbat_adc_dis_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vsys_adc_dis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vsys_adc_dis_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_ts_adc_dis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_ts_adc_dis_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_tdie_adc_dis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_tdie_adc_dis_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_dplus_adc_dis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_dplus_adc_dis_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_dminus_adc_dis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_dminus_adc_dis_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vac2_adc_dis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vac2_adc_dis_ = sensor;
}
void BQ25798BinarySensor::assign_binary_sensor_vac1_adc_dis(binary_sensor::BinarySensor *sensor) {
  this->binary_sensor_vac1_adc_dis_ = sensor;
}

}  // namespace bq25798
}  // namespace esphome