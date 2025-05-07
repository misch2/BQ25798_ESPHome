import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import core
from esphome.components import binary_sensor
from esphome.const import (
    CONF_ID,
)

from .. import (
    CONF_BQ25798_ID,
    BQ25798_CLIENT_SCHEMA,
    bq25798_ns,
)

DEPENDENCIES = ["bq25798"]

BQ25798BinarySensor = bq25798_ns.class_("BQ25798BinarySensor", cg.Component)

# Boolean settings
CONF_BQ25798_REG_RST = "reg_rst"
CONF_BQ25798_STOP_WD_CHG = "stop_wd_chg"
CONF_BQ25798_EN_TRICHG_TMR = "en_trichg_tmr"
CONF_BQ25798_EN_PRECHG_TMR = "en_prechg_tmr"
CONF_BQ25798_EN_CHG_TMR = "en_chg_tmr"
CONF_BQ25798_TMR2X_EN = "tmr2x_en"
CONF_BQ25798_EN_AUTO_IBATDIS = "en_auto_ibatdis"
CONF_BQ25798_FORCE_IBATDIS = "force_ibatdis"
CONF_BQ25798_EN_CHG = "en_chg"
CONF_BQ25798_EN_ICO = "en_ico"
CONF_BQ25798_FORCE_ICO = "force_ico"
CONF_BQ25798_EN_HIZ = "en_hiz"
CONF_BQ25798_EN_TERM = "en_term"
CONF_BQ25798_EN_BACKUP = "en_backup"
CONF_BQ25798_WD_RST = "wd_rst"
CONF_BQ25798_FORCE_INDET = "force_indet"
CONF_BQ25798_AUTO_INDET_EN = "auto_indet_en"
CONF_BQ25798_EN_12V = "en_12v"
CONF_BQ25798_EN_9V = "en_9v"
CONF_BQ25798_HVDCP_EN = "hvdcp_en"
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
CONF_BQ25798_EN_IINDPM = "en_iindpm"
CONF_BQ25798_EN_EXTILIM = "en_extilim"
CONF_BQ25798_EN_BATOC = "en_batoc"
CONF_BQ25798_EN_MPPT = "en_mppt"
CONF_BQ25798_VBUS_PD_EN = "vbus_pd_en"
CONF_BQ25798_VAC1_PD_EN = "vac1_pd_en"
CONF_BQ25798_VAC2_PD_EN = "vac2_pd_en"
CONF_BQ25798_TS_IGNORE = "ts_ignore"
CONF_BQ25798_BC12_DONE_STAT = "bc12_done_stat"
CONF_BQ25798_ACRB2_STAT = "acrb2_stat"
CONF_BQ25798_ACRB1_STAT = "acrb1_stat"
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

# See https://www.home-assistant.io/integrations/binary_sensor/#device-class for the list of binary sensor device classes

# Usable ones:
# '',                  =       on / off
# 'battery',           =      low / normal               OK = FALSE
# 'battery_charging',  = charging / not charging
# 'cold',              =     cold / normal               OK = FALSE
# 'heat',              =      hot / normal               OK = FALSE
# 'power',             =       on / off                  OK = TRUE
# 'problem',           =  problem / ok                   OK = FALSE
# 'running',           =  running / not running
# 'safety',            =   unsafe / safe                 OK = FALSE
# 'tamper',            = tampered / clear                OK = FALSE

