#include "elec.h"
#include "../swc.h"
#include "../sim.h"
#include "../failures.h"
#include "../acf.h"
#include "../engines_system/eng.h"

/*local apu_gen_counter = 0
local gen_1_counter = 1
local gen_2_counter = 1
local gen_3_counter = 1
local gpu_counter = 0

local gen_on_1_last = get(gen_1_on)
local gen_on_2_last = get(gen_2_on)
local gen_on_3_last = get(gen_3_on)

local ovrld_count_1 = 0
local ovrld_count_2 = 0
local ovrld_count_3 = 0
local ovrld_count_4 = 0*/

int apu_gen_counter = 0;
int gen_1_counter = 1;
int gen_2_counter = 1;
int gen_3_counter = 1;
int gpu_counter = 0;

int gen_on_1_last = 0;
int gen_on_2_last = 0;
int gen_on_3_last = 0;

int ovrld_count_1 = 0;
int ovrld_count_2 = 0;
int ovrld_count_3 = 0;
int ovrld_count_4 = 0;

void generators_logic(elec_t* elec, sim_t* sim, swc_t* swc, failures_t* fails, eng_t* eng, acf_t* acf) {

    float passed = acf->frame_time;

    if (passed > 0) {
        float eng_rpm1 = sim->ENGN_N1_0;
        float eng_rpm2 = sim->ENGN_N1_1;
        float eng_rpm3 = sim->ENGN_N1_2;
        float eng_rpm4 = eng->apu_n1;

        int eng1_work = 0;
        int eng2_work = 0;
        int eng3_work = 0;
        int eng4_work = 0;

        float gen1_amp = elec->gen1_amp;
        float gen2_amp = elec->gen2_amp;
        float gen3_amp = elec->gen3_amp;
        float gen4_amp = elec->gen4_amp;

        int DC = 0;
        if (elec->bus27_volt_left > 13 || elec->bus27_volt_right > 13) {
            DC = 1;
        }

        int gen_on1 = elec->gen1_work;
        int gen_on2 = elec->gen2_work;
        int gen_on3 = elec->gen3_work;
        int gen_on4 = 0;

        if (gen_on1 != gen_on_1_last) gen_on1 = 0;
        if (gen_on2 != gen_on_2_last) gen_on2 = 0;
        if (gen_on3 != gen_on_3_last) gen_on3 = 0;

        gen_on_1_last = elec->gen1_work;
        gen_on_2_last = elec->gen2_work;
        gen_on_3_last = elec->gen3_work;

        if (eng_rpm1 > 25) eng1_work = 1;
        if (eng_rpm2 > 25) eng2_work = 1;
        if (eng_rpm3 > 25) eng3_work = 1;
        if (eng_rpm4 > 92) eng4_work = 1;

        int gen1_fail = sim->rel_genera0 == 6 || elec->gen1_overload == 1;
        int gen2_fail = sim->rel_genera1 == 6 || elec->gen2_overload == 1;
        int gen3_fail = sim->rel_genera2 == 6 || elec->gen3_overload == 1;
        int gen4_fail = elec->gen4_overload == 1 || fails->apu_gen_fail == 1;

        int gen_work_1 = 0;
        if (fabs(gen_on1) * DC * eng1_work == 1) gen_1_counter += passed * 0.5;
        else gen_1_counter = 0;

        if (gen_1_counter > 1) {
            gen_1_counter = 1;
            gen_work_1 = 1;
        }

        float gen1_volt = (119 - gen1_amp / 100) * fabs(gen_on1) * gen_work_1;
        if (gen1_fail) gen1_volt = 0;
        elec->gen1_volt = gen1_volt;

        if (gen1_volt > 110 && gen_on1 == 1) elec->gen1_work = 1;
        else elec->gen1_work = 0;

        int gen_work_2 = 0;
        if (fabs(gen_on2) * DC * eng2_work == 1) gen_2_counter += passed * 0.5;
        else gen_2_counter = 0;

        if (gen_2_counter > 1) {
            gen_2_counter = 1;
            gen_work_2 = 1;
        }

        float gen2_volt = (119 - gen2_amp / 100) * fabs(gen_on2) * gen_work_2;
        if (gen2_fail) gen2_volt = 0;
        elec->gen2_volt = gen2_volt;

        if (gen2_volt > 110 && gen_on2 == 1) elec->gen2_work = 1;
        else elec->gen2_work = 0;

        int gen_work_3 = 0;
        if (fabs(gen_on3) * DC * eng3_work == 1) gen_3_counter += passed * 0.5;
        else gen_3_counter = 0;

        if (gen_3_counter > 1) {
            gen_3_counter = 1;
            gen_work_3 = 1;
        }

        float gen3_volt = (119 - gen3_amp / 100) * fabs(gen_on3) * gen_work_3;
        if (gen3_fail) gen3_volt = 0;
        elec->gen3_volt = gen3_volt;

        if (gen3_volt > 110 && gen_on3 == 1) elec->gen3_work = 1;
        else elec->gen3_work = 0;

        if (swc->eng->apu_gen_on * DC * eng4_work == 1) apu_gen_counter += passed * 0.5;
        else apu_gen_counter = 0;

        if (apu_gen_counter > 1) {
            apu_gen_counter = 1;
            gen_on4 = 1;
        }

        float gen4_volt = (119 - gen4_amp / 100) * gen_on4;
        if (gen4_fail) gen4_volt = 0;
        elec->gen4_volt = gen4_volt;

        if (gen4_volt > 110 && gen_on4 == 1) elec->gen4_work = 1;
        else elec->gen4_work = 0;

        if (gen1_amp > 145) ovrld_count_1 += passed;
        else ovrld_count_1 = 0;

        if (ovrld_count_1 > 5) {
            elec->gen1_overload = 1;
        } else if (gen_on1 == 0) {
            elec->gen1_overload = 0;
        }

        if (gen2_amp > 145) ovrld_count_2 += passed;
        else ovrld_count_2 = 0;

        if (ovrld_count_2 > 5) {
            elec->gen2_overload = 1;
        } else if (gen_on2 == 0) {
            elec->gen2_overload = 0;
        }

        if (gen3_amp > 145) ovrld_count_3 += passed;
        else ovrld_count_3 = 0;

        if (ovrld_count_3 > 5) {
            elec->gen3_overload = 1;
        } else if (gen_on3 == 0) {
            elec->gen3_overload = 0;
        }

        if (gen4_amp > 145) ovrld_count_4 += passed;
        else ovrld_count_4 = 0;

        if (ovrld_count_4 > 5) {
            elec->gen4_overload = 1;
        } else if (gen_on4 == 0) {
            elec->gen4_overload = 0;
        }

        if (gen1_volt * gen_on1 > 0) {
            sim->generator_on0 = 1;
        } else {
            sim->generator_on0 = 0;
        }

        if (gen2_volt * gen_on2 > 0) {
            sim->generator_on1 = 1;
        } else {
            sim->generator_on1 = 0;
        }

        if (gen3_volt * gen_on3 > 0) {
            sim->generator_on2 = 1;
        } else {
            sim->generator_on2 = 0;
        }

        if (gen4_volt * gen_on4 > 0) {
            sim->APU_generator_on = 1;
        } else {
            sim->APU_generator_on = 0;
        }

    }

}