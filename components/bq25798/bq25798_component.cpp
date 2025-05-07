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

  int pn = get_pn(true);
  if (pn != static_cast<int>(BQ25798NoI2C::PN_t::PN_BQ25798)) {
    ESP_LOGE(TAG, "BQ25798 chip not found at address 0x%02X. Read signature: %d", this->address_, pn);
    this->mark_failed();
    return;
  }

  int dev_rev = get_dev_rev(true);
  if (dev_rev != static_cast<int>(BQ25798NoI2C::DEV_REV_t::DEV_REV_BQ25798)) {
    ESP_LOGE(TAG, "BQ25798 chip at address 0x%02X has unexpected device revision: %d", this->address_, dev_rev);
    this->mark_failed();
    return;
  }
  
  ESP_LOGCONFIG(TAG, "Resetting the chip...");
  set_reg_rst(true, true); 
  while (get_reg_rst(true)) {
    delay(1); // wait for the chip to reset
  }
  ESP_LOGCONFIG(TAG, "Chip reset complete.");
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

  // Dump all the sensors enabled in YAML config
  LOG_SENSOR("  ", "VSYSMIN", this->vsysmin_sensor_);
  LOG_SENSOR("  ", "VREG", this->vreg_sensor_);
  LOG_SENSOR("  ", "ICHG", this->ichg_sensor_);
  LOG_SENSOR("  ", "VINDPM", this->vindpm_sensor_);
  LOG_SENSOR("  ", "IINDPM", this->iindpm_sensor_);
  LOG_SENSOR("  ", "VBAT_LOWV", this->vbat_lowv_sensor_);
  LOG_TEXT_SENSOR("  ", "VBAT_LOWV", this->vbat_lowv_text_sensor_);
  LOG_SENSOR("  ", "IPRECHG", this->iprechg_sensor_);
  LOG_BINARY_SENSOR("  ", "REG_RST", this->reg_rst_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "STOP_WD_CHG", this->stop_wd_chg_binary_sensor_);
  LOG_SENSOR("  ", "ITERM", this->iterm_sensor_);
  LOG_SENSOR("  ", "CELL", this->cell_sensor_);
  LOG_TEXT_SENSOR("  ", "CELL", this->cell_text_sensor_);
  LOG_SENSOR("  ", "TRECHG", this->trechg_sensor_);
  LOG_TEXT_SENSOR("  ", "TRECHG", this->trechg_text_sensor_);
  LOG_SENSOR("  ", "VRECHG", this->vrechg_sensor_);
  LOG_SENSOR("  ", "VOTG", this->votg_sensor_);
  LOG_SENSOR("  ", "PRECHG_TMR", this->prechg_tmr_sensor_);
  LOG_TEXT_SENSOR("  ", "PRECHG_TMR", this->prechg_tmr_text_sensor_);
  LOG_SENSOR("  ", "IOTG", this->iotg_sensor_);
  LOG_SENSOR("  ", "TOPOFF_TMR", this->topoff_tmr_sensor_);
  LOG_TEXT_SENSOR("  ", "TOPOFF_TMR", this->topoff_tmr_text_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_TRICHG_TMR", this->en_trichg_tmr_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_PRECHG_TMR", this->en_prechg_tmr_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_CHG_TMR", this->en_chg_tmr_binary_sensor_);
  LOG_SENSOR("  ", "CHG_TMR", this->chg_tmr_sensor_);
  LOG_TEXT_SENSOR("  ", "CHG_TMR", this->chg_tmr_text_sensor_);
  LOG_BINARY_SENSOR("  ", "TMR2X_EN", this->tmr2x_en_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_AUTO_IBATDIS", this->en_auto_ibatdis_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "FORCE_IBATDIS", this->force_ibatdis_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_CHG", this->en_chg_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_ICO", this->en_ico_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "FORCE_ICO", this->force_ico_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_HIZ", this->en_hiz_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_TERM", this->en_term_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_BACKUP", this->en_backup_binary_sensor_);
  LOG_SENSOR("  ", "VBUS_BACKUP", this->vbus_backup_sensor_);
  LOG_TEXT_SENSOR("  ", "VBUS_BACKUP", this->vbus_backup_text_sensor_);
  LOG_SENSOR("  ", "VAC_OVP", this->vac_ovp_sensor_);
  LOG_TEXT_SENSOR("  ", "VAC_OVP", this->vac_ovp_text_sensor_);
  LOG_BINARY_SENSOR("  ", "WD_RST", this->wd_rst_binary_sensor_);
  LOG_SENSOR("  ", "WATCHDOG", this->watchdog_sensor_);
  LOG_TEXT_SENSOR("  ", "WATCHDOG", this->watchdog_text_sensor_);
  LOG_BINARY_SENSOR("  ", "FORCE_INDET", this->force_indet_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "AUTO_INDET_EN", this->auto_indet_en_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_12V", this->en_12v_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_9V", this->en_9v_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "HVDCP_EN", this->hvdcp_en_binary_sensor_);
  LOG_SENSOR("  ", "SDRV_CTRL", this->sdrv_ctrl_sensor_);
  LOG_TEXT_SENSOR("  ", "SDRV_CTRL", this->sdrv_ctrl_text_sensor_);
  LOG_SENSOR("  ", "SDRV_DLY", this->sdrv_dly_sensor_);
  LOG_TEXT_SENSOR("  ", "SDRV_DLY", this->sdrv_dly_text_sensor_);
  LOG_BINARY_SENSOR("  ", "DIS_ACDRV", this->dis_acdrv_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_OTG", this->en_otg_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "PFM_OTG_DIS", this->pfm_otg_dis_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "PFM_FWD_DIS", this->pfm_fwd_dis_binary_sensor_);
  LOG_SENSOR("  ", "WKUP_DLY", this->wkup_dly_sensor_);
  LOG_TEXT_SENSOR("  ", "WKUP_DLY", this->wkup_dly_text_sensor_);
  LOG_BINARY_SENSOR("  ", "DIS_LDO", this->dis_ldo_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "DIS_OTG_OOA", this->dis_otg_ooa_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "DIS_FWD_OOA", this->dis_fwd_ooa_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_ACDRV2", this->en_acdrv2_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_ACDRV1", this->en_acdrv1_binary_sensor_);
  LOG_SENSOR("  ", "PWM_FREQ", this->pwm_freq_sensor_);
  LOG_TEXT_SENSOR("  ", "PWM_FREQ", this->pwm_freq_text_sensor_);
  LOG_BINARY_SENSOR("  ", "DIS_STAT", this->dis_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "DIS_VSYS_SHORT", this->dis_vsys_short_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "DIS_VOTG_UVP", this->dis_votg_uvp_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "FORCE_VINDPM_DET", this->force_vindpm_det_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_IBUS_OCP", this->en_ibus_ocp_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "SFET_PRESENT", this->sfet_present_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_IBAT", this->en_ibat_binary_sensor_);
  LOG_SENSOR("  ", "IBAT_REG", this->ibat_reg_sensor_);
  LOG_TEXT_SENSOR("  ", "IBAT_REG", this->ibat_reg_text_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_IINDPM", this->en_iindpm_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_EXTILIM", this->en_extilim_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_BATOC", this->en_batoc_binary_sensor_);
  LOG_SENSOR("  ", "VOC_PCT", this->voc_pct_sensor_);
  LOG_TEXT_SENSOR("  ", "VOC_PCT", this->voc_pct_text_sensor_);
  LOG_SENSOR("  ", "VOC_DLY", this->voc_dly_sensor_);
  LOG_TEXT_SENSOR("  ", "VOC_DLY", this->voc_dly_text_sensor_);
  LOG_SENSOR("  ", "VOC_RATE", this->voc_rate_sensor_);
  LOG_TEXT_SENSOR("  ", "VOC_RATE", this->voc_rate_text_sensor_);
  LOG_BINARY_SENSOR("  ", "EN_MPPT", this->en_mppt_binary_sensor_);
  LOG_SENSOR("  ", "TREG", this->treg_sensor_);
  LOG_TEXT_SENSOR("  ", "TREG", this->treg_text_sensor_);
  LOG_SENSOR("  ", "TSHUT", this->tshut_sensor_);
  LOG_TEXT_SENSOR("  ", "TSHUT", this->tshut_text_sensor_);
  LOG_BINARY_SENSOR("  ", "VBUS_PD_EN", this->vbus_pd_en_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VAC1_PD_EN", this->vac1_pd_en_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VAC2_PD_EN", this->vac2_pd_en_binary_sensor_);
  LOG_SENSOR("  ", "BKUP_ACFET1_ON", this->bkup_acfet1_on_sensor_);
  LOG_TEXT_SENSOR("  ", "BKUP_ACFET1_ON", this->bkup_acfet1_on_text_sensor_);
  LOG_SENSOR("  ", "JEITA_VSET", this->jeita_vset_sensor_);
  LOG_TEXT_SENSOR("  ", "JEITA_VSET", this->jeita_vset_text_sensor_);
  LOG_SENSOR("  ", "JEITA_ISETH", this->jeita_iseth_sensor_);
  LOG_TEXT_SENSOR("  ", "JEITA_ISETH", this->jeita_iseth_text_sensor_);
  LOG_SENSOR("  ", "JEITA_ISETC", this->jeita_isetc_sensor_);
  LOG_TEXT_SENSOR("  ", "JEITA_ISETC", this->jeita_isetc_text_sensor_);
  LOG_SENSOR("  ", "TS_COOL", this->ts_cool_sensor_);
  LOG_TEXT_SENSOR("  ", "TS_COOL", this->ts_cool_text_sensor_);
  LOG_SENSOR("  ", "TS_WARM", this->ts_warm_sensor_);
  LOG_TEXT_SENSOR("  ", "TS_WARM", this->ts_warm_text_sensor_);
  LOG_SENSOR("  ", "BHOT", this->bhot_sensor_);
  LOG_TEXT_SENSOR("  ", "BHOT", this->bhot_text_sensor_);
  LOG_SENSOR("  ", "BCOLD", this->bcold_sensor_);
  LOG_TEXT_SENSOR("  ", "BCOLD", this->bcold_text_sensor_);
  LOG_BINARY_SENSOR("  ", "TS_IGNORE", this->ts_ignore_binary_sensor_);
  LOG_SENSOR("  ", "ICO_ILIM", this->ico_ilim_sensor_);
  LOG_SENSOR("  ", "IINDPM_STAT", this->iindpm_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "IINDPM_STAT", this->iindpm_stat_text_sensor_);
  LOG_SENSOR("  ", "VINDPM_STAT", this->vindpm_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "VINDPM_STAT", this->vindpm_stat_text_sensor_);
  LOG_SENSOR("  ", "WD_STAT", this->wd_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "WD_STAT", this->wd_stat_text_sensor_);
  LOG_SENSOR("  ", "PG_STAT", this->pg_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "PG_STAT", this->pg_stat_text_sensor_);
  LOG_SENSOR("  ", "AC2_PRESENT_STAT", this->ac2_present_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "AC2_PRESENT_STAT", this->ac2_present_stat_text_sensor_);
  LOG_SENSOR("  ", "AC1_PRESENT_STAT", this->ac1_present_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "AC1_PRESENT_STAT", this->ac1_present_stat_text_sensor_);
  LOG_SENSOR("  ", "VBUS_PRESENT_STAT", this->vbus_present_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "VBUS_PRESENT_STAT", this->vbus_present_stat_text_sensor_);
  LOG_SENSOR("  ", "CHG_STAT", this->chg_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "CHG_STAT", this->chg_stat_text_sensor_);
  LOG_SENSOR("  ", "VBUS_STAT", this->vbus_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "VBUS_STAT", this->vbus_stat_text_sensor_);
  LOG_BINARY_SENSOR("  ", "BC12_DONE_STAT", this->bc12_done_stat_binary_sensor_);
  LOG_SENSOR("  ", "ICO_STAT", this->ico_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "ICO_STAT", this->ico_stat_text_sensor_);
  LOG_SENSOR("  ", "TREG_STAT", this->treg_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "TREG_STAT", this->treg_stat_text_sensor_);
  LOG_SENSOR("  ", "DPDM_STAT", this->dpdm_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "DPDM_STAT", this->dpdm_stat_text_sensor_);
  LOG_SENSOR("  ", "VBAT_PRESENT_STAT", this->vbat_present_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "VBAT_PRESENT_STAT", this->vbat_present_stat_text_sensor_);
  LOG_BINARY_SENSOR("  ", "ACRB2_STAT", this->acrb2_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "ACRB1_STAT", this->acrb1_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "ADC_DONE_STAT", this->adc_done_stat_binary_sensor_);
  LOG_SENSOR("  ", "VSYS_STAT", this->vsys_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "VSYS_STAT", this->vsys_stat_text_sensor_);
  LOG_SENSOR("  ", "CHG_TMR_STAT", this->chg_tmr_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "CHG_TMR_STAT", this->chg_tmr_stat_text_sensor_);
  LOG_SENSOR("  ", "TRICHG_TMR_STAT", this->trichg_tmr_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "TRICHG_TMR_STAT", this->trichg_tmr_stat_text_sensor_);
  LOG_SENSOR("  ", "PRECHG_TMR_STAT", this->prechg_tmr_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "PRECHG_TMR_STAT", this->prechg_tmr_stat_text_sensor_);
  LOG_SENSOR("  ", "VBATOTG_LOW_STAT", this->vbatotg_low_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "VBATOTG_LOW_STAT", this->vbatotg_low_stat_text_sensor_);
  LOG_SENSOR("  ", "TS_COLD_STAT", this->ts_cold_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "TS_COLD_STAT", this->ts_cold_stat_text_sensor_);
  LOG_SENSOR("  ", "TS_COOL_STAT", this->ts_cool_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "TS_COOL_STAT", this->ts_cool_stat_text_sensor_);
  LOG_SENSOR("  ", "TS_WARM_STAT", this->ts_warm_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "TS_WARM_STAT", this->ts_warm_stat_text_sensor_);
  LOG_SENSOR("  ", "TS_HOT_STAT", this->ts_hot_stat_sensor_);
  LOG_TEXT_SENSOR("  ", "TS_HOT_STAT", this->ts_hot_stat_text_sensor_);
  LOG_BINARY_SENSOR("  ", "IBAT_REG_STAT", this->ibat_reg_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VBUS_OVP_STAT", this->vbus_ovp_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VBAT_OVP_STAT", this->vbat_ovp_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "IBUS_OCP_STAT", this->ibus_ocp_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "IBAT_OCP_STAT", this->ibat_ocp_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "CONV_OCP_STAT", this->conv_ocp_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VAC2_OVP_STAT", this->vac2_ovp_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VAC1_OVP_STAT", this->vac1_ovp_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VSYS_SHORT_STAT", this->vsys_short_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VSYS_OVP_STAT", this->vsys_ovp_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "OTG_OVP_STAT", this->otg_ovp_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "OTG_UVP_STAT", this->otg_uvp_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "TSHUT_STAT", this->tshut_stat_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "IINDPM_FLAG", this->iindpm_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VINDPM_FLAG", this->vindpm_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "WD_FLAG", this->wd_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "POORSRC_FLAG", this->poorsrc_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "PG_FLAG", this->pg_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "AC2_PRESENT_FLAG", this->ac2_present_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "AC1_PRESENT_FLAG", this->ac1_present_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VBUS_PRESENT_FLAG", this->vbus_present_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "CHG_FLAG", this->chg_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "ICO_FLAG", this->ico_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VBUS_FLAG", this->vbus_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "TREG_FLAG", this->treg_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VBAT_PRESENT_FLAG", this->vbat_present_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "BC1_2_DONE_FLAG", this->bc1_2_done_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "DPDM_DONE_FLAG", this->dpdm_done_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "ADC_DONE_FLAG", this->adc_done_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VSYS_FLAG", this->vsys_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "CHG_TMR_FLAG", this->chg_tmr_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "TRICHG_TMR_FLAG", this->trichg_tmr_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "PRECHG_TMR_FLAG", this->prechg_tmr_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "TOPOFF_TMR_FLAG", this->topoff_tmr_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VBATOTG_LOW_FLAG", this->vbatotg_low_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "TS_COLD_FLAG", this->ts_cold_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "TS_COOL_FLAG", this->ts_cool_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "TS_WARM_FLAG", this->ts_warm_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "TS_HOT_FLAG", this->ts_hot_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "IBAT_REG_FLAG", this->ibat_reg_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VBUS_OVP_FLAG", this->vbus_ovp_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VBAT_OVP_FLAG", this->vbat_ovp_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "IBUS_OCP_FLAG", this->ibus_ocp_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "IBAT_OCP_FLAG", this->ibat_ocp_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "CONV_OCP_FLAG", this->conv_ocp_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VAC2_OVP_FLAG", this->vac2_ovp_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VAC1_OVP_FLAG", this->vac1_ovp_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VSYS_SHORT_FLAG", this->vsys_short_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VSYS_OVP_FLAG", this->vsys_ovp_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "OTG_OVP_FLAG", this->otg_ovp_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "OTG_UVP_FLAG", this->otg_uvp_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "TSHUT_FLAG", this->tshut_flag_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "ADC_EN", this->adc_en_binary_sensor_);
  LOG_SENSOR("  ", "ADC_RATE", this->adc_rate_sensor_);
  LOG_TEXT_SENSOR("  ", "ADC_RATE", this->adc_rate_text_sensor_);
  LOG_SENSOR("  ", "ADC_SAMPLE", this->adc_sample_sensor_);
  LOG_TEXT_SENSOR("  ", "ADC_SAMPLE", this->adc_sample_text_sensor_);
  LOG_SENSOR("  ", "ADC_AVG", this->adc_avg_sensor_);
  LOG_TEXT_SENSOR("  ", "ADC_AVG", this->adc_avg_text_sensor_);
  LOG_BINARY_SENSOR("  ", "ADC_AVG_INIT", this->adc_avg_init_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "IBUS_ADC_DIS", this->ibus_adc_dis_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "IBAT_ADC_DIS", this->ibat_adc_dis_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VBUS_ADC_DIS", this->vbus_adc_dis_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VBAT_ADC_DIS", this->vbat_adc_dis_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VSYS_ADC_DIS", this->vsys_adc_dis_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "TS_ADC_DIS", this->ts_adc_dis_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "TDIE_ADC_DIS", this->tdie_adc_dis_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "DPLUS_ADC_DIS", this->dplus_adc_dis_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "DMINUS_ADC_DIS", this->dminus_adc_dis_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VAC2_ADC_DIS", this->vac2_adc_dis_binary_sensor_);
  LOG_BINARY_SENSOR("  ", "VAC1_ADC_DIS", this->vac1_adc_dis_binary_sensor_);
  LOG_SENSOR("  ", "IBUS_ADC", this->ibus_adc_sensor_);
  LOG_SENSOR("  ", "IBAT_ADC", this->ibat_adc_sensor_);
  LOG_SENSOR("  ", "VBUS_ADC", this->vbus_adc_sensor_);
  LOG_SENSOR("  ", "VAC1_ADC", this->vac1_adc_sensor_);
  LOG_SENSOR("  ", "VAC2_ADC", this->vac2_adc_sensor_);
  LOG_SENSOR("  ", "VBAT_ADC", this->vbat_adc_sensor_);
  LOG_SENSOR("  ", "VSYS_ADC", this->vsys_adc_sensor_);
  LOG_SENSOR("  ", "TS_ADC", this->ts_adc_sensor_);
  LOG_SENSOR("  ", "TDIE_ADC", this->tdie_adc_sensor_);
  LOG_SENSOR("  ", "DPLUS_ADC", this->dplus_adc_sensor_);
  LOG_SENSOR("  ", "DMINUS_ADC", this->dminus_adc_sensor_);
  LOG_SENSOR("  ", "DPLUS_DAC", this->dplus_dac_sensor_);
  LOG_TEXT_SENSOR("  ", "DPLUS_DAC", this->dplus_dac_text_sensor_);
  LOG_SENSOR("  ", "DMINUS_DAC", this->dminus_dac_sensor_);
  LOG_TEXT_SENSOR("  ", "DMINUS_DAC", this->dminus_dac_text_sensor_);
  LOG_SENSOR("  ", "PN", this->pn_sensor_);
  LOG_TEXT_SENSOR("  ", "PN", this->pn_text_sensor_);
  LOG_SENSOR("  ", "DEV_REV", this->dev_rev_sensor_);
  LOG_TEXT_SENSOR("  ", "DEV_REV", this->dev_rev_text_sensor_);
}

float BQ25798Component::get_setup_priority() const { return setup_priority::DATA; }

void BQ25798Component::update() {
  bool needs_2nd_read;
  if (this->vsysmin_sensor_ != nullptr) {
    this->vsysmin_sensor_->publish_state(get_vsysmin(true));
  }


  if (this->vreg_sensor_ != nullptr) {
    this->vreg_sensor_->publish_state(get_vreg(true));
  }


  if (this->ichg_sensor_ != nullptr) {
    this->ichg_sensor_->publish_state(get_ichg(true));
  }


  if (this->vindpm_sensor_ != nullptr) {
    this->vindpm_sensor_->publish_state(get_vindpm(true));
  }


  if (this->iindpm_sensor_ != nullptr) {
    this->iindpm_sensor_->publish_state(get_iindpm(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->vbat_lowv_sensor_ != nullptr) {
    this->vbat_lowv_sensor_->publish_state(get_vbat_lowv(true));
    needs_2nd_read = false;
  }
  if (this->vbat_lowv_text_sensor_ != nullptr) {
    this->vbat_lowv_text_sensor_->publish_state(get_vbat_lowv_string(needs_2nd_read));
  }


  if (this->iprechg_sensor_ != nullptr) {
    this->iprechg_sensor_->publish_state(get_iprechg(true));
  }


  if (this->reg_rst_binary_sensor_ != nullptr) {
    this->reg_rst_binary_sensor_->publish_state(get_reg_rst(true));
  }


  if (this->stop_wd_chg_binary_sensor_ != nullptr) {
    this->stop_wd_chg_binary_sensor_->publish_state(get_stop_wd_chg(true));
  }


  if (this->iterm_sensor_ != nullptr) {
    this->iterm_sensor_->publish_state(get_iterm(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->cell_sensor_ != nullptr) {
    this->cell_sensor_->publish_state(get_cell(true));
    needs_2nd_read = false;
  }
  if (this->cell_text_sensor_ != nullptr) {
    this->cell_text_sensor_->publish_state(get_cell_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->trechg_sensor_ != nullptr) {
    this->trechg_sensor_->publish_state(get_trechg(true));
    needs_2nd_read = false;
  }
  if (this->trechg_text_sensor_ != nullptr) {
    this->trechg_text_sensor_->publish_state(get_trechg_string(needs_2nd_read));
  }


  if (this->vrechg_sensor_ != nullptr) {
    this->vrechg_sensor_->publish_state(get_vrechg(true));
  }


  if (this->votg_sensor_ != nullptr) {
    this->votg_sensor_->publish_state(get_votg(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->prechg_tmr_sensor_ != nullptr) {
    this->prechg_tmr_sensor_->publish_state(get_prechg_tmr(true));
    needs_2nd_read = false;
  }
  if (this->prechg_tmr_text_sensor_ != nullptr) {
    this->prechg_tmr_text_sensor_->publish_state(get_prechg_tmr_string(needs_2nd_read));
  }


  if (this->iotg_sensor_ != nullptr) {
    this->iotg_sensor_->publish_state(get_iotg(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->topoff_tmr_sensor_ != nullptr) {
    this->topoff_tmr_sensor_->publish_state(get_topoff_tmr(true));
    needs_2nd_read = false;
  }
  if (this->topoff_tmr_text_sensor_ != nullptr) {
    this->topoff_tmr_text_sensor_->publish_state(get_topoff_tmr_string(needs_2nd_read));
  }


  if (this->en_trichg_tmr_binary_sensor_ != nullptr) {
    this->en_trichg_tmr_binary_sensor_->publish_state(get_en_trichg_tmr(true));
  }


  if (this->en_prechg_tmr_binary_sensor_ != nullptr) {
    this->en_prechg_tmr_binary_sensor_->publish_state(get_en_prechg_tmr(true));
  }


  if (this->en_chg_tmr_binary_sensor_ != nullptr) {
    this->en_chg_tmr_binary_sensor_->publish_state(get_en_chg_tmr(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->chg_tmr_sensor_ != nullptr) {
    this->chg_tmr_sensor_->publish_state(get_chg_tmr(true));
    needs_2nd_read = false;
  }
  if (this->chg_tmr_text_sensor_ != nullptr) {
    this->chg_tmr_text_sensor_->publish_state(get_chg_tmr_string(needs_2nd_read));
  }


  if (this->tmr2x_en_binary_sensor_ != nullptr) {
    this->tmr2x_en_binary_sensor_->publish_state(get_tmr2x_en(true));
  }


  if (this->en_auto_ibatdis_binary_sensor_ != nullptr) {
    this->en_auto_ibatdis_binary_sensor_->publish_state(get_en_auto_ibatdis(true));
  }


  if (this->force_ibatdis_binary_sensor_ != nullptr) {
    this->force_ibatdis_binary_sensor_->publish_state(get_force_ibatdis(true));
  }


  if (this->en_chg_binary_sensor_ != nullptr) {
    this->en_chg_binary_sensor_->publish_state(get_en_chg(true));
  }


  if (this->en_ico_binary_sensor_ != nullptr) {
    this->en_ico_binary_sensor_->publish_state(get_en_ico(true));
  }


  if (this->force_ico_binary_sensor_ != nullptr) {
    this->force_ico_binary_sensor_->publish_state(get_force_ico(true));
  }


  if (this->en_hiz_binary_sensor_ != nullptr) {
    this->en_hiz_binary_sensor_->publish_state(get_en_hiz(true));
  }


  if (this->en_term_binary_sensor_ != nullptr) {
    this->en_term_binary_sensor_->publish_state(get_en_term(true));
  }


  if (this->en_backup_binary_sensor_ != nullptr) {
    this->en_backup_binary_sensor_->publish_state(get_en_backup(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->vbus_backup_sensor_ != nullptr) {
    this->vbus_backup_sensor_->publish_state(get_vbus_backup(true));
    needs_2nd_read = false;
  }
  if (this->vbus_backup_text_sensor_ != nullptr) {
    this->vbus_backup_text_sensor_->publish_state(get_vbus_backup_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->vac_ovp_sensor_ != nullptr) {
    this->vac_ovp_sensor_->publish_state(get_vac_ovp(true));
    needs_2nd_read = false;
  }
  if (this->vac_ovp_text_sensor_ != nullptr) {
    this->vac_ovp_text_sensor_->publish_state(get_vac_ovp_string(needs_2nd_read));
  }


  if (this->wd_rst_binary_sensor_ != nullptr) {
    this->wd_rst_binary_sensor_->publish_state(get_wd_rst(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->watchdog_sensor_ != nullptr) {
    this->watchdog_sensor_->publish_state(get_watchdog(true));
    needs_2nd_read = false;
  }
  if (this->watchdog_text_sensor_ != nullptr) {
    this->watchdog_text_sensor_->publish_state(get_watchdog_string(needs_2nd_read));
  }


  if (this->force_indet_binary_sensor_ != nullptr) {
    this->force_indet_binary_sensor_->publish_state(get_force_indet(true));
  }


  if (this->auto_indet_en_binary_sensor_ != nullptr) {
    this->auto_indet_en_binary_sensor_->publish_state(get_auto_indet_en(true));
  }


  if (this->en_12v_binary_sensor_ != nullptr) {
    this->en_12v_binary_sensor_->publish_state(get_en_12v(true));
  }


  if (this->en_9v_binary_sensor_ != nullptr) {
    this->en_9v_binary_sensor_->publish_state(get_en_9v(true));
  }


  if (this->hvdcp_en_binary_sensor_ != nullptr) {
    this->hvdcp_en_binary_sensor_->publish_state(get_hvdcp_en(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->sdrv_ctrl_sensor_ != nullptr) {
    this->sdrv_ctrl_sensor_->publish_state(get_sdrv_ctrl(true));
    needs_2nd_read = false;
  }
  if (this->sdrv_ctrl_text_sensor_ != nullptr) {
    this->sdrv_ctrl_text_sensor_->publish_state(get_sdrv_ctrl_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->sdrv_dly_sensor_ != nullptr) {
    this->sdrv_dly_sensor_->publish_state(get_sdrv_dly(true));
    needs_2nd_read = false;
  }
  if (this->sdrv_dly_text_sensor_ != nullptr) {
    this->sdrv_dly_text_sensor_->publish_state(get_sdrv_dly_string(needs_2nd_read));
  }


  if (this->dis_acdrv_binary_sensor_ != nullptr) {
    this->dis_acdrv_binary_sensor_->publish_state(get_dis_acdrv(true));
  }


  if (this->en_otg_binary_sensor_ != nullptr) {
    this->en_otg_binary_sensor_->publish_state(get_en_otg(true));
  }


  if (this->pfm_otg_dis_binary_sensor_ != nullptr) {
    this->pfm_otg_dis_binary_sensor_->publish_state(get_pfm_otg_dis(true));
  }


  if (this->pfm_fwd_dis_binary_sensor_ != nullptr) {
    this->pfm_fwd_dis_binary_sensor_->publish_state(get_pfm_fwd_dis(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->wkup_dly_sensor_ != nullptr) {
    this->wkup_dly_sensor_->publish_state(get_wkup_dly(true));
    needs_2nd_read = false;
  }
  if (this->wkup_dly_text_sensor_ != nullptr) {
    this->wkup_dly_text_sensor_->publish_state(get_wkup_dly_string(needs_2nd_read));
  }


  if (this->dis_ldo_binary_sensor_ != nullptr) {
    this->dis_ldo_binary_sensor_->publish_state(get_dis_ldo(true));
  }


  if (this->dis_otg_ooa_binary_sensor_ != nullptr) {
    this->dis_otg_ooa_binary_sensor_->publish_state(get_dis_otg_ooa(true));
  }


  if (this->dis_fwd_ooa_binary_sensor_ != nullptr) {
    this->dis_fwd_ooa_binary_sensor_->publish_state(get_dis_fwd_ooa(true));
  }


  if (this->en_acdrv2_binary_sensor_ != nullptr) {
    this->en_acdrv2_binary_sensor_->publish_state(get_en_acdrv2(true));
  }


  if (this->en_acdrv1_binary_sensor_ != nullptr) {
    this->en_acdrv1_binary_sensor_->publish_state(get_en_acdrv1(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->pwm_freq_sensor_ != nullptr) {
    this->pwm_freq_sensor_->publish_state(get_pwm_freq(true));
    needs_2nd_read = false;
  }
  if (this->pwm_freq_text_sensor_ != nullptr) {
    this->pwm_freq_text_sensor_->publish_state(get_pwm_freq_string(needs_2nd_read));
  }


  if (this->dis_stat_binary_sensor_ != nullptr) {
    this->dis_stat_binary_sensor_->publish_state(get_dis_stat(true));
  }


  if (this->dis_vsys_short_binary_sensor_ != nullptr) {
    this->dis_vsys_short_binary_sensor_->publish_state(get_dis_vsys_short(true));
  }


  if (this->dis_votg_uvp_binary_sensor_ != nullptr) {
    this->dis_votg_uvp_binary_sensor_->publish_state(get_dis_votg_uvp(true));
  }


  if (this->force_vindpm_det_binary_sensor_ != nullptr) {
    this->force_vindpm_det_binary_sensor_->publish_state(get_force_vindpm_det(true));
  }


  if (this->en_ibus_ocp_binary_sensor_ != nullptr) {
    this->en_ibus_ocp_binary_sensor_->publish_state(get_en_ibus_ocp(true));
  }


  if (this->sfet_present_binary_sensor_ != nullptr) {
    this->sfet_present_binary_sensor_->publish_state(get_sfet_present(true));
  }


  if (this->en_ibat_binary_sensor_ != nullptr) {
    this->en_ibat_binary_sensor_->publish_state(get_en_ibat(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->ibat_reg_sensor_ != nullptr) {
    this->ibat_reg_sensor_->publish_state(get_ibat_reg(true));
    needs_2nd_read = false;
  }
  if (this->ibat_reg_text_sensor_ != nullptr) {
    this->ibat_reg_text_sensor_->publish_state(get_ibat_reg_string(needs_2nd_read));
  }


  if (this->en_iindpm_binary_sensor_ != nullptr) {
    this->en_iindpm_binary_sensor_->publish_state(get_en_iindpm(true));
  }


  if (this->en_extilim_binary_sensor_ != nullptr) {
    this->en_extilim_binary_sensor_->publish_state(get_en_extilim(true));
  }


  if (this->en_batoc_binary_sensor_ != nullptr) {
    this->en_batoc_binary_sensor_->publish_state(get_en_batoc(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->voc_pct_sensor_ != nullptr) {
    this->voc_pct_sensor_->publish_state(get_voc_pct(true));
    needs_2nd_read = false;
  }
  if (this->voc_pct_text_sensor_ != nullptr) {
    this->voc_pct_text_sensor_->publish_state(get_voc_pct_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->voc_dly_sensor_ != nullptr) {
    this->voc_dly_sensor_->publish_state(get_voc_dly(true));
    needs_2nd_read = false;
  }
  if (this->voc_dly_text_sensor_ != nullptr) {
    this->voc_dly_text_sensor_->publish_state(get_voc_dly_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->voc_rate_sensor_ != nullptr) {
    this->voc_rate_sensor_->publish_state(get_voc_rate(true));
    needs_2nd_read = false;
  }
  if (this->voc_rate_text_sensor_ != nullptr) {
    this->voc_rate_text_sensor_->publish_state(get_voc_rate_string(needs_2nd_read));
  }


  if (this->en_mppt_binary_sensor_ != nullptr) {
    this->en_mppt_binary_sensor_->publish_state(get_en_mppt(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->treg_sensor_ != nullptr) {
    this->treg_sensor_->publish_state(get_treg(true));
    needs_2nd_read = false;
  }
  if (this->treg_text_sensor_ != nullptr) {
    this->treg_text_sensor_->publish_state(get_treg_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->tshut_sensor_ != nullptr) {
    this->tshut_sensor_->publish_state(get_tshut(true));
    needs_2nd_read = false;
  }
  if (this->tshut_text_sensor_ != nullptr) {
    this->tshut_text_sensor_->publish_state(get_tshut_string(needs_2nd_read));
  }


  if (this->vbus_pd_en_binary_sensor_ != nullptr) {
    this->vbus_pd_en_binary_sensor_->publish_state(get_vbus_pd_en(true));
  }


  if (this->vac1_pd_en_binary_sensor_ != nullptr) {
    this->vac1_pd_en_binary_sensor_->publish_state(get_vac1_pd_en(true));
  }


  if (this->vac2_pd_en_binary_sensor_ != nullptr) {
    this->vac2_pd_en_binary_sensor_->publish_state(get_vac2_pd_en(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->bkup_acfet1_on_sensor_ != nullptr) {
    this->bkup_acfet1_on_sensor_->publish_state(get_bkup_acfet1_on(true));
    needs_2nd_read = false;
  }
  if (this->bkup_acfet1_on_text_sensor_ != nullptr) {
    this->bkup_acfet1_on_text_sensor_->publish_state(get_bkup_acfet1_on_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->jeita_vset_sensor_ != nullptr) {
    this->jeita_vset_sensor_->publish_state(get_jeita_vset(true));
    needs_2nd_read = false;
  }
  if (this->jeita_vset_text_sensor_ != nullptr) {
    this->jeita_vset_text_sensor_->publish_state(get_jeita_vset_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->jeita_iseth_sensor_ != nullptr) {
    this->jeita_iseth_sensor_->publish_state(get_jeita_iseth(true));
    needs_2nd_read = false;
  }
  if (this->jeita_iseth_text_sensor_ != nullptr) {
    this->jeita_iseth_text_sensor_->publish_state(get_jeita_iseth_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->jeita_isetc_sensor_ != nullptr) {
    this->jeita_isetc_sensor_->publish_state(get_jeita_isetc(true));
    needs_2nd_read = false;
  }
  if (this->jeita_isetc_text_sensor_ != nullptr) {
    this->jeita_isetc_text_sensor_->publish_state(get_jeita_isetc_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->ts_cool_sensor_ != nullptr) {
    this->ts_cool_sensor_->publish_state(get_ts_cool(true));
    needs_2nd_read = false;
  }
  if (this->ts_cool_text_sensor_ != nullptr) {
    this->ts_cool_text_sensor_->publish_state(get_ts_cool_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->ts_warm_sensor_ != nullptr) {
    this->ts_warm_sensor_->publish_state(get_ts_warm(true));
    needs_2nd_read = false;
  }
  if (this->ts_warm_text_sensor_ != nullptr) {
    this->ts_warm_text_sensor_->publish_state(get_ts_warm_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->bhot_sensor_ != nullptr) {
    this->bhot_sensor_->publish_state(get_bhot(true));
    needs_2nd_read = false;
  }
  if (this->bhot_text_sensor_ != nullptr) {
    this->bhot_text_sensor_->publish_state(get_bhot_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->bcold_sensor_ != nullptr) {
    this->bcold_sensor_->publish_state(get_bcold(true));
    needs_2nd_read = false;
  }
  if (this->bcold_text_sensor_ != nullptr) {
    this->bcold_text_sensor_->publish_state(get_bcold_string(needs_2nd_read));
  }


  if (this->ts_ignore_binary_sensor_ != nullptr) {
    this->ts_ignore_binary_sensor_->publish_state(get_ts_ignore(true));
  }


  if (this->ico_ilim_sensor_ != nullptr) {
    this->ico_ilim_sensor_->publish_state(get_ico_ilim(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->iindpm_stat_sensor_ != nullptr) {
    this->iindpm_stat_sensor_->publish_state(get_iindpm_stat(true));
    needs_2nd_read = false;
  }
  if (this->iindpm_stat_text_sensor_ != nullptr) {
    this->iindpm_stat_text_sensor_->publish_state(get_iindpm_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->vindpm_stat_sensor_ != nullptr) {
    this->vindpm_stat_sensor_->publish_state(get_vindpm_stat(true));
    needs_2nd_read = false;
  }
  if (this->vindpm_stat_text_sensor_ != nullptr) {
    this->vindpm_stat_text_sensor_->publish_state(get_vindpm_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->wd_stat_sensor_ != nullptr) {
    this->wd_stat_sensor_->publish_state(get_wd_stat(true));
    needs_2nd_read = false;
  }
  if (this->wd_stat_text_sensor_ != nullptr) {
    this->wd_stat_text_sensor_->publish_state(get_wd_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->pg_stat_sensor_ != nullptr) {
    this->pg_stat_sensor_->publish_state(get_pg_stat(true));
    needs_2nd_read = false;
  }
  if (this->pg_stat_text_sensor_ != nullptr) {
    this->pg_stat_text_sensor_->publish_state(get_pg_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->ac2_present_stat_sensor_ != nullptr) {
    this->ac2_present_stat_sensor_->publish_state(get_ac2_present_stat(true));
    needs_2nd_read = false;
  }
  if (this->ac2_present_stat_text_sensor_ != nullptr) {
    this->ac2_present_stat_text_sensor_->publish_state(get_ac2_present_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->ac1_present_stat_sensor_ != nullptr) {
    this->ac1_present_stat_sensor_->publish_state(get_ac1_present_stat(true));
    needs_2nd_read = false;
  }
  if (this->ac1_present_stat_text_sensor_ != nullptr) {
    this->ac1_present_stat_text_sensor_->publish_state(get_ac1_present_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->vbus_present_stat_sensor_ != nullptr) {
    this->vbus_present_stat_sensor_->publish_state(get_vbus_present_stat(true));
    needs_2nd_read = false;
  }
  if (this->vbus_present_stat_text_sensor_ != nullptr) {
    this->vbus_present_stat_text_sensor_->publish_state(get_vbus_present_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->chg_stat_sensor_ != nullptr) {
    this->chg_stat_sensor_->publish_state(get_chg_stat(true));
    needs_2nd_read = false;
  }
  if (this->chg_stat_text_sensor_ != nullptr) {
    this->chg_stat_text_sensor_->publish_state(get_chg_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->vbus_stat_sensor_ != nullptr) {
    this->vbus_stat_sensor_->publish_state(get_vbus_stat(true));
    needs_2nd_read = false;
  }
  if (this->vbus_stat_text_sensor_ != nullptr) {
    this->vbus_stat_text_sensor_->publish_state(get_vbus_stat_string(needs_2nd_read));
  }


  if (this->bc12_done_stat_binary_sensor_ != nullptr) {
    this->bc12_done_stat_binary_sensor_->publish_state(get_bc12_done_stat(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->ico_stat_sensor_ != nullptr) {
    this->ico_stat_sensor_->publish_state(get_ico_stat(true));
    needs_2nd_read = false;
  }
  if (this->ico_stat_text_sensor_ != nullptr) {
    this->ico_stat_text_sensor_->publish_state(get_ico_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->treg_stat_sensor_ != nullptr) {
    this->treg_stat_sensor_->publish_state(get_treg_stat(true));
    needs_2nd_read = false;
  }
  if (this->treg_stat_text_sensor_ != nullptr) {
    this->treg_stat_text_sensor_->publish_state(get_treg_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->dpdm_stat_sensor_ != nullptr) {
    this->dpdm_stat_sensor_->publish_state(get_dpdm_stat(true));
    needs_2nd_read = false;
  }
  if (this->dpdm_stat_text_sensor_ != nullptr) {
    this->dpdm_stat_text_sensor_->publish_state(get_dpdm_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->vbat_present_stat_sensor_ != nullptr) {
    this->vbat_present_stat_sensor_->publish_state(get_vbat_present_stat(true));
    needs_2nd_read = false;
  }
  if (this->vbat_present_stat_text_sensor_ != nullptr) {
    this->vbat_present_stat_text_sensor_->publish_state(get_vbat_present_stat_string(needs_2nd_read));
  }


  if (this->acrb2_stat_binary_sensor_ != nullptr) {
    this->acrb2_stat_binary_sensor_->publish_state(get_acrb2_stat(true));
  }


  if (this->acrb1_stat_binary_sensor_ != nullptr) {
    this->acrb1_stat_binary_sensor_->publish_state(get_acrb1_stat(true));
  }


  if (this->adc_done_stat_binary_sensor_ != nullptr) {
    this->adc_done_stat_binary_sensor_->publish_state(get_adc_done_stat(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->vsys_stat_sensor_ != nullptr) {
    this->vsys_stat_sensor_->publish_state(get_vsys_stat(true));
    needs_2nd_read = false;
  }
  if (this->vsys_stat_text_sensor_ != nullptr) {
    this->vsys_stat_text_sensor_->publish_state(get_vsys_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->chg_tmr_stat_sensor_ != nullptr) {
    this->chg_tmr_stat_sensor_->publish_state(get_chg_tmr_stat(true));
    needs_2nd_read = false;
  }
  if (this->chg_tmr_stat_text_sensor_ != nullptr) {
    this->chg_tmr_stat_text_sensor_->publish_state(get_chg_tmr_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->trichg_tmr_stat_sensor_ != nullptr) {
    this->trichg_tmr_stat_sensor_->publish_state(get_trichg_tmr_stat(true));
    needs_2nd_read = false;
  }
  if (this->trichg_tmr_stat_text_sensor_ != nullptr) {
    this->trichg_tmr_stat_text_sensor_->publish_state(get_trichg_tmr_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->prechg_tmr_stat_sensor_ != nullptr) {
    this->prechg_tmr_stat_sensor_->publish_state(get_prechg_tmr_stat(true));
    needs_2nd_read = false;
  }
  if (this->prechg_tmr_stat_text_sensor_ != nullptr) {
    this->prechg_tmr_stat_text_sensor_->publish_state(get_prechg_tmr_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->vbatotg_low_stat_sensor_ != nullptr) {
    this->vbatotg_low_stat_sensor_->publish_state(get_vbatotg_low_stat(true));
    needs_2nd_read = false;
  }
  if (this->vbatotg_low_stat_text_sensor_ != nullptr) {
    this->vbatotg_low_stat_text_sensor_->publish_state(get_vbatotg_low_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->ts_cold_stat_sensor_ != nullptr) {
    this->ts_cold_stat_sensor_->publish_state(get_ts_cold_stat(true));
    needs_2nd_read = false;
  }
  if (this->ts_cold_stat_text_sensor_ != nullptr) {
    this->ts_cold_stat_text_sensor_->publish_state(get_ts_cold_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->ts_cool_stat_sensor_ != nullptr) {
    this->ts_cool_stat_sensor_->publish_state(get_ts_cool_stat(true));
    needs_2nd_read = false;
  }
  if (this->ts_cool_stat_text_sensor_ != nullptr) {
    this->ts_cool_stat_text_sensor_->publish_state(get_ts_cool_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->ts_warm_stat_sensor_ != nullptr) {
    this->ts_warm_stat_sensor_->publish_state(get_ts_warm_stat(true));
    needs_2nd_read = false;
  }
  if (this->ts_warm_stat_text_sensor_ != nullptr) {
    this->ts_warm_stat_text_sensor_->publish_state(get_ts_warm_stat_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->ts_hot_stat_sensor_ != nullptr) {
    this->ts_hot_stat_sensor_->publish_state(get_ts_hot_stat(true));
    needs_2nd_read = false;
  }
  if (this->ts_hot_stat_text_sensor_ != nullptr) {
    this->ts_hot_stat_text_sensor_->publish_state(get_ts_hot_stat_string(needs_2nd_read));
  }


  if (this->ibat_reg_stat_binary_sensor_ != nullptr) {
    this->ibat_reg_stat_binary_sensor_->publish_state(get_ibat_reg_stat(true));
  }


  if (this->vbus_ovp_stat_binary_sensor_ != nullptr) {
    this->vbus_ovp_stat_binary_sensor_->publish_state(get_vbus_ovp_stat(true));
  }


  if (this->vbat_ovp_stat_binary_sensor_ != nullptr) {
    this->vbat_ovp_stat_binary_sensor_->publish_state(get_vbat_ovp_stat(true));
  }


  if (this->ibus_ocp_stat_binary_sensor_ != nullptr) {
    this->ibus_ocp_stat_binary_sensor_->publish_state(get_ibus_ocp_stat(true));
  }


  if (this->ibat_ocp_stat_binary_sensor_ != nullptr) {
    this->ibat_ocp_stat_binary_sensor_->publish_state(get_ibat_ocp_stat(true));
  }


  if (this->conv_ocp_stat_binary_sensor_ != nullptr) {
    this->conv_ocp_stat_binary_sensor_->publish_state(get_conv_ocp_stat(true));
  }


  if (this->vac2_ovp_stat_binary_sensor_ != nullptr) {
    this->vac2_ovp_stat_binary_sensor_->publish_state(get_vac2_ovp_stat(true));
  }


  if (this->vac1_ovp_stat_binary_sensor_ != nullptr) {
    this->vac1_ovp_stat_binary_sensor_->publish_state(get_vac1_ovp_stat(true));
  }


  if (this->vsys_short_stat_binary_sensor_ != nullptr) {
    this->vsys_short_stat_binary_sensor_->publish_state(get_vsys_short_stat(true));
  }


  if (this->vsys_ovp_stat_binary_sensor_ != nullptr) {
    this->vsys_ovp_stat_binary_sensor_->publish_state(get_vsys_ovp_stat(true));
  }


  if (this->otg_ovp_stat_binary_sensor_ != nullptr) {
    this->otg_ovp_stat_binary_sensor_->publish_state(get_otg_ovp_stat(true));
  }


  if (this->otg_uvp_stat_binary_sensor_ != nullptr) {
    this->otg_uvp_stat_binary_sensor_->publish_state(get_otg_uvp_stat(true));
  }


  if (this->tshut_stat_binary_sensor_ != nullptr) {
    this->tshut_stat_binary_sensor_->publish_state(get_tshut_stat(true));
  }


  if (this->iindpm_flag_binary_sensor_ != nullptr) {
    this->iindpm_flag_binary_sensor_->publish_state(get_iindpm_flag(true));
  }


  if (this->vindpm_flag_binary_sensor_ != nullptr) {
    this->vindpm_flag_binary_sensor_->publish_state(get_vindpm_flag(true));
  }


  if (this->wd_flag_binary_sensor_ != nullptr) {
    this->wd_flag_binary_sensor_->publish_state(get_wd_flag(true));
  }


  if (this->poorsrc_flag_binary_sensor_ != nullptr) {
    this->poorsrc_flag_binary_sensor_->publish_state(get_poorsrc_flag(true));
  }


  if (this->pg_flag_binary_sensor_ != nullptr) {
    this->pg_flag_binary_sensor_->publish_state(get_pg_flag(true));
  }


  if (this->ac2_present_flag_binary_sensor_ != nullptr) {
    this->ac2_present_flag_binary_sensor_->publish_state(get_ac2_present_flag(true));
  }


  if (this->ac1_present_flag_binary_sensor_ != nullptr) {
    this->ac1_present_flag_binary_sensor_->publish_state(get_ac1_present_flag(true));
  }


  if (this->vbus_present_flag_binary_sensor_ != nullptr) {
    this->vbus_present_flag_binary_sensor_->publish_state(get_vbus_present_flag(true));
  }


  if (this->chg_flag_binary_sensor_ != nullptr) {
    this->chg_flag_binary_sensor_->publish_state(get_chg_flag(true));
  }


  if (this->ico_flag_binary_sensor_ != nullptr) {
    this->ico_flag_binary_sensor_->publish_state(get_ico_flag(true));
  }


  if (this->vbus_flag_binary_sensor_ != nullptr) {
    this->vbus_flag_binary_sensor_->publish_state(get_vbus_flag(true));
  }


  if (this->treg_flag_binary_sensor_ != nullptr) {
    this->treg_flag_binary_sensor_->publish_state(get_treg_flag(true));
  }


  if (this->vbat_present_flag_binary_sensor_ != nullptr) {
    this->vbat_present_flag_binary_sensor_->publish_state(get_vbat_present_flag(true));
  }


  if (this->bc1_2_done_flag_binary_sensor_ != nullptr) {
    this->bc1_2_done_flag_binary_sensor_->publish_state(get_bc1_2_done_flag(true));
  }


  if (this->dpdm_done_flag_binary_sensor_ != nullptr) {
    this->dpdm_done_flag_binary_sensor_->publish_state(get_dpdm_done_flag(true));
  }


  if (this->adc_done_flag_binary_sensor_ != nullptr) {
    this->adc_done_flag_binary_sensor_->publish_state(get_adc_done_flag(true));
  }


  if (this->vsys_flag_binary_sensor_ != nullptr) {
    this->vsys_flag_binary_sensor_->publish_state(get_vsys_flag(true));
  }


  if (this->chg_tmr_flag_binary_sensor_ != nullptr) {
    this->chg_tmr_flag_binary_sensor_->publish_state(get_chg_tmr_flag(true));
  }


  if (this->trichg_tmr_flag_binary_sensor_ != nullptr) {
    this->trichg_tmr_flag_binary_sensor_->publish_state(get_trichg_tmr_flag(true));
  }


  if (this->prechg_tmr_flag_binary_sensor_ != nullptr) {
    this->prechg_tmr_flag_binary_sensor_->publish_state(get_prechg_tmr_flag(true));
  }


  if (this->topoff_tmr_flag_binary_sensor_ != nullptr) {
    this->topoff_tmr_flag_binary_sensor_->publish_state(get_topoff_tmr_flag(true));
  }


  if (this->vbatotg_low_flag_binary_sensor_ != nullptr) {
    this->vbatotg_low_flag_binary_sensor_->publish_state(get_vbatotg_low_flag(true));
  }


  if (this->ts_cold_flag_binary_sensor_ != nullptr) {
    this->ts_cold_flag_binary_sensor_->publish_state(get_ts_cold_flag(true));
  }


  if (this->ts_cool_flag_binary_sensor_ != nullptr) {
    this->ts_cool_flag_binary_sensor_->publish_state(get_ts_cool_flag(true));
  }


  if (this->ts_warm_flag_binary_sensor_ != nullptr) {
    this->ts_warm_flag_binary_sensor_->publish_state(get_ts_warm_flag(true));
  }


  if (this->ts_hot_flag_binary_sensor_ != nullptr) {
    this->ts_hot_flag_binary_sensor_->publish_state(get_ts_hot_flag(true));
  }


  if (this->ibat_reg_flag_binary_sensor_ != nullptr) {
    this->ibat_reg_flag_binary_sensor_->publish_state(get_ibat_reg_flag(true));
  }


  if (this->vbus_ovp_flag_binary_sensor_ != nullptr) {
    this->vbus_ovp_flag_binary_sensor_->publish_state(get_vbus_ovp_flag(true));
  }


  if (this->vbat_ovp_flag_binary_sensor_ != nullptr) {
    this->vbat_ovp_flag_binary_sensor_->publish_state(get_vbat_ovp_flag(true));
  }


  if (this->ibus_ocp_flag_binary_sensor_ != nullptr) {
    this->ibus_ocp_flag_binary_sensor_->publish_state(get_ibus_ocp_flag(true));
  }


  if (this->ibat_ocp_flag_binary_sensor_ != nullptr) {
    this->ibat_ocp_flag_binary_sensor_->publish_state(get_ibat_ocp_flag(true));
  }


  if (this->conv_ocp_flag_binary_sensor_ != nullptr) {
    this->conv_ocp_flag_binary_sensor_->publish_state(get_conv_ocp_flag(true));
  }


  if (this->vac2_ovp_flag_binary_sensor_ != nullptr) {
    this->vac2_ovp_flag_binary_sensor_->publish_state(get_vac2_ovp_flag(true));
  }


  if (this->vac1_ovp_flag_binary_sensor_ != nullptr) {
    this->vac1_ovp_flag_binary_sensor_->publish_state(get_vac1_ovp_flag(true));
  }


  if (this->vsys_short_flag_binary_sensor_ != nullptr) {
    this->vsys_short_flag_binary_sensor_->publish_state(get_vsys_short_flag(true));
  }


  if (this->vsys_ovp_flag_binary_sensor_ != nullptr) {
    this->vsys_ovp_flag_binary_sensor_->publish_state(get_vsys_ovp_flag(true));
  }


  if (this->otg_ovp_flag_binary_sensor_ != nullptr) {
    this->otg_ovp_flag_binary_sensor_->publish_state(get_otg_ovp_flag(true));
  }


  if (this->otg_uvp_flag_binary_sensor_ != nullptr) {
    this->otg_uvp_flag_binary_sensor_->publish_state(get_otg_uvp_flag(true));
  }


  if (this->tshut_flag_binary_sensor_ != nullptr) {
    this->tshut_flag_binary_sensor_->publish_state(get_tshut_flag(true));
  }


  if (this->adc_en_binary_sensor_ != nullptr) {
    this->adc_en_binary_sensor_->publish_state(get_adc_en(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->adc_rate_sensor_ != nullptr) {
    this->adc_rate_sensor_->publish_state(get_adc_rate(true));
    needs_2nd_read = false;
  }
  if (this->adc_rate_text_sensor_ != nullptr) {
    this->adc_rate_text_sensor_->publish_state(get_adc_rate_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->adc_sample_sensor_ != nullptr) {
    this->adc_sample_sensor_->publish_state(get_adc_sample(true));
    needs_2nd_read = false;
  }
  if (this->adc_sample_text_sensor_ != nullptr) {
    this->adc_sample_text_sensor_->publish_state(get_adc_sample_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->adc_avg_sensor_ != nullptr) {
    this->adc_avg_sensor_->publish_state(get_adc_avg(true));
    needs_2nd_read = false;
  }
  if (this->adc_avg_text_sensor_ != nullptr) {
    this->adc_avg_text_sensor_->publish_state(get_adc_avg_string(needs_2nd_read));
  }


  if (this->adc_avg_init_binary_sensor_ != nullptr) {
    this->adc_avg_init_binary_sensor_->publish_state(get_adc_avg_init(true));
  }


  if (this->ibus_adc_dis_binary_sensor_ != nullptr) {
    this->ibus_adc_dis_binary_sensor_->publish_state(get_ibus_adc_dis(true));
  }


  if (this->ibat_adc_dis_binary_sensor_ != nullptr) {
    this->ibat_adc_dis_binary_sensor_->publish_state(get_ibat_adc_dis(true));
  }


  if (this->vbus_adc_dis_binary_sensor_ != nullptr) {
    this->vbus_adc_dis_binary_sensor_->publish_state(get_vbus_adc_dis(true));
  }


  if (this->vbat_adc_dis_binary_sensor_ != nullptr) {
    this->vbat_adc_dis_binary_sensor_->publish_state(get_vbat_adc_dis(true));
  }


  if (this->vsys_adc_dis_binary_sensor_ != nullptr) {
    this->vsys_adc_dis_binary_sensor_->publish_state(get_vsys_adc_dis(true));
  }


  if (this->ts_adc_dis_binary_sensor_ != nullptr) {
    this->ts_adc_dis_binary_sensor_->publish_state(get_ts_adc_dis(true));
  }


  if (this->tdie_adc_dis_binary_sensor_ != nullptr) {
    this->tdie_adc_dis_binary_sensor_->publish_state(get_tdie_adc_dis(true));
  }


  if (this->dplus_adc_dis_binary_sensor_ != nullptr) {
    this->dplus_adc_dis_binary_sensor_->publish_state(get_dplus_adc_dis(true));
  }


  if (this->dminus_adc_dis_binary_sensor_ != nullptr) {
    this->dminus_adc_dis_binary_sensor_->publish_state(get_dminus_adc_dis(true));
  }


  if (this->vac2_adc_dis_binary_sensor_ != nullptr) {
    this->vac2_adc_dis_binary_sensor_->publish_state(get_vac2_adc_dis(true));
  }


  if (this->vac1_adc_dis_binary_sensor_ != nullptr) {
    this->vac1_adc_dis_binary_sensor_->publish_state(get_vac1_adc_dis(true));
  }


  if (this->ibus_adc_sensor_ != nullptr) {
    this->ibus_adc_sensor_->publish_state(get_ibus_adc(true));
  }


  if (this->ibat_adc_sensor_ != nullptr) {
    this->ibat_adc_sensor_->publish_state(get_ibat_adc(true));
  }


  if (this->vbus_adc_sensor_ != nullptr) {
    this->vbus_adc_sensor_->publish_state(get_vbus_adc(true));
  }


  if (this->vac1_adc_sensor_ != nullptr) {
    this->vac1_adc_sensor_->publish_state(get_vac1_adc(true));
  }


  if (this->vac2_adc_sensor_ != nullptr) {
    this->vac2_adc_sensor_->publish_state(get_vac2_adc(true));
  }


  if (this->vbat_adc_sensor_ != nullptr) {
    this->vbat_adc_sensor_->publish_state(get_vbat_adc(true));
  }


  if (this->vsys_adc_sensor_ != nullptr) {
    this->vsys_adc_sensor_->publish_state(get_vsys_adc(true));
  }


  if (this->ts_adc_sensor_ != nullptr) {
    this->ts_adc_sensor_->publish_state(get_ts_adc(true));
  }


  if (this->tdie_adc_sensor_ != nullptr) {
    this->tdie_adc_sensor_->publish_state(get_tdie_adc(true));
  }


  if (this->dplus_adc_sensor_ != nullptr) {
    this->dplus_adc_sensor_->publish_state(get_dplus_adc(true));
  }


  if (this->dminus_adc_sensor_ != nullptr) {
    this->dminus_adc_sensor_->publish_state(get_dminus_adc(true));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->dplus_dac_sensor_ != nullptr) {
    this->dplus_dac_sensor_->publish_state(get_dplus_dac(true));
    needs_2nd_read = false;
  }
  if (this->dplus_dac_text_sensor_ != nullptr) {
    this->dplus_dac_text_sensor_->publish_state(get_dplus_dac_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->dminus_dac_sensor_ != nullptr) {
    this->dminus_dac_sensor_->publish_state(get_dminus_dac(true));
    needs_2nd_read = false;
  }
  if (this->dminus_dac_text_sensor_ != nullptr) {
    this->dminus_dac_text_sensor_->publish_state(get_dminus_dac_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->pn_sensor_ != nullptr) {
    this->pn_sensor_->publish_state(get_pn(true));
    needs_2nd_read = false;
  }
  if (this->pn_text_sensor_ != nullptr) {
    this->pn_text_sensor_->publish_state(get_pn_string(needs_2nd_read));
  }


  // exception: process both int and string values
  needs_2nd_read = true;
  if (this->dev_rev_sensor_ != nullptr) {
    this->dev_rev_sensor_->publish_state(get_dev_rev(true));
    needs_2nd_read = false;
  }
  if (this->dev_rev_text_sensor_ != nullptr) {
    this->dev_rev_text_sensor_->publish_state(get_dev_rev_string(needs_2nd_read));
  }


}


int BQ25798Component::get_vsysmin(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG00_Minimal_System_Voltage, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG00_Minimal_System_Voltage\") value: 0x%02X", REG00_Minimal_System_Voltage, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(6);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (6 bits) raw value: 0x%04X", raw_value);
    vsysmin_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYSMIN);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vsysmin_;
} // getter





void BQ25798Component::on_init_set_vsysmin(bool value) {
  on_init_set_vsysmin_ = value;
}


void BQ25798Component::set_vsysmin(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VSYSMIN to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  vsysmin_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VSYSMIN);

 uint8_t reg_value;
  if (!this->read_byte(REG00_Minimal_System_Voltage, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG00_Minimal_System_Voltage\") value: 0x%02X", REG00_Minimal_System_Voltage, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(6) << 0);
// ESP_LOGD(TAG, "  masked (6 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(6)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG00_Minimal_System_Voltage, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_vreg(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG01_Charge_Voltage_Limit, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(11);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (11 bits) raw value: 0x%04X", raw_value);
    vreg_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VREG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vreg_;
} // getter





void BQ25798Component::on_init_set_vreg(bool value) {
  on_init_set_vreg_ = value;
}


void BQ25798Component::set_vreg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VREG to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  vreg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VREG);

  uint16_t reg_value;
  if (!this->read_byte_16(REG01_Charge_Voltage_Limit, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 16-bit register %02X value: 0x%04X", REG01_Charge_Voltage_Limit, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(11) << 0);
//ESP_LOGD(TAG, "  masked register value: 0x%04X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(11)) << 0);
//ESP_LOGD(TAG, "  new register value: 0x%04X", reg_value);
  if (!this->write_byte_16(REG01_Charge_Voltage_Limit, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_ichg(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG03_Charge_Current_Limit, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(9);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (9 bits) raw value: 0x%04X", raw_value);
    ichg_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICHG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ichg_;
} // getter





void BQ25798Component::on_init_set_ichg(bool value) {
  on_init_set_ichg_ = value;
}


void BQ25798Component::set_ichg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ICHG to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  ichg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ICHG);

  uint16_t reg_value;
  if (!this->read_byte_16(REG03_Charge_Current_Limit, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 16-bit register %02X value: 0x%04X", REG03_Charge_Current_Limit, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(9) << 0);
//ESP_LOGD(TAG, "  masked register value: 0x%04X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(9)) << 0);
//ESP_LOGD(TAG, "  new register value: 0x%04X", reg_value);
  if (!this->write_byte_16(REG03_Charge_Current_Limit, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_vindpm(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG05_Input_Voltage_Limit, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG05_Input_Voltage_Limit\") value: 0x%02X", REG05_Input_Voltage_Limit, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(8);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (8 bits) raw value: 0x%04X", raw_value);
    vindpm_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VINDPM);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vindpm_;
} // getter





void BQ25798Component::on_init_set_vindpm(bool value) {
  on_init_set_vindpm_ = value;
}


void BQ25798Component::set_vindpm(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VINDPM to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  vindpm_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VINDPM);

 uint8_t reg_value;
  if (!this->read_byte(REG05_Input_Voltage_Limit, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG05_Input_Voltage_Limit\") value: 0x%02X", REG05_Input_Voltage_Limit, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(8) << 0);
// ESP_LOGD(TAG, "  masked (8 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(8)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG05_Input_Voltage_Limit, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_iindpm(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG06_Input_Current_Limit, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(9);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (9 bits) raw value: 0x%04X", raw_value);
    iindpm_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IINDPM);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return iindpm_;
} // getter





void BQ25798Component::on_init_set_iindpm(bool value) {
  on_init_set_iindpm_ = value;
}


void BQ25798Component::set_iindpm(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IINDPM to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  iindpm_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IINDPM);

  uint16_t reg_value;
  if (!this->read_byte_16(REG06_Input_Current_Limit, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 16-bit register %02X value: 0x%04X", REG06_Input_Current_Limit, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(9) << 0);
//ESP_LOGD(TAG, "  masked register value: 0x%04X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(9)) << 0);
//ESP_LOGD(TAG, "  new register value: 0x%04X", reg_value);
  if (!this->write_byte_16(REG06_Input_Current_Limit, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_vbat_lowv(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG08_Precharge_Control\") value: 0x%02X", REG08_Precharge_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);
    vbat_lowv_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_LOWV);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbat_lowv_;
} // getter
const char* BQ25798Component::get_vbat_lowv_string(bool read_from_i2c) {
  int value = get_vbat_lowv(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VBAT_LOWV_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_vbat_lowv(bool value) {
  on_init_set_vbat_lowv_ = value;
}


void BQ25798Component::set_vbat_lowv(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBAT_LOWV to %d (<VBAT_LOWV_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  vbat_lowv_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VBAT_LOWV);
 uint8_t reg_value;
  if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG08_Precharge_Control\") value: 0x%02X", REG08_Precharge_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG08_Precharge_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_iprechg(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG08_Precharge_Control\") value: 0x%02X", REG08_Precharge_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(6);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (6 bits) raw value: 0x%04X", raw_value);
    iprechg_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IPRECHG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return iprechg_;
} // getter





void BQ25798Component::on_init_set_iprechg(bool value) {
  on_init_set_iprechg_ = value;
}


void BQ25798Component::set_iprechg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IPRECHG to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  iprechg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IPRECHG);

 uint8_t reg_value;
  if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG08_Precharge_Control\") value: 0x%02X", REG08_Precharge_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(6) << 0);
// ESP_LOGD(TAG, "  masked (6 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(6)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG08_Precharge_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_reg_rst(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    reg_rst_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->REG_RST);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return reg_rst_;
} // getter





void BQ25798Component::on_init_set_reg_rst(bool value) {
  on_init_set_reg_rst_ = value;
}


void BQ25798Component::set_reg_rst(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s REG_RST to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  reg_rst_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->REG_RST);

 uint8_t reg_value;
  if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG09_Termination_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_stop_wd_chg(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    stop_wd_chg_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->STOP_WD_CHG);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return stop_wd_chg_;
} // getter





void BQ25798Component::on_init_set_stop_wd_chg(bool value) {
  on_init_set_stop_wd_chg_ = value;
}


void BQ25798Component::set_stop_wd_chg(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s STOP_WD_CHG to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  stop_wd_chg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->STOP_WD_CHG);

 uint8_t reg_value;
  if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG09_Termination_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_iterm(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(5);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (5 bits) raw value: 0x%04X", raw_value);
    iterm_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ITERM);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return iterm_;
} // getter





void BQ25798Component::on_init_set_iterm(bool value) {
  on_init_set_iterm_ = value;
}


void BQ25798Component::set_iterm(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ITERM to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  iterm_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ITERM);

 uint8_t reg_value;
  if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG09_Termination_Control\") value: 0x%02X", REG09_Termination_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(5) << 0);
// ESP_LOGD(TAG, "  masked (5 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(5)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG09_Termination_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_cell(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);
    cell_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CELL);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return cell_;
} // getter
const char* BQ25798Component::get_cell_string(bool read_from_i2c) {
  int value = get_cell(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->CELL_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_cell(bool value) {
  on_init_set_cell_ = value;
}


void BQ25798Component::set_cell(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s CELL to %d (<CELL_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  cell_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->CELL);
 uint8_t reg_value;
  if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_trechg(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);
    trechg_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TRECHG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return trechg_;
} // getter
const char* BQ25798Component::get_trechg_string(bool read_from_i2c) {
  int value = get_trechg(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TRECHG_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_trechg(bool value) {
  on_init_set_trechg_ = value;
}


void BQ25798Component::set_trechg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TRECHG to %d (<TRECHG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  trechg_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TRECHG);
 uint8_t reg_value;
  if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_vrechg(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(4);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (4 bits) raw value: 0x%04X", raw_value);
    vrechg_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VRECHG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vrechg_;
} // getter





void BQ25798Component::on_init_set_vrechg(bool value) {
  on_init_set_vrechg_ = value;
}


void BQ25798Component::set_vrechg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VRECHG to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  vrechg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VRECHG);

 uint8_t reg_value;
  if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0A_Recharge_Control\") value: 0x%02X", REG0A_Recharge_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(4) << 0);
// ESP_LOGD(TAG, "  masked (4 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(4)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_votg(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG0B_VOTG_regulation, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(11);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (11 bits) raw value: 0x%04X", raw_value);
    votg_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOTG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return votg_;
} // getter





void BQ25798Component::on_init_set_votg(bool value) {
  on_init_set_votg_ = value;
}


void BQ25798Component::set_votg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VOTG to %d mV", _write ? "Setting and writing" : "Will eventually set", value);
  votg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOTG);

  uint16_t reg_value;
  if (!this->read_byte_16(REG0B_VOTG_regulation, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 16-bit register %02X value: 0x%04X", REG0B_VOTG_regulation, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(11) << 0);
//ESP_LOGD(TAG, "  masked register value: 0x%04X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(11)) << 0);
//ESP_LOGD(TAG, "  new register value: 0x%04X", reg_value);
  if (!this->write_byte_16(REG0B_VOTG_regulation, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_prechg_tmr(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0D_IOTG_regulation\") value: 0x%02X", REG0D_IOTG_regulation, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    prechg_tmr_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PRECHG_TMR);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return prechg_tmr_;
} // getter
const char* BQ25798Component::get_prechg_tmr_string(bool read_from_i2c) {
  int value = get_prechg_tmr(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->PRECHG_TMR_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_prechg_tmr(bool value) {
  on_init_set_prechg_tmr_ = value;
}


void BQ25798Component::set_prechg_tmr(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s PRECHG_TMR to %d (<PRECHG_TMR_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  prechg_tmr_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->PRECHG_TMR);
 uint8_t reg_value;
  if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0D_IOTG_regulation\") value: 0x%02X", REG0D_IOTG_regulation, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0D_IOTG_regulation, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_iotg(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0D_IOTG_regulation\") value: 0x%02X", REG0D_IOTG_regulation, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(7);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (7 bits) raw value: 0x%04X", raw_value);
    iotg_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IOTG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return iotg_;
} // getter





void BQ25798Component::on_init_set_iotg(bool value) {
  on_init_set_iotg_ = value;
}


void BQ25798Component::set_iotg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IOTG to %d mA", _write ? "Setting and writing" : "Will eventually set", value);
  iotg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IOTG);

 uint8_t reg_value;
  if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0D_IOTG_regulation\") value: 0x%02X", REG0D_IOTG_regulation, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(7) << 0);
// ESP_LOGD(TAG, "  masked (7 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(7)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0D_IOTG_regulation, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_topoff_tmr(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);
    topoff_tmr_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TOPOFF_TMR);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return topoff_tmr_;
} // getter
const char* BQ25798Component::get_topoff_tmr_string(bool read_from_i2c) {
  int value = get_topoff_tmr(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TOPOFF_TMR_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_topoff_tmr(bool value) {
  on_init_set_topoff_tmr_ = value;
}


void BQ25798Component::set_topoff_tmr(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TOPOFF_TMR to %d (<TOPOFF_TMR_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  topoff_tmr_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TOPOFF_TMR);
 uint8_t reg_value;
  if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_trichg_tmr(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_trichg_tmr_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_TRICHG_TMR);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_trichg_tmr_;
} // getter





void BQ25798Component::on_init_set_en_trichg_tmr(bool value) {
  on_init_set_en_trichg_tmr_ = value;
}


void BQ25798Component::set_en_trichg_tmr(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_TRICHG_TMR to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_trichg_tmr_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_TRICHG_TMR);

 uint8_t reg_value;
  if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_prechg_tmr(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_prechg_tmr_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_PRECHG_TMR);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_prechg_tmr_;
} // getter





void BQ25798Component::on_init_set_en_prechg_tmr(bool value) {
  on_init_set_en_prechg_tmr_ = value;
}


void BQ25798Component::set_en_prechg_tmr(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_PRECHG_TMR to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_prechg_tmr_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_PRECHG_TMR);

 uint8_t reg_value;
  if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_chg_tmr(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_chg_tmr_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_CHG_TMR);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_chg_tmr_;
} // getter





void BQ25798Component::on_init_set_en_chg_tmr(bool value) {
  on_init_set_en_chg_tmr_ = value;
}


void BQ25798Component::set_en_chg_tmr(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_CHG_TMR to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_chg_tmr_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_CHG_TMR);

 uint8_t reg_value;
  if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_chg_tmr(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (2 bits) raw value: 0x%04X", raw_value);
    chg_tmr_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_TMR);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return chg_tmr_;
} // getter
const char* BQ25798Component::get_chg_tmr_string(bool read_from_i2c) {
  int value = get_chg_tmr(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->CHG_TMR_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_chg_tmr(bool value) {
  on_init_set_chg_tmr_ = value;
}


void BQ25798Component::set_chg_tmr(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s CHG_TMR to %d (<CHG_TMR_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  chg_tmr_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->CHG_TMR);
 uint8_t reg_value;
  if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_tmr2x_en(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    tmr2x_en_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TMR2X_EN);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return tmr2x_en_;
} // getter





void BQ25798Component::on_init_set_tmr2x_en(bool value) {
  on_init_set_tmr2x_en_ = value;
}


void BQ25798Component::set_tmr2x_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TMR2X_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  tmr2x_en_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TMR2X_EN);

 uint8_t reg_value;
  if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0E_Timer_Control\") value: 0x%02X", REG0E_Timer_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_auto_ibatdis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_auto_ibatdis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_AUTO_IBATDIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_auto_ibatdis_;
} // getter





void BQ25798Component::on_init_set_en_auto_ibatdis(bool value) {
  on_init_set_en_auto_ibatdis_ = value;
}


void BQ25798Component::set_en_auto_ibatdis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_AUTO_IBATDIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_auto_ibatdis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_AUTO_IBATDIS);

 uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_force_ibatdis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    force_ibatdis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_IBATDIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return force_ibatdis_;
} // getter





void BQ25798Component::on_init_set_force_ibatdis(bool value) {
  on_init_set_force_ibatdis_ = value;
}


void BQ25798Component::set_force_ibatdis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s FORCE_IBATDIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  force_ibatdis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_IBATDIS);

 uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_chg(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_chg_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_CHG);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_chg_;
} // getter





void BQ25798Component::on_init_set_en_chg(bool value) {
  on_init_set_en_chg_ = value;
}


void BQ25798Component::set_en_chg(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_CHG to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_chg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_CHG);

 uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_ico(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_ico_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ICO);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_ico_;
} // getter





void BQ25798Component::on_init_set_en_ico(bool value) {
  on_init_set_en_ico_ = value;
}


void BQ25798Component::set_en_ico(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_ICO to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_ico_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_ICO);

 uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_force_ico(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    force_ico_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_ICO);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return force_ico_;
} // getter





void BQ25798Component::on_init_set_force_ico(bool value) {
  on_init_set_force_ico_ = value;
}


void BQ25798Component::set_force_ico(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s FORCE_ICO to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  force_ico_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_ICO);

 uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_hiz(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_hiz_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_HIZ);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_hiz_;
} // getter





void BQ25798Component::on_init_set_en_hiz(bool value) {
  on_init_set_en_hiz_ = value;
}


void BQ25798Component::set_en_hiz(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_HIZ to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_hiz_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_HIZ);

 uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_term(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_term_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_TERM);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_term_;
} // getter





void BQ25798Component::on_init_set_en_term(bool value) {
  on_init_set_en_term_ = value;
}


void BQ25798Component::set_en_term(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_TERM to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_term_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_TERM);

 uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_backup(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_backup_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_BACKUP);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_backup_;
} // getter





void BQ25798Component::on_init_set_en_backup(bool value) {
  on_init_set_en_backup_ = value;
}


void BQ25798Component::set_en_backup(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_BACKUP to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_backup_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_BACKUP);

 uint8_t reg_value;
  if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG0F_Charger_Control_0\") value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_vbus_backup(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);
    vbus_backup_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_BACKUP);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbus_backup_;
} // getter
const char* BQ25798Component::get_vbus_backup_string(bool read_from_i2c) {
  int value = get_vbus_backup(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VBUS_BACKUP_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_vbus_backup(bool value) {
  on_init_set_vbus_backup_ = value;
}


void BQ25798Component::set_vbus_backup(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBUS_BACKUP to %d (<VBUS_BACKUP_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  vbus_backup_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VBUS_BACKUP);
 uint8_t reg_value;
  if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_vac_ovp(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);
    vac_ovp_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC_OVP);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vac_ovp_;
} // getter
const char* BQ25798Component::get_vac_ovp_string(bool read_from_i2c) {
  int value = get_vac_ovp(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VAC_OVP_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_vac_ovp(bool value) {
  on_init_set_vac_ovp_ = value;
}


void BQ25798Component::set_vac_ovp(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC_OVP to %d (<VAC_OVP_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  vac_ovp_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VAC_OVP);
 uint8_t reg_value;
  if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_wd_rst(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    wd_rst_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->WD_RST);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return wd_rst_;
} // getter





void BQ25798Component::on_init_set_wd_rst(bool value) {
  on_init_set_wd_rst_ = value;
}


void BQ25798Component::set_wd_rst(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s WD_RST to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  wd_rst_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->WD_RST);

 uint8_t reg_value;
  if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_watchdog(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (3 bits) raw value: 0x%04X", raw_value);
    watchdog_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WATCHDOG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return watchdog_;
} // getter
const char* BQ25798Component::get_watchdog_string(bool read_from_i2c) {
  int value = get_watchdog(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->WATCHDOG_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_watchdog(bool value) {
  on_init_set_watchdog_ = value;
}


void BQ25798Component::set_watchdog(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s WATCHDOG to %d (<WATCHDOG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  watchdog_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->WATCHDOG);
 uint8_t reg_value;
  if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG10_Charger_Control_1\") value: 0x%02X", REG10_Charger_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 0);
// ESP_LOGD(TAG, "  masked (3 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_force_indet(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    force_indet_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_INDET);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return force_indet_;
} // getter





void BQ25798Component::on_init_set_force_indet(bool value) {
  on_init_set_force_indet_ = value;
}


void BQ25798Component::set_force_indet(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s FORCE_INDET to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  force_indet_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_INDET);

 uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_auto_indet_en(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    auto_indet_en_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AUTO_INDET_EN);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return auto_indet_en_;
} // getter





void BQ25798Component::on_init_set_auto_indet_en(bool value) {
  on_init_set_auto_indet_en_ = value;
}


void BQ25798Component::set_auto_indet_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s AUTO_INDET_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  auto_indet_en_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->AUTO_INDET_EN);

 uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_12v(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_12v_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_12V);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_12v_;
} // getter





void BQ25798Component::on_init_set_en_12v(bool value) {
  on_init_set_en_12v_ = value;
}


void BQ25798Component::set_en_12v(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_12V to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_12v_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_12V);

 uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_9v(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_9v_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_9V);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_9v_;
} // getter





void BQ25798Component::on_init_set_en_9v(bool value) {
  on_init_set_en_9v_ = value;
}


void BQ25798Component::set_en_9v(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_9V to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_9v_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_9V);

 uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_hvdcp_en(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    hvdcp_en_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->HVDCP_EN);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return hvdcp_en_;
} // getter





void BQ25798Component::on_init_set_hvdcp_en(bool value) {
  on_init_set_hvdcp_en_ = value;
}


void BQ25798Component::set_hvdcp_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s HVDCP_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  hvdcp_en_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->HVDCP_EN);

 uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_sdrv_ctrl(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (2 bits) raw value: 0x%04X", raw_value);
    sdrv_ctrl_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->SDRV_CTRL);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return sdrv_ctrl_;
} // getter
const char* BQ25798Component::get_sdrv_ctrl_string(bool read_from_i2c) {
  int value = get_sdrv_ctrl(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->SDRV_CTRL_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_sdrv_ctrl(bool value) {
  on_init_set_sdrv_ctrl_ = value;
}


void BQ25798Component::set_sdrv_ctrl(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s SDRV_CTRL to %d (<SDRV_CTRL_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  sdrv_ctrl_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->SDRV_CTRL);
 uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_sdrv_dly(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    sdrv_dly_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->SDRV_DLY);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return sdrv_dly_;
} // getter
const char* BQ25798Component::get_sdrv_dly_string(bool read_from_i2c) {
  int value = get_sdrv_dly(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->SDRV_DLY_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_sdrv_dly(bool value) {
  on_init_set_sdrv_dly_ = value;
}


void BQ25798Component::set_sdrv_dly(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s SDRV_DLY to %d (<SDRV_DLY_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  sdrv_dly_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->SDRV_DLY);
 uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG11_Charger_Control_2\") value: 0x%02X", REG11_Charger_Control_2, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_dis_acdrv(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    dis_acdrv_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_ACDRV);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dis_acdrv_;
} // getter





void BQ25798Component::on_init_set_dis_acdrv(bool value) {
  on_init_set_dis_acdrv_ = value;
}


void BQ25798Component::set_dis_acdrv(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_ACDRV to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  dis_acdrv_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_ACDRV);

 uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_otg(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_otg_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_OTG);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_otg_;
} // getter





void BQ25798Component::on_init_set_en_otg(bool value) {
  on_init_set_en_otg_ = value;
}


void BQ25798Component::set_en_otg(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_OTG to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_otg_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_OTG);

 uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_pfm_otg_dis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    pfm_otg_dis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PFM_OTG_DIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return pfm_otg_dis_;
} // getter





void BQ25798Component::on_init_set_pfm_otg_dis(bool value) {
  on_init_set_pfm_otg_dis_ = value;
}


void BQ25798Component::set_pfm_otg_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s PFM_OTG_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  pfm_otg_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->PFM_OTG_DIS);

 uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_pfm_fwd_dis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    pfm_fwd_dis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PFM_FWD_DIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return pfm_fwd_dis_;
} // getter





void BQ25798Component::on_init_set_pfm_fwd_dis(bool value) {
  on_init_set_pfm_fwd_dis_ = value;
}


void BQ25798Component::set_pfm_fwd_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s PFM_FWD_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  pfm_fwd_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->PFM_FWD_DIS);

 uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_wkup_dly(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    wkup_dly_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WKUP_DLY);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return wkup_dly_;
} // getter
const char* BQ25798Component::get_wkup_dly_string(bool read_from_i2c) {
  int value = get_wkup_dly(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->WKUP_DLY_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_wkup_dly(bool value) {
  on_init_set_wkup_dly_ = value;
}


void BQ25798Component::set_wkup_dly(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s WKUP_DLY to %d (<WKUP_DLY_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  wkup_dly_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->WKUP_DLY);
 uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_dis_ldo(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    dis_ldo_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_LDO);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dis_ldo_;
} // getter





void BQ25798Component::on_init_set_dis_ldo(bool value) {
  on_init_set_dis_ldo_ = value;
}


void BQ25798Component::set_dis_ldo(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_LDO to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  dis_ldo_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_LDO);

 uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_dis_otg_ooa(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    dis_otg_ooa_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_OTG_OOA);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dis_otg_ooa_;
} // getter





void BQ25798Component::on_init_set_dis_otg_ooa(bool value) {
  on_init_set_dis_otg_ooa_ = value;
}


void BQ25798Component::set_dis_otg_ooa(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_OTG_OOA to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  dis_otg_ooa_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_OTG_OOA);

 uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_dis_fwd_ooa(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    dis_fwd_ooa_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_FWD_OOA);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dis_fwd_ooa_;
} // getter





void BQ25798Component::on_init_set_dis_fwd_ooa(bool value) {
  on_init_set_dis_fwd_ooa_ = value;
}


void BQ25798Component::set_dis_fwd_ooa(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_FWD_OOA to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  dis_fwd_ooa_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_FWD_OOA);

 uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG12_Charger_Control_3\") value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_acdrv2(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_acdrv2_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ACDRV2);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_acdrv2_;
} // getter





void BQ25798Component::on_init_set_en_acdrv2(bool value) {
  on_init_set_en_acdrv2_ = value;
}


void BQ25798Component::set_en_acdrv2(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_ACDRV2 to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_acdrv2_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_ACDRV2);

 uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_acdrv1(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_acdrv1_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ACDRV1);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_acdrv1_;
} // getter





void BQ25798Component::on_init_set_en_acdrv1(bool value) {
  on_init_set_en_acdrv1_ = value;
}


void BQ25798Component::set_en_acdrv1(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_ACDRV1 to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_acdrv1_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_ACDRV1);

 uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_pwm_freq(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    pwm_freq_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PWM_FREQ);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return pwm_freq_;
} // getter
const char* BQ25798Component::get_pwm_freq_string(bool read_from_i2c) {
  int value = get_pwm_freq(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->PWM_FREQ_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_pwm_freq(bool value) {
  on_init_set_pwm_freq_ = value;
}


void BQ25798Component::set_pwm_freq(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s PWM_FREQ to %d (<PWM_FREQ_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  pwm_freq_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->PWM_FREQ);
 uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_dis_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    dis_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dis_stat_;
} // getter





void BQ25798Component::on_init_set_dis_stat(bool value) {
  on_init_set_dis_stat_ = value;
}


void BQ25798Component::set_dis_stat(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_STAT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  dis_stat_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_STAT);

 uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_dis_vsys_short(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    dis_vsys_short_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_VSYS_SHORT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dis_vsys_short_;
} // getter





void BQ25798Component::on_init_set_dis_vsys_short(bool value) {
  on_init_set_dis_vsys_short_ = value;
}


void BQ25798Component::set_dis_vsys_short(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_VSYS_SHORT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  dis_vsys_short_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_VSYS_SHORT);

 uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_dis_votg_uvp(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    dis_votg_uvp_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_VOTG_UVP);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dis_votg_uvp_;
} // getter





void BQ25798Component::on_init_set_dis_votg_uvp(bool value) {
  on_init_set_dis_votg_uvp_ = value;
}


void BQ25798Component::set_dis_votg_uvp(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DIS_VOTG_UVP to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  dis_votg_uvp_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DIS_VOTG_UVP);

 uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_force_vindpm_det(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    force_vindpm_det_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_VINDPM_DET);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return force_vindpm_det_;
} // getter





void BQ25798Component::on_init_set_force_vindpm_det(bool value) {
  on_init_set_force_vindpm_det_ = value;
}


void BQ25798Component::set_force_vindpm_det(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s FORCE_VINDPM_DET to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  force_vindpm_det_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->FORCE_VINDPM_DET);

 uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_ibus_ocp(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_ibus_ocp_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IBUS_OCP);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_ibus_ocp_;
} // getter





void BQ25798Component::on_init_set_en_ibus_ocp(bool value) {
  on_init_set_en_ibus_ocp_ = value;
}


void BQ25798Component::set_en_ibus_ocp(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_IBUS_OCP to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_ibus_ocp_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_IBUS_OCP);

 uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG13_Charger_Control_4\") value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_sfet_present(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    sfet_present_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->SFET_PRESENT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return sfet_present_;
} // getter





void BQ25798Component::on_init_set_sfet_present(bool value) {
  on_init_set_sfet_present_ = value;
}


void BQ25798Component::set_sfet_present(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s SFET_PRESENT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  sfet_present_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->SFET_PRESENT);

 uint8_t reg_value;
  if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_ibat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_ibat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IBAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_ibat_;
} // getter





void BQ25798Component::on_init_set_en_ibat(bool value) {
  on_init_set_en_ibat_ = value;
}


void BQ25798Component::set_en_ibat(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_IBAT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_ibat_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_IBAT);

 uint8_t reg_value;
  if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_ibat_reg(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (2 bits) raw value: 0x%04X", raw_value);
    ibat_reg_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBAT_REG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ibat_reg_;
} // getter
const char* BQ25798Component::get_ibat_reg_string(bool read_from_i2c) {
  int value = get_ibat_reg(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->IBAT_REG_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_ibat_reg(bool value) {
  on_init_set_ibat_reg_ = value;
}


void BQ25798Component::set_ibat_reg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IBAT_REG to %d (<IBAT_REG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  ibat_reg_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->IBAT_REG);
 uint8_t reg_value;
  if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 3);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 3);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_iindpm(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_iindpm_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IINDPM);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_iindpm_;
} // getter





void BQ25798Component::on_init_set_en_iindpm(bool value) {
  on_init_set_en_iindpm_ = value;
}


void BQ25798Component::set_en_iindpm(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_IINDPM to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_iindpm_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_IINDPM);

 uint8_t reg_value;
  if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_extilim(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_extilim_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_EXTILIM);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_extilim_;
} // getter





void BQ25798Component::on_init_set_en_extilim(bool value) {
  on_init_set_en_extilim_ = value;
}


void BQ25798Component::set_en_extilim(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_EXTILIM to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_extilim_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_EXTILIM);

 uint8_t reg_value;
  if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_batoc(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_batoc_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_BATOC);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_batoc_;
} // getter





void BQ25798Component::on_init_set_en_batoc(bool value) {
  on_init_set_en_batoc_ = value;
}


void BQ25798Component::set_en_batoc(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_BATOC to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_batoc_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_BATOC);

 uint8_t reg_value;
  if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG14_Charger_Control_5\") value: 0x%02X", REG14_Charger_Control_5, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_voc_pct(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);
    voc_pct_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_PCT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return voc_pct_;
} // getter
const char* BQ25798Component::get_voc_pct_string(bool read_from_i2c) {
  int value = get_voc_pct(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VOC_PCT_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_voc_pct(bool value) {
  on_init_set_voc_pct_ = value;
}


void BQ25798Component::set_voc_pct(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VOC_PCT to %d (<VOC_PCT_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  voc_pct_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOC_PCT);
 uint8_t reg_value;
  if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
// ESP_LOGD(TAG, "  masked (3 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_voc_dly(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);
    voc_dly_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_DLY);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return voc_dly_;
} // getter
const char* BQ25798Component::get_voc_dly_string(bool read_from_i2c) {
  int value = get_voc_dly(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VOC_DLY_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_voc_dly(bool value) {
  on_init_set_voc_dly_ = value;
}


void BQ25798Component::set_voc_dly(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VOC_DLY to %d (<VOC_DLY_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  voc_dly_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOC_DLY);
 uint8_t reg_value;
  if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_voc_rate(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (2 bits) raw value: 0x%04X", raw_value);
    voc_rate_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_RATE);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return voc_rate_;
} // getter
const char* BQ25798Component::get_voc_rate_string(bool read_from_i2c) {
  int value = get_voc_rate(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VOC_RATE_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_voc_rate(bool value) {
  on_init_set_voc_rate_ = value;
}


void BQ25798Component::set_voc_rate(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VOC_RATE to %d (<VOC_RATE_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  voc_rate_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->VOC_RATE);
 uint8_t reg_value;
  if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 2);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 2);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_en_mppt(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    en_mppt_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_MPPT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return en_mppt_;
} // getter





void BQ25798Component::on_init_set_en_mppt(bool value) {
  on_init_set_en_mppt_ = value;
}


void BQ25798Component::set_en_mppt(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s EN_MPPT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  en_mppt_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->EN_MPPT);

 uint8_t reg_value;
  if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG15_MPPT_Control\") value: 0x%02X", REG15_MPPT_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_treg(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);
    treg_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TREG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return treg_;
} // getter
const char* BQ25798Component::get_treg_string(bool read_from_i2c) {
  int value = get_treg(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TREG_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_treg(bool value) {
  on_init_set_treg_ = value;
}


void BQ25798Component::set_treg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TREG to %d (<TREG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  treg_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TREG);
 uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_tshut(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);
    tshut_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TSHUT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return tshut_;
} // getter
const char* BQ25798Component::get_tshut_string(bool read_from_i2c) {
  int value = get_tshut(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TSHUT_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_tshut(bool value) {
  on_init_set_tshut_ = value;
}


void BQ25798Component::set_tshut(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TSHUT to %d (<TSHUT_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  tshut_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TSHUT);
 uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_vbus_pd_en(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    vbus_pd_en_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_PD_EN);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbus_pd_en_;
} // getter





void BQ25798Component::on_init_set_vbus_pd_en(bool value) {
  on_init_set_vbus_pd_en_ = value;
}


void BQ25798Component::set_vbus_pd_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBUS_PD_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  vbus_pd_en_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBUS_PD_EN);

 uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_vac1_pd_en(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    vac1_pd_en_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_PD_EN);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vac1_pd_en_;
} // getter





void BQ25798Component::on_init_set_vac1_pd_en(bool value) {
  on_init_set_vac1_pd_en_ = value;
}


void BQ25798Component::set_vac1_pd_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC1_PD_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  vac1_pd_en_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC1_PD_EN);

 uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_vac2_pd_en(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    vac2_pd_en_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_PD_EN);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vac2_pd_en_;
} // getter





void BQ25798Component::on_init_set_vac2_pd_en(bool value) {
  on_init_set_vac2_pd_en_ = value;
}


void BQ25798Component::set_vac2_pd_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC2_PD_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  vac2_pd_en_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC2_PD_EN);

 uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_bkup_acfet1_on(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bkup_acfet1_on_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BKUP_ACFET1_ON);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return bkup_acfet1_on_;
} // getter
const char* BQ25798Component::get_bkup_acfet1_on_string(bool read_from_i2c) {
  int value = get_bkup_acfet1_on(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->BKUP_ACFET1_ON_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_bkup_acfet1_on(bool value) {
  on_init_set_bkup_acfet1_on_ = value;
}


void BQ25798Component::set_bkup_acfet1_on(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s BKUP_ACFET1_ON to %d (<BKUP_ACFET1_ON_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  bkup_acfet1_on_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->BKUP_ACFET1_ON);
 uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG16_Temperature_Control\") value: 0x%02X", REG16_Temperature_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_jeita_vset(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);
    jeita_vset_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_VSET);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return jeita_vset_;
} // getter
const char* BQ25798Component::get_jeita_vset_string(bool read_from_i2c) {
  int value = get_jeita_vset(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->JEITA_VSET_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_jeita_vset(bool value) {
  on_init_set_jeita_vset_ = value;
}


void BQ25798Component::set_jeita_vset(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s JEITA_VSET to %d (<JEITA_VSET_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  jeita_vset_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->JEITA_VSET);
 uint8_t reg_value;
  if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
// ESP_LOGD(TAG, "  masked (3 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_jeita_iseth(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (2 bits) raw value: 0x%04X", raw_value);
    jeita_iseth_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_ISETH);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return jeita_iseth_;
} // getter
const char* BQ25798Component::get_jeita_iseth_string(bool read_from_i2c) {
  int value = get_jeita_iseth(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->JEITA_ISETH_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_jeita_iseth(bool value) {
  on_init_set_jeita_iseth_ = value;
}


void BQ25798Component::set_jeita_iseth(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s JEITA_ISETH to %d (<JEITA_ISETH_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  jeita_iseth_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->JEITA_ISETH);
 uint8_t reg_value;
  if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 3);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 3);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_jeita_isetc(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (2 bits) raw value: 0x%04X", raw_value);
    jeita_isetc_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_ISETC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return jeita_isetc_;
} // getter
const char* BQ25798Component::get_jeita_isetc_string(bool read_from_i2c) {
  int value = get_jeita_isetc(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->JEITA_ISETC_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_jeita_isetc(bool value) {
  on_init_set_jeita_isetc_ = value;
}


void BQ25798Component::set_jeita_isetc(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s JEITA_ISETC to %d (<JEITA_ISETC_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  jeita_isetc_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->JEITA_ISETC);
 uint8_t reg_value;
  if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG17_NTC_Control_0\") value: 0x%02X", REG17_NTC_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_ts_cool(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);
    ts_cool_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COOL);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ts_cool_;
} // getter
const char* BQ25798Component::get_ts_cool_string(bool read_from_i2c) {
  int value = get_ts_cool(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TS_COOL_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_ts_cool(bool value) {
  on_init_set_ts_cool_ = value;
}


void BQ25798Component::set_ts_cool(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TS_COOL to %d (<TS_COOL_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  ts_cool_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TS_COOL);
 uint8_t reg_value;
  if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_ts_warm(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);
    ts_warm_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_WARM);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ts_warm_;
} // getter
const char* BQ25798Component::get_ts_warm_string(bool read_from_i2c) {
  int value = get_ts_warm(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TS_WARM_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_ts_warm(bool value) {
  on_init_set_ts_warm_ = value;
}


void BQ25798Component::set_ts_warm(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TS_WARM to %d (<TS_WARM_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  ts_warm_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->TS_WARM);
 uint8_t reg_value;
  if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_bhot(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (2 bits) raw value: 0x%04X", raw_value);
    bhot_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BHOT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return bhot_;
} // getter
const char* BQ25798Component::get_bhot_string(bool read_from_i2c) {
  int value = get_bhot(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->BHOT_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_bhot(bool value) {
  on_init_set_bhot_ = value;
}


void BQ25798Component::set_bhot(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s BHOT to %d (<BHOT_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  bhot_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->BHOT);
 uint8_t reg_value;
  if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 2);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 2);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_bcold(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    bcold_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BCOLD);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return bcold_;
} // getter
const char* BQ25798Component::get_bcold_string(bool read_from_i2c) {
  int value = get_bcold(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->BCOLD_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_bcold(bool value) {
  on_init_set_bcold_ = value;
}


void BQ25798Component::set_bcold(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s BCOLD to %d (<BCOLD_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  bcold_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->BCOLD);
 uint8_t reg_value;
  if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_ts_ignore(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    ts_ignore_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_IGNORE);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ts_ignore_;
} // getter





void BQ25798Component::on_init_set_ts_ignore(bool value) {
  on_init_set_ts_ignore_ = value;
}


void BQ25798Component::set_ts_ignore(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TS_IGNORE to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  ts_ignore_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TS_IGNORE);

 uint8_t reg_value;
  if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG18_NTC_Control_1\") value: 0x%02X", REG18_NTC_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_ico_ilim(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG19_ICO_Current_Limit, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(9);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (9 bits) raw value: 0x%04X", raw_value);
    ico_ilim_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICO_ILIM);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ico_ilim_;
} // getter






int BQ25798Component::get_iindpm_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    iindpm_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IINDPM_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return iindpm_stat_;
} // getter
const char* BQ25798Component::get_iindpm_stat_string(bool read_from_i2c) {
  int value = get_iindpm_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->IINDPM_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_vindpm_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    vindpm_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VINDPM_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vindpm_stat_;
} // getter
const char* BQ25798Component::get_vindpm_stat_string(bool read_from_i2c) {
  int value = get_vindpm_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VINDPM_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_wd_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    wd_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WD_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return wd_stat_;
} // getter
const char* BQ25798Component::get_wd_stat_string(bool read_from_i2c) {
  int value = get_wd_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->WD_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_pg_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    pg_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PG_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return pg_stat_;
} // getter
const char* BQ25798Component::get_pg_stat_string(bool read_from_i2c) {
  int value = get_pg_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->PG_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_ac2_present_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    ac2_present_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->AC2_PRESENT_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ac2_present_stat_;
} // getter
const char* BQ25798Component::get_ac2_present_stat_string(bool read_from_i2c) {
  int value = get_ac2_present_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->AC2_PRESENT_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_ac1_present_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    ac1_present_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->AC1_PRESENT_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ac1_present_stat_;
} // getter
const char* BQ25798Component::get_ac1_present_stat_string(bool read_from_i2c) {
  int value = get_ac1_present_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->AC1_PRESENT_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_vbus_present_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1B_Charger_Status_0\") value: 0x%02X", REG1B_Charger_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    vbus_present_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_PRESENT_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbus_present_stat_;
} // getter
const char* BQ25798Component::get_vbus_present_stat_string(bool read_from_i2c) {
  int value = get_vbus_present_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VBUS_PRESENT_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_chg_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1C_Charger_Status_1\") value: 0x%02X", REG1C_Charger_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);
    chg_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return chg_stat_;
} // getter
const char* BQ25798Component::get_chg_stat_string(bool read_from_i2c) {
  int value = get_chg_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->CHG_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_vbus_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1C_Charger_Status_1\") value: 0x%02X", REG1C_Charger_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(4);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (4 bits) raw value: 0x%04X", raw_value);
    vbus_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbus_stat_;
} // getter
const char* BQ25798Component::get_vbus_stat_string(bool read_from_i2c) {
  int value = get_vbus_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VBUS_STAT_strings);  // not nice, should not access toString() and strings array directly
}






bool BQ25798Component::get_bc12_done_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1C_Charger_Status_1\") value: 0x%02X", REG1C_Charger_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    bc12_done_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->BC12_DONE_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return bc12_done_stat_;
} // getter






int BQ25798Component::get_ico_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1D_Charger_Status_2\") value: 0x%02X", REG1D_Charger_Status_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);
    ico_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICO_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ico_stat_;
} // getter
const char* BQ25798Component::get_ico_stat_string(bool read_from_i2c) {
  int value = get_ico_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->ICO_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_treg_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1D_Charger_Status_2\") value: 0x%02X", REG1D_Charger_Status_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    treg_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TREG_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return treg_stat_;
} // getter
const char* BQ25798Component::get_treg_stat_string(bool read_from_i2c) {
  int value = get_treg_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TREG_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_dpdm_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1D_Charger_Status_2\") value: 0x%02X", REG1D_Charger_Status_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    dpdm_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPDM_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dpdm_stat_;
} // getter
const char* BQ25798Component::get_dpdm_stat_string(bool read_from_i2c) {
  int value = get_dpdm_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->DPDM_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_vbat_present_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1D_Charger_Status_2\") value: 0x%02X", REG1D_Charger_Status_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    vbat_present_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_PRESENT_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbat_present_stat_;
} // getter
const char* BQ25798Component::get_vbat_present_stat_string(bool read_from_i2c) {
  int value = get_vbat_present_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VBAT_PRESENT_STAT_strings);  // not nice, should not access toString() and strings array directly
}






bool BQ25798Component::get_acrb2_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    acrb2_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ACRB2_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return acrb2_stat_;
} // getter






bool BQ25798Component::get_acrb1_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    acrb1_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ACRB1_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return acrb1_stat_;
} // getter






bool BQ25798Component::get_adc_done_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    adc_done_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_DONE_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return adc_done_stat_;
} // getter






int BQ25798Component::get_vsys_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    vsys_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYS_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vsys_stat_;
} // getter
const char* BQ25798Component::get_vsys_stat_string(bool read_from_i2c) {
  int value = get_vsys_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VSYS_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_chg_tmr_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    chg_tmr_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_TMR_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return chg_tmr_stat_;
} // getter
const char* BQ25798Component::get_chg_tmr_stat_string(bool read_from_i2c) {
  int value = get_chg_tmr_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->CHG_TMR_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_trichg_tmr_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    trichg_tmr_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TRICHG_TMR_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return trichg_tmr_stat_;
} // getter
const char* BQ25798Component::get_trichg_tmr_stat_string(bool read_from_i2c) {
  int value = get_trichg_tmr_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TRICHG_TMR_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_prechg_tmr_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1E_Charger_Status_3\") value: 0x%02X", REG1E_Charger_Status_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    prechg_tmr_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PRECHG_TMR_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return prechg_tmr_stat_;
} // getter
const char* BQ25798Component::get_prechg_tmr_stat_string(bool read_from_i2c) {
  int value = get_prechg_tmr_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->PRECHG_TMR_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_vbatotg_low_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    vbatotg_low_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBATOTG_LOW_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbatotg_low_stat_;
} // getter
const char* BQ25798Component::get_vbatotg_low_stat_string(bool read_from_i2c) {
  int value = get_vbatotg_low_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->VBATOTG_LOW_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_ts_cold_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    ts_cold_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COLD_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ts_cold_stat_;
} // getter
const char* BQ25798Component::get_ts_cold_stat_string(bool read_from_i2c) {
  int value = get_ts_cold_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TS_COLD_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_ts_cool_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    ts_cool_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COOL_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ts_cool_stat_;
} // getter
const char* BQ25798Component::get_ts_cool_stat_string(bool read_from_i2c) {
  int value = get_ts_cool_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TS_COOL_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_ts_warm_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    ts_warm_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_WARM_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ts_warm_stat_;
} // getter
const char* BQ25798Component::get_ts_warm_stat_string(bool read_from_i2c) {
  int value = get_ts_warm_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TS_WARM_STAT_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_ts_hot_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG1F_Charger_Status_4\") value: 0x%02X", REG1F_Charger_Status_4, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    ts_hot_stat_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_HOT_STAT);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ts_hot_stat_;
} // getter
const char* BQ25798Component::get_ts_hot_stat_string(bool read_from_i2c) {
  int value = get_ts_hot_stat(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->TS_HOT_STAT_strings);  // not nice, should not access toString() and strings array directly
}






bool BQ25798Component::get_ibat_reg_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    ibat_reg_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_REG_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ibat_reg_stat_;
} // getter






bool BQ25798Component::get_vbus_ovp_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    vbus_ovp_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_OVP_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbus_ovp_stat_;
} // getter






bool BQ25798Component::get_vbat_ovp_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    vbat_ovp_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_OVP_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbat_ovp_stat_;
} // getter






bool BQ25798Component::get_ibus_ocp_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    ibus_ocp_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_OCP_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ibus_ocp_stat_;
} // getter






bool BQ25798Component::get_ibat_ocp_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    ibat_ocp_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_OCP_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ibat_ocp_stat_;
} // getter






bool BQ25798Component::get_conv_ocp_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    conv_ocp_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CONV_OCP_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return conv_ocp_stat_;
} // getter






bool BQ25798Component::get_vac2_ovp_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    vac2_ovp_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_OVP_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vac2_ovp_stat_;
} // getter






bool BQ25798Component::get_vac1_ovp_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG20_FAULT_Status_0\") value: 0x%02X", REG20_FAULT_Status_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    vac1_ovp_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_OVP_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vac1_ovp_stat_;
} // getter






bool BQ25798Component::get_vsys_short_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    vsys_short_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_SHORT_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vsys_short_stat_;
} // getter






bool BQ25798Component::get_vsys_ovp_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    vsys_ovp_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_OVP_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vsys_ovp_stat_;
} // getter






bool BQ25798Component::get_otg_ovp_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    otg_ovp_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_OVP_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return otg_ovp_stat_;
} // getter






bool BQ25798Component::get_otg_uvp_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    otg_uvp_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_UVP_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return otg_uvp_stat_;
} // getter






bool BQ25798Component::get_tshut_stat(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG21_FAULT_Status_1\") value: 0x%02X", REG21_FAULT_Status_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    tshut_stat_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TSHUT_STAT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return tshut_stat_;
} // getter






bool BQ25798Component::get_iindpm_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_iindpm_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IINDPM_FLAG);
    if (tmp_iindpm_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_iindpm_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return iindpm_flag_;
} // getter






bool BQ25798Component::get_vindpm_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_vindpm_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VINDPM_FLAG);
    if (tmp_vindpm_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_vindpm_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vindpm_flag_;
} // getter






bool BQ25798Component::get_wd_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_wd_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->WD_FLAG);
    if (tmp_wd_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_wd_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return wd_flag_;
} // getter






bool BQ25798Component::get_poorsrc_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_poorsrc_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->POORSRC_FLAG);
    if (tmp_poorsrc_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_poorsrc_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return poorsrc_flag_;
} // getter






bool BQ25798Component::get_pg_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_pg_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PG_FLAG);
    if (tmp_pg_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_pg_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return pg_flag_;
} // getter






bool BQ25798Component::get_ac2_present_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_ac2_present_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AC2_PRESENT_FLAG);
    if (tmp_ac2_present_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_ac2_present_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ac2_present_flag_;
} // getter






bool BQ25798Component::get_ac1_present_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_ac1_present_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AC1_PRESENT_FLAG);
    if (tmp_ac1_present_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_ac1_present_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ac1_present_flag_;
} // getter






bool BQ25798Component::get_vbus_present_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG22_Charger_Flag_0\") value: 0x%02X", REG22_Charger_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_vbus_present_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_PRESENT_FLAG);
    if (tmp_vbus_present_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_vbus_present_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbus_present_flag_;
} // getter






bool BQ25798Component::get_chg_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_chg_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CHG_FLAG);
    if (tmp_chg_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_chg_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return chg_flag_;
} // getter






bool BQ25798Component::get_ico_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_ico_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ICO_FLAG);
    if (tmp_ico_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_ico_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ico_flag_;
} // getter






bool BQ25798Component::get_vbus_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_vbus_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_FLAG);
    if (tmp_vbus_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_vbus_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbus_flag_;
} // getter






bool BQ25798Component::get_treg_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_treg_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TREG_FLAG);
    if (tmp_treg_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_treg_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return treg_flag_;
} // getter






bool BQ25798Component::get_vbat_present_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_vbat_present_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_PRESENT_FLAG);
    if (tmp_vbat_present_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_vbat_present_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbat_present_flag_;
} // getter






bool BQ25798Component::get_bc1_2_done_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG23_Charger_Flag_1\") value: 0x%02X", REG23_Charger_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_bc1_2_done_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->BC1_2_DONE_FLAG);
    if (tmp_bc1_2_done_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_bc1_2_done_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return bc1_2_done_flag_;
} // getter






bool BQ25798Component::get_dpdm_done_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_dpdm_done_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DPDM_DONE_FLAG);
    if (tmp_dpdm_done_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_dpdm_done_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dpdm_done_flag_;
} // getter






bool BQ25798Component::get_adc_done_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_adc_done_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_DONE_FLAG);
    if (tmp_adc_done_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_adc_done_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return adc_done_flag_;
} // getter






bool BQ25798Component::get_vsys_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_vsys_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_FLAG);
    if (tmp_vsys_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_vsys_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vsys_flag_;
} // getter






bool BQ25798Component::get_chg_tmr_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_chg_tmr_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CHG_TMR_FLAG);
    if (tmp_chg_tmr_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_chg_tmr_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return chg_tmr_flag_;
} // getter






bool BQ25798Component::get_trichg_tmr_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_trichg_tmr_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TRICHG_TMR_FLAG);
    if (tmp_trichg_tmr_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_trichg_tmr_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return trichg_tmr_flag_;
} // getter






bool BQ25798Component::get_prechg_tmr_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_prechg_tmr_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PRECHG_TMR_FLAG);
    if (tmp_prechg_tmr_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_prechg_tmr_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return prechg_tmr_flag_;
} // getter






bool BQ25798Component::get_topoff_tmr_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG24_Charger_Flag_2\") value: 0x%02X", REG24_Charger_Flag_2, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_topoff_tmr_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TOPOFF_TMR_FLAG);
    if (tmp_topoff_tmr_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_topoff_tmr_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return topoff_tmr_flag_;
} // getter






bool BQ25798Component::get_vbatotg_low_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_vbatotg_low_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBATOTG_LOW_FLAG);
    if (tmp_vbatotg_low_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_vbatotg_low_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbatotg_low_flag_;
} // getter






bool BQ25798Component::get_ts_cold_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_ts_cold_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_COLD_FLAG);
    if (tmp_ts_cold_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_ts_cold_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ts_cold_flag_;
} // getter






bool BQ25798Component::get_ts_cool_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_ts_cool_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_COOL_FLAG);
    if (tmp_ts_cool_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_ts_cool_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ts_cool_flag_;
} // getter






bool BQ25798Component::get_ts_warm_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_ts_warm_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_WARM_FLAG);
    if (tmp_ts_warm_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_ts_warm_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ts_warm_flag_;
} // getter






bool BQ25798Component::get_ts_hot_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG25_Charger_Flag_3\") value: 0x%02X", REG25_Charger_Flag_3, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_ts_hot_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_HOT_FLAG);
    if (tmp_ts_hot_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_ts_hot_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ts_hot_flag_;
} // getter






bool BQ25798Component::get_ibat_reg_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_ibat_reg_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_REG_FLAG);
    if (tmp_ibat_reg_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_ibat_reg_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ibat_reg_flag_;
} // getter






bool BQ25798Component::get_vbus_ovp_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_vbus_ovp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_OVP_FLAG);
    if (tmp_vbus_ovp_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_vbus_ovp_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbus_ovp_flag_;
} // getter






bool BQ25798Component::get_vbat_ovp_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_vbat_ovp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_OVP_FLAG);
    if (tmp_vbat_ovp_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_vbat_ovp_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbat_ovp_flag_;
} // getter






bool BQ25798Component::get_ibus_ocp_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_ibus_ocp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_OCP_FLAG);
    if (tmp_ibus_ocp_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_ibus_ocp_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ibus_ocp_flag_;
} // getter






bool BQ25798Component::get_ibat_ocp_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_ibat_ocp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_OCP_FLAG);
    if (tmp_ibat_ocp_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_ibat_ocp_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ibat_ocp_flag_;
} // getter






bool BQ25798Component::get_conv_ocp_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_conv_ocp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CONV_OCP_FLAG);
    if (tmp_conv_ocp_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_conv_ocp_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return conv_ocp_flag_;
} // getter






bool BQ25798Component::get_vac2_ovp_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_vac2_ovp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_OVP_FLAG);
    if (tmp_vac2_ovp_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_vac2_ovp_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vac2_ovp_flag_;
} // getter






bool BQ25798Component::get_vac1_ovp_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG26_FAULT_Flag_0\") value: 0x%02X", REG26_FAULT_Flag_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_vac1_ovp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_OVP_FLAG);
    if (tmp_vac1_ovp_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_vac1_ovp_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vac1_ovp_flag_;
} // getter






