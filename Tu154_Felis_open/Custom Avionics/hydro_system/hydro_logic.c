#include "../but.h"
#include "../swc.h"
#include "../gauges.h"
#include "../electric_system/elec.h"
#include "hydro.h"
#include "../failures.h"
#include "../brake_system/brake.h"
#include "../controls/controls.h"
#include "../main_panel/absu/absu.h"
#include "../acf.h"
#include "../sim.h"
#include <math.h>

/*
Setting defaults

set(system_qty_1, 58)
set(system_qty_2, 58)
set(system_qty_3, 45)

set(gs_press_1, 210)
set(gs_press_2, 210)
set(gs_press_3, 210)
set(gs_press_4, 210)
*/
/*
-- controls
defineProperty("accum_fill", globalPropertyi("sim/custom/buttons/hydro/accum_fill")) -- зарядка аккумулятора

defineProperty("connect2to1", globalPropertyi("sim/custom/switchers/hydro/connect2to1")) -- подключение 2 ГС на 1 ГС
defineProperty("pump_2", globalPropertyi("sim/custom/switchers/hydro/pump_2")) -- включение НС 2
defineProperty("pump_3", globalPropertyi("sim/custom/switchers/hydro/pump_3")) -- включение НС3

-- sources
defineProperty("rpm_high_1", globalPropertyf("sim/custom/gauges/engine/rpm_high_1")) -- обороты турбины высокого давления №1
defineProperty("rpm_high_2", globalPropertyf("sim/custom/gauges/engine/rpm_high_2")) -- обороты турбины высокого давления №2
defineProperty("rpm_high_3", globalPropertyf("sim/custom/gauges/engine/rpm_high_3")) -- обороты турбины высокого давления №3

defineProperty("bus115_1_volt", globalPropertyf("sim/custom/elec/bus115_1_volt"))
defineProperty("bus115_3_volt", globalPropertyf("sim/custom/elec/bus115_3_volt"))

defineProperty("bus27_volt_left", globalPropertyf("sim/custom/elec/bus27_volt_left")) -- напряжение сети 27
defineProperty("bus27_volt_right", globalPropertyf("sim/custom/elec/bus27_volt_right")) -- напряжение сети 27

-- results
defineProperty("gs_press_1", globalPropertyf("sim/custom/hydro/gs_press_1")) -- давление в ГС1
defineProperty("gs_press_2", globalPropertyf("sim/custom/hydro/gs_press_2")) -- давление в ГС2
defineProperty("gs_press_3", globalPropertyf("sim/custom/hydro/gs_press_3")) -- давление в ГС3
defineProperty("gs_press_4", globalPropertyf("sim/custom/hydro/gs_press_4")) -- давление в ГС4

defineProperty("bak_qty_1", globalPropertyf("sim/custom/hydro/gs_bak_qty_1")) -- остаток масла в баке
defineProperty("bak_qty_2", globalPropertyf("sim/custom/hydro/gs_bak_qty_2")) -- остаток масла в баке
defineProperty("bak_qty_3", globalPropertyf("sim/custom/hydro/gs_bak_qty_3")) -- остаток масла в баке


defineProperty("system_qty_1", globalPropertyf("sim/custom/hydro/gs_qty_1")) -- остаток масла в системе
defineProperty("system_qty_2", globalPropertyf("sim/custom/hydro/gs_qty_2")) -- остаток масла в системе
defineProperty("system_qty_3", globalPropertyf("sim/custom/hydro/gs_qty_3")) -- остаток масла в системе


defineProperty("gs_qty_12_show", globalPropertyf("sim/custom/hydro/gs_qty_12_show")) -- остаток масла в гидробаке
defineProperty("gs_qty_3_show", globalPropertyf("sim/custom/hydro/gs_qty_3_show")) -- остаток масла в гидробаке


-- failures
defineProperty("hs_leak_1", globalPropertyi("sim/custom/failures/hydro_leak_1")) -- leak
defineProperty("hs_leak_2", globalPropertyi("sim/custom/failures/hydro_leak_2")) -- leak
defineProperty("hs_leak_3", globalPropertyi("sim/custom/failures/hydro_leak_3")) -- leak
defineProperty("hs_leak_4", globalPropertyi("sim/custom/failures/hydro_leak_4")) -- leak

defineProperty("hydro_pump_fail_11", globalPropertyi("sim/custom/failures/hydro_pump_fail_11")) -- fail
defineProperty("hydro_pump_fail_12", globalPropertyi("sim/custom/failures/hydro_pump_fail_12")) -- fail
defineProperty("hydro_pump_fail_2", globalPropertyi("sim/custom/failures/hydro_pump_fail_2")) -- fail
defineProperty("hydro_pump_fail_3", globalPropertyi("sim/custom/failures/hydro_pump_fail_3")) -- fail

defineProperty("hydro_elec_fail_2", globalPropertyi("sim/custom/failures/hydro_elec_fail_2")) -- fail
defineProperty("hydro_elec_fail_3", globalPropertyi("sim/custom/failures/hydro_elec_fail_3")) -- fail



-- time
defineProperty("frame_time", globalPropertyf("sim/custom/time/frame_time")) -- flight time


-- engines
defineProperty("eng1_N1", globalPropertyf("sim/flightmodel/engine/ENGN_N1_[0]")) -- engine 1 rpm
defineProperty("eng2_N1", globalPropertyf("sim/flightmodel/engine/ENGN_N1_[1]")) -- engine 2 rpm
defineProperty("eng3_N1", globalPropertyf("sim/flightmodel/engine/ENGN_N1_[2]")) -- engine 3 rpm

-- users --

-- flaps
defineProperty("flap_inn_L", globalPropertyf("sim/flightmodel/controls/wing1l_fla1def")) -- inner flaps left
defineProperty("flap_inn_R", globalPropertyf("sim/flightmodel/controls/wing1r_fla1def")) -- inner flaps right

-- brakes
defineProperty("l_brake_add", globalPropertyf("sim/custom/brakes/int_brakes_L")) -- реальное положение тормоза
defineProperty("r_brake_add", globalPropertyf("sim/custom/brakes/int_brakes_R")) -- реальное положение тормоза

defineProperty("parkbrake", globalPropertyf("sim/flightmodel/controls/parkbrake")) -- Parking Brake

defineProperty("brake_emerg", globalPropertyf("sim/custom/controlls/brake_emerg")) -- аварийный тормоз
defineProperty("brake_emerg_L", globalPropertyf("sim/custom/controlls/brake_emerg_L")) -- аварийный тормоз
defineProperty("brake_emerg_R", globalPropertyf("sim/custom/controlls/brake_emerg_R")) -- аварийный тормоз

-- absu
defineProperty("absu_contr_pitch", globalPropertyf("sim/custom/absu/contr_pitch")) -- отклонение штока РА56 по тангажу
defineProperty("absu_contr_roll", globalPropertyf("sim/custom/absu/contr_roll")) -- отклонение штока РА56 по крену
defineProperty("absu_contr_yaw", globalPropertyf("sim/custom/absu/contr_yaw")) -- отклонение штока РА56 по направлению

defineProperty("hydro_ra56_rud_1", globalPropertyi("sim/custom/switchers/eng/hydro_ra56_rud_1")) -- гидропитание РА56 курс
defineProperty("hydro_ra56_rud_2", globalPropertyi("sim/custom/switchers/eng/hydro_ra56_rud_2")) -- гидропитание РА56 курс
defineProperty("hydro_ra56_rud_3", globalPropertyi("sim/custom/switchers/eng/hydro_ra56_rud_3")) -- гидропитание РА56 курс

defineProperty("hydro_ra56_ail_1", globalPropertyi("sim/custom/switchers/eng/hydro_ra56_ail_1")) -- гидропитание РА56 крен
defineProperty("hydro_ra56_ail_2", globalPropertyi("sim/custom/switchers/eng/hydro_ra56_ail_2")) -- гидропитание РА56 крен
defineProperty("hydro_ra56_ail_3", globalPropertyi("sim/custom/switchers/eng/hydro_ra56_ail_3")) -- гидропитание РА56 крен

defineProperty("hydro_ra56_elev_1", globalPropertyi("sim/custom/switchers/eng/hydro_ra56_elev_1")) -- гидропитание РА56 тангаж
defineProperty("hydro_ra56_elev_2", globalPropertyi("sim/custom/switchers/eng/hydro_ra56_elev_2")) -- гидропитание РА56 тангаж
defineProperty("hydro_ra56_elev_3", globalPropertyi("sim/custom/switchers/eng/hydro_ra56_elev_3")) -- гидропитание РА56 тангаж


-- ailerons
defineProperty("ail_L", globalPropertyf("sim/flightmodel/controls/wing3l_ail1def")) -- aileron left Degrees, positive is trailing-edge down. +- 20
defineProperty("ail_R", globalPropertyf("sim/flightmodel/controls/wing3r_ail1def")) -- aileron right Degrees, positive is trailing-edge down. +- 20

-- spoilers
defineProperty("spd_brk_inn_L", globalPropertyf("sim/flightmodel/controls/wing1l_spo1def")) -- inner speedbrake left Degrees
defineProperty("spd_brk_inn_R", globalPropertyf("sim/flightmodel/controls/wing1r_spo1def")) -- inner speedbrake right Degrees

defineProperty("spd_brk_mid_L", globalPropertyf("sim/flightmodel/controls/wing2l_spo2def")) -- middle speedbrake left Degrees
defineProperty("spd_brk_mid_R", globalPropertyf("sim/flightmodel/controls/wing2r_spo2def")) -- middle speedbrake right Degrees

-- tail
defineProperty("elevator_L", globalPropertyf("sim/flightmodel/controls/hstab1_elv1def")) -- Degrees, positive is trailing-edge down.
defineProperty("elevator_R", globalPropertyf("sim/flightmodel/controls/hstab2_elv1def")) -- Degrees, positive is trailing-edge down.
defineProperty("rudder", globalPropertyf("sim/flightmodel/controls/vstab2_rud1def")) -- degrees, positive is trailing-edge left

-- gear
defineProperty("gear1_deploy", globalPropertyf("sim/aircraft/parts/acf_gear_deploy[0]"))  -- deploy of front gear
defineProperty("gear2_deploy", globalPropertyf("sim/aircraft/parts/acf_gear_deploy[1]"))  -- deploy of right gear
defineProperty("gear3_deploy", globalPropertyf("sim/aircraft/parts/acf_gear_deploy[2]"))  -- deploy of left gear

defineProperty("gears_retr_lock", globalPropertyi("sim/custom/switchers/gears_retr_lock")) -- блокировка уборки шасси
defineProperty("gears_ext_3GS", globalPropertyi("sim/custom/switchers/gears_ext_3GS")) -- выпуск шасси от 3ГС
defineProperty("emerg_gear_ext", globalPropertyi("sim/custom/controll/emerg_gear_ext")) -- ручка аварийного выпуска шасси
defineProperty("gear_lever", globalPropertyi("sim/custom/controll/gear_lever")) -- ручка выпуска шасси. -1 - уборка, 0 - нейтр, +1 - выпуск





-- busters
defineProperty("buster_on_1", globalPropertyi("sim/custom/switchers/console/buster_on_1")) -- выключатель бустера
defineProperty("buster_on_2", globalPropertyi("sim/custom/switchers/console/buster_on_2")) -- выключатель бустера
defineProperty("buster_on_3", globalPropertyi("sim/custom/switchers/console/buster_on_3")) -- выключатель бустера

-- currents
defineProperty("gs_pump_2_cc", globalPropertyf("sim/custom/hydro/gs_pump_2_cc")) -- ток насосной станции
defineProperty("gs_pump_3_cc", globalPropertyf("sim/custom/hydro/gs_pump_3_cc")) -- ток насосной станции







-- Smart Copilot
defineProperty("ismaster", globalPropertyf("scp/api/ismaster")) -- Master. 0 = plugin not found, 1 = slave 2 = master
defineProperty("hascontrol_1", globalPropertyf("scp/api/hascontrol_1")) -- Have control. 0 = plugin not found, 1 = no control 2 = has control
*/
int not_loaded = 1;
float sim_start_timer = 0;

