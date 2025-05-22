#pragma once

#include "esphome/components/select/select.h"
#include "esphome/core/component.h"
#include "esphome/core/helpers.h"

#include "../bq25798_component.h"

namespace esphome {
namespace bq25798 {


// VBAT_LOWV - Battery voltage thresholds for fast charge (percent of VREG)
class BQ25798VbatLowvSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VbatLowvSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// CELL - Battery cell count
class BQ25798CellSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798CellSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// TRECHG - Battery recharge delay time
class BQ25798TrechgSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TrechgSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// PRECHG_TMR - Pre-charge safety timer setting
class BQ25798PrechgTmrSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798PrechgTmrSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// TOPOFF_TMR - Top-off timer control
class BQ25798TopoffTmrSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TopoffTmrSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// CHG_TMR - Fast charge timer setting
class BQ25798ChgTmrSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798ChgTmrSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// VBUS_BACKUP - The thresholds to trigger the backup mode, defined as a ratio of VINDPM
class BQ25798VbusBackupSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VbusBackupSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// VAC_OVP - Over voltage protection thresholds
class BQ25798VacOvpSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VacOvpSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// WATCHDOG - Watchdog timer settings
class BQ25798WatchdogSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798WatchdogSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// SDRV_CTRL - Enable external Ship FET control
class BQ25798SdrvCtrlSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798SdrvCtrlSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// SDRV_DLY - Delay for SDRV control
class BQ25798SdrvDlySelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798SdrvDlySelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// WKUP_DLY - Wakeup (Ship FET) delay
class BQ25798WkupDlySelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798WkupDlySelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// PWM_FREQ - PWM frequency setting
class BQ25798PwmFreqSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798PwmFreqSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// IBAT_REG - Battery discharge current regulation in OTG mode
class BQ25798IbatRegSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798IbatRegSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// VOC_PCT - 
class BQ25798VocPctSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VocPctSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// VOC_DLY - 
class BQ25798VocDlySelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VocDlySelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// VOC_RATE - 
class BQ25798VocRateSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798VocRateSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// TREG - 
class BQ25798TregSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TregSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// TSHUT - 
class BQ25798TshutSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TshutSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// BKUP_ACFET1_ON - 
class BQ25798BkupAcfet1OnSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798BkupAcfet1OnSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// JEITA_VSET - 
class BQ25798JeitaVsetSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798JeitaVsetSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// JEITA_ISETH - 
class BQ25798JeitaIsethSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798JeitaIsethSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// JEITA_ISETC - 
class BQ25798JeitaIsetcSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798JeitaIsetcSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// TS_COOL - 
class BQ25798TsCoolSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TsCoolSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// TS_WARM - 
class BQ25798TsWarmSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798TsWarmSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// BHOT - 
class BQ25798BhotSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798BhotSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// BCOLD - 
class BQ25798BcoldSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798BcoldSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// ADC_RATE - 
class BQ25798AdcRateSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798AdcRateSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// ADC_SAMPLE - 
class BQ25798AdcSampleSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798AdcSampleSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// ADC_AVG - 
class BQ25798AdcAvgSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798AdcAvgSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// DPLUS_DAC - D+ Output Driver
class BQ25798DplusDacSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798DplusDacSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


// DMINUS_DAC - D- Output Driver
class BQ25798DminusDacSelect : public select::Select,
                            public PollingComponent,
                            public Parented<BQ25798Component> {
 public:
  BQ25798DminusDacSelect() = default;
  void update() override;
  void dump_config() override;
  float get_setup_priority() const override;

 protected:
  void control(const std::string &value) override;
};


}  // namespace bq25798
}  // namespace esphome