bool BQ25798Component::get_vsys_short_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_vsys_short_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_SHORT_FLAG);
    if (tmp_vsys_short_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_vsys_short_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vsys_short_flag_;
} // getter






bool BQ25798Component::get_vsys_ovp_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_vsys_ovp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_OVP_FLAG);
    if (tmp_vsys_ovp_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_vsys_ovp_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vsys_ovp_flag_;
} // getter






bool BQ25798Component::get_otg_ovp_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_otg_ovp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_OVP_FLAG);
    if (tmp_otg_ovp_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_otg_ovp_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return otg_ovp_flag_;
} // getter






bool BQ25798Component::get_otg_uvp_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_otg_uvp_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_UVP_FLAG);
    if (tmp_otg_uvp_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_otg_uvp_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return otg_uvp_flag_;
} // getter






bool BQ25798Component::get_tshut_flag(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG27_FAULT_Flag_1\") value: 0x%02X", REG27_FAULT_Flag_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    // This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them and keep them raised too
    bool tmp_tshut_flag = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TSHUT_FLAG);
    if (tmp_tshut_flag) {  // only set the flag if it is on. All the flags need to be cleared explicitly
      raise_flag_tshut_flag();
    }


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return tshut_flag_;
} // getter






bool BQ25798Component::get_adc_en(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    adc_en_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_EN);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return adc_en_;
} // getter





