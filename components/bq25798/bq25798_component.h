#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"

#include "BQ25798ESPHome.h"

#include <cinttypes>

namespace esphome {
namespace bq25798 {

class BQ25798Component : public PollingComponent, public i2c::I2CDevice {
 public:
  void setup() override;
  void dump_config() override;
  float get_setup_priority() const override;
  void update() override;
  void set_vsysmin(int value);
  void set_vsysmin_sensor(sensor::Sensor *sensor) { vsysmin_sensor_ = sensor; }

  void set_vreg(int value);
  void set_vreg_sensor(sensor::Sensor *sensor) { vreg_sensor_ = sensor; }

  void set_ichg(int value);
  void set_ichg_sensor(sensor::Sensor *sensor) { ichg_sensor_ = sensor; }

  void set_vindpm(int value);
  void set_vindpm_sensor(sensor::Sensor *sensor) { vindpm_sensor_ = sensor; }

  void set_iindpm(int value);
  void set_iindpm_sensor(sensor::Sensor *sensor) { iindpm_sensor_ = sensor; }

  void set_vbat_lowv(int value);
  void set_vbat_lowv_sensor(sensor::Sensor *sensor) { vbat_lowv_sensor_ = sensor; }

  void set_iprechg(int value);
  void set_iprechg_sensor(sensor::Sensor *sensor) { iprechg_sensor_ = sensor; }

  void set_reg_rst(bool value);
  void set_reg_rst_sensor(sensor::Sensor *sensor) { reg_rst_sensor_ = sensor; }

  void set_stop_wd_chg(bool value);
  void set_stop_wd_chg_sensor(sensor::Sensor *sensor) { stop_wd_chg_sensor_ = sensor; }

  void set_iterm(int value);
  void set_iterm_sensor(sensor::Sensor *sensor) { iterm_sensor_ = sensor; }

  void set_cell(int value);
  void set_cell_sensor(sensor::Sensor *sensor) { cell_sensor_ = sensor; }

  void set_trechg(int value);
  void set_trechg_sensor(sensor::Sensor *sensor) { trechg_sensor_ = sensor; }

  void set_vrechg(int value);
  void set_vrechg_sensor(sensor::Sensor *sensor) { vrechg_sensor_ = sensor; }

  void set_votg(int value);
  void set_votg_sensor(sensor::Sensor *sensor) { votg_sensor_ = sensor; }

  void set_prechg_tmr(int value);
  void set_prechg_tmr_sensor(sensor::Sensor *sensor) { prechg_tmr_sensor_ = sensor; }

  void set_iotg(int value);
  void set_iotg_sensor(sensor::Sensor *sensor) { iotg_sensor_ = sensor; }

  void set_topoff_tmr(int value);
  void set_topoff_tmr_sensor(sensor::Sensor *sensor) { topoff_tmr_sensor_ = sensor; }

  void set_en_trichg_tmr(bool value);
  void set_en_trichg_tmr_sensor(sensor::Sensor *sensor) { en_trichg_tmr_sensor_ = sensor; }

  void set_en_prechg_tmr(bool value);
  void set_en_prechg_tmr_sensor(sensor::Sensor *sensor) { en_prechg_tmr_sensor_ = sensor; }

  void set_en_chg_tmr(bool value);
  void set_en_chg_tmr_sensor(sensor::Sensor *sensor) { en_chg_tmr_sensor_ = sensor; }

  void set_chg_tmr(int value);
  void set_chg_tmr_sensor(sensor::Sensor *sensor) { chg_tmr_sensor_ = sensor; }

  void set_tmr2x_en(bool value);
  void set_tmr2x_en_sensor(sensor::Sensor *sensor) { tmr2x_en_sensor_ = sensor; }

  void set_en_auto_ibatdis(bool value);
  void set_en_auto_ibatdis_sensor(sensor::Sensor *sensor) { en_auto_ibatdis_sensor_ = sensor; }

  void set_force_ibatdis(bool value);
  void set_force_ibatdis_sensor(sensor::Sensor *sensor) { force_ibatdis_sensor_ = sensor; }

  void set_en_chg(bool value);
  void set_en_chg_sensor(sensor::Sensor *sensor) { en_chg_sensor_ = sensor; }

  void set_en_ico(bool value);
  void set_en_ico_sensor(sensor::Sensor *sensor) { en_ico_sensor_ = sensor; }

  void set_force_ico(bool value);
  void set_force_ico_sensor(sensor::Sensor *sensor) { force_ico_sensor_ = sensor; }

  void set_en_hiz(bool value);
  void set_en_hiz_sensor(sensor::Sensor *sensor) { en_hiz_sensor_ = sensor; }

  void set_en_term(bool value);
  void set_en_term_sensor(sensor::Sensor *sensor) { en_term_sensor_ = sensor; }

  void set_en_backup(bool value);
  void set_en_backup_sensor(sensor::Sensor *sensor) { en_backup_sensor_ = sensor; }

  void set_vbus_backup(int value);
  void set_vbus_backup_sensor(sensor::Sensor *sensor) { vbus_backup_sensor_ = sensor; }

  void set_vac_ovp(int value);
  void set_vac_ovp_sensor(sensor::Sensor *sensor) { vac_ovp_sensor_ = sensor; }

  void set_wd_rst(bool value);
  void set_wd_rst_sensor(sensor::Sensor *sensor) { wd_rst_sensor_ = sensor; }

  void set_watchdog(int value);
  void set_watchdog_sensor(sensor::Sensor *sensor) { watchdog_sensor_ = sensor; }

  void set_force_indet(bool value);
  void set_force_indet_sensor(sensor::Sensor *sensor) { force_indet_sensor_ = sensor; }

  void set_auto_indet_en(bool value);
  void set_auto_indet_en_sensor(sensor::Sensor *sensor) { auto_indet_en_sensor_ = sensor; }

