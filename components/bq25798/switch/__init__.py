import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import switch
from esphome.const import (
    CONF_ID,
)

from .. import (
    CONF_BQ25798_ID,
    bq25798_ns,
    BQ25798Component
)

DEPENDENCIES = ["bq25798"]


# Boolean settings

BQ25798RegRstSwitch = bq25798_ns.class_("BQ25798RegRstSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_REG_RST = "reg_rst"

BQ25798StopWdChgSwitch = bq25798_ns.class_("BQ25798StopWdChgSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_STOP_WD_CHG = "stop_wd_chg"

BQ25798EnTrichgTmrSwitch = bq25798_ns.class_("BQ25798EnTrichgTmrSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_TRICHG_TMR = "en_trichg_tmr"

BQ25798EnPrechgTmrSwitch = bq25798_ns.class_("BQ25798EnPrechgTmrSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_PRECHG_TMR = "en_prechg_tmr"

BQ25798EnChgTmrSwitch = bq25798_ns.class_("BQ25798EnChgTmrSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_CHG_TMR = "en_chg_tmr"

BQ25798Tmr2xEnSwitch = bq25798_ns.class_("BQ25798Tmr2xEnSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_TMR2X_EN = "tmr2x_en"

BQ25798EnAutoIbatdisSwitch = bq25798_ns.class_("BQ25798EnAutoIbatdisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_AUTO_IBATDIS = "en_auto_ibatdis"

BQ25798ForceIbatdisSwitch = bq25798_ns.class_("BQ25798ForceIbatdisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_FORCE_IBATDIS = "force_ibatdis"

BQ25798EnChgSwitch = bq25798_ns.class_("BQ25798EnChgSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_CHG = "en_chg"

BQ25798EnIcoSwitch = bq25798_ns.class_("BQ25798EnIcoSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_ICO = "en_ico"

BQ25798ForceIcoSwitch = bq25798_ns.class_("BQ25798ForceIcoSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_FORCE_ICO = "force_ico"

BQ25798EnHizSwitch = bq25798_ns.class_("BQ25798EnHizSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_HIZ = "en_hiz"

BQ25798EnTermSwitch = bq25798_ns.class_("BQ25798EnTermSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_TERM = "en_term"

BQ25798EnBackupSwitch = bq25798_ns.class_("BQ25798EnBackupSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_BACKUP = "en_backup"

BQ25798WdRstSwitch = bq25798_ns.class_("BQ25798WdRstSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_WD_RST = "wd_rst"

BQ25798ForceIndetSwitch = bq25798_ns.class_("BQ25798ForceIndetSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_FORCE_INDET = "force_indet"

BQ25798AutoIndetEnSwitch = bq25798_ns.class_("BQ25798AutoIndetEnSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_AUTO_INDET_EN = "auto_indet_en"

BQ25798En12vSwitch = bq25798_ns.class_("BQ25798En12vSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_12V = "en_12v"

BQ25798En9vSwitch = bq25798_ns.class_("BQ25798En9vSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_9V = "en_9v"

BQ25798HvdcpEnSwitch = bq25798_ns.class_("BQ25798HvdcpEnSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_HVDCP_EN = "hvdcp_en"

BQ25798DisAcdrvSwitch = bq25798_ns.class_("BQ25798DisAcdrvSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_DIS_ACDRV = "dis_acdrv"

BQ25798EnOtgSwitch = bq25798_ns.class_("BQ25798EnOtgSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_OTG = "en_otg"

BQ25798PfmOtgDisSwitch = bq25798_ns.class_("BQ25798PfmOtgDisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_PFM_OTG_DIS = "pfm_otg_dis"

BQ25798PfmFwdDisSwitch = bq25798_ns.class_("BQ25798PfmFwdDisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_PFM_FWD_DIS = "pfm_fwd_dis"

BQ25798DisLdoSwitch = bq25798_ns.class_("BQ25798DisLdoSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_DIS_LDO = "dis_ldo"

BQ25798DisOtgOoaSwitch = bq25798_ns.class_("BQ25798DisOtgOoaSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_DIS_OTG_OOA = "dis_otg_ooa"

BQ25798DisFwdOoaSwitch = bq25798_ns.class_("BQ25798DisFwdOoaSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_DIS_FWD_OOA = "dis_fwd_ooa"

BQ25798EnAcdrv2Switch = bq25798_ns.class_("BQ25798EnAcdrv2Switch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_ACDRV2 = "en_acdrv2"

BQ25798EnAcdrv1Switch = bq25798_ns.class_("BQ25798EnAcdrv1Switch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_ACDRV1 = "en_acdrv1"

BQ25798DisStatSwitch = bq25798_ns.class_("BQ25798DisStatSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_DIS_STAT = "dis_stat"

BQ25798DisVsysShortSwitch = bq25798_ns.class_("BQ25798DisVsysShortSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_DIS_VSYS_SHORT = "dis_vsys_short"

BQ25798DisVotgUvpSwitch = bq25798_ns.class_("BQ25798DisVotgUvpSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_DIS_VOTG_UVP = "dis_votg_uvp"

BQ25798ForceVindpmDetSwitch = bq25798_ns.class_("BQ25798ForceVindpmDetSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_FORCE_VINDPM_DET = "force_vindpm_det"

BQ25798EnIbusOcpSwitch = bq25798_ns.class_("BQ25798EnIbusOcpSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_IBUS_OCP = "en_ibus_ocp"

BQ25798SfetPresentSwitch = bq25798_ns.class_("BQ25798SfetPresentSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_SFET_PRESENT = "sfet_present"

BQ25798EnIbatSwitch = bq25798_ns.class_("BQ25798EnIbatSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_IBAT = "en_ibat"

BQ25798EnIindpmSwitch = bq25798_ns.class_("BQ25798EnIindpmSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_IINDPM = "en_iindpm"

BQ25798EnExtilimSwitch = bq25798_ns.class_("BQ25798EnExtilimSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_EXTILIM = "en_extilim"

BQ25798EnBatocSwitch = bq25798_ns.class_("BQ25798EnBatocSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_BATOC = "en_batoc"

BQ25798EnMpptSwitch = bq25798_ns.class_("BQ25798EnMpptSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_EN_MPPT = "en_mppt"

BQ25798VbusPdEnSwitch = bq25798_ns.class_("BQ25798VbusPdEnSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_VBUS_PD_EN = "vbus_pd_en"

BQ25798Vac1PdEnSwitch = bq25798_ns.class_("BQ25798Vac1PdEnSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_VAC1_PD_EN = "vac1_pd_en"

BQ25798Vac2PdEnSwitch = bq25798_ns.class_("BQ25798Vac2PdEnSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_VAC2_PD_EN = "vac2_pd_en"

BQ25798TsIgnoreSwitch = bq25798_ns.class_("BQ25798TsIgnoreSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_TS_IGNORE = "ts_ignore"

BQ25798AdcEnSwitch = bq25798_ns.class_("BQ25798AdcEnSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_ADC_EN = "adc_en"

BQ25798AdcAvgInitSwitch = bq25798_ns.class_("BQ25798AdcAvgInitSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_ADC_AVG_INIT = "adc_avg_init"

BQ25798IbusAdcDisSwitch = bq25798_ns.class_("BQ25798IbusAdcDisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_IBUS_ADC_DIS = "ibus_adc_dis"

BQ25798IbatAdcDisSwitch = bq25798_ns.class_("BQ25798IbatAdcDisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_IBAT_ADC_DIS = "ibat_adc_dis"

BQ25798VbusAdcDisSwitch = bq25798_ns.class_("BQ25798VbusAdcDisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_VBUS_ADC_DIS = "vbus_adc_dis"

BQ25798VbatAdcDisSwitch = bq25798_ns.class_("BQ25798VbatAdcDisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_VBAT_ADC_DIS = "vbat_adc_dis"

BQ25798VsysAdcDisSwitch = bq25798_ns.class_("BQ25798VsysAdcDisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_VSYS_ADC_DIS = "vsys_adc_dis"

BQ25798TsAdcDisSwitch = bq25798_ns.class_("BQ25798TsAdcDisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_TS_ADC_DIS = "ts_adc_dis"

BQ25798TdieAdcDisSwitch = bq25798_ns.class_("BQ25798TdieAdcDisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_TDIE_ADC_DIS = "tdie_adc_dis"

BQ25798DplusAdcDisSwitch = bq25798_ns.class_("BQ25798DplusAdcDisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_DPLUS_ADC_DIS = "dplus_adc_dis"

BQ25798DminusAdcDisSwitch = bq25798_ns.class_("BQ25798DminusAdcDisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_DMINUS_ADC_DIS = "dminus_adc_dis"

BQ25798Vac2AdcDisSwitch = bq25798_ns.class_("BQ25798Vac2AdcDisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_VAC2_ADC_DIS = "vac2_adc_dis"

BQ25798Vac1AdcDisSwitch = bq25798_ns.class_("BQ25798Vac1AdcDisSwitch", switch.Switch, cg.PollingComponent)
CONF_BQ25798_VAC1_ADC_DIS = "vac1_adc_dis"

CONFIG_SCHEMA = (
    switch.switch_schema(BQ25798Component)
    .extend({
            cv.GenerateID(CONF_BQ25798_ID): cv.use_id(BQ25798Component),

            cv.Optional(CONF_BQ25798_REG_RST): switch.switch_schema(
                BQ25798RegRstSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_STOP_WD_CHG): switch.switch_schema(
                BQ25798StopWdChgSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_TRICHG_TMR): switch.switch_schema(
                BQ25798EnTrichgTmrSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_PRECHG_TMR): switch.switch_schema(
                BQ25798EnPrechgTmrSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_CHG_TMR): switch.switch_schema(
                BQ25798EnChgTmrSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_TMR2X_EN): switch.switch_schema(
                BQ25798Tmr2xEnSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_AUTO_IBATDIS): switch.switch_schema(
                BQ25798EnAutoIbatdisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_FORCE_IBATDIS): switch.switch_schema(
                BQ25798ForceIbatdisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_CHG): switch.switch_schema(
                BQ25798EnChgSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_ICO): switch.switch_schema(
                BQ25798EnIcoSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_FORCE_ICO): switch.switch_schema(
                BQ25798ForceIcoSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_HIZ): switch.switch_schema(
                BQ25798EnHizSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_TERM): switch.switch_schema(
                BQ25798EnTermSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_BACKUP): switch.switch_schema(
                BQ25798EnBackupSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_WD_RST): switch.switch_schema(
                BQ25798WdRstSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_FORCE_INDET): switch.switch_schema(
                BQ25798ForceIndetSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_AUTO_INDET_EN): switch.switch_schema(
                BQ25798AutoIndetEnSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_12V): switch.switch_schema(
                BQ25798En12vSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_9V): switch.switch_schema(
                BQ25798En9vSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_HVDCP_EN): switch.switch_schema(
                BQ25798HvdcpEnSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_DIS_ACDRV): switch.switch_schema(
                BQ25798DisAcdrvSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_OTG): switch.switch_schema(
                BQ25798EnOtgSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_PFM_OTG_DIS): switch.switch_schema(
                BQ25798PfmOtgDisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_PFM_FWD_DIS): switch.switch_schema(
                BQ25798PfmFwdDisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_DIS_LDO): switch.switch_schema(
                BQ25798DisLdoSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_DIS_OTG_OOA): switch.switch_schema(
                BQ25798DisOtgOoaSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_DIS_FWD_OOA): switch.switch_schema(
                BQ25798DisFwdOoaSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_ACDRV2): switch.switch_schema(
                BQ25798EnAcdrv2Switch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_ACDRV1): switch.switch_schema(
                BQ25798EnAcdrv1Switch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_DIS_STAT): switch.switch_schema(
                BQ25798DisStatSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_DIS_VSYS_SHORT): switch.switch_schema(
                BQ25798DisVsysShortSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_DIS_VOTG_UVP): switch.switch_schema(
                BQ25798DisVotgUvpSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_FORCE_VINDPM_DET): switch.switch_schema(
                BQ25798ForceVindpmDetSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_IBUS_OCP): switch.switch_schema(
                BQ25798EnIbusOcpSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_SFET_PRESENT): switch.switch_schema(
                BQ25798SfetPresentSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_IBAT): switch.switch_schema(
                BQ25798EnIbatSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_IINDPM): switch.switch_schema(
                BQ25798EnIindpmSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_EXTILIM): switch.switch_schema(
                BQ25798EnExtilimSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_BATOC): switch.switch_schema(
                BQ25798EnBatocSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_EN_MPPT): switch.switch_schema(
                BQ25798EnMpptSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_VBUS_PD_EN): switch.switch_schema(
                BQ25798VbusPdEnSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_VAC1_PD_EN): switch.switch_schema(
                BQ25798Vac1PdEnSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_VAC2_PD_EN): switch.switch_schema(
                BQ25798Vac2PdEnSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_TS_IGNORE): switch.switch_schema(
                BQ25798TsIgnoreSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_ADC_EN): switch.switch_schema(
                BQ25798AdcEnSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_ADC_AVG_INIT): switch.switch_schema(
                BQ25798AdcAvgInitSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_IBUS_ADC_DIS): switch.switch_schema(
                BQ25798IbusAdcDisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_IBAT_ADC_DIS): switch.switch_schema(
                BQ25798IbatAdcDisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_VBUS_ADC_DIS): switch.switch_schema(
                BQ25798VbusAdcDisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_VBAT_ADC_DIS): switch.switch_schema(
                BQ25798VbatAdcDisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_VSYS_ADC_DIS): switch.switch_schema(
                BQ25798VsysAdcDisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_TS_ADC_DIS): switch.switch_schema(
                BQ25798TsAdcDisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_TDIE_ADC_DIS): switch.switch_schema(
                BQ25798TdieAdcDisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_DPLUS_ADC_DIS): switch.switch_schema(
                BQ25798DplusAdcDisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_DMINUS_ADC_DIS): switch.switch_schema(
                BQ25798DminusAdcDisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_VAC2_ADC_DIS): switch.switch_schema(
                BQ25798Vac2AdcDisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
            cv.Optional(CONF_BQ25798_VAC1_ADC_DIS): switch.switch_schema(
                BQ25798Vac1AdcDisSwitch,
                default_restore_mode="DISABLED",    # read the current state from the device
            ),
    })
    .extend(cv.polling_component_schema("5s"))
)

async def to_code(config):
    main_component = await cg.get_variable(config[CONF_BQ25798_ID]) # parent component

    # Switches







    if reg_rst_config := config.get(CONF_BQ25798_REG_RST):
        sw = await switch.new_switch(reg_rst_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if stop_wd_chg_config := config.get(CONF_BQ25798_STOP_WD_CHG):
        sw = await switch.new_switch(stop_wd_chg_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)










    if en_trichg_tmr_config := config.get(CONF_BQ25798_EN_TRICHG_TMR):
        sw = await switch.new_switch(en_trichg_tmr_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_prechg_tmr_config := config.get(CONF_BQ25798_EN_PRECHG_TMR):
        sw = await switch.new_switch(en_prechg_tmr_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_chg_tmr_config := config.get(CONF_BQ25798_EN_CHG_TMR):
        sw = await switch.new_switch(en_chg_tmr_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)



    if tmr2x_en_config := config.get(CONF_BQ25798_TMR2X_EN):
        sw = await switch.new_switch(tmr2x_en_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_auto_ibatdis_config := config.get(CONF_BQ25798_EN_AUTO_IBATDIS):
        sw = await switch.new_switch(en_auto_ibatdis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if force_ibatdis_config := config.get(CONF_BQ25798_FORCE_IBATDIS):
        sw = await switch.new_switch(force_ibatdis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_chg_config := config.get(CONF_BQ25798_EN_CHG):
        sw = await switch.new_switch(en_chg_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_ico_config := config.get(CONF_BQ25798_EN_ICO):
        sw = await switch.new_switch(en_ico_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if force_ico_config := config.get(CONF_BQ25798_FORCE_ICO):
        sw = await switch.new_switch(force_ico_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_hiz_config := config.get(CONF_BQ25798_EN_HIZ):
        sw = await switch.new_switch(en_hiz_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_term_config := config.get(CONF_BQ25798_EN_TERM):
        sw = await switch.new_switch(en_term_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_backup_config := config.get(CONF_BQ25798_EN_BACKUP):
        sw = await switch.new_switch(en_backup_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)




    if wd_rst_config := config.get(CONF_BQ25798_WD_RST):
        sw = await switch.new_switch(wd_rst_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)



    if force_indet_config := config.get(CONF_BQ25798_FORCE_INDET):
        sw = await switch.new_switch(force_indet_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if auto_indet_en_config := config.get(CONF_BQ25798_AUTO_INDET_EN):
        sw = await switch.new_switch(auto_indet_en_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_12v_config := config.get(CONF_BQ25798_EN_12V):
        sw = await switch.new_switch(en_12v_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_9v_config := config.get(CONF_BQ25798_EN_9V):
        sw = await switch.new_switch(en_9v_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if hvdcp_en_config := config.get(CONF_BQ25798_HVDCP_EN):
        sw = await switch.new_switch(hvdcp_en_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)




    if dis_acdrv_config := config.get(CONF_BQ25798_DIS_ACDRV):
        sw = await switch.new_switch(dis_acdrv_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_otg_config := config.get(CONF_BQ25798_EN_OTG):
        sw = await switch.new_switch(en_otg_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if pfm_otg_dis_config := config.get(CONF_BQ25798_PFM_OTG_DIS):
        sw = await switch.new_switch(pfm_otg_dis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if pfm_fwd_dis_config := config.get(CONF_BQ25798_PFM_FWD_DIS):
        sw = await switch.new_switch(pfm_fwd_dis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)



    if dis_ldo_config := config.get(CONF_BQ25798_DIS_LDO):
        sw = await switch.new_switch(dis_ldo_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if dis_otg_ooa_config := config.get(CONF_BQ25798_DIS_OTG_OOA):
        sw = await switch.new_switch(dis_otg_ooa_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if dis_fwd_ooa_config := config.get(CONF_BQ25798_DIS_FWD_OOA):
        sw = await switch.new_switch(dis_fwd_ooa_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_acdrv2_config := config.get(CONF_BQ25798_EN_ACDRV2):
        sw = await switch.new_switch(en_acdrv2_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_acdrv1_config := config.get(CONF_BQ25798_EN_ACDRV1):
        sw = await switch.new_switch(en_acdrv1_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)



    if dis_stat_config := config.get(CONF_BQ25798_DIS_STAT):
        sw = await switch.new_switch(dis_stat_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if dis_vsys_short_config := config.get(CONF_BQ25798_DIS_VSYS_SHORT):
        sw = await switch.new_switch(dis_vsys_short_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if dis_votg_uvp_config := config.get(CONF_BQ25798_DIS_VOTG_UVP):
        sw = await switch.new_switch(dis_votg_uvp_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if force_vindpm_det_config := config.get(CONF_BQ25798_FORCE_VINDPM_DET):
        sw = await switch.new_switch(force_vindpm_det_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_ibus_ocp_config := config.get(CONF_BQ25798_EN_IBUS_OCP):
        sw = await switch.new_switch(en_ibus_ocp_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if sfet_present_config := config.get(CONF_BQ25798_SFET_PRESENT):
        sw = await switch.new_switch(sfet_present_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_ibat_config := config.get(CONF_BQ25798_EN_IBAT):
        sw = await switch.new_switch(en_ibat_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)



    if en_iindpm_config := config.get(CONF_BQ25798_EN_IINDPM):
        sw = await switch.new_switch(en_iindpm_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_extilim_config := config.get(CONF_BQ25798_EN_EXTILIM):
        sw = await switch.new_switch(en_extilim_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if en_batoc_config := config.get(CONF_BQ25798_EN_BATOC):
        sw = await switch.new_switch(en_batoc_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)





    if en_mppt_config := config.get(CONF_BQ25798_EN_MPPT):
        sw = await switch.new_switch(en_mppt_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)




    if vbus_pd_en_config := config.get(CONF_BQ25798_VBUS_PD_EN):
        sw = await switch.new_switch(vbus_pd_en_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if vac1_pd_en_config := config.get(CONF_BQ25798_VAC1_PD_EN):
        sw = await switch.new_switch(vac1_pd_en_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if vac2_pd_en_config := config.get(CONF_BQ25798_VAC2_PD_EN):
        sw = await switch.new_switch(vac2_pd_en_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)










    if ts_ignore_config := config.get(CONF_BQ25798_TS_IGNORE):
        sw = await switch.new_switch(ts_ignore_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)

















































































    if adc_en_config := config.get(CONF_BQ25798_ADC_EN):
        sw = await switch.new_switch(adc_en_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)





    if adc_avg_init_config := config.get(CONF_BQ25798_ADC_AVG_INIT):
        sw = await switch.new_switch(adc_avg_init_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if ibus_adc_dis_config := config.get(CONF_BQ25798_IBUS_ADC_DIS):
        sw = await switch.new_switch(ibus_adc_dis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if ibat_adc_dis_config := config.get(CONF_BQ25798_IBAT_ADC_DIS):
        sw = await switch.new_switch(ibat_adc_dis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if vbus_adc_dis_config := config.get(CONF_BQ25798_VBUS_ADC_DIS):
        sw = await switch.new_switch(vbus_adc_dis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if vbat_adc_dis_config := config.get(CONF_BQ25798_VBAT_ADC_DIS):
        sw = await switch.new_switch(vbat_adc_dis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if vsys_adc_dis_config := config.get(CONF_BQ25798_VSYS_ADC_DIS):
        sw = await switch.new_switch(vsys_adc_dis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if ts_adc_dis_config := config.get(CONF_BQ25798_TS_ADC_DIS):
        sw = await switch.new_switch(ts_adc_dis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if tdie_adc_dis_config := config.get(CONF_BQ25798_TDIE_ADC_DIS):
        sw = await switch.new_switch(tdie_adc_dis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if dplus_adc_dis_config := config.get(CONF_BQ25798_DPLUS_ADC_DIS):
        sw = await switch.new_switch(dplus_adc_dis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if dminus_adc_dis_config := config.get(CONF_BQ25798_DMINUS_ADC_DIS):
        sw = await switch.new_switch(dminus_adc_dis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if vac2_adc_dis_config := config.get(CONF_BQ25798_VAC2_ADC_DIS):
        sw = await switch.new_switch(vac2_adc_dis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)


    if vac1_adc_dis_config := config.get(CONF_BQ25798_VAC1_ADC_DIS):
        sw = await switch.new_switch(vac1_adc_dis_config)
        await cg.register_parented(sw, config[CONF_BQ25798_ID])
        await cg.register_component(sw, config)

