void BQ25798Component::on_init_set_adc_en(bool value) {
  on_init_set_adc_en_ = value;
}


void BQ25798Component::set_adc_en(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_EN to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  adc_en_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->ADC_EN);

 uint8_t reg_value;
  if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_adc_rate(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    adc_rate_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_RATE);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return adc_rate_;
} // getter
const char* BQ25798Component::get_adc_rate_string(bool read_from_i2c) {
  int value = get_adc_rate(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->ADC_RATE_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_adc_rate(bool value) {
  on_init_set_adc_rate_ = value;
}


void BQ25798Component::set_adc_rate(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_RATE to %d (<ADC_RATE_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  adc_rate_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ADC_RATE);
 uint8_t reg_value;
  if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_adc_sample(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);
    adc_sample_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_SAMPLE);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return adc_sample_;
} // getter
const char* BQ25798Component::get_adc_sample_string(bool read_from_i2c) {
  int value = get_adc_sample(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->ADC_SAMPLE_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_adc_sample(bool value) {
  on_init_set_adc_sample_ = value;
}


void BQ25798Component::set_adc_sample(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_SAMPLE to %d (<ADC_SAMPLE_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  adc_sample_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ADC_SAMPLE);
 uint8_t reg_value;
  if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
// ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_adc_avg(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    adc_avg_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_AVG);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return adc_avg_;
} // getter
const char* BQ25798Component::get_adc_avg_string(bool read_from_i2c) {
  int value = get_adc_avg(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->ADC_AVG_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_adc_avg(bool value) {
  on_init_set_adc_avg_ = value;
}


void BQ25798Component::set_adc_avg(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_AVG to %d (<ADC_AVG_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  adc_avg_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->ADC_AVG);
 uint8_t reg_value;
  if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_adc_avg_init(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    adc_avg_init_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_AVG_INIT);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return adc_avg_init_;
} // getter





void BQ25798Component::on_init_set_adc_avg_init(bool value) {
  on_init_set_adc_avg_init_ = value;
}


void BQ25798Component::set_adc_avg_init(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s ADC_AVG_INIT to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  adc_avg_init_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->ADC_AVG_INIT);

 uint8_t reg_value;
  if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2E_ADC_Control\") value: 0x%02X", REG2E_ADC_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_ibus_adc_dis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    ibus_adc_dis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_ADC_DIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ibus_adc_dis_;
} // getter





void BQ25798Component::on_init_set_ibus_adc_dis(bool value) {
  on_init_set_ibus_adc_dis_ = value;
}


void BQ25798Component::set_ibus_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IBUS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  ibus_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IBUS_ADC_DIS);

 uint8_t reg_value;
  if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_ibat_adc_dis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    ibat_adc_dis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_ADC_DIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ibat_adc_dis_;
} // getter





void BQ25798Component::on_init_set_ibat_adc_dis(bool value) {
  on_init_set_ibat_adc_dis_ = value;
}


void BQ25798Component::set_ibat_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s IBAT_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  ibat_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->IBAT_ADC_DIS);

 uint8_t reg_value;
  if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_vbus_adc_dis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    vbus_adc_dis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_ADC_DIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbus_adc_dis_;
} // getter