void reset_switches(hydro_t* hydro, sim_t* sim) {
    if (sim->ENGN_N1_0 < 5 && sim->ENGN_N1_1 < 5 && sim->ENGN_N1_2 < 5) {
        hydro->gs_press_1 = 0;
        hydro->gs_press_2 = 0;
        hydro->gs_press_3 = 0;
        hydro->gs_press_4 = 0;
    }
    not_loaded = 0;
}

float engine_pumps_t(float n) {
    if (n <= 3.8) return -0.0097165991902835782 * n * n - 0.015708502024290971 * n + 0.9;
    else if (n <= 4.21) return -4.6457607495077538 * n * n + 35.505226530261204 * n - 67.13507559211223;
    else return 0;
}

float electric_pumps_t(float n) {
    if (n <= 3.8) return 0.29994191242180529 - 0.0079088471849866199 * n;
    else if (n <= 4.15) return 2.1157142857142461 - 0.48571428571427577 * n;
    else if (n <= 4.21) return 7.0166666666277786 - 1.6666666666573635 * n;
    else return 0;
}

/*local brakes_L_last = get(l_brake_add)
local brakes_R_last = get(r_brake_add)
--local brakes_last = get(parkbrake)

local brakes_EM_L_last = get(brake_emerg_L)
local brakes_EM_R_last = get(brake_emerg_R)
local brakes_EM_last = get(brake_emerg)

local flap_L_last = get(flap_inn_L)
local flap_R_last = get(flap_inn_R)

local ail_L_last = get(ail_L)
local ail_R_last = get(ail_R)

local spd_brk_L_last = get(spd_brk_mid_L) + get(spd_brk_inn_L)
local spd_brk_R_last = get(spd_brk_mid_R) + get(spd_brk_inn_R)

local elev_last = get(elevator_L) + get(elevator_R)

local rudder_last = get(rudder)

local buster_1_ON = 0
local buster_2_ON = 0
local buster_3_ON = 0

local absu_pitch_last = get(absu_contr_pitch)
local absu_roll_last = get(absu_contr_roll)
local absu_yaw_last = get(absu_contr_yaw)

local gear_pos_1_last = get(gear1_deploy)
local gear_pos_2_last = get(gear2_deploy)
local gear_pos_3_last = get(gear3_deploy)*/

