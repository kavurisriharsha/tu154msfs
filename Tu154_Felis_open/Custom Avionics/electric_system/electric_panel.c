#include "elec.h"
#include "../swc.h"
#include "../gauges.h"
#include "../lights_system/lights.h"
#include "../sim.h"
#include "../acf.h"
#include <math.h>

int not_loaded = 1;

void reset_switchers(elec_t *elec, swc_t *swc, sim_t *sim) {

    if (sim->ENGN_N1_0 < 5 && sim->ENGN_N1_1 < 5 && sim->ENGN_N1_2 < 5) {
        swc->eng->bat_1_on = 0;
        swc->eng->bat_2_on = 0;
        swc->eng->bat_3_on = 0;
        swc->eng->bat_4_on = 0;
        swc->eng->bus27_vu1 = 0;
        swc->eng->bus27_vu2 = 0;
        swc->eng->bat1_on = 0;
        swc->eng->bat2_on = 0;
        swc->eng->bat3_on = 0;
        swc->eng->bat4_on = 0;
    }

    not_loaded = 0;

}

float k1 = 50;
float k2 = 200;
float vlim = 20;
float alim = 5;

float volt115_table(float volts) {
    return 0.010076965215009590 * volts * volts + 0.071248972884140560 * volts - 120.54533004656257;
}

float volt115_actual = -120;
float freq115_actual = -120;
float volt115_v = 0;
float freq115_v = 0;
float volt115_timer = 0;
float freq115_timer = 0;
float passed = 0;

void voltmeter115(elec_t *elec, swc_t *swc, gauges_t *gauges, lights_t *lights, sim_t *sim, acf_t *acf) {

    passed = acf->frame_time;

    float volt115_angle = -120;
    int v115_sw = swc->eng->bus115_volt_sel;
    int bus115_volt_phase_sel = swc->eng->bus115_volt_phase_sel;

    volt115_timer += passed;

    if (v115_sw != swc->eng->bus115_volt_sel || bus115_volt_phase_sel != swc->eng->bus115_volt_phase_sel) {
        volt115_timer = 0;
        freq115_timer = 0;
    }

    int v115_sw = swc->eng->bus115_volt_sel;
    int bus115_volt_phase_sel = swc->eng->bus115_volt_phase_sel;

    if (volt115_timer < 0.05) volt115_angle = -120;
    else {
        switch (v115_sw) {
            case 0:
                volt115_angle = volt115_table(elec->gen1_volt);
                break;
            case 1:
                volt115_angle = volt115_table(elec->gen2_volt);
                break;
            case 2:
                volt115_angle = volt115_table(elec->gen3_volt);
                break;
            case 3:
                volt115_angle = volt115_table(elec->gen4_volt);
                break;
            case 4:
                volt115_angle = volt115_table(elec->gpu_volt);
                break;
            case 5:
                volt115_angle = volt115_table(elec->bus115_em_1_volt);
                break;
            case 6:
                volt115_angle = volt115_table(elec->bus115_em_2_volt);
                break;
            case 7:
                volt115_angle = volt115_table(elec->bus115_1_volt);
                break;
            case 8:
                volt115_angle = volt115_table(elec->bus115_2_volt);
                break;
            case 9:
                volt115_angle = volt115_table(elec->bus115_3_volt);
                break;
            default:
                break;
        }

    }

    float a115 = (volt115_angle - volt115_actual) * k1;
    volt115_v += a115 * passed;

    volt115_v -= sign(volt115_v) * fmin(k2 * passed, fabs(volt115_v) * 0.5);

    if (volt115_v > vlim) volt115_v = vlim;
    else if (volt115_v < -vlim) volt115_v = -vlim;

    if (passed == 0) volt115_v = 0;

    volt115_actual += volt115_v;

    gauges->eng->bus115_volt = volt115_actual;

    /*local freq115_angle = -120 
	if volt115_angle > 0 and freq115_timer > 0.2 then freq115_angle = 0 else freq115_angle = -120 end
	freq115_timer = freq115_timer + passed
	
	
	local f115 = (freq115_angle - freq115_actual) * k1 -- needle acceleration
	freq115_v = freq115_v + f115 * passed -- needle speed
	
	freq115_v = freq115_v - sign(freq115_v) * math.min(k2 * passed, math.abs(freq115_v)*0.5) -- needle speed with friction
	-- limit the velocity
	if freq115_v > vlim then freq115_v = vlim
	elseif freq115_v < -vlim then freq115_v = -vlim end
	
	if passed == 0 then freq115_v = 0 end
	
	freq115_actual = freq115_actual + freq115_v
	
	set(bus115_freq, freq115_actual)*/

    float freq115_angle = -120;

    if (volt115_angle > 0 && freq115_timer > 0.2) freq115_angle = 0;
    else freq115_angle = -120;

    freq115_timer += passed;

    float f115 = (freq115_angle - freq115_actual) * k1;
    freq115_v += f115 * passed;

    freq115_v -= sign(freq115_v) * fmin(k2 * passed, fabs(freq115_v) * 0.5);

    if (freq115_v > vlim) freq115_v = vlim;
    else if (freq115_v < -vlim) freq115_v = -vlim;

    if (passed == 0) freq115_v = 0;

    freq115_actual += freq115_v;

    gauges->eng->bus115_freq = freq115_actual;

}

