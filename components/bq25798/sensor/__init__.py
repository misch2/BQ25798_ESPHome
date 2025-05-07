import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import core
from esphome.components import i2c, sensor
from esphome.const import (
    CONF_ID,
    DEVICE_CLASS_TEMPERATURE,
    DEVICE_CLASS_VOLTAGE,
    DEVICE_CLASS_CURRENT,
    STATE_CLASS_MEASUREMENT,
    UNIT_CELSIUS,
    UNIT_VOLT,
    UNIT_MILLIAMP,
    UNIT_PERCENT,
)

from .. import (
    CONF_BQ25798_ID,
    BQ25798_CLIENT_SCHEMA,
    bq25798_ns, 
)

DEPENDENCIES = ["bq25798"]

BQ25798Sensor = bq25798_ns.class_("BQ25798Sensor", cg.Component)

# Numeric settings including the enums
CONF_BQ25798_VSYSMIN = "vsysmin"
CONF_BQ25798_VREG = "vreg"
CONF_BQ25798_ICHG = "ichg"
CONF_BQ25798_VINDPM = "vindpm"
CONF_BQ25798_IINDPM = "iindpm"
CONF_BQ25798_VBAT_LOWV = "vbat_lowv"
CONF_BQ25798_IPRECHG = "iprechg"
CONF_BQ25798_ITERM = "iterm"
CONF_BQ25798_CELL = "cell"
CONF_BQ25798_TRECHG = "trechg"
CONF_BQ25798_VRECHG = "vrechg"
CONF_BQ25798_VOTG = "votg"
CONF_BQ25798_PRECHG_TMR = "prechg_tmr"
CONF_BQ25798_IOTG = "iotg"
CONF_BQ25798_TOPOFF_TMR = "topoff_tmr"
CONF_BQ25798_CHG_TMR = "chg_tmr"
CONF_BQ25798_VBUS_BACKUP = "vbus_backup"
CONF_BQ25798_VAC_OVP = "vac_ovp"
CONF_BQ25798_WATCHDOG = "watchdog"
CONF_BQ25798_SDRV_CTRL = "sdrv_ctrl"
CONF_BQ25798_SDRV_DLY = "sdrv_dly"
CONF_BQ25798_WKUP_DLY = "wkup_dly"
CONF_BQ25798_PWM_FREQ = "pwm_freq"
CONF_BQ25798_IBAT_REG = "ibat_reg"
CONF_BQ25798_VOC_PCT = "voc_pct"
CONF_BQ25798_VOC_DLY = "voc_dly"
CONF_BQ25798_VOC_RATE = "voc_rate"
CONF_BQ25798_TREG = "treg"
CONF_BQ25798_TSHUT = "tshut"
CONF_BQ25798_BKUP_ACFET1_ON = "bkup_acfet1_on"
CONF_BQ25798_JEITA_VSET = "jeita_vset"
CONF_BQ25798_JEITA_ISETH = "jeita_iseth"
CONF_BQ25798_JEITA_ISETC = "jeita_isetc"
CONF_BQ25798_TS_COOL = "ts_cool"
CONF_BQ25798_TS_WARM = "ts_warm"
CONF_BQ25798_BHOT = "bhot"
CONF_BQ25798_BCOLD = "bcold"
CONF_BQ25798_ICO_ILIM = "ico_ilim"
CONF_BQ25798_IINDPM_STAT = "iindpm_stat"
CONF_BQ25798_VINDPM_STAT = "vindpm_stat"
CONF_BQ25798_WD_STAT = "wd_stat"
CONF_BQ25798_PG_STAT = "pg_stat"
CONF_BQ25798_AC2_PRESENT_STAT = "ac2_present_stat"
CONF_BQ25798_AC1_PRESENT_STAT = "ac1_present_stat"
CONF_BQ25798_VBUS_PRESENT_STAT = "vbus_present_stat"
CONF_BQ25798_CHG_STAT = "chg_stat"
CONF_BQ25798_VBUS_STAT = "vbus_stat"
CONF_BQ25798_ICO_STAT = "ico_stat"
CONF_BQ25798_TREG_STAT = "treg_stat"
CONF_BQ25798_DPDM_STAT = "dpdm_stat"
CONF_BQ25798_VBAT_PRESENT_STAT = "vbat_present_stat"
CONF_BQ25798_VSYS_STAT = "vsys_stat"
CONF_BQ25798_CHG_TMR_STAT = "chg_tmr_stat"
CONF_BQ25798_TRICHG_TMR_STAT = "trichg_tmr_stat"
CONF_BQ25798_PRECHG_TMR_STAT = "prechg_tmr_stat"
CONF_BQ25798_VBATOTG_LOW_STAT = "vbatotg_low_stat"
CONF_BQ25798_TS_COLD_STAT = "ts_cold_stat"
CONF_BQ25798_TS_COOL_STAT = "ts_cool_stat"
CONF_BQ25798_TS_WARM_STAT = "ts_warm_stat"
CONF_BQ25798_TS_HOT_STAT = "ts_hot_stat"
CONF_BQ25798_ADC_RATE = "adc_rate"
CONF_BQ25798_ADC_SAMPLE = "adc_sample"
CONF_BQ25798_ADC_AVG = "adc_avg"
CONF_BQ25798_IBUS_ADC = "ibus_adc"
CONF_BQ25798_IBAT_ADC = "ibat_adc"
CONF_BQ25798_VBUS_ADC = "vbus_adc"
CONF_BQ25798_VAC1_ADC = "vac1_adc"
CONF_BQ25798_VAC2_ADC = "vac2_adc"
CONF_BQ25798_VBAT_ADC = "vbat_adc"
CONF_BQ25798_VSYS_ADC = "vsys_adc"
CONF_BQ25798_TS_ADC = "ts_adc"
CONF_BQ25798_TDIE_ADC = "tdie_adc"
CONF_BQ25798_DPLUS_ADC = "dplus_adc"
CONF_BQ25798_DMINUS_ADC = "dminus_adc"
CONF_BQ25798_DPLUS_DAC = "dplus_dac"
CONF_BQ25798_DMINUS_DAC = "dminus_dac"
CONF_BQ25798_PN = "pn"
CONF_BQ25798_DEV_REV = "dev_rev"
ENUM_BQ25798_VBAT_LOWV = {
    "VBAT_LOWV_PCT_15": 0,
    "VBAT_LOWV_PCT_62": 1,
    "VBAT_LOWV_PCT_67": 2,
    "VBAT_LOWV_PCT_71": 3,
}
ENUM_BQ25798_CELL = {
    "CELL_1S": 0,
    "CELL_2S": 1,
    "CELL_3S": 2,
    "CELL_4S": 3,
}
ENUM_BQ25798_TRECHG = {
    "TRECHG_64MS": 0,
    "TRECHG_256MS": 1,
    "TRECHG_1024MS": 2,
    "TRECHG_2048MS": 3,
}
ENUM_BQ25798_PRECHG_TMR = {
    "PRECHG_TMR_2HRS": 0,
    "PRECHG_TMR_30MIN": 1,
}
ENUM_BQ25798_TOPOFF_TMR = {
    "TOPOFF_TMR_DISABLED": 0,
    "TOPOFF_TMR_15MIN": 1,
    "TOPOFF_TMR_30MIN": 2,
    "TOPOFF_TMR_45MIN": 3,
}
ENUM_BQ25798_CHG_TMR = {
    "CHG_TMR_5HRS": 0,
    "CHG_TMR_8HRS": 1,
    "CHG_TMR_12HRS": 2,
    "CHG_TMR_24HRS": 3,
}
ENUM_BQ25798_VBUS_BACKUP = {
    "PCT_VBUS_BACKUP_40": 0,
    "PCT_VBUS_BACKUP_60": 1,
    "PCT_VBUS_BACKUP_80": 2,
    "PCT_VBUS_BACKUP_100": 3,
}
ENUM_BQ25798_VAC_OVP = {
    "VAC_OVP_26V": 0,
    "VAC_OVP_22V": 1,
    "VAC_OVP_12V": 2,
    "VAC_OVP_7V": 3,
}
ENUM_BQ25798_WATCHDOG = {
    "WATCHDOG_DISABLE": 0,
    "WATCHDOG_05S": 1,
    "WATCHDOG_1S": 2,
    "WATCHDOG_2S": 3,
    "WATCHDOG_20S": 4,
    "WATCHDOG_40S": 5,
    "WATCHDOG_80S": 6,
    "WATCHDOG_160S": 7,
}
ENUM_BQ25798_SDRV_CTRL = {
    "SDRV_CTRL_IDLE": 0,
    "SDRV_CTRL_SHUTDOWN": 1,
    "SDRV_CTRL_SHIP": 2,
    "SDRV_CTRL_SYS_PWR_RST": 3,
}
ENUM_BQ25798_SDRV_DLY = {
    "SDRV_DLY_10S": 0,
    "SDRV_DLY_0S": 1,
}
ENUM_BQ25798_WKUP_DLY = {
    "WKUP_DLY_1S": 0,
    "WKUP_DLY_15MS": 1,
}
ENUM_BQ25798_PWM_FREQ = {
    "PWM_FREQ_1_5MHZ": 0,
    "PWM_FREQ_750KHZ": 1,
}
ENUM_BQ25798_IBAT_REG = {
    "IBAT_REG_3A": 0,
    "IBAT_REG_4A": 1,
    "IBAT_REG_5A": 2,
    "IBAT_REG_DISABLE": 3,
}
ENUM_BQ25798_VOC_PCT = {
    "VOC_PCT_0_5625": 0,
    "VOC_PCT_0_625": 1,
    "VOC_PCT_0_6875": 2,
    "VOC_PCT_0_75": 3,
    "VOC_PCT_0_8125": 4,
    "VOC_PCT_0_875": 5,
    "VOC_PCT_0_9375": 6,
    "VOC_PCT_1": 7,
}
ENUM_BQ25798_VOC_DLY = {
    "VOC_DLY_50MS": 0,
    "VOC_DLY_300MS": 1,
    "VOC_DLY_2S": 2,
    "VOC_DLY_5S": 3,
}
ENUM_BQ25798_VOC_RATE = {
    "VOC_RATE_30S": 0,
    "VOC_RATE_2MIN": 1,
    "VOC_RATE_10MIN": 2,
    "VOC_RATE_30MIN": 3,
}
ENUM_BQ25798_TREG = {
    "TREG_60": 0,
    "TREG_80": 1,
    "TREG_100": 2,
    "TREG_120": 3,
}
ENUM_BQ25798_TSHUT = {
    "TSHUT_150": 0,
    "TSHUT_130": 1,
    "TSHUT_120": 2,
    "TSHUT_85": 3,
}
ENUM_BQ25798_BKUP_ACFET1_ON = {
    "BKUP_ACFET1_ON_IDLE": 0,
    "BKUP_ACFET1_ON_TURN_ON": 1,
}
ENUM_BQ25798_JEITA_VSET = {
    "JEITA_VSET_CHARGE_SUSPEND": 0,
    "JEITA_VSET_SET_VREG_TO_VREG_800MV": 1,
    "JEITA_VSET_SET_VREG_TO_VREG_600MV": 2,
    "JEITA_VSET_SET_VREG_TO_VREG_400MV": 3,
    "JEITA_VSET_SET_VREG_TO_VREG_300MV": 4,
    "JEITA_VSET_SET_VREG_TO_VREG_200MV": 5,
    "JEITA_VSET_SET_VREG_TO_VREG_100MV": 6,
    "JEITA_VSET_VREG_UNCHANGED": 7,
}
ENUM_BQ25798_JEITA_ISETH = {
    "JEITA_ISETH_CHARGE_SUSPEND": 0,
    "JEITA_ISETH_SET_ICHG_TO_20": 1,
    "JEITA_ISETH_SET_ICHG_TO_40": 2,
    "JEITA_ISETH_ICHG_UNCHANGED": 3,
}
ENUM_BQ25798_JEITA_ISETC = {
    "JEITA_ISETC_CHARGE_SUSPEND": 0,
    "JEITA_ISETC_SET_ICHG_TO_20": 1,
    "JEITA_ISETC_SET_ICHG_TO_40": 2,
    "JEITA_ISETC_ICHG_UNCHANGED": 3,
}
ENUM_BQ25798_TS_COOL = {
    "TS_COOL_5": 0,
    "TS_COOL_10": 1,
    "TS_COOL_15": 2,
    "TS_COOL_20": 3,
}
ENUM_BQ25798_TS_WARM = {
    "TS_WARM_40": 0,
    "TS_WARM_45": 1,
    "TS_WARM_50": 2,
    "TS_WARM_55": 3,
}
ENUM_BQ25798_BHOT = {
    "TS_BHOT_55": 0,
    "TS_BHOT_60": 1,
    "TS_BHOT_65": 2,
    "TS_BHOT_DISABLE": 3,
}
ENUM_BQ25798_BCOLD = {
    "TS_BCOLD_MINUS_10": 0,
    "TS_BCOLD_MINUS_20": 1,
}
ENUM_BQ25798_IINDPM_STAT = {
    "IINDPM_STAT_NORMAL": 0,
    "IINDPM_STAT_REGULATION": 1,
}
ENUM_BQ25798_VINDPM_STAT = {
    "VINDPM_STAT_NORMAL": 0,
    "VINDPM_STAT_REGULATION": 1,
}
ENUM_BQ25798_WD_STAT = {
    "WD_STAT_NORMAL": 0,
    "WD_STAT_EXPIRED": 1,
}
ENUM_BQ25798_PG_STAT = {
    "PG_STAT_BAD": 0,
    "PG_STAT_GOOD": 1,
}
ENUM_BQ25798_AC2_PRESENT_STAT = {
    "AC2_PRESENT_STAT_NOT_PRESENT": 0,
    "AC2_PRESENT_STAT_PRESENT": 1,
}
ENUM_BQ25798_AC1_PRESENT_STAT = {
    "AC1_PRESENT_STAT_NOT_PRESENT": 0,
    "AC1_PRESENT_STAT_PRESENT": 1,
}
ENUM_BQ25798_VBUS_PRESENT_STAT = {
    "VBUS_PRESENT_STAT_NOT_PRESENT": 0,
    "VBUS_PRESENT_STAT_PRESENT": 1,
}
ENUM_BQ25798_CHG_STAT = {
    "CHG_STAT_NOT_CHARGING": 0,
    "CHG_STAT_TRICKLECHARGE": 1,
    "CHG_STAT_PRECHARGE": 2,
    "CHG_STAT_FASTCHARGE_CC": 3,
    "CHG_STAT_FASTCHARGE_CV": 4,
    "CHG_STAT_RESERVED_5": 5,
    "CHG_STAT_TOPOFF": 6,
    "CHG_STAT_TERMINATED": 7,
}
ENUM_BQ25798_VBUS_STAT = {
    "VBUS_STAT_NO_INPUT": 0,
    "VBUS_STAT_USB_SDP": 1,
    "VBUS_STAT_USB_CDP": 2,
    "VBUS_STAT_USB_DCP": 3,
    "VBUS_STAT_ADJUSTABLE_HVDCP": 4,
    "VBUS_STAT_UNKNOWN_ADAPTOR": 5,
    "VBUS_STAT_NON_STANDARD_ADAPTER": 6,
    "VBUS_STAT_OTG_MODE": 7,
    "VBUS_STAT_NOT_QUALIFIED_ADAPTOR": 8,
    "VBUS_STAT_RESERVED_9": 9,
    "VBUS_STAT_RESERVED_A": 10,
    "VBUS_STAT_DEVICE_POWERED_FROM_VBUS": 11,
    "VBUS_STAT_BACKUP_MODE": 12,
    "VBUS_STAT_RESERVED_D": 13,
    "VBUS_STAT_RESERVED_E": 14,
    "VBUS_STAT_RESERVED_F": 15,
}
ENUM_BQ25798_ICO_STAT = {
    "ICO_STAT_DISABLED": 0,
    "ICO_STAT_IN_PROGRESS": 1,
    "ICO_STAT_MAX_CURRENT_DETECTED": 2,
    "ICO_STAT_RESERVED": 3,
}
ENUM_BQ25798_TREG_STAT = {
    "TREG_STAT_NORMAL": 0,
    "TREG_STAT_THERMAL_REGULATION": 1,
}
ENUM_BQ25798_DPDM_STAT = {
    "DPDM_STAT_NOT_STARTED": 0,
    "DPDM_STAT_IN_PROGRESS": 1,
}
ENUM_BQ25798_VBAT_PRESENT_STAT = {
    "VBAT_PRESENT_STAT_NOT_PRESENT": 0,
    "VBAT_PRESENT_STAT_PRESENT": 1,
}
ENUM_BQ25798_VSYS_STAT = {
    "VSYS_STAT_NOT_IN_VSYSMIN_REGULATION": 0,
    "VSYS_STAT_IN_VSYSMIN_REGULATION": 1,
}
ENUM_BQ25798_CHG_TMR_STAT = {
    "CHG_TMR_STAT_NORMAL": 0,
    "CHG_TMR_STAT_SAFETY_TIMER_EXPIRED": 1,
}
ENUM_BQ25798_TRICHG_TMR_STAT = {
    "TRICHG_TMR_STAT_NORMAL": 0,
    "TRICHG_TMR_STAT_SAFETY_TIMER_EXPIRED": 1,
}
ENUM_BQ25798_PRECHG_TMR_STAT = {
    "PRECHG_TMR_STAT_NORMAL": 0,
    "PRECHG_TMR_STAT_SAFETY_TIMER_EXPIRED": 1,
}
ENUM_BQ25798_VBATOTG_LOW_STAT = {
    "VBATOTG_LOW_STAT_VBATOTG_LOW": 0,
    "VBATOTG_LOW_STAT_VBATOTG_OK": 1,
}
ENUM_BQ25798_TS_COLD_STAT = {
    "TS_COLD_STAT_NOT_COLD": 0,
    "TS_COLD_STAT_COLD": 1,
}
ENUM_BQ25798_TS_COOL_STAT = {
    "TS_COOL_STAT_NOT_COOL": 0,
    "TS_COOL_STAT_COOL": 1,
}
ENUM_BQ25798_TS_WARM_STAT = {
    "TS_WARM_STAT_NOT_WARM": 0,
    "TS_WARM_STAT_WARM": 1,
}
ENUM_BQ25798_TS_HOT_STAT = {
    "TS_HOT_STAT_NOT_HOT": 0,
    "TS_HOT_STAT_HOT": 1,
}
ENUM_BQ25798_ADC_RATE = {
    "ADC_RATE_CONTINUOUS": 0,
    "ADC_RATE_ONESHOT": 1,
}
ENUM_BQ25798_ADC_SAMPLE = {
    "ADC_SAMPLE_15BIT": 0,
    "ADC_SAMPLE_14BIT": 1,
    "ADC_SAMPLE_13BIT": 2,
    "ADC_SAMPLE_12BIT": 3,
}
ENUM_BQ25798_ADC_AVG = {
    "ADC_AVG_NO_AVERAGING": 0,
    "ADC_AVG_RUNNING_AVERAGE": 1,
}
ENUM_BQ25798_DPLUS_DAC = {
    "DPLUS_DAC_HIZ": 0,
    "DPLUS_DAC_VOUT_0": 1,
    "DPLUS_DAC_VOUT_0_6": 2,
    "DPLUS_DAC_VOUT_1_2": 3,
    "DPLUS_DAC_VOUT_2_0": 4,
    "DPLUS_DAC_VOUT_2_7": 5,
    "DPLUS_DAC_VOUT_3_3": 6,
    "DPLUS_DAC_DPLUS_DMINUS_SHORT": 7,
}
ENUM_BQ25798_DMINUS_DAC = {
    "DMINUS_DAC_HIZ": 0,
    "DMINUS_DAC_VOUT_0": 1,
    "DMINUS_DAC_VOUT_0_6": 2,
    "DMINUS_DAC_VOUT_1_2": 3,
    "DMINUS_DAC_VOUT_2_0": 4,
    "DMINUS_DAC_VOUT_2_7": 5,
    "DMINUS_DAC_VOUT_3_3": 6,
    "DMINUS_DAC_RESERVED": 7,
}
ENUM_BQ25798_PN = {
    "PN_RESERVED_0": 0,
    "PN_RESERVED_1": 1,
    "PN_RESERVED_2": 2,
    "PN_BQ25798": 3,
    "PN_RESERVED_4": 4,
    "PN_RESERVED_5": 5,
    "PN_RESERVED_6": 6,
    "PN_RESERVED_7": 7,
}
ENUM_BQ25798_DEV_REV = {
    "DEV_REV_RESERVED_0": 0,
    "DEV_REV_BQ25798": 1,
    "DEV_REV_RESERVED_2": 2,
    "DEV_REV_RESERVED_3": 3,
    "DEV_REV_RESERVED_4": 4,
    "DEV_REV_RESERVED_5": 5,
    "DEV_REV_RESERVED_6": 6,
    "DEV_REV_RESERVED_7": 7,
}

