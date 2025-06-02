import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor
from esphome.const import (
    CONF_ID,
    DEVICE_CLASS_TEMPERATURE,
    DEVICE_CLASS_VOLTAGE,
    DEVICE_CLASS_CURRENT,
    STATE_CLASS_MEASUREMENT,
    UNIT_CELSIUS,
    UNIT_MILLIAMP,
    UNIT_PERCENT,
)

from .. import (
    CONF_BQ25798_ID,
    bq25798_ns,
    BQ25798Component
)

DEPENDENCIES = ["bq25798"]

BQ25798Sensor = bq25798_ns.class_("BQ25798Sensor", sensor.Sensor, cg.PollingComponent)

# Numeric settings including the enums
CONF_BQ25798_VSYSMIN = "vsysmin"
CONF_BQ25798_VREG = "vreg"
CONF_BQ25798_ICHG = "ichg"
CONF_BQ25798_VINDPM = "vindpm"
CONF_BQ25798_IINDPM = "iindpm"
CONF_BQ25798_VBAT_LOWV = "vbat_lowv"
CONF_BQ25798_IPRECHG = "iprechg"
CONF_BQ25798_REG_RST = "reg_rst"
CONF_BQ25798_STOP_WD_CHG = "stop_wd_chg"
CONF_BQ25798_ITERM = "iterm"
CONF_BQ25798_CELL = "cell"
CONF_BQ25798_TRECHG = "trechg"
CONF_BQ25798_VRECHG = "vrechg"
CONF_BQ25798_VOTG = "votg"
CONF_BQ25798_IOTG = "iotg"
CONF_BQ25798_TOPOFF_TMR = "topoff_tmr"
CONF_BQ25798_EN_TRICHG_TMR = "en_trichg_tmr"
CONF_BQ25798_EN_PRECHG_TMR = "en_prechg_tmr"
CONF_BQ25798_EN_CHG_TMR = "en_chg_tmr"
CONF_BQ25798_CHG_TMR = "chg_tmr"
CONF_BQ25798_TMR2X_EN = "tmr2x_en"
CONF_BQ25798_EN_AUTO_IBATDIS = "en_auto_ibatdis"
CONF_BQ25798_FORCE_IBATDIS = "force_ibatdis"
CONF_BQ25798_EN_CHG = "en_chg"
CONF_BQ25798_EN_ICO = "en_ico"
CONF_BQ25798_FORCE_ICO = "force_ico"
CONF_BQ25798_EN_HIZ = "en_hiz"
CONF_BQ25798_EN_TERM = "en_term"
CONF_BQ25798_EN_BACKUP = "en_backup"
CONF_BQ25798_VBUS_BACKUP = "vbus_backup"
CONF_BQ25798_VAC_OVP = "vac_ovp"
CONF_BQ25798_WD_RST = "wd_rst"
CONF_BQ25798_WATCHDOG = "watchdog"
CONF_BQ25798_FORCE_INDET = "force_indet"
CONF_BQ25798_AUTO_INDET_EN = "auto_indet_en"
CONF_BQ25798_EN_12V = "en_12v"
CONF_BQ25798_EN_9V = "en_9v"
CONF_BQ25798_HVDCP_EN = "hvdcp_en"
CONF_BQ25798_SDRV_CTRL = "sdrv_ctrl"
CONF_BQ25798_DIS_ACDRV = "dis_acdrv"
CONF_BQ25798_EN_OTG = "en_otg"
CONF_BQ25798_PFM_OTG_DIS = "pfm_otg_dis"
CONF_BQ25798_PFM_FWD_DIS = "pfm_fwd_dis"
CONF_BQ25798_DIS_LDO = "dis_ldo"
CONF_BQ25798_DIS_OTG_OOA = "dis_otg_ooa"
CONF_BQ25798_DIS_FWD_OOA = "dis_fwd_ooa"
CONF_BQ25798_EN_ACDRV2 = "en_acdrv2"
CONF_BQ25798_EN_ACDRV1 = "en_acdrv1"
CONF_BQ25798_DIS_STAT = "dis_stat"
CONF_BQ25798_DIS_VSYS_SHORT = "dis_vsys_short"
CONF_BQ25798_DIS_VOTG_UVP = "dis_votg_uvp"
CONF_BQ25798_FORCE_VINDPM_DET = "force_vindpm_det"
CONF_BQ25798_EN_IBUS_OCP = "en_ibus_ocp"
CONF_BQ25798_SFET_PRESENT = "sfet_present"
CONF_BQ25798_EN_IBAT = "en_ibat"
CONF_BQ25798_IBAT_REG = "ibat_reg"
CONF_BQ25798_EN_IINDPM = "en_iindpm"
CONF_BQ25798_EN_EXTILIM = "en_extilim"
CONF_BQ25798_EN_BATOC = "en_batoc"
CONF_BQ25798_VOC_PCT = "voc_pct"
CONF_BQ25798_VOC_DLY = "voc_dly"
CONF_BQ25798_VOC_RATE = "voc_rate"
CONF_BQ25798_EN_MPPT = "en_mppt"
CONF_BQ25798_TREG = "treg"
CONF_BQ25798_TSHUT = "tshut"
CONF_BQ25798_VBUS_PD_EN = "vbus_pd_en"
CONF_BQ25798_VAC1_PD_EN = "vac1_pd_en"
CONF_BQ25798_VAC2_PD_EN = "vac2_pd_en"
CONF_BQ25798_BKUP_ACFET1_ON = "bkup_acfet1_on"
CONF_BQ25798_JEITA_VSET = "jeita_vset"
CONF_BQ25798_JEITA_ISETH = "jeita_iseth"
CONF_BQ25798_JEITA_ISETC = "jeita_isetc"
CONF_BQ25798_TS_COOL = "ts_cool"
CONF_BQ25798_TS_WARM = "ts_warm"
CONF_BQ25798_BHOT = "bhot"
CONF_BQ25798_TS_IGNORE = "ts_ignore"
CONF_BQ25798_ICO_ILIM = "ico_ilim"
CONF_BQ25798_CHG_STAT = "chg_stat"
CONF_BQ25798_VBUS_STAT = "vbus_stat"
CONF_BQ25798_BC12_DONE_STAT = "bc12_done_stat"
CONF_BQ25798_ICO_STAT = "ico_stat"
CONF_BQ25798_ADC_DONE_STAT = "adc_done_stat"
CONF_BQ25798_IBAT_REG_STAT = "ibat_reg_stat"
CONF_BQ25798_VBUS_OVP_STAT = "vbus_ovp_stat"
CONF_BQ25798_VBAT_OVP_STAT = "vbat_ovp_stat"
CONF_BQ25798_IBUS_OCP_STAT = "ibus_ocp_stat"
CONF_BQ25798_IBAT_OCP_STAT = "ibat_ocp_stat"
CONF_BQ25798_CONV_OCP_STAT = "conv_ocp_stat"
CONF_BQ25798_VAC2_OVP_STAT = "vac2_ovp_stat"
CONF_BQ25798_VAC1_OVP_STAT = "vac1_ovp_stat"
CONF_BQ25798_VSYS_SHORT_STAT = "vsys_short_stat"
CONF_BQ25798_VSYS_OVP_STAT = "vsys_ovp_stat"
CONF_BQ25798_OTG_OVP_STAT = "otg_ovp_stat"
CONF_BQ25798_OTG_UVP_STAT = "otg_uvp_stat"
CONF_BQ25798_TSHUT_STAT = "tshut_stat"
CONF_BQ25798_IINDPM_FLAG = "iindpm_flag"
CONF_BQ25798_VINDPM_FLAG = "vindpm_flag"
CONF_BQ25798_WD_FLAG = "wd_flag"
CONF_BQ25798_POORSRC_FLAG = "poorsrc_flag"
CONF_BQ25798_PG_FLAG = "pg_flag"
CONF_BQ25798_AC2_PRESENT_FLAG = "ac2_present_flag"
CONF_BQ25798_AC1_PRESENT_FLAG = "ac1_present_flag"
CONF_BQ25798_VBUS_PRESENT_FLAG = "vbus_present_flag"
CONF_BQ25798_CHG_FLAG = "chg_flag"
CONF_BQ25798_ICO_FLAG = "ico_flag"
CONF_BQ25798_VBUS_FLAG = "vbus_flag"
CONF_BQ25798_TREG_FLAG = "treg_flag"
CONF_BQ25798_VBAT_PRESENT_FLAG = "vbat_present_flag"
CONF_BQ25798_BC1_2_DONE_FLAG = "bc1_2_done_flag"
CONF_BQ25798_DPDM_DONE_FLAG = "dpdm_done_flag"
CONF_BQ25798_ADC_DONE_FLAG = "adc_done_flag"
CONF_BQ25798_VSYS_FLAG = "vsys_flag"
CONF_BQ25798_CHG_TMR_FLAG = "chg_tmr_flag"
CONF_BQ25798_TRICHG_TMR_FLAG = "trichg_tmr_flag"
CONF_BQ25798_PRECHG_TMR_FLAG = "prechg_tmr_flag"
CONF_BQ25798_TOPOFF_TMR_FLAG = "topoff_tmr_flag"
CONF_BQ25798_VBATOTG_LOW_FLAG = "vbatotg_low_flag"
CONF_BQ25798_TS_COLD_FLAG = "ts_cold_flag"
CONF_BQ25798_TS_COOL_FLAG = "ts_cool_flag"
CONF_BQ25798_TS_WARM_FLAG = "ts_warm_flag"
CONF_BQ25798_TS_HOT_FLAG = "ts_hot_flag"
CONF_BQ25798_IBAT_REG_FLAG = "ibat_reg_flag"
CONF_BQ25798_VBUS_OVP_FLAG = "vbus_ovp_flag"
CONF_BQ25798_VBAT_OVP_FLAG = "vbat_ovp_flag"
CONF_BQ25798_IBUS_OCP_FLAG = "ibus_ocp_flag"
CONF_BQ25798_IBAT_OCP_FLAG = "ibat_ocp_flag"
CONF_BQ25798_CONV_OCP_FLAG = "conv_ocp_flag"
CONF_BQ25798_VAC2_OVP_FLAG = "vac2_ovp_flag"
CONF_BQ25798_VAC1_OVP_FLAG = "vac1_ovp_flag"
CONF_BQ25798_VSYS_SHORT_FLAG = "vsys_short_flag"
CONF_BQ25798_VSYS_OVP_FLAG = "vsys_ovp_flag"
CONF_BQ25798_OTG_OVP_FLAG = "otg_ovp_flag"
CONF_BQ25798_OTG_UVP_FLAG = "otg_uvp_flag"
CONF_BQ25798_TSHUT_FLAG = "tshut_flag"
CONF_BQ25798_ADC_EN = "adc_en"
CONF_BQ25798_ADC_SAMPLE = "adc_sample"
CONF_BQ25798_ADC_AVG_INIT = "adc_avg_init"
CONF_BQ25798_IBUS_ADC_DIS = "ibus_adc_dis"
CONF_BQ25798_IBAT_ADC_DIS = "ibat_adc_dis"
CONF_BQ25798_VBUS_ADC_DIS = "vbus_adc_dis"
CONF_BQ25798_VBAT_ADC_DIS = "vbat_adc_dis"
CONF_BQ25798_VSYS_ADC_DIS = "vsys_adc_dis"
CONF_BQ25798_TS_ADC_DIS = "ts_adc_dis"
CONF_BQ25798_TDIE_ADC_DIS = "tdie_adc_dis"
CONF_BQ25798_DPLUS_ADC_DIS = "dplus_adc_dis"
CONF_BQ25798_DMINUS_ADC_DIS = "dminus_adc_dis"
CONF_BQ25798_VAC2_ADC_DIS = "vac2_adc_dis"
CONF_BQ25798_VAC1_ADC_DIS = "vac1_adc_dis"
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
ENUM_BQ25798_ACRB2_STAT = {
    "ACRB2_STAT_OFF": 0,
    "ACRB2_STAT_ON": 1,
}
ENUM_BQ25798_ACRB1_STAT = {
    "ACRB1_STAT_OFF": 0,
    "ACRB1_STAT_ON": 1,
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
    "VBATOTG_LOW_STAT_VBATOTG_OK": 0,
    "VBATOTG_LOW_STAT_VBATOTG_LOW": 1,
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
    sensor.sensor_schema(BQ25798Sensor)
    .extend(
        {
            cv.GenerateID(CONF_BQ25798_ID): cv.use_id(BQ25798Component),

            cv.Optional(CONF_BQ25798_VSYSMIN): sensor.sensor_schema(
                unit_of_measurement="mV",
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VREG): sensor.sensor_schema(
                unit_of_measurement="mV",
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
                unit_of_measurement="mV",
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
            cv.Optional(CONF_BQ25798_REG_RST): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_STOP_WD_CHG): sensor.sensor_schema(
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
                unit_of_measurement="mV",
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VOTG): sensor.sensor_schema(
                unit_of_measurement="mV",
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
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
            cv.Optional(CONF_BQ25798_EN_TRICHG_TMR): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_PRECHG_TMR): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_CHG_TMR): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_CHG_TMR): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TMR2X_EN): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_AUTO_IBATDIS): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_FORCE_IBATDIS): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_CHG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_ICO): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_FORCE_ICO): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_HIZ): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_TERM): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_BACKUP): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBUS_BACKUP): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VAC_OVP): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_WD_RST): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_WATCHDOG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_FORCE_INDET): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_AUTO_INDET_EN): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_12V): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_9V): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_HVDCP_EN): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_SDRV_CTRL): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DIS_ACDRV): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_OTG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_PFM_OTG_DIS): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_PFM_FWD_DIS): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DIS_LDO): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DIS_OTG_OOA): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DIS_FWD_OOA): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_ACDRV2): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_ACDRV1): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DIS_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DIS_VSYS_SHORT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DIS_VOTG_UVP): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_FORCE_VINDPM_DET): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_IBUS_OCP): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_SFET_PRESENT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_IBAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IBAT_REG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_IINDPM): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_EXTILIM): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_EN_BATOC): sensor.sensor_schema(
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
            cv.Optional(CONF_BQ25798_EN_MPPT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TREG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TSHUT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBUS_PD_EN): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VAC1_PD_EN): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VAC2_PD_EN): sensor.sensor_schema(
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
            cv.Optional(CONF_BQ25798_TS_IGNORE): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ICO_ILIM): sensor.sensor_schema(
                unit_of_measurement=UNIT_MILLIAMP,
                device_class=DEVICE_CLASS_CURRENT,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_CHG_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBUS_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_BC12_DONE_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ICO_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ADC_DONE_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IBAT_REG_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBUS_OVP_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBAT_OVP_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IBUS_OCP_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IBAT_OCP_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_CONV_OCP_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VAC2_OVP_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VAC1_OVP_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VSYS_SHORT_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VSYS_OVP_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_OTG_OVP_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_OTG_UVP_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TSHUT_STAT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IINDPM_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VINDPM_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_WD_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_POORSRC_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_PG_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_AC2_PRESENT_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_AC1_PRESENT_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBUS_PRESENT_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_CHG_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ICO_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBUS_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TREG_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBAT_PRESENT_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_BC1_2_DONE_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DPDM_DONE_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ADC_DONE_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VSYS_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_CHG_TMR_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TRICHG_TMR_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_PRECHG_TMR_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TOPOFF_TMR_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBATOTG_LOW_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TS_COLD_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TS_COOL_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TS_WARM_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TS_HOT_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IBAT_REG_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBUS_OVP_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBAT_OVP_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IBUS_OCP_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IBAT_OCP_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_CONV_OCP_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VAC2_OVP_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VAC1_OVP_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VSYS_SHORT_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VSYS_OVP_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_OTG_OVP_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_OTG_UVP_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TSHUT_FLAG): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ADC_EN): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ADC_SAMPLE): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_ADC_AVG_INIT): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IBUS_ADC_DIS): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_IBAT_ADC_DIS): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBUS_ADC_DIS): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBAT_ADC_DIS): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VSYS_ADC_DIS): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TS_ADC_DIS): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_TDIE_ADC_DIS): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DPLUS_ADC_DIS): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DMINUS_ADC_DIS): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VAC2_ADC_DIS): sensor.sensor_schema(
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VAC1_ADC_DIS): sensor.sensor_schema(
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
                unit_of_measurement="mV",
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VAC1_ADC): sensor.sensor_schema(
                unit_of_measurement="mV",
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VAC2_ADC): sensor.sensor_schema(
                unit_of_measurement="mV",
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VBAT_ADC): sensor.sensor_schema(
                unit_of_measurement="mV",
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_VSYS_ADC): sensor.sensor_schema(
                unit_of_measurement="mV",
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
                unit_of_measurement="mV",
                device_class=DEVICE_CLASS_VOLTAGE,
                accuracy_decimals=0,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Optional(CONF_BQ25798_DMINUS_ADC): sensor.sensor_schema(
                unit_of_measurement="mV",
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
    .extend(cv.polling_component_schema("1s"))
)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_parented(var, config[CONF_BQ25798_ID])
    await cg.register_component(var, config)

    if vsysmin := config.get(CONF_BQ25798_VSYSMIN):
        sens = await sensor.new_sensor(vsysmin)
        cg.add(var.assign_sensor_vsysmin(sens))
    if vreg := config.get(CONF_BQ25798_VREG):
        sens = await sensor.new_sensor(vreg)
        cg.add(var.assign_sensor_vreg(sens))
    if ichg := config.get(CONF_BQ25798_ICHG):
        sens = await sensor.new_sensor(ichg)
        cg.add(var.assign_sensor_ichg(sens))
    if vindpm := config.get(CONF_BQ25798_VINDPM):
        sens = await sensor.new_sensor(vindpm)
        cg.add(var.assign_sensor_vindpm(sens))
    if iindpm := config.get(CONF_BQ25798_IINDPM):
        sens = await sensor.new_sensor(iindpm)
        cg.add(var.assign_sensor_iindpm(sens))
    if vbat_lowv := config.get(CONF_BQ25798_VBAT_LOWV):
        sens = await sensor.new_sensor(vbat_lowv)
        cg.add(var.assign_sensor_vbat_lowv(sens))
    if iprechg := config.get(CONF_BQ25798_IPRECHG):
        sens = await sensor.new_sensor(iprechg)
        cg.add(var.assign_sensor_iprechg(sens))
    if reg_rst := config.get(CONF_BQ25798_REG_RST):
        sens = await sensor.new_sensor(reg_rst)
        cg.add(var.assign_sensor_reg_rst(sens))
    if stop_wd_chg := config.get(CONF_BQ25798_STOP_WD_CHG):
        sens = await sensor.new_sensor(stop_wd_chg)
        cg.add(var.assign_sensor_stop_wd_chg(sens))
    if iterm := config.get(CONF_BQ25798_ITERM):
        sens = await sensor.new_sensor(iterm)
        cg.add(var.assign_sensor_iterm(sens))
    if cell := config.get(CONF_BQ25798_CELL):
        sens = await sensor.new_sensor(cell)
        cg.add(var.assign_sensor_cell(sens))
    if trechg := config.get(CONF_BQ25798_TRECHG):
        sens = await sensor.new_sensor(trechg)
        cg.add(var.assign_sensor_trechg(sens))
    if vrechg := config.get(CONF_BQ25798_VRECHG):
        sens = await sensor.new_sensor(vrechg)
        cg.add(var.assign_sensor_vrechg(sens))
    if votg := config.get(CONF_BQ25798_VOTG):
        sens = await sensor.new_sensor(votg)
        cg.add(var.assign_sensor_votg(sens))
    if iotg := config.get(CONF_BQ25798_IOTG):
        sens = await sensor.new_sensor(iotg)
        cg.add(var.assign_sensor_iotg(sens))
    if topoff_tmr := config.get(CONF_BQ25798_TOPOFF_TMR):
        sens = await sensor.new_sensor(topoff_tmr)
        cg.add(var.assign_sensor_topoff_tmr(sens))
    if en_trichg_tmr := config.get(CONF_BQ25798_EN_TRICHG_TMR):
        sens = await sensor.new_sensor(en_trichg_tmr)
        cg.add(var.assign_sensor_en_trichg_tmr(sens))
    if en_prechg_tmr := config.get(CONF_BQ25798_EN_PRECHG_TMR):
        sens = await sensor.new_sensor(en_prechg_tmr)
        cg.add(var.assign_sensor_en_prechg_tmr(sens))
    if en_chg_tmr := config.get(CONF_BQ25798_EN_CHG_TMR):
        sens = await sensor.new_sensor(en_chg_tmr)
        cg.add(var.assign_sensor_en_chg_tmr(sens))
    if chg_tmr := config.get(CONF_BQ25798_CHG_TMR):
        sens = await sensor.new_sensor(chg_tmr)
        cg.add(var.assign_sensor_chg_tmr(sens))
    if tmr2x_en := config.get(CONF_BQ25798_TMR2X_EN):
        sens = await sensor.new_sensor(tmr2x_en)
        cg.add(var.assign_sensor_tmr2x_en(sens))
    if en_auto_ibatdis := config.get(CONF_BQ25798_EN_AUTO_IBATDIS):
        sens = await sensor.new_sensor(en_auto_ibatdis)
        cg.add(var.assign_sensor_en_auto_ibatdis(sens))
    if force_ibatdis := config.get(CONF_BQ25798_FORCE_IBATDIS):
        sens = await sensor.new_sensor(force_ibatdis)
        cg.add(var.assign_sensor_force_ibatdis(sens))
    if en_chg := config.get(CONF_BQ25798_EN_CHG):
        sens = await sensor.new_sensor(en_chg)
        cg.add(var.assign_sensor_en_chg(sens))
    if en_ico := config.get(CONF_BQ25798_EN_ICO):
        sens = await sensor.new_sensor(en_ico)
        cg.add(var.assign_sensor_en_ico(sens))
    if force_ico := config.get(CONF_BQ25798_FORCE_ICO):
        sens = await sensor.new_sensor(force_ico)
        cg.add(var.assign_sensor_force_ico(sens))
    if en_hiz := config.get(CONF_BQ25798_EN_HIZ):
        sens = await sensor.new_sensor(en_hiz)
        cg.add(var.assign_sensor_en_hiz(sens))
    if en_term := config.get(CONF_BQ25798_EN_TERM):
        sens = await sensor.new_sensor(en_term)
        cg.add(var.assign_sensor_en_term(sens))
    if en_backup := config.get(CONF_BQ25798_EN_BACKUP):
        sens = await sensor.new_sensor(en_backup)
        cg.add(var.assign_sensor_en_backup(sens))
    if vbus_backup := config.get(CONF_BQ25798_VBUS_BACKUP):
        sens = await sensor.new_sensor(vbus_backup)
        cg.add(var.assign_sensor_vbus_backup(sens))
    if vac_ovp := config.get(CONF_BQ25798_VAC_OVP):
        sens = await sensor.new_sensor(vac_ovp)
        cg.add(var.assign_sensor_vac_ovp(sens))
    if wd_rst := config.get(CONF_BQ25798_WD_RST):
        sens = await sensor.new_sensor(wd_rst)
        cg.add(var.assign_sensor_wd_rst(sens))
    if watchdog := config.get(CONF_BQ25798_WATCHDOG):
        sens = await sensor.new_sensor(watchdog)
        cg.add(var.assign_sensor_watchdog(sens))
    if force_indet := config.get(CONF_BQ25798_FORCE_INDET):
        sens = await sensor.new_sensor(force_indet)
        cg.add(var.assign_sensor_force_indet(sens))
    if auto_indet_en := config.get(CONF_BQ25798_AUTO_INDET_EN):
        sens = await sensor.new_sensor(auto_indet_en)
        cg.add(var.assign_sensor_auto_indet_en(sens))
    if en_12v := config.get(CONF_BQ25798_EN_12V):
        sens = await sensor.new_sensor(en_12v)
        cg.add(var.assign_sensor_en_12v(sens))
    if en_9v := config.get(CONF_BQ25798_EN_9V):
        sens = await sensor.new_sensor(en_9v)
        cg.add(var.assign_sensor_en_9v(sens))
    if hvdcp_en := config.get(CONF_BQ25798_HVDCP_EN):
        sens = await sensor.new_sensor(hvdcp_en)
        cg.add(var.assign_sensor_hvdcp_en(sens))
    if sdrv_ctrl := config.get(CONF_BQ25798_SDRV_CTRL):
        sens = await sensor.new_sensor(sdrv_ctrl)
        cg.add(var.assign_sensor_sdrv_ctrl(sens))
    if dis_acdrv := config.get(CONF_BQ25798_DIS_ACDRV):
        sens = await sensor.new_sensor(dis_acdrv)
        cg.add(var.assign_sensor_dis_acdrv(sens))
    if en_otg := config.get(CONF_BQ25798_EN_OTG):
        sens = await sensor.new_sensor(en_otg)
        cg.add(var.assign_sensor_en_otg(sens))
    if pfm_otg_dis := config.get(CONF_BQ25798_PFM_OTG_DIS):
        sens = await sensor.new_sensor(pfm_otg_dis)
        cg.add(var.assign_sensor_pfm_otg_dis(sens))
    if pfm_fwd_dis := config.get(CONF_BQ25798_PFM_FWD_DIS):
        sens = await sensor.new_sensor(pfm_fwd_dis)
        cg.add(var.assign_sensor_pfm_fwd_dis(sens))
    if dis_ldo := config.get(CONF_BQ25798_DIS_LDO):
        sens = await sensor.new_sensor(dis_ldo)
        cg.add(var.assign_sensor_dis_ldo(sens))
    if dis_otg_ooa := config.get(CONF_BQ25798_DIS_OTG_OOA):
        sens = await sensor.new_sensor(dis_otg_ooa)
        cg.add(var.assign_sensor_dis_otg_ooa(sens))
    if dis_fwd_ooa := config.get(CONF_BQ25798_DIS_FWD_OOA):
        sens = await sensor.new_sensor(dis_fwd_ooa)
        cg.add(var.assign_sensor_dis_fwd_ooa(sens))
    if en_acdrv2 := config.get(CONF_BQ25798_EN_ACDRV2):
        sens = await sensor.new_sensor(en_acdrv2)
        cg.add(var.assign_sensor_en_acdrv2(sens))
    if en_acdrv1 := config.get(CONF_BQ25798_EN_ACDRV1):
        sens = await sensor.new_sensor(en_acdrv1)
        cg.add(var.assign_sensor_en_acdrv1(sens))
    if dis_stat := config.get(CONF_BQ25798_DIS_STAT):
        sens = await sensor.new_sensor(dis_stat)
        cg.add(var.assign_sensor_dis_stat(sens))
    if dis_vsys_short := config.get(CONF_BQ25798_DIS_VSYS_SHORT):
        sens = await sensor.new_sensor(dis_vsys_short)
        cg.add(var.assign_sensor_dis_vsys_short(sens))
    if dis_votg_uvp := config.get(CONF_BQ25798_DIS_VOTG_UVP):
        sens = await sensor.new_sensor(dis_votg_uvp)
        cg.add(var.assign_sensor_dis_votg_uvp(sens))
    if force_vindpm_det := config.get(CONF_BQ25798_FORCE_VINDPM_DET):
        sens = await sensor.new_sensor(force_vindpm_det)
        cg.add(var.assign_sensor_force_vindpm_det(sens))
    if en_ibus_ocp := config.get(CONF_BQ25798_EN_IBUS_OCP):
        sens = await sensor.new_sensor(en_ibus_ocp)
        cg.add(var.assign_sensor_en_ibus_ocp(sens))
    if sfet_present := config.get(CONF_BQ25798_SFET_PRESENT):
        sens = await sensor.new_sensor(sfet_present)
        cg.add(var.assign_sensor_sfet_present(sens))
    if en_ibat := config.get(CONF_BQ25798_EN_IBAT):
        sens = await sensor.new_sensor(en_ibat)
        cg.add(var.assign_sensor_en_ibat(sens))
    if ibat_reg := config.get(CONF_BQ25798_IBAT_REG):
        sens = await sensor.new_sensor(ibat_reg)
        cg.add(var.assign_sensor_ibat_reg(sens))
    if en_iindpm := config.get(CONF_BQ25798_EN_IINDPM):
        sens = await sensor.new_sensor(en_iindpm)
        cg.add(var.assign_sensor_en_iindpm(sens))
    if en_extilim := config.get(CONF_BQ25798_EN_EXTILIM):
        sens = await sensor.new_sensor(en_extilim)
        cg.add(var.assign_sensor_en_extilim(sens))
    if en_batoc := config.get(CONF_BQ25798_EN_BATOC):
        sens = await sensor.new_sensor(en_batoc)
        cg.add(var.assign_sensor_en_batoc(sens))
    if voc_pct := config.get(CONF_BQ25798_VOC_PCT):
        sens = await sensor.new_sensor(voc_pct)
        cg.add(var.assign_sensor_voc_pct(sens))
    if voc_dly := config.get(CONF_BQ25798_VOC_DLY):
        sens = await sensor.new_sensor(voc_dly)
        cg.add(var.assign_sensor_voc_dly(sens))
    if voc_rate := config.get(CONF_BQ25798_VOC_RATE):
        sens = await sensor.new_sensor(voc_rate)
        cg.add(var.assign_sensor_voc_rate(sens))
    if en_mppt := config.get(CONF_BQ25798_EN_MPPT):
        sens = await sensor.new_sensor(en_mppt)
        cg.add(var.assign_sensor_en_mppt(sens))
    if treg := config.get(CONF_BQ25798_TREG):
        sens = await sensor.new_sensor(treg)
        cg.add(var.assign_sensor_treg(sens))
    if tshut := config.get(CONF_BQ25798_TSHUT):
        sens = await sensor.new_sensor(tshut)
        cg.add(var.assign_sensor_tshut(sens))
    if vbus_pd_en := config.get(CONF_BQ25798_VBUS_PD_EN):
        sens = await sensor.new_sensor(vbus_pd_en)
        cg.add(var.assign_sensor_vbus_pd_en(sens))
    if vac1_pd_en := config.get(CONF_BQ25798_VAC1_PD_EN):
        sens = await sensor.new_sensor(vac1_pd_en)
        cg.add(var.assign_sensor_vac1_pd_en(sens))
    if vac2_pd_en := config.get(CONF_BQ25798_VAC2_PD_EN):
        sens = await sensor.new_sensor(vac2_pd_en)
        cg.add(var.assign_sensor_vac2_pd_en(sens))
    if bkup_acfet1_on := config.get(CONF_BQ25798_BKUP_ACFET1_ON):
        sens = await sensor.new_sensor(bkup_acfet1_on)
        cg.add(var.assign_sensor_bkup_acfet1_on(sens))
    if jeita_vset := config.get(CONF_BQ25798_JEITA_VSET):
        sens = await sensor.new_sensor(jeita_vset)
        cg.add(var.assign_sensor_jeita_vset(sens))
    if jeita_iseth := config.get(CONF_BQ25798_JEITA_ISETH):
        sens = await sensor.new_sensor(jeita_iseth)
        cg.add(var.assign_sensor_jeita_iseth(sens))
    if jeita_isetc := config.get(CONF_BQ25798_JEITA_ISETC):
        sens = await sensor.new_sensor(jeita_isetc)
        cg.add(var.assign_sensor_jeita_isetc(sens))
    if ts_cool := config.get(CONF_BQ25798_TS_COOL):
        sens = await sensor.new_sensor(ts_cool)
        cg.add(var.assign_sensor_ts_cool(sens))
    if ts_warm := config.get(CONF_BQ25798_TS_WARM):
        sens = await sensor.new_sensor(ts_warm)
        cg.add(var.assign_sensor_ts_warm(sens))
    if bhot := config.get(CONF_BQ25798_BHOT):
        sens = await sensor.new_sensor(bhot)
        cg.add(var.assign_sensor_bhot(sens))
    if ts_ignore := config.get(CONF_BQ25798_TS_IGNORE):
        sens = await sensor.new_sensor(ts_ignore)
        cg.add(var.assign_sensor_ts_ignore(sens))
    if ico_ilim := config.get(CONF_BQ25798_ICO_ILIM):
        sens = await sensor.new_sensor(ico_ilim)
        cg.add(var.assign_sensor_ico_ilim(sens))
    if chg_stat := config.get(CONF_BQ25798_CHG_STAT):
        sens = await sensor.new_sensor(chg_stat)
        cg.add(var.assign_sensor_chg_stat(sens))
    if vbus_stat := config.get(CONF_BQ25798_VBUS_STAT):
        sens = await sensor.new_sensor(vbus_stat)
        cg.add(var.assign_sensor_vbus_stat(sens))
    if bc12_done_stat := config.get(CONF_BQ25798_BC12_DONE_STAT):
        sens = await sensor.new_sensor(bc12_done_stat)
        cg.add(var.assign_sensor_bc12_done_stat(sens))
    if ico_stat := config.get(CONF_BQ25798_ICO_STAT):
        sens = await sensor.new_sensor(ico_stat)
        cg.add(var.assign_sensor_ico_stat(sens))
    if adc_done_stat := config.get(CONF_BQ25798_ADC_DONE_STAT):
        sens = await sensor.new_sensor(adc_done_stat)
        cg.add(var.assign_sensor_adc_done_stat(sens))
    if ibat_reg_stat := config.get(CONF_BQ25798_IBAT_REG_STAT):
        sens = await sensor.new_sensor(ibat_reg_stat)
        cg.add(var.assign_sensor_ibat_reg_stat(sens))
    if vbus_ovp_stat := config.get(CONF_BQ25798_VBUS_OVP_STAT):
        sens = await sensor.new_sensor(vbus_ovp_stat)
        cg.add(var.assign_sensor_vbus_ovp_stat(sens))
    if vbat_ovp_stat := config.get(CONF_BQ25798_VBAT_OVP_STAT):
        sens = await sensor.new_sensor(vbat_ovp_stat)
        cg.add(var.assign_sensor_vbat_ovp_stat(sens))
    if ibus_ocp_stat := config.get(CONF_BQ25798_IBUS_OCP_STAT):
        sens = await sensor.new_sensor(ibus_ocp_stat)
        cg.add(var.assign_sensor_ibus_ocp_stat(sens))
    if ibat_ocp_stat := config.get(CONF_BQ25798_IBAT_OCP_STAT):
        sens = await sensor.new_sensor(ibat_ocp_stat)
        cg.add(var.assign_sensor_ibat_ocp_stat(sens))
    if conv_ocp_stat := config.get(CONF_BQ25798_CONV_OCP_STAT):
        sens = await sensor.new_sensor(conv_ocp_stat)
        cg.add(var.assign_sensor_conv_ocp_stat(sens))
    if vac2_ovp_stat := config.get(CONF_BQ25798_VAC2_OVP_STAT):
        sens = await sensor.new_sensor(vac2_ovp_stat)
        cg.add(var.assign_sensor_vac2_ovp_stat(sens))
    if vac1_ovp_stat := config.get(CONF_BQ25798_VAC1_OVP_STAT):
        sens = await sensor.new_sensor(vac1_ovp_stat)
        cg.add(var.assign_sensor_vac1_ovp_stat(sens))
    if vsys_short_stat := config.get(CONF_BQ25798_VSYS_SHORT_STAT):
        sens = await sensor.new_sensor(vsys_short_stat)
        cg.add(var.assign_sensor_vsys_short_stat(sens))
    if vsys_ovp_stat := config.get(CONF_BQ25798_VSYS_OVP_STAT):
        sens = await sensor.new_sensor(vsys_ovp_stat)
        cg.add(var.assign_sensor_vsys_ovp_stat(sens))
    if otg_ovp_stat := config.get(CONF_BQ25798_OTG_OVP_STAT):
        sens = await sensor.new_sensor(otg_ovp_stat)
        cg.add(var.assign_sensor_otg_ovp_stat(sens))
    if otg_uvp_stat := config.get(CONF_BQ25798_OTG_UVP_STAT):
        sens = await sensor.new_sensor(otg_uvp_stat)
        cg.add(var.assign_sensor_otg_uvp_stat(sens))
    if tshut_stat := config.get(CONF_BQ25798_TSHUT_STAT):
        sens = await sensor.new_sensor(tshut_stat)
        cg.add(var.assign_sensor_tshut_stat(sens))
    if iindpm_flag := config.get(CONF_BQ25798_IINDPM_FLAG):
        sens = await sensor.new_sensor(iindpm_flag)
        cg.add(var.assign_sensor_iindpm_flag(sens))
    if vindpm_flag := config.get(CONF_BQ25798_VINDPM_FLAG):
        sens = await sensor.new_sensor(vindpm_flag)
        cg.add(var.assign_sensor_vindpm_flag(sens))
    if wd_flag := config.get(CONF_BQ25798_WD_FLAG):
        sens = await sensor.new_sensor(wd_flag)
        cg.add(var.assign_sensor_wd_flag(sens))
    if poorsrc_flag := config.get(CONF_BQ25798_POORSRC_FLAG):
        sens = await sensor.new_sensor(poorsrc_flag)
        cg.add(var.assign_sensor_poorsrc_flag(sens))
    if pg_flag := config.get(CONF_BQ25798_PG_FLAG):
        sens = await sensor.new_sensor(pg_flag)
        cg.add(var.assign_sensor_pg_flag(sens))
    if ac2_present_flag := config.get(CONF_BQ25798_AC2_PRESENT_FLAG):
        sens = await sensor.new_sensor(ac2_present_flag)
        cg.add(var.assign_sensor_ac2_present_flag(sens))
    if ac1_present_flag := config.get(CONF_BQ25798_AC1_PRESENT_FLAG):
        sens = await sensor.new_sensor(ac1_present_flag)
        cg.add(var.assign_sensor_ac1_present_flag(sens))
    if vbus_present_flag := config.get(CONF_BQ25798_VBUS_PRESENT_FLAG):
        sens = await sensor.new_sensor(vbus_present_flag)
        cg.add(var.assign_sensor_vbus_present_flag(sens))
    if chg_flag := config.get(CONF_BQ25798_CHG_FLAG):
        sens = await sensor.new_sensor(chg_flag)
        cg.add(var.assign_sensor_chg_flag(sens))
    if ico_flag := config.get(CONF_BQ25798_ICO_FLAG):
        sens = await sensor.new_sensor(ico_flag)
        cg.add(var.assign_sensor_ico_flag(sens))
    if vbus_flag := config.get(CONF_BQ25798_VBUS_FLAG):
        sens = await sensor.new_sensor(vbus_flag)
        cg.add(var.assign_sensor_vbus_flag(sens))
    if treg_flag := config.get(CONF_BQ25798_TREG_FLAG):
        sens = await sensor.new_sensor(treg_flag)
        cg.add(var.assign_sensor_treg_flag(sens))
    if vbat_present_flag := config.get(CONF_BQ25798_VBAT_PRESENT_FLAG):
        sens = await sensor.new_sensor(vbat_present_flag)
        cg.add(var.assign_sensor_vbat_present_flag(sens))
    if bc1_2_done_flag := config.get(CONF_BQ25798_BC1_2_DONE_FLAG):
        sens = await sensor.new_sensor(bc1_2_done_flag)
        cg.add(var.assign_sensor_bc1_2_done_flag(sens))
    if dpdm_done_flag := config.get(CONF_BQ25798_DPDM_DONE_FLAG):
        sens = await sensor.new_sensor(dpdm_done_flag)
        cg.add(var.assign_sensor_dpdm_done_flag(sens))
    if adc_done_flag := config.get(CONF_BQ25798_ADC_DONE_FLAG):
        sens = await sensor.new_sensor(adc_done_flag)
        cg.add(var.assign_sensor_adc_done_flag(sens))
    if vsys_flag := config.get(CONF_BQ25798_VSYS_FLAG):
        sens = await sensor.new_sensor(vsys_flag)
        cg.add(var.assign_sensor_vsys_flag(sens))
    if chg_tmr_flag := config.get(CONF_BQ25798_CHG_TMR_FLAG):
        sens = await sensor.new_sensor(chg_tmr_flag)
        cg.add(var.assign_sensor_chg_tmr_flag(sens))
    if trichg_tmr_flag := config.get(CONF_BQ25798_TRICHG_TMR_FLAG):
        sens = await sensor.new_sensor(trichg_tmr_flag)
        cg.add(var.assign_sensor_trichg_tmr_flag(sens))
    if prechg_tmr_flag := config.get(CONF_BQ25798_PRECHG_TMR_FLAG):
        sens = await sensor.new_sensor(prechg_tmr_flag)
        cg.add(var.assign_sensor_prechg_tmr_flag(sens))
    if topoff_tmr_flag := config.get(CONF_BQ25798_TOPOFF_TMR_FLAG):
        sens = await sensor.new_sensor(topoff_tmr_flag)
        cg.add(var.assign_sensor_topoff_tmr_flag(sens))
    if vbatotg_low_flag := config.get(CONF_BQ25798_VBATOTG_LOW_FLAG):
        sens = await sensor.new_sensor(vbatotg_low_flag)
        cg.add(var.assign_sensor_vbatotg_low_flag(sens))
    if ts_cold_flag := config.get(CONF_BQ25798_TS_COLD_FLAG):
        sens = await sensor.new_sensor(ts_cold_flag)
        cg.add(var.assign_sensor_ts_cold_flag(sens))
    if ts_cool_flag := config.get(CONF_BQ25798_TS_COOL_FLAG):
        sens = await sensor.new_sensor(ts_cool_flag)
        cg.add(var.assign_sensor_ts_cool_flag(sens))
    if ts_warm_flag := config.get(CONF_BQ25798_TS_WARM_FLAG):
        sens = await sensor.new_sensor(ts_warm_flag)
        cg.add(var.assign_sensor_ts_warm_flag(sens))
    if ts_hot_flag := config.get(CONF_BQ25798_TS_HOT_FLAG):
        sens = await sensor.new_sensor(ts_hot_flag)
        cg.add(var.assign_sensor_ts_hot_flag(sens))
    if ibat_reg_flag := config.get(CONF_BQ25798_IBAT_REG_FLAG):
        sens = await sensor.new_sensor(ibat_reg_flag)
        cg.add(var.assign_sensor_ibat_reg_flag(sens))
    if vbus_ovp_flag := config.get(CONF_BQ25798_VBUS_OVP_FLAG):
        sens = await sensor.new_sensor(vbus_ovp_flag)
        cg.add(var.assign_sensor_vbus_ovp_flag(sens))
    if vbat_ovp_flag := config.get(CONF_BQ25798_VBAT_OVP_FLAG):
        sens = await sensor.new_sensor(vbat_ovp_flag)
        cg.add(var.assign_sensor_vbat_ovp_flag(sens))
    if ibus_ocp_flag := config.get(CONF_BQ25798_IBUS_OCP_FLAG):
        sens = await sensor.new_sensor(ibus_ocp_flag)
        cg.add(var.assign_sensor_ibus_ocp_flag(sens))
    if ibat_ocp_flag := config.get(CONF_BQ25798_IBAT_OCP_FLAG):
        sens = await sensor.new_sensor(ibat_ocp_flag)
        cg.add(var.assign_sensor_ibat_ocp_flag(sens))
    if conv_ocp_flag := config.get(CONF_BQ25798_CONV_OCP_FLAG):
        sens = await sensor.new_sensor(conv_ocp_flag)
        cg.add(var.assign_sensor_conv_ocp_flag(sens))
    if vac2_ovp_flag := config.get(CONF_BQ25798_VAC2_OVP_FLAG):
        sens = await sensor.new_sensor(vac2_ovp_flag)
        cg.add(var.assign_sensor_vac2_ovp_flag(sens))
    if vac1_ovp_flag := config.get(CONF_BQ25798_VAC1_OVP_FLAG):
        sens = await sensor.new_sensor(vac1_ovp_flag)
        cg.add(var.assign_sensor_vac1_ovp_flag(sens))
    if vsys_short_flag := config.get(CONF_BQ25798_VSYS_SHORT_FLAG):
        sens = await sensor.new_sensor(vsys_short_flag)
        cg.add(var.assign_sensor_vsys_short_flag(sens))
    if vsys_ovp_flag := config.get(CONF_BQ25798_VSYS_OVP_FLAG):
        sens = await sensor.new_sensor(vsys_ovp_flag)
        cg.add(var.assign_sensor_vsys_ovp_flag(sens))
    if otg_ovp_flag := config.get(CONF_BQ25798_OTG_OVP_FLAG):
        sens = await sensor.new_sensor(otg_ovp_flag)
        cg.add(var.assign_sensor_otg_ovp_flag(sens))
    if otg_uvp_flag := config.get(CONF_BQ25798_OTG_UVP_FLAG):
        sens = await sensor.new_sensor(otg_uvp_flag)
        cg.add(var.assign_sensor_otg_uvp_flag(sens))
    if tshut_flag := config.get(CONF_BQ25798_TSHUT_FLAG):
        sens = await sensor.new_sensor(tshut_flag)
        cg.add(var.assign_sensor_tshut_flag(sens))
    if adc_en := config.get(CONF_BQ25798_ADC_EN):
        sens = await sensor.new_sensor(adc_en)
        cg.add(var.assign_sensor_adc_en(sens))
    if adc_sample := config.get(CONF_BQ25798_ADC_SAMPLE):
        sens = await sensor.new_sensor(adc_sample)
        cg.add(var.assign_sensor_adc_sample(sens))
    if adc_avg_init := config.get(CONF_BQ25798_ADC_AVG_INIT):
        sens = await sensor.new_sensor(adc_avg_init)
        cg.add(var.assign_sensor_adc_avg_init(sens))
    if ibus_adc_dis := config.get(CONF_BQ25798_IBUS_ADC_DIS):
        sens = await sensor.new_sensor(ibus_adc_dis)
        cg.add(var.assign_sensor_ibus_adc_dis(sens))
    if ibat_adc_dis := config.get(CONF_BQ25798_IBAT_ADC_DIS):
        sens = await sensor.new_sensor(ibat_adc_dis)
        cg.add(var.assign_sensor_ibat_adc_dis(sens))
    if vbus_adc_dis := config.get(CONF_BQ25798_VBUS_ADC_DIS):
        sens = await sensor.new_sensor(vbus_adc_dis)
        cg.add(var.assign_sensor_vbus_adc_dis(sens))
    if vbat_adc_dis := config.get(CONF_BQ25798_VBAT_ADC_DIS):
        sens = await sensor.new_sensor(vbat_adc_dis)
        cg.add(var.assign_sensor_vbat_adc_dis(sens))
    if vsys_adc_dis := config.get(CONF_BQ25798_VSYS_ADC_DIS):
        sens = await sensor.new_sensor(vsys_adc_dis)
        cg.add(var.assign_sensor_vsys_adc_dis(sens))
    if ts_adc_dis := config.get(CONF_BQ25798_TS_ADC_DIS):
        sens = await sensor.new_sensor(ts_adc_dis)
        cg.add(var.assign_sensor_ts_adc_dis(sens))
    if tdie_adc_dis := config.get(CONF_BQ25798_TDIE_ADC_DIS):
        sens = await sensor.new_sensor(tdie_adc_dis)
        cg.add(var.assign_sensor_tdie_adc_dis(sens))
    if dplus_adc_dis := config.get(CONF_BQ25798_DPLUS_ADC_DIS):
        sens = await sensor.new_sensor(dplus_adc_dis)
        cg.add(var.assign_sensor_dplus_adc_dis(sens))
    if dminus_adc_dis := config.get(CONF_BQ25798_DMINUS_ADC_DIS):
        sens = await sensor.new_sensor(dminus_adc_dis)
        cg.add(var.assign_sensor_dminus_adc_dis(sens))
    if vac2_adc_dis := config.get(CONF_BQ25798_VAC2_ADC_DIS):
        sens = await sensor.new_sensor(vac2_adc_dis)
        cg.add(var.assign_sensor_vac2_adc_dis(sens))
    if vac1_adc_dis := config.get(CONF_BQ25798_VAC1_ADC_DIS):
        sens = await sensor.new_sensor(vac1_adc_dis)
        cg.add(var.assign_sensor_vac1_adc_dis(sens))
    if ibus_adc := config.get(CONF_BQ25798_IBUS_ADC):
        sens = await sensor.new_sensor(ibus_adc)
        cg.add(var.assign_sensor_ibus_adc(sens))
    if ibat_adc := config.get(CONF_BQ25798_IBAT_ADC):
        sens = await sensor.new_sensor(ibat_adc)
        cg.add(var.assign_sensor_ibat_adc(sens))
    if vbus_adc := config.get(CONF_BQ25798_VBUS_ADC):
        sens = await sensor.new_sensor(vbus_adc)
        cg.add(var.assign_sensor_vbus_adc(sens))
    if vac1_adc := config.get(CONF_BQ25798_VAC1_ADC):
        sens = await sensor.new_sensor(vac1_adc)
        cg.add(var.assign_sensor_vac1_adc(sens))
    if vac2_adc := config.get(CONF_BQ25798_VAC2_ADC):
        sens = await sensor.new_sensor(vac2_adc)
        cg.add(var.assign_sensor_vac2_adc(sens))
    if vbat_adc := config.get(CONF_BQ25798_VBAT_ADC):
        sens = await sensor.new_sensor(vbat_adc)
        cg.add(var.assign_sensor_vbat_adc(sens))
    if vsys_adc := config.get(CONF_BQ25798_VSYS_ADC):
        sens = await sensor.new_sensor(vsys_adc)
        cg.add(var.assign_sensor_vsys_adc(sens))
    if ts_adc := config.get(CONF_BQ25798_TS_ADC):
        sens = await sensor.new_sensor(ts_adc)
        cg.add(var.assign_sensor_ts_adc(sens))
    if tdie_adc := config.get(CONF_BQ25798_TDIE_ADC):
        sens = await sensor.new_sensor(tdie_adc)
        cg.add(var.assign_sensor_tdie_adc(sens))
    if dplus_adc := config.get(CONF_BQ25798_DPLUS_ADC):
        sens = await sensor.new_sensor(dplus_adc)
        cg.add(var.assign_sensor_dplus_adc(sens))
    if dminus_adc := config.get(CONF_BQ25798_DMINUS_ADC):
        sens = await sensor.new_sensor(dminus_adc)
        cg.add(var.assign_sensor_dminus_adc(sens))
    if dplus_dac := config.get(CONF_BQ25798_DPLUS_DAC):
        sens = await sensor.new_sensor(dplus_dac)
        cg.add(var.assign_sensor_dplus_dac(sens))
    if dminus_dac := config.get(CONF_BQ25798_DMINUS_DAC):
        sens = await sensor.new_sensor(dminus_dac)
        cg.add(var.assign_sensor_dminus_dac(sens))
    if pn := config.get(CONF_BQ25798_PN):
        sens = await sensor.new_sensor(pn)
        cg.add(var.assign_sensor_pn(sens))
    if dev_rev := config.get(CONF_BQ25798_DEV_REV):
        sens = await sensor.new_sensor(dev_rev)
        cg.add(var.assign_sensor_dev_rev(sens))