CONFIG_SCHEMA = (
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(BQ25798BinarySensor),
            cv.Optional(CONF_BQ25798_REG_RST): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_STOP_WD_CHG): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_TRICHG_TMR): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_PRECHG_TMR): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_CHG_TMR): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_TMR2X_EN): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_AUTO_IBATDIS): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_FORCE_IBATDIS): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_CHG): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_ICO): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_FORCE_ICO): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_HIZ): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_TERM): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_BACKUP): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_WD_RST): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_FORCE_INDET): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_AUTO_INDET_EN): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_12V): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_9V): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_HVDCP_EN): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_DIS_ACDRV): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_OTG): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_PFM_OTG_DIS): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_PFM_FWD_DIS): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_DIS_LDO): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_DIS_OTG_OOA): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_DIS_FWD_OOA): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_ACDRV2): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_ACDRV1): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_DIS_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_DIS_VSYS_SHORT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_DIS_VOTG_UVP): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_FORCE_VINDPM_DET): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_IBUS_OCP): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_SFET_PRESENT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_IBAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_IINDPM): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_EXTILIM): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_BATOC): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_EN_MPPT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_VBUS_PD_EN): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_VAC1_PD_EN): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_VAC2_PD_EN): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_TS_IGNORE): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_BC12_DONE_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_ACRB2_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_ACRB1_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_ADC_DONE_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_IBAT_REG_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_VBUS_OVP_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_VBAT_OVP_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_IBUS_OCP_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_IBAT_OCP_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_CONV_OCP_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_VAC2_OVP_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_VAC1_OVP_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_VSYS_SHORT_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_VSYS_OVP_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_OTG_OVP_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_OTG_UVP_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_TSHUT_STAT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_IINDPM_FLAG): binary_sensor.binary_sensor_schema(
            ),
            cv.Optional(CONF_BQ25798_VINDPM_FLAG): binary_sensor.binary_sensor_schema(
            ),
            cv.Optional(CONF_BQ25798_WD_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_POORSRC_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_PG_FLAG): binary_sensor.binary_sensor_schema(
                device_class="power",
            ),
            cv.Optional(CONF_BQ25798_AC2_PRESENT_FLAG): binary_sensor.binary_sensor_schema(
                device_class="power",
            ),
            cv.Optional(CONF_BQ25798_AC1_PRESENT_FLAG): binary_sensor.binary_sensor_schema(
                device_class="power",
            ),
            cv.Optional(CONF_BQ25798_VBUS_PRESENT_FLAG): binary_sensor.binary_sensor_schema(
                device_class="power",
            ),
            cv.Optional(CONF_BQ25798_CHG_FLAG): binary_sensor.binary_sensor_schema(
                device_class="power",
            ),
            cv.Optional(CONF_BQ25798_ICO_FLAG): binary_sensor.binary_sensor_schema(
                device_class="power",
            ),
            cv.Optional(CONF_BQ25798_VBUS_FLAG): binary_sensor.binary_sensor_schema(
                device_class="power",
            ),
            cv.Optional(CONF_BQ25798_TREG_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_VBAT_PRESENT_FLAG): binary_sensor.binary_sensor_schema(
                device_class="battery",
            ),
            cv.Optional(CONF_BQ25798_BC1_2_DONE_FLAG): binary_sensor.binary_sensor_schema(
            ),
            cv.Optional(CONF_BQ25798_DPDM_DONE_FLAG): binary_sensor.binary_sensor_schema(
            ),
            cv.Optional(CONF_BQ25798_ADC_DONE_FLAG): binary_sensor.binary_sensor_schema(
            ),
            cv.Optional(CONF_BQ25798_VSYS_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_CHG_TMR_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_TRICHG_TMR_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_PRECHG_TMR_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_TOPOFF_TMR_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_VBATOTG_LOW_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_TS_COLD_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_TS_COOL_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_TS_WARM_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_TS_HOT_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_IBAT_REG_FLAG): binary_sensor.binary_sensor_schema(
                device_class="battery",
            ),
            cv.Optional(CONF_BQ25798_VBUS_OVP_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_VBAT_OVP_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_IBUS_OCP_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_IBAT_OCP_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_CONV_OCP_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_VAC2_OVP_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_VAC1_OVP_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_VSYS_SHORT_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_VSYS_OVP_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_OTG_OVP_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_OTG_UVP_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_TSHUT_FLAG): binary_sensor.binary_sensor_schema(
                device_class="problem",
            ),
            cv.Optional(CONF_BQ25798_ADC_EN): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_ADC_AVG_INIT): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_IBUS_ADC_DIS): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_IBAT_ADC_DIS): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_VBUS_ADC_DIS): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_VBAT_ADC_DIS): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_VSYS_ADC_DIS): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_TS_ADC_DIS): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_TDIE_ADC_DIS): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_DPLUS_ADC_DIS): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_DMINUS_ADC_DIS): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_VAC2_ADC_DIS): binary_sensor.binary_sensor_schema(
                device_class="",
            ),
            cv.Optional(CONF_BQ25798_VAC1_ADC_DIS): binary_sensor.binary_sensor_schema(
                device_class="",
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
    if reg_rst := config.get(CONF_BQ25798_REG_RST):
        sens = await binary_sensor.new_binary_sensor(reg_rst)
        cg.add(parent.set_reg_rst_binary_sensor(sens))
    if stop_wd_chg := config.get(CONF_BQ25798_STOP_WD_CHG):
        sens = await binary_sensor.new_binary_sensor(stop_wd_chg)
        cg.add(parent.set_stop_wd_chg_binary_sensor(sens))
    if en_trichg_tmr := config.get(CONF_BQ25798_EN_TRICHG_TMR):
        sens = await binary_sensor.new_binary_sensor(en_trichg_tmr)
        cg.add(parent.set_en_trichg_tmr_binary_sensor(sens))
    if en_prechg_tmr := config.get(CONF_BQ25798_EN_PRECHG_TMR):
        sens = await binary_sensor.new_binary_sensor(en_prechg_tmr)
        cg.add(parent.set_en_prechg_tmr_binary_sensor(sens))
    if en_chg_tmr := config.get(CONF_BQ25798_EN_CHG_TMR):
        sens = await binary_sensor.new_binary_sensor(en_chg_tmr)
        cg.add(parent.set_en_chg_tmr_binary_sensor(sens))
    if tmr2x_en := config.get(CONF_BQ25798_TMR2X_EN):
        sens = await binary_sensor.new_binary_sensor(tmr2x_en)
        cg.add(parent.set_tmr2x_en_binary_sensor(sens))
    if en_auto_ibatdis := config.get(CONF_BQ25798_EN_AUTO_IBATDIS):
        sens = await binary_sensor.new_binary_sensor(en_auto_ibatdis)
        cg.add(parent.set_en_auto_ibatdis_binary_sensor(sens))
    if force_ibatdis := config.get(CONF_BQ25798_FORCE_IBATDIS):
        sens = await binary_sensor.new_binary_sensor(force_ibatdis)
        cg.add(parent.set_force_ibatdis_binary_sensor(sens))
    if en_chg := config.get(CONF_BQ25798_EN_CHG):
        sens = await binary_sensor.new_binary_sensor(en_chg)
        cg.add(parent.set_en_chg_binary_sensor(sens))
    if en_ico := config.get(CONF_BQ25798_EN_ICO):
        sens = await binary_sensor.new_binary_sensor(en_ico)
        cg.add(parent.set_en_ico_binary_sensor(sens))
    if force_ico := config.get(CONF_BQ25798_FORCE_ICO):
        sens = await binary_sensor.new_binary_sensor(force_ico)
        cg.add(parent.set_force_ico_binary_sensor(sens))
    if en_hiz := config.get(CONF_BQ25798_EN_HIZ):
        sens = await binary_sensor.new_binary_sensor(en_hiz)
        cg.add(parent.set_en_hiz_binary_sensor(sens))
    if en_term := config.get(CONF_BQ25798_EN_TERM):
        sens = await binary_sensor.new_binary_sensor(en_term)
        cg.add(parent.set_en_term_binary_sensor(sens))
    if en_backup := config.get(CONF_BQ25798_EN_BACKUP):
        sens = await binary_sensor.new_binary_sensor(en_backup)
        cg.add(parent.set_en_backup_binary_sensor(sens))
    if wd_rst := config.get(CONF_BQ25798_WD_RST):
        sens = await binary_sensor.new_binary_sensor(wd_rst)
        cg.add(parent.set_wd_rst_binary_sensor(sens))
    if force_indet := config.get(CONF_BQ25798_FORCE_INDET):
        sens = await binary_sensor.new_binary_sensor(force_indet)
        cg.add(parent.set_force_indet_binary_sensor(sens))
    if auto_indet_en := config.get(CONF_BQ25798_AUTO_INDET_EN):
        sens = await binary_sensor.new_binary_sensor(auto_indet_en)
        cg.add(parent.set_auto_indet_en_binary_sensor(sens))
    if en_12v := config.get(CONF_BQ25798_EN_12V):
        sens = await binary_sensor.new_binary_sensor(en_12v)
        cg.add(parent.set_en_12v_binary_sensor(sens))
    if en_9v := config.get(CONF_BQ25798_EN_9V):
        sens = await binary_sensor.new_binary_sensor(en_9v)
        cg.add(parent.set_en_9v_binary_sensor(sens))
    if hvdcp_en := config.get(CONF_BQ25798_HVDCP_EN):
        sens = await binary_sensor.new_binary_sensor(hvdcp_en)
        cg.add(parent.set_hvdcp_en_binary_sensor(sens))
    if dis_acdrv := config.get(CONF_BQ25798_DIS_ACDRV):
        sens = await binary_sensor.new_binary_sensor(dis_acdrv)
        cg.add(parent.set_dis_acdrv_binary_sensor(sens))
    if en_otg := config.get(CONF_BQ25798_EN_OTG):
        sens = await binary_sensor.new_binary_sensor(en_otg)
        cg.add(parent.set_en_otg_binary_sensor(sens))
    if pfm_otg_dis := config.get(CONF_BQ25798_PFM_OTG_DIS):
        sens = await binary_sensor.new_binary_sensor(pfm_otg_dis)
        cg.add(parent.set_pfm_otg_dis_binary_sensor(sens))
    if pfm_fwd_dis := config.get(CONF_BQ25798_PFM_FWD_DIS):
        sens = await binary_sensor.new_binary_sensor(pfm_fwd_dis)
        cg.add(parent.set_pfm_fwd_dis_binary_sensor(sens))
    if dis_ldo := config.get(CONF_BQ25798_DIS_LDO):
        sens = await binary_sensor.new_binary_sensor(dis_ldo)
        cg.add(parent.set_dis_ldo_binary_sensor(sens))
    if dis_otg_ooa := config.get(CONF_BQ25798_DIS_OTG_OOA):
        sens = await binary_sensor.new_binary_sensor(dis_otg_ooa)
        cg.add(parent.set_dis_otg_ooa_binary_sensor(sens))
    if dis_fwd_ooa := config.get(CONF_BQ25798_DIS_FWD_OOA):
        sens = await binary_sensor.new_binary_sensor(dis_fwd_ooa)
        cg.add(parent.set_dis_fwd_ooa_binary_sensor(sens))
    if en_acdrv2 := config.get(CONF_BQ25798_EN_ACDRV2):
        sens = await binary_sensor.new_binary_sensor(en_acdrv2)
        cg.add(parent.set_en_acdrv2_binary_sensor(sens))
    if en_acdrv1 := config.get(CONF_BQ25798_EN_ACDRV1):
        sens = await binary_sensor.new_binary_sensor(en_acdrv1)
        cg.add(parent.set_en_acdrv1_binary_sensor(sens))
    if dis_stat := config.get(CONF_BQ25798_DIS_STAT):
        sens = await binary_sensor.new_binary_sensor(dis_stat)
        cg.add(parent.set_dis_stat_binary_sensor(sens))
    if dis_vsys_short := config.get(CONF_BQ25798_DIS_VSYS_SHORT):
        sens = await binary_sensor.new_binary_sensor(dis_vsys_short)
        cg.add(parent.set_dis_vsys_short_binary_sensor(sens))
    if dis_votg_uvp := config.get(CONF_BQ25798_DIS_VOTG_UVP):
        sens = await binary_sensor.new_binary_sensor(dis_votg_uvp)
        cg.add(parent.set_dis_votg_uvp_binary_sensor(sens))
    if force_vindpm_det := config.get(CONF_BQ25798_FORCE_VINDPM_DET):
        sens = await binary_sensor.new_binary_sensor(force_vindpm_det)
        cg.add(parent.set_force_vindpm_det_binary_sensor(sens))
    if en_ibus_ocp := config.get(CONF_BQ25798_EN_IBUS_OCP):
        sens = await binary_sensor.new_binary_sensor(en_ibus_ocp)
        cg.add(parent.set_en_ibus_ocp_binary_sensor(sens))
    if sfet_present := config.get(CONF_BQ25798_SFET_PRESENT):
        sens = await binary_sensor.new_binary_sensor(sfet_present)
        cg.add(parent.set_sfet_present_binary_sensor(sens))
    if en_ibat := config.get(CONF_BQ25798_EN_IBAT):
        sens = await binary_sensor.new_binary_sensor(en_ibat)
        cg.add(parent.set_en_ibat_binary_sensor(sens))
    if en_iindpm := config.get(CONF_BQ25798_EN_IINDPM):
        sens = await binary_sensor.new_binary_sensor(en_iindpm)
        cg.add(parent.set_en_iindpm_binary_sensor(sens))
    if en_extilim := config.get(CONF_BQ25798_EN_EXTILIM):
        sens = await binary_sensor.new_binary_sensor(en_extilim)
        cg.add(parent.set_en_extilim_binary_sensor(sens))
    if en_batoc := config.get(CONF_BQ25798_EN_BATOC):
        sens = await binary_sensor.new_binary_sensor(en_batoc)
        cg.add(parent.set_en_batoc_binary_sensor(sens))
    if en_mppt := config.get(CONF_BQ25798_EN_MPPT):
        sens = await binary_sensor.new_binary_sensor(en_mppt)
        cg.add(parent.set_en_mppt_binary_sensor(sens))
    if vbus_pd_en := config.get(CONF_BQ25798_VBUS_PD_EN):
        sens = await binary_sensor.new_binary_sensor(vbus_pd_en)
        cg.add(parent.set_vbus_pd_en_binary_sensor(sens))
    if vac1_pd_en := config.get(CONF_BQ25798_VAC1_PD_EN):
        sens = await binary_sensor.new_binary_sensor(vac1_pd_en)
        cg.add(parent.set_vac1_pd_en_binary_sensor(sens))
    if vac2_pd_en := config.get(CONF_BQ25798_VAC2_PD_EN):
        sens = await binary_sensor.new_binary_sensor(vac2_pd_en)
        cg.add(parent.set_vac2_pd_en_binary_sensor(sens))
    if ts_ignore := config.get(CONF_BQ25798_TS_IGNORE):
        sens = await binary_sensor.new_binary_sensor(ts_ignore)
        cg.add(parent.set_ts_ignore_binary_sensor(sens))
    if bc12_done_stat := config.get(CONF_BQ25798_BC12_DONE_STAT):
        sens = await binary_sensor.new_binary_sensor(bc12_done_stat)
        cg.add(parent.set_bc12_done_stat_binary_sensor(sens))
    if acrb2_stat := config.get(CONF_BQ25798_ACRB2_STAT):
        sens = await binary_sensor.new_binary_sensor(acrb2_stat)
        cg.add(parent.set_acrb2_stat_binary_sensor(sens))
    if acrb1_stat := config.get(CONF_BQ25798_ACRB1_STAT):
        sens = await binary_sensor.new_binary_sensor(acrb1_stat)
        cg.add(parent.set_acrb1_stat_binary_sensor(sens))
    if adc_done_stat := config.get(CONF_BQ25798_ADC_DONE_STAT):
        sens = await binary_sensor.new_binary_sensor(adc_done_stat)
        cg.add(parent.set_adc_done_stat_binary_sensor(sens))
    if ibat_reg_stat := config.get(CONF_BQ25798_IBAT_REG_STAT):
        sens = await binary_sensor.new_binary_sensor(ibat_reg_stat)
        cg.add(parent.set_ibat_reg_stat_binary_sensor(sens))
    if vbus_ovp_stat := config.get(CONF_BQ25798_VBUS_OVP_STAT):
        sens = await binary_sensor.new_binary_sensor(vbus_ovp_stat)
        cg.add(parent.set_vbus_ovp_stat_binary_sensor(sens))
    if vbat_ovp_stat := config.get(CONF_BQ25798_VBAT_OVP_STAT):
        sens = await binary_sensor.new_binary_sensor(vbat_ovp_stat)
        cg.add(parent.set_vbat_ovp_stat_binary_sensor(sens))
    if ibus_ocp_stat := config.get(CONF_BQ25798_IBUS_OCP_STAT):
        sens = await binary_sensor.new_binary_sensor(ibus_ocp_stat)
        cg.add(parent.set_ibus_ocp_stat_binary_sensor(sens))
    if ibat_ocp_stat := config.get(CONF_BQ25798_IBAT_OCP_STAT):
        sens = await binary_sensor.new_binary_sensor(ibat_ocp_stat)
        cg.add(parent.set_ibat_ocp_stat_binary_sensor(sens))
    if conv_ocp_stat := config.get(CONF_BQ25798_CONV_OCP_STAT):
        sens = await binary_sensor.new_binary_sensor(conv_ocp_stat)
        cg.add(parent.set_conv_ocp_stat_binary_sensor(sens))
    if vac2_ovp_stat := config.get(CONF_BQ25798_VAC2_OVP_STAT):
        sens = await binary_sensor.new_binary_sensor(vac2_ovp_stat)
        cg.add(parent.set_vac2_ovp_stat_binary_sensor(sens))
    if vac1_ovp_stat := config.get(CONF_BQ25798_VAC1_OVP_STAT):
        sens = await binary_sensor.new_binary_sensor(vac1_ovp_stat)
        cg.add(parent.set_vac1_ovp_stat_binary_sensor(sens))
    if vsys_short_stat := config.get(CONF_BQ25798_VSYS_SHORT_STAT):
        sens = await binary_sensor.new_binary_sensor(vsys_short_stat)
        cg.add(parent.set_vsys_short_stat_binary_sensor(sens))
    if vsys_ovp_stat := config.get(CONF_BQ25798_VSYS_OVP_STAT):
        sens = await binary_sensor.new_binary_sensor(vsys_ovp_stat)
        cg.add(parent.set_vsys_ovp_stat_binary_sensor(sens))
    if otg_ovp_stat := config.get(CONF_BQ25798_OTG_OVP_STAT):
        sens = await binary_sensor.new_binary_sensor(otg_ovp_stat)
        cg.add(parent.set_otg_ovp_stat_binary_sensor(sens))
    if otg_uvp_stat := config.get(CONF_BQ25798_OTG_UVP_STAT):
        sens = await binary_sensor.new_binary_sensor(otg_uvp_stat)
        cg.add(parent.set_otg_uvp_stat_binary_sensor(sens))
    if tshut_stat := config.get(CONF_BQ25798_TSHUT_STAT):
        sens = await binary_sensor.new_binary_sensor(tshut_stat)
        cg.add(parent.set_tshut_stat_binary_sensor(sens))
    if iindpm_flag := config.get(CONF_BQ25798_IINDPM_FLAG):
        sens = await binary_sensor.new_binary_sensor(iindpm_flag)
        cg.add(parent.set_iindpm_flag_binary_sensor(sens))
    if vindpm_flag := config.get(CONF_BQ25798_VINDPM_FLAG):
        sens = await binary_sensor.new_binary_sensor(vindpm_flag)
        cg.add(parent.set_vindpm_flag_binary_sensor(sens))
    if wd_flag := config.get(CONF_BQ25798_WD_FLAG):
        sens = await binary_sensor.new_binary_sensor(wd_flag)
        cg.add(parent.set_wd_flag_binary_sensor(sens))
    if poorsrc_flag := config.get(CONF_BQ25798_POORSRC_FLAG):
        sens = await binary_sensor.new_binary_sensor(poorsrc_flag)
        cg.add(parent.set_poorsrc_flag_binary_sensor(sens))
    if pg_flag := config.get(CONF_BQ25798_PG_FLAG):
        sens = await binary_sensor.new_binary_sensor(pg_flag)
        cg.add(parent.set_pg_flag_binary_sensor(sens))
    if ac2_present_flag := config.get(CONF_BQ25798_AC2_PRESENT_FLAG):
        sens = await binary_sensor.new_binary_sensor(ac2_present_flag)
        cg.add(parent.set_ac2_present_flag_binary_sensor(sens))
    if ac1_present_flag := config.get(CONF_BQ25798_AC1_PRESENT_FLAG):
        sens = await binary_sensor.new_binary_sensor(ac1_present_flag)
        cg.add(parent.set_ac1_present_flag_binary_sensor(sens))
    if vbus_present_flag := config.get(CONF_BQ25798_VBUS_PRESENT_FLAG):
        sens = await binary_sensor.new_binary_sensor(vbus_present_flag)
        cg.add(parent.set_vbus_present_flag_binary_sensor(sens))
    if chg_flag := config.get(CONF_BQ25798_CHG_FLAG):
        sens = await binary_sensor.new_binary_sensor(chg_flag)
        cg.add(parent.set_chg_flag_binary_sensor(sens))
    if ico_flag := config.get(CONF_BQ25798_ICO_FLAG):
        sens = await binary_sensor.new_binary_sensor(ico_flag)
        cg.add(parent.set_ico_flag_binary_sensor(sens))
    if vbus_flag := config.get(CONF_BQ25798_VBUS_FLAG):
        sens = await binary_sensor.new_binary_sensor(vbus_flag)
        cg.add(parent.set_vbus_flag_binary_sensor(sens))
    if treg_flag := config.get(CONF_BQ25798_TREG_FLAG):
        sens = await binary_sensor.new_binary_sensor(treg_flag)
        cg.add(parent.set_treg_flag_binary_sensor(sens))
    if vbat_present_flag := config.get(CONF_BQ25798_VBAT_PRESENT_FLAG):
        sens = await binary_sensor.new_binary_sensor(vbat_present_flag)
        cg.add(parent.set_vbat_present_flag_binary_sensor(sens))
    if bc1_2_done_flag := config.get(CONF_BQ25798_BC1_2_DONE_FLAG):
        sens = await binary_sensor.new_binary_sensor(bc1_2_done_flag)
        cg.add(parent.set_bc1_2_done_flag_binary_sensor(sens))
    if dpdm_done_flag := config.get(CONF_BQ25798_DPDM_DONE_FLAG):
        sens = await binary_sensor.new_binary_sensor(dpdm_done_flag)
        cg.add(parent.set_dpdm_done_flag_binary_sensor(sens))
    if adc_done_flag := config.get(CONF_BQ25798_ADC_DONE_FLAG):
        sens = await binary_sensor.new_binary_sensor(adc_done_flag)
        cg.add(parent.set_adc_done_flag_binary_sensor(sens))
    if vsys_flag := config.get(CONF_BQ25798_VSYS_FLAG):
        sens = await binary_sensor.new_binary_sensor(vsys_flag)
        cg.add(parent.set_vsys_flag_binary_sensor(sens))
    if chg_tmr_flag := config.get(CONF_BQ25798_CHG_TMR_FLAG):
        sens = await binary_sensor.new_binary_sensor(chg_tmr_flag)
        cg.add(parent.set_chg_tmr_flag_binary_sensor(sens))
    if trichg_tmr_flag := config.get(CONF_BQ25798_TRICHG_TMR_FLAG):
        sens = await binary_sensor.new_binary_sensor(trichg_tmr_flag)
        cg.add(parent.set_trichg_tmr_flag_binary_sensor(sens))
    if prechg_tmr_flag := config.get(CONF_BQ25798_PRECHG_TMR_FLAG):
        sens = await binary_sensor.new_binary_sensor(prechg_tmr_flag)
        cg.add(parent.set_prechg_tmr_flag_binary_sensor(sens))
    if topoff_tmr_flag := config.get(CONF_BQ25798_TOPOFF_TMR_FLAG):
        sens = await binary_sensor.new_binary_sensor(topoff_tmr_flag)
        cg.add(parent.set_topoff_tmr_flag_binary_sensor(sens))
    if vbatotg_low_flag := config.get(CONF_BQ25798_VBATOTG_LOW_FLAG):
        sens = await binary_sensor.new_binary_sensor(vbatotg_low_flag)
        cg.add(parent.set_vbatotg_low_flag_binary_sensor(sens))
    if ts_cold_flag := config.get(CONF_BQ25798_TS_COLD_FLAG):
        sens = await binary_sensor.new_binary_sensor(ts_cold_flag)
        cg.add(parent.set_ts_cold_flag_binary_sensor(sens))
    if ts_cool_flag := config.get(CONF_BQ25798_TS_COOL_FLAG):
        sens = await binary_sensor.new_binary_sensor(ts_cool_flag)
        cg.add(parent.set_ts_cool_flag_binary_sensor(sens))
    if ts_warm_flag := config.get(CONF_BQ25798_TS_WARM_FLAG):
        sens = await binary_sensor.new_binary_sensor(ts_warm_flag)
        cg.add(parent.set_ts_warm_flag_binary_sensor(sens))
    if ts_hot_flag := config.get(CONF_BQ25798_TS_HOT_FLAG):
        sens = await binary_sensor.new_binary_sensor(ts_hot_flag)
        cg.add(parent.set_ts_hot_flag_binary_sensor(sens))
    if ibat_reg_flag := config.get(CONF_BQ25798_IBAT_REG_FLAG):
        sens = await binary_sensor.new_binary_sensor(ibat_reg_flag)
        cg.add(parent.set_ibat_reg_flag_binary_sensor(sens))
    if vbus_ovp_flag := config.get(CONF_BQ25798_VBUS_OVP_FLAG):
        sens = await binary_sensor.new_binary_sensor(vbus_ovp_flag)
        cg.add(parent.set_vbus_ovp_flag_binary_sensor(sens))
    if vbat_ovp_flag := config.get(CONF_BQ25798_VBAT_OVP_FLAG):
        sens = await binary_sensor.new_binary_sensor(vbat_ovp_flag)
        cg.add(parent.set_vbat_ovp_flag_binary_sensor(sens))
    if ibus_ocp_flag := config.get(CONF_BQ25798_IBUS_OCP_FLAG):
        sens = await binary_sensor.new_binary_sensor(ibus_ocp_flag)
        cg.add(parent.set_ibus_ocp_flag_binary_sensor(sens))
    if ibat_ocp_flag := config.get(CONF_BQ25798_IBAT_OCP_FLAG):
        sens = await binary_sensor.new_binary_sensor(ibat_ocp_flag)
        cg.add(parent.set_ibat_ocp_flag_binary_sensor(sens))
    if conv_ocp_flag := config.get(CONF_BQ25798_CONV_OCP_FLAG):
        sens = await binary_sensor.new_binary_sensor(conv_ocp_flag)
        cg.add(parent.set_conv_ocp_flag_binary_sensor(sens))
    if vac2_ovp_flag := config.get(CONF_BQ25798_VAC2_OVP_FLAG):
        sens = await binary_sensor.new_binary_sensor(vac2_ovp_flag)
        cg.add(parent.set_vac2_ovp_flag_binary_sensor(sens))
    if vac1_ovp_flag := config.get(CONF_BQ25798_VAC1_OVP_FLAG):
        sens = await binary_sensor.new_binary_sensor(vac1_ovp_flag)
        cg.add(parent.set_vac1_ovp_flag_binary_sensor(sens))
    if vsys_short_flag := config.get(CONF_BQ25798_VSYS_SHORT_FLAG):
        sens = await binary_sensor.new_binary_sensor(vsys_short_flag)
        cg.add(parent.set_vsys_short_flag_binary_sensor(sens))
    if vsys_ovp_flag := config.get(CONF_BQ25798_VSYS_OVP_FLAG):
        sens = await binary_sensor.new_binary_sensor(vsys_ovp_flag)
        cg.add(parent.set_vsys_ovp_flag_binary_sensor(sens))
    if otg_ovp_flag := config.get(CONF_BQ25798_OTG_OVP_FLAG):
        sens = await binary_sensor.new_binary_sensor(otg_ovp_flag)
        cg.add(parent.set_otg_ovp_flag_binary_sensor(sens))
    if otg_uvp_flag := config.get(CONF_BQ25798_OTG_UVP_FLAG):
        sens = await binary_sensor.new_binary_sensor(otg_uvp_flag)
        cg.add(parent.set_otg_uvp_flag_binary_sensor(sens))
    if tshut_flag := config.get(CONF_BQ25798_TSHUT_FLAG):
        sens = await binary_sensor.new_binary_sensor(tshut_flag)
        cg.add(parent.set_tshut_flag_binary_sensor(sens))
    if adc_en := config.get(CONF_BQ25798_ADC_EN):
        sens = await binary_sensor.new_binary_sensor(adc_en)
        cg.add(parent.set_adc_en_binary_sensor(sens))
    if adc_avg_init := config.get(CONF_BQ25798_ADC_AVG_INIT):
        sens = await binary_sensor.new_binary_sensor(adc_avg_init)
        cg.add(parent.set_adc_avg_init_binary_sensor(sens))
    if ibus_adc_dis := config.get(CONF_BQ25798_IBUS_ADC_DIS):
        sens = await binary_sensor.new_binary_sensor(ibus_adc_dis)
        cg.add(parent.set_ibus_adc_dis_binary_sensor(sens))
    if ibat_adc_dis := config.get(CONF_BQ25798_IBAT_ADC_DIS):
        sens = await binary_sensor.new_binary_sensor(ibat_adc_dis)
        cg.add(parent.set_ibat_adc_dis_binary_sensor(sens))
    if vbus_adc_dis := config.get(CONF_BQ25798_VBUS_ADC_DIS):
        sens = await binary_sensor.new_binary_sensor(vbus_adc_dis)
        cg.add(parent.set_vbus_adc_dis_binary_sensor(sens))
    if vbat_adc_dis := config.get(CONF_BQ25798_VBAT_ADC_DIS):
        sens = await binary_sensor.new_binary_sensor(vbat_adc_dis)
        cg.add(parent.set_vbat_adc_dis_binary_sensor(sens))
    if vsys_adc_dis := config.get(CONF_BQ25798_VSYS_ADC_DIS):
        sens = await binary_sensor.new_binary_sensor(vsys_adc_dis)
        cg.add(parent.set_vsys_adc_dis_binary_sensor(sens))
    if ts_adc_dis := config.get(CONF_BQ25798_TS_ADC_DIS):
        sens = await binary_sensor.new_binary_sensor(ts_adc_dis)
        cg.add(parent.set_ts_adc_dis_binary_sensor(sens))
    if tdie_adc_dis := config.get(CONF_BQ25798_TDIE_ADC_DIS):
        sens = await binary_sensor.new_binary_sensor(tdie_adc_dis)
        cg.add(parent.set_tdie_adc_dis_binary_sensor(sens))
    if dplus_adc_dis := config.get(CONF_BQ25798_DPLUS_ADC_DIS):
        sens = await binary_sensor.new_binary_sensor(dplus_adc_dis)
        cg.add(parent.set_dplus_adc_dis_binary_sensor(sens))
    if dminus_adc_dis := config.get(CONF_BQ25798_DMINUS_ADC_DIS):
        sens = await binary_sensor.new_binary_sensor(dminus_adc_dis)
        cg.add(parent.set_dminus_adc_dis_binary_sensor(sens))
    if vac2_adc_dis := config.get(CONF_BQ25798_VAC2_ADC_DIS):
        sens = await binary_sensor.new_binary_sensor(vac2_adc_dis)
        cg.add(parent.set_vac2_adc_dis_binary_sensor(sens))
    if vac1_adc_dis := config.get(CONF_BQ25798_VAC1_ADC_DIS):
        sens = await binary_sensor.new_binary_sensor(vac1_adc_dis)
        cg.add(parent.set_vac1_adc_dis_binary_sensor(sens))