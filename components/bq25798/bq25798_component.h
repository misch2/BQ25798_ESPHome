#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/binary_sensor/binary_sensor.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "esphome/components/i2c/i2c.h"

// Relative path to the BQ25798 library because this file is in the "lib" folder on the same level as the "src" folder which PlatformIO's library manager uses to find libraries.
#include "../lib/BQ25798NoI2C/BQ25798NoI2C.h"

#include <cinttypes>

namespace esphome {
namespace bq25798 {

class BQ25798Component : public PollingComponent, public i2c::I2CDevice {
 public:
  void setup() override;
  void dump_config() override;
  float get_setup_priority() const override;
  void update() override;
  void on_init_set_vsysmin(bool value);
  void set_vsysmin(int value, bool write_to_i2c);
  int get_vsysmin(bool read_from_i2c);
  void set_vsysmin_sensor(sensor::Sensor *sensor) { vsysmin_sensor_ = sensor; }

  void on_init_set_vreg(bool value);
  void set_vreg(int value, bool write_to_i2c);
  int get_vreg(bool read_from_i2c);
  void set_vreg_sensor(sensor::Sensor *sensor) { vreg_sensor_ = sensor; }

  void on_init_set_ichg(bool value);
  void set_ichg(int value, bool write_to_i2c);
  int get_ichg(bool read_from_i2c);
  void set_ichg_sensor(sensor::Sensor *sensor) { ichg_sensor_ = sensor; }

  void on_init_set_vindpm(bool value);
  void set_vindpm(int value, bool write_to_i2c);
  int get_vindpm(bool read_from_i2c);
  void set_vindpm_sensor(sensor::Sensor *sensor) { vindpm_sensor_ = sensor; }

  void on_init_set_iindpm(bool value);
  void set_iindpm(int value, bool write_to_i2c);
  int get_iindpm(bool read_from_i2c);
  void set_iindpm_sensor(sensor::Sensor *sensor) { iindpm_sensor_ = sensor; }

  void on_init_set_vbat_lowv(bool value);
  void set_vbat_lowv(int value, bool write_to_i2c);
  int get_vbat_lowv(bool read_from_i2c);
  const char* get_vbat_lowv_string(bool read_from_i2c);
  void set_vbat_lowv_sensor(sensor::Sensor *sensor) { vbat_lowv_sensor_ = sensor; }
  void set_vbat_lowv_text_sensor(text_sensor::TextSensor *sensor) { vbat_lowv_text_sensor_ = sensor; }

  void on_init_set_iprechg(bool value);
  void set_iprechg(int value, bool write_to_i2c);
  int get_iprechg(bool read_from_i2c);
  void set_iprechg_sensor(sensor::Sensor *sensor) { iprechg_sensor_ = sensor; }

  void on_init_set_reg_rst(bool value);
  void set_reg_rst(bool value, bool write_to_i2c);
  bool get_reg_rst(bool read_from_i2c);
  void set_reg_rst_binary_sensor(binary_sensor::BinarySensor *sensor) { reg_rst_binary_sensor_ = sensor; }

  void on_init_set_stop_wd_chg(bool value);
  void set_stop_wd_chg(bool value, bool write_to_i2c);
  bool get_stop_wd_chg(bool read_from_i2c);
  void set_stop_wd_chg_binary_sensor(binary_sensor::BinarySensor *sensor) { stop_wd_chg_binary_sensor_ = sensor; }

  void on_init_set_iterm(bool value);
  void set_iterm(int value, bool write_to_i2c);
  int get_iterm(bool read_from_i2c);
  void set_iterm_sensor(sensor::Sensor *sensor) { iterm_sensor_ = sensor; }

  void on_init_set_cell(bool value);
  void set_cell(int value, bool write_to_i2c);
  int get_cell(bool read_from_i2c);
  const char* get_cell_string(bool read_from_i2c);
  void set_cell_sensor(sensor::Sensor *sensor) { cell_sensor_ = sensor; }
  void set_cell_text_sensor(text_sensor::TextSensor *sensor) { cell_text_sensor_ = sensor; }

  void on_init_set_trechg(bool value);
  void set_trechg(int value, bool write_to_i2c);
  int get_trechg(bool read_from_i2c);
  const char* get_trechg_string(bool read_from_i2c);
  void set_trechg_sensor(sensor::Sensor *sensor) { trechg_sensor_ = sensor; }
  void set_trechg_text_sensor(text_sensor::TextSensor *sensor) { trechg_text_sensor_ = sensor; }

  void on_init_set_vrechg(bool value);
  void set_vrechg(int value, bool write_to_i2c);
  int get_vrechg(bool read_from_i2c);
  void set_vrechg_sensor(sensor::Sensor *sensor) { vrechg_sensor_ = sensor; }

  void on_init_set_votg(bool value);
  void set_votg(int value, bool write_to_i2c);
  int get_votg(bool read_from_i2c);
  void set_votg_sensor(sensor::Sensor *sensor) { votg_sensor_ = sensor; }

  void on_init_set_prechg_tmr(bool value);
  void set_prechg_tmr(int value, bool write_to_i2c);
  int get_prechg_tmr(bool read_from_i2c);
  const char* get_prechg_tmr_string(bool read_from_i2c);
  void set_prechg_tmr_sensor(sensor::Sensor *sensor) { prechg_tmr_sensor_ = sensor; }
  void set_prechg_tmr_text_sensor(text_sensor::TextSensor *sensor) { prechg_tmr_text_sensor_ = sensor; }

  void on_init_set_iotg(bool value);
  void set_iotg(int value, bool write_to_i2c);
  int get_iotg(bool read_from_i2c);
  void set_iotg_sensor(sensor::Sensor *sensor) { iotg_sensor_ = sensor; }

  void on_init_set_topoff_tmr(bool value);
  void set_topoff_tmr(int value, bool write_to_i2c);
  int get_topoff_tmr(bool read_from_i2c);
  const char* get_topoff_tmr_string(bool read_from_i2c);
  void set_topoff_tmr_sensor(sensor::Sensor *sensor) { topoff_tmr_sensor_ = sensor; }
  void set_topoff_tmr_text_sensor(text_sensor::TextSensor *sensor) { topoff_tmr_text_sensor_ = sensor; }

  void on_init_set_en_trichg_tmr(bool value);
  void set_en_trichg_tmr(bool value, bool write_to_i2c);
  bool get_en_trichg_tmr(bool read_from_i2c);
  void set_en_trichg_tmr_binary_sensor(binary_sensor::BinarySensor *sensor) { en_trichg_tmr_binary_sensor_ = sensor; }

  void on_init_set_en_prechg_tmr(bool value);
  void set_en_prechg_tmr(bool value, bool write_to_i2c);
  bool get_en_prechg_tmr(bool read_from_i2c);
  void set_en_prechg_tmr_binary_sensor(binary_sensor::BinarySensor *sensor) { en_prechg_tmr_binary_sensor_ = sensor; }

  void on_init_set_en_chg_tmr(bool value);
  void set_en_chg_tmr(bool value, bool write_to_i2c);
  bool get_en_chg_tmr(bool read_from_i2c);
  void set_en_chg_tmr_binary_sensor(binary_sensor::BinarySensor *sensor) { en_chg_tmr_binary_sensor_ = sensor; }

  void on_init_set_chg_tmr(bool value);
  void set_chg_tmr(int value, bool write_to_i2c);
  int get_chg_tmr(bool read_from_i2c);
  const char* get_chg_tmr_string(bool read_from_i2c);
  void set_chg_tmr_sensor(sensor::Sensor *sensor) { chg_tmr_sensor_ = sensor; }
  void set_chg_tmr_text_sensor(text_sensor::TextSensor *sensor) { chg_tmr_text_sensor_ = sensor; }

  void on_init_set_tmr2x_en(bool value);
  void set_tmr2x_en(bool value, bool write_to_i2c);
  bool get_tmr2x_en(bool read_from_i2c);
  void set_tmr2x_en_binary_sensor(binary_sensor::BinarySensor *sensor) { tmr2x_en_binary_sensor_ = sensor; }

  void on_init_set_en_auto_ibatdis(bool value);
  void set_en_auto_ibatdis(bool value, bool write_to_i2c);
  bool get_en_auto_ibatdis(bool read_from_i2c);
  void set_en_auto_ibatdis_binary_sensor(binary_sensor::BinarySensor *sensor) { en_auto_ibatdis_binary_sensor_ = sensor; }

  void on_init_set_force_ibatdis(bool value);
  void set_force_ibatdis(bool value, bool write_to_i2c);
  bool get_force_ibatdis(bool read_from_i2c);
  void set_force_ibatdis_binary_sensor(binary_sensor::BinarySensor *sensor) { force_ibatdis_binary_sensor_ = sensor; }

  void on_init_set_en_chg(bool value);
  void set_en_chg(bool value, bool write_to_i2c);
  bool get_en_chg(bool read_from_i2c);
  void set_en_chg_binary_sensor(binary_sensor::BinarySensor *sensor) { en_chg_binary_sensor_ = sensor; }

  void on_init_set_en_ico(bool value);
  void set_en_ico(bool value, bool write_to_i2c);
  bool get_en_ico(bool read_from_i2c);
  void set_en_ico_binary_sensor(binary_sensor::BinarySensor *sensor) { en_ico_binary_sensor_ = sensor; }

  void on_init_set_force_ico(bool value);
  void set_force_ico(bool value, bool write_to_i2c);
  bool get_force_ico(bool read_from_i2c);
  void set_force_ico_binary_sensor(binary_sensor::BinarySensor *sensor) { force_ico_binary_sensor_ = sensor; }

  void on_init_set_en_hiz(bool value);
  void set_en_hiz(bool value, bool write_to_i2c);
  bool get_en_hiz(bool read_from_i2c);
  void set_en_hiz_binary_sensor(binary_sensor::BinarySensor *sensor) { en_hiz_binary_sensor_ = sensor; }

  void on_init_set_en_term(bool value);
  void set_en_term(bool value, bool write_to_i2c);
  bool get_en_term(bool read_from_i2c);
  void set_en_term_binary_sensor(binary_sensor::BinarySensor *sensor) { en_term_binary_sensor_ = sensor; }

  void on_init_set_en_backup(bool value);
  void set_en_backup(bool value, bool write_to_i2c);
  bool get_en_backup(bool read_from_i2c);
  void set_en_backup_binary_sensor(binary_sensor::BinarySensor *sensor) { en_backup_binary_sensor_ = sensor; }

  void on_init_set_vbus_backup(bool value);
  void set_vbus_backup(int value, bool write_to_i2c);
  int get_vbus_backup(bool read_from_i2c);
  const char* get_vbus_backup_string(bool read_from_i2c);
  void set_vbus_backup_sensor(sensor::Sensor *sensor) { vbus_backup_sensor_ = sensor; }
  void set_vbus_backup_text_sensor(text_sensor::TextSensor *sensor) { vbus_backup_text_sensor_ = sensor; }

  void on_init_set_vac_ovp(bool value);
  void set_vac_ovp(int value, bool write_to_i2c);
  int get_vac_ovp(bool read_from_i2c);
  const char* get_vac_ovp_string(bool read_from_i2c);
  void set_vac_ovp_sensor(sensor::Sensor *sensor) { vac_ovp_sensor_ = sensor; }
  void set_vac_ovp_text_sensor(text_sensor::TextSensor *sensor) { vac_ovp_text_sensor_ = sensor; }

  void on_init_set_wd_rst(bool value);
  void set_wd_rst(bool value, bool write_to_i2c);
  bool get_wd_rst(bool read_from_i2c);
  void set_wd_rst_binary_sensor(binary_sensor::BinarySensor *sensor) { wd_rst_binary_sensor_ = sensor; }

  void on_init_set_watchdog(bool value);
  void set_watchdog(int value, bool write_to_i2c);
  int get_watchdog(bool read_from_i2c);
  const char* get_watchdog_string(bool read_from_i2c);
  void set_watchdog_sensor(sensor::Sensor *sensor) { watchdog_sensor_ = sensor; }
  void set_watchdog_text_sensor(text_sensor::TextSensor *sensor) { watchdog_text_sensor_ = sensor; }