  void set_en_12v(bool value);
  void set_en_12v_sensor(sensor::Sensor *sensor) { en_12v_sensor_ = sensor; }

  void set_en_9v(bool value);
  void set_en_9v_sensor(sensor::Sensor *sensor) { en_9v_sensor_ = sensor; }

  void set_hvdcp_en(bool value);
  void set_hvdcp_en_sensor(sensor::Sensor *sensor) { hvdcp_en_sensor_ = sensor; }

  void set_sdrv_ctrl(int value);
  void set_sdrv_ctrl_sensor(sensor::Sensor *sensor) { sdrv_ctrl_sensor_ = sensor; }

  void set_sdrv_dly(int value);
  void set_sdrv_dly_sensor(sensor::Sensor *sensor) { sdrv_dly_sensor_ = sensor; }

  void set_dis_acdrv(bool value);
  void set_dis_acdrv_sensor(sensor::Sensor *sensor) { dis_acdrv_sensor_ = sensor; }

  void set_en_otg(bool value);
  void set_en_otg_sensor(sensor::Sensor *sensor) { en_otg_sensor_ = sensor; }

  void set_pfm_otg_dis(bool value);
  void set_pfm_otg_dis_sensor(sensor::Sensor *sensor) { pfm_otg_dis_sensor_ = sensor; }

  void set_pfm_fwd_dis(bool value);
  void set_pfm_fwd_dis_sensor(sensor::Sensor *sensor) { pfm_fwd_dis_sensor_ = sensor; }

  void set_wkup_dly(int value);
  void set_wkup_dly_sensor(sensor::Sensor *sensor) { wkup_dly_sensor_ = sensor; }

  void set_dis_ldo(bool value);
  void set_dis_ldo_sensor(sensor::Sensor *sensor) { dis_ldo_sensor_ = sensor; }

  void set_dis_otg_ooa(bool value);
  void set_dis_otg_ooa_sensor(sensor::Sensor *sensor) { dis_otg_ooa_sensor_ = sensor; }

  void set_dis_fwd_ooa(bool value);
  void set_dis_fwd_ooa_sensor(sensor::Sensor *sensor) { dis_fwd_ooa_sensor_ = sensor; }

  void set_en_acdrv2(bool value);
  void set_en_acdrv2_sensor(sensor::Sensor *sensor) { en_acdrv2_sensor_ = sensor; }

  void set_en_acdrv1(bool value);
  void set_en_acdrv1_sensor(sensor::Sensor *sensor) { en_acdrv1_sensor_ = sensor; }

  void set_pwm_freq(int value);
  void set_pwm_freq_sensor(sensor::Sensor *sensor) { pwm_freq_sensor_ = sensor; }

  void set_dis_stat(bool value);
  void set_dis_stat_sensor(sensor::Sensor *sensor) { dis_stat_sensor_ = sensor; }

  void set_dis_vsys_short(bool value);
  void set_dis_vsys_short_sensor(sensor::Sensor *sensor) { dis_vsys_short_sensor_ = sensor; }

  void set_dis_votg_uvp(bool value);
  void set_dis_votg_uvp_sensor(sensor::Sensor *sensor) { dis_votg_uvp_sensor_ = sensor; }

  void set_force_vindpm_det(bool value);
  void set_force_vindpm_det_sensor(sensor::Sensor *sensor) { force_vindpm_det_sensor_ = sensor; }

  void set_en_ibus_ocp(bool value);
  void set_en_ibus_ocp_sensor(sensor::Sensor *sensor) { en_ibus_ocp_sensor_ = sensor; }

  void set_sfet_present(bool value);
  void set_sfet_present_sensor(sensor::Sensor *sensor) { sfet_present_sensor_ = sensor; }

  void set_en_ibat(bool value);
  void set_en_ibat_sensor(sensor::Sensor *sensor) { en_ibat_sensor_ = sensor; }

  void set_ibat_reg(int value);
  void set_ibat_reg_sensor(sensor::Sensor *sensor) { ibat_reg_sensor_ = sensor; }

  void set_en_iindpm(bool value);
  void set_en_iindpm_sensor(sensor::Sensor *sensor) { en_iindpm_sensor_ = sensor; }

  void set_en_extilim(bool value);
  void set_en_extilim_sensor(sensor::Sensor *sensor) { en_extilim_sensor_ = sensor; }

  void set_en_batoc(bool value);
  void set_en_batoc_sensor(sensor::Sensor *sensor) { en_batoc_sensor_ = sensor; }

  void set_voc_pct(int value);
  void set_voc_pct_sensor(sensor::Sensor *sensor) { voc_pct_sensor_ = sensor; }

  void set_voc_dly(int value);
  void set_voc_dly_sensor(sensor::Sensor *sensor) { voc_dly_sensor_ = sensor; }

  void set_voc_rate(int value);
  void set_voc_rate_sensor(sensor::Sensor *sensor) { voc_rate_sensor_ = sensor; }

  void set_en_mppt(bool value);
  void set_en_mppt_sensor(sensor::Sensor *sensor) { en_mppt_sensor_ = sensor; }

  void set_treg(int value);
  void set_treg_sensor(sensor::Sensor *sensor) { treg_sensor_ = sensor; }

  void set_tshut(int value);
  void set_tshut_sensor(sensor::Sensor *sensor) { tshut_sensor_ = sensor; }

  void set_vbus_pd_en(bool value);
  void set_vbus_pd_en_sensor(sensor::Sensor *sensor) { vbus_pd_en_sensor_ = sensor; }

  void set_vac1_pd_en(bool value);
  void set_vac1_pd_en_sensor(sensor::Sensor *sensor) { vac1_pd_en_sensor_ = sensor; }