float amp115_table(float amps) {
    return 0.000037998988778963266 * amps * amps * amps + 0.0023573971647122775 * amps * amps + 0.37662172537801075 * amps - 120.18687856110505;
}

/*local ampSel_115_last = get(bus115_amp_sel)
local ampPhaseSel_115_last = get(bus115_amp_phase_sel)
local amp115_timer = 0
local amp115_actual = -120
local amp115_v = 0*/

float amp115_actual = -120;
float amp115_v = 0;
float amp115_timer = 0;
float ampsel_115_last = 0;
float ampphase_115_last = 0;

void ammeter115(elec_t *elec, swc_t *swc, gauges_t *gauges, lights_t *lights, sim_t *sim, acf_t *acf) {

    passed = acf->frame_time;

    float ampsel_115_last = swc->eng->bus115_amp_sel;
    float ampphase_115_last = swc->eng->bus115_amp_phase_sel;

    /*if ampSel_115 ~= ampSel_115_last or ampPhaseSel_115 ~= ampPhaseSel_115_last then
		amp115_timer = 0
		playSample(rotary_sound, 0)
	end	
	ampSel_115_last = ampSel_115
	ampPhaseSel_115_last = ampPhaseSel_115
	
	-- set angles
	amp115_timer = amp115_timer + passed
	local amp115_angle = -120
	if amp115_timer < 0.05 then amp115_angle = -120
	elseif ampSel_115 == 0 then amp115_angle = interpolate(amp115_table, get(gpu_amp))
	elseif ampSel_115 == 1 then amp115_angle = interpolate(amp115_table, get(gen1_amp))
	elseif ampSel_115 == 2 then amp115_angle = interpolate(amp115_table, get(gen2_amp))
	elseif ampSel_115 == 3 then amp115_angle = interpolate(amp115_table, get(gen3_amp))
	elseif ampSel_115 == 4 then amp115_angle = interpolate(amp115_table, get(gen4_amp))
	end
	
	-- needle movement
	local a115 = (amp115_angle - amp115_actual) * k1 -- needle acceleration
	amp115_v = amp115_v + a115 * passed -- needle speed
	
	amp115_v = amp115_v - sign(amp115_v) * math.min(k2 * passed, math.abs(amp115_v)*0.5) -- needle speed with friction
	-- limit the velocity
	if amp115_v > vlim then amp115_v = vlim
	elseif amp115_v < -vlim then amp115_v = -vlim end
	
	if passed == 0 then amp115_v = 0 end
	
	amp115_actual = amp115_actual + amp115_v
	
	set(bus115_amp, amp115_actual)*/

    if (swc->eng->bus115_amp_sel != ampsel_115_last || swc->eng->bus115_amp_phase_sel != ampphase_115_last) {
        amp115_timer = 0;
    }

    ampsel_115_last = swc->eng->bus115_amp_sel;
    ampphase_115_last = swc->eng->bus115_amp_phase_sel;

    amp115_timer += passed;
    float amp115_angle = -120;

    if (amp115_timer < 0.05) amp115_angle = -120;
    else {
        switch (swc->eng->bus115_amp_sel) {
            case 0:
                amp115_angle = amp115_table(elec->gpu_amp);
                break;
            case 1:
                amp115_angle = amp115_table(elec->gen1_amp);
                break;
            case 2:
                amp115_angle = amp115_table(elec->gen2_amp);
                break;
            case 3:
                amp115_angle = amp115_table(elec->gen3_amp);
                break;
            case 4:
                amp115_angle = amp115_table(elec->gen4_amp);
                break;
            default:
                break;
        }
    }

    float a115 = (amp115_angle - amp115_actual) * k1;
    amp115_v += a115 * passed;

    amp115_v -= sign(amp115_v) * fmin(k2 * passed, fabs(amp115_v) * 0.5);

    if (amp115_v > vlim) amp115_v = vlim;
    else if (amp115_v < -vlim) amp115_v = -vlim;

    if (passed == 0) amp115_v = 0;

    amp115_actual += amp115_v;

    gauges->eng->bus115_amp = amp115_actual;

}