  void on_init_set_force_indet(bool value);
  void set_force_indet(bool value, bool write_to_i2c);
  bool get_force_indet(bool read_from_i2c);
  void set_force_indet_binary_sensor(binary_sensor::BinarySensor *sensor) { force_indet_binary_sensor_ = sensor; }

  void on_init_set_auto_indet_en(bool value);
  void set_auto_indet_en(bool value, bool write_to_i2c);
  bool get_auto_indet_en(bool read_from_i2c);
  void set_auto_indet_en_binary_sensor(binary_sensor::BinarySensor *sensor) { auto_indet_en_binary_sensor_ = sensor; }

  void on_init_set_en_12v(bool value);
  void set_en_12v(bool value, bool write_to_i2c);
  bool get_en_12v(bool read_from_i2c);
  void set_en_12v_binary_sensor(binary_sensor::BinarySensor *sensor) { en_12v_binary_sensor_ = sensor; }

  void on_init_set_en_9v(bool value);
  void set_en_9v(bool value, bool write_to_i2c);
  bool get_en_9v(bool read_from_i2c);
  void set_en_9v_binary_sensor(binary_sensor::BinarySensor *sensor) { en_9v_binary_sensor_ = sensor; }

  void on_init_set_hvdcp_en(bool value);
  void set_hvdcp_en(bool value, bool write_to_i2c);
  bool get_hvdcp_en(bool read_from_i2c);
  void set_hvdcp_en_binary_sensor(binary_sensor::BinarySensor *sensor) { hvdcp_en_binary_sensor_ = sensor; }

  void on_init_set_sdrv_ctrl(bool value);
  void set_sdrv_ctrl(int value, bool write_to_i2c);
  int get_sdrv_ctrl(bool read_from_i2c);
  const char* get_sdrv_ctrl_string(bool read_from_i2c);
  void set_sdrv_ctrl_sensor(sensor::Sensor *sensor) { sdrv_ctrl_sensor_ = sensor; }
  void set_sdrv_ctrl_text_sensor(text_sensor::TextSensor *sensor) { sdrv_ctrl_text_sensor_ = sensor; }

  void on_init_set_sdrv_dly(bool value);
  void set_sdrv_dly(int value, bool write_to_i2c);
  int get_sdrv_dly(bool read_from_i2c);
  const char* get_sdrv_dly_string(bool read_from_i2c);
  void set_sdrv_dly_sensor(sensor::Sensor *sensor) { sdrv_dly_sensor_ = sensor; }
  void set_sdrv_dly_text_sensor(text_sensor::TextSensor *sensor) { sdrv_dly_text_sensor_ = sensor; }

  void on_init_set_dis_acdrv(bool value);
  void set_dis_acdrv(bool value, bool write_to_i2c);
  bool get_dis_acdrv(bool read_from_i2c);
  void set_dis_acdrv_binary_sensor(binary_sensor::BinarySensor *sensor) { dis_acdrv_binary_sensor_ = sensor; }

  void on_init_set_en_otg(bool value);
  void set_en_otg(bool value, bool write_to_i2c);
  bool get_en_otg(bool read_from_i2c);
  void set_en_otg_binary_sensor(binary_sensor::BinarySensor *sensor) { en_otg_binary_sensor_ = sensor; }

  void on_init_set_pfm_otg_dis(bool value);
  void set_pfm_otg_dis(bool value, bool write_to_i2c);
  bool get_pfm_otg_dis(bool read_from_i2c);
  void set_pfm_otg_dis_binary_sensor(binary_sensor::BinarySensor *sensor) { pfm_otg_dis_binary_sensor_ = sensor; }

  void on_init_set_pfm_fwd_dis(bool value);
  void set_pfm_fwd_dis(bool value, bool write_to_i2c);
  bool get_pfm_fwd_dis(bool read_from_i2c);
  void set_pfm_fwd_dis_binary_sensor(binary_sensor::BinarySensor *sensor) { pfm_fwd_dis_binary_sensor_ = sensor; }

  void on_init_set_wkup_dly(bool value);
  void set_wkup_dly(int value, bool write_to_i2c);
  int get_wkup_dly(bool read_from_i2c);
  const char* get_wkup_dly_string(bool read_from_i2c);
  void set_wkup_dly_sensor(sensor::Sensor *sensor) { wkup_dly_sensor_ = sensor; }
  void set_wkup_dly_text_sensor(text_sensor::TextSensor *sensor) { wkup_dly_text_sensor_ = sensor; }

  void on_init_set_dis_ldo(bool value);
  void set_dis_ldo(bool value, bool write_to_i2c);
  bool get_dis_ldo(bool read_from_i2c);
  void set_dis_ldo_binary_sensor(binary_sensor::BinarySensor *sensor) { dis_ldo_binary_sensor_ = sensor; }

  void on_init_set_dis_otg_ooa(bool value);
  void set_dis_otg_ooa(bool value, bool write_to_i2c);
  bool get_dis_otg_ooa(bool read_from_i2c);
  void set_dis_otg_ooa_binary_sensor(binary_sensor::BinarySensor *sensor) { dis_otg_ooa_binary_sensor_ = sensor; }

  void on_init_set_dis_fwd_ooa(bool value);
  void set_dis_fwd_ooa(bool value, bool write_to_i2c);
  bool get_dis_fwd_ooa(bool read_from_i2c);
  void set_dis_fwd_ooa_binary_sensor(binary_sensor::BinarySensor *sensor) { dis_fwd_ooa_binary_sensor_ = sensor; }

  void on_init_set_en_acdrv2(bool value);
  void set_en_acdrv2(bool value, bool write_to_i2c);
  bool get_en_acdrv2(bool read_from_i2c);
  void set_en_acdrv2_binary_sensor(binary_sensor::BinarySensor *sensor) { en_acdrv2_binary_sensor_ = sensor; }

  void on_init_set_en_acdrv1(bool value);
  void set_en_acdrv1(bool value, bool write_to_i2c);
  bool get_en_acdrv1(bool read_from_i2c);
  void set_en_acdrv1_binary_sensor(binary_sensor::BinarySensor *sensor) { en_acdrv1_binary_sensor_ = sensor; }

  void on_init_set_pwm_freq(bool value);
  void set_pwm_freq(int value, bool write_to_i2c);
  int get_pwm_freq(bool read_from_i2c);
  const char* get_pwm_freq_string(bool read_from_i2c);
  void set_pwm_freq_sensor(sensor::Sensor *sensor) { pwm_freq_sensor_ = sensor; }
  void set_pwm_freq_text_sensor(text_sensor::TextSensor *sensor) { pwm_freq_text_sensor_ = sensor; }

  void on_init_set_dis_stat(bool value);
  void set_dis_stat(bool value, bool write_to_i2c);
  bool get_dis_stat(bool read_from_i2c);
  void set_dis_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { dis_stat_binary_sensor_ = sensor; }

  void on_init_set_dis_vsys_short(bool value);
  void set_dis_vsys_short(bool value, bool write_to_i2c);
  bool get_dis_vsys_short(bool read_from_i2c);
  void set_dis_vsys_short_binary_sensor(binary_sensor::BinarySensor *sensor) { dis_vsys_short_binary_sensor_ = sensor; }

  void on_init_set_dis_votg_uvp(bool value);
  void set_dis_votg_uvp(bool value, bool write_to_i2c);
  bool get_dis_votg_uvp(bool read_from_i2c);
  void set_dis_votg_uvp_binary_sensor(binary_sensor::BinarySensor *sensor) { dis_votg_uvp_binary_sensor_ = sensor; }

  void on_init_set_force_vindpm_det(bool value);
  void set_force_vindpm_det(bool value, bool write_to_i2c);
  bool get_force_vindpm_det(bool read_from_i2c);
  void set_force_vindpm_det_binary_sensor(binary_sensor::BinarySensor *sensor) { force_vindpm_det_binary_sensor_ = sensor; }

  void on_init_set_en_ibus_ocp(bool value);
  void set_en_ibus_ocp(bool value, bool write_to_i2c);
  bool get_en_ibus_ocp(bool read_from_i2c);
  void set_en_ibus_ocp_binary_sensor(binary_sensor::BinarySensor *sensor) { en_ibus_ocp_binary_sensor_ = sensor; }

  void on_init_set_sfet_present(bool value);
  void set_sfet_present(bool value, bool write_to_i2c);
  bool get_sfet_present(bool read_from_i2c);
  void set_sfet_present_binary_sensor(binary_sensor::BinarySensor *sensor) { sfet_present_binary_sensor_ = sensor; }

  void on_init_set_en_ibat(bool value);
  void set_en_ibat(bool value, bool write_to_i2c);
  bool get_en_ibat(bool read_from_i2c);
  void set_en_ibat_binary_sensor(binary_sensor::BinarySensor *sensor) { en_ibat_binary_sensor_ = sensor; }

  void on_init_set_ibat_reg(bool value);
  void set_ibat_reg(int value, bool write_to_i2c);
  int get_ibat_reg(bool read_from_i2c);
  const char* get_ibat_reg_string(bool read_from_i2c);
  void set_ibat_reg_sensor(sensor::Sensor *sensor) { ibat_reg_sensor_ = sensor; }
  void set_ibat_reg_text_sensor(text_sensor::TextSensor *sensor) { ibat_reg_text_sensor_ = sensor; }

  void on_init_set_en_iindpm(bool value);
  void set_en_iindpm(bool value, bool write_to_i2c);
  bool get_en_iindpm(bool read_from_i2c);
  void set_en_iindpm_binary_sensor(binary_sensor::BinarySensor *sensor) { en_iindpm_binary_sensor_ = sensor; }

  void on_init_set_en_extilim(bool value);
  void set_en_extilim(bool value, bool write_to_i2c);
  bool get_en_extilim(bool read_from_i2c);
  void set_en_extilim_binary_sensor(binary_sensor::BinarySensor *sensor) { en_extilim_binary_sensor_ = sensor; }

  void on_init_set_en_batoc(bool value);
  void set_en_batoc(bool value, bool write_to_i2c);
  bool get_en_batoc(bool read_from_i2c);
  void set_en_batoc_binary_sensor(binary_sensor::BinarySensor *sensor) { en_batoc_binary_sensor_ = sensor; }

  void on_init_set_voc_pct(bool value);
  void set_voc_pct(int value, bool write_to_i2c);
  int get_voc_pct(bool read_from_i2c);
  const char* get_voc_pct_string(bool read_from_i2c);
  void set_voc_pct_sensor(sensor::Sensor *sensor) { voc_pct_sensor_ = sensor; }
  void set_voc_pct_text_sensor(text_sensor::TextSensor *sensor) { voc_pct_text_sensor_ = sensor; }

  void on_init_set_voc_dly(bool value);
  void set_voc_dly(int value, bool write_to_i2c);
  int get_voc_dly(bool read_from_i2c);
  const char* get_voc_dly_string(bool read_from_i2c);
  void set_voc_dly_sensor(sensor::Sensor *sensor) { voc_dly_sensor_ = sensor; }
  void set_voc_dly_text_sensor(text_sensor::TextSensor *sensor) { voc_dly_text_sensor_ = sensor; }

  void on_init_set_voc_rate(bool value);
  void set_voc_rate(int value, bool write_to_i2c);
  int get_voc_rate(bool read_from_i2c);
  const char* get_voc_rate_string(bool read_from_i2c);
  void set_voc_rate_sensor(sensor::Sensor *sensor) { voc_rate_sensor_ = sensor; }
  void set_voc_rate_text_sensor(text_sensor::TextSensor *sensor) { voc_rate_text_sensor_ = sensor; }

  void on_init_set_en_mppt(bool value);
  void set_en_mppt(bool value, bool write_to_i2c);
  bool get_en_mppt(bool read_from_i2c);
  void set_en_mppt_binary_sensor(binary_sensor::BinarySensor *sensor) { en_mppt_binary_sensor_ = sensor; }

  void on_init_set_treg(bool value);
  void set_treg(int value, bool write_to_i2c);
  int get_treg(bool read_from_i2c);
  const char* get_treg_string(bool read_from_i2c);
  void set_treg_sensor(sensor::Sensor *sensor) { treg_sensor_ = sensor; }
  void set_treg_text_sensor(text_sensor::TextSensor *sensor) { treg_text_sensor_ = sensor; }