  void set_vac2_pd_en(bool value);
  void set_vac2_pd_en_sensor(sensor::Sensor *sensor) { vac2_pd_en_sensor_ = sensor; }

  void set_bkup_acfet1_on(int value);
  void set_bkup_acfet1_on_sensor(sensor::Sensor *sensor) { bkup_acfet1_on_sensor_ = sensor; }

  void set_jeita_vset(int value);
  void set_jeita_vset_sensor(sensor::Sensor *sensor) { jeita_vset_sensor_ = sensor; }

  void set_jeita_iseth(int value);
  void set_jeita_iseth_sensor(sensor::Sensor *sensor) { jeita_iseth_sensor_ = sensor; }

  void set_jeita_isetc(int value);
  void set_jeita_isetc_sensor(sensor::Sensor *sensor) { jeita_isetc_sensor_ = sensor; }

  void set_ts_cool(int value);
  void set_ts_cool_sensor(sensor::Sensor *sensor) { ts_cool_sensor_ = sensor; }

  void set_ts_warm(int value);
  void set_ts_warm_sensor(sensor::Sensor *sensor) { ts_warm_sensor_ = sensor; }

  void set_bhot(int value);
  void set_bhot_sensor(sensor::Sensor *sensor) { bhot_sensor_ = sensor; }

  void set_bcold(int value);
  void set_bcold_sensor(sensor::Sensor *sensor) { bcold_sensor_ = sensor; }

  void set_ts_ignore(bool value);
  void set_ts_ignore_sensor(sensor::Sensor *sensor) { ts_ignore_sensor_ = sensor; }

  void set_ico_ilim(int value);
  void set_ico_ilim_sensor(sensor::Sensor *sensor) { ico_ilim_sensor_ = sensor; }

  void set_iindpm_stat(int value);
  void set_iindpm_stat_sensor(sensor::Sensor *sensor) { iindpm_stat_sensor_ = sensor; }

  void set_vindpm_stat(int value);
  void set_vindpm_stat_sensor(sensor::Sensor *sensor) { vindpm_stat_sensor_ = sensor; }

  void set_wd_stat(int value);
  void set_wd_stat_sensor(sensor::Sensor *sensor) { wd_stat_sensor_ = sensor; }

  void set_pg_stat(int value);
  void set_pg_stat_sensor(sensor::Sensor *sensor) { pg_stat_sensor_ = sensor; }

  void set_ac2_present_stat(int value);
  void set_ac2_present_stat_sensor(sensor::Sensor *sensor) { ac2_present_stat_sensor_ = sensor; }

  void set_ac1_present_stat(int value);
  void set_ac1_present_stat_sensor(sensor::Sensor *sensor) { ac1_present_stat_sensor_ = sensor; }

  void set_vbus_present_stat(int value);
  void set_vbus_present_stat_sensor(sensor::Sensor *sensor) { vbus_present_stat_sensor_ = sensor; }

  void set_chg_stat(int value);
  void set_chg_stat_sensor(sensor::Sensor *sensor) { chg_stat_sensor_ = sensor; }

  void set_vbus_stat(int value);
  void set_vbus_stat_sensor(sensor::Sensor *sensor) { vbus_stat_sensor_ = sensor; }

  void set_bc12_done_stat(bool value);
  void set_bc12_done_stat_sensor(sensor::Sensor *sensor) { bc12_done_stat_sensor_ = sensor; }

  void set_ico_stat(int value);
  void set_ico_stat_sensor(sensor::Sensor *sensor) { ico_stat_sensor_ = sensor; }

  void set_treg_stat(int value);
  void set_treg_stat_sensor(sensor::Sensor *sensor) { treg_stat_sensor_ = sensor; }

  void set_dpdm_stat(int value);
  void set_dpdm_stat_sensor(sensor::Sensor *sensor) { dpdm_stat_sensor_ = sensor; }

  void set_vbat_present_stat(int value);
  void set_vbat_present_stat_sensor(sensor::Sensor *sensor) { vbat_present_stat_sensor_ = sensor; }

  void set_acrb2_stat(bool value);
  void set_acrb2_stat_sensor(sensor::Sensor *sensor) { acrb2_stat_sensor_ = sensor; }

  void set_acrb1_stat(bool value);
  void set_acrb1_stat_sensor(sensor::Sensor *sensor) { acrb1_stat_sensor_ = sensor; }

  void set_adc_done_stat(bool value);
  void set_adc_done_stat_sensor(sensor::Sensor *sensor) { adc_done_stat_sensor_ = sensor; }

  void set_vsys_stat(int value);
  void set_vsys_stat_sensor(sensor::Sensor *sensor) { vsys_stat_sensor_ = sensor; }

  void set_chg_tmr_stat(int value);
  void set_chg_tmr_stat_sensor(sensor::Sensor *sensor) { chg_tmr_stat_sensor_ = sensor; }

  void set_trichg_tmr_stat(int value);
  void set_trichg_tmr_stat_sensor(sensor::Sensor *sensor) { trichg_tmr_stat_sensor_ = sensor; }

  void set_prechg_tmr_stat(int value);
  void set_prechg_tmr_stat_sensor(sensor::Sensor *sensor) { prechg_tmr_stat_sensor_ = sensor; }

  void set_vbatotg_low_stat(int value);
  void set_vbatotg_low_stat_sensor(sensor::Sensor *sensor) { vbatotg_low_stat_sensor_ = sensor; }

  void set_ts_cold_stat(int value);
  void set_ts_cold_stat_sensor(sensor::Sensor *sensor) { ts_cold_stat_sensor_ = sensor; }

  void set_ts_cool_stat(int value);
  void set_ts_cool_stat_sensor(sensor::Sensor *sensor) { ts_cool_stat_sensor_ = sensor; }

  void set_ts_warm_stat(int value);
  void set_ts_warm_stat_sensor(sensor::Sensor *sensor) { ts_warm_stat_sensor_ = sensor; }