float volt36_table(float volts) {
    return  0.00078016861708829141 * volts * volts * volts + 0.057721691923271638 * volts * volts + 1.0993906056194716 * volts - 120.36401876718998;
}

/*local volSel_36_last = get(bus36_volt_sel)
local volt36_timer = 0
local volt36_v = 0
local volt36_actual = -120*/

float volt36_actual = -120;
float volt36_v = 0;
float volt36_timer = 0;
float volsel_36_last = 0;

void voltmeter36(elec_t *elec, swc_t *swc, gauges_t *gauges, lights_t *lights, sim_t *sim, acf_t *acf) {

    passed = acf->frame_time;
    /*local volSel_36 = get(bus36_volt_sel)
	volt36_timer = volt36_timer + passed
	-- play sound and reset timers
	if volSel_36 ~= volSel_36_last then
		volt36_timer = 0
		playSample(rotary_sound, 0)
	end	
	
	local volt36_angle = -120
	if volt36_timer < 0.05 then volt36_angle = -120
	elseif volSel_36 < 3 then volt36_angle = interpolate(volt36_table, get(bus36_volt_left))
	elseif volSel_36 < 6 then volt36_angle = interpolate(volt36_table, get(bus36_volt_right))
	else 
		if get(pts250_sel) == 0 then
			volt36_angle = interpolate(volt36_table, get(bus36_volt_pts250_1))
		else
			volt36_angle = interpolate(volt36_table, get(bus36_volt_pts250_2))
		end
	end
	
	-- needle movement
	local a36 = (volt36_angle - volt36_actual) * k1 -- needle acceleration
	volt36_v = volt36_v + a36 * passed -- needle speed
	
	volt36_v = volt36_v - sign(volt36_v) * math.min(k2 * passed, math.abs(volt36_v)*0.5) -- needle speed with friction
	-- limit the velocity
	if volt36_v > vlim then volt36_v = vlim
	elseif volt36_v < -vlim then volt36_v = -vlim end
	
	if passed == 0 then volt36_v = 0 end
	
	volt36_actual = volt36_actual + volt36_v

	
	set(bus36_volt, volt36_actual)
	volSel_36_last = volSel_36*/

    float volsel_36_last = swc->eng->bus36_volt_sel;
    volt36_timer += passed;

    if (swc->eng->bus36_volt_sel != volsel_36_last) {
        volt36_timer = 0;
    }

    float volt36_angle = -120;

    if (volt36_timer < 0.05) volt36_angle = -120;
    else {
        if (swc->eng->bus36_volt_sel < 3) {
            volt36_angle = volt36_table(elec->bus36_volt_left);
        } else if (swc->eng->bus36_volt_sel < 6) {
            volt36_angle = volt36_table(elec->bus36_volt_right);
        } else {
            if (swc->eng->pts250_sel == 0) {
                volt36_angle = volt36_table(elec->bus36_volt_pts250_1);
            } else {
                volt36_angle = volt36_table(elec->bus36_volt_pts250_2);
            }
        }
    }

    float a36 = (volt36_angle - volt36_actual) * k1;
    volt36_v += a36 * passed;

    volt36_v -= sign(volt36_v) * fmin(k2 * passed, fabs(volt36_v) * 0.5);

    if (volt36_v > vlim) volt36_v = vlim;
    else if (volt36_v < -vlim) volt36_v = -vlim;

    if (passed == 0) volt36_v = 0;

    volt36_actual += volt36_v;

    gauges->eng->bus36_volt = volt36_actual;
    volsel_36_last = swc->eng->bus36_volt_sel;

}   

