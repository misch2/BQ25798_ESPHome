import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c
from esphome.const import CONF_ID

DEPENDENCIES = ["i2c"]

bq25798_ns = cg.esphome_ns.namespace("bq25798")
BQ25798Component = bq25798_ns.class_("BQ25798Component", cg.Component, i2c.I2CDevice)

# Settings
CONF_VSYSMIN = "vsysmin"
CONF_VREG = "vreg"
CONF_ICHG = "ichg"
CONF_VINDPM = "vindpm"
CONF_IINDPM = "iindpm"
CONF_VBAT_LOWV = "vbat_lowv"
CONF_IPRECHG = "iprechg"
CONF_REG_RST = "reg_rst"
CONF_STOP_WD_CHG = "stop_wd_chg"
CONF_ITERM = "iterm"
CONF_CELL = "cell"
CONF_TRECHG = "trechg"
CONF_VRECHG = "vrechg"
CONF_VOTG = "votg"
CONF_PRECHG_TMR = "prechg_tmr"
CONF_IOTG = "iotg"
CONF_TOPOFF_TMR = "topoff_tmr"
CONF_EN_TRICHG_TMR = "en_trichg_tmr"
CONF_EN_PRECHG_TMR = "en_prechg_tmr"
CONF_EN_CHG_TMR = "en_chg_tmr"
CONF_CHG_TMR = "chg_tmr"
CONF_TMR2X_EN = "tmr2x_en"
CONF_EN_AUTO_IBATDIS = "en_auto_ibatdis"
CONF_FORCE_IBATDIS = "force_ibatdis"
CONF_EN_CHG = "en_chg"
CONF_EN_ICO = "en_ico"
CONF_FORCE_ICO = "force_ico"
CONF_EN_HIZ = "en_hiz"
CONF_EN_TERM = "en_term"
CONF_EN_BACKUP = "en_backup"
CONF_VBUS_BACKUP = "vbus_backup"
CONF_VAC_OVP = "vac_ovp"
CONF_WD_RST = "wd_rst"
CONF_WATCHDOG = "watchdog"
CONF_FORCE_INDET = "force_indet"
CONF_AUTO_INDET_EN = "auto_indet_en"
CONF_EN_12V = "en_12v"
CONF_EN_9V = "en_9v"
CONF_HVDCP_EN = "hvdcp_en"
CONF_SDRV_CTRL = "sdrv_ctrl"
CONF_SDRV_DLY = "sdrv_dly"
CONF_DIS_ACDRV = "dis_acdrv"
CONF_EN_OTG = "en_otg"
CONF_PFM_OTG_DIS = "pfm_otg_dis"
CONF_PFM_FWD_DIS = "pfm_fwd_dis"
CONF_WKUP_DLY = "wkup_dly"
CONF_DIS_LDO = "dis_ldo"
CONF_DIS_OTG_OOA = "dis_otg_ooa"
CONF_DIS_FWD_OOA = "dis_fwd_ooa"
CONF_EN_ACDRV2 = "en_acdrv2"
CONF_EN_ACDRV1 = "en_acdrv1"
CONF_PWM_FREQ = "pwm_freq"
CONF_DIS_STAT = "dis_stat"
CONF_DIS_VSYS_SHORT = "dis_vsys_short"
CONF_DIS_VOTG_UVP = "dis_votg_uvp"
CONF_FORCE_VINDPM_DET = "force_vindpm_det"
CONF_EN_IBUS_OCP = "en_ibus_ocp"
CONF_SFET_PRESENT = "sfet_present"
CONF_EN_IBAT = "en_ibat"
CONF_IBAT_REG = "ibat_reg"
CONF_EN_IINDPM = "en_iindpm"
CONF_EN_EXTILIM = "en_extilim"
CONF_EN_BATOC = "en_batoc"
CONF_VOC_PCT = "voc_pct"
CONF_VOC_DLY = "voc_dly"
CONF_VOC_RATE = "voc_rate"
CONF_EN_MPPT = "en_mppt"
CONF_TREG = "treg"
CONF_TSHUT = "tshut"
CONF_VBUS_PD_EN = "vbus_pd_en"
CONF_VAC1_PD_EN = "vac1_pd_en"
CONF_VAC2_PD_EN = "vac2_pd_en"
CONF_BKUP_ACFET1_ON = "bkup_acfet1_on"
CONF_JEITA_VSET = "jeita_vset"
CONF_JEITA_ISETH = "jeita_iseth"
CONF_JEITA_ISETC = "jeita_isetc"
CONF_TS_COOL = "ts_cool"
CONF_TS_WARM = "ts_warm"
CONF_BHOT = "bhot"
CONF_BCOLD = "bcold"
CONF_TS_IGNORE = "ts_ignore"
CONF_ICO_ILIM = "ico_ilim"
CONF_IINDPM_STAT = "iindpm_stat"
CONF_VINDPM_STAT = "vindpm_stat"
CONF_WD_STAT = "wd_stat"
CONF_PG_STAT = "pg_stat"
CONF_AC2_PRESENT_STAT = "ac2_present_stat"
CONF_AC1_PRESENT_STAT = "ac1_present_stat"
CONF_VBUS_PRESENT_STAT = "vbus_present_stat"
CONF_CHG_STAT = "chg_stat"
CONF_VBUS_STAT = "vbus_stat"
CONF_BC12_DONE_STAT = "bc12_done_stat"
CONF_ICO_STAT = "ico_stat"
CONF_TREG_STAT = "treg_stat"
CONF_DPDM_STAT = "dpdm_stat"
CONF_VBAT_PRESENT_STAT = "vbat_present_stat"
CONF_ACRB2_STAT = "acrb2_stat"
CONF_ACRB1_STAT = "acrb1_stat"
CONF_ADC_DONE_STAT = "adc_done_stat"
CONF_VSYS_STAT = "vsys_stat"
CONF_CHG_TMR_STAT = "chg_tmr_stat"
CONF_TRICHG_TMR_STAT = "trichg_tmr_stat"
CONF_PRECHG_TMR_STAT = "prechg_tmr_stat"
CONF_VBATOTG_LOW_STAT = "vbatotg_low_stat"
CONF_TS_COLD_STAT = "ts_cold_stat"
CONF_TS_COOL_STAT = "ts_cool_stat"
CONF_TS_WARM_STAT = "ts_warm_stat"
CONF_TS_HOT_STAT = "ts_hot_stat"
CONF_IBAT_REG_STAT = "ibat_reg_stat"
CONF_VBUS_OVP_STAT = "vbus_ovp_stat"
CONF_VBAT_OVP_STAT = "vbat_ovp_stat"
CONF_IBUS_OCP_STAT = "ibus_ocp_stat"
CONF_IBAT_OCP_STAT = "ibat_ocp_stat"
CONF_CONV_OCP_STAT = "conv_ocp_stat"
CONF_VAC2_OVP_STAT = "vac2_ovp_stat"
CONF_VAC1_OVP_STAT = "vac1_ovp_stat"
CONF_VSYS_SHORT_STAT = "vsys_short_stat"
CONF_VSYS_OVP_STAT = "vsys_ovp_stat"
CONF_OTG_OVP_STAT = "otg_ovp_stat"
CONF_OTG_UVP_STAT = "otg_uvp_stat"
CONF_TSHUT_STAT = "tshut_stat"
CONF_IINDPM_FLAG = "iindpm_flag"
CONF_VINDPM_FLAG = "vindpm_flag"
CONF_WD_FLAG = "wd_flag"
CONF_POORSRC_FLAG = "poorsrc_flag"
CONF_PG_FLAG = "pg_flag"
CONF_AC2_PRESENT_FLAG = "ac2_present_flag"
CONF_AC1_PRESENT_FLAG = "ac1_present_flag"
CONF_VBUS_PRESENT_FLAG = "vbus_present_flag"
CONF_CHG_FLAG = "chg_flag"
CONF_ICO_FLAG = "ico_flag"
CONF_VBUS_FLAG = "vbus_flag"
CONF_TREG_FLAG = "treg_flag"
CONF_VBAT_PRESENT_FLAG = "vbat_present_flag"
CONF_BC1_2_DONE_FLAG = "bc1_2_done_flag"
CONF_DPDM_DONE_FLAG = "dpdm_done_flag"
CONF_ADC_DONE_FLAG = "adc_done_flag"
CONF_VSYS_FLAG = "vsys_flag"
CONF_CHG_TMR_FLAG = "chg_tmr_flag"
CONF_TRICHG_TMR_FLAG = "trichg_tmr_flag"
CONF_PRECHG_TMR_FLAG = "prechg_tmr_flag"
CONF_TOPOFF_TMR_FLAG = "topoff_tmr_flag"
CONF_VBATOTG_LOW_FLAG = "vbatotg_low_flag"
CONF_TS_COLD_FLAG = "ts_cold_flag"
CONF_TS_COOL_FLAG = "ts_cool_flag"
CONF_TS_WARM_FLAG = "ts_warm_flag"
CONF_TS_HOT_FLAG = "ts_hot_flag"
CONF_IBAT_REG_FLAG = "ibat_reg_flag"
CONF_VBUS_OVP_FLAG = "vbus_ovp_flag"
CONF_VBAT_OVP_FLAG = "vbat_ovp_flag"
CONF_IBUS_OCP_FLAG = "ibus_ocp_flag"
CONF_IBAT_OCP_FLAG = "ibat_ocp_flag"
CONF_CONV_OCP_FLAG = "conv_ocp_flag"
CONF_VAC2_OVP_FLAG = "vac2_ovp_flag"
CONF_VAC1_OVP_FLAG = "vac1_ovp_flag"
CONF_VSYS_SHORT_FLAG = "vsys_short_flag"
CONF_VSYS_OVP_FLAG = "vsys_ovp_flag"
CONF_OTG_OVP_FLAG = "otg_ovp_flag"
CONF_OTG_UVP_FLAG = "otg_uvp_flag"
CONF_TSHUT_FLAG = "tshut_flag"
CONF_ADC_EN = "adc_en"
CONF_ADC_RATE = "adc_rate"
CONF_ADC_SAMPLE = "adc_sample"
CONF_ADC_AVG = "adc_avg"
CONF_ADC_AVG_INIT = "adc_avg_init"
CONF_IBUS_ADC_DIS = "ibus_adc_dis"
CONF_IBAT_ADC_DIS = "ibat_adc_dis"
CONF_VBUS_ADC_DIS = "vbus_adc_dis"
CONF_VBAT_ADC_DIS = "vbat_adc_dis"
CONF_VSYS_ADC_DIS = "vsys_adc_dis"
CONF_TS_ADC_DIS = "ts_adc_dis"
CONF_TDIE_ADC_DIS = "tdie_adc_dis"
CONF_DPLUS_ADC_DIS = "dplus_adc_dis"
CONF_DMINUS_ADC_DIS = "dminus_adc_dis"
CONF_VAC2_ADC_DIS = "vac2_adc_dis"
CONF_VAC1_ADC_DIS = "vac1_adc_dis"
CONF_IBUS_ADC = "ibus_adc"
CONF_IBAT_ADC = "ibat_adc"
CONF_VBUS_ADC = "vbus_adc"
CONF_VAC1_ADC = "vac1_adc"
CONF_VAC2_ADC = "vac2_adc"
CONF_VBAT_ADC = "vbat_adc"
CONF_VSYS_ADC = "vsys_adc"
CONF_TS_ADC = "ts_adc"
CONF_TDIE_ADC = "tdie_adc"
CONF_DPLUS_ADC = "dplus_adc"
CONF_DMINUS_ADC = "dminus_adc"
CONF_DPLUS_DAC = "dplus_dac"
CONF_DMINUS_DAC = "dminus_dac"
CONF_PN = "pn"
CONF_DEV_REV = "dev_rev"