  void set_ts_hot_stat(int value);
  void set_ts_hot_stat_sensor(sensor::Sensor *sensor) { ts_hot_stat_sensor_ = sensor; }

  void set_ibat_reg_stat(bool value);
  void set_ibat_reg_stat_sensor(sensor::Sensor *sensor) { ibat_reg_stat_sensor_ = sensor; }

  void set_vbus_ovp_stat(bool value);
  void set_vbus_ovp_stat_sensor(sensor::Sensor *sensor) { vbus_ovp_stat_sensor_ = sensor; }

  void set_vbat_ovp_stat(bool value);
  void set_vbat_ovp_stat_sensor(sensor::Sensor *sensor) { vbat_ovp_stat_sensor_ = sensor; }

  void set_ibus_ocp_stat(bool value);
  void set_ibus_ocp_stat_sensor(sensor::Sensor *sensor) { ibus_ocp_stat_sensor_ = sensor; }

  void set_ibat_ocp_stat(bool value);
  void set_ibat_ocp_stat_sensor(sensor::Sensor *sensor) { ibat_ocp_stat_sensor_ = sensor; }

  void set_conv_ocp_stat(bool value);
  void set_conv_ocp_stat_sensor(sensor::Sensor *sensor) { conv_ocp_stat_sensor_ = sensor; }

  void set_vac2_ovp_stat(bool value);
  void set_vac2_ovp_stat_sensor(sensor::Sensor *sensor) { vac2_ovp_stat_sensor_ = sensor; }

  void set_vac1_ovp_stat(bool value);
  void set_vac1_ovp_stat_sensor(sensor::Sensor *sensor) { vac1_ovp_stat_sensor_ = sensor; }

  void set_vsys_short_stat(bool value);
  void set_vsys_short_stat_sensor(sensor::Sensor *sensor) { vsys_short_stat_sensor_ = sensor; }

  void set_vsys_ovp_stat(bool value);
  void set_vsys_ovp_stat_sensor(sensor::Sensor *sensor) { vsys_ovp_stat_sensor_ = sensor; }

  void set_otg_ovp_stat(bool value);
  void set_otg_ovp_stat_sensor(sensor::Sensor *sensor) { otg_ovp_stat_sensor_ = sensor; }

  void set_otg_uvp_stat(bool value);
  void set_otg_uvp_stat_sensor(sensor::Sensor *sensor) { otg_uvp_stat_sensor_ = sensor; }

  void set_tshut_stat(bool value);
  void set_tshut_stat_sensor(sensor::Sensor *sensor) { tshut_stat_sensor_ = sensor; }

  void set_iindpm_flag(bool value);
  void set_iindpm_flag_sensor(sensor::Sensor *sensor) { iindpm_flag_sensor_ = sensor; }

  void set_vindpm_flag(bool value);
  void set_vindpm_flag_sensor(sensor::Sensor *sensor) { vindpm_flag_sensor_ = sensor; }

  void set_wd_flag(bool value);
  void set_wd_flag_sensor(sensor::Sensor *sensor) { wd_flag_sensor_ = sensor; }

  void set_poorsrc_flag(bool value);
  void set_poorsrc_flag_sensor(sensor::Sensor *sensor) { poorsrc_flag_sensor_ = sensor; }

  void set_pg_flag(bool value);
  void set_pg_flag_sensor(sensor::Sensor *sensor) { pg_flag_sensor_ = sensor; }

  void set_ac2_present_flag(bool value);
  void set_ac2_present_flag_sensor(sensor::Sensor *sensor) { ac2_present_flag_sensor_ = sensor; }

  void set_ac1_present_flag(bool value);
  void set_ac1_present_flag_sensor(sensor::Sensor *sensor) { ac1_present_flag_sensor_ = sensor; }

  void set_vbus_present_flag(bool value);
  void set_vbus_present_flag_sensor(sensor::Sensor *sensor) { vbus_present_flag_sensor_ = sensor; }

  void set_chg_flag(bool value);
  void set_chg_flag_sensor(sensor::Sensor *sensor) { chg_flag_sensor_ = sensor; }

  void set_ico_flag(bool value);
  void set_ico_flag_sensor(sensor::Sensor *sensor) { ico_flag_sensor_ = sensor; }

  void set_vbus_flag(bool value);
  void set_vbus_flag_sensor(sensor::Sensor *sensor) { vbus_flag_sensor_ = sensor; }

  void set_treg_flag(bool value);
  void set_treg_flag_sensor(sensor::Sensor *sensor) { treg_flag_sensor_ = sensor; }

  void set_vbat_present_flag(bool value);
  void set_vbat_present_flag_sensor(sensor::Sensor *sensor) { vbat_present_flag_sensor_ = sensor; }

  void set_bc1_2_done_flag(bool value);
  void set_bc1_2_done_flag_sensor(sensor::Sensor *sensor) { bc1_2_done_flag_sensor_ = sensor; }

  void set_dpdm_done_flag(bool value);
  void set_dpdm_done_flag_sensor(sensor::Sensor *sensor) { dpdm_done_flag_sensor_ = sensor; }

  void set_adc_done_flag(bool value);
  void set_adc_done_flag_sensor(sensor::Sensor *sensor) { adc_done_flag_sensor_ = sensor; }

  void set_vsys_flag(bool value);
  void set_vsys_flag_sensor(sensor::Sensor *sensor) { vsys_flag_sensor_ = sensor; }

  void set_chg_tmr_flag(bool value);
  void set_chg_tmr_flag_sensor(sensor::Sensor *sensor) { chg_tmr_flag_sensor_ = sensor; }

  void set_trichg_tmr_flag(bool value);
  void set_trichg_tmr_flag_sensor(sensor::Sensor *sensor) { trichg_tmr_flag_sensor_ = sensor; }

