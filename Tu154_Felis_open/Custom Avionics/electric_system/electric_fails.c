#include "elec.h"
#include "../failures.h"
#include "../acf.h"
#include "../../xpdef.h"
#include <stlib.h>
#include <time.h>

float vu_timer_1 = 0;
float vu_timer_2 = 0;
float vu_timer_3 = 0;

float fail_counter = 0;

srand(time(NULL));
float check_time = rand() % (30 - 15 + 1) + 15;

void electric_fails(elec_t* elec, failures_t* fails, acf_t* acf, xpdef_t* xpdef) {

    int fail = fails->failures_enabled;
    fail = fail * 0.05 * 4 ^ (fail * 0.5);

    if (fail > 0) {

        fail_counter += acf->frame_time;

        if (fail_counter > check_time) {

            fail_counter = 0;
            check_time = rand() % (30 - 15 + 1) + 15;

            if (fails->bat_1_fail != 1) fails->bat_1_fail = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;
            if (fails->bat_2_fail != 1) fails->bat_2_fail = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;
            if (fails->bat_3_fail != 1) fails->bat_3_fail = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;
            if (fails->bat_4_fail != 1) fails->bat_4_fail = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;

            if (fails->bat_1_kz != 1) fails->bat_1_kz = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;
            if (fails->bat_2_kz != 1) fails->bat_2_kz = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;
            if (fails->bat_3_kz != 1) fails->bat_3_kz = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;
            if (fails->bat_4_kz != 1) fails->bat_4_kz = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;

            if (fails->vu1_fail != 1) fails->vu1_fail = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;
            if (fails->vu2_fail != 1) fails->vu2_fail = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;
            if (fails->vu3_fail != 1) fails->vu3_fail = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;

            if (fails->tr1_fail != 1) fails->tr1_fail = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;
            if (fails->tr2_fail != 1) fails->tr2_fail = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;

            if (fails->pts250_1_fail != 1) fails->pts250_1_fail = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;
            if (fails->pts250_2_fail != 1) fails->pts250_2_fail = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;

            if (fails->inv115_fail != 1) fails->inv115_fail = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;

            if (xpdef->ops_rel_genera0 != 1) xpdef->ops_rel_genera0 = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;
            if (xpdef->ops_rel_genera1 != 1) xpdef->ops_rel_genera1 = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;
            if (xpdef->ops_rel_genera2 != 1) xpdef->ops_rel_genera2 = ((rand() / (double)RAND_MAX) < 0.00001 * fail * 0.3) ? 1 : 0;

        }

        /*-- dependent failures
        -- set failures for VUs
        -- 300A should burn out the VU in 3 minutes (180 seconds). Current over 400A - 5 seconds.*/

        float vu_amp_1 = elec->vu1_amp;

        if (vu_amp_1 > 300) vu_timer_1 += acf->frame_time * (vu_amp_1 - 297.5) * 0.4;
        else if (vu_timer_1 > 0) vu_timer_1 -= acf->frame_time * 3;

        if (vu_timer_1 > 180) fails->vu1_fail = 1;

        float vu_amp_2 = elec->vu2_amp;

        if (vu_amp_2 > 300) vu_timer_2 += acf->frame_time * (vu_amp_2 - 297.5) * 0.4;
        else if (vu_timer_2 > 0) vu_timer_2 -= acf->frame_time * 3;

        if (vu_timer_2 > 180) fails->vu2_fail = 1;

        float vu_amp_3 = elec->vu_res_amp;

        if (vu_amp_3 > 300) vu_timer_3 += acf->frame_time * (vu_amp_3 - 297.5) * 0.4;
        else if (vu_timer_3 > 0) vu_timer_3 -= acf->frame_time * 3;

        if (vu_timer_3 > 180) fails->vu3_fail = 1;

    }

    else {

        fail_counter = 0;

        fails->bat_1_fail = 0;
        fails->bat_2_fail = 0;
        fails->bat_3_fail = 0;
        fails->bat_4_fail = 0;

        fails->bat_1_kz = 0;
        fails->bat_2_kz = 0;
        fails->bat_3_kz = 0;
        fails->bat_4_kz = 0;

        fails->vu1_fail = 0;
        fails->vu2_fail = 0;
        fails->vu3_fail = 0;

        fails->tr1_fail = 0;
        fails->tr2_fail = 0;

        fails->pts250_1_fail = 0;
        fails->pts250_2_fail = 0;

        fails->inv115_fail = 0;

        xpdef->ops_rel_genera0 = 0;
        xpdef->ops_rel_genera1 = 0;
        xpdef->ops_rel_genera2 = 0;

    }

}