float brakes_L_last = 0;
float brakes_R_last = 0;

float brakes_EM_L_last = 0;
float brakes_EM_R_last = 0;
float brakes_EM_last = 0;

float flap_L_last = 0;
float flap_R_last = 0;

float ail_L_last = 0;
float ail_R_last = 0;

float spd_brk_L_last = 0;
float spd_brk_R_last = 0;

float elev_last = 0;

float rudder_last = 0;

int buster_1_ON = 0;
int buster_2_ON = 0;
int buster_3_ON = 0;

float absu_pitch_last = 0;
float absu_roll_last = 0;
float absu_yaw_last = 0;

float gear_pos_1_last = 0;
float gear_pos_2_last = 0;
float gear_pos_3_last = 0;

float passed = 0;

void hydro_logic(swc_t* swc, but_t* but, gauges_t* gauges, hydro_t* hydro, sim_t* sim, elec_t* elec, failures_t* failures, brake_t* brake, controls_t* controls, absu_t* absu, acf_t* acf) {

/*-- reset some variables for cold start
	sim_start_timer = sim_start_timer + passed
	if sim_start_timer > 0.3 then 
		if notLoaded then reset_switchers() end
	end
	
	
	
	-- calculate oil amount
	local sys_qty_1 = get(system_qty_1)
	local sys_qty_2 = get(system_qty_2)
	local sys_qty_3 = get(system_qty_3)
	
	-- calculate amount of oil in accums
	local acc_1 = get(gs_press_1) * 0.02
	local acc_2 = get(gs_press_2) * 0.02
	local acc_3 = get(gs_press_3) * 0.02
	local acc_4 = get(gs_press_4) * 0.02
	
	
	-- calculate amount in barrels. barrel = whole system - pipes - accums
	local hs1_qty = sys_qty_1 - 34 - acc_1 - acc_4/2 -- quantity of oil
	local hs2_qty = sys_qty_2 - 34 - acc_2 - acc_4/2 -- quantity of oil
	local hs3_qty = sys_qty_3 - 21 - acc_3 -- quantity of oil
	
	-- limit zero amount in barrels
	if hs1_qty < 0 then hs1_qty = 0 end
	if hs2_qty < 0 then hs2_qty = 0 end
	if hs3_qty < 0 then hs3_qty = 0 end
	
	
	-- cross-feed in bak 1 and bak 2
	if (hs1_qty > 12 or hs2_qty > 12) and math.abs(hs1_qty - hs2_qty) > 0.001 then
		local flow = (hs2_qty - hs1_qty) * passed * 5
		
		hs1_qty = hs1_qty + flow
		hs2_qty = hs2_qty - flow
	end
	
	
	-- check power
	local power27L = get(bus27_volt_left) > 13
	local power27R = get(bus27_volt_right) > 13
	
	local power115_1 = get(bus115_1_volt) > 110
	local power115_3 = get(bus115_3_volt) > 110


	
	-- gain pressure from engine pumps
	local RPM_1 = get(rpm_high_1)
	local RPM_2 = get(rpm_high_2)
	local RPM_3 = get(rpm_high_3)
	local eng_pump_1_1 = math.min (1, RPM_1 * 0.02) * (1 - get(hydro_pump_fail_11))
	local eng_pump_1_2 = math.min (1, RPM_2 * 0.02) * (1 - get(hydro_pump_fail_12))
	local eng_pump_2 = math.min (1, RPM_2 * 0.02) * (1 - get(hydro_pump_fail_2))
	local eng_pump_3 = math.min (1, RPM_3 * 0.02) * (1 - get(hydro_pump_fail_3))	

	-- pump oil from storage to accums
	if hs1_qty > 0 then 
		local flow = (eng_pump_1_1 + eng_pump_1_2) * interpolate(engine_pumps_t, acc_1) * passed
		acc_1 = acc_1 + flow 
		hs1_qty = hs1_qty - flow
	end	

	if hs2_qty > 0 then 
		local flow = eng_pump_2 * interpolate(engine_pumps_t, acc_2) * passed
		acc_2 = acc_2 + flow 
		hs2_qty = hs2_qty - flow
	end

	if hs3_qty > 0 then 
		local flow = eng_pump_3 * interpolate(engine_pumps_t, acc_3) * passed
		acc_3 = acc_3 + flow
		hs3_qty = hs3_qty - flow
	end	

	-- gain pressure from electrical pumps
	local elec_pump_2 = bool2int(power115_1 and power27L and get(pump_2) == 1 and get(hydro_elec_fail_2) == 0)
	local elec_pump_3 = bool2int(power115_3 and power27R and get(pump_3) == 1 and get(hydro_elec_fail_3) == 0)
	
	if hs2_qty > 0 then 
		local flow = elec_pump_2 * interpolate(electric_pumps_t, acc_2) * passed 
		acc_2 = acc_2 + flow
		hs2_qty = hs2_qty - flow
	end
	if hs3_qty > 0 then 
		local flow = elec_pump_3 * interpolate(electric_pumps_t, acc_3) * passed 
		acc_3 = acc_3 + flow
		hs3_qty = hs3_qty - flow
	end
	
	local pump2_current = elec_pump_2 * (32 + interpolate(electric_pumps_t, acc_2 * 50) * 0.15)
	local pump3_current = elec_pump_3 * (32 + interpolate(electric_pumps_t, acc_3 * 50) * 0.15)
	

	-- charge the accumulator for emergency brakes
	if get(accum_fill) == 1 and acc_4 < acc_1 and power27L then
		local flow = (acc_1 - acc_4)
		if flow > 2 then flow = 2 end
		
		acc_1 = acc_1 - flow * passed
		acc_4 = acc_4 + flow * passed
	end

	-- connect HS 1 and HS2
	if get(connect2to1) == 1 and power27L and acc_2 > acc_1 then
		local flow = acc_2 - acc_1
		if flow > 2 then flow = 2 end
		
		acc_1 = acc_1 + flow * passed
		acc_2 = acc_2 - flow * passed
	end

	




	
	
	
	-- internal leak
	-- HS1 leaks down to 120 (2.4) for one hour
	-- HS2 leaks down to 130 (2.6) for one hour
	-- HS3 leaks down to 190 (3.8) for one hour
	-- HS4 leaks down to 190 (3.8) for one hour
	
	if acc_1 > 0.1 then
		local flow = passed * acc_1 * 0.00008
		acc_1 = acc_1 - flow
		hs1_qty = hs1_qty + flow
	end

	if acc_2 > 0.1 then
		local flow = passed * acc_2 * 0.000074
		acc_2 = acc_2 - flow
		hs2_qty = hs2_qty + flow
	end	
	
	if acc_3 > 0.1 then
		local flow = passed * acc_3 * 0.000014
		acc_3 = acc_3 - flow
		hs3_qty = hs3_qty + flow
	end	
	
	if acc_4 > 0.1 then
		local flow = passed * acc_4 * 0.000014
		acc_4 = acc_4 - flow
		hs1_qty = hs1_qty + flow
	end		



	
	-- check leak failure
	local high_leak_1 = get(hs_leak_1)
	local high_leak_2 = get(hs_leak_2)
	local high_leak_3 = get(hs_leak_3)
	local high_leak_4 = get(hs_leak_4)
	
	acc_1 = acc_1 - high_leak_1 * acc_1 * passed * 0.05
	acc_2 = acc_2 - high_leak_2 * acc_2 * passed * 0.05
	acc_3 = acc_3 - high_leak_3 * acc_3 * passed * 0.05
	acc_4 = acc_4 - high_leak_4 * acc_4 * passed * 0.05
	

	-- для каждого потребителя давления нужно прописывать перекачку масла из аккумуляторов обратно в баки
	-- кроме утечек :)
	
	-- brakes --
	-- takes 0.04 l for full brake for each gear
	local brakes_L = get(l_brake_add)
	local brakes_R = get(r_brake_add)
	--local brakes = get(parkbrake)
	
	local main_brakes_feed = (math.max(brakes_L - brakes_L_last, 0) + math.max(brakes_R - brakes_R_last, 0)) * 0.04
	
	brakes_L_last = brakes_L
	brakes_R_last = brakes_R
	--brakes_last = brakes
	
	if acc_1 > 0 and main_brakes_feed > 0 then 
		acc_1 = acc_1 - main_brakes_feed -- take oil from HS1
		hs1_qty = hs1_qty + main_brakes_feed -- return it to barrel
	end
	
	-- emergency brakes
	local brakes_EM_L = get(brake_emerg_L)
	local brakes_EM_R = get(brake_emerg_R)
	local brakes_EM = get(brake_emerg)
	
	--local EM_brakes_feed = (brakes_EM_L - brakes_EM_L_last + brakes_EM_R - brakes_EM_R_last + brakes_EM - brakes_EM_last) * 0.04 * passed
	local EM_brakes_feed = (brakes_EM - brakes_EM_last) * 0.04
	
	brakes_EM_L_last = brakes_EM_L
	brakes_EM_R_last = brakes_EM_R
	brakes_EM_last = brakes_EM
	
	if acc_4 > 0 and EM_brakes_feed > 0 then 
		acc_4 = acc_4 - EM_brakes_feed -- take oil from HS4
		hs1_qty = hs1_qty + EM_brakes_feed -- return it to barrel
	end	
	
	
	
	
	------
	-- flaps
	local flap_L_now = get(flap_inn_L)
	local flap_R_now = get(flap_inn_R)	
	
	local flaps_feed = math.abs(flap_L_now - flap_L_last + flap_R_now - flap_R_last) * 0.01

	
	flap_L_last = flap_L_now
	flap_R_last = flap_R_now
	

	-- flight controls
	-- set busters work status
	if power27L then
		buster_1_ON = get(buster_on_1)
		buster_2_ON = get(buster_on_2)
	end
	
	if power27R then
		buster_3_ON = get(buster_on_3)
	end



	local ail_L_now = get(ail_L)
	local ail_R_now = get(ail_R)

	local spd_brk_L_now = get(spd_brk_mid_L) + get(spd_brk_inn_L)
	local spd_brk_R_now = get(spd_brk_mid_R) + get(spd_brk_inn_R)

	local elev_now = get(elevator_L) + get(elevator_R)

	local rudder_now = get(rudder)	
	
	local ailerons_feed = (math.abs(ail_L_now - ail_L_last) + math.abs(ail_R_now - ail_R_last)) * 0.05 * 0.05
	
	local elev_feed = math.abs(elev_now - elev_last) * 0.05 * 0.05
	
	local rudder_feed = math.abs(rudder_now - rudder_last) * 0.05 * 0.05
	
	local sbd_brk_feed = math.abs(spd_brk_L_now - spd_brk_L_last + spd_brk_R_now - spd_brk_R_last) * 0.05 * 0.05
	
	ail_L_last = ail_L_now
	ail_R_last = ail_R_now
	
	elev_last = elev_now
	rudder_last = rudder_now
	
	spd_brk_L_last = spd_brk_L_now
	spd_brk_R_last = spd_brk_R_now

	
	if acc_1 > 0 then
		local flow = (ailerons_feed + elev_feed + rudder_feed) * buster_1_ON + sbd_brk_feed + flaps_feed
		acc_1 = acc_1 - flow -- take oil from HS1
		hs1_qty = hs1_qty + flow -- return it to barrel		
	end
	
	if acc_2 > 0 then
		local flow = (ailerons_feed + elev_feed + rudder_feed) * buster_2_ON + flaps_feed
		acc_2 = acc_2 - flow -- take oil from HS2
		hs2_qty = hs2_qty + flow -- return it to barrel
	end		
	if acc_3 > 0 then
		local flow = (ailerons_feed + elev_feed + rudder_feed) * buster_3_ON
		acc_3 = acc_3 - flow -- take oil from HS3
		hs3_qty = hs3_qty + flow -- return it to barrel
	end		
	
	

	-- ABSU
	local absu_pitch_feed = math.abs(get(absu_contr_pitch) - absu_pitch_last) * 0.01
	local absu_roll_feed = math.abs(get(absu_contr_roll) - absu_roll_last) * 0.01
	local absu_yaw_feed = math.abs(get(absu_contr_yaw) - absu_yaw_last) * 0.01
	
	absu_pitch_last = get(absu_contr_pitch)
	absu_roll_last = get(absu_contr_roll)
	absu_yaw_last = get(absu_contr_yaw)
	
	if acc_1 > 0 then
		local flow = absu_pitch_feed * get(hydro_ra56_elev_1) + absu_roll_feed * get(hydro_ra56_ail_1) + absu_yaw_feed * get(hydro_ra56_rud_1)
		acc_1 = acc_1 - flow -- take oil from HS1
		hs1_qty = hs1_qty + flow -- return it to barrel		
	end
	
	if acc_2 > 0 then
		local flow = absu_pitch_feed * get(hydro_ra56_elev_2) + absu_roll_feed * get(hydro_ra56_ail_2) + absu_yaw_feed * get(hydro_ra56_rud_2)
		acc_2 = acc_2 - flow -- take oil from HS2
		hs2_qty = hs2_qty + flow -- return it to barrel
	end		
	if acc_3 > 0 then
		local flow = absu_pitch_feed * get(hydro_ra56_elev_3) + absu_roll_feed * get(hydro_ra56_ail_3) + absu_yaw_feed * get(hydro_ra56_rud_3)
		acc_3 = acc_3 - flow -- take oil from HS3
		hs3_qty = hs3_qty + flow -- return it to barrel
	end		
	

	-- gears
	local gear_feed_1 = math.abs(get(gear1_deploy) - gear_pos_1_last) * 8 / 2.5
	local gear_feed_2 = math.abs(get(gear2_deploy) - gear_pos_2_last) * 17 / 2.5
	local gear_feed_3 = math.abs(get(gear3_deploy) - gear_pos_3_last) * 17 / 2.5
	
	gear_pos_1_last = get(gear1_deploy)
	gear_pos_2_last = get(gear2_deploy)
	gear_pos_3_last = get(gear3_deploy)
	
	-- normal operation
	if acc_1 > 0 and get(gears_ext_3GS) == 0 and get(emerg_gear_ext) == 0 then
		acc_1 = acc_1 - gear_feed_1 - gear_feed_2 - gear_feed_3 -- take oil from HS1
		hs1_qty = hs1_qty + gear_feed_1 + gear_feed_2 + gear_feed_3 -- return it to barrel	
	end
	
	-- emerg operation
	if acc_2 > 0 and get(emerg_gear_ext) == 1 then
		acc_2 = acc_2 - gear_feed_1 - gear_feed_2 - gear_feed_3 -- take oil from HS2
		hs2_qty = hs2_qty + gear_feed_1 + gear_feed_2 + gear_feed_3 -- return it to barrel	
	end
	
	-- 3'd HS operation
	if acc_3 > 0 and get(gears_ext_3GS) == 1 and get(emerg_gear_ext) == 0 then
		acc_3 = acc_3 - gear_feed_1 - gear_feed_2 - gear_feed_3 -- take oil from HS3
		hs3_qty = hs3_qty + gear_feed_1 + gear_feed_2 + gear_feed_3 -- return it to barrel	
	end
	
	
	
	
	
	-- set results
	set(gs_press_1, acc_1 * 50)
	set(gs_press_2, acc_2 * 50)
	set(gs_press_3, acc_3 * 50)
	set(gs_press_4, acc_4 * 50)
	
	set(bak_qty_1, hs1_qty)
	set(bak_qty_2, hs2_qty)
	set(bak_qty_3, hs3_qty)	
	
	-- whole system = barrel + pipes + accums
	set(system_qty_1, hs1_qty + 34 + acc_1 + acc_4/2)
	set(system_qty_2, hs2_qty + 34 + acc_2 + acc_4/2)
	set(system_qty_3, hs3_qty + 21 + acc_3)
	

	set(gs_qty_12_show, hs1_qty * 2)
	set(gs_qty_3_show, hs3_qty)	
	
	set(gs_pump_2_cc, pump2_current)
	set(gs_pump_3_cc, pump3_current)	
	*/
    passed = acf->frame_time - sim_start_timer;

    sim_start_timer += passed;

    if (sim_start_timer > 0.3 && not_loaded) {
        reset_switches(hydro, sim);
    }

    float sys_qty_1 = hydro->gs_qty_1;
    float sys_qty_2 = hydro->gs_qty_2;
    float sys_qty_3 = hydro->gs_qty_3;

    float acc_1 = hydro->gs_press_1 * 0.02;
    float acc_2 = hydro->gs_press_2 * 0.02;
    float acc_3 = hydro->gs_press_3 * 0.02;
    float acc_4 = hydro->gs_press_4 * 0.02;

    float hs1_qty = sys_qty_1 - 34 - acc_1 - acc_4 / 2;
    float hs2_qty = sys_qty_2 - 34 - acc_2 - acc_4 / 2;
    float hs3_qty = sys_qty_3 - 21 - acc_3;

    if (hs1_qty < 0) hs1_qty = 0;
    if (hs2_qty < 0) hs2_qty = 0;
    if (hs3_qty < 0) hs3_qty = 0;

    if ((hs1_qty > 12 || hs2_qty > 12) && fabs(hs1_qty - hs2_qty) > 0.001) {
        float flow = (hs2_qty - hs1_qty) * passed * 5;

        hs1_qty += flow;
        hs2_qty -= flow;
    }

    int power27L = elec->bus27_volt_left > 13;
    int power27R = elec->bus27_volt_right > 13;

    int power115_1 = elec->bus115_1_volt > 110;
    int power115_3 = elec->bus115_3_volt > 110;

    float RPM_1 = gauges->eng->rpm_high_1;
    float RPM_2 = gauges->eng->rpm_high_2;
    float RPM_3 = gauges->eng->rpm_high_3;

    float eng_pump_1_1 = fmin(1, RPM_1 * 0.02) * (1 - failures->hydro_pump_fail_11);
    float eng_pump_1_2 = fmin(1, RPM_2 * 0.02) * (1 - failures->hydro_pump_fail_12);
    float eng_pump_2 = fmin(1, RPM_2 * 0.02) * (1 - failures->hydro_pump_fail_2);
    float eng_pump_3 = fmin(1, RPM_3 * 0.02) * (1 - failures->hydro_pump_fail_3);

    if (hs1_qty > 0) {
        float flow = (eng_pump_1_1 + eng_pump_1_2) * engine_pumps_t(acc_1) * passed;
        acc_1 += flow;
        hs1_qty -= flow;
    }

    if (hs2_qty > 0) {
        float flow = eng_pump_2 * engine_pumps_t(acc_2) * passed;
        acc_2 += flow;
        hs2_qty -= flow;
    }

    if (hs3_qty > 0) {
        float flow = eng_pump_3 * engine_pumps_t(acc_3) * passed;
        acc_3 += flow;
        hs3_qty -= flow;
    }

    int elec_pump_2 = power115_1 && power27L && swc->hydro->pump_2 == 1 && failures->hydro_elec_fail_2 == 0;
    int elec_pump_3 = power115_3 && power27R && swc->hydro->pump_3 == 1 && failures->hydro_elec_fail_3 == 0;

    if (hs2_qty > 0) {
        float flow = elec_pump_2 * electric_pumps_t(acc_2) * passed;
        acc_2 += flow;
        hs2_qty -= flow;
    }

    if (hs3_qty > 0) {
        float flow = elec_pump_3 * electric_pumps_t(acc_3) * passed;
        acc_3 += flow;
        hs3_qty -= flow;
    }

    float pump2_current = elec_pump_2 * (32 + electric_pumps_t(acc_2 * 50) * 0.15);
    float pump3_current = elec_pump_3 * (32 + electric_pumps_t(acc_3 * 50) * 0.15);

    if (but->hydro->accum_fill == 1 && acc_4 < acc_1 && power27L) {
        float flow = (acc_1 - acc_4);
        if (flow > 2) flow = 2;

        acc_1 -= flow * passed;
        acc_4 += flow * passed;
    }

    if (swc->hydro->connect2to1 == 1 && power27L && acc_2 > acc_1) {
        float flow = acc_2 - acc_1;
        if (flow > 2) flow = 2;

        acc_1 += flow * passed;
        acc_2 -= flow * passed;
    }

    if (acc_1 > 0.1) {
        float flow = passed * acc_1 * 0.00008;
        acc_1 -= flow;
        hs1_qty += flow;
    }

    if (acc_2 > 0.1) {
        float flow = passed * acc_2 * 0.000074;
        acc_2 -= flow;
        hs2_qty += flow;
    }

    if (acc_3 > 0.1) {
        float flow = passed * acc_3 * 0.000014;
        acc_3 -= flow;
        hs3_qty += flow;
    }

    if (acc_4 > 0.1) {
        float flow = passed * acc_4 * 0.000014;
        acc_4 -= flow;
        hs1_qty += flow;
    }


    float high_leak_1 = failures->hydro_leak_1;
    float high_leak_2 = failures->hydro_leak_2;
    float high_leak_3 = failures->hydro_leak_3;
    float high_leak_4 = failures->hydro_leak_4;

    acc_1 -= high_leak_1 * acc_1 * passed * 0.05;   
    acc_2 -= high_leak_2 * acc_2 * passed * 0.05;
    acc_3 -= high_leak_3 * acc_3 * passed * 0.05;
    acc_4 -= high_leak_4 * acc_4 * passed * 0.05;

    float brakes_L = brake->int_brakes_L;
    float brakes_R = brake->int_brakes_R;

    float main_brakes_feed = (fmax(brakes_L - brakes_L_last, 0) + fmax(brakes_R - brakes_R_last, 0)) * 0.04;

    brakes_L_last = brakes_L;
    brakes_R_last = brakes_R;

    if (acc_1 > 0 && main_brakes_feed > 0) {
        acc_1 -= main_brakes_feed;
        hs1_qty += main_brakes_feed;
    }

    float brakes_EM_L = controls->brake_emerg_L;
    float brakes_EM_R = controls->brake_emerg_R;
    float brakes_EM = controls->brake_emerg;

    float EM_brakes_feed = (brakes_EM - brakes_EM_last) * 0.04;

    brakes_EM_L_last = brakes_EM_L;
    brakes_EM_R_last = brakes_EM_R;
    brakes_EM_last = brakes_EM;

    if (acc_4 > 0 && EM_brakes_feed > 0) {
        acc_4 -= EM_brakes_feed;
        hs1_qty += EM_brakes_feed;
    }

    float flap_L_now = sim->wing1l_fla1def;
    float flap_R_now = sim->wing1r_fla1def;

    float flaps_feed = fabs(flap_L_now - flap_L_last + flap_R_now - flap_R_last) * 0.01;

    flap_L_last = flap_L_now;
    flap_R_last = flap_R_now;

    if (power27L) {
        buster_1_ON = but->console->buster_on_1;
        buster_2_ON = but->console->buster_on_2;
    }

    if (power27R) {
        buster_3_ON = but->console->buster_on_3;
    }

    float ail_L_now = sim->wing3l_ail1def;
    float ail_R_now = sim->wing3r_ail1def;

    float spd_brk_L_now = sim->wing1l_spo1def + sim->wing2l_spo2def;
    float spd_brk_R_now = sim->wing1r_spo1def + sim->wing2r_spo2def;

    float elev_now = sim->hstab1_elv1def + sim->hstab2_elv1def;

    float rudder_now = sim->vstab2_rud1def;

    float ailerons_feed = (fabs(ail_L_now - ail_L_last) + fabs(ail_R_now - ail_R_last)) * 0.05 * 0.05;

    float elev_feed = fabs(elev_now - elev_last) * 0.05 * 0.05;

    float rudder_feed = fabs(rudder_now - rudder_last) * 0.05 * 0.05;

    float sbd_brk_feed = fabs(spd_brk_L_now - spd_brk_L_last + spd_brk_R_now - spd_brk_R_last) * 0.05 * 0.05;

    ail_L_last = ail_L_now;
    ail_R_last = ail_R_now;

    elev_last = elev_now;
    rudder_last = rudder_now;

    spd_brk_L_last = spd_brk_L_now;
    spd_brk_R_last = spd_brk_R_now;

    if (acc_1 > 0) {
        float flow = (ailerons_feed + elev_feed + rudder_feed) * buster_1_ON + sbd_brk_feed + flaps_feed;
        acc_1 -= flow;
        hs1_qty += flow;
    }

    if (acc_2 > 0) {
        float flow = (ailerons_feed + elev_feed + rudder_feed) * buster_2_ON + flaps_feed;
        acc_2 -= flow;
        hs2_qty += flow;
    }

    if (acc_3 > 0) {
        float flow = (ailerons_feed + elev_feed + rudder_feed) * buster_3_ON;
        acc_3 -= flow;
        hs3_qty += flow;
    }

    float absu_pitch_feed = fabs(absu->contr_pitch - absu_pitch_last) * 0.01;
    float absu_roll_feed = fabs(absu->contr_roll - absu_roll_last) * 0.01;
    float absu_yaw_feed = fabs(absu->contr_yaw - absu_yaw_last) * 0.01;

    absu_pitch_last = absu->contr_pitch;
    absu_roll_last = absu->contr_roll;
    absu_yaw_last = absu->contr_yaw;

    if (acc_1 > 0) {
        float flow = absu_pitch_feed * swc->hydro->hydro_ra56_elev_1 + absu_roll_feed * swc->hydro->hydro_ra56_ail_1 + absu_yaw_feed * swc->hydro->hydro_ra56_rud_1;
        acc_1 -= flow;
        hs1_qty += flow;
    }

    if (acc_2 > 0) {
        float flow = absu_pitch_feed * swc->hydro->hydro_ra56_elev_2 + absu_roll_feed * swc->hydro->hydro_ra56_ail_2 + absu_yaw_feed * swc->hydro->hydro_ra56_rud_2;
        acc_2 -= flow;
        hs2_qty += flow;
    }

    if (acc_3 > 0) {
        float flow = absu_pitch_feed * swc->hydro->hydro_ra56_elev_3 + absu_roll_feed * swc->hydro->hydro_ra56_ail_3 + absu_yaw_feed * swc->hydro->hydro_ra56_rud_3;
        acc_3 -= flow;
        hs3_qty += flow;
    }

    float gear_feed_1 = fabs(sim->acf_gear_deploy0 - gear_pos_1_last) * 8 / 2.5;
    float gear_feed_2 = fabs(sim->acf_gear_deploy1 - gear_pos_2_last) * 17 / 2.5;
    float gear_feed_3 = fabs(sim->acf_gear_deploy2 - gear_pos_3_last) * 17 / 2.5;

    gear_pos_1_last = sim->acf_gear_deploy0;
    gear_pos_2_last = sim->acf_gear_deploy1;
    gear_pos_3_last = sim->acf_gear_deploy2;

    if (acc_1 > 0 && swc->gears_ext_3GS == 0 && controls->emerg_gear_ext == 0) {
        acc_1 -= gear_feed_1 + gear_feed_2 + gear_feed_3;
        hs1_qty += gear_feed_1 + gear_feed_2 + gear_feed_3;
    }
    
    if (acc_2 > 0 && controls->emerg_gear_ext == 1) {
        acc_2 -= gear_feed_1 + gear_feed_2 + gear_feed_3;
        hs2_qty += gear_feed_1 + gear_feed_2 + gear_feed_3;
    }

    if (acc_3 > 0 && swc->gears_ext_3GS == 1 && controls->emerg_gear_ext == 0) {
        acc_3 -= gear_feed_1 + gear_feed_2 + gear_feed_3;
        hs3_qty += gear_feed_1 + gear_feed_2 + gear_feed_3;
    }

    hydro->gs_press_1 = acc_1 * 50;
    hydro->gs_press_2 = acc_2 * 50;
    hydro->gs_press_3 = acc_3 * 50;
    hydro->gs_press_4 = acc_4 * 50;

    hydro->gs_bak_qty_1 = hs1_qty;
    hydro->gs_bak_qty_2 = hs2_qty;
    hydro->gs_bak_qty_3 = hs3_qty;

    hydro->gs_qty_1 = hs1_qty + 34 + acc_1 + acc_4 / 2;
    hydro->gs_qty_2 = hs2_qty + 34 + acc_2 + acc_4 / 2;
    hydro->gs_qty_3 = hs3_qty + 21 + acc_3;

    hydro->gs_qty_12_show = hs1_qty * 2;
    hydro->gs_qty_3_show = hs3_qty;

    hydro->gs_pump_2_cc = pump2_current;
    hydro->gs_pump_3_cc = pump3_current;

}





