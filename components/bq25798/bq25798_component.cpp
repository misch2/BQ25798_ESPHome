#include "bq25798_component.h"
#include "esphome/core/log.h"
#include "esphome/core/hal.h"

namespace esphome {
namespace bq25798 {

static const char* TAG = "bq25798.component";

void BQ25798Component::setup() {
  ESP_LOGCONFIG(TAG, "Setting up BQ25798...");

  bq25798_noi2c = new BQ25798NoI2C();
  bq25798_noi2c->begin(this->address_); // no-op

  uint8_t raw_value;
  if (!this->read_byte(REG00_Minimal_System_Voltage, &raw_value)) {
    ESP_LOGE(TAG, "Failed to read from BQ25798 at address 0x%02X", this->address_);
     this->mark_failed();
     return;
  }
  // ^FIXME Maybe check chip ID instead?
  if (on_init_set_vsysmin_) {
    set_vsysmin(vsysmin_, true);
  }
  if (on_init_set_vreg_) {
    set_vreg(vreg_, true);
  }
  if (on_init_set_ichg_) {
    set_ichg(ichg_, true);
  }
  if (on_init_set_vindpm_) {
    set_vindpm(vindpm_, true);
  }
  if (on_init_set_iindpm_) {
    set_iindpm(iindpm_, true);
  }
  if (on_init_set_vbat_lowv_) {
    set_vbat_lowv(vbat_lowv_, true);
  }
  if (on_init_set_iprechg_) {
    set_iprechg(iprechg_, true);
  }
  if (on_init_set_reg_rst_) {
    set_reg_rst(reg_rst_, true);
  }
  if (on_init_set_stop_wd_chg_) {
    set_stop_wd_chg(stop_wd_chg_, true);
  }
  if (on_init_set_iterm_) {
    set_iterm(iterm_, true);
  }
  if (on_init_set_cell_) {
    set_cell(cell_, true);
  }
  if (on_init_set_trechg_) {
    set_trechg(trechg_, true);
  }
  if (on_init_set_vrechg_) {
    set_vrechg(vrechg_, true);
  }
  if (on_init_set_votg_) {
    set_votg(votg_, true);
  }
  if (on_init_set_prechg_tmr_) {
    set_prechg_tmr(prechg_tmr_, true);
  }
  if (on_init_set_iotg_) {
    set_iotg(iotg_, true);
  }
  if (on_init_set_topoff_tmr_) {
    set_topoff_tmr(topoff_tmr_, true);
  }
  if (on_init_set_en_trichg_tmr_) {
    set_en_trichg_tmr(en_trichg_tmr_, true);
  }
  if (on_init_set_en_prechg_tmr_) {
    set_en_prechg_tmr(en_prechg_tmr_, true);
  }
  if (on_init_set_en_chg_tmr_) {
    set_en_chg_tmr(en_chg_tmr_, true);
  }
  if (on_init_set_chg_tmr_) {
    set_chg_tmr(chg_tmr_, true);
  }
  if (on_init_set_tmr2x_en_) {
    set_tmr2x_en(tmr2x_en_, true);
  }
  if (on_init_set_en_auto_ibatdis_) {
    set_en_auto_ibatdis(en_auto_ibatdis_, true);
  }
  if (on_init_set_force_ibatdis_) {
    set_force_ibatdis(force_ibatdis_, true);
  }
  if (on_init_set_en_chg_) {
    set_en_chg(en_chg_, true);
  }
  if (on_init_set_en_ico_) {
    set_en_ico(en_ico_, true);
  }
  if (on_init_set_force_ico_) {
    set_force_ico(force_ico_, true);
  }
  if (on_init_set_en_hiz_) {
    set_en_hiz(en_hiz_, true);
  }
  if (on_init_set_en_term_) {
    set_en_term(en_term_, true);
  }
  if (on_init_set_en_backup_) {
    set_en_backup(en_backup_, true);
  }
  if (on_init_set_vbus_backup_) {
    set_vbus_backup(vbus_backup_, true);
  }
  if (on_init_set_vac_ovp_) {
    set_vac_ovp(vac_ovp_, true);
  }
  if (on_init_set_wd_rst_) {
    set_wd_rst(wd_rst_, true);
  }
  if (on_init_set_watchdog_) {
    set_watchdog(watchdog_, true);
  }
  if (on_init_set_force_indet_) {
    set_force_indet(force_indet_, true);
  }
  if (on_init_set_auto_indet_en_) {
    set_auto_indet_en(auto_indet_en_, true);
  }
  if (on_init_set_en_12v_) {
    set_en_12v(en_12v_, true);
  }
  if (on_init_set_en_9v_) {
    set_en_9v(en_9v_, true);
  }
  if (on_init_set_hvdcp_en_) {
    set_hvdcp_en(hvdcp_en_, true);
  }
  if (on_init_set_sdrv_ctrl_) {
    set_sdrv_ctrl(sdrv_ctrl_, true);
  }
  if (on_init_set_sdrv_dly_) {
    set_sdrv_dly(sdrv_dly_, true);
  }
  if (on_init_set_dis_acdrv_) {
    set_dis_acdrv(dis_acdrv_, true);
  }
  if (on_init_set_en_otg_) {
    set_en_otg(en_otg_, true);
  }
  if (on_init_set_pfm_otg_dis_) {
    set_pfm_otg_dis(pfm_otg_dis_, true);
  }
  if (on_init_set_pfm_fwd_dis_) {
    set_pfm_fwd_dis(pfm_fwd_dis_, true);
  }
  if (on_init_set_wkup_dly_) {
    set_wkup_dly(wkup_dly_, true);
  }
  if (on_init_set_dis_ldo_) {
    set_dis_ldo(dis_ldo_, true);
  }
  if (on_init_set_dis_otg_ooa_) {
    set_dis_otg_ooa(dis_otg_ooa_, true);
  }
  if (on_init_set_dis_fwd_ooa_) {
    set_dis_fwd_ooa(dis_fwd_ooa_, true);
  }
  if (on_init_set_en_acdrv2_) {
    set_en_acdrv2(en_acdrv2_, true);
  }
  if (on_init_set_en_acdrv1_) {
    set_en_acdrv1(en_acdrv1_, true);
  }
  if (on_init_set_pwm_freq_) {
    set_pwm_freq(pwm_freq_, true);
  }
  if (on_init_set_dis_stat_) {
    set_dis_stat(dis_stat_, true);
  }
  if (on_init_set_dis_vsys_short_) {
    set_dis_vsys_short(dis_vsys_short_, true);
  }
  if (on_init_set_dis_votg_uvp_) {
    set_dis_votg_uvp(dis_votg_uvp_, true);
  }
  if (on_init_set_force_vindpm_det_) {
    set_force_vindpm_det(force_vindpm_det_, true);
  }
  if (on_init_set_en_ibus_ocp_) {
    set_en_ibus_ocp(en_ibus_ocp_, true);
  }
  if (on_init_set_sfet_present_) {
    set_sfet_present(sfet_present_, true);
  }
  if (on_init_set_en_ibat_) {
    set_en_ibat(en_ibat_, true);
  }
  if (on_init_set_ibat_reg_) {
    set_ibat_reg(ibat_reg_, true);
  }
  if (on_init_set_en_iindpm_) {
    set_en_iindpm(en_iindpm_, true);
  }
  if (on_init_set_en_extilim_) {
    set_en_extilim(en_extilim_, true);
  }
  if (on_init_set_en_batoc_) {
    set_en_batoc(en_batoc_, true);
  }
  if (on_init_set_voc_pct_) {
    set_voc_pct(voc_pct_, true);
  }
  if (on_init_set_voc_dly_) {
    set_voc_dly(voc_dly_, true);
  }
  if (on_init_set_voc_rate_) {
    set_voc_rate(voc_rate_, true);
  }
  if (on_init_set_en_mppt_) {
    set_en_mppt(en_mppt_, true);
  }
  if (on_init_set_treg_) {
    set_treg(treg_, true);
  }
  if (on_init_set_tshut_) {
    set_tshut(tshut_, true);
  }
  if (on_init_set_vbus_pd_en_) {
    set_vbus_pd_en(vbus_pd_en_, true);
  }
  if (on_init_set_vac1_pd_en_) {
    set_vac1_pd_en(vac1_pd_en_, true);
  }
  if (on_init_set_vac2_pd_en_) {
    set_vac2_pd_en(vac2_pd_en_, true);
  }
  if (on_init_set_bkup_acfet1_on_) {
    set_bkup_acfet1_on(bkup_acfet1_on_, true);
  }
  if (on_init_set_jeita_vset_) {
    set_jeita_vset(jeita_vset_, true);
  }
  if (on_init_set_jeita_iseth_) {
    set_jeita_iseth(jeita_iseth_, true);
  }
  if (on_init_set_jeita_isetc_) {
    set_jeita_isetc(jeita_isetc_, true);
  }
  if (on_init_set_ts_cool_) {
    set_ts_cool(ts_cool_, true);
  }
  if (on_init_set_ts_warm_) {
    set_ts_warm(ts_warm_, true);
  }
  if (on_init_set_bhot_) {
    set_bhot(bhot_, true);
  }
  if (on_init_set_bcold_) {
    set_bcold(bcold_, true);
  }
  if (on_init_set_ts_ignore_) {
    set_ts_ignore(ts_ignore_, true);
  }
  if (on_init_set_adc_en_) {
    set_adc_en(adc_en_, true);
  }
  if (on_init_set_adc_rate_) {
    set_adc_rate(adc_rate_, true);
  }
  if (on_init_set_adc_sample_) {
    set_adc_sample(adc_sample_, true);
  }
  if (on_init_set_adc_avg_) {
    set_adc_avg(adc_avg_, true);
  }
  if (on_init_set_adc_avg_init_) {
    set_adc_avg_init(adc_avg_init_, true);
  }
  if (on_init_set_ibus_adc_dis_) {
    set_ibus_adc_dis(ibus_adc_dis_, true);
  }
  if (on_init_set_ibat_adc_dis_) {
    set_ibat_adc_dis(ibat_adc_dis_, true);
  }
  if (on_init_set_vbus_adc_dis_) {
    set_vbus_adc_dis(vbus_adc_dis_, true);
  }
  if (on_init_set_vbat_adc_dis_) {
    set_vbat_adc_dis(vbat_adc_dis_, true);
  }
  if (on_init_set_vsys_adc_dis_) {
    set_vsys_adc_dis(vsys_adc_dis_, true);
  }
  if (on_init_set_ts_adc_dis_) {
    set_ts_adc_dis(ts_adc_dis_, true);
  }
  if (on_init_set_tdie_adc_dis_) {
    set_tdie_adc_dis(tdie_adc_dis_, true);
  }
  if (on_init_set_dplus_adc_dis_) {
    set_dplus_adc_dis(dplus_adc_dis_, true);
  }
  if (on_init_set_dminus_adc_dis_) {
    set_dminus_adc_dis(dminus_adc_dis_, true);
  }
  if (on_init_set_vac2_adc_dis_) {
    set_vac2_adc_dis(vac2_adc_dis_, true);
  }
  if (on_init_set_vac1_adc_dis_) {
    set_vac1_adc_dis(vac1_adc_dis_, true);
  }
  if (on_init_set_dplus_dac_) {
    set_dplus_dac(dplus_dac_, true);
  }
  if (on_init_set_dminus_dac_) {
    set_dminus_dac(dminus_dac_, true);
  }

  ESP_LOGCONFIG(TAG, "BQ25798 initialized successfully at address 0x%02X", this->address_);

  delay(1);
}

void BQ25798Component::dump_config() {
  ESP_LOGCONFIG(TAG, "Dumping BQ25798 configuration...");
  LOG_I2C_DEVICE(this);
  if (this->is_failed()) {
    return;
  }
  LOG_UPDATE_INTERVAL(this);
  LOG_SENSOR("  ", "VSYSMIN", this->vsysmin_sensor_);
  LOG_SENSOR("  ", "VREG", this->vreg_sensor_);
  LOG_SENSOR("  ", "ICHG", this->ichg_sensor_);
  LOG_SENSOR("  ", "VINDPM", this->vindpm_sensor_);
  LOG_SENSOR("  ", "IINDPM", this->iindpm_sensor_);
  LOG_SENSOR("  ", "VBAT_LOWV", this->vbat_lowv_sensor_);
  LOG_SENSOR("  ", "IPRECHG", this->iprechg_sensor_);
  LOG_BINARY_SENSOR("  ", "REG_RST", this->reg_rst_sensor_);
  LOG_BINARY_SENSOR("  ", "STOP_WD_CHG", this->stop_wd_chg_sensor_);
  LOG_SENSOR("  ", "ITERM", this->iterm_sensor_);
  LOG_SENSOR("  ", "CELL", this->cell_sensor_);
  LOG_SENSOR("  ", "TRECHG", this->trechg_sensor_);
  LOG_SENSOR("  ", "VRECHG", this->vrechg_sensor_);
  LOG_SENSOR("  ", "VOTG", this->votg_sensor_);
  LOG_SENSOR("  ", "PRECHG_TMR", this->prechg_tmr_sensor_);
  LOG_SENSOR("  ", "IOTG", this->iotg_sensor_);
  LOG_SENSOR("  ", "TOPOFF_TMR", this->topoff_tmr_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_TRICHG_TMR", this->en_trichg_tmr_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_PRECHG_TMR", this->en_prechg_tmr_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_CHG_TMR", this->en_chg_tmr_sensor_);
  LOG_SENSOR("  ", "CHG_TMR", this->chg_tmr_sensor_);
  LOG_BINARY_SENSOR("  ", "TMR2X_EN", this->tmr2x_en_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_AUTO_IBATDIS", this->en_auto_ibatdis_sensor_);
  LOG_BINARY_SENSOR("  ", "FORCE_IBATDIS", this->force_ibatdis_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_CHG", this->en_chg_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_ICO", this->en_ico_sensor_);
  LOG_BINARY_SENSOR("  ", "FORCE_ICO", this->force_ico_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_HIZ", this->en_hiz_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_TERM", this->en_term_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_BACKUP", this->en_backup_sensor_);
  LOG_SENSOR("  ", "VBUS_BACKUP", this->vbus_backup_sensor_);
  LOG_SENSOR("  ", "VAC_OVP", this->vac_ovp_sensor_);
  LOG_BINARY_SENSOR("  ", "WD_RST", this->wd_rst_sensor_);
  LOG_SENSOR("  ", "WATCHDOG", this->watchdog_sensor_);
  LOG_BINARY_SENSOR("  ", "FORCE_INDET", this->force_indet_sensor_);
  LOG_BINARY_SENSOR("  ", "AUTO_INDET_EN", this->auto_indet_en_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_12V", this->en_12v_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_9V", this->en_9v_sensor_);
  LOG_BINARY_SENSOR("  ", "HVDCP_EN", this->hvdcp_en_sensor_);
  LOG_SENSOR("  ", "SDRV_CTRL", this->sdrv_ctrl_sensor_);
  LOG_SENSOR("  ", "SDRV_DLY", this->sdrv_dly_sensor_);
  LOG_BINARY_SENSOR("  ", "DIS_ACDRV", this->dis_acdrv_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_OTG", this->en_otg_sensor_);
  LOG_BINARY_SENSOR("  ", "PFM_OTG_DIS", this->pfm_otg_dis_sensor_);
  LOG_BINARY_SENSOR("  ", "PFM_FWD_DIS", this->pfm_fwd_dis_sensor_);
  LOG_SENSOR("  ", "WKUP_DLY", this->wkup_dly_sensor_);
  LOG_BINARY_SENSOR("  ", "DIS_LDO", this->dis_ldo_sensor_);
  LOG_BINARY_SENSOR("  ", "DIS_OTG_OOA", this->dis_otg_ooa_sensor_);
  LOG_BINARY_SENSOR("  ", "DIS_FWD_OOA", this->dis_fwd_ooa_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_ACDRV2", this->en_acdrv2_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_ACDRV1", this->en_acdrv1_sensor_);
  LOG_SENSOR("  ", "PWM_FREQ", this->pwm_freq_sensor_);
  LOG_BINARY_SENSOR("  ", "DIS_STAT", this->dis_stat_sensor_);
  LOG_BINARY_SENSOR("  ", "DIS_VSYS_SHORT", this->dis_vsys_short_sensor_);
  LOG_BINARY_SENSOR("  ", "DIS_VOTG_UVP", this->dis_votg_uvp_sensor_);
  LOG_BINARY_SENSOR("  ", "FORCE_VINDPM_DET", this->force_vindpm_det_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_IBUS_OCP", this->en_ibus_ocp_sensor_);
  LOG_BINARY_SENSOR("  ", "SFET_PRESENT", this->sfet_present_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_IBAT", this->en_ibat_sensor_);
  LOG_SENSOR("  ", "IBAT_REG", this->ibat_reg_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_IINDPM", this->en_iindpm_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_EXTILIM", this->en_extilim_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_BATOC", this->en_batoc_sensor_);
  LOG_SENSOR("  ", "VOC_PCT", this->voc_pct_sensor_);
  LOG_SENSOR("  ", "VOC_DLY", this->voc_dly_sensor_);
  LOG_SENSOR("  ", "VOC_RATE", this->voc_rate_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_MPPT", this->en_mppt_sensor_);
  LOG_SENSOR("  ", "TREG", this->treg_sensor_);
  LOG_SENSOR("  ", "TSHUT", this->tshut_sensor_);
  LOG_BINARY_SENSOR("  ", "VBUS_PD_EN", this->vbus_pd_en_sensor_);
  LOG_BINARY_SENSOR("  ", "VAC1_PD_EN", this->vac1_pd_en_sensor_);
  LOG_BINARY_SENSOR("  ", "VAC2_PD_EN", this->vac2_pd_en_sensor_);
  LOG_SENSOR("  ", "BKUP_ACFET1_ON", this->bkup_acfet1_on_sensor_);
  LOG_SENSOR("  ", "JEITA_VSET", this->jeita_vset_sensor_);
  LOG_SENSOR("  ", "JEITA_ISETH", this->jeita_iseth_sensor_);
  LOG_SENSOR("  ", "JEITA_ISETC", this->jeita_isetc_sensor_);
  LOG_SENSOR("  ", "TS_COOL", this->ts_cool_sensor_);
  LOG_SENSOR("  ", "TS_WARM", this->ts_warm_sensor_);
  LOG_SENSOR("  ", "BHOT", this->bhot_sensor_);
  LOG_SENSOR("  ", "BCOLD", this->bcold_sensor_);
  LOG_BINARY_SENSOR("  ", "TS_IGNORE", this->ts_ignore_sensor_);
  LOG_SENSOR("  ", "ICO_ILIM", this->ico_ilim_sensor_);
  ESP_LOGCONFIG(TAG, "  ICO_ILIM: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "IINDPM_STAT", this->iindpm_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  IINDPM_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "VINDPM_STAT", this->vindpm_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  VINDPM_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "WD_STAT", this->wd_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  WD_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "PG_STAT", this->pg_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  PG_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "AC2_PRESENT_STAT", this->ac2_present_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  AC2_PRESENT_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "AC1_PRESENT_STAT", this->ac1_present_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  AC1_PRESENT_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "VBUS_PRESENT_STAT", this->vbus_present_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  VBUS_PRESENT_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "CHG_STAT", this->chg_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  CHG_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "VBUS_STAT", this->vbus_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  VBUS_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "BC12_DONE_STAT", this->bc12_done_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  BC12_DONE_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "ICO_STAT", this->ico_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  ICO_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "TREG_STAT", this->treg_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  TREG_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "DPDM_STAT", this->dpdm_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  DPDM_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "VBAT_PRESENT_STAT", this->vbat_present_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  VBAT_PRESENT_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "ACRB2_STAT", this->acrb2_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  ACRB2_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "ACRB1_STAT", this->acrb1_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  ACRB1_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "ADC_DONE_STAT", this->adc_done_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  ADC_DONE_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "VSYS_STAT", this->vsys_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  VSYS_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "CHG_TMR_STAT", this->chg_tmr_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  CHG_TMR_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "TRICHG_TMR_STAT", this->trichg_tmr_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  TRICHG_TMR_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "PRECHG_TMR_STAT", this->prechg_tmr_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  PRECHG_TMR_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "VBATOTG_LOW_STAT", this->vbatotg_low_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  VBATOTG_LOW_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "TS_COLD_STAT", this->ts_cold_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  TS_COLD_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "TS_COOL_STAT", this->ts_cool_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  TS_COOL_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "TS_WARM_STAT", this->ts_warm_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  TS_WARM_STAT: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "TS_HOT_STAT", this->ts_hot_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  TS_HOT_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "IBAT_REG_STAT", this->ibat_reg_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  IBAT_REG_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VBUS_OVP_STAT", this->vbus_ovp_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  VBUS_OVP_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VBAT_OVP_STAT", this->vbat_ovp_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  VBAT_OVP_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "IBUS_OCP_STAT", this->ibus_ocp_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  IBUS_OCP_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "IBAT_OCP_STAT", this->ibat_ocp_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  IBAT_OCP_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "CONV_OCP_STAT", this->conv_ocp_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  CONV_OCP_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VAC2_OVP_STAT", this->vac2_ovp_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  VAC2_OVP_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VAC1_OVP_STAT", this->vac1_ovp_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  VAC1_OVP_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VSYS_SHORT_STAT", this->vsys_short_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  VSYS_SHORT_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VSYS_OVP_STAT", this->vsys_ovp_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  VSYS_OVP_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "OTG_OVP_STAT", this->otg_ovp_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  OTG_OVP_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "OTG_UVP_STAT", this->otg_uvp_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  OTG_UVP_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "TSHUT_STAT", this->tshut_stat_sensor_);
  ESP_LOGCONFIG(TAG, "  TSHUT_STAT: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "IINDPM_FLAG", this->iindpm_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  IINDPM_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VINDPM_FLAG", this->vindpm_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  VINDPM_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "WD_FLAG", this->wd_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  WD_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "POORSRC_FLAG", this->poorsrc_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  POORSRC_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "PG_FLAG", this->pg_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  PG_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "AC2_PRESENT_FLAG", this->ac2_present_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  AC2_PRESENT_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "AC1_PRESENT_FLAG", this->ac1_present_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  AC1_PRESENT_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VBUS_PRESENT_FLAG", this->vbus_present_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  VBUS_PRESENT_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "CHG_FLAG", this->chg_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  CHG_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "ICO_FLAG", this->ico_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  ICO_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VBUS_FLAG", this->vbus_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  VBUS_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "TREG_FLAG", this->treg_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  TREG_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VBAT_PRESENT_FLAG", this->vbat_present_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  VBAT_PRESENT_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "BC1_2_DONE_FLAG", this->bc1_2_done_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  BC1_2_DONE_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "DPDM_DONE_FLAG", this->dpdm_done_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  DPDM_DONE_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "ADC_DONE_FLAG", this->adc_done_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  ADC_DONE_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VSYS_FLAG", this->vsys_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  VSYS_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "CHG_TMR_FLAG", this->chg_tmr_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  CHG_TMR_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "TRICHG_TMR_FLAG", this->trichg_tmr_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  TRICHG_TMR_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "PRECHG_TMR_FLAG", this->prechg_tmr_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  PRECHG_TMR_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "TOPOFF_TMR_FLAG", this->topoff_tmr_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  TOPOFF_TMR_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VBATOTG_LOW_FLAG", this->vbatotg_low_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  VBATOTG_LOW_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "TS_COLD_FLAG", this->ts_cold_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  TS_COLD_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "TS_COOL_FLAG", this->ts_cool_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  TS_COOL_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "TS_WARM_FLAG", this->ts_warm_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  TS_WARM_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "TS_HOT_FLAG", this->ts_hot_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  TS_HOT_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "IBAT_REG_FLAG", this->ibat_reg_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  IBAT_REG_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VBUS_OVP_FLAG", this->vbus_ovp_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  VBUS_OVP_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VBAT_OVP_FLAG", this->vbat_ovp_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  VBAT_OVP_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "IBUS_OCP_FLAG", this->ibus_ocp_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  IBUS_OCP_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "IBAT_OCP_FLAG", this->ibat_ocp_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  IBAT_OCP_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "CONV_OCP_FLAG", this->conv_ocp_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  CONV_OCP_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VAC2_OVP_FLAG", this->vac2_ovp_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  VAC2_OVP_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VAC1_OVP_FLAG", this->vac1_ovp_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  VAC1_OVP_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VSYS_SHORT_FLAG", this->vsys_short_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  VSYS_SHORT_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "VSYS_OVP_FLAG", this->vsys_ovp_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  VSYS_OVP_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "OTG_OVP_FLAG", this->otg_ovp_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  OTG_OVP_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "OTG_UVP_FLAG", this->otg_uvp_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  OTG_UVP_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "TSHUT_FLAG", this->tshut_flag_sensor_);
  ESP_LOGCONFIG(TAG, "  TSHUT_FLAG: (read-only)"); // FIXME?
  LOG_BINARY_SENSOR("  ", "ADC_EN", this->adc_en_sensor_);
  LOG_SENSOR("  ", "ADC_RATE", this->adc_rate_sensor_);
  LOG_SENSOR("  ", "ADC_SAMPLE", this->adc_sample_sensor_);
  LOG_SENSOR("  ", "ADC_AVG", this->adc_avg_sensor_);
  LOG_BINARY_SENSOR("  ", "ADC_AVG_INIT", this->adc_avg_init_sensor_);
  LOG_BINARY_SENSOR("  ", "IBUS_ADC_DIS", this->ibus_adc_dis_sensor_);
  LOG_BINARY_SENSOR("  ", "IBAT_ADC_DIS", this->ibat_adc_dis_sensor_);
  LOG_BINARY_SENSOR("  ", "VBUS_ADC_DIS", this->vbus_adc_dis_sensor_);
  LOG_BINARY_SENSOR("  ", "VBAT_ADC_DIS", this->vbat_adc_dis_sensor_);
  LOG_BINARY_SENSOR("  ", "VSYS_ADC_DIS", this->vsys_adc_dis_sensor_);
  LOG_BINARY_SENSOR("  ", "TS_ADC_DIS", this->ts_adc_dis_sensor_);
  LOG_BINARY_SENSOR("  ", "TDIE_ADC_DIS", this->tdie_adc_dis_sensor_);
  LOG_BINARY_SENSOR("  ", "DPLUS_ADC_DIS", this->dplus_adc_dis_sensor_);
  LOG_BINARY_SENSOR("  ", "DMINUS_ADC_DIS", this->dminus_adc_dis_sensor_);
  LOG_BINARY_SENSOR("  ", "VAC2_ADC_DIS", this->vac2_adc_dis_sensor_);
  LOG_BINARY_SENSOR("  ", "VAC1_ADC_DIS", this->vac1_adc_dis_sensor_);
  LOG_SENSOR("  ", "IBUS_ADC", this->ibus_adc_sensor_);
  ESP_LOGCONFIG(TAG, "  IBUS_ADC: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "IBAT_ADC", this->ibat_adc_sensor_);
  ESP_LOGCONFIG(TAG, "  IBAT_ADC: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "VBUS_ADC", this->vbus_adc_sensor_);
  ESP_LOGCONFIG(TAG, "  VBUS_ADC: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "VAC1_ADC", this->vac1_adc_sensor_);
  ESP_LOGCONFIG(TAG, "  VAC1_ADC: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "VAC2_ADC", this->vac2_adc_sensor_);
  ESP_LOGCONFIG(TAG, "  VAC2_ADC: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "VBAT_ADC", this->vbat_adc_sensor_);
  ESP_LOGCONFIG(TAG, "  VBAT_ADC: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "VSYS_ADC", this->vsys_adc_sensor_);
  ESP_LOGCONFIG(TAG, "  VSYS_ADC: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "TS_ADC", this->ts_adc_sensor_);
  ESP_LOGCONFIG(TAG, "  TS_ADC: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "TDIE_ADC", this->tdie_adc_sensor_);
  ESP_LOGCONFIG(TAG, "  TDIE_ADC: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "DPLUS_ADC", this->dplus_adc_sensor_);
  ESP_LOGCONFIG(TAG, "  DPLUS_ADC: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "DMINUS_ADC", this->dminus_adc_sensor_);
  ESP_LOGCONFIG(TAG, "  DMINUS_ADC: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "DPLUS_DAC", this->dplus_dac_sensor_);
  LOG_SENSOR("  ", "DMINUS_DAC", this->dminus_dac_sensor_);
  LOG_SENSOR("  ", "PN", this->pn_sensor_);
  ESP_LOGCONFIG(TAG, "  PN: (read-only)"); // FIXME?
  LOG_SENSOR("  ", "DEV_REV", this->dev_rev_sensor_);
  ESP_LOGCONFIG(TAG, "  DEV_REV: (read-only)"); // FIXME?

}

float BQ25798Component::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798Component::update() {
  if (this->vsysmin_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG00_Minimal_System_Voltage, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYSMIN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsysmin_sensor_->publish_state(value);
  }

  if (this->vreg_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG01_Charge_Voltage_Limit, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VREG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vreg_sensor_->publish_state(value);
  }

  if (this->ichg_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG03_Charge_Current_Limit, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICHG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ichg_sensor_->publish_state(value);
  }

  if (this->vindpm_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG05_Input_Voltage_Limit, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VINDPM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vindpm_sensor_->publish_state(value);
  }

  if (this->iindpm_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG06_Input_Current_Limit, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IINDPM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->iindpm_sensor_->publish_state(value);
  }

  if (this->vbat_lowv_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG08_Precharge_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBAT_LOWV);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_lowv_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_LOWV);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_lowv_sensor_->publish_state(value);
  }

  if (this->iprechg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG08_Precharge_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IPRECHG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->iprechg_sensor_->publish_state(value);
  }

  if (this->reg_rst_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG09_Termination_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->REG_RST);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->reg_rst_sensor_->publish_state(value);
  }

  if (this->stop_wd_chg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG09_Termination_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->STOP_WD_CHG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->stop_wd_chg_sensor_->publish_state(value);
  }

  if (this->iterm_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG09_Termination_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ITERM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->iterm_sensor_->publish_state(value);
  }

  if (this->cell_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0A_Recharge_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->CELL);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->cell_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CELL);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->cell_sensor_->publish_state(value);
  }

  if (this->trechg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0A_Recharge_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TRECHG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->trechg_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TRECHG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->trechg_sensor_->publish_state(value);
  }

  if (this->vrechg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0A_Recharge_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VRECHG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vrechg_sensor_->publish_state(value);
  }

  if (this->votg_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG0B_VOTG_regulation, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOTG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->votg_sensor_->publish_state(value);
  }

  if (this->prechg_tmr_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0D_IOTG_regulation, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PRECHG_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->prechg_tmr_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PRECHG_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->prechg_tmr_sensor_->publish_state(value);
  }

  if (this->iotg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0D_IOTG_regulation, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IOTG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->iotg_sensor_->publish_state(value);
  }

  if (this->topoff_tmr_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0E_Timer_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TOPOFF_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->topoff_tmr_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TOPOFF_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->topoff_tmr_sensor_->publish_state(value);
  }

  if (this->en_trichg_tmr_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0E_Timer_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_TRICHG_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_trichg_tmr_sensor_->publish_state(value);
  }

  if (this->en_prechg_tmr_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0E_Timer_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_PRECHG_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_prechg_tmr_sensor_->publish_state(value);
  }

  if (this->en_chg_tmr_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0E_Timer_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_CHG_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_chg_tmr_sensor_->publish_state(value);
  }

  if (this->chg_tmr_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0E_Timer_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->CHG_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_tmr_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_TMR);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_tmr_sensor_->publish_state(value);
  }

  if (this->tmr2x_en_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0E_Timer_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TMR2X_EN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->tmr2x_en_sensor_->publish_state(value);
  }

  if (this->en_auto_ibatdis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_AUTO_IBATDIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_auto_ibatdis_sensor_->publish_state(value);
  }

  if (this->force_ibatdis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_IBATDIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->force_ibatdis_sensor_->publish_state(value);
  }

  if (this->en_chg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_CHG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_chg_sensor_->publish_state(value);
  }

  if (this->en_ico_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ICO);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_ico_sensor_->publish_state(value);
  }

  if (this->force_ico_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_ICO);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->force_ico_sensor_->publish_state(value);
  }

  if (this->en_hiz_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_HIZ);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_hiz_sensor_->publish_state(value);
  }

  if (this->en_term_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_TERM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_term_sensor_->publish_state(value);
  }

  if (this->en_backup_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_BACKUP);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_backup_sensor_->publish_state(value);
  }

  if (this->vbus_backup_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG10_Charger_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBUS_BACKUP);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_backup_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_BACKUP);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_backup_sensor_->publish_state(value);
  }

  if (this->vac_ovp_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG10_Charger_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VAC_OVP);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac_ovp_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC_OVP);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac_ovp_sensor_->publish_state(value);
  }

  if (this->wd_rst_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG10_Charger_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->WD_RST);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->wd_rst_sensor_->publish_state(value);
  }

  if (this->watchdog_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG10_Charger_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->WATCHDOG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->watchdog_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WATCHDOG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->watchdog_sensor_->publish_state(value);
  }

  if (this->force_indet_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG11_Charger_Control_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_INDET);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->force_indet_sensor_->publish_state(value);
  }

  if (this->auto_indet_en_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG11_Charger_Control_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AUTO_INDET_EN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->auto_indet_en_sensor_->publish_state(value);
  }

  if (this->en_12v_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG11_Charger_Control_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_12V);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_12v_sensor_->publish_state(value);
  }

  if (this->en_9v_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG11_Charger_Control_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_9V);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_9v_sensor_->publish_state(value);
  }

  if (this->hvdcp_en_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG11_Charger_Control_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->HVDCP_EN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->hvdcp_en_sensor_->publish_state(value);
  }

  if (this->sdrv_ctrl_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG11_Charger_Control_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->SDRV_CTRL);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->sdrv_ctrl_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->SDRV_CTRL);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->sdrv_ctrl_sensor_->publish_state(value);
  }

  if (this->sdrv_dly_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG11_Charger_Control_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->SDRV_DLY);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->sdrv_dly_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->SDRV_DLY);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->sdrv_dly_sensor_->publish_state(value);
  }

