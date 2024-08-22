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

/*local volSel_27_last = get(bus27_volt_sel)
local ampSel_27_1_last = get(bus27_amp1_sel)
local ampSel_27_2_last = get(bus27_amp2_sel)
local volt27_timer = 0
local amp27_1_timer = 0
local amp27_2_timer = 0

local volt27_v = 0
local volt27_actual = -120

local amp27_1_v = 0
local amp27_1_actual = -99

local amp27_2_v = 0
local amp27_2_actual = -99*/

float volt27_actual = -120;
float volt27_v = 0;

float amp27_1_actual = -99;
float amp27_1_v = 0;

float amp27_2_actual = -99;
float amp27_2_v = 0;

float volt27_timer = 0;
float amp27_1_timer = 0;
float amp27_2_timer = 0;

float volsel_27_last = 0;
float ampsel_27_1_last = 0;
float ampsel_27_2_last = 0;

float volt27_table(float volts) {
    return 8 * volts - 120;
}

float amp27_table(float amps) {
    /*Output form: simple list (ordered x^0 to x^n):

-9.8999999999999858e+001
 5.2704545454546126e-001
 5.1136363636346064e-005*/
    return -99 + 0.52704545454546126 * amps + 0.000051136363636346064 * amps * amps;
}

void bus27_gauge(elec_t *elec, swc_t *swc, gauges_t *gauges, lights_t *lights, sim_t *sim, acf_t *acf) {

    passed = acf->frame_time;

    /*local volSel_27 = get(bus27_volt_sel)
	local ampSel_27_1 = get(bus27_amp1_sel)
	local ampSel_27_2 = get(bus27_amp2_sel)
	
	volt27_timer = volt27_timer + passed
	amp27_1_timer = amp27_1_timer + passed
	amp27_2_timer = amp27_2_timer + passed
	
	-- play sounds and reset timers
	if volSel_27 ~= volSel_27_last then
		volt27_timer = 0
		playSample(rotary_sound, 0)
	end
	if ampSel_27_1 ~= ampSel_27_1_last then
		amp27_1_timer = 0
		playSample(rotary_sound, 0)
	end
	if ampSel_27_2 ~= ampSel_27_2_last then
		amp27_2_timer = 0
		playSample(rotary_sound, 0)
	end
	
	volSel_27_last = volSel_27
	ampSel_27_1_last = ampSel_27_1
	ampSel_27_2_last = ampSel_27_2
	
	local volt27_angle = -120
	if volt27_timer < 0.05 then volt27_angle = -120
	elseif volSel_27 == 0 then volt27_angle = interpolate(volt27_table, get(bat_volt_1))
	elseif volSel_27 == 4 then volt27_angle = interpolate(volt27_table, get(bat_volt_2))
	elseif volSel_27 == 1 then volt27_angle = interpolate(volt27_table, get(bat_volt_3))
	elseif volSel_27 == 5 then volt27_angle = interpolate(volt27_table, get(bat_volt_4))
	elseif volSel_27 == 2 then volt27_angle = interpolate(volt27_table, get(bus27_volt_left))
	elseif volSel_27 == 3 then volt27_angle = interpolate(volt27_table, get(bus27_volt_right))
	end

	local amp27_1_angle = -99
	if amp27_1_timer < 0.05 then amp27_1_angle = -99
	elseif ampSel_27_1 == 0 then amp27_1_angle = interpolate(amp27_table, get(bat_amp_1) - get(bat_amp_cc_1))
	elseif ampSel_27_1 == 1 then amp27_1_angle = interpolate(amp27_table, get(bat_amp_3) - get(bat_amp_cc_3))
	elseif ampSel_27_1 == 2 then amp27_1_angle = interpolate(amp27_table, get(vu1_amp))
	elseif ampSel_27_1 == 3 then amp27_1_angle = interpolate(amp27_table, get(vu_res_amp))
	end

	local amp27_2_angle = -99
	if amp27_2_timer < 0.05 then amp27_2_angle = -99
	elseif ampSel_27_2 == 0 then amp27_2_angle = interpolate(amp27_table, get(bat_amp_2) - get(bat_amp_cc_2))
	elseif ampSel_27_2 == 1 then amp27_2_angle = interpolate(amp27_table, get(bat_amp_4) - get(bat_amp_cc_4))
	elseif ampSel_27_2 == 2 then amp27_2_angle = interpolate(amp27_table, get(vu2_amp))
	elseif ampSel_27_2 == 3 then amp27_2_angle = interpolate(amp27_table, get(vu_res_amp))
	end

	-- needles movements
	-- voltmeter
	local av27 = (volt27_angle - volt27_actual) * k1 -- needle acceleration
	volt27_v = volt27_v + av27 * passed -- needle speed
	
	volt27_v = volt27_v - sign(volt27_v) * math.min(k2 * passed, math.abs(volt27_v)*0.5) -- needle speed with friction
	-- limit the velocity
	if volt27_v > vlim then volt27_v = vlim
	elseif volt27_v < -vlim then volt27_v = -vlim end
	
	if passed == 0 then volt27_v = 0 end
	
	volt27_actual = volt27_actual + volt27_v	
	
	-- ampermeter 1
	local aa27_1 = (amp27_1_angle - amp27_1_actual) * k1 -- needle acceleration
	amp27_1_v = amp27_1_v + aa27_1 * passed -- needle speed
	
	amp27_1_v = amp27_1_v - sign(amp27_1_v) * math.min(k2 * passed, math.abs(amp27_1_v)*0.5) -- needle speed with friction
	-- limit the velocity
	if amp27_1_v > vlim then amp27_1_v = vlim
	elseif amp27_1_v < -vlim then amp27_1_v = -vlim end
	
	if passed == 0 then amp27_1_v = 0 end
	
	amp27_1_actual = amp27_1_actual + amp27_1_v	

	-- ampermeter 2
	local aa27_2 = (amp27_2_angle - amp27_2_actual) * k1 -- needle acceleration
	amp27_2_v = amp27_2_v + aa27_2 * passed -- needle speed
	
	amp27_2_v = amp27_2_v - sign(amp27_2_v) * math.min(k2 * passed, math.abs(amp27_2_v)*0.5) -- needle speed with friction
	-- limit the velocity
	if amp27_2_v > vlim then amp27_2_v = vlim
	elseif amp27_2_v < -vlim then amp27_2_v = -vlim end
	
	if passed == 0 then amp27_2_v = 0 end
	
	amp27_2_actual = amp27_2_actual + amp27_2_v	
		
	
	set(bus27_volt, volt27_actual)
	set(bus27_amp1, amp27_1_actual)
	set(bus27_amp2, amp27_2_actual)
	*/

    float volsel_27 = swc->eng->bus27_volt_sel;
    float ampsel_27_1 = swc->eng->bus27_amp1_sel;
    float ampsel_27_2 = swc->eng->bus27_amp2_sel;

    volt27_timer += passed;
    amp27_1_timer += passed;
    amp27_2_timer += passed;

    if (swc->eng->bus27_volt_sel != volsel_27_last) {
        volt27_timer = 0;
    }

    if (swc->eng->bus27_amp1_sel != ampsel_27_1_last) {
        amp27_1_timer = 0;
    }

    if (swc->eng->bus27_amp2_sel != ampsel_27_2_last) {
        amp27_2_timer = 0;
    }

    volsel_27_last = volsel_27;
    ampsel_27_1_last = ampsel_27_1;
    ampsel_27_2_last = ampsel_27_2;

    float volt27_angle = -120;

    if (volt27_timer < 0.05) volt27_angle = -120;
    else {
        switch (swc->eng->bus27_volt_sel) {
            case 0:
                volt27_angle = volt27_table(elec->bat_volt_1);
                break;
            case 4:
                volt27_angle = volt27_table(elec->bat_volt_2);
                break;
            case 1:
                volt27_angle = volt27_table(elec->bat_volt_3);
                break;
            case 5:
                volt27_angle = volt27_table(elec->bat_volt_4);
                break;
            case 2:
                volt27_angle = volt27_table(elec->bus27_volt_left);
                break;
            case 3:
                volt27_angle = volt27_table(elec->bus27_volt_right);
                break;
            default:
                break;
        }
    }

    float amp27_1_angle = -99;

    if (amp27_1_timer < 0.05) amp27_1_angle = -99;
    else {
        switch (swc->eng->bus27_amp1_sel) {
            case 0:
                amp27_1_angle = amp27_table(elec->bat_amp_1 - elec->bat_amp_cc_1);
                break;
            case 1:
                amp27_1_angle = amp27_table(elec->bat_amp_3 - elec->bat_amp_cc_3);
                break;
            case 2:
                amp27_1_angle = amp27_table(elec->vu1_amp);
                break;
            case 3:
                amp27_1_angle = amp27_table(elec->vu_res_amp);
                break;
            default:
                break;
        }
    }

    float amp27_2_angle = -99;

    if (amp27_2_timer < 0.05) amp27_2_angle = -99;
    else {
        switch (swc->eng->bus27_amp2_sel) {
            case 0:
                amp27_2_angle = amp27_table(elec->bat_amp_2 - elec->bat_amp_cc_2);
                break;
            case 1:
                amp27_2_angle = amp27_table(elec->bat_amp_4 - elec->bat_amp_cc_4);
                break;
            case 2:
                amp27_2_angle = amp27_table(elec->vu2_amp);
                break;
            case 3:
                amp27_2_angle = amp27_table(elec->vu_res_amp);
                break;
            default:
                break;
        }
    }

    float av27 = (volt27_angle - volt27_actual) * k1;
    volt27_v += av27 * passed;

    volt27_v -= sign(volt27_v) * fmin(k2 * passed, fabs(volt27_v) * 0.5);

    if (volt27_v > vlim) volt27_v = vlim;
    else if (volt27_v < -vlim) volt27_v = -vlim;

    if (passed == 0) volt27_v = 0;

    volt27_actual += volt27_v;

    float aa27_1 = (amp27_1_angle - amp27_1_actual) * k1;
    amp27_1_v += aa27_1 * passed;

    amp27_1_v -= sign(amp27_1_v) * fmin(k2 * passed, fabs(amp27_1_v) * 0.5);

    if (amp27_1_v > vlim) amp27_1_v = vlim;
    else if (amp27_1_v < -vlim) amp27_1_v = -vlim;

    if (passed == 0) amp27_1_v = 0;

    amp27_1_actual += amp27_1_v;

    float aa27_2 = (amp27_2_angle - amp27_2_actual) * k1;
    amp27_2_v += aa27_2 * passed;

    amp27_2_v -= sign(amp27_2_v) * fmin(k2 * passed, fabs(amp27_2_v) * 0.5);

    if (amp27_2_v > vlim) amp27_2_v = vlim;
    else if (amp27_2_v < -vlim) amp27_2_v = -vlim;

    if (passed == 0) amp27_2_v = 0;

    amp27_2_actual += amp27_2_v;

    gauges->eng->bus27_volt = volt27_actual;
    gauges->eng->bus27_amp1 = amp27_1_actual;
    gauges->eng->bus27_amp2 = amp27_2_actual;
  
}

