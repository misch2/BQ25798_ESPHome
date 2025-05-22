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

BQ25798IprechgNumber = bq25798_ns.class_("BQ25798IprechgNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_IPRECHG = "iprechg"

BQ25798ItermNumber = bq25798_ns.class_("BQ25798ItermNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_ITERM = "iterm"

BQ25798VrechgNumber = bq25798_ns.class_("BQ25798VrechgNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_VRECHG = "vrechg"

BQ25798VotgNumber = bq25798_ns.class_("BQ25798VotgNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_VOTG = "votg"

BQ25798IotgNumber = bq25798_ns.class_("BQ25798IotgNumber", number.Number, cg.PollingComponent)
CONF_BQ25798_IOTG = "iotg"

CONFIG_SCHEMA = (
    number.number_schema(BQ25798Component)
    .extend({
            cv.GenerateID(CONF_BQ25798_ID): cv.use_id(BQ25798Component),

            cv.Optional(CONF_BQ25798_VSYSMIN): number.number_schema(
                BQ25798VsysminNumber,
                unit_of_measurement="mV",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VREG): number.number_schema(
                BQ25798VregNumber,
                unit_of_measurement="mV",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_ICHG): number.number_schema(
                BQ25798IchgNumber,
                unit_of_measurement="mA",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VINDPM): number.number_schema(
                BQ25798VindpmNumber,
                unit_of_measurement="mV",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_IINDPM): number.number_schema(
                BQ25798IindpmNumber,
                unit_of_measurement="mA",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_IPRECHG): number.number_schema(
                BQ25798IprechgNumber,
                unit_of_measurement="mA",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_ITERM): number.number_schema(
                BQ25798ItermNumber,
                unit_of_measurement="mA",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VRECHG): number.number_schema(
                BQ25798VrechgNumber,
                unit_of_measurement="mV",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_VOTG): number.number_schema(
                BQ25798VotgNumber,
                unit_of_measurement="mV",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
            cv.Optional(CONF_BQ25798_IOTG): number.number_schema(
                BQ25798IotgNumber,
                unit_of_measurement="mA",
                entity_category=ENTITY_CATEGORY_CONFIG,
            ),
    })
    .extend(cv.polling_component_schema("5s"))
)

async def to_code(config):
    main_component = await cg.get_variable(config[CONF_BQ25798_ID]) # parent component

    # Numbers
    if vsysmin_config := config.get(CONF_BQ25798_VSYSMIN):
        num = await number.new_number(
            vsysmin_config,
            min_value=2500,
            max_value=16000,
            step=250,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])
        await cg.register_component(num, config)


    if vreg_config := config.get(CONF_BQ25798_VREG):
        num = await number.new_number(
            vreg_config,
            min_value=3000,
            max_value=18800,
            step=10,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])
        await cg.register_component(num, config)


    if ichg_config := config.get(CONF_BQ25798_ICHG):
        num = await number.new_number(
            ichg_config,
            min_value=50,
            max_value=5000,
            step=10,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])
        await cg.register_component(num, config)


    if vindpm_config := config.get(CONF_BQ25798_VINDPM):
        num = await number.new_number(
            vindpm_config,
            min_value=3600,
            max_value=22000,
            step=100,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])
        await cg.register_component(num, config)


    if iindpm_config := config.get(CONF_BQ25798_IINDPM):
        num = await number.new_number(
            iindpm_config,
            min_value=100,
            max_value=3300,
            step=10,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])
        await cg.register_component(num, config)



    if iprechg_config := config.get(CONF_BQ25798_IPRECHG):
        num = await number.new_number(
            iprechg_config,
            min_value=40,
            max_value=2000,
            step=40,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])
        await cg.register_component(num, config)




    if iterm_config := config.get(CONF_BQ25798_ITERM):
        num = await number.new_number(
            iterm_config,
            min_value=40,
            max_value=1000,
            step=40,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])
        await cg.register_component(num, config)




    if vrechg_config := config.get(CONF_BQ25798_VRECHG):
        num = await number.new_number(
            vrechg_config,
            min_value=50,
            max_value=800,
            step=50,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])
        await cg.register_component(num, config)


    if votg_config := config.get(CONF_BQ25798_VOTG):
        num = await number.new_number(
            votg_config,
            min_value=2800,
            max_value=22000,
            step=10,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])
        await cg.register_component(num, config)



    if iotg_config := config.get(CONF_BQ25798_IOTG):
        num = await number.new_number(
            iotg_config,
            min_value=160,
            max_value=3360,
            step=40,
        )
        await cg.register_parented(num, config[CONF_BQ25798_ID])
        await cg.register_component(num, config)

















































































































































































