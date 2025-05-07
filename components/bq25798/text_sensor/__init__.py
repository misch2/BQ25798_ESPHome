import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import core
from esphome.components import text_sensor
from esphome.const import (
    CONF_ID,
)

from .. import (
    CONF_BQ25798_ID,
    BQ25798_CLIENT_SCHEMA,
    bq25798_ns, 
)

DEPENDENCIES = ["bq25798"]

BQ25798TextSensor = bq25798_ns.class_("BQ25798TextSensor", cg.Component)

# Enum settings
CONF_BQ25798_VBAT_LOWV = "vbat_lowv"
CONF_BQ25798_CELL = "cell"
CONF_BQ25798_TRECHG = "trechg"
CONF_BQ25798_PRECHG_TMR = "prechg_tmr"
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
CONF_BQ25798_DPLUS_DAC = "dplus_dac"
CONF_BQ25798_DMINUS_DAC = "dminus_dac"
CONF_BQ25798_PN = "pn"
CONF_BQ25798_DEV_REV = "dev_rev"

CONFIG_SCHEMA = (
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(BQ25798TextSensor),
            cv.Optional(CONF_BQ25798_VBAT_LOWV): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_CELL): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_TRECHG): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_PRECHG_TMR): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_TOPOFF_TMR): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_CHG_TMR): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_VBUS_BACKUP): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_VAC_OVP): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_WATCHDOG): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_SDRV_CTRL): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_SDRV_DLY): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_WKUP_DLY): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_PWM_FREQ): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_IBAT_REG): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_VOC_PCT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_VOC_DLY): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_VOC_RATE): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_TREG): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_TSHUT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_BKUP_ACFET1_ON): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_JEITA_VSET): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_JEITA_ISETH): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_JEITA_ISETC): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_TS_COOL): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_TS_WARM): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_BHOT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_BCOLD): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_IINDPM_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_VINDPM_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_WD_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_PG_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_AC2_PRESENT_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_AC1_PRESENT_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_VBUS_PRESENT_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_CHG_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_VBUS_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_ICO_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_TREG_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_DPDM_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_VBAT_PRESENT_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_VSYS_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_CHG_TMR_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_TRICHG_TMR_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_PRECHG_TMR_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_VBATOTG_LOW_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_TS_COLD_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_TS_COOL_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_TS_WARM_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_TS_HOT_STAT): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_ADC_RATE): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_ADC_SAMPLE): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_ADC_AVG): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_DPLUS_DAC): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_DMINUS_DAC): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_PN): text_sensor.text_sensor_schema(),
            cv.Optional(CONF_BQ25798_DEV_REV): text_sensor.text_sensor_schema(),
        }
    )
    .extend(BQ25798_CLIENT_SCHEMA)
)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])

    await cg.register_component(var, config)
    parent = await cg.get_variable(config[CONF_BQ25798_ID])

    # Sensors
    if vbat_lowv := config.get(CONF_BQ25798_VBAT_LOWV):
        sens = await text_sensor.new_text_sensor(vbat_lowv)
        cg.add(parent.set_vbat_lowv_text_sensor(sens))
    if cell := config.get(CONF_BQ25798_CELL):
        sens = await text_sensor.new_text_sensor(cell)
        cg.add(parent.set_cell_text_sensor(sens))
    if trechg := config.get(CONF_BQ25798_TRECHG):
        sens = await text_sensor.new_text_sensor(trechg)
        cg.add(parent.set_trechg_text_sensor(sens))
    if prechg_tmr := config.get(CONF_BQ25798_PRECHG_TMR):
        sens = await text_sensor.new_text_sensor(prechg_tmr)
        cg.add(parent.set_prechg_tmr_text_sensor(sens))
    if topoff_tmr := config.get(CONF_BQ25798_TOPOFF_TMR):
        sens = await text_sensor.new_text_sensor(topoff_tmr)
        cg.add(parent.set_topoff_tmr_text_sensor(sens))
    if chg_tmr := config.get(CONF_BQ25798_CHG_TMR):
        sens = await text_sensor.new_text_sensor(chg_tmr)
        cg.add(parent.set_chg_tmr_text_sensor(sens))
    if vbus_backup := config.get(CONF_BQ25798_VBUS_BACKUP):
        sens = await text_sensor.new_text_sensor(vbus_backup)
        cg.add(parent.set_vbus_backup_text_sensor(sens))
    if vac_ovp := config.get(CONF_BQ25798_VAC_OVP):
        sens = await text_sensor.new_text_sensor(vac_ovp)
        cg.add(parent.set_vac_ovp_text_sensor(sens))
    if watchdog := config.get(CONF_BQ25798_WATCHDOG):
        sens = await text_sensor.new_text_sensor(watchdog)
        cg.add(parent.set_watchdog_text_sensor(sens))
    if sdrv_ctrl := config.get(CONF_BQ25798_SDRV_CTRL):
        sens = await text_sensor.new_text_sensor(sdrv_ctrl)
        cg.add(parent.set_sdrv_ctrl_text_sensor(sens))
    if sdrv_dly := config.get(CONF_BQ25798_SDRV_DLY):
        sens = await text_sensor.new_text_sensor(sdrv_dly)
        cg.add(parent.set_sdrv_dly_text_sensor(sens))
    if wkup_dly := config.get(CONF_BQ25798_WKUP_DLY):
        sens = await text_sensor.new_text_sensor(wkup_dly)
        cg.add(parent.set_wkup_dly_text_sensor(sens))
    if pwm_freq := config.get(CONF_BQ25798_PWM_FREQ):
        sens = await text_sensor.new_text_sensor(pwm_freq)
        cg.add(parent.set_pwm_freq_text_sensor(sens))
    if ibat_reg := config.get(CONF_BQ25798_IBAT_REG):
        sens = await text_sensor.new_text_sensor(ibat_reg)
        cg.add(parent.set_ibat_reg_text_sensor(sens))
    if voc_pct := config.get(CONF_BQ25798_VOC_PCT):
        sens = await text_sensor.new_text_sensor(voc_pct)
        cg.add(parent.set_voc_pct_text_sensor(sens))
    if voc_dly := config.get(CONF_BQ25798_VOC_DLY):
        sens = await text_sensor.new_text_sensor(voc_dly)
        cg.add(parent.set_voc_dly_text_sensor(sens))
    if voc_rate := config.get(CONF_BQ25798_VOC_RATE):
        sens = await text_sensor.new_text_sensor(voc_rate)
        cg.add(parent.set_voc_rate_text_sensor(sens))
    if treg := config.get(CONF_BQ25798_TREG):
        sens = await text_sensor.new_text_sensor(treg)
        cg.add(parent.set_treg_text_sensor(sens))
    if tshut := config.get(CONF_BQ25798_TSHUT):
        sens = await text_sensor.new_text_sensor(tshut)
        cg.add(parent.set_tshut_text_sensor(sens))
    if bkup_acfet1_on := config.get(CONF_BQ25798_BKUP_ACFET1_ON):
        sens = await text_sensor.new_text_sensor(bkup_acfet1_on)
        cg.add(parent.set_bkup_acfet1_on_text_sensor(sens))
    if jeita_vset := config.get(CONF_BQ25798_JEITA_VSET):
        sens = await text_sensor.new_text_sensor(jeita_vset)
        cg.add(parent.set_jeita_vset_text_sensor(sens))
    if jeita_iseth := config.get(CONF_BQ25798_JEITA_ISETH):
        sens = await text_sensor.new_text_sensor(jeita_iseth)
        cg.add(parent.set_jeita_iseth_text_sensor(sens))
    if jeita_isetc := config.get(CONF_BQ25798_JEITA_ISETC):
        sens = await text_sensor.new_text_sensor(jeita_isetc)
        cg.add(parent.set_jeita_isetc_text_sensor(sens))
    if ts_cool := config.get(CONF_BQ25798_TS_COOL):
        sens = await text_sensor.new_text_sensor(ts_cool)
        cg.add(parent.set_ts_cool_text_sensor(sens))
    if ts_warm := config.get(CONF_BQ25798_TS_WARM):
        sens = await text_sensor.new_text_sensor(ts_warm)
        cg.add(parent.set_ts_warm_text_sensor(sens))
    if bhot := config.get(CONF_BQ25798_BHOT):
        sens = await text_sensor.new_text_sensor(bhot)
        cg.add(parent.set_bhot_text_sensor(sens))
    if bcold := config.get(CONF_BQ25798_BCOLD):
        sens = await text_sensor.new_text_sensor(bcold)
        cg.add(parent.set_bcold_text_sensor(sens))
    if iindpm_stat := config.get(CONF_BQ25798_IINDPM_STAT):
        sens = await text_sensor.new_text_sensor(iindpm_stat)
        cg.add(parent.set_iindpm_stat_text_sensor(sens))
    if vindpm_stat := config.get(CONF_BQ25798_VINDPM_STAT):
        sens = await text_sensor.new_text_sensor(vindpm_stat)
        cg.add(parent.set_vindpm_stat_text_sensor(sens))
    if wd_stat := config.get(CONF_BQ25798_WD_STAT):
        sens = await text_sensor.new_text_sensor(wd_stat)
        cg.add(parent.set_wd_stat_text_sensor(sens))
    if pg_stat := config.get(CONF_BQ25798_PG_STAT):
        sens = await text_sensor.new_text_sensor(pg_stat)
        cg.add(parent.set_pg_stat_text_sensor(sens))
    if ac2_present_stat := config.get(CONF_BQ25798_AC2_PRESENT_STAT):
        sens = await text_sensor.new_text_sensor(ac2_present_stat)
        cg.add(parent.set_ac2_present_stat_text_sensor(sens))
    if ac1_present_stat := config.get(CONF_BQ25798_AC1_PRESENT_STAT):
        sens = await text_sensor.new_text_sensor(ac1_present_stat)
        cg.add(parent.set_ac1_present_stat_text_sensor(sens))
    if vbus_present_stat := config.get(CONF_BQ25798_VBUS_PRESENT_STAT):
        sens = await text_sensor.new_text_sensor(vbus_present_stat)
        cg.add(parent.set_vbus_present_stat_text_sensor(sens))
    if chg_stat := config.get(CONF_BQ25798_CHG_STAT):
        sens = await text_sensor.new_text_sensor(chg_stat)
        cg.add(parent.set_chg_stat_text_sensor(sens))
    if vbus_stat := config.get(CONF_BQ25798_VBUS_STAT):
        sens = await text_sensor.new_text_sensor(vbus_stat)
        cg.add(parent.set_vbus_stat_text_sensor(sens))
    if ico_stat := config.get(CONF_BQ25798_ICO_STAT):
        sens = await text_sensor.new_text_sensor(ico_stat)
        cg.add(parent.set_ico_stat_text_sensor(sens))
    if treg_stat := config.get(CONF_BQ25798_TREG_STAT):
        sens = await text_sensor.new_text_sensor(treg_stat)
        cg.add(parent.set_treg_stat_text_sensor(sens))
    if dpdm_stat := config.get(CONF_BQ25798_DPDM_STAT):
        sens = await text_sensor.new_text_sensor(dpdm_stat)
        cg.add(parent.set_dpdm_stat_text_sensor(sens))
    if vbat_present_stat := config.get(CONF_BQ25798_VBAT_PRESENT_STAT):
        sens = await text_sensor.new_text_sensor(vbat_present_stat)
        cg.add(parent.set_vbat_present_stat_text_sensor(sens))
    if vsys_stat := config.get(CONF_BQ25798_VSYS_STAT):
        sens = await text_sensor.new_text_sensor(vsys_stat)
        cg.add(parent.set_vsys_stat_text_sensor(sens))
    if chg_tmr_stat := config.get(CONF_BQ25798_CHG_TMR_STAT):
        sens = await text_sensor.new_text_sensor(chg_tmr_stat)
        cg.add(parent.set_chg_tmr_stat_text_sensor(sens))
    if trichg_tmr_stat := config.get(CONF_BQ25798_TRICHG_TMR_STAT):
        sens = await text_sensor.new_text_sensor(trichg_tmr_stat)
        cg.add(parent.set_trichg_tmr_stat_text_sensor(sens))
    if prechg_tmr_stat := config.get(CONF_BQ25798_PRECHG_TMR_STAT):
        sens = await text_sensor.new_text_sensor(prechg_tmr_stat)
        cg.add(parent.set_prechg_tmr_stat_text_sensor(sens))
    if vbatotg_low_stat := config.get(CONF_BQ25798_VBATOTG_LOW_STAT):
        sens = await text_sensor.new_text_sensor(vbatotg_low_stat)
        cg.add(parent.set_vbatotg_low_stat_text_sensor(sens))
    if ts_cold_stat := config.get(CONF_BQ25798_TS_COLD_STAT):
        sens = await text_sensor.new_text_sensor(ts_cold_stat)
        cg.add(parent.set_ts_cold_stat_text_sensor(sens))
    if ts_cool_stat := config.get(CONF_BQ25798_TS_COOL_STAT):
        sens = await text_sensor.new_text_sensor(ts_cool_stat)
        cg.add(parent.set_ts_cool_stat_text_sensor(sens))
    if ts_warm_stat := config.get(CONF_BQ25798_TS_WARM_STAT):
        sens = await text_sensor.new_text_sensor(ts_warm_stat)
        cg.add(parent.set_ts_warm_stat_text_sensor(sens))
    if ts_hot_stat := config.get(CONF_BQ25798_TS_HOT_STAT):
        sens = await text_sensor.new_text_sensor(ts_hot_stat)
        cg.add(parent.set_ts_hot_stat_text_sensor(sens))
    if adc_rate := config.get(CONF_BQ25798_ADC_RATE):
        sens = await text_sensor.new_text_sensor(adc_rate)
        cg.add(parent.set_adc_rate_text_sensor(sens))
    if adc_sample := config.get(CONF_BQ25798_ADC_SAMPLE):
        sens = await text_sensor.new_text_sensor(adc_sample)
        cg.add(parent.set_adc_sample_text_sensor(sens))
    if adc_avg := config.get(CONF_BQ25798_ADC_AVG):
        sens = await text_sensor.new_text_sensor(adc_avg)
        cg.add(parent.set_adc_avg_text_sensor(sens))
    if dplus_dac := config.get(CONF_BQ25798_DPLUS_DAC):
        sens = await text_sensor.new_text_sensor(dplus_dac)
        cg.add(parent.set_dplus_dac_text_sensor(sens))
    if dminus_dac := config.get(CONF_BQ25798_DMINUS_DAC):
        sens = await text_sensor.new_text_sensor(dminus_dac)
        cg.add(parent.set_dminus_dac_text_sensor(sens))
    if pn := config.get(CONF_BQ25798_PN):
        sens = await text_sensor.new_text_sensor(pn)
        cg.add(parent.set_pn_text_sensor(sens))
    if dev_rev := config.get(CONF_BQ25798_DEV_REV):
        sens = await text_sensor.new_text_sensor(dev_rev)
        cg.add(parent.set_dev_rev_text_sensor(sens))