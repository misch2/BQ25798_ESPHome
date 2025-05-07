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

  // FIXME reset the chip?

  uint8_t reg_value;
  if (!this->read_byte(REG00_Minimal_System_Voltage, &reg_value)) {
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
  if (this->vsysmin_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vsysmin_sensor_ from I2C register REG00_Minimal_System_Voltage...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG00_Minimal_System_Voltage, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(6);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (6 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYSMIN);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vsysmin_sensor_ != nullptr) {
      this->vsysmin_sensor_->publish_state(value);
    }
  }


  if (this->vreg_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vreg_sensor_ from I2C register REG01_Charge_Voltage_Limit...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG01_Charge_Voltage_Limit, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(11);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (11 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VREG);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vreg_sensor_ != nullptr) {
      this->vreg_sensor_->publish_state(value);
    }
  }


  if (this->ichg_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ichg_sensor_ from I2C register REG03_Charge_Current_Limit...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG03_Charge_Current_Limit, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(9);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (9 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICHG);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ichg_sensor_ != nullptr) {
      this->ichg_sensor_->publish_state(value);
    }
  }


  if (this->vindpm_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vindpm_sensor_ from I2C register REG05_Input_Voltage_Limit...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG05_Input_Voltage_Limit, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(8);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (8 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VINDPM);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vindpm_sensor_ != nullptr) {
      this->vindpm_sensor_->publish_state(value);
    }
  }


  if (this->iindpm_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->iindpm_sensor_ from I2C register REG06_Input_Current_Limit...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG06_Input_Current_Limit, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(9);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (9 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IINDPM);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->iindpm_sensor_ != nullptr) {
      this->iindpm_sensor_->publish_state(value);
    }
  }


  if (this->vbat_lowv_sensor_ != nullptr || this->vbat_lowv_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbat_lowv_sensor_ and/or this->vbat_lowv_text_sensor_ from I2C register REG08_Precharge_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBAT_LOWV);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbat_lowv_text_sensor_ != nullptr) {
      this->vbat_lowv_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_LOWV);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbat_lowv_sensor_ != nullptr) {
      this->vbat_lowv_sensor_->publish_state(value);
    }
  }


  if (this->iprechg_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->iprechg_sensor_ from I2C register REG08_Precharge_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(6);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (6 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IPRECHG);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->iprechg_sensor_ != nullptr) {
      this->iprechg_sensor_->publish_state(value);
    }
  }


  if (this->reg_rst_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->reg_rst_binary_sensor_ from I2C register REG09_Termination_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->REG_RST);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->reg_rst_binary_sensor_ != nullptr) {
      this->reg_rst_binary_sensor_->publish_state(value);
    }
  }


  if (this->stop_wd_chg_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->stop_wd_chg_binary_sensor_ from I2C register REG09_Termination_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->STOP_WD_CHG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->stop_wd_chg_binary_sensor_ != nullptr) {
      this->stop_wd_chg_binary_sensor_->publish_state(value);
    }
  }


  if (this->iterm_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->iterm_sensor_ from I2C register REG09_Termination_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(5);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (5 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ITERM);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->iterm_sensor_ != nullptr) {
      this->iterm_sensor_->publish_state(value);
    }
  }


  if (this->cell_sensor_ != nullptr || this->cell_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->cell_sensor_ and/or this->cell_text_sensor_ from I2C register REG0A_Recharge_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->CELL);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->cell_text_sensor_ != nullptr) {
      this->cell_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CELL);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->cell_sensor_ != nullptr) {
      this->cell_sensor_->publish_state(value);
    }
  }


  if (this->trechg_sensor_ != nullptr || this->trechg_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->trechg_sensor_ and/or this->trechg_text_sensor_ from I2C register REG0A_Recharge_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TRECHG);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->trechg_text_sensor_ != nullptr) {
      this->trechg_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TRECHG);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->trechg_sensor_ != nullptr) {
      this->trechg_sensor_->publish_state(value);
    }
  }


  if (this->vrechg_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vrechg_sensor_ from I2C register REG0A_Recharge_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(4);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (4 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VRECHG);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vrechg_sensor_ != nullptr) {
      this->vrechg_sensor_->publish_state(value);
    }
  }


  if (this->votg_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->votg_sensor_ from I2C register REG0B_VOTG_regulation...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG0B_VOTG_regulation, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(11);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (11 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOTG);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->votg_sensor_ != nullptr) {
      this->votg_sensor_->publish_state(value);
    }
  }


  if (this->prechg_tmr_sensor_ != nullptr || this->prechg_tmr_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->prechg_tmr_sensor_ and/or this->prechg_tmr_text_sensor_ from I2C register REG0D_IOTG_regulation...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PRECHG_TMR);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->prechg_tmr_text_sensor_ != nullptr) {
      this->prechg_tmr_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PRECHG_TMR);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->prechg_tmr_sensor_ != nullptr) {
      this->prechg_tmr_sensor_->publish_state(value);
    }
  }


  if (this->iotg_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->iotg_sensor_ from I2C register REG0D_IOTG_regulation...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(7);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (7 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IOTG);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->iotg_sensor_ != nullptr) {
      this->iotg_sensor_->publish_state(value);
    }
  }


  if (this->topoff_tmr_sensor_ != nullptr || this->topoff_tmr_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->topoff_tmr_sensor_ and/or this->topoff_tmr_text_sensor_ from I2C register REG0E_Timer_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TOPOFF_TMR);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->topoff_tmr_text_sensor_ != nullptr) {
      this->topoff_tmr_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TOPOFF_TMR);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->topoff_tmr_sensor_ != nullptr) {
      this->topoff_tmr_sensor_->publish_state(value);
    }
  }


  if (this->en_trichg_tmr_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_trichg_tmr_binary_sensor_ from I2C register REG0E_Timer_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_TRICHG_TMR);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_trichg_tmr_binary_sensor_ != nullptr) {
      this->en_trichg_tmr_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_prechg_tmr_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_prechg_tmr_binary_sensor_ from I2C register REG0E_Timer_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_PRECHG_TMR);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_prechg_tmr_binary_sensor_ != nullptr) {
      this->en_prechg_tmr_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_chg_tmr_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_chg_tmr_binary_sensor_ from I2C register REG0E_Timer_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_CHG_TMR);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_chg_tmr_binary_sensor_ != nullptr) {
      this->en_chg_tmr_binary_sensor_->publish_state(value);
    }
  }


  if (this->chg_tmr_sensor_ != nullptr || this->chg_tmr_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->chg_tmr_sensor_ and/or this->chg_tmr_text_sensor_ from I2C register REG0E_Timer_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->CHG_TMR);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->chg_tmr_text_sensor_ != nullptr) {
      this->chg_tmr_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_TMR);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->chg_tmr_sensor_ != nullptr) {
      this->chg_tmr_sensor_->publish_state(value);
    }
  }


  if (this->tmr2x_en_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->tmr2x_en_binary_sensor_ from I2C register REG0E_Timer_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TMR2X_EN);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->tmr2x_en_binary_sensor_ != nullptr) {
      this->tmr2x_en_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_auto_ibatdis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_auto_ibatdis_binary_sensor_ from I2C register REG0F_Charger_Control_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_AUTO_IBATDIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_auto_ibatdis_binary_sensor_ != nullptr) {
      this->en_auto_ibatdis_binary_sensor_->publish_state(value);
    }
  }


  if (this->force_ibatdis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->force_ibatdis_binary_sensor_ from I2C register REG0F_Charger_Control_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_IBATDIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->force_ibatdis_binary_sensor_ != nullptr) {
      this->force_ibatdis_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_chg_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_chg_binary_sensor_ from I2C register REG0F_Charger_Control_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_CHG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_chg_binary_sensor_ != nullptr) {
      this->en_chg_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_ico_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_ico_binary_sensor_ from I2C register REG0F_Charger_Control_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ICO);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_ico_binary_sensor_ != nullptr) {
      this->en_ico_binary_sensor_->publish_state(value);
    }
  }


  if (this->force_ico_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->force_ico_binary_sensor_ from I2C register REG0F_Charger_Control_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_ICO);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->force_ico_binary_sensor_ != nullptr) {
      this->force_ico_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_hiz_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_hiz_binary_sensor_ from I2C register REG0F_Charger_Control_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_HIZ);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_hiz_binary_sensor_ != nullptr) {
      this->en_hiz_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_term_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_term_binary_sensor_ from I2C register REG0F_Charger_Control_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_TERM);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_term_binary_sensor_ != nullptr) {
      this->en_term_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_backup_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_backup_binary_sensor_ from I2C register REG0F_Charger_Control_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG0F_Charger_Control_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_BACKUP);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_backup_binary_sensor_ != nullptr) {
      this->en_backup_binary_sensor_->publish_state(value);
    }
  }


  if (this->vbus_backup_sensor_ != nullptr || this->vbus_backup_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbus_backup_sensor_ and/or this->vbus_backup_text_sensor_ from I2C register REG10_Charger_Control_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBUS_BACKUP);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbus_backup_text_sensor_ != nullptr) {
      this->vbus_backup_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_BACKUP);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbus_backup_sensor_ != nullptr) {
      this->vbus_backup_sensor_->publish_state(value);
    }
  }


  if (this->vac_ovp_sensor_ != nullptr || this->vac_ovp_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vac_ovp_sensor_ and/or this->vac_ovp_text_sensor_ from I2C register REG10_Charger_Control_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VAC_OVP);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vac_ovp_text_sensor_ != nullptr) {
      this->vac_ovp_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC_OVP);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vac_ovp_sensor_ != nullptr) {
      this->vac_ovp_sensor_->publish_state(value);
    }
  }


  if (this->wd_rst_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->wd_rst_binary_sensor_ from I2C register REG10_Charger_Control_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->WD_RST);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->wd_rst_binary_sensor_ != nullptr) {
      this->wd_rst_binary_sensor_->publish_state(value);
    }
  }


  if (this->watchdog_sensor_ != nullptr || this->watchdog_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->watchdog_sensor_ and/or this->watchdog_text_sensor_ from I2C register REG10_Charger_Control_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (3 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->WATCHDOG);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->watchdog_text_sensor_ != nullptr) {
      this->watchdog_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WATCHDOG);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->watchdog_sensor_ != nullptr) {
      this->watchdog_sensor_->publish_state(value);
    }
  }


  if (this->force_indet_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->force_indet_binary_sensor_ from I2C register REG11_Charger_Control_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_INDET);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->force_indet_binary_sensor_ != nullptr) {
      this->force_indet_binary_sensor_->publish_state(value);
    }
  }


  if (this->auto_indet_en_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->auto_indet_en_binary_sensor_ from I2C register REG11_Charger_Control_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AUTO_INDET_EN);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->auto_indet_en_binary_sensor_ != nullptr) {
      this->auto_indet_en_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_12v_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_12v_binary_sensor_ from I2C register REG11_Charger_Control_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_12V);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_12v_binary_sensor_ != nullptr) {
      this->en_12v_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_9v_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_9v_binary_sensor_ from I2C register REG11_Charger_Control_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_9V);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_9v_binary_sensor_ != nullptr) {
      this->en_9v_binary_sensor_->publish_state(value);
    }
  }


  if (this->hvdcp_en_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->hvdcp_en_binary_sensor_ from I2C register REG11_Charger_Control_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->HVDCP_EN);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->hvdcp_en_binary_sensor_ != nullptr) {
      this->hvdcp_en_binary_sensor_->publish_state(value);
    }
  }


  if (this->sdrv_ctrl_sensor_ != nullptr || this->sdrv_ctrl_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->sdrv_ctrl_sensor_ and/or this->sdrv_ctrl_text_sensor_ from I2C register REG11_Charger_Control_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->SDRV_CTRL);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->sdrv_ctrl_text_sensor_ != nullptr) {
      this->sdrv_ctrl_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->SDRV_CTRL);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->sdrv_ctrl_sensor_ != nullptr) {
      this->sdrv_ctrl_sensor_->publish_state(value);
    }
  }


  if (this->sdrv_dly_sensor_ != nullptr || this->sdrv_dly_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->sdrv_dly_sensor_ and/or this->sdrv_dly_text_sensor_ from I2C register REG11_Charger_Control_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->SDRV_DLY);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->sdrv_dly_text_sensor_ != nullptr) {
      this->sdrv_dly_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->SDRV_DLY);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->sdrv_dly_sensor_ != nullptr) {
      this->sdrv_dly_sensor_->publish_state(value);
    }
  }


  if (this->dis_acdrv_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dis_acdrv_binary_sensor_ from I2C register REG12_Charger_Control_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_ACDRV);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dis_acdrv_binary_sensor_ != nullptr) {
      this->dis_acdrv_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_otg_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_otg_binary_sensor_ from I2C register REG12_Charger_Control_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_OTG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_otg_binary_sensor_ != nullptr) {
      this->en_otg_binary_sensor_->publish_state(value);
    }
  }


  if (this->pfm_otg_dis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->pfm_otg_dis_binary_sensor_ from I2C register REG12_Charger_Control_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PFM_OTG_DIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->pfm_otg_dis_binary_sensor_ != nullptr) {
      this->pfm_otg_dis_binary_sensor_->publish_state(value);
    }
  }


  if (this->pfm_fwd_dis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->pfm_fwd_dis_binary_sensor_ from I2C register REG12_Charger_Control_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PFM_FWD_DIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->pfm_fwd_dis_binary_sensor_ != nullptr) {
      this->pfm_fwd_dis_binary_sensor_->publish_state(value);
    }
  }


  if (this->wkup_dly_sensor_ != nullptr || this->wkup_dly_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->wkup_dly_sensor_ and/or this->wkup_dly_text_sensor_ from I2C register REG12_Charger_Control_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->WKUP_DLY);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->wkup_dly_text_sensor_ != nullptr) {
      this->wkup_dly_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WKUP_DLY);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->wkup_dly_sensor_ != nullptr) {
      this->wkup_dly_sensor_->publish_state(value);
    }
  }


  if (this->dis_ldo_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dis_ldo_binary_sensor_ from I2C register REG12_Charger_Control_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_LDO);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dis_ldo_binary_sensor_ != nullptr) {
      this->dis_ldo_binary_sensor_->publish_state(value);
    }
  }


  if (this->dis_otg_ooa_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dis_otg_ooa_binary_sensor_ from I2C register REG12_Charger_Control_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_OTG_OOA);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dis_otg_ooa_binary_sensor_ != nullptr) {
      this->dis_otg_ooa_binary_sensor_->publish_state(value);
    }
  }


  if (this->dis_fwd_ooa_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dis_fwd_ooa_binary_sensor_ from I2C register REG12_Charger_Control_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_FWD_OOA);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dis_fwd_ooa_binary_sensor_ != nullptr) {
      this->dis_fwd_ooa_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_acdrv2_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_acdrv2_binary_sensor_ from I2C register REG13_Charger_Control_4...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ACDRV2);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_acdrv2_binary_sensor_ != nullptr) {
      this->en_acdrv2_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_acdrv1_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_acdrv1_binary_sensor_ from I2C register REG13_Charger_Control_4...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_ACDRV1);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_acdrv1_binary_sensor_ != nullptr) {
      this->en_acdrv1_binary_sensor_->publish_state(value);
    }
  }


  if (this->pwm_freq_sensor_ != nullptr || this->pwm_freq_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->pwm_freq_sensor_ and/or this->pwm_freq_text_sensor_ from I2C register REG13_Charger_Control_4...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PWM_FREQ);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->pwm_freq_text_sensor_ != nullptr) {
      this->pwm_freq_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PWM_FREQ);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->pwm_freq_sensor_ != nullptr) {
      this->pwm_freq_sensor_->publish_state(value);
    }
  }


  if (this->dis_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dis_stat_binary_sensor_ from I2C register REG13_Charger_Control_4...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dis_stat_binary_sensor_ != nullptr) {
      this->dis_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->dis_vsys_short_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dis_vsys_short_binary_sensor_ from I2C register REG13_Charger_Control_4...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_VSYS_SHORT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dis_vsys_short_binary_sensor_ != nullptr) {
      this->dis_vsys_short_binary_sensor_->publish_state(value);
    }
  }


  if (this->dis_votg_uvp_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dis_votg_uvp_binary_sensor_ from I2C register REG13_Charger_Control_4...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DIS_VOTG_UVP);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dis_votg_uvp_binary_sensor_ != nullptr) {
      this->dis_votg_uvp_binary_sensor_->publish_state(value);
    }
  }


  if (this->force_vindpm_det_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->force_vindpm_det_binary_sensor_ from I2C register REG13_Charger_Control_4...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->FORCE_VINDPM_DET);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->force_vindpm_det_binary_sensor_ != nullptr) {
      this->force_vindpm_det_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_ibus_ocp_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_ibus_ocp_binary_sensor_ from I2C register REG13_Charger_Control_4...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IBUS_OCP);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_ibus_ocp_binary_sensor_ != nullptr) {
      this->en_ibus_ocp_binary_sensor_->publish_state(value);
    }
  }


  if (this->sfet_present_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->sfet_present_binary_sensor_ from I2C register REG14_Charger_Control_5...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->SFET_PRESENT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->sfet_present_binary_sensor_ != nullptr) {
      this->sfet_present_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_ibat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_ibat_binary_sensor_ from I2C register REG14_Charger_Control_5...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IBAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_ibat_binary_sensor_ != nullptr) {
      this->en_ibat_binary_sensor_->publish_state(value);
    }
  }


  if (this->ibat_reg_sensor_ != nullptr || this->ibat_reg_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ibat_reg_sensor_ and/or this->ibat_reg_text_sensor_ from I2C register REG14_Charger_Control_5...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->IBAT_REG);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ibat_reg_text_sensor_ != nullptr) {
      this->ibat_reg_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBAT_REG);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ibat_reg_sensor_ != nullptr) {
      this->ibat_reg_sensor_->publish_state(value);
    }
  }


  if (this->en_iindpm_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_iindpm_binary_sensor_ from I2C register REG14_Charger_Control_5...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_IINDPM);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_iindpm_binary_sensor_ != nullptr) {
      this->en_iindpm_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_extilim_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_extilim_binary_sensor_ from I2C register REG14_Charger_Control_5...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_EXTILIM);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_extilim_binary_sensor_ != nullptr) {
      this->en_extilim_binary_sensor_->publish_state(value);
    }
  }


  if (this->en_batoc_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_batoc_binary_sensor_ from I2C register REG14_Charger_Control_5...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_BATOC);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_batoc_binary_sensor_ != nullptr) {
      this->en_batoc_binary_sensor_->publish_state(value);
    }
  }


  if (this->voc_pct_sensor_ != nullptr || this->voc_pct_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->voc_pct_sensor_ and/or this->voc_pct_text_sensor_ from I2C register REG15_MPPT_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VOC_PCT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->voc_pct_text_sensor_ != nullptr) {
      this->voc_pct_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_PCT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->voc_pct_sensor_ != nullptr) {
      this->voc_pct_sensor_->publish_state(value);
    }
  }


  if (this->voc_dly_sensor_ != nullptr || this->voc_dly_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->voc_dly_sensor_ and/or this->voc_dly_text_sensor_ from I2C register REG15_MPPT_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VOC_DLY);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->voc_dly_text_sensor_ != nullptr) {
      this->voc_dly_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_DLY);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->voc_dly_sensor_ != nullptr) {
      this->voc_dly_sensor_->publish_state(value);
    }
  }


  if (this->voc_rate_sensor_ != nullptr || this->voc_rate_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->voc_rate_sensor_ and/or this->voc_rate_text_sensor_ from I2C register REG15_MPPT_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VOC_RATE);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->voc_rate_text_sensor_ != nullptr) {
      this->voc_rate_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VOC_RATE);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->voc_rate_sensor_ != nullptr) {
      this->voc_rate_sensor_->publish_state(value);
    }
  }


  if (this->en_mppt_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->en_mppt_binary_sensor_ from I2C register REG15_MPPT_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->EN_MPPT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->en_mppt_binary_sensor_ != nullptr) {
      this->en_mppt_binary_sensor_->publish_state(value);
    }
  }


  if (this->treg_sensor_ != nullptr || this->treg_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->treg_sensor_ and/or this->treg_text_sensor_ from I2C register REG16_Temperature_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TREG);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->treg_text_sensor_ != nullptr) {
      this->treg_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TREG);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->treg_sensor_ != nullptr) {
      this->treg_sensor_->publish_state(value);
    }
  }


  if (this->tshut_sensor_ != nullptr || this->tshut_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->tshut_sensor_ and/or this->tshut_text_sensor_ from I2C register REG16_Temperature_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TSHUT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->tshut_text_sensor_ != nullptr) {
      this->tshut_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TSHUT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->tshut_sensor_ != nullptr) {
      this->tshut_sensor_->publish_state(value);
    }
  }


  if (this->vbus_pd_en_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbus_pd_en_binary_sensor_ from I2C register REG16_Temperature_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_PD_EN);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbus_pd_en_binary_sensor_ != nullptr) {
      this->vbus_pd_en_binary_sensor_->publish_state(value);
    }
  }


  if (this->vac1_pd_en_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vac1_pd_en_binary_sensor_ from I2C register REG16_Temperature_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_PD_EN);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vac1_pd_en_binary_sensor_ != nullptr) {
      this->vac1_pd_en_binary_sensor_->publish_state(value);
    }
  }


  if (this->vac2_pd_en_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vac2_pd_en_binary_sensor_ from I2C register REG16_Temperature_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_PD_EN);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vac2_pd_en_binary_sensor_ != nullptr) {
      this->vac2_pd_en_binary_sensor_->publish_state(value);
    }
  }


  if (this->bkup_acfet1_on_sensor_ != nullptr || this->bkup_acfet1_on_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->bkup_acfet1_on_sensor_ and/or this->bkup_acfet1_on_text_sensor_ from I2C register REG16_Temperature_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->BKUP_ACFET1_ON);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->bkup_acfet1_on_text_sensor_ != nullptr) {
      this->bkup_acfet1_on_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BKUP_ACFET1_ON);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->bkup_acfet1_on_sensor_ != nullptr) {
      this->bkup_acfet1_on_sensor_->publish_state(value);
    }
  }


  if (this->jeita_vset_sensor_ != nullptr || this->jeita_vset_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->jeita_vset_sensor_ and/or this->jeita_vset_text_sensor_ from I2C register REG17_NTC_Control_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->JEITA_VSET);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->jeita_vset_text_sensor_ != nullptr) {
      this->jeita_vset_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_VSET);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->jeita_vset_sensor_ != nullptr) {
      this->jeita_vset_sensor_->publish_state(value);
    }
  }


  if (this->jeita_iseth_sensor_ != nullptr || this->jeita_iseth_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->jeita_iseth_sensor_ and/or this->jeita_iseth_text_sensor_ from I2C register REG17_NTC_Control_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->JEITA_ISETH);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->jeita_iseth_text_sensor_ != nullptr) {
      this->jeita_iseth_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_ISETH);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->jeita_iseth_sensor_ != nullptr) {
      this->jeita_iseth_sensor_->publish_state(value);
    }
  }


  if (this->jeita_isetc_sensor_ != nullptr || this->jeita_isetc_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->jeita_isetc_sensor_ and/or this->jeita_isetc_text_sensor_ from I2C register REG17_NTC_Control_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->JEITA_ISETC);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->jeita_isetc_text_sensor_ != nullptr) {
      this->jeita_isetc_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->JEITA_ISETC);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->jeita_isetc_sensor_ != nullptr) {
      this->jeita_isetc_sensor_->publish_state(value);
    }
  }


  if (this->ts_cool_sensor_ != nullptr || this->ts_cool_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ts_cool_sensor_ and/or this->ts_cool_text_sensor_ from I2C register REG18_NTC_Control_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_COOL);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_cool_text_sensor_ != nullptr) {
      this->ts_cool_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COOL);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_cool_sensor_ != nullptr) {
      this->ts_cool_sensor_->publish_state(value);
    }
  }


  if (this->ts_warm_sensor_ != nullptr || this->ts_warm_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ts_warm_sensor_ and/or this->ts_warm_text_sensor_ from I2C register REG18_NTC_Control_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_WARM);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_warm_text_sensor_ != nullptr) {
      this->ts_warm_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_WARM);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_warm_sensor_ != nullptr) {
      this->ts_warm_sensor_->publish_state(value);
    }
  }


  if (this->bhot_sensor_ != nullptr || this->bhot_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->bhot_sensor_ and/or this->bhot_text_sensor_ from I2C register REG18_NTC_Control_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->BHOT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->bhot_text_sensor_ != nullptr) {
      this->bhot_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BHOT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->bhot_sensor_ != nullptr) {
      this->bhot_sensor_->publish_state(value);
    }
  }


  if (this->bcold_sensor_ != nullptr || this->bcold_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->bcold_sensor_ and/or this->bcold_text_sensor_ from I2C register REG18_NTC_Control_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->BCOLD);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->bcold_text_sensor_ != nullptr) {
      this->bcold_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->BCOLD);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->bcold_sensor_ != nullptr) {
      this->bcold_sensor_->publish_state(value);
    }
  }


  if (this->ts_ignore_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ts_ignore_binary_sensor_ from I2C register REG18_NTC_Control_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_IGNORE);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_ignore_binary_sensor_ != nullptr) {
      this->ts_ignore_binary_sensor_->publish_state(value);
    }
  }


  if (this->ico_ilim_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ico_ilim_sensor_ from I2C register REG19_ICO_Current_Limit...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG19_ICO_Current_Limit, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(9);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (9 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICO_ILIM);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ico_ilim_sensor_ != nullptr) {
      this->ico_ilim_sensor_->publish_state(value);
    }
  }


  if (this->iindpm_stat_sensor_ != nullptr || this->iindpm_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->iindpm_stat_sensor_ and/or this->iindpm_stat_text_sensor_ from I2C register REG1B_Charger_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->IINDPM_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->iindpm_stat_text_sensor_ != nullptr) {
      this->iindpm_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IINDPM_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->iindpm_stat_sensor_ != nullptr) {
      this->iindpm_stat_sensor_->publish_state(value);
    }
  }


  if (this->vindpm_stat_sensor_ != nullptr || this->vindpm_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vindpm_stat_sensor_ and/or this->vindpm_stat_text_sensor_ from I2C register REG1B_Charger_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VINDPM_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vindpm_stat_text_sensor_ != nullptr) {
      this->vindpm_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VINDPM_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vindpm_stat_sensor_ != nullptr) {
      this->vindpm_stat_sensor_->publish_state(value);
    }
  }


  if (this->wd_stat_sensor_ != nullptr || this->wd_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->wd_stat_sensor_ and/or this->wd_stat_text_sensor_ from I2C register REG1B_Charger_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->WD_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->wd_stat_text_sensor_ != nullptr) {
      this->wd_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->WD_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->wd_stat_sensor_ != nullptr) {
      this->wd_stat_sensor_->publish_state(value);
    }
  }


  if (this->pg_stat_sensor_ != nullptr || this->pg_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->pg_stat_sensor_ and/or this->pg_stat_text_sensor_ from I2C register REG1B_Charger_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PG_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->pg_stat_text_sensor_ != nullptr) {
      this->pg_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PG_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->pg_stat_sensor_ != nullptr) {
      this->pg_stat_sensor_->publish_state(value);
    }
  }


  if (this->ac2_present_stat_sensor_ != nullptr || this->ac2_present_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ac2_present_stat_sensor_ and/or this->ac2_present_stat_text_sensor_ from I2C register REG1B_Charger_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->AC2_PRESENT_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ac2_present_stat_text_sensor_ != nullptr) {
      this->ac2_present_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->AC2_PRESENT_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ac2_present_stat_sensor_ != nullptr) {
      this->ac2_present_stat_sensor_->publish_state(value);
    }
  }


  if (this->ac1_present_stat_sensor_ != nullptr || this->ac1_present_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ac1_present_stat_sensor_ and/or this->ac1_present_stat_text_sensor_ from I2C register REG1B_Charger_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->AC1_PRESENT_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ac1_present_stat_text_sensor_ != nullptr) {
      this->ac1_present_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->AC1_PRESENT_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ac1_present_stat_sensor_ != nullptr) {
      this->ac1_present_stat_sensor_->publish_state(value);
    }
  }


  if (this->vbus_present_stat_sensor_ != nullptr || this->vbus_present_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbus_present_stat_sensor_ and/or this->vbus_present_stat_text_sensor_ from I2C register REG1B_Charger_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1B_Charger_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBUS_PRESENT_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbus_present_stat_text_sensor_ != nullptr) {
      this->vbus_present_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_PRESENT_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbus_present_stat_sensor_ != nullptr) {
      this->vbus_present_stat_sensor_->publish_state(value);
    }
  }


  if (this->chg_stat_sensor_ != nullptr || this->chg_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->chg_stat_sensor_ and/or this->chg_stat_text_sensor_ from I2C register REG1C_Charger_Status_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->CHG_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->chg_stat_text_sensor_ != nullptr) {
      this->chg_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->chg_stat_sensor_ != nullptr) {
      this->chg_stat_sensor_->publish_state(value);
    }
  }


  if (this->vbus_stat_sensor_ != nullptr || this->vbus_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbus_stat_sensor_ and/or this->vbus_stat_text_sensor_ from I2C register REG1C_Charger_Status_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(4);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (4 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBUS_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbus_stat_text_sensor_ != nullptr) {
      this->vbus_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbus_stat_sensor_ != nullptr) {
      this->vbus_stat_sensor_->publish_state(value);
    }
  }


  if (this->bc12_done_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->bc12_done_stat_binary_sensor_ from I2C register REG1C_Charger_Status_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1C_Charger_Status_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->BC12_DONE_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->bc12_done_stat_binary_sensor_ != nullptr) {
      this->bc12_done_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->ico_stat_sensor_ != nullptr || this->ico_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ico_stat_sensor_ and/or this->ico_stat_text_sensor_ from I2C register REG1D_Charger_Status_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->ICO_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ico_stat_text_sensor_ != nullptr) {
      this->ico_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ICO_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ico_stat_sensor_ != nullptr) {
      this->ico_stat_sensor_->publish_state(value);
    }
  }


  if (this->treg_stat_sensor_ != nullptr || this->treg_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->treg_stat_sensor_ and/or this->treg_stat_text_sensor_ from I2C register REG1D_Charger_Status_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TREG_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->treg_stat_text_sensor_ != nullptr) {
      this->treg_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TREG_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->treg_stat_sensor_ != nullptr) {
      this->treg_stat_sensor_->publish_state(value);
    }
  }


  if (this->dpdm_stat_sensor_ != nullptr || this->dpdm_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dpdm_stat_sensor_ and/or this->dpdm_stat_text_sensor_ from I2C register REG1D_Charger_Status_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->DPDM_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dpdm_stat_text_sensor_ != nullptr) {
      this->dpdm_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPDM_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dpdm_stat_sensor_ != nullptr) {
      this->dpdm_stat_sensor_->publish_state(value);
    }
  }


  if (this->vbat_present_stat_sensor_ != nullptr || this->vbat_present_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbat_present_stat_sensor_ and/or this->vbat_present_stat_text_sensor_ from I2C register REG1D_Charger_Status_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1D_Charger_Status_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBAT_PRESENT_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbat_present_stat_text_sensor_ != nullptr) {
      this->vbat_present_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_PRESENT_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbat_present_stat_sensor_ != nullptr) {
      this->vbat_present_stat_sensor_->publish_state(value);
    }
  }


  if (this->acrb2_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->acrb2_stat_binary_sensor_ from I2C register REG1E_Charger_Status_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ACRB2_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->acrb2_stat_binary_sensor_ != nullptr) {
      this->acrb2_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->acrb1_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->acrb1_stat_binary_sensor_ from I2C register REG1E_Charger_Status_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ACRB1_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->acrb1_stat_binary_sensor_ != nullptr) {
      this->acrb1_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->adc_done_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->adc_done_stat_binary_sensor_ from I2C register REG1E_Charger_Status_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_DONE_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->adc_done_stat_binary_sensor_ != nullptr) {
      this->adc_done_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->vsys_stat_sensor_ != nullptr || this->vsys_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vsys_stat_sensor_ and/or this->vsys_stat_text_sensor_ from I2C register REG1E_Charger_Status_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VSYS_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vsys_stat_text_sensor_ != nullptr) {
      this->vsys_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYS_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vsys_stat_sensor_ != nullptr) {
      this->vsys_stat_sensor_->publish_state(value);
    }
  }


  if (this->chg_tmr_stat_sensor_ != nullptr || this->chg_tmr_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->chg_tmr_stat_sensor_ and/or this->chg_tmr_stat_text_sensor_ from I2C register REG1E_Charger_Status_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->CHG_TMR_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->chg_tmr_stat_text_sensor_ != nullptr) {
      this->chg_tmr_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->CHG_TMR_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->chg_tmr_stat_sensor_ != nullptr) {
      this->chg_tmr_stat_sensor_->publish_state(value);
    }
  }


  if (this->trichg_tmr_stat_sensor_ != nullptr || this->trichg_tmr_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->trichg_tmr_stat_sensor_ and/or this->trichg_tmr_stat_text_sensor_ from I2C register REG1E_Charger_Status_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TRICHG_TMR_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->trichg_tmr_stat_text_sensor_ != nullptr) {
      this->trichg_tmr_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TRICHG_TMR_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->trichg_tmr_stat_sensor_ != nullptr) {
      this->trichg_tmr_stat_sensor_->publish_state(value);
    }
  }


  if (this->prechg_tmr_stat_sensor_ != nullptr || this->prechg_tmr_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->prechg_tmr_stat_sensor_ and/or this->prechg_tmr_stat_text_sensor_ from I2C register REG1E_Charger_Status_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1E_Charger_Status_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PRECHG_TMR_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->prechg_tmr_stat_text_sensor_ != nullptr) {
      this->prechg_tmr_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PRECHG_TMR_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->prechg_tmr_stat_sensor_ != nullptr) {
      this->prechg_tmr_stat_sensor_->publish_state(value);
    }
  }


  if (this->vbatotg_low_stat_sensor_ != nullptr || this->vbatotg_low_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbatotg_low_stat_sensor_ and/or this->vbatotg_low_stat_text_sensor_ from I2C register REG1F_Charger_Status_4...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->VBATOTG_LOW_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbatotg_low_stat_text_sensor_ != nullptr) {
      this->vbatotg_low_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBATOTG_LOW_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbatotg_low_stat_sensor_ != nullptr) {
      this->vbatotg_low_stat_sensor_->publish_state(value);
    }
  }


  if (this->ts_cold_stat_sensor_ != nullptr || this->ts_cold_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ts_cold_stat_sensor_ and/or this->ts_cold_stat_text_sensor_ from I2C register REG1F_Charger_Status_4...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_COLD_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_cold_stat_text_sensor_ != nullptr) {
      this->ts_cold_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COLD_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_cold_stat_sensor_ != nullptr) {
      this->ts_cold_stat_sensor_->publish_state(value);
    }
  }


  if (this->ts_cool_stat_sensor_ != nullptr || this->ts_cool_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ts_cool_stat_sensor_ and/or this->ts_cool_stat_text_sensor_ from I2C register REG1F_Charger_Status_4...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_COOL_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_cool_stat_text_sensor_ != nullptr) {
      this->ts_cool_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_COOL_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_cool_stat_sensor_ != nullptr) {
      this->ts_cool_stat_sensor_->publish_state(value);
    }
  }


  if (this->ts_warm_stat_sensor_ != nullptr || this->ts_warm_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ts_warm_stat_sensor_ and/or this->ts_warm_stat_text_sensor_ from I2C register REG1F_Charger_Status_4...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_WARM_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_warm_stat_text_sensor_ != nullptr) {
      this->ts_warm_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_WARM_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_warm_stat_sensor_ != nullptr) {
      this->ts_warm_stat_sensor_->publish_state(value);
    }
  }


  if (this->ts_hot_stat_sensor_ != nullptr || this->ts_hot_stat_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ts_hot_stat_sensor_ and/or this->ts_hot_stat_text_sensor_ from I2C register REG1F_Charger_Status_4...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG1F_Charger_Status_4, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->TS_HOT_STAT);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_hot_stat_text_sensor_ != nullptr) {
      this->ts_hot_stat_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->TS_HOT_STAT);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_hot_stat_sensor_ != nullptr) {
      this->ts_hot_stat_sensor_->publish_state(value);
    }
  }


  if (this->ibat_reg_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ibat_reg_stat_binary_sensor_ from I2C register REG20_FAULT_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_REG_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ibat_reg_stat_binary_sensor_ != nullptr) {
      this->ibat_reg_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->vbus_ovp_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbus_ovp_stat_binary_sensor_ from I2C register REG20_FAULT_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_OVP_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbus_ovp_stat_binary_sensor_ != nullptr) {
      this->vbus_ovp_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->vbat_ovp_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbat_ovp_stat_binary_sensor_ from I2C register REG20_FAULT_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_OVP_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbat_ovp_stat_binary_sensor_ != nullptr) {
      this->vbat_ovp_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->ibus_ocp_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ibus_ocp_stat_binary_sensor_ from I2C register REG20_FAULT_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_OCP_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ibus_ocp_stat_binary_sensor_ != nullptr) {
      this->ibus_ocp_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->ibat_ocp_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ibat_ocp_stat_binary_sensor_ from I2C register REG20_FAULT_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_OCP_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ibat_ocp_stat_binary_sensor_ != nullptr) {
      this->ibat_ocp_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->conv_ocp_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->conv_ocp_stat_binary_sensor_ from I2C register REG20_FAULT_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CONV_OCP_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->conv_ocp_stat_binary_sensor_ != nullptr) {
      this->conv_ocp_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->vac2_ovp_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vac2_ovp_stat_binary_sensor_ from I2C register REG20_FAULT_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_OVP_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vac2_ovp_stat_binary_sensor_ != nullptr) {
      this->vac2_ovp_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->vac1_ovp_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vac1_ovp_stat_binary_sensor_ from I2C register REG20_FAULT_Status_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG20_FAULT_Status_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_OVP_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vac1_ovp_stat_binary_sensor_ != nullptr) {
      this->vac1_ovp_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->vsys_short_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vsys_short_stat_binary_sensor_ from I2C register REG21_FAULT_Status_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_SHORT_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vsys_short_stat_binary_sensor_ != nullptr) {
      this->vsys_short_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->vsys_ovp_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vsys_ovp_stat_binary_sensor_ from I2C register REG21_FAULT_Status_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_OVP_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vsys_ovp_stat_binary_sensor_ != nullptr) {
      this->vsys_ovp_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->otg_ovp_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->otg_ovp_stat_binary_sensor_ from I2C register REG21_FAULT_Status_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_OVP_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->otg_ovp_stat_binary_sensor_ != nullptr) {
      this->otg_ovp_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->otg_uvp_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->otg_uvp_stat_binary_sensor_ from I2C register REG21_FAULT_Status_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_UVP_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->otg_uvp_stat_binary_sensor_ != nullptr) {
      this->otg_uvp_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->tshut_stat_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->tshut_stat_binary_sensor_ from I2C register REG21_FAULT_Status_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG21_FAULT_Status_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TSHUT_STAT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->tshut_stat_binary_sensor_ != nullptr) {
      this->tshut_stat_binary_sensor_->publish_state(value);
    }
  }


  if (this->iindpm_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->iindpm_flag_binary_sensor_ from I2C register REG22_Charger_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IINDPM_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->iindpm_flag_binary_sensor_ != nullptr) {
      this->iindpm_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->vindpm_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vindpm_flag_binary_sensor_ from I2C register REG22_Charger_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VINDPM_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vindpm_flag_binary_sensor_ != nullptr) {
      this->vindpm_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->wd_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->wd_flag_binary_sensor_ from I2C register REG22_Charger_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->WD_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->wd_flag_binary_sensor_ != nullptr) {
      this->wd_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->poorsrc_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->poorsrc_flag_binary_sensor_ from I2C register REG22_Charger_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->POORSRC_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->poorsrc_flag_binary_sensor_ != nullptr) {
      this->poorsrc_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->pg_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->pg_flag_binary_sensor_ from I2C register REG22_Charger_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PG_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->pg_flag_binary_sensor_ != nullptr) {
      this->pg_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->ac2_present_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ac2_present_flag_binary_sensor_ from I2C register REG22_Charger_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AC2_PRESENT_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ac2_present_flag_binary_sensor_ != nullptr) {
      this->ac2_present_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->ac1_present_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ac1_present_flag_binary_sensor_ from I2C register REG22_Charger_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->AC1_PRESENT_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ac1_present_flag_binary_sensor_ != nullptr) {
      this->ac1_present_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->vbus_present_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbus_present_flag_binary_sensor_ from I2C register REG22_Charger_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG22_Charger_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_PRESENT_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbus_present_flag_binary_sensor_ != nullptr) {
      this->vbus_present_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->chg_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->chg_flag_binary_sensor_ from I2C register REG23_Charger_Flag_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CHG_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->chg_flag_binary_sensor_ != nullptr) {
      this->chg_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->ico_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ico_flag_binary_sensor_ from I2C register REG23_Charger_Flag_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ICO_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ico_flag_binary_sensor_ != nullptr) {
      this->ico_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->vbus_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbus_flag_binary_sensor_ from I2C register REG23_Charger_Flag_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbus_flag_binary_sensor_ != nullptr) {
      this->vbus_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->treg_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->treg_flag_binary_sensor_ from I2C register REG23_Charger_Flag_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TREG_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->treg_flag_binary_sensor_ != nullptr) {
      this->treg_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->vbat_present_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbat_present_flag_binary_sensor_ from I2C register REG23_Charger_Flag_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_PRESENT_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbat_present_flag_binary_sensor_ != nullptr) {
      this->vbat_present_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->bc1_2_done_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->bc1_2_done_flag_binary_sensor_ from I2C register REG23_Charger_Flag_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG23_Charger_Flag_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->BC1_2_DONE_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->bc1_2_done_flag_binary_sensor_ != nullptr) {
      this->bc1_2_done_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->dpdm_done_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dpdm_done_flag_binary_sensor_ from I2C register REG24_Charger_Flag_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DPDM_DONE_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dpdm_done_flag_binary_sensor_ != nullptr) {
      this->dpdm_done_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->adc_done_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->adc_done_flag_binary_sensor_ from I2C register REG24_Charger_Flag_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_DONE_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->adc_done_flag_binary_sensor_ != nullptr) {
      this->adc_done_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->vsys_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vsys_flag_binary_sensor_ from I2C register REG24_Charger_Flag_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vsys_flag_binary_sensor_ != nullptr) {
      this->vsys_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->chg_tmr_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->chg_tmr_flag_binary_sensor_ from I2C register REG24_Charger_Flag_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CHG_TMR_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->chg_tmr_flag_binary_sensor_ != nullptr) {
      this->chg_tmr_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->trichg_tmr_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->trichg_tmr_flag_binary_sensor_ from I2C register REG24_Charger_Flag_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TRICHG_TMR_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->trichg_tmr_flag_binary_sensor_ != nullptr) {
      this->trichg_tmr_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->prechg_tmr_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->prechg_tmr_flag_binary_sensor_ from I2C register REG24_Charger_Flag_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->PRECHG_TMR_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->prechg_tmr_flag_binary_sensor_ != nullptr) {
      this->prechg_tmr_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->topoff_tmr_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->topoff_tmr_flag_binary_sensor_ from I2C register REG24_Charger_Flag_2...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG24_Charger_Flag_2, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TOPOFF_TMR_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->topoff_tmr_flag_binary_sensor_ != nullptr) {
      this->topoff_tmr_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->vbatotg_low_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbatotg_low_flag_binary_sensor_ from I2C register REG25_Charger_Flag_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBATOTG_LOW_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbatotg_low_flag_binary_sensor_ != nullptr) {
      this->vbatotg_low_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->ts_cold_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ts_cold_flag_binary_sensor_ from I2C register REG25_Charger_Flag_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_COLD_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_cold_flag_binary_sensor_ != nullptr) {
      this->ts_cold_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->ts_cool_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ts_cool_flag_binary_sensor_ from I2C register REG25_Charger_Flag_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_COOL_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_cool_flag_binary_sensor_ != nullptr) {
      this->ts_cool_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->ts_warm_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ts_warm_flag_binary_sensor_ from I2C register REG25_Charger_Flag_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_WARM_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_warm_flag_binary_sensor_ != nullptr) {
      this->ts_warm_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->ts_hot_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ts_hot_flag_binary_sensor_ from I2C register REG25_Charger_Flag_3...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG25_Charger_Flag_3, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_HOT_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_hot_flag_binary_sensor_ != nullptr) {
      this->ts_hot_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->ibat_reg_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ibat_reg_flag_binary_sensor_ from I2C register REG26_FAULT_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_REG_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ibat_reg_flag_binary_sensor_ != nullptr) {
      this->ibat_reg_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->vbus_ovp_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbus_ovp_flag_binary_sensor_ from I2C register REG26_FAULT_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_OVP_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbus_ovp_flag_binary_sensor_ != nullptr) {
      this->vbus_ovp_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->vbat_ovp_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbat_ovp_flag_binary_sensor_ from I2C register REG26_FAULT_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_OVP_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbat_ovp_flag_binary_sensor_ != nullptr) {
      this->vbat_ovp_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->ibus_ocp_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ibus_ocp_flag_binary_sensor_ from I2C register REG26_FAULT_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_OCP_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ibus_ocp_flag_binary_sensor_ != nullptr) {
      this->ibus_ocp_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->ibat_ocp_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ibat_ocp_flag_binary_sensor_ from I2C register REG26_FAULT_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_OCP_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ibat_ocp_flag_binary_sensor_ != nullptr) {
      this->ibat_ocp_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->conv_ocp_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->conv_ocp_flag_binary_sensor_ from I2C register REG26_FAULT_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->CONV_OCP_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->conv_ocp_flag_binary_sensor_ != nullptr) {
      this->conv_ocp_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->vac2_ovp_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vac2_ovp_flag_binary_sensor_ from I2C register REG26_FAULT_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_OVP_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vac2_ovp_flag_binary_sensor_ != nullptr) {
      this->vac2_ovp_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->vac1_ovp_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vac1_ovp_flag_binary_sensor_ from I2C register REG26_FAULT_Flag_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG26_FAULT_Flag_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_OVP_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vac1_ovp_flag_binary_sensor_ != nullptr) {
      this->vac1_ovp_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->vsys_short_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vsys_short_flag_binary_sensor_ from I2C register REG27_FAULT_Flag_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_SHORT_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vsys_short_flag_binary_sensor_ != nullptr) {
      this->vsys_short_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->vsys_ovp_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vsys_ovp_flag_binary_sensor_ from I2C register REG27_FAULT_Flag_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_OVP_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vsys_ovp_flag_binary_sensor_ != nullptr) {
      this->vsys_ovp_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->otg_ovp_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->otg_ovp_flag_binary_sensor_ from I2C register REG27_FAULT_Flag_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_OVP_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->otg_ovp_flag_binary_sensor_ != nullptr) {
      this->otg_ovp_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->otg_uvp_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->otg_uvp_flag_binary_sensor_ from I2C register REG27_FAULT_Flag_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->OTG_UVP_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->otg_uvp_flag_binary_sensor_ != nullptr) {
      this->otg_uvp_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->tshut_flag_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->tshut_flag_binary_sensor_ from I2C register REG27_FAULT_Flag_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG27_FAULT_Flag_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TSHUT_FLAG);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->tshut_flag_binary_sensor_ != nullptr) {
      this->tshut_flag_binary_sensor_->publish_state(value);
    }
  }


  if (this->adc_en_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->adc_en_binary_sensor_ from I2C register REG2E_ADC_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_EN);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->adc_en_binary_sensor_ != nullptr) {
      this->adc_en_binary_sensor_->publish_state(value);
    }
  }


  if (this->adc_rate_sensor_ != nullptr || this->adc_rate_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->adc_rate_sensor_ and/or this->adc_rate_text_sensor_ from I2C register REG2E_ADC_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->ADC_RATE);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->adc_rate_text_sensor_ != nullptr) {
      this->adc_rate_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_RATE);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->adc_rate_sensor_ != nullptr) {
      this->adc_rate_sensor_->publish_state(value);
    }
  }


  if (this->adc_sample_sensor_ != nullptr || this->adc_sample_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->adc_sample_sensor_ and/or this->adc_sample_text_sensor_ from I2C register REG2E_ADC_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(2);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (2 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->ADC_SAMPLE);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->adc_sample_text_sensor_ != nullptr) {
      this->adc_sample_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_SAMPLE);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->adc_sample_sensor_ != nullptr) {
      this->adc_sample_sensor_->publish_state(value);
    }
  }


  if (this->adc_avg_sensor_ != nullptr || this->adc_avg_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->adc_avg_sensor_ and/or this->adc_avg_text_sensor_ from I2C register REG2E_ADC_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->ADC_AVG);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->adc_avg_text_sensor_ != nullptr) {
      this->adc_avg_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->ADC_AVG);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->adc_avg_sensor_ != nullptr) {
      this->adc_avg_sensor_->publish_state(value);
    }
  }


  if (this->adc_avg_init_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->adc_avg_init_binary_sensor_ from I2C register REG2E_ADC_Control...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->ADC_AVG_INIT);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->adc_avg_init_binary_sensor_ != nullptr) {
      this->adc_avg_init_binary_sensor_->publish_state(value);
    }
  }


  if (this->ibus_adc_dis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ibus_adc_dis_binary_sensor_ from I2C register REG2F_ADC_Function_Disable_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBUS_ADC_DIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ibus_adc_dis_binary_sensor_ != nullptr) {
      this->ibus_adc_dis_binary_sensor_->publish_state(value);
    }
  }


  if (this->ibat_adc_dis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ibat_adc_dis_binary_sensor_ from I2C register REG2F_ADC_Function_Disable_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->IBAT_ADC_DIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ibat_adc_dis_binary_sensor_ != nullptr) {
      this->ibat_adc_dis_binary_sensor_->publish_state(value);
    }
  }


  if (this->vbus_adc_dis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbus_adc_dis_binary_sensor_ from I2C register REG2F_ADC_Function_Disable_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBUS_ADC_DIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbus_adc_dis_binary_sensor_ != nullptr) {
      this->vbus_adc_dis_binary_sensor_->publish_state(value);
    }
  }


  if (this->vbat_adc_dis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbat_adc_dis_binary_sensor_ from I2C register REG2F_ADC_Function_Disable_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VBAT_ADC_DIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbat_adc_dis_binary_sensor_ != nullptr) {
      this->vbat_adc_dis_binary_sensor_->publish_state(value);
    }
  }


  if (this->vsys_adc_dis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vsys_adc_dis_binary_sensor_ from I2C register REG2F_ADC_Function_Disable_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VSYS_ADC_DIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vsys_adc_dis_binary_sensor_ != nullptr) {
      this->vsys_adc_dis_binary_sensor_->publish_state(value);
    }
  }


  if (this->ts_adc_dis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ts_adc_dis_binary_sensor_ from I2C register REG2F_ADC_Function_Disable_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TS_ADC_DIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_adc_dis_binary_sensor_ != nullptr) {
      this->ts_adc_dis_binary_sensor_->publish_state(value);
    }
  }


  if (this->tdie_adc_dis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->tdie_adc_dis_binary_sensor_ from I2C register REG2F_ADC_Function_Disable_0...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG2F_ADC_Function_Disable_0, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 1) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 1) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->TDIE_ADC_DIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->tdie_adc_dis_binary_sensor_ != nullptr) {
      this->tdie_adc_dis_binary_sensor_->publish_state(value);
    }
  }


  if (this->dplus_adc_dis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dplus_adc_dis_binary_sensor_ from I2C register REG30_ADC_Function_Disable_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 7) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 7) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DPLUS_ADC_DIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dplus_adc_dis_binary_sensor_ != nullptr) {
      this->dplus_adc_dis_binary_sensor_->publish_state(value);
    }
  }


  if (this->dminus_adc_dis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dminus_adc_dis_binary_sensor_ from I2C register REG30_ADC_Function_Disable_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 6) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 6) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->DMINUS_ADC_DIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dminus_adc_dis_binary_sensor_ != nullptr) {
      this->dminus_adc_dis_binary_sensor_->publish_state(value);
    }
  }


  if (this->vac2_adc_dis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vac2_adc_dis_binary_sensor_ from I2C register REG30_ADC_Function_Disable_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC2_ADC_DIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vac2_adc_dis_binary_sensor_ != nullptr) {
      this->vac2_adc_dis_binary_sensor_->publish_state(value);
    }
  }


  if (this->vac1_adc_dis_binary_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vac1_adc_dis_binary_sensor_ from I2C register REG30_ADC_Function_Disable_1...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG30_ADC_Function_Disable_1, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 4) & BITLENGTH_TO_MASK(1);
    // ESP_LOGD(TAG, "  shifted (>> 4) and masked (1 bits) raw value: 0x%04X", raw_value);
    bool value = this->bq25798_noi2c->rawToBool(raw_value, this->bq25798_noi2c->VAC1_ADC_DIS);
    // ESP_LOGD(TAG, "  converted to bool: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vac1_adc_dis_binary_sensor_ != nullptr) {
      this->vac1_adc_dis_binary_sensor_->publish_state(value);
    }
  }


  if (this->ibus_adc_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ibus_adc_sensor_ from I2C register REG31_IBUS_ADC...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG31_IBUS_ADC, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBUS_ADC);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ibus_adc_sensor_ != nullptr) {
      this->ibus_adc_sensor_->publish_state(value);
    }
  }


  if (this->ibat_adc_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ibat_adc_sensor_ from I2C register REG33_IBAT_ADC...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG33_IBAT_ADC, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->IBAT_ADC);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ibat_adc_sensor_ != nullptr) {
      this->ibat_adc_sensor_->publish_state(value);
    }
  }


  if (this->vbus_adc_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbus_adc_sensor_ from I2C register REG35_VBUS_ADC...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG35_VBUS_ADC, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBUS_ADC);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbus_adc_sensor_ != nullptr) {
      this->vbus_adc_sensor_->publish_state(value);
    }
  }


  if (this->vac1_adc_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vac1_adc_sensor_ from I2C register REG37_VAC1_ADC...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG37_VAC1_ADC, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC1_ADC);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vac1_adc_sensor_ != nullptr) {
      this->vac1_adc_sensor_->publish_state(value);
    }
  }


  if (this->vac2_adc_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vac2_adc_sensor_ from I2C register REG39_VAC2_ADC...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG39_VAC2_ADC, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VAC2_ADC);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vac2_adc_sensor_ != nullptr) {
      this->vac2_adc_sensor_->publish_state(value);
    }
  }


  if (this->vbat_adc_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vbat_adc_sensor_ from I2C register REG3B_VBAT_ADC...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG3B_VBAT_ADC, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VBAT_ADC);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vbat_adc_sensor_ != nullptr) {
      this->vbat_adc_sensor_->publish_state(value);
    }
  }


  if (this->vsys_adc_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->vsys_adc_sensor_ from I2C register REG3D_VSYS_ADC...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG3D_VSYS_ADC, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->VSYS_ADC);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->vsys_adc_sensor_ != nullptr) {
      this->vsys_adc_sensor_->publish_state(value);
    }
  }


  if (this->ts_adc_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->ts_adc_sensor_ from I2C register REG3F_TS_ADC...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG3F_TS_ADC, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    float value = this->bq25798_noi2c->rawToFloat(raw_value, this->bq25798_noi2c->TS_ADC);
    // ESP_LOGD(TAG, "  converted to float: %f", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->ts_adc_sensor_ != nullptr) {
      this->ts_adc_sensor_->publish_state(value);
    }
  }


  if (this->tdie_adc_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->tdie_adc_sensor_ from I2C register REG41_TDIE_ADC...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG41_TDIE_ADC, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    float value = this->bq25798_noi2c->rawToFloat(raw_value, this->bq25798_noi2c->TDIE_ADC);
    // ESP_LOGD(TAG, "  converted to float: %f", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->tdie_adc_sensor_ != nullptr) {
      this->tdie_adc_sensor_->publish_state(value);
    }
  }


  if (this->dplus_adc_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dplus_adc_sensor_ from I2C register REG43_DPLUS_ADC...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG43_DPLUS_ADC, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPLUS_ADC);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dplus_adc_sensor_ != nullptr) {
      this->dplus_adc_sensor_->publish_state(value);
    }
  }


  if (this->dminus_adc_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dminus_adc_sensor_ from I2C register REG45_DMINUS_ADC...");

    // read the value from the chip
    uint16_t reg_value;
    if (!this->read_byte_16(REG45_DMINUS_ADC, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 16-bit register value: 0x%04X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(16);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (16 bits) raw value: 0x%04X", raw_value);
    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DMINUS_ADC);
    // ESP_LOGD(TAG, "  converted to int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dminus_adc_sensor_ != nullptr) {
      this->dminus_adc_sensor_->publish_state(value);
    }
  }


  if (this->dplus_dac_sensor_ != nullptr || this->dplus_dac_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dplus_dac_sensor_ and/or this->dplus_dac_text_sensor_ from I2C register REG47_DPDM_Driver...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 5) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 5) and masked (3 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->DPLUS_DAC);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dplus_dac_text_sensor_ != nullptr) {
      this->dplus_dac_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DPLUS_DAC);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dplus_dac_sensor_ != nullptr) {
      this->dplus_dac_sensor_->publish_state(value);
    }
  }


  if (this->dminus_dac_sensor_ != nullptr || this->dminus_dac_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dminus_dac_sensor_ and/or this->dminus_dac_text_sensor_ from I2C register REG47_DPDM_Driver...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 2) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 2) and masked (3 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->DMINUS_DAC);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dminus_dac_text_sensor_ != nullptr) {
      this->dminus_dac_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DMINUS_DAC);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dminus_dac_sensor_ != nullptr) {
      this->dminus_dac_sensor_->publish_state(value);
    }
  }


  if (this->pn_sensor_ != nullptr || this->pn_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->pn_sensor_ and/or this->pn_text_sensor_ from I2C register REG48_Part_Information...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG48_Part_Information, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 3) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 3) and masked (3 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->PN);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->pn_text_sensor_ != nullptr) {
      this->pn_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->PN);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->pn_sensor_ != nullptr) {
      this->pn_sensor_->publish_state(value);
    }
  }


  if (this->dev_rev_sensor_ != nullptr || this->dev_rev_text_sensor_ != nullptr) {
    // ESP_LOGD(TAG, "Reading this->dev_rev_sensor_ and/or this->dev_rev_text_sensor_ from I2C register REG48_Part_Information...");

    // read the value from the chip
    uint8_t reg_value;
    if (!this->read_byte(REG48_Part_Information, &reg_value)) {
      this->mark_failed();
      return;
    }
// ESP_LOGD(TAG, "  received raw 8-bit register value: 0x%02X", reg_value);

    // shift and mask it to get the raw value
    uint16_t raw_value = (reg_value >> 0) & BITLENGTH_TO_MASK(3);
    // ESP_LOGD(TAG, "  shifted (>> 0) and masked (3 bits) raw value: 0x%04X", raw_value);
    // exception: process both int and string values
    const char* string_value = this->bq25798_noi2c->rawToString(raw_value, this->bq25798_noi2c->DEV_REV);
    // ESP_LOGD(TAG, "  converted to enum.string: %s", string_value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dev_rev_text_sensor_ != nullptr) {
      this->dev_rev_text_sensor_->publish_state(string_value);
    }

    int value = this->bq25798_noi2c->rawToInt(raw_value, this->bq25798_noi2c->DEV_REV);
    // ESP_LOGD(TAG, "  converted to enum.int: %d", value);
    if (this->bq25798_noi2c->lastError()) {
      this->status_set_warning();
      this->bq25798_noi2c->clearError();
      return;
    }
    if (this->dev_rev_sensor_ != nullptr) {
      this->dev_rev_sensor_->publish_state(value);
    }
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


 uint8_t reg_value;
  if (!this->read_byte(REG00_Minimal_System_Voltage, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG00_Minimal_System_Voltage, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(6) << 0);
//ESP_LOGD(TAG, "  masked (6 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(6)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG00_Minimal_System_Voltage, reg_value)) {
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


 uint8_t reg_value;
  if (!this->read_byte(REG05_Input_Voltage_Limit, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG05_Input_Voltage_Limit, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(8) << 0);
//ESP_LOGD(TAG, "  masked (8 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(8)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG05_Input_Voltage_Limit, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG08_Precharge_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG08_Precharge_Control, reg_value)) {
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


 uint8_t reg_value;
  if (!this->read_byte(REG08_Precharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG08_Precharge_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(6) << 0);
//ESP_LOGD(TAG, "  masked (6 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(6)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG08_Precharge_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG09_Termination_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG09_Termination_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG09_Termination_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG09_Termination_Control, reg_value)) {
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


 uint8_t reg_value;
  if (!this->read_byte(REG09_Termination_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG09_Termination_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(5) << 0);
//ESP_LOGD(TAG, "  masked (5 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(5)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG09_Termination_Control, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0A_Recharge_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0A_Recharge_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
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


 uint8_t reg_value;
  if (!this->read_byte(REG0A_Recharge_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0A_Recharge_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(4) << 0);
//ESP_LOGD(TAG, "  masked (4 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(4)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0A_Recharge_Control, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0D_IOTG_regulation, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0D_IOTG_regulation, reg_value)) {
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


 uint8_t reg_value;
  if (!this->read_byte(REG0D_IOTG_regulation, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0D_IOTG_regulation, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(7) << 0);
//ESP_LOGD(TAG, "  masked (7 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(7)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0D_IOTG_regulation, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0E_Timer_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0E_Timer_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0E_Timer_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0E_Timer_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG0E_Timer_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0E_Timer_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0E_Timer_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0E_Timer_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG0F_Charger_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG0F_Charger_Control_0, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG10_Charger_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG10_Charger_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG10_Charger_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG10_Charger_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG10_Charger_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 0);
//ESP_LOGD(TAG, "  masked (3 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG10_Charger_Control_1, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG11_Charger_Control_2, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG11_Charger_Control_2, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG11_Charger_Control_2, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG11_Charger_Control_2, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG11_Charger_Control_2, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG11_Charger_Control_2, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG11_Charger_Control_2, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG11_Charger_Control_2, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG11_Charger_Control_2, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG12_Charger_Control_3, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG12_Charger_Control_3, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG12_Charger_Control_3, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG13_Charger_Control_4, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG13_Charger_Control_4, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG13_Charger_Control_4, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG14_Charger_Control_5, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG14_Charger_Control_5, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG14_Charger_Control_5, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG14_Charger_Control_5, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 3);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 3);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG14_Charger_Control_5, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG14_Charger_Control_5, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG14_Charger_Control_5, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG14_Charger_Control_5, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG15_MPPT_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
//ESP_LOGD(TAG, "  masked (3 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG15_MPPT_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG15_MPPT_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG15_MPPT_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 2);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 2);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG15_MPPT_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG15_MPPT_Control, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG16_Temperature_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG16_Temperature_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG16_Temperature_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG16_Temperature_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG16_Temperature_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG16_Temperature_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG16_Temperature_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG16_Temperature_Control, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG17_NTC_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
//ESP_LOGD(TAG, "  masked (3 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG17_NTC_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 3);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 3);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG17_NTC_Control_0, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG17_NTC_Control_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 1);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 1);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG17_NTC_Control_0, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG18_NTC_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 6);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 6);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG18_NTC_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG18_NTC_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 2);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 2);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG18_NTC_Control_1, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG18_NTC_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG18_NTC_Control_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 0);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 0) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 0);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG18_NTC_Control_1, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG2E_ADC_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG2E_ADC_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG2E_ADC_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(2) << 4);
//ESP_LOGD(TAG, "  masked (2 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(2)) << 4);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG2E_ADC_Control, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG2E_ADC_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG2E_ADC_Control, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2E_ADC_Control, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 3);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 3) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 3);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 2);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 2);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG2F_ADC_Function_Disable_0, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 1);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 1) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 1);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG2F_ADC_Function_Disable_0, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 7);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 7) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 7);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 6);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 6) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 6);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 5);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 5);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

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

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG30_ADC_Function_Disable_1, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(1) << 4);
//ESP_LOGD(TAG, "  masked (1 bits shifted by 4) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(1)) << 4);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG30_ADC_Function_Disable_1, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG47_DPDM_Driver, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 5);
//ESP_LOGD(TAG, "  masked (3 bits shifted by 5) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 5);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG47_DPDM_Driver, reg_value)) {
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

 uint8_t reg_value;
  if (!this->read_byte(REG47_DPDM_Driver, &reg_value)) {
    this->mark_failed();
    return;
  }

//ESP_LOGD(TAG, "  received raw 8-bit register %02X value: 0x%02X", REG47_DPDM_Driver, reg_value);
// mask out the bits we are going to change
  reg_value &= ~(BITLENGTH_TO_MASK(3) << 2);
//ESP_LOGD(TAG, "  masked (3 bits shifted by 2) register value: 0x%02X", reg_value);  
// shift the new value into place and mask it
  reg_value |= ((raw_value & BITLENGTH_TO_MASK(3)) << 2);
//ESP_LOGD(TAG, "  or-ed register value: 0x%02X", reg_value);

  if (!this->write_byte(REG47_DPDM_Driver, reg_value)) {
    this->mark_failed();
  }
  } // if (write_to_i2c && this->bq25798_noi2c != nullptr)
};  // function end

}  // namespace bq25798
}  // namespace esphome