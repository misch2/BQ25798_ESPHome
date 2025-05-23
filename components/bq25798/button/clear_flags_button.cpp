#include "clear_flags_button.h"

#include "esphome/core/log.h"

namespace esphome {
namespace bq25798 {

static const char* const TAG = "bq25798.button";

// Clears the internal (cached) flags.
// This is a workaround for the fact that the BQ25798 clears the flag registers on read so we can't just read them keep them raised
void BQ25798ClearFlagsButton::press_action() {
    ESP_LOGI(TAG, "ClearFlagsButton pressed. Executing action...");    this->parent_->clear_flag_iindpm_flag();
    this->parent_->clear_flag_vindpm_flag();
    this->parent_->clear_flag_wd_flag();
    this->parent_->clear_flag_poorsrc_flag();
    this->parent_->clear_flag_pg_flag();
    this->parent_->clear_flag_ac2_present_flag();
    this->parent_->clear_flag_ac1_present_flag();
    this->parent_->clear_flag_vbus_present_flag();
    this->parent_->clear_flag_chg_flag();
    this->parent_->clear_flag_ico_flag();
    this->parent_->clear_flag_vbus_flag();
    this->parent_->clear_flag_treg_flag();
    this->parent_->clear_flag_vbat_present_flag();
    this->parent_->clear_flag_bc1_2_done_flag();
    this->parent_->clear_flag_dpdm_done_flag();
    this->parent_->clear_flag_adc_done_flag();
    this->parent_->clear_flag_vsys_flag();
    this->parent_->clear_flag_chg_tmr_flag();
    this->parent_->clear_flag_trichg_tmr_flag();
    this->parent_->clear_flag_prechg_tmr_flag();
    this->parent_->clear_flag_topoff_tmr_flag();
    this->parent_->clear_flag_vbatotg_low_flag();
    this->parent_->clear_flag_ts_cold_flag();
    this->parent_->clear_flag_ts_cool_flag();
    this->parent_->clear_flag_ts_warm_flag();
    this->parent_->clear_flag_ts_hot_flag();
    this->parent_->clear_flag_ibat_reg_flag();
    this->parent_->clear_flag_vbus_ovp_flag();
    this->parent_->clear_flag_vbat_ovp_flag();
    this->parent_->clear_flag_ibus_ocp_flag();
    this->parent_->clear_flag_ibat_ocp_flag();
    this->parent_->clear_flag_conv_ocp_flag();
    this->parent_->clear_flag_vac2_ovp_flag();
    this->parent_->clear_flag_vac1_ovp_flag();
    this->parent_->clear_flag_vsys_short_flag();
    this->parent_->clear_flag_vsys_ovp_flag();
    this->parent_->clear_flag_otg_ovp_flag();
    this->parent_->clear_flag_otg_uvp_flag();
    this->parent_->clear_flag_tshut_flag();
}

}  // namespace bq25798
}  // namespace esphome