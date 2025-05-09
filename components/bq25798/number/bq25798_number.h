#pragma once

#include "esphome/components/number/number.h"
#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

#include "../bq25798_component.h"

namespace esphome {
namespace bq25798 {


// VSYSMIN - Minimal System Voltage
class BQ25798VsysminNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VsysminNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// VREG - Charge Voltage Limit
class BQ25798VregNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VregNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// ICHG - Charge Current Limit
class BQ25798IchgNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798IchgNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// VINDPM - Input Voltage Limit
class BQ25798VindpmNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VindpmNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// IINDPM - Input Current Limit
class BQ25798IindpmNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798IindpmNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
class BQ25798VbatLowvNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VbatLowvNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// IPRECHG - Precharge Current Limit
class BQ25798IprechgNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798IprechgNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// ITERM - Termination Current Limit
class BQ25798ItermNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798ItermNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// CELL - Battery cell count
class BQ25798CellNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798CellNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// TRECHG - Battery recharge delay time
class BQ25798TrechgNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TrechgNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// VRECHG - Battery Recharge Threshold Offset (Below VREG)
class BQ25798VrechgNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VrechgNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// VOTG - OTG mode regulation voltage
class BQ25798VotgNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VotgNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// PRECHG_TMR - Pre-charge safety timer setting
class BQ25798PrechgTmrNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798PrechgTmrNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// IOTG - OTG current limit
class BQ25798IotgNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798IotgNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// TOPOFF_TMR - Top-off timer control
class BQ25798TopoffTmrNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TopoffTmrNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// CHG_TMR - Fast charge timer setting
class BQ25798ChgTmrNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798ChgTmrNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// VBUS_BACKUP - The thresholds to trigger the backup mode, defined as a ratio of VINDPM
class BQ25798VbusBackupNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VbusBackupNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// VAC_OVP - Over voltage protection thresholds
class BQ25798VacOvpNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VacOvpNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// WATCHDOG - Watchdog timer settings
class BQ25798WatchdogNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798WatchdogNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// SDRV_CTRL - Enable external Ship FET control
class BQ25798SdrvCtrlNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798SdrvCtrlNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// SDRV_DLY - Delay for SDRV control
class BQ25798SdrvDlyNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798SdrvDlyNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// WKUP_DLY - Wakeup (Ship FET) delay
class BQ25798WkupDlyNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798WkupDlyNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// PWM_FREQ - PWM frequency setting
class BQ25798PwmFreqNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798PwmFreqNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// IBAT_REG - Battery discharge current regulation in OTG mode
class BQ25798IbatRegNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798IbatRegNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// VOC_PCT - 
class BQ25798VocPctNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VocPctNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// VOC_DLY - 
class BQ25798VocDlyNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VocDlyNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// VOC_RATE - 
class BQ25798VocRateNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VocRateNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// TREG - 
class BQ25798TregNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TregNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// TSHUT - 
class BQ25798TshutNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TshutNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// BKUP_ACFET1_ON - 
class BQ25798BkupAcfet1OnNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798BkupAcfet1OnNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// JEITA_VSET - 
class BQ25798JeitaVsetNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798JeitaVsetNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// JEITA_ISETH - 
class BQ25798JeitaIsethNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798JeitaIsethNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// JEITA_ISETC - 
class BQ25798JeitaIsetcNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798JeitaIsetcNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// TS_COOL - 
class BQ25798TsCoolNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TsCoolNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// TS_WARM - 
class BQ25798TsWarmNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TsWarmNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// BHOT - 
class BQ25798BhotNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798BhotNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// BCOLD - 
class BQ25798BcoldNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798BcoldNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// ADC_RATE - 
class BQ25798AdcRateNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798AdcRateNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// ADC_SAMPLE - 
class BQ25798AdcSampleNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798AdcSampleNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// ADC_AVG - 
class BQ25798AdcAvgNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798AdcAvgNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// DPLUS_DAC - D+ Output Driver
class BQ25798DplusDacNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798DplusDacNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


// DMINUS_DAC - D- Output Driver
class BQ25798DminusDacNumber : public number::Number,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798DminusDacNumber() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control (float new_value) override;
};


}  // namespace bq25798
}  // namespace esphome