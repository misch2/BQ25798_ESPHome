
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
  if (this->binary_sensor_reg_rst_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_reg_rst_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_reg_rst_bool();
      if (new_state != this->binary_sensor_reg_rst_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'REG_RST' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_reg_rst_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_stop_wd_chg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_stop_wd_chg_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_stop_wd_chg_bool();
      if (new_state != this->binary_sensor_stop_wd_chg_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'STOP_WD_CHG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_stop_wd_chg_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_prechg_tmr_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_prechg_tmr_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_prechg_tmr_bool();
      if (new_state != this->binary_sensor_prechg_tmr_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'PRECHG_TMR' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_prechg_tmr_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_trichg_tmr_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_trichg_tmr_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_trichg_tmr_bool();
      if (new_state != this->binary_sensor_en_trichg_tmr_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_TRICHG_TMR' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_trichg_tmr_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_prechg_tmr_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_prechg_tmr_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_prechg_tmr_bool();
      if (new_state != this->binary_sensor_en_prechg_tmr_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_PRECHG_TMR' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_prechg_tmr_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_chg_tmr_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_chg_tmr_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_chg_tmr_bool();
      if (new_state != this->binary_sensor_en_chg_tmr_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_CHG_TMR' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_chg_tmr_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_tmr2x_en_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_tmr2x_en_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_tmr2x_en_bool();
      if (new_state != this->binary_sensor_tmr2x_en_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TMR2X_EN' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_tmr2x_en_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_auto_ibatdis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_auto_ibatdis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_auto_ibatdis_bool();
      if (new_state != this->binary_sensor_en_auto_ibatdis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_AUTO_IBATDIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_auto_ibatdis_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_force_ibatdis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_force_ibatdis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_force_ibatdis_bool();
      if (new_state != this->binary_sensor_force_ibatdis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'FORCE_IBATDIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_force_ibatdis_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_chg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_chg_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_chg_bool();
      if (new_state != this->binary_sensor_en_chg_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_CHG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_chg_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_ico_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_ico_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_ico_bool();
      if (new_state != this->binary_sensor_en_ico_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_ICO' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_ico_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_force_ico_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_force_ico_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_force_ico_bool();
      if (new_state != this->binary_sensor_force_ico_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'FORCE_ICO' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_force_ico_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_hiz_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_hiz_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_hiz_bool();
      if (new_state != this->binary_sensor_en_hiz_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_HIZ' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_hiz_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_term_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_term_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_term_bool();
      if (new_state != this->binary_sensor_en_term_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_TERM' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_term_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_backup_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_backup_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_backup_bool();
      if (new_state != this->binary_sensor_en_backup_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_BACKUP' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_backup_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_wd_rst_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_wd_rst_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_wd_rst_bool();
      if (new_state != this->binary_sensor_wd_rst_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'WD_RST' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_wd_rst_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_force_indet_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_force_indet_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_force_indet_bool();
      if (new_state != this->binary_sensor_force_indet_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'FORCE_INDET' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_force_indet_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_auto_indet_en_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_auto_indet_en_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_auto_indet_en_bool();
      if (new_state != this->binary_sensor_auto_indet_en_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'AUTO_INDET_EN' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_auto_indet_en_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_12v_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_12v_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_12v_bool();
      if (new_state != this->binary_sensor_en_12v_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_12V' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_12v_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_9v_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_9v_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_9v_bool();
      if (new_state != this->binary_sensor_en_9v_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_9V' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_9v_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_hvdcp_en_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_hvdcp_en_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_hvdcp_en_bool();
      if (new_state != this->binary_sensor_hvdcp_en_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'HVDCP_EN' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_hvdcp_en_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_sdrv_dly_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_sdrv_dly_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_sdrv_dly_bool();
      if (new_state != this->binary_sensor_sdrv_dly_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'SDRV_DLY' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_sdrv_dly_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_dis_acdrv_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_dis_acdrv_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_dis_acdrv_bool();
      if (new_state != this->binary_sensor_dis_acdrv_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'DIS_ACDRV' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_dis_acdrv_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_otg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_otg_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_otg_bool();
      if (new_state != this->binary_sensor_en_otg_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_OTG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_otg_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_pfm_otg_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_pfm_otg_dis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_pfm_otg_dis_bool();
      if (new_state != this->binary_sensor_pfm_otg_dis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'PFM_OTG_DIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_pfm_otg_dis_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_pfm_fwd_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_pfm_fwd_dis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_pfm_fwd_dis_bool();
      if (new_state != this->binary_sensor_pfm_fwd_dis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'PFM_FWD_DIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_pfm_fwd_dis_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_wkup_dly_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_wkup_dly_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_wkup_dly_bool();
      if (new_state != this->binary_sensor_wkup_dly_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'WKUP_DLY' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_wkup_dly_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_dis_ldo_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_dis_ldo_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_dis_ldo_bool();
      if (new_state != this->binary_sensor_dis_ldo_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'DIS_LDO' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_dis_ldo_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_dis_otg_ooa_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_dis_otg_ooa_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_dis_otg_ooa_bool();
      if (new_state != this->binary_sensor_dis_otg_ooa_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'DIS_OTG_OOA' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_dis_otg_ooa_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_dis_fwd_ooa_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_dis_fwd_ooa_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_dis_fwd_ooa_bool();
      if (new_state != this->binary_sensor_dis_fwd_ooa_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'DIS_FWD_OOA' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_dis_fwd_ooa_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_acdrv2_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_acdrv2_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_acdrv2_bool();
      if (new_state != this->binary_sensor_en_acdrv2_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_ACDRV2' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_acdrv2_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_acdrv1_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_acdrv1_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_acdrv1_bool();
      if (new_state != this->binary_sensor_en_acdrv1_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_ACDRV1' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_acdrv1_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_pwm_freq_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_pwm_freq_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_pwm_freq_bool();
      if (new_state != this->binary_sensor_pwm_freq_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'PWM_FREQ' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_pwm_freq_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_dis_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_dis_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_dis_stat_bool();
      if (new_state != this->binary_sensor_dis_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'DIS_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_dis_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_dis_vsys_short_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_dis_vsys_short_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_dis_vsys_short_bool();
      if (new_state != this->binary_sensor_dis_vsys_short_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'DIS_VSYS_SHORT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_dis_vsys_short_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_dis_votg_uvp_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_dis_votg_uvp_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_dis_votg_uvp_bool();
      if (new_state != this->binary_sensor_dis_votg_uvp_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'DIS_VOTG_UVP' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_dis_votg_uvp_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_force_vindpm_det_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_force_vindpm_det_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_force_vindpm_det_bool();
      if (new_state != this->binary_sensor_force_vindpm_det_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'FORCE_VINDPM_DET' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_force_vindpm_det_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_ibus_ocp_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_ibus_ocp_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_ibus_ocp_bool();
      if (new_state != this->binary_sensor_en_ibus_ocp_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_IBUS_OCP' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_ibus_ocp_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_sfet_present_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_sfet_present_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_sfet_present_bool();
      if (new_state != this->binary_sensor_sfet_present_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'SFET_PRESENT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_sfet_present_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_ibat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_ibat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_ibat_bool();
      if (new_state != this->binary_sensor_en_ibat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_IBAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_ibat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_iindpm_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_iindpm_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_iindpm_bool();
      if (new_state != this->binary_sensor_en_iindpm_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_IINDPM' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_iindpm_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_extilim_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_extilim_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_extilim_bool();
      if (new_state != this->binary_sensor_en_extilim_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_EXTILIM' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_extilim_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_batoc_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_batoc_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_batoc_bool();
      if (new_state != this->binary_sensor_en_batoc_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_BATOC' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_batoc_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_en_mppt_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_en_mppt_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_en_mppt_bool();
      if (new_state != this->binary_sensor_en_mppt_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'EN_MPPT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_en_mppt_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vbus_pd_en_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vbus_pd_en_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vbus_pd_en_bool();
      if (new_state != this->binary_sensor_vbus_pd_en_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VBUS_PD_EN' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vbus_pd_en_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vac1_pd_en_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vac1_pd_en_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vac1_pd_en_bool();
      if (new_state != this->binary_sensor_vac1_pd_en_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VAC1_PD_EN' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vac1_pd_en_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vac2_pd_en_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vac2_pd_en_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vac2_pd_en_bool();
      if (new_state != this->binary_sensor_vac2_pd_en_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VAC2_PD_EN' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vac2_pd_en_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_bkup_acfet1_on_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_bkup_acfet1_on_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_bkup_acfet1_on_bool();
      if (new_state != this->binary_sensor_bkup_acfet1_on_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'BKUP_ACFET1_ON' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_bkup_acfet1_on_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_bcold_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_bcold_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_bcold_bool();
      if (new_state != this->binary_sensor_bcold_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'BCOLD' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_bcold_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ts_ignore_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ts_ignore_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ts_ignore_bool();
      if (new_state != this->binary_sensor_ts_ignore_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TS_IGNORE' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ts_ignore_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_iindpm_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_iindpm_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_iindpm_stat_bool();
      if (new_state != this->binary_sensor_iindpm_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'IINDPM_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_iindpm_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vindpm_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vindpm_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vindpm_stat_bool();
      if (new_state != this->binary_sensor_vindpm_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VINDPM_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vindpm_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_wd_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_wd_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_wd_stat_bool();
      if (new_state != this->binary_sensor_wd_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'WD_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_wd_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_pg_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_pg_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_pg_stat_bool();
      if (new_state != this->binary_sensor_pg_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'PG_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_pg_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ac2_present_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ac2_present_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ac2_present_stat_bool();
      if (new_state != this->binary_sensor_ac2_present_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'AC2_PRESENT_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ac2_present_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ac1_present_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ac1_present_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ac1_present_stat_bool();
      if (new_state != this->binary_sensor_ac1_present_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'AC1_PRESENT_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ac1_present_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vbus_present_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vbus_present_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vbus_present_stat_bool();
      if (new_state != this->binary_sensor_vbus_present_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VBUS_PRESENT_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vbus_present_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_bc12_done_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_bc12_done_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_bc12_done_stat_bool();
      if (new_state != this->binary_sensor_bc12_done_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'BC12_DONE_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_bc12_done_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_treg_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_treg_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_treg_stat_bool();
      if (new_state != this->binary_sensor_treg_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TREG_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_treg_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_dpdm_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_dpdm_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_dpdm_stat_bool();
      if (new_state != this->binary_sensor_dpdm_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'DPDM_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_dpdm_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vbat_present_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vbat_present_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vbat_present_stat_bool();
      if (new_state != this->binary_sensor_vbat_present_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VBAT_PRESENT_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vbat_present_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_acrb2_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_acrb2_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_acrb2_stat_bool();
      if (new_state != this->binary_sensor_acrb2_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'ACRB2_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_acrb2_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_acrb1_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_acrb1_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_acrb1_stat_bool();
      if (new_state != this->binary_sensor_acrb1_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'ACRB1_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_acrb1_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_adc_done_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_adc_done_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_adc_done_stat_bool();
      if (new_state != this->binary_sensor_adc_done_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'ADC_DONE_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_adc_done_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vsys_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vsys_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vsys_stat_bool();
      if (new_state != this->binary_sensor_vsys_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VSYS_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vsys_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_chg_tmr_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_chg_tmr_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_chg_tmr_stat_bool();
      if (new_state != this->binary_sensor_chg_tmr_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'CHG_TMR_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_chg_tmr_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_trichg_tmr_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_trichg_tmr_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_trichg_tmr_stat_bool();
      if (new_state != this->binary_sensor_trichg_tmr_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TRICHG_TMR_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_trichg_tmr_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_prechg_tmr_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_prechg_tmr_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_prechg_tmr_stat_bool();
      if (new_state != this->binary_sensor_prechg_tmr_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'PRECHG_TMR_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_prechg_tmr_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vbatotg_low_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vbatotg_low_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vbatotg_low_stat_bool();
      if (new_state != this->binary_sensor_vbatotg_low_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VBATOTG_LOW_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vbatotg_low_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ts_cold_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ts_cold_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ts_cold_stat_bool();
      if (new_state != this->binary_sensor_ts_cold_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TS_COLD_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ts_cold_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ts_cool_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ts_cool_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ts_cool_stat_bool();
      if (new_state != this->binary_sensor_ts_cool_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TS_COOL_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ts_cool_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ts_warm_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ts_warm_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ts_warm_stat_bool();
      if (new_state != this->binary_sensor_ts_warm_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TS_WARM_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ts_warm_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ts_hot_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ts_hot_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ts_hot_stat_bool();
      if (new_state != this->binary_sensor_ts_hot_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TS_HOT_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ts_hot_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ibat_reg_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ibat_reg_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ibat_reg_stat_bool();
      if (new_state != this->binary_sensor_ibat_reg_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'IBAT_REG_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ibat_reg_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vbus_ovp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vbus_ovp_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vbus_ovp_stat_bool();
      if (new_state != this->binary_sensor_vbus_ovp_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VBUS_OVP_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vbus_ovp_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vbat_ovp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vbat_ovp_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vbat_ovp_stat_bool();
      if (new_state != this->binary_sensor_vbat_ovp_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VBAT_OVP_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vbat_ovp_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ibus_ocp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ibus_ocp_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ibus_ocp_stat_bool();
      if (new_state != this->binary_sensor_ibus_ocp_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'IBUS_OCP_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ibus_ocp_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ibat_ocp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ibat_ocp_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ibat_ocp_stat_bool();
      if (new_state != this->binary_sensor_ibat_ocp_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'IBAT_OCP_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ibat_ocp_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_conv_ocp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_conv_ocp_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_conv_ocp_stat_bool();
      if (new_state != this->binary_sensor_conv_ocp_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'CONV_OCP_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_conv_ocp_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vac2_ovp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vac2_ovp_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vac2_ovp_stat_bool();
      if (new_state != this->binary_sensor_vac2_ovp_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VAC2_OVP_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vac2_ovp_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vac1_ovp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vac1_ovp_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vac1_ovp_stat_bool();
      if (new_state != this->binary_sensor_vac1_ovp_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VAC1_OVP_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vac1_ovp_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vsys_short_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vsys_short_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vsys_short_stat_bool();
      if (new_state != this->binary_sensor_vsys_short_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VSYS_SHORT_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vsys_short_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vsys_ovp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vsys_ovp_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vsys_ovp_stat_bool();
      if (new_state != this->binary_sensor_vsys_ovp_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VSYS_OVP_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vsys_ovp_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_otg_ovp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_otg_ovp_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_otg_ovp_stat_bool();
      if (new_state != this->binary_sensor_otg_ovp_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'OTG_OVP_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_otg_ovp_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_otg_uvp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_otg_uvp_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_otg_uvp_stat_bool();
      if (new_state != this->binary_sensor_otg_uvp_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'OTG_UVP_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_otg_uvp_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_tshut_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_tshut_stat_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_tshut_stat_bool();
      if (new_state != this->binary_sensor_tshut_stat_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TSHUT_STAT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_tshut_stat_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_iindpm_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_iindpm_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_iindpm_flag_flag();
      if (new_state != this->binary_sensor_iindpm_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'IINDPM_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_iindpm_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vindpm_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vindpm_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vindpm_flag_flag();
      if (new_state != this->binary_sensor_vindpm_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VINDPM_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vindpm_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_wd_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_wd_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_wd_flag_flag();
      if (new_state != this->binary_sensor_wd_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'WD_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_wd_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_poorsrc_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_poorsrc_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_poorsrc_flag_flag();
      if (new_state != this->binary_sensor_poorsrc_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'POORSRC_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_poorsrc_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_pg_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_pg_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_pg_flag_flag();
      if (new_state != this->binary_sensor_pg_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'PG_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_pg_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ac2_present_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ac2_present_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ac2_present_flag_flag();
      if (new_state != this->binary_sensor_ac2_present_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'AC2_PRESENT_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ac2_present_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ac1_present_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ac1_present_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ac1_present_flag_flag();
      if (new_state != this->binary_sensor_ac1_present_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'AC1_PRESENT_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ac1_present_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vbus_present_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vbus_present_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vbus_present_flag_flag();
      if (new_state != this->binary_sensor_vbus_present_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VBUS_PRESENT_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vbus_present_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_chg_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_chg_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_chg_flag_flag();
      if (new_state != this->binary_sensor_chg_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'CHG_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_chg_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ico_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ico_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ico_flag_flag();
      if (new_state != this->binary_sensor_ico_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'ICO_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ico_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vbus_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vbus_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vbus_flag_flag();
      if (new_state != this->binary_sensor_vbus_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VBUS_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vbus_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_treg_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_treg_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_treg_flag_flag();
      if (new_state != this->binary_sensor_treg_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TREG_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_treg_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vbat_present_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vbat_present_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vbat_present_flag_flag();
      if (new_state != this->binary_sensor_vbat_present_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VBAT_PRESENT_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vbat_present_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_bc1_2_done_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_bc1_2_done_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_bc1_2_done_flag_flag();
      if (new_state != this->binary_sensor_bc1_2_done_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'BC1_2_DONE_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_bc1_2_done_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_dpdm_done_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_dpdm_done_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_dpdm_done_flag_flag();
      if (new_state != this->binary_sensor_dpdm_done_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'DPDM_DONE_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_dpdm_done_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_adc_done_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_adc_done_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_adc_done_flag_flag();
      if (new_state != this->binary_sensor_adc_done_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'ADC_DONE_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_adc_done_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vsys_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vsys_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vsys_flag_flag();
      if (new_state != this->binary_sensor_vsys_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VSYS_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vsys_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_chg_tmr_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_chg_tmr_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_chg_tmr_flag_flag();
      if (new_state != this->binary_sensor_chg_tmr_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'CHG_TMR_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_chg_tmr_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_trichg_tmr_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_trichg_tmr_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_trichg_tmr_flag_flag();
      if (new_state != this->binary_sensor_trichg_tmr_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TRICHG_TMR_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_trichg_tmr_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_prechg_tmr_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_prechg_tmr_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_prechg_tmr_flag_flag();
      if (new_state != this->binary_sensor_prechg_tmr_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'PRECHG_TMR_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_prechg_tmr_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_topoff_tmr_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_topoff_tmr_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_topoff_tmr_flag_flag();
      if (new_state != this->binary_sensor_topoff_tmr_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TOPOFF_TMR_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_topoff_tmr_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vbatotg_low_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vbatotg_low_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vbatotg_low_flag_flag();
      if (new_state != this->binary_sensor_vbatotg_low_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VBATOTG_LOW_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vbatotg_low_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ts_cold_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ts_cold_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ts_cold_flag_flag();
      if (new_state != this->binary_sensor_ts_cold_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TS_COLD_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ts_cold_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ts_cool_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ts_cool_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ts_cool_flag_flag();
      if (new_state != this->binary_sensor_ts_cool_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TS_COOL_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ts_cool_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ts_warm_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ts_warm_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ts_warm_flag_flag();
      if (new_state != this->binary_sensor_ts_warm_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TS_WARM_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ts_warm_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ts_hot_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ts_hot_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ts_hot_flag_flag();
      if (new_state != this->binary_sensor_ts_hot_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TS_HOT_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ts_hot_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ibat_reg_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ibat_reg_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ibat_reg_flag_flag();
      if (new_state != this->binary_sensor_ibat_reg_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'IBAT_REG_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ibat_reg_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vbus_ovp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vbus_ovp_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vbus_ovp_flag_flag();
      if (new_state != this->binary_sensor_vbus_ovp_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VBUS_OVP_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vbus_ovp_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vbat_ovp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vbat_ovp_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vbat_ovp_flag_flag();
      if (new_state != this->binary_sensor_vbat_ovp_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VBAT_OVP_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vbat_ovp_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ibus_ocp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ibus_ocp_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ibus_ocp_flag_flag();
      if (new_state != this->binary_sensor_ibus_ocp_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'IBUS_OCP_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ibus_ocp_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ibat_ocp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ibat_ocp_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ibat_ocp_flag_flag();
      if (new_state != this->binary_sensor_ibat_ocp_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'IBAT_OCP_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ibat_ocp_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_conv_ocp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_conv_ocp_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_conv_ocp_flag_flag();
      if (new_state != this->binary_sensor_conv_ocp_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'CONV_OCP_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_conv_ocp_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vac2_ovp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vac2_ovp_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vac2_ovp_flag_flag();
      if (new_state != this->binary_sensor_vac2_ovp_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VAC2_OVP_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vac2_ovp_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vac1_ovp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vac1_ovp_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vac1_ovp_flag_flag();
      if (new_state != this->binary_sensor_vac1_ovp_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VAC1_OVP_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vac1_ovp_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vsys_short_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vsys_short_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vsys_short_flag_flag();
      if (new_state != this->binary_sensor_vsys_short_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VSYS_SHORT_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vsys_short_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vsys_ovp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vsys_ovp_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vsys_ovp_flag_flag();
      if (new_state != this->binary_sensor_vsys_ovp_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VSYS_OVP_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vsys_ovp_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_otg_ovp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_otg_ovp_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_otg_ovp_flag_flag();
      if (new_state != this->binary_sensor_otg_ovp_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'OTG_OVP_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_otg_ovp_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_otg_uvp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_otg_uvp_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_otg_uvp_flag_flag();
      if (new_state != this->binary_sensor_otg_uvp_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'OTG_UVP_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_otg_uvp_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_tshut_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_tshut_flag_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_tshut_flag_flag();
      if (new_state != this->binary_sensor_tshut_flag_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TSHUT_FLAG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_tshut_flag_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_adc_en_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_adc_en_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_adc_en_bool();
      if (new_state != this->binary_sensor_adc_en_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'ADC_EN' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_adc_en_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_adc_rate_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_adc_rate_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_adc_rate_bool();
      if (new_state != this->binary_sensor_adc_rate_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'ADC_RATE' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_adc_rate_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_adc_avg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_adc_avg_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_adc_avg_bool();
      if (new_state != this->binary_sensor_adc_avg_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'ADC_AVG' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_adc_avg_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_adc_avg_init_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_adc_avg_init_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_adc_avg_init_bool();
      if (new_state != this->binary_sensor_adc_avg_init_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'ADC_AVG_INIT' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_adc_avg_init_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ibus_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ibus_adc_dis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ibus_adc_dis_bool();
      if (new_state != this->binary_sensor_ibus_adc_dis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'IBUS_ADC_DIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ibus_adc_dis_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ibat_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ibat_adc_dis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ibat_adc_dis_bool();
      if (new_state != this->binary_sensor_ibat_adc_dis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'IBAT_ADC_DIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ibat_adc_dis_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vbus_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vbus_adc_dis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vbus_adc_dis_bool();
      if (new_state != this->binary_sensor_vbus_adc_dis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VBUS_ADC_DIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vbus_adc_dis_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vbat_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vbat_adc_dis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vbat_adc_dis_bool();
      if (new_state != this->binary_sensor_vbat_adc_dis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VBAT_ADC_DIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vbat_adc_dis_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vsys_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vsys_adc_dis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vsys_adc_dis_bool();
      if (new_state != this->binary_sensor_vsys_adc_dis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VSYS_ADC_DIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vsys_adc_dis_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_ts_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_ts_adc_dis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_ts_adc_dis_bool();
      if (new_state != this->binary_sensor_ts_adc_dis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TS_ADC_DIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_ts_adc_dis_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_tdie_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_tdie_adc_dis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_tdie_adc_dis_bool();
      if (new_state != this->binary_sensor_tdie_adc_dis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'TDIE_ADC_DIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_tdie_adc_dis_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_dplus_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_dplus_adc_dis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_dplus_adc_dis_bool();
      if (new_state != this->binary_sensor_dplus_adc_dis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'DPLUS_ADC_DIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_dplus_adc_dis_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_dminus_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_dminus_adc_dis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_dminus_adc_dis_bool();
      if (new_state != this->binary_sensor_dminus_adc_dis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'DMINUS_ADC_DIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_dminus_adc_dis_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vac2_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vac2_adc_dis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vac2_adc_dis_bool();
      if (new_state != this->binary_sensor_vac2_adc_dis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VAC2_ADC_DIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vac2_adc_dis_->publish_state(new_state);
    }
  }
  if (this->binary_sensor_vac1_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->binary_sensor_vac1_adc_dis_->publish_state(false);
    } else {
      bool new_state = this->parent_->get_vac1_adc_dis_bool();
      if (new_state != this->binary_sensor_vac1_adc_dis_->state) {
        ESP_LOGI(TAG, "Updating binary sensor 'VAC1_ADC_DIS' to %s", new_state ? "ON" : "OFF");
      }
      this->binary_sensor_vac1_adc_dis_->publish_state(new_state);
    }
  }
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