CONFIG_SCHEMA = (
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(BQ25798Sensor),
            cv.Optional(CONF_BQ25798_VSYSMIN): sensor.sensor_schema(
                unit_of_measurement="mV",   # FIXME
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VREG): sensor.sensor_schema(
                unit_of_measurement="mV",   # FIXME
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ICHG): sensor.sensor_schema(
                unit_of_measurement=UNIT_MILLIAMP,
                device_class=DEVICE_CLASS_CURRENT,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VINDPM): sensor.sensor_schema(
                unit_of_measurement="mV",   # FIXME
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IINDPM): sensor.sensor_schema(
                unit_of_measurement=UNIT_MILLIAMP,
                device_class=DEVICE_CLASS_CURRENT,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBAT_LOWV): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IPRECHG): sensor.sensor_schema(
                unit_of_measurement=UNIT_MILLIAMP,
                device_class=DEVICE_CLASS_CURRENT,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ITERM): sensor.sensor_schema(
                unit_of_measurement=UNIT_MILLIAMP,
                device_class=DEVICE_CLASS_CURRENT,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_CELL): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TRECHG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VRECHG): sensor.sensor_schema(
                unit_of_measurement="mV",   # FIXME
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VOTG): sensor.sensor_schema(
                unit_of_measurement="mV",   # FIXME
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_PRECHG_TMR): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IOTG): sensor.sensor_schema(
                unit_of_measurement=UNIT_MILLIAMP,
                device_class=DEVICE_CLASS_CURRENT,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TOPOFF_TMR): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_CHG_TMR): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBUS_BACKUP): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VAC_OVP): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_WATCHDOG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_SDRV_CTRL): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_SDRV_DLY): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_WKUP_DLY): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_PWM_FREQ): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IBAT_REG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VOC_PCT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VOC_DLY): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VOC_RATE): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TREG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TSHUT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_BKUP_ACFET1_ON): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_JEITA_VSET): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_JEITA_ISETH): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_JEITA_ISETC): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TS_COOL): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TS_WARM): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_BHOT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_BCOLD): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ICO_ILIM): sensor.sensor_schema(
                unit_of_measurement=UNIT_MILLIAMP,
                device_class=DEVICE_CLASS_CURRENT,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IINDPM_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VINDPM_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_WD_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_PG_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_AC2_PRESENT_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_AC1_PRESENT_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBUS_PRESENT_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_CHG_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBUS_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ICO_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TREG_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DPDM_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBAT_PRESENT_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VSYS_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_CHG_TMR_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TRICHG_TMR_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_PRECHG_TMR_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBATOTG_LOW_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TS_COLD_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TS_COOL_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TS_WARM_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TS_HOT_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ADC_RATE): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ADC_SAMPLE): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ADC_AVG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IBUS_ADC): sensor.sensor_schema(
                unit_of_measurement=UNIT_MILLIAMP,
                device_class=DEVICE_CLASS_CURRENT,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IBAT_ADC): sensor.sensor_schema(
                unit_of_measurement=UNIT_MILLIAMP,
                device_class=DEVICE_CLASS_CURRENT,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBUS_ADC): sensor.sensor_schema(
                unit_of_measurement="mV",   # FIXME
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VAC1_ADC): sensor.sensor_schema(
                unit_of_measurement="mV",   # FIXME
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VAC2_ADC): sensor.sensor_schema(
                unit_of_measurement="mV",   # FIXME
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBAT_ADC): sensor.sensor_schema(
                unit_of_measurement="mV",   # FIXME
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VSYS_ADC): sensor.sensor_schema(
                unit_of_measurement="mV",   # FIXME
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TS_ADC): sensor.sensor_schema(
                unit_of_measurement=UNIT_PERCENT,
                accuracy_decimals=2,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TDIE_ADC): sensor.sensor_schema(
                unit_of_measurement=UNIT_CELSIUS,
                device_class=DEVICE_CLASS_TEMPERATURE,
                accuracy_decimals=2,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DPLUS_ADC): sensor.sensor_schema(
                unit_of_measurement="mV",   # FIXME
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DMINUS_ADC): sensor.sensor_schema(
                unit_of_measurement="mV",   # FIXME
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DPLUS_DAC): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DMINUS_DAC): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_PN): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DEV_REV): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
        }
    )
    .extend(BQ25798_CLIENT_SCHEMA)
)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])

    await cg.register_component(var, config)
    parent = await cg.get_variable(config[CONF_BQ25798_ID])

    # Sensors
    if vsysmin := config.get(CONF_BQ25798_VSYSMIN):
        sens = await sensor.new_sensor(vsysmin)
        cg.add(parent.set_vsysmin_sensor(sens))                    

    if vreg := config.get(CONF_BQ25798_VREG):
        sens = await sensor.new_sensor(vreg)
        cg.add(parent.set_vreg_sensor(sens))                    

    if ichg := config.get(CONF_BQ25798_ICHG):
        sens = await sensor.new_sensor(ichg)
        cg.add(parent.set_ichg_sensor(sens))                    

    if vindpm := config.get(CONF_BQ25798_VINDPM):
        sens = await sensor.new_sensor(vindpm)
        cg.add(parent.set_vindpm_sensor(sens))                    

    if iindpm := config.get(CONF_BQ25798_IINDPM):
        sens = await sensor.new_sensor(iindpm)
        cg.add(parent.set_iindpm_sensor(sens))                    

    if vbat_lowv := config.get(CONF_BQ25798_VBAT_LOWV):
        sens = await sensor.new_sensor(vbat_lowv)
        cg.add(parent.set_vbat_lowv_sensor(sens))                    

    if iprechg := config.get(CONF_BQ25798_IPRECHG):
        sens = await sensor.new_sensor(iprechg)
        cg.add(parent.set_iprechg_sensor(sens))                    
                    
                    

    if iterm := config.get(CONF_BQ25798_ITERM):
        sens = await sensor.new_sensor(iterm)
        cg.add(parent.set_iterm_sensor(sens))                    

    if cell := config.get(CONF_BQ25798_CELL):
        sens = await sensor.new_sensor(cell)
        cg.add(parent.set_cell_sensor(sens))                    

    if trechg := config.get(CONF_BQ25798_TRECHG):
        sens = await sensor.new_sensor(trechg)
        cg.add(parent.set_trechg_sensor(sens))                    

    if vrechg := config.get(CONF_BQ25798_VRECHG):
        sens = await sensor.new_sensor(vrechg)
        cg.add(parent.set_vrechg_sensor(sens))                    

    if votg := config.get(CONF_BQ25798_VOTG):
        sens = await sensor.new_sensor(votg)
        cg.add(parent.set_votg_sensor(sens))                    

    if prechg_tmr := config.get(CONF_BQ25798_PRECHG_TMR):
        sens = await sensor.new_sensor(prechg_tmr)
        cg.add(parent.set_prechg_tmr_sensor(sens))                    

    if iotg := config.get(CONF_BQ25798_IOTG):
        sens = await sensor.new_sensor(iotg)
        cg.add(parent.set_iotg_sensor(sens))                    

    if topoff_tmr := config.get(CONF_BQ25798_TOPOFF_TMR):
        sens = await sensor.new_sensor(topoff_tmr)
        cg.add(parent.set_topoff_tmr_sensor(sens))                    
                    
                    
                    

    if chg_tmr := config.get(CONF_BQ25798_CHG_TMR):
        sens = await sensor.new_sensor(chg_tmr)
        cg.add(parent.set_chg_tmr_sensor(sens))                    
                    
                    
                    
                    
                    
                    
                    
                    
                    

    if vbus_backup := config.get(CONF_BQ25798_VBUS_BACKUP):
        sens = await sensor.new_sensor(vbus_backup)
        cg.add(parent.set_vbus_backup_sensor(sens))                    

    if vac_ovp := config.get(CONF_BQ25798_VAC_OVP):
        sens = await sensor.new_sensor(vac_ovp)
        cg.add(parent.set_vac_ovp_sensor(sens))                    
                    

    if watchdog := config.get(CONF_BQ25798_WATCHDOG):
        sens = await sensor.new_sensor(watchdog)
        cg.add(parent.set_watchdog_sensor(sens))                    
                    
                    
                    
                    
                    

    if sdrv_ctrl := config.get(CONF_BQ25798_SDRV_CTRL):
        sens = await sensor.new_sensor(sdrv_ctrl)
        cg.add(parent.set_sdrv_ctrl_sensor(sens))                    

    if sdrv_dly := config.get(CONF_BQ25798_SDRV_DLY):
        sens = await sensor.new_sensor(sdrv_dly)
        cg.add(parent.set_sdrv_dly_sensor(sens))                    
                    
                    
                    
                    

    if wkup_dly := config.get(CONF_BQ25798_WKUP_DLY):
        sens = await sensor.new_sensor(wkup_dly)
        cg.add(parent.set_wkup_dly_sensor(sens))                    
                    
                    
                    
                    
                    

    if pwm_freq := config.get(CONF_BQ25798_PWM_FREQ):
        sens = await sensor.new_sensor(pwm_freq)
        cg.add(parent.set_pwm_freq_sensor(sens))                    
                    
                    
                    
                    
                    
                    
                    

    if ibat_reg := config.get(CONF_BQ25798_IBAT_REG):
        sens = await sensor.new_sensor(ibat_reg)
        cg.add(parent.set_ibat_reg_sensor(sens))                    
                    
                    
                    

    if voc_pct := config.get(CONF_BQ25798_VOC_PCT):
        sens = await sensor.new_sensor(voc_pct)
        cg.add(parent.set_voc_pct_sensor(sens))                    

    if voc_dly := config.get(CONF_BQ25798_VOC_DLY):
        sens = await sensor.new_sensor(voc_dly)
        cg.add(parent.set_voc_dly_sensor(sens))                    

    if voc_rate := config.get(CONF_BQ25798_VOC_RATE):
        sens = await sensor.new_sensor(voc_rate)
        cg.add(parent.set_voc_rate_sensor(sens))                    
                    

    if treg := config.get(CONF_BQ25798_TREG):
        sens = await sensor.new_sensor(treg)
        cg.add(parent.set_treg_sensor(sens))                    

    if tshut := config.get(CONF_BQ25798_TSHUT):
        sens = await sensor.new_sensor(tshut)
        cg.add(parent.set_tshut_sensor(sens))                    
                    
                    
                    

    if bkup_acfet1_on := config.get(CONF_BQ25798_BKUP_ACFET1_ON):
        sens = await sensor.new_sensor(bkup_acfet1_on)
        cg.add(parent.set_bkup_acfet1_on_sensor(sens))                    

    if jeita_vset := config.get(CONF_BQ25798_JEITA_VSET):
        sens = await sensor.new_sensor(jeita_vset)
        cg.add(parent.set_jeita_vset_sensor(sens))                    

    if jeita_iseth := config.get(CONF_BQ25798_JEITA_ISETH):
        sens = await sensor.new_sensor(jeita_iseth)
        cg.add(parent.set_jeita_iseth_sensor(sens))                    

    if jeita_isetc := config.get(CONF_BQ25798_JEITA_ISETC):
        sens = await sensor.new_sensor(jeita_isetc)
        cg.add(parent.set_jeita_isetc_sensor(sens))                    

    if ts_cool := config.get(CONF_BQ25798_TS_COOL):
        sens = await sensor.new_sensor(ts_cool)
        cg.add(parent.set_ts_cool_sensor(sens))                    

    if ts_warm := config.get(CONF_BQ25798_TS_WARM):
        sens = await sensor.new_sensor(ts_warm)
        cg.add(parent.set_ts_warm_sensor(sens))                    

    if bhot := config.get(CONF_BQ25798_BHOT):
        sens = await sensor.new_sensor(bhot)
        cg.add(parent.set_bhot_sensor(sens))                    

    if bcold := config.get(CONF_BQ25798_BCOLD):
        sens = await sensor.new_sensor(bcold)
        cg.add(parent.set_bcold_sensor(sens))                    
                    

    if ico_ilim := config.get(CONF_BQ25798_ICO_ILIM):
        sens = await sensor.new_sensor(ico_ilim)
        cg.add(parent.set_ico_ilim_sensor(sens))                    

    if iindpm_stat := config.get(CONF_BQ25798_IINDPM_STAT):
        sens = await sensor.new_sensor(iindpm_stat)
        cg.add(parent.set_iindpm_stat_sensor(sens))                    

    if vindpm_stat := config.get(CONF_BQ25798_VINDPM_STAT):
        sens = await sensor.new_sensor(vindpm_stat)
        cg.add(parent.set_vindpm_stat_sensor(sens))                    

    if wd_stat := config.get(CONF_BQ25798_WD_STAT):
        sens = await sensor.new_sensor(wd_stat)
        cg.add(parent.set_wd_stat_sensor(sens))                    

    if pg_stat := config.get(CONF_BQ25798_PG_STAT):
        sens = await sensor.new_sensor(pg_stat)
        cg.add(parent.set_pg_stat_sensor(sens))                    

    if ac2_present_stat := config.get(CONF_BQ25798_AC2_PRESENT_STAT):
        sens = await sensor.new_sensor(ac2_present_stat)
        cg.add(parent.set_ac2_present_stat_sensor(sens))                    

    if ac1_present_stat := config.get(CONF_BQ25798_AC1_PRESENT_STAT):
        sens = await sensor.new_sensor(ac1_present_stat)
        cg.add(parent.set_ac1_present_stat_sensor(sens))                    

    if vbus_present_stat := config.get(CONF_BQ25798_VBUS_PRESENT_STAT):
        sens = await sensor.new_sensor(vbus_present_stat)
        cg.add(parent.set_vbus_present_stat_sensor(sens))                    

    if chg_stat := config.get(CONF_BQ25798_CHG_STAT):
        sens = await sensor.new_sensor(chg_stat)
        cg.add(parent.set_chg_stat_sensor(sens))                    

    if vbus_stat := config.get(CONF_BQ25798_VBUS_STAT):
        sens = await sensor.new_sensor(vbus_stat)
        cg.add(parent.set_vbus_stat_sensor(sens))                    
                    

    if ico_stat := config.get(CONF_BQ25798_ICO_STAT):
        sens = await sensor.new_sensor(ico_stat)
        cg.add(parent.set_ico_stat_sensor(sens))                    

    if treg_stat := config.get(CONF_BQ25798_TREG_STAT):
        sens = await sensor.new_sensor(treg_stat)
        cg.add(parent.set_treg_stat_sensor(sens))                    

    if dpdm_stat := config.get(CONF_BQ25798_DPDM_STAT):
        sens = await sensor.new_sensor(dpdm_stat)
        cg.add(parent.set_dpdm_stat_sensor(sens))                    

    if vbat_present_stat := config.get(CONF_BQ25798_VBAT_PRESENT_STAT):
        sens = await sensor.new_sensor(vbat_present_stat)
        cg.add(parent.set_vbat_present_stat_sensor(sens))                    
                    
                    
                    

    if vsys_stat := config.get(CONF_BQ25798_VSYS_STAT):
        sens = await sensor.new_sensor(vsys_stat)
        cg.add(parent.set_vsys_stat_sensor(sens))                    

    if chg_tmr_stat := config.get(CONF_BQ25798_CHG_TMR_STAT):
        sens = await sensor.new_sensor(chg_tmr_stat)
        cg.add(parent.set_chg_tmr_stat_sensor(sens))                    

    if trichg_tmr_stat := config.get(CONF_BQ25798_TRICHG_TMR_STAT):
        sens = await sensor.new_sensor(trichg_tmr_stat)
        cg.add(parent.set_trichg_tmr_stat_sensor(sens))                    

    if prechg_tmr_stat := config.get(CONF_BQ25798_PRECHG_TMR_STAT):
        sens = await sensor.new_sensor(prechg_tmr_stat)
        cg.add(parent.set_prechg_tmr_stat_sensor(sens))                    

    if vbatotg_low_stat := config.get(CONF_BQ25798_VBATOTG_LOW_STAT):
        sens = await sensor.new_sensor(vbatotg_low_stat)
        cg.add(parent.set_vbatotg_low_stat_sensor(sens))                    

    if ts_cold_stat := config.get(CONF_BQ25798_TS_COLD_STAT):
        sens = await sensor.new_sensor(ts_cold_stat)
        cg.add(parent.set_ts_cold_stat_sensor(sens))                    

    if ts_cool_stat := config.get(CONF_BQ25798_TS_COOL_STAT):
        sens = await sensor.new_sensor(ts_cool_stat)
        cg.add(parent.set_ts_cool_stat_sensor(sens))                    

    if ts_warm_stat := config.get(CONF_BQ25798_TS_WARM_STAT):
        sens = await sensor.new_sensor(ts_warm_stat)
        cg.add(parent.set_ts_warm_stat_sensor(sens))                    

    if ts_hot_stat := config.get(CONF_BQ25798_TS_HOT_STAT):
        sens = await sensor.new_sensor(ts_hot_stat)
        cg.add(parent.set_ts_hot_stat_sensor(sens))                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    

    if adc_rate := config.get(CONF_BQ25798_ADC_RATE):
        sens = await sensor.new_sensor(adc_rate)
        cg.add(parent.set_adc_rate_sensor(sens))                    

    if adc_sample := config.get(CONF_BQ25798_ADC_SAMPLE):
        sens = await sensor.new_sensor(adc_sample)
        cg.add(parent.set_adc_sample_sensor(sens))                    

    if adc_avg := config.get(CONF_BQ25798_ADC_AVG):
        sens = await sensor.new_sensor(adc_avg)
        cg.add(parent.set_adc_avg_sensor(sens))                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    

    if ibus_adc := config.get(CONF_BQ25798_IBUS_ADC):
        sens = await sensor.new_sensor(ibus_adc)
        cg.add(parent.set_ibus_adc_sensor(sens))                    

    if ibat_adc := config.get(CONF_BQ25798_IBAT_ADC):
        sens = await sensor.new_sensor(ibat_adc)
        cg.add(parent.set_ibat_adc_sensor(sens))                    

    if vbus_adc := config.get(CONF_BQ25798_VBUS_ADC):
        sens = await sensor.new_sensor(vbus_adc)
        cg.add(parent.set_vbus_adc_sensor(sens))                    

    if vac1_adc := config.get(CONF_BQ25798_VAC1_ADC):
        sens = await sensor.new_sensor(vac1_adc)
        cg.add(parent.set_vac1_adc_sensor(sens))                    

    if vac2_adc := config.get(CONF_BQ25798_VAC2_ADC):
        sens = await sensor.new_sensor(vac2_adc)
        cg.add(parent.set_vac2_adc_sensor(sens))                    

    if vbat_adc := config.get(CONF_BQ25798_VBAT_ADC):
        sens = await sensor.new_sensor(vbat_adc)
        cg.add(parent.set_vbat_adc_sensor(sens))                    

    if vsys_adc := config.get(CONF_BQ25798_VSYS_ADC):
        sens = await sensor.new_sensor(vsys_adc)
        cg.add(parent.set_vsys_adc_sensor(sens))                    

    if ts_adc := config.get(CONF_BQ25798_TS_ADC):
        sens = await sensor.new_sensor(ts_adc)
        cg.add(parent.set_ts_adc_sensor(sens))                    

    if tdie_adc := config.get(CONF_BQ25798_TDIE_ADC):
        sens = await sensor.new_sensor(tdie_adc)
        cg.add(parent.set_tdie_adc_sensor(sens))                    

    if dplus_adc := config.get(CONF_BQ25798_DPLUS_ADC):
        sens = await sensor.new_sensor(dplus_adc)
        cg.add(parent.set_dplus_adc_sensor(sens))                    

    if dminus_adc := config.get(CONF_BQ25798_DMINUS_ADC):
        sens = await sensor.new_sensor(dminus_adc)
        cg.add(parent.set_dminus_adc_sensor(sens))                    

    if dplus_dac := config.get(CONF_BQ25798_DPLUS_DAC):
        sens = await sensor.new_sensor(dplus_dac)
        cg.add(parent.set_dplus_dac_sensor(sens))                    

    if dminus_dac := config.get(CONF_BQ25798_DMINUS_DAC):
        sens = await sensor.new_sensor(dminus_dac)
        cg.add(parent.set_dminus_dac_sensor(sens))                    

    if pn := config.get(CONF_BQ25798_PN):
        sens = await sensor.new_sensor(pn)
        cg.add(parent.set_pn_sensor(sens))                    

    if dev_rev := config.get(CONF_BQ25798_DEV_REV):
        sens = await sensor.new_sensor(dev_rev)
        cg.add(parent.set_dev_rev_sensor(sens))                    
