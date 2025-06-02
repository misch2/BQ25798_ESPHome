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
  if (this->sensor_reg_rst_ != nullptr) {
    LOG_SENSOR("  ", "REG_RST", this->sensor_reg_rst_);
  }
  if (this->sensor_stop_wd_chg_ != nullptr) {
    LOG_SENSOR("  ", "STOP_WD_CHG", this->sensor_stop_wd_chg_);
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
  if (this->sensor_en_trichg_tmr_ != nullptr) {
    LOG_SENSOR("  ", "EN_TRICHG_TMR", this->sensor_en_trichg_tmr_);
  }
  if (this->sensor_en_prechg_tmr_ != nullptr) {
    LOG_SENSOR("  ", "EN_PRECHG_TMR", this->sensor_en_prechg_tmr_);
  }
  if (this->sensor_en_chg_tmr_ != nullptr) {
    LOG_SENSOR("  ", "EN_CHG_TMR", this->sensor_en_chg_tmr_);
  }
  if (this->sensor_chg_tmr_ != nullptr) {
    LOG_SENSOR("  ", "CHG_TMR", this->sensor_chg_tmr_);
  }
  if (this->sensor_tmr2x_en_ != nullptr) {
    LOG_SENSOR("  ", "TMR2X_EN", this->sensor_tmr2x_en_);
  }
  if (this->sensor_en_auto_ibatdis_ != nullptr) {
    LOG_SENSOR("  ", "EN_AUTO_IBATDIS", this->sensor_en_auto_ibatdis_);
  }
  if (this->sensor_force_ibatdis_ != nullptr) {
    LOG_SENSOR("  ", "FORCE_IBATDIS", this->sensor_force_ibatdis_);
  }
  if (this->sensor_en_chg_ != nullptr) {
    LOG_SENSOR("  ", "EN_CHG", this->sensor_en_chg_);
  }
  if (this->sensor_en_ico_ != nullptr) {
    LOG_SENSOR("  ", "EN_ICO", this->sensor_en_ico_);
  }
  if (this->sensor_force_ico_ != nullptr) {
    LOG_SENSOR("  ", "FORCE_ICO", this->sensor_force_ico_);
  }
  if (this->sensor_en_hiz_ != nullptr) {
    LOG_SENSOR("  ", "EN_HIZ", this->sensor_en_hiz_);
  }
  if (this->sensor_en_term_ != nullptr) {
    LOG_SENSOR("  ", "EN_TERM", this->sensor_en_term_);
  }
  if (this->sensor_en_backup_ != nullptr) {
    LOG_SENSOR("  ", "EN_BACKUP", this->sensor_en_backup_);
  }
  if (this->sensor_vbus_backup_ != nullptr) {
    LOG_SENSOR("  ", "VBUS_BACKUP", this->sensor_vbus_backup_);
  }
  if (this->sensor_vac_ovp_ != nullptr) {
    LOG_SENSOR("  ", "VAC_OVP", this->sensor_vac_ovp_);
  }
  if (this->sensor_wd_rst_ != nullptr) {
    LOG_SENSOR("  ", "WD_RST", this->sensor_wd_rst_);
  }
  if (this->sensor_watchdog_ != nullptr) {
    LOG_SENSOR("  ", "WATCHDOG", this->sensor_watchdog_);
  }
  if (this->sensor_force_indet_ != nullptr) {
    LOG_SENSOR("  ", "FORCE_INDET", this->sensor_force_indet_);
  }
  if (this->sensor_auto_indet_en_ != nullptr) {
    LOG_SENSOR("  ", "AUTO_INDET_EN", this->sensor_auto_indet_en_);
  }
  if (this->sensor_en_12v_ != nullptr) {
    LOG_SENSOR("  ", "EN_12V", this->sensor_en_12v_);
  }
  if (this->sensor_en_9v_ != nullptr) {
    LOG_SENSOR("  ", "EN_9V", this->sensor_en_9v_);
  }
  if (this->sensor_hvdcp_en_ != nullptr) {
    LOG_SENSOR("  ", "HVDCP_EN", this->sensor_hvdcp_en_);
  }
  if (this->sensor_sdrv_ctrl_ != nullptr) {
    LOG_SENSOR("  ", "SDRV_CTRL", this->sensor_sdrv_ctrl_);
  }
  if (this->sensor_sdrv_dly_ != nullptr) {
    LOG_SENSOR("  ", "SDRV_DLY", this->sensor_sdrv_dly_);
  }
  if (this->sensor_dis_acdrv_ != nullptr) {
    LOG_SENSOR("  ", "DIS_ACDRV", this->sensor_dis_acdrv_);
  }
  if (this->sensor_en_otg_ != nullptr) {
    LOG_SENSOR("  ", "EN_OTG", this->sensor_en_otg_);
  }
  if (this->sensor_pfm_otg_dis_ != nullptr) {
    LOG_SENSOR("  ", "PFM_OTG_DIS", this->sensor_pfm_otg_dis_);
  }
  if (this->sensor_pfm_fwd_dis_ != nullptr) {
    LOG_SENSOR("  ", "PFM_FWD_DIS", this->sensor_pfm_fwd_dis_);
  }
  if (this->sensor_wkup_dly_ != nullptr) {
    LOG_SENSOR("  ", "WKUP_DLY", this->sensor_wkup_dly_);
  }
  if (this->sensor_dis_ldo_ != nullptr) {
    LOG_SENSOR("  ", "DIS_LDO", this->sensor_dis_ldo_);
  }
  if (this->sensor_dis_otg_ooa_ != nullptr) {
    LOG_SENSOR("  ", "DIS_OTG_OOA", this->sensor_dis_otg_ooa_);
  }
  if (this->sensor_dis_fwd_ooa_ != nullptr) {
    LOG_SENSOR("  ", "DIS_FWD_OOA", this->sensor_dis_fwd_ooa_);
  }
  if (this->sensor_en_acdrv2_ != nullptr) {
    LOG_SENSOR("  ", "EN_ACDRV2", this->sensor_en_acdrv2_);
  }
  if (this->sensor_en_acdrv1_ != nullptr) {
    LOG_SENSOR("  ", "EN_ACDRV1", this->sensor_en_acdrv1_);
  }
  if (this->sensor_pwm_freq_ != nullptr) {
    LOG_SENSOR("  ", "PWM_FREQ", this->sensor_pwm_freq_);
  }
  if (this->sensor_dis_stat_ != nullptr) {
    LOG_SENSOR("  ", "DIS_STAT", this->sensor_dis_stat_);
  }
  if (this->sensor_dis_vsys_short_ != nullptr) {
    LOG_SENSOR("  ", "DIS_VSYS_SHORT", this->sensor_dis_vsys_short_);
  }
  if (this->sensor_dis_votg_uvp_ != nullptr) {
    LOG_SENSOR("  ", "DIS_VOTG_UVP", this->sensor_dis_votg_uvp_);
  }
  if (this->sensor_force_vindpm_det_ != nullptr) {
    LOG_SENSOR("  ", "FORCE_VINDPM_DET", this->sensor_force_vindpm_det_);
  }
  if (this->sensor_en_ibus_ocp_ != nullptr) {
    LOG_SENSOR("  ", "EN_IBUS_OCP", this->sensor_en_ibus_ocp_);
  }
  if (this->sensor_sfet_present_ != nullptr) {
    LOG_SENSOR("  ", "SFET_PRESENT", this->sensor_sfet_present_);
  }
  if (this->sensor_en_ibat_ != nullptr) {
    LOG_SENSOR("  ", "EN_IBAT", this->sensor_en_ibat_);
  }
  if (this->sensor_ibat_reg_ != nullptr) {
    LOG_SENSOR("  ", "IBAT_REG", this->sensor_ibat_reg_);
  }
  if (this->sensor_en_iindpm_ != nullptr) {
    LOG_SENSOR("  ", "EN_IINDPM", this->sensor_en_iindpm_);
  }
  if (this->sensor_en_extilim_ != nullptr) {
    LOG_SENSOR("  ", "EN_EXTILIM", this->sensor_en_extilim_);
  }
  if (this->sensor_en_batoc_ != nullptr) {
    LOG_SENSOR("  ", "EN_BATOC", this->sensor_en_batoc_);
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
  if (this->sensor_en_mppt_ != nullptr) {
    LOG_SENSOR("  ", "EN_MPPT", this->sensor_en_mppt_);
  }
  if (this->sensor_treg_ != nullptr) {
    LOG_SENSOR("  ", "TREG", this->sensor_treg_);
  }
  if (this->sensor_tshut_ != nullptr) {
    LOG_SENSOR("  ", "TSHUT", this->sensor_tshut_);
  }
  if (this->sensor_vbus_pd_en_ != nullptr) {
    LOG_SENSOR("  ", "VBUS_PD_EN", this->sensor_vbus_pd_en_);
  }
  if (this->sensor_vac1_pd_en_ != nullptr) {
    LOG_SENSOR("  ", "VAC1_PD_EN", this->sensor_vac1_pd_en_);
  }
  if (this->sensor_vac2_pd_en_ != nullptr) {
    LOG_SENSOR("  ", "VAC2_PD_EN", this->sensor_vac2_pd_en_);
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
  if (this->sensor_ts_ignore_ != nullptr) {
    LOG_SENSOR("  ", "TS_IGNORE", this->sensor_ts_ignore_);
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
  if (this->sensor_bc12_done_stat_ != nullptr) {
    LOG_SENSOR("  ", "BC12_DONE_STAT", this->sensor_bc12_done_stat_);
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
  if (this->sensor_adc_done_stat_ != nullptr) {
    LOG_SENSOR("  ", "ADC_DONE_STAT", this->sensor_adc_done_stat_);
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
  if (this->sensor_ibat_reg_stat_ != nullptr) {
    LOG_SENSOR("  ", "IBAT_REG_STAT", this->sensor_ibat_reg_stat_);
  }
  if (this->sensor_vbus_ovp_stat_ != nullptr) {
    LOG_SENSOR("  ", "VBUS_OVP_STAT", this->sensor_vbus_ovp_stat_);
  }
  if (this->sensor_vbat_ovp_stat_ != nullptr) {
    LOG_SENSOR("  ", "VBAT_OVP_STAT", this->sensor_vbat_ovp_stat_);
  }
  if (this->sensor_ibus_ocp_stat_ != nullptr) {
    LOG_SENSOR("  ", "IBUS_OCP_STAT", this->sensor_ibus_ocp_stat_);
  }
  if (this->sensor_ibat_ocp_stat_ != nullptr) {
    LOG_SENSOR("  ", "IBAT_OCP_STAT", this->sensor_ibat_ocp_stat_);
  }
  if (this->sensor_conv_ocp_stat_ != nullptr) {
    LOG_SENSOR("  ", "CONV_OCP_STAT", this->sensor_conv_ocp_stat_);
  }
  if (this->sensor_vac2_ovp_stat_ != nullptr) {
    LOG_SENSOR("  ", "VAC2_OVP_STAT", this->sensor_vac2_ovp_stat_);
  }
  if (this->sensor_vac1_ovp_stat_ != nullptr) {
    LOG_SENSOR("  ", "VAC1_OVP_STAT", this->sensor_vac1_ovp_stat_);
  }
  if (this->sensor_vsys_short_stat_ != nullptr) {
    LOG_SENSOR("  ", "VSYS_SHORT_STAT", this->sensor_vsys_short_stat_);
  }
  if (this->sensor_vsys_ovp_stat_ != nullptr) {
    LOG_SENSOR("  ", "VSYS_OVP_STAT", this->sensor_vsys_ovp_stat_);
  }
  if (this->sensor_otg_ovp_stat_ != nullptr) {
    LOG_SENSOR("  ", "OTG_OVP_STAT", this->sensor_otg_ovp_stat_);
  }
  if (this->sensor_otg_uvp_stat_ != nullptr) {
    LOG_SENSOR("  ", "OTG_UVP_STAT", this->sensor_otg_uvp_stat_);
  }
  if (this->sensor_tshut_stat_ != nullptr) {
    LOG_SENSOR("  ", "TSHUT_STAT", this->sensor_tshut_stat_);
  }
  if (this->sensor_iindpm_flag_ != nullptr) {
    LOG_SENSOR("  ", "IINDPM_FLAG", this->sensor_iindpm_flag_);
  }
  if (this->sensor_vindpm_flag_ != nullptr) {
    LOG_SENSOR("  ", "VINDPM_FLAG", this->sensor_vindpm_flag_);
  }
  if (this->sensor_wd_flag_ != nullptr) {
    LOG_SENSOR("  ", "WD_FLAG", this->sensor_wd_flag_);
  }
  if (this->sensor_poorsrc_flag_ != nullptr) {
    LOG_SENSOR("  ", "POORSRC_FLAG", this->sensor_poorsrc_flag_);
  }
  if (this->sensor_pg_flag_ != nullptr) {
    LOG_SENSOR("  ", "PG_FLAG", this->sensor_pg_flag_);
  }
  if (this->sensor_ac2_present_flag_ != nullptr) {
    LOG_SENSOR("  ", "AC2_PRESENT_FLAG", this->sensor_ac2_present_flag_);
  }
  if (this->sensor_ac1_present_flag_ != nullptr) {
    LOG_SENSOR("  ", "AC1_PRESENT_FLAG", this->sensor_ac1_present_flag_);
  }
  if (this->sensor_vbus_present_flag_ != nullptr) {
    LOG_SENSOR("  ", "VBUS_PRESENT_FLAG", this->sensor_vbus_present_flag_);
  }
  if (this->sensor_chg_flag_ != nullptr) {
    LOG_SENSOR("  ", "CHG_FLAG", this->sensor_chg_flag_);
  }
  if (this->sensor_ico_flag_ != nullptr) {
    LOG_SENSOR("  ", "ICO_FLAG", this->sensor_ico_flag_);
  }
  if (this->sensor_vbus_flag_ != nullptr) {
    LOG_SENSOR("  ", "VBUS_FLAG", this->sensor_vbus_flag_);
  }
  if (this->sensor_treg_flag_ != nullptr) {
    LOG_SENSOR("  ", "TREG_FLAG", this->sensor_treg_flag_);
  }
  if (this->sensor_vbat_present_flag_ != nullptr) {
    LOG_SENSOR("  ", "VBAT_PRESENT_FLAG", this->sensor_vbat_present_flag_);
  }
  if (this->sensor_bc1_2_done_flag_ != nullptr) {
    LOG_SENSOR("  ", "BC1_2_DONE_FLAG", this->sensor_bc1_2_done_flag_);
  }
  if (this->sensor_dpdm_done_flag_ != nullptr) {
    LOG_SENSOR("  ", "DPDM_DONE_FLAG", this->sensor_dpdm_done_flag_);
  }
  if (this->sensor_adc_done_flag_ != nullptr) {
    LOG_SENSOR("  ", "ADC_DONE_FLAG", this->sensor_adc_done_flag_);
  }
  if (this->sensor_vsys_flag_ != nullptr) {
    LOG_SENSOR("  ", "VSYS_FLAG", this->sensor_vsys_flag_);
  }
  if (this->sensor_chg_tmr_flag_ != nullptr) {
    LOG_SENSOR("  ", "CHG_TMR_FLAG", this->sensor_chg_tmr_flag_);
  }
  if (this->sensor_trichg_tmr_flag_ != nullptr) {
    LOG_SENSOR("  ", "TRICHG_TMR_FLAG", this->sensor_trichg_tmr_flag_);
  }
  if (this->sensor_prechg_tmr_flag_ != nullptr) {
    LOG_SENSOR("  ", "PRECHG_TMR_FLAG", this->sensor_prechg_tmr_flag_);
  }
  if (this->sensor_topoff_tmr_flag_ != nullptr) {
    LOG_SENSOR("  ", "TOPOFF_TMR_FLAG", this->sensor_topoff_tmr_flag_);
  }
  if (this->sensor_vbatotg_low_flag_ != nullptr) {
    LOG_SENSOR("  ", "VBATOTG_LOW_FLAG", this->sensor_vbatotg_low_flag_);
  }
  if (this->sensor_ts_cold_flag_ != nullptr) {
    LOG_SENSOR("  ", "TS_COLD_FLAG", this->sensor_ts_cold_flag_);
  }
  if (this->sensor_ts_cool_flag_ != nullptr) {
    LOG_SENSOR("  ", "TS_COOL_FLAG", this->sensor_ts_cool_flag_);
  }
  if (this->sensor_ts_warm_flag_ != nullptr) {
    LOG_SENSOR("  ", "TS_WARM_FLAG", this->sensor_ts_warm_flag_);
  }
  if (this->sensor_ts_hot_flag_ != nullptr) {
    LOG_SENSOR("  ", "TS_HOT_FLAG", this->sensor_ts_hot_flag_);
  }
  if (this->sensor_ibat_reg_flag_ != nullptr) {
    LOG_SENSOR("  ", "IBAT_REG_FLAG", this->sensor_ibat_reg_flag_);
  }
  if (this->sensor_vbus_ovp_flag_ != nullptr) {
    LOG_SENSOR("  ", "VBUS_OVP_FLAG", this->sensor_vbus_ovp_flag_);
  }
  if (this->sensor_vbat_ovp_flag_ != nullptr) {
    LOG_SENSOR("  ", "VBAT_OVP_FLAG", this->sensor_vbat_ovp_flag_);
  }
  if (this->sensor_ibus_ocp_flag_ != nullptr) {
    LOG_SENSOR("  ", "IBUS_OCP_FLAG", this->sensor_ibus_ocp_flag_);
  }
  if (this->sensor_ibat_ocp_flag_ != nullptr) {
    LOG_SENSOR("  ", "IBAT_OCP_FLAG", this->sensor_ibat_ocp_flag_);
  }
  if (this->sensor_conv_ocp_flag_ != nullptr) {
    LOG_SENSOR("  ", "CONV_OCP_FLAG", this->sensor_conv_ocp_flag_);
  }
  if (this->sensor_vac2_ovp_flag_ != nullptr) {
    LOG_SENSOR("  ", "VAC2_OVP_FLAG", this->sensor_vac2_ovp_flag_);
  }
  if (this->sensor_vac1_ovp_flag_ != nullptr) {
    LOG_SENSOR("  ", "VAC1_OVP_FLAG", this->sensor_vac1_ovp_flag_);
  }
  if (this->sensor_vsys_short_flag_ != nullptr) {
    LOG_SENSOR("  ", "VSYS_SHORT_FLAG", this->sensor_vsys_short_flag_);
  }
  if (this->sensor_vsys_ovp_flag_ != nullptr) {
    LOG_SENSOR("  ", "VSYS_OVP_FLAG", this->sensor_vsys_ovp_flag_);
  }
  if (this->sensor_otg_ovp_flag_ != nullptr) {
    LOG_SENSOR("  ", "OTG_OVP_FLAG", this->sensor_otg_ovp_flag_);
  }
  if (this->sensor_otg_uvp_flag_ != nullptr) {
    LOG_SENSOR("  ", "OTG_UVP_FLAG", this->sensor_otg_uvp_flag_);
  }
  if (this->sensor_tshut_flag_ != nullptr) {
    LOG_SENSOR("  ", "TSHUT_FLAG", this->sensor_tshut_flag_);
  }
  if (this->sensor_adc_en_ != nullptr) {
    LOG_SENSOR("  ", "ADC_EN", this->sensor_adc_en_);
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
  if (this->sensor_adc_avg_init_ != nullptr) {
    LOG_SENSOR("  ", "ADC_AVG_INIT", this->sensor_adc_avg_init_);
  }
  if (this->sensor_ibus_adc_dis_ != nullptr) {
    LOG_SENSOR("  ", "IBUS_ADC_DIS", this->sensor_ibus_adc_dis_);
  }
  if (this->sensor_ibat_adc_dis_ != nullptr) {
    LOG_SENSOR("  ", "IBAT_ADC_DIS", this->sensor_ibat_adc_dis_);
  }
  if (this->sensor_vbus_adc_dis_ != nullptr) {
    LOG_SENSOR("  ", "VBUS_ADC_DIS", this->sensor_vbus_adc_dis_);
  }
  if (this->sensor_vbat_adc_dis_ != nullptr) {
    LOG_SENSOR("  ", "VBAT_ADC_DIS", this->sensor_vbat_adc_dis_);
  }
  if (this->sensor_vsys_adc_dis_ != nullptr) {
    LOG_SENSOR("  ", "VSYS_ADC_DIS", this->sensor_vsys_adc_dis_);
  }
  if (this->sensor_ts_adc_dis_ != nullptr) {
    LOG_SENSOR("  ", "TS_ADC_DIS", this->sensor_ts_adc_dis_);
  }
  if (this->sensor_tdie_adc_dis_ != nullptr) {
    LOG_SENSOR("  ", "TDIE_ADC_DIS", this->sensor_tdie_adc_dis_);
  }
  if (this->sensor_dplus_adc_dis_ != nullptr) {
    LOG_SENSOR("  ", "DPLUS_ADC_DIS", this->sensor_dplus_adc_dis_);
  }
  if (this->sensor_dminus_adc_dis_ != nullptr) {
    LOG_SENSOR("  ", "DMINUS_ADC_DIS", this->sensor_dminus_adc_dis_);
  }
  if (this->sensor_vac2_adc_dis_ != nullptr) {
    LOG_SENSOR("  ", "VAC2_ADC_DIS", this->sensor_vac2_adc_dis_);
  }
  if (this->sensor_vac1_adc_dis_ != nullptr) {
    LOG_SENSOR("  ", "VAC1_ADC_DIS", this->sensor_vac1_adc_dis_);
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
  // VSYSMIN - Minimal System Voltage
  if (this->sensor_vsysmin_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vsysmin_->publish_state(NAN);
    } else {
      this->sensor_vsysmin_->publish_state(this->parent_->get_vsysmin_int());
    }
  }
  // VREG - Charge Voltage Limit
  if (this->sensor_vreg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vreg_->publish_state(NAN);
    } else {
      this->sensor_vreg_->publish_state(this->parent_->get_vreg_int());
    }
  }
  // ICHG - Charge Current Limit
  if (this->sensor_ichg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ichg_->publish_state(NAN);
    } else {
      this->sensor_ichg_->publish_state(this->parent_->get_ichg_int());
    }
  }
  // VINDPM - Input Voltage Limit
  if (this->sensor_vindpm_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vindpm_->publish_state(NAN);
    } else {
      this->sensor_vindpm_->publish_state(this->parent_->get_vindpm_int());
    }
  }
  // IINDPM - Input Current Limit
  if (this->sensor_iindpm_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_iindpm_->publish_state(NAN);
    } else {
      this->sensor_iindpm_->publish_state(this->parent_->get_iindpm_int());
    }
  }
  // VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
  if (this->sensor_vbat_lowv_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbat_lowv_->publish_state(NAN);
    } else {
      this->sensor_vbat_lowv_->publish_state(this->parent_->get_vbat_lowv_enum_int());
    }
  }
  // IPRECHG - Precharge Current Limit
  if (this->sensor_iprechg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_iprechg_->publish_state(NAN);
    } else {
      this->sensor_iprechg_->publish_state(this->parent_->get_iprechg_int());
    }
  }
  // REG_RST - Reset registers to default values and reset timer
  if (this->sensor_reg_rst_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_reg_rst_->publish_state(NAN);
    } else {
      this->sensor_reg_rst_->publish_state(this->parent_->get_reg_rst_enum_int());
    }
  }
  // STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
  if (this->sensor_stop_wd_chg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_stop_wd_chg_->publish_state(NAN);
    } else {
      this->sensor_stop_wd_chg_->publish_state(this->parent_->get_stop_wd_chg_enum_int());
    }
  }
  // ITERM - Termination Current Limit
  if (this->sensor_iterm_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_iterm_->publish_state(NAN);
    } else {
      this->sensor_iterm_->publish_state(this->parent_->get_iterm_int());
    }
  }
  // CELL - Battery cell count
  if (this->sensor_cell_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_cell_->publish_state(NAN);
    } else {
      this->sensor_cell_->publish_state(this->parent_->get_cell_enum_int());
    }
  }
  // TRECHG - Battery recharge delay time
  if (this->sensor_trechg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_trechg_->publish_state(NAN);
    } else {
      this->sensor_trechg_->publish_state(this->parent_->get_trechg_enum_int());
    }
  }
  // VRECHG - Battery Recharge Threshold Offset (Below VREG)
  if (this->sensor_vrechg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vrechg_->publish_state(NAN);
    } else {
      this->sensor_vrechg_->publish_state(this->parent_->get_vrechg_int());
    }
  }
  // VOTG - OTG mode regulation voltage
  if (this->sensor_votg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_votg_->publish_state(NAN);
    } else {
      this->sensor_votg_->publish_state(this->parent_->get_votg_int());
    }
  }
  // PRECHG_TMR - Pre-charge safety timer setting
  if (this->sensor_prechg_tmr_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_prechg_tmr_->publish_state(NAN);
    } else {
      this->sensor_prechg_tmr_->publish_state(this->parent_->get_prechg_tmr_enum_int());
    }
  }
  // IOTG - OTG current limit
  if (this->sensor_iotg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_iotg_->publish_state(NAN);
    } else {
      this->sensor_iotg_->publish_state(this->parent_->get_iotg_int());
    }
  }
  // TOPOFF_TMR - Top-off timer control
  if (this->sensor_topoff_tmr_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_topoff_tmr_->publish_state(NAN);
    } else {
      this->sensor_topoff_tmr_->publish_state(this->parent_->get_topoff_tmr_enum_int());
    }
  }
  // EN_TRICHG_TMR - Trickle charge timer enable
  if (this->sensor_en_trichg_tmr_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_trichg_tmr_->publish_state(NAN);
    } else {
      this->sensor_en_trichg_tmr_->publish_state(this->parent_->get_en_trichg_tmr_enum_int());
    }
  }
  // EN_PRECHG_TMR - Precharge timer enable
  if (this->sensor_en_prechg_tmr_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_prechg_tmr_->publish_state(NAN);
    } else {
      this->sensor_en_prechg_tmr_->publish_state(this->parent_->get_en_prechg_tmr_enum_int());
    }
  }
  // EN_CHG_TMR - Fast charge timer enable
  if (this->sensor_en_chg_tmr_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_chg_tmr_->publish_state(NAN);
    } else {
      this->sensor_en_chg_tmr_->publish_state(this->parent_->get_en_chg_tmr_enum_int());
    }
  }
  // CHG_TMR - Fast charge timer setting
  if (this->sensor_chg_tmr_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_chg_tmr_->publish_state(NAN);
    } else {
      this->sensor_chg_tmr_->publish_state(this->parent_->get_chg_tmr_enum_int());
    }
  }
  // TMR2X_EN - 2x slower charging in DPM enable
  if (this->sensor_tmr2x_en_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_tmr2x_en_->publish_state(NAN);
    } else {
      this->sensor_tmr2x_en_->publish_state(this->parent_->get_tmr2x_en_enum_int());
    }
  }
  // EN_AUTO_IBATDIS - Enable the auto battery discharging during the battery OVP fault
  if (this->sensor_en_auto_ibatdis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_auto_ibatdis_->publish_state(NAN);
    } else {
      this->sensor_en_auto_ibatdis_->publish_state(this->parent_->get_en_auto_ibatdis_enum_int());
    }
  }
  // FORCE_IBATDIS - Force the battery discharging current
  if (this->sensor_force_ibatdis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_force_ibatdis_->publish_state(NAN);
    } else {
      this->sensor_force_ibatdis_->publish_state(this->parent_->get_force_ibatdis_enum_int());
    }
  }
  // EN_CHG - Enable the charger
  if (this->sensor_en_chg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_chg_->publish_state(NAN);
    } else {
      this->sensor_en_chg_->publish_state(this->parent_->get_en_chg_enum_int());
    }
  }
  // EN_ICO - Enable the ICO (Input Current Optimizer)
  if (this->sensor_en_ico_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_ico_->publish_state(NAN);
    } else {
      this->sensor_en_ico_->publish_state(this->parent_->get_en_ico_enum_int());
    }
  }
  // FORCE_ICO - Force the ICO (Input Current Optimizer)
  if (this->sensor_force_ico_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_force_ico_->publish_state(NAN);
    } else {
      this->sensor_force_ico_->publish_state(this->parent_->get_force_ico_enum_int());
    }
  }
  // EN_HIZ - Enable the high impedance mode
  if (this->sensor_en_hiz_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_hiz_->publish_state(NAN);
    } else {
      this->sensor_en_hiz_->publish_state(this->parent_->get_en_hiz_enum_int());
    }
  }
  // EN_TERM - Enable the termination
  if (this->sensor_en_term_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_term_->publish_state(NAN);
    } else {
      this->sensor_en_term_->publish_state(this->parent_->get_en_term_enum_int());
    }
  }
  // EN_BACKUP - Enable the backup (auto OTG) mode
  if (this->sensor_en_backup_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_backup_->publish_state(NAN);
    } else {
      this->sensor_en_backup_->publish_state(this->parent_->get_en_backup_enum_int());
    }
  }
  // VBUS_BACKUP - The thresholds to trigger the backup mode, defined as a ratio of VINDPM
  if (this->sensor_vbus_backup_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbus_backup_->publish_state(NAN);
    } else {
      this->sensor_vbus_backup_->publish_state(this->parent_->get_vbus_backup_enum_int());
    }
  }
  // VAC_OVP - Over voltage protection thresholds
  if (this->sensor_vac_ovp_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vac_ovp_->publish_state(NAN);
    } else {
      this->sensor_vac_ovp_->publish_state(this->parent_->get_vac_ovp_enum_int());
    }
  }
  // WD_RST - I2C watch dog timer reset
  if (this->sensor_wd_rst_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_wd_rst_->publish_state(NAN);
    } else {
      this->sensor_wd_rst_->publish_state(this->parent_->get_wd_rst_enum_int());
    }
  }
  // WATCHDOG - Watchdog timer settings
  if (this->sensor_watchdog_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_watchdog_->publish_state(NAN);
    } else {
      this->sensor_watchdog_->publish_state(this->parent_->get_watchdog_enum_int());
    }
  }
  // FORCE_INDET - Force D+/D- detection
  if (this->sensor_force_indet_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_force_indet_->publish_state(NAN);
    } else {
      this->sensor_force_indet_->publish_state(this->parent_->get_force_indet_enum_int());
    }
  }
  // AUTO_INDET_EN - Enable automatic D+/D- detection
  if (this->sensor_auto_indet_en_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_auto_indet_en_->publish_state(NAN);
    } else {
      this->sensor_auto_indet_en_->publish_state(this->parent_->get_auto_indet_en_enum_int());
    }
  }
  // EN_12V - Enable 12V output in HVDCP
  if (this->sensor_en_12v_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_12v_->publish_state(NAN);
    } else {
      this->sensor_en_12v_->publish_state(this->parent_->get_en_12v_enum_int());
    }
  }
  // EN_9V - Enable 9V output in HVDCP
  if (this->sensor_en_9v_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_9v_->publish_state(NAN);
    } else {
      this->sensor_en_9v_->publish_state(this->parent_->get_en_9v_enum_int());
    }
  }
  // HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
  if (this->sensor_hvdcp_en_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_hvdcp_en_->publish_state(NAN);
    } else {
      this->sensor_hvdcp_en_->publish_state(this->parent_->get_hvdcp_en_enum_int());
    }
  }
  // SDRV_CTRL - Enable external Ship FET control
  if (this->sensor_sdrv_ctrl_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_sdrv_ctrl_->publish_state(NAN);
    } else {
      this->sensor_sdrv_ctrl_->publish_state(this->parent_->get_sdrv_ctrl_enum_int());
    }
  }
  // SDRV_DLY - Delay for SDRV control
  if (this->sensor_sdrv_dly_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_sdrv_dly_->publish_state(NAN);
    } else {
      this->sensor_sdrv_dly_->publish_state(this->parent_->get_sdrv_dly_enum_int());
    }
  }
  // DIS_ACDRV - Disable both AC1 and AC2 drivers
  if (this->sensor_dis_acdrv_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dis_acdrv_->publish_state(NAN);
    } else {
      this->sensor_dis_acdrv_->publish_state(this->parent_->get_dis_acdrv_enum_int());
    }
  }
  // EN_OTG - Enable OTG mode
  if (this->sensor_en_otg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_otg_->publish_state(NAN);
    } else {
      this->sensor_en_otg_->publish_state(this->parent_->get_en_otg_enum_int());
    }
  }
  // PFM_OTG_DIS - Disable PFM in OTG mode
  if (this->sensor_pfm_otg_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_pfm_otg_dis_->publish_state(NAN);
    } else {
      this->sensor_pfm_otg_dis_->publish_state(this->parent_->get_pfm_otg_dis_enum_int());
    }
  }
  // PFM_FWD_DIS - Disable PFM in forward mode
  if (this->sensor_pfm_fwd_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_pfm_fwd_dis_->publish_state(NAN);
    } else {
      this->sensor_pfm_fwd_dis_->publish_state(this->parent_->get_pfm_fwd_dis_enum_int());
    }
  }
  // WKUP_DLY - Wakeup (Ship FET) delay
  if (this->sensor_wkup_dly_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_wkup_dly_->publish_state(NAN);
    } else {
      this->sensor_wkup_dly_->publish_state(this->parent_->get_wkup_dly_enum_int());
    }
  }
  // DIS_LDO - Disable BATFET LDO mode in precharge state
  if (this->sensor_dis_ldo_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dis_ldo_->publish_state(NAN);
    } else {
      this->sensor_dis_ldo_->publish_state(this->parent_->get_dis_ldo_enum_int());
    }
  }
  // DIS_OTG_OOA - Disable OOA in OTG mode
  if (this->sensor_dis_otg_ooa_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dis_otg_ooa_->publish_state(NAN);
    } else {
      this->sensor_dis_otg_ooa_->publish_state(this->parent_->get_dis_otg_ooa_enum_int());
    }
  }
  // DIS_FWD_OOA - Disable OOA in forward mode
  if (this->sensor_dis_fwd_ooa_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dis_fwd_ooa_->publish_state(NAN);
    } else {
      this->sensor_dis_fwd_ooa_->publish_state(this->parent_->get_dis_fwd_ooa_enum_int());
    }
  }
  // EN_ACDRV2 - Enable AC2 gate driver control
  if (this->sensor_en_acdrv2_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_acdrv2_->publish_state(NAN);
    } else {
      this->sensor_en_acdrv2_->publish_state(this->parent_->get_en_acdrv2_enum_int());
    }
  }
  // EN_ACDRV1 - Enable AC1 gate driver control
  if (this->sensor_en_acdrv1_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_acdrv1_->publish_state(NAN);
    } else {
      this->sensor_en_acdrv1_->publish_state(this->parent_->get_en_acdrv1_enum_int());
    }
  }
  // PWM_FREQ - PWM frequency setting
  if (this->sensor_pwm_freq_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_pwm_freq_->publish_state(NAN);
    } else {
      this->sensor_pwm_freq_->publish_state(this->parent_->get_pwm_freq_enum_int());
    }
  }
  // DIS_STAT - Disable STAT pin output
  if (this->sensor_dis_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dis_stat_->publish_state(NAN);
    } else {
      this->sensor_dis_stat_->publish_state(this->parent_->get_dis_stat_enum_int());
    }
  }
  // DIS_VSYS_SHORT - Disable VSYS short hiccup protection
  if (this->sensor_dis_vsys_short_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dis_vsys_short_->publish_state(NAN);
    } else {
      this->sensor_dis_vsys_short_->publish_state(this->parent_->get_dis_vsys_short_enum_int());
    }
  }
  // DIS_VOTG_UVP - Disable VOTG under voltage hiccup protection
  if (this->sensor_dis_votg_uvp_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dis_votg_uvp_->publish_state(NAN);
    } else {
      this->sensor_dis_votg_uvp_->publish_state(this->parent_->get_dis_votg_uvp_enum_int());
    }
  }
  // FORCE_VINDPM_DET - Force VINDPM detection (settable only when VBAT>VSYSMIN)
  if (this->sensor_force_vindpm_det_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_force_vindpm_det_->publish_state(NAN);
    } else {
      this->sensor_force_vindpm_det_->publish_state(this->parent_->get_force_vindpm_det_enum_int());
    }
  }
  // EN_IBUS_OCP - Enable input over current protection in forward mode
  if (this->sensor_en_ibus_ocp_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_ibus_ocp_->publish_state(NAN);
    } else {
      this->sensor_en_ibus_ocp_->publish_state(this->parent_->get_en_ibus_ocp_enum_int());
    }
  }
  // SFET_PRESENT - Ship FET present
  if (this->sensor_sfet_present_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_sfet_present_->publish_state(NAN);
    } else {
      this->sensor_sfet_present_->publish_state(this->parent_->get_sfet_present_enum_int());
    }
  }
  // EN_IBAT - Enable battery discharge current sensing
  if (this->sensor_en_ibat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_ibat_->publish_state(NAN);
    } else {
      this->sensor_en_ibat_->publish_state(this->parent_->get_en_ibat_enum_int());
    }
  }
  // IBAT_REG - Battery discharge current regulation in OTG mode
  if (this->sensor_ibat_reg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ibat_reg_->publish_state(NAN);
    } else {
      this->sensor_ibat_reg_->publish_state(this->parent_->get_ibat_reg_enum_int());
    }
  }
  // EN_IINDPM - Enable input current regulation
  if (this->sensor_en_iindpm_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_iindpm_->publish_state(NAN);
    } else {
      this->sensor_en_iindpm_->publish_state(this->parent_->get_en_iindpm_enum_int());
    }
  }
  // EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
  if (this->sensor_en_extilim_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_extilim_->publish_state(NAN);
    } else {
      this->sensor_en_extilim_->publish_state(this->parent_->get_en_extilim_enum_int());
    }
  }
  // EN_BATOC - Enable battery discharging over current protection
  if (this->sensor_en_batoc_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_batoc_->publish_state(NAN);
    } else {
      this->sensor_en_batoc_->publish_state(this->parent_->get_en_batoc_enum_int());
    }
  }
  // VOC_PCT - Set VINDPM as a percentage of the VBUS open circuit voltage when the VOC measurement is done
  if (this->sensor_voc_pct_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_voc_pct_->publish_state(NAN);
    } else {
      this->sensor_voc_pct_->publish_state(this->parent_->get_voc_pct_enum_int());
    }
  }
  // VOC_DLY - After the converter stops switching, the time delay before the VOC is measured
  if (this->sensor_voc_dly_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_voc_dly_->publish_state(NAN);
    } else {
      this->sensor_voc_dly_->publish_state(this->parent_->get_voc_dly_enum_int());
    }
  }
  // VOC_RATE - The time interval between two consecutive VOC measurements
  if (this->sensor_voc_rate_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_voc_rate_->publish_state(NAN);
    } else {
      this->sensor_voc_rate_->publish_state(this->parent_->get_voc_rate_enum_int());
    }
  }
  // EN_MPPT - Enable MPPT (Maximum Power Point Tracking)
  if (this->sensor_en_mppt_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_en_mppt_->publish_state(NAN);
    } else {
      this->sensor_en_mppt_->publish_state(this->parent_->get_en_mppt_enum_int());
    }
  }
  // TREG - Thermal regulation thresholds
  if (this->sensor_treg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_treg_->publish_state(NAN);
    } else {
      this->sensor_treg_->publish_state(this->parent_->get_treg_enum_int());
    }
  }
  // TSHUT - Thermal shutdown thresholds
  if (this->sensor_tshut_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_tshut_->publish_state(NAN);
    } else {
      this->sensor_tshut_->publish_state(this->parent_->get_tshut_enum_int());
    }
  }
  // VBUS_PD_EN - Enable VBUS pull down resistor (6 kOhm)
  if (this->sensor_vbus_pd_en_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbus_pd_en_->publish_state(NAN);
    } else {
      this->sensor_vbus_pd_en_->publish_state(this->parent_->get_vbus_pd_en_enum_int());
    }
  }
  // VAC1_PD_EN - Enable VAC1 pull down resistor
  if (this->sensor_vac1_pd_en_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vac1_pd_en_->publish_state(NAN);
    } else {
      this->sensor_vac1_pd_en_->publish_state(this->parent_->get_vac1_pd_en_enum_int());
    }
  }
  // VAC2_PD_EN - Enable VAC2 pull down resistor
  if (this->sensor_vac2_pd_en_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vac2_pd_en_->publish_state(NAN);
    } else {
      this->sensor_vac2_pd_en_->publish_state(this->parent_->get_vac2_pd_en_enum_int());
    }
  }
  // BKUP_ACFET1_ON - Enable ACFET1 in backup mode (exit backup mode)
  if (this->sensor_bkup_acfet1_on_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_bkup_acfet1_on_->publish_state(NAN);
    } else {
      this->sensor_bkup_acfet1_on_->publish_state(this->parent_->get_bkup_acfet1_on_enum_int());
    }
  }
  // JEITA_VSET - JEITA high temperature range (TWARN - THOT) charge voltage setting
  if (this->sensor_jeita_vset_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_jeita_vset_->publish_state(NAN);
    } else {
      this->sensor_jeita_vset_->publish_state(this->parent_->get_jeita_vset_enum_int());
    }
  }
  // JEITA_ISETH - JEITA high temperature range (TWARN - THOT) charge current setting
  if (this->sensor_jeita_iseth_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_jeita_iseth_->publish_state(NAN);
    } else {
      this->sensor_jeita_iseth_->publish_state(this->parent_->get_jeita_iseth_enum_int());
    }
  }
  // JEITA_ISETC - JEITA low temperature range (TCOLD - TWARN) charge current setting
  if (this->sensor_jeita_isetc_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_jeita_isetc_->publish_state(NAN);
    } else {
      this->sensor_jeita_isetc_->publish_state(this->parent_->get_jeita_isetc_enum_int());
    }
  }
  // TS_COOL - JEITA VT2 comparator voltage rising thresholds as a percentage of REGN.
  if (this->sensor_ts_cool_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ts_cool_->publish_state(NAN);
    } else {
      this->sensor_ts_cool_->publish_state(this->parent_->get_ts_cool_enum_int());
    }
  }
  // TS_WARM - JEITA VT3 comparator voltage falling thresholds as a percentage of REGN.
  if (this->sensor_ts_warm_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ts_warm_->publish_state(NAN);
    } else {
      this->sensor_ts_warm_->publish_state(this->parent_->get_ts_warm_enum_int());
    }
  }
  // BHOT - OTG mode TS HOT temperature threshold
  if (this->sensor_bhot_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_bhot_->publish_state(NAN);
    } else {
      this->sensor_bhot_->publish_state(this->parent_->get_bhot_enum_int());
    }
  }
  // BCOLD - OTG mode TS COLD temperature threshold
  if (this->sensor_bcold_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_bcold_->publish_state(NAN);
    } else {
      this->sensor_bcold_->publish_state(this->parent_->get_bcold_enum_int());
    }
  }
  // TS_IGNORE - Ignore TS detection (the charger considers the TS is always good)
  if (this->sensor_ts_ignore_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ts_ignore_->publish_state(NAN);
    } else {
      this->sensor_ts_ignore_->publish_state(this->parent_->get_ts_ignore_enum_int());
    }
  }
  // ICO_ILIM - Input Current Limit obtained from ICO or ILIM_HIZ pin setting
  if (this->sensor_ico_ilim_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ico_ilim_->publish_state(NAN);
    } else {
      this->sensor_ico_ilim_->publish_state(this->parent_->get_ico_ilim_int());
    }
  }
  // IINDPM_STAT - IINDPM status (forward mode) or IOTG status (OTG mode)
  if (this->sensor_iindpm_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_iindpm_stat_->publish_state(NAN);
    } else {
      this->sensor_iindpm_stat_->publish_state(this->parent_->get_iindpm_stat_enum_int());
    }
  }
  // VINDPM_STAT - VINDPM status (forward mode) or VOTG status (OTG mode)
  if (this->sensor_vindpm_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vindpm_stat_->publish_state(NAN);
    } else {
      this->sensor_vindpm_stat_->publish_state(this->parent_->get_vindpm_stat_enum_int());
    }
  }
  // WD_STAT - Watchdog timer status
  if (this->sensor_wd_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_wd_stat_->publish_state(NAN);
    } else {
      this->sensor_wd_stat_->publish_state(this->parent_->get_wd_stat_enum_int());
    }
  }
  // PG_STAT - Power good status
  if (this->sensor_pg_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_pg_stat_->publish_state(NAN);
    } else {
      this->sensor_pg_stat_->publish_state(this->parent_->get_pg_stat_enum_int());
    }
  }
  // AC2_PRESENT_STAT - VAC2 present status
  if (this->sensor_ac2_present_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ac2_present_stat_->publish_state(NAN);
    } else {
      this->sensor_ac2_present_stat_->publish_state(this->parent_->get_ac2_present_stat_enum_int());
    }
  }
  // AC1_PRESENT_STAT - VAC1 present status
  if (this->sensor_ac1_present_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ac1_present_stat_->publish_state(NAN);
    } else {
      this->sensor_ac1_present_stat_->publish_state(this->parent_->get_ac1_present_stat_enum_int());
    }
  }
  // VBUS_PRESENT_STAT - VBUS present status
  if (this->sensor_vbus_present_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbus_present_stat_->publish_state(NAN);
    } else {
      this->sensor_vbus_present_stat_->publish_state(this->parent_->get_vbus_present_stat_enum_int());
    }
  }
  // CHG_STAT - Charge Status bits
  if (this->sensor_chg_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_chg_stat_->publish_state(NAN);
    } else {
      this->sensor_chg_stat_->publish_state(this->parent_->get_chg_stat_enum_int());
    }
  }
  // VBUS_STAT - VBUS status bits
  if (this->sensor_vbus_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbus_stat_->publish_state(NAN);
    } else {
      this->sensor_vbus_stat_->publish_state(this->parent_->get_vbus_stat_enum_int());
    }
  }
  // BC12_DONE_STAT - BC1.2 detection done status
  if (this->sensor_bc12_done_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_bc12_done_stat_->publish_state(NAN);
    } else {
      this->sensor_bc12_done_stat_->publish_state(this->parent_->get_bc12_done_stat_enum_int());
    }
  }
  // ICO_STAT - Input Current Optimizer (ICO) status
  if (this->sensor_ico_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ico_stat_->publish_state(NAN);
    } else {
      this->sensor_ico_stat_->publish_state(this->parent_->get_ico_stat_enum_int());
    }
  }
  // TREG_STAT - IC thermal regulation status
  if (this->sensor_treg_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_treg_stat_->publish_state(NAN);
    } else {
      this->sensor_treg_stat_->publish_state(this->parent_->get_treg_stat_enum_int());
    }
  }
  // DPDM_STAT - D+/D- detection status
  if (this->sensor_dpdm_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dpdm_stat_->publish_state(NAN);
    } else {
      this->sensor_dpdm_stat_->publish_state(this->parent_->get_dpdm_stat_enum_int());
    }
  }
  // VBAT_PRESENT_STAT - Battery present status
  if (this->sensor_vbat_present_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbat_present_stat_->publish_state(NAN);
    } else {
      this->sensor_vbat_present_stat_->publish_state(this->parent_->get_vbat_present_stat_enum_int());
    }
  }
  // ACRB2_STAT - The ACFET2-RBFET2 status
  if (this->sensor_acrb2_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_acrb2_stat_->publish_state(NAN);
    } else {
      this->sensor_acrb2_stat_->publish_state(this->parent_->get_acrb2_stat_enum_int());
    }
  }
  // ACRB1_STAT - The ACFET1-RBFET1 status
  if (this->sensor_acrb1_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_acrb1_stat_->publish_state(NAN);
    } else {
      this->sensor_acrb1_stat_->publish_state(this->parent_->get_acrb1_stat_enum_int());
    }
  }
  // ADC_DONE_STAT - ADC Conversion Status
  if (this->sensor_adc_done_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_adc_done_stat_->publish_state(NAN);
    } else {
      this->sensor_adc_done_stat_->publish_state(this->parent_->get_adc_done_stat_enum_int());
    }
  }
  // VSYS_STAT - VSYS Regulation Status
  if (this->sensor_vsys_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vsys_stat_->publish_state(NAN);
    } else {
      this->sensor_vsys_stat_->publish_state(this->parent_->get_vsys_stat_enum_int());
    }
  }
  // CHG_TMR_STAT - Fast charge timer status
  if (this->sensor_chg_tmr_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_chg_tmr_stat_->publish_state(NAN);
    } else {
      this->sensor_chg_tmr_stat_->publish_state(this->parent_->get_chg_tmr_stat_enum_int());
    }
  }
  // TRICHG_TMR_STAT - Trickle charge timer status
  if (this->sensor_trichg_tmr_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_trichg_tmr_stat_->publish_state(NAN);
    } else {
      this->sensor_trichg_tmr_stat_->publish_state(this->parent_->get_trichg_tmr_stat_enum_int());
    }
  }
  // PRECHG_TMR_STAT - Pre-charge timer status
  if (this->sensor_prechg_tmr_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_prechg_tmr_stat_->publish_state(NAN);
    } else {
      this->sensor_prechg_tmr_stat_->publish_state(this->parent_->get_prechg_tmr_stat_enum_int());
    }
  }
  // VBATOTG_LOW_STAT - The battery voltage is too low to enable OTG mode
  if (this->sensor_vbatotg_low_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbatotg_low_stat_->publish_state(NAN);
    } else {
      this->sensor_vbatotg_low_stat_->publish_state(this->parent_->get_vbatotg_low_stat_enum_int());
    }
  }
  // TS_COLD_STAT - The TS temperature is in the cold range
  if (this->sensor_ts_cold_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ts_cold_stat_->publish_state(NAN);
    } else {
      this->sensor_ts_cold_stat_->publish_state(this->parent_->get_ts_cold_stat_enum_int());
    }
  }
  // TS_COOL_STAT - The TS temperature is in the cool range
  if (this->sensor_ts_cool_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ts_cool_stat_->publish_state(NAN);
    } else {
      this->sensor_ts_cool_stat_->publish_state(this->parent_->get_ts_cool_stat_enum_int());
    }
  }
  // TS_WARM_STAT - The TS temperature is in the warm range
  if (this->sensor_ts_warm_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ts_warm_stat_->publish_state(NAN);
    } else {
      this->sensor_ts_warm_stat_->publish_state(this->parent_->get_ts_warm_stat_enum_int());
    }
  }
  // TS_HOT_STAT - The TS temperature is in the hot range
  if (this->sensor_ts_hot_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ts_hot_stat_->publish_state(NAN);
    } else {
      this->sensor_ts_hot_stat_->publish_state(this->parent_->get_ts_hot_stat_enum_int());
    }
  }
  // IBAT_REG_STAT - In battery discharging current regulation
  if (this->sensor_ibat_reg_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ibat_reg_stat_->publish_state(NAN);
    } else {
      this->sensor_ibat_reg_stat_->publish_state(this->parent_->get_ibat_reg_stat_enum_int());
    }
  }
  // VBUS_OVP_STAT - VBUS over-voltage status
  if (this->sensor_vbus_ovp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbus_ovp_stat_->publish_state(NAN);
    } else {
      this->sensor_vbus_ovp_stat_->publish_state(this->parent_->get_vbus_ovp_stat_enum_int());
    }
  }
  // VBAT_OVP_STAT - VBAT over-voltage status
  if (this->sensor_vbat_ovp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbat_ovp_stat_->publish_state(NAN);
    } else {
      this->sensor_vbat_ovp_stat_->publish_state(this->parent_->get_vbat_ovp_stat_enum_int());
    }
  }
  // IBUS_OCP_STAT - IBUS over-current status
  if (this->sensor_ibus_ocp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ibus_ocp_stat_->publish_state(NAN);
    } else {
      this->sensor_ibus_ocp_stat_->publish_state(this->parent_->get_ibus_ocp_stat_enum_int());
    }
  }
  // IBAT_OCP_STAT - IBAT over-current status
  if (this->sensor_ibat_ocp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ibat_ocp_stat_->publish_state(NAN);
    } else {
      this->sensor_ibat_ocp_stat_->publish_state(this->parent_->get_ibat_ocp_stat_enum_int());
    }
  }
  // CONV_OCP_STAT - Converter over-current status
  if (this->sensor_conv_ocp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_conv_ocp_stat_->publish_state(NAN);
    } else {
      this->sensor_conv_ocp_stat_->publish_state(this->parent_->get_conv_ocp_stat_enum_int());
    }
  }
  // VAC2_OVP_STAT - VAC2 over-voltage status
  if (this->sensor_vac2_ovp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vac2_ovp_stat_->publish_state(NAN);
    } else {
      this->sensor_vac2_ovp_stat_->publish_state(this->parent_->get_vac2_ovp_stat_enum_int());
    }
  }
  // VAC1_OVP_STAT - VAC1 over-voltage status
  if (this->sensor_vac1_ovp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vac1_ovp_stat_->publish_state(NAN);
    } else {
      this->sensor_vac1_ovp_stat_->publish_state(this->parent_->get_vac1_ovp_stat_enum_int());
    }
  }
  // VSYS_SHORT_STAT - VSYS short circuit status
  if (this->sensor_vsys_short_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vsys_short_stat_->publish_state(NAN);
    } else {
      this->sensor_vsys_short_stat_->publish_state(this->parent_->get_vsys_short_stat_enum_int());
    }
  }
  // VSYS_OVP_STAT - VSYS over-voltage status
  if (this->sensor_vsys_ovp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vsys_ovp_stat_->publish_state(NAN);
    } else {
      this->sensor_vsys_ovp_stat_->publish_state(this->parent_->get_vsys_ovp_stat_enum_int());
    }
  }
  // OTG_OVP_STAT - OTG over-voltage status
  if (this->sensor_otg_ovp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_otg_ovp_stat_->publish_state(NAN);
    } else {
      this->sensor_otg_ovp_stat_->publish_state(this->parent_->get_otg_ovp_stat_enum_int());
    }
  }
  // OTG_UVP_STAT - OTG under-voltage status
  if (this->sensor_otg_uvp_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_otg_uvp_stat_->publish_state(NAN);
    } else {
      this->sensor_otg_uvp_stat_->publish_state(this->parent_->get_otg_uvp_stat_enum_int());
    }
  }
  // TSHUT_STAT - IC thermal shutdown status
  if (this->sensor_tshut_stat_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_tshut_stat_->publish_state(NAN);
    } else {
      this->sensor_tshut_stat_->publish_state(this->parent_->get_tshut_stat_enum_int());
    }
  }
  // IINDPM_FLAG - IINDPM / IOTG flag
  if (this->sensor_iindpm_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_iindpm_flag_->publish_state(NAN);
    } else {
      this->sensor_iindpm_flag_->publish_state(this->parent_->get_iindpm_flag_enum_int());
    }
  }
  // VINDPM_FLAG - VINDPM / VOTG Flag
  if (this->sensor_vindpm_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vindpm_flag_->publish_state(NAN);
    } else {
      this->sensor_vindpm_flag_->publish_state(this->parent_->get_vindpm_flag_enum_int());
    }
  }
  // WD_FLAG - I2C watchdog timer flag
  if (this->sensor_wd_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_wd_flag_->publish_state(NAN);
    } else {
      this->sensor_wd_flag_->publish_state(this->parent_->get_wd_flag_enum_int());
    }
  }
  // POORSRC_FLAG - Poor source detection flag
  if (this->sensor_poorsrc_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_poorsrc_flag_->publish_state(NAN);
    } else {
      this->sensor_poorsrc_flag_->publish_state(this->parent_->get_poorsrc_flag_enum_int());
    }
  }
  // PG_FLAG - Poor source detection flag
  if (this->sensor_pg_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_pg_flag_->publish_state(NAN);
    } else {
      this->sensor_pg_flag_->publish_state(this->parent_->get_pg_flag_enum_int());
    }
  }
  // AC2_PRESENT_FLAG - VAC2 present flag
  if (this->sensor_ac2_present_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ac2_present_flag_->publish_state(NAN);
    } else {
      this->sensor_ac2_present_flag_->publish_state(this->parent_->get_ac2_present_flag_enum_int());
    }
  }
  // AC1_PRESENT_FLAG - VAC1 present flag
  if (this->sensor_ac1_present_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ac1_present_flag_->publish_state(NAN);
    } else {
      this->sensor_ac1_present_flag_->publish_state(this->parent_->get_ac1_present_flag_enum_int());
    }
  }
  // VBUS_PRESENT_FLAG - VBUS present flag
  if (this->sensor_vbus_present_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbus_present_flag_->publish_state(NAN);
    } else {
      this->sensor_vbus_present_flag_->publish_state(this->parent_->get_vbus_present_flag_enum_int());
    }
  }
  // CHG_FLAG - Charge status flag
  if (this->sensor_chg_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_chg_flag_->publish_state(NAN);
    } else {
      this->sensor_chg_flag_->publish_state(this->parent_->get_chg_flag_enum_int());
    }
  }
  // ICO_FLAG - ICO status flag
  if (this->sensor_ico_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ico_flag_->publish_state(NAN);
    } else {
      this->sensor_ico_flag_->publish_state(this->parent_->get_ico_flag_enum_int());
    }
  }
  // VBUS_FLAG - VBUS status flag
  if (this->sensor_vbus_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbus_flag_->publish_state(NAN);
    } else {
      this->sensor_vbus_flag_->publish_state(this->parent_->get_vbus_flag_enum_int());
    }
  }
  // TREG_FLAG - IC thermal regulation flag
  if (this->sensor_treg_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_treg_flag_->publish_state(NAN);
    } else {
      this->sensor_treg_flag_->publish_state(this->parent_->get_treg_flag_enum_int());
    }
  }
  // VBAT_PRESENT_FLAG - VBAT present flag
  if (this->sensor_vbat_present_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbat_present_flag_->publish_state(NAN);
    } else {
      this->sensor_vbat_present_flag_->publish_state(this->parent_->get_vbat_present_flag_enum_int());
    }
  }
  // BC1_2_DONE_FLAG - BC1.2 status Flag
  if (this->sensor_bc1_2_done_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_bc1_2_done_flag_->publish_state(NAN);
    } else {
      this->sensor_bc1_2_done_flag_->publish_state(this->parent_->get_bc1_2_done_flag_enum_int());
    }
  }
  // DPDM_DONE_FLAG - D+/D- detection is done flag.
  if (this->sensor_dpdm_done_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dpdm_done_flag_->publish_state(NAN);
    } else {
      this->sensor_dpdm_done_flag_->publish_state(this->parent_->get_dpdm_done_flag_enum_int());
    }
  }
  // ADC_DONE_FLAG - ADC conversion flag (only in one-shot mode)
  if (this->sensor_adc_done_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_adc_done_flag_->publish_state(NAN);
    } else {
      this->sensor_adc_done_flag_->publish_state(this->parent_->get_adc_done_flag_enum_int());
    }
  }
  // VSYS_FLAG - VSYSMIN regulation flag
  if (this->sensor_vsys_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vsys_flag_->publish_state(NAN);
    } else {
      this->sensor_vsys_flag_->publish_state(this->parent_->get_vsys_flag_enum_int());
    }
  }
  // CHG_TMR_FLAG - Fast charge timer flag
  if (this->sensor_chg_tmr_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_chg_tmr_flag_->publish_state(NAN);
    } else {
      this->sensor_chg_tmr_flag_->publish_state(this->parent_->get_chg_tmr_flag_enum_int());
    }
  }
  // TRICHG_TMR_FLAG - Trickle charge timer flag
  if (this->sensor_trichg_tmr_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_trichg_tmr_flag_->publish_state(NAN);
    } else {
      this->sensor_trichg_tmr_flag_->publish_state(this->parent_->get_trichg_tmr_flag_enum_int());
    }
  }
  // PRECHG_TMR_FLAG - Pre-charge timer flag
  if (this->sensor_prechg_tmr_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_prechg_tmr_flag_->publish_state(NAN);
    } else {
      this->sensor_prechg_tmr_flag_->publish_state(this->parent_->get_prechg_tmr_flag_enum_int());
    }
  }
  // TOPOFF_TMR_FLAG - Top off timer flag
  if (this->sensor_topoff_tmr_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_topoff_tmr_flag_->publish_state(NAN);
    } else {
      this->sensor_topoff_tmr_flag_->publish_state(this->parent_->get_topoff_tmr_flag_enum_int());
    }
  }
  // VBATOTG_LOW_FLAG - VBAT too low to enable OTG flag
  if (this->sensor_vbatotg_low_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbatotg_low_flag_->publish_state(NAN);
    } else {
      this->sensor_vbatotg_low_flag_->publish_state(this->parent_->get_vbatotg_low_flag_enum_int());
    }
  }
  // TS_COLD_FLAG - TS cold temperature flag
  if (this->sensor_ts_cold_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ts_cold_flag_->publish_state(NAN);
    } else {
      this->sensor_ts_cold_flag_->publish_state(this->parent_->get_ts_cold_flag_enum_int());
    }
  }
  // TS_COOL_FLAG - TS cool temperature flag
  if (this->sensor_ts_cool_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ts_cool_flag_->publish_state(NAN);
    } else {
      this->sensor_ts_cool_flag_->publish_state(this->parent_->get_ts_cool_flag_enum_int());
    }
  }
  // TS_WARM_FLAG - TS warm temperature flag
  if (this->sensor_ts_warm_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ts_warm_flag_->publish_state(NAN);
    } else {
      this->sensor_ts_warm_flag_->publish_state(this->parent_->get_ts_warm_flag_enum_int());
    }
  }
  // TS_HOT_FLAG - TS hot temperature flag
  if (this->sensor_ts_hot_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ts_hot_flag_->publish_state(NAN);
    } else {
      this->sensor_ts_hot_flag_->publish_state(this->parent_->get_ts_hot_flag_enum_int());
    }
  }
  // IBAT_REG_FLAG - IBAT regulation flag
  if (this->sensor_ibat_reg_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ibat_reg_flag_->publish_state(NAN);
    } else {
      this->sensor_ibat_reg_flag_->publish_state(this->parent_->get_ibat_reg_flag_enum_int());
    }
  }
  // VBUS_OVP_FLAG - VBUS over-voltage flag
  if (this->sensor_vbus_ovp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbus_ovp_flag_->publish_state(NAN);
    } else {
      this->sensor_vbus_ovp_flag_->publish_state(this->parent_->get_vbus_ovp_flag_enum_int());
    }
  }
  // VBAT_OVP_FLAG - VBAT over-voltage flag
  if (this->sensor_vbat_ovp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbat_ovp_flag_->publish_state(NAN);
    } else {
      this->sensor_vbat_ovp_flag_->publish_state(this->parent_->get_vbat_ovp_flag_enum_int());
    }
  }
  // IBUS_OCP_FLAG - IBUS over-current flag
  if (this->sensor_ibus_ocp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ibus_ocp_flag_->publish_state(NAN);
    } else {
      this->sensor_ibus_ocp_flag_->publish_state(this->parent_->get_ibus_ocp_flag_enum_int());
    }
  }
  // IBAT_OCP_FLAG - IBAT over-current flag
  if (this->sensor_ibat_ocp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ibat_ocp_flag_->publish_state(NAN);
    } else {
      this->sensor_ibat_ocp_flag_->publish_state(this->parent_->get_ibat_ocp_flag_enum_int());
    }
  }
  // CONV_OCP_FLAG - Converter over-current flag
  if (this->sensor_conv_ocp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_conv_ocp_flag_->publish_state(NAN);
    } else {
      this->sensor_conv_ocp_flag_->publish_state(this->parent_->get_conv_ocp_flag_enum_int());
    }
  }
  // VAC2_OVP_FLAG - VAC2 over-voltage flag
  if (this->sensor_vac2_ovp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vac2_ovp_flag_->publish_state(NAN);
    } else {
      this->sensor_vac2_ovp_flag_->publish_state(this->parent_->get_vac2_ovp_flag_enum_int());
    }
  }
  // VAC1_OVP_FLAG - VAC1 over-voltage flag
  if (this->sensor_vac1_ovp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vac1_ovp_flag_->publish_state(NAN);
    } else {
      this->sensor_vac1_ovp_flag_->publish_state(this->parent_->get_vac1_ovp_flag_enum_int());
    }
  }
  // VSYS_SHORT_FLAG - VSYS short circuit flag
  if (this->sensor_vsys_short_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vsys_short_flag_->publish_state(NAN);
    } else {
      this->sensor_vsys_short_flag_->publish_state(this->parent_->get_vsys_short_flag_enum_int());
    }
  }
  // VSYS_OVP_FLAG - VSYS over-voltage flag
  if (this->sensor_vsys_ovp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vsys_ovp_flag_->publish_state(NAN);
    } else {
      this->sensor_vsys_ovp_flag_->publish_state(this->parent_->get_vsys_ovp_flag_enum_int());
    }
  }
  // OTG_OVP_FLAG - OTG over-voltage flag
  if (this->sensor_otg_ovp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_otg_ovp_flag_->publish_state(NAN);
    } else {
      this->sensor_otg_ovp_flag_->publish_state(this->parent_->get_otg_ovp_flag_enum_int());
    }
  }
  // OTG_UVP_FLAG - OTG under-voltage flag
  if (this->sensor_otg_uvp_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_otg_uvp_flag_->publish_state(NAN);
    } else {
      this->sensor_otg_uvp_flag_->publish_state(this->parent_->get_otg_uvp_flag_enum_int());
    }
  }
  // TSHUT_FLAG - IC thermal shutdown flag
  if (this->sensor_tshut_flag_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_tshut_flag_->publish_state(NAN);
    } else {
      this->sensor_tshut_flag_->publish_state(this->parent_->get_tshut_flag_enum_int());
    }
  }
  // ADC_EN - ADC enable
  if (this->sensor_adc_en_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_adc_en_->publish_state(NAN);
    } else {
      this->sensor_adc_en_->publish_state(this->parent_->get_adc_en_enum_int());
    }
  }
  // ADC_RATE - ADC conversion rate
  if (this->sensor_adc_rate_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_adc_rate_->publish_state(NAN);
    } else {
      this->sensor_adc_rate_->publish_state(this->parent_->get_adc_rate_enum_int());
    }
  }
  // ADC_SAMPLE - ADC sample speed
  if (this->sensor_adc_sample_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_adc_sample_->publish_state(NAN);
    } else {
      this->sensor_adc_sample_->publish_state(this->parent_->get_adc_sample_enum_int());
    }
  }
  // ADC_AVG - ADC averaging
  if (this->sensor_adc_avg_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_adc_avg_->publish_state(NAN);
    } else {
      this->sensor_adc_avg_->publish_state(this->parent_->get_adc_avg_enum_int());
    }
  }
  // ADC_AVG_INIT - ADC average initialization
  if (this->sensor_adc_avg_init_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_adc_avg_init_->publish_state(NAN);
    } else {
      this->sensor_adc_avg_init_->publish_state(this->parent_->get_adc_avg_init_enum_int());
    }
  }
  // IBUS_ADC_DIS - IBUS ADC disable
  if (this->sensor_ibus_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ibus_adc_dis_->publish_state(NAN);
    } else {
      this->sensor_ibus_adc_dis_->publish_state(this->parent_->get_ibus_adc_dis_enum_int());
    }
  }
  // IBAT_ADC_DIS - IBAT ADC disable
  if (this->sensor_ibat_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ibat_adc_dis_->publish_state(NAN);
    } else {
      this->sensor_ibat_adc_dis_->publish_state(this->parent_->get_ibat_adc_dis_enum_int());
    }
  }
  // VBUS_ADC_DIS - VBUS ADC disable
  if (this->sensor_vbus_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbus_adc_dis_->publish_state(NAN);
    } else {
      this->sensor_vbus_adc_dis_->publish_state(this->parent_->get_vbus_adc_dis_enum_int());
    }
  }
  // VBAT_ADC_DIS - VBAT ADC disable
  if (this->sensor_vbat_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbat_adc_dis_->publish_state(NAN);
    } else {
      this->sensor_vbat_adc_dis_->publish_state(this->parent_->get_vbat_adc_dis_enum_int());
    }
  }
  // VSYS_ADC_DIS - VSYS ADC disable
  if (this->sensor_vsys_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vsys_adc_dis_->publish_state(NAN);
    } else {
      this->sensor_vsys_adc_dis_->publish_state(this->parent_->get_vsys_adc_dis_enum_int());
    }
  }
  // TS_ADC_DIS - TS ADC disable
  if (this->sensor_ts_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ts_adc_dis_->publish_state(NAN);
    } else {
      this->sensor_ts_adc_dis_->publish_state(this->parent_->get_ts_adc_dis_enum_int());
    }
  }
  // TDIE_ADC_DIS - TDIE ADC disable
  if (this->sensor_tdie_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_tdie_adc_dis_->publish_state(NAN);
    } else {
      this->sensor_tdie_adc_dis_->publish_state(this->parent_->get_tdie_adc_dis_enum_int());
    }
  }
  // DPLUS_ADC_DIS - D+ ADC disable
  if (this->sensor_dplus_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dplus_adc_dis_->publish_state(NAN);
    } else {
      this->sensor_dplus_adc_dis_->publish_state(this->parent_->get_dplus_adc_dis_enum_int());
    }
  }
  // DMINUS_ADC_DIS - D- ADC disable
  if (this->sensor_dminus_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dminus_adc_dis_->publish_state(NAN);
    } else {
      this->sensor_dminus_adc_dis_->publish_state(this->parent_->get_dminus_adc_dis_enum_int());
    }
  }
  // VAC2_ADC_DIS - VAC2 ADC disable
  if (this->sensor_vac2_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vac2_adc_dis_->publish_state(NAN);
    } else {
      this->sensor_vac2_adc_dis_->publish_state(this->parent_->get_vac2_adc_dis_enum_int());
    }
  }
  // VAC1_ADC_DIS - VAC1 ADC disable
  if (this->sensor_vac1_adc_dis_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vac1_adc_dis_->publish_state(NAN);
    } else {
      this->sensor_vac1_adc_dis_->publish_state(this->parent_->get_vac1_adc_dis_enum_int());
    }
  }
  // IBUS_ADC - IBUS ADC reading
  if (this->sensor_ibus_adc_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ibus_adc_->publish_state(NAN);
    } else {
      this->sensor_ibus_adc_->publish_state(this->parent_->get_ibus_adc_int());
    }
  }
  // IBAT_ADC - IBAT ADC reading
  if (this->sensor_ibat_adc_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ibat_adc_->publish_state(NAN);
    } else {
      this->sensor_ibat_adc_->publish_state(this->parent_->get_ibat_adc_int());
    }
  }
  // VBUS_ADC - VBUS ADC reading
  if (this->sensor_vbus_adc_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbus_adc_->publish_state(NAN);
    } else {
      this->sensor_vbus_adc_->publish_state(this->parent_->get_vbus_adc_int());
    }
  }
  // VAC1_ADC - VAC1 ADC reading
  if (this->sensor_vac1_adc_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vac1_adc_->publish_state(NAN);
    } else {
      this->sensor_vac1_adc_->publish_state(this->parent_->get_vac1_adc_int());
    }
  }
  // VAC2_ADC - VAC2 ADC reading
  if (this->sensor_vac2_adc_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vac2_adc_->publish_state(NAN);
    } else {
      this->sensor_vac2_adc_->publish_state(this->parent_->get_vac2_adc_int());
    }
  }
  // VBAT_ADC - VBAT ADC reading
  if (this->sensor_vbat_adc_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vbat_adc_->publish_state(NAN);
    } else {
      this->sensor_vbat_adc_->publish_state(this->parent_->get_vbat_adc_int());
    }
  }
  // VSYS_ADC - VSYS ADC reading
  if (this->sensor_vsys_adc_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_vsys_adc_->publish_state(NAN);
    } else {
      this->sensor_vsys_adc_->publish_state(this->parent_->get_vsys_adc_int());
    }
  }
  // TS_ADC - TS ADC reading
  if (this->sensor_ts_adc_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_ts_adc_->publish_state(NAN);
    } else {
      this->sensor_ts_adc_->publish_state(this->parent_->get_ts_adc_float());
    }
  }
  // TDIE_ADC - TDIE ADC reading
  if (this->sensor_tdie_adc_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_tdie_adc_->publish_state(NAN);
    } else {
      this->sensor_tdie_adc_->publish_state(this->parent_->get_tdie_adc_float());
    }
  }
  // DPLUS_ADC - D+ ADC reading
  if (this->sensor_dplus_adc_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dplus_adc_->publish_state(NAN);
    } else {
      this->sensor_dplus_adc_->publish_state(this->parent_->get_dplus_adc_int());
    }
  }
  // DMINUS_ADC - D- ADC reading
  if (this->sensor_dminus_adc_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dminus_adc_->publish_state(NAN);
    } else {
      this->sensor_dminus_adc_->publish_state(this->parent_->get_dminus_adc_int());
    }
  }
  // DPLUS_DAC - D+ Output Driver
  if (this->sensor_dplus_dac_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dplus_dac_->publish_state(NAN);
    } else {
      this->sensor_dplus_dac_->publish_state(this->parent_->get_dplus_dac_enum_int());
    }
  }
  // DMINUS_DAC - D- Output Driver
  if (this->sensor_dminus_dac_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dminus_dac_->publish_state(NAN);
    } else {
      this->sensor_dminus_dac_->publish_state(this->parent_->get_dminus_dac_enum_int());
    }
  }
  // PN - Part number
  if (this->sensor_pn_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_pn_->publish_state(NAN);
    } else {
      this->sensor_pn_->publish_state(this->parent_->get_pn_enum_int());
    }
  }
  // DEV_REV - Device revision
  if (this->sensor_dev_rev_ != nullptr) {
    if (this->parent_->is_failed()) {
      this->sensor_dev_rev_->publish_state(NAN);
    } else {
      this->sensor_dev_rev_->publish_state(this->parent_->get_dev_rev_enum_int());
    }
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
void BQ25798Sensor::assign_sensor_reg_rst(sensor::Sensor *sensor) {
  this->sensor_reg_rst_ = sensor;
}
void BQ25798Sensor::assign_sensor_stop_wd_chg(sensor::Sensor *sensor) {
  this->sensor_stop_wd_chg_ = sensor;
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
void BQ25798Sensor::assign_sensor_en_trichg_tmr(sensor::Sensor *sensor) {
  this->sensor_en_trichg_tmr_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_prechg_tmr(sensor::Sensor *sensor) {
  this->sensor_en_prechg_tmr_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_chg_tmr(sensor::Sensor *sensor) {
  this->sensor_en_chg_tmr_ = sensor;
}
void BQ25798Sensor::assign_sensor_chg_tmr(sensor::Sensor *sensor) {
  this->sensor_chg_tmr_ = sensor;
}
void BQ25798Sensor::assign_sensor_tmr2x_en(sensor::Sensor *sensor) {
  this->sensor_tmr2x_en_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_auto_ibatdis(sensor::Sensor *sensor) {
  this->sensor_en_auto_ibatdis_ = sensor;
}
void BQ25798Sensor::assign_sensor_force_ibatdis(sensor::Sensor *sensor) {
  this->sensor_force_ibatdis_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_chg(sensor::Sensor *sensor) {
  this->sensor_en_chg_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_ico(sensor::Sensor *sensor) {
  this->sensor_en_ico_ = sensor;
}
void BQ25798Sensor::assign_sensor_force_ico(sensor::Sensor *sensor) {
  this->sensor_force_ico_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_hiz(sensor::Sensor *sensor) {
  this->sensor_en_hiz_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_term(sensor::Sensor *sensor) {
  this->sensor_en_term_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_backup(sensor::Sensor *sensor) {
  this->sensor_en_backup_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_backup(sensor::Sensor *sensor) {
  this->sensor_vbus_backup_ = sensor;
}
void BQ25798Sensor::assign_sensor_vac_ovp(sensor::Sensor *sensor) {
  this->sensor_vac_ovp_ = sensor;
}
void BQ25798Sensor::assign_sensor_wd_rst(sensor::Sensor *sensor) {
  this->sensor_wd_rst_ = sensor;
}
void BQ25798Sensor::assign_sensor_watchdog(sensor::Sensor *sensor) {
  this->sensor_watchdog_ = sensor;
}
void BQ25798Sensor::assign_sensor_force_indet(sensor::Sensor *sensor) {
  this->sensor_force_indet_ = sensor;
}
void BQ25798Sensor::assign_sensor_auto_indet_en(sensor::Sensor *sensor) {
  this->sensor_auto_indet_en_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_12v(sensor::Sensor *sensor) {
  this->sensor_en_12v_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_9v(sensor::Sensor *sensor) {
  this->sensor_en_9v_ = sensor;
}
void BQ25798Sensor::assign_sensor_hvdcp_en(sensor::Sensor *sensor) {
  this->sensor_hvdcp_en_ = sensor;
}
void BQ25798Sensor::assign_sensor_sdrv_ctrl(sensor::Sensor *sensor) {
  this->sensor_sdrv_ctrl_ = sensor;
}
void BQ25798Sensor::assign_sensor_sdrv_dly(sensor::Sensor *sensor) {
  this->sensor_sdrv_dly_ = sensor;
}
void BQ25798Sensor::assign_sensor_dis_acdrv(sensor::Sensor *sensor) {
  this->sensor_dis_acdrv_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_otg(sensor::Sensor *sensor) {
  this->sensor_en_otg_ = sensor;
}
void BQ25798Sensor::assign_sensor_pfm_otg_dis(sensor::Sensor *sensor) {
  this->sensor_pfm_otg_dis_ = sensor;
}
void BQ25798Sensor::assign_sensor_pfm_fwd_dis(sensor::Sensor *sensor) {
  this->sensor_pfm_fwd_dis_ = sensor;
}
void BQ25798Sensor::assign_sensor_wkup_dly(sensor::Sensor *sensor) {
  this->sensor_wkup_dly_ = sensor;
}
void BQ25798Sensor::assign_sensor_dis_ldo(sensor::Sensor *sensor) {
  this->sensor_dis_ldo_ = sensor;
}
void BQ25798Sensor::assign_sensor_dis_otg_ooa(sensor::Sensor *sensor) {
  this->sensor_dis_otg_ooa_ = sensor;
}
void BQ25798Sensor::assign_sensor_dis_fwd_ooa(sensor::Sensor *sensor) {
  this->sensor_dis_fwd_ooa_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_acdrv2(sensor::Sensor *sensor) {
  this->sensor_en_acdrv2_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_acdrv1(sensor::Sensor *sensor) {
  this->sensor_en_acdrv1_ = sensor;
}
void BQ25798Sensor::assign_sensor_pwm_freq(sensor::Sensor *sensor) {
  this->sensor_pwm_freq_ = sensor;
}
void BQ25798Sensor::assign_sensor_dis_stat(sensor::Sensor *sensor) {
  this->sensor_dis_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_dis_vsys_short(sensor::Sensor *sensor) {
  this->sensor_dis_vsys_short_ = sensor;
}
void BQ25798Sensor::assign_sensor_dis_votg_uvp(sensor::Sensor *sensor) {
  this->sensor_dis_votg_uvp_ = sensor;
}
void BQ25798Sensor::assign_sensor_force_vindpm_det(sensor::Sensor *sensor) {
  this->sensor_force_vindpm_det_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_ibus_ocp(sensor::Sensor *sensor) {
  this->sensor_en_ibus_ocp_ = sensor;
}
void BQ25798Sensor::assign_sensor_sfet_present(sensor::Sensor *sensor) {
  this->sensor_sfet_present_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_ibat(sensor::Sensor *sensor) {
  this->sensor_en_ibat_ = sensor;
}
void BQ25798Sensor::assign_sensor_ibat_reg(sensor::Sensor *sensor) {
  this->sensor_ibat_reg_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_iindpm(sensor::Sensor *sensor) {
  this->sensor_en_iindpm_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_extilim(sensor::Sensor *sensor) {
  this->sensor_en_extilim_ = sensor;
}
void BQ25798Sensor::assign_sensor_en_batoc(sensor::Sensor *sensor) {
  this->sensor_en_batoc_ = sensor;
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
void BQ25798Sensor::assign_sensor_en_mppt(sensor::Sensor *sensor) {
  this->sensor_en_mppt_ = sensor;
}
void BQ25798Sensor::assign_sensor_treg(sensor::Sensor *sensor) {
  this->sensor_treg_ = sensor;
}
void BQ25798Sensor::assign_sensor_tshut(sensor::Sensor *sensor) {
  this->sensor_tshut_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_pd_en(sensor::Sensor *sensor) {
  this->sensor_vbus_pd_en_ = sensor;
}
void BQ25798Sensor::assign_sensor_vac1_pd_en(sensor::Sensor *sensor) {
  this->sensor_vac1_pd_en_ = sensor;
}
void BQ25798Sensor::assign_sensor_vac2_pd_en(sensor::Sensor *sensor) {
  this->sensor_vac2_pd_en_ = sensor;
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
void BQ25798Sensor::assign_sensor_ts_ignore(sensor::Sensor *sensor) {
  this->sensor_ts_ignore_ = sensor;
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
void BQ25798Sensor::assign_sensor_bc12_done_stat(sensor::Sensor *sensor) {
  this->sensor_bc12_done_stat_ = sensor;
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
void BQ25798Sensor::assign_sensor_adc_done_stat(sensor::Sensor *sensor) {
  this->sensor_adc_done_stat_ = sensor;
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
void BQ25798Sensor::assign_sensor_ibat_reg_stat(sensor::Sensor *sensor) {
  this->sensor_ibat_reg_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_ovp_stat(sensor::Sensor *sensor) {
  this->sensor_vbus_ovp_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbat_ovp_stat(sensor::Sensor *sensor) {
  this->sensor_vbat_ovp_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_ibus_ocp_stat(sensor::Sensor *sensor) {
  this->sensor_ibus_ocp_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_ibat_ocp_stat(sensor::Sensor *sensor) {
  this->sensor_ibat_ocp_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_conv_ocp_stat(sensor::Sensor *sensor) {
  this->sensor_conv_ocp_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_vac2_ovp_stat(sensor::Sensor *sensor) {
  this->sensor_vac2_ovp_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_vac1_ovp_stat(sensor::Sensor *sensor) {
  this->sensor_vac1_ovp_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_vsys_short_stat(sensor::Sensor *sensor) {
  this->sensor_vsys_short_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_vsys_ovp_stat(sensor::Sensor *sensor) {
  this->sensor_vsys_ovp_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_otg_ovp_stat(sensor::Sensor *sensor) {
  this->sensor_otg_ovp_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_otg_uvp_stat(sensor::Sensor *sensor) {
  this->sensor_otg_uvp_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_tshut_stat(sensor::Sensor *sensor) {
  this->sensor_tshut_stat_ = sensor;
}
void BQ25798Sensor::assign_sensor_iindpm_flag(sensor::Sensor *sensor) {
  this->sensor_iindpm_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_vindpm_flag(sensor::Sensor *sensor) {
  this->sensor_vindpm_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_wd_flag(sensor::Sensor *sensor) {
  this->sensor_wd_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_poorsrc_flag(sensor::Sensor *sensor) {
  this->sensor_poorsrc_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_pg_flag(sensor::Sensor *sensor) {
  this->sensor_pg_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_ac2_present_flag(sensor::Sensor *sensor) {
  this->sensor_ac2_present_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_ac1_present_flag(sensor::Sensor *sensor) {
  this->sensor_ac1_present_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_present_flag(sensor::Sensor *sensor) {
  this->sensor_vbus_present_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_chg_flag(sensor::Sensor *sensor) {
  this->sensor_chg_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_ico_flag(sensor::Sensor *sensor) {
  this->sensor_ico_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_flag(sensor::Sensor *sensor) {
  this->sensor_vbus_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_treg_flag(sensor::Sensor *sensor) {
  this->sensor_treg_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbat_present_flag(sensor::Sensor *sensor) {
  this->sensor_vbat_present_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_bc1_2_done_flag(sensor::Sensor *sensor) {
  this->sensor_bc1_2_done_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_dpdm_done_flag(sensor::Sensor *sensor) {
  this->sensor_dpdm_done_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_adc_done_flag(sensor::Sensor *sensor) {
  this->sensor_adc_done_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_vsys_flag(sensor::Sensor *sensor) {
  this->sensor_vsys_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_chg_tmr_flag(sensor::Sensor *sensor) {
  this->sensor_chg_tmr_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_trichg_tmr_flag(sensor::Sensor *sensor) {
  this->sensor_trichg_tmr_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_prechg_tmr_flag(sensor::Sensor *sensor) {
  this->sensor_prechg_tmr_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_topoff_tmr_flag(sensor::Sensor *sensor) {
  this->sensor_topoff_tmr_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbatotg_low_flag(sensor::Sensor *sensor) {
  this->sensor_vbatotg_low_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_ts_cold_flag(sensor::Sensor *sensor) {
  this->sensor_ts_cold_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_ts_cool_flag(sensor::Sensor *sensor) {
  this->sensor_ts_cool_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_ts_warm_flag(sensor::Sensor *sensor) {
  this->sensor_ts_warm_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_ts_hot_flag(sensor::Sensor *sensor) {
  this->sensor_ts_hot_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_ibat_reg_flag(sensor::Sensor *sensor) {
  this->sensor_ibat_reg_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_ovp_flag(sensor::Sensor *sensor) {
  this->sensor_vbus_ovp_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbat_ovp_flag(sensor::Sensor *sensor) {
  this->sensor_vbat_ovp_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_ibus_ocp_flag(sensor::Sensor *sensor) {
  this->sensor_ibus_ocp_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_ibat_ocp_flag(sensor::Sensor *sensor) {
  this->sensor_ibat_ocp_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_conv_ocp_flag(sensor::Sensor *sensor) {
  this->sensor_conv_ocp_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_vac2_ovp_flag(sensor::Sensor *sensor) {
  this->sensor_vac2_ovp_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_vac1_ovp_flag(sensor::Sensor *sensor) {
  this->sensor_vac1_ovp_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_vsys_short_flag(sensor::Sensor *sensor) {
  this->sensor_vsys_short_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_vsys_ovp_flag(sensor::Sensor *sensor) {
  this->sensor_vsys_ovp_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_otg_ovp_flag(sensor::Sensor *sensor) {
  this->sensor_otg_ovp_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_otg_uvp_flag(sensor::Sensor *sensor) {
  this->sensor_otg_uvp_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_tshut_flag(sensor::Sensor *sensor) {
  this->sensor_tshut_flag_ = sensor;
}
void BQ25798Sensor::assign_sensor_adc_en(sensor::Sensor *sensor) {
  this->sensor_adc_en_ = sensor;
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
void BQ25798Sensor::assign_sensor_adc_avg_init(sensor::Sensor *sensor) {
  this->sensor_adc_avg_init_ = sensor;
}
void BQ25798Sensor::assign_sensor_ibus_adc_dis(sensor::Sensor *sensor) {
  this->sensor_ibus_adc_dis_ = sensor;
}
void BQ25798Sensor::assign_sensor_ibat_adc_dis(sensor::Sensor *sensor) {
  this->sensor_ibat_adc_dis_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbus_adc_dis(sensor::Sensor *sensor) {
  this->sensor_vbus_adc_dis_ = sensor;
}
void BQ25798Sensor::assign_sensor_vbat_adc_dis(sensor::Sensor *sensor) {
  this->sensor_vbat_adc_dis_ = sensor;
}
void BQ25798Sensor::assign_sensor_vsys_adc_dis(sensor::Sensor *sensor) {
  this->sensor_vsys_adc_dis_ = sensor;
}
void BQ25798Sensor::assign_sensor_ts_adc_dis(sensor::Sensor *sensor) {
  this->sensor_ts_adc_dis_ = sensor;
}
void BQ25798Sensor::assign_sensor_tdie_adc_dis(sensor::Sensor *sensor) {
  this->sensor_tdie_adc_dis_ = sensor;
}
void BQ25798Sensor::assign_sensor_dplus_adc_dis(sensor::Sensor *sensor) {
  this->sensor_dplus_adc_dis_ = sensor;
}
void BQ25798Sensor::assign_sensor_dminus_adc_dis(sensor::Sensor *sensor) {
  this->sensor_dminus_adc_dis_ = sensor;
}
void BQ25798Sensor::assign_sensor_vac2_adc_dis(sensor::Sensor *sensor) {
  this->sensor_vac2_adc_dis_ = sensor;
}
void BQ25798Sensor::assign_sensor_vac1_adc_dis(sensor::Sensor *sensor) {
  this->sensor_vac1_adc_dis_ = sensor;
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