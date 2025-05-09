import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import number
from esphome.const import (
    CONF_ID,
    ENTITY_CATEGORY_CONFIG,
)

from .. import (
    CONF_BQ25798_ID,
    bq25798_ns,
    BQ25798Component
)

DEPENDENCIES = ["bq25798"]


# Numeric settings

BQ25798VsysminNumber = bq25798_ns.class_("BQ25798VsysminNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_VSYSMIN = "vsysmin"

BQ25798VregNumber = bq25798_ns.class_("BQ25798VregNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_VREG = "vreg"

BQ25798IchgNumber = bq25798_ns.class_("BQ25798IchgNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_ICHG = "ichg"

BQ25798VindpmNumber = bq25798_ns.class_("BQ25798VindpmNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_VINDPM = "vindpm"

BQ25798IindpmNumber = bq25798_ns.class_("BQ25798IindpmNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_IINDPM = "iindpm"

BQ25798VbatLowvNumber = bq25798_ns.class_("BQ25798VbatLowvNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_VBAT_LOWV = "vbat_lowv"

BQ25798IprechgNumber = bq25798_ns.class_("BQ25798IprechgNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_IPRECHG = "iprechg"

BQ25798ItermNumber = bq25798_ns.class_("BQ25798ItermNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_ITERM = "iterm"

BQ25798CellNumber = bq25798_ns.class_("BQ25798CellNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_CELL = "cell"

BQ25798TrechgNumber = bq25798_ns.class_("BQ25798TrechgNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_TRECHG = "trechg"

BQ25798VrechgNumber = bq25798_ns.class_("BQ25798VrechgNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_VRECHG = "vrechg"

BQ25798VotgNumber = bq25798_ns.class_("BQ25798VotgNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_VOTG = "votg"

BQ25798PrechgTmrNumber = bq25798_ns.class_("BQ25798PrechgTmrNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_PRECHG_TMR = "prechg_tmr"

BQ25798IotgNumber = bq25798_ns.class_("BQ25798IotgNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_IOTG = "iotg"

BQ25798TopoffTmrNumber = bq25798_ns.class_("BQ25798TopoffTmrNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_TOPOFF_TMR = "topoff_tmr"

BQ25798ChgTmrNumber = bq25798_ns.class_("BQ25798ChgTmrNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_CHG_TMR = "chg_tmr"

BQ25798VbusBackupNumber = bq25798_ns.class_("BQ25798VbusBackupNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_VBUS_BACKUP = "vbus_backup"

BQ25798VacOvpNumber = bq25798_ns.class_("BQ25798VacOvpNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_VAC_OVP = "vac_ovp"

BQ25798WatchdogNumber = bq25798_ns.class_("BQ25798WatchdogNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_WATCHDOG = "watchdog"

BQ25798SdrvCtrlNumber = bq25798_ns.class_("BQ25798SdrvCtrlNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_SDRV_CTRL = "sdrv_ctrl"

BQ25798SdrvDlyNumber = bq25798_ns.class_("BQ25798SdrvDlyNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_SDRV_DLY = "sdrv_dly"

BQ25798WkupDlyNumber = bq25798_ns.class_("BQ25798WkupDlyNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_WKUP_DLY = "wkup_dly"

BQ25798PwmFreqNumber = bq25798_ns.class_("BQ25798PwmFreqNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_PWM_FREQ = "pwm_freq"

BQ25798IbatRegNumber = bq25798_ns.class_("BQ25798IbatRegNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_IBAT_REG = "ibat_reg"

BQ25798VocPctNumber = bq25798_ns.class_("BQ25798VocPctNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_VOC_PCT = "voc_pct"

BQ25798VocDlyNumber = bq25798_ns.class_("BQ25798VocDlyNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_VOC_DLY = "voc_dly"

BQ25798VocRateNumber = bq25798_ns.class_("BQ25798VocRateNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_VOC_RATE = "voc_rate"

BQ25798TregNumber = bq25798_ns.class_("BQ25798TregNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_TREG = "treg"

BQ25798TshutNumber = bq25798_ns.class_("BQ25798TshutNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_TSHUT = "tshut"

BQ25798BkupAcfet1OnNumber = bq25798_ns.class_("BQ25798BkupAcfet1OnNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_BKUP_ACFET1_ON = "bkup_acfet1_on"

BQ25798JeitaVsetNumber = bq25798_ns.class_("BQ25798JeitaVsetNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_JEITA_VSET = "jeita_vset"

BQ25798JeitaIsethNumber = bq25798_ns.class_("BQ25798JeitaIsethNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_JEITA_ISETH = "jeita_iseth"

BQ25798JeitaIsetcNumber = bq25798_ns.class_("BQ25798JeitaIsetcNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_JEITA_ISETC = "jeita_isetc"

BQ25798TsCoolNumber = bq25798_ns.class_("BQ25798TsCoolNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_TS_COOL = "ts_cool"

BQ25798TsWarmNumber = bq25798_ns.class_("BQ25798TsWarmNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_TS_WARM = "ts_warm"

BQ25798BhotNumber = bq25798_ns.class_("BQ25798BhotNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_BHOT = "bhot"

BQ25798BcoldNumber = bq25798_ns.class_("BQ25798BcoldNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_BCOLD = "bcold"

BQ25798AdcRateNumber = bq25798_ns.class_("BQ25798AdcRateNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_ADC_RATE = "adc_rate"

BQ25798AdcSampleNumber = bq25798_ns.class_("BQ25798AdcSampleNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_ADC_SAMPLE = "adc_sample"

BQ25798AdcAvgNumber = bq25798_ns.class_("BQ25798AdcAvgNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_ADC_AVG = "adc_avg"

BQ25798DplusDacNumber = bq25798_ns.class_("BQ25798DplusDacNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_DPLUS_DAC = "dplus_dac"

BQ25798DminusDacNumber = bq25798_ns.class_("BQ25798DminusDacNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_DMINUS_DAC = "dminus_dac"

CONFIG_SCHEMA = (
    number.number_schema(BQ25798Component)
    .extend({
            cv.GenerateID(CONF_BQ25798_ID): cv.use_id(BQ25798Component),

            cv.Optional(CONF_BQ25798_VSYSMIN): number.number_schema(
                BQ25798VsysminNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="mV",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VREG): number.number_schema(
                BQ25798VregNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="mV",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_ICHG): number.number_schema(
                BQ25798IchgNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="mA",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VINDPM): number.number_schema(
                BQ25798VindpmNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="mV",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_IINDPM): number.number_schema(
                BQ25798IindpmNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="mA",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VBAT_LOWV): number.number_schema(
                BQ25798VbatLowvNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_IPRECHG): number.number_schema(
                BQ25798IprechgNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="mA",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_ITERM): number.number_schema(
                BQ25798ItermNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="mA",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_CELL): number.number_schema(
                BQ25798CellNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_TRECHG): number.number_schema(
                BQ25798TrechgNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VRECHG): number.number_schema(
                BQ25798VrechgNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="mV",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VOTG): number.number_schema(
                BQ25798VotgNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="mV",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_PRECHG_TMR): number.number_schema(
                BQ25798PrechgTmrNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_IOTG): number.number_schema(
                BQ25798IotgNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="mA",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_TOPOFF_TMR): number.number_schema(
                BQ25798TopoffTmrNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_CHG_TMR): number.number_schema(
                BQ25798ChgTmrNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VBUS_BACKUP): number.number_schema(
                BQ25798VbusBackupNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VAC_OVP): number.number_schema(
                BQ25798VacOvpNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_WATCHDOG): number.number_schema(
                BQ25798WatchdogNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_SDRV_CTRL): number.number_schema(
                BQ25798SdrvCtrlNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_SDRV_DLY): number.number_schema(
                BQ25798SdrvDlyNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_WKUP_DLY): number.number_schema(
                BQ25798WkupDlyNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_PWM_FREQ): number.number_schema(
                BQ25798PwmFreqNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_IBAT_REG): number.number_schema(
                BQ25798IbatRegNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VOC_PCT): number.number_schema(
                BQ25798VocPctNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VOC_DLY): number.number_schema(
                BQ25798VocDlyNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VOC_RATE): number.number_schema(
                BQ25798VocRateNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_TREG): number.number_schema(
                BQ25798TregNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_TSHUT): number.number_schema(
                BQ25798TshutNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_BKUP_ACFET1_ON): number.number_schema(
                BQ25798BkupAcfet1OnNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_JEITA_VSET): number.number_schema(
                BQ25798JeitaVsetNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_JEITA_ISETH): number.number_schema(
                BQ25798JeitaIsethNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_JEITA_ISETC): number.number_schema(
                BQ25798JeitaIsetcNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_TS_COOL): number.number_schema(
                BQ25798TsCoolNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_TS_WARM): number.number_schema(
                BQ25798TsWarmNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_BHOT): number.number_schema(
                BQ25798BhotNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_BCOLD): number.number_schema(
                BQ25798BcoldNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_ADC_RATE): number.number_schema(
                BQ25798AdcRateNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_ADC_SAMPLE): number.number_schema(
                BQ25798AdcSampleNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_ADC_AVG): number.number_schema(
                BQ25798AdcAvgNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_DPLUS_DAC): number.number_schema(
                BQ25798DplusDacNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_DMINUS_DAC): number.number_schema(
                BQ25798DminusDacNumber,
#FIXME                default_restore_mode="DISABLED",    # read the current state from the device
                unit_of_measurement="",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
    })
    .extend(cv.polling_component_schema("10s")) # FIXME?
)

async def to_code(config):
    main_component = await cg.get_variable(config[CONF_BQ25798_ID]) # parent component

    # Numberes
    if vsysmin_config := config.get(CONF_BQ25798_VSYSMIN):
        num = await number.new_number(
            vsysmin_config,
            min_value=2500,
            max_value=16000,
            step=250,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if vreg_config := config.get(CONF_BQ25798_VREG):
        num = await number.new_number(
            vreg_config,
            min_value=3000,
            max_value=18800,
            step=10,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if ichg_config := config.get(CONF_BQ25798_ICHG):
        num = await number.new_number(
            ichg_config,
            min_value=50,
            max_value=5000,
            step=10,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if vindpm_config := config.get(CONF_BQ25798_VINDPM):
        num = await number.new_number(
            vindpm_config,
            min_value=3600,
            max_value=22000,
            step=100,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if iindpm_config := config.get(CONF_BQ25798_IINDPM):
        num = await number.new_number(
            iindpm_config,
            min_value=100,
            max_value=3300,
            step=10,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if vbat_lowv_config := config.get(CONF_BQ25798_VBAT_LOWV):
        num = await number.new_number(
            vbat_lowv_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if iprechg_config := config.get(CONF_BQ25798_IPRECHG):
        num = await number.new_number(
            iprechg_config,
            min_value=40,
            max_value=2000,
            step=40,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])




    if iterm_config := config.get(CONF_BQ25798_ITERM):
        num = await number.new_number(
            iterm_config,
            min_value=40,
            max_value=1000,
            step=40,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if cell_config := config.get(CONF_BQ25798_CELL):
        num = await number.new_number(
            cell_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if trechg_config := config.get(CONF_BQ25798_TRECHG):
        num = await number.new_number(
            trechg_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if vrechg_config := config.get(CONF_BQ25798_VRECHG):
        num = await number.new_number(
            vrechg_config,
            min_value=50,
            max_value=800,
            step=50,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if votg_config := config.get(CONF_BQ25798_VOTG):
        num = await number.new_number(
            votg_config,
            min_value=2800,
            max_value=22000,
            step=10,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if prechg_tmr_config := config.get(CONF_BQ25798_PRECHG_TMR):
        num = await number.new_number(
            prechg_tmr_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if iotg_config := config.get(CONF_BQ25798_IOTG):
        num = await number.new_number(
            iotg_config,
            min_value=160,
            max_value=3360,
            step=40,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if topoff_tmr_config := config.get(CONF_BQ25798_TOPOFF_TMR):
        num = await number.new_number(
            topoff_tmr_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])





    if chg_tmr_config := config.get(CONF_BQ25798_CHG_TMR):
        num = await number.new_number(
            chg_tmr_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])











    if vbus_backup_config := config.get(CONF_BQ25798_VBUS_BACKUP):
        num = await number.new_number(
            vbus_backup_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if vac_ovp_config := config.get(CONF_BQ25798_VAC_OVP):
        num = await number.new_number(
            vac_ovp_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])



    if watchdog_config := config.get(CONF_BQ25798_WATCHDOG):
        num = await number.new_number(
            watchdog_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])







    if sdrv_ctrl_config := config.get(CONF_BQ25798_SDRV_CTRL):
        num = await number.new_number(
            sdrv_ctrl_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if sdrv_dly_config := config.get(CONF_BQ25798_SDRV_DLY):
        num = await number.new_number(
            sdrv_dly_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])






    if wkup_dly_config := config.get(CONF_BQ25798_WKUP_DLY):
        num = await number.new_number(
            wkup_dly_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])







    if pwm_freq_config := config.get(CONF_BQ25798_PWM_FREQ):
        num = await number.new_number(
            pwm_freq_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])









    if ibat_reg_config := config.get(CONF_BQ25798_IBAT_REG):
        num = await number.new_number(
            ibat_reg_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])





    if voc_pct_config := config.get(CONF_BQ25798_VOC_PCT):
        num = await number.new_number(
            voc_pct_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if voc_dly_config := config.get(CONF_BQ25798_VOC_DLY):
        num = await number.new_number(
            voc_dly_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if voc_rate_config := config.get(CONF_BQ25798_VOC_RATE):
        num = await number.new_number(
            voc_rate_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])



    if treg_config := config.get(CONF_BQ25798_TREG):
        num = await number.new_number(
            treg_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if tshut_config := config.get(CONF_BQ25798_TSHUT):
        num = await number.new_number(
            tshut_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])





    if bkup_acfet1_on_config := config.get(CONF_BQ25798_BKUP_ACFET1_ON):
        num = await number.new_number(
            bkup_acfet1_on_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if jeita_vset_config := config.get(CONF_BQ25798_JEITA_VSET):
        num = await number.new_number(
            jeita_vset_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if jeita_iseth_config := config.get(CONF_BQ25798_JEITA_ISETH):
        num = await number.new_number(
            jeita_iseth_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if jeita_isetc_config := config.get(CONF_BQ25798_JEITA_ISETC):
        num = await number.new_number(
            jeita_isetc_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if ts_cool_config := config.get(CONF_BQ25798_TS_COOL):
        num = await number.new_number(
            ts_cool_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if ts_warm_config := config.get(CONF_BQ25798_TS_WARM):
        num = await number.new_number(
            ts_warm_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if bhot_config := config.get(CONF_BQ25798_BHOT):
        num = await number.new_number(
            bhot_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if bcold_config := config.get(CONF_BQ25798_BCOLD):
        num = await number.new_number(
            bcold_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])



















































































    if adc_rate_config := config.get(CONF_BQ25798_ADC_RATE):
        num = await number.new_number(
            adc_rate_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if adc_sample_config := config.get(CONF_BQ25798_ADC_SAMPLE):
        num = await number.new_number(
            adc_sample_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if adc_avg_config := config.get(CONF_BQ25798_ADC_AVG):
        num = await number.new_number(
            adc_avg_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])

























    if dplus_dac_config := config.get(CONF_BQ25798_DPLUS_DAC):
        num = await number.new_number(
            dplus_dac_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])


    if dminus_dac_config := config.get(CONF_BQ25798_DMINUS_DAC):
        num = await number.new_number(
            dminus_dac_config,
            min_value=0,
            max_value=0,
            step=0,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])




