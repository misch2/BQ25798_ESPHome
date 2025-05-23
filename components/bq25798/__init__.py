import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import core
from esphome.components import i2c
from esphome.const import (
    CONF_ID
)

DEPENDENCIES = ["i2c"]
MULTI_CONF = True

bq25798_ns = cg.esphome_ns.namespace("bq25798")
BQ25798Component = bq25798_ns.class_("BQ25798Component", cg.PollingComponent, i2c.I2CDevice)

CONF_BQ25798_ID = "bq25798_id"

CONFIG_SCHEMA = (
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(BQ25798Component),
        }
    )
    .extend(cv.COMPONENT_SCHEMA)
    .extend(cv.polling_component_schema("15s"))  # For the watchdog purpose only
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