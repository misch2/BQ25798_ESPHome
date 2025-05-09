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

  // VSYSMIN - Minimal System Voltage
  void on_init_set_vsysmin(bool value);
  void set_vsysmin(int value, bool write_to_i2c);
  int get_vsysmin(bool read_from_i2c);

  // VREG - Charge Voltage Limit
  void on_init_set_vreg(bool value);
  void set_vreg(int value, bool write_to_i2c);
  int get_vreg(bool read_from_i2c);

  // ICHG - Charge Current Limit
  void on_init_set_ichg(bool value);
  void set_ichg(int value, bool write_to_i2c);
  int get_ichg(bool read_from_i2c);

  // VINDPM - Input Voltage Limit
  void on_init_set_vindpm(bool value);
  void set_vindpm(int value, bool write_to_i2c);
  int get_vindpm(bool read_from_i2c);

  // IINDPM - Input Current Limit
  void on_init_set_iindpm(bool value);
  void set_iindpm(int value, bool write_to_i2c);
  int get_iindpm(bool read_from_i2c);

  // VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
  void on_init_set_vbat_lowv(bool value);
  void set_vbat_lowv(int value, bool write_to_i2c);
  int get_vbat_lowv(bool read_from_i2c);
  const char* get_vbat_lowv_string(bool read_from_i2c);

  // IPRECHG - Precharge Current Limit
  void on_init_set_iprechg(bool value);
  void set_iprechg(int value, bool write_to_i2c);
  int get_iprechg(bool read_from_i2c);

  // REG_RST - Reset registers to default values and reset timer
  void on_init_set_reg_rst(bool value);
  void set_reg_rst(bool value, bool write_to_i2c);
  bool get_reg_rst(bool read_from_i2c);

  // STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
  void on_init_set_stop_wd_chg(bool value);
  void set_stop_wd_chg(bool value, bool write_to_i2c);
  bool get_stop_wd_chg(bool read_from_i2c);

  // ITERM - Termination Current Limit
  void on_init_set_iterm(bool value);
  void set_iterm(int value, bool write_to_i2c);
  int get_iterm(bool read_from_i2c);

  // CELL - Battery cell count
  void on_init_set_cell(bool value);
  void set_cell(int value, bool write_to_i2c);
  int get_cell(bool read_from_i2c);
  const char* get_cell_string(bool read_from_i2c);

  // TRECHG - Battery recharge delay time
  void on_init_set_trechg(bool value);
  void set_trechg(int value, bool write_to_i2c);
  int get_trechg(bool read_from_i2c);
  const char* get_trechg_string(bool read_from_i2c);

  // VRECHG - Battery Recharge Threshold Offset (Below VREG)
  void on_init_set_vrechg(bool value);
  void set_vrechg(int value, bool write_to_i2c);
  int get_vrechg(bool read_from_i2c);

  // VOTG - OTG mode regulation voltage
  void on_init_set_votg(bool value);
  void set_votg(int value, bool write_to_i2c);
  int get_votg(bool read_from_i2c);

  // PRECHG_TMR - Pre-charge safety timer setting
  void on_init_set_prechg_tmr(bool value);
  void set_prechg_tmr(int value, bool write_to_i2c);
  int get_prechg_tmr(bool read_from_i2c);
  const char* get_prechg_tmr_string(bool read_from_i2c);

  // IOTG - OTG current limit
  void on_init_set_iotg(bool value);
  void set_iotg(int value, bool write_to_i2c);
  int get_iotg(bool read_from_i2c);

  // TOPOFF_TMR - Top-off timer control
  void on_init_set_topoff_tmr(bool value);
  void set_topoff_tmr(int value, bool write_to_i2c);
  int get_topoff_tmr(bool read_from_i2c);
  const char* get_topoff_tmr_string(bool read_from_i2c);

  // EN_TRICHG_TMR - Trickle charge timer enable
  void on_init_set_en_trichg_tmr(bool value);
  void set_en_trichg_tmr(bool value, bool write_to_i2c);
  bool get_en_trichg_tmr(bool read_from_i2c);

  // EN_PRECHG_TMR - Precharge timer enable
  void on_init_set_en_prechg_tmr(bool value);
  void set_en_prechg_tmr(bool value, bool write_to_i2c);
  bool get_en_prechg_tmr(bool read_from_i2c);

  // EN_CHG_TMR - Fast charge timer enable
  void on_init_set_en_chg_tmr(bool value);
  void set_en_chg_tmr(bool value, bool write_to_i2c);
  bool get_en_chg_tmr(bool read_from_i2c);

  // CHG_TMR - Fast charge timer setting
  void on_init_set_chg_tmr(bool value);
  void set_chg_tmr(int value, bool write_to_i2c);
  int get_chg_tmr(bool read_from_i2c);
  const char* get_chg_tmr_string(bool read_from_i2c);

  // TMR2X_EN - 2x slower charging in DPM enable
  void on_init_set_tmr2x_en(bool value);
  void set_tmr2x_en(bool value, bool write_to_i2c);
  bool get_tmr2x_en(bool read_from_i2c);

  // EN_AUTO_IBATDIS - Enable the auto battery discharging during the battery OVP fault
  void on_init_set_en_auto_ibatdis(bool value);
  void set_en_auto_ibatdis(bool value, bool write_to_i2c);
  bool get_en_auto_ibatdis(bool read_from_i2c);

  // FORCE_IBATDIS - Force the battery discharging current
  void on_init_set_force_ibatdis(bool value);
  void set_force_ibatdis(bool value, bool write_to_i2c);
  bool get_force_ibatdis(bool read_from_i2c);

  // EN_CHG - Enable the charger
  void on_init_set_en_chg(bool value);
  void set_en_chg(bool value, bool write_to_i2c);
  bool get_en_chg(bool read_from_i2c);

  // EN_ICO - Enable the ICO (Input Current Optimizer)
  void on_init_set_en_ico(bool value);
  void set_en_ico(bool value, bool write_to_i2c);
  bool get_en_ico(bool read_from_i2c);

  // FORCE_ICO - Force the ICO (Input Current Optimizer)
  void on_init_set_force_ico(bool value);
  void set_force_ico(bool value, bool write_to_i2c);
  bool get_force_ico(bool read_from_i2c);

  // EN_HIZ - Enable the high impedance mode
  void on_init_set_en_hiz(bool value);
  void set_en_hiz(bool value, bool write_to_i2c);
  bool get_en_hiz(bool read_from_i2c);

  // EN_TERM - Enable the termination
  void on_init_set_en_term(bool value);
  void set_en_term(bool value, bool write_to_i2c);
  bool get_en_term(bool read_from_i2c);

  // EN_BACKUP - Enable the backup (auto OTG) mode
  void on_init_set_en_backup(bool value);
  void set_en_backup(bool value, bool write_to_i2c);
  bool get_en_backup(bool read_from_i2c);

  // VBUS_BACKUP - The thresholds to trigger the backup mode, defined as a ratio of VINDPM
  void on_init_set_vbus_backup(bool value);
  void set_vbus_backup(int value, bool write_to_i2c);
  int get_vbus_backup(bool read_from_i2c);
  const char* get_vbus_backup_string(bool read_from_i2c);

  // VAC_OVP - Over voltage protection thresholds
  void on_init_set_vac_ovp(bool value);
  void set_vac_ovp(int value, bool write_to_i2c);
  int get_vac_ovp(bool read_from_i2c);
  const char* get_vac_ovp_string(bool read_from_i2c);

  // WD_RST - I2C watch dog timer reset
  void on_init_set_wd_rst(bool value);
  void set_wd_rst(bool value, bool write_to_i2c);
  bool get_wd_rst(bool read_from_i2c);

  // WATCHDOG - Watchdog timer settings
  void on_init_set_watchdog(bool value);
  void set_watchdog(int value, bool write_to_i2c);
  int get_watchdog(bool read_from_i2c);
  const char* get_watchdog_string(bool read_from_i2c);

  // FORCE_INDET - Force D+/D- detection
  void on_init_set_force_indet(bool value);
  void set_force_indet(bool value, bool write_to_i2c);
  bool get_force_indet(bool read_from_i2c);

  // AUTO_INDET_EN - Enable automatic D+/D- detection
  void on_init_set_auto_indet_en(bool value);
  void set_auto_indet_en(bool value, bool write_to_i2c);
  bool get_auto_indet_en(bool read_from_i2c);

  // EN_12V - Enable 12V output in HVDCP
  void on_init_set_en_12v(bool value);
  void set_en_12v(bool value, bool write_to_i2c);
  bool get_en_12v(bool read_from_i2c);

  // EN_9V - Enable 9V output in HVDCP
  void on_init_set_en_9v(bool value);
  void set_en_9v(bool value, bool write_to_i2c);
  bool get_en_9v(bool read_from_i2c);

  // HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
  void on_init_set_hvdcp_en(bool value);
  void set_hvdcp_en(bool value, bool write_to_i2c);
  bool get_hvdcp_en(bool read_from_i2c);

  // SDRV_CTRL - Enable external Ship FET control
  void on_init_set_sdrv_ctrl(bool value);
  void set_sdrv_ctrl(int value, bool write_to_i2c);
  int get_sdrv_ctrl(bool read_from_i2c);
  const char* get_sdrv_ctrl_string(bool read_from_i2c);

  // SDRV_DLY - Delay for SDRV control
  void on_init_set_sdrv_dly(bool value);
  void set_sdrv_dly(int value, bool write_to_i2c);
  int get_sdrv_dly(bool read_from_i2c);
  const char* get_sdrv_dly_string(bool read_from_i2c);

  // DIS_ACDRV - Disable both AC1 and AC2 drivers
  void on_init_set_dis_acdrv(bool value);
  void set_dis_acdrv(bool value, bool write_to_i2c);
  bool get_dis_acdrv(bool read_from_i2c);

  // EN_OTG - Enable OTG mode
  void on_init_set_en_otg(bool value);
  void set_en_otg(bool value, bool write_to_i2c);
  bool get_en_otg(bool read_from_i2c);

  // PFM_OTG_DIS - Disable PFM in OTG mode
  void on_init_set_pfm_otg_dis(bool value);
  void set_pfm_otg_dis(bool value, bool write_to_i2c);
  bool get_pfm_otg_dis(bool read_from_i2c);

  // PFM_FWD_DIS - Disable PFM in forward mode
  void on_init_set_pfm_fwd_dis(bool value);
  void set_pfm_fwd_dis(bool value, bool write_to_i2c);
  bool get_pfm_fwd_dis(bool read_from_i2c);

  // WKUP_DLY - Wakeup (Ship FET) delay
  void on_init_set_wkup_dly(bool value);
  void set_wkup_dly(int value, bool write_to_i2c);
  int get_wkup_dly(bool read_from_i2c);
  const char* get_wkup_dly_string(bool read_from_i2c);

  // DIS_LDO - Disable BATFET LDO mode in precharge state
  void on_init_set_dis_ldo(bool value);
  void set_dis_ldo(bool value, bool write_to_i2c);
  bool get_dis_ldo(bool read_from_i2c);

  // DIS_OTG_OOA - Disable OOA in OTG mode
  void on_init_set_dis_otg_ooa(bool value);
  void set_dis_otg_ooa(bool value, bool write_to_i2c);
  bool get_dis_otg_ooa(bool read_from_i2c);

  // DIS_FWD_OOA - Disable OOA in forward mode
  void on_init_set_dis_fwd_ooa(bool value);
  void set_dis_fwd_ooa(bool value, bool write_to_i2c);
  bool get_dis_fwd_ooa(bool read_from_i2c);

  // EN_ACDRV2 - Enable AC2 gate driver control
  void on_init_set_en_acdrv2(bool value);
  void set_en_acdrv2(bool value, bool write_to_i2c);
  bool get_en_acdrv2(bool read_from_i2c);

  // EN_ACDRV1 - Enable AC1 gate driver control
  void on_init_set_en_acdrv1(bool value);
  void set_en_acdrv1(bool value, bool write_to_i2c);
  bool get_en_acdrv1(bool read_from_i2c);

  // PWM_FREQ - PWM frequency setting
  void on_init_set_pwm_freq(bool value);
  void set_pwm_freq(int value, bool write_to_i2c);
  int get_pwm_freq(bool read_from_i2c);
  const char* get_pwm_freq_string(bool read_from_i2c);

  // DIS_STAT - Disable STAT pin output
  void on_init_set_dis_stat(bool value);
  void set_dis_stat(bool value, bool write_to_i2c);
  bool get_dis_stat(bool read_from_i2c);

  // DIS_VSYS_SHORT - Disable VSYS short hiccup protection
  void on_init_set_dis_vsys_short(bool value);
  void set_dis_vsys_short(bool value, bool write_to_i2c);
  bool get_dis_vsys_short(bool read_from_i2c);

  // DIS_VOTG_UVP - Disable VOTG under voltage hiccup protection
  void on_init_set_dis_votg_uvp(bool value);
  void set_dis_votg_uvp(bool value, bool write_to_i2c);
  bool get_dis_votg_uvp(bool read_from_i2c);

  // FORCE_VINDPM_DET - Force VINDPM detection (settable only when VBAT>VSYSMIN)
  void on_init_set_force_vindpm_det(bool value);
  void set_force_vindpm_det(bool value, bool write_to_i2c);
  bool get_force_vindpm_det(bool read_from_i2c);

  // EN_IBUS_OCP - Enable input over current protection in forward mode
  void on_init_set_en_ibus_ocp(bool value);
  void set_en_ibus_ocp(bool value, bool write_to_i2c);
  bool get_en_ibus_ocp(bool read_from_i2c);

  // SFET_PRESENT - Ship FET present
  void on_init_set_sfet_present(bool value);
  void set_sfet_present(bool value, bool write_to_i2c);
  bool get_sfet_present(bool read_from_i2c);

  // EN_IBAT - Enable battery discharge current sensing
  void on_init_set_en_ibat(bool value);
  void set_en_ibat(bool value, bool write_to_i2c);
  bool get_en_ibat(bool read_from_i2c);

  // IBAT_REG - Battery discharge current regulation in OTG mode
  void on_init_set_ibat_reg(bool value);
  void set_ibat_reg(int value, bool write_to_i2c);
  int get_ibat_reg(bool read_from_i2c);
  const char* get_ibat_reg_string(bool read_from_i2c);

  // EN_IINDPM - Enable input current regulation
  void on_init_set_en_iindpm(bool value);
  void set_en_iindpm(bool value, bool write_to_i2c);
  bool get_en_iindpm(bool read_from_i2c);

  // EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
  void on_init_set_en_extilim(bool value);
  void set_en_extilim(bool value, bool write_to_i2c);
  bool get_en_extilim(bool read_from_i2c);

  // EN_BATOC - Enable battery discharging over current protection
  void on_init_set_en_batoc(bool value);
  void set_en_batoc(bool value, bool write_to_i2c);
  bool get_en_batoc(bool read_from_i2c);

  // VOC_PCT - 
  void on_init_set_voc_pct(bool value);
  void set_voc_pct(int value, bool write_to_i2c);
  int get_voc_pct(bool read_from_i2c);
  const char* get_voc_pct_string(bool read_from_i2c);

  // VOC_DLY - 
  void on_init_set_voc_dly(bool value);
  void set_voc_dly(int value, bool write_to_i2c);
  int get_voc_dly(bool read_from_i2c);
  const char* get_voc_dly_string(bool read_from_i2c);

  // VOC_RATE - 
  void on_init_set_voc_rate(bool value);
  void set_voc_rate(int value, bool write_to_i2c);
  int get_voc_rate(bool read_from_i2c);
  const char* get_voc_rate_string(bool read_from_i2c);

  // EN_MPPT - 
  void on_init_set_en_mppt(bool value);
  void set_en_mppt(bool value, bool write_to_i2c);
  bool get_en_mppt(bool read_from_i2c);

  // TREG - 
  void on_init_set_treg(bool value);
  void set_treg(int value, bool write_to_i2c);
  int get_treg(bool read_from_i2c);
  const char* get_treg_string(bool read_from_i2c);

  // TSHUT - 
  void on_init_set_tshut(bool value);
  void set_tshut(int value, bool write_to_i2c);
  int get_tshut(bool read_from_i2c);
  const char* get_tshut_string(bool read_from_i2c);

  // VBUS_PD_EN - 
  void on_init_set_vbus_pd_en(bool value);
  void set_vbus_pd_en(bool value, bool write_to_i2c);
  bool get_vbus_pd_en(bool read_from_i2c);

  // VAC1_PD_EN - 
  void on_init_set_vac1_pd_en(bool value);
  void set_vac1_pd_en(bool value, bool write_to_i2c);
  bool get_vac1_pd_en(bool read_from_i2c);

  // VAC2_PD_EN - 
  void on_init_set_vac2_pd_en(bool value);
  void set_vac2_pd_en(bool value, bool write_to_i2c);
  bool get_vac2_pd_en(bool read_from_i2c);

  // BKUP_ACFET1_ON - 
  void on_init_set_bkup_acfet1_on(bool value);
  void set_bkup_acfet1_on(int value, bool write_to_i2c);
  int get_bkup_acfet1_on(bool read_from_i2c);
  const char* get_bkup_acfet1_on_string(bool read_from_i2c);

  // JEITA_VSET - 
  void on_init_set_jeita_vset(bool value);
  void set_jeita_vset(int value, bool write_to_i2c);
  int get_jeita_vset(bool read_from_i2c);
  const char* get_jeita_vset_string(bool read_from_i2c);

  // JEITA_ISETH - 
  void on_init_set_jeita_iseth(bool value);
  void set_jeita_iseth(int value, bool write_to_i2c);
  int get_jeita_iseth(bool read_from_i2c);
  const char* get_jeita_iseth_string(bool read_from_i2c);

  // JEITA_ISETC - 
  void on_init_set_jeita_isetc(bool value);
  void set_jeita_isetc(int value, bool write_to_i2c);
  int get_jeita_isetc(bool read_from_i2c);
  const char* get_jeita_isetc_string(bool read_from_i2c);

  // TS_COOL - 
  void on_init_set_ts_cool(bool value);
  void set_ts_cool(int value, bool write_to_i2c);
  int get_ts_cool(bool read_from_i2c);
  const char* get_ts_cool_string(bool read_from_i2c);

  // TS_WARM - 
  void on_init_set_ts_warm(bool value);
  void set_ts_warm(int value, bool write_to_i2c);
  int get_ts_warm(bool read_from_i2c);
  const char* get_ts_warm_string(bool read_from_i2c);

  // BHOT - 
  void on_init_set_bhot(bool value);
  void set_bhot(int value, bool write_to_i2c);
  int get_bhot(bool read_from_i2c);
  const char* get_bhot_string(bool read_from_i2c);

  // BCOLD - 
  void on_init_set_bcold(bool value);
  void set_bcold(int value, bool write_to_i2c);
  int get_bcold(bool read_from_i2c);
  const char* get_bcold_string(bool read_from_i2c);

  // TS_IGNORE - 
  void on_init_set_ts_ignore(bool value);
  void set_ts_ignore(bool value, bool write_to_i2c);
  bool get_ts_ignore(bool read_from_i2c);

  // ICO_ILIM - 
  int get_ico_ilim(bool read_from_i2c);

  // IINDPM_STAT - 
  int get_iindpm_stat(bool read_from_i2c);
  const char* get_iindpm_stat_string(bool read_from_i2c);

  // VINDPM_STAT - 
  int get_vindpm_stat(bool read_from_i2c);
  const char* get_vindpm_stat_string(bool read_from_i2c);

  // WD_STAT - 
  int get_wd_stat(bool read_from_i2c);
  const char* get_wd_stat_string(bool read_from_i2c);

  // PG_STAT - 
  int get_pg_stat(bool read_from_i2c);
  const char* get_pg_stat_string(bool read_from_i2c);

  // AC2_PRESENT_STAT - 
  int get_ac2_present_stat(bool read_from_i2c);
  const char* get_ac2_present_stat_string(bool read_from_i2c);

  // AC1_PRESENT_STAT - 
  int get_ac1_present_stat(bool read_from_i2c);
  const char* get_ac1_present_stat_string(bool read_from_i2c);

  // VBUS_PRESENT_STAT - 
  int get_vbus_present_stat(bool read_from_i2c);
  const char* get_vbus_present_stat_string(bool read_from_i2c);

  // CHG_STAT - Charge Status bits
  int get_chg_stat(bool read_from_i2c);
  const char* get_chg_stat_string(bool read_from_i2c);

  // VBUS_STAT - VBUS status bits
  int get_vbus_stat(bool read_from_i2c);
  const char* get_vbus_stat_string(bool read_from_i2c);

  // BC12_DONE_STAT - 
  bool get_bc12_done_stat(bool read_from_i2c);

  // ICO_STAT - 
  int get_ico_stat(bool read_from_i2c);
  const char* get_ico_stat_string(bool read_from_i2c);

  // TREG_STAT - 
  int get_treg_stat(bool read_from_i2c);
  const char* get_treg_stat_string(bool read_from_i2c);

  // DPDM_STAT - 
  int get_dpdm_stat(bool read_from_i2c);
  const char* get_dpdm_stat_string(bool read_from_i2c);

  // VBAT_PRESENT_STAT - 
  int get_vbat_present_stat(bool read_from_i2c);
  const char* get_vbat_present_stat_string(bool read_from_i2c);

  // ACRB2_STAT - The ACFET2-RBFET2 status
  bool get_acrb2_stat(bool read_from_i2c);

  // ACRB1_STAT - The ACFET1-RBFET1 status
  bool get_acrb1_stat(bool read_from_i2c);

  // ADC_DONE_STAT - ADC Conversion Status
  bool get_adc_done_stat(bool read_from_i2c);

  // VSYS_STAT - VSYS Regulation Status
  int get_vsys_stat(bool read_from_i2c);
  const char* get_vsys_stat_string(bool read_from_i2c);

  // CHG_TMR_STAT - Fast charge timer status
  int get_chg_tmr_stat(bool read_from_i2c);
  const char* get_chg_tmr_stat_string(bool read_from_i2c);

  // TRICHG_TMR_STAT - Trickle charge timer status
  int get_trichg_tmr_stat(bool read_from_i2c);
  const char* get_trichg_tmr_stat_string(bool read_from_i2c);

  // PRECHG_TMR_STAT - Pre-charge timer status
  int get_prechg_tmr_stat(bool read_from_i2c);
  const char* get_prechg_tmr_stat_string(bool read_from_i2c);

  // VBATOTG_LOW_STAT - VBAT too low to enable OTG flag
  int get_vbatotg_low_stat(bool read_from_i2c);
  const char* get_vbatotg_low_stat_string(bool read_from_i2c);

  // TS_COLD_STAT - The TS temperature is in the cold range
  int get_ts_cold_stat(bool read_from_i2c);
  const char* get_ts_cold_stat_string(bool read_from_i2c);

  // TS_COOL_STAT - The TS temperature is in the cool range
  int get_ts_cool_stat(bool read_from_i2c);
  const char* get_ts_cool_stat_string(bool read_from_i2c);

  // TS_WARM_STAT - The TS temperature is in the warm range
  int get_ts_warm_stat(bool read_from_i2c);
  const char* get_ts_warm_stat_string(bool read_from_i2c);

  // TS_HOT_STAT - The TS temperature is in the hot range
  int get_ts_hot_stat(bool read_from_i2c);
  const char* get_ts_hot_stat_string(bool read_from_i2c);

  // IBAT_REG_STAT - IBAT regulation status
  bool get_ibat_reg_stat(bool read_from_i2c);

  // VBUS_OVP_STAT - VBUS over-voltage status
  bool get_vbus_ovp_stat(bool read_from_i2c);

  // VBAT_OVP_STAT - VBAT over-voltage status
  bool get_vbat_ovp_stat(bool read_from_i2c);

  // IBUS_OCP_STAT - IBUS over-current status
  bool get_ibus_ocp_stat(bool read_from_i2c);

  // IBAT_OCP_STAT - IBAT over-current status
  bool get_ibat_ocp_stat(bool read_from_i2c);

  // CONV_OCP_STAT - Converter over-current status
  bool get_conv_ocp_stat(bool read_from_i2c);

  // VAC2_OVP_STAT - VAC2 over-voltage status
  bool get_vac2_ovp_stat(bool read_from_i2c);

  // VAC1_OVP_STAT - VAC1 over-voltage status
  bool get_vac1_ovp_stat(bool read_from_i2c);

  // VSYS_SHORT_STAT - 
  bool get_vsys_short_stat(bool read_from_i2c);

  // VSYS_OVP_STAT - 
  bool get_vsys_ovp_stat(bool read_from_i2c);

  // OTG_OVP_STAT - 
  bool get_otg_ovp_stat(bool read_from_i2c);

  // OTG_UVP_STAT - 
  bool get_otg_uvp_stat(bool read_from_i2c);

  // TSHUT_STAT - 
  bool get_tshut_stat(bool read_from_i2c);

  // IINDPM_FLAG - In IINDPM / IOTG regulation
  bool get_iindpm_flag(bool read_from_i2c);
  void clear_flag_iindpm_flag() { this->last_value_iindpm_flag_ = false; }
  void raise_flag_iindpm_flag() { this->last_value_iindpm_flag_ = true; }

  // VINDPM_FLAG - In VINDPM / VOTG regulation
  bool get_vindpm_flag(bool read_from_i2c);
  void clear_flag_vindpm_flag() { this->last_value_vindpm_flag_ = false; }
  void raise_flag_vindpm_flag() { this->last_value_vindpm_flag_ = true; }

  // WD_FLAG - Watchdog timer expired
  bool get_wd_flag(bool read_from_i2c);
  void clear_flag_wd_flag() { this->last_value_wd_flag_ = false; }
  void raise_flag_wd_flag() { this->last_value_wd_flag_ = true; }

  // POORSRC_FLAG - Poor source detected
  bool get_poorsrc_flag(bool read_from_i2c);
  void clear_flag_poorsrc_flag() { this->last_value_poorsrc_flag_ = false; }
  void raise_flag_poorsrc_flag() { this->last_value_poorsrc_flag_ = true; }

  // PG_FLAG - Power status changed
  bool get_pg_flag(bool read_from_i2c);
  void clear_flag_pg_flag() { this->last_value_pg_flag_ = false; }
  void raise_flag_pg_flag() { this->last_value_pg_flag_ = true; }

  // AC2_PRESENT_FLAG - AC2 present status changed
  bool get_ac2_present_flag(bool read_from_i2c);
  void clear_flag_ac2_present_flag() { this->last_value_ac2_present_flag_ = false; }
  void raise_flag_ac2_present_flag() { this->last_value_ac2_present_flag_ = true; }

  // AC1_PRESENT_FLAG - AC1 present status changed
  bool get_ac1_present_flag(bool read_from_i2c);
  void clear_flag_ac1_present_flag() { this->last_value_ac1_present_flag_ = false; }
  void raise_flag_ac1_present_flag() { this->last_value_ac1_present_flag_ = true; }

  // VBUS_PRESENT_FLAG - VBUS present status changed
  bool get_vbus_present_flag(bool read_from_i2c);
  void clear_flag_vbus_present_flag() { this->last_value_vbus_present_flag_ = false; }
  void raise_flag_vbus_present_flag() { this->last_value_vbus_present_flag_ = true; }

  // CHG_FLAG - Charging status changed
  bool get_chg_flag(bool read_from_i2c);
  void clear_flag_chg_flag() { this->last_value_chg_flag_ = false; }
  void raise_flag_chg_flag() { this->last_value_chg_flag_ = true; }

  // ICO_FLAG - ICO status changed
  bool get_ico_flag(bool read_from_i2c);
  void clear_flag_ico_flag() { this->last_value_ico_flag_ = false; }
  void raise_flag_ico_flag() { this->last_value_ico_flag_ = true; }

  // VBUS_FLAG - VBUS status changed
  bool get_vbus_flag(bool read_from_i2c);
  void clear_flag_vbus_flag() { this->last_value_vbus_flag_ = false; }
  void raise_flag_vbus_flag() { this->last_value_vbus_flag_ = true; }

  // TREG_FLAG - 
  bool get_treg_flag(bool read_from_i2c);
  void clear_flag_treg_flag() { this->last_value_treg_flag_ = false; }
  void raise_flag_treg_flag() { this->last_value_treg_flag_ = true; }

  // VBAT_PRESENT_FLAG - 
  bool get_vbat_present_flag(bool read_from_i2c);
  void clear_flag_vbat_present_flag() { this->last_value_vbat_present_flag_ = false; }
  void raise_flag_vbat_present_flag() { this->last_value_vbat_present_flag_ = true; }

  // BC1_2_DONE_FLAG - 
  bool get_bc1_2_done_flag(bool read_from_i2c);
  void clear_flag_bc1_2_done_flag() { this->last_value_bc1_2_done_flag_ = false; }
  void raise_flag_bc1_2_done_flag() { this->last_value_bc1_2_done_flag_ = true; }

  // DPDM_DONE_FLAG - 
  bool get_dpdm_done_flag(bool read_from_i2c);
  void clear_flag_dpdm_done_flag() { this->last_value_dpdm_done_flag_ = false; }
  void raise_flag_dpdm_done_flag() { this->last_value_dpdm_done_flag_ = true; }

  // ADC_DONE_FLAG - 
  bool get_adc_done_flag(bool read_from_i2c);
  void clear_flag_adc_done_flag() { this->last_value_adc_done_flag_ = false; }
  void raise_flag_adc_done_flag() { this->last_value_adc_done_flag_ = true; }

  // VSYS_FLAG - 
  bool get_vsys_flag(bool read_from_i2c);
  void clear_flag_vsys_flag() { this->last_value_vsys_flag_ = false; }
  void raise_flag_vsys_flag() { this->last_value_vsys_flag_ = true; }

  // CHG_TMR_FLAG - 
  bool get_chg_tmr_flag(bool read_from_i2c);
  void clear_flag_chg_tmr_flag() { this->last_value_chg_tmr_flag_ = false; }
  void raise_flag_chg_tmr_flag() { this->last_value_chg_tmr_flag_ = true; }

  // TRICHG_TMR_FLAG - 
  bool get_trichg_tmr_flag(bool read_from_i2c);
  void clear_flag_trichg_tmr_flag() { this->last_value_trichg_tmr_flag_ = false; }
  void raise_flag_trichg_tmr_flag() { this->last_value_trichg_tmr_flag_ = true; }

  // PRECHG_TMR_FLAG - 
  bool get_prechg_tmr_flag(bool read_from_i2c);
  void clear_flag_prechg_tmr_flag() { this->last_value_prechg_tmr_flag_ = false; }
  void raise_flag_prechg_tmr_flag() { this->last_value_prechg_tmr_flag_ = true; }

  // TOPOFF_TMR_FLAG - 
  bool get_topoff_tmr_flag(bool read_from_i2c);
  void clear_flag_topoff_tmr_flag() { this->last_value_topoff_tmr_flag_ = false; }
  void raise_flag_topoff_tmr_flag() { this->last_value_topoff_tmr_flag_ = true; }

  // VBATOTG_LOW_FLAG - 
  bool get_vbatotg_low_flag(bool read_from_i2c);
  void clear_flag_vbatotg_low_flag() { this->last_value_vbatotg_low_flag_ = false; }
  void raise_flag_vbatotg_low_flag() { this->last_value_vbatotg_low_flag_ = true; }

  // TS_COLD_FLAG - 
  bool get_ts_cold_flag(bool read_from_i2c);
  void clear_flag_ts_cold_flag() { this->last_value_ts_cold_flag_ = false; }
  void raise_flag_ts_cold_flag() { this->last_value_ts_cold_flag_ = true; }

  // TS_COOL_FLAG - 
  bool get_ts_cool_flag(bool read_from_i2c);
  void clear_flag_ts_cool_flag() { this->last_value_ts_cool_flag_ = false; }
  void raise_flag_ts_cool_flag() { this->last_value_ts_cool_flag_ = true; }

  // TS_WARM_FLAG - 
  bool get_ts_warm_flag(bool read_from_i2c);
  void clear_flag_ts_warm_flag() { this->last_value_ts_warm_flag_ = false; }
  void raise_flag_ts_warm_flag() { this->last_value_ts_warm_flag_ = true; }

  // TS_HOT_FLAG - 
  bool get_ts_hot_flag(bool read_from_i2c);
  void clear_flag_ts_hot_flag() { this->last_value_ts_hot_flag_ = false; }
  void raise_flag_ts_hot_flag() { this->last_value_ts_hot_flag_ = true; }

  // IBAT_REG_FLAG - 
  bool get_ibat_reg_flag(bool read_from_i2c);
  void clear_flag_ibat_reg_flag() { this->last_value_ibat_reg_flag_ = false; }
  void raise_flag_ibat_reg_flag() { this->last_value_ibat_reg_flag_ = true; }

  // VBUS_OVP_FLAG - 
  bool get_vbus_ovp_flag(bool read_from_i2c);
  void clear_flag_vbus_ovp_flag() { this->last_value_vbus_ovp_flag_ = false; }
  void raise_flag_vbus_ovp_flag() { this->last_value_vbus_ovp_flag_ = true; }

  // VBAT_OVP_FLAG - 
  bool get_vbat_ovp_flag(bool read_from_i2c);
  void clear_flag_vbat_ovp_flag() { this->last_value_vbat_ovp_flag_ = false; }
  void raise_flag_vbat_ovp_flag() { this->last_value_vbat_ovp_flag_ = true; }

  // IBUS_OCP_FLAG - 
  bool get_ibus_ocp_flag(bool read_from_i2c);
  void clear_flag_ibus_ocp_flag() { this->last_value_ibus_ocp_flag_ = false; }
  void raise_flag_ibus_ocp_flag() { this->last_value_ibus_ocp_flag_ = true; }

  // IBAT_OCP_FLAG - 
  bool get_ibat_ocp_flag(bool read_from_i2c);
  void clear_flag_ibat_ocp_flag() { this->last_value_ibat_ocp_flag_ = false; }
  void raise_flag_ibat_ocp_flag() { this->last_value_ibat_ocp_flag_ = true; }

  // CONV_OCP_FLAG - 
  bool get_conv_ocp_flag(bool read_from_i2c);
  void clear_flag_conv_ocp_flag() { this->last_value_conv_ocp_flag_ = false; }
  void raise_flag_conv_ocp_flag() { this->last_value_conv_ocp_flag_ = true; }

  // VAC2_OVP_FLAG - 
  bool get_vac2_ovp_flag(bool read_from_i2c);
  void clear_flag_vac2_ovp_flag() { this->last_value_vac2_ovp_flag_ = false; }
  void raise_flag_vac2_ovp_flag() { this->last_value_vac2_ovp_flag_ = true; }

  // VAC1_OVP_FLAG - 
  bool get_vac1_ovp_flag(bool read_from_i2c);
  void clear_flag_vac1_ovp_flag() { this->last_value_vac1_ovp_flag_ = false; }
  void raise_flag_vac1_ovp_flag() { this->last_value_vac1_ovp_flag_ = true; }

  // VSYS_SHORT_FLAG - 
  bool get_vsys_short_flag(bool read_from_i2c);
  void clear_flag_vsys_short_flag() { this->last_value_vsys_short_flag_ = false; }
  void raise_flag_vsys_short_flag() { this->last_value_vsys_short_flag_ = true; }

  // VSYS_OVP_FLAG - 
  bool get_vsys_ovp_flag(bool read_from_i2c);
  void clear_flag_vsys_ovp_flag() { this->last_value_vsys_ovp_flag_ = false; }
  void raise_flag_vsys_ovp_flag() { this->last_value_vsys_ovp_flag_ = true; }

  // OTG_OVP_FLAG - 
  bool get_otg_ovp_flag(bool read_from_i2c);
  void clear_flag_otg_ovp_flag() { this->last_value_otg_ovp_flag_ = false; }
  void raise_flag_otg_ovp_flag() { this->last_value_otg_ovp_flag_ = true; }

  // OTG_UVP_FLAG - 
  bool get_otg_uvp_flag(bool read_from_i2c);
  void clear_flag_otg_uvp_flag() { this->last_value_otg_uvp_flag_ = false; }
  void raise_flag_otg_uvp_flag() { this->last_value_otg_uvp_flag_ = true; }

  // TSHUT_FLAG - 
  bool get_tshut_flag(bool read_from_i2c);
  void clear_flag_tshut_flag() { this->last_value_tshut_flag_ = false; }
  void raise_flag_tshut_flag() { this->last_value_tshut_flag_ = true; }

  // ADC_EN - 
  void on_init_set_adc_en(bool value);
  void set_adc_en(bool value, bool write_to_i2c);
  bool get_adc_en(bool read_from_i2c);

  // ADC_RATE - 
  void on_init_set_adc_rate(bool value);
  void set_adc_rate(int value, bool write_to_i2c);
  int get_adc_rate(bool read_from_i2c);
  const char* get_adc_rate_string(bool read_from_i2c);

  // ADC_SAMPLE - 
  void on_init_set_adc_sample(bool value);
  void set_adc_sample(int value, bool write_to_i2c);
  int get_adc_sample(bool read_from_i2c);
  const char* get_adc_sample_string(bool read_from_i2c);

  // ADC_AVG - 
  void on_init_set_adc_avg(bool value);
  void set_adc_avg(int value, bool write_to_i2c);
  int get_adc_avg(bool read_from_i2c);
  const char* get_adc_avg_string(bool read_from_i2c);

  // ADC_AVG_INIT - 
  void on_init_set_adc_avg_init(bool value);
  void set_adc_avg_init(bool value, bool write_to_i2c);
  bool get_adc_avg_init(bool read_from_i2c);

  // IBUS_ADC_DIS - 
  void on_init_set_ibus_adc_dis(bool value);
  void set_ibus_adc_dis(bool value, bool write_to_i2c);
  bool get_ibus_adc_dis(bool read_from_i2c);

  // IBAT_ADC_DIS - 
  void on_init_set_ibat_adc_dis(bool value);
  void set_ibat_adc_dis(bool value, bool write_to_i2c);
  bool get_ibat_adc_dis(bool read_from_i2c);

  // VBUS_ADC_DIS - 
  void on_init_set_vbus_adc_dis(bool value);
  void set_vbus_adc_dis(bool value, bool write_to_i2c);
  bool get_vbus_adc_dis(bool read_from_i2c);

  // VBAT_ADC_DIS - 
  void on_init_set_vbat_adc_dis(bool value);
  void set_vbat_adc_dis(bool value, bool write_to_i2c);
  bool get_vbat_adc_dis(bool read_from_i2c);

  // VSYS_ADC_DIS - 
  void on_init_set_vsys_adc_dis(bool value);
  void set_vsys_adc_dis(bool value, bool write_to_i2c);
  bool get_vsys_adc_dis(bool read_from_i2c);

  // TS_ADC_DIS - 
  void on_init_set_ts_adc_dis(bool value);
  void set_ts_adc_dis(bool value, bool write_to_i2c);
  bool get_ts_adc_dis(bool read_from_i2c);

  // TDIE_ADC_DIS - 
  void on_init_set_tdie_adc_dis(bool value);
  void set_tdie_adc_dis(bool value, bool write_to_i2c);
  bool get_tdie_adc_dis(bool read_from_i2c);

  // DPLUS_ADC_DIS - 
  void on_init_set_dplus_adc_dis(bool value);
  void set_dplus_adc_dis(bool value, bool write_to_i2c);
  bool get_dplus_adc_dis(bool read_from_i2c);

  // DMINUS_ADC_DIS - 
  void on_init_set_dminus_adc_dis(bool value);
  void set_dminus_adc_dis(bool value, bool write_to_i2c);
  bool get_dminus_adc_dis(bool read_from_i2c);

  // VAC2_ADC_DIS - 
  void on_init_set_vac2_adc_dis(bool value);
  void set_vac2_adc_dis(bool value, bool write_to_i2c);
  bool get_vac2_adc_dis(bool read_from_i2c);

  // VAC1_ADC_DIS - 
  void on_init_set_vac1_adc_dis(bool value);
  void set_vac1_adc_dis(bool value, bool write_to_i2c);
  bool get_vac1_adc_dis(bool read_from_i2c);

  // IBUS_ADC - 
  int get_ibus_adc(bool read_from_i2c);

  // IBAT_ADC - 
  int get_ibat_adc(bool read_from_i2c);

  // VBUS_ADC - 
  int get_vbus_adc(bool read_from_i2c);

  // VAC1_ADC - 
  int get_vac1_adc(bool read_from_i2c);

  // VAC2_ADC - 
  int get_vac2_adc(bool read_from_i2c);

  // VBAT_ADC - 
  int get_vbat_adc(bool read_from_i2c);

  // VSYS_ADC - 
  int get_vsys_adc(bool read_from_i2c);

  // TS_ADC - 
  float get_ts_adc(bool read_from_i2c);

  // TDIE_ADC - TDIE ADC reading
  float get_tdie_adc(bool read_from_i2c);

  // DPLUS_ADC - D+ ADC reading
  int get_dplus_adc(bool read_from_i2c);

  // DMINUS_ADC - D- ADC reading
  int get_dminus_adc(bool read_from_i2c);

  // DPLUS_DAC - D+ Output Driver
  void on_init_set_dplus_dac(bool value);
  void set_dplus_dac(int value, bool write_to_i2c);
  int get_dplus_dac(bool read_from_i2c);
  const char* get_dplus_dac_string(bool read_from_i2c);

  // DMINUS_DAC - D- Output Driver
  void on_init_set_dminus_dac(bool value);
  void set_dminus_dac(int value, bool write_to_i2c);
  int get_dminus_dac(bool read_from_i2c);
  const char* get_dminus_dac_string(bool read_from_i2c);

  // PN - 
  int get_pn(bool read_from_i2c);
  const char* get_pn_string(bool read_from_i2c);

  // DEV_REV - 
  int get_dev_rev(bool read_from_i2c);
  const char* get_dev_rev_string(bool read_from_i2c);