# Configuration schema
ENUM_VBAT_LOWV = {
    "VBAT_LOWV_PCT_15": 0,
    "VBAT_LOWV_PCT_62": 1,
    "VBAT_LOWV_PCT_67": 2,
    "VBAT_LOWV_PCT_71": 3,
}
ENUM_CELL = {
    "CELL_1S": 0,
    "CELL_2S": 1,
    "CELL_3S": 2,
    "CELL_4S": 3,
}
ENUM_TRECHG = {
    "TRECHG_64MS": 0,
    "TRECHG_256MS": 1,
    "TRECHG_1024MS": 2,
    "TRECHG_2048MS": 3,
}
ENUM_PRECHG_TMR = {
    "PRECHG_TMR_2HRS": 0,
    "PRECHG_TMR_30MIN": 1,
}
ENUM_TOPOFF_TMR = {
    "TOPOFF_TMR_DISABLED": 0,
    "TOPOFF_TMR_15MIN": 1,
    "TOPOFF_TMR_30MIN": 2,
    "TOPOFF_TMR_45MIN": 3,
}
ENUM_CHG_TMR = {
    "CHG_TMR_5HRS": 0,
    "CHG_TMR_8HRS": 1,
    "CHG_TMR_12HRS": 2,
    "CHG_TMR_24HRS": 3,
}
ENUM_VBUS_BACKUP = {
    "PCT_VBUS_BACKUP_40": 0,
    "PCT_VBUS_BACKUP_60": 1,
    "PCT_VBUS_BACKUP_80": 2,
    "PCT_VBUS_BACKUP_100": 3,
}
ENUM_VAC_OVP = {
    "VAC_OVP_26V": 0,
    "VAC_OVP_22V": 1,
    "VAC_OVP_12V": 2,
    "VAC_OVP_7V": 3,
}
ENUM_WATCHDOG = {
    "WATCHDOG_DISABLE": 0,
    "WATCHDOG_05S": 1,
    "WATCHDOG_1S": 2,
    "WATCHDOG_2S": 3,
    "WATCHDOG_20S": 4,
    "WATCHDOG_40S": 5,
    "WATCHDOG_80S": 6,
    "WATCHDOG_160S": 7,
}
ENUM_SDRV_CTRL = {
    "SDRV_CTRL_IDLE": 0,
    "SDRV_CTRL_SHUTDOWN": 1,
    "SDRV_CTRL_SHIP": 2,
    "SDRV_CTRL_SYS_PWR_RST": 3,
}
ENUM_SDRV_DLY = {
    "SDRV_DLY_10S": 0,
    "SDRV_DLY_0S": 1,
}
ENUM_WKUP_DLY = {
    "WKUP_DLY_1S": 0,
    "WKUP_DLY_15MS": 1,
}
ENUM_PWM_FREQ = {
    "PWM_FREQ_1_5MHZ": 0,
    "PWM_FREQ_750KHZ": 1,
}
ENUM_IBAT_REG = {
    "IBAT_REG_3A": 0,
    "IBAT_REG_4A": 1,
    "IBAT_REG_5A": 2,
    "IBAT_REG_DISABLE": 3,
}
ENUM_VOC_PCT = {
    "VOC_PCT_0_5625": 0,
    "VOC_PCT_0_625": 1,
    "VOC_PCT_0_6875": 2,
    "VOC_PCT_0_75": 3,
    "VOC_PCT_0_8125": 4,
    "VOC_PCT_0_875": 5,
    "VOC_PCT_0_9375": 6,
    "VOC_PCT_1": 7,
}
ENUM_VOC_DLY = {
    "VOC_DLY_50MS": 0,
    "VOC_DLY_300MS": 1,
    "VOC_DLY_2S": 2,
    "VOC_DLY_5S": 3,
}
ENUM_VOC_RATE = {
    "VOC_RATE_30S": 0,
    "VOC_RATE_2MIN": 1,
    "VOC_RATE_10MIN": 2,
    "VOC_RATE_30MIN": 3,
}
ENUM_TREG = {
    "TREG_60": 0,
    "TREG_80": 1,
    "TREG_100": 2,
    "TREG_120": 3,
}
ENUM_TSHUT = {
    "TSHUT_150": 0,
    "TSHUT_130": 1,
    "TSHUT_120": 2,
    "TSHUT_85": 3,
}
ENUM_BKUP_ACFET1_ON = {
    "BKUP_ACFET1_ON_IDLE": 0,
    "BKUP_ACFET1_ON_TURN_ON": 1,
}
ENUM_JEITA_VSET = {
    "JEITA_VSET_CHARGE_SUSPEND": 0,
    "JEITA_VSET_SET_VREG_TO_VREG_800MV": 1,
    "JEITA_VSET_SET_VREG_TO_VREG_600MV": 2,
    "JEITA_VSET_SET_VREG_TO_VREG_400MV": 3,
    "JEITA_VSET_SET_VREG_TO_VREG_300MV": 4,
    "JEITA_VSET_SET_VREG_TO_VREG_200MV": 5,
    "JEITA_VSET_SET_VREG_TO_VREG_100MV": 6,
    "JEITA_VSET_VREG_UNCHANGED": 7,
}
ENUM_JEITA_ISETH = {
    "JEITA_ISETH_CHARGE_SUSPEND": 0,
    "JEITA_ISETH_SET_ICHG_TO_20": 1,
    "JEITA_ISETH_SET_ICHG_TO_40": 2,
    "JEITA_ISETH_ICHG_UNCHANGED": 3,
}
ENUM_JEITA_ISETC = {
    "JEITA_ISETC_CHARGE_SUSPEND": 0,
    "JEITA_ISETC_SET_ICHG_TO_20": 1,
    "JEITA_ISETC_SET_ICHG_TO_40": 2,
    "JEITA_ISETC_ICHG_UNCHANGED": 3,
}
ENUM_TS_COOL = {
    "TS_COOL_5": 0,
    "TS_COOL_10": 1,
    "TS_COOL_15": 2,
    "TS_COOL_20": 3,
}
ENUM_TS_WARM = {
    "TS_WARM_40": 0,
    "TS_WARM_45": 1,
    "TS_WARM_50": 2,
    "TS_WARM_55": 3,
}
ENUM_BHOT = {
    "TS_BHOT_55": 0,
    "TS_BHOT_60": 1,
    "TS_BHOT_65": 2,
    "TS_BHOT_DISABLE": 3,
}
ENUM_BCOLD = {
    "TS_BCOLD_MINUS_10": 0,
    "TS_BCOLD_MINUS_20": 1,
}
ENUM_IINDPM_STAT = {
    "IINDPM_STAT_NORMAL": 0,
    "IINDPM_STAT_REGULATION": 1,
}
ENUM_VINDPM_STAT = {
    "VINDPM_STAT_NORMAL": 0,
    "VINDPM_STAT_REGULATION": 1,
}
ENUM_WD_STAT = {
    "WD_STAT_NORMAL": 0,
    "WD_STAT_EXPIRED": 1,
}
ENUM_PG_STAT = {
    "PG_STAT_BAD": 0,
    "PG_STAT_GOOD": 1,
}
ENUM_AC2_PRESENT_STAT = {
    "AC2_PRESENT_STAT_NOT_PRESENT": 0,
    "AC2_PRESENT_STAT_PRESENT": 1,
}
ENUM_AC1_PRESENT_STAT = {
    "AC1_PRESENT_STAT_NOT_PRESENT": 0,
    "AC1_PRESENT_STAT_PRESENT": 1,
}
ENUM_VBUS_PRESENT_STAT = {
    "VBUS_PRESENT_STAT_NOT_PRESENT": 0,
    "VBUS_PRESENT_STAT_PRESENT": 1,
}
ENUM_CHG_STAT = {
    "CHG_STAT_NOT_CHARGING": 0,
    "CHG_STAT_TRICKLECHARGE": 1,
    "CHG_STAT_PRECHARGE": 2,
    "CHG_STAT_FASTCHARGE_CC": 3,
    "CHG_STAT_FASTCHARGE_CV": 4,
    "CHG_STAT_RESERVED_5": 5,
    "CHG_STAT_TOPOFF": 6,
    "CHG_STAT_TERMINATED": 7,
}
ENUM_VBUS_STAT = {
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
ENUM_ICO_STAT = {
    "ICO_STAT_DISABLED": 0,
    "ICO_STAT_IN_PROGRESS": 1,
    "ICO_STAT_MAX_CURRENT_DETECTED": 2,
    "ICO_STAT_RESERVED": 3,
}
ENUM_TREG_STAT = {
    "TREG_STAT_NORMAL": 0,
    "TREG_STAT_THERMAL_REGULATION": 1,
}
ENUM_DPDM_STAT = {
    "DPDM_STAT_NOT_STARTED": 0,
    "DPDM_STAT_IN_PROGRESS": 1,
}
ENUM_VBAT_PRESENT_STAT = {
    "VBAT_PRESENT_STAT_NOT_PRESENT": 0,
    "VBAT_PRESENT_STAT_PRESENT": 1,
}
ENUM_VSYS_STAT = {
    "VSYS_STAT_NOT_IN_VSYSMIN_REGULATION": 0,
    "VSYS_STAT_IN_VSYSMIN_REGULATION": 1,
}
ENUM_CHG_TMR_STAT = {
    "CHG_TMR_STAT_NORMAL": 0,
    "CHG_TMR_STAT_SAFETY_TIMER_EXPIRED": 1,
}
ENUM_TRICHG_TMR_STAT = {
    "TRICHG_TMR_STAT_NORMAL": 0,
    "TRICHG_TMR_STAT_SAFETY_TIMER_EXPIRED": 1,
}
ENUM_PRECHG_TMR_STAT = {
    "PRECHG_TMR_STAT_NORMAL": 0,
    "PRECHG_TMR_STAT_SAFETY_TIMER_EXPIRED": 1,
}
ENUM_VBATOTG_LOW_STAT = {
    "VBATOTG_LOW_STAT_VBATOTG_LOW": 0,
    "VBATOTG_LOW_STAT_VBATOTG_OK": 1,
}
ENUM_TS_COLD_STAT = {
    "TS_COLD_STAT_NOT_COLD": 0,
    "TS_COLD_STAT_COLD": 1,
}
ENUM_TS_COOL_STAT = {
    "TS_COOL_STAT_NOT_COOL": 0,
    "TS_COOL_STAT_COOL": 1,
}
ENUM_TS_WARM_STAT = {
    "TS_WARM_STAT_NOT_WARM": 0,
    "TS_WARM_STAT_WARM": 1,
}
ENUM_TS_HOT_STAT = {
    "TS_HOT_STAT_NOT_HOT": 0,
    "TS_HOT_STAT_HOT": 1,
}
ENUM_ADC_RATE = {
    "ADC_RATE_CONTINUOUS": 0,
    "ADC_RATE_ONESHOT": 1,
}
ENUM_ADC_SAMPLE = {
    "ADC_SAMPLE_15BIT": 0,
    "ADC_SAMPLE_14BIT": 1,
    "ADC_SAMPLE_13BIT": 2,
    "ADC_SAMPLE_12BIT": 3,
}
ENUM_ADC_AVG = {
    "ADC_AVG_NO_AVERAGING": 0,
    "ADC_AVG_RUNNING_AVERAGE": 1,
}
ENUM_DPLUS_DAC = {
    "DPLUS_DAC_HIZ": 0,
    "DPLUS_DAC_VOUT_0": 1,
    "DPLUS_DAC_VOUT_0_6": 2,
    "DPLUS_DAC_VOUT_1_2": 3,
    "DPLUS_DAC_VOUT_2_0": 4,
    "DPLUS_DAC_VOUT_2_7": 5,
    "DPLUS_DAC_VOUT_3_3": 6,
    "DPLUS_DAC_DPLUS_DMINUS_SHORT": 7,
}
ENUM_DMINUS_DAC = {
    "DMINUS_DAC_HIZ": 0,
    "DMINUS_DAC_VOUT_0": 1,
    "DMINUS_DAC_VOUT_0_6": 2,
    "DMINUS_DAC_VOUT_1_2": 3,
    "DMINUS_DAC_VOUT_2_0": 4,
    "DMINUS_DAC_VOUT_2_7": 5,
    "DMINUS_DAC_VOUT_3_3": 6,
    "DMINUS_DAC_RESERVED": 7,
}
ENUM_PN = {
    "PN_RESERVED_0": 0,
    "PN_RESERVED_1": 1,
    "PN_RESERVED_2": 2,
    "PN_BQ25798": 3,
    "PN_RESERVED_4": 4,
    "PN_RESERVED_5": 5,
    "PN_RESERVED_6": 6,
    "PN_RESERVED_7": 7,
}
ENUM_DEV_REV = {
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
            cv.GenerateID(): cv.declare_id(BQ25798Component),
            # Chip settings
            cv.Optional(CONF_VSYSMIN): cv.int_,
            cv.Optional(CONF_VREG): cv.int_,
            cv.Optional(CONF_ICHG): cv.int_,
            cv.Optional(CONF_VINDPM): cv.int_,
            cv.Optional(CONF_IINDPM): cv.int_,
            cv.Optional(CONF_VBAT_LOWV): cv.enum(ENUM_VBAT_LOWV),
            cv.Optional(CONF_IPRECHG): cv.int_,
            cv.Optional(CONF_REG_RST): cv.boolean,
            cv.Optional(CONF_STOP_WD_CHG): cv.boolean,
            cv.Optional(CONF_ITERM): cv.int_,
            cv.Optional(CONF_CELL): cv.enum(ENUM_CELL),
            cv.Optional(CONF_TRECHG): cv.enum(ENUM_TRECHG),
            cv.Optional(CONF_VRECHG): cv.int_,
            cv.Optional(CONF_VOTG): cv.int_,
            cv.Optional(CONF_PRECHG_TMR): cv.enum(ENUM_PRECHG_TMR),
            cv.Optional(CONF_IOTG): cv.int_,
            cv.Optional(CONF_TOPOFF_TMR): cv.enum(ENUM_TOPOFF_TMR),
            cv.Optional(CONF_EN_TRICHG_TMR): cv.boolean,
            cv.Optional(CONF_EN_PRECHG_TMR): cv.boolean,
            cv.Optional(CONF_EN_CHG_TMR): cv.boolean,
            cv.Optional(CONF_CHG_TMR): cv.enum(ENUM_CHG_TMR),
            cv.Optional(CONF_TMR2X_EN): cv.boolean,
            cv.Optional(CONF_EN_AUTO_IBATDIS): cv.boolean,
            cv.Optional(CONF_FORCE_IBATDIS): cv.boolean,
            cv.Optional(CONF_EN_CHG): cv.boolean,
            cv.Optional(CONF_EN_ICO): cv.boolean,
            cv.Optional(CONF_FORCE_ICO): cv.boolean,
            cv.Optional(CONF_EN_HIZ): cv.boolean,
            cv.Optional(CONF_EN_TERM): cv.boolean,
            cv.Optional(CONF_EN_BACKUP): cv.boolean,
            cv.Optional(CONF_VBUS_BACKUP): cv.enum(ENUM_VBUS_BACKUP),
            cv.Optional(CONF_VAC_OVP): cv.enum(ENUM_VAC_OVP),
            cv.Optional(CONF_WD_RST): cv.boolean,
            cv.Optional(CONF_WATCHDOG): cv.enum(ENUM_WATCHDOG),
            cv.Optional(CONF_FORCE_INDET): cv.boolean,
            cv.Optional(CONF_AUTO_INDET_EN): cv.boolean,
            cv.Optional(CONF_EN_12V): cv.boolean,
            cv.Optional(CONF_EN_9V): cv.boolean,
            cv.Optional(CONF_HVDCP_EN): cv.boolean,
            cv.Optional(CONF_SDRV_CTRL): cv.enum(ENUM_SDRV_CTRL),
            cv.Optional(CONF_SDRV_DLY): cv.enum(ENUM_SDRV_DLY),
            cv.Optional(CONF_DIS_ACDRV): cv.boolean,
            cv.Optional(CONF_EN_OTG): cv.boolean,
            cv.Optional(CONF_PFM_OTG_DIS): cv.boolean,
            cv.Optional(CONF_PFM_FWD_DIS): cv.boolean,
            cv.Optional(CONF_WKUP_DLY): cv.enum(ENUM_WKUP_DLY),
            cv.Optional(CONF_DIS_LDO): cv.boolean,
            cv.Optional(CONF_DIS_OTG_OOA): cv.boolean,
            cv.Optional(CONF_DIS_FWD_OOA): cv.boolean,
            cv.Optional(CONF_EN_ACDRV2): cv.boolean,
            cv.Optional(CONF_EN_ACDRV1): cv.boolean,
            cv.Optional(CONF_PWM_FREQ): cv.enum(ENUM_PWM_FREQ),
            cv.Optional(CONF_DIS_STAT): cv.boolean,
            cv.Optional(CONF_DIS_VSYS_SHORT): cv.boolean,
            cv.Optional(CONF_DIS_VOTG_UVP): cv.boolean,
            cv.Optional(CONF_FORCE_VINDPM_DET): cv.boolean,
            cv.Optional(CONF_EN_IBUS_OCP): cv.boolean,
            cv.Optional(CONF_SFET_PRESENT): cv.boolean,
            cv.Optional(CONF_EN_IBAT): cv.boolean,
            cv.Optional(CONF_IBAT_REG): cv.enum(ENUM_IBAT_REG),
            cv.Optional(CONF_EN_IINDPM): cv.boolean,
            cv.Optional(CONF_EN_EXTILIM): cv.boolean,
            cv.Optional(CONF_EN_BATOC): cv.boolean,
            cv.Optional(CONF_VOC_PCT): cv.enum(ENUM_VOC_PCT),
            cv.Optional(CONF_VOC_DLY): cv.enum(ENUM_VOC_DLY),
            cv.Optional(CONF_VOC_RATE): cv.enum(ENUM_VOC_RATE),
            cv.Optional(CONF_EN_MPPT): cv.boolean,
            cv.Optional(CONF_TREG): cv.enum(ENUM_TREG),
            cv.Optional(CONF_TSHUT): cv.enum(ENUM_TSHUT),
            cv.Optional(CONF_VBUS_PD_EN): cv.boolean,
            cv.Optional(CONF_VAC1_PD_EN): cv.boolean,
            cv.Optional(CONF_VAC2_PD_EN): cv.boolean,
            cv.Optional(CONF_BKUP_ACFET1_ON): cv.enum(ENUM_BKUP_ACFET1_ON),
            cv.Optional(CONF_JEITA_VSET): cv.enum(ENUM_JEITA_VSET),
            cv.Optional(CONF_JEITA_ISETH): cv.enum(ENUM_JEITA_ISETH),
            cv.Optional(CONF_JEITA_ISETC): cv.enum(ENUM_JEITA_ISETC),
            cv.Optional(CONF_TS_COOL): cv.enum(ENUM_TS_COOL),
            cv.Optional(CONF_TS_WARM): cv.enum(ENUM_TS_WARM),
            cv.Optional(CONF_BHOT): cv.enum(ENUM_BHOT),
            cv.Optional(CONF_BCOLD): cv.enum(ENUM_BCOLD),
            cv.Optional(CONF_TS_IGNORE): cv.boolean,
            cv.Optional(CONF_ICO_ILIM): cv.int_,
            cv.Optional(CONF_IINDPM_STAT): cv.enum(ENUM_IINDPM_STAT),
            cv.Optional(CONF_VINDPM_STAT): cv.enum(ENUM_VINDPM_STAT),
            cv.Optional(CONF_WD_STAT): cv.enum(ENUM_WD_STAT),
            cv.Optional(CONF_PG_STAT): cv.enum(ENUM_PG_STAT),
            cv.Optional(CONF_AC2_PRESENT_STAT): cv.enum(ENUM_AC2_PRESENT_STAT),
            cv.Optional(CONF_AC1_PRESENT_STAT): cv.enum(ENUM_AC1_PRESENT_STAT),
            cv.Optional(CONF_VBUS_PRESENT_STAT): cv.enum(ENUM_VBUS_PRESENT_STAT),
            cv.Optional(CONF_CHG_STAT): cv.enum(ENUM_CHG_STAT),
            cv.Optional(CONF_VBUS_STAT): cv.enum(ENUM_VBUS_STAT),
            cv.Optional(CONF_BC12_DONE_STAT): cv.boolean,
            cv.Optional(CONF_ICO_STAT): cv.enum(ENUM_ICO_STAT),
            cv.Optional(CONF_TREG_STAT): cv.enum(ENUM_TREG_STAT),
            cv.Optional(CONF_DPDM_STAT): cv.enum(ENUM_DPDM_STAT),
            cv.Optional(CONF_VBAT_PRESENT_STAT): cv.enum(ENUM_VBAT_PRESENT_STAT),
            cv.Optional(CONF_ACRB2_STAT): cv.boolean,
            cv.Optional(CONF_ACRB1_STAT): cv.boolean,
            cv.Optional(CONF_ADC_DONE_STAT): cv.boolean,
            cv.Optional(CONF_VSYS_STAT): cv.enum(ENUM_VSYS_STAT),
            cv.Optional(CONF_CHG_TMR_STAT): cv.enum(ENUM_CHG_TMR_STAT),
            cv.Optional(CONF_TRICHG_TMR_STAT): cv.enum(ENUM_TRICHG_TMR_STAT),
            cv.Optional(CONF_PRECHG_TMR_STAT): cv.enum(ENUM_PRECHG_TMR_STAT),
            cv.Optional(CONF_VBATOTG_LOW_STAT): cv.enum(ENUM_VBATOTG_LOW_STAT),
            cv.Optional(CONF_TS_COLD_STAT): cv.enum(ENUM_TS_COLD_STAT),
            cv.Optional(CONF_TS_COOL_STAT): cv.enum(ENUM_TS_COOL_STAT),
            cv.Optional(CONF_TS_WARM_STAT): cv.enum(ENUM_TS_WARM_STAT),
            cv.Optional(CONF_TS_HOT_STAT): cv.enum(ENUM_TS_HOT_STAT),
            cv.Optional(CONF_IBAT_REG_STAT): cv.boolean,
            cv.Optional(CONF_VBUS_OVP_STAT): cv.boolean,
            cv.Optional(CONF_VBAT_OVP_STAT): cv.boolean,
            cv.Optional(CONF_IBUS_OCP_STAT): cv.boolean,
            cv.Optional(CONF_IBAT_OCP_STAT): cv.boolean,
            cv.Optional(CONF_CONV_OCP_STAT): cv.boolean,
            cv.Optional(CONF_VAC2_OVP_STAT): cv.boolean,
            cv.Optional(CONF_VAC1_OVP_STAT): cv.boolean,
            cv.Optional(CONF_VSYS_SHORT_STAT): cv.boolean,
            cv.Optional(CONF_VSYS_OVP_STAT): cv.boolean,
            cv.Optional(CONF_OTG_OVP_STAT): cv.boolean,
            cv.Optional(CONF_OTG_UVP_STAT): cv.boolean,
            cv.Optional(CONF_TSHUT_STAT): cv.boolean,
            cv.Optional(CONF_IINDPM_FLAG): cv.boolean,
            cv.Optional(CONF_VINDPM_FLAG): cv.boolean,
            cv.Optional(CONF_WD_FLAG): cv.boolean,
            cv.Optional(CONF_POORSRC_FLAG): cv.boolean,
            cv.Optional(CONF_PG_FLAG): cv.boolean,
            cv.Optional(CONF_AC2_PRESENT_FLAG): cv.boolean,
            cv.Optional(CONF_AC1_PRESENT_FLAG): cv.boolean,
            cv.Optional(CONF_VBUS_PRESENT_FLAG): cv.boolean,
            cv.Optional(CONF_CHG_FLAG): cv.boolean,
            cv.Optional(CONF_ICO_FLAG): cv.boolean,
            cv.Optional(CONF_VBUS_FLAG): cv.boolean,
            cv.Optional(CONF_TREG_FLAG): cv.boolean,
            cv.Optional(CONF_VBAT_PRESENT_FLAG): cv.boolean,
            cv.Optional(CONF_BC1_2_DONE_FLAG): cv.boolean,
            cv.Optional(CONF_DPDM_DONE_FLAG): cv.boolean,
            cv.Optional(CONF_ADC_DONE_FLAG): cv.boolean,
            cv.Optional(CONF_VSYS_FLAG): cv.boolean,
            cv.Optional(CONF_CHG_TMR_FLAG): cv.boolean,
            cv.Optional(CONF_TRICHG_TMR_FLAG): cv.boolean,
            cv.Optional(CONF_PRECHG_TMR_FLAG): cv.boolean,
            cv.Optional(CONF_TOPOFF_TMR_FLAG): cv.boolean,
            cv.Optional(CONF_VBATOTG_LOW_FLAG): cv.boolean,
            cv.Optional(CONF_TS_COLD_FLAG): cv.boolean,
            cv.Optional(CONF_TS_COOL_FLAG): cv.boolean,
            cv.Optional(CONF_TS_WARM_FLAG): cv.boolean,
            cv.Optional(CONF_TS_HOT_FLAG): cv.boolean,
            cv.Optional(CONF_IBAT_REG_FLAG): cv.boolean,
            cv.Optional(CONF_VBUS_OVP_FLAG): cv.boolean,
            cv.Optional(CONF_VBAT_OVP_FLAG): cv.boolean,
            cv.Optional(CONF_IBUS_OCP_FLAG): cv.boolean,
            cv.Optional(CONF_IBAT_OCP_FLAG): cv.boolean,
            cv.Optional(CONF_CONV_OCP_FLAG): cv.boolean,
            cv.Optional(CONF_VAC2_OVP_FLAG): cv.boolean,
            cv.Optional(CONF_VAC1_OVP_FLAG): cv.boolean,
            cv.Optional(CONF_VSYS_SHORT_FLAG): cv.boolean,
            cv.Optional(CONF_VSYS_OVP_FLAG): cv.boolean,
            cv.Optional(CONF_OTG_OVP_FLAG): cv.boolean,
            cv.Optional(CONF_OTG_UVP_FLAG): cv.boolean,
            cv.Optional(CONF_TSHUT_FLAG): cv.boolean,
            cv.Optional(CONF_ADC_EN): cv.boolean,
            cv.Optional(CONF_ADC_RATE): cv.enum(ENUM_ADC_RATE),
            cv.Optional(CONF_ADC_SAMPLE): cv.enum(ENUM_ADC_SAMPLE),
            cv.Optional(CONF_ADC_AVG): cv.enum(ENUM_ADC_AVG),
            cv.Optional(CONF_ADC_AVG_INIT): cv.boolean,
            cv.Optional(CONF_IBUS_ADC_DIS): cv.boolean,
            cv.Optional(CONF_IBAT_ADC_DIS): cv.boolean,
            cv.Optional(CONF_VBUS_ADC_DIS): cv.boolean,
            cv.Optional(CONF_VBAT_ADC_DIS): cv.boolean,
            cv.Optional(CONF_VSYS_ADC_DIS): cv.boolean,
            cv.Optional(CONF_TS_ADC_DIS): cv.boolean,
            cv.Optional(CONF_TDIE_ADC_DIS): cv.boolean,
            cv.Optional(CONF_DPLUS_ADC_DIS): cv.boolean,
            cv.Optional(CONF_DMINUS_ADC_DIS): cv.boolean,
            cv.Optional(CONF_VAC2_ADC_DIS): cv.boolean,
            cv.Optional(CONF_VAC1_ADC_DIS): cv.boolean,
            cv.Optional(CONF_IBUS_ADC): cv.int_,
            cv.Optional(CONF_IBAT_ADC): cv.int_,
            cv.Optional(CONF_VBUS_ADC): cv.int_,
            cv.Optional(CONF_VAC1_ADC): cv.int_,
            cv.Optional(CONF_VAC2_ADC): cv.int_,
            cv.Optional(CONF_VBAT_ADC): cv.int_,
            cv.Optional(CONF_VSYS_ADC): cv.int_,
            cv.Optional(CONF_TS_ADC): cv.float_,
            cv.Optional(CONF_TDIE_ADC): cv.float_,
            cv.Optional(CONF_DPLUS_ADC): cv.int_,
            cv.Optional(CONF_DMINUS_ADC): cv.int_,
            cv.Optional(CONF_DPLUS_DAC): cv.enum(ENUM_DPLUS_DAC),
            cv.Optional(CONF_DMINUS_DAC): cv.enum(ENUM_DMINUS_DAC),
            cv.Optional(CONF_PN): cv.enum(ENUM_PN),
            cv.Optional(CONF_DEV_REV): cv.enum(ENUM_DEV_REV),
        }
    )
    .extend(cv.COMPONENT_SCHEMA)
    .extend(i2c.i2c_device_schema(0x6B))
)


