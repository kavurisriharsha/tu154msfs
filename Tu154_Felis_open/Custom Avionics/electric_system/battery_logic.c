#include <stdlib.h>
#include <math.h>
#include <elec.h>

#define BAT_CURR_COEF 2

#ifndef bat_amp
#define bat_amp 0
#endif

// Global vars
int bat_on_bus;
int bat_source;
float bat_amp_bus;
float bat_amp_cc;
float bat_volt_bus;
float bat_thermo;
int bat_fail;
int bat_kz;
float bus_volt;
float cockpit_temp;
float frame_time;
int sim_bat_on;

// setting the initial battery voltage with some random offset between 0 and 1.5 volts
double bat_capacity = 25 - (rand() % 150) / 100.0;

float kz_timer = 0;
float KzTimer = 1;

int8_t thermo = 20;

int8_t max_bat_cap = 45 + cockpit_temp;

max_bat_cap = fmin(fmax(0, max_bat_cap), 25);

if (bat_capacity > max_bat_cap)
    bat_capacity = max_bat_cap;


void calc() {
    float bat_voltage = 17 + ((bat_capacity - kz_timer)/2.5) - 1.5 * bat_amp/100;

    if (bat_on_bus && bat_source) {
        
        // battery is on the bus
        bat_capacity -= bat_amp * frame_time/3600;
        // battery drops 2 volts for each 100 amp
        bat_voltage = 17 + ((bat_capacity - kz_timer)/2.5) - 1.5 * bat_amp/100;

        if (bat_capacity < 2)
        {
            bat_volt = 3;
        }

        bat_amp_cc = 0;
    }

    else if (bat_on_bus && !bat_source) {

        // battery on the bus but not the source
        if (bat_fail) {
            bat_capcity = 0;
            bat_volt = 3;
            MAX_BAT_CAP = 0;
        }

        if (bus_volt > bat_voltage) {
            bat_volt = bus_volt;
        }

        bat_capacity += frame_time * 0.01;

        bat_amp_cc = (max_bat_cap - bat_capacity) * BAT_CURR_COEF + (0.00027778 * (kz_timer) ^ 2 + 0.06667 * kz_timer - 10); 

    }

    else {
        // battery is not on the bus
        if (bat_fail) {
            bat_capacity = 0;
            bat_voltage = 3;
            max_bat_cap = 0;
        }

        bat_amp_cc = 0;
        bat_volt_bus = bat_voltage;

        if (thermo > 20) {
            thermo -= frame_time * 0.5;
            bat_thermo = thermo;
        }
    }
    
    if (bat_on_bus) {

        if (bat_kz && kz_timer < 1800) {
            kz_timer += frame_time * KzTimer;
        }

        max_bat_cap -= kz_timer;

        bat_volt_bus = bat_voltage;

        // limit bat cap between max and 0 truncate values if below 0 or above max

        if (bat_capacity > max_bat_cap) {
            bat_capacity = max_bat_cap;
        }

        if (bat_capacity < 0) {
            bat_capacity = 0;
        }

        thermo = 20 + bat_amp_cc * 0.3;
        bat_thermo = thermo;
    }
    
}
