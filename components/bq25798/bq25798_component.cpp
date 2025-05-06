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
  ESP_LOGD(TAG, "Setting %s to %d", "VBAT_LOWV", value);
  // (BQ25798::VBAT_LOWV_t)
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
void BQ25798Component::set_stop_wd_chg(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "STOP_WD_CHG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_iterm(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "ITERM", value, "mA");
  // FIXME
}
void BQ25798Component::set_cell(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "CELL", value);
  // (BQ25798::CELL_t)
  // FIXME
}
void BQ25798Component::set_trechg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "TRECHG", value);
  // (BQ25798::TRECHG_t)
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
  ESP_LOGD(TAG, "Setting %s to %d", "PRECHG_TMR", value);
  // (BQ25798::PRECHG_TMR_t)
  // FIXME
}
void BQ25798Component::set_iotg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "IOTG", value, "mA");
  // FIXME
}
void BQ25798Component::set_topoff_tmr(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "TOPOFF_TMR", value);
  // (BQ25798::TOPOFF_TMR_t)
  // FIXME
}
void BQ25798Component::set_en_trichg_tmr(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_TRICHG_TMR", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_prechg_tmr(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_PRECHG_TMR", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_chg_tmr(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_CHG_TMR", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_chg_tmr(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "CHG_TMR", value);
  // (BQ25798::CHG_TMR_t)
  // FIXME
}
void BQ25798Component::set_tmr2x_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TMR2X_EN", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_auto_ibatdis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_AUTO_IBATDIS", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_force_ibatdis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "FORCE_IBATDIS", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_chg(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_CHG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_ico(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_ICO", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_force_ico(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "FORCE_ICO", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_hiz(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_HIZ", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_term(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_TERM", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_backup(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_BACKUP", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vbus_backup(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "VBUS_BACKUP", value);
  // (BQ25798::VBUS_BACKUP_t)
  // FIXME
}
void BQ25798Component::set_vac_ovp(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "VAC_OVP", value);
  // (BQ25798::VAC_OVP_t)
  // FIXME
}
void BQ25798Component::set_wd_rst(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "WD_RST", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_watchdog(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "WATCHDOG", value);
  // (BQ25798::WATCHDOG_t)
  // FIXME
}
void BQ25798Component::set_force_indet(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "FORCE_INDET", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_auto_indet_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "AUTO_INDET_EN", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_12v(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_12V", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_9v(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_9V", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_hvdcp_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "HVDCP_EN", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_sdrv_ctrl(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "SDRV_CTRL", value);
  // (BQ25798::SDRV_CTRL_t)
  // FIXME
}
void BQ25798Component::set_sdrv_dly(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "SDRV_DLY", value);
  // (BQ25798::SDRV_DLY_t)
  // FIXME
}
void BQ25798Component::set_dis_acdrv(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_ACDRV", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_otg(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_OTG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_pfm_otg_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "PFM_OTG_DIS", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_pfm_fwd_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "PFM_FWD_DIS", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_wkup_dly(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "WKUP_DLY", value);
  // (BQ25798::WKUP_DLY_t)
  // FIXME
}
void BQ25798Component::set_dis_ldo(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_LDO", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_dis_otg_ooa(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_OTG_OOA", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_dis_fwd_ooa(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_FWD_OOA", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_acdrv2(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_ACDRV2", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_acdrv1(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_ACDRV1", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_pwm_freq(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "PWM_FREQ", value);
  // (BQ25798::PWM_FREQ_t)
  // FIXME
}
void BQ25798Component::set_dis_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_dis_vsys_short(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_VSYS_SHORT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_dis_votg_uvp(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DIS_VOTG_UVP", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_force_vindpm_det(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "FORCE_VINDPM_DET", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_ibus_ocp(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_IBUS_OCP", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_sfet_present(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "SFET_PRESENT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_ibat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_IBAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ibat_reg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "IBAT_REG", value);
  // (BQ25798::IBAT_REG_t)
  // FIXME
}
void BQ25798Component::set_en_iindpm(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_IINDPM", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_extilim(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_EXTILIM", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_en_batoc(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_BATOC", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_voc_pct(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "VOC_PCT", value);
  // (BQ25798::VOC_PCT_t)
  // FIXME
}
void BQ25798Component::set_voc_dly(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "VOC_DLY", value);
  // (BQ25798::VOC_DLY_t)
  // FIXME
}
void BQ25798Component::set_voc_rate(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "VOC_RATE", value);
  // (BQ25798::VOC_RATE_t)
  // FIXME
}
void BQ25798Component::set_en_mppt(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "EN_MPPT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_treg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "TREG", value);
  // (BQ25798::TREG_t)
  // FIXME
}
void BQ25798Component::set_tshut(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "TSHUT", value);
  // (BQ25798::TSHUT_t)
  // FIXME
}
void BQ25798Component::set_vbus_pd_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_PD_EN", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vac1_pd_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC1_PD_EN", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vac2_pd_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC2_PD_EN", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_bkup_acfet1_on(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "BKUP_ACFET1_ON", value);
  // (BQ25798::BKUP_ACFET1_ON_t)
  // FIXME
}
void BQ25798Component::set_jeita_vset(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "JEITA_VSET", value);
  // (BQ25798::JEITA_VSET_t)
  // FIXME
}
void BQ25798Component::set_jeita_iseth(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "JEITA_ISETH", value);
  // (BQ25798::JEITA_ISETH_t)
  // FIXME
}
void BQ25798Component::set_jeita_isetc(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "JEITA_ISETC", value);
  // (BQ25798::JEITA_ISETC_t)
  // FIXME
}
void BQ25798Component::set_ts_cool(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "TS_COOL", value);
  // (BQ25798::TS_COOL_t)
  // FIXME
}
void BQ25798Component::set_ts_warm(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "TS_WARM", value);
  // (BQ25798::TS_WARM_t)
  // FIXME
}
void BQ25798Component::set_bhot(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "BHOT", value);
  // (BQ25798::BHOT_t)
  // FIXME
}
void BQ25798Component::set_bcold(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "BCOLD", value);
  // (BQ25798::BCOLD_t)
  // FIXME
}
void BQ25798Component::set_ts_ignore(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_IGNORE", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ico_ilim(int value) {
  ESP_LOGD(TAG, "Setting %s to %d %s", "ICO_ILIM", value, "mA");
  // FIXME
}
void BQ25798Component::set_iindpm_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "IINDPM_STAT", value);
  // (BQ25798::IINDPM_STAT_t)
  // FIXME
}
void BQ25798Component::set_vindpm_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "VINDPM_STAT", value);
  // (BQ25798::VINDPM_STAT_t)
  // FIXME
}
void BQ25798Component::set_wd_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "WD_STAT", value);
  // (BQ25798::WD_STAT_t)
  // FIXME
}
void BQ25798Component::set_pg_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "PG_STAT", value);
  // (BQ25798::PG_STAT_t)
  // FIXME
}
void BQ25798Component::set_ac2_present_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "AC2_PRESENT_STAT", value);
  // (BQ25798::AC2_PRESENT_STAT_t)
  // FIXME
}
void BQ25798Component::set_ac1_present_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "AC1_PRESENT_STAT", value);
  // (BQ25798::AC1_PRESENT_STAT_t)
  // FIXME
}
void BQ25798Component::set_vbus_present_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "VBUS_PRESENT_STAT", value);
  // (BQ25798::VBUS_PRESENT_STAT_t)
  // FIXME
}
void BQ25798Component::set_chg_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "CHG_STAT", value);
  // (BQ25798::CHG_STAT_t)
  // FIXME
}
void BQ25798Component::set_vbus_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "VBUS_STAT", value);
  // (BQ25798::VBUS_STAT_t)
  // FIXME
}
void BQ25798Component::set_bc12_done_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "BC12_DONE_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ico_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "ICO_STAT", value);
  // (BQ25798::ICO_STAT_t)
  // FIXME
}
void BQ25798Component::set_treg_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "TREG_STAT", value);
  // (BQ25798::TREG_STAT_t)
  // FIXME
}
void BQ25798Component::set_dpdm_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "DPDM_STAT", value);
  // (BQ25798::DPDM_STAT_t)
  // FIXME
}
void BQ25798Component::set_vbat_present_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "VBAT_PRESENT_STAT", value);
  // (BQ25798::VBAT_PRESENT_STAT_t)
  // FIXME
}
void BQ25798Component::set_acrb2_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ACRB2_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_acrb1_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ACRB1_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_adc_done_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ADC_DONE_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vsys_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "VSYS_STAT", value);
  // (BQ25798::VSYS_STAT_t)
  // FIXME
}
void BQ25798Component::set_chg_tmr_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "CHG_TMR_STAT", value);
  // (BQ25798::CHG_TMR_STAT_t)
  // FIXME
}
void BQ25798Component::set_trichg_tmr_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "TRICHG_TMR_STAT", value);
  // (BQ25798::TRICHG_TMR_STAT_t)
  // FIXME
}
void BQ25798Component::set_prechg_tmr_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "PRECHG_TMR_STAT", value);
  // (BQ25798::PRECHG_TMR_STAT_t)
  // FIXME
}
void BQ25798Component::set_vbatotg_low_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "VBATOTG_LOW_STAT", value);
  // (BQ25798::VBATOTG_LOW_STAT_t)
  // FIXME
}
void BQ25798Component::set_ts_cold_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "TS_COLD_STAT", value);
  // (BQ25798::TS_COLD_STAT_t)
  // FIXME
}
void BQ25798Component::set_ts_cool_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "TS_COOL_STAT", value);
  // (BQ25798::TS_COOL_STAT_t)
  // FIXME
}
void BQ25798Component::set_ts_warm_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "TS_WARM_STAT", value);
  // (BQ25798::TS_WARM_STAT_t)
  // FIXME
}
void BQ25798Component::set_ts_hot_stat(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "TS_HOT_STAT", value);
  // (BQ25798::TS_HOT_STAT_t)
  // FIXME
}
void BQ25798Component::set_ibat_reg_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_REG_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vbus_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_OVP_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vbat_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBAT_OVP_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ibus_ocp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBUS_OCP_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ibat_ocp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_OCP_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_conv_ocp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "CONV_OCP_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vac2_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC2_OVP_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vac1_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC1_OVP_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vsys_short_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_SHORT_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vsys_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_OVP_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_otg_ovp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "OTG_OVP_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_otg_uvp_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "OTG_UVP_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_tshut_stat(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TSHUT_STAT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_iindpm_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IINDPM_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vindpm_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VINDPM_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_wd_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "WD_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_poorsrc_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "POORSRC_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_pg_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "PG_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ac2_present_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "AC2_PRESENT_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ac1_present_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "AC1_PRESENT_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vbus_present_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_PRESENT_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_chg_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "CHG_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ico_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ICO_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vbus_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_treg_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TREG_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vbat_present_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBAT_PRESENT_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_bc1_2_done_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "BC1_2_DONE_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_dpdm_done_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DPDM_DONE_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_adc_done_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ADC_DONE_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vsys_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_chg_tmr_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "CHG_TMR_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_trichg_tmr_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TRICHG_TMR_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_prechg_tmr_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "PRECHG_TMR_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_topoff_tmr_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TOPOFF_TMR_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vbatotg_low_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBATOTG_LOW_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ts_cold_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_COLD_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ts_cool_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_COOL_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ts_warm_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_WARM_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ts_hot_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_HOT_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ibat_reg_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_REG_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vbus_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_OVP_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vbat_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBAT_OVP_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ibus_ocp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBUS_OCP_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ibat_ocp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_OCP_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_conv_ocp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "CONV_OCP_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vac2_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC2_OVP_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vac1_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC1_OVP_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vsys_short_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_SHORT_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vsys_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_OVP_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_otg_ovp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "OTG_OVP_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_otg_uvp_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "OTG_UVP_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_tshut_flag(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TSHUT_FLAG", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_adc_en(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ADC_EN", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_adc_rate(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "ADC_RATE", value);
  // (BQ25798::ADC_RATE_t)
  // FIXME
}
void BQ25798Component::set_adc_sample(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "ADC_SAMPLE", value);
  // (BQ25798::ADC_SAMPLE_t)
  // FIXME
}
void BQ25798Component::set_adc_avg(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "ADC_AVG", value);
  // (BQ25798::ADC_AVG_t)
  // FIXME
}
void BQ25798Component::set_adc_avg_init(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "ADC_AVG_INIT", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ibus_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBUS_ADC_DIS", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ibat_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "IBAT_ADC_DIS", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vbus_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBUS_ADC_DIS", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vbat_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VBAT_ADC_DIS", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vsys_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VSYS_ADC_DIS", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_ts_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TS_ADC_DIS", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_tdie_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "TDIE_ADC_DIS", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_dplus_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DPLUS_ADC_DIS", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_dminus_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "DMINUS_ADC_DIS", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vac2_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC2_ADC_DIS", value ? "True" : "False");
  // FIXME
}
void BQ25798Component::set_vac1_adc_dis(bool value) {
  ESP_LOGD(TAG, "Setting %s to %s", "VAC1_ADC_DIS", value ? "True" : "False");
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
  ESP_LOGD(TAG, "Setting %s to %d", "DPLUS_DAC", value);
  // (BQ25798::DPLUS_DAC_t)
  // FIXME
}
void BQ25798Component::set_dminus_dac(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "DMINUS_DAC", value);
  // (BQ25798::DMINUS_DAC_t)
  // FIXME
}
void BQ25798Component::set_pn(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "PN", value);
  // (BQ25798::PN_t)
  // FIXME
}
void BQ25798Component::set_dev_rev(int value) {
  ESP_LOGD(TAG, "Setting %s to %d", "DEV_REV", value);
  // (BQ25798::DEV_REV_t)
  // FIXME
}

}  // namespace bq25798
}  // namespace esphome