  void on_init_set_tshut(bool value);
  void set_tshut(int value, bool write_to_i2c);
  int get_tshut(bool read_from_i2c);
  const char* get_tshut_string(bool read_from_i2c);
  void set_tshut_sensor(sensor::Sensor *sensor) { tshut_sensor_ = sensor; }
  void set_tshut_text_sensor(text_sensor::TextSensor *sensor) { tshut_text_sensor_ = sensor; }

  void on_init_set_vbus_pd_en(bool value);
  void set_vbus_pd_en(bool value, bool write_to_i2c);
  bool get_vbus_pd_en(bool read_from_i2c);
  void set_vbus_pd_en_binary_sensor(binary_sensor::BinarySensor *sensor) { vbus_pd_en_binary_sensor_ = sensor; }

  void on_init_set_vac1_pd_en(bool value);
  void set_vac1_pd_en(bool value, bool write_to_i2c);
  bool get_vac1_pd_en(bool read_from_i2c);
  void set_vac1_pd_en_binary_sensor(binary_sensor::BinarySensor *sensor) { vac1_pd_en_binary_sensor_ = sensor; }

  void on_init_set_vac2_pd_en(bool value);
  void set_vac2_pd_en(bool value, bool write_to_i2c);
  bool get_vac2_pd_en(bool read_from_i2c);
  void set_vac2_pd_en_binary_sensor(binary_sensor::BinarySensor *sensor) { vac2_pd_en_binary_sensor_ = sensor; }

  void on_init_set_bkup_acfet1_on(bool value);
  void set_bkup_acfet1_on(int value, bool write_to_i2c);
  int get_bkup_acfet1_on(bool read_from_i2c);
  const char* get_bkup_acfet1_on_string(bool read_from_i2c);
  void set_bkup_acfet1_on_sensor(sensor::Sensor *sensor) { bkup_acfet1_on_sensor_ = sensor; }
  void set_bkup_acfet1_on_text_sensor(text_sensor::TextSensor *sensor) { bkup_acfet1_on_text_sensor_ = sensor; }

  void on_init_set_jeita_vset(bool value);
  void set_jeita_vset(int value, bool write_to_i2c);
  int get_jeita_vset(bool read_from_i2c);
  const char* get_jeita_vset_string(bool read_from_i2c);
  void set_jeita_vset_sensor(sensor::Sensor *sensor) { jeita_vset_sensor_ = sensor; }
  void set_jeita_vset_text_sensor(text_sensor::TextSensor *sensor) { jeita_vset_text_sensor_ = sensor; }

  void on_init_set_jeita_iseth(bool value);
  void set_jeita_iseth(int value, bool write_to_i2c);
  int get_jeita_iseth(bool read_from_i2c);
  const char* get_jeita_iseth_string(bool read_from_i2c);
  void set_jeita_iseth_sensor(sensor::Sensor *sensor) { jeita_iseth_sensor_ = sensor; }
  void set_jeita_iseth_text_sensor(text_sensor::TextSensor *sensor) { jeita_iseth_text_sensor_ = sensor; }

  void on_init_set_jeita_isetc(bool value);
  void set_jeita_isetc(int value, bool write_to_i2c);
  int get_jeita_isetc(bool read_from_i2c);
  const char* get_jeita_isetc_string(bool read_from_i2c);
  void set_jeita_isetc_sensor(sensor::Sensor *sensor) { jeita_isetc_sensor_ = sensor; }
  void set_jeita_isetc_text_sensor(text_sensor::TextSensor *sensor) { jeita_isetc_text_sensor_ = sensor; }

  void on_init_set_ts_cool(bool value);
  void set_ts_cool(int value, bool write_to_i2c);
  int get_ts_cool(bool read_from_i2c);
  const char* get_ts_cool_string(bool read_from_i2c);
  void set_ts_cool_sensor(sensor::Sensor *sensor) { ts_cool_sensor_ = sensor; }
  void set_ts_cool_text_sensor(text_sensor::TextSensor *sensor) { ts_cool_text_sensor_ = sensor; }

  void on_init_set_ts_warm(bool value);
  void set_ts_warm(int value, bool write_to_i2c);
  int get_ts_warm(bool read_from_i2c);
  const char* get_ts_warm_string(bool read_from_i2c);
  void set_ts_warm_sensor(sensor::Sensor *sensor) { ts_warm_sensor_ = sensor; }
  void set_ts_warm_text_sensor(text_sensor::TextSensor *sensor) { ts_warm_text_sensor_ = sensor; }

  void on_init_set_bhot(bool value);
  void set_bhot(int value, bool write_to_i2c);
  int get_bhot(bool read_from_i2c);
  const char* get_bhot_string(bool read_from_i2c);
  void set_bhot_sensor(sensor::Sensor *sensor) { bhot_sensor_ = sensor; }
  void set_bhot_text_sensor(text_sensor::TextSensor *sensor) { bhot_text_sensor_ = sensor; }

  void on_init_set_bcold(bool value);
  void set_bcold(int value, bool write_to_i2c);
  int get_bcold(bool read_from_i2c);
  const char* get_bcold_string(bool read_from_i2c);
  void set_bcold_sensor(sensor::Sensor *sensor) { bcold_sensor_ = sensor; }
  void set_bcold_text_sensor(text_sensor::TextSensor *sensor) { bcold_text_sensor_ = sensor; }

  void on_init_set_ts_ignore(bool value);
  void set_ts_ignore(bool value, bool write_to_i2c);
  bool get_ts_ignore(bool read_from_i2c);
  void set_ts_ignore_binary_sensor(binary_sensor::BinarySensor *sensor) { ts_ignore_binary_sensor_ = sensor; }

  int get_ico_ilim(bool read_from_i2c);
  void set_ico_ilim_sensor(sensor::Sensor *sensor) { ico_ilim_sensor_ = sensor; }

  int get_iindpm_stat(bool read_from_i2c);
  const char* get_iindpm_stat_string(bool read_from_i2c);
  void set_iindpm_stat_sensor(sensor::Sensor *sensor) { iindpm_stat_sensor_ = sensor; }
  void set_iindpm_stat_text_sensor(text_sensor::TextSensor *sensor) { iindpm_stat_text_sensor_ = sensor; }

  int get_vindpm_stat(bool read_from_i2c);
  const char* get_vindpm_stat_string(bool read_from_i2c);
  void set_vindpm_stat_sensor(sensor::Sensor *sensor) { vindpm_stat_sensor_ = sensor; }
  void set_vindpm_stat_text_sensor(text_sensor::TextSensor *sensor) { vindpm_stat_text_sensor_ = sensor; }

  int get_wd_stat(bool read_from_i2c);
  const char* get_wd_stat_string(bool read_from_i2c);
  void set_wd_stat_sensor(sensor::Sensor *sensor) { wd_stat_sensor_ = sensor; }
  void set_wd_stat_text_sensor(text_sensor::TextSensor *sensor) { wd_stat_text_sensor_ = sensor; }

  int get_pg_stat(bool read_from_i2c);
  const char* get_pg_stat_string(bool read_from_i2c);
  void set_pg_stat_sensor(sensor::Sensor *sensor) { pg_stat_sensor_ = sensor; }
  void set_pg_stat_text_sensor(text_sensor::TextSensor *sensor) { pg_stat_text_sensor_ = sensor; }

  int get_ac2_present_stat(bool read_from_i2c);
  const char* get_ac2_present_stat_string(bool read_from_i2c);
  void set_ac2_present_stat_sensor(sensor::Sensor *sensor) { ac2_present_stat_sensor_ = sensor; }
  void set_ac2_present_stat_text_sensor(text_sensor::TextSensor *sensor) { ac2_present_stat_text_sensor_ = sensor; }

  int get_ac1_present_stat(bool read_from_i2c);
  const char* get_ac1_present_stat_string(bool read_from_i2c);
  void set_ac1_present_stat_sensor(sensor::Sensor *sensor) { ac1_present_stat_sensor_ = sensor; }
  void set_ac1_present_stat_text_sensor(text_sensor::TextSensor *sensor) { ac1_present_stat_text_sensor_ = sensor; }

  int get_vbus_present_stat(bool read_from_i2c);
  const char* get_vbus_present_stat_string(bool read_from_i2c);
  void set_vbus_present_stat_sensor(sensor::Sensor *sensor) { vbus_present_stat_sensor_ = sensor; }
  void set_vbus_present_stat_text_sensor(text_sensor::TextSensor *sensor) { vbus_present_stat_text_sensor_ = sensor; }

  int get_chg_stat(bool read_from_i2c);
  const char* get_chg_stat_string(bool read_from_i2c);
  void set_chg_stat_sensor(sensor::Sensor *sensor) { chg_stat_sensor_ = sensor; }
  void set_chg_stat_text_sensor(text_sensor::TextSensor *sensor) { chg_stat_text_sensor_ = sensor; }

  int get_vbus_stat(bool read_from_i2c);
  const char* get_vbus_stat_string(bool read_from_i2c);
  void set_vbus_stat_sensor(sensor::Sensor *sensor) { vbus_stat_sensor_ = sensor; }
  void set_vbus_stat_text_sensor(text_sensor::TextSensor *sensor) { vbus_stat_text_sensor_ = sensor; }

  bool get_bc12_done_stat(bool read_from_i2c);
  void set_bc12_done_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { bc12_done_stat_binary_sensor_ = sensor; }

  int get_ico_stat(bool read_from_i2c);
  const char* get_ico_stat_string(bool read_from_i2c);
  void set_ico_stat_sensor(sensor::Sensor *sensor) { ico_stat_sensor_ = sensor; }
  void set_ico_stat_text_sensor(text_sensor::TextSensor *sensor) { ico_stat_text_sensor_ = sensor; }

  int get_treg_stat(bool read_from_i2c);
  const char* get_treg_stat_string(bool read_from_i2c);
  void set_treg_stat_sensor(sensor::Sensor *sensor) { treg_stat_sensor_ = sensor; }
  void set_treg_stat_text_sensor(text_sensor::TextSensor *sensor) { treg_stat_text_sensor_ = sensor; }

  int get_dpdm_stat(bool read_from_i2c);
  const char* get_dpdm_stat_string(bool read_from_i2c);
  void set_dpdm_stat_sensor(sensor::Sensor *sensor) { dpdm_stat_sensor_ = sensor; }
  void set_dpdm_stat_text_sensor(text_sensor::TextSensor *sensor) { dpdm_stat_text_sensor_ = sensor; }

  int get_vbat_present_stat(bool read_from_i2c);
  const char* get_vbat_present_stat_string(bool read_from_i2c);
  void set_vbat_present_stat_sensor(sensor::Sensor *sensor) { vbat_present_stat_sensor_ = sensor; }
  void set_vbat_present_stat_text_sensor(text_sensor::TextSensor *sensor) { vbat_present_stat_text_sensor_ = sensor; }

  bool get_acrb2_stat(bool read_from_i2c);
  void set_acrb2_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { acrb2_stat_binary_sensor_ = sensor; }

  bool get_acrb1_stat(bool read_from_i2c);
  void set_acrb1_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { acrb1_stat_binary_sensor_ = sensor; }

  bool get_adc_done_stat(bool read_from_i2c);
  void set_adc_done_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { adc_done_stat_binary_sensor_ = sensor; }

  int get_vsys_stat(bool read_from_i2c);
  const char* get_vsys_stat_string(bool read_from_i2c);
  void set_vsys_stat_sensor(sensor::Sensor *sensor) { vsys_stat_sensor_ = sensor; }
  void set_vsys_stat_text_sensor(text_sensor::TextSensor *sensor) { vsys_stat_text_sensor_ = sensor; }

  int get_chg_tmr_stat(bool read_from_i2c);
  const char* get_chg_tmr_stat_string(bool read_from_i2c);
  void set_chg_tmr_stat_sensor(sensor::Sensor *sensor) { chg_tmr_stat_sensor_ = sensor; }
  void set_chg_tmr_stat_text_sensor(text_sensor::TextSensor *sensor) { chg_tmr_stat_text_sensor_ = sensor; }