  void set_prechg_tmr_flag(bool value);
  void set_prechg_tmr_flag_sensor(sensor::Sensor *sensor) { prechg_tmr_flag_sensor_ = sensor; }

  void set_topoff_tmr_flag(bool value);
  void set_topoff_tmr_flag_sensor(sensor::Sensor *sensor) { topoff_tmr_flag_sensor_ = sensor; }

  void set_vbatotg_low_flag(bool value);
  void set_vbatotg_low_flag_sensor(sensor::Sensor *sensor) { vbatotg_low_flag_sensor_ = sensor; }

  void set_ts_cold_flag(bool value);
  void set_ts_cold_flag_sensor(sensor::Sensor *sensor) { ts_cold_flag_sensor_ = sensor; }

  void set_ts_cool_flag(bool value);
  void set_ts_cool_flag_sensor(sensor::Sensor *sensor) { ts_cool_flag_sensor_ = sensor; }

  void set_ts_warm_flag(bool value);
  void set_ts_warm_flag_sensor(sensor::Sensor *sensor) { ts_warm_flag_sensor_ = sensor; }

  void set_ts_hot_flag(bool value);
  void set_ts_hot_flag_sensor(sensor::Sensor *sensor) { ts_hot_flag_sensor_ = sensor; }

  void set_ibat_reg_flag(bool value);
  void set_ibat_reg_flag_sensor(sensor::Sensor *sensor) { ibat_reg_flag_sensor_ = sensor; }

  void set_vbus_ovp_flag(bool value);
  void set_vbus_ovp_flag_sensor(sensor::Sensor *sensor) { vbus_ovp_flag_sensor_ = sensor; }

  void set_vbat_ovp_flag(bool value);
  void set_vbat_ovp_flag_sensor(sensor::Sensor *sensor) { vbat_ovp_flag_sensor_ = sensor; }

  void set_ibus_ocp_flag(bool value);
  void set_ibus_ocp_flag_sensor(sensor::Sensor *sensor) { ibus_ocp_flag_sensor_ = sensor; }

  void set_ibat_ocp_flag(bool value);
  void set_ibat_ocp_flag_sensor(sensor::Sensor *sensor) { ibat_ocp_flag_sensor_ = sensor; }

  void set_conv_ocp_flag(bool value);
  void set_conv_ocp_flag_sensor(sensor::Sensor *sensor) { conv_ocp_flag_sensor_ = sensor; }

  void set_vac2_ovp_flag(bool value);
  void set_vac2_ovp_flag_sensor(sensor::Sensor *sensor) { vac2_ovp_flag_sensor_ = sensor; }

  void set_vac1_ovp_flag(bool value);
  void set_vac1_ovp_flag_sensor(sensor::Sensor *sensor) { vac1_ovp_flag_sensor_ = sensor; }

  void set_vsys_short_flag(bool value);
  void set_vsys_short_flag_sensor(sensor::Sensor *sensor) { vsys_short_flag_sensor_ = sensor; }

  void set_vsys_ovp_flag(bool value);
  void set_vsys_ovp_flag_sensor(sensor::Sensor *sensor) { vsys_ovp_flag_sensor_ = sensor; }

  void set_otg_ovp_flag(bool value);
  void set_otg_ovp_flag_sensor(sensor::Sensor *sensor) { otg_ovp_flag_sensor_ = sensor; }

  void set_otg_uvp_flag(bool value);
  void set_otg_uvp_flag_sensor(sensor::Sensor *sensor) { otg_uvp_flag_sensor_ = sensor; }

  void set_tshut_flag(bool value);
  void set_tshut_flag_sensor(sensor::Sensor *sensor) { tshut_flag_sensor_ = sensor; }

  void set_adc_en(bool value);
  void set_adc_en_sensor(sensor::Sensor *sensor) { adc_en_sensor_ = sensor; }

  void set_adc_rate(int value);
  void set_adc_rate_sensor(sensor::Sensor *sensor) { adc_rate_sensor_ = sensor; }

  void set_adc_sample(int value);
  void set_adc_sample_sensor(sensor::Sensor *sensor) { adc_sample_sensor_ = sensor; }

  void set_adc_avg(int value);
  void set_adc_avg_sensor(sensor::Sensor *sensor) { adc_avg_sensor_ = sensor; }

  void set_adc_avg_init(bool value);
  void set_adc_avg_init_sensor(sensor::Sensor *sensor) { adc_avg_init_sensor_ = sensor; }

  void set_ibus_adc_dis(bool value);
  void set_ibus_adc_dis_sensor(sensor::Sensor *sensor) { ibus_adc_dis_sensor_ = sensor; }

  void set_ibat_adc_dis(bool value);
  void set_ibat_adc_dis_sensor(sensor::Sensor *sensor) { ibat_adc_dis_sensor_ = sensor; }

  void set_vbus_adc_dis(bool value);
  void set_vbus_adc_dis_sensor(sensor::Sensor *sensor) { vbus_adc_dis_sensor_ = sensor; }

  void set_vbat_adc_dis(bool value);
  void set_vbat_adc_dis_sensor(sensor::Sensor *sensor) { vbat_adc_dis_sensor_ = sensor; }

  void set_vsys_adc_dis(bool value);
  void set_vsys_adc_dis_sensor(sensor::Sensor *sensor) { vsys_adc_dis_sensor_ = sensor; }

  void set_ts_adc_dis(bool value);
  void set_ts_adc_dis_sensor(sensor::Sensor *sensor) { ts_adc_dis_sensor_ = sensor; }

  void set_tdie_adc_dis(bool value);
  void set_tdie_adc_dis_sensor(sensor::Sensor *sensor) { tdie_adc_dis_sensor_ = sensor; }

