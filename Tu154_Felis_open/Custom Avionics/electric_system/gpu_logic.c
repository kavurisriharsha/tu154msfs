#include "elec.h"
#include "../swc.h"
#include "../sim.h" 
#include "../acf.h"
#include "../animation/anim.h"

/*local work_timer = 0
local last_dist = 0


local gpu_connect_timer = 0

local gpuSoundsLoaded = true

local gpu_eject_timer = 0
*/

int work_timer = 0;
int last_dist = 0;

int gpu_connect_timer = 0;

int gpu_eject_timer = 0;

void gpu_update(anim_t* anim, elec_t* elec, swc_t* swc, sim_t* sim, acf_t* acf) {

    /*local passed = get(frame_time)
	local external = get(external_view) -- 0 = inside, 1 = external
	
	-- check if GPU can be conected
	local present = get(gpu_present)
	if math.abs(get(GS)) > 0.1 then
		gpu_eject_timer = gpu_eject_timer + passed
	else
		gpu_eject_timer = 0
	end
	
	
	if gpu_eject_timer < 1 then
	
		if present == 1 then 
			work_timer = work_timer + passed * 0.25 -- 3 sec for start
		else 
			work_timer = work_timer - passed * 0.1 -- 10 sec for stop
			set(gpu_overload, 0) -- reset overload flag
		end
		-- set limits and working parameters
		if work_timer > 1 then 
			work_timer = 1
			if get(DC_27_volt1) > 13 or get(DC_27_volt2) > 13 then 
				set(gpu_volt, 115 * (1 - get(gpu_overload)))
			else
				set(gpu_volt, 0)
			end
		elseif work_timer < 0 then 
			work_timer = 0
			set(gpu_volt, 0)
		elseif work_timer < 0.9 then 
			set(gpu_volt, 0)
		end
		set(gpu_work_anim, work_timer) -- set animation
		
		-- connect GPU to the bus
		if get(gpu_on) == 1 then 
			gpu_connect_timer = gpu_connect_timer + passed
			if gpu_connect_timer >= 1 then
				if work_timer == 1 and get(gpu_overload) ~= 1 then set(gpu_work_bus, 1) 
				else set(gpu_work_bus, 0) end
				gpu_connect_timer = 1
			else
				set(gpu_work_bus, 0) 
			end
			
			
		else 
			set(gpu_work_bus, 0) 
			gpu_connect_timer = 0
			
		end
		
		
		
		
		-- set overload flag and reset it when GPU is disconnected
		if get(gpu_amp) > 500 then set(gpu_overload, 1)
		elseif get(gpu_on) == 0 then set(gpu_overload, 0) end


		-- set sounds
		if work_timer > 0 and work_timer < 1 and not isSamplePlaying(gpu_start_out) and present == 1 then
			playSample(gpu_start_out, 0)
			playSample(gpu_start_inn, 0)
			stopSample(gpu_run_out)
			stopSample(gpu_run_inn)
		elseif work_timer == 1 and not isSamplePlaying(gpu_run_out) then
			playSample(gpu_run_out, 1)
			playSample(gpu_run_inn, 1)
		elseif work_timer > 0 and work_timer < 1 and not isSamplePlaying(gpu_stop_out) and present == 0 then
			playSample(gpu_stop_out, 0)
			playSample(gpu_stop_inn, 0)
			stopSample(gpu_start_out)
			stopSample(gpu_run_out)
			stopSample(gpu_start_inn)
			stopSample(gpu_run_inn)
		elseif work_timer == 0 then
			stopSample(gpu_start_out)
			stopSample(gpu_start_inn)
			stopSample(gpu_run_out)
			stopSample(gpu_run_inn)
		end
		
		-- set effects to external GPU sound
		local camera_distance = math.sqrt(((get(view_x)-get(local_x))^2)+((get(view_y)-get(local_y))^2)+((get(view_z)-get(local_z))^2)) -- in meters
		if camera_distance < 1 then camera_distance = 1 end -- limit minimum distance
		
		local dist_coef = 300 / camera_distance ^ 1.7
		if dist_coef > 1 then dist_coef = 1 end
		-- calculate camera/aircraft speed
		local spd_time = math.min(0.0001, passed)
		local camera_spd = -(camera_distance - last_dist) / spd_time
		
		last_dist = camera_distance
		
		local dopp_coef = camera_spd * 0.02
		if dopp_coef > 400 then dopp_coef = 300
		elseif dopp_coef < -300 then dopp_coef = -300 end
		
		local window_open = 0 -- temp
		
		-- set sound volume
		setSampleGain(gpu_start_out, 1000 * (external + window_open * (1 - external)) * dist_coef)
		setSampleGain(gpu_run_out, 1000 * (external + window_open * (1 - external)) * dist_coef)
		setSampleGain(gpu_stop_out, 1000 * (external + window_open * (1 - external)) * dist_coef)

		setSampleGain(gpu_start_inn, 2000 * (1 - external))
		setSampleGain(gpu_run_inn, 2000 * (1 - external))
		setSampleGain(gpu_stop_inn, 2000 * (1 - external))
		--setSampleGain(prop_out_1, prop_loud_1 * (external + window_open * (1 - external)) * N1 * dist_coef) -- example
	
	else
		work_timer = 0
		
		set(gpu_work_anim, 0)
		set(gpu_present, 0)
		set(gpu_volt, 0)
		set(gpu_overload, 0)
		set(gpu_work_bus, 0)
		
		-- unload sounds
		stopSample(gpu_run_out)
		stopSample(gpu_start_out)
		stopSample(gpu_stop_out)
		
		--if gpuSoundsLoaded then unloadSounds() end
	end
	*/

    float passed = acf->frame_time;
    int external = sim->view_is_external; // 0 = inside, 1 = external

    int present = anim->gpu_present;

    if (fabs(sim->groundspeed) > 0.1) {
        gpu_eject_timer += passed;
    } else {
        gpu_eject_timer = 0;
    }

    if (gpu_eject_timer < 1) {

        if (present == 1) {
            work_timer += passed * 0.25;
        } else {
            work_timer -= passed * 0.1;
            elec->gpu_overload = 0;
        }

        if (work_timer > 1) {
            work_timer = 1;
            if (elec->bus27_volt_left > 13 || elec->bus27_volt_right > 13) {
                elec->gpu_volt = 115 * (1 - elec->gpu_overload);
            } else {
                elec->gpu_volt = 0;
            }
        } else if (work_timer < 0) {
            work_timer = 0;
            elec->gpu_volt = 0;
        } else if (work_timer < 0.9) {
            elec->gpu_volt = 0;
        }

        anim->gpu_work = work_timer;

        if (swc->eng->gpu_on == 1) {
            gpu_connect_timer += passed;
            if (gpu_connect_timer >= 1) {
                if (work_timer == 1 && elec->gpu_overload != 1) {
                    elec->gpu_work = 1;
                } else {
                    elec->gpu_work = 0;
                }
                gpu_connect_timer = 1;
            } else {
                elec->gpu_work = 0;
            }
        } else {
            elec->gpu_work = 0;
            gpu_connect_timer = 0;
        }

        if (elec->gpu_amp > 500) {
            elec->gpu_overload = 1;
        } else if (swc->eng->gpu_on == 0) {
            elec->gpu_overload = 0;
        }

        float camera_distance = sqrt(pow(sim->view_x - sim->local_x, 2) + pow(sim->view_y - sim->local_y, 2) + pow(sim->view_z - sim->local_z, 2));

        if (camera_distance < 1) {
            camera_distance = 1;
        }

        float dist_coef = 300 / pow(camera_distance, 1.7);
        if (dist_coef > 1) {
            dist_coef = 1;
        }

        float spd_time = fmin(0.0001, passed);
        float camera_spd = -(camera_distance - last_dist) / spd_time;

        last_dist = camera_distance;

        float dopp_coef = camera_spd * 0.02;
        if (dopp_coef > 400) {
            dopp_coef = 300;
        } else if (dopp_coef < -300) {
            dopp_coef = -300;
        }

        int window_open = 0;
        
    }

    else {
        work_timer = 0;

        anim->gpu_work = 0;
        anim->gpu_present = 0;
        elec->gpu_volt = 0;
        elec->gpu_overload = 0;
        elec->gpu_work = 0;

    }
    
}