  int get_trichg_tmr_stat(bool read_from_i2c);
  const char* get_trichg_tmr_stat_string(bool read_from_i2c);
  void set_trichg_tmr_stat_sensor(sensor::Sensor *sensor) { trichg_tmr_stat_sensor_ = sensor; }
  void set_trichg_tmr_stat_text_sensor(text_sensor::TextSensor *sensor) { trichg_tmr_stat_text_sensor_ = sensor; }

  int get_prechg_tmr_stat(bool read_from_i2c);
  const char* get_prechg_tmr_stat_string(bool read_from_i2c);
  void set_prechg_tmr_stat_sensor(sensor::Sensor *sensor) { prechg_tmr_stat_sensor_ = sensor; }
  void set_prechg_tmr_stat_text_sensor(text_sensor::TextSensor *sensor) { prechg_tmr_stat_text_sensor_ = sensor; }

  int get_vbatotg_low_stat(bool read_from_i2c);
  const char* get_vbatotg_low_stat_string(bool read_from_i2c);
  void set_vbatotg_low_stat_sensor(sensor::Sensor *sensor) { vbatotg_low_stat_sensor_ = sensor; }
  void set_vbatotg_low_stat_text_sensor(text_sensor::TextSensor *sensor) { vbatotg_low_stat_text_sensor_ = sensor; }

  int get_ts_cold_stat(bool read_from_i2c);
  const char* get_ts_cold_stat_string(bool read_from_i2c);
  void set_ts_cold_stat_sensor(sensor::Sensor *sensor) { ts_cold_stat_sensor_ = sensor; }
  void set_ts_cold_stat_text_sensor(text_sensor::TextSensor *sensor) { ts_cold_stat_text_sensor_ = sensor; }

  int get_ts_cool_stat(bool read_from_i2c);
  const char* get_ts_cool_stat_string(bool read_from_i2c);
  void set_ts_cool_stat_sensor(sensor::Sensor *sensor) { ts_cool_stat_sensor_ = sensor; }
  void set_ts_cool_stat_text_sensor(text_sensor::TextSensor *sensor) { ts_cool_stat_text_sensor_ = sensor; }

  int get_ts_warm_stat(bool read_from_i2c);
  const char* get_ts_warm_stat_string(bool read_from_i2c);
  void set_ts_warm_stat_sensor(sensor::Sensor *sensor) { ts_warm_stat_sensor_ = sensor; }
  void set_ts_warm_stat_text_sensor(text_sensor::TextSensor *sensor) { ts_warm_stat_text_sensor_ = sensor; }

  int get_ts_hot_stat(bool read_from_i2c);
  const char* get_ts_hot_stat_string(bool read_from_i2c);
  void set_ts_hot_stat_sensor(sensor::Sensor *sensor) { ts_hot_stat_sensor_ = sensor; }
  void set_ts_hot_stat_text_sensor(text_sensor::TextSensor *sensor) { ts_hot_stat_text_sensor_ = sensor; }

  bool get_ibat_reg_stat(bool read_from_i2c);
  void set_ibat_reg_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { ibat_reg_stat_binary_sensor_ = sensor; }

  bool get_vbus_ovp_stat(bool read_from_i2c);
  void set_vbus_ovp_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { vbus_ovp_stat_binary_sensor_ = sensor; }

  bool get_vbat_ovp_stat(bool read_from_i2c);
  void set_vbat_ovp_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { vbat_ovp_stat_binary_sensor_ = sensor; }

  bool get_ibus_ocp_stat(bool read_from_i2c);
  void set_ibus_ocp_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { ibus_ocp_stat_binary_sensor_ = sensor; }

  bool get_ibat_ocp_stat(bool read_from_i2c);
  void set_ibat_ocp_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { ibat_ocp_stat_binary_sensor_ = sensor; }

  bool get_conv_ocp_stat(bool read_from_i2c);
  void set_conv_ocp_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { conv_ocp_stat_binary_sensor_ = sensor; }

  bool get_vac2_ovp_stat(bool read_from_i2c);
  void set_vac2_ovp_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { vac2_ovp_stat_binary_sensor_ = sensor; }

  bool get_vac1_ovp_stat(bool read_from_i2c);
  void set_vac1_ovp_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { vac1_ovp_stat_binary_sensor_ = sensor; }

  bool get_vsys_short_stat(bool read_from_i2c);
  void set_vsys_short_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { vsys_short_stat_binary_sensor_ = sensor; }

  bool get_vsys_ovp_stat(bool read_from_i2c);
  void set_vsys_ovp_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { vsys_ovp_stat_binary_sensor_ = sensor; }

  bool get_otg_ovp_stat(bool read_from_i2c);
  void set_otg_ovp_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { otg_ovp_stat_binary_sensor_ = sensor; }

  bool get_otg_uvp_stat(bool read_from_i2c);
  void set_otg_uvp_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { otg_uvp_stat_binary_sensor_ = sensor; }

  bool get_tshut_stat(bool read_from_i2c);
  void set_tshut_stat_binary_sensor(binary_sensor::BinarySensor *sensor) { tshut_stat_binary_sensor_ = sensor; }

  bool get_iindpm_flag(bool read_from_i2c);
  void set_iindpm_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { iindpm_flag_binary_sensor_ = sensor; }
  void clear_flag_iindpm_flag() { iindpm_flag_ = false; }
  void raise_flag_iindpm_flag() { iindpm_flag_ = true; }

  bool get_vindpm_flag(bool read_from_i2c);
  void set_vindpm_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { vindpm_flag_binary_sensor_ = sensor; }
  void clear_flag_vindpm_flag() { vindpm_flag_ = false; }
  void raise_flag_vindpm_flag() { vindpm_flag_ = true; }

  bool get_wd_flag(bool read_from_i2c);
  void set_wd_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { wd_flag_binary_sensor_ = sensor; }
  void clear_flag_wd_flag() { wd_flag_ = false; }
  void raise_flag_wd_flag() { wd_flag_ = true; }

  bool get_poorsrc_flag(bool read_from_i2c);
  void set_poorsrc_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { poorsrc_flag_binary_sensor_ = sensor; }
  void clear_flag_poorsrc_flag() { poorsrc_flag_ = false; }
  void raise_flag_poorsrc_flag() { poorsrc_flag_ = true; }

  bool get_pg_flag(bool read_from_i2c);
  void set_pg_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { pg_flag_binary_sensor_ = sensor; }
  void clear_flag_pg_flag() { pg_flag_ = false; }
  void raise_flag_pg_flag() { pg_flag_ = true; }

  bool get_ac2_present_flag(bool read_from_i2c);
  void set_ac2_present_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { ac2_present_flag_binary_sensor_ = sensor; }
  void clear_flag_ac2_present_flag() { ac2_present_flag_ = false; }
  void raise_flag_ac2_present_flag() { ac2_present_flag_ = true; }

  bool get_ac1_present_flag(bool read_from_i2c);
  void set_ac1_present_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { ac1_present_flag_binary_sensor_ = sensor; }
  void clear_flag_ac1_present_flag() { ac1_present_flag_ = false; }
  void raise_flag_ac1_present_flag() { ac1_present_flag_ = true; }

  bool get_vbus_present_flag(bool read_from_i2c);
  void set_vbus_present_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { vbus_present_flag_binary_sensor_ = sensor; }
  void clear_flag_vbus_present_flag() { vbus_present_flag_ = false; }
  void raise_flag_vbus_present_flag() { vbus_present_flag_ = true; }

  bool get_chg_flag(bool read_from_i2c);
  void set_chg_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { chg_flag_binary_sensor_ = sensor; }
  void clear_flag_chg_flag() { chg_flag_ = false; }
  void raise_flag_chg_flag() { chg_flag_ = true; }

  bool get_ico_flag(bool read_from_i2c);
  void set_ico_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { ico_flag_binary_sensor_ = sensor; }
  void clear_flag_ico_flag() { ico_flag_ = false; }
  void raise_flag_ico_flag() { ico_flag_ = true; }

  bool get_vbus_flag(bool read_from_i2c);
  void set_vbus_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { vbus_flag_binary_sensor_ = sensor; }
  void clear_flag_vbus_flag() { vbus_flag_ = false; }
  void raise_flag_vbus_flag() { vbus_flag_ = true; }

  bool get_treg_flag(bool read_from_i2c);
  void set_treg_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { treg_flag_binary_sensor_ = sensor; }
  void clear_flag_treg_flag() { treg_flag_ = false; }
  void raise_flag_treg_flag() { treg_flag_ = true; }

  bool get_vbat_present_flag(bool read_from_i2c);
  void set_vbat_present_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { vbat_present_flag_binary_sensor_ = sensor; }
  void clear_flag_vbat_present_flag() { vbat_present_flag_ = false; }
  void raise_flag_vbat_present_flag() { vbat_present_flag_ = true; }

  bool get_bc1_2_done_flag(bool read_from_i2c);
  void set_bc1_2_done_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { bc1_2_done_flag_binary_sensor_ = sensor; }
  void clear_flag_bc1_2_done_flag() { bc1_2_done_flag_ = false; }
  void raise_flag_bc1_2_done_flag() { bc1_2_done_flag_ = true; }

  bool get_dpdm_done_flag(bool read_from_i2c);
  void set_dpdm_done_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { dpdm_done_flag_binary_sensor_ = sensor; }
  void clear_flag_dpdm_done_flag() { dpdm_done_flag_ = false; }
  void raise_flag_dpdm_done_flag() { dpdm_done_flag_ = true; }

  bool get_adc_done_flag(bool read_from_i2c);
  void set_adc_done_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { adc_done_flag_binary_sensor_ = sensor; }
  void clear_flag_adc_done_flag() { adc_done_flag_ = false; }
  void raise_flag_adc_done_flag() { adc_done_flag_ = true; }

  bool get_vsys_flag(bool read_from_i2c);
  void set_vsys_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { vsys_flag_binary_sensor_ = sensor; }
  void clear_flag_vsys_flag() { vsys_flag_ = false; }
  void raise_flag_vsys_flag() { vsys_flag_ = true; }

  bool get_chg_tmr_flag(bool read_from_i2c);
  void set_chg_tmr_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { chg_tmr_flag_binary_sensor_ = sensor; }
  void clear_flag_chg_tmr_flag() { chg_tmr_flag_ = false; }
  void raise_flag_chg_tmr_flag() { chg_tmr_flag_ = true; }

  bool get_trichg_tmr_flag(bool read_from_i2c);
  void set_trichg_tmr_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { trichg_tmr_flag_binary_sensor_ = sensor; }
  void clear_flag_trichg_tmr_flag() { trichg_tmr_flag_ = false; }
  void raise_flag_trichg_tmr_flag() { trichg_tmr_flag_ = true; }

  bool get_prechg_tmr_flag(bool read_from_i2c);
  void set_prechg_tmr_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { prechg_tmr_flag_binary_sensor_ = sensor; }
  void clear_flag_prechg_tmr_flag() { prechg_tmr_flag_ = false; }
  void raise_flag_prechg_tmr_flag() { prechg_tmr_flag_ = true; }

  bool get_topoff_tmr_flag(bool read_from_i2c);
  void set_topoff_tmr_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { topoff_tmr_flag_binary_sensor_ = sensor; }
  void clear_flag_topoff_tmr_flag() { topoff_tmr_flag_ = false; }
  void raise_flag_topoff_tmr_flag() { topoff_tmr_flag_ = true; }

  bool get_vbatotg_low_flag(bool read_from_i2c);
  void set_vbatotg_low_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { vbatotg_low_flag_binary_sensor_ = sensor; }
  void clear_flag_vbatotg_low_flag() { vbatotg_low_flag_ = false; }
  void raise_flag_vbatotg_low_flag() { vbatotg_low_flag_ = true; }

  bool get_ts_cold_flag(bool read_from_i2c);
  void set_ts_cold_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { ts_cold_flag_binary_sensor_ = sensor; }
  void clear_flag_ts_cold_flag() { ts_cold_flag_ = false; }
  void raise_flag_ts_cold_flag() { ts_cold_flag_ = true; }

