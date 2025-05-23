#pragma once

#include "esphome/components/switch/switch.h"
#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

#include "../bq25798_component.h"

namespace esphome {
namespace bq25798 {


// REG_RST - Reset registers to default values and reset timer
class BQ25798RegRstSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798RegRstSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// STOP_WD_CHG - Defines whether a watchdog timer expiration will disable charging
class BQ25798StopWdChgSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798StopWdChgSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// PRECHG_TMR - Pre-charge safety timer setting
class BQ25798PrechgTmrSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798PrechgTmrSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_TRICHG_TMR - Trickle charge timer enable
class BQ25798EnTrichgTmrSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnTrichgTmrSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_PRECHG_TMR - Precharge timer enable
class BQ25798EnPrechgTmrSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnPrechgTmrSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_CHG_TMR - Fast charge timer enable
class BQ25798EnChgTmrSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnChgTmrSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// TMR2X_EN - 2x slower charging in DPM enable
class BQ25798Tmr2xEnSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798Tmr2xEnSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_AUTO_IBATDIS - Enable the auto battery discharging during the battery OVP fault
class BQ25798EnAutoIbatdisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnAutoIbatdisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// FORCE_IBATDIS - Force the battery discharging current
class BQ25798ForceIbatdisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798ForceIbatdisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_CHG - Enable the charger
class BQ25798EnChgSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnChgSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_ICO - Enable the ICO (Input Current Optimizer)
class BQ25798EnIcoSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnIcoSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// FORCE_ICO - Force the ICO (Input Current Optimizer)
class BQ25798ForceIcoSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798ForceIcoSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_HIZ - Enable the high impedance mode
class BQ25798EnHizSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnHizSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_TERM - Enable the termination
class BQ25798EnTermSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnTermSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_BACKUP - Enable the backup (auto OTG) mode
class BQ25798EnBackupSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnBackupSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// WD_RST - I2C watch dog timer reset
class BQ25798WdRstSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798WdRstSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// FORCE_INDET - Force D+/D- detection
class BQ25798ForceIndetSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798ForceIndetSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// AUTO_INDET_EN - Enable automatic D+/D- detection
class BQ25798AutoIndetEnSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798AutoIndetEnSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_12V - Enable 12V output in HVDCP
class BQ25798En12vSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798En12vSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_9V - Enable 9V output in HVDCP
class BQ25798En9vSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798En9vSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// HVDCP_EN - Enable HVDCP (High Voltage Device Charging Protocol)
class BQ25798HvdcpEnSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798HvdcpEnSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// SDRV_DLY - Delay for SDRV control
class BQ25798SdrvDlySwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798SdrvDlySwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// DIS_ACDRV - Disable both AC1 and AC2 drivers
class BQ25798DisAcdrvSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798DisAcdrvSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_OTG - Enable OTG mode
class BQ25798EnOtgSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnOtgSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// PFM_OTG_DIS - Disable PFM in OTG mode
class BQ25798PfmOtgDisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798PfmOtgDisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// PFM_FWD_DIS - Disable PFM in forward mode
class BQ25798PfmFwdDisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798PfmFwdDisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// WKUP_DLY - Wakeup (Ship FET) delay
class BQ25798WkupDlySwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798WkupDlySwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// DIS_LDO - Disable BATFET LDO mode in precharge state
class BQ25798DisLdoSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798DisLdoSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// DIS_OTG_OOA - Disable OOA in OTG mode
class BQ25798DisOtgOoaSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798DisOtgOoaSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// DIS_FWD_OOA - Disable OOA in forward mode
class BQ25798DisFwdOoaSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798DisFwdOoaSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_ACDRV2 - Enable AC2 gate driver control
class BQ25798EnAcdrv2Switch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnAcdrv2Switch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_ACDRV1 - Enable AC1 gate driver control
class BQ25798EnAcdrv1Switch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnAcdrv1Switch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// PWM_FREQ - PWM frequency setting
class BQ25798PwmFreqSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798PwmFreqSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// DIS_STAT - Disable STAT pin output
class BQ25798DisStatSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798DisStatSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// DIS_VSYS_SHORT - Disable VSYS short hiccup protection
class BQ25798DisVsysShortSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798DisVsysShortSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// DIS_VOTG_UVP - Disable VOTG under voltage hiccup protection
class BQ25798DisVotgUvpSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798DisVotgUvpSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// FORCE_VINDPM_DET - Force VINDPM detection (settable only when VBAT>VSYSMIN)
class BQ25798ForceVindpmDetSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798ForceVindpmDetSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_IBUS_OCP - Enable input over current protection in forward mode
class BQ25798EnIbusOcpSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnIbusOcpSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// SFET_PRESENT - Ship FET present
class BQ25798SfetPresentSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798SfetPresentSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_IBAT - Enable battery discharge current sensing
class BQ25798EnIbatSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnIbatSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_IINDPM - Enable input current regulation
class BQ25798EnIindpmSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnIindpmSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_EXTILIM - Enable external ILIM_HIZ pin current regulation
class BQ25798EnExtilimSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnExtilimSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_BATOC - Enable battery discharging over current protection
class BQ25798EnBatocSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnBatocSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// EN_MPPT - 
class BQ25798EnMpptSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798EnMpptSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// VBUS_PD_EN - 
class BQ25798VbusPdEnSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VbusPdEnSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// VAC1_PD_EN - 
class BQ25798Vac1PdEnSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798Vac1PdEnSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// VAC2_PD_EN - 
class BQ25798Vac2PdEnSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798Vac2PdEnSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// BKUP_ACFET1_ON - 
class BQ25798BkupAcfet1OnSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798BkupAcfet1OnSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// BCOLD - 
class BQ25798BcoldSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798BcoldSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// TS_IGNORE - 
class BQ25798TsIgnoreSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TsIgnoreSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// ADC_EN - 
class BQ25798AdcEnSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798AdcEnSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// ADC_RATE - 
class BQ25798AdcRateSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798AdcRateSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// ADC_AVG - 
class BQ25798AdcAvgSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798AdcAvgSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// ADC_AVG_INIT - 
class BQ25798AdcAvgInitSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798AdcAvgInitSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// IBUS_ADC_DIS - 
class BQ25798IbusAdcDisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798IbusAdcDisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// IBAT_ADC_DIS - 
class BQ25798IbatAdcDisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798IbatAdcDisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// VBUS_ADC_DIS - 
class BQ25798VbusAdcDisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VbusAdcDisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// VBAT_ADC_DIS - 
class BQ25798VbatAdcDisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VbatAdcDisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// VSYS_ADC_DIS - 
class BQ25798VsysAdcDisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VsysAdcDisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// TS_ADC_DIS - 
class BQ25798TsAdcDisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TsAdcDisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// TDIE_ADC_DIS - 
class BQ25798TdieAdcDisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TdieAdcDisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// DPLUS_ADC_DIS - 
class BQ25798DplusAdcDisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798DplusAdcDisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// DMINUS_ADC_DIS - 
class BQ25798DminusAdcDisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798DminusAdcDisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// VAC2_ADC_DIS - 
class BQ25798Vac2AdcDisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798Vac2AdcDisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


// VAC1_ADC_DIS - 
class BQ25798Vac1AdcDisSwitch : public switch_::Switch,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798Vac1AdcDisSwitch() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void write_state(bool state) override;
};


}  // namespace bq25798
}  // namespace esphome