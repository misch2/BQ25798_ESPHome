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
  uint16_t get_vsysmin_raw(bool read_from_i2c);
  void set_vsysmin_raw(uint16_t value, bool write_to_i2c);

  int get_vsysmin_int(bool read_from_i2c);
  void set_vsysmin_int(int value, bool write_to_i2c);

  // VREG - Charge Voltage Limit
  uint16_t get_vreg_raw(bool read_from_i2c);
  void set_vreg_raw(uint16_t value, bool write_to_i2c);

  int get_vreg_int(bool read_from_i2c);
  void set_vreg_int(int value, bool write_to_i2c);

  // ICHG - Charge Current Limit
  uint16_t get_ichg_raw(bool read_from_i2c);
  void set_ichg_raw(uint16_t value, bool write_to_i2c);

  int get_ichg_int(bool read_from_i2c);
  void set_ichg_int(int value, bool write_to_i2c);

  // VINDPM - Input Voltage Limit
  uint16_t get_vindpm_raw(bool read_from_i2c);
  void set_vindpm_raw(uint16_t value, bool write_to_i2c);

  int get_vindpm_int(bool read_from_i2c);
  void set_vindpm_int(int value, bool write_to_i2c);

  // IINDPM - Input Current Limit
  uint16_t get_iindpm_raw(bool read_from_i2c);
  void set_iindpm_raw(uint16_t value, bool write_to_i2c);

  int get_iindpm_int(bool read_from_i2c);
  void set_iindpm_int(int value, bool write_to_i2c);

  // VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
  uint16_t get_vbat_lowv_raw(bool read_from_i2c);
  void set_vbat_lowv_raw(uint16_t value, bool write_to_i2c);

  int get_vbat_lowv_enum_int(bool read_from_i2c);
  const char* get_vbat_lowv_enum_string(bool read_from_i2c);
  void set_vbat_lowv_enum_int(int value, bool write_to_i2c);

  // IPRECHG - Precharge Current Limit
  uint16_t get_iprechg_raw(bool read_from_i2c);
  void set_iprechg_raw(uint16_t value, bool write_to_i2c);

  int get_iprechg_int(bool read_from_i2c);
  void set_iprechg_int(int value, bool write_to_i2c);

  // REG_RST - Reset registers to default values and reset timer
  uint16_t get_reg_rst_raw(bool read_from_i2c);
  void set_reg_rst_raw(uint16_t value, bool write_to_i2c);

  bool get_reg_rst_bool(bool read_from_i2c);
  void set_reg_rst_bool(bool value, bool write_to_i2c);

  // STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
  uint16_t get_stop_wd_chg_raw(bool read_from_i2c);
  void set_stop_wd_chg_raw(uint16_t value, bool write_to_i2c);

  bool get_stop_wd_chg_bool(bool read_from_i2c);
  void set_stop_wd_chg_bool(bool value, bool write_to_i2c);

  // ITERM - Termination Current Limit
  uint16_t get_iterm_raw(bool read_from_i2c);
  void set_iterm_raw(uint16_t value, bool write_to_i2c);

  int get_iterm_int(bool read_from_i2c);
  void set_iterm_int(int value, bool write_to_i2c);

  // CELL - Battery cell count
  uint16_t get_cell_raw(bool read_from_i2c);
  void set_cell_raw(uint16_t value, bool write_to_i2c);

  int get_cell_enum_int(bool read_from_i2c);
  const char* get_cell_enum_string(bool read_from_i2c);
  void set_cell_enum_int(int value, bool write_to_i2c);

  // TRECHG - Battery recharge delay time
  uint16_t get_trechg_raw(bool read_from_i2c);
  void set_trechg_raw(uint16_t value, bool write_to_i2c);

  int get_trechg_enum_int(bool read_from_i2c);
  const char* get_trechg_enum_string(bool read_from_i2c);
  void set_trechg_enum_int(int value, bool write_to_i2c);

  // VRECHG - Battery Recharge Threshold Offset (Below VREG)
  uint16_t get_vrechg_raw(bool read_from_i2c);
  void set_vrechg_raw(uint16_t value, bool write_to_i2c);

  int get_vrechg_int(bool read_from_i2c);
  void set_vrechg_int(int value, bool write_to_i2c);

  // VOTG - OTG mode regulation voltage
  uint16_t get_votg_raw(bool read_from_i2c);
  void set_votg_raw(uint16_t value, bool write_to_i2c);

  int get_votg_int(bool read_from_i2c);
  void set_votg_int(int value, bool write_to_i2c);

  // PRECHG_TMR - Pre-charge safety timer setting
  uint16_t get_prechg_tmr_raw(bool read_from_i2c);
  void set_prechg_tmr_raw(uint16_t value, bool write_to_i2c);

  bool get_prechg_tmr_bool(bool read_from_i2c);
  void set_prechg_tmr_bool(bool value, bool write_to_i2c);
  int get_prechg_tmr_enum_int(bool read_from_i2c);
  const char* get_prechg_tmr_enum_string(bool read_from_i2c);
  void set_prechg_tmr_enum_int(int value, bool write_to_i2c);

  // IOTG - OTG current limit
  uint16_t get_iotg_raw(bool read_from_i2c);
  void set_iotg_raw(uint16_t value, bool write_to_i2c);

  int get_iotg_int(bool read_from_i2c);
  void set_iotg_int(int value, bool write_to_i2c);

  // TOPOFF_TMR - Top-off timer control
  uint16_t get_topoff_tmr_raw(bool read_from_i2c);
  void set_topoff_tmr_raw(uint16_t value, bool write_to_i2c);

  int get_topoff_tmr_enum_int(bool read_from_i2c);
  const char* get_topoff_tmr_enum_string(bool read_from_i2c);
  void set_topoff_tmr_enum_int(int value, bool write_to_i2c);

  // EN_TRICHG_TMR - Trickle charge timer enable
  uint16_t get_en_trichg_tmr_raw(bool read_from_i2c);
  void set_en_trichg_tmr_raw(uint16_t value, bool write_to_i2c);

  bool get_en_trichg_tmr_bool(bool read_from_i2c);
  void set_en_trichg_tmr_bool(bool value, bool write_to_i2c);

  // EN_PRECHG_TMR - Precharge timer enable
  uint16_t get_en_prechg_tmr_raw(bool read_from_i2c);
  void set_en_prechg_tmr_raw(uint16_t value, bool write_to_i2c);

  bool get_en_prechg_tmr_bool(bool read_from_i2c);
  void set_en_prechg_tmr_bool(bool value, bool write_to_i2c);

  // EN_CHG_TMR - Fast charge timer enable
  uint16_t get_en_chg_tmr_raw(bool read_from_i2c);
  void set_en_chg_tmr_raw(uint16_t value, bool write_to_i2c);

  bool get_en_chg_tmr_bool(bool read_from_i2c);
  void set_en_chg_tmr_bool(bool value, bool write_to_i2c);

  // CHG_TMR - Fast charge timer setting
  uint16_t get_chg_tmr_raw(bool read_from_i2c);
  void set_chg_tmr_raw(uint16_t value, bool write_to_i2c);

  int get_chg_tmr_enum_int(bool read_from_i2c);
  const char* get_chg_tmr_enum_string(bool read_from_i2c);
  void set_chg_tmr_enum_int(int value, bool write_to_i2c);

  // TMR2X_EN - 2x slower charging in DPM enable
  uint16_t get_tmr2x_en_raw(bool read_from_i2c);
  void set_tmr2x_en_raw(uint16_t value, bool write_to_i2c);

  bool get_tmr2x_en_bool(bool read_from_i2c);
  void set_tmr2x_en_bool(bool value, bool write_to_i2c);

  // EN_AUTO_IBATDIS - Enable the auto battery discharging during the battery OVP fault
  uint16_t get_en_auto_ibatdis_raw(bool read_from_i2c);
  void set_en_auto_ibatdis_raw(uint16_t value, bool write_to_i2c);

  bool get_en_auto_ibatdis_bool(bool read_from_i2c);
  void set_en_auto_ibatdis_bool(bool value, bool write_to_i2c);

  // FORCE_IBATDIS - Force the battery discharging current
  uint16_t get_force_ibatdis_raw(bool read_from_i2c);
  void set_force_ibatdis_raw(uint16_t value, bool write_to_i2c);

  bool get_force_ibatdis_bool(bool read_from_i2c);
  void set_force_ibatdis_bool(bool value, bool write_to_i2c);

  // EN_CHG - Enable the charger
  uint16_t get_en_chg_raw(bool read_from_i2c);
  void set_en_chg_raw(uint16_t value, bool write_to_i2c);

  bool get_en_chg_bool(bool read_from_i2c);
  void set_en_chg_bool(bool value, bool write_to_i2c);

  // EN_ICO - Enable the ICO (Input Current Optimizer)
  uint16_t get_en_ico_raw(bool read_from_i2c);
  void set_en_ico_raw(uint16_t value, bool write_to_i2c);

  bool get_en_ico_bool(bool read_from_i2c);
  void set_en_ico_bool(bool value, bool write_to_i2c);

  // FORCE_ICO - Force the ICO (Input Current Optimizer)
  uint16_t get_force_ico_raw(bool read_from_i2c);
  void set_force_ico_raw(uint16_t value, bool write_to_i2c);

  bool get_force_ico_bool(bool read_from_i2c);
  void set_force_ico_bool(bool value, bool write_to_i2c);

  // EN_HIZ - Enable the high impedance mode
  uint16_t get_en_hiz_raw(bool read_from_i2c);
  void set_en_hiz_raw(uint16_t value, bool write_to_i2c);

  bool get_en_hiz_bool(bool read_from_i2c);
  void set_en_hiz_bool(bool value, bool write_to_i2c);

  // EN_TERM - Enable the termination
  uint16_t get_en_term_raw(bool read_from_i2c);
  void set_en_term_raw(uint16_t value, bool write_to_i2c);

  bool get_en_term_bool(bool read_from_i2c);
  void set_en_term_bool(bool value, bool write_to_i2c);

  // EN_BACKUP - Enable the backup (auto OTG) mode
  uint16_t get_en_backup_raw(bool read_from_i2c);
  void set_en_backup_raw(uint16_t value, bool write_to_i2c);

  bool get_en_backup_bool(bool read_from_i2c);
  void set_en_backup_bool(bool value, bool write_to_i2c);

  // VBUS_BACKUP - The thresholds to trigger the backup mode, defined as a ratio of VINDPM
  uint16_t get_vbus_backup_raw(bool read_from_i2c);
  void set_vbus_backup_raw(uint16_t value, bool write_to_i2c);

  int get_vbus_backup_enum_int(bool read_from_i2c);
  const char* get_vbus_backup_enum_string(bool read_from_i2c);
  void set_vbus_backup_enum_int(int value, bool write_to_i2c);

  // VAC_OVP - Over voltage protection thresholds
  uint16_t get_vac_ovp_raw(bool read_from_i2c);
  void set_vac_ovp_raw(uint16_t value, bool write_to_i2c);

  int get_vac_ovp_enum_int(bool read_from_i2c);
  const char* get_vac_ovp_enum_string(bool read_from_i2c);
  void set_vac_ovp_enum_int(int value, bool write_to_i2c);

  // WD_RST - I2C watch dog timer reset
  uint16_t get_wd_rst_raw(bool read_from_i2c);
  void set_wd_rst_raw(uint16_t value, bool write_to_i2c);

  bool get_wd_rst_bool(bool read_from_i2c);
  void set_wd_rst_bool(bool value, bool write_to_i2c);

  // WATCHDOG - Watchdog timer settings
  uint16_t get_watchdog_raw(bool read_from_i2c);
  void set_watchdog_raw(uint16_t value, bool write_to_i2c);

  int get_watchdog_enum_int(bool read_from_i2c);
  const char* get_watchdog_enum_string(bool read_from_i2c);
  void set_watchdog_enum_int(int value, bool write_to_i2c);

  // FORCE_INDET - Force D+/D- detection
  uint16_t get_force_indet_raw(bool read_from_i2c);
  void set_force_indet_raw(uint16_t value, bool write_to_i2c);

  bool get_force_indet_bool(bool read_from_i2c);
  void set_force_indet_bool(bool value, bool write_to_i2c);

  // AUTO_INDET_EN - Enable automatic D+/D- detection
  uint16_t get_auto_indet_en_raw(bool read_from_i2c);
  void set_auto_indet_en_raw(uint16_t value, bool write_to_i2c);

  bool get_auto_indet_en_bool(bool read_from_i2c);
  void set_auto_indet_en_bool(bool value, bool write_to_i2c);

  // EN_12V - Enable 12V output in HVDCP
  uint16_t get_en_12v_raw(bool read_from_i2c);
  void set_en_12v_raw(uint16_t value, bool write_to_i2c);

  bool get_en_12v_bool(bool read_from_i2c);
  void set_en_12v_bool(bool value, bool write_to_i2c);

  // EN_9V - Enable 9V output in HVDCP
  uint16_t get_en_9v_raw(bool read_from_i2c);
  void set_en_9v_raw(uint16_t value, bool write_to_i2c);

  bool get_en_9v_bool(bool read_from_i2c);
  void set_en_9v_bool(bool value, bool write_to_i2c);

  // HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
  uint16_t get_hvdcp_en_raw(bool read_from_i2c);
  void set_hvdcp_en_raw(uint16_t value, bool write_to_i2c);

  bool get_hvdcp_en_bool(bool read_from_i2c);
  void set_hvdcp_en_bool(bool value, bool write_to_i2c);

  // SDRV_CTRL - Enable external Ship FET control
  uint16_t get_sdrv_ctrl_raw(bool read_from_i2c);
  void set_sdrv_ctrl_raw(uint16_t value, bool write_to_i2c);

  int get_sdrv_ctrl_enum_int(bool read_from_i2c);
  const char* get_sdrv_ctrl_enum_string(bool read_from_i2c);
  void set_sdrv_ctrl_enum_int(int value, bool write_to_i2c);

  // SDRV_DLY - Delay for SDRV control
  uint16_t get_sdrv_dly_raw(bool read_from_i2c);
  void set_sdrv_dly_raw(uint16_t value, bool write_to_i2c);

  bool get_sdrv_dly_bool(bool read_from_i2c);
  void set_sdrv_dly_bool(bool value, bool write_to_i2c);
  int get_sdrv_dly_enum_int(bool read_from_i2c);
  const char* get_sdrv_dly_enum_string(bool read_from_i2c);
  void set_sdrv_dly_enum_int(int value, bool write_to_i2c);

  // DIS_ACDRV - Disable both AC1 and AC2 drivers
  uint16_t get_dis_acdrv_raw(bool read_from_i2c);
  void set_dis_acdrv_raw(uint16_t value, bool write_to_i2c);

  bool get_dis_acdrv_bool(bool read_from_i2c);
  void set_dis_acdrv_bool(bool value, bool write_to_i2c);

  // EN_OTG - Enable OTG mode
  uint16_t get_en_otg_raw(bool read_from_i2c);
  void set_en_otg_raw(uint16_t value, bool write_to_i2c);

  bool get_en_otg_bool(bool read_from_i2c);
  void set_en_otg_bool(bool value, bool write_to_i2c);

  // PFM_OTG_DIS - Disable PFM in OTG mode
  uint16_t get_pfm_otg_dis_raw(bool read_from_i2c);
  void set_pfm_otg_dis_raw(uint16_t value, bool write_to_i2c);

  bool get_pfm_otg_dis_bool(bool read_from_i2c);
  void set_pfm_otg_dis_bool(bool value, bool write_to_i2c);

  // PFM_FWD_DIS - Disable PFM in forward mode
  uint16_t get_pfm_fwd_dis_raw(bool read_from_i2c);
  void set_pfm_fwd_dis_raw(uint16_t value, bool write_to_i2c);

  bool get_pfm_fwd_dis_bool(bool read_from_i2c);
  void set_pfm_fwd_dis_bool(bool value, bool write_to_i2c);

  // WKUP_DLY - Wakeup (Ship FET) delay
  uint16_t get_wkup_dly_raw(bool read_from_i2c);
  void set_wkup_dly_raw(uint16_t value, bool write_to_i2c);

  bool get_wkup_dly_bool(bool read_from_i2c);
  void set_wkup_dly_bool(bool value, bool write_to_i2c);
  int get_wkup_dly_enum_int(bool read_from_i2c);
  const char* get_wkup_dly_enum_string(bool read_from_i2c);
  void set_wkup_dly_enum_int(int value, bool write_to_i2c);

  // DIS_LDO - Disable BATFET LDO mode in precharge state
  uint16_t get_dis_ldo_raw(bool read_from_i2c);
  void set_dis_ldo_raw(uint16_t value, bool write_to_i2c);

  bool get_dis_ldo_bool(bool read_from_i2c);
  void set_dis_ldo_bool(bool value, bool write_to_i2c);

  // DIS_OTG_OOA - Disable OOA in OTG mode
  uint16_t get_dis_otg_ooa_raw(bool read_from_i2c);
  void set_dis_otg_ooa_raw(uint16_t value, bool write_to_i2c);

  bool get_dis_otg_ooa_bool(bool read_from_i2c);
  void set_dis_otg_ooa_bool(bool value, bool write_to_i2c);

  // DIS_FWD_OOA - Disable OOA in forward mode
  uint16_t get_dis_fwd_ooa_raw(bool read_from_i2c);
  void set_dis_fwd_ooa_raw(uint16_t value, bool write_to_i2c);

  bool get_dis_fwd_ooa_bool(bool read_from_i2c);
  void set_dis_fwd_ooa_bool(bool value, bool write_to_i2c);

  // EN_ACDRV2 - Enable AC2 gate driver control
  uint16_t get_en_acdrv2_raw(bool read_from_i2c);
  void set_en_acdrv2_raw(uint16_t value, bool write_to_i2c);

  bool get_en_acdrv2_bool(bool read_from_i2c);
  void set_en_acdrv2_bool(bool value, bool write_to_i2c);

  // EN_ACDRV1 - Enable AC1 gate driver control
  uint16_t get_en_acdrv1_raw(bool read_from_i2c);
  void set_en_acdrv1_raw(uint16_t value, bool write_to_i2c);

  bool get_en_acdrv1_bool(bool read_from_i2c);
  void set_en_acdrv1_bool(bool value, bool write_to_i2c);

  // PWM_FREQ - PWM frequency setting
  uint16_t get_pwm_freq_raw(bool read_from_i2c);
  void set_pwm_freq_raw(uint16_t value, bool write_to_i2c);

  bool get_pwm_freq_bool(bool read_from_i2c);
  void set_pwm_freq_bool(bool value, bool write_to_i2c);
  int get_pwm_freq_enum_int(bool read_from_i2c);
  const char* get_pwm_freq_enum_string(bool read_from_i2c);
  void set_pwm_freq_enum_int(int value, bool write_to_i2c);

  // DIS_STAT - Disable STAT pin output
  uint16_t get_dis_stat_raw(bool read_from_i2c);
  void set_dis_stat_raw(uint16_t value, bool write_to_i2c);

  bool get_dis_stat_bool(bool read_from_i2c);
  void set_dis_stat_bool(bool value, bool write_to_i2c);

  // DIS_VSYS_SHORT - Disable VSYS short hiccup protection
  uint16_t get_dis_vsys_short_raw(bool read_from_i2c);
  void set_dis_vsys_short_raw(uint16_t value, bool write_to_i2c);

  bool get_dis_vsys_short_bool(bool read_from_i2c);
  void set_dis_vsys_short_bool(bool value, bool write_to_i2c);

  // DIS_VOTG_UVP - Disable VOTG under voltage hiccup protection
  uint16_t get_dis_votg_uvp_raw(bool read_from_i2c);
  void set_dis_votg_uvp_raw(uint16_t value, bool write_to_i2c);

  bool get_dis_votg_uvp_bool(bool read_from_i2c);
  void set_dis_votg_uvp_bool(bool value, bool write_to_i2c);

  // FORCE_VINDPM_DET - Force VINDPM detection (settable only when VBAT>VSYSMIN)
  uint16_t get_force_vindpm_det_raw(bool read_from_i2c);
  void set_force_vindpm_det_raw(uint16_t value, bool write_to_i2c);

  bool get_force_vindpm_det_bool(bool read_from_i2c);
  void set_force_vindpm_det_bool(bool value, bool write_to_i2c);

  // EN_IBUS_OCP - Enable input over current protection in forward mode
  uint16_t get_en_ibus_ocp_raw(bool read_from_i2c);
  void set_en_ibus_ocp_raw(uint16_t value, bool write_to_i2c);

  bool get_en_ibus_ocp_bool(bool read_from_i2c);
  void set_en_ibus_ocp_bool(bool value, bool write_to_i2c);

  // SFET_PRESENT - Ship FET present
  uint16_t get_sfet_present_raw(bool read_from_i2c);
  void set_sfet_present_raw(uint16_t value, bool write_to_i2c);

  bool get_sfet_present_bool(bool read_from_i2c);
  void set_sfet_present_bool(bool value, bool write_to_i2c);

  // EN_IBAT - Enable battery discharge current sensing
  uint16_t get_en_ibat_raw(bool read_from_i2c);
  void set_en_ibat_raw(uint16_t value, bool write_to_i2c);

  bool get_en_ibat_bool(bool read_from_i2c);
  void set_en_ibat_bool(bool value, bool write_to_i2c);

  // IBAT_REG - Battery discharge current regulation in OTG mode
  uint16_t get_ibat_reg_raw(bool read_from_i2c);
  void set_ibat_reg_raw(uint16_t value, bool write_to_i2c);

  int get_ibat_reg_enum_int(bool read_from_i2c);
  const char* get_ibat_reg_enum_string(bool read_from_i2c);
  void set_ibat_reg_enum_int(int value, bool write_to_i2c);

  // EN_IINDPM - Enable input current regulation
  uint16_t get_en_iindpm_raw(bool read_from_i2c);
  void set_en_iindpm_raw(uint16_t value, bool write_to_i2c);

  bool get_en_iindpm_bool(bool read_from_i2c);
  void set_en_iindpm_bool(bool value, bool write_to_i2c);

  // EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
  uint16_t get_en_extilim_raw(bool read_from_i2c);
  void set_en_extilim_raw(uint16_t value, bool write_to_i2c);

  bool get_en_extilim_bool(bool read_from_i2c);
  void set_en_extilim_bool(bool value, bool write_to_i2c);

  // EN_BATOC - Enable battery discharging over current protection
  uint16_t get_en_batoc_raw(bool read_from_i2c);
  void set_en_batoc_raw(uint16_t value, bool write_to_i2c);

  bool get_en_batoc_bool(bool read_from_i2c);
  void set_en_batoc_bool(bool value, bool write_to_i2c);

  // VOC_PCT - Set VINDPM as a percentage of the VBUS open circuit voltage when the VOC measurement is done
  uint16_t get_voc_pct_raw(bool read_from_i2c);
  void set_voc_pct_raw(uint16_t value, bool write_to_i2c);

  int get_voc_pct_enum_int(bool read_from_i2c);
  const char* get_voc_pct_enum_string(bool read_from_i2c);
  void set_voc_pct_enum_int(int value, bool write_to_i2c);

  // VOC_DLY - After the converter stops switching, the time delay before the VOC is measured
  uint16_t get_voc_dly_raw(bool read_from_i2c);
  void set_voc_dly_raw(uint16_t value, bool write_to_i2c);

  int get_voc_dly_enum_int(bool read_from_i2c);
  const char* get_voc_dly_enum_string(bool read_from_i2c);
  void set_voc_dly_enum_int(int value, bool write_to_i2c);

  // VOC_RATE - The time interval between two consecutive VOC measurements
  uint16_t get_voc_rate_raw(bool read_from_i2c);
  void set_voc_rate_raw(uint16_t value, bool write_to_i2c);

  int get_voc_rate_enum_int(bool read_from_i2c);
  const char* get_voc_rate_enum_string(bool read_from_i2c);
  void set_voc_rate_enum_int(int value, bool write_to_i2c);

  // EN_MPPT - Enable MPPT (Maximum Power Point Tracking)
  uint16_t get_en_mppt_raw(bool read_from_i2c);
  void set_en_mppt_raw(uint16_t value, bool write_to_i2c);

  bool get_en_mppt_bool(bool read_from_i2c);
  void set_en_mppt_bool(bool value, bool write_to_i2c);

  // TREG - Thermal regulation thresholds
  uint16_t get_treg_raw(bool read_from_i2c);
  void set_treg_raw(uint16_t value, bool write_to_i2c);

  int get_treg_enum_int(bool read_from_i2c);
  const char* get_treg_enum_string(bool read_from_i2c);
  void set_treg_enum_int(int value, bool write_to_i2c);

  // TSHUT - Thermal shutdown thresholds
  uint16_t get_tshut_raw(bool read_from_i2c);
  void set_tshut_raw(uint16_t value, bool write_to_i2c);

  int get_tshut_enum_int(bool read_from_i2c);
  const char* get_tshut_enum_string(bool read_from_i2c);
  void set_tshut_enum_int(int value, bool write_to_i2c);

  // VBUS_PD_EN - Enable VBUS pull down resistor (6 kOhm)
  uint16_t get_vbus_pd_en_raw(bool read_from_i2c);
  void set_vbus_pd_en_raw(uint16_t value, bool write_to_i2c);

  bool get_vbus_pd_en_bool(bool read_from_i2c);
  void set_vbus_pd_en_bool(bool value, bool write_to_i2c);

  // VAC1_PD_EN - Enable VAC1 pull down resistor
  uint16_t get_vac1_pd_en_raw(bool read_from_i2c);
  void set_vac1_pd_en_raw(uint16_t value, bool write_to_i2c);

  bool get_vac1_pd_en_bool(bool read_from_i2c);
  void set_vac1_pd_en_bool(bool value, bool write_to_i2c);

  // VAC2_PD_EN - Enable VAC2 pull down resistor
  uint16_t get_vac2_pd_en_raw(bool read_from_i2c);
  void set_vac2_pd_en_raw(uint16_t value, bool write_to_i2c);

  bool get_vac2_pd_en_bool(bool read_from_i2c);
  void set_vac2_pd_en_bool(bool value, bool write_to_i2c);

  // BKUP_ACFET1_ON - Enable ACFET1 in backup mode (exit backup mode)
  uint16_t get_bkup_acfet1_on_raw(bool read_from_i2c);
  void set_bkup_acfet1_on_raw(uint16_t value, bool write_to_i2c);

  bool get_bkup_acfet1_on_bool(bool read_from_i2c);
  void set_bkup_acfet1_on_bool(bool value, bool write_to_i2c);
  int get_bkup_acfet1_on_enum_int(bool read_from_i2c);
  const char* get_bkup_acfet1_on_enum_string(bool read_from_i2c);
  void set_bkup_acfet1_on_enum_int(int value, bool write_to_i2c);

  // JEITA_VSET - JEITA high temperature range (TWARN - THOT) charge voltage setting
  uint16_t get_jeita_vset_raw(bool read_from_i2c);
  void set_jeita_vset_raw(uint16_t value, bool write_to_i2c);

  int get_jeita_vset_enum_int(bool read_from_i2c);
  const char* get_jeita_vset_enum_string(bool read_from_i2c);
  void set_jeita_vset_enum_int(int value, bool write_to_i2c);

  // JEITA_ISETH - JEITA high temperature range (TWARN - THOT) charge current setting
  uint16_t get_jeita_iseth_raw(bool read_from_i2c);
  void set_jeita_iseth_raw(uint16_t value, bool write_to_i2c);

  int get_jeita_iseth_enum_int(bool read_from_i2c);
  const char* get_jeita_iseth_enum_string(bool read_from_i2c);
  void set_jeita_iseth_enum_int(int value, bool write_to_i2c);

  // JEITA_ISETC - JEITA low temperature range (TCOLD - TWARN) charge current setting
  uint16_t get_jeita_isetc_raw(bool read_from_i2c);
  void set_jeita_isetc_raw(uint16_t value, bool write_to_i2c);

  int get_jeita_isetc_enum_int(bool read_from_i2c);
  const char* get_jeita_isetc_enum_string(bool read_from_i2c);
  void set_jeita_isetc_enum_int(int value, bool write_to_i2c);

  // TS_COOL - JEITA VT2 comparator voltage rising thresholds as a percentage of REGN.
  uint16_t get_ts_cool_raw(bool read_from_i2c);
  void set_ts_cool_raw(uint16_t value, bool write_to_i2c);

  int get_ts_cool_enum_int(bool read_from_i2c);
  const char* get_ts_cool_enum_string(bool read_from_i2c);
  void set_ts_cool_enum_int(int value, bool write_to_i2c);

  // TS_WARM - JEITA VT3 comparator voltage falling thresholds as a percentage of REGN.
  uint16_t get_ts_warm_raw(bool read_from_i2c);
  void set_ts_warm_raw(uint16_t value, bool write_to_i2c);

  int get_ts_warm_enum_int(bool read_from_i2c);
  const char* get_ts_warm_enum_string(bool read_from_i2c);
  void set_ts_warm_enum_int(int value, bool write_to_i2c);

  // BHOT - OTG mode TS HOT temperature threshold
  uint16_t get_bhot_raw(bool read_from_i2c);
  void set_bhot_raw(uint16_t value, bool write_to_i2c);

  int get_bhot_enum_int(bool read_from_i2c);
  const char* get_bhot_enum_string(bool read_from_i2c);
  void set_bhot_enum_int(int value, bool write_to_i2c);

  // BCOLD - OTG mode TS COLD temperature threshold
  uint16_t get_bcold_raw(bool read_from_i2c);
  void set_bcold_raw(uint16_t value, bool write_to_i2c);

  bool get_bcold_bool(bool read_from_i2c);
  void set_bcold_bool(bool value, bool write_to_i2c);
  int get_bcold_enum_int(bool read_from_i2c);
  const char* get_bcold_enum_string(bool read_from_i2c);
  void set_bcold_enum_int(int value, bool write_to_i2c);

  // TS_IGNORE - Ignore TS detection (the charger considers the TS is always good)
  uint16_t get_ts_ignore_raw(bool read_from_i2c);
  void set_ts_ignore_raw(uint16_t value, bool write_to_i2c);

  bool get_ts_ignore_bool(bool read_from_i2c);
  void set_ts_ignore_bool(bool value, bool write_to_i2c);

  // ICO_ILIM - Input Current Limit obtained from ICO or ILIM_HIZ pin setting
  uint16_t get_ico_ilim_raw(bool read_from_i2c);

  int get_ico_ilim_int(bool read_from_i2c);

  // IINDPM_STAT - IINDPM status (forward mode) or IOTG status (OTG mode)
  uint16_t get_iindpm_stat_raw(bool read_from_i2c);

  bool get_iindpm_stat_bool(bool read_from_i2c);
  int get_iindpm_stat_enum_int(bool read_from_i2c);
  const char* get_iindpm_stat_enum_string(bool read_from_i2c);

  // VINDPM_STAT - VINDPM status (forward mode) or VOTG status (OTG mode)
  uint16_t get_vindpm_stat_raw(bool read_from_i2c);

  bool get_vindpm_stat_bool(bool read_from_i2c);
  int get_vindpm_stat_enum_int(bool read_from_i2c);
  const char* get_vindpm_stat_enum_string(bool read_from_i2c);

  // WD_STAT - Watchdog timer status
  uint16_t get_wd_stat_raw(bool read_from_i2c);

  bool get_wd_stat_bool(bool read_from_i2c);
  int get_wd_stat_enum_int(bool read_from_i2c);
  const char* get_wd_stat_enum_string(bool read_from_i2c);

  // PG_STAT - Power good status
  uint16_t get_pg_stat_raw(bool read_from_i2c);

  bool get_pg_stat_bool(bool read_from_i2c);
  int get_pg_stat_enum_int(bool read_from_i2c);
  const char* get_pg_stat_enum_string(bool read_from_i2c);

  // AC2_PRESENT_STAT - VAC2 present status
  uint16_t get_ac2_present_stat_raw(bool read_from_i2c);

  bool get_ac2_present_stat_bool(bool read_from_i2c);
  int get_ac2_present_stat_enum_int(bool read_from_i2c);
  const char* get_ac2_present_stat_enum_string(bool read_from_i2c);

  // AC1_PRESENT_STAT - VAC1 present status
  uint16_t get_ac1_present_stat_raw(bool read_from_i2c);

  bool get_ac1_present_stat_bool(bool read_from_i2c);
  int get_ac1_present_stat_enum_int(bool read_from_i2c);
  const char* get_ac1_present_stat_enum_string(bool read_from_i2c);

  // VBUS_PRESENT_STAT - VBUS present status
  uint16_t get_vbus_present_stat_raw(bool read_from_i2c);

  bool get_vbus_present_stat_bool(bool read_from_i2c);
  int get_vbus_present_stat_enum_int(bool read_from_i2c);
  const char* get_vbus_present_stat_enum_string(bool read_from_i2c);

  // CHG_STAT - Charge Status bits
  uint16_t get_chg_stat_raw(bool read_from_i2c);

  int get_chg_stat_enum_int(bool read_from_i2c);
  const char* get_chg_stat_enum_string(bool read_from_i2c);

  // VBUS_STAT - VBUS status bits
  uint16_t get_vbus_stat_raw(bool read_from_i2c);

  int get_vbus_stat_enum_int(bool read_from_i2c);
  const char* get_vbus_stat_enum_string(bool read_from_i2c);

  // BC12_DONE_STAT - BC1.2 detection done status
  uint16_t get_bc12_done_stat_raw(bool read_from_i2c);

  bool get_bc12_done_stat_bool(bool read_from_i2c);

  // ICO_STAT - Input Current Optimizer (ICO) status
  uint16_t get_ico_stat_raw(bool read_from_i2c);

  int get_ico_stat_enum_int(bool read_from_i2c);
  const char* get_ico_stat_enum_string(bool read_from_i2c);

  // TREG_STAT - IC thermal regulation status
  uint16_t get_treg_stat_raw(bool read_from_i2c);

  bool get_treg_stat_bool(bool read_from_i2c);
  int get_treg_stat_enum_int(bool read_from_i2c);
  const char* get_treg_stat_enum_string(bool read_from_i2c);

  // DPDM_STAT - D+/D- detection status
  uint16_t get_dpdm_stat_raw(bool read_from_i2c);

  bool get_dpdm_stat_bool(bool read_from_i2c);
  int get_dpdm_stat_enum_int(bool read_from_i2c);
  const char* get_dpdm_stat_enum_string(bool read_from_i2c);

  // VBAT_PRESENT_STAT - Battery present status
  uint16_t get_vbat_present_stat_raw(bool read_from_i2c);

  bool get_vbat_present_stat_bool(bool read_from_i2c);
  int get_vbat_present_stat_enum_int(bool read_from_i2c);
  const char* get_vbat_present_stat_enum_string(bool read_from_i2c);

  // ACRB2_STAT - The ACFET2-RBFET2 status
  uint16_t get_acrb2_stat_raw(bool read_from_i2c);

  bool get_acrb2_stat_bool(bool read_from_i2c);
  int get_acrb2_stat_enum_int(bool read_from_i2c);
  const char* get_acrb2_stat_enum_string(bool read_from_i2c);

  // ACRB1_STAT - The ACFET1-RBFET1 status
  uint16_t get_acrb1_stat_raw(bool read_from_i2c);

  bool get_acrb1_stat_bool(bool read_from_i2c);
  int get_acrb1_stat_enum_int(bool read_from_i2c);
  const char* get_acrb1_stat_enum_string(bool read_from_i2c);

  // ADC_DONE_STAT - ADC Conversion Status
  uint16_t get_adc_done_stat_raw(bool read_from_i2c);

  bool get_adc_done_stat_bool(bool read_from_i2c);

  // VSYS_STAT - VSYS Regulation Status
  uint16_t get_vsys_stat_raw(bool read_from_i2c);

  bool get_vsys_stat_bool(bool read_from_i2c);
  int get_vsys_stat_enum_int(bool read_from_i2c);
  const char* get_vsys_stat_enum_string(bool read_from_i2c);

  // CHG_TMR_STAT - Fast charge timer status
  uint16_t get_chg_tmr_stat_raw(bool read_from_i2c);

  bool get_chg_tmr_stat_bool(bool read_from_i2c);
  int get_chg_tmr_stat_enum_int(bool read_from_i2c);
  const char* get_chg_tmr_stat_enum_string(bool read_from_i2c);

  // TRICHG_TMR_STAT - Trickle charge timer status
  uint16_t get_trichg_tmr_stat_raw(bool read_from_i2c);

  bool get_trichg_tmr_stat_bool(bool read_from_i2c);
  int get_trichg_tmr_stat_enum_int(bool read_from_i2c);
  const char* get_trichg_tmr_stat_enum_string(bool read_from_i2c);

  // PRECHG_TMR_STAT - Pre-charge timer status
  uint16_t get_prechg_tmr_stat_raw(bool read_from_i2c);

  bool get_prechg_tmr_stat_bool(bool read_from_i2c);
  int get_prechg_tmr_stat_enum_int(bool read_from_i2c);
  const char* get_prechg_tmr_stat_enum_string(bool read_from_i2c);

  // VBATOTG_LOW_STAT - VBAT too low to enable OTG flag
  uint16_t get_vbatotg_low_stat_raw(bool read_from_i2c);

  bool get_vbatotg_low_stat_bool(bool read_from_i2c);
  int get_vbatotg_low_stat_enum_int(bool read_from_i2c);
  const char* get_vbatotg_low_stat_enum_string(bool read_from_i2c);

  // TS_COLD_STAT - The TS temperature is in the cold range
  uint16_t get_ts_cold_stat_raw(bool read_from_i2c);

  bool get_ts_cold_stat_bool(bool read_from_i2c);
  int get_ts_cold_stat_enum_int(bool read_from_i2c);
  const char* get_ts_cold_stat_enum_string(bool read_from_i2c);

  // TS_COOL_STAT - The TS temperature is in the cool range
  uint16_t get_ts_cool_stat_raw(bool read_from_i2c);

  bool get_ts_cool_stat_bool(bool read_from_i2c);
  int get_ts_cool_stat_enum_int(bool read_from_i2c);
  const char* get_ts_cool_stat_enum_string(bool read_from_i2c);

  // TS_WARM_STAT - The TS temperature is in the warm range
  uint16_t get_ts_warm_stat_raw(bool read_from_i2c);

  bool get_ts_warm_stat_bool(bool read_from_i2c);
  int get_ts_warm_stat_enum_int(bool read_from_i2c);
  const char* get_ts_warm_stat_enum_string(bool read_from_i2c);

  // TS_HOT_STAT - The TS temperature is in the hot range
  uint16_t get_ts_hot_stat_raw(bool read_from_i2c);

  bool get_ts_hot_stat_bool(bool read_from_i2c);
  int get_ts_hot_stat_enum_int(bool read_from_i2c);
  const char* get_ts_hot_stat_enum_string(bool read_from_i2c);

  // IBAT_REG_STAT - In battery discharging current regulation
  uint16_t get_ibat_reg_stat_raw(bool read_from_i2c);

  bool get_ibat_reg_stat_bool(bool read_from_i2c);

  // VBUS_OVP_STAT - VBUS over-voltage status
  uint16_t get_vbus_ovp_stat_raw(bool read_from_i2c);

  bool get_vbus_ovp_stat_bool(bool read_from_i2c);

  // VBAT_OVP_STAT - VBAT over-voltage status
  uint16_t get_vbat_ovp_stat_raw(bool read_from_i2c);

  bool get_vbat_ovp_stat_bool(bool read_from_i2c);

  // IBUS_OCP_STAT - IBUS over-current status
  uint16_t get_ibus_ocp_stat_raw(bool read_from_i2c);

  bool get_ibus_ocp_stat_bool(bool read_from_i2c);

  // IBAT_OCP_STAT - IBAT over-current status
  uint16_t get_ibat_ocp_stat_raw(bool read_from_i2c);

  bool get_ibat_ocp_stat_bool(bool read_from_i2c);

  // CONV_OCP_STAT - Converter over-current status
  uint16_t get_conv_ocp_stat_raw(bool read_from_i2c);

  bool get_conv_ocp_stat_bool(bool read_from_i2c);

  // VAC2_OVP_STAT - VAC2 over-voltage status
  uint16_t get_vac2_ovp_stat_raw(bool read_from_i2c);

  bool get_vac2_ovp_stat_bool(bool read_from_i2c);

  // VAC1_OVP_STAT - VAC1 over-voltage status
  uint16_t get_vac1_ovp_stat_raw(bool read_from_i2c);

  bool get_vac1_ovp_stat_bool(bool read_from_i2c);

  // VSYS_SHORT_STAT - VSYS short circuit status
  uint16_t get_vsys_short_stat_raw(bool read_from_i2c);

  bool get_vsys_short_stat_bool(bool read_from_i2c);

  // VSYS_OVP_STAT - VSYS over-voltage status
  uint16_t get_vsys_ovp_stat_raw(bool read_from_i2c);

  bool get_vsys_ovp_stat_bool(bool read_from_i2c);

  // OTG_OVP_STAT - OTG over-voltage status
  uint16_t get_otg_ovp_stat_raw(bool read_from_i2c);

  bool get_otg_ovp_stat_bool(bool read_from_i2c);

  // OTG_UVP_STAT - OTG under-voltage status
  uint16_t get_otg_uvp_stat_raw(bool read_from_i2c);

  bool get_otg_uvp_stat_bool(bool read_from_i2c);

  // TSHUT_STAT - IC thermal shutdown status
  uint16_t get_tshut_stat_raw(bool read_from_i2c);

  bool get_tshut_stat_bool(bool read_from_i2c);

  // IINDPM_FLAG - In IINDPM / IOTG regulation
  uint16_t get_iindpm_flag_raw(bool read_from_i2c);

  bool get_iindpm_flag_bool(bool read_from_i2c);
  void clear_flag_iindpm_flag() { this->last_iindpm_flag_raw_ = 0; }
  void raise_flag_iindpm_flag() { this->last_iindpm_flag_raw_ = 1; }

  // VINDPM_FLAG - In VINDPM / VOTG regulation
  uint16_t get_vindpm_flag_raw(bool read_from_i2c);

  bool get_vindpm_flag_bool(bool read_from_i2c);
  void clear_flag_vindpm_flag() { this->last_vindpm_flag_raw_ = 0; }
  void raise_flag_vindpm_flag() { this->last_vindpm_flag_raw_ = 1; }

  // WD_FLAG - Watchdog timer expired
  uint16_t get_wd_flag_raw(bool read_from_i2c);

  bool get_wd_flag_bool(bool read_from_i2c);
  void clear_flag_wd_flag() { this->last_wd_flag_raw_ = 0; }
  void raise_flag_wd_flag() { this->last_wd_flag_raw_ = 1; }

  // POORSRC_FLAG - Poor source detected
  uint16_t get_poorsrc_flag_raw(bool read_from_i2c);

  bool get_poorsrc_flag_bool(bool read_from_i2c);
  void clear_flag_poorsrc_flag() { this->last_poorsrc_flag_raw_ = 0; }
  void raise_flag_poorsrc_flag() { this->last_poorsrc_flag_raw_ = 1; }

  // PG_FLAG - Power status changed
  uint16_t get_pg_flag_raw(bool read_from_i2c);

  bool get_pg_flag_bool(bool read_from_i2c);
  void clear_flag_pg_flag() { this->last_pg_flag_raw_ = 0; }
  void raise_flag_pg_flag() { this->last_pg_flag_raw_ = 1; }

  // AC2_PRESENT_FLAG - AC2 present status changed
  uint16_t get_ac2_present_flag_raw(bool read_from_i2c);

  bool get_ac2_present_flag_bool(bool read_from_i2c);
  void clear_flag_ac2_present_flag() { this->last_ac2_present_flag_raw_ = 0; }
  void raise_flag_ac2_present_flag() { this->last_ac2_present_flag_raw_ = 1; }

  // AC1_PRESENT_FLAG - AC1 present status changed
  uint16_t get_ac1_present_flag_raw(bool read_from_i2c);

  bool get_ac1_present_flag_bool(bool read_from_i2c);
  void clear_flag_ac1_present_flag() { this->last_ac1_present_flag_raw_ = 0; }
  void raise_flag_ac1_present_flag() { this->last_ac1_present_flag_raw_ = 1; }

  // VBUS_PRESENT_FLAG - VBUS present status changed
  uint16_t get_vbus_present_flag_raw(bool read_from_i2c);

  bool get_vbus_present_flag_bool(bool read_from_i2c);
  void clear_flag_vbus_present_flag() { this->last_vbus_present_flag_raw_ = 0; }
  void raise_flag_vbus_present_flag() { this->last_vbus_present_flag_raw_ = 1; }

  // CHG_FLAG - Charging status changed
  uint16_t get_chg_flag_raw(bool read_from_i2c);

  bool get_chg_flag_bool(bool read_from_i2c);
  void clear_flag_chg_flag() { this->last_chg_flag_raw_ = 0; }
  void raise_flag_chg_flag() { this->last_chg_flag_raw_ = 1; }

  // ICO_FLAG - ICO status changed
  uint16_t get_ico_flag_raw(bool read_from_i2c);

  bool get_ico_flag_bool(bool read_from_i2c);
  void clear_flag_ico_flag() { this->last_ico_flag_raw_ = 0; }
  void raise_flag_ico_flag() { this->last_ico_flag_raw_ = 1; }

  // VBUS_FLAG - VBUS status changed
  uint16_t get_vbus_flag_raw(bool read_from_i2c);

  bool get_vbus_flag_bool(bool read_from_i2c);
  void clear_flag_vbus_flag() { this->last_vbus_flag_raw_ = 0; }
  void raise_flag_vbus_flag() { this->last_vbus_flag_raw_ = 1; }

  // TREG_FLAG - TREG signal rising threshold detected
  uint16_t get_treg_flag_raw(bool read_from_i2c);

  bool get_treg_flag_bool(bool read_from_i2c);
  void clear_flag_treg_flag() { this->last_treg_flag_raw_ = 0; }
  void raise_flag_treg_flag() { this->last_treg_flag_raw_ = 1; }

  // VBAT_PRESENT_FLAG - Battery present status changed
  uint16_t get_vbat_present_flag_raw(bool read_from_i2c);

  bool get_vbat_present_flag_bool(bool read_from_i2c);
  void clear_flag_vbat_present_flag() { this->last_vbat_present_flag_raw_ = 0; }
  void raise_flag_vbat_present_flag() { this->last_vbat_present_flag_raw_ = 1; }

  // BC1_2_DONE_FLAG - BC1.2 detection status changed
  uint16_t get_bc1_2_done_flag_raw(bool read_from_i2c);

  bool get_bc1_2_done_flag_bool(bool read_from_i2c);
  void clear_flag_bc1_2_done_flag() { this->last_bc1_2_done_flag_raw_ = 0; }
  void raise_flag_bc1_2_done_flag() { this->last_bc1_2_done_flag_raw_ = 1; }

  // DPDM_DONE_FLAG - D+/D- detection is completed
  uint16_t get_dpdm_done_flag_raw(bool read_from_i2c);

  bool get_dpdm_done_flag_bool(bool read_from_i2c);
  void clear_flag_dpdm_done_flag() { this->last_dpdm_done_flag_raw_ = 0; }
  void raise_flag_dpdm_done_flag() { this->last_dpdm_done_flag_raw_ = 1; }

  // ADC_DONE_FLAG - ADC conversion is completed
  uint16_t get_adc_done_flag_raw(bool read_from_i2c);

  bool get_adc_done_flag_bool(bool read_from_i2c);
  void clear_flag_adc_done_flag() { this->last_adc_done_flag_raw_ = 0; }
  void raise_flag_adc_done_flag() { this->last_adc_done_flag_raw_ = 1; }

  // VSYS_FLAG - Entered or existed VSYSMIN regulation
  uint16_t get_vsys_flag_raw(bool read_from_i2c);

  bool get_vsys_flag_bool(bool read_from_i2c);
  void clear_flag_vsys_flag() { this->last_vsys_flag_raw_ = 0; }
  void raise_flag_vsys_flag() { this->last_vsys_flag_raw_ = 1; }

  // CHG_TMR_FLAG - Fast charge timer expired rising edge detected
  uint16_t get_chg_tmr_flag_raw(bool read_from_i2c);

  bool get_chg_tmr_flag_bool(bool read_from_i2c);
  void clear_flag_chg_tmr_flag() { this->last_chg_tmr_flag_raw_ = 0; }
  void raise_flag_chg_tmr_flag() { this->last_chg_tmr_flag_raw_ = 1; }

  // TRICHG_TMR_FLAG - Trickle charge timer expired rising edge detected
  uint16_t get_trichg_tmr_flag_raw(bool read_from_i2c);

  bool get_trichg_tmr_flag_bool(bool read_from_i2c);
  void clear_flag_trichg_tmr_flag() { this->last_trichg_tmr_flag_raw_ = 0; }
  void raise_flag_trichg_tmr_flag() { this->last_trichg_tmr_flag_raw_ = 1; }

  // PRECHG_TMR_FLAG - Pre-charge timer expired rising edge detected
  uint16_t get_prechg_tmr_flag_raw(bool read_from_i2c);

  bool get_prechg_tmr_flag_bool(bool read_from_i2c);
  void clear_flag_prechg_tmr_flag() { this->last_prechg_tmr_flag_raw_ = 0; }
  void raise_flag_prechg_tmr_flag() { this->last_prechg_tmr_flag_raw_ = 1; }

  // TOPOFF_TMR_FLAG - Top-off timer expired rising edge detected
  uint16_t get_topoff_tmr_flag_raw(bool read_from_i2c);

  bool get_topoff_tmr_flag_bool(bool read_from_i2c);
  void clear_flag_topoff_tmr_flag() { this->last_topoff_tmr_flag_raw_ = 0; }
  void raise_flag_topoff_tmr_flag() { this->last_topoff_tmr_flag_raw_ = 1; }

  // VBATOTG_LOW_FLAG - VBAT falls below the threshold to enable the OTG mode
  uint16_t get_vbatotg_low_flag_raw(bool read_from_i2c);

  bool get_vbatotg_low_flag_bool(bool read_from_i2c);
  void clear_flag_vbatotg_low_flag() { this->last_vbatotg_low_flag_raw_ = 0; }
  void raise_flag_vbatotg_low_flag() { this->last_vbatotg_low_flag_raw_ = 1; }

  // TS_COLD_FLAG - TS across cold temperature (T1) is detected
  uint16_t get_ts_cold_flag_raw(bool read_from_i2c);

  bool get_ts_cold_flag_bool(bool read_from_i2c);
  void clear_flag_ts_cold_flag() { this->last_ts_cold_flag_raw_ = 0; }
  void raise_flag_ts_cold_flag() { this->last_ts_cold_flag_raw_ = 1; }

  // TS_COOL_FLAG - TS across cool temperature (T2) is detected
  uint16_t get_ts_cool_flag_raw(bool read_from_i2c);

  bool get_ts_cool_flag_bool(bool read_from_i2c);
  void clear_flag_ts_cool_flag() { this->last_ts_cool_flag_raw_ = 0; }
  void raise_flag_ts_cool_flag() { this->last_ts_cool_flag_raw_ = 1; }

  // TS_WARM_FLAG - TS across warm temperature (T3) is detected
  uint16_t get_ts_warm_flag_raw(bool read_from_i2c);

  bool get_ts_warm_flag_bool(bool read_from_i2c);
  void clear_flag_ts_warm_flag() { this->last_ts_warm_flag_raw_ = 0; }
  void raise_flag_ts_warm_flag() { this->last_ts_warm_flag_raw_ = 1; }

  // TS_HOT_FLAG - TS across hot temperature (T5) is detected
  uint16_t get_ts_hot_flag_raw(bool read_from_i2c);

  bool get_ts_hot_flag_bool(bool read_from_i2c);
  void clear_flag_ts_hot_flag() { this->last_ts_hot_flag_raw_ = 0; }
  void raise_flag_ts_hot_flag() { this->last_ts_hot_flag_raw_ = 1; }

  // IBAT_REG_FLAG - Enter or exit IBAT regulation
  uint16_t get_ibat_reg_flag_raw(bool read_from_i2c);

  bool get_ibat_reg_flag_bool(bool read_from_i2c);
  void clear_flag_ibat_reg_flag() { this->last_ibat_reg_flag_raw_ = 0; }
  void raise_flag_ibat_reg_flag() { this->last_ibat_reg_flag_raw_ = 1; }

  // VBUS_OVP_FLAG - Enter VBUS OVP
  uint16_t get_vbus_ovp_flag_raw(bool read_from_i2c);

  bool get_vbus_ovp_flag_bool(bool read_from_i2c);
  void clear_flag_vbus_ovp_flag() { this->last_vbus_ovp_flag_raw_ = 0; }
  void raise_flag_vbus_ovp_flag() { this->last_vbus_ovp_flag_raw_ = 1; }

  // VBAT_OVP_FLAG - Enter VBAT OVP
  uint16_t get_vbat_ovp_flag_raw(bool read_from_i2c);

  bool get_vbat_ovp_flag_bool(bool read_from_i2c);
  void clear_flag_vbat_ovp_flag() { this->last_vbat_ovp_flag_raw_ = 0; }
  void raise_flag_vbat_ovp_flag() { this->last_vbat_ovp_flag_raw_ = 1; }

  // IBUS_OCP_FLAG - Enter IBUS OCP
  uint16_t get_ibus_ocp_flag_raw(bool read_from_i2c);

  bool get_ibus_ocp_flag_bool(bool read_from_i2c);
  void clear_flag_ibus_ocp_flag() { this->last_ibus_ocp_flag_raw_ = 0; }
  void raise_flag_ibus_ocp_flag() { this->last_ibus_ocp_flag_raw_ = 1; }

  // IBAT_OCP_FLAG - Enter discharged OCP
  uint16_t get_ibat_ocp_flag_raw(bool read_from_i2c);

  bool get_ibat_ocp_flag_bool(bool read_from_i2c);
  void clear_flag_ibat_ocp_flag() { this->last_ibat_ocp_flag_raw_ = 0; }
  void raise_flag_ibat_ocp_flag() { this->last_ibat_ocp_flag_raw_ = 1; }

  // CONV_OCP_FLAG - Enter converter OCP
  uint16_t get_conv_ocp_flag_raw(bool read_from_i2c);

  bool get_conv_ocp_flag_bool(bool read_from_i2c);
  void clear_flag_conv_ocp_flag() { this->last_conv_ocp_flag_raw_ = 0; }
  void raise_flag_conv_ocp_flag() { this->last_conv_ocp_flag_raw_ = 1; }

  // VAC2_OVP_FLAG - Enter VAC2 OVP
  uint16_t get_vac2_ovp_flag_raw(bool read_from_i2c);

  bool get_vac2_ovp_flag_bool(bool read_from_i2c);
  void clear_flag_vac2_ovp_flag() { this->last_vac2_ovp_flag_raw_ = 0; }
  void raise_flag_vac2_ovp_flag() { this->last_vac2_ovp_flag_raw_ = 1; }

  // VAC1_OVP_FLAG - Enter VAC1 OVP
  uint16_t get_vac1_ovp_flag_raw(bool read_from_i2c);

  bool get_vac1_ovp_flag_bool(bool read_from_i2c);
  void clear_flag_vac1_ovp_flag() { this->last_vac1_ovp_flag_raw_ = 0; }
  void raise_flag_vac1_ovp_flag() { this->last_vac1_ovp_flag_raw_ = 1; }

  // VSYS_SHORT_FLAG - Stop switching due to system short
  uint16_t get_vsys_short_flag_raw(bool read_from_i2c);

  bool get_vsys_short_flag_bool(bool read_from_i2c);
  void clear_flag_vsys_short_flag() { this->last_vsys_short_flag_raw_ = 0; }
  void raise_flag_vsys_short_flag() { this->last_vsys_short_flag_raw_ = 1; }

  // VSYS_OVP_FLAG - Stop switching due to system over-voltage
  uint16_t get_vsys_ovp_flag_raw(bool read_from_i2c);

  bool get_vsys_ovp_flag_bool(bool read_from_i2c);
  void clear_flag_vsys_ovp_flag() { this->last_vsys_ovp_flag_raw_ = 0; }
  void raise_flag_vsys_ovp_flag() { this->last_vsys_ovp_flag_raw_ = 1; }

  // OTG_OVP_FLAG - Stop OTG due to VBUS over voltage
  uint16_t get_otg_ovp_flag_raw(bool read_from_i2c);

  bool get_otg_ovp_flag_bool(bool read_from_i2c);
  void clear_flag_otg_ovp_flag() { this->last_otg_ovp_flag_raw_ = 0; }
  void raise_flag_otg_ovp_flag() { this->last_otg_ovp_flag_raw_ = 1; }

  // OTG_UVP_FLAG - Stop OTG due to VBUS under voltage
  uint16_t get_otg_uvp_flag_raw(bool read_from_i2c);

  bool get_otg_uvp_flag_bool(bool read_from_i2c);
  void clear_flag_otg_uvp_flag() { this->last_otg_uvp_flag_raw_ = 0; }
  void raise_flag_otg_uvp_flag() { this->last_otg_uvp_flag_raw_ = 1; }

  // TSHUT_FLAG - TS shutdown signal rising threshold detected
  uint16_t get_tshut_flag_raw(bool read_from_i2c);

  bool get_tshut_flag_bool(bool read_from_i2c);
  void clear_flag_tshut_flag() { this->last_tshut_flag_raw_ = 0; }
  void raise_flag_tshut_flag() { this->last_tshut_flag_raw_ = 1; }

  // ADC_EN - ADC enable
  uint16_t get_adc_en_raw(bool read_from_i2c);
  void set_adc_en_raw(uint16_t value, bool write_to_i2c);

  bool get_adc_en_bool(bool read_from_i2c);
  void set_adc_en_bool(bool value, bool write_to_i2c);

  // ADC_RATE - ADC conversion rate
  uint16_t get_adc_rate_raw(bool read_from_i2c);
  void set_adc_rate_raw(uint16_t value, bool write_to_i2c);

  bool get_adc_rate_bool(bool read_from_i2c);
  void set_adc_rate_bool(bool value, bool write_to_i2c);
  int get_adc_rate_enum_int(bool read_from_i2c);
  const char* get_adc_rate_enum_string(bool read_from_i2c);
  void set_adc_rate_enum_int(int value, bool write_to_i2c);

  // ADC_SAMPLE - ADC sample speed
  uint16_t get_adc_sample_raw(bool read_from_i2c);
  void set_adc_sample_raw(uint16_t value, bool write_to_i2c);

  int get_adc_sample_enum_int(bool read_from_i2c);
  const char* get_adc_sample_enum_string(bool read_from_i2c);
  void set_adc_sample_enum_int(int value, bool write_to_i2c);

  // ADC_AVG - ADC averaging
  uint16_t get_adc_avg_raw(bool read_from_i2c);
  void set_adc_avg_raw(uint16_t value, bool write_to_i2c);

  bool get_adc_avg_bool(bool read_from_i2c);
  void set_adc_avg_bool(bool value, bool write_to_i2c);
  int get_adc_avg_enum_int(bool read_from_i2c);
  const char* get_adc_avg_enum_string(bool read_from_i2c);
  void set_adc_avg_enum_int(int value, bool write_to_i2c);

  // ADC_AVG_INIT - ADC average initialization
  uint16_t get_adc_avg_init_raw(bool read_from_i2c);
  void set_adc_avg_init_raw(uint16_t value, bool write_to_i2c);

  bool get_adc_avg_init_bool(bool read_from_i2c);
  void set_adc_avg_init_bool(bool value, bool write_to_i2c);

  // IBUS_ADC_DIS - IBUS ADC disable
  uint16_t get_ibus_adc_dis_raw(bool read_from_i2c);
  void set_ibus_adc_dis_raw(uint16_t value, bool write_to_i2c);

  bool get_ibus_adc_dis_bool(bool read_from_i2c);
  void set_ibus_adc_dis_bool(bool value, bool write_to_i2c);

  // IBAT_ADC_DIS - IBAT ADC disable
  uint16_t get_ibat_adc_dis_raw(bool read_from_i2c);
  void set_ibat_adc_dis_raw(uint16_t value, bool write_to_i2c);

  bool get_ibat_adc_dis_bool(bool read_from_i2c);
  void set_ibat_adc_dis_bool(bool value, bool write_to_i2c);

  // VBUS_ADC_DIS - VBUS ADC disable
  uint16_t get_vbus_adc_dis_raw(bool read_from_i2c);
  void set_vbus_adc_dis_raw(uint16_t value, bool write_to_i2c);

  bool get_vbus_adc_dis_bool(bool read_from_i2c);
  void set_vbus_adc_dis_bool(bool value, bool write_to_i2c);

  // VBAT_ADC_DIS - VBAT ADC disable
  uint16_t get_vbat_adc_dis_raw(bool read_from_i2c);
  void set_vbat_adc_dis_raw(uint16_t value, bool write_to_i2c);

  bool get_vbat_adc_dis_bool(bool read_from_i2c);
  void set_vbat_adc_dis_bool(bool value, bool write_to_i2c);

  // VSYS_ADC_DIS - VSYS ADC disable
  uint16_t get_vsys_adc_dis_raw(bool read_from_i2c);
  void set_vsys_adc_dis_raw(uint16_t value, bool write_to_i2c);

  bool get_vsys_adc_dis_bool(bool read_from_i2c);
  void set_vsys_adc_dis_bool(bool value, bool write_to_i2c);

  // TS_ADC_DIS - TS ADC disable
  uint16_t get_ts_adc_dis_raw(bool read_from_i2c);
  void set_ts_adc_dis_raw(uint16_t value, bool write_to_i2c);

  bool get_ts_adc_dis_bool(bool read_from_i2c);
  void set_ts_adc_dis_bool(bool value, bool write_to_i2c);

  // TDIE_ADC_DIS - TDIE ADC disable
  uint16_t get_tdie_adc_dis_raw(bool read_from_i2c);
  void set_tdie_adc_dis_raw(uint16_t value, bool write_to_i2c);

  bool get_tdie_adc_dis_bool(bool read_from_i2c);
  void set_tdie_adc_dis_bool(bool value, bool write_to_i2c);

  // DPLUS_ADC_DIS - D+ ADC disable
  uint16_t get_dplus_adc_dis_raw(bool read_from_i2c);
  void set_dplus_adc_dis_raw(uint16_t value, bool write_to_i2c);

  bool get_dplus_adc_dis_bool(bool read_from_i2c);
  void set_dplus_adc_dis_bool(bool value, bool write_to_i2c);

  // DMINUS_ADC_DIS - D- ADC disable
  uint16_t get_dminus_adc_dis_raw(bool read_from_i2c);
  void set_dminus_adc_dis_raw(uint16_t value, bool write_to_i2c);

  bool get_dminus_adc_dis_bool(bool read_from_i2c);
  void set_dminus_adc_dis_bool(bool value, bool write_to_i2c);

  // VAC2_ADC_DIS - VAC2 ADC disable
  uint16_t get_vac2_adc_dis_raw(bool read_from_i2c);
  void set_vac2_adc_dis_raw(uint16_t value, bool write_to_i2c);

  bool get_vac2_adc_dis_bool(bool read_from_i2c);
  void set_vac2_adc_dis_bool(bool value, bool write_to_i2c);

  // VAC1_ADC_DIS - VAC1 ADC disable
  uint16_t get_vac1_adc_dis_raw(bool read_from_i2c);
  void set_vac1_adc_dis_raw(uint16_t value, bool write_to_i2c);

  bool get_vac1_adc_dis_bool(bool read_from_i2c);
  void set_vac1_adc_dis_bool(bool value, bool write_to_i2c);

  // IBUS_ADC - IBUS ADC reading
  uint16_t get_ibus_adc_raw(bool read_from_i2c);

  int get_ibus_adc_int(bool read_from_i2c);

  // IBAT_ADC - IBAT ADC reading
  uint16_t get_ibat_adc_raw(bool read_from_i2c);

  int get_ibat_adc_int(bool read_from_i2c);

  // VBUS_ADC - VBUS ADC reading
  uint16_t get_vbus_adc_raw(bool read_from_i2c);

  int get_vbus_adc_int(bool read_from_i2c);

  // VAC1_ADC - VAC1 ADC reading
  uint16_t get_vac1_adc_raw(bool read_from_i2c);

  int get_vac1_adc_int(bool read_from_i2c);

  // VAC2_ADC - VAC2 ADC reading
  uint16_t get_vac2_adc_raw(bool read_from_i2c);

  int get_vac2_adc_int(bool read_from_i2c);

  // VBAT_ADC - VBAT ADC reading
  uint16_t get_vbat_adc_raw(bool read_from_i2c);

  int get_vbat_adc_int(bool read_from_i2c);

  // VSYS_ADC - VSYS ADC reading
  uint16_t get_vsys_adc_raw(bool read_from_i2c);

  int get_vsys_adc_int(bool read_from_i2c);

  // TS_ADC - TS ADC reading
  uint16_t get_ts_adc_raw(bool read_from_i2c);

  float get_ts_adc_float(bool read_from_i2c);

  // TDIE_ADC - TDIE ADC reading
  uint16_t get_tdie_adc_raw(bool read_from_i2c);

  float get_tdie_adc_float(bool read_from_i2c);

  // DPLUS_ADC - D+ ADC reading
  uint16_t get_dplus_adc_raw(bool read_from_i2c);

  int get_dplus_adc_int(bool read_from_i2c);

  // DMINUS_ADC - D- ADC reading
  uint16_t get_dminus_adc_raw(bool read_from_i2c);

  int get_dminus_adc_int(bool read_from_i2c);

  // DPLUS_DAC - D+ Output Driver
  uint16_t get_dplus_dac_raw(bool read_from_i2c);
  void set_dplus_dac_raw(uint16_t value, bool write_to_i2c);

  int get_dplus_dac_enum_int(bool read_from_i2c);
  const char* get_dplus_dac_enum_string(bool read_from_i2c);
  void set_dplus_dac_enum_int(int value, bool write_to_i2c);

  // DMINUS_DAC - D- Output Driver
  uint16_t get_dminus_dac_raw(bool read_from_i2c);
  void set_dminus_dac_raw(uint16_t value, bool write_to_i2c);

  int get_dminus_dac_enum_int(bool read_from_i2c);
  const char* get_dminus_dac_enum_string(bool read_from_i2c);
  void set_dminus_dac_enum_int(int value, bool write_to_i2c);

  // PN - Part number
  uint16_t get_pn_raw(bool read_from_i2c);

  int get_pn_enum_int(bool read_from_i2c);
  const char* get_pn_enum_string(bool read_from_i2c);

  // DEV_REV - Device revision
  uint16_t get_dev_rev_raw(bool read_from_i2c);

  int get_dev_rev_enum_int(bool read_from_i2c);
  const char* get_dev_rev_enum_string(bool read_from_i2c);

