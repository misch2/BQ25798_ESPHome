#pragma once

#include "esphome/components/sensor/sensor.h"
#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

#include "../bq25798_component.h"

namespace esphome {
namespace bq25798 {

class BQ25798Sensor : public sensor::Sensor,
                      public PollingComponent,
                      public Parented<BQ25798Component> {
 public:
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

  void assign_sensor_vsysmin(sensor::Sensor *sensor);
  void assign_sensor_vreg(sensor::Sensor *sensor);
  void assign_sensor_ichg(sensor::Sensor *sensor);
  void assign_sensor_vindpm(sensor::Sensor *sensor);
  void assign_sensor_iindpm(sensor::Sensor *sensor);
  void assign_sensor_vbat_lowv(sensor::Sensor *sensor);
  void assign_sensor_iprechg(sensor::Sensor *sensor);
  void assign_sensor_iterm(sensor::Sensor *sensor);
  void assign_sensor_cell(sensor::Sensor *sensor);
  void assign_sensor_trechg(sensor::Sensor *sensor);
  void assign_sensor_vrechg(sensor::Sensor *sensor);
  void assign_sensor_votg(sensor::Sensor *sensor);
  void assign_sensor_prechg_tmr(sensor::Sensor *sensor);
  void assign_sensor_iotg(sensor::Sensor *sensor);
  void assign_sensor_topoff_tmr(sensor::Sensor *sensor);
  void assign_sensor_chg_tmr(sensor::Sensor *sensor);
  void assign_sensor_vbus_backup(sensor::Sensor *sensor);
  void assign_sensor_vac_ovp(sensor::Sensor *sensor);
  void assign_sensor_watchdog(sensor::Sensor *sensor);
  void assign_sensor_sdrv_ctrl(sensor::Sensor *sensor);
  void assign_sensor_sdrv_dly(sensor::Sensor *sensor);
  void assign_sensor_wkup_dly(sensor::Sensor *sensor);
  void assign_sensor_pwm_freq(sensor::Sensor *sensor);
  void assign_sensor_ibat_reg(sensor::Sensor *sensor);
  void assign_sensor_voc_pct(sensor::Sensor *sensor);
  void assign_sensor_voc_dly(sensor::Sensor *sensor);
  void assign_sensor_voc_rate(sensor::Sensor *sensor);
  void assign_sensor_treg(sensor::Sensor *sensor);
  void assign_sensor_tshut(sensor::Sensor *sensor);
  void assign_sensor_bkup_acfet1_on(sensor::Sensor *sensor);
  void assign_sensor_jeita_vset(sensor::Sensor *sensor);
  void assign_sensor_jeita_iseth(sensor::Sensor *sensor);
  void assign_sensor_jeita_isetc(sensor::Sensor *sensor);
  void assign_sensor_ts_cool(sensor::Sensor *sensor);
  void assign_sensor_ts_warm(sensor::Sensor *sensor);
  void assign_sensor_bhot(sensor::Sensor *sensor);
  void assign_sensor_bcold(sensor::Sensor *sensor);
  void assign_sensor_ico_ilim(sensor::Sensor *sensor);
  void assign_sensor_iindpm_stat(sensor::Sensor *sensor);
  void assign_sensor_vindpm_stat(sensor::Sensor *sensor);
  void assign_sensor_wd_stat(sensor::Sensor *sensor);
  void assign_sensor_pg_stat(sensor::Sensor *sensor);
  void assign_sensor_ac2_present_stat(sensor::Sensor *sensor);
  void assign_sensor_ac1_present_stat(sensor::Sensor *sensor);
  void assign_sensor_vbus_present_stat(sensor::Sensor *sensor);
  void assign_sensor_chg_stat(sensor::Sensor *sensor);
  void assign_sensor_vbus_stat(sensor::Sensor *sensor);
  void assign_sensor_ico_stat(sensor::Sensor *sensor);
  void assign_sensor_treg_stat(sensor::Sensor *sensor);
  void assign_sensor_dpdm_stat(sensor::Sensor *sensor);
  void assign_sensor_vbat_present_stat(sensor::Sensor *sensor);
  void assign_sensor_vsys_stat(sensor::Sensor *sensor);
  void assign_sensor_chg_tmr_stat(sensor::Sensor *sensor);
  void assign_sensor_trichg_tmr_stat(sensor::Sensor *sensor);
  void assign_sensor_prechg_tmr_stat(sensor::Sensor *sensor);
  void assign_sensor_vbatotg_low_stat(sensor::Sensor *sensor);
  void assign_sensor_ts_cold_stat(sensor::Sensor *sensor);
  void assign_sensor_ts_cool_stat(sensor::Sensor *sensor);
  void assign_sensor_ts_warm_stat(sensor::Sensor *sensor);
  void assign_sensor_ts_hot_stat(sensor::Sensor *sensor);
  void assign_sensor_adc_rate(sensor::Sensor *sensor);
  void assign_sensor_adc_sample(sensor::Sensor *sensor);
  void assign_sensor_adc_avg(sensor::Sensor *sensor);
  void assign_sensor_ibus_adc(sensor::Sensor *sensor);
  void assign_sensor_ibat_adc(sensor::Sensor *sensor);
  void assign_sensor_vbus_adc(sensor::Sensor *sensor);
  void assign_sensor_vac1_adc(sensor::Sensor *sensor);
  void assign_sensor_vac2_adc(sensor::Sensor *sensor);
  void assign_sensor_vbat_adc(sensor::Sensor *sensor);
  void assign_sensor_vsys_adc(sensor::Sensor *sensor);
  void assign_sensor_ts_adc(sensor::Sensor *sensor);
  void assign_sensor_tdie_adc(sensor::Sensor *sensor);
  void assign_sensor_dplus_adc(sensor::Sensor *sensor);
  void assign_sensor_dminus_adc(sensor::Sensor *sensor);
  void assign_sensor_dplus_dac(sensor::Sensor *sensor);
  void assign_sensor_dminus_dac(sensor::Sensor *sensor);
  void assign_sensor_pn(sensor::Sensor *sensor);
  void assign_sensor_dev_rev(sensor::Sensor *sensor);

 protected:
  sensor::Sensor *sensor_vsysmin {nullptr};
  sensor::Sensor *sensor_vreg {nullptr};
  sensor::Sensor *sensor_ichg {nullptr};
  sensor::Sensor *sensor_vindpm {nullptr};
  sensor::Sensor *sensor_iindpm {nullptr};
  sensor::Sensor *sensor_vbat_lowv {nullptr};
  sensor::Sensor *sensor_iprechg {nullptr};
  sensor::Sensor *sensor_iterm {nullptr};
  sensor::Sensor *sensor_cell {nullptr};
  sensor::Sensor *sensor_trechg {nullptr};
  sensor::Sensor *sensor_vrechg {nullptr};
  sensor::Sensor *sensor_votg {nullptr};
  sensor::Sensor *sensor_prechg_tmr {nullptr};
  sensor::Sensor *sensor_iotg {nullptr};
  sensor::Sensor *sensor_topoff_tmr {nullptr};
  sensor::Sensor *sensor_chg_tmr {nullptr};
  sensor::Sensor *sensor_vbus_backup {nullptr};
  sensor::Sensor *sensor_vac_ovp {nullptr};
  sensor::Sensor *sensor_watchdog {nullptr};
  sensor::Sensor *sensor_sdrv_ctrl {nullptr};
  sensor::Sensor *sensor_sdrv_dly {nullptr};
  sensor::Sensor *sensor_wkup_dly {nullptr};
  sensor::Sensor *sensor_pwm_freq {nullptr};
  sensor::Sensor *sensor_ibat_reg {nullptr};
  sensor::Sensor *sensor_voc_pct {nullptr};
  sensor::Sensor *sensor_voc_dly {nullptr};
  sensor::Sensor *sensor_voc_rate {nullptr};
  sensor::Sensor *sensor_treg {nullptr};
  sensor::Sensor *sensor_tshut {nullptr};
  sensor::Sensor *sensor_bkup_acfet1_on {nullptr};
  sensor::Sensor *sensor_jeita_vset {nullptr};
  sensor::Sensor *sensor_jeita_iseth {nullptr};
  sensor::Sensor *sensor_jeita_isetc {nullptr};
  sensor::Sensor *sensor_ts_cool {nullptr};
  sensor::Sensor *sensor_ts_warm {nullptr};
  sensor::Sensor *sensor_bhot {nullptr};
  sensor::Sensor *sensor_bcold {nullptr};
  sensor::Sensor *sensor_ico_ilim {nullptr};
  sensor::Sensor *sensor_iindpm_stat {nullptr};
  sensor::Sensor *sensor_vindpm_stat {nullptr};
  sensor::Sensor *sensor_wd_stat {nullptr};
  sensor::Sensor *sensor_pg_stat {nullptr};
  sensor::Sensor *sensor_ac2_present_stat {nullptr};
  sensor::Sensor *sensor_ac1_present_stat {nullptr};
  sensor::Sensor *sensor_vbus_present_stat {nullptr};
  sensor::Sensor *sensor_chg_stat {nullptr};
  sensor::Sensor *sensor_vbus_stat {nullptr};
  sensor::Sensor *sensor_ico_stat {nullptr};
  sensor::Sensor *sensor_treg_stat {nullptr};
  sensor::Sensor *sensor_dpdm_stat {nullptr};
  sensor::Sensor *sensor_vbat_present_stat {nullptr};
  sensor::Sensor *sensor_vsys_stat {nullptr};
  sensor::Sensor *sensor_chg_tmr_stat {nullptr};
  sensor::Sensor *sensor_trichg_tmr_stat {nullptr};
  sensor::Sensor *sensor_prechg_tmr_stat {nullptr};
  sensor::Sensor *sensor_vbatotg_low_stat {nullptr};
  sensor::Sensor *sensor_ts_cold_stat {nullptr};
  sensor::Sensor *sensor_ts_cool_stat {nullptr};
  sensor::Sensor *sensor_ts_warm_stat {nullptr};
  sensor::Sensor *sensor_ts_hot_stat {nullptr};
  sensor::Sensor *sensor_adc_rate {nullptr};
  sensor::Sensor *sensor_adc_sample {nullptr};
  sensor::Sensor *sensor_adc_avg {nullptr};
  sensor::Sensor *sensor_ibus_adc {nullptr};
  sensor::Sensor *sensor_ibat_adc {nullptr};
  sensor::Sensor *sensor_vbus_adc {nullptr};
  sensor::Sensor *sensor_vac1_adc {nullptr};
  sensor::Sensor *sensor_vac2_adc {nullptr};
  sensor::Sensor *sensor_vbat_adc {nullptr};
  sensor::Sensor *sensor_vsys_adc {nullptr};
  sensor::Sensor *sensor_ts_adc {nullptr};
  sensor::Sensor *sensor_tdie_adc {nullptr};
  sensor::Sensor *sensor_dplus_adc {nullptr};
  sensor::Sensor *sensor_dminus_adc {nullptr};
  sensor::Sensor *sensor_dplus_dac {nullptr};
  sensor::Sensor *sensor_dminus_dac {nullptr};
  sensor::Sensor *sensor_pn {nullptr};
  sensor::Sensor *sensor_dev_rev {nullptr};
};

}  // namespace bq25798
}  // namespace esphome