  void set_dplus_adc_dis(bool value);
  void set_dplus_adc_dis_sensor(sensor::Sensor *sensor) { dplus_adc_dis_sensor_ = sensor; }

  void set_dminus_adc_dis(bool value);
  void set_dminus_adc_dis_sensor(sensor::Sensor *sensor) { dminus_adc_dis_sensor_ = sensor; }

  void set_vac2_adc_dis(bool value);
  void set_vac2_adc_dis_sensor(sensor::Sensor *sensor) { vac2_adc_dis_sensor_ = sensor; }

  void set_vac1_adc_dis(bool value);
  void set_vac1_adc_dis_sensor(sensor::Sensor *sensor) { vac1_adc_dis_sensor_ = sensor; }

  void set_ibus_adc(int value);
  void set_ibus_adc_sensor(sensor::Sensor *sensor) { ibus_adc_sensor_ = sensor; }

  void set_ibat_adc(int value);
  void set_ibat_adc_sensor(sensor::Sensor *sensor) { ibat_adc_sensor_ = sensor; }

  void set_vbus_adc(int value);
  void set_vbus_adc_sensor(sensor::Sensor *sensor) { vbus_adc_sensor_ = sensor; }

  void set_vac1_adc(int value);
  void set_vac1_adc_sensor(sensor::Sensor *sensor) { vac1_adc_sensor_ = sensor; }

  void set_vac2_adc(int value);
  void set_vac2_adc_sensor(sensor::Sensor *sensor) { vac2_adc_sensor_ = sensor; }

  void set_vbat_adc(int value);
  void set_vbat_adc_sensor(sensor::Sensor *sensor) { vbat_adc_sensor_ = sensor; }

  void set_vsys_adc(int value);
  void set_vsys_adc_sensor(sensor::Sensor *sensor) { vsys_adc_sensor_ = sensor; }

  void set_ts_adc(float value);
  void set_ts_adc_sensor(sensor::Sensor *sensor) { ts_adc_sensor_ = sensor; }

  void set_tdie_adc(float value);
  void set_tdie_adc_sensor(sensor::Sensor *sensor) { tdie_adc_sensor_ = sensor; }

  void set_dplus_adc(int value);
  void set_dplus_adc_sensor(sensor::Sensor *sensor) { dplus_adc_sensor_ = sensor; }

  void set_dminus_adc(int value);
  void set_dminus_adc_sensor(sensor::Sensor *sensor) { dminus_adc_sensor_ = sensor; }

  void set_dplus_dac(int value);
  void set_dplus_dac_sensor(sensor::Sensor *sensor) { dplus_dac_sensor_ = sensor; }

  void set_dminus_dac(int value);
  void set_dminus_dac_sensor(sensor::Sensor *sensor) { dminus_dac_sensor_ = sensor; }

  void set_pn(int value);
  void set_pn_sensor(sensor::Sensor *sensor) { pn_sensor_ = sensor; }

  void set_dev_rev(int value);
  void set_dev_rev_sensor(sensor::Sensor *sensor) { dev_rev_sensor_ = sensor; }


 protected:
  sensor::Sensor *vsysmin_sensor_ {nullptr};

  sensor::Sensor *vreg_sensor_ {nullptr};

  sensor::Sensor *ichg_sensor_ {nullptr};

  sensor::Sensor *vindpm_sensor_ {nullptr};

  sensor::Sensor *iindpm_sensor_ {nullptr};

  sensor::Sensor *vbat_lowv_sensor_ {nullptr};

  sensor::Sensor *iprechg_sensor_ {nullptr};

  sensor::Sensor *reg_rst_sensor_ {nullptr};

  sensor::Sensor *stop_wd_chg_sensor_ {nullptr};

  sensor::Sensor *iterm_sensor_ {nullptr};

  sensor::Sensor *cell_sensor_ {nullptr};

  sensor::Sensor *trechg_sensor_ {nullptr};

  sensor::Sensor *vrechg_sensor_ {nullptr};

  sensor::Sensor *votg_sensor_ {nullptr};

  sensor::Sensor *prechg_tmr_sensor_ {nullptr};

  sensor::Sensor *iotg_sensor_ {nullptr};

  sensor::Sensor *topoff_tmr_sensor_ {nullptr};

  sensor::Sensor *en_trichg_tmr_sensor_ {nullptr};

  sensor::Sensor *en_prechg_tmr_sensor_ {nullptr};

  sensor::Sensor *en_chg_tmr_sensor_ {nullptr};

  sensor::Sensor *chg_tmr_sensor_ {nullptr};

  sensor::Sensor *tmr2x_en_sensor_ {nullptr};

  sensor::Sensor *en_auto_ibatdis_sensor_ {nullptr};

  sensor::Sensor *force_ibatdis_sensor_ {nullptr};

  sensor::Sensor *en_chg_sensor_ {nullptr};

  sensor::Sensor *en_ico_sensor_ {nullptr};

  sensor::Sensor *force_ico_sensor_ {nullptr};

  sensor::Sensor *en_hiz_sensor_ {nullptr};

  sensor::Sensor *en_term_sensor_ {nullptr};

  sensor::Sensor *en_backup_sensor_ {nullptr};

  sensor::Sensor *vbus_backup_sensor_ {nullptr};

  sensor::Sensor *vac_ovp_sensor_ {nullptr};

  sensor::Sensor *wd_rst_sensor_ {nullptr};

  sensor::Sensor *watchdog_sensor_ {nullptr};

  sensor::Sensor *force_indet_sensor_ {nullptr};

  sensor::Sensor *auto_indet_en_sensor_ {nullptr};

  sensor::Sensor *en_12v_sensor_ {nullptr};

  sensor::Sensor *en_9v_sensor_ {nullptr};

  sensor::Sensor *hvdcp_en_sensor_ {nullptr};

  sensor::Sensor *sdrv_ctrl_sensor_ {nullptr};