/*local gpu_sw_last = get(gpu_on)
	local apu_sw_last = get(apu_gen_on)
	local gen_1_last = get(gen_1_on)
	local gen_2_last = get(gen_2_on)
	local gen_3_last = get(gen_3_on)
	local pts_sw_last = get(pts250_sel)
	local pts_LR_last = get(bus36_tr_left_to_right)
	local pts_RL_last = get(bus36_tr_right_to_left)
	local pts_sw_on_last = get(pts250_on)
	local pts_mod_last = get(pts250_mode)
	local vu1_last = get(bus27_vu1)
	local vu2_last = get(bus27_vu2)
	local bat1_last = get(bat1_on)
	local bat2_last = get(bat2_on)
	local bat3_last = get(bat3_on)
	local bat4_last = get(bat4_on)
	local emerg_115_last = get(emerg_inv115)
	local bus_con_last = get(bus27_connect)	*/

int gpu_sw_last = 0;
int apu_sw_last = 0;
int gen_1_last = 0;
int gen_2_last = 0;
int gen_3_last = 0;
int pts_sw_last = 0;
int pts_LR_last = 0;
int pts_RL_last = 0;
int pts_sw_on_last = 0;
int pts_mod_last = 0;
int vu1_last = 0;
int vu2_last = 0;
int bat1_last = 0;
int bat2_last = 0;
int bat3_last = 0;
int bat4_last = 0;
int emerg_115_last = 0;
int bus_con_last = 0;

