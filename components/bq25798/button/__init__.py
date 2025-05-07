import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import core
from esphome.components import button
from esphome.const import (
    CONF_ID,
)

from .. import (
    CONF_BQ25798_ID,
    BQ25798_CLIENT_SCHEMA,
    bq25798_ns,
)

DEPENDENCIES = ["bq25798"]

ClearFlagsButton = bq25798_ns.class_("ClearFlagsButton", cg.Component, button.Button)

# CONF_BQ25798_RESET = "reset"
CONF_BQ25798_CLEAR_FLAGS = "clear_flags"

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(ClearFlagsButton),  # FIXME?
        cv.Optional(CONF_BQ25798_CLEAR_FLAGS): button.button_schema(
            ClearFlagsButton,
            icon="mdi:close",
        ),
    }
).extend(BQ25798_CLIENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])

    await cg.register_component(var, config)
    parent = await cg.get_variable(config[CONF_BQ25798_ID])

    if conf_clear_flags := config.get(CONF_BQ25798_CLEAR_FLAGS):
        btn = await button.new_button(conf_clear_flags)
        # cg.add(parent.set_clear_flags_button(btn))
        await cg.register_parented(btn, config[CONF_BQ25798_ID])