async def to_code(config):
    cg.add_library(
        name="BQ25798",
        repository="https://github.com/misch2/BQ25798_Library",
        version=None,
    )

    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await i2c.register_i2c_device(var, config)
    if vsysmin := config.get(CONF_VSYSMIN):
        cg.add(var.set_vsysmin(vsysmin))

    if vreg := config.get(CONF_VREG):
        cg.add(var.set_vreg(vreg))

    if ichg := config.get(CONF_ICHG):
        cg.add(var.set_ichg(ichg))

    if vindpm := config.get(CONF_VINDPM):
        cg.add(var.set_vindpm(vindpm))

    if iindpm := config.get(CONF_IINDPM):
        cg.add(var.set_iindpm(iindpm))

    if vbat_lowv := config.get(CONF_VBAT_LOWV):
        cg.add(var.set_vbat_lowv(vbat_lowv))

    if iprechg := config.get(CONF_IPRECHG):
        cg.add(var.set_iprechg(iprechg))

    if reg_rst := config.get(CONF_REG_RST):
        cg.add(var.set_reg_rst(reg_rst))

    if stop_wd_chg := config.get(CONF_STOP_WD_CHG):
        cg.add(var.set_stop_wd_chg(stop_wd_chg))

    if iterm := config.get(CONF_ITERM):
        cg.add(var.set_iterm(iterm))

    if cell := config.get(CONF_CELL):
        cg.add(var.set_cell(cell))

    if trechg := config.get(CONF_TRECHG):
        cg.add(var.set_trechg(trechg))

    if vrechg := config.get(CONF_VRECHG):
        cg.add(var.set_vrechg(vrechg))

    if votg := config.get(CONF_VOTG):
        cg.add(var.set_votg(votg))

    if prechg_tmr := config.get(CONF_PRECHG_TMR):
        cg.add(var.set_prechg_tmr(prechg_tmr))

    if iotg := config.get(CONF_IOTG):
        cg.add(var.set_iotg(iotg))

    if topoff_tmr := config.get(CONF_TOPOFF_TMR):
        cg.add(var.set_topoff_tmr(topoff_tmr))

    if en_trichg_tmr := config.get(CONF_EN_TRICHG_TMR):
        cg.add(var.set_en_trichg_tmr(en_trichg_tmr))

    if en_prechg_tmr := config.get(CONF_EN_PRECHG_TMR):
        cg.add(var.set_en_prechg_tmr(en_prechg_tmr))

    if en_chg_tmr := config.get(CONF_EN_CHG_TMR):
        cg.add(var.set_en_chg_tmr(en_chg_tmr))

    if chg_tmr := config.get(CONF_CHG_TMR):
        cg.add(var.set_chg_tmr(chg_tmr))

    if tmr2x_en := config.get(CONF_TMR2X_EN):
        cg.add(var.set_tmr2x_en(tmr2x_en))

    if en_auto_ibatdis := config.get(CONF_EN_AUTO_IBATDIS):
        cg.add(var.set_en_auto_ibatdis(en_auto_ibatdis))

    if force_ibatdis := config.get(CONF_FORCE_IBATDIS):
        cg.add(var.set_force_ibatdis(force_ibatdis))

    if en_chg := config.get(CONF_EN_CHG):
        cg.add(var.set_en_chg(en_chg))

    if en_ico := config.get(CONF_EN_ICO):
        cg.add(var.set_en_ico(en_ico))

    if force_ico := config.get(CONF_FORCE_ICO):
        cg.add(var.set_force_ico(force_ico))

    if en_hiz := config.get(CONF_EN_HIZ):
        cg.add(var.set_en_hiz(en_hiz))

    if en_term := config.get(CONF_EN_TERM):
        cg.add(var.set_en_term(en_term))

    if en_backup := config.get(CONF_EN_BACKUP):
        cg.add(var.set_en_backup(en_backup))

    if vbus_backup := config.get(CONF_VBUS_BACKUP):
        cg.add(var.set_vbus_backup(vbus_backup))

    if vac_ovp := config.get(CONF_VAC_OVP):
        cg.add(var.set_vac_ovp(vac_ovp))

    if wd_rst := config.get(CONF_WD_RST):
        cg.add(var.set_wd_rst(wd_rst))

    if watchdog := config.get(CONF_WATCHDOG):
        cg.add(var.set_watchdog(watchdog))

    if force_indet := config.get(CONF_FORCE_INDET):
        cg.add(var.set_force_indet(force_indet))

    if auto_indet_en := config.get(CONF_AUTO_INDET_EN):
        cg.add(var.set_auto_indet_en(auto_indet_en))

    if en_12v := config.get(CONF_EN_12V):
        cg.add(var.set_en_12v(en_12v))

    if en_9v := config.get(CONF_EN_9V):
        cg.add(var.set_en_9v(en_9v))

    if hvdcp_en := config.get(CONF_HVDCP_EN):
        cg.add(var.set_hvdcp_en(hvdcp_en))

    if sdrv_ctrl := config.get(CONF_SDRV_CTRL):
        cg.add(var.set_sdrv_ctrl(sdrv_ctrl))

    if sdrv_dly := config.get(CONF_SDRV_DLY):
        cg.add(var.set_sdrv_dly(sdrv_dly))

    if dis_acdrv := config.get(CONF_DIS_ACDRV):
        cg.add(var.set_dis_acdrv(dis_acdrv))

    if en_otg := config.get(CONF_EN_OTG):
        cg.add(var.set_en_otg(en_otg))

    if pfm_otg_dis := config.get(CONF_PFM_OTG_DIS):
        cg.add(var.set_pfm_otg_dis(pfm_otg_dis))

    if pfm_fwd_dis := config.get(CONF_PFM_FWD_DIS):
        cg.add(var.set_pfm_fwd_dis(pfm_fwd_dis))

    if wkup_dly := config.get(CONF_WKUP_DLY):
        cg.add(var.set_wkup_dly(wkup_dly))

    if dis_ldo := config.get(CONF_DIS_LDO):
        cg.add(var.set_dis_ldo(dis_ldo))

    if dis_otg_ooa := config.get(CONF_DIS_OTG_OOA):
        cg.add(var.set_dis_otg_ooa(dis_otg_ooa))

    if dis_fwd_ooa := config.get(CONF_DIS_FWD_OOA):
        cg.add(var.set_dis_fwd_ooa(dis_fwd_ooa))

    if en_acdrv2 := config.get(CONF_EN_ACDRV2):
        cg.add(var.set_en_acdrv2(en_acdrv2))

    if en_acdrv1 := config.get(CONF_EN_ACDRV1):
        cg.add(var.set_en_acdrv1(en_acdrv1))

    if pwm_freq := config.get(CONF_PWM_FREQ):
        cg.add(var.set_pwm_freq(pwm_freq))

    if dis_stat := config.get(CONF_DIS_STAT):
        cg.add(var.set_dis_stat(dis_stat))

    if dis_vsys_short := config.get(CONF_DIS_VSYS_SHORT):
        cg.add(var.set_dis_vsys_short(dis_vsys_short))

    if dis_votg_uvp := config.get(CONF_DIS_VOTG_UVP):
        cg.add(var.set_dis_votg_uvp(dis_votg_uvp))

    if force_vindpm_det := config.get(CONF_FORCE_VINDPM_DET):
        cg.add(var.set_force_vindpm_det(force_vindpm_det))

    if en_ibus_ocp := config.get(CONF_EN_IBUS_OCP):
        cg.add(var.set_en_ibus_ocp(en_ibus_ocp))

    if sfet_present := config.get(CONF_SFET_PRESENT):
        cg.add(var.set_sfet_present(sfet_present))

    if en_ibat := config.get(CONF_EN_IBAT):
        cg.add(var.set_en_ibat(en_ibat))

    if ibat_reg := config.get(CONF_IBAT_REG):
        cg.add(var.set_ibat_reg(ibat_reg))

    if en_iindpm := config.get(CONF_EN_IINDPM):
        cg.add(var.set_en_iindpm(en_iindpm))

    if en_extilim := config.get(CONF_EN_EXTILIM):
        cg.add(var.set_en_extilim(en_extilim))

    if en_batoc := config.get(CONF_EN_BATOC):
        cg.add(var.set_en_batoc(en_batoc))

    if voc_pct := config.get(CONF_VOC_PCT):
        cg.add(var.set_voc_pct(voc_pct))

    if voc_dly := config.get(CONF_VOC_DLY):
        cg.add(var.set_voc_dly(voc_dly))

    if voc_rate := config.get(CONF_VOC_RATE):
        cg.add(var.set_voc_rate(voc_rate))

    if en_mppt := config.get(CONF_EN_MPPT):
        cg.add(var.set_en_mppt(en_mppt))

    if treg := config.get(CONF_TREG):
        cg.add(var.set_treg(treg))

    if tshut := config.get(CONF_TSHUT):
        cg.add(var.set_tshut(tshut))

    if vbus_pd_en := config.get(CONF_VBUS_PD_EN):
        cg.add(var.set_vbus_pd_en(vbus_pd_en))

    if vac1_pd_en := config.get(CONF_VAC1_PD_EN):
        cg.add(var.set_vac1_pd_en(vac1_pd_en))

    if vac2_pd_en := config.get(CONF_VAC2_PD_EN):
        cg.add(var.set_vac2_pd_en(vac2_pd_en))

    if bkup_acfet1_on := config.get(CONF_BKUP_ACFET1_ON):
        cg.add(var.set_bkup_acfet1_on(bkup_acfet1_on))

    if jeita_vset := config.get(CONF_JEITA_VSET):
        cg.add(var.set_jeita_vset(jeita_vset))

    if jeita_iseth := config.get(CONF_JEITA_ISETH):
        cg.add(var.set_jeita_iseth(jeita_iseth))

    if jeita_isetc := config.get(CONF_JEITA_ISETC):
        cg.add(var.set_jeita_isetc(jeita_isetc))

    if ts_cool := config.get(CONF_TS_COOL):
        cg.add(var.set_ts_cool(ts_cool))

    if ts_warm := config.get(CONF_TS_WARM):
        cg.add(var.set_ts_warm(ts_warm))

    if bhot := config.get(CONF_BHOT):
        cg.add(var.set_bhot(bhot))

    if bcold := config.get(CONF_BCOLD):
        cg.add(var.set_bcold(bcold))

    if ts_ignore := config.get(CONF_TS_IGNORE):
        cg.add(var.set_ts_ignore(ts_ignore))

    if ico_ilim := config.get(CONF_ICO_ILIM):
        cg.add(var.set_ico_ilim(ico_ilim))

    if iindpm_stat := config.get(CONF_IINDPM_STAT):
        cg.add(var.set_iindpm_stat(iindpm_stat))

    if vindpm_stat := config.get(CONF_VINDPM_STAT):
        cg.add(var.set_vindpm_stat(vindpm_stat))

    if wd_stat := config.get(CONF_WD_STAT):
        cg.add(var.set_wd_stat(wd_stat))

    if pg_stat := config.get(CONF_PG_STAT):
        cg.add(var.set_pg_stat(pg_stat))

    if ac2_present_stat := config.get(CONF_AC2_PRESENT_STAT):
        cg.add(var.set_ac2_present_stat(ac2_present_stat))

    if ac1_present_stat := config.get(CONF_AC1_PRESENT_STAT):
        cg.add(var.set_ac1_present_stat(ac1_present_stat))

    if vbus_present_stat := config.get(CONF_VBUS_PRESENT_STAT):
        cg.add(var.set_vbus_present_stat(vbus_present_stat))

    if chg_stat := config.get(CONF_CHG_STAT):
        cg.add(var.set_chg_stat(chg_stat))

    if vbus_stat := config.get(CONF_VBUS_STAT):
        cg.add(var.set_vbus_stat(vbus_stat))

    if bc12_done_stat := config.get(CONF_BC12_DONE_STAT):
        cg.add(var.set_bc12_done_stat(bc12_done_stat))

    if ico_stat := config.get(CONF_ICO_STAT):
        cg.add(var.set_ico_stat(ico_stat))

    if treg_stat := config.get(CONF_TREG_STAT):
        cg.add(var.set_treg_stat(treg_stat))

    if dpdm_stat := config.get(CONF_DPDM_STAT):
        cg.add(var.set_dpdm_stat(dpdm_stat))

    if vbat_present_stat := config.get(CONF_VBAT_PRESENT_STAT):
        cg.add(var.set_vbat_present_stat(vbat_present_stat))

    if acrb2_stat := config.get(CONF_ACRB2_STAT):
        cg.add(var.set_acrb2_stat(acrb2_stat))

    if acrb1_stat := config.get(CONF_ACRB1_STAT):
        cg.add(var.set_acrb1_stat(acrb1_stat))

    if adc_done_stat := config.get(CONF_ADC_DONE_STAT):
        cg.add(var.set_adc_done_stat(adc_done_stat))

    if vsys_stat := config.get(CONF_VSYS_STAT):
        cg.add(var.set_vsys_stat(vsys_stat))

    if chg_tmr_stat := config.get(CONF_CHG_TMR_STAT):
        cg.add(var.set_chg_tmr_stat(chg_tmr_stat))

    if trichg_tmr_stat := config.get(CONF_TRICHG_TMR_STAT):
        cg.add(var.set_trichg_tmr_stat(trichg_tmr_stat))

    if prechg_tmr_stat := config.get(CONF_PRECHG_TMR_STAT):
        cg.add(var.set_prechg_tmr_stat(prechg_tmr_stat))

    if vbatotg_low_stat := config.get(CONF_VBATOTG_LOW_STAT):
        cg.add(var.set_vbatotg_low_stat(vbatotg_low_stat))

    if ts_cold_stat := config.get(CONF_TS_COLD_STAT):
        cg.add(var.set_ts_cold_stat(ts_cold_stat))

    if ts_cool_stat := config.get(CONF_TS_COOL_STAT):
        cg.add(var.set_ts_cool_stat(ts_cool_stat))

    if ts_warm_stat := config.get(CONF_TS_WARM_STAT):
        cg.add(var.set_ts_warm_stat(ts_warm_stat))

    if ts_hot_stat := config.get(CONF_TS_HOT_STAT):
        cg.add(var.set_ts_hot_stat(ts_hot_stat))

    if ibat_reg_stat := config.get(CONF_IBAT_REG_STAT):
        cg.add(var.set_ibat_reg_stat(ibat_reg_stat))

    if vbus_ovp_stat := config.get(CONF_VBUS_OVP_STAT):
        cg.add(var.set_vbus_ovp_stat(vbus_ovp_stat))

    if vbat_ovp_stat := config.get(CONF_VBAT_OVP_STAT):
        cg.add(var.set_vbat_ovp_stat(vbat_ovp_stat))

    if ibus_ocp_stat := config.get(CONF_IBUS_OCP_STAT):
        cg.add(var.set_ibus_ocp_stat(ibus_ocp_stat))

    if ibat_ocp_stat := config.get(CONF_IBAT_OCP_STAT):
        cg.add(var.set_ibat_ocp_stat(ibat_ocp_stat))

    if conv_ocp_stat := config.get(CONF_CONV_OCP_STAT):
        cg.add(var.set_conv_ocp_stat(conv_ocp_stat))

    if vac2_ovp_stat := config.get(CONF_VAC2_OVP_STAT):
        cg.add(var.set_vac2_ovp_stat(vac2_ovp_stat))

    if vac1_ovp_stat := config.get(CONF_VAC1_OVP_STAT):
        cg.add(var.set_vac1_ovp_stat(vac1_ovp_stat))

    if vsys_short_stat := config.get(CONF_VSYS_SHORT_STAT):
        cg.add(var.set_vsys_short_stat(vsys_short_stat))

    if vsys_ovp_stat := config.get(CONF_VSYS_OVP_STAT):
        cg.add(var.set_vsys_ovp_stat(vsys_ovp_stat))

    if otg_ovp_stat := config.get(CONF_OTG_OVP_STAT):
        cg.add(var.set_otg_ovp_stat(otg_ovp_stat))

    if otg_uvp_stat := config.get(CONF_OTG_UVP_STAT):
        cg.add(var.set_otg_uvp_stat(otg_uvp_stat))

    if tshut_stat := config.get(CONF_TSHUT_STAT):
        cg.add(var.set_tshut_stat(tshut_stat))

    if iindpm_flag := config.get(CONF_IINDPM_FLAG):
        cg.add(var.set_iindpm_flag(iindpm_flag))

    if vindpm_flag := config.get(CONF_VINDPM_FLAG):
        cg.add(var.set_vindpm_flag(vindpm_flag))

    if wd_flag := config.get(CONF_WD_FLAG):
        cg.add(var.set_wd_flag(wd_flag))

    if poorsrc_flag := config.get(CONF_POORSRC_FLAG):
        cg.add(var.set_poorsrc_flag(poorsrc_flag))

    if pg_flag := config.get(CONF_PG_FLAG):
        cg.add(var.set_pg_flag(pg_flag))

    if ac2_present_flag := config.get(CONF_AC2_PRESENT_FLAG):
        cg.add(var.set_ac2_present_flag(ac2_present_flag))

    if ac1_present_flag := config.get(CONF_AC1_PRESENT_FLAG):
        cg.add(var.set_ac1_present_flag(ac1_present_flag))

    if vbus_present_flag := config.get(CONF_VBUS_PRESENT_FLAG):
        cg.add(var.set_vbus_present_flag(vbus_present_flag))

    if chg_flag := config.get(CONF_CHG_FLAG):
        cg.add(var.set_chg_flag(chg_flag))

    if ico_flag := config.get(CONF_ICO_FLAG):
        cg.add(var.set_ico_flag(ico_flag))

    if vbus_flag := config.get(CONF_VBUS_FLAG):
        cg.add(var.set_vbus_flag(vbus_flag))

    if treg_flag := config.get(CONF_TREG_FLAG):
        cg.add(var.set_treg_flag(treg_flag))

    if vbat_present_flag := config.get(CONF_VBAT_PRESENT_FLAG):
        cg.add(var.set_vbat_present_flag(vbat_present_flag))

    if bc1_2_done_flag := config.get(CONF_BC1_2_DONE_FLAG):
        cg.add(var.set_bc1_2_done_flag(bc1_2_done_flag))

    if dpdm_done_flag := config.get(CONF_DPDM_DONE_FLAG):
        cg.add(var.set_dpdm_done_flag(dpdm_done_flag))

    if adc_done_flag := config.get(CONF_ADC_DONE_FLAG):
        cg.add(var.set_adc_done_flag(adc_done_flag))

    if vsys_flag := config.get(CONF_VSYS_FLAG):
        cg.add(var.set_vsys_flag(vsys_flag))

    if chg_tmr_flag := config.get(CONF_CHG_TMR_FLAG):
        cg.add(var.set_chg_tmr_flag(chg_tmr_flag))

    if trichg_tmr_flag := config.get(CONF_TRICHG_TMR_FLAG):
        cg.add(var.set_trichg_tmr_flag(trichg_tmr_flag))

    if prechg_tmr_flag := config.get(CONF_PRECHG_TMR_FLAG):
        cg.add(var.set_prechg_tmr_flag(prechg_tmr_flag))

    if topoff_tmr_flag := config.get(CONF_TOPOFF_TMR_FLAG):
        cg.add(var.set_topoff_tmr_flag(topoff_tmr_flag))

    if vbatotg_low_flag := config.get(CONF_VBATOTG_LOW_FLAG):
        cg.add(var.set_vbatotg_low_flag(vbatotg_low_flag))

    if ts_cold_flag := config.get(CONF_TS_COLD_FLAG):
        cg.add(var.set_ts_cold_flag(ts_cold_flag))

    if ts_cool_flag := config.get(CONF_TS_COOL_FLAG):
        cg.add(var.set_ts_cool_flag(ts_cool_flag))

    if ts_warm_flag := config.get(CONF_TS_WARM_FLAG):
        cg.add(var.set_ts_warm_flag(ts_warm_flag))

    if ts_hot_flag := config.get(CONF_TS_HOT_FLAG):
        cg.add(var.set_ts_hot_flag(ts_hot_flag))

    if ibat_reg_flag := config.get(CONF_IBAT_REG_FLAG):
        cg.add(var.set_ibat_reg_flag(ibat_reg_flag))

    if vbus_ovp_flag := config.get(CONF_VBUS_OVP_FLAG):
        cg.add(var.set_vbus_ovp_flag(vbus_ovp_flag))

    if vbat_ovp_flag := config.get(CONF_VBAT_OVP_FLAG):
        cg.add(var.set_vbat_ovp_flag(vbat_ovp_flag))

    if ibus_ocp_flag := config.get(CONF_IBUS_OCP_FLAG):
        cg.add(var.set_ibus_ocp_flag(ibus_ocp_flag))

    if ibat_ocp_flag := config.get(CONF_IBAT_OCP_FLAG):
        cg.add(var.set_ibat_ocp_flag(ibat_ocp_flag))

    if conv_ocp_flag := config.get(CONF_CONV_OCP_FLAG):
        cg.add(var.set_conv_ocp_flag(conv_ocp_flag))

    if vac2_ovp_flag := config.get(CONF_VAC2_OVP_FLAG):
        cg.add(var.set_vac2_ovp_flag(vac2_ovp_flag))

    if vac1_ovp_flag := config.get(CONF_VAC1_OVP_FLAG):
        cg.add(var.set_vac1_ovp_flag(vac1_ovp_flag))

    if vsys_short_flag := config.get(CONF_VSYS_SHORT_FLAG):
        cg.add(var.set_vsys_short_flag(vsys_short_flag))

    if vsys_ovp_flag := config.get(CONF_VSYS_OVP_FLAG):
        cg.add(var.set_vsys_ovp_flag(vsys_ovp_flag))

    if otg_ovp_flag := config.get(CONF_OTG_OVP_FLAG):
        cg.add(var.set_otg_ovp_flag(otg_ovp_flag))

    if otg_uvp_flag := config.get(CONF_OTG_UVP_FLAG):
        cg.add(var.set_otg_uvp_flag(otg_uvp_flag))

    if tshut_flag := config.get(CONF_TSHUT_FLAG):
        cg.add(var.set_tshut_flag(tshut_flag))

    if adc_en := config.get(CONF_ADC_EN):
        cg.add(var.set_adc_en(adc_en))

    if adc_rate := config.get(CONF_ADC_RATE):
        cg.add(var.set_adc_rate(adc_rate))

    if adc_sample := config.get(CONF_ADC_SAMPLE):
        cg.add(var.set_adc_sample(adc_sample))

    if adc_avg := config.get(CONF_ADC_AVG):
        cg.add(var.set_adc_avg(adc_avg))

    if adc_avg_init := config.get(CONF_ADC_AVG_INIT):
        cg.add(var.set_adc_avg_init(adc_avg_init))

    if ibus_adc_dis := config.get(CONF_IBUS_ADC_DIS):
        cg.add(var.set_ibus_adc_dis(ibus_adc_dis))

    if ibat_adc_dis := config.get(CONF_IBAT_ADC_DIS):
        cg.add(var.set_ibat_adc_dis(ibat_adc_dis))

    if vbus_adc_dis := config.get(CONF_VBUS_ADC_DIS):
        cg.add(var.set_vbus_adc_dis(vbus_adc_dis))

    if vbat_adc_dis := config.get(CONF_VBAT_ADC_DIS):
        cg.add(var.set_vbat_adc_dis(vbat_adc_dis))

    if vsys_adc_dis := config.get(CONF_VSYS_ADC_DIS):
        cg.add(var.set_vsys_adc_dis(vsys_adc_dis))

    if ts_adc_dis := config.get(CONF_TS_ADC_DIS):
        cg.add(var.set_ts_adc_dis(ts_adc_dis))

    if tdie_adc_dis := config.get(CONF_TDIE_ADC_DIS):
        cg.add(var.set_tdie_adc_dis(tdie_adc_dis))

    if dplus_adc_dis := config.get(CONF_DPLUS_ADC_DIS):
        cg.add(var.set_dplus_adc_dis(dplus_adc_dis))

    if dminus_adc_dis := config.get(CONF_DMINUS_ADC_DIS):
        cg.add(var.set_dminus_adc_dis(dminus_adc_dis))

    if vac2_adc_dis := config.get(CONF_VAC2_ADC_DIS):
        cg.add(var.set_vac2_adc_dis(vac2_adc_dis))

    if vac1_adc_dis := config.get(CONF_VAC1_ADC_DIS):
        cg.add(var.set_vac1_adc_dis(vac1_adc_dis))

    if ibus_adc := config.get(CONF_IBUS_ADC):
        cg.add(var.set_ibus_adc(ibus_adc))

    if ibat_adc := config.get(CONF_IBAT_ADC):
        cg.add(var.set_ibat_adc(ibat_adc))

    if vbus_adc := config.get(CONF_VBUS_ADC):
        cg.add(var.set_vbus_adc(vbus_adc))

    if vac1_adc := config.get(CONF_VAC1_ADC):
        cg.add(var.set_vac1_adc(vac1_adc))

    if vac2_adc := config.get(CONF_VAC2_ADC):
        cg.add(var.set_vac2_adc(vac2_adc))

    if vbat_adc := config.get(CONF_VBAT_ADC):
        cg.add(var.set_vbat_adc(vbat_adc))

    if vsys_adc := config.get(CONF_VSYS_ADC):
        cg.add(var.set_vsys_adc(vsys_adc))

    if ts_adc := config.get(CONF_TS_ADC):
        cg.add(var.set_ts_adc(ts_adc))

    if tdie_adc := config.get(CONF_TDIE_ADC):
        cg.add(var.set_tdie_adc(tdie_adc))

    if dplus_adc := config.get(CONF_DPLUS_ADC):
        cg.add(var.set_dplus_adc(dplus_adc))

    if dminus_adc := config.get(CONF_DMINUS_ADC):
        cg.add(var.set_dminus_adc(dminus_adc))

    if dplus_dac := config.get(CONF_DPLUS_DAC):
        cg.add(var.set_dplus_dac(dplus_dac))

    if dminus_dac := config.get(CONF_DMINUS_DAC):
        cg.add(var.set_dminus_dac(dminus_dac))

    if pn := config.get(CONF_PN):
        cg.add(var.set_pn(pn))

    if dev_rev := config.get(CONF_DEV_REV):
        cg.add(var.set_dev_rev(dev_rev))