void switchers_check() {

    /*local gpu_sw = get(gpu_on)
	local apu_sw = get(apu_gen_on)
	local gen_1 = get(gen_1_on)
	local gen_2 = get(gen_2_on)
	local gen_3 = get(gen_3_on)
	local pts_sw = get(pts250_sel)
	local pts_LR = get(bus36_tr_left_to_right)
	local pts_RL = get(bus36_tr_right_to_left)
	local pts_on_sw = get(pts250_on)
	local pts_mod = get(pts250_mode)
	local vu1 = get(bus27_vu1)
	local vu2 = get(bus27_vu2)
	local bat1 = get(bat1_on)
	local bat2 = get(bat2_on)
	local bat3 = get(bat3_on)
	local bat4 = get(bat4_on)
	
	local emerg_115 = get(emerg_inv115)
	local bus_con = get(bus27_connect)
	
	local sw_change = gpu_sw - gpu_sw_last + apu_sw - apu_sw_last + gen_1 - gen_1_last + gen_2 - gen_2_last + gen_3 - gen_3_last
	sw_change = sw_change + pts_sw - pts_sw_last + pts_LR - pts_LR_last + pts_RL - pts_RL_last + pts_on_sw - pts_sw_on_last + pts_mod - pts_mod_last
	sw_change = sw_change + vu1 - vu1_last + vu2 - vu2_last + bat1 - bat1_last + bat2 - bat2_last + bat3 - bat3_last + bat4 - bat4_last
	sw_change = sw_change + emerg_115 + bus_con - emerg_115_last - bus_con_last
	
	if sw_change ~= 0 then playSample(switcher_sound, 0) end -- play sound
	
	gpu_sw_last = gpu_sw
	apu_sw_last = apu_sw
	gen_1_last = gen_1
	gen_2_last = gen_2
	gen_3_last = gen_3
	pts_sw_last = pts_sw
	pts_LR_last = pts_LR
	pts_RL_last = pts_RL
	pts_sw_on_last = pts_on_sw
	pts_mod_last = pts_mod
	vu1_last = vu1
	vu2_last = vu2
	bat1_last = bat1
	bat2_last = bat2
	bat3_last = bat3
	bat4_last = bat4
	emerg_115_last = emerg_115
	bus_con_last = bus_con
	*/

    gpu_sw_last = swc->eng->gpu_on;
    apu_sw_last = swc->eng->apu_gen_on;
    gen_1_last = swc->eng->gen_1_on;
    gen_2_last = swc->eng->gen_2_on;
    gen_3_last = swc->eng->gen_3_on;
    pts_sw_last = swc->eng->pts250_sel;
    pts_LR_last = swc->eng->bus36_tr_left_to_right;
    pts_RL_last = swc->eng->bus36_tr_right_to_left;
    pts_sw_on_last = swc->eng->pts250_on;
    pts_mod_last = swc->eng->pts250_mode;
    vu1_last = swc->eng->bus27_vu1;
    vu2_last = swc->eng->bus27_vu2;
    bat1_last = swc->eng->bat1_on;
    bat2_last = swc->eng->bat2_on;
    bat3_last = swc->eng->bat3_on;
    bat4_last = swc->eng->bat4_on;
    emerg_115_last = swc->eng->emerg_inv115;
    bus_con_last = swc->eng->bus27_connect;

    int sw_change = swc->eng->gpu_on - gpu_sw_last + swc->eng->apu_gen_on - apu_sw_last + swc->eng->gen_1_on - gen_1_last + swc->eng->gen_2_on - gen_2_last + swc->eng->gen_3_on - gen_3_last;
    sw_change += swc->eng->pts250_sel - pts_sw_last + swc->eng->bus36_tr_left_to_right - pts_LR_last + swc->eng->bus36_tr_right_to_left - pts_RL_last + swc->eng->pts250_on - pts_sw_on_last + swc->eng->pts250_mode - pts_mod_last;
    sw_change += swc->eng->bus27_vu1 - vu1_last + swc->eng->bus27_vu2 - vu2_last + swc->eng->bat1_on - bat1_last + swc->eng->bat2_on - bat2_last + swc->eng->bat3_on - bat3_last + swc->eng->bat4_on - bat4_last;
    sw_change += swc->eng->emerg_inv115 + swc->eng->bus27_connect - emerg_115_last - bus_con_last;

    if (sw_change != 0) {
        //playSample(switcher_sound, 0);
    }

    gpu_sw_last = swc->eng->gpu_on;
    apu_sw_last = swc->eng->apu_gen_on;
    gen_1_last = swc->eng->gen_1_on;
    gen_2_last = swc->eng->gen_2_on;
    gen_3_last = swc->eng->gen_3_on;
    pts_sw_last = swc->eng->pts250_sel;
    pts_LR_last = swc->eng->bus36_tr_left_to_right;
    pts_RL_last = swc->eng->bus36_tr_right_to_left;
    pts_sw_on_last = swc->eng->pts250_on;
    pts_mod_last = swc->eng->pts250_mode;
    vu1_last = swc->eng->bus27_vu1;
    vu2_last = swc->eng->bus27_vu2;
    bat1_last = swc->eng->bat1_on;
    bat2_last = swc->eng->bat2_on;
    bat3_last = swc->eng->bat3_on;
    bat4_last = swc->eng->bat4_on;
    emerg_115_last = swc->eng->emerg_inv115;
    bus_con_last = swc->eng->bus27_connect;

}