  if (this->dis_acdrv_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_ACDRV);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dis_acdrv_sensor_->publish_state(value);
  }

  if (this->en_otg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_OTG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_otg_sensor_->publish_state(value);
  }

  if (this->pfm_otg_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PFM_OTG_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pfm_otg_dis_sensor_->publish_state(value);
  }

  if (this->pfm_fwd_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PFM_FWD_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pfm_fwd_dis_sensor_->publish_state(value);
  }

  if (this->wkup_dly_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->WKUP_DLY);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->wkup_dly_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WKUP_DLY);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->wkup_dly_sensor_->publish_state(value);
  }

  if (this->dis_ldo_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_LDO);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dis_ldo_sensor_->publish_state(value);
  }

  if (this->dis_otg_ooa_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_OTG_OOA);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dis_otg_ooa_sensor_->publish_state(value);
  }

  if (this->dis_fwd_ooa_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG12_Charger_Control_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_FWD_OOA);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dis_fwd_ooa_sensor_->publish_state(value);
  }

  if (this->en_acdrv2_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ACDRV2);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_acdrv2_sensor_->publish_state(value);
  }

  if (this->en_acdrv1_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ACDRV1);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_acdrv1_sensor_->publish_state(value);
  }

  if (this->pwm_freq_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PWM_FREQ);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pwm_freq_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PWM_FREQ);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pwm_freq_sensor_->publish_state(value);
  }

  if (this->dis_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dis_stat_sensor_->publish_state(value);
  }

  if (this->dis_vsys_short_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_VSYS_SHORT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dis_vsys_short_sensor_->publish_state(value);
  }

  if (this->dis_votg_uvp_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_VOTG_UVP);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dis_votg_uvp_sensor_->publish_state(value);
  }

  if (this->force_vindpm_det_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_VINDPM_DET);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->force_vindpm_det_sensor_->publish_state(value);
  }

  if (this->en_ibus_ocp_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG13_Charger_Control_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IBUS_OCP);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_ibus_ocp_sensor_->publish_state(value);
  }

  if (this->sfet_present_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG14_Charger_Control_5, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->SFET_PRESENT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->sfet_present_sensor_->publish_state(value);
  }

  if (this->en_ibat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG14_Charger_Control_5, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IBAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_ibat_sensor_->publish_state(value);
  }

  if (this->ibat_reg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG14_Charger_Control_5, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->IBAT_REG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_reg_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBAT_REG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_reg_sensor_->publish_state(value);
  }

  if (this->en_iindpm_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG14_Charger_Control_5, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IINDPM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_iindpm_sensor_->publish_state(value);
  }

  if (this->en_extilim_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG14_Charger_Control_5, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_EXTILIM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_extilim_sensor_->publish_state(value);
  }

  if (this->en_batoc_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG14_Charger_Control_5, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_BATOC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_batoc_sensor_->publish_state(value);
  }

  if (this->voc_pct_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG15_MPPT_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VOC_PCT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->voc_pct_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_PCT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->voc_pct_sensor_->publish_state(value);
  }

  if (this->voc_dly_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG15_MPPT_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VOC_DLY);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->voc_dly_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_DLY);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->voc_dly_sensor_->publish_state(value);
  }

  if (this->voc_rate_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG15_MPPT_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VOC_RATE);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->voc_rate_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_RATE);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->voc_rate_sensor_->publish_state(value);
  }

  if (this->en_mppt_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG15_MPPT_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_MPPT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->en_mppt_sensor_->publish_state(value);
  }

  if (this->treg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG16_Temperature_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TREG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->treg_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TREG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->treg_sensor_->publish_state(value);
  }

  if (this->tshut_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG16_Temperature_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TSHUT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->tshut_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TSHUT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->tshut_sensor_->publish_state(value);
  }

  if (this->vbus_pd_en_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG16_Temperature_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_PD_EN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_pd_en_sensor_->publish_state(value);
  }

  if (this->vac1_pd_en_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG16_Temperature_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_PD_EN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac1_pd_en_sensor_->publish_state(value);
  }

  if (this->vac2_pd_en_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG16_Temperature_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_PD_EN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac2_pd_en_sensor_->publish_state(value);
  }

  if (this->bkup_acfet1_on_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG16_Temperature_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->BKUP_ACFET1_ON);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bkup_acfet1_on_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BKUP_ACFET1_ON);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bkup_acfet1_on_sensor_->publish_state(value);
  }

  if (this->jeita_vset_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG17_NTC_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->JEITA_VSET);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->jeita_vset_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_VSET);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->jeita_vset_sensor_->publish_state(value);
  }

  if (this->jeita_iseth_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG17_NTC_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->JEITA_ISETH);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->jeita_iseth_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_ISETH);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->jeita_iseth_sensor_->publish_state(value);
  }

  if (this->jeita_isetc_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG17_NTC_Control_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->JEITA_ISETC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->jeita_isetc_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_ISETC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->jeita_isetc_sensor_->publish_state(value);
  }

  if (this->ts_cool_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG18_NTC_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_COOL);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cool_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COOL);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cool_sensor_->publish_state(value);
  }

  if (this->ts_warm_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG18_NTC_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_WARM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_warm_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_WARM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_warm_sensor_->publish_state(value);
  }

  if (this->bhot_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG18_NTC_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->BHOT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bhot_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BHOT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bhot_sensor_->publish_state(value);
  }

  if (this->bcold_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG18_NTC_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->BCOLD);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bcold_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BCOLD);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bcold_sensor_->publish_state(value);
  }

  if (this->ts_ignore_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG18_NTC_Control_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_IGNORE);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_ignore_sensor_->publish_state(value);
  }

  if (this->ico_ilim_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG19_ICO_Current_Limit, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICO_ILIM);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ico_ilim_sensor_->publish_state(value);
  }

  if (this->iindpm_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->IINDPM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->iindpm_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IINDPM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->iindpm_stat_sensor_->publish_state(value);
  }

  if (this->vindpm_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VINDPM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vindpm_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VINDPM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vindpm_stat_sensor_->publish_state(value);
  }

  if (this->wd_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->WD_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->wd_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WD_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->wd_stat_sensor_->publish_state(value);
  }

  if (this->pg_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PG_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pg_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PG_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pg_stat_sensor_->publish_state(value);
  }

  if (this->ac2_present_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->AC2_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ac2_present_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->AC2_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ac2_present_stat_sensor_->publish_state(value);
  }

  if (this->ac1_present_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->AC1_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ac1_present_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->AC1_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ac1_present_stat_sensor_->publish_state(value);
  }

  if (this->vbus_present_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBUS_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_present_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_present_stat_sensor_->publish_state(value);
  }

  if (this->chg_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->CHG_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_stat_sensor_->publish_state(value);
  }

  if (this->vbus_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBUS_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_stat_sensor_->publish_state(value);
  }

  if (this->bc12_done_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->BC12_DONE_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bc12_done_stat_sensor_->publish_state(value);
  }

  if (this->ico_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->ICO_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ico_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICO_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ico_stat_sensor_->publish_state(value);
  }

  if (this->treg_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TREG_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->treg_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TREG_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->treg_stat_sensor_->publish_state(value);
  }

  if (this->dpdm_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->DPDM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dpdm_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPDM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dpdm_stat_sensor_->publish_state(value);
  }

  if (this->vbat_present_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBAT_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_present_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_PRESENT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_present_stat_sensor_->publish_state(value);
  }

  if (this->acrb2_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ACRB2_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->acrb2_stat_sensor_->publish_state(value);
  }

  if (this->acrb1_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ACRB1_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->acrb1_stat_sensor_->publish_state(value);
  }

  if (this->adc_done_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_DONE_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_done_stat_sensor_->publish_state(value);
  }

  if (this->vsys_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VSYS_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYS_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_stat_sensor_->publish_state(value);
  }

  if (this->chg_tmr_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->CHG_TMR_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_tmr_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_TMR_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_tmr_stat_sensor_->publish_state(value);
  }

  if (this->trichg_tmr_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TRICHG_TMR_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->trichg_tmr_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TRICHG_TMR_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->trichg_tmr_stat_sensor_->publish_state(value);
  }

  if (this->prechg_tmr_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PRECHG_TMR_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->prechg_tmr_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PRECHG_TMR_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->prechg_tmr_stat_sensor_->publish_state(value);
  }

  if (this->vbatotg_low_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBATOTG_LOW_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbatotg_low_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBATOTG_LOW_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbatotg_low_stat_sensor_->publish_state(value);
  }

  if (this->ts_cold_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_COLD_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cold_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COLD_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cold_stat_sensor_->publish_state(value);
  }

  if (this->ts_cool_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_COOL_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cool_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COOL_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cool_stat_sensor_->publish_state(value);
  }

  if (this->ts_warm_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_WARM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_warm_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_WARM_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_warm_stat_sensor_->publish_state(value);
  }

  if (this->ts_hot_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_HOT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_hot_stat_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_HOT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_hot_stat_sensor_->publish_state(value);
  }

  if (this->ibat_reg_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_REG_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_reg_stat_sensor_->publish_state(value);
  }

  if (this->vbus_ovp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_OVP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_ovp_stat_sensor_->publish_state(value);
  }

  if (this->vbat_ovp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_OVP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_ovp_stat_sensor_->publish_state(value);
  }

  if (this->ibus_ocp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_OCP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibus_ocp_stat_sensor_->publish_state(value);
  }

  if (this->ibat_ocp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_OCP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_ocp_stat_sensor_->publish_state(value);
  }

  if (this->conv_ocp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CONV_OCP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->conv_ocp_stat_sensor_->publish_state(value);
  }

  if (this->vac2_ovp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_OVP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac2_ovp_stat_sensor_->publish_state(value);
  }

  if (this->vac1_ovp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_OVP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac1_ovp_stat_sensor_->publish_state(value);
  }

  if (this->vsys_short_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_SHORT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_short_stat_sensor_->publish_state(value);
  }

  if (this->vsys_ovp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_OVP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_ovp_stat_sensor_->publish_state(value);
  }

  if (this->otg_ovp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_OVP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->otg_ovp_stat_sensor_->publish_state(value);
  }

  if (this->otg_uvp_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_UVP_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->otg_uvp_stat_sensor_->publish_state(value);
  }

  if (this->tshut_stat_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TSHUT_STAT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->tshut_stat_sensor_->publish_state(value);
  }

  if (this->iindpm_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IINDPM_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->iindpm_flag_sensor_->publish_state(value);
  }

  if (this->vindpm_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VINDPM_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vindpm_flag_sensor_->publish_state(value);
  }

  if (this->wd_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->WD_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->wd_flag_sensor_->publish_state(value);
  }

  if (this->poorsrc_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->POORSRC_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->poorsrc_flag_sensor_->publish_state(value);
  }

  if (this->pg_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PG_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pg_flag_sensor_->publish_state(value);
  }

  if (this->ac2_present_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AC2_PRESENT_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ac2_present_flag_sensor_->publish_state(value);
  }

  if (this->ac1_present_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AC1_PRESENT_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ac1_present_flag_sensor_->publish_state(value);
  }

  if (this->vbus_present_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_PRESENT_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_present_flag_sensor_->publish_state(value);
  }

  if (this->chg_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CHG_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_flag_sensor_->publish_state(value);
  }

  if (this->ico_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ICO_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ico_flag_sensor_->publish_state(value);
  }

  if (this->vbus_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_flag_sensor_->publish_state(value);
  }

  if (this->treg_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TREG_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->treg_flag_sensor_->publish_state(value);
  }

  if (this->vbat_present_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_PRESENT_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_present_flag_sensor_->publish_state(value);
  }

  if (this->bc1_2_done_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->BC1_2_DONE_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->bc1_2_done_flag_sensor_->publish_state(value);
  }

  if (this->dpdm_done_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DPDM_DONE_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dpdm_done_flag_sensor_->publish_state(value);
  }

  if (this->adc_done_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_DONE_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_done_flag_sensor_->publish_state(value);
  }

  if (this->vsys_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_flag_sensor_->publish_state(value);
  }

  if (this->chg_tmr_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CHG_TMR_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->chg_tmr_flag_sensor_->publish_state(value);
  }

  if (this->trichg_tmr_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TRICHG_TMR_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->trichg_tmr_flag_sensor_->publish_state(value);
  }

  if (this->prechg_tmr_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PRECHG_TMR_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->prechg_tmr_flag_sensor_->publish_state(value);
  }

  if (this->topoff_tmr_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TOPOFF_TMR_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->topoff_tmr_flag_sensor_->publish_state(value);
  }

  if (this->vbatotg_low_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBATOTG_LOW_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbatotg_low_flag_sensor_->publish_state(value);
  }

  if (this->ts_cold_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_COLD_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cold_flag_sensor_->publish_state(value);
  }

  if (this->ts_cool_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_COOL_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_cool_flag_sensor_->publish_state(value);
  }

  if (this->ts_warm_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_WARM_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_warm_flag_sensor_->publish_state(value);
  }

  if (this->ts_hot_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_HOT_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_hot_flag_sensor_->publish_state(value);
  }

  if (this->ibat_reg_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_REG_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_reg_flag_sensor_->publish_state(value);
  }

  if (this->vbus_ovp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_OVP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_ovp_flag_sensor_->publish_state(value);
  }

  if (this->vbat_ovp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_OVP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_ovp_flag_sensor_->publish_state(value);
  }

  if (this->ibus_ocp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_OCP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibus_ocp_flag_sensor_->publish_state(value);
  }

  if (this->ibat_ocp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_OCP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_ocp_flag_sensor_->publish_state(value);
  }

  if (this->conv_ocp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CONV_OCP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->conv_ocp_flag_sensor_->publish_state(value);
  }

  if (this->vac2_ovp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_OVP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac2_ovp_flag_sensor_->publish_state(value);
  }

  if (this->vac1_ovp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_OVP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac1_ovp_flag_sensor_->publish_state(value);
  }

  if (this->vsys_short_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_SHORT_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_short_flag_sensor_->publish_state(value);
  }

  if (this->vsys_ovp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_OVP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_ovp_flag_sensor_->publish_state(value);
  }

  if (this->otg_ovp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_OVP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->otg_ovp_flag_sensor_->publish_state(value);
  }

  if (this->otg_uvp_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_UVP_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->otg_uvp_flag_sensor_->publish_state(value);
  }

  if (this->tshut_flag_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TSHUT_FLAG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->tshut_flag_sensor_->publish_state(value);
  }

  if (this->adc_en_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2E_ADC_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_EN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_en_sensor_->publish_state(value);
  }

  if (this->adc_rate_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2E_ADC_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->ADC_RATE);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_rate_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_RATE);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_rate_sensor_->publish_state(value);
  }

  if (this->adc_sample_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2E_ADC_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->ADC_SAMPLE);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_sample_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_SAMPLE);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_sample_sensor_->publish_state(value);
  }

  if (this->adc_avg_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2E_ADC_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->ADC_AVG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_avg_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_AVG);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_avg_sensor_->publish_state(value);
  }

  if (this->adc_avg_init_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2E_ADC_Control, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_AVG_INIT);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->adc_avg_init_sensor_->publish_state(value);
  }

  if (this->ibus_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibus_adc_dis_sensor_->publish_state(value);
  }

  if (this->ibat_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_adc_dis_sensor_->publish_state(value);
  }

  if (this->vbus_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_adc_dis_sensor_->publish_state(value);
  }

  if (this->vbat_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_adc_dis_sensor_->publish_state(value);
  }

  if (this->vsys_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_adc_dis_sensor_->publish_state(value);
  }

  if (this->ts_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_adc_dis_sensor_->publish_state(value);
  }

  if (this->tdie_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TDIE_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->tdie_adc_dis_sensor_->publish_state(value);
  }

  if (this->dplus_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DPLUS_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dplus_adc_dis_sensor_->publish_state(value);
  }

  if (this->dminus_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DMINUS_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dminus_adc_dis_sensor_->publish_state(value);
  }

  if (this->vac2_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac2_adc_dis_sensor_->publish_state(value);
  }

  if (this->vac1_adc_dis_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &raw_value)) {
      this->mark_failed();
      return;
    }
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_ADC_DIS);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac1_adc_dis_sensor_->publish_state(value);
  }

  if (this->ibus_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG31_IBUS_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBUS_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibus_adc_sensor_->publish_state(value);
  }

  if (this->ibat_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG33_IBAT_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBAT_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ibat_adc_sensor_->publish_state(value);
  }

  if (this->vbus_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG35_VBUS_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbus_adc_sensor_->publish_state(value);
  }

  if (this->vac1_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG37_VAC1_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC1_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac1_adc_sensor_->publish_state(value);
  }

  if (this->vac2_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG39_VAC2_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC2_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vac2_adc_sensor_->publish_state(value);
  }

  if (this->vbat_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG3B_VBAT_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vbat_adc_sensor_->publish_state(value);
  }

  if (this->vsys_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG3D_VSYS_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYS_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->vsys_adc_sensor_->publish_state(value);
  }

  if (this->ts_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG3F_TS_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    float value = this->bq25798_noi2c->rawToFloat(raw_value, this->bq25798_noi2c->TS_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->ts_adc_sensor_->publish_state(value);
  }

  if (this->tdie_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG41_TDIE_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    float value = this->bq25798_noi2c->rawToFloat(raw_value, this->bq25798_noi2c->TDIE_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->tdie_adc_sensor_->publish_state(value);
  }

  if (this->dplus_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG43_DPLUS_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPLUS_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dplus_adc_sensor_->publish_state(value);
  }

  if (this->dminus_adc_sensor_ != nullptr) {
    uint16_t raw_value;
    if (!this->read_byte_16(REG45_DMINUS_ADC, &raw_value)) {
      this->mark_failed();
      return;
    }
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DMINUS_ADC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dminus_adc_sensor_->publish_state(value);
  }

  if (this->dplus_dac_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG47_DPDM_Driver, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->DPLUS_DAC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dplus_dac_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPLUS_DAC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dplus_dac_sensor_->publish_state(value);
  }

  if (this->dminus_dac_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG47_DPDM_Driver, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->DMINUS_DAC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dminus_dac_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DMINUS_DAC);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dminus_dac_sensor_->publish_state(value);
  }

  if (this->pn_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG48_Part_Information, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pn_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PN);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->pn_sensor_->publish_state(value);
  }

  if (this->dev_rev_sensor_ != nullptr) {
    uint8_t raw_value;
    if (!this->read_byte(REG48_Part_Information, &raw_value)) {
      this->mark_failed();
      return;
    }
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->DEV_REV);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dev_rev_text_sensor_->publish_state(string_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DEV_REV);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    this->dev_rev_sensor_->publish_state(value);
  }

}

