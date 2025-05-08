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
  void assign_sensor_vsysmin(sensor::Sensor *sensor) { 
    sensor_vsysmin = sensor; 
  }


  void on_init_set_vreg(bool value);
  void set_vreg(int value, bool write_to_i2c);
  int get_vreg(bool read_from_i2c);
  void assign_sensor_vreg(sensor::Sensor *sensor) { 
    sensor_vreg = sensor; 
  }


  void on_init_set_ichg(bool value);
  void set_ichg(int value, bool write_to_i2c);
  int get_ichg(bool read_from_i2c);
  void assign_sensor_ichg(sensor::Sensor *sensor) { 
    sensor_ichg = sensor; 
  }


  void on_init_set_vindpm(bool value);
  void set_vindpm(int value, bool write_to_i2c);
  int get_vindpm(bool read_from_i2c);
  void assign_sensor_vindpm(sensor::Sensor *sensor) { 
    sensor_vindpm = sensor; 
  }


  void on_init_set_iindpm(bool value);
  void set_iindpm(int value, bool write_to_i2c);
  int get_iindpm(bool read_from_i2c);
  void assign_sensor_iindpm(sensor::Sensor *sensor) { 
    sensor_iindpm = sensor; 
  }


  void on_init_set_vbat_lowv(bool value);
  void set_vbat_lowv(int value, bool write_to_i2c);
  int get_vbat_lowv(bool read_from_i2c);
  const char* get_vbat_lowv_string(bool read_from_i2c);
  void assign_sensor_vbat_lowv(sensor::Sensor *sensor) { 
    sensor_vbat_lowv = sensor; 
  }
  void assign_text_sensor_vbat_lowv(text_sensor::TextSensor *sensor) { 
    text_sensor_vbat_lowv = sensor; 
  }


  void on_init_set_iprechg(bool value);
  void set_iprechg(int value, bool write_to_i2c);
  int get_iprechg(bool read_from_i2c);
  void assign_sensor_iprechg(sensor::Sensor *sensor) { 
    sensor_iprechg = sensor; 
  }


  void on_init_set_reg_rst(bool value);
  void set_reg_rst(bool value, bool write_to_i2c);
  bool get_reg_rst(bool read_from_i2c);
  void assign_binary_sensor_reg_rst(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_reg_rst = sensor; 
  }


  void on_init_set_stop_wd_chg(bool value);
  void set_stop_wd_chg(bool value, bool write_to_i2c);
  bool get_stop_wd_chg(bool read_from_i2c);
  void assign_binary_sensor_stop_wd_chg(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_stop_wd_chg = sensor; 
  }


  void on_init_set_iterm(bool value);
  void set_iterm(int value, bool write_to_i2c);
  int get_iterm(bool read_from_i2c);
  void assign_sensor_iterm(sensor::Sensor *sensor) { 
    sensor_iterm = sensor; 
  }


  void on_init_set_cell(bool value);
  void set_cell(int value, bool write_to_i2c);
  int get_cell(bool read_from_i2c);
  const char* get_cell_string(bool read_from_i2c);
  void assign_sensor_cell(sensor::Sensor *sensor) { 
    sensor_cell = sensor; 
  }
  void assign_text_sensor_cell(text_sensor::TextSensor *sensor) { 
    text_sensor_cell = sensor; 
  }


  void on_init_set_trechg(bool value);
  void set_trechg(int value, bool write_to_i2c);
  int get_trechg(bool read_from_i2c);
  const char* get_trechg_string(bool read_from_i2c);
  void assign_sensor_trechg(sensor::Sensor *sensor) { 
    sensor_trechg = sensor; 
  }
  void assign_text_sensor_trechg(text_sensor::TextSensor *sensor) { 
    text_sensor_trechg = sensor; 
  }


  void on_init_set_vrechg(bool value);
  void set_vrechg(int value, bool write_to_i2c);
  int get_vrechg(bool read_from_i2c);
  void assign_sensor_vrechg(sensor::Sensor *sensor) { 
    sensor_vrechg = sensor; 
  }


  void on_init_set_votg(bool value);
  void set_votg(int value, bool write_to_i2c);
  int get_votg(bool read_from_i2c);
  void assign_sensor_votg(sensor::Sensor *sensor) { 
    sensor_votg = sensor; 
  }


  void on_init_set_prechg_tmr(bool value);
  void set_prechg_tmr(int value, bool write_to_i2c);
  int get_prechg_tmr(bool read_from_i2c);
  const char* get_prechg_tmr_string(bool read_from_i2c);
  void assign_sensor_prechg_tmr(sensor::Sensor *sensor) { 
    sensor_prechg_tmr = sensor; 
  }
  void assign_text_sensor_prechg_tmr(text_sensor::TextSensor *sensor) { 
    text_sensor_prechg_tmr = sensor; 
  }


  void on_init_set_iotg(bool value);
  void set_iotg(int value, bool write_to_i2c);
  int get_iotg(bool read_from_i2c);
  void assign_sensor_iotg(sensor::Sensor *sensor) { 
    sensor_iotg = sensor; 
  }


  void on_init_set_topoff_tmr(bool value);
  void set_topoff_tmr(int value, bool write_to_i2c);
  int get_topoff_tmr(bool read_from_i2c);
  const char* get_topoff_tmr_string(bool read_from_i2c);
  void assign_sensor_topoff_tmr(sensor::Sensor *sensor) { 
    sensor_topoff_tmr = sensor; 
  }
  void assign_text_sensor_topoff_tmr(text_sensor::TextSensor *sensor) { 
    text_sensor_topoff_tmr = sensor; 
  }


  void on_init_set_en_trichg_tmr(bool value);
  void set_en_trichg_tmr(bool value, bool write_to_i2c);
  bool get_en_trichg_tmr(bool read_from_i2c);
  void assign_binary_sensor_en_trichg_tmr(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_trichg_tmr = sensor; 
  }


  void on_init_set_en_prechg_tmr(bool value);
  void set_en_prechg_tmr(bool value, bool write_to_i2c);
  bool get_en_prechg_tmr(bool read_from_i2c);
  void assign_binary_sensor_en_prechg_tmr(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_prechg_tmr = sensor; 
  }


  void on_init_set_en_chg_tmr(bool value);
  void set_en_chg_tmr(bool value, bool write_to_i2c);
  bool get_en_chg_tmr(bool read_from_i2c);
  void assign_binary_sensor_en_chg_tmr(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_chg_tmr = sensor; 
  }


  void on_init_set_chg_tmr(bool value);
  void set_chg_tmr(int value, bool write_to_i2c);
  int get_chg_tmr(bool read_from_i2c);
  const char* get_chg_tmr_string(bool read_from_i2c);
  void assign_sensor_chg_tmr(sensor::Sensor *sensor) { 
    sensor_chg_tmr = sensor; 
  }
  void assign_text_sensor_chg_tmr(text_sensor::TextSensor *sensor) { 
    text_sensor_chg_tmr = sensor; 
  }


  void on_init_set_tmr2x_en(bool value);
  void set_tmr2x_en(bool value, bool write_to_i2c);
  bool get_tmr2x_en(bool read_from_i2c);
  void assign_binary_sensor_tmr2x_en(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_tmr2x_en = sensor; 
  }


  void on_init_set_en_auto_ibatdis(bool value);
  void set_en_auto_ibatdis(bool value, bool write_to_i2c);
  bool get_en_auto_ibatdis(bool read_from_i2c);
  void assign_binary_sensor_en_auto_ibatdis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_auto_ibatdis = sensor; 
  }


  void on_init_set_force_ibatdis(bool value);
  void set_force_ibatdis(bool value, bool write_to_i2c);
  bool get_force_ibatdis(bool read_from_i2c);
  void assign_binary_sensor_force_ibatdis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_force_ibatdis = sensor; 
  }


  void on_init_set_en_chg(bool value);
  void set_en_chg(bool value, bool write_to_i2c);
  bool get_en_chg(bool read_from_i2c);
  void assign_binary_sensor_en_chg(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_chg = sensor; 
  }


  void on_init_set_en_ico(bool value);
  void set_en_ico(bool value, bool write_to_i2c);
  bool get_en_ico(bool read_from_i2c);
  void assign_binary_sensor_en_ico(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_ico = sensor; 
  }


  void on_init_set_force_ico(bool value);
  void set_force_ico(bool value, bool write_to_i2c);
  bool get_force_ico(bool read_from_i2c);
  void assign_binary_sensor_force_ico(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_force_ico = sensor; 
  }


  void on_init_set_en_hiz(bool value);
  void set_en_hiz(bool value, bool write_to_i2c);
  bool get_en_hiz(bool read_from_i2c);
  void assign_binary_sensor_en_hiz(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_hiz = sensor; 
  }


  void on_init_set_en_term(bool value);
  void set_en_term(bool value, bool write_to_i2c);
  bool get_en_term(bool read_from_i2c);
  void assign_binary_sensor_en_term(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_term = sensor; 
  }


  void on_init_set_en_backup(bool value);
  void set_en_backup(bool value, bool write_to_i2c);
  bool get_en_backup(bool read_from_i2c);
  void assign_binary_sensor_en_backup(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_backup = sensor; 
  }


  void on_init_set_vbus_backup(bool value);
  void set_vbus_backup(int value, bool write_to_i2c);
  int get_vbus_backup(bool read_from_i2c);
  const char* get_vbus_backup_string(bool read_from_i2c);
  void assign_sensor_vbus_backup(sensor::Sensor *sensor) { 
    sensor_vbus_backup = sensor; 
  }
  void assign_text_sensor_vbus_backup(text_sensor::TextSensor *sensor) { 
    text_sensor_vbus_backup = sensor; 
  }


  void on_init_set_vac_ovp(bool value);
  void set_vac_ovp(int value, bool write_to_i2c);
  int get_vac_ovp(bool read_from_i2c);
  const char* get_vac_ovp_string(bool read_from_i2c);
  void assign_sensor_vac_ovp(sensor::Sensor *sensor) { 
    sensor_vac_ovp = sensor; 
  }
  void assign_text_sensor_vac_ovp(text_sensor::TextSensor *sensor) { 
    text_sensor_vac_ovp = sensor; 
  }


  void on_init_set_wd_rst(bool value);
  void set_wd_rst(bool value, bool write_to_i2c);
  bool get_wd_rst(bool read_from_i2c);
  void assign_binary_sensor_wd_rst(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_wd_rst = sensor; 
  }


  void on_init_set_watchdog(bool value);
  void set_watchdog(int value, bool write_to_i2c);
  int get_watchdog(bool read_from_i2c);
  const char* get_watchdog_string(bool read_from_i2c);
  void assign_sensor_watchdog(sensor::Sensor *sensor) { 
    sensor_watchdog = sensor; 
  }
  void assign_text_sensor_watchdog(text_sensor::TextSensor *sensor) { 
    text_sensor_watchdog = sensor; 
  }


  void on_init_set_force_indet(bool value);
  void set_force_indet(bool value, bool write_to_i2c);
  bool get_force_indet(bool read_from_i2c);
  void assign_binary_sensor_force_indet(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_force_indet = sensor; 
  }


  void on_init_set_auto_indet_en(bool value);
  void set_auto_indet_en(bool value, bool write_to_i2c);
  bool get_auto_indet_en(bool read_from_i2c);
  void assign_binary_sensor_auto_indet_en(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_auto_indet_en = sensor; 
  }


  void on_init_set_en_12v(bool value);
  void set_en_12v(bool value, bool write_to_i2c);
  bool get_en_12v(bool read_from_i2c);
  void assign_binary_sensor_en_12v(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_12v = sensor; 
  }


  void on_init_set_en_9v(bool value);
  void set_en_9v(bool value, bool write_to_i2c);
  bool get_en_9v(bool read_from_i2c);
  void assign_binary_sensor_en_9v(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_9v = sensor; 
  }


  void on_init_set_hvdcp_en(bool value);
  void set_hvdcp_en(bool value, bool write_to_i2c);
  bool get_hvdcp_en(bool read_from_i2c);
  void assign_binary_sensor_hvdcp_en(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_hvdcp_en = sensor; 
  }


  void on_init_set_sdrv_ctrl(bool value);
  void set_sdrv_ctrl(int value, bool write_to_i2c);
  int get_sdrv_ctrl(bool read_from_i2c);
  const char* get_sdrv_ctrl_string(bool read_from_i2c);
  void assign_sensor_sdrv_ctrl(sensor::Sensor *sensor) { 
    sensor_sdrv_ctrl = sensor; 
  }
  void assign_text_sensor_sdrv_ctrl(text_sensor::TextSensor *sensor) { 
    text_sensor_sdrv_ctrl = sensor; 
  }


  void on_init_set_sdrv_dly(bool value);
  void set_sdrv_dly(int value, bool write_to_i2c);
  int get_sdrv_dly(bool read_from_i2c);
  const char* get_sdrv_dly_string(bool read_from_i2c);
  void assign_sensor_sdrv_dly(sensor::Sensor *sensor) { 
    sensor_sdrv_dly = sensor; 
  }
  void assign_text_sensor_sdrv_dly(text_sensor::TextSensor *sensor) { 
    text_sensor_sdrv_dly = sensor; 
  }


  void on_init_set_dis_acdrv(bool value);
  void set_dis_acdrv(bool value, bool write_to_i2c);
  bool get_dis_acdrv(bool read_from_i2c);
  void assign_binary_sensor_dis_acdrv(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_dis_acdrv = sensor; 
  }


  void on_init_set_en_otg(bool value);
  void set_en_otg(bool value, bool write_to_i2c);
  bool get_en_otg(bool read_from_i2c);
  void assign_binary_sensor_en_otg(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_otg = sensor; 
  }


  void on_init_set_pfm_otg_dis(bool value);
  void set_pfm_otg_dis(bool value, bool write_to_i2c);
  bool get_pfm_otg_dis(bool read_from_i2c);
  void assign_binary_sensor_pfm_otg_dis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_pfm_otg_dis = sensor; 
  }


  void on_init_set_pfm_fwd_dis(bool value);
  void set_pfm_fwd_dis(bool value, bool write_to_i2c);
  bool get_pfm_fwd_dis(bool read_from_i2c);
  void assign_binary_sensor_pfm_fwd_dis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_pfm_fwd_dis = sensor; 
  }


  void on_init_set_wkup_dly(bool value);
  void set_wkup_dly(int value, bool write_to_i2c);
  int get_wkup_dly(bool read_from_i2c);
  const char* get_wkup_dly_string(bool read_from_i2c);
  void assign_sensor_wkup_dly(sensor::Sensor *sensor) { 
    sensor_wkup_dly = sensor; 
  }
  void assign_text_sensor_wkup_dly(text_sensor::TextSensor *sensor) { 
    text_sensor_wkup_dly = sensor; 
  }


  void on_init_set_dis_ldo(bool value);
  void set_dis_ldo(bool value, bool write_to_i2c);
  bool get_dis_ldo(bool read_from_i2c);
  void assign_binary_sensor_dis_ldo(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_dis_ldo = sensor; 
  }


  void on_init_set_dis_otg_ooa(bool value);
  void set_dis_otg_ooa(bool value, bool write_to_i2c);
  bool get_dis_otg_ooa(bool read_from_i2c);
  void assign_binary_sensor_dis_otg_ooa(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_dis_otg_ooa = sensor; 
  }


  void on_init_set_dis_fwd_ooa(bool value);
  void set_dis_fwd_ooa(bool value, bool write_to_i2c);
  bool get_dis_fwd_ooa(bool read_from_i2c);
  void assign_binary_sensor_dis_fwd_ooa(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_dis_fwd_ooa = sensor; 
  }


  void on_init_set_en_acdrv2(bool value);
  void set_en_acdrv2(bool value, bool write_to_i2c);
  bool get_en_acdrv2(bool read_from_i2c);
  void assign_binary_sensor_en_acdrv2(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_acdrv2 = sensor; 
  }


  void on_init_set_en_acdrv1(bool value);
  void set_en_acdrv1(bool value, bool write_to_i2c);
  bool get_en_acdrv1(bool read_from_i2c);
  void assign_binary_sensor_en_acdrv1(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_acdrv1 = sensor; 
  }


  void on_init_set_pwm_freq(bool value);
  void set_pwm_freq(int value, bool write_to_i2c);
  int get_pwm_freq(bool read_from_i2c);
  const char* get_pwm_freq_string(bool read_from_i2c);
  void assign_sensor_pwm_freq(sensor::Sensor *sensor) { 
    sensor_pwm_freq = sensor; 
  }
  void assign_text_sensor_pwm_freq(text_sensor::TextSensor *sensor) { 
    text_sensor_pwm_freq = sensor; 
  }


  void on_init_set_dis_stat(bool value);
  void set_dis_stat(bool value, bool write_to_i2c);
  bool get_dis_stat(bool read_from_i2c);
  void assign_binary_sensor_dis_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_dis_stat = sensor; 
  }


  void on_init_set_dis_vsys_short(bool value);
  void set_dis_vsys_short(bool value, bool write_to_i2c);
  bool get_dis_vsys_short(bool read_from_i2c);
  void assign_binary_sensor_dis_vsys_short(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_dis_vsys_short = sensor; 
  }


  void on_init_set_dis_votg_uvp(bool value);
  void set_dis_votg_uvp(bool value, bool write_to_i2c);
  bool get_dis_votg_uvp(bool read_from_i2c);
  void assign_binary_sensor_dis_votg_uvp(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_dis_votg_uvp = sensor; 
  }


  void on_init_set_force_vindpm_det(bool value);
  void set_force_vindpm_det(bool value, bool write_to_i2c);
  bool get_force_vindpm_det(bool read_from_i2c);
  void assign_binary_sensor_force_vindpm_det(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_force_vindpm_det = sensor; 
  }


  void on_init_set_en_ibus_ocp(bool value);
  void set_en_ibus_ocp(bool value, bool write_to_i2c);
  bool get_en_ibus_ocp(bool read_from_i2c);
  void assign_binary_sensor_en_ibus_ocp(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_ibus_ocp = sensor; 
  }


  void on_init_set_sfet_present(bool value);
  void set_sfet_present(bool value, bool write_to_i2c);
  bool get_sfet_present(bool read_from_i2c);
  void assign_binary_sensor_sfet_present(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_sfet_present = sensor; 
  }


  void on_init_set_en_ibat(bool value);
  void set_en_ibat(bool value, bool write_to_i2c);
  bool get_en_ibat(bool read_from_i2c);
  void assign_binary_sensor_en_ibat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_ibat = sensor; 
  }


  void on_init_set_ibat_reg(bool value);
  void set_ibat_reg(int value, bool write_to_i2c);
  int get_ibat_reg(bool read_from_i2c);
  const char* get_ibat_reg_string(bool read_from_i2c);
  void assign_sensor_ibat_reg(sensor::Sensor *sensor) { 
    sensor_ibat_reg = sensor; 
  }
  void assign_text_sensor_ibat_reg(text_sensor::TextSensor *sensor) { 
    text_sensor_ibat_reg = sensor; 
  }


  void on_init_set_en_iindpm(bool value);
  void set_en_iindpm(bool value, bool write_to_i2c);
  bool get_en_iindpm(bool read_from_i2c);
  void assign_binary_sensor_en_iindpm(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_iindpm = sensor; 
  }


  void on_init_set_en_extilim(bool value);
  void set_en_extilim(bool value, bool write_to_i2c);
  bool get_en_extilim(bool read_from_i2c);
  void assign_binary_sensor_en_extilim(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_extilim = sensor; 
  }


  void on_init_set_en_batoc(bool value);
  void set_en_batoc(bool value, bool write_to_i2c);
  bool get_en_batoc(bool read_from_i2c);
  void assign_binary_sensor_en_batoc(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_batoc = sensor; 
  }


  void on_init_set_voc_pct(bool value);
  void set_voc_pct(int value, bool write_to_i2c);
  int get_voc_pct(bool read_from_i2c);
  const char* get_voc_pct_string(bool read_from_i2c);
  void assign_sensor_voc_pct(sensor::Sensor *sensor) { 
    sensor_voc_pct = sensor; 
  }
  void assign_text_sensor_voc_pct(text_sensor::TextSensor *sensor) { 
    text_sensor_voc_pct = sensor; 
  }


  void on_init_set_voc_dly(bool value);
  void set_voc_dly(int value, bool write_to_i2c);
  int get_voc_dly(bool read_from_i2c);
  const char* get_voc_dly_string(bool read_from_i2c);
  void assign_sensor_voc_dly(sensor::Sensor *sensor) { 
    sensor_voc_dly = sensor; 
  }
  void assign_text_sensor_voc_dly(text_sensor::TextSensor *sensor) { 
    text_sensor_voc_dly = sensor; 
  }


  void on_init_set_voc_rate(bool value);
  void set_voc_rate(int value, bool write_to_i2c);
  int get_voc_rate(bool read_from_i2c);
  const char* get_voc_rate_string(bool read_from_i2c);
  void assign_sensor_voc_rate(sensor::Sensor *sensor) { 
    sensor_voc_rate = sensor; 
  }
  void assign_text_sensor_voc_rate(text_sensor::TextSensor *sensor) { 
    text_sensor_voc_rate = sensor; 
  }


  void on_init_set_en_mppt(bool value);
  void set_en_mppt(bool value, bool write_to_i2c);
  bool get_en_mppt(bool read_from_i2c);
  void assign_binary_sensor_en_mppt(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_en_mppt = sensor; 
  }


  void on_init_set_treg(bool value);
  void set_treg(int value, bool write_to_i2c);
  int get_treg(bool read_from_i2c);
  const char* get_treg_string(bool read_from_i2c);
  void assign_sensor_treg(sensor::Sensor *sensor) { 
    sensor_treg = sensor; 
  }
  void assign_text_sensor_treg(text_sensor::TextSensor *sensor) { 
    text_sensor_treg = sensor; 
  }


  void on_init_set_tshut(bool value);
  void set_tshut(int value, bool write_to_i2c);
  int get_tshut(bool read_from_i2c);
  const char* get_tshut_string(bool read_from_i2c);
  void assign_sensor_tshut(sensor::Sensor *sensor) { 
    sensor_tshut = sensor; 
  }
  void assign_text_sensor_tshut(text_sensor::TextSensor *sensor) { 
    text_sensor_tshut = sensor; 
  }


  void on_init_set_vbus_pd_en(bool value);
  void set_vbus_pd_en(bool value, bool write_to_i2c);
  bool get_vbus_pd_en(bool read_from_i2c);
  void assign_binary_sensor_vbus_pd_en(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vbus_pd_en = sensor; 
  }


  void on_init_set_vac1_pd_en(bool value);
  void set_vac1_pd_en(bool value, bool write_to_i2c);
  bool get_vac1_pd_en(bool read_from_i2c);
  void assign_binary_sensor_vac1_pd_en(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vac1_pd_en = sensor; 
  }


  void on_init_set_vac2_pd_en(bool value);
  void set_vac2_pd_en(bool value, bool write_to_i2c);
  bool get_vac2_pd_en(bool read_from_i2c);
  void assign_binary_sensor_vac2_pd_en(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vac2_pd_en = sensor; 
  }


  void on_init_set_bkup_acfet1_on(bool value);
  void set_bkup_acfet1_on(int value, bool write_to_i2c);
  int get_bkup_acfet1_on(bool read_from_i2c);
  const char* get_bkup_acfet1_on_string(bool read_from_i2c);
  void assign_sensor_bkup_acfet1_on(sensor::Sensor *sensor) { 
    sensor_bkup_acfet1_on = sensor; 
  }
  void assign_text_sensor_bkup_acfet1_on(text_sensor::TextSensor *sensor) { 
    text_sensor_bkup_acfet1_on = sensor; 
  }


  void on_init_set_jeita_vset(bool value);
  void set_jeita_vset(int value, bool write_to_i2c);
  int get_jeita_vset(bool read_from_i2c);
  const char* get_jeita_vset_string(bool read_from_i2c);
  void assign_sensor_jeita_vset(sensor::Sensor *sensor) { 
    sensor_jeita_vset = sensor; 
  }
  void assign_text_sensor_jeita_vset(text_sensor::TextSensor *sensor) { 
    text_sensor_jeita_vset = sensor; 
  }


  void on_init_set_jeita_iseth(bool value);
  void set_jeita_iseth(int value, bool write_to_i2c);
  int get_jeita_iseth(bool read_from_i2c);
  const char* get_jeita_iseth_string(bool read_from_i2c);
  void assign_sensor_jeita_iseth(sensor::Sensor *sensor) { 
    sensor_jeita_iseth = sensor; 
  }
  void assign_text_sensor_jeita_iseth(text_sensor::TextSensor *sensor) { 
    text_sensor_jeita_iseth = sensor; 
  }


  void on_init_set_jeita_isetc(bool value);
  void set_jeita_isetc(int value, bool write_to_i2c);
  int get_jeita_isetc(bool read_from_i2c);
  const char* get_jeita_isetc_string(bool read_from_i2c);
  void assign_sensor_jeita_isetc(sensor::Sensor *sensor) { 
    sensor_jeita_isetc = sensor; 
  }
  void assign_text_sensor_jeita_isetc(text_sensor::TextSensor *sensor) { 
    text_sensor_jeita_isetc = sensor; 
  }


  void on_init_set_ts_cool(bool value);
  void set_ts_cool(int value, bool write_to_i2c);
  int get_ts_cool(bool read_from_i2c);
  const char* get_ts_cool_string(bool read_from_i2c);
  void assign_sensor_ts_cool(sensor::Sensor *sensor) { 
    sensor_ts_cool = sensor; 
  }
  void assign_text_sensor_ts_cool(text_sensor::TextSensor *sensor) { 
    text_sensor_ts_cool = sensor; 
  }


  void on_init_set_ts_warm(bool value);
  void set_ts_warm(int value, bool write_to_i2c);
  int get_ts_warm(bool read_from_i2c);
  const char* get_ts_warm_string(bool read_from_i2c);
  void assign_sensor_ts_warm(sensor::Sensor *sensor) { 
    sensor_ts_warm = sensor; 
  }
  void assign_text_sensor_ts_warm(text_sensor::TextSensor *sensor) { 
    text_sensor_ts_warm = sensor; 
  }


  void on_init_set_bhot(bool value);
  void set_bhot(int value, bool write_to_i2c);
  int get_bhot(bool read_from_i2c);
  const char* get_bhot_string(bool read_from_i2c);
  void assign_sensor_bhot(sensor::Sensor *sensor) { 
    sensor_bhot = sensor; 
  }
  void assign_text_sensor_bhot(text_sensor::TextSensor *sensor) { 
    text_sensor_bhot = sensor; 
  }


  void on_init_set_bcold(bool value);
  void set_bcold(int value, bool write_to_i2c);
  int get_bcold(bool read_from_i2c);
  const char* get_bcold_string(bool read_from_i2c);
  void assign_sensor_bcold(sensor::Sensor *sensor) { 
    sensor_bcold = sensor; 
  }
  void assign_text_sensor_bcold(text_sensor::TextSensor *sensor) { 
    text_sensor_bcold = sensor; 
  }


  void on_init_set_ts_ignore(bool value);
  void set_ts_ignore(bool value, bool write_to_i2c);
  bool get_ts_ignore(bool read_from_i2c);
  void assign_binary_sensor_ts_ignore(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ts_ignore = sensor; 
  }


  int get_ico_ilim(bool read_from_i2c);
  void assign_sensor_ico_ilim(sensor::Sensor *sensor) { 
    sensor_ico_ilim = sensor; 
  }


  int get_iindpm_stat(bool read_from_i2c);
  const char* get_iindpm_stat_string(bool read_from_i2c);
  void assign_sensor_iindpm_stat(sensor::Sensor *sensor) { 
    sensor_iindpm_stat = sensor; 
  }
  void assign_text_sensor_iindpm_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_iindpm_stat = sensor; 
  }


  int get_vindpm_stat(bool read_from_i2c);
  const char* get_vindpm_stat_string(bool read_from_i2c);
  void assign_sensor_vindpm_stat(sensor::Sensor *sensor) { 
    sensor_vindpm_stat = sensor; 
  }
  void assign_text_sensor_vindpm_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_vindpm_stat = sensor; 
  }


  int get_wd_stat(bool read_from_i2c);
  const char* get_wd_stat_string(bool read_from_i2c);
  void assign_sensor_wd_stat(sensor::Sensor *sensor) { 
    sensor_wd_stat = sensor; 
  }
  void assign_text_sensor_wd_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_wd_stat = sensor; 
  }


  int get_pg_stat(bool read_from_i2c);
  const char* get_pg_stat_string(bool read_from_i2c);
  void assign_sensor_pg_stat(sensor::Sensor *sensor) { 
    sensor_pg_stat = sensor; 
  }
  void assign_text_sensor_pg_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_pg_stat = sensor; 
  }


  int get_ac2_present_stat(bool read_from_i2c);
  const char* get_ac2_present_stat_string(bool read_from_i2c);
  void assign_sensor_ac2_present_stat(sensor::Sensor *sensor) { 
    sensor_ac2_present_stat = sensor; 
  }
  void assign_text_sensor_ac2_present_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_ac2_present_stat = sensor; 
  }


  int get_ac1_present_stat(bool read_from_i2c);
  const char* get_ac1_present_stat_string(bool read_from_i2c);
  void assign_sensor_ac1_present_stat(sensor::Sensor *sensor) { 
    sensor_ac1_present_stat = sensor; 
  }
  void assign_text_sensor_ac1_present_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_ac1_present_stat = sensor; 
  }


  int get_vbus_present_stat(bool read_from_i2c);
  const char* get_vbus_present_stat_string(bool read_from_i2c);
  void assign_sensor_vbus_present_stat(sensor::Sensor *sensor) { 
    sensor_vbus_present_stat = sensor; 
  }
  void assign_text_sensor_vbus_present_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_vbus_present_stat = sensor; 
  }


  int get_chg_stat(bool read_from_i2c);
  const char* get_chg_stat_string(bool read_from_i2c);
  void assign_sensor_chg_stat(sensor::Sensor *sensor) { 
    sensor_chg_stat = sensor; 
  }
  void assign_text_sensor_chg_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_chg_stat = sensor; 
  }


  int get_vbus_stat(bool read_from_i2c);
  const char* get_vbus_stat_string(bool read_from_i2c);
  void assign_sensor_vbus_stat(sensor::Sensor *sensor) { 
    sensor_vbus_stat = sensor; 
  }
  void assign_text_sensor_vbus_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_vbus_stat = sensor; 
  }


  bool get_bc12_done_stat(bool read_from_i2c);
  void assign_binary_sensor_bc12_done_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_bc12_done_stat = sensor; 
  }


  int get_ico_stat(bool read_from_i2c);
  const char* get_ico_stat_string(bool read_from_i2c);
  void assign_sensor_ico_stat(sensor::Sensor *sensor) { 
    sensor_ico_stat = sensor; 
  }
  void assign_text_sensor_ico_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_ico_stat = sensor; 
  }


  int get_treg_stat(bool read_from_i2c);
  const char* get_treg_stat_string(bool read_from_i2c);
  void assign_sensor_treg_stat(sensor::Sensor *sensor) { 
    sensor_treg_stat = sensor; 
  }
  void assign_text_sensor_treg_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_treg_stat = sensor; 
  }


  int get_dpdm_stat(bool read_from_i2c);
  const char* get_dpdm_stat_string(bool read_from_i2c);
  void assign_sensor_dpdm_stat(sensor::Sensor *sensor) { 
    sensor_dpdm_stat = sensor; 
  }
  void assign_text_sensor_dpdm_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_dpdm_stat = sensor; 
  }


  int get_vbat_present_stat(bool read_from_i2c);
  const char* get_vbat_present_stat_string(bool read_from_i2c);
  void assign_sensor_vbat_present_stat(sensor::Sensor *sensor) { 
    sensor_vbat_present_stat = sensor; 
  }
  void assign_text_sensor_vbat_present_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_vbat_present_stat = sensor; 
  }


  bool get_acrb2_stat(bool read_from_i2c);
  void assign_binary_sensor_acrb2_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_acrb2_stat = sensor; 
  }


  bool get_acrb1_stat(bool read_from_i2c);
  void assign_binary_sensor_acrb1_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_acrb1_stat = sensor; 
  }


  bool get_adc_done_stat(bool read_from_i2c);
  void assign_binary_sensor_adc_done_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_adc_done_stat = sensor; 
  }


  int get_vsys_stat(bool read_from_i2c);
  const char* get_vsys_stat_string(bool read_from_i2c);
  void assign_sensor_vsys_stat(sensor::Sensor *sensor) { 
    sensor_vsys_stat = sensor; 
  }
  void assign_text_sensor_vsys_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_vsys_stat = sensor; 
  }


  int get_chg_tmr_stat(bool read_from_i2c);
  const char* get_chg_tmr_stat_string(bool read_from_i2c);
  void assign_sensor_chg_tmr_stat(sensor::Sensor *sensor) { 
    sensor_chg_tmr_stat = sensor; 
  }
  void assign_text_sensor_chg_tmr_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_chg_tmr_stat = sensor; 
  }


  int get_trichg_tmr_stat(bool read_from_i2c);
  const char* get_trichg_tmr_stat_string(bool read_from_i2c);
  void assign_sensor_trichg_tmr_stat(sensor::Sensor *sensor) { 
    sensor_trichg_tmr_stat = sensor; 
  }
  void assign_text_sensor_trichg_tmr_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_trichg_tmr_stat = sensor; 
  }


  int get_prechg_tmr_stat(bool read_from_i2c);
  const char* get_prechg_tmr_stat_string(bool read_from_i2c);
  void assign_sensor_prechg_tmr_stat(sensor::Sensor *sensor) { 
    sensor_prechg_tmr_stat = sensor; 
  }
  void assign_text_sensor_prechg_tmr_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_prechg_tmr_stat = sensor; 
  }


  int get_vbatotg_low_stat(bool read_from_i2c);
  const char* get_vbatotg_low_stat_string(bool read_from_i2c);
  void assign_sensor_vbatotg_low_stat(sensor::Sensor *sensor) { 
    sensor_vbatotg_low_stat = sensor; 
  }
  void assign_text_sensor_vbatotg_low_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_vbatotg_low_stat = sensor; 
  }


  int get_ts_cold_stat(bool read_from_i2c);
  const char* get_ts_cold_stat_string(bool read_from_i2c);
  void assign_sensor_ts_cold_stat(sensor::Sensor *sensor) { 
    sensor_ts_cold_stat = sensor; 
  }
  void assign_text_sensor_ts_cold_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_ts_cold_stat = sensor; 
  }


  int get_ts_cool_stat(bool read_from_i2c);
  const char* get_ts_cool_stat_string(bool read_from_i2c);
  void assign_sensor_ts_cool_stat(sensor::Sensor *sensor) { 
    sensor_ts_cool_stat = sensor; 
  }
  void assign_text_sensor_ts_cool_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_ts_cool_stat = sensor; 
  }


  int get_ts_warm_stat(bool read_from_i2c);
  const char* get_ts_warm_stat_string(bool read_from_i2c);
  void assign_sensor_ts_warm_stat(sensor::Sensor *sensor) { 
    sensor_ts_warm_stat = sensor; 
  }
  void assign_text_sensor_ts_warm_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_ts_warm_stat = sensor; 
  }


  int get_ts_hot_stat(bool read_from_i2c);
  const char* get_ts_hot_stat_string(bool read_from_i2c);
  void assign_sensor_ts_hot_stat(sensor::Sensor *sensor) { 
    sensor_ts_hot_stat = sensor; 
  }
  void assign_text_sensor_ts_hot_stat(text_sensor::TextSensor *sensor) { 
    text_sensor_ts_hot_stat = sensor; 
  }


  bool get_ibat_reg_stat(bool read_from_i2c);
  void assign_binary_sensor_ibat_reg_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ibat_reg_stat = sensor; 
  }


  bool get_vbus_ovp_stat(bool read_from_i2c);
  void assign_binary_sensor_vbus_ovp_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vbus_ovp_stat = sensor; 
  }


  bool get_vbat_ovp_stat(bool read_from_i2c);
  void assign_binary_sensor_vbat_ovp_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vbat_ovp_stat = sensor; 
  }


  bool get_ibus_ocp_stat(bool read_from_i2c);
  void assign_binary_sensor_ibus_ocp_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ibus_ocp_stat = sensor; 
  }


  bool get_ibat_ocp_stat(bool read_from_i2c);
  void assign_binary_sensor_ibat_ocp_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ibat_ocp_stat = sensor; 
  }


  bool get_conv_ocp_stat(bool read_from_i2c);
  void assign_binary_sensor_conv_ocp_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_conv_ocp_stat = sensor; 
  }


  bool get_vac2_ovp_stat(bool read_from_i2c);
  void assign_binary_sensor_vac2_ovp_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vac2_ovp_stat = sensor; 
  }


  bool get_vac1_ovp_stat(bool read_from_i2c);
  void assign_binary_sensor_vac1_ovp_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vac1_ovp_stat = sensor; 
  }


  bool get_vsys_short_stat(bool read_from_i2c);
  void assign_binary_sensor_vsys_short_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vsys_short_stat = sensor; 
  }


  bool get_vsys_ovp_stat(bool read_from_i2c);
  void assign_binary_sensor_vsys_ovp_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vsys_ovp_stat = sensor; 
  }


  bool get_otg_ovp_stat(bool read_from_i2c);
  void assign_binary_sensor_otg_ovp_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_otg_ovp_stat = sensor; 
  }


  bool get_otg_uvp_stat(bool read_from_i2c);
  void assign_binary_sensor_otg_uvp_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_otg_uvp_stat = sensor; 
  }


  bool get_tshut_stat(bool read_from_i2c);
  void assign_binary_sensor_tshut_stat(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_tshut_stat = sensor; 
  }


  bool get_iindpm_flag(bool read_from_i2c);
  void assign_binary_sensor_iindpm_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_iindpm_flag = sensor; 
  }


  bool get_vindpm_flag(bool read_from_i2c);
  void assign_binary_sensor_vindpm_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vindpm_flag = sensor; 
  }


  bool get_wd_flag(bool read_from_i2c);
  void assign_binary_sensor_wd_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_wd_flag = sensor; 
  }


  bool get_poorsrc_flag(bool read_from_i2c);
  void assign_binary_sensor_poorsrc_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_poorsrc_flag = sensor; 
  }


  bool get_pg_flag(bool read_from_i2c);
  void assign_binary_sensor_pg_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_pg_flag = sensor; 
  }


  bool get_ac2_present_flag(bool read_from_i2c);
  void assign_binary_sensor_ac2_present_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ac2_present_flag = sensor; 
  }


  bool get_ac1_present_flag(bool read_from_i2c);
  void assign_binary_sensor_ac1_present_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ac1_present_flag = sensor; 
  }


  bool get_vbus_present_flag(bool read_from_i2c);
  void assign_binary_sensor_vbus_present_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vbus_present_flag = sensor; 
  }


  bool get_chg_flag(bool read_from_i2c);
  void assign_binary_sensor_chg_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_chg_flag = sensor; 
  }


  bool get_ico_flag(bool read_from_i2c);
  void assign_binary_sensor_ico_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ico_flag = sensor; 
  }


  bool get_vbus_flag(bool read_from_i2c);
  void assign_binary_sensor_vbus_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vbus_flag = sensor; 
  }


  bool get_treg_flag(bool read_from_i2c);
  void assign_binary_sensor_treg_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_treg_flag = sensor; 
  }


  bool get_vbat_present_flag(bool read_from_i2c);
  void assign_binary_sensor_vbat_present_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vbat_present_flag = sensor; 
  }


  bool get_bc1_2_done_flag(bool read_from_i2c);
  void assign_binary_sensor_bc1_2_done_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_bc1_2_done_flag = sensor; 
  }


  bool get_dpdm_done_flag(bool read_from_i2c);
  void assign_binary_sensor_dpdm_done_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_dpdm_done_flag = sensor; 
  }


  bool get_adc_done_flag(bool read_from_i2c);
  void assign_binary_sensor_adc_done_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_adc_done_flag = sensor; 
  }


  bool get_vsys_flag(bool read_from_i2c);
  void assign_binary_sensor_vsys_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vsys_flag = sensor; 
  }


  bool get_chg_tmr_flag(bool read_from_i2c);
  void assign_binary_sensor_chg_tmr_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_chg_tmr_flag = sensor; 
  }


  bool get_trichg_tmr_flag(bool read_from_i2c);
  void assign_binary_sensor_trichg_tmr_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_trichg_tmr_flag = sensor; 
  }


  bool get_prechg_tmr_flag(bool read_from_i2c);
  void assign_binary_sensor_prechg_tmr_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_prechg_tmr_flag = sensor; 
  }


  bool get_topoff_tmr_flag(bool read_from_i2c);
  void assign_binary_sensor_topoff_tmr_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_topoff_tmr_flag = sensor; 
  }


  bool get_vbatotg_low_flag(bool read_from_i2c);
  void assign_binary_sensor_vbatotg_low_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vbatotg_low_flag = sensor; 
  }


  bool get_ts_cold_flag(bool read_from_i2c);
  void assign_binary_sensor_ts_cold_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ts_cold_flag = sensor; 
  }


  bool get_ts_cool_flag(bool read_from_i2c);
  void assign_binary_sensor_ts_cool_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ts_cool_flag = sensor; 
  }


  bool get_ts_warm_flag(bool read_from_i2c);
  void assign_binary_sensor_ts_warm_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ts_warm_flag = sensor; 
  }


  bool get_ts_hot_flag(bool read_from_i2c);
  void assign_binary_sensor_ts_hot_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ts_hot_flag = sensor; 
  }


  bool get_ibat_reg_flag(bool read_from_i2c);
  void assign_binary_sensor_ibat_reg_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ibat_reg_flag = sensor; 
  }


  bool get_vbus_ovp_flag(bool read_from_i2c);
  void assign_binary_sensor_vbus_ovp_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vbus_ovp_flag = sensor; 
  }


  bool get_vbat_ovp_flag(bool read_from_i2c);
  void assign_binary_sensor_vbat_ovp_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vbat_ovp_flag = sensor; 
  }


  bool get_ibus_ocp_flag(bool read_from_i2c);
  void assign_binary_sensor_ibus_ocp_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ibus_ocp_flag = sensor; 
  }


  bool get_ibat_ocp_flag(bool read_from_i2c);
  void assign_binary_sensor_ibat_ocp_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ibat_ocp_flag = sensor; 
  }


  bool get_conv_ocp_flag(bool read_from_i2c);
  void assign_binary_sensor_conv_ocp_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_conv_ocp_flag = sensor; 
  }


  bool get_vac2_ovp_flag(bool read_from_i2c);
  void assign_binary_sensor_vac2_ovp_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vac2_ovp_flag = sensor; 
  }


  bool get_vac1_ovp_flag(bool read_from_i2c);
  void assign_binary_sensor_vac1_ovp_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vac1_ovp_flag = sensor; 
  }


  bool get_vsys_short_flag(bool read_from_i2c);
  void assign_binary_sensor_vsys_short_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vsys_short_flag = sensor; 
  }


  bool get_vsys_ovp_flag(bool read_from_i2c);
  void assign_binary_sensor_vsys_ovp_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vsys_ovp_flag = sensor; 
  }


  bool get_otg_ovp_flag(bool read_from_i2c);
  void assign_binary_sensor_otg_ovp_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_otg_ovp_flag = sensor; 
  }


  bool get_otg_uvp_flag(bool read_from_i2c);
  void assign_binary_sensor_otg_uvp_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_otg_uvp_flag = sensor; 
  }


  bool get_tshut_flag(bool read_from_i2c);
  void assign_binary_sensor_tshut_flag(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_tshut_flag = sensor; 
  }


  void on_init_set_adc_en(bool value);
  void set_adc_en(bool value, bool write_to_i2c);
  bool get_adc_en(bool read_from_i2c);
  void assign_binary_sensor_adc_en(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_adc_en = sensor; 
  }


  void on_init_set_adc_rate(bool value);
  void set_adc_rate(int value, bool write_to_i2c);
  int get_adc_rate(bool read_from_i2c);
  const char* get_adc_rate_string(bool read_from_i2c);
  void assign_sensor_adc_rate(sensor::Sensor *sensor) { 
    sensor_adc_rate = sensor; 
  }
  void assign_text_sensor_adc_rate(text_sensor::TextSensor *sensor) { 
    text_sensor_adc_rate = sensor; 
  }


  void on_init_set_adc_sample(bool value);
  void set_adc_sample(int value, bool write_to_i2c);
  int get_adc_sample(bool read_from_i2c);
  const char* get_adc_sample_string(bool read_from_i2c);
  void assign_sensor_adc_sample(sensor::Sensor *sensor) { 
    sensor_adc_sample = sensor; 
  }
  void assign_text_sensor_adc_sample(text_sensor::TextSensor *sensor) { 
    text_sensor_adc_sample = sensor; 
  }


  void on_init_set_adc_avg(bool value);
  void set_adc_avg(int value, bool write_to_i2c);
  int get_adc_avg(bool read_from_i2c);
  const char* get_adc_avg_string(bool read_from_i2c);
  void assign_sensor_adc_avg(sensor::Sensor *sensor) { 
    sensor_adc_avg = sensor; 
  }
  void assign_text_sensor_adc_avg(text_sensor::TextSensor *sensor) { 
    text_sensor_adc_avg = sensor; 
  }


  void on_init_set_adc_avg_init(bool value);
  void set_adc_avg_init(bool value, bool write_to_i2c);
  bool get_adc_avg_init(bool read_from_i2c);
  void assign_binary_sensor_adc_avg_init(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_adc_avg_init = sensor; 
  }


  void on_init_set_ibus_adc_dis(bool value);
  void set_ibus_adc_dis(bool value, bool write_to_i2c);
  bool get_ibus_adc_dis(bool read_from_i2c);
  void assign_binary_sensor_ibus_adc_dis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ibus_adc_dis = sensor; 
  }


  void on_init_set_ibat_adc_dis(bool value);
  void set_ibat_adc_dis(bool value, bool write_to_i2c);
  bool get_ibat_adc_dis(bool read_from_i2c);
  void assign_binary_sensor_ibat_adc_dis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ibat_adc_dis = sensor; 
  }


  void on_init_set_vbus_adc_dis(bool value);
  void set_vbus_adc_dis(bool value, bool write_to_i2c);
  bool get_vbus_adc_dis(bool read_from_i2c);
  void assign_binary_sensor_vbus_adc_dis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vbus_adc_dis = sensor; 
  }


  void on_init_set_vbat_adc_dis(bool value);
  void set_vbat_adc_dis(bool value, bool write_to_i2c);
  bool get_vbat_adc_dis(bool read_from_i2c);
  void assign_binary_sensor_vbat_adc_dis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vbat_adc_dis = sensor; 
  }


  void on_init_set_vsys_adc_dis(bool value);
  void set_vsys_adc_dis(bool value, bool write_to_i2c);
  bool get_vsys_adc_dis(bool read_from_i2c);
  void assign_binary_sensor_vsys_adc_dis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vsys_adc_dis = sensor; 
  }


  void on_init_set_ts_adc_dis(bool value);
  void set_ts_adc_dis(bool value, bool write_to_i2c);
  bool get_ts_adc_dis(bool read_from_i2c);
  void assign_binary_sensor_ts_adc_dis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_ts_adc_dis = sensor; 
  }


  void on_init_set_tdie_adc_dis(bool value);
  void set_tdie_adc_dis(bool value, bool write_to_i2c);
  bool get_tdie_adc_dis(bool read_from_i2c);
  void assign_binary_sensor_tdie_adc_dis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_tdie_adc_dis = sensor; 
  }


  void on_init_set_dplus_adc_dis(bool value);
  void set_dplus_adc_dis(bool value, bool write_to_i2c);
  bool get_dplus_adc_dis(bool read_from_i2c);
  void assign_binary_sensor_dplus_adc_dis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_dplus_adc_dis = sensor; 
  }


  void on_init_set_dminus_adc_dis(bool value);
  void set_dminus_adc_dis(bool value, bool write_to_i2c);
  bool get_dminus_adc_dis(bool read_from_i2c);
  void assign_binary_sensor_dminus_adc_dis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_dminus_adc_dis = sensor; 
  }


  void on_init_set_vac2_adc_dis(bool value);
  void set_vac2_adc_dis(bool value, bool write_to_i2c);
  bool get_vac2_adc_dis(bool read_from_i2c);
  void assign_binary_sensor_vac2_adc_dis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vac2_adc_dis = sensor; 
  }


  void on_init_set_vac1_adc_dis(bool value);
  void set_vac1_adc_dis(bool value, bool write_to_i2c);
  bool get_vac1_adc_dis(bool read_from_i2c);
  void assign_binary_sensor_vac1_adc_dis(binary_sensor::BinarySensor *sensor) { 
    binary_sensor_vac1_adc_dis = sensor; 
  }


  int get_ibus_adc(bool read_from_i2c);
  void assign_sensor_ibus_adc(sensor::Sensor *sensor) { 
    sensor_ibus_adc = sensor; 
  }


  int get_ibat_adc(bool read_from_i2c);
  void assign_sensor_ibat_adc(sensor::Sensor *sensor) { 
    sensor_ibat_adc = sensor; 
  }


  int get_vbus_adc(bool read_from_i2c);
  void assign_sensor_vbus_adc(sensor::Sensor *sensor) { 
    sensor_vbus_adc = sensor; 
  }


  int get_vac1_adc(bool read_from_i2c);
  void assign_sensor_vac1_adc(sensor::Sensor *sensor) { 
    sensor_vac1_adc = sensor; 
  }


  int get_vac2_adc(bool read_from_i2c);
  void assign_sensor_vac2_adc(sensor::Sensor *sensor) { 
    sensor_vac2_adc = sensor; 
  }


  int get_vbat_adc(bool read_from_i2c);
  void assign_sensor_vbat_adc(sensor::Sensor *sensor) { 
    sensor_vbat_adc = sensor; 
  }


  int get_vsys_adc(bool read_from_i2c);
  void assign_sensor_vsys_adc(sensor::Sensor *sensor) { 
    sensor_vsys_adc = sensor; 
  }


  float get_ts_adc(bool read_from_i2c);
  void assign_sensor_ts_adc(sensor::Sensor *sensor) { 
    sensor_ts_adc = sensor; 
  }


  float get_tdie_adc(bool read_from_i2c);
  void assign_sensor_tdie_adc(sensor::Sensor *sensor) { 
    sensor_tdie_adc = sensor; 
  }


  int get_dplus_adc(bool read_from_i2c);
  void assign_sensor_dplus_adc(sensor::Sensor *sensor) { 
    sensor_dplus_adc = sensor; 
  }


  int get_dminus_adc(bool read_from_i2c);
  void assign_sensor_dminus_adc(sensor::Sensor *sensor) { 
    sensor_dminus_adc = sensor; 
  }


  void on_init_set_dplus_dac(bool value);
  void set_dplus_dac(int value, bool write_to_i2c);
  int get_dplus_dac(bool read_from_i2c);
  const char* get_dplus_dac_string(bool read_from_i2c);
  void assign_sensor_dplus_dac(sensor::Sensor *sensor) { 
    sensor_dplus_dac = sensor; 
  }
  void assign_text_sensor_dplus_dac(text_sensor::TextSensor *sensor) { 
    text_sensor_dplus_dac = sensor; 
  }


  void on_init_set_dminus_dac(bool value);
  void set_dminus_dac(int value, bool write_to_i2c);
  int get_dminus_dac(bool read_from_i2c);
  const char* get_dminus_dac_string(bool read_from_i2c);
  void assign_sensor_dminus_dac(sensor::Sensor *sensor) { 
    sensor_dminus_dac = sensor; 
  }
  void assign_text_sensor_dminus_dac(text_sensor::TextSensor *sensor) { 
    text_sensor_dminus_dac = sensor; 
  }


  int get_pn(bool read_from_i2c);
  const char* get_pn_string(bool read_from_i2c);
  void assign_sensor_pn(sensor::Sensor *sensor) { 
    sensor_pn = sensor; 
  }
  void assign_text_sensor_pn(text_sensor::TextSensor *sensor) { 
    text_sensor_pn = sensor; 
  }


  int get_dev_rev(bool read_from_i2c);
  const char* get_dev_rev_string(bool read_from_i2c);
  void assign_sensor_dev_rev(sensor::Sensor *sensor) { 
    sensor_dev_rev = sensor; 
  }
  void assign_text_sensor_dev_rev(text_sensor::TextSensor *sensor) { 
    text_sensor_dev_rev = sensor; 
  }



 protected:

  int last_value_vsysmin = 0;
  bool on_init_set_vsysmin_ = false;
  sensor::Sensor *sensor_vsysmin {nullptr};


  int last_value_vreg = 0;
  bool on_init_set_vreg_ = false;
  sensor::Sensor *sensor_vreg {nullptr};


  int last_value_ichg = 0;
  bool on_init_set_ichg_ = false;
  sensor::Sensor *sensor_ichg {nullptr};


  int last_value_vindpm = 0;
  bool on_init_set_vindpm_ = false;
  sensor::Sensor *sensor_vindpm {nullptr};


  int last_value_iindpm = 0;
  bool on_init_set_iindpm_ = false;
  sensor::Sensor *sensor_iindpm {nullptr};


  int last_value_vbat_lowv = 0;
  bool on_init_set_vbat_lowv_ = false;
  sensor::Sensor *sensor_vbat_lowv {nullptr};
  text_sensor::TextSensor *text_sensor_vbat_lowv {nullptr};


  int last_value_iprechg = 0;
  bool on_init_set_iprechg_ = false;
  sensor::Sensor *sensor_iprechg {nullptr};


  bool last_value_reg_rst = false;
  bool on_init_set_reg_rst_ = false;
  binary_sensor::BinarySensor *binary_sensor_reg_rst {nullptr};


  bool last_value_stop_wd_chg = false;
  bool on_init_set_stop_wd_chg_ = false;
  binary_sensor::BinarySensor *binary_sensor_stop_wd_chg {nullptr};


  int last_value_iterm = 0;
  bool on_init_set_iterm_ = false;
  sensor::Sensor *sensor_iterm {nullptr};


  int last_value_cell = 0;
  bool on_init_set_cell_ = false;
  sensor::Sensor *sensor_cell {nullptr};
  text_sensor::TextSensor *text_sensor_cell {nullptr};


  int last_value_trechg = 0;
  bool on_init_set_trechg_ = false;
  sensor::Sensor *sensor_trechg {nullptr};
  text_sensor::TextSensor *text_sensor_trechg {nullptr};


  int last_value_vrechg = 0;
  bool on_init_set_vrechg_ = false;
  sensor::Sensor *sensor_vrechg {nullptr};


  int last_value_votg = 0;
  bool on_init_set_votg_ = false;
  sensor::Sensor *sensor_votg {nullptr};


  int last_value_prechg_tmr = 0;
  bool on_init_set_prechg_tmr_ = false;
  sensor::Sensor *sensor_prechg_tmr {nullptr};
  text_sensor::TextSensor *text_sensor_prechg_tmr {nullptr};


  int last_value_iotg = 0;
  bool on_init_set_iotg_ = false;
  sensor::Sensor *sensor_iotg {nullptr};


  int last_value_topoff_tmr = 0;
  bool on_init_set_topoff_tmr_ = false;
  sensor::Sensor *sensor_topoff_tmr {nullptr};
  text_sensor::TextSensor *text_sensor_topoff_tmr {nullptr};


  bool last_value_en_trichg_tmr = false;
  bool on_init_set_en_trichg_tmr_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_trichg_tmr {nullptr};


  bool last_value_en_prechg_tmr = false;
  bool on_init_set_en_prechg_tmr_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_prechg_tmr {nullptr};


  bool last_value_en_chg_tmr = false;
  bool on_init_set_en_chg_tmr_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_chg_tmr {nullptr};


  int last_value_chg_tmr = 0;
  bool on_init_set_chg_tmr_ = false;
  sensor::Sensor *sensor_chg_tmr {nullptr};
  text_sensor::TextSensor *text_sensor_chg_tmr {nullptr};


  bool last_value_tmr2x_en = false;
  bool on_init_set_tmr2x_en_ = false;
  binary_sensor::BinarySensor *binary_sensor_tmr2x_en {nullptr};


  bool last_value_en_auto_ibatdis = false;
  bool on_init_set_en_auto_ibatdis_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_auto_ibatdis {nullptr};


  bool last_value_force_ibatdis = false;
  bool on_init_set_force_ibatdis_ = false;
  binary_sensor::BinarySensor *binary_sensor_force_ibatdis {nullptr};


  bool last_value_en_chg = false;
  bool on_init_set_en_chg_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_chg {nullptr};


  bool last_value_en_ico = false;
  bool on_init_set_en_ico_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_ico {nullptr};


  bool last_value_force_ico = false;
  bool on_init_set_force_ico_ = false;
  binary_sensor::BinarySensor *binary_sensor_force_ico {nullptr};


  bool last_value_en_hiz = false;
  bool on_init_set_en_hiz_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_hiz {nullptr};


  bool last_value_en_term = false;
  bool on_init_set_en_term_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_term {nullptr};


  bool last_value_en_backup = false;
  bool on_init_set_en_backup_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_backup {nullptr};


  int last_value_vbus_backup = 0;
  bool on_init_set_vbus_backup_ = false;
  sensor::Sensor *sensor_vbus_backup {nullptr};
  text_sensor::TextSensor *text_sensor_vbus_backup {nullptr};


  int last_value_vac_ovp = 0;
  bool on_init_set_vac_ovp_ = false;
  sensor::Sensor *sensor_vac_ovp {nullptr};
  text_sensor::TextSensor *text_sensor_vac_ovp {nullptr};


  bool last_value_wd_rst = false;
  bool on_init_set_wd_rst_ = false;
  binary_sensor::BinarySensor *binary_sensor_wd_rst {nullptr};


  int last_value_watchdog = 0;
  bool on_init_set_watchdog_ = false;
  sensor::Sensor *sensor_watchdog {nullptr};
  text_sensor::TextSensor *text_sensor_watchdog {nullptr};


  bool last_value_force_indet = false;
  bool on_init_set_force_indet_ = false;
  binary_sensor::BinarySensor *binary_sensor_force_indet {nullptr};


  bool last_value_auto_indet_en = false;
  bool on_init_set_auto_indet_en_ = false;
  binary_sensor::BinarySensor *binary_sensor_auto_indet_en {nullptr};


  bool last_value_en_12v = false;
  bool on_init_set_en_12v_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_12v {nullptr};


  bool last_value_en_9v = false;
  bool on_init_set_en_9v_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_9v {nullptr};


  bool last_value_hvdcp_en = false;
  bool on_init_set_hvdcp_en_ = false;
  binary_sensor::BinarySensor *binary_sensor_hvdcp_en {nullptr};


  int last_value_sdrv_ctrl = 0;
  bool on_init_set_sdrv_ctrl_ = false;
  sensor::Sensor *sensor_sdrv_ctrl {nullptr};
  text_sensor::TextSensor *text_sensor_sdrv_ctrl {nullptr};


  int last_value_sdrv_dly = 0;
  bool on_init_set_sdrv_dly_ = false;
  sensor::Sensor *sensor_sdrv_dly {nullptr};
  text_sensor::TextSensor *text_sensor_sdrv_dly {nullptr};


  bool last_value_dis_acdrv = false;
  bool on_init_set_dis_acdrv_ = false;
  binary_sensor::BinarySensor *binary_sensor_dis_acdrv {nullptr};


  bool last_value_en_otg = false;
  bool on_init_set_en_otg_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_otg {nullptr};


  bool last_value_pfm_otg_dis = false;
  bool on_init_set_pfm_otg_dis_ = false;
  binary_sensor::BinarySensor *binary_sensor_pfm_otg_dis {nullptr};


  bool last_value_pfm_fwd_dis = false;
  bool on_init_set_pfm_fwd_dis_ = false;
  binary_sensor::BinarySensor *binary_sensor_pfm_fwd_dis {nullptr};


  int last_value_wkup_dly = 0;
  bool on_init_set_wkup_dly_ = false;
  sensor::Sensor *sensor_wkup_dly {nullptr};
  text_sensor::TextSensor *text_sensor_wkup_dly {nullptr};


  bool last_value_dis_ldo = false;
  bool on_init_set_dis_ldo_ = false;
  binary_sensor::BinarySensor *binary_sensor_dis_ldo {nullptr};


  bool last_value_dis_otg_ooa = false;
  bool on_init_set_dis_otg_ooa_ = false;
  binary_sensor::BinarySensor *binary_sensor_dis_otg_ooa {nullptr};


  bool last_value_dis_fwd_ooa = false;
  bool on_init_set_dis_fwd_ooa_ = false;
  binary_sensor::BinarySensor *binary_sensor_dis_fwd_ooa {nullptr};


  bool last_value_en_acdrv2 = false;
  bool on_init_set_en_acdrv2_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_acdrv2 {nullptr};


  bool last_value_en_acdrv1 = false;
  bool on_init_set_en_acdrv1_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_acdrv1 {nullptr};


  int last_value_pwm_freq = 0;
  bool on_init_set_pwm_freq_ = false;
  sensor::Sensor *sensor_pwm_freq {nullptr};
  text_sensor::TextSensor *text_sensor_pwm_freq {nullptr};


  bool last_value_dis_stat = false;
  bool on_init_set_dis_stat_ = false;
  binary_sensor::BinarySensor *binary_sensor_dis_stat {nullptr};


  bool last_value_dis_vsys_short = false;
  bool on_init_set_dis_vsys_short_ = false;
  binary_sensor::BinarySensor *binary_sensor_dis_vsys_short {nullptr};


  bool last_value_dis_votg_uvp = false;
  bool on_init_set_dis_votg_uvp_ = false;
  binary_sensor::BinarySensor *binary_sensor_dis_votg_uvp {nullptr};


  bool last_value_force_vindpm_det = false;
  bool on_init_set_force_vindpm_det_ = false;
  binary_sensor::BinarySensor *binary_sensor_force_vindpm_det {nullptr};


  bool last_value_en_ibus_ocp = false;
  bool on_init_set_en_ibus_ocp_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_ibus_ocp {nullptr};


  bool last_value_sfet_present = false;
  bool on_init_set_sfet_present_ = false;
  binary_sensor::BinarySensor *binary_sensor_sfet_present {nullptr};


  bool last_value_en_ibat = false;
  bool on_init_set_en_ibat_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_ibat {nullptr};


  int last_value_ibat_reg = 0;
  bool on_init_set_ibat_reg_ = false;
  sensor::Sensor *sensor_ibat_reg {nullptr};
  text_sensor::TextSensor *text_sensor_ibat_reg {nullptr};


  bool last_value_en_iindpm = false;
  bool on_init_set_en_iindpm_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_iindpm {nullptr};


  bool last_value_en_extilim = false;
  bool on_init_set_en_extilim_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_extilim {nullptr};


  bool last_value_en_batoc = false;
  bool on_init_set_en_batoc_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_batoc {nullptr};


  int last_value_voc_pct = 0;
  bool on_init_set_voc_pct_ = false;
  sensor::Sensor *sensor_voc_pct {nullptr};
  text_sensor::TextSensor *text_sensor_voc_pct {nullptr};


  int last_value_voc_dly = 0;
  bool on_init_set_voc_dly_ = false;
  sensor::Sensor *sensor_voc_dly {nullptr};
  text_sensor::TextSensor *text_sensor_voc_dly {nullptr};


  int last_value_voc_rate = 0;
  bool on_init_set_voc_rate_ = false;
  sensor::Sensor *sensor_voc_rate {nullptr};
  text_sensor::TextSensor *text_sensor_voc_rate {nullptr};


  bool last_value_en_mppt = false;
  bool on_init_set_en_mppt_ = false;
  binary_sensor::BinarySensor *binary_sensor_en_mppt {nullptr};


  int last_value_treg = 0;
  bool on_init_set_treg_ = false;
  sensor::Sensor *sensor_treg {nullptr};
  text_sensor::TextSensor *text_sensor_treg {nullptr};


  int last_value_tshut = 0;
  bool on_init_set_tshut_ = false;
  sensor::Sensor *sensor_tshut {nullptr};
  text_sensor::TextSensor *text_sensor_tshut {nullptr};


  bool last_value_vbus_pd_en = false;
  bool on_init_set_vbus_pd_en_ = false;
  binary_sensor::BinarySensor *binary_sensor_vbus_pd_en {nullptr};


  bool last_value_vac1_pd_en = false;
  bool on_init_set_vac1_pd_en_ = false;
  binary_sensor::BinarySensor *binary_sensor_vac1_pd_en {nullptr};


  bool last_value_vac2_pd_en = false;
  bool on_init_set_vac2_pd_en_ = false;
  binary_sensor::BinarySensor *binary_sensor_vac2_pd_en {nullptr};


  int last_value_bkup_acfet1_on = 0;
  bool on_init_set_bkup_acfet1_on_ = false;
  sensor::Sensor *sensor_bkup_acfet1_on {nullptr};
  text_sensor::TextSensor *text_sensor_bkup_acfet1_on {nullptr};


  int last_value_jeita_vset = 0;
  bool on_init_set_jeita_vset_ = false;
  sensor::Sensor *sensor_jeita_vset {nullptr};
  text_sensor::TextSensor *text_sensor_jeita_vset {nullptr};


  int last_value_jeita_iseth = 0;
  bool on_init_set_jeita_iseth_ = false;
  sensor::Sensor *sensor_jeita_iseth {nullptr};
  text_sensor::TextSensor *text_sensor_jeita_iseth {nullptr};


  int last_value_jeita_isetc = 0;
  bool on_init_set_jeita_isetc_ = false;
  sensor::Sensor *sensor_jeita_isetc {nullptr};
  text_sensor::TextSensor *text_sensor_jeita_isetc {nullptr};


  int last_value_ts_cool = 0;
  bool on_init_set_ts_cool_ = false;
  sensor::Sensor *sensor_ts_cool {nullptr};
  text_sensor::TextSensor *text_sensor_ts_cool {nullptr};


  int last_value_ts_warm = 0;
  bool on_init_set_ts_warm_ = false;
  sensor::Sensor *sensor_ts_warm {nullptr};
  text_sensor::TextSensor *text_sensor_ts_warm {nullptr};


  int last_value_bhot = 0;
  bool on_init_set_bhot_ = false;
  sensor::Sensor *sensor_bhot {nullptr};
  text_sensor::TextSensor *text_sensor_bhot {nullptr};


  int last_value_bcold = 0;
  bool on_init_set_bcold_ = false;
  sensor::Sensor *sensor_bcold {nullptr};
  text_sensor::TextSensor *text_sensor_bcold {nullptr};


  bool last_value_ts_ignore = false;
  bool on_init_set_ts_ignore_ = false;
  binary_sensor::BinarySensor *binary_sensor_ts_ignore {nullptr};


  int last_value_ico_ilim = 0;
  sensor::Sensor *sensor_ico_ilim {nullptr};


  int last_value_iindpm_stat = 0;
  sensor::Sensor *sensor_iindpm_stat {nullptr};
  text_sensor::TextSensor *text_sensor_iindpm_stat {nullptr};


  int last_value_vindpm_stat = 0;
  sensor::Sensor *sensor_vindpm_stat {nullptr};
  text_sensor::TextSensor *text_sensor_vindpm_stat {nullptr};


  int last_value_wd_stat = 0;
  sensor::Sensor *sensor_wd_stat {nullptr};
  text_sensor::TextSensor *text_sensor_wd_stat {nullptr};


  int last_value_pg_stat = 0;
  sensor::Sensor *sensor_pg_stat {nullptr};
  text_sensor::TextSensor *text_sensor_pg_stat {nullptr};


  int last_value_ac2_present_stat = 0;
  sensor::Sensor *sensor_ac2_present_stat {nullptr};
  text_sensor::TextSensor *text_sensor_ac2_present_stat {nullptr};


  int last_value_ac1_present_stat = 0;
  sensor::Sensor *sensor_ac1_present_stat {nullptr};
  text_sensor::TextSensor *text_sensor_ac1_present_stat {nullptr};


  int last_value_vbus_present_stat = 0;
  sensor::Sensor *sensor_vbus_present_stat {nullptr};
  text_sensor::TextSensor *text_sensor_vbus_present_stat {nullptr};


  int last_value_chg_stat = 0;
  sensor::Sensor *sensor_chg_stat {nullptr};
  text_sensor::TextSensor *text_sensor_chg_stat {nullptr};


  int last_value_vbus_stat = 0;
  sensor::Sensor *sensor_vbus_stat {nullptr};
  text_sensor::TextSensor *text_sensor_vbus_stat {nullptr};


  bool last_value_bc12_done_stat = false;
  binary_sensor::BinarySensor *binary_sensor_bc12_done_stat {nullptr};


  int last_value_ico_stat = 0;
  sensor::Sensor *sensor_ico_stat {nullptr};
  text_sensor::TextSensor *text_sensor_ico_stat {nullptr};


  int last_value_treg_stat = 0;
  sensor::Sensor *sensor_treg_stat {nullptr};
  text_sensor::TextSensor *text_sensor_treg_stat {nullptr};


  int last_value_dpdm_stat = 0;
  sensor::Sensor *sensor_dpdm_stat {nullptr};
  text_sensor::TextSensor *text_sensor_dpdm_stat {nullptr};


  int last_value_vbat_present_stat = 0;
  sensor::Sensor *sensor_vbat_present_stat {nullptr};
  text_sensor::TextSensor *text_sensor_vbat_present_stat {nullptr};


  bool last_value_acrb2_stat = false;
  binary_sensor::BinarySensor *binary_sensor_acrb2_stat {nullptr};


  bool last_value_acrb1_stat = false;
  binary_sensor::BinarySensor *binary_sensor_acrb1_stat {nullptr};


  bool last_value_adc_done_stat = false;
  binary_sensor::BinarySensor *binary_sensor_adc_done_stat {nullptr};


  int last_value_vsys_stat = 0;
  sensor::Sensor *sensor_vsys_stat {nullptr};
  text_sensor::TextSensor *text_sensor_vsys_stat {nullptr};


  int last_value_chg_tmr_stat = 0;
  sensor::Sensor *sensor_chg_tmr_stat {nullptr};
  text_sensor::TextSensor *text_sensor_chg_tmr_stat {nullptr};


  int last_value_trichg_tmr_stat = 0;
  sensor::Sensor *sensor_trichg_tmr_stat {nullptr};
  text_sensor::TextSensor *text_sensor_trichg_tmr_stat {nullptr};


  int last_value_prechg_tmr_stat = 0;
  sensor::Sensor *sensor_prechg_tmr_stat {nullptr};
  text_sensor::TextSensor *text_sensor_prechg_tmr_stat {nullptr};


  int last_value_vbatotg_low_stat = 0;
  sensor::Sensor *sensor_vbatotg_low_stat {nullptr};
  text_sensor::TextSensor *text_sensor_vbatotg_low_stat {nullptr};


  int last_value_ts_cold_stat = 0;
  sensor::Sensor *sensor_ts_cold_stat {nullptr};
  text_sensor::TextSensor *text_sensor_ts_cold_stat {nullptr};


  int last_value_ts_cool_stat = 0;
  sensor::Sensor *sensor_ts_cool_stat {nullptr};
  text_sensor::TextSensor *text_sensor_ts_cool_stat {nullptr};


  int last_value_ts_warm_stat = 0;
  sensor::Sensor *sensor_ts_warm_stat {nullptr};
  text_sensor::TextSensor *text_sensor_ts_warm_stat {nullptr};


  int last_value_ts_hot_stat = 0;
  sensor::Sensor *sensor_ts_hot_stat {nullptr};
  text_sensor::TextSensor *text_sensor_ts_hot_stat {nullptr};


  bool last_value_ibat_reg_stat = false;
  binary_sensor::BinarySensor *binary_sensor_ibat_reg_stat {nullptr};


  bool last_value_vbus_ovp_stat = false;
  binary_sensor::BinarySensor *binary_sensor_vbus_ovp_stat {nullptr};


  bool last_value_vbat_ovp_stat = false;
  binary_sensor::BinarySensor *binary_sensor_vbat_ovp_stat {nullptr};


  bool last_value_ibus_ocp_stat = false;
  binary_sensor::BinarySensor *binary_sensor_ibus_ocp_stat {nullptr};


  bool last_value_ibat_ocp_stat = false;
  binary_sensor::BinarySensor *binary_sensor_ibat_ocp_stat {nullptr};


  bool last_value_conv_ocp_stat = false;
  binary_sensor::BinarySensor *binary_sensor_conv_ocp_stat {nullptr};


  bool last_value_vac2_ovp_stat = false;
  binary_sensor::BinarySensor *binary_sensor_vac2_ovp_stat {nullptr};


  bool last_value_vac1_ovp_stat = false;
  binary_sensor::BinarySensor *binary_sensor_vac1_ovp_stat {nullptr};


  bool last_value_vsys_short_stat = false;
  binary_sensor::BinarySensor *binary_sensor_vsys_short_stat {nullptr};


  bool last_value_vsys_ovp_stat = false;
  binary_sensor::BinarySensor *binary_sensor_vsys_ovp_stat {nullptr};


  bool last_value_otg_ovp_stat = false;
  binary_sensor::BinarySensor *binary_sensor_otg_ovp_stat {nullptr};


  bool last_value_otg_uvp_stat = false;
  binary_sensor::BinarySensor *binary_sensor_otg_uvp_stat {nullptr};


  bool last_value_tshut_stat = false;
  binary_sensor::BinarySensor *binary_sensor_tshut_stat {nullptr};


  bool last_value_iindpm_flag = false;
  binary_sensor::BinarySensor *binary_sensor_iindpm_flag {nullptr};


  bool last_value_vindpm_flag = false;
  binary_sensor::BinarySensor *binary_sensor_vindpm_flag {nullptr};


  bool last_value_wd_flag = false;
  binary_sensor::BinarySensor *binary_sensor_wd_flag {nullptr};


  bool last_value_poorsrc_flag = false;
  binary_sensor::BinarySensor *binary_sensor_poorsrc_flag {nullptr};


  bool last_value_pg_flag = false;
  binary_sensor::BinarySensor *binary_sensor_pg_flag {nullptr};


  bool last_value_ac2_present_flag = false;
  binary_sensor::BinarySensor *binary_sensor_ac2_present_flag {nullptr};


  bool last_value_ac1_present_flag = false;
  binary_sensor::BinarySensor *binary_sensor_ac1_present_flag {nullptr};


  bool last_value_vbus_present_flag = false;
  binary_sensor::BinarySensor *binary_sensor_vbus_present_flag {nullptr};


  bool last_value_chg_flag = false;
  binary_sensor::BinarySensor *binary_sensor_chg_flag {nullptr};


  bool last_value_ico_flag = false;
  binary_sensor::BinarySensor *binary_sensor_ico_flag {nullptr};


  bool last_value_vbus_flag = false;
  binary_sensor::BinarySensor *binary_sensor_vbus_flag {nullptr};


  bool last_value_treg_flag = false;
  binary_sensor::BinarySensor *binary_sensor_treg_flag {nullptr};


  bool last_value_vbat_present_flag = false;
  binary_sensor::BinarySensor *binary_sensor_vbat_present_flag {nullptr};


  bool last_value_bc1_2_done_flag = false;
  binary_sensor::BinarySensor *binary_sensor_bc1_2_done_flag {nullptr};


  bool last_value_dpdm_done_flag = false;
  binary_sensor::BinarySensor *binary_sensor_dpdm_done_flag {nullptr};


  bool last_value_adc_done_flag = false;
  binary_sensor::BinarySensor *binary_sensor_adc_done_flag {nullptr};


  bool last_value_vsys_flag = false;
  binary_sensor::BinarySensor *binary_sensor_vsys_flag {nullptr};


  bool last_value_chg_tmr_flag = false;
  binary_sensor::BinarySensor *binary_sensor_chg_tmr_flag {nullptr};


  bool last_value_trichg_tmr_flag = false;
  binary_sensor::BinarySensor *binary_sensor_trichg_tmr_flag {nullptr};


  bool last_value_prechg_tmr_flag = false;
  binary_sensor::BinarySensor *binary_sensor_prechg_tmr_flag {nullptr};


  bool last_value_topoff_tmr_flag = false;
  binary_sensor::BinarySensor *binary_sensor_topoff_tmr_flag {nullptr};


  bool last_value_vbatotg_low_flag = false;
  binary_sensor::BinarySensor *binary_sensor_vbatotg_low_flag {nullptr};


  bool last_value_ts_cold_flag = false;
  binary_sensor::BinarySensor *binary_sensor_ts_cold_flag {nullptr};


  bool last_value_ts_cool_flag = false;
  binary_sensor::BinarySensor *binary_sensor_ts_cool_flag {nullptr};


  bool last_value_ts_warm_flag = false;
  binary_sensor::BinarySensor *binary_sensor_ts_warm_flag {nullptr};


  bool last_value_ts_hot_flag = false;
  binary_sensor::BinarySensor *binary_sensor_ts_hot_flag {nullptr};


  bool last_value_ibat_reg_flag = false;
  binary_sensor::BinarySensor *binary_sensor_ibat_reg_flag {nullptr};


  bool last_value_vbus_ovp_flag = false;
  binary_sensor::BinarySensor *binary_sensor_vbus_ovp_flag {nullptr};


  bool last_value_vbat_ovp_flag = false;
  binary_sensor::BinarySensor *binary_sensor_vbat_ovp_flag {nullptr};


  bool last_value_ibus_ocp_flag = false;
  binary_sensor::BinarySensor *binary_sensor_ibus_ocp_flag {nullptr};


  bool last_value_ibat_ocp_flag = false;
  binary_sensor::BinarySensor *binary_sensor_ibat_ocp_flag {nullptr};


  bool last_value_conv_ocp_flag = false;
  binary_sensor::BinarySensor *binary_sensor_conv_ocp_flag {nullptr};


  bool last_value_vac2_ovp_flag = false;
  binary_sensor::BinarySensor *binary_sensor_vac2_ovp_flag {nullptr};


  bool last_value_vac1_ovp_flag = false;
  binary_sensor::BinarySensor *binary_sensor_vac1_ovp_flag {nullptr};


  bool last_value_vsys_short_flag = false;
  binary_sensor::BinarySensor *binary_sensor_vsys_short_flag {nullptr};


  bool last_value_vsys_ovp_flag = false;
  binary_sensor::BinarySensor *binary_sensor_vsys_ovp_flag {nullptr};


  bool last_value_otg_ovp_flag = false;
  binary_sensor::BinarySensor *binary_sensor_otg_ovp_flag {nullptr};


  bool last_value_otg_uvp_flag = false;
  binary_sensor::BinarySensor *binary_sensor_otg_uvp_flag {nullptr};


  bool last_value_tshut_flag = false;
  binary_sensor::BinarySensor *binary_sensor_tshut_flag {nullptr};


  bool last_value_adc_en = false;
  bool on_init_set_adc_en_ = false;
  binary_sensor::BinarySensor *binary_sensor_adc_en {nullptr};


  int last_value_adc_rate = 0;
  bool on_init_set_adc_rate_ = false;
  sensor::Sensor *sensor_adc_rate {nullptr};
  text_sensor::TextSensor *text_sensor_adc_rate {nullptr};


  int last_value_adc_sample = 0;
  bool on_init_set_adc_sample_ = false;
  sensor::Sensor *sensor_adc_sample {nullptr};
  text_sensor::TextSensor *text_sensor_adc_sample {nullptr};


  int last_value_adc_avg = 0;
  bool on_init_set_adc_avg_ = false;
  sensor::Sensor *sensor_adc_avg {nullptr};
  text_sensor::TextSensor *text_sensor_adc_avg {nullptr};


  bool last_value_adc_avg_init = false;
  bool on_init_set_adc_avg_init_ = false;
  binary_sensor::BinarySensor *binary_sensor_adc_avg_init {nullptr};


  bool last_value_ibus_adc_dis = false;
  bool on_init_set_ibus_adc_dis_ = false;
  binary_sensor::BinarySensor *binary_sensor_ibus_adc_dis {nullptr};


  bool last_value_ibat_adc_dis = false;
  bool on_init_set_ibat_adc_dis_ = false;
  binary_sensor::BinarySensor *binary_sensor_ibat_adc_dis {nullptr};


  bool last_value_vbus_adc_dis = false;
  bool on_init_set_vbus_adc_dis_ = false;
  binary_sensor::BinarySensor *binary_sensor_vbus_adc_dis {nullptr};


  bool last_value_vbat_adc_dis = false;
  bool on_init_set_vbat_adc_dis_ = false;
  binary_sensor::BinarySensor *binary_sensor_vbat_adc_dis {nullptr};


  bool last_value_vsys_adc_dis = false;
  bool on_init_set_vsys_adc_dis_ = false;
  binary_sensor::BinarySensor *binary_sensor_vsys_adc_dis {nullptr};


  bool last_value_ts_adc_dis = false;
  bool on_init_set_ts_adc_dis_ = false;
  binary_sensor::BinarySensor *binary_sensor_ts_adc_dis {nullptr};


  bool last_value_tdie_adc_dis = false;
  bool on_init_set_tdie_adc_dis_ = false;
  binary_sensor::BinarySensor *binary_sensor_tdie_adc_dis {nullptr};


  bool last_value_dplus_adc_dis = false;
  bool on_init_set_dplus_adc_dis_ = false;
  binary_sensor::BinarySensor *binary_sensor_dplus_adc_dis {nullptr};


  bool last_value_dminus_adc_dis = false;
  bool on_init_set_dminus_adc_dis_ = false;
  binary_sensor::BinarySensor *binary_sensor_dminus_adc_dis {nullptr};


  bool last_value_vac2_adc_dis = false;
  bool on_init_set_vac2_adc_dis_ = false;
  binary_sensor::BinarySensor *binary_sensor_vac2_adc_dis {nullptr};


  bool last_value_vac1_adc_dis = false;
  bool on_init_set_vac1_adc_dis_ = false;
  binary_sensor::BinarySensor *binary_sensor_vac1_adc_dis {nullptr};


  int last_value_ibus_adc = 0;
  sensor::Sensor *sensor_ibus_adc {nullptr};


  int last_value_ibat_adc = 0;
  sensor::Sensor *sensor_ibat_adc {nullptr};


  int last_value_vbus_adc = 0;
  sensor::Sensor *sensor_vbus_adc {nullptr};


  int last_value_vac1_adc = 0;
  sensor::Sensor *sensor_vac1_adc {nullptr};


  int last_value_vac2_adc = 0;
  sensor::Sensor *sensor_vac2_adc {nullptr};


  int last_value_vbat_adc = 0;
  sensor::Sensor *sensor_vbat_adc {nullptr};


  int last_value_vsys_adc = 0;
  sensor::Sensor *sensor_vsys_adc {nullptr};


  float last_value_ts_adc = 0.0f;
  sensor::Sensor *sensor_ts_adc {nullptr};


  float last_value_tdie_adc = 0.0f;
  sensor::Sensor *sensor_tdie_adc {nullptr};


  int last_value_dplus_adc = 0;
  sensor::Sensor *sensor_dplus_adc {nullptr};


  int last_value_dminus_adc = 0;
  sensor::Sensor *sensor_dminus_adc {nullptr};


  int last_value_dplus_dac = 0;
  bool on_init_set_dplus_dac_ = false;
  sensor::Sensor *sensor_dplus_dac {nullptr};
  text_sensor::TextSensor *text_sensor_dplus_dac {nullptr};


  int last_value_dminus_dac = 0;
  bool on_init_set_dminus_dac_ = false;
  sensor::Sensor *sensor_dminus_dac {nullptr};
  text_sensor::TextSensor *text_sensor_dminus_dac {nullptr};


  int last_value_pn = 0;
  sensor::Sensor *sensor_pn {nullptr};
  text_sensor::TextSensor *text_sensor_pn {nullptr};


  int last_value_dev_rev = 0;
  sensor::Sensor *sensor_dev_rev {nullptr};
  text_sensor::TextSensor *text_sensor_dev_rev {nullptr};



  private:
    BQ25798NoI2C *bq25798_noi2c {nullptr};
};  // class BQ25798Component

}  // namespace bq25798
}  // namespace esphome