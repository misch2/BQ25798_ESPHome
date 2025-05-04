import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c
from esphome.const import CONF_ID

DEPENDENCIES = ["i2c"]

bq25798_ns = cg.esphome_ns.namespace("bq25798")
BQ25798Component = bq25798_ns.class_("BQ25798Component", cg.Component, i2c.I2CDevice)
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
ENUM_VBAT_LOWV = {
    "PCT_15": 0,
    "PCT_62": 1,
    "PCT_67": 2,
    "PCT_71": 3,
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
    "IDLE": 0,
    "SHUTDOWN": 1,
    "SHIP": 2,
    "SYS_PWR_RST": 3,
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
    "IDLE": 0,
    "TURN_ON": 1,
}
ENUM_JEITA_VSET = {
    "CHARGE_SUSPEND": 0,
    "SET_VREG_TO_VREG_800MV": 1,
    "SET_VREG_TO_VREG_600MV": 2,
    "SET_VREG_TO_VREG_400MV": 3,
    "SET_VREG_TO_VREG_300MV": 4,
    "SET_VREG_TO_VREG_200MV": 5,
    "SET_VREG_TO_VREG_100MV": 6,
    "VREG_UNCHANGED": 7,
}
ENUM_JEITA_ISETH = {
    "CHARGE_SUSPEND": 0,
    "SET_ICHG_TO_20": 1,
    "SET_ICHG_TO_40": 2,
    "ICHG_UNCHANGED": 3,
}
ENUM_JEITA_ISETC = {
    "CHARGE_SUSPEND": 0,
    "SET_ICHG_TO_20": 1,
    "SET_ICHG_TO_40": 2,
    "ICHG_UNCHANGED": 3,
}
ENUM_TS_COOL = {
    "TS_5": 0,
    "TS_10": 1,
    "TS_15": 2,
    "TS_20": 3,
}
ENUM_TS_WARM = {
    "TS_40": 0,
    "TS_45": 1,
    "TS_50": 2,
    "TS_55": 3,
}
ENUM_BHOT = {
    "TS_55": 0,
    "TS_60": 1,
    "TS_65": 2,
    "DISABLE": 3,
}
ENUM_BCOLD = {
    "MINUS_10": 0,
    "MINUS_20": 1,
}
ENUM_IINDPM_STAT = {
    "NORMAL": 0,
    "REGULATION": 1,
}
ENUM_VINDPM_STAT = {
    "NORMAL": 0,
    "REGULATION": 1,
}
ENUM_WD_STAT = {
    "NORMAL": 0,
    "EXPIRED": 1,
}
ENUM_PG_STAT = {
    "BAD": 0,
    "GOOD": 1,
}
ENUM_AC2_PRESENT_STAT = {
    "NOT_PRESENT": 0,
    "PRESENT": 1,
}
ENUM_AC1_PRESENT_STAT = {
    "NOT_PRESENT": 0,
    "PRESENT": 1,
}
ENUM_VBUS_PRESENT_STAT = {
    "NOT_PRESENT": 0,
    "PRESENT": 1,
}
ENUM_CHG_STAT = {
    "NOT_CHARGING": 0,
    "TRICKLECHARGE": 1,
    "PRECHARGE": 2,
    "FASTCHARGE_CC": 3,
    "FASTCHARGE_CV": 4,
    "RESERVED_5": 5,
    "TOPOFF": 6,
    "TERMINATED": 7,
}
ENUM_VBUS_STAT = {
    "NO_INPUT": 0,
    "USB_SDP": 1,
    "USB_CDP": 2,
    "USB_DCP": 3,
    "ADJUSTABLE_HVDCP": 4,
    "UNKNOWN_ADAPTOR": 5,
    "NON_STANDARD_ADAPTER": 6,
    "OTG_MODE": 7,
    "NOT_QUALIFIED_ADAPTOR": 8,
    "RESERVED_9": 9,
    "RESERVED_A": 10,
    "DEVICE_POWERED_FROM_VBUS": 11,
    "BACKUP_MODE": 12,
    "RESERVED_D": 13,
    "RESERVED_E": 14,
    "RESERVED_F": 15,
}
ENUM_ICO_STAT = {
    "ICO_DISABLED": 0,
    "ICO_IN_PROGRESS": 1,
    "ICO_MAX_CURRENT_DETECTED": 2,
    "ICO_RESERVED": 3,
}
ENUM_TREG_STAT = {
    "NORMAL": 0,
    "THERMAL_REGULATION": 1,
}
ENUM_DPDM_STAT = {
    "NOT_STARTED": 0,
    "IN_PROGRESS": 1,
}
ENUM_VBAT_PRESENT_STAT = {
    "NOT_PRESENT": 0,
    "PRESENT": 1,
}
ENUM_VSYS_STAT = {
    "NOT_IN_VSYSMIN_REGULATION": 0,
    "IN_VSYSMIN_REGULATION": 1,
}
ENUM_CHG_TMR_STAT = {
    "NORMAL": 0,
    "SAFETY_TIMER_EXPIRED": 1,
}
ENUM_TRICHG_TMR_STAT = {
    "NORMAL": 0,
    "SAFETY_TIMER_EXPIRED": 1,
}
ENUM_PRECHG_TMR_STAT = {
    "NORMAL": 0,
    "SAFETY_TIMER_EXPIRED": 1,
}
ENUM_VBATOTG_LOW_STAT = {
    "VBATOTG_LOW": 0,
    "VBATOTG_OK": 1,
}
ENUM_TS_COLD_STAT = {
    "NOT_COLD": 0,
    "COLD": 1,
}
ENUM_TS_COOL_STAT = {
    "NOT_COOL": 0,
    "COOL": 1,
}
ENUM_TS_WARM_STAT = {
    "NOT_WARM": 0,
    "WARM": 1,
}
ENUM_TS_HOT_STAT = {
    "NOT_HOT": 0,
    "HOT": 1,
}
ENUM_ADC_RATE = {
    "CONTINUOUS": 0,
    "ONESHOT": 1,
}
ENUM_ADC_SAMPLE = {
    "ADC_SAMPLE_15BIT": 0,
    "ADC_SAMPLE_14BIT": 1,
    "ADC_SAMPLE_13BIT": 2,
    "ADC_SAMPLE_12BIT": 3,
}
ENUM_ADC_AVG = {
    "NO_AVERAGING": 0,
    "RUNNING_AVERAGE": 1,
}
ENUM_DPLUS_DAC = {
    "HIZ": 0,
    "VOUT_0": 1,
    "VOUT_0_6": 2,
    "VOUT_1_2": 3,
    "VOUT_2_0": 4,
    "VOUT_2_7": 5,
    "VOUT_3_3": 6,
    "DPLUS_DMINUS_SHORT": 7,
}
ENUM_DMINUS_DAC = {
    "HIZ": 0,
    "VOUT_0": 1,
    "VOUT_0_6": 2,
    "VOUT_1_2": 3,
    "VOUT_2_0": 4,
    "VOUT_2_7": 5,
    "VOUT_3_3": 6,
    "RESERVED": 7,
}
ENUM_PN = {
    "RESERVED_0": 0,
    "RESERVED_1": 1,
    "RESERVED_2": 2,
    "BQ25798": 3,
    "RESERVED_4": 4,
    "RESERVED_5": 5,
    "RESERVED_6": 6,
    "RESERVED_7": 7,
}
ENUM_DEV_REV = {
    "RESERVED_0": 0,
    "BQ25798": 1,
    "RESERVED_2": 2,
    "RESERVED_3": 3,
    "RESERVED_4": 4,
    "RESERVED_5": 5,
    "RESERVED_6": 6,
    "RESERVED_7": 7,
}


CONFIG_SCHEMA = (
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(BQ25798Component),
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

            cv.Optional(CONF_VSYSMIN): cv.positive_int,
        }
    )
    .extend(cv.COMPONENT_SCHEMA)
    .extend(i2c.i2c_device_schema(0x01))    # FIXME
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