void BQ25798Component::on_init_set_vsysmin(bool value) {
  on_init_set_vsysmin_ = value;
}


void BQ25798Component::set_vsysmin(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VSYSMIN to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  vsysmin_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VSYSMIN);

  if (!this->write_byte(REG00_Minimal_System_Voltage, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_vreg(bool value) {
  on_init_set_vreg_ = value;
}


void BQ25798Component::set_vreg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VREG to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  vreg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VREG);

  if (!this->write_byte_16(REG01_Charge_Voltage_Limit, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_ichg(bool value) {
  on_init_set_ichg_ = value;
}


void BQ25798Component::set_ichg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ICHG to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  ichg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ICHG);

  if (!this->write_byte_16(REG03_Charge_Current_Limit, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_vindpm(bool value) {
  on_init_set_vindpm_ = value;
}


void BQ25798Component::set_vindpm(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VINDPM to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  vindpm_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VINDPM);

  if (!this->write_byte(REG05_Input_Voltage_Limit, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_iindpm(bool value) {
  on_init_set_iindpm_ = value;
}


void BQ25798Component::set_iindpm(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IINDPM to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  iindpm_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IINDPM);

  if (!this->write_byte_16(REG06_Input_Current_Limit, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_vbat_lowv(bool value) {
  on_init_set_vbat_lowv_ = value;
}


void BQ25798Component::set_vbat_lowv(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBAT_LOWV to %d (<VBAT_LOWV_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  vbat_lowv_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VBAT_LOWV);
  if (!this->write_byte(REG08_Precharge_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_iprechg(bool value) {
  on_init_set_iprechg_ = value;
}


void BQ25798Component::set_iprechg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IPRECHG to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  iprechg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IPRECHG);

  if (!this->write_byte(REG08_Precharge_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_reg_rst(bool value) {
  on_init_set_reg_rst_ = value;
}


void BQ25798Component::set_reg_rst(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s REG_RST to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  reg_rst_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->REG_RST);

  if (!this->write_byte(REG09_Termination_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_stop_wd_chg(bool value) {
  on_init_set_stop_wd_chg_ = value;
}


void BQ25798Component::set_stop_wd_chg(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s STOP_WD_CHG to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  stop_wd_chg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->STOP_WD_CHG);

  if (!this->write_byte(REG09_Termination_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_iterm(bool value) {
  on_init_set_iterm_ = value;
}


void BQ25798Component::set_iterm(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ITERM to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  iterm_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ITERM);

  if (!this->write_byte(REG09_Termination_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_cell(bool value) {
  on_init_set_cell_ = value;
}


void BQ25798Component::set_cell(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s CELL to %d (<CELL_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  cell_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->CELL);
  if (!this->write_byte(REG0A_Recharge_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_trechg(bool value) {
  on_init_set_trechg_ = value;
}


void BQ25798Component::set_trechg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TRECHG to %d (<TRECHG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  trechg_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TRECHG);
  if (!this->write_byte(REG0A_Recharge_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_vrechg(bool value) {
  on_init_set_vrechg_ = value;
}


void BQ25798Component::set_vrechg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VRECHG to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  vrechg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VRECHG);

  if (!this->write_byte(REG0A_Recharge_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_votg(bool value) {
  on_init_set_votg_ = value;
}


void BQ25798Component::set_votg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VOTG to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  votg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOTG);

  if (!this->write_byte_16(REG0B_VOTG_regulation, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_prechg_tmr(bool value) {
  on_init_set_prechg_tmr_ = value;
}


void BQ25798Component::set_prechg_tmr(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s PRECHG_TMR to %d (<PRECHG_TMR_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  prechg_tmr_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->PRECHG_TMR);
  if (!this->write_byte(REG0D_IOTG_regulation, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_iotg(bool value) {
  on_init_set_iotg_ = value;
}


void BQ25798Component::set_iotg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IOTG to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  iotg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IOTG);

  if (!this->write_byte(REG0D_IOTG_regulation, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_topoff_tmr(bool value) {
  on_init_set_topoff_tmr_ = value;
}


void BQ25798Component::set_topoff_tmr(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TOPOFF_TMR to %d (<TOPOFF_TMR_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  topoff_tmr_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TOPOFF_TMR);
  if (!this->write_byte(REG0E_Timer_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_trichg_tmr(bool value) {
  on_init_set_en_trichg_tmr_ = value;
}


void BQ25798Component::set_en_trichg_tmr(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_TRICHG_TMR to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_trichg_tmr_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_TRICHG_TMR);

  if (!this->write_byte(REG0E_Timer_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_prechg_tmr(bool value) {
  on_init_set_en_prechg_tmr_ = value;
}


void BQ25798Component::set_en_prechg_tmr(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_PRECHG_TMR to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_prechg_tmr_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_PRECHG_TMR);

  if (!this->write_byte(REG0E_Timer_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_chg_tmr(bool value) {
  on_init_set_en_chg_tmr_ = value;
}


void BQ25798Component::set_en_chg_tmr(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_CHG_TMR to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_chg_tmr_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_CHG_TMR);

  if (!this->write_byte(REG0E_Timer_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_chg_tmr(bool value) {
  on_init_set_chg_tmr_ = value;
}


void BQ25798Component::set_chg_tmr(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s CHG_TMR to %d (<CHG_TMR_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  chg_tmr_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->CHG_TMR);
  if (!this->write_byte(REG0E_Timer_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_tmr2x_en(bool value) {
  on_init_set_tmr2x_en_ = value;
}


void BQ25798Component::set_tmr2x_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TMR2X_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  tmr2x_en_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TMR2X_EN);

  if (!this->write_byte(REG0E_Timer_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_auto_ibatdis(bool value) {
  on_init_set_en_auto_ibatdis_ = value;
}


void BQ25798Component::set_en_auto_ibatdis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_AUTO_IBATDIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_auto_ibatdis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_AUTO_IBATDIS);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_force_ibatdis(bool value) {
  on_init_set_force_ibatdis_ = value;
}


void BQ25798Component::set_force_ibatdis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s FORCE_IBATDIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  force_ibatdis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_IBATDIS);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_chg(bool value) {
  on_init_set_en_chg_ = value;
}


void BQ25798Component::set_en_chg(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_CHG to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_chg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_CHG);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_ico(bool value) {
  on_init_set_en_ico_ = value;
}


void BQ25798Component::set_en_ico(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_ICO to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_ico_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_ICO);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_force_ico(bool value) {
  on_init_set_force_ico_ = value;
}


void BQ25798Component::set_force_ico(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s FORCE_ICO to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  force_ico_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_ICO);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_hiz(bool value) {
  on_init_set_en_hiz_ = value;
}


void BQ25798Component::set_en_hiz(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_HIZ to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_hiz_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_HIZ);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_term(bool value) {
  on_init_set_en_term_ = value;
}


void BQ25798Component::set_en_term(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_TERM to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_term_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_TERM);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_backup(bool value) {
  on_init_set_en_backup_ = value;
}


void BQ25798Component::set_en_backup(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_BACKUP to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_backup_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_BACKUP);

  if (!this->write_byte(REG0F_Charger_Control_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_vbus_backup(bool value) {
  on_init_set_vbus_backup_ = value;
}


void BQ25798Component::set_vbus_backup(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBUS_BACKUP to %d (<VBUS_BACKUP_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  vbus_backup_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VBUS_BACKUP);
  if (!this->write_byte(REG10_Charger_Control_1, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_vac_ovp(bool value) {
  on_init_set_vac_ovp_ = value;
}


void BQ25798Component::set_vac_ovp(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC_OVP to %d (<VAC_OVP_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  vac_ovp_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VAC_OVP);
  if (!this->write_byte(REG10_Charger_Control_1, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_wd_rst(bool value) {
  on_init_set_wd_rst_ = value;
}


void BQ25798Component::set_wd_rst(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s WD_RST to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  wd_rst_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->WD_RST);

  if (!this->write_byte(REG10_Charger_Control_1, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_watchdog(bool value) {
  on_init_set_watchdog_ = value;
}


void BQ25798Component::set_watchdog(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s WATCHDOG to %d (<WATCHDOG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  watchdog_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->WATCHDOG);
  if (!this->write_byte(REG10_Charger_Control_1, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_force_indet(bool value) {
  on_init_set_force_indet_ = value;
}


void BQ25798Component::set_force_indet(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s FORCE_INDET to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  force_indet_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_INDET);

  if (!this->write_byte(REG11_Charger_Control_2, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_auto_indet_en(bool value) {
  on_init_set_auto_indet_en_ = value;
}


void BQ25798Component::set_auto_indet_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s AUTO_INDET_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  auto_indet_en_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->AUTO_INDET_EN);

  if (!this->write_byte(REG11_Charger_Control_2, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_12v(bool value) {
  on_init_set_en_12v_ = value;
}


void BQ25798Component::set_en_12v(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_12V to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_12v_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_12V);

  if (!this->write_byte(REG11_Charger_Control_2, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_9v(bool value) {
  on_init_set_en_9v_ = value;
}


void BQ25798Component::set_en_9v(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_9V to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_9v_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_9V);

  if (!this->write_byte(REG11_Charger_Control_2, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_hvdcp_en(bool value) {
  on_init_set_hvdcp_en_ = value;
}


void BQ25798Component::set_hvdcp_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s HVDCP_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  hvdcp_en_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->HVDCP_EN);

  if (!this->write_byte(REG11_Charger_Control_2, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_sdrv_ctrl(bool value) {
  on_init_set_sdrv_ctrl_ = value;
}


void BQ25798Component::set_sdrv_ctrl(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s SDRV_CTRL to %d (<SDRV_CTRL_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  sdrv_ctrl_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->SDRV_CTRL);
  if (!this->write_byte(REG11_Charger_Control_2, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_sdrv_dly(bool value) {
  on_init_set_sdrv_dly_ = value;
}


void BQ25798Component::set_sdrv_dly(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s SDRV_DLY to %d (<SDRV_DLY_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  sdrv_dly_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->SDRV_DLY);
  if (!this->write_byte(REG11_Charger_Control_2, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_dis_acdrv(bool value) {
  on_init_set_dis_acdrv_ = value;
}


void BQ25798Component::set_dis_acdrv(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_ACDRV to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  dis_acdrv_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_ACDRV);

  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_otg(bool value) {
  on_init_set_en_otg_ = value;
}


void BQ25798Component::set_en_otg(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_OTG to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_otg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_OTG);

  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_pfm_otg_dis(bool value) {
  on_init_set_pfm_otg_dis_ = value;
}


void BQ25798Component::set_pfm_otg_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s PFM_OTG_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  pfm_otg_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->PFM_OTG_DIS);

  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_pfm_fwd_dis(bool value) {
  on_init_set_pfm_fwd_dis_ = value;
}


void BQ25798Component::set_pfm_fwd_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s PFM_FWD_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  pfm_fwd_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->PFM_FWD_DIS);

  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_wkup_dly(bool value) {
  on_init_set_wkup_dly_ = value;
}


void BQ25798Component::set_wkup_dly(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s WKUP_DLY to %d (<WKUP_DLY_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  wkup_dly_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->WKUP_DLY);
  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_dis_ldo(bool value) {
  on_init_set_dis_ldo_ = value;
}


void BQ25798Component::set_dis_ldo(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_LDO to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  dis_ldo_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_LDO);

  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_dis_otg_ooa(bool value) {
  on_init_set_dis_otg_ooa_ = value;
}


void BQ25798Component::set_dis_otg_ooa(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_OTG_OOA to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  dis_otg_ooa_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_OTG_OOA);

  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_dis_fwd_ooa(bool value) {
  on_init_set_dis_fwd_ooa_ = value;
}


void BQ25798Component::set_dis_fwd_ooa(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_FWD_OOA to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  dis_fwd_ooa_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_FWD_OOA);

  if (!this->write_byte(REG12_Charger_Control_3, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_acdrv2(bool value) {
  on_init_set_en_acdrv2_ = value;
}


void BQ25798Component::set_en_acdrv2(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_ACDRV2 to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_acdrv2_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_ACDRV2);

  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_acdrv1(bool value) {
  on_init_set_en_acdrv1_ = value;
}


void BQ25798Component::set_en_acdrv1(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_ACDRV1 to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_acdrv1_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_ACDRV1);

  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_pwm_freq(bool value) {
  on_init_set_pwm_freq_ = value;
}


void BQ25798Component::set_pwm_freq(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s PWM_FREQ to %d (<PWM_FREQ_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  pwm_freq_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->PWM_FREQ);
  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_dis_stat(bool value) {
  on_init_set_dis_stat_ = value;
}


void BQ25798Component::set_dis_stat(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_STAT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  dis_stat_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_STAT);

  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_dis_vsys_short(bool value) {
  on_init_set_dis_vsys_short_ = value;
}


void BQ25798Component::set_dis_vsys_short(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_VSYS_SHORT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  dis_vsys_short_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_VSYS_SHORT);

  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_dis_votg_uvp(bool value) {
  on_init_set_dis_votg_uvp_ = value;
}


void BQ25798Component::set_dis_votg_uvp(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_VOTG_UVP to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  dis_votg_uvp_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_VOTG_UVP);

  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_force_vindpm_det(bool value) {
  on_init_set_force_vindpm_det_ = value;
}


void BQ25798Component::set_force_vindpm_det(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s FORCE_VINDPM_DET to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  force_vindpm_det_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_VINDPM_DET);

  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_ibus_ocp(bool value) {
  on_init_set_en_ibus_ocp_ = value;
}


void BQ25798Component::set_en_ibus_ocp(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_IBUS_OCP to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_ibus_ocp_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_IBUS_OCP);

  if (!this->write_byte(REG13_Charger_Control_4, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_sfet_present(bool value) {
  on_init_set_sfet_present_ = value;
}


void BQ25798Component::set_sfet_present(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s SFET_PRESENT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  sfet_present_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->SFET_PRESENT);

  if (!this->write_byte(REG14_Charger_Control_5, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_ibat(bool value) {
  on_init_set_en_ibat_ = value;
}


void BQ25798Component::set_en_ibat(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_IBAT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_ibat_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_IBAT);

  if (!this->write_byte(REG14_Charger_Control_5, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_ibat_reg(bool value) {
  on_init_set_ibat_reg_ = value;
}


void BQ25798Component::set_ibat_reg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IBAT_REG to %d (<IBAT_REG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  ibat_reg_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IBAT_REG);
  if (!this->write_byte(REG14_Charger_Control_5, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_iindpm(bool value) {
  on_init_set_en_iindpm_ = value;
}


void BQ25798Component::set_en_iindpm(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_IINDPM to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_iindpm_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_IINDPM);

  if (!this->write_byte(REG14_Charger_Control_5, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_extilim(bool value) {
  on_init_set_en_extilim_ = value;
}


void BQ25798Component::set_en_extilim(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_EXTILIM to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_extilim_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_EXTILIM);

  if (!this->write_byte(REG14_Charger_Control_5, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_batoc(bool value) {
  on_init_set_en_batoc_ = value;
}


void BQ25798Component::set_en_batoc(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_BATOC to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_batoc_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_BATOC);

  if (!this->write_byte(REG14_Charger_Control_5, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_voc_pct(bool value) {
  on_init_set_voc_pct_ = value;
}


void BQ25798Component::set_voc_pct(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VOC_PCT to %d (<VOC_PCT_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  voc_pct_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOC_PCT);
  if (!this->write_byte(REG15_MPPT_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_voc_dly(bool value) {
  on_init_set_voc_dly_ = value;
}


void BQ25798Component::set_voc_dly(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VOC_DLY to %d (<VOC_DLY_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  voc_dly_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOC_DLY);
  if (!this->write_byte(REG15_MPPT_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_voc_rate(bool value) {
  on_init_set_voc_rate_ = value;
}


void BQ25798Component::set_voc_rate(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VOC_RATE to %d (<VOC_RATE_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  voc_rate_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOC_RATE);
  if (!this->write_byte(REG15_MPPT_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_en_mppt(bool value) {
  on_init_set_en_mppt_ = value;
}


void BQ25798Component::set_en_mppt(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_MPPT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  en_mppt_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_MPPT);

  if (!this->write_byte(REG15_MPPT_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_treg(bool value) {
  on_init_set_treg_ = value;
}


void BQ25798Component::set_treg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TREG to %d (<TREG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  treg_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TREG);
  if (!this->write_byte(REG16_Temperature_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_tshut(bool value) {
  on_init_set_tshut_ = value;
}


void BQ25798Component::set_tshut(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TSHUT to %d (<TSHUT_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  tshut_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TSHUT);
  if (!this->write_byte(REG16_Temperature_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_vbus_pd_en(bool value) {
  on_init_set_vbus_pd_en_ = value;
}


void BQ25798Component::set_vbus_pd_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBUS_PD_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  vbus_pd_en_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBUS_PD_EN);

  if (!this->write_byte(REG16_Temperature_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_vac1_pd_en(bool value) {
  on_init_set_vac1_pd_en_ = value;
}


void BQ25798Component::set_vac1_pd_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC1_PD_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  vac1_pd_en_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC1_PD_EN);

  if (!this->write_byte(REG16_Temperature_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_vac2_pd_en(bool value) {
  on_init_set_vac2_pd_en_ = value;
}


void BQ25798Component::set_vac2_pd_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC2_PD_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  vac2_pd_en_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC2_PD_EN);

  if (!this->write_byte(REG16_Temperature_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_bkup_acfet1_on(bool value) {
  on_init_set_bkup_acfet1_on_ = value;
}


void BQ25798Component::set_bkup_acfet1_on(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s BKUP_ACFET1_ON to %d (<BKUP_ACFET1_ON_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  bkup_acfet1_on_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->BKUP_ACFET1_ON);
  if (!this->write_byte(REG16_Temperature_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_jeita_vset(bool value) {
  on_init_set_jeita_vset_ = value;
}


void BQ25798Component::set_jeita_vset(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s JEITA_VSET to %d (<JEITA_VSET_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  jeita_vset_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->JEITA_VSET);
  if (!this->write_byte(REG17_NTC_Control_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_jeita_iseth(bool value) {
  on_init_set_jeita_iseth_ = value;
}


void BQ25798Component::set_jeita_iseth(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s JEITA_ISETH to %d (<JEITA_ISETH_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  jeita_iseth_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->JEITA_ISETH);
  if (!this->write_byte(REG17_NTC_Control_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_jeita_isetc(bool value) {
  on_init_set_jeita_isetc_ = value;
}


void BQ25798Component::set_jeita_isetc(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s JEITA_ISETC to %d (<JEITA_ISETC_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  jeita_isetc_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->JEITA_ISETC);
  if (!this->write_byte(REG17_NTC_Control_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_ts_cool(bool value) {
  on_init_set_ts_cool_ = value;
}


void BQ25798Component::set_ts_cool(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TS_COOL to %d (<TS_COOL_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  ts_cool_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TS_COOL);
  if (!this->write_byte(REG18_NTC_Control_1, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_ts_warm(bool value) {
  on_init_set_ts_warm_ = value;
}


void BQ25798Component::set_ts_warm(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TS_WARM to %d (<TS_WARM_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  ts_warm_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TS_WARM);
  if (!this->write_byte(REG18_NTC_Control_1, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_bhot(bool value) {
  on_init_set_bhot_ = value;
}


void BQ25798Component::set_bhot(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s BHOT to %d (<BHOT_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  bhot_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->BHOT);
  if (!this->write_byte(REG18_NTC_Control_1, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_bcold(bool value) {
  on_init_set_bcold_ = value;
}


void BQ25798Component::set_bcold(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s BCOLD to %d (<BCOLD_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  bcold_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->BCOLD);
  if (!this->write_byte(REG18_NTC_Control_1, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_ts_ignore(bool value) {
  on_init_set_ts_ignore_ = value;
}


void BQ25798Component::set_ts_ignore(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TS_IGNORE to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  ts_ignore_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TS_IGNORE);

  if (!this->write_byte(REG18_NTC_Control_1, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_adc_en(bool value) {
  on_init_set_adc_en_ = value;
}


void BQ25798Component::set_adc_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  adc_en_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->ADC_EN);

  if (!this->write_byte(REG2E_ADC_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_adc_rate(bool value) {
  on_init_set_adc_rate_ = value;
}


void BQ25798Component::set_adc_rate(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_RATE to %d (<ADC_RATE_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  adc_rate_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ADC_RATE);
  if (!this->write_byte(REG2E_ADC_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_adc_sample(bool value) {
  on_init_set_adc_sample_ = value;
}


void BQ25798Component::set_adc_sample(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_SAMPLE to %d (<ADC_SAMPLE_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  adc_sample_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ADC_SAMPLE);
  if (!this->write_byte(REG2E_ADC_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_adc_avg(bool value) {
  on_init_set_adc_avg_ = value;
}


void BQ25798Component::set_adc_avg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_AVG to %d (<ADC_AVG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  adc_avg_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ADC_AVG);
  if (!this->write_byte(REG2E_ADC_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_adc_avg_init(bool value) {
  on_init_set_adc_avg_init_ = value;
}


void BQ25798Component::set_adc_avg_init(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_AVG_INIT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  adc_avg_init_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->ADC_AVG_INIT);

  if (!this->write_byte(REG2E_ADC_Control, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_ibus_adc_dis(bool value) {
  on_init_set_ibus_adc_dis_ = value;
}


void BQ25798Component::set_ibus_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IBUS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  ibus_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IBUS_ADC_DIS);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_ibat_adc_dis(bool value) {
  on_init_set_ibat_adc_dis_ = value;
}


void BQ25798Component::set_ibat_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IBAT_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  ibat_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IBAT_ADC_DIS);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_vbus_adc_dis(bool value) {
  on_init_set_vbus_adc_dis_ = value;
}


void BQ25798Component::set_vbus_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBUS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  vbus_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBUS_ADC_DIS);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_vbat_adc_dis(bool value) {
  on_init_set_vbat_adc_dis_ = value;
}


void BQ25798Component::set_vbat_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBAT_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  vbat_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBAT_ADC_DIS);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_vsys_adc_dis(bool value) {
  on_init_set_vsys_adc_dis_ = value;
}


void BQ25798Component::set_vsys_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VSYS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  vsys_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VSYS_ADC_DIS);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_ts_adc_dis(bool value) {
  on_init_set_ts_adc_dis_ = value;
}


void BQ25798Component::set_ts_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  ts_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TS_ADC_DIS);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_tdie_adc_dis(bool value) {
  on_init_set_tdie_adc_dis_ = value;
}


void BQ25798Component::set_tdie_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TDIE_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  tdie_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TDIE_ADC_DIS);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_dplus_adc_dis(bool value) {
  on_init_set_dplus_adc_dis_ = value;
}


void BQ25798Component::set_dplus_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DPLUS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  dplus_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DPLUS_ADC_DIS);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_dminus_adc_dis(bool value) {
  on_init_set_dminus_adc_dis_ = value;
}


void BQ25798Component::set_dminus_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DMINUS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  dminus_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DMINUS_ADC_DIS);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_vac2_adc_dis(bool value) {
  on_init_set_vac2_adc_dis_ = value;
}


void BQ25798Component::set_vac2_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC2_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  vac2_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC2_ADC_DIS);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_vac1_adc_dis(bool value) {
  on_init_set_vac1_adc_dis_ = value;
}


void BQ25798Component::set_vac1_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC1_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "True" : "False");
  vac1_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC1_ADC_DIS);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_dplus_dac(bool value) {
  on_init_set_dplus_dac_ = value;
}


void BQ25798Component::set_dplus_dac(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DPLUS_DAC to %d (<DPLUS_DAC_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  dplus_dac_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->DPLUS_DAC);
  if (!this->write_byte(REG47_DPDM_Driver, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

void BQ25798Component::on_init_set_dminus_dac(bool value) {
  on_init_set_dminus_dac_ = value;
}


void BQ25798Component::set_dminus_dac(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DMINUS_DAC to %d (<DMINUS_DAC_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  dminus_dac_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->DMINUS_DAC);
  if (!this->write_byte(REG47_DPDM_Driver, raw_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

}  // namespace bq25798
}  // namespace esphome