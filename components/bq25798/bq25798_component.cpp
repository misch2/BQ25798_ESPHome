#include "bq25798_component.h"
#include "esphome/core/log.h"

namespace esphome {
namespace bq25798 {

static const char* TAG = "bq25798.component";

// BQ25798 bqlib = BQ25798();

void BQ25798Component::setup() {
  ESP_LOGCONFIG(TAG, "Setting up BQ25798...");

  //   uint16_t value;
  //   if (!this->read_byte_16(ADS1115_REGISTER_CONVERSION, &value)) {
  //     this->mark_failed();
  //     return;
  //   }
}

void BQ25798Component::loop() {}

void BQ25798Component::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798 configuration...");
  LOG_I2C_DEVICE(this);
  if (this->is_failed()) {
    ESP_LOGE(TAG, "Communication with BQ25798 failed!");
  }
}
void BQ25798Component::set_vsysmin(int value) {
  // FIXME
}
void BQ25798Component::set_vreg(int value) {
  // FIXME
}
void BQ25798Component::set_ichg(int value) {
  // FIXME
}
void BQ25798Component::set_vindpm(int value) {
  // FIXME
}
void BQ25798Component::set_iindpm(int value) {
  // FIXME
}
void BQ25798Component::set_vbat_lowv(int value) {
  // (BQ25798::VBAT_LOWV_t)
  // FIXME
}
void BQ25798Component::set_iprechg(int value) {
  // FIXME
}
void BQ25798Component::set_reg_rst(bool value) {
  // FIXME
}
void BQ25798Component::set_stop_wd_chg(bool value) {
  // FIXME
}
void BQ25798Component::set_iterm(int value) {
  // FIXME
}
void BQ25798Component::set_cell(int value) {
  // (BQ25798::CELL_t)
  // FIXME
}
void BQ25798Component::set_trechg(int value) {
  // (BQ25798::TRECHG_t)
  // FIXME
}
void BQ25798Component::set_vrechg(int value) {
  // FIXME
}
void BQ25798Component::set_votg(int value) {
  // FIXME
}
void BQ25798Component::set_prechg_tmr(int value) {
  // (BQ25798::PRECHG_TMR_t)
  // FIXME
}
void BQ25798Component::set_iotg(int value) {
  // FIXME
}
void BQ25798Component::set_topoff_tmr(int value) {
  // (BQ25798::TOPOFF_TMR_t)
  // FIXME
}
void BQ25798Component::set_en_trichg_tmr(bool value) {
  // FIXME
}
void BQ25798Component::set_en_prechg_tmr(bool value) {
  // FIXME
}
void BQ25798Component::set_en_chg_tmr(bool value) {
  // FIXME
}
void BQ25798Component::set_chg_tmr(int value) {
  // (BQ25798::CHG_TMR_t)
  // FIXME
}
void BQ25798Component::set_tmr2x_en(bool value) {
  // FIXME
}
void BQ25798Component::set_en_auto_ibatdis(bool value) {
  // FIXME
}
void BQ25798Component::set_force_ibatdis(bool value) {
  // FIXME
}
void BQ25798Component::set_en_chg(bool value) {
  // FIXME
}
void BQ25798Component::set_en_ico(bool value) {
  // FIXME
}
void BQ25798Component::set_force_ico(bool value) {
  // FIXME
}
void BQ25798Component::set_en_hiz(bool value) {
  // FIXME
}
void BQ25798Component::set_en_term(bool value) {
  // FIXME
}
void BQ25798Component::set_en_backup(bool value) {
  // FIXME
}
void BQ25798Component::set_vbus_backup(int value) {
  // (BQ25798::VBUS_BACKUP_t)
  // FIXME
}
void BQ25798Component::set_vac_ovp(int value) {
  // (BQ25798::VAC_OVP_t)
  // FIXME
}
void BQ25798Component::set_wd_rst(bool value) {
  // FIXME
}
void BQ25798Component::set_watchdog(int value) {
  // (BQ25798::WATCHDOG_t)
  // FIXME
}
void BQ25798Component::set_force_indet(bool value) {
  // FIXME
}
void BQ25798Component::set_auto_indet_en(bool value) {
  // FIXME
}
void BQ25798Component::set_en_12v(bool value) {
  // FIXME
}
void BQ25798Component::set_en_9v(bool value) {
  // FIXME
}
void BQ25798Component::set_hvdcp_en(bool value) {
  // FIXME
}
void BQ25798Component::set_sdrv_ctrl(int value) {
  // (BQ25798::SDRV_CTRL_t)
  // FIXME
}
void BQ25798Component::set_sdrv_dly(int value) {
  // (BQ25798::SDRV_DLY_t)
  // FIXME
}
void BQ25798Component::set_dis_acdrv(bool value) {
  // FIXME
}
void BQ25798Component::set_en_otg(bool value) {
  // FIXME
}
void BQ25798Component::set_pfm_otg_dis(bool value) {
  // FIXME
}
void BQ25798Component::set_pfm_fwd_dis(bool value) {
  // FIXME
}
void BQ25798Component::set_wkup_dly(int value) {
  // (BQ25798::WKUP_DLY_t)
  // FIXME
}
void BQ25798Component::set_dis_ldo(bool value) {
  // FIXME
}
void BQ25798Component::set_dis_otg_ooa(bool value) {
  // FIXME
}
void BQ25798Component::set_dis_fwd_ooa(bool value) {
  // FIXME
}
void BQ25798Component::set_en_acdrv2(bool value) {
  // FIXME
}
void BQ25798Component::set_en_acdrv1(bool value) {
  // FIXME
}
void BQ25798Component::set_pwm_freq(int value) {
  // (BQ25798::PWM_FREQ_t)
  // FIXME
}
void BQ25798Component::set_dis_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_dis_vsys_short(bool value) {
  // FIXME
}
void BQ25798Component::set_dis_votg_uvp(bool value) {
  // FIXME
}
void BQ25798Component::set_force_vindpm_det(bool value) {
  // FIXME
}
void BQ25798Component::set_en_ibus_ocp(bool value) {
  // FIXME
}
void BQ25798Component::set_sfet_present(bool value) {
  // FIXME
}
void BQ25798Component::set_en_ibat(bool value) {
  // FIXME
}
void BQ25798Component::set_ibat_reg(int value) {
  // (BQ25798::IBAT_REG_t)
  // FIXME
}
void BQ25798Component::set_en_iindpm(bool value) {
  // FIXME
}
void BQ25798Component::set_en_extilim(bool value) {
  // FIXME
}
void BQ25798Component::set_en_batoc(bool value) {
  // FIXME
}
void BQ25798Component::set_voc_pct(int value) {
  // (BQ25798::VOC_PCT_t)
  // FIXME
}
void BQ25798Component::set_voc_dly(int value) {
  // (BQ25798::VOC_DLY_t)
  // FIXME
}
void BQ25798Component::set_voc_rate(int value) {
  // (BQ25798::VOC_RATE_t)
  // FIXME
}
void BQ25798Component::set_en_mppt(bool value) {
  // FIXME
}
void BQ25798Component::set_treg(int value) {
  // (BQ25798::TREG_t)
  // FIXME
}
void BQ25798Component::set_tshut(int value) {
  // (BQ25798::TSHUT_t)
  // FIXME
}
void BQ25798Component::set_vbus_pd_en(bool value) {
  // FIXME
}
void BQ25798Component::set_vac1_pd_en(bool value) {
  // FIXME
}
void BQ25798Component::set_vac2_pd_en(bool value) {
  // FIXME
}
void BQ25798Component::set_bkup_acfet1_on(int value) {
  // (BQ25798::BKUP_ACFET1_ON_t)
  // FIXME
}
void BQ25798Component::set_jeita_vset(int value) {
  // (BQ25798::JEITA_VSET_t)
  // FIXME
}
void BQ25798Component::set_jeita_iseth(int value) {
  // (BQ25798::JEITA_ISETH_t)
  // FIXME
}
void BQ25798Component::set_jeita_isetc(int value) {
  // (BQ25798::JEITA_ISETC_t)
  // FIXME
}
void BQ25798Component::set_ts_cool(int value) {
  // (BQ25798::TS_COOL_t)
  // FIXME
}
void BQ25798Component::set_ts_warm(int value) {
  // (BQ25798::TS_WARM_t)
  // FIXME
}
void BQ25798Component::set_bhot(int value) {
  // (BQ25798::BHOT_t)
  // FIXME
}
void BQ25798Component::set_bcold(int value) {
  // (BQ25798::BCOLD_t)
  // FIXME
}
void BQ25798Component::set_ts_ignore(bool value) {
  // FIXME
}
void BQ25798Component::set_ico_ilim(int value) {
  // FIXME
}
void BQ25798Component::set_iindpm_stat(int value) {
  // (BQ25798::IINDPM_STAT_t)
  // FIXME
}
void BQ25798Component::set_vindpm_stat(int value) {
  // (BQ25798::VINDPM_STAT_t)
  // FIXME
}
void BQ25798Component::set_wd_stat(int value) {
  // (BQ25798::WD_STAT_t)
  // FIXME
}
void BQ25798Component::set_pg_stat(int value) {
  // (BQ25798::PG_STAT_t)
  // FIXME
}
void BQ25798Component::set_ac2_present_stat(int value) {
  // (BQ25798::AC2_PRESENT_STAT_t)
  // FIXME
}
void BQ25798Component::set_ac1_present_stat(int value) {
  // (BQ25798::AC1_PRESENT_STAT_t)
  // FIXME
}
void BQ25798Component::set_vbus_present_stat(int value) {
  // (BQ25798::VBUS_PRESENT_STAT_t)
  // FIXME
}
void BQ25798Component::set_chg_stat(int value) {
  // (BQ25798::CHG_STAT_t)
  // FIXME
}
void BQ25798Component::set_vbus_stat(int value) {
  // (BQ25798::VBUS_STAT_t)
  // FIXME
}
void BQ25798Component::set_bc12_done_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_ico_stat(int value) {
  // (BQ25798::ICO_STAT_t)
  // FIXME
}
void BQ25798Component::set_treg_stat(int value) {
  // (BQ25798::TREG_STAT_t)
  // FIXME
}
void BQ25798Component::set_dpdm_stat(int value) {
  // (BQ25798::DPDM_STAT_t)
  // FIXME
}
void BQ25798Component::set_vbat_present_stat(int value) {
  // (BQ25798::VBAT_PRESENT_STAT_t)
  // FIXME
}
void BQ25798Component::set_acrb2_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_acrb1_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_adc_done_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_vsys_stat(int value) {
  // (BQ25798::VSYS_STAT_t)
  // FIXME
}
void BQ25798Component::set_chg_tmr_stat(int value) {
  // (BQ25798::CHG_TMR_STAT_t)
  // FIXME
}
void BQ25798Component::set_trichg_tmr_stat(int value) {
  // (BQ25798::TRICHG_TMR_STAT_t)
  // FIXME
}
void BQ25798Component::set_prechg_tmr_stat(int value) {
  // (BQ25798::PRECHG_TMR_STAT_t)
  // FIXME
}
void BQ25798Component::set_vbatotg_low_stat(int value) {
  // (BQ25798::VBATOTG_LOW_STAT_t)
  // FIXME
}
void BQ25798Component::set_ts_cold_stat(int value) {
  // (BQ25798::TS_COLD_STAT_t)
  // FIXME
}
void BQ25798Component::set_ts_cool_stat(int value) {
  // (BQ25798::TS_COOL_STAT_t)
  // FIXME
}
void BQ25798Component::set_ts_warm_stat(int value) {
  // (BQ25798::TS_WARM_STAT_t)
  // FIXME
}
void BQ25798Component::set_ts_hot_stat(int value) {
  // (BQ25798::TS_HOT_STAT_t)
  // FIXME
}
void BQ25798Component::set_ibat_reg_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_vbus_ovp_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_vbat_ovp_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_ibus_ocp_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_ibat_ocp_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_conv_ocp_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_vac2_ovp_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_vac1_ovp_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_vsys_short_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_vsys_ovp_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_otg_ovp_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_otg_uvp_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_tshut_stat(bool value) {
  // FIXME
}
void BQ25798Component::set_iindpm_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_vindpm_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_wd_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_poorsrc_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_pg_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_ac2_present_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_ac1_present_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_vbus_present_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_chg_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_ico_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_vbus_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_treg_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_vbat_present_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_bc1_2_done_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_dpdm_done_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_adc_done_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_vsys_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_chg_tmr_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_trichg_tmr_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_prechg_tmr_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_topoff_tmr_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_vbatotg_low_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_ts_cold_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_ts_cool_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_ts_warm_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_ts_hot_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_ibat_reg_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_vbus_ovp_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_vbat_ovp_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_ibus_ocp_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_ibat_ocp_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_conv_ocp_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_vac2_ovp_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_vac1_ovp_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_vsys_short_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_vsys_ovp_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_otg_ovp_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_otg_uvp_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_tshut_flag(bool value) {
  // FIXME
}
void BQ25798Component::set_adc_en(bool value) {
  // FIXME
}
void BQ25798Component::set_adc_rate(int value) {
  // (BQ25798::ADC_RATE_t)
  // FIXME
}
void BQ25798Component::set_adc_sample(int value) {
  // (BQ25798::ADC_SAMPLE_t)
  // FIXME
}
void BQ25798Component::set_adc_avg(int value) {
  // (BQ25798::ADC_AVG_t)
  // FIXME
}
void BQ25798Component::set_adc_avg_init(bool value) {
  // FIXME
}
void BQ25798Component::set_ibus_adc_dis(bool value) {
  // FIXME
}
void BQ25798Component::set_ibat_adc_dis(bool value) {
  // FIXME
}
void BQ25798Component::set_vbus_adc_dis(bool value) {
  // FIXME
}
void BQ25798Component::set_vbat_adc_dis(bool value) {
  // FIXME
}
void BQ25798Component::set_vsys_adc_dis(bool value) {
  // FIXME
}
void BQ25798Component::set_ts_adc_dis(bool value) {
  // FIXME
}
void BQ25798Component::set_tdie_adc_dis(bool value) {
  // FIXME
}
void BQ25798Component::set_dplus_adc_dis(bool value) {
  // FIXME
}
void BQ25798Component::set_dminus_adc_dis(bool value) {
  // FIXME
}
void BQ25798Component::set_vac2_adc_dis(bool value) {
  // FIXME
}
void BQ25798Component::set_vac1_adc_dis(bool value) {
  // FIXME
}
void BQ25798Component::set_ibus_adc(int value) {
  // FIXME
}
void BQ25798Component::set_ibat_adc(int value) {
  // FIXME
}
void BQ25798Component::set_vbus_adc(int value) {
  // FIXME
}
void BQ25798Component::set_vac1_adc(int value) {
  // FIXME
}
void BQ25798Component::set_vac2_adc(int value) {
  // FIXME
}
void BQ25798Component::set_vbat_adc(int value) {
  // FIXME
}
void BQ25798Component::set_vsys_adc(int value) {
  // FIXME
}
void BQ25798Component::set_ts_adc(float value) {
  // FIXME
}
void BQ25798Component::set_tdie_adc(float value) {
  // FIXME
}
void BQ25798Component::set_dplus_adc(int value) {
  // FIXME
}
void BQ25798Component::set_dminus_adc(int value) {
  // FIXME
}
void BQ25798Component::set_dplus_dac(int value) {
  // (BQ25798::DPLUS_DAC_t)
  // FIXME
}
void BQ25798Component::set_dminus_dac(int value) {
  // (BQ25798::DMINUS_DAC_t)
  // FIXME
}
void BQ25798Component::set_pn(int value) {
  // (BQ25798::PN_t)
  // FIXME
}
void BQ25798Component::set_dev_rev(int value) {
  // (BQ25798::DEV_REV_t)
  // FIXME
}

}  // namespace bq25798
}  // namespace esphome