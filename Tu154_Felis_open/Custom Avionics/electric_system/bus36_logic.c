#include "elec.h"
#include "../acf.h"
#include "../swc.h"
#include "../fail.h"

void update(acf_t * acf, swc_t * swc, fail_t * fail, elec_t * elec) {
    if (acf->frame_time > 0) {
        int tr1_switch = swc->eng->bus36_tr_left_to_right;
        int tr2_switch = swc->eng->bus36_tr_right_to_left;
        float tr1_volt = (elec->bus115_1_volt / 3.27) * (1 - fail->tr1_fail);
        float tr2_volt = (elec->bus115_1_volt / 3.27) * (1 - fail->tr2_fail);
        int bus_source_L = 0;
        int bus_source_R = 0;

        float bus_L_volt = 0;

        if (tr1_switch == 0 && tr1_volt > 30) {
            bus_L_volt = tr1_volt;
            bus_source_L = 0;
        } else {
            bus_source_L = 1;
            bus_L_volt = tr2_volt;
        }

        float bus_R_volt = 0;

        if (tr2_switch == 0 && tr2_volt > 30) {
            bus_source_R = 0;
            bus_R_volt = tr2_volt;
        } else {
            bus_source_R = 1;
            bus_R_volt = tr1_volt;
        }

        elec->bus36_volt_left = bus_L_volt;
        elec->bus36_volt_right = bus_R_volt;
        elec->bus36_src_L = bus_source_L;
        elec->bus36_src_R = bus_source_R;

        if (tr1_volt > 0) {
            elec->bus36_tr1_work = 1;
        } else {
            elec->bus36_tr1_work = 0;
        }

        if (tr2_volt > 0) {
            elec->bus36_tr2_work = 1;
        } else {
            elec->bus36_tr2_work = 0;
        }   

        float bus27_L = elec->bus27_volt_left;
        float bus27_R = elec->bus27_volt_right;

        float pts_1_volt = 0;

        if (bus27_R > 13 && (swc->eng->pts250_mode == 1 || swc->ovh->agr_on == 1) && fail->pts250_1_fail == 0) {
            pts_1_volt = 36;
            elec->bus36_pts1_work = 1;
        } else {
            pts_1_volt = 0;
            elec->bus36_pts1_work = 0;
        }

        float pts_2_volt = 0;

        if ((bus_L_volt < 30 || swc->eng->pts250_mode == 1) && bus27_L > 13 && fail->pts250_2_fail == 0) {
            pts_2_volt = 36;
            elec->bus36_pts2_work = 1;
        } else {
            pts_2_volt = 0;
            elec->bus36_pts2_work = 0;
        }

        float bus_1_volt = 0;
        int pts_1_fail = 0;

        if (pts_1_volt > 0) {
            bus_1_volt = 36;
            elec->bus27_amp_right += elec->bus36_amp_pts250_1 * 1.4;
        } else {
            bus_1_volt = elec->bus36_volt_right;
            elec->bus36_amp_right += elec->bus36_amp_pts250_1 * 1.05;
        }

        float bus_2_volt = 0;
        int pts_2_fail = 0;

        if (bus_L_volt > 30) {
            bus_2_volt = bus_L_volt;
            elec->bus27_amp_left += elec->bus36_amp_pts250_2 * 1.05;
        } else {
            bus_2_volt = pts_2_volt;
            elec->bus36_amp_left += elec->bus36_amp_pts250_2 * 1.4;
        }

        elec->bus36_amp_pts250_1 = bus_1_volt;
        elec->bus36_amp_pts250_2 = bus_2_volt;

        elec->bus115_1_amp += (elec->bus36_amp_left / 3.25 * (1 - bus_source_L) + (elec->bus36_amp_right / 3.25 * bus_source_R));
        elec->bus115_3_amp += (elec->bus36_amp_left / 3.25 * bus_source_L + (elec->bus36_amp_right / 3.25 * (1 - bus_source_R)));

        return;
    }
} 