/*local em115_cap_last = get(emerg_inv115_cap)
	local pts_on_cap_last = get(pts250_on_cap)
	local pts_mod_cap_last = get(pts250_mode_cap)
	local bus_con_cap_last = get(bus27_connect_cap)*/

int em115_cap_last = 0;
int pts_on_cap_last = 0;
int pts_mod_cap_last = 0;
int bus_con_cap_last = 0;

void caps_check(elec_t *elec, swc_t *swc, gauges_t *gauges, lights_t *lights, sim_t *sim, acf_t *acf) {

    /*local em115_cap = get(emerg_inv115_cap)
	local pts_on_cap = get(pts250_on_cap)
	local pts_mod_cap = get(pts250_mode_cap)
	local bus_con_cap = get(bus27_connect_cap)
	
	local cap_change = em115_cap + pts_on_cap + pts_mod_cap + bus_con_cap - em115_cap_last - pts_on_cap_last - pts_mod_cap_last - bus_con_cap_last
	
	if cap_change ~= 0 then playSample(cap_sound, 0) end -- play sound
	
	if em115_cap == 0 then set(emerg_inv115, 0) end
	if pts_on_cap == 0 then set(pts250_on, 0) end
	if pts_mod_cap == 0 then set(pts250_mode, 0) end
	if bus_con_cap == 0 then set(bus27_connect, 0) end
	
	em115_cap_last = em115_cap
	pts_on_cap_last = pts_on_cap
	pts_mod_cap_last = pts_mod_cap
	bus_con_cap_last = bus_con_cap*/

    em115_cap_last = swc->eng->emerg_inv115_cap;
    pts_on_cap_last = swc->eng->pts250_on_cap;
    pts_mod_cap_last = swc->eng->pts250_mode_cap;
    bus_con_cap_last = swc->eng->bus27_connect_cap;

    int cap_change = swc->eng->emerg_inv115_cap + swc->eng->pts250_on_cap + swc->eng->pts250_mode_cap + swc->eng->bus27_connect_cap - em115_cap_last - pts_on_cap_last - pts_mod_cap_last - bus_con_cap_last;

    if (cap_change != 0) {
        //playSample(cap_sound, 0);
    }

    if (swc->eng->emerg_inv115_cap == 0) swc->eng->emerg_inv115 = 0;
    if (swc->eng->pts250_on_cap == 0) swc->eng->pts250_on = 0;
    if (swc->eng->pts250_mode_cap == 0) swc->eng->pts250_mode = 0;
    if (swc->eng->bus27_connect_cap == 0) swc->eng->bus27_connect = 0;

    em115_cap_last = swc->eng->emerg_inv115_cap;
    pts_on_cap_last = swc->eng->pts250_on_cap;
    pts_mod_cap_last = swc->eng->pts250_mode_cap;
    bus_con_cap_last = swc->eng->bus27_connect_cap;

}

