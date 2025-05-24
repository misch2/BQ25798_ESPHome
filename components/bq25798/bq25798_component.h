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
  uint16_t get_vsysmin_raw();
  void set_vsysmin_raw(uint16_t value);
  int get_vsysmin_int();
  void set_vsysmin_int(int value);

  // VREG - Charge Voltage Limit
  uint16_t get_vreg_raw();
  void set_vreg_raw(uint16_t value);
  int get_vreg_int();
  void set_vreg_int(int value);

  // ICHG - Charge Current Limit
  uint16_t get_ichg_raw();
  void set_ichg_raw(uint16_t value);
  int get_ichg_int();
  void set_ichg_int(int value);

  // VINDPM - Input Voltage Limit
  uint16_t get_vindpm_raw();
  void set_vindpm_raw(uint16_t value);
  int get_vindpm_int();
  void set_vindpm_int(int value);

  // IINDPM - Input Current Limit
  uint16_t get_iindpm_raw();
  void set_iindpm_raw(uint16_t value);
  int get_iindpm_int();
  void set_iindpm_int(int value);

  // VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
  uint16_t get_vbat_lowv_raw();
  void set_vbat_lowv_raw(uint16_t value);
  int get_vbat_lowv_enum_int();
  const char* get_vbat_lowv_enum_string();
  void set_vbat_lowv_enum_int(int value);

  // IPRECHG - Precharge Current Limit
  uint16_t get_iprechg_raw();
  void set_iprechg_raw(uint16_t value);
  int get_iprechg_int();
  void set_iprechg_int(int value);

  // REG_RST - Reset registers to default values and reset timer
  uint16_t get_reg_rst_raw();
  void set_reg_rst_raw(uint16_t value);
  bool get_reg_rst_bool();
  void set_reg_rst_bool(bool value);

  // STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
  uint16_t get_stop_wd_chg_raw();
  void set_stop_wd_chg_raw(uint16_t value);
  bool get_stop_wd_chg_bool();
  void set_stop_wd_chg_bool(bool value);

  // ITERM - Termination Current Limit
  uint16_t get_iterm_raw();
  void set_iterm_raw(uint16_t value);
  int get_iterm_int();
  void set_iterm_int(int value);

  // CELL - Battery cell count
  uint16_t get_cell_raw();
  void set_cell_raw(uint16_t value);
  int get_cell_enum_int();
  const char* get_cell_enum_string();
  void set_cell_enum_int(int value);

  // TRECHG - Battery recharge delay time
  uint16_t get_trechg_raw();
  void set_trechg_raw(uint16_t value);
  int get_trechg_enum_int();
  const char* get_trechg_enum_string();
  void set_trechg_enum_int(int value);

  // VRECHG - Battery Recharge Threshold Offset (Below VREG)
  uint16_t get_vrechg_raw();
  void set_vrechg_raw(uint16_t value);
  int get_vrechg_int();
  void set_vrechg_int(int value);

  // VOTG - OTG mode regulation voltage
  uint16_t get_votg_raw();
  void set_votg_raw(uint16_t value);
  int get_votg_int();
  void set_votg_int(int value);

  // PRECHG_TMR - Pre-charge safety timer setting
  uint16_t get_prechg_tmr_raw();
  void set_prechg_tmr_raw(uint16_t value);
  bool get_prechg_tmr_bool();
  void set_prechg_tmr_bool(bool value);
  int get_prechg_tmr_enum_int();
  const char* get_prechg_tmr_enum_string();
  void set_prechg_tmr_enum_int(int value);

  // IOTG - OTG current limit
  uint16_t get_iotg_raw();
  void set_iotg_raw(uint16_t value);
  int get_iotg_int();
  void set_iotg_int(int value);

  // TOPOFF_TMR - Top-off timer control
  uint16_t get_topoff_tmr_raw();
  void set_topoff_tmr_raw(uint16_t value);
  int get_topoff_tmr_enum_int();
  const char* get_topoff_tmr_enum_string();
  void set_topoff_tmr_enum_int(int value);

  // EN_TRICHG_TMR - Trickle charge timer enable
  uint16_t get_en_trichg_tmr_raw();
  void set_en_trichg_tmr_raw(uint16_t value);
  bool get_en_trichg_tmr_bool();
  void set_en_trichg_tmr_bool(bool value);

  // EN_PRECHG_TMR - Precharge timer enable
  uint16_t get_en_prechg_tmr_raw();
  void set_en_prechg_tmr_raw(uint16_t value);
  bool get_en_prechg_tmr_bool();
  void set_en_prechg_tmr_bool(bool value);

  // EN_CHG_TMR - Fast charge timer enable
  uint16_t get_en_chg_tmr_raw();
  void set_en_chg_tmr_raw(uint16_t value);
  bool get_en_chg_tmr_bool();
  void set_en_chg_tmr_bool(bool value);

  // CHG_TMR - Fast charge timer setting
  uint16_t get_chg_tmr_raw();
  void set_chg_tmr_raw(uint16_t value);
  int get_chg_tmr_enum_int();
  const char* get_chg_tmr_enum_string();
  void set_chg_tmr_enum_int(int value);

  // TMR2X_EN - 2x slower charging in DPM enable
  uint16_t get_tmr2x_en_raw();
  void set_tmr2x_en_raw(uint16_t value);
  bool get_tmr2x_en_bool();
  void set_tmr2x_en_bool(bool value);

  // EN_AUTO_IBATDIS - Enable the auto battery discharging during the battery OVP fault
  uint16_t get_en_auto_ibatdis_raw();
  void set_en_auto_ibatdis_raw(uint16_t value);
  bool get_en_auto_ibatdis_bool();
  void set_en_auto_ibatdis_bool(bool value);

  // FORCE_IBATDIS - Force the battery discharging current
  uint16_t get_force_ibatdis_raw();
  void set_force_ibatdis_raw(uint16_t value);
  bool get_force_ibatdis_bool();
  void set_force_ibatdis_bool(bool value);

  // EN_CHG - Enable the charger
  uint16_t get_en_chg_raw();
  void set_en_chg_raw(uint16_t value);
  bool get_en_chg_bool();
  void set_en_chg_bool(bool value);

  // EN_ICO - Enable the ICO (Input Current Optimizer)
  uint16_t get_en_ico_raw();
  void set_en_ico_raw(uint16_t value);
  bool get_en_ico_bool();
  void set_en_ico_bool(bool value);

  // FORCE_ICO - Force the ICO (Input Current Optimizer)
  uint16_t get_force_ico_raw();
  void set_force_ico_raw(uint16_t value);
  bool get_force_ico_bool();
  void set_force_ico_bool(bool value);

  // EN_HIZ - Enable the high impedance mode
  uint16_t get_en_hiz_raw();
  void set_en_hiz_raw(uint16_t value);
  bool get_en_hiz_bool();
  void set_en_hiz_bool(bool value);

  // EN_TERM - Enable the termination
  uint16_t get_en_term_raw();
  void set_en_term_raw(uint16_t value);
  bool get_en_term_bool();
  void set_en_term_bool(bool value);

  // EN_BACKUP - Enable the backup (auto OTG) mode
  uint16_t get_en_backup_raw();
  void set_en_backup_raw(uint16_t value);
  bool get_en_backup_bool();
  void set_en_backup_bool(bool value);

  // VBUS_BACKUP - The thresholds to trigger the backup mode, defined as a ratio of VINDPM
  uint16_t get_vbus_backup_raw();
  void set_vbus_backup_raw(uint16_t value);
  int get_vbus_backup_enum_int();
  const char* get_vbus_backup_enum_string();
  void set_vbus_backup_enum_int(int value);

  // VAC_OVP - Over voltage protection thresholds
  uint16_t get_vac_ovp_raw();
  void set_vac_ovp_raw(uint16_t value);
  int get_vac_ovp_enum_int();
  const char* get_vac_ovp_enum_string();
  void set_vac_ovp_enum_int(int value);

  // WD_RST - I2C watch dog timer reset
  uint16_t get_wd_rst_raw();
  void set_wd_rst_raw(uint16_t value);
  bool get_wd_rst_bool();
  void set_wd_rst_bool(bool value);

  // WATCHDOG - Watchdog timer settings
  uint16_t get_watchdog_raw();
  void set_watchdog_raw(uint16_t value);
  int get_watchdog_enum_int();
  const char* get_watchdog_enum_string();
  void set_watchdog_enum_int(int value);

  // FORCE_INDET - Force D+/D- detection
  uint16_t get_force_indet_raw();
  void set_force_indet_raw(uint16_t value);
  bool get_force_indet_bool();
  void set_force_indet_bool(bool value);

  // AUTO_INDET_EN - Enable automatic D+/D- detection
  uint16_t get_auto_indet_en_raw();
  void set_auto_indet_en_raw(uint16_t value);
  bool get_auto_indet_en_bool();
  void set_auto_indet_en_bool(bool value);

  // EN_12V - Enable 12V output in HVDCP
  uint16_t get_en_12v_raw();
  void set_en_12v_raw(uint16_t value);
  bool get_en_12v_bool();
  void set_en_12v_bool(bool value);

  // EN_9V - Enable 9V output in HVDCP
  uint16_t get_en_9v_raw();
  void set_en_9v_raw(uint16_t value);
  bool get_en_9v_bool();
  void set_en_9v_bool(bool value);

  // HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
  uint16_t get_hvdcp_en_raw();
  void set_hvdcp_en_raw(uint16_t value);
  bool get_hvdcp_en_bool();
  void set_hvdcp_en_bool(bool value);

  // SDRV_CTRL - Enable external Ship FET control
  uint16_t get_sdrv_ctrl_raw();
  void set_sdrv_ctrl_raw(uint16_t value);
  int get_sdrv_ctrl_enum_int();
  const char* get_sdrv_ctrl_enum_string();
  void set_sdrv_ctrl_enum_int(int value);

  // SDRV_DLY - Delay for SDRV control
  uint16_t get_sdrv_dly_raw();
  void set_sdrv_dly_raw(uint16_t value);
  bool get_sdrv_dly_bool();
  void set_sdrv_dly_bool(bool value);
  int get_sdrv_dly_enum_int();
  const char* get_sdrv_dly_enum_string();
  void set_sdrv_dly_enum_int(int value);

  // DIS_ACDRV - Disable both AC1 and AC2 drivers
  uint16_t get_dis_acdrv_raw();
  void set_dis_acdrv_raw(uint16_t value);
  bool get_dis_acdrv_bool();
  void set_dis_acdrv_bool(bool value);

  // EN_OTG - Enable OTG mode
  uint16_t get_en_otg_raw();
  void set_en_otg_raw(uint16_t value);
  bool get_en_otg_bool();
  void set_en_otg_bool(bool value);

  // PFM_OTG_DIS - Disable PFM in OTG mode
  uint16_t get_pfm_otg_dis_raw();
  void set_pfm_otg_dis_raw(uint16_t value);
  bool get_pfm_otg_dis_bool();
  void set_pfm_otg_dis_bool(bool value);

  // PFM_FWD_DIS - Disable PFM in forward mode
  uint16_t get_pfm_fwd_dis_raw();
  void set_pfm_fwd_dis_raw(uint16_t value);
  bool get_pfm_fwd_dis_bool();
  void set_pfm_fwd_dis_bool(bool value);

  // WKUP_DLY - Wakeup (Ship FET) delay
  uint16_t get_wkup_dly_raw();
  void set_wkup_dly_raw(uint16_t value);
  bool get_wkup_dly_bool();
  void set_wkup_dly_bool(bool value);
  int get_wkup_dly_enum_int();
  const char* get_wkup_dly_enum_string();
  void set_wkup_dly_enum_int(int value);

  // DIS_LDO - Disable BATFET LDO mode in precharge state
  uint16_t get_dis_ldo_raw();
  void set_dis_ldo_raw(uint16_t value);
  bool get_dis_ldo_bool();
  void set_dis_ldo_bool(bool value);

  // DIS_OTG_OOA - Disable OOA in OTG mode
  uint16_t get_dis_otg_ooa_raw();
  void set_dis_otg_ooa_raw(uint16_t value);
  bool get_dis_otg_ooa_bool();
  void set_dis_otg_ooa_bool(bool value);

  // DIS_FWD_OOA - Disable OOA in forward mode
  uint16_t get_dis_fwd_ooa_raw();
  void set_dis_fwd_ooa_raw(uint16_t value);
  bool get_dis_fwd_ooa_bool();
  void set_dis_fwd_ooa_bool(bool value);

  // EN_ACDRV2 - Enable AC2 gate driver control
  uint16_t get_en_acdrv2_raw();
  void set_en_acdrv2_raw(uint16_t value);
  bool get_en_acdrv2_bool();
  void set_en_acdrv2_bool(bool value);

  // EN_ACDRV1 - Enable AC1 gate driver control
  uint16_t get_en_acdrv1_raw();
  void set_en_acdrv1_raw(uint16_t value);
  bool get_en_acdrv1_bool();
  void set_en_acdrv1_bool(bool value);

  // PWM_FREQ - PWM frequency setting
  uint16_t get_pwm_freq_raw();
  void set_pwm_freq_raw(uint16_t value);
  bool get_pwm_freq_bool();
  void set_pwm_freq_bool(bool value);
  int get_pwm_freq_enum_int();
  const char* get_pwm_freq_enum_string();
  void set_pwm_freq_enum_int(int value);

  // DIS_STAT - Disable STAT pin output
  uint16_t get_dis_stat_raw();
  void set_dis_stat_raw(uint16_t value);
  bool get_dis_stat_bool();
  void set_dis_stat_bool(bool value);

  // DIS_VSYS_SHORT - Disable VSYS short hiccup protection
  uint16_t get_dis_vsys_short_raw();
  void set_dis_vsys_short_raw(uint16_t value);
  bool get_dis_vsys_short_bool();
  void set_dis_vsys_short_bool(bool value);

  // DIS_VOTG_UVP - Disable VOTG under voltage hiccup protection
  uint16_t get_dis_votg_uvp_raw();
  void set_dis_votg_uvp_raw(uint16_t value);
  bool get_dis_votg_uvp_bool();
  void set_dis_votg_uvp_bool(bool value);

  // FORCE_VINDPM_DET - Force VINDPM detection (settable only when VBAT>VSYSMIN)
  uint16_t get_force_vindpm_det_raw();
  void set_force_vindpm_det_raw(uint16_t value);
  bool get_force_vindpm_det_bool();
  void set_force_vindpm_det_bool(bool value);

  // EN_IBUS_OCP - Enable input over current protection in forward mode
  uint16_t get_en_ibus_ocp_raw();
  void set_en_ibus_ocp_raw(uint16_t value);
  bool get_en_ibus_ocp_bool();
  void set_en_ibus_ocp_bool(bool value);

  // SFET_PRESENT - Ship FET present
  uint16_t get_sfet_present_raw();
  void set_sfet_present_raw(uint16_t value);
  bool get_sfet_present_bool();
  void set_sfet_present_bool(bool value);

  // EN_IBAT - Enable battery discharge current sensing
  uint16_t get_en_ibat_raw();
  void set_en_ibat_raw(uint16_t value);
  bool get_en_ibat_bool();
  void set_en_ibat_bool(bool value);

  // IBAT_REG - Battery discharge current regulation in OTG mode
  uint16_t get_ibat_reg_raw();
  void set_ibat_reg_raw(uint16_t value);
  int get_ibat_reg_enum_int();
  const char* get_ibat_reg_enum_string();
  void set_ibat_reg_enum_int(int value);

  // EN_IINDPM - Enable input current regulation
  uint16_t get_en_iindpm_raw();
  void set_en_iindpm_raw(uint16_t value);
  bool get_en_iindpm_bool();
  void set_en_iindpm_bool(bool value);

  // EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
  uint16_t get_en_extilim_raw();
  void set_en_extilim_raw(uint16_t value);
  bool get_en_extilim_bool();
  void set_en_extilim_bool(bool value);

  // EN_BATOC - Enable battery discharging over current protection
  uint16_t get_en_batoc_raw();
  void set_en_batoc_raw(uint16_t value);
  bool get_en_batoc_bool();
  void set_en_batoc_bool(bool value);

  // VOC_PCT - Set VINDPM as a percentage of the VBUS open circuit voltage when the VOC measurement is done
  uint16_t get_voc_pct_raw();
  void set_voc_pct_raw(uint16_t value);
  int get_voc_pct_enum_int();
  const char* get_voc_pct_enum_string();
  void set_voc_pct_enum_int(int value);

  // VOC_DLY - After the converter stops switching, the time delay before the VOC is measured
  uint16_t get_voc_dly_raw();
  void set_voc_dly_raw(uint16_t value);
  int get_voc_dly_enum_int();
  const char* get_voc_dly_enum_string();
  void set_voc_dly_enum_int(int value);

  // VOC_RATE - The time interval between two consecutive VOC measurements
  uint16_t get_voc_rate_raw();
  void set_voc_rate_raw(uint16_t value);
  int get_voc_rate_enum_int();
  const char* get_voc_rate_enum_string();
  void set_voc_rate_enum_int(int value);

  // EN_MPPT - Enable MPPT (Maximum Power Point Tracking)
  uint16_t get_en_mppt_raw();
  void set_en_mppt_raw(uint16_t value);
  bool get_en_mppt_bool();
  void set_en_mppt_bool(bool value);

  // TREG - Thermal regulation thresholds
  uint16_t get_treg_raw();
  void set_treg_raw(uint16_t value);
  int get_treg_enum_int();
  const char* get_treg_enum_string();
  void set_treg_enum_int(int value);

  // TSHUT - Thermal shutdown thresholds
  uint16_t get_tshut_raw();
  void set_tshut_raw(uint16_t value);
  int get_tshut_enum_int();
  const char* get_tshut_enum_string();
  void set_tshut_enum_int(int value);

  // VBUS_PD_EN - Enable VBUS pull down resistor (6 kOhm)
  uint16_t get_vbus_pd_en_raw();
  void set_vbus_pd_en_raw(uint16_t value);
  bool get_vbus_pd_en_bool();
  void set_vbus_pd_en_bool(bool value);

  // VAC1_PD_EN - Enable VAC1 pull down resistor
  uint16_t get_vac1_pd_en_raw();
  void set_vac1_pd_en_raw(uint16_t value);
  bool get_vac1_pd_en_bool();
  void set_vac1_pd_en_bool(bool value);

  // VAC2_PD_EN - Enable VAC2 pull down resistor
  uint16_t get_vac2_pd_en_raw();
  void set_vac2_pd_en_raw(uint16_t value);
  bool get_vac2_pd_en_bool();
  void set_vac2_pd_en_bool(bool value);

  // BKUP_ACFET1_ON - Enable ACFET1 in backup mode (exit backup mode)
  uint16_t get_bkup_acfet1_on_raw();
  void set_bkup_acfet1_on_raw(uint16_t value);
  bool get_bkup_acfet1_on_bool();
  void set_bkup_acfet1_on_bool(bool value);

  // JEITA_VSET - JEITA high temperature range (TWARN - THOT) charge voltage setting
  uint16_t get_jeita_vset_raw();
  void set_jeita_vset_raw(uint16_t value);
  int get_jeita_vset_enum_int();
  const char* get_jeita_vset_enum_string();
  void set_jeita_vset_enum_int(int value);

  // JEITA_ISETH - JEITA high temperature range (TWARN - THOT) charge current setting
  uint16_t get_jeita_iseth_raw();
  void set_jeita_iseth_raw(uint16_t value);
  int get_jeita_iseth_enum_int();
  const char* get_jeita_iseth_enum_string();
  void set_jeita_iseth_enum_int(int value);

  // JEITA_ISETC - JEITA low temperature range (TCOLD - TWARN) charge current setting
  uint16_t get_jeita_isetc_raw();
  void set_jeita_isetc_raw(uint16_t value);
  int get_jeita_isetc_enum_int();
  const char* get_jeita_isetc_enum_string();
  void set_jeita_isetc_enum_int(int value);

  // TS_COOL - JEITA VT2 comparator voltage rising thresholds as a percentage of REGN.
  uint16_t get_ts_cool_raw();
  void set_ts_cool_raw(uint16_t value);
  int get_ts_cool_enum_int();
  const char* get_ts_cool_enum_string();
  void set_ts_cool_enum_int(int value);

  // TS_WARM - JEITA VT3 comparator voltage falling thresholds as a percentage of REGN.
  uint16_t get_ts_warm_raw();
  void set_ts_warm_raw(uint16_t value);
  int get_ts_warm_enum_int();
  const char* get_ts_warm_enum_string();
  void set_ts_warm_enum_int(int value);

  // BHOT - OTG mode TS HOT temperature threshold
  uint16_t get_bhot_raw();
  void set_bhot_raw(uint16_t value);
  int get_bhot_enum_int();
  const char* get_bhot_enum_string();
  void set_bhot_enum_int(int value);

  // BCOLD - OTG mode TS COLD temperature threshold
  uint16_t get_bcold_raw();
  void set_bcold_raw(uint16_t value);
  bool get_bcold_bool();
  void set_bcold_bool(bool value);
  int get_bcold_enum_int();
  const char* get_bcold_enum_string();
  void set_bcold_enum_int(int value);

  // TS_IGNORE - Ignore TS detection (the charger considers the TS is always good)
  uint16_t get_ts_ignore_raw();
  void set_ts_ignore_raw(uint16_t value);
  bool get_ts_ignore_bool();
  void set_ts_ignore_bool(bool value);

  // ICO_ILIM - Input Current Limit obtained from ICO or ILIM_HIZ pin setting
  uint16_t get_ico_ilim_raw();
  int get_ico_ilim_int();

  // IINDPM_STAT - IINDPM status (forward mode) or IOTG status (OTG mode)
  uint16_t get_iindpm_stat_raw();
  bool get_iindpm_stat_bool();
  int get_iindpm_stat_enum_int();
  const char* get_iindpm_stat_enum_string();

  // VINDPM_STAT - VINDPM status (forward mode) or VOTG status (OTG mode)
  uint16_t get_vindpm_stat_raw();
  bool get_vindpm_stat_bool();
  int get_vindpm_stat_enum_int();
  const char* get_vindpm_stat_enum_string();

  // WD_STAT - Watchdog timer status
  uint16_t get_wd_stat_raw();
  bool get_wd_stat_bool();
  int get_wd_stat_enum_int();
  const char* get_wd_stat_enum_string();

  // PG_STAT - Power good status
  uint16_t get_pg_stat_raw();
  bool get_pg_stat_bool();
  int get_pg_stat_enum_int();
  const char* get_pg_stat_enum_string();

  // AC2_PRESENT_STAT - VAC2 present status
  uint16_t get_ac2_present_stat_raw();
  bool get_ac2_present_stat_bool();
  int get_ac2_present_stat_enum_int();
  const char* get_ac2_present_stat_enum_string();

  // AC1_PRESENT_STAT - VAC1 present status
  uint16_t get_ac1_present_stat_raw();
  bool get_ac1_present_stat_bool();
  int get_ac1_present_stat_enum_int();
  const char* get_ac1_present_stat_enum_string();

  // VBUS_PRESENT_STAT - VBUS present status
  uint16_t get_vbus_present_stat_raw();
  bool get_vbus_present_stat_bool();
  int get_vbus_present_stat_enum_int();
  const char* get_vbus_present_stat_enum_string();

  // CHG_STAT - Charge Status bits
  uint16_t get_chg_stat_raw();
  int get_chg_stat_enum_int();
  const char* get_chg_stat_enum_string();

  // VBUS_STAT - VBUS status bits
  uint16_t get_vbus_stat_raw();
  int get_vbus_stat_enum_int();
  const char* get_vbus_stat_enum_string();

  // BC12_DONE_STAT - BC1.2 detection done status
  uint16_t get_bc12_done_stat_raw();
  bool get_bc12_done_stat_bool();

  // ICO_STAT - Input Current Optimizer (ICO) status
  uint16_t get_ico_stat_raw();
  int get_ico_stat_enum_int();
  const char* get_ico_stat_enum_string();

  // TREG_STAT - IC thermal regulation status
  uint16_t get_treg_stat_raw();
  bool get_treg_stat_bool();
  int get_treg_stat_enum_int();
  const char* get_treg_stat_enum_string();

  // DPDM_STAT - D+/D- detection status
  uint16_t get_dpdm_stat_raw();
  bool get_dpdm_stat_bool();
  int get_dpdm_stat_enum_int();
  const char* get_dpdm_stat_enum_string();

  // VBAT_PRESENT_STAT - Battery present status
  uint16_t get_vbat_present_stat_raw();
  bool get_vbat_present_stat_bool();
  int get_vbat_present_stat_enum_int();
  const char* get_vbat_present_stat_enum_string();

  // ACRB2_STAT - The ACFET2-RBFET2 status
  uint16_t get_acrb2_stat_raw();
  bool get_acrb2_stat_bool();
  int get_acrb2_stat_enum_int();
  const char* get_acrb2_stat_enum_string();

  // ACRB1_STAT - The ACFET1-RBFET1 status
  uint16_t get_acrb1_stat_raw();
  bool get_acrb1_stat_bool();
  int get_acrb1_stat_enum_int();
  const char* get_acrb1_stat_enum_string();

  // ADC_DONE_STAT - ADC Conversion Status
  uint16_t get_adc_done_stat_raw();
  bool get_adc_done_stat_bool();

  // VSYS_STAT - VSYS Regulation Status
  uint16_t get_vsys_stat_raw();
  bool get_vsys_stat_bool();
  int get_vsys_stat_enum_int();
  const char* get_vsys_stat_enum_string();

  // CHG_TMR_STAT - Fast charge timer status
  uint16_t get_chg_tmr_stat_raw();
  bool get_chg_tmr_stat_bool();
  int get_chg_tmr_stat_enum_int();
  const char* get_chg_tmr_stat_enum_string();

  // TRICHG_TMR_STAT - Trickle charge timer status
  uint16_t get_trichg_tmr_stat_raw();
  bool get_trichg_tmr_stat_bool();
  int get_trichg_tmr_stat_enum_int();
  const char* get_trichg_tmr_stat_enum_string();

  // PRECHG_TMR_STAT - Pre-charge timer status
  uint16_t get_prechg_tmr_stat_raw();
  bool get_prechg_tmr_stat_bool();
  int get_prechg_tmr_stat_enum_int();
  const char* get_prechg_tmr_stat_enum_string();

  // VBATOTG_LOW_STAT - The battery voltage is too low to enable OTG mode
  uint16_t get_vbatotg_low_stat_raw();
  bool get_vbatotg_low_stat_bool();
  int get_vbatotg_low_stat_enum_int();
  const char* get_vbatotg_low_stat_enum_string();

  // TS_COLD_STAT - The TS temperature is in the cold range
  uint16_t get_ts_cold_stat_raw();
  bool get_ts_cold_stat_bool();
  int get_ts_cold_stat_enum_int();
  const char* get_ts_cold_stat_enum_string();

  // TS_COOL_STAT - The TS temperature is in the cool range
  uint16_t get_ts_cool_stat_raw();
  bool get_ts_cool_stat_bool();
  int get_ts_cool_stat_enum_int();
  const char* get_ts_cool_stat_enum_string();

  // TS_WARM_STAT - The TS temperature is in the warm range
  uint16_t get_ts_warm_stat_raw();
  bool get_ts_warm_stat_bool();
  int get_ts_warm_stat_enum_int();
  const char* get_ts_warm_stat_enum_string();

  // TS_HOT_STAT - The TS temperature is in the hot range
  uint16_t get_ts_hot_stat_raw();
  bool get_ts_hot_stat_bool();
  int get_ts_hot_stat_enum_int();
  const char* get_ts_hot_stat_enum_string();

  // IBAT_REG_STAT - In battery discharging current regulation
  uint16_t get_ibat_reg_stat_raw();
  bool get_ibat_reg_stat_bool();

  // VBUS_OVP_STAT - VBUS over-voltage status
  uint16_t get_vbus_ovp_stat_raw();
  bool get_vbus_ovp_stat_bool();

  // VBAT_OVP_STAT - VBAT over-voltage status
  uint16_t get_vbat_ovp_stat_raw();
  bool get_vbat_ovp_stat_bool();

  // IBUS_OCP_STAT - IBUS over-current status
  uint16_t get_ibus_ocp_stat_raw();
  bool get_ibus_ocp_stat_bool();

  // IBAT_OCP_STAT - IBAT over-current status
  uint16_t get_ibat_ocp_stat_raw();
  bool get_ibat_ocp_stat_bool();

  // CONV_OCP_STAT - Converter over-current status
  uint16_t get_conv_ocp_stat_raw();
  bool get_conv_ocp_stat_bool();

  // VAC2_OVP_STAT - VAC2 over-voltage status
  uint16_t get_vac2_ovp_stat_raw();
  bool get_vac2_ovp_stat_bool();

  // VAC1_OVP_STAT - VAC1 over-voltage status
  uint16_t get_vac1_ovp_stat_raw();
  bool get_vac1_ovp_stat_bool();

  // VSYS_SHORT_STAT - VSYS short circuit status
  uint16_t get_vsys_short_stat_raw();
  bool get_vsys_short_stat_bool();

  // VSYS_OVP_STAT - VSYS over-voltage status
  uint16_t get_vsys_ovp_stat_raw();
  bool get_vsys_ovp_stat_bool();

  // OTG_OVP_STAT - OTG over-voltage status
  uint16_t get_otg_ovp_stat_raw();
  bool get_otg_ovp_stat_bool();

  // OTG_UVP_STAT - OTG under-voltage status
  uint16_t get_otg_uvp_stat_raw();
  bool get_otg_uvp_stat_bool();

  // TSHUT_STAT - IC thermal shutdown status
  uint16_t get_tshut_stat_raw();
  bool get_tshut_stat_bool();

  // IINDPM_FLAG - IINDPM / IOTG flag
  uint16_t get_iindpm_flag_raw();
  bool get_iindpm_flag_flag();
  void clear_flag_iindpm_flag() { this->last_iindpm_flag_ = false; }
  void raise_flag_iindpm_flag() { this->last_iindpm_flag_ = true; }

  // VINDPM_FLAG - VINDPM / VOTG Flag
  uint16_t get_vindpm_flag_raw();
  bool get_vindpm_flag_flag();
  void clear_flag_vindpm_flag() { this->last_vindpm_flag_ = false; }
  void raise_flag_vindpm_flag() { this->last_vindpm_flag_ = true; }

  // WD_FLAG - I2C watchdog timer flag
  uint16_t get_wd_flag_raw();
  bool get_wd_flag_flag();
  void clear_flag_wd_flag() { this->last_wd_flag_ = false; }
  void raise_flag_wd_flag() { this->last_wd_flag_ = true; }

  // POORSRC_FLAG - Poor source detection flag
  uint16_t get_poorsrc_flag_raw();
  bool get_poorsrc_flag_flag();
  void clear_flag_poorsrc_flag() { this->last_poorsrc_flag_ = false; }
  void raise_flag_poorsrc_flag() { this->last_poorsrc_flag_ = true; }

  // PG_FLAG - Poor source detection flag
  uint16_t get_pg_flag_raw();
  bool get_pg_flag_flag();
  void clear_flag_pg_flag() { this->last_pg_flag_ = false; }
  void raise_flag_pg_flag() { this->last_pg_flag_ = true; }

  // AC2_PRESENT_FLAG - VAC2 present flag
  uint16_t get_ac2_present_flag_raw();
  bool get_ac2_present_flag_flag();
  void clear_flag_ac2_present_flag() { this->last_ac2_present_flag_ = false; }
  void raise_flag_ac2_present_flag() { this->last_ac2_present_flag_ = true; }

  // AC1_PRESENT_FLAG - VAC1 present flag
  uint16_t get_ac1_present_flag_raw();
  bool get_ac1_present_flag_flag();
  void clear_flag_ac1_present_flag() { this->last_ac1_present_flag_ = false; }
  void raise_flag_ac1_present_flag() { this->last_ac1_present_flag_ = true; }

  // VBUS_PRESENT_FLAG - VBUS present flag
  uint16_t get_vbus_present_flag_raw();
  bool get_vbus_present_flag_flag();
  void clear_flag_vbus_present_flag() { this->last_vbus_present_flag_ = false; }
  void raise_flag_vbus_present_flag() { this->last_vbus_present_flag_ = true; }

  // CHG_FLAG - Charge status flag
  uint16_t get_chg_flag_raw();
  bool get_chg_flag_flag();
  void clear_flag_chg_flag() { this->last_chg_flag_ = false; }
  void raise_flag_chg_flag() { this->last_chg_flag_ = true; }

  // ICO_FLAG - ICO status flag
  uint16_t get_ico_flag_raw();
  bool get_ico_flag_flag();
  void clear_flag_ico_flag() { this->last_ico_flag_ = false; }
  void raise_flag_ico_flag() { this->last_ico_flag_ = true; }

  // VBUS_FLAG - VBUS status flag
  uint16_t get_vbus_flag_raw();
  bool get_vbus_flag_flag();
  void clear_flag_vbus_flag() { this->last_vbus_flag_ = false; }
  void raise_flag_vbus_flag() { this->last_vbus_flag_ = true; }

  // TREG_FLAG - IC thermal regulation flag
  uint16_t get_treg_flag_raw();
  bool get_treg_flag_flag();
  void clear_flag_treg_flag() { this->last_treg_flag_ = false; }
  void raise_flag_treg_flag() { this->last_treg_flag_ = true; }

  // VBAT_PRESENT_FLAG - VBAT present flag
  uint16_t get_vbat_present_flag_raw();
  bool get_vbat_present_flag_flag();
  void clear_flag_vbat_present_flag() { this->last_vbat_present_flag_ = false; }
  void raise_flag_vbat_present_flag() { this->last_vbat_present_flag_ = true; }

  // BC1_2_DONE_FLAG - BC1.2 status Flag
  uint16_t get_bc1_2_done_flag_raw();
  bool get_bc1_2_done_flag_flag();
  void clear_flag_bc1_2_done_flag() { this->last_bc1_2_done_flag_ = false; }
  void raise_flag_bc1_2_done_flag() { this->last_bc1_2_done_flag_ = true; }

  // DPDM_DONE_FLAG - D+/D- detection is done flag.
  uint16_t get_dpdm_done_flag_raw();
  bool get_dpdm_done_flag_flag();
  void clear_flag_dpdm_done_flag() { this->last_dpdm_done_flag_ = false; }
  void raise_flag_dpdm_done_flag() { this->last_dpdm_done_flag_ = true; }

  // ADC_DONE_FLAG - ADC conversion flag (only in one-shot mode)
  uint16_t get_adc_done_flag_raw();
  bool get_adc_done_flag_flag();
  void clear_flag_adc_done_flag() { this->last_adc_done_flag_ = false; }
  void raise_flag_adc_done_flag() { this->last_adc_done_flag_ = true; }

  // VSYS_FLAG - VSYSMIN regulation flag
  uint16_t get_vsys_flag_raw();
  bool get_vsys_flag_flag();
  void clear_flag_vsys_flag() { this->last_vsys_flag_ = false; }
  void raise_flag_vsys_flag() { this->last_vsys_flag_ = true; }

  // CHG_TMR_FLAG - Fast charge timer flag
  uint16_t get_chg_tmr_flag_raw();
  bool get_chg_tmr_flag_flag();
  void clear_flag_chg_tmr_flag() { this->last_chg_tmr_flag_ = false; }
  void raise_flag_chg_tmr_flag() { this->last_chg_tmr_flag_ = true; }

  // TRICHG_TMR_FLAG - Trickle charge timer flag
  uint16_t get_trichg_tmr_flag_raw();
  bool get_trichg_tmr_flag_flag();
  void clear_flag_trichg_tmr_flag() { this->last_trichg_tmr_flag_ = false; }
  void raise_flag_trichg_tmr_flag() { this->last_trichg_tmr_flag_ = true; }

  // PRECHG_TMR_FLAG - Pre-charge timer flag
  uint16_t get_prechg_tmr_flag_raw();
  bool get_prechg_tmr_flag_flag();
  void clear_flag_prechg_tmr_flag() { this->last_prechg_tmr_flag_ = false; }
  void raise_flag_prechg_tmr_flag() { this->last_prechg_tmr_flag_ = true; }

  // TOPOFF_TMR_FLAG - Top off timer flag
  uint16_t get_topoff_tmr_flag_raw();
  bool get_topoff_tmr_flag_flag();
  void clear_flag_topoff_tmr_flag() { this->last_topoff_tmr_flag_ = false; }
  void raise_flag_topoff_tmr_flag() { this->last_topoff_tmr_flag_ = true; }

  // VBATOTG_LOW_FLAG - VBAT too low to enable OTG flag
  uint16_t get_vbatotg_low_flag_raw();
  bool get_vbatotg_low_flag_flag();
  void clear_flag_vbatotg_low_flag() { this->last_vbatotg_low_flag_ = false; }
  void raise_flag_vbatotg_low_flag() { this->last_vbatotg_low_flag_ = true; }

  // TS_COLD_FLAG - TS cold temperature flag
  uint16_t get_ts_cold_flag_raw();
  bool get_ts_cold_flag_flag();
  void clear_flag_ts_cold_flag() { this->last_ts_cold_flag_ = false; }
  void raise_flag_ts_cold_flag() { this->last_ts_cold_flag_ = true; }

  // TS_COOL_FLAG - TS cool temperature flag
  uint16_t get_ts_cool_flag_raw();
  bool get_ts_cool_flag_flag();
  void clear_flag_ts_cool_flag() { this->last_ts_cool_flag_ = false; }
  void raise_flag_ts_cool_flag() { this->last_ts_cool_flag_ = true; }

  // TS_WARM_FLAG - TS warm temperature flag
  uint16_t get_ts_warm_flag_raw();
  bool get_ts_warm_flag_flag();
  void clear_flag_ts_warm_flag() { this->last_ts_warm_flag_ = false; }
  void raise_flag_ts_warm_flag() { this->last_ts_warm_flag_ = true; }

  // TS_HOT_FLAG - TS hot temperature flag
  uint16_t get_ts_hot_flag_raw();
  bool get_ts_hot_flag_flag();
  void clear_flag_ts_hot_flag() { this->last_ts_hot_flag_ = false; }
  void raise_flag_ts_hot_flag() { this->last_ts_hot_flag_ = true; }

  // IBAT_REG_FLAG - IBAT regulation flag
  uint16_t get_ibat_reg_flag_raw();
  bool get_ibat_reg_flag_flag();
  void clear_flag_ibat_reg_flag() { this->last_ibat_reg_flag_ = false; }
  void raise_flag_ibat_reg_flag() { this->last_ibat_reg_flag_ = true; }

  // VBUS_OVP_FLAG - VBUS over-voltage flag
  uint16_t get_vbus_ovp_flag_raw();
  bool get_vbus_ovp_flag_flag();
  void clear_flag_vbus_ovp_flag() { this->last_vbus_ovp_flag_ = false; }
  void raise_flag_vbus_ovp_flag() { this->last_vbus_ovp_flag_ = true; }

  // VBAT_OVP_FLAG - VBAT over-voltage flag
  uint16_t get_vbat_ovp_flag_raw();
  bool get_vbat_ovp_flag_flag();
  void clear_flag_vbat_ovp_flag() { this->last_vbat_ovp_flag_ = false; }
  void raise_flag_vbat_ovp_flag() { this->last_vbat_ovp_flag_ = true; }

  // IBUS_OCP_FLAG - IBUS over-current flag
  uint16_t get_ibus_ocp_flag_raw();
  bool get_ibus_ocp_flag_flag();
  void clear_flag_ibus_ocp_flag() { this->last_ibus_ocp_flag_ = false; }
  void raise_flag_ibus_ocp_flag() { this->last_ibus_ocp_flag_ = true; }

  // IBAT_OCP_FLAG - IBAT over-current flag
  uint16_t get_ibat_ocp_flag_raw();
  bool get_ibat_ocp_flag_flag();
  void clear_flag_ibat_ocp_flag() { this->last_ibat_ocp_flag_ = false; }
  void raise_flag_ibat_ocp_flag() { this->last_ibat_ocp_flag_ = true; }

  // CONV_OCP_FLAG - Converter over-current flag
  uint16_t get_conv_ocp_flag_raw();
  bool get_conv_ocp_flag_flag();
  void clear_flag_conv_ocp_flag() { this->last_conv_ocp_flag_ = false; }
  void raise_flag_conv_ocp_flag() { this->last_conv_ocp_flag_ = true; }

  // VAC2_OVP_FLAG - VAC2 over-voltage flag
  uint16_t get_vac2_ovp_flag_raw();
  bool get_vac2_ovp_flag_flag();
  void clear_flag_vac2_ovp_flag() { this->last_vac2_ovp_flag_ = false; }
  void raise_flag_vac2_ovp_flag() { this->last_vac2_ovp_flag_ = true; }

  // VAC1_OVP_FLAG - VAC1 over-voltage flag
  uint16_t get_vac1_ovp_flag_raw();
  bool get_vac1_ovp_flag_flag();
  void clear_flag_vac1_ovp_flag() { this->last_vac1_ovp_flag_ = false; }
  void raise_flag_vac1_ovp_flag() { this->last_vac1_ovp_flag_ = true; }

  // VSYS_SHORT_FLAG - VSYS short circuit flag
  uint16_t get_vsys_short_flag_raw();
  bool get_vsys_short_flag_flag();
  void clear_flag_vsys_short_flag() { this->last_vsys_short_flag_ = false; }
  void raise_flag_vsys_short_flag() { this->last_vsys_short_flag_ = true; }

  // VSYS_OVP_FLAG - VSYS over-voltage flag
  uint16_t get_vsys_ovp_flag_raw();
  bool get_vsys_ovp_flag_flag();
  void clear_flag_vsys_ovp_flag() { this->last_vsys_ovp_flag_ = false; }
  void raise_flag_vsys_ovp_flag() { this->last_vsys_ovp_flag_ = true; }

  // OTG_OVP_FLAG - OTG over-voltage flag
  uint16_t get_otg_ovp_flag_raw();
  bool get_otg_ovp_flag_flag();
  void clear_flag_otg_ovp_flag() { this->last_otg_ovp_flag_ = false; }
  void raise_flag_otg_ovp_flag() { this->last_otg_ovp_flag_ = true; }

  // OTG_UVP_FLAG - OTG under-voltage flag
  uint16_t get_otg_uvp_flag_raw();
  bool get_otg_uvp_flag_flag();
  void clear_flag_otg_uvp_flag() { this->last_otg_uvp_flag_ = false; }
  void raise_flag_otg_uvp_flag() { this->last_otg_uvp_flag_ = true; }

  // TSHUT_FLAG - IC thermal shutdown flag
  uint16_t get_tshut_flag_raw();
  bool get_tshut_flag_flag();
  void clear_flag_tshut_flag() { this->last_tshut_flag_ = false; }
  void raise_flag_tshut_flag() { this->last_tshut_flag_ = true; }

  // ADC_EN - ADC enable
  uint16_t get_adc_en_raw();
  void set_adc_en_raw(uint16_t value);
  bool get_adc_en_bool();
  void set_adc_en_bool(bool value);

  // ADC_RATE - ADC conversion rate
  uint16_t get_adc_rate_raw();
  void set_adc_rate_raw(uint16_t value);
  bool get_adc_rate_bool();
  void set_adc_rate_bool(bool value);
  int get_adc_rate_enum_int();
  const char* get_adc_rate_enum_string();
  void set_adc_rate_enum_int(int value);

  // ADC_SAMPLE - ADC sample speed
  uint16_t get_adc_sample_raw();
  void set_adc_sample_raw(uint16_t value);
  int get_adc_sample_enum_int();
  const char* get_adc_sample_enum_string();
  void set_adc_sample_enum_int(int value);

  // ADC_AVG - ADC averaging
  uint16_t get_adc_avg_raw();
  void set_adc_avg_raw(uint16_t value);
  bool get_adc_avg_bool();
  void set_adc_avg_bool(bool value);
  int get_adc_avg_enum_int();
  const char* get_adc_avg_enum_string();
  void set_adc_avg_enum_int(int value);

  // ADC_AVG_INIT - ADC average initialization
  uint16_t get_adc_avg_init_raw();
  void set_adc_avg_init_raw(uint16_t value);
  bool get_adc_avg_init_bool();
  void set_adc_avg_init_bool(bool value);

  // IBUS_ADC_DIS - IBUS ADC disable
  uint16_t get_ibus_adc_dis_raw();
  void set_ibus_adc_dis_raw(uint16_t value);
  bool get_ibus_adc_dis_bool();
  void set_ibus_adc_dis_bool(bool value);

  // IBAT_ADC_DIS - IBAT ADC disable
  uint16_t get_ibat_adc_dis_raw();
  void set_ibat_adc_dis_raw(uint16_t value);
  bool get_ibat_adc_dis_bool();
  void set_ibat_adc_dis_bool(bool value);

  // VBUS_ADC_DIS - VBUS ADC disable
  uint16_t get_vbus_adc_dis_raw();
  void set_vbus_adc_dis_raw(uint16_t value);
  bool get_vbus_adc_dis_bool();
  void set_vbus_adc_dis_bool(bool value);

  // VBAT_ADC_DIS - VBAT ADC disable
  uint16_t get_vbat_adc_dis_raw();
  void set_vbat_adc_dis_raw(uint16_t value);
  bool get_vbat_adc_dis_bool();
  void set_vbat_adc_dis_bool(bool value);

  // VSYS_ADC_DIS - VSYS ADC disable
  uint16_t get_vsys_adc_dis_raw();
  void set_vsys_adc_dis_raw(uint16_t value);
  bool get_vsys_adc_dis_bool();
  void set_vsys_adc_dis_bool(bool value);

  // TS_ADC_DIS - TS ADC disable
  uint16_t get_ts_adc_dis_raw();
  void set_ts_adc_dis_raw(uint16_t value);
  bool get_ts_adc_dis_bool();
  void set_ts_adc_dis_bool(bool value);

  // TDIE_ADC_DIS - TDIE ADC disable
  uint16_t get_tdie_adc_dis_raw();
  void set_tdie_adc_dis_raw(uint16_t value);
  bool get_tdie_adc_dis_bool();
  void set_tdie_adc_dis_bool(bool value);

  // DPLUS_ADC_DIS - D+ ADC disable
  uint16_t get_dplus_adc_dis_raw();
  void set_dplus_adc_dis_raw(uint16_t value);
  bool get_dplus_adc_dis_bool();
  void set_dplus_adc_dis_bool(bool value);

  // DMINUS_ADC_DIS - D- ADC disable
  uint16_t get_dminus_adc_dis_raw();
  void set_dminus_adc_dis_raw(uint16_t value);
  bool get_dminus_adc_dis_bool();
  void set_dminus_adc_dis_bool(bool value);

  // VAC2_ADC_DIS - VAC2 ADC disable
  uint16_t get_vac2_adc_dis_raw();
  void set_vac2_adc_dis_raw(uint16_t value);
  bool get_vac2_adc_dis_bool();
  void set_vac2_adc_dis_bool(bool value);

  // VAC1_ADC_DIS - VAC1 ADC disable
  uint16_t get_vac1_adc_dis_raw();
  void set_vac1_adc_dis_raw(uint16_t value);
  bool get_vac1_adc_dis_bool();
  void set_vac1_adc_dis_bool(bool value);

  // IBUS_ADC - IBUS ADC reading
  uint16_t get_ibus_adc_raw();
  int get_ibus_adc_int();

  // IBAT_ADC - IBAT ADC reading
  uint16_t get_ibat_adc_raw();
  int get_ibat_adc_int();

  // VBUS_ADC - VBUS ADC reading
  uint16_t get_vbus_adc_raw();
  int get_vbus_adc_int();

  // VAC1_ADC - VAC1 ADC reading
  uint16_t get_vac1_adc_raw();
  int get_vac1_adc_int();

  // VAC2_ADC - VAC2 ADC reading
  uint16_t get_vac2_adc_raw();
  int get_vac2_adc_int();

  // VBAT_ADC - VBAT ADC reading
  uint16_t get_vbat_adc_raw();
  int get_vbat_adc_int();

  // VSYS_ADC - VSYS ADC reading
  uint16_t get_vsys_adc_raw();
  int get_vsys_adc_int();

  // TS_ADC - TS ADC reading
  uint16_t get_ts_adc_raw();
  float get_ts_adc_float();

  // TDIE_ADC - TDIE ADC reading
  uint16_t get_tdie_adc_raw();
  float get_tdie_adc_float();

  // DPLUS_ADC - D+ ADC reading
  uint16_t get_dplus_adc_raw();
  int get_dplus_adc_int();

  // DMINUS_ADC - D- ADC reading
  uint16_t get_dminus_adc_raw();
  int get_dminus_adc_int();

  // DPLUS_DAC - D+ Output Driver
  uint16_t get_dplus_dac_raw();
  void set_dplus_dac_raw(uint16_t value);
  int get_dplus_dac_enum_int();
  const char* get_dplus_dac_enum_string();
  void set_dplus_dac_enum_int(int value);

  // DMINUS_DAC - D- Output Driver
  uint16_t get_dminus_dac_raw();
  void set_dminus_dac_raw(uint16_t value);
  int get_dminus_dac_enum_int();
  const char* get_dminus_dac_enum_string();
  void set_dminus_dac_enum_int(int value);

  // PN - Part number
  uint16_t get_pn_raw();
  int get_pn_enum_int();
  const char* get_pn_enum_string();

  // DEV_REV - Device revision
  uint16_t get_dev_rev_raw();
  int get_dev_rev_enum_int();
  const char* get_dev_rev_enum_string();

