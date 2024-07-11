#include "elec.h"
#include "../antiice/antiice.h"
#include "../controls/controls.h"
#include "../msrp/msrp.h"
#include "../main_panel/svs.h"
#include "../main_panel/taws/taws.h"
#include "../main_panel/tks/tks.h"
#include "../main_panel/radio/radio.h"
#include "../main_panel/bkk.h"
#include "../main_panel/nvu/nvu.h"
#include "../hydro_system/hydro.h"
#include "../ahz.h"
#include "../fire_system/fire.h"
#include "../acf.h"

void current_counter(elec_t *elec, antiice_t *antiice, controls_t *controls, msrp_t *msrp, svs_t *svs, taws_t *taws, tks_t *tks, radio_t *radio, bkk_t *bkk, nvu_t *nvu, hydro_t *hydro, ahz_t *ahz, fire_t *fire, acf_t *acf) {

    float bus27_L = elec->bat_cc_1 + elec->bat_cc_3 + elec->cockpit_light_cc_left + elec->ext_light_cc_left + elec->fuel_pumps_27_cc * 0.5 + antiice->ai_27_L_cc + controls->ctr_27_L_cc + msrp->msrp_27_L_cc + svs->power_27cc + elec->rv5_left_cc + taws->taws_cc + radio->vhf1_cc + tks->km5_1_cc * 2 + tks->ga_1_cc * 0.5 + tks->ga_2_cc * 0.5 + tks->ga_heat_cc + tks->bgmk_1_cc + ahz->agr_cc + nvu->nvu_cc * 10 + radio->ark15_L_cc + nvu->diss_cc + radio->rsbn_cc * 5;
    float bus27_R = elec->bat_cc_2 + elec->bat_cc_4 + elec->cockpit_light_cc_right + elec->ext_light_cc_right + elec->fuel_pumps_27_cc * 0.5 + antiice->ai_27_R_cc + controls->ctr_27_R_cc + msrp->msrp_27_R_cc + elec->auasp_pow27_cc + elec->rv5_right_cc + fire->fire_sys_cc + radio->vhf2_cc + tks->km5_2_cc * 2 + tks->bgmk_2_cc + tks->ush_cc + radio->ark15_R_cc + radio->radar_cc * 3;

    elec->bus27_amp_left = bus27_L;
    elec->bus27_amp_right = bus27_R;

    //--------------------------------------------

    float bus36_L = controls->ctr_36L_cc + svs->power_36cc + acf->absu_power_cc * 3 + bkk->pkp_left_power_cc + acf->absu_at_power_cc + nvu->nvu_cc * 7 + radio->ark15_L_cc + nvu->diss_cc;
    float bus36_R = controls->ctr_36R_cc + acf->absu_power_cc * 3 + bkk->pkp_right_power_cc + tks->km5_2_cc * 3 + tks->ga_2_cc * 2 + tks->bgmk_2_cc + radio->ark15_R_cc + radio->nav2_pow_cc;

    float bus36_pts_1 = acf->absu_power_cc * 3 + bkk->mgv_ctr_power_cc + ahz->agr_cc + radio->radar_cc;
    float bus36_pts_2 = tks->km5_1_cc * 3 + tks->ga_1_cc * 2 + tks->bgmk_1_cc + radio->nav1_pow_cc;

    elec->bus36_amp_left = bus36_L;
    elec->bus36_amp_right = bus36_R;
    elec->bus36_amp_pts250_1 = bus36_pts_1;
    elec->bus36_amp_pts250_2 = bus36_pts_2;

    //--------------------------------------------

    float bus115_1 = elec->vu1_amp * 0.25 + elec->vu_res_amp * 0.125 + elec->cockpit_light_cc_115 * 0.5 + elec->fuel_pumps_115_1_cc + hydro->gs_pump_2_cc + antiice->ai_115_1_cc + controls->ctr_115_1_cc + svs->power_115cc + elec->rv5_left_cc + taws->taws_cc * 0.2 + acf->absu_at_power_cc + nvu->nvu_cc + nvu->diss_cc * 3 + radio->nav1_pow_cc * radio->rsbn_cc * 5;
    float bus115_3 = elec->vu2_amp * 0.25 + elec->vu_res_amp * 0.125 + elec->cockpit_light_cc_115 * 0.5 + elec->fuel_pumps_115_3_cc + hydro->gs_pump_3_cc + antiice->ai_115_3_cc + controls->ctr_115_3_cc + elec->auasp_pow115_cc + elec->rv5_right_cc + acf->absu_power_cc + radio->nav2_pow_cc + radio->radar_cc * 3;

    elec->bus115_1_amp = bus115_1;
    elec->bus115_2_amp = antiice->ai_115_2_cc;
    elec->bus115_3_amp = bus115_3;

}
