
#pragma once

#include "esphome/components/text_sensor/text_sensor.h"
#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

#include "../bq25798_component.h"

namespace esphome {
namespace bq25798 {

class BQ25798TextSensor : public sensor::Sensor,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

  void assign_text_sensor_vbat_lowv(text_sensor::TextSensor *sensor);
  void assign_text_sensor_cell(text_sensor::TextSensor *sensor);
  void assign_text_sensor_trechg(text_sensor::TextSensor *sensor);
  void assign_text_sensor_prechg_tmr(text_sensor::TextSensor *sensor);
  void assign_text_sensor_topoff_tmr(text_sensor::TextSensor *sensor);
  void assign_text_sensor_chg_tmr(text_sensor::TextSensor *sensor);
  void assign_text_sensor_vbus_backup(text_sensor::TextSensor *sensor);
  void assign_text_sensor_vac_ovp(text_sensor::TextSensor *sensor);
  void assign_text_sensor_watchdog(text_sensor::TextSensor *sensor);
  void assign_text_sensor_sdrv_ctrl(text_sensor::TextSensor *sensor);
  void assign_text_sensor_sdrv_dly(text_sensor::TextSensor *sensor);
  void assign_text_sensor_wkup_dly(text_sensor::TextSensor *sensor);
  void assign_text_sensor_pwm_freq(text_sensor::TextSensor *sensor);
  void assign_text_sensor_ibat_reg(text_sensor::TextSensor *sensor);
  void assign_text_sensor_voc_pct(text_sensor::TextSensor *sensor);
  void assign_text_sensor_voc_dly(text_sensor::TextSensor *sensor);
  void assign_text_sensor_voc_rate(text_sensor::TextSensor *sensor);
  void assign_text_sensor_treg(text_sensor::TextSensor *sensor);
  void assign_text_sensor_tshut(text_sensor::TextSensor *sensor);
  void assign_text_sensor_bkup_acfet1_on(text_sensor::TextSensor *sensor);
  void assign_text_sensor_jeita_vset(text_sensor::TextSensor *sensor);
  void assign_text_sensor_jeita_iseth(text_sensor::TextSensor *sensor);
  void assign_text_sensor_jeita_isetc(text_sensor::TextSensor *sensor);
  void assign_text_sensor_ts_cool(text_sensor::TextSensor *sensor);
  void assign_text_sensor_ts_warm(text_sensor::TextSensor *sensor);
  void assign_text_sensor_bhot(text_sensor::TextSensor *sensor);
  void assign_text_sensor_bcold(text_sensor::TextSensor *sensor);
  void assign_text_sensor_iindpm_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_vindpm_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_wd_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_pg_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_ac2_present_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_ac1_present_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_vbus_present_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_chg_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_vbus_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_ico_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_treg_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_dpdm_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_vbat_present_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_acrb2_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_acrb1_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_vsys_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_chg_tmr_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_trichg_tmr_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_prechg_tmr_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_vbatotg_low_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_ts_cold_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_ts_cool_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_ts_warm_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_ts_hot_stat(text_sensor::TextSensor *sensor);
  void assign_text_sensor_adc_rate(text_sensor::TextSensor *sensor);
  void assign_text_sensor_adc_sample(text_sensor::TextSensor *sensor);
  void assign_text_sensor_adc_avg(text_sensor::TextSensor *sensor);
  void assign_text_sensor_dplus_dac(text_sensor::TextSensor *sensor);
  void assign_text_sensor_dminus_dac(text_sensor::TextSensor *sensor);
  void assign_text_sensor_pn(text_sensor::TextSensor *sensor);
  void assign_text_sensor_dev_rev(text_sensor::TextSensor *sensor);

 protected:
  text_sensor::TextSensor *text_sensor_vbat_lowv_ {nullptr};
  text_sensor::TextSensor *text_sensor_cell_ {nullptr};
  text_sensor::TextSensor *text_sensor_trechg_ {nullptr};
  text_sensor::TextSensor *text_sensor_prechg_tmr_ {nullptr};
  text_sensor::TextSensor *text_sensor_topoff_tmr_ {nullptr};
  text_sensor::TextSensor *text_sensor_chg_tmr_ {nullptr};
  text_sensor::TextSensor *text_sensor_vbus_backup_ {nullptr};
  text_sensor::TextSensor *text_sensor_vac_ovp_ {nullptr};
  text_sensor::TextSensor *text_sensor_watchdog_ {nullptr};
  text_sensor::TextSensor *text_sensor_sdrv_ctrl_ {nullptr};
  text_sensor::TextSensor *text_sensor_sdrv_dly_ {nullptr};
  text_sensor::TextSensor *text_sensor_wkup_dly_ {nullptr};
  text_sensor::TextSensor *text_sensor_pwm_freq_ {nullptr};
  text_sensor::TextSensor *text_sensor_ibat_reg_ {nullptr};
  text_sensor::TextSensor *text_sensor_voc_pct_ {nullptr};
  text_sensor::TextSensor *text_sensor_voc_dly_ {nullptr};
  text_sensor::TextSensor *text_sensor_voc_rate_ {nullptr};
  text_sensor::TextSensor *text_sensor_treg_ {nullptr};
  text_sensor::TextSensor *text_sensor_tshut_ {nullptr};
  text_sensor::TextSensor *text_sensor_bkup_acfet1_on_ {nullptr};
  text_sensor::TextSensor *text_sensor_jeita_vset_ {nullptr};
  text_sensor::TextSensor *text_sensor_jeita_iseth_ {nullptr};
  text_sensor::TextSensor *text_sensor_jeita_isetc_ {nullptr};
  text_sensor::TextSensor *text_sensor_ts_cool_ {nullptr};
  text_sensor::TextSensor *text_sensor_ts_warm_ {nullptr};
  text_sensor::TextSensor *text_sensor_bhot_ {nullptr};
  text_sensor::TextSensor *text_sensor_bcold_ {nullptr};
  text_sensor::TextSensor *text_sensor_iindpm_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_vindpm_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_wd_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_pg_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_ac2_present_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_ac1_present_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_vbus_present_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_chg_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_vbus_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_ico_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_treg_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_dpdm_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_vbat_present_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_acrb2_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_acrb1_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_vsys_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_chg_tmr_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_trichg_tmr_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_prechg_tmr_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_vbatotg_low_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_ts_cold_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_ts_cool_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_ts_warm_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_ts_hot_stat_ {nullptr};
  text_sensor::TextSensor *text_sensor_adc_rate_ {nullptr};
  text_sensor::TextSensor *text_sensor_adc_sample_ {nullptr};
  text_sensor::TextSensor *text_sensor_adc_avg_ {nullptr};
  text_sensor::TextSensor *text_sensor_dplus_dac_ {nullptr};
  text_sensor::TextSensor *text_sensor_dminus_dac_ {nullptr};
  text_sensor::TextSensor *text_sensor_pn_ {nullptr};
  text_sensor::TextSensor *text_sensor_dev_rev_ {nullptr};
};

}  // namespace bq25798
}  // namespace esphome