void lamps(elec_t *elec, swc_t *swc, gauges_t *gauges, lights_t *lights, sim_t *sim, acf_t *acf) {

    /*local lamps_brt = math.max((math.max(get(bus27_volt_right), get(bus27_volt_left))  - 10) / 18.5, 0)
	local test_btn = get(test_lamps) * math.max(get(bus27_volt_right)  - 10 / 18.5, 0)
		
	-- lamps logic
	local gpu_brt = math.max(get(gpu_work_bus) * lamps_brt, test_btn)
	
	local npk_brt = 0
	if get(bus115_1_volt) < 110 and get(bus115_3_volt) < 110 then npk_brt = 1 end
	npk_brt = math.max(npk_brt * lamps_brt, test_btn)
	
	local emerg115_brt = math.max(get(emerg_inv115) * (1 - get(inv115_fail)), test_btn) * lamps_brt
		
	local gen_1_brt = 0
	if get(gen1_volt) < 110 then gen_1_brt = 1 end
	gen_1_brt = math.max(gen_1_brt * lamps_brt, test_btn)

	local gen_2_brt = 0
	if get(gen2_volt) < 110 then gen_2_brt = 1 end
	gen_2_brt = math.max(gen_2_brt * lamps_brt, test_btn)

	local gen_3_brt = 0
	if get(gen3_volt) < 110 then gen_3_brt = 1 end
	gen_3_brt = math.max(gen_3_brt * lamps_brt, test_btn)	
	
	local bus_con_brt = math.max(get(buses_connected) * lamps_brt, test_btn)

	local left_bat_brt = 0
	if get(bus27_source_left) > 2 then left_bat_brt = math.max(get(bat1_on), get(bat3_on)) end
	left_bat_brt = math.max(left_bat_brt * lamps_brt, test_btn)
	
	local right_bat_brt = 0
	if get(bus27_source_right) > 2 then right_bat_brt = math.max(get(bat2_on), get(bat4_on)) end
	right_bat_brt = math.max(right_bat_brt * lamps_brt, test_btn)
	
	local bat_1_brt = 0
	if get(bat_therm_1) > 100 then bat_1_brt = 1 end
	bat_1_brt = math.max(bat_1_brt * lamps_brt, test_btn)
	
	local bat_2_brt = 0
	if get(bat_therm_2) > 100 then bat_2_brt = 1 end
	bat_2_brt = math.max(bat_2_brt * lamps_brt, test_btn)

	local bat_3_brt = 0
	if get(bat_therm_3) > 100 then bat_3_brt = 1 end
	bat_3_brt = math.max(bat_3_brt * lamps_brt, test_btn)

	local bat_4_brt = 0
	if get(bat_therm_4) > 100 then bat_4_brt = 1 end
	bat_4_brt = math.max(bat_4_brt * lamps_brt, test_btn)

	
	local left_VU_brt = math.max(get(vu_res_to_L) * lamps_brt, test_btn)
	local right_VU_brt = math.max(get(vu_res_to_R) * lamps_brt, test_btn)
	
	local L_R_brt = math.max(get(bus36_src_L) * lamps_brt, test_btn)
	local R_L_brt = math.max(get(bus36_src_R) * lamps_brt, test_btn)
	
	
	local pts_1_brt = math.max((1 - get(bus36_pts1_work)) * lamps_brt, test_btn)
	local pts_2_brt = math.max(get(bus36_pts2_work) * lamps_brt, test_btn)

	-- set results
	set(lamp_apu_gen_on, gpu_brt)
	set(bus_npk_1, npk_brt)
	set(bus_npk_2, npk_brt)
	set(emerg_inv_115, emerg115_brt)
	set(gen_fail_1, gen_1_brt)
	set(gen_fail_2, gen_2_brt)
	set(gen_fail_3, gen_3_brt)
	set(bus_connected, bus_con_brt)
	set(left_bus_use_bat, left_bat_brt)
	set(right_bus_use_bat, right_bat_brt)
	
	set(turn_off_bat_1, bat_1_brt)
	set(turn_off_bat_2, bat_2_brt)
	set(turn_off_bat_3, bat_3_brt)
	set(turn_off_bat_4, bat_4_brt)
	
	set(vu_on_1, left_VU_brt)
	set(vu_on_2, right_VU_brt)
	
	set(left_bus_on_tr2, L_R_brt)
	set(right_bus_on_tr1, R_L_brt)
	set(pts250_n1, pts_1_brt)
	set(pts250_n2, pts_2_brt)
	*/

    float lamps_brt = fmax((fmax(elec->bus27_volt_right, elec->bus27_volt_left) - 10) / 18.5, 0);
    float test_btn = swc->eng->test_lamps * fmax(elec->bus27_volt_right - 10 / 18.5, 0);

    float gpu_brt = fmax(swc->eng->gpu_work_bus * lamps_brt, test_btn);

    float npk_brt = 0;
    if (elec->bus115_1_volt < 110 && elec->bus115_3_volt < 110) npk_brt = 1;
    npk_brt = fmax(npk_brt * lamps_brt, test_btn);

    float emerg115_brt = fmax(swc->eng->emerg_inv115 * (1 - elec->inv115_fail), test_btn) * lamps_brt;

    float gen_1_brt = 0;
    if (elec->gen1_volt < 110) gen_1_brt = 1;
    gen_1_brt = fmax(gen_1_brt * lamps_brt, test_btn);

    float gen_2_brt = 0;
    if (elec->gen2_volt < 110) gen_2_brt = 1;
    gen_2_brt = fmax(gen_2_brt * lamps_brt, test_btn);

    float gen_3_brt = 0;
    if (elec->gen3_volt < 110) gen_3_brt = 1;
    gen_3_brt = fmax(gen_3_brt * lamps_brt, test_btn);

    float bus_con_brt = fmax(swc->eng->buses_connected * lamps_brt, test_btn);

    float left_bat_brt = 0;
    if (elec->bus27_source_left > 2) left_bat_brt = fmax(swc->eng->bat1_on, swc->eng->bat3_on);
    left_bat_brt = fmax(left_bat_brt * lamps_brt, test_btn);

    float right_bat_brt = 0;
    if (elec->bus27_source_right > 2) right_bat_brt = fmax(swc->eng->bat2_on, swc->eng->bat4_on);
    right_bat_brt = fmax(right_bat_brt * lamps_brt, test_btn);

    float bat_1_brt = 0;
    if (elec->bat_therm_1 > 100) bat_1_brt = 1;
    bat_1_brt = fmax(bat_1_brt * lamps_brt, test_btn);

    float bat_2_brt = 0;
    if (elec->bat_therm_2 > 100) bat_2_brt = 1;
    bat_2_brt = fmax(bat_2_brt * lamps_brt, test_btn);

    float bat_3_brt = 0;
    if (elec->bat_therm_3 > 100) bat_3_brt = 1;
    bat_3_brt = fmax(bat_3_brt * lamps_brt, test_btn);

    float bat_4_brt = 0;
    if (elec->bat_therm_4 > 100) bat_4_brt = 1;
    bat_4_brt = fmax(bat_4_brt * lamps_brt, test_btn);

    float left_VU_brt = fmax(swc->eng->vu_res_to_L * lamps_brt, test_btn);
    float right_VU_brt = fmax(swc->eng->vu_res_to_R * lamps_brt, test_btn);

    float L_R_brt = fmax(swc->eng->bus36_src_L * lamps_brt, test_btn);
    float R_L_brt = fmax(swc->eng->bus36_src_R * lamps_brt, test_btn);

    float pts_1_brt = fmax((1 - swc->eng->bus36_pts1_work) * lamps_brt, test_btn);
    float pts_2_brt = fmax(swc->eng->bus36_pts2_work * lamps_brt, test_btn);

    gauges->eng->lamp_apu_gen_on = gpu_brt;
    gauges->eng->bus_npk_1 = npk_brt;
    gauges->eng->bus_npk_2 = npk_brt;
    gauges->eng->emerg_inv_115 = emerg115_brt;
    gauges->eng->gen_fail_1 = gen_1_brt;
    gauges->eng->gen_fail_2 = gen_2_brt;
    gauges->eng->gen_fail_3 = gen_3_brt;
    gauges->eng->bus_connected = bus_con_brt;
    gauges->eng->left_bus_use_bat = left_bat_brt;
    gauges->eng->right_bus_use_bat = right_bat_brt;
    gauges->eng->turn_off_bat_1 = bat_1_brt;
    gauges->eng->turn_off_bat_2 = bat_2_brt;
    gauges->eng->turn_off_bat_3 = bat_3_brt;
    gauges->eng->turn_off_bat_4 = bat_4_brt;
    gauges->eng->vu_on_1 = left_VU_brt;
    gauges->eng->vu_on_2 = right_VU_brt;
    gauges->eng->left_bus_on_tr2 = L_R_brt;
    gauges->eng->right_bus_on_tr1 = R_L_brt;
    gauges->eng->pts250_n1 = pts_1_brt;
    gauges->eng->pts250_n2 = pts_2_brt;
    
}