protected:
  int last_value_vsysmin_ = 0;
  bool on_init_set_vsysmin_ = false;

  int last_value_vreg_ = 0;
  bool on_init_set_vreg_ = false;

  int last_value_ichg_ = 0;
  bool on_init_set_ichg_ = false;

  int last_value_vindpm_ = 0;
  bool on_init_set_vindpm_ = false;

  int last_value_iindpm_ = 0;
  bool on_init_set_iindpm_ = false;

  int last_value_vbat_lowv_ = 0;
  bool on_init_set_vbat_lowv_ = false;

  int last_value_iprechg_ = 0;
  bool on_init_set_iprechg_ = false;

  bool last_value_reg_rst_ = false;
  bool on_init_set_reg_rst_ = false;

  bool last_value_stop_wd_chg_ = false;
  bool on_init_set_stop_wd_chg_ = false;

  int last_value_iterm_ = 0;
  bool on_init_set_iterm_ = false;

  int last_value_cell_ = 0;
  bool on_init_set_cell_ = false;

  int last_value_trechg_ = 0;
  bool on_init_set_trechg_ = false;

  int last_value_vrechg_ = 0;
  bool on_init_set_vrechg_ = false;

  int last_value_votg_ = 0;
  bool on_init_set_votg_ = false;

  int last_value_prechg_tmr_ = 0;
  bool on_init_set_prechg_tmr_ = false;

  int last_value_iotg_ = 0;
  bool on_init_set_iotg_ = false;

  int last_value_topoff_tmr_ = 0;
  bool on_init_set_topoff_tmr_ = false;

  bool last_value_en_trichg_tmr_ = false;
  bool on_init_set_en_trichg_tmr_ = false;

  bool last_value_en_prechg_tmr_ = false;
  bool on_init_set_en_prechg_tmr_ = false;

  bool last_value_en_chg_tmr_ = false;
  bool on_init_set_en_chg_tmr_ = false;

  int last_value_chg_tmr_ = 0;
  bool on_init_set_chg_tmr_ = false;

  bool last_value_tmr2x_en_ = false;
  bool on_init_set_tmr2x_en_ = false;

  bool last_value_en_auto_ibatdis_ = false;
  bool on_init_set_en_auto_ibatdis_ = false;

  bool last_value_force_ibatdis_ = false;
  bool on_init_set_force_ibatdis_ = false;

  bool last_value_en_chg_ = false;
  bool on_init_set_en_chg_ = false;

  bool last_value_en_ico_ = false;
  bool on_init_set_en_ico_ = false;

  bool last_value_force_ico_ = false;
  bool on_init_set_force_ico_ = false;

  bool last_value_en_hiz_ = false;
  bool on_init_set_en_hiz_ = false;

  bool last_value_en_term_ = false;
  bool on_init_set_en_term_ = false;

  bool last_value_en_backup_ = false;
  bool on_init_set_en_backup_ = false;

  int last_value_vbus_backup_ = 0;
  bool on_init_set_vbus_backup_ = false;

  int last_value_vac_ovp_ = 0;
  bool on_init_set_vac_ovp_ = false;

  bool last_value_wd_rst_ = false;
  bool on_init_set_wd_rst_ = false;

  int last_value_watchdog_ = 0;
  bool on_init_set_watchdog_ = false;

  bool last_value_force_indet_ = false;
  bool on_init_set_force_indet_ = false;

  bool last_value_auto_indet_en_ = false;
  bool on_init_set_auto_indet_en_ = false;

  bool last_value_en_12v_ = false;
  bool on_init_set_en_12v_ = false;

  bool last_value_en_9v_ = false;
  bool on_init_set_en_9v_ = false;

  bool last_value_hvdcp_en_ = false;
  bool on_init_set_hvdcp_en_ = false;

  int last_value_sdrv_ctrl_ = 0;
  bool on_init_set_sdrv_ctrl_ = false;

  int last_value_sdrv_dly_ = 0;
  bool on_init_set_sdrv_dly_ = false;

  bool last_value_dis_acdrv_ = false;
  bool on_init_set_dis_acdrv_ = false;

  bool last_value_en_otg_ = false;
  bool on_init_set_en_otg_ = false;

  bool last_value_pfm_otg_dis_ = false;
  bool on_init_set_pfm_otg_dis_ = false;

  bool last_value_pfm_fwd_dis_ = false;
  bool on_init_set_pfm_fwd_dis_ = false;

  int last_value_wkup_dly_ = 0;
  bool on_init_set_wkup_dly_ = false;

  bool last_value_dis_ldo_ = false;
  bool on_init_set_dis_ldo_ = false;

  bool last_value_dis_otg_ooa_ = false;
  bool on_init_set_dis_otg_ooa_ = false;

  bool last_value_dis_fwd_ooa_ = false;
  bool on_init_set_dis_fwd_ooa_ = false;

  bool last_value_en_acdrv2_ = false;
  bool on_init_set_en_acdrv2_ = false;

  bool last_value_en_acdrv1_ = false;
  bool on_init_set_en_acdrv1_ = false;

  int last_value_pwm_freq_ = 0;
  bool on_init_set_pwm_freq_ = false;

  bool last_value_dis_stat_ = false;
  bool on_init_set_dis_stat_ = false;

  bool last_value_dis_vsys_short_ = false;
  bool on_init_set_dis_vsys_short_ = false;

  bool last_value_dis_votg_uvp_ = false;
  bool on_init_set_dis_votg_uvp_ = false;

  bool last_value_force_vindpm_det_ = false;
  bool on_init_set_force_vindpm_det_ = false;

  bool last_value_en_ibus_ocp_ = false;
  bool on_init_set_en_ibus_ocp_ = false;

  bool last_value_sfet_present_ = false;
  bool on_init_set_sfet_present_ = false;

  bool last_value_en_ibat_ = false;
  bool on_init_set_en_ibat_ = false;

  int last_value_ibat_reg_ = 0;
  bool on_init_set_ibat_reg_ = false;

  bool last_value_en_iindpm_ = false;
  bool on_init_set_en_iindpm_ = false;

  bool last_value_en_extilim_ = false;
  bool on_init_set_en_extilim_ = false;

  bool last_value_en_batoc_ = false;
  bool on_init_set_en_batoc_ = false;

  int last_value_voc_pct_ = 0;
  bool on_init_set_voc_pct_ = false;

  int last_value_voc_dly_ = 0;
  bool on_init_set_voc_dly_ = false;

  int last_value_voc_rate_ = 0;
  bool on_init_set_voc_rate_ = false;

  bool last_value_en_mppt_ = false;
  bool on_init_set_en_mppt_ = false;

  int last_value_treg_ = 0;
  bool on_init_set_treg_ = false;

  int last_value_tshut_ = 0;
  bool on_init_set_tshut_ = false;

  bool last_value_vbus_pd_en_ = false;
  bool on_init_set_vbus_pd_en_ = false;

  bool last_value_vac1_pd_en_ = false;
  bool on_init_set_vac1_pd_en_ = false;

  bool last_value_vac2_pd_en_ = false;
  bool on_init_set_vac2_pd_en_ = false;

  int last_value_bkup_acfet1_on_ = 0;
  bool on_init_set_bkup_acfet1_on_ = false;

  int last_value_jeita_vset_ = 0;
  bool on_init_set_jeita_vset_ = false;

  int last_value_jeita_iseth_ = 0;
  bool on_init_set_jeita_iseth_ = false;

  int last_value_jeita_isetc_ = 0;
  bool on_init_set_jeita_isetc_ = false;

  int last_value_ts_cool_ = 0;
  bool on_init_set_ts_cool_ = false;

  int last_value_ts_warm_ = 0;
  bool on_init_set_ts_warm_ = false;

  int last_value_bhot_ = 0;
  bool on_init_set_bhot_ = false;

  int last_value_bcold_ = 0;
  bool on_init_set_bcold_ = false;

  bool last_value_ts_ignore_ = false;
  bool on_init_set_ts_ignore_ = false;

  int last_value_ico_ilim_ = 0;

  int last_value_iindpm_stat_ = 0;

  int last_value_vindpm_stat_ = 0;

  int last_value_wd_stat_ = 0;

  int last_value_pg_stat_ = 0;

  int last_value_ac2_present_stat_ = 0;

  int last_value_ac1_present_stat_ = 0;

  int last_value_vbus_present_stat_ = 0;

  int last_value_chg_stat_ = 0;

  int last_value_vbus_stat_ = 0;

  bool last_value_bc12_done_stat_ = false;

  int last_value_ico_stat_ = 0;

  int last_value_treg_stat_ = 0;

  int last_value_dpdm_stat_ = 0;

  int last_value_vbat_present_stat_ = 0;

  bool last_value_acrb2_stat_ = false;

  bool last_value_acrb1_stat_ = false;

  bool last_value_adc_done_stat_ = false;

  int last_value_vsys_stat_ = 0;

  int last_value_chg_tmr_stat_ = 0;

  int last_value_trichg_tmr_stat_ = 0;

  int last_value_prechg_tmr_stat_ = 0;

  int last_value_vbatotg_low_stat_ = 0;

  int last_value_ts_cold_stat_ = 0;

  int last_value_ts_cool_stat_ = 0;

  int last_value_ts_warm_stat_ = 0;

  int last_value_ts_hot_stat_ = 0;

  bool last_value_ibat_reg_stat_ = false;

  bool last_value_vbus_ovp_stat_ = false;

  bool last_value_vbat_ovp_stat_ = false;

  bool last_value_ibus_ocp_stat_ = false;

  bool last_value_ibat_ocp_stat_ = false;

  bool last_value_conv_ocp_stat_ = false;

  bool last_value_vac2_ovp_stat_ = false;

  bool last_value_vac1_ovp_stat_ = false;

  bool last_value_vsys_short_stat_ = false;

  bool last_value_vsys_ovp_stat_ = false;

  bool last_value_otg_ovp_stat_ = false;

  bool last_value_otg_uvp_stat_ = false;

  bool last_value_tshut_stat_ = false;

  bool last_value_iindpm_flag_ = false;

  bool last_value_vindpm_flag_ = false;

  bool last_value_wd_flag_ = false;

  bool last_value_poorsrc_flag_ = false;

  bool last_value_pg_flag_ = false;

  bool last_value_ac2_present_flag_ = false;

  bool last_value_ac1_present_flag_ = false;

  bool last_value_vbus_present_flag_ = false;

  bool last_value_chg_flag_ = false;

  bool last_value_ico_flag_ = false;

  bool last_value_vbus_flag_ = false;

  bool last_value_treg_flag_ = false;

  bool last_value_vbat_present_flag_ = false;

  bool last_value_bc1_2_done_flag_ = false;

  bool last_value_dpdm_done_flag_ = false;

  bool last_value_adc_done_flag_ = false;

  bool last_value_vsys_flag_ = false;

  bool last_value_chg_tmr_flag_ = false;

  bool last_value_trichg_tmr_flag_ = false;

  bool last_value_prechg_tmr_flag_ = false;

  bool last_value_topoff_tmr_flag_ = false;

  bool last_value_vbatotg_low_flag_ = false;

  bool last_value_ts_cold_flag_ = false;

  bool last_value_ts_cool_flag_ = false;

  bool last_value_ts_warm_flag_ = false;

  bool last_value_ts_hot_flag_ = false;

  bool last_value_ibat_reg_flag_ = false;

  bool last_value_vbus_ovp_flag_ = false;

  bool last_value_vbat_ovp_flag_ = false;

  bool last_value_ibus_ocp_flag_ = false;

  bool last_value_ibat_ocp_flag_ = false;

  bool last_value_conv_ocp_flag_ = false;

  bool last_value_vac2_ovp_flag_ = false;

  bool last_value_vac1_ovp_flag_ = false;

  bool last_value_vsys_short_flag_ = false;

  bool last_value_vsys_ovp_flag_ = false;

  bool last_value_otg_ovp_flag_ = false;

  bool last_value_otg_uvp_flag_ = false;

  bool last_value_tshut_flag_ = false;

  bool last_value_adc_en_ = false;
  bool on_init_set_adc_en_ = false;

  int last_value_adc_rate_ = 0;
  bool on_init_set_adc_rate_ = false;

  int last_value_adc_sample_ = 0;
  bool on_init_set_adc_sample_ = false;

  int last_value_adc_avg_ = 0;
  bool on_init_set_adc_avg_ = false;

  bool last_value_adc_avg_init_ = false;
  bool on_init_set_adc_avg_init_ = false;

  bool last_value_ibus_adc_dis_ = false;
  bool on_init_set_ibus_adc_dis_ = false;

  bool last_value_ibat_adc_dis_ = false;
  bool on_init_set_ibat_adc_dis_ = false;

  bool last_value_vbus_adc_dis_ = false;
  bool on_init_set_vbus_adc_dis_ = false;

  bool last_value_vbat_adc_dis_ = false;
  bool on_init_set_vbat_adc_dis_ = false;

  bool last_value_vsys_adc_dis_ = false;
  bool on_init_set_vsys_adc_dis_ = false;

  bool last_value_ts_adc_dis_ = false;
  bool on_init_set_ts_adc_dis_ = false;

  bool last_value_tdie_adc_dis_ = false;
  bool on_init_set_tdie_adc_dis_ = false;

  bool last_value_dplus_adc_dis_ = false;
  bool on_init_set_dplus_adc_dis_ = false;

  bool last_value_dminus_adc_dis_ = false;
  bool on_init_set_dminus_adc_dis_ = false;

  bool last_value_vac2_adc_dis_ = false;
  bool on_init_set_vac2_adc_dis_ = false;

  bool last_value_vac1_adc_dis_ = false;
  bool on_init_set_vac1_adc_dis_ = false;

  int last_value_ibus_adc_ = 0;

  int last_value_ibat_adc_ = 0;

  int last_value_vbus_adc_ = 0;

  int last_value_vac1_adc_ = 0;

  int last_value_vac2_adc_ = 0;

  int last_value_vbat_adc_ = 0;

  int last_value_vsys_adc_ = 0;

  float last_value_ts_adc_ = 0.0f;

  float last_value_tdie_adc_ = 0.0f;

  int last_value_dplus_adc_ = 0;

  int last_value_dminus_adc_ = 0;

  int last_value_dplus_dac_ = 0;
  bool on_init_set_dplus_dac_ = false;

  int last_value_dminus_dac_ = 0;
  bool on_init_set_dminus_dac_ = false;

  int last_value_pn_ = 0;

  int last_value_dev_rev_ = 0;

BQ25798NoI2C *bq25798_noi2c_ {nullptr};
};  // class BQ25798Component

}  // namespace bq25798
}  // namespace esphome