void BQ25798Component::on_init_set_vbus_adc_dis(bool value) {
  on_init_set_vbus_adc_dis_ = value;
}


void BQ25798Component::set_vbus_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBUS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  vbus_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBUS_ADC_DIS);

 uint8_t reg_value;
  if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_vbat_adc_dis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    vbat_adc_dis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_ADC_DIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbat_adc_dis_;
} // getter





void BQ25798Component::on_init_set_vbat_adc_dis(bool value) {
  on_init_set_vbat_adc_dis_ = value;
}


void BQ25798Component::set_vbat_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VBAT_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  vbat_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VBAT_ADC_DIS);

 uint8_t reg_value;
  if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_vsys_adc_dis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);

    vsys_adc_dis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_ADC_DIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vsys_adc_dis_;
} // getter





void BQ25798Component::on_init_set_vsys_adc_dis(bool value) {
  on_init_set_vsys_adc_dis_ = value;
}


void BQ25798Component::set_vsys_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VSYS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  vsys_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VSYS_ADC_DIS);

 uint8_t reg_value;
  if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_ts_adc_dis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);

    ts_adc_dis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_ADC_DIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ts_adc_dis_;
} // getter





void BQ25798Component::on_init_set_ts_adc_dis(bool value) {
  on_init_set_ts_adc_dis_ = value;
}