protected:
  bool last_iindpm_flag_ = false;
  bool last_vindpm_flag_ = false;
  bool last_wd_flag_ = false;
  bool last_poorsrc_flag_ = false;
  bool last_pg_flag_ = false;
  bool last_ac2_present_flag_ = false;
  bool last_ac1_present_flag_ = false;
  bool last_vbus_present_flag_ = false;
  bool last_chg_flag_ = false;
  bool last_ico_flag_ = false;
  bool last_vbus_flag_ = false;
  bool last_treg_flag_ = false;
  bool last_vbat_present_flag_ = false;
  bool last_bc1_2_done_flag_ = false;
  bool last_dpdm_done_flag_ = false;
  bool last_adc_done_flag_ = false;
  bool last_vsys_flag_ = false;
  bool last_chg_tmr_flag_ = false;
  bool last_trichg_tmr_flag_ = false;
  bool last_prechg_tmr_flag_ = false;
  bool last_topoff_tmr_flag_ = false;
  bool last_vbatotg_low_flag_ = false;
  bool last_ts_cold_flag_ = false;
  bool last_ts_cool_flag_ = false;
  bool last_ts_warm_flag_ = false;
  bool last_ts_hot_flag_ = false;
  bool last_ibat_reg_flag_ = false;
  bool last_vbus_ovp_flag_ = false;
  bool last_vbat_ovp_flag_ = false;
  bool last_ibus_ocp_flag_ = false;
  bool last_ibat_ocp_flag_ = false;
  bool last_conv_ocp_flag_ = false;
  bool last_vac2_ovp_flag_ = false;
  bool last_vac1_ovp_flag_ = false;
  bool last_vsys_short_flag_ = false;
  bool last_vsys_ovp_flag_ = false;
  bool last_otg_ovp_flag_ = false;
  bool last_otg_uvp_flag_ = false;
  bool last_tshut_flag_ = false;

  BQ25798NoI2C *bq25798_noi2c_ {nullptr};
};  // class BQ25798Component

}  // namespace bq25798
}  // namespace esphome