protected:
  uint16_t last_vsysmin_raw_ = 0;
  uint16_t last_vreg_raw_ = 0;
  uint16_t last_ichg_raw_ = 0;
  uint16_t last_vindpm_raw_ = 0;
  uint16_t last_iindpm_raw_ = 0;
  uint16_t last_vbat_lowv_raw_ = 0;
  uint16_t last_iprechg_raw_ = 0;
  uint16_t last_reg_rst_raw_ = 0;
  uint16_t last_stop_wd_chg_raw_ = 0;
  uint16_t last_iterm_raw_ = 0;
  uint16_t last_cell_raw_ = 0;
  uint16_t last_trechg_raw_ = 0;
  uint16_t last_vrechg_raw_ = 0;
  uint16_t last_votg_raw_ = 0;
  uint16_t last_prechg_tmr_raw_ = 0;
  uint16_t last_iotg_raw_ = 0;
  uint16_t last_topoff_tmr_raw_ = 0;
  uint16_t last_en_trichg_tmr_raw_ = 0;
  uint16_t last_en_prechg_tmr_raw_ = 0;
  uint16_t last_en_chg_tmr_raw_ = 0;
  uint16_t last_chg_tmr_raw_ = 0;
  uint16_t last_tmr2x_en_raw_ = 0;
  uint16_t last_en_auto_ibatdis_raw_ = 0;
  uint16_t last_force_ibatdis_raw_ = 0;
  uint16_t last_en_chg_raw_ = 0;
  uint16_t last_en_ico_raw_ = 0;
  uint16_t last_force_ico_raw_ = 0;
  uint16_t last_en_hiz_raw_ = 0;
  uint16_t last_en_term_raw_ = 0;
  uint16_t last_en_backup_raw_ = 0;
  uint16_t last_vbus_backup_raw_ = 0;
  uint16_t last_vac_ovp_raw_ = 0;
  uint16_t last_wd_rst_raw_ = 0;
  uint16_t last_watchdog_raw_ = 0;
  uint16_t last_force_indet_raw_ = 0;
  uint16_t last_auto_indet_en_raw_ = 0;
  uint16_t last_en_12v_raw_ = 0;
  uint16_t last_en_9v_raw_ = 0;
  uint16_t last_hvdcp_en_raw_ = 0;
  uint16_t last_sdrv_ctrl_raw_ = 0;
  uint16_t last_sdrv_dly_raw_ = 0;
  uint16_t last_dis_acdrv_raw_ = 0;
  uint16_t last_en_otg_raw_ = 0;
  uint16_t last_pfm_otg_dis_raw_ = 0;
  uint16_t last_pfm_fwd_dis_raw_ = 0;
  uint16_t last_wkup_dly_raw_ = 0;
  uint16_t last_dis_ldo_raw_ = 0;
  uint16_t last_dis_otg_ooa_raw_ = 0;
  uint16_t last_dis_fwd_ooa_raw_ = 0;
  uint16_t last_en_acdrv2_raw_ = 0;
  uint16_t last_en_acdrv1_raw_ = 0;
  uint16_t last_pwm_freq_raw_ = 0;
  uint16_t last_dis_stat_raw_ = 0;
  uint16_t last_dis_vsys_short_raw_ = 0;
  uint16_t last_dis_votg_uvp_raw_ = 0;
  uint16_t last_force_vindpm_det_raw_ = 0;
  uint16_t last_en_ibus_ocp_raw_ = 0;
  uint16_t last_sfet_present_raw_ = 0;
  uint16_t last_en_ibat_raw_ = 0;
  uint16_t last_ibat_reg_raw_ = 0;
  uint16_t last_en_iindpm_raw_ = 0;
  uint16_t last_en_extilim_raw_ = 0;
  uint16_t last_en_batoc_raw_ = 0;
  uint16_t last_voc_pct_raw_ = 0;
  uint16_t last_voc_dly_raw_ = 0;
  uint16_t last_voc_rate_raw_ = 0;
  uint16_t last_en_mppt_raw_ = 0;
  uint16_t last_treg_raw_ = 0;
  uint16_t last_tshut_raw_ = 0;
  uint16_t last_vbus_pd_en_raw_ = 0;
  uint16_t last_vac1_pd_en_raw_ = 0;
  uint16_t last_vac2_pd_en_raw_ = 0;
  uint16_t last_bkup_acfet1_on_raw_ = 0;
  uint16_t last_jeita_vset_raw_ = 0;
  uint16_t last_jeita_iseth_raw_ = 0;
  uint16_t last_jeita_isetc_raw_ = 0;
  uint16_t last_ts_cool_raw_ = 0;
  uint16_t last_ts_warm_raw_ = 0;
  uint16_t last_bhot_raw_ = 0;
  uint16_t last_bcold_raw_ = 0;
  uint16_t last_ts_ignore_raw_ = 0;
  uint16_t last_ico_ilim_raw_ = 0;
  uint16_t last_iindpm_stat_raw_ = 0;
  uint16_t last_vindpm_stat_raw_ = 0;
  uint16_t last_wd_stat_raw_ = 0;
  uint16_t last_pg_stat_raw_ = 0;
  uint16_t last_ac2_present_stat_raw_ = 0;
  uint16_t last_ac1_present_stat_raw_ = 0;
  uint16_t last_vbus_present_stat_raw_ = 0;
  uint16_t last_chg_stat_raw_ = 0;
  uint16_t last_vbus_stat_raw_ = 0;
  uint16_t last_bc12_done_stat_raw_ = 0;
  uint16_t last_ico_stat_raw_ = 0;
  uint16_t last_treg_stat_raw_ = 0;
  uint16_t last_dpdm_stat_raw_ = 0;
  uint16_t last_vbat_present_stat_raw_ = 0;
  uint16_t last_acrb2_stat_raw_ = 0;
  uint16_t last_acrb1_stat_raw_ = 0;
  uint16_t last_adc_done_stat_raw_ = 0;
  uint16_t last_vsys_stat_raw_ = 0;
  uint16_t last_chg_tmr_stat_raw_ = 0;
  uint16_t last_trichg_tmr_stat_raw_ = 0;
  uint16_t last_prechg_tmr_stat_raw_ = 0;
  uint16_t last_vbatotg_low_stat_raw_ = 0;
  uint16_t last_ts_cold_stat_raw_ = 0;
  uint16_t last_ts_cool_stat_raw_ = 0;
  uint16_t last_ts_warm_stat_raw_ = 0;
  uint16_t last_ts_hot_stat_raw_ = 0;
  uint16_t last_ibat_reg_stat_raw_ = 0;
  uint16_t last_vbus_ovp_stat_raw_ = 0;
  uint16_t last_vbat_ovp_stat_raw_ = 0;
  uint16_t last_ibus_ocp_stat_raw_ = 0;
  uint16_t last_ibat_ocp_stat_raw_ = 0;
  uint16_t last_conv_ocp_stat_raw_ = 0;
  uint16_t last_vac2_ovp_stat_raw_ = 0;
  uint16_t last_vac1_ovp_stat_raw_ = 0;
  uint16_t last_vsys_short_stat_raw_ = 0;
  uint16_t last_vsys_ovp_stat_raw_ = 0;
  uint16_t last_otg_ovp_stat_raw_ = 0;
  uint16_t last_otg_uvp_stat_raw_ = 0;
  uint16_t last_tshut_stat_raw_ = 0;
  uint16_t last_iindpm_flag_raw_ = 0;
  uint16_t last_vindpm_flag_raw_ = 0;
  uint16_t last_wd_flag_raw_ = 0;
  uint16_t last_poorsrc_flag_raw_ = 0;
  uint16_t last_pg_flag_raw_ = 0;
  uint16_t last_ac2_present_flag_raw_ = 0;
  uint16_t last_ac1_present_flag_raw_ = 0;
  uint16_t last_vbus_present_flag_raw_ = 0;
  uint16_t last_chg_flag_raw_ = 0;
  uint16_t last_ico_flag_raw_ = 0;
  uint16_t last_vbus_flag_raw_ = 0;
  uint16_t last_treg_flag_raw_ = 0;
  uint16_t last_vbat_present_flag_raw_ = 0;
  uint16_t last_bc1_2_done_flag_raw_ = 0;
  uint16_t last_dpdm_done_flag_raw_ = 0;
  uint16_t last_adc_done_flag_raw_ = 0;
  uint16_t last_vsys_flag_raw_ = 0;
  uint16_t last_chg_tmr_flag_raw_ = 0;
  uint16_t last_trichg_tmr_flag_raw_ = 0;
  uint16_t last_prechg_tmr_flag_raw_ = 0;
  uint16_t last_topoff_tmr_flag_raw_ = 0;
  uint16_t last_vbatotg_low_flag_raw_ = 0;
  uint16_t last_ts_cold_flag_raw_ = 0;
  uint16_t last_ts_cool_flag_raw_ = 0;
  uint16_t last_ts_warm_flag_raw_ = 0;
  uint16_t last_ts_hot_flag_raw_ = 0;
  uint16_t last_ibat_reg_flag_raw_ = 0;
  uint16_t last_vbus_ovp_flag_raw_ = 0;
  uint16_t last_vbat_ovp_flag_raw_ = 0;
  uint16_t last_ibus_ocp_flag_raw_ = 0;
  uint16_t last_ibat_ocp_flag_raw_ = 0;
  uint16_t last_conv_ocp_flag_raw_ = 0;
  uint16_t last_vac2_ovp_flag_raw_ = 0;
  uint16_t last_vac1_ovp_flag_raw_ = 0;
  uint16_t last_vsys_short_flag_raw_ = 0;
  uint16_t last_vsys_ovp_flag_raw_ = 0;
  uint16_t last_otg_ovp_flag_raw_ = 0;
  uint16_t last_otg_uvp_flag_raw_ = 0;
  uint16_t last_tshut_flag_raw_ = 0;
  uint16_t last_adc_en_raw_ = 0;
  uint16_t last_adc_rate_raw_ = 0;
  uint16_t last_adc_sample_raw_ = 0;
  uint16_t last_adc_avg_raw_ = 0;
  uint16_t last_adc_avg_init_raw_ = 0;
  uint16_t last_ibus_adc_dis_raw_ = 0;
  uint16_t last_ibat_adc_dis_raw_ = 0;
  uint16_t last_vbus_adc_dis_raw_ = 0;
  uint16_t last_vbat_adc_dis_raw_ = 0;
  uint16_t last_vsys_adc_dis_raw_ = 0;
  uint16_t last_ts_adc_dis_raw_ = 0;
  uint16_t last_tdie_adc_dis_raw_ = 0;
  uint16_t last_dplus_adc_dis_raw_ = 0;
  uint16_t last_dminus_adc_dis_raw_ = 0;
  uint16_t last_vac2_adc_dis_raw_ = 0;
  uint16_t last_vac1_adc_dis_raw_ = 0;
  uint16_t last_ibus_adc_raw_ = 0;
  uint16_t last_ibat_adc_raw_ = 0;
  uint16_t last_vbus_adc_raw_ = 0;
  uint16_t last_vac1_adc_raw_ = 0;
  uint16_t last_vac2_adc_raw_ = 0;
  uint16_t last_vbat_adc_raw_ = 0;
  uint16_t last_vsys_adc_raw_ = 0;
  uint16_t last_ts_adc_raw_ = 0;
  uint16_t last_tdie_adc_raw_ = 0;
  uint16_t last_dplus_adc_raw_ = 0;
  uint16_t last_dminus_adc_raw_ = 0;
  uint16_t last_dplus_dac_raw_ = 0;
  uint16_t last_dminus_dac_raw_ = 0;
  uint16_t last_pn_raw_ = 0;
  uint16_t last_dev_rev_raw_ = 0;

  BQ25798NoI2C *bq25798_noi2c_ {nullptr};
};  // class BQ25798Component

}  // namespace bq25798
}  // namespace esphome