void BQ25798Component::set_ts_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  ts_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TS_ADC_DIS);

 uint8_t reg_value;
  if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_tdie_adc_dis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);

    tdie_adc_dis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TDIE_ADC_DIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return tdie_adc_dis_;
} // getter





void BQ25798Component::on_init_set_tdie_adc_dis(bool value) {
  on_init_set_tdie_adc_dis_ = value;
}


void BQ25798Component::set_tdie_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s TDIE_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  tdie_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->TDIE_ADC_DIS);

 uint8_t reg_value;
  if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG2F_ADC_Function_Disable_0\") value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_dplus_adc_dis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);

    dplus_adc_dis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DPLUS_ADC_DIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dplus_adc_dis_;
} // getter





void BQ25798Component::on_init_set_dplus_adc_dis(bool value) {
  on_init_set_dplus_adc_dis_ = value;
}


void BQ25798Component::set_dplus_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DPLUS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  dplus_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DPLUS_ADC_DIS);

 uint8_t reg_value;
  if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_dminus_adc_dis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);

    dminus_adc_dis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DMINUS_ADC_DIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dminus_adc_dis_;
} // getter





void BQ25798Component::on_init_set_dminus_adc_dis(bool value) {
  on_init_set_dminus_adc_dis_ = value;
}


void BQ25798Component::set_dminus_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DMINUS_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  dminus_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->DMINUS_ADC_DIS);

 uint8_t reg_value;
  if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_vac2_adc_dis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);

    vac2_adc_dis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_ADC_DIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vac2_adc_dis_;
} // getter