float sim_start_timer = 0;

void electric_panel(elec_t *elec, swc_t *swc, gauges_t *gauges, lights_t *lights, sim_t *sim, acf_t *acf) {

    /*--print(get(eng1_N1), "  ", get(eng2_N1), "  ", get(eng3_N1))
	
	passed = get(frame_time)
	
	-- reset switchers
	sim_start_timer = sim_start_timer + passed
	if sim_start_timer > 0.3 then 
		if notLoaded then reset_switchers() end
	
		swichers_check() -- make them sound
		caps_check() -- make them sound
	end
	voltmetr115()
	ampermeter115()
	voltmeter36()
	bus27_gaug()
	lamps()
	
	-- set sim avionics
	if get(bus27_volt_left) > 13 or get(bus27_volt_right) > 13 then
		set(sim_avionics, 1)
	else
		set(sim_avionics, 0)
	end
	*/

    passed = acf->frame_time;

    sim_start_timer += passed;

    if (sim_start_timer > 0.3) {
        if (not_loaded) {
            reset_switchers(elec, swc, sim);
        }

        switchers_check();
        caps_check(elec, swc, gauges, lights, sim, acf);
    }

    voltmeter115(elec, swc, gauges, lights, sim, acf);
    ammmeter115(elec, swc, gauges, lights, sim, acf);
    voltmeter36(elec, swc, gauges, lights, sim, acf);
    bus27_gauge(elec, swc, gauges, lights, sim, acf);
    lamps(elec, swc, gauges, lights, sim, acf);

    if (elec->bus27_volt_left > 13 || elec->bus27_volt_right > 13) {
        sim->avionics_power_on = 1;
    }
    else {
        sim->avionics_power_on = 0;
    }

}