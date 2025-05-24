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
  void assign_sensor_acrb2_stat(sensor::Sensor *sensor);
  void assign_sensor_acrb1_stat(sensor::Sensor *sensor);
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
  sensor::Sensor *sensor_vsysmin_ {nullptr};
  sensor::Sensor *sensor_vreg_ {nullptr};
  sensor::Sensor *sensor_ichg_ {nullptr};
  sensor::Sensor *sensor_vindpm_ {nullptr};
  sensor::Sensor *sensor_iindpm_ {nullptr};
  sensor::Sensor *sensor_vbat_lowv_ {nullptr};
  sensor::Sensor *sensor_iprechg_ {nullptr};
  sensor::Sensor *sensor_iterm_ {nullptr};
  sensor::Sensor *sensor_cell_ {nullptr};
  sensor::Sensor *sensor_trechg_ {nullptr};
  sensor::Sensor *sensor_vrechg_ {nullptr};
  sensor::Sensor *sensor_votg_ {nullptr};
  sensor::Sensor *sensor_prechg_tmr_ {nullptr};
  sensor::Sensor *sensor_iotg_ {nullptr};
  sensor::Sensor *sensor_topoff_tmr_ {nullptr};
  sensor::Sensor *sensor_chg_tmr_ {nullptr};
  sensor::Sensor *sensor_vbus_backup_ {nullptr};
  sensor::Sensor *sensor_vac_ovp_ {nullptr};
  sensor::Sensor *sensor_watchdog_ {nullptr};
  sensor::Sensor *sensor_sdrv_ctrl_ {nullptr};
  sensor::Sensor *sensor_sdrv_dly_ {nullptr};
  sensor::Sensor *sensor_wkup_dly_ {nullptr};
  sensor::Sensor *sensor_pwm_freq_ {nullptr};
  sensor::Sensor *sensor_ibat_reg_ {nullptr};
  sensor::Sensor *sensor_voc_pct_ {nullptr};
  sensor::Sensor *sensor_voc_dly_ {nullptr};
  sensor::Sensor *sensor_voc_rate_ {nullptr};
  sensor::Sensor *sensor_treg_ {nullptr};
  sensor::Sensor *sensor_tshut_ {nullptr};
  sensor::Sensor *sensor_jeita_vset_ {nullptr};
  sensor::Sensor *sensor_jeita_iseth_ {nullptr};
  sensor::Sensor *sensor_jeita_isetc_ {nullptr};
  sensor::Sensor *sensor_ts_cool_ {nullptr};
  sensor::Sensor *sensor_ts_warm_ {nullptr};
  sensor::Sensor *sensor_bhot_ {nullptr};
  sensor::Sensor *sensor_bcold_ {nullptr};
  sensor::Sensor *sensor_ico_ilim_ {nullptr};
  sensor::Sensor *sensor_iindpm_stat_ {nullptr};
  sensor::Sensor *sensor_vindpm_stat_ {nullptr};
  sensor::Sensor *sensor_wd_stat_ {nullptr};
  sensor::Sensor *sensor_pg_stat_ {nullptr};
  sensor::Sensor *sensor_ac2_present_stat_ {nullptr};
  sensor::Sensor *sensor_ac1_present_stat_ {nullptr};
  sensor::Sensor *sensor_vbus_present_stat_ {nullptr};
  sensor::Sensor *sensor_chg_stat_ {nullptr};
  sensor::Sensor *sensor_vbus_stat_ {nullptr};
  sensor::Sensor *sensor_ico_stat_ {nullptr};
  sensor::Sensor *sensor_treg_stat_ {nullptr};
  sensor::Sensor *sensor_dpdm_stat_ {nullptr};
  sensor::Sensor *sensor_vbat_present_stat_ {nullptr};
  sensor::Sensor *sensor_acrb2_stat_ {nullptr};
  sensor::Sensor *sensor_acrb1_stat_ {nullptr};
  sensor::Sensor *sensor_vsys_stat_ {nullptr};
  sensor::Sensor *sensor_chg_tmr_stat_ {nullptr};
  sensor::Sensor *sensor_trichg_tmr_stat_ {nullptr};
  sensor::Sensor *sensor_prechg_tmr_stat_ {nullptr};
  sensor::Sensor *sensor_vbatotg_low_stat_ {nullptr};
  sensor::Sensor *sensor_ts_cold_stat_ {nullptr};
  sensor::Sensor *sensor_ts_cool_stat_ {nullptr};
  sensor::Sensor *sensor_ts_warm_stat_ {nullptr};
  sensor::Sensor *sensor_ts_hot_stat_ {nullptr};
  sensor::Sensor *sensor_adc_rate_ {nullptr};
  sensor::Sensor *sensor_adc_sample_ {nullptr};
  sensor::Sensor *sensor_adc_avg_ {nullptr};
  sensor::Sensor *sensor_ibus_adc_ {nullptr};
  sensor::Sensor *sensor_ibat_adc_ {nullptr};
  sensor::Sensor *sensor_vbus_adc_ {nullptr};
  sensor::Sensor *sensor_vac1_adc_ {nullptr};
  sensor::Sensor *sensor_vac2_adc_ {nullptr};
  sensor::Sensor *sensor_vbat_adc_ {nullptr};
  sensor::Sensor *sensor_vsys_adc_ {nullptr};
  sensor::Sensor *sensor_ts_adc_ {nullptr};
  sensor::Sensor *sensor_tdie_adc_ {nullptr};
  sensor::Sensor *sensor_dplus_adc_ {nullptr};
  sensor::Sensor *sensor_dminus_adc_ {nullptr};
  sensor::Sensor *sensor_dplus_dac_ {nullptr};
  sensor::Sensor *sensor_dminus_dac_ {nullptr};
  sensor::Sensor *sensor_pn_ {nullptr};
  sensor::Sensor *sensor_dev_rev_ {nullptr};
};

}  // namespace bq25798
}  // namespace esphome