void BQ25798Component::on_init_set_vac2_adc_dis(bool value) {
  on_init_set_vac2_adc_dis_ = value;
}


void BQ25798Component::set_vac2_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC2_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  vac2_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC2_ADC_DIS);

 uint8_t reg_value;
  if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


bool BQ25798Component::get_vac1_adc_dis(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);

    vac1_adc_dis_ = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_ADC_DIS);


    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vac1_adc_dis_;
} // getter





void BQ25798Component::on_init_set_vac1_adc_dis(bool value) {
  on_init_set_vac1_adc_dis_ = value;
}


void BQ25798Component::set_vac1_adc_dis(bool value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s VAC1_ADC_DIS to %s", _write ? "Setting and writing" : "Will eventually set", value ? "true" : "false");
  vac1_adc_dis_ = value;
  if (_write) {
    uint16_t raw_value = this->bq25798_noi2c->boolToRaw(value, this->bq25798_noi2c->VAC1_ADC_DIS);

 uint8_t reg_value;
  if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG30_ADC_Function_Disable_1\") value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
// ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_ibus_adc(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG31_IBUS_ADC, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    ibus_adc_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBUS_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ibus_adc_;
} // getter






int BQ25798Component::get_ibat_adc(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG33_IBAT_ADC, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    ibat_adc_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBAT_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ibat_adc_;
} // getter






int BQ25798Component::get_vbus_adc(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG35_VBUS_ADC, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    vbus_adc_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbus_adc_;
} // getter






int BQ25798Component::get_vac1_adc(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG37_VAC1_ADC, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    vac1_adc_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC1_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vac1_adc_;
} // getter






int BQ25798Component::get_vac2_adc(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG39_VAC2_ADC, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    vac2_adc_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC2_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vac2_adc_;
} // getter






int BQ25798Component::get_vbat_adc(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG3B_VBAT_ADC, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    vbat_adc_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vbat_adc_;
} // getter






int BQ25798Component::get_vsys_adc(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG3D_VSYS_ADC, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    vsys_adc_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYS_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return vsys_adc_;
} // getter






float BQ25798Component::get_ts_adc(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG3F_TS_ADC, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    ts_adc_ = this->bq25798_noi2c->rawToFloat(raw_value, this->bq25798_noi2c->TS_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return ts_adc_;
} // getter






float BQ25798Component::get_tdie_adc(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG41_TDIE_ADC, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    tdie_adc_ = this->bq25798_noi2c->rawToFloat(raw_value, this->bq25798_noi2c->TDIE_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return tdie_adc_;
} // getter






int BQ25798Component::get_dplus_adc(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG43_DPLUS_ADC, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    dplus_adc_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPLUS_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dplus_adc_;
} // getter






int BQ25798Component::get_dminus_adc(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG45_DMINUS_ADC, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    dminus_adc_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DMINUS_ADC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dminus_adc_;
} // getter






int BQ25798Component::get_dplus_dac(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG47_DPDM_Driver\") value: 0x%02X", REG47_DPDM_Driver, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);
    dplus_dac_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPLUS_DAC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dplus_dac_;
} // getter
const char* BQ25798Component::get_dplus_dac_string(bool read_from_i2c) {
  int value = get_dplus_dac(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->DPLUS_DAC_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_dplus_dac(bool value) {
  on_init_set_dplus_dac_ = value;
}


void BQ25798Component::set_dplus_dac(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DPLUS_DAC to %d (<DPLUS_DAC_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  dplus_dac_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->DPLUS_DAC);
 uint8_t reg_value;
  if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG47_DPDM_Driver\") value: 0x%02X", REG47_DPDM_Driver, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
// ESP_LOGD(TAG, "  masked (3 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG47_DPDM_Driver, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_dminus_dac(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG47_DPDM_Driver\") value: 0x%02X", REG47_DPDM_Driver, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (3 bits) raw value: 0x%04X", raw_value);
    dminus_dac_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DMINUS_DAC);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dminus_dac_;
} // getter
const char* BQ25798Component::get_dminus_dac_string(bool read_from_i2c) {
  int value = get_dminus_dac(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->DMINUS_DAC_strings);  // not nice, should not access toString() and strings array directly
}





void BQ25798Component::on_init_set_dminus_dac(bool value) {
  on_init_set_dminus_dac_ = value;
}


void BQ25798Component::set_dminus_dac(int value, bool write_to_i2c) {
  bool _write = write_to_i2c && this->bq25798_noi2c != nullptr;
  ESP_LOGD(TAG, "%s DMINUS_DAC to %d (<DMINUS_DAC_t>)", _write ? "Setting and writing" : "Will eventually set", value);
  dminus_dac_ = value;
  if (_write) {
    uint8_t raw_value = this->bq25798_noi2c->intToRaw(value, this->bq25798_noi2c->DMINUS_DAC);
 uint8_t reg_value;
  if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
    this->mark_failed();
    return;
  }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG47_DPDM_Driver\") value: 0x%02X", REG47_DPDM_Driver, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 2);
// ESP_LOGD(TAG, "  masked (3 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 2);
// ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);
  if (!this->write_byte(REG47_DPDM_Driver, reg_value)) {
    this->mark_failed();
  }
  } // if (_write)
};  // function end


int BQ25798Component::get_pn(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG48_Part_Information, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG48_Part_Information\") value: 0x%02X", REG48_Part_Information, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (3 bits) raw value: 0x%04X", raw_value);
    pn_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PN);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return pn_;
} // getter
const char* BQ25798Component::get_pn_string(bool read_from_i2c) {
  int value = get_pn(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->PN_strings);  // not nice, should not access toString() and strings array directly
}






int BQ25798Component::get_dev_rev(bool read_from_i2c) {

  if (read_from_i2c && this->bq25798_noi2c != nullptr) {
    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG48_Part_Information, &reg_value)) {
      this->mark_failed();
    }
// ESP_LOGD(TAG, "  received raw 8-bit register %02X (\"REG48_Part_Information\") value: 0x%02X", REG48_Part_Information, reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (3 bits) raw value: 0x%04X", raw_value);
    dev_rev_ = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DEV_REV);

    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
    }
  }

  return dev_rev_;
} // getter
const char* BQ25798Component::get_dev_rev_string(bool read_from_i2c) {
  int value = get_dev_rev(read_from_i2c);
  return this->bq25798_noi2c->toString(value, this->bq25798_noi2c->DEV_REV_strings);  // not nice, should not access toString() and strings array directly
}





}  // namespace bq25798
}  // namespace esphome