  sensor::Sensor *sdrv_dly_sensor_ {nullptr};

  sensor::Sensor *dis_acdrv_sensor_ {nullptr};

  sensor::Sensor *en_otg_sensor_ {nullptr};

  sensor::Sensor *pfm_otg_dis_sensor_ {nullptr};

  sensor::Sensor *pfm_fwd_dis_sensor_ {nullptr};

  sensor::Sensor *wkup_dly_sensor_ {nullptr};

  sensor::Sensor *dis_ldo_sensor_ {nullptr};

  sensor::Sensor *dis_otg_ooa_sensor_ {nullptr};

  sensor::Sensor *dis_fwd_ooa_sensor_ {nullptr};

  sensor::Sensor *en_acdrv2_sensor_ {nullptr};

  sensor::Sensor *en_acdrv1_sensor_ {nullptr};

  sensor::Sensor *pwm_freq_sensor_ {nullptr};

  sensor::Sensor *dis_stat_sensor_ {nullptr};

  sensor::Sensor *dis_vsys_short_sensor_ {nullptr};

  sensor::Sensor *dis_votg_uvp_sensor_ {nullptr};

  sensor::Sensor *force_vindpm_det_sensor_ {nullptr};

  sensor::Sensor *en_ibus_ocp_sensor_ {nullptr};

  sensor::Sensor *sfet_present_sensor_ {nullptr};

  sensor::Sensor *en_ibat_sensor_ {nullptr};

  sensor::Sensor *ibat_reg_sensor_ {nullptr};

  sensor::Sensor *en_iindpm_sensor_ {nullptr};

  sensor::Sensor *en_extilim_sensor_ {nullptr};

  sensor::Sensor *en_batoc_sensor_ {nullptr};

  sensor::Sensor *voc_pct_sensor_ {nullptr};

  sensor::Sensor *voc_dly_sensor_ {nullptr};

  sensor::Sensor *voc_rate_sensor_ {nullptr};

  sensor::Sensor *en_mppt_sensor_ {nullptr};

  sensor::Sensor *treg_sensor_ {nullptr};

  sensor::Sensor *tshut_sensor_ {nullptr};

  sensor::Sensor *vbus_pd_en_sensor_ {nullptr};

  sensor::Sensor *vac1_pd_en_sensor_ {nullptr};

  sensor::Sensor *vac2_pd_en_sensor_ {nullptr};

  sensor::Sensor *bkup_acfet1_on_sensor_ {nullptr};

  sensor::Sensor *jeita_vset_sensor_ {nullptr};

  sensor::Sensor *jeita_iseth_sensor_ {nullptr};

  sensor::Sensor *jeita_isetc_sensor_ {nullptr};

  sensor::Sensor *ts_cool_sensor_ {nullptr};

  sensor::Sensor *ts_warm_sensor_ {nullptr};

  sensor::Sensor *bhot_sensor_ {nullptr};

  sensor::Sensor *bcold_sensor_ {nullptr};

  sensor::Sensor *ts_ignore_sensor_ {nullptr};

  sensor::Sensor *ico_ilim_sensor_ {nullptr};

  sensor::Sensor *iindpm_stat_sensor_ {nullptr};

  sensor::Sensor *vindpm_stat_sensor_ {nullptr};

  sensor::Sensor *wd_stat_sensor_ {nullptr};

  sensor::Sensor *pg_stat_sensor_ {nullptr};

  sensor::Sensor *ac2_present_stat_sensor_ {nullptr};

  sensor::Sensor *ac1_present_stat_sensor_ {nullptr};

  sensor::Sensor *vbus_present_stat_sensor_ {nullptr};

  sensor::Sensor *chg_stat_sensor_ {nullptr};

  sensor::Sensor *vbus_stat_sensor_ {nullptr};

  sensor::Sensor *bc12_done_stat_sensor_ {nullptr};

  sensor::Sensor *ico_stat_sensor_ {nullptr};

  sensor::Sensor *treg_stat_sensor_ {nullptr};

  sensor::Sensor *dpdm_stat_sensor_ {nullptr};

  sensor::Sensor *vbat_present_stat_sensor_ {nullptr};

  sensor::Sensor *acrb2_stat_sensor_ {nullptr};

  sensor::Sensor *acrb1_stat_sensor_ {nullptr};

  sensor::Sensor *adc_done_stat_sensor_ {nullptr};

  sensor::Sensor *vsys_stat_sensor_ {nullptr};

  sensor::Sensor *chg_tmr_stat_sensor_ {nullptr};

  sensor::Sensor *trichg_tmr_stat_sensor_ {nullptr};

  sensor::Sensor *prechg_tmr_stat_sensor_ {nullptr};

  sensor::Sensor *vbatotg_low_stat_sensor_ {nullptr};

  sensor::Sensor *ts_cold_stat_sensor_ {nullptr};

  sensor::Sensor *ts_cool_stat_sensor_ {nullptr};

  sensor::Sensor *ts_warm_stat_sensor_ {nullptr};

  sensor::Sensor *ts_hot_stat_sensor_ {nullptr};

  sensor::Sensor *ibat_reg_stat_sensor_ {nullptr};

  sensor::Sensor *vbus_ovp_stat_sensor_ {nullptr};

  sensor::Sensor *vbat_ovp_stat_sensor_ {nullptr};

  sensor::Sensor *ibus_ocp_stat_sensor_ {nullptr};

  sensor::Sensor *ibat_ocp_stat_sensor_ {nullptr};

  sensor::Sensor *conv_ocp_stat_sensor_ {nullptr};

  sensor::Sensor *vac2_ovp_stat_sensor_ {nullptr};

  sensor::Sensor *vac1_ovp_stat_sensor_ {nullptr};

  sensor::Sensor *vsys_short_stat_sensor_ {nullptr};

  sensor::Sensor *vsys_ovp_stat_sensor_ {nullptr};

  sensor::Sensor *otg_ovp_stat_sensor_ {nullptr};

  sensor::Sensor *otg_uvp_stat_sensor_ {nullptr};

  sensor::Sensor *tshut_stat_sensor_ {nullptr};

  sensor::Sensor *iindpm_flag_sensor_ {nullptr};

  sensor::Sensor *vindpm_flag_sensor_ {nullptr};

  sensor::Sensor *wd_flag_sensor_ {nullptr};

  sensor::Sensor *poorsrc_flag_sensor_ {nullptr};

  sensor::Sensor *pg_flag_sensor_ {nullptr};

  sensor::Sensor *ac2_present_flag_sensor_ {nullptr};

  sensor::Sensor *ac1_present_flag_sensor_ {nullptr};

  sensor::Sensor *vbus_present_flag_sensor_ {nullptr};

  sensor::Sensor *chg_flag_sensor_ {nullptr};

  sensor::Sensor *ico_flag_sensor_ {nullptr};

  sensor::Sensor *vbus_flag_sensor_ {nullptr};

  sensor::Sensor *treg_flag_sensor_ {nullptr};

  sensor::Sensor *vbat_present_flag_sensor_ {nullptr};

  sensor::Sensor *bc1_2_done_flag_sensor_ {nullptr};

  sensor::Sensor *dpdm_done_flag_sensor_ {nullptr};

  sensor::Sensor *adc_done_flag_sensor_ {nullptr};

  sensor::Sensor *vsys_flag_sensor_ {nullptr};

  sensor::Sensor *chg_tmr_flag_sensor_ {nullptr};

  sensor::Sensor *trichg_tmr_flag_sensor_ {nullptr};

  sensor::Sensor *prechg_tmr_flag_sensor_ {nullptr};

  sensor::Sensor *topoff_tmr_flag_sensor_ {nullptr};

  sensor::Sensor *vbatotg_low_flag_sensor_ {nullptr};

  sensor::Sensor *ts_cold_flag_sensor_ {nullptr};

  sensor::Sensor *ts_cool_flag_sensor_ {nullptr};

  sensor::Sensor *ts_warm_flag_sensor_ {nullptr};

  sensor::Sensor *ts_hot_flag_sensor_ {nullptr};

  sensor::Sensor *ibat_reg_flag_sensor_ {nullptr};

  sensor::Sensor *vbus_ovp_flag_sensor_ {nullptr};

  sensor::Sensor *vbat_ovp_flag_sensor_ {nullptr};

  sensor::Sensor *ibus_ocp_flag_sensor_ {nullptr};

  sensor::Sensor *ibat_ocp_flag_sensor_ {nullptr};

  sensor::Sensor *conv_ocp_flag_sensor_ {nullptr};

  sensor::Sensor *vac2_ovp_flag_sensor_ {nullptr};

  sensor::Sensor *vac1_ovp_flag_sensor_ {nullptr};

  sensor::Sensor *vsys_short_flag_sensor_ {nullptr};

  sensor::Sensor *vsys_ovp_flag_sensor_ {nullptr};

  sensor::Sensor *otg_ovp_flag_sensor_ {nullptr};

  sensor::Sensor *otg_uvp_flag_sensor_ {nullptr};

  sensor::Sensor *tshut_flag_sensor_ {nullptr};

  sensor::Sensor *adc_en_sensor_ {nullptr};

  sensor::Sensor *adc_rate_sensor_ {nullptr};

  sensor::Sensor *adc_sample_sensor_ {nullptr};

  sensor::Sensor *adc_avg_sensor_ {nullptr};

  sensor::Sensor *adc_avg_init_sensor_ {nullptr};

  sensor::Sensor *ibus_adc_dis_sensor_ {nullptr};

  sensor::Sensor *ibat_adc_dis_sensor_ {nullptr};

  sensor::Sensor *vbus_adc_dis_sensor_ {nullptr};

  sensor::Sensor *vbat_adc_dis_sensor_ {nullptr};

  sensor::Sensor *vsys_adc_dis_sensor_ {nullptr};

  sensor::Sensor *ts_adc_dis_sensor_ {nullptr};

  sensor::Sensor *tdie_adc_dis_sensor_ {nullptr};

  sensor::Sensor *dplus_adc_dis_sensor_ {nullptr};

  sensor::Sensor *dminus_adc_dis_sensor_ {nullptr};

  sensor::Sensor *vac2_adc_dis_sensor_ {nullptr};

  sensor::Sensor *vac1_adc_dis_sensor_ {nullptr};

  sensor::Sensor *ibus_adc_sensor_ {nullptr};

  sensor::Sensor *ibat_adc_sensor_ {nullptr};

  sensor::Sensor *vbus_adc_sensor_ {nullptr};

  sensor::Sensor *vac1_adc_sensor_ {nullptr};

  sensor::Sensor *vac2_adc_sensor_ {nullptr};

  sensor::Sensor *vbat_adc_sensor_ {nullptr};

  sensor::Sensor *vsys_adc_sensor_ {nullptr};

  sensor::Sensor *ts_adc_sensor_ {nullptr};

  sensor::Sensor *tdie_adc_sensor_ {nullptr};

  sensor::Sensor *dplus_adc_sensor_ {nullptr};

  sensor::Sensor *dminus_adc_sensor_ {nullptr};

  sensor::Sensor *dplus_dac_sensor_ {nullptr};

  sensor::Sensor *dminus_dac_sensor_ {nullptr};

  sensor::Sensor *pn_sensor_ {nullptr};

  sensor::Sensor *dev_rev_sensor_ {nullptr};


  private:
    BQ25798ESPHome *bq25798 = BQ25798ESPHome();
};  // class BQ25798Component

}  // namespace bq25798
}  // namespace esphome