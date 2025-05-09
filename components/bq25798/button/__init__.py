import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import button
from esphome.const import (
    CONF_ID,
)

from .. import (
    CONF_BQ25798_ID,
    bq25798_ns,
    BQ25798Component
)

DEPENDENCIES = ["bq25798"]

BQ25798ClearFlagsButton = bq25798_ns.class_("BQ25798ClearFlagsButton", button.Button, cg.Component)
CONF_BQ25798_CLEAR_FLAGS = "clear_flags"

CONFIG_SCHEMA =(
    button.button_schema(BQ25798Component)
    .extend({
        cv.GenerateID(CONF_BQ25798_ID): cv.use_id(BQ25798Component),
        cv.Optional(CONF_BQ25798_CLEAR_FLAGS): button.button_schema(
            BQ25798ClearFlagsButton,
            icon="mdi:close",
        ),
    })
    .extend(cv.COMPONENT_SCHEMA)
)

async def to_code(config):
    main_component = await cg.get_variable(config[CONF_BQ25798_ID]) # parent component

    if clear_flags_config := config.get(CONF_BQ25798_CLEAR_FLAGS):
        btn = await button.new_button(
            clear_flags_config
        )
        await cg.register_parented(btn, config[CONF_BQ25798_ID])
        await cg.register_component(btn, config)
