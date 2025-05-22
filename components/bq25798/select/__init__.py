
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import select
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


# Enum settings

BQ25798VbatLowvSelect = bq25798_ns.class_("BQ25798VbatLowvSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_VBAT_LOWV = "vbat_lowv"

BQ25798CellSelect = bq25798_ns.class_("BQ25798CellSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_CELL = "cell"

BQ25798TrechgSelect = bq25798_ns.class_("BQ25798TrechgSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_TRECHG = "trechg"

BQ25798PrechgTmrSelect = bq25798_ns.class_("BQ25798PrechgTmrSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_PRECHG_TMR = "prechg_tmr"

BQ25798TopoffTmrSelect = bq25798_ns.class_("BQ25798TopoffTmrSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_TOPOFF_TMR = "topoff_tmr"

BQ25798ChgTmrSelect = bq25798_ns.class_("BQ25798ChgTmrSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_CHG_TMR = "chg_tmr"

BQ25798VbusBackupSelect = bq25798_ns.class_("BQ25798VbusBackupSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_VBUS_BACKUP = "vbus_backup"

BQ25798VacOvpSelect = bq25798_ns.class_("BQ25798VacOvpSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_VAC_OVP = "vac_ovp"

BQ25798WatchdogSelect = bq25798_ns.class_("BQ25798WatchdogSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_WATCHDOG = "watchdog"

BQ25798SdrvCtrlSelect = bq25798_ns.class_("BQ25798SdrvCtrlSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_SDRV_CTRL = "sdrv_ctrl"

BQ25798SdrvDlySelect = bq25798_ns.class_("BQ25798SdrvDlySelect", select.Select, cg.PollingComponent)
CONF_BQ25798_SDRV_DLY = "sdrv_dly"

BQ25798WkupDlySelect = bq25798_ns.class_("BQ25798WkupDlySelect", select.Select, cg.PollingComponent)
CONF_BQ25798_WKUP_DLY = "wkup_dly"

BQ25798PwmFreqSelect = bq25798_ns.class_("BQ25798PwmFreqSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_PWM_FREQ = "pwm_freq"

BQ25798IbatRegSelect = bq25798_ns.class_("BQ25798IbatRegSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_IBAT_REG = "ibat_reg"

BQ25798VocPctSelect = bq25798_ns.class_("BQ25798VocPctSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_VOC_PCT = "voc_pct"

BQ25798VocDlySelect = bq25798_ns.class_("BQ25798VocDlySelect", select.Select, cg.PollingComponent)
CONF_BQ25798_VOC_DLY = "voc_dly"

BQ25798VocRateSelect = bq25798_ns.class_("BQ25798VocRateSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_VOC_RATE = "voc_rate"

BQ25798TregSelect = bq25798_ns.class_("BQ25798TregSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_TREG = "treg"

BQ25798TshutSelect = bq25798_ns.class_("BQ25798TshutSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_TSHUT = "tshut"

BQ25798BkupAcfet1OnSelect = bq25798_ns.class_("BQ25798BkupAcfet1OnSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_BKUP_ACFET1_ON = "bkup_acfet1_on"

BQ25798JeitaVsetSelect = bq25798_ns.class_("BQ25798JeitaVsetSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_JEITA_VSET = "jeita_vset"

BQ25798JeitaIsethSelect = bq25798_ns.class_("BQ25798JeitaIsethSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_JEITA_ISETH = "jeita_iseth"

BQ25798JeitaIsetcSelect = bq25798_ns.class_("BQ25798JeitaIsetcSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_JEITA_ISETC = "jeita_isetc"

BQ25798TsCoolSelect = bq25798_ns.class_("BQ25798TsCoolSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_TS_COOL = "ts_cool"

BQ25798TsWarmSelect = bq25798_ns.class_("BQ25798TsWarmSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_TS_WARM = "ts_warm"

BQ25798BhotSelect = bq25798_ns.class_("BQ25798BhotSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_BHOT = "bhot"

BQ25798BcoldSelect = bq25798_ns.class_("BQ25798BcoldSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_BCOLD = "bcold"

BQ25798AdcRateSelect = bq25798_ns.class_("BQ25798AdcRateSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_ADC_RATE = "adc_rate"

BQ25798AdcSampleSelect = bq25798_ns.class_("BQ25798AdcSampleSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_ADC_SAMPLE = "adc_sample"

BQ25798AdcAvgSelect = bq25798_ns.class_("BQ25798AdcAvgSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_ADC_AVG = "adc_avg"

BQ25798DplusDacSelect = bq25798_ns.class_("BQ25798DplusDacSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_DPLUS_DAC = "dplus_dac"

BQ25798DminusDacSelect = bq25798_ns.class_("BQ25798DminusDacSelect", select.Select, cg.PollingComponent)
CONF_BQ25798_DMINUS_DAC = "dminus_dac"

CONFIG_SCHEMA = (
    select.select_schema(BQ25798Component)
    .extend({
            cv.GenerateID(CONF_BQ25798_ID): cv.use_id(BQ25798Component),

            cv.Optional(CONF_BQ25798_VBAT_LOWV): select.select_schema(
                BQ25798VbatLowvSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_CELL): select.select_schema(
                BQ25798CellSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_TRECHG): select.select_schema(
                BQ25798TrechgSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_PRECHG_TMR): select.select_schema(
                BQ25798PrechgTmrSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_TOPOFF_TMR): select.select_schema(
                BQ25798TopoffTmrSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_CHG_TMR): select.select_schema(
                BQ25798ChgTmrSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VBUS_BACKUP): select.select_schema(
                BQ25798VbusBackupSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VAC_OVP): select.select_schema(
                BQ25798VacOvpSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_WATCHDOG): select.select_schema(
                BQ25798WatchdogSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_SDRV_CTRL): select.select_schema(
                BQ25798SdrvCtrlSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_SDRV_DLY): select.select_schema(
                BQ25798SdrvDlySelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_WKUP_DLY): select.select_schema(
                BQ25798WkupDlySelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_PWM_FREQ): select.select_schema(
                BQ25798PwmFreqSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_IBAT_REG): select.select_schema(
                BQ25798IbatRegSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VOC_PCT): select.select_schema(
                BQ25798VocPctSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VOC_DLY): select.select_schema(
                BQ25798VocDlySelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VOC_RATE): select.select_schema(
                BQ25798VocRateSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_TREG): select.select_schema(
                BQ25798TregSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_TSHUT): select.select_schema(
                BQ25798TshutSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_BKUP_ACFET1_ON): select.select_schema(
                BQ25798BkupAcfet1OnSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_JEITA_VSET): select.select_schema(
                BQ25798JeitaVsetSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_JEITA_ISETH): select.select_schema(
                BQ25798JeitaIsethSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_JEITA_ISETC): select.select_schema(
                BQ25798JeitaIsetcSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_TS_COOL): select.select_schema(
                BQ25798TsCoolSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_TS_WARM): select.select_schema(
                BQ25798TsWarmSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_BHOT): select.select_schema(
                BQ25798BhotSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_BCOLD): select.select_schema(
                BQ25798BcoldSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_ADC_RATE): select.select_schema(
                BQ25798AdcRateSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_ADC_SAMPLE): select.select_schema(
                BQ25798AdcSampleSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_ADC_AVG): select.select_schema(
                BQ25798AdcAvgSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_DPLUS_DAC): select.select_schema(
                BQ25798DplusDacSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_DMINUS_DAC): select.select_schema(
                BQ25798DminusDacSelect,
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
    })
    .extend(cv.polling_component_schema("5s"))
)

async def to_code(config):
    main_component = await cg.get_variable(config[CONF_BQ25798_ID]) # parent component

    # Selects





    if vbat_lowv_config := config.get(CONF_BQ25798_VBAT_LOWV):
        sel = await select.new_select(
            vbat_lowv_config,
            # step=1,
            options=[
                "VBAT_LOWV_PCT_15",
                "VBAT_LOWV_PCT_62",
                "VBAT_LOWV_PCT_67",
                "VBAT_LOWV_PCT_71",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)






    if cell_config := config.get(CONF_BQ25798_CELL):
        sel = await select.new_select(
            cell_config,
            # step=1,
            options=[
                "CELL_1S",
                "CELL_2S",
                "CELL_3S",
                "CELL_4S",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if trechg_config := config.get(CONF_BQ25798_TRECHG):
        sel = await select.new_select(
            trechg_config,
            # step=1,
            options=[
                "TRECHG_64MS",
                "TRECHG_256MS",
                "TRECHG_1024MS",
                "TRECHG_2048MS",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)




    if prechg_tmr_config := config.get(CONF_BQ25798_PRECHG_TMR):
        sel = await select.new_select(
            prechg_tmr_config,
            # step=1,
            options=[
                "PRECHG_TMR_2HRS",
                "PRECHG_TMR_30MIN",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)



    if topoff_tmr_config := config.get(CONF_BQ25798_TOPOFF_TMR):
        sel = await select.new_select(
            topoff_tmr_config,
            # step=1,
            options=[
                "TOPOFF_TMR_DISABLED",
                "TOPOFF_TMR_15MIN",
                "TOPOFF_TMR_30MIN",
                "TOPOFF_TMR_45MIN",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)





    if chg_tmr_config := config.get(CONF_BQ25798_CHG_TMR):
        sel = await select.new_select(
            chg_tmr_config,
            # step=1,
            options=[
                "CHG_TMR_5HRS",
                "CHG_TMR_8HRS",
                "CHG_TMR_12HRS",
                "CHG_TMR_24HRS",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)











    if vbus_backup_config := config.get(CONF_BQ25798_VBUS_BACKUP):
        sel = await select.new_select(
            vbus_backup_config,
            # step=1,
            options=[
                "PCT_VBUS_BACKUP_40",
                "PCT_VBUS_BACKUP_60",
                "PCT_VBUS_BACKUP_80",
                "PCT_VBUS_BACKUP_100",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if vac_ovp_config := config.get(CONF_BQ25798_VAC_OVP):
        sel = await select.new_select(
            vac_ovp_config,
            # step=1,
            options=[
                "VAC_OVP_26V",
                "VAC_OVP_22V",
                "VAC_OVP_12V",
                "VAC_OVP_7V",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)



    if watchdog_config := config.get(CONF_BQ25798_WATCHDOG):
        sel = await select.new_select(
            watchdog_config,
            # step=1,
            options=[
                "WATCHDOG_DISABLE",
                "WATCHDOG_05S",
                "WATCHDOG_1S",
                "WATCHDOG_2S",
                "WATCHDOG_20S",
                "WATCHDOG_40S",
                "WATCHDOG_80S",
                "WATCHDOG_160S",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)







    if sdrv_ctrl_config := config.get(CONF_BQ25798_SDRV_CTRL):
        sel = await select.new_select(
            sdrv_ctrl_config,
            # step=1,
            options=[
                "SDRV_CTRL_IDLE",
                "SDRV_CTRL_SHUTDOWN",
                "SDRV_CTRL_SHIP",
                "SDRV_CTRL_SYS_PWR_RST",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if sdrv_dly_config := config.get(CONF_BQ25798_SDRV_DLY):
        sel = await select.new_select(
            sdrv_dly_config,
            # step=1,
            options=[
                "SDRV_DLY_10S",
                "SDRV_DLY_0S",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)






    if wkup_dly_config := config.get(CONF_BQ25798_WKUP_DLY):
        sel = await select.new_select(
            wkup_dly_config,
            # step=1,
            options=[
                "WKUP_DLY_1S",
                "WKUP_DLY_15MS",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)







    if pwm_freq_config := config.get(CONF_BQ25798_PWM_FREQ):
        sel = await select.new_select(
            pwm_freq_config,
            # step=1,
            options=[
                "PWM_FREQ_1_5MHZ",
                "PWM_FREQ_750KHZ",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)









    if ibat_reg_config := config.get(CONF_BQ25798_IBAT_REG):
        sel = await select.new_select(
            ibat_reg_config,
            # step=1,
            options=[
                "IBAT_REG_3A",
                "IBAT_REG_4A",
                "IBAT_REG_5A",
                "IBAT_REG_DISABLE",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)





    if voc_pct_config := config.get(CONF_BQ25798_VOC_PCT):
        sel = await select.new_select(
            voc_pct_config,
            # step=1,
            options=[
                "VOC_PCT_0_5625",
                "VOC_PCT_0_625",
                "VOC_PCT_0_6875",
                "VOC_PCT_0_75",
                "VOC_PCT_0_8125",
                "VOC_PCT_0_875",
                "VOC_PCT_0_9375",
                "VOC_PCT_1",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if voc_dly_config := config.get(CONF_BQ25798_VOC_DLY):
        sel = await select.new_select(
            voc_dly_config,
            # step=1,
            options=[
                "VOC_DLY_50MS",
                "VOC_DLY_300MS",
                "VOC_DLY_2S",
                "VOC_DLY_5S",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if voc_rate_config := config.get(CONF_BQ25798_VOC_RATE):
        sel = await select.new_select(
            voc_rate_config,
            # step=1,
            options=[
                "VOC_RATE_30S",
                "VOC_RATE_2MIN",
                "VOC_RATE_10MIN",
                "VOC_RATE_30MIN",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)



    if treg_config := config.get(CONF_BQ25798_TREG):
        sel = await select.new_select(
            treg_config,
            # step=1,
            options=[
                "TREG_60",
                "TREG_80",
                "TREG_100",
                "TREG_120",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if tshut_config := config.get(CONF_BQ25798_TSHUT):
        sel = await select.new_select(
            tshut_config,
            # step=1,
            options=[
                "TSHUT_150",
                "TSHUT_130",
                "TSHUT_120",
                "TSHUT_85",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)





    if bkup_acfet1_on_config := config.get(CONF_BQ25798_BKUP_ACFET1_ON):
        sel = await select.new_select(
            bkup_acfet1_on_config,
            # step=1,
            options=[
                "BKUP_ACFET1_ON_IDLE",
                "BKUP_ACFET1_ON_TURN_ON",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if jeita_vset_config := config.get(CONF_BQ25798_JEITA_VSET):
        sel = await select.new_select(
            jeita_vset_config,
            # step=1,
            options=[
                "JEITA_VSET_CHARGE_SUSPEND",
                "JEITA_VSET_SET_VREG_TO_VREG_800MV",
                "JEITA_VSET_SET_VREG_TO_VREG_600MV",
                "JEITA_VSET_SET_VREG_TO_VREG_400MV",
                "JEITA_VSET_SET_VREG_TO_VREG_300MV",
                "JEITA_VSET_SET_VREG_TO_VREG_200MV",
                "JEITA_VSET_SET_VREG_TO_VREG_100MV",
                "JEITA_VSET_VREG_UNCHANGED",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if jeita_iseth_config := config.get(CONF_BQ25798_JEITA_ISETH):
        sel = await select.new_select(
            jeita_iseth_config,
            # step=1,
            options=[
                "JEITA_ISETH_CHARGE_SUSPEND",
                "JEITA_ISETH_SET_ICHG_TO_20",
                "JEITA_ISETH_SET_ICHG_TO_40",
                "JEITA_ISETH_ICHG_UNCHANGED",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if jeita_isetc_config := config.get(CONF_BQ25798_JEITA_ISETC):
        sel = await select.new_select(
            jeita_isetc_config,
            # step=1,
            options=[
                "JEITA_ISETC_CHARGE_SUSPEND",
                "JEITA_ISETC_SET_ICHG_TO_20",
                "JEITA_ISETC_SET_ICHG_TO_40",
                "JEITA_ISETC_ICHG_UNCHANGED",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if ts_cool_config := config.get(CONF_BQ25798_TS_COOL):
        sel = await select.new_select(
            ts_cool_config,
            # step=1,
            options=[
                "TS_COOL_5",
                "TS_COOL_10",
                "TS_COOL_15",
                "TS_COOL_20",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if ts_warm_config := config.get(CONF_BQ25798_TS_WARM):
        sel = await select.new_select(
            ts_warm_config,
            # step=1,
            options=[
                "TS_WARM_40",
                "TS_WARM_45",
                "TS_WARM_50",
                "TS_WARM_55",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if bhot_config := config.get(CONF_BQ25798_BHOT):
        sel = await select.new_select(
            bhot_config,
            # step=1,
            options=[
                "TS_BHOT_55",
                "TS_BHOT_60",
                "TS_BHOT_65",
                "TS_BHOT_DISABLE",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if bcold_config := config.get(CONF_BQ25798_BCOLD):
        sel = await select.new_select(
            bcold_config,
            # step=1,
            options=[
                "TS_BCOLD_MINUS_10",
                "TS_BCOLD_MINUS_20",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)



















































































    if adc_rate_config := config.get(CONF_BQ25798_ADC_RATE):
        sel = await select.new_select(
            adc_rate_config,
            # step=1,
            options=[
                "ADC_RATE_CONTINUOUS",
                "ADC_RATE_ONESHOT",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if adc_sample_config := config.get(CONF_BQ25798_ADC_SAMPLE):
        sel = await select.new_select(
            adc_sample_config,
            # step=1,
            options=[
                "ADC_SAMPLE_15BIT",
                "ADC_SAMPLE_14BIT",
                "ADC_SAMPLE_13BIT",
                "ADC_SAMPLE_12BIT",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if adc_avg_config := config.get(CONF_BQ25798_ADC_AVG):
        sel = await select.new_select(
            adc_avg_config,
            # step=1,
            options=[
                "ADC_AVG_NO_AVERAGING",
                "ADC_AVG_RUNNING_AVERAGE",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)

























    if dplus_dac_config := config.get(CONF_BQ25798_DPLUS_DAC):
        sel = await select.new_select(
            dplus_dac_config,
            # step=1,
            options=[
                "DPLUS_DAC_HIZ",
                "DPLUS_DAC_VOUT_0",
                "DPLUS_DAC_VOUT_0_6",
                "DPLUS_DAC_VOUT_1_2",
                "DPLUS_DAC_VOUT_2_0",
                "DPLUS_DAC_VOUT_2_7",
                "DPLUS_DAC_VOUT_3_3",
                "DPLUS_DAC_DPLUS_DMINUS_SHORT",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)


    if dminus_dac_config := config.get(CONF_BQ25798_DMINUS_DAC):
        sel = await select.new_select(
            dminus_dac_config,
            # step=1,
            options=[
                "DMINUS_DAC_HIZ",
                "DMINUS_DAC_VOUT_0",
                "DMINUS_DAC_VOUT_0_6",
                "DMINUS_DAC_VOUT_1_2",
                "DMINUS_DAC_VOUT_2_0",
                "DMINUS_DAC_VOUT_2_7",
                "DMINUS_DAC_VOUT_3_3",
                "DMINUS_DAC_RESERVED",
            ]
        )
        await cg.register_parented(sel, config[CONF_BQ25798_ID])
        await cg.register_component(sel, config)