  bool get_ts_cool_flag(bool read_from_i2c);
  void set_ts_cool_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { ts_cool_flag_binary_sensor_ = sensor; }
  void clear_flag_ts_cool_flag() { ts_cool_flag_ = false; }
  void raise_flag_ts_cool_flag() { ts_cool_flag_ = true; }

  bool get_ts_warm_flag(bool read_from_i2c);
  void set_ts_warm_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { ts_warm_flag_binary_sensor_ = sensor; }
  void clear_flag_ts_warm_flag() { ts_warm_flag_ = false; }
  void raise_flag_ts_warm_flag() { ts_warm_flag_ = true; }

  bool get_ts_hot_flag(bool read_from_i2c);
  void set_ts_hot_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { ts_hot_flag_binary_sensor_ = sensor; }
  void clear_flag_ts_hot_flag() { ts_hot_flag_ = false; }
  void raise_flag_ts_hot_flag() { ts_hot_flag_ = true; }

  bool get_ibat_reg_flag(bool read_from_i2c);
  void set_ibat_reg_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { ibat_reg_flag_binary_sensor_ = sensor; }
  void clear_flag_ibat_reg_flag() { ibat_reg_flag_ = false; }
  void raise_flag_ibat_reg_flag() { ibat_reg_flag_ = true; }

  bool get_vbus_ovp_flag(bool read_from_i2c);
  void set_vbus_ovp_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { vbus_ovp_flag_binary_sensor_ = sensor; }
  void clear_flag_vbus_ovp_flag() { vbus_ovp_flag_ = false; }
  void raise_flag_vbus_ovp_flag() { vbus_ovp_flag_ = true; }

  bool get_vbat_ovp_flag(bool read_from_i2c);
  void set_vbat_ovp_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { vbat_ovp_flag_binary_sensor_ = sensor; }
  void clear_flag_vbat_ovp_flag() { vbat_ovp_flag_ = false; }
  void raise_flag_vbat_ovp_flag() { vbat_ovp_flag_ = true; }

  bool get_ibus_ocp_flag(bool read_from_i2c);
  void set_ibus_ocp_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { ibus_ocp_flag_binary_sensor_ = sensor; }
  void clear_flag_ibus_ocp_flag() { ibus_ocp_flag_ = false; }
  void raise_flag_ibus_ocp_flag() { ibus_ocp_flag_ = true; }

  bool get_ibat_ocp_flag(bool read_from_i2c);
  void set_ibat_ocp_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { ibat_ocp_flag_binary_sensor_ = sensor; }
  void clear_flag_ibat_ocp_flag() { ibat_ocp_flag_ = false; }
  void raise_flag_ibat_ocp_flag() { ibat_ocp_flag_ = true; }

  bool get_conv_ocp_flag(bool read_from_i2c);
  void set_conv_ocp_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { conv_ocp_flag_binary_sensor_ = sensor; }
  void clear_flag_conv_ocp_flag() { conv_ocp_flag_ = false; }
  void raise_flag_conv_ocp_flag() { conv_ocp_flag_ = true; }

  bool get_vac2_ovp_flag(bool read_from_i2c);
  void set_vac2_ovp_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { vac2_ovp_flag_binary_sensor_ = sensor; }
  void clear_flag_vac2_ovp_flag() { vac2_ovp_flag_ = false; }
  void raise_flag_vac2_ovp_flag() { vac2_ovp_flag_ = true; }

  bool get_vac1_ovp_flag(bool read_from_i2c);
  void set_vac1_ovp_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { vac1_ovp_flag_binary_sensor_ = sensor; }
  void clear_flag_vac1_ovp_flag() { vac1_ovp_flag_ = false; }
  void raise_flag_vac1_ovp_flag() { vac1_ovp_flag_ = true; }

  bool get_vsys_short_flag(bool read_from_i2c);
  void set_vsys_short_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { vsys_short_flag_binary_sensor_ = sensor; }
  void clear_flag_vsys_short_flag() { vsys_short_flag_ = false; }
  void raise_flag_vsys_short_flag() { vsys_short_flag_ = true; }

  bool get_vsys_ovp_flag(bool read_from_i2c);
  void set_vsys_ovp_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { vsys_ovp_flag_binary_sensor_ = sensor; }
  void clear_flag_vsys_ovp_flag() { vsys_ovp_flag_ = false; }
  void raise_flag_vsys_ovp_flag() { vsys_ovp_flag_ = true; }

  bool get_otg_ovp_flag(bool read_from_i2c);
  void set_otg_ovp_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { otg_ovp_flag_binary_sensor_ = sensor; }
  void clear_flag_otg_ovp_flag() { otg_ovp_flag_ = false; }
  void raise_flag_otg_ovp_flag() { otg_ovp_flag_ = true; }

  bool get_otg_uvp_flag(bool read_from_i2c);
  void set_otg_uvp_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { otg_uvp_flag_binary_sensor_ = sensor; }
  void clear_flag_otg_uvp_flag() { otg_uvp_flag_ = false; }
  void raise_flag_otg_uvp_flag() { otg_uvp_flag_ = true; }

  bool get_tshut_flag(bool read_from_i2c);
  void set_tshut_flag_binary_sensor(binary_sensor::BinarySensor *sensor) { tshut_flag_binary_sensor_ = sensor; }
  void clear_flag_tshut_flag() { tshut_flag_ = false; }
  void raise_flag_tshut_flag() { tshut_flag_ = true; }

  void on_init_set_adc_en(bool value);
  void set_adc_en(bool value, bool write_to_i2c);
  bool get_adc_en(bool read_from_i2c);
  void set_adc_en_binary_sensor(binary_sensor::BinarySensor *sensor) { adc_en_binary_sensor_ = sensor; }

  void on_init_set_adc_rate(bool value);
  void set_adc_rate(int value, bool write_to_i2c);
  int get_adc_rate(bool read_from_i2c);
  const char* get_adc_rate_string(bool read_from_i2c);
  void set_adc_rate_sensor(sensor::Sensor *sensor) { adc_rate_sensor_ = sensor; }
  void set_adc_rate_text_sensor(text_sensor::TextSensor *sensor) { adc_rate_text_sensor_ = sensor; }

  void on_init_set_adc_sample(bool value);
  void set_adc_sample(int value, bool write_to_i2c);
  int get_adc_sample(bool read_from_i2c);
  const char* get_adc_sample_string(bool read_from_i2c);
  void set_adc_sample_sensor(sensor::Sensor *sensor) { adc_sample_sensor_ = sensor; }
  void set_adc_sample_text_sensor(text_sensor::TextSensor *sensor) { adc_sample_text_sensor_ = sensor; }

  void on_init_set_adc_avg(bool value);
  void set_adc_avg(int value, bool write_to_i2c);
  int get_adc_avg(bool read_from_i2c);
  const char* get_adc_avg_string(bool read_from_i2c);
  void set_adc_avg_sensor(sensor::Sensor *sensor) { adc_avg_sensor_ = sensor; }
  void set_adc_avg_text_sensor(text_sensor::TextSensor *sensor) { adc_avg_text_sensor_ = sensor; }

  void on_init_set_adc_avg_init(bool value);
  void set_adc_avg_init(bool value, bool write_to_i2c);
  bool get_adc_avg_init(bool read_from_i2c);
  void set_adc_avg_init_binary_sensor(binary_sensor::BinarySensor *sensor) { adc_avg_init_binary_sensor_ = sensor; }

  void on_init_set_ibus_adc_dis(bool value);
  void set_ibus_adc_dis(bool value, bool write_to_i2c);
  bool get_ibus_adc_dis(bool read_from_i2c);
  void set_ibus_adc_dis_binary_sensor(binary_sensor::BinarySensor *sensor) { ibus_adc_dis_binary_sensor_ = sensor; }

  void on_init_set_ibat_adc_dis(bool value);
  void set_ibat_adc_dis(bool value, bool write_to_i2c);
  bool get_ibat_adc_dis(bool read_from_i2c);
  void set_ibat_adc_dis_binary_sensor(binary_sensor::BinarySensor *sensor) { ibat_adc_dis_binary_sensor_ = sensor; }

  void on_init_set_vbus_adc_dis(bool value);
  void set_vbus_adc_dis(bool value, bool write_to_i2c);
  bool get_vbus_adc_dis(bool read_from_i2c);
  void set_vbus_adc_dis_binary_sensor(binary_sensor::BinarySensor *sensor) { vbus_adc_dis_binary_sensor_ = sensor; }

  void on_init_set_vbat_adc_dis(bool value);
  void set_vbat_adc_dis(bool value, bool write_to_i2c);
  bool get_vbat_adc_dis(bool read_from_i2c);
  void set_vbat_adc_dis_binary_sensor(binary_sensor::BinarySensor *sensor) { vbat_adc_dis_binary_sensor_ = sensor; }

  void on_init_set_vsys_adc_dis(bool value);
  void set_vsys_adc_dis(bool value, bool write_to_i2c);
  bool get_vsys_adc_dis(bool read_from_i2c);
  void set_vsys_adc_dis_binary_sensor(binary_sensor::BinarySensor *sensor) { vsys_adc_dis_binary_sensor_ = sensor; }

  void on_init_set_ts_adc_dis(bool value);
  void set_ts_adc_dis(bool value, bool write_to_i2c);
  bool get_ts_adc_dis(bool read_from_i2c);
  void set_ts_adc_dis_binary_sensor(binary_sensor::BinarySensor *sensor) { ts_adc_dis_binary_sensor_ = sensor; }

  void on_init_set_tdie_adc_dis(bool value);
  void set_tdie_adc_dis(bool value, bool write_to_i2c);
  bool get_tdie_adc_dis(bool read_from_i2c);
  void set_tdie_adc_dis_binary_sensor(binary_sensor::BinarySensor *sensor) { tdie_adc_dis_binary_sensor_ = sensor; }

  void on_init_set_dplus_adc_dis(bool value);
  void set_dplus_adc_dis(bool value, bool write_to_i2c);
  bool get_dplus_adc_dis(bool read_from_i2c);
  void set_dplus_adc_dis_binary_sensor(binary_sensor::BinarySensor *sensor) { dplus_adc_dis_binary_sensor_ = sensor; }

  void on_init_set_dminus_adc_dis(bool value);
  void set_dminus_adc_dis(bool value, bool write_to_i2c);
  bool get_dminus_adc_dis(bool read_from_i2c);
  void set_dminus_adc_dis_binary_sensor(binary_sensor::BinarySensor *sensor) { dminus_adc_dis_binary_sensor_ = sensor; }

  void on_init_set_vac2_adc_dis(bool value);
  void set_vac2_adc_dis(bool value, bool write_to_i2c);
  bool get_vac2_adc_dis(bool read_from_i2c);
  void set_vac2_adc_dis_binary_sensor(binary_sensor::BinarySensor *sensor) { vac2_adc_dis_binary_sensor_ = sensor; }

  void on_init_set_vac1_adc_dis(bool value);
  void set_vac1_adc_dis(bool value, bool write_to_i2c);
  bool get_vac1_adc_dis(bool read_from_i2c);
  void set_vac1_adc_dis_binary_sensor(binary_sensor::BinarySensor *sensor) { vac1_adc_dis_binary_sensor_ = sensor; }

  int get_ibus_adc(bool read_from_i2c);
  void set_ibus_adc_sensor(sensor::Sensor *sensor) { ibus_adc_sensor_ = sensor; }

  int get_ibat_adc(bool read_from_i2c);
  void set_ibat_adc_sensor(sensor::Sensor *sensor) { ibat_adc_sensor_ = sensor; }

  int get_vbus_adc(bool read_from_i2c);
  void set_vbus_adc_sensor(sensor::Sensor *sensor) { vbus_adc_sensor_ = sensor; }

  int get_vac1_adc(bool read_from_i2c);
  void set_vac1_adc_sensor(sensor::Sensor *sensor) { vac1_adc_sensor_ = sensor; }

  int get_vac2_adc(bool read_from_i2c);
  void set_vac2_adc_sensor(sensor::Sensor *sensor) { vac2_adc_sensor_ = sensor; }

  int get_vbat_adc(bool read_from_i2c);
  void set_vbat_adc_sensor(sensor::Sensor *sensor) { vbat_adc_sensor_ = sensor; }

  int get_vsys_adc(bool read_from_i2c);
  void set_vsys_adc_sensor(sensor::Sensor *sensor) { vsys_adc_sensor_ = sensor; }

  float get_ts_adc(bool read_from_i2c);
  void set_ts_adc_sensor(sensor::Sensor *sensor) { ts_adc_sensor_ = sensor; }

  float get_tdie_adc(bool read_from_i2c);
  void set_tdie_adc_sensor(sensor::Sensor *sensor) { tdie_adc_sensor_ = sensor; }

  int get_dplus_adc(bool read_from_i2c);
  void set_dplus_adc_sensor(sensor::Sensor *sensor) { dplus_adc_sensor_ = sensor; }

  int get_dminus_adc(bool read_from_i2c);
  void set_dminus_adc_sensor(sensor::Sensor *sensor) { dminus_adc_sensor_ = sensor; }

  void on_init_set_dplus_dac(bool value);
  void set_dplus_dac(int value, bool write_to_i2c);
  int get_dplus_dac(bool read_from_i2c);
  const char* get_dplus_dac_string(bool read_from_i2c);
  void set_dplus_dac_sensor(sensor::Sensor *sensor) { dplus_dac_sensor_ = sensor; }
  void set_dplus_dac_text_sensor(text_sensor::TextSensor *sensor) { dplus_dac_text_sensor_ = sensor; }

  void on_init_set_dminus_dac(bool value);
  void set_dminus_dac(int value, bool write_to_i2c);
  int get_dminus_dac(bool read_from_i2c);
  const char* get_dminus_dac_string(bool read_from_i2c);
  void set_dminus_dac_sensor(sensor::Sensor *sensor) { dminus_dac_sensor_ = sensor; }
  void set_dminus_dac_text_sensor(text_sensor::TextSensor *sensor) { dminus_dac_text_sensor_ = sensor; }

  int get_pn(bool read_from_i2c);
  const char* get_pn_string(bool read_from_i2c);
  void set_pn_sensor(sensor::Sensor *sensor) { pn_sensor_ = sensor; }
  void set_pn_text_sensor(text_sensor::TextSensor *sensor) { pn_text_sensor_ = sensor; }

  int get_dev_rev(bool read_from_i2c);
  const char* get_dev_rev_string(bool read_from_i2c);
  void set_dev_rev_sensor(sensor::Sensor *sensor) { dev_rev_sensor_ = sensor; }
  void set_dev_rev_text_sensor(text_sensor::TextSensor *sensor) { dev_rev_text_sensor_ = sensor; }


 protected:
  int vsysmin_ = 0;
  bool on_init_set_vsysmin_ = false;
  sensor::Sensor *vsysmin_sensor_ {nullptr};


  int vreg_ = 0;
  bool on_init_set_vreg_ = false;
  sensor::Sensor *vreg_sensor_ {nullptr};


  int ichg_ = 0;
  bool on_init_set_ichg_ = false;
  sensor::Sensor *ichg_sensor_ {nullptr};


  int vindpm_ = 0;
  bool on_init_set_vindpm_ = false;
  sensor::Sensor *vindpm_sensor_ {nullptr};


  int iindpm_ = 0;
  bool on_init_set_iindpm_ = false;
  sensor::Sensor *iindpm_sensor_ {nullptr};


  int vbat_lowv_ = 0;
  bool on_init_set_vbat_lowv_ = false;
  sensor::Sensor *vbat_lowv_sensor_ {nullptr};
  text_sensor::TextSensor *vbat_lowv_text_sensor_ {nullptr};


  int iprechg_ = 0;
  bool on_init_set_iprechg_ = false;
  sensor::Sensor *iprechg_sensor_ {nullptr};


  bool reg_rst_ = false;
  bool on_init_set_reg_rst_ = false;
  binary_sensor::BinarySensor *reg_rst_binary_sensor_ {nullptr};


  bool stop_wd_chg_ = false;
  bool on_init_set_stop_wd_chg_ = false;
  binary_sensor::BinarySensor *stop_wd_chg_binary_sensor_ {nullptr};


  int iterm_ = 0;
  bool on_init_set_iterm_ = false;
  sensor::Sensor *iterm_sensor_ {nullptr};


  int cell_ = 0;
  bool on_init_set_cell_ = false;
  sensor::Sensor *cell_sensor_ {nullptr};
  text_sensor::TextSensor *cell_text_sensor_ {nullptr};


  int trechg_ = 0;
  bool on_init_set_trechg_ = false;
  sensor::Sensor *trechg_sensor_ {nullptr};
  text_sensor::TextSensor *trechg_text_sensor_ {nullptr};


  int vrechg_ = 0;
  bool on_init_set_vrechg_ = false;
  sensor::Sensor *vrechg_sensor_ {nullptr};


  int votg_ = 0;
  bool on_init_set_votg_ = false;
  sensor::Sensor *votg_sensor_ {nullptr};


  int prechg_tmr_ = 0;
  bool on_init_set_prechg_tmr_ = false;
  sensor::Sensor *prechg_tmr_sensor_ {nullptr};
  text_sensor::TextSensor *prechg_tmr_text_sensor_ {nullptr};


  int iotg_ = 0;
  bool on_init_set_iotg_ = false;
  sensor::Sensor *iotg_sensor_ {nullptr};


  int topoff_tmr_ = 0;
  bool on_init_set_topoff_tmr_ = false;
  sensor::Sensor *topoff_tmr_sensor_ {nullptr};
  text_sensor::TextSensor *topoff_tmr_text_sensor_ {nullptr};


  bool en_trichg_tmr_ = false;
  bool on_init_set_en_trichg_tmr_ = false;
  binary_sensor::BinarySensor *en_trichg_tmr_binary_sensor_ {nullptr};


  bool en_prechg_tmr_ = false;
  bool on_init_set_en_prechg_tmr_ = false;
  binary_sensor::BinarySensor *en_prechg_tmr_binary_sensor_ {nullptr};


  bool en_chg_tmr_ = false;
  bool on_init_set_en_chg_tmr_ = false;
  binary_sensor::BinarySensor *en_chg_tmr_binary_sensor_ {nullptr};


  int chg_tmr_ = 0;
  bool on_init_set_chg_tmr_ = false;
  sensor::Sensor *chg_tmr_sensor_ {nullptr};
  text_sensor::TextSensor *chg_tmr_text_sensor_ {nullptr};


  bool tmr2x_en_ = false;
  bool on_init_set_tmr2x_en_ = false;
  binary_sensor::BinarySensor *tmr2x_en_binary_sensor_ {nullptr};


  bool en_auto_ibatdis_ = false;
  bool on_init_set_en_auto_ibatdis_ = false;
  binary_sensor::BinarySensor *en_auto_ibatdis_binary_sensor_ {nullptr};


  bool force_ibatdis_ = false;
  bool on_init_set_force_ibatdis_ = false;
  binary_sensor::BinarySensor *force_ibatdis_binary_sensor_ {nullptr};


  bool en_chg_ = false;
  bool on_init_set_en_chg_ = false;
  binary_sensor::BinarySensor *en_chg_binary_sensor_ {nullptr};


  bool en_ico_ = false;
  bool on_init_set_en_ico_ = false;
  binary_sensor::BinarySensor *en_ico_binary_sensor_ {nullptr};


  bool force_ico_ = false;
  bool on_init_set_force_ico_ = false;
  binary_sensor::BinarySensor *force_ico_binary_sensor_ {nullptr};


  bool en_hiz_ = false;
  bool on_init_set_en_hiz_ = false;
  binary_sensor::BinarySensor *en_hiz_binary_sensor_ {nullptr};


  bool en_term_ = false;
  bool on_init_set_en_term_ = false;
  binary_sensor::BinarySensor *en_term_binary_sensor_ {nullptr};


  bool en_backup_ = false;
  bool on_init_set_en_backup_ = false;
  binary_sensor::BinarySensor *en_backup_binary_sensor_ {nullptr};


  int vbus_backup_ = 0;
  bool on_init_set_vbus_backup_ = false;
  sensor::Sensor *vbus_backup_sensor_ {nullptr};
  text_sensor::TextSensor *vbus_backup_text_sensor_ {nullptr};


  int vac_ovp_ = 0;
  bool on_init_set_vac_ovp_ = false;
  sensor::Sensor *vac_ovp_sensor_ {nullptr};
  text_sensor::TextSensor *vac_ovp_text_sensor_ {nullptr};


  bool wd_rst_ = false;
  bool on_init_set_wd_rst_ = false;
  binary_sensor::BinarySensor *wd_rst_binary_sensor_ {nullptr};


  int watchdog_ = 0;
  bool on_init_set_watchdog_ = false;
  sensor::Sensor *watchdog_sensor_ {nullptr};
  text_sensor::TextSensor *watchdog_text_sensor_ {nullptr};


  bool force_indet_ = false;
  bool on_init_set_force_indet_ = false;
  binary_sensor::BinarySensor *force_indet_binary_sensor_ {nullptr};


  bool auto_indet_en_ = false;
  bool on_init_set_auto_indet_en_ = false;
  binary_sensor::BinarySensor *auto_indet_en_binary_sensor_ {nullptr};


  bool en_12v_ = false;
  bool on_init_set_en_12v_ = false;
  binary_sensor::BinarySensor *en_12v_binary_sensor_ {nullptr};


  bool en_9v_ = false;
  bool on_init_set_en_9v_ = false;
  binary_sensor::BinarySensor *en_9v_binary_sensor_ {nullptr};


  bool hvdcp_en_ = false;
  bool on_init_set_hvdcp_en_ = false;
  binary_sensor::BinarySensor *hvdcp_en_binary_sensor_ {nullptr};


  int sdrv_ctrl_ = 0;
  bool on_init_set_sdrv_ctrl_ = false;
  sensor::Sensor *sdrv_ctrl_sensor_ {nullptr};
  text_sensor::TextSensor *sdrv_ctrl_text_sensor_ {nullptr};


  int sdrv_dly_ = 0;
  bool on_init_set_sdrv_dly_ = false;
  sensor::Sensor *sdrv_dly_sensor_ {nullptr};
  text_sensor::TextSensor *sdrv_dly_text_sensor_ {nullptr};


  bool dis_acdrv_ = false;
  bool on_init_set_dis_acdrv_ = false;
  binary_sensor::BinarySensor *dis_acdrv_binary_sensor_ {nullptr};


  bool en_otg_ = false;
  bool on_init_set_en_otg_ = false;
  binary_sensor::BinarySensor *en_otg_binary_sensor_ {nullptr};


  bool pfm_otg_dis_ = false;
  bool on_init_set_pfm_otg_dis_ = false;
  binary_sensor::BinarySensor *pfm_otg_dis_binary_sensor_ {nullptr};


  bool pfm_fwd_dis_ = false;
  bool on_init_set_pfm_fwd_dis_ = false;
  binary_sensor::BinarySensor *pfm_fwd_dis_binary_sensor_ {nullptr};


  int wkup_dly_ = 0;
  bool on_init_set_wkup_dly_ = false;
  sensor::Sensor *wkup_dly_sensor_ {nullptr};
  text_sensor::TextSensor *wkup_dly_text_sensor_ {nullptr};


  bool dis_ldo_ = false;
  bool on_init_set_dis_ldo_ = false;
  binary_sensor::BinarySensor *dis_ldo_binary_sensor_ {nullptr};


  bool dis_otg_ooa_ = false;
  bool on_init_set_dis_otg_ooa_ = false;
  binary_sensor::BinarySensor *dis_otg_ooa_binary_sensor_ {nullptr};


  bool dis_fwd_ooa_ = false;
  bool on_init_set_dis_fwd_ooa_ = false;
  binary_sensor::BinarySensor *dis_fwd_ooa_binary_sensor_ {nullptr};


  bool en_acdrv2_ = false;
  bool on_init_set_en_acdrv2_ = false;
  binary_sensor::BinarySensor *en_acdrv2_binary_sensor_ {nullptr};


  bool en_acdrv1_ = false;
  bool on_init_set_en_acdrv1_ = false;
  binary_sensor::BinarySensor *en_acdrv1_binary_sensor_ {nullptr};


  int pwm_freq_ = 0;
  bool on_init_set_pwm_freq_ = false;
  sensor::Sensor *pwm_freq_sensor_ {nullptr};
  text_sensor::TextSensor *pwm_freq_text_sensor_ {nullptr};


  bool dis_stat_ = false;
  bool on_init_set_dis_stat_ = false;
  binary_sensor::BinarySensor *dis_stat_binary_sensor_ {nullptr};


  bool dis_vsys_short_ = false;
  bool on_init_set_dis_vsys_short_ = false;
  binary_sensor::BinarySensor *dis_vsys_short_binary_sensor_ {nullptr};


  bool dis_votg_uvp_ = false;
  bool on_init_set_dis_votg_uvp_ = false;
  binary_sensor::BinarySensor *dis_votg_uvp_binary_sensor_ {nullptr};


  bool force_vindpm_det_ = false;
  bool on_init_set_force_vindpm_det_ = false;
  binary_sensor::BinarySensor *force_vindpm_det_binary_sensor_ {nullptr};


  bool en_ibus_ocp_ = false;
  bool on_init_set_en_ibus_ocp_ = false;
  binary_sensor::BinarySensor *en_ibus_ocp_binary_sensor_ {nullptr};


  bool sfet_present_ = false;
  bool on_init_set_sfet_present_ = false;
  binary_sensor::BinarySensor *sfet_present_binary_sensor_ {nullptr};


  bool en_ibat_ = false;
  bool on_init_set_en_ibat_ = false;
  binary_sensor::BinarySensor *en_ibat_binary_sensor_ {nullptr};


  int ibat_reg_ = 0;
  bool on_init_set_ibat_reg_ = false;
  sensor::Sensor *ibat_reg_sensor_ {nullptr};
  text_sensor::TextSensor *ibat_reg_text_sensor_ {nullptr};


  bool en_iindpm_ = false;
  bool on_init_set_en_iindpm_ = false;
  binary_sensor::BinarySensor *en_iindpm_binary_sensor_ {nullptr};


  bool en_extilim_ = false;
  bool on_init_set_en_extilim_ = false;
  binary_sensor::BinarySensor *en_extilim_binary_sensor_ {nullptr};


  bool en_batoc_ = false;
  bool on_init_set_en_batoc_ = false;
  binary_sensor::BinarySensor *en_batoc_binary_sensor_ {nullptr};


  int voc_pct_ = 0;
  bool on_init_set_voc_pct_ = false;
  sensor::Sensor *voc_pct_sensor_ {nullptr};
  text_sensor::TextSensor *voc_pct_text_sensor_ {nullptr};


  int voc_dly_ = 0;
  bool on_init_set_voc_dly_ = false;
  sensor::Sensor *voc_dly_sensor_ {nullptr};
  text_sensor::TextSensor *voc_dly_text_sensor_ {nullptr};


  int voc_rate_ = 0;
  bool on_init_set_voc_rate_ = false;
  sensor::Sensor *voc_rate_sensor_ {nullptr};
  text_sensor::TextSensor *voc_rate_text_sensor_ {nullptr};


  bool en_mppt_ = false;
  bool on_init_set_en_mppt_ = false;
  binary_sensor::BinarySensor *en_mppt_binary_sensor_ {nullptr};


  int treg_ = 0;
  bool on_init_set_treg_ = false;
  sensor::Sensor *treg_sensor_ {nullptr};
  text_sensor::TextSensor *treg_text_sensor_ {nullptr};


  int tshut_ = 0;
  bool on_init_set_tshut_ = false;
  sensor::Sensor *tshut_sensor_ {nullptr};
  text_sensor::TextSensor *tshut_text_sensor_ {nullptr};


  bool vbus_pd_en_ = false;
  bool on_init_set_vbus_pd_en_ = false;
  binary_sensor::BinarySensor *vbus_pd_en_binary_sensor_ {nullptr};


  bool vac1_pd_en_ = false;
  bool on_init_set_vac1_pd_en_ = false;
  binary_sensor::BinarySensor *vac1_pd_en_binary_sensor_ {nullptr};


  bool vac2_pd_en_ = false;
  bool on_init_set_vac2_pd_en_ = false;
  binary_sensor::BinarySensor *vac2_pd_en_binary_sensor_ {nullptr};


  int bkup_acfet1_on_ = 0;
  bool on_init_set_bkup_acfet1_on_ = false;
  sensor::Sensor *bkup_acfet1_on_sensor_ {nullptr};
  text_sensor::TextSensor *bkup_acfet1_on_text_sensor_ {nullptr};


  int jeita_vset_ = 0;
  bool on_init_set_jeita_vset_ = false;
  sensor::Sensor *jeita_vset_sensor_ {nullptr};
  text_sensor::TextSensor *jeita_vset_text_sensor_ {nullptr};


  int jeita_iseth_ = 0;
  bool on_init_set_jeita_iseth_ = false;
  sensor::Sensor *jeita_iseth_sensor_ {nullptr};
  text_sensor::TextSensor *jeita_iseth_text_sensor_ {nullptr};


  int jeita_isetc_ = 0;
  bool on_init_set_jeita_isetc_ = false;
  sensor::Sensor *jeita_isetc_sensor_ {nullptr};
  text_sensor::TextSensor *jeita_isetc_text_sensor_ {nullptr};


  int ts_cool_ = 0;
  bool on_init_set_ts_cool_ = false;
  sensor::Sensor *ts_cool_sensor_ {nullptr};
  text_sensor::TextSensor *ts_cool_text_sensor_ {nullptr};


  int ts_warm_ = 0;
  bool on_init_set_ts_warm_ = false;
  sensor::Sensor *ts_warm_sensor_ {nullptr};
  text_sensor::TextSensor *ts_warm_text_sensor_ {nullptr};


  int bhot_ = 0;
  bool on_init_set_bhot_ = false;
  sensor::Sensor *bhot_sensor_ {nullptr};
  text_sensor::TextSensor *bhot_text_sensor_ {nullptr};


  int bcold_ = 0;
  bool on_init_set_bcold_ = false;
  sensor::Sensor *bcold_sensor_ {nullptr};
  text_sensor::TextSensor *bcold_text_sensor_ {nullptr};


  bool ts_ignore_ = false;
  bool on_init_set_ts_ignore_ = false;
  binary_sensor::BinarySensor *ts_ignore_binary_sensor_ {nullptr};


  int ico_ilim_ = 0;
  sensor::Sensor *ico_ilim_sensor_ {nullptr};


  int iindpm_stat_ = 0;
  sensor::Sensor *iindpm_stat_sensor_ {nullptr};
  text_sensor::TextSensor *iindpm_stat_text_sensor_ {nullptr};


  int vindpm_stat_ = 0;
  sensor::Sensor *vindpm_stat_sensor_ {nullptr};
  text_sensor::TextSensor *vindpm_stat_text_sensor_ {nullptr};


  int wd_stat_ = 0;
  sensor::Sensor *wd_stat_sensor_ {nullptr};
  text_sensor::TextSensor *wd_stat_text_sensor_ {nullptr};


  int pg_stat_ = 0;
  sensor::Sensor *pg_stat_sensor_ {nullptr};
  text_sensor::TextSensor *pg_stat_text_sensor_ {nullptr};


  int ac2_present_stat_ = 0;
  sensor::Sensor *ac2_present_stat_sensor_ {nullptr};
  text_sensor::TextSensor *ac2_present_stat_text_sensor_ {nullptr};


  int ac1_present_stat_ = 0;
  sensor::Sensor *ac1_present_stat_sensor_ {nullptr};
  text_sensor::TextSensor *ac1_present_stat_text_sensor_ {nullptr};


  int vbus_present_stat_ = 0;
  sensor::Sensor *vbus_present_stat_sensor_ {nullptr};
  text_sensor::TextSensor *vbus_present_stat_text_sensor_ {nullptr};


  int chg_stat_ = 0;
  sensor::Sensor *chg_stat_sensor_ {nullptr};
  text_sensor::TextSensor *chg_stat_text_sensor_ {nullptr};


  int vbus_stat_ = 0;
  sensor::Sensor *vbus_stat_sensor_ {nullptr};
  text_sensor::TextSensor *vbus_stat_text_sensor_ {nullptr};


  bool bc12_done_stat_ = false;
  binary_sensor::BinarySensor *bc12_done_stat_binary_sensor_ {nullptr};


  int ico_stat_ = 0;
  sensor::Sensor *ico_stat_sensor_ {nullptr};
  text_sensor::TextSensor *ico_stat_text_sensor_ {nullptr};


  int treg_stat_ = 0;
  sensor::Sensor *treg_stat_sensor_ {nullptr};
  text_sensor::TextSensor *treg_stat_text_sensor_ {nullptr};


  int dpdm_stat_ = 0;
  sensor::Sensor *dpdm_stat_sensor_ {nullptr};
  text_sensor::TextSensor *dpdm_stat_text_sensor_ {nullptr};


  int vbat_present_stat_ = 0;
  sensor::Sensor *vbat_present_stat_sensor_ {nullptr};
  text_sensor::TextSensor *vbat_present_stat_text_sensor_ {nullptr};


  bool acrb2_stat_ = false;
  binary_sensor::BinarySensor *acrb2_stat_binary_sensor_ {nullptr};


  bool acrb1_stat_ = false;
  binary_sensor::BinarySensor *acrb1_stat_binary_sensor_ {nullptr};


  bool adc_done_stat_ = false;
  binary_sensor::BinarySensor *adc_done_stat_binary_sensor_ {nullptr};


  int vsys_stat_ = 0;
  sensor::Sensor *vsys_stat_sensor_ {nullptr};
  text_sensor::TextSensor *vsys_stat_text_sensor_ {nullptr};


  int chg_tmr_stat_ = 0;
  sensor::Sensor *chg_tmr_stat_sensor_ {nullptr};
  text_sensor::TextSensor *chg_tmr_stat_text_sensor_ {nullptr};


  int trichg_tmr_stat_ = 0;
  sensor::Sensor *trichg_tmr_stat_sensor_ {nullptr};
  text_sensor::TextSensor *trichg_tmr_stat_text_sensor_ {nullptr};


  int prechg_tmr_stat_ = 0;
  sensor::Sensor *prechg_tmr_stat_sensor_ {nullptr};
  text_sensor::TextSensor *prechg_tmr_stat_text_sensor_ {nullptr};


  int vbatotg_low_stat_ = 0;
  sensor::Sensor *vbatotg_low_stat_sensor_ {nullptr};
  text_sensor::TextSensor *vbatotg_low_stat_text_sensor_ {nullptr};


  int ts_cold_stat_ = 0;
  sensor::Sensor *ts_cold_stat_sensor_ {nullptr};
  text_sensor::TextSensor *ts_cold_stat_text_sensor_ {nullptr};


  int ts_cool_stat_ = 0;
  sensor::Sensor *ts_cool_stat_sensor_ {nullptr};
  text_sensor::TextSensor *ts_cool_stat_text_sensor_ {nullptr};


  int ts_warm_stat_ = 0;
  sensor::Sensor *ts_warm_stat_sensor_ {nullptr};
  text_sensor::TextSensor *ts_warm_stat_text_sensor_ {nullptr};


  int ts_hot_stat_ = 0;
  sensor::Sensor *ts_hot_stat_sensor_ {nullptr};
  text_sensor::TextSensor *ts_hot_stat_text_sensor_ {nullptr};


  bool ibat_reg_stat_ = false;
  binary_sensor::BinarySensor *ibat_reg_stat_binary_sensor_ {nullptr};


  bool vbus_ovp_stat_ = false;
  binary_sensor::BinarySensor *vbus_ovp_stat_binary_sensor_ {nullptr};


  bool vbat_ovp_stat_ = false;
  binary_sensor::BinarySensor *vbat_ovp_stat_binary_sensor_ {nullptr};


  bool ibus_ocp_stat_ = false;
  binary_sensor::BinarySensor *ibus_ocp_stat_binary_sensor_ {nullptr};


  bool ibat_ocp_stat_ = false;
  binary_sensor::BinarySensor *ibat_ocp_stat_binary_sensor_ {nullptr};


  bool conv_ocp_stat_ = false;
  binary_sensor::BinarySensor *conv_ocp_stat_binary_sensor_ {nullptr};


  bool vac2_ovp_stat_ = false;
  binary_sensor::BinarySensor *vac2_ovp_stat_binary_sensor_ {nullptr};


  bool vac1_ovp_stat_ = false;
  binary_sensor::BinarySensor *vac1_ovp_stat_binary_sensor_ {nullptr};


  bool vsys_short_stat_ = false;
  binary_sensor::BinarySensor *vsys_short_stat_binary_sensor_ {nullptr};


  bool vsys_ovp_stat_ = false;
  binary_sensor::BinarySensor *vsys_ovp_stat_binary_sensor_ {nullptr};


  bool otg_ovp_stat_ = false;
  binary_sensor::BinarySensor *otg_ovp_stat_binary_sensor_ {nullptr};


  bool otg_uvp_stat_ = false;
  binary_sensor::BinarySensor *otg_uvp_stat_binary_sensor_ {nullptr};


  bool tshut_stat_ = false;
  binary_sensor::BinarySensor *tshut_stat_binary_sensor_ {nullptr};


  bool iindpm_flag_ = false;
  binary_sensor::BinarySensor *iindpm_flag_binary_sensor_ {nullptr};


  bool vindpm_flag_ = false;
  binary_sensor::BinarySensor *vindpm_flag_binary_sensor_ {nullptr};


  bool wd_flag_ = false;
  binary_sensor::BinarySensor *wd_flag_binary_sensor_ {nullptr};


  bool poorsrc_flag_ = false;
  binary_sensor::BinarySensor *poorsrc_flag_binary_sensor_ {nullptr};


  bool pg_flag_ = false;
  binary_sensor::BinarySensor *pg_flag_binary_sensor_ {nullptr};


  bool ac2_present_flag_ = false;
  binary_sensor::BinarySensor *ac2_present_flag_binary_sensor_ {nullptr};


  bool ac1_present_flag_ = false;
  binary_sensor::BinarySensor *ac1_present_flag_binary_sensor_ {nullptr};


  bool vbus_present_flag_ = false;
  binary_sensor::BinarySensor *vbus_present_flag_binary_sensor_ {nullptr};


  bool chg_flag_ = false;
  binary_sensor::BinarySensor *chg_flag_binary_sensor_ {nullptr};


  bool ico_flag_ = false;
  binary_sensor::BinarySensor *ico_flag_binary_sensor_ {nullptr};


  bool vbus_flag_ = false;
  binary_sensor::BinarySensor *vbus_flag_binary_sensor_ {nullptr};


  bool treg_flag_ = false;
  binary_sensor::BinarySensor *treg_flag_binary_sensor_ {nullptr};


  bool vbat_present_flag_ = false;
  binary_sensor::BinarySensor *vbat_present_flag_binary_sensor_ {nullptr};


  bool bc1_2_done_flag_ = false;
  binary_sensor::BinarySensor *bc1_2_done_flag_binary_sensor_ {nullptr};


  bool dpdm_done_flag_ = false;
  binary_sensor::BinarySensor *dpdm_done_flag_binary_sensor_ {nullptr};


  bool adc_done_flag_ = false;
  binary_sensor::BinarySensor *adc_done_flag_binary_sensor_ {nullptr};


  bool vsys_flag_ = false;
  binary_sensor::BinarySensor *vsys_flag_binary_sensor_ {nullptr};


  bool chg_tmr_flag_ = false;
  binary_sensor::BinarySensor *chg_tmr_flag_binary_sensor_ {nullptr};


  bool trichg_tmr_flag_ = false;
  binary_sensor::BinarySensor *trichg_tmr_flag_binary_sensor_ {nullptr};


  bool prechg_tmr_flag_ = false;
  binary_sensor::BinarySensor *prechg_tmr_flag_binary_sensor_ {nullptr};


  bool topoff_tmr_flag_ = false;
  binary_sensor::BinarySensor *topoff_tmr_flag_binary_sensor_ {nullptr};


  bool vbatotg_low_flag_ = false;
  binary_sensor::BinarySensor *vbatotg_low_flag_binary_sensor_ {nullptr};


  bool ts_cold_flag_ = false;
  binary_sensor::BinarySensor *ts_cold_flag_binary_sensor_ {nullptr};


  bool ts_cool_flag_ = false;
  binary_sensor::BinarySensor *ts_cool_flag_binary_sensor_ {nullptr};


  bool ts_warm_flag_ = false;
  binary_sensor::BinarySensor *ts_warm_flag_binary_sensor_ {nullptr};


  bool ts_hot_flag_ = false;
  binary_sensor::BinarySensor *ts_hot_flag_binary_sensor_ {nullptr};


  bool ibat_reg_flag_ = false;
  binary_sensor::BinarySensor *ibat_reg_flag_binary_sensor_ {nullptr};


  bool vbus_ovp_flag_ = false;
  binary_sensor::BinarySensor *vbus_ovp_flag_binary_sensor_ {nullptr};


  bool vbat_ovp_flag_ = false;
  binary_sensor::BinarySensor *vbat_ovp_flag_binary_sensor_ {nullptr};


  bool ibus_ocp_flag_ = false;
  binary_sensor::BinarySensor *ibus_ocp_flag_binary_sensor_ {nullptr};


  bool ibat_ocp_flag_ = false;
  binary_sensor::BinarySensor *ibat_ocp_flag_binary_sensor_ {nullptr};


  bool conv_ocp_flag_ = false;
  binary_sensor::BinarySensor *conv_ocp_flag_binary_sensor_ {nullptr};


  bool vac2_ovp_flag_ = false;
  binary_sensor::BinarySensor *vac2_ovp_flag_binary_sensor_ {nullptr};


  bool vac1_ovp_flag_ = false;
  binary_sensor::BinarySensor *vac1_ovp_flag_binary_sensor_ {nullptr};


  bool vsys_short_flag_ = false;
  binary_sensor::BinarySensor *vsys_short_flag_binary_sensor_ {nullptr};


  bool vsys_ovp_flag_ = false;
  binary_sensor::BinarySensor *vsys_ovp_flag_binary_sensor_ {nullptr};


  bool otg_ovp_flag_ = false;
  binary_sensor::BinarySensor *otg_ovp_flag_binary_sensor_ {nullptr};


  bool otg_uvp_flag_ = false;
  binary_sensor::BinarySensor *otg_uvp_flag_binary_sensor_ {nullptr};


  bool tshut_flag_ = false;
  binary_sensor::BinarySensor *tshut_flag_binary_sensor_ {nullptr};


  bool adc_en_ = false;
  bool on_init_set_adc_en_ = false;
  binary_sensor::BinarySensor *adc_en_binary_sensor_ {nullptr};


  int adc_rate_ = 0;
  bool on_init_set_adc_rate_ = false;
  sensor::Sensor *adc_rate_sensor_ {nullptr};
  text_sensor::TextSensor *adc_rate_text_sensor_ {nullptr};


  int adc_sample_ = 0;
  bool on_init_set_adc_sample_ = false;
  sensor::Sensor *adc_sample_sensor_ {nullptr};
  text_sensor::TextSensor *adc_sample_text_sensor_ {nullptr};


  int adc_avg_ = 0;
  bool on_init_set_adc_avg_ = false;
  sensor::Sensor *adc_avg_sensor_ {nullptr};
  text_sensor::TextSensor *adc_avg_text_sensor_ {nullptr};


  bool adc_avg_init_ = false;
  bool on_init_set_adc_avg_init_ = false;
  binary_sensor::BinarySensor *adc_avg_init_binary_sensor_ {nullptr};


  bool ibus_adc_dis_ = false;
  bool on_init_set_ibus_adc_dis_ = false;
  binary_sensor::BinarySensor *ibus_adc_dis_binary_sensor_ {nullptr};


  bool ibat_adc_dis_ = false;
  bool on_init_set_ibat_adc_dis_ = false;
  binary_sensor::BinarySensor *ibat_adc_dis_binary_sensor_ {nullptr};


  bool vbus_adc_dis_ = false;
  bool on_init_set_vbus_adc_dis_ = false;
  binary_sensor::BinarySensor *vbus_adc_dis_binary_sensor_ {nullptr};


  bool vbat_adc_dis_ = false;
  bool on_init_set_vbat_adc_dis_ = false;
  binary_sensor::BinarySensor *vbat_adc_dis_binary_sensor_ {nullptr};


  bool vsys_adc_dis_ = false;
  bool on_init_set_vsys_adc_dis_ = false;
  binary_sensor::BinarySensor *vsys_adc_dis_binary_sensor_ {nullptr};


  bool ts_adc_dis_ = false;
  bool on_init_set_ts_adc_dis_ = false;
  binary_sensor::BinarySensor *ts_adc_dis_binary_sensor_ {nullptr};


  bool tdie_adc_dis_ = false;
  bool on_init_set_tdie_adc_dis_ = false;
  binary_sensor::BinarySensor *tdie_adc_dis_binary_sensor_ {nullptr};


  bool dplus_adc_dis_ = false;
  bool on_init_set_dplus_adc_dis_ = false;
  binary_sensor::BinarySensor *dplus_adc_dis_binary_sensor_ {nullptr};


  bool dminus_adc_dis_ = false;
  bool on_init_set_dminus_adc_dis_ = false;
  binary_sensor::BinarySensor *dminus_adc_dis_binary_sensor_ {nullptr};


  bool vac2_adc_dis_ = false;
  bool on_init_set_vac2_adc_dis_ = false;
  binary_sensor::BinarySensor *vac2_adc_dis_binary_sensor_ {nullptr};


  bool vac1_adc_dis_ = false;
  bool on_init_set_vac1_adc_dis_ = false;
  binary_sensor::BinarySensor *vac1_adc_dis_binary_sensor_ {nullptr};


  int ibus_adc_ = 0;
  sensor::Sensor *ibus_adc_sensor_ {nullptr};


  int ibat_adc_ = 0;
  sensor::Sensor *ibat_adc_sensor_ {nullptr};


  int vbus_adc_ = 0;
  sensor::Sensor *vbus_adc_sensor_ {nullptr};


  int vac1_adc_ = 0;
  sensor::Sensor *vac1_adc_sensor_ {nullptr};


  int vac2_adc_ = 0;
  sensor::Sensor *vac2_adc_sensor_ {nullptr};


  int vbat_adc_ = 0;
  sensor::Sensor *vbat_adc_sensor_ {nullptr};


  int vsys_adc_ = 0;
  sensor::Sensor *vsys_adc_sensor_ {nullptr};


  float ts_adc_ = 0.0f;
  sensor::Sensor *ts_adc_sensor_ {nullptr};


  float tdie_adc_ = 0.0f;
  sensor::Sensor *tdie_adc_sensor_ {nullptr};


  int dplus_adc_ = 0;
  sensor::Sensor *dplus_adc_sensor_ {nullptr};


  int dminus_adc_ = 0;
  sensor::Sensor *dminus_adc_sensor_ {nullptr};


  int dplus_dac_ = 0;
  bool on_init_set_dplus_dac_ = false;
  sensor::Sensor *dplus_dac_sensor_ {nullptr};
  text_sensor::TextSensor *dplus_dac_text_sensor_ {nullptr};


  int dminus_dac_ = 0;
  bool on_init_set_dminus_dac_ = false;
  sensor::Sensor *dminus_dac_sensor_ {nullptr};
  text_sensor::TextSensor *dminus_dac_text_sensor_ {nullptr};


  int pn_ = 0;
  sensor::Sensor *pn_sensor_ {nullptr};
  text_sensor::TextSensor *pn_text_sensor_ {nullptr};


  int dev_rev_ = 0;
  sensor::Sensor *dev_rev_sensor_ {nullptr};
  text_sensor::TextSensor *dev_rev_text_sensor_ {nullptr};



  private:
    BQ25798NoI2C *bq25798_noi2c {nullptr};
};  // class BQ25798Component

}  // namespace bq25798
}  // namespace esphome