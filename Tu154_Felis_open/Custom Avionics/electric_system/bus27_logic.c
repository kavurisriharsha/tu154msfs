#include <stdlib.h>
#include <math.h>
#include <elec.h>

/*
27V Bus Logic
Each bus has multiple sources - 2 batteries, VU, VU Aux and the other bus if itself has its own sources.
*/

int bus27_connect; // network connection 27v
int bus27_vu1; // VU1. -1 - reserve, 0 - off, +1 - on.
int bus27_vu2; // VU2. -1 - reserve, 0 - off, +1 - on.
int bat1_on; // battery 1
int bat2_on; // battery 2
int bat3_on; // battery 3
int bat4_on; // battery 4

// sources
float bat_volt_1; // battery voltage
float bat_volt_2; // battery voltage
float bat_volt_3; // battery voltage
float bat_volt_4; // battery voltage

float bat_amp_1; // battery current
float bat_amp_2; // battery current
float bat_amp_3; // battery current
float bat_amp_4; // battery current

int bat_1_kz; // thermal runaway
int bat_2_kz; // thermal runaway
int bat_3_kz; // thermal runaway
int bat_4_kz; // thermal runaway

int bat_fail_1; // battery failure
int bat_fail_2; // battery failure
int bat_fail_3; // battery failure
int bat_fail_4; // battery failure

int bat_source_1; // battery is the source
int bat_source_2; // battery is the source
int bat_source_3; // battery is the source
int bat_source_4; // battery is the source

int apu_system_on;
int apu_start_seq; // APU start process is ongoing

float vu1_volt; // VU operation
float vu2_volt; // VU operation
float vu_res_volt; // VU operation

float vu1_amp; // VU operation
float vu2_amp; // VU operation
float vu3_amp; // VU operation

int vu1_fail; // VU failure
int vu2_fail; // VU failure
int vu3_fail; // VU failure

// aux source
float bus115_1_volt; // voltage on the 115v network
float bus115_3_volt; // voltage on the 115v network

float apu_start_bus; // APU network voltage
float apu_start_cc; // APU starter current consumption

int apu_main_switch; // APU switch

float gear_defl; // landing gear strut deflection

// results
float bus27_volt_left; // network voltage 27
float bus27_volt_right; // network voltage 27

float bus27_amp_left; // network current 27
float bus27_amp_right; // network current 27

float bus27_source_left; // network source. 0 - nothing. 1 - VU1, 2 - VU reserve, 3 - batteries 1 and 3, 6 - neighboring network
float bus27_source_right; // network source. 0 - nothing. 1 - VU2, 2 - VU reserve, 3 - batteries 2 and 4, 6 - neighboring network

int buses_connected;

int vu_res_to_L; // reserve VU connected to the left network
int vu_res_to_R; // reserve VU connected to the right network

// time
float frame_time; // flight time

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int vu_overload_1 = 0;
int vu_overload_2 = 0;
int vu_overload_3 = 0;

int source_L = 0;
int source_R = 0;

void update() {
    if (frame_time > 0) {
        float bus_volt_L = 0;
        float bus_volt_R = 0;

        float bat_works_1 = bat1_on * (1- bat_1_kz) * (1 - bat_fail_1);
        float bat_works_2 = bat2_on * (1- bat_2_kz) * (1 - bat_fail_2);
        float bat_works_3 = bat3_on * (1- bat_3_kz) * (1 - bat_fail_3);
        float bat_works_4 = bat4_on * (1- bat_4_kz) * (1 - bat_fail_4);

        // Checking if VU can produce power

        int vu1 = bus115_1_volt >= 115 && vu1_fail == 0 && !vu_overload_1;
        int vu2 = bus115_3_volt >= 115 && vu2_fail == 0 && !vu_overload_2;
        int vu3 = (bus115_1_volt >= 115 || bus115_3_volt >= 115) && vu3_fail == 0 && !vu_overload_3;

        int vu1_connected = vu1 && bus27_vu1;
        int vu2_connected = vu2 && bus27_vu2;
        int vu3_connectedL = vu3 && !bus27_vu1;
        int vu3_connectedR = vu3 && !bus27_vu2;
         
        vu1_volt = vu1 ? 27 : 0;
        vu2_volt = vu2 ? 27 : 0;
        vu_res_volt = vu3 ? 27 : 0;

        if (vu1_amp > 450) {
            vu_overload_1 = 1;
        } else if (vu1_amp < 1) {
            vu_overload_1 = 0;
        }

        if (vu2_amp > 450) {
            vu_overload_2 = 1;
        } else if (vu2_amp < 1) {
            vu_overload_2 = 0;
        }

        if (vu3_amp > 450) {
            vu_overload_3 = 1;
        } else if (vu3_amp < 1 && bus27_vu2) {
            vu_overload_3 = 0;
        }

        if (apu_start_seq) {
            buses_connected = 1;
            if (vu1_connected || vu2_connected || vu3) {
                source_L = 1;
                source_R = 1;
                bus_volt_L = 28.5;
                bus_volt_R = 28.5;
                apu_start_bus = 28.5;

                bat_source_1 = 0;
                bat_source_2 = 0;
                bat_source_3 = 0;
                bat_source_4 = 0;

                vu1_amp = (bus27_amp_left + bus27_amp_right + apu_start_cc) * vu1_connected / (vu1_connected + vu2_connected + vu3);
                vu2_amp = (bus27_amp_left + bus27_amp_right + apu_start_cc) * vu2_connected / (vu1_connected + vu2_connected + vu3);
                vu3_amp = (bus27_amp_left + bus27_amp_right + apu_start_cc) * vu3 / (vu1_connected + vu2_connected + vu3);

                bat_amp_1 = 0;
                bat_amp_2 = 0;
                bat_amp_3 = 0;
                bat_amp_4 = 0;

                vu3_connectedL = vu3;
                vu3_connectedR = vu3;

            }
            else if(gear_defl > 0.05) {
                if ((bat_works_1 + bat_works_2 + bat_works_3 + bat_works_4) > 0)  {
                    source_L = 3;
                    source_R = 3;
                    bus_volt_L = (bat_volt_1 * bat_works_1 + bat_volt_2 * bat_works_2 + bat_volt_3 * bat_works_3 + bat_volt_4 * bat_works_4) / (bat_works_1 + bat_works_2 + bat_works_3 + bat_works_4);
                    bus_volt_R = bus_volt_L;

                    bat_source_1 = bat_works_1; 
                    bat_source_2 = bat_works_2;
                    bat_source_3 = bat_works_3;
                    bat_source_4 = bat_works_4;

                    vu1_amp = 0;
                    vu2_amp = 0;    
                    vu3_amp = 0;
                    
                    bat_amp_1 = (bus27_amp_left + bus27_amp_right + apu_start_cc) * bat_works_1 / (bat_works_1 + bat_works_3 + bat_works_2 + bat_works_4);
                    bat_amp_2 = (bus27_amp_left + bus27_amp_right + apu_start_cc) * bat_works_2 / (bat_works_1 + bat_works_3 + bat_works_2 + bat_works_4);
                    bat_amp_3 = (bus27_amp_left + bus27_amp_right + apu_start_cc) * bat_works_3 / (bat_works_1 + bat_works_3 + bat_works_2 + bat_works_4);
                    bat_amp_4 = (bus27_amp_left + bus27_amp_right + apu_start_cc) * bat_works_4 / (bat_works_1 + bat_works_3 + bat_works_2 + bat_works_4);            
                } 

                else {
                    source_L = 0;
                    source_R = 0;
                    bus_volt_L = 0;
                    bus_volt_R = 0;
                    apu_start_bus = 0;
                }

                bat_source_1 = bat_works_1;
                bat_source_2 = bat_works_2;
                bat_source_3 = bat_works_3;
                bat_source_4 = bat_works_4;

                if (bat_works_3 + bat_works_4 > 0) {
                    apu_start_bus = bat_volt_3 * bat_works_3 + bat_volt_4 * bat_works_4 / (bat_works_3 + bat_works_4);
                    bat_amp_3 = apu_start_cc * bat_works_3 / (bat_works_3 + bat_works_4);
                    bat_amp_4 = apu_start_cc * bat_works_4 / (bat_works_3 + bat_works_4);
                } 
                
                else {
                    apu_start_bus = 0;
                    bat_amp_3 = 0;
                    bat_amp_4 = 0;
                }
            }

            else {
                source_L = 3;
                source_R = 3;

                if (bat_works_1 + bat_works_2 > 0) {
                    bus_volt_L = (bat_volt_1 * bat_works_1 + bat_volt_2 * bat_works_2) / (bat_works_1 + bat_works_2);
                    bus_volt_R = bus_volt_L;
                    bat_amp_1 = (bus27_amp_left + bus27_amp_right) * bat_works_1 / (bat_works_1 + bat_works_2);
                    bat_amp_2 = (bus27_amp_left + bus27_amp_right) * bat_works_2 / (bat_works_1 + bat_works_2);
                }

                else {
                    bus_volt_L = 0;
                    bus_volt_R = 0;
                    vu1_amp = 0;
                    vu2_amp = 0;
                    vu3_amp = 0;
                    bat_amp_1 = 0;
                    bat_amp_2 = 0;
                }

                bat_source_1 = bat_works_1;
                bat_source_2 = bat_works_2;
                bat_source_3 = bat_works_3;
                bat_source_4 = bat_works_4;

                if (bat_works_3 + bat_works_4 > 0) {
                    apu_start_bus = (bat_volt_3 * bat_works_3 + bat_volt_4 * bat_works_4) / (bat_works_3 + bat_works_4);
                    bat_amp_3 = apu_start_cc * bat_works_3 / (bat_works_3 + bat_works_4);
                    bat_amp_4 = apu_start_cc * bat_works_4 / (bat_works_3 + bat_works_4);
                } 
                
                else {
                    apu_start_bus = 0;
                    bat_amp_3 = 0;
                    bat_amp_4 = 0;
                }
            }
        }

        

        else if (bus27_connect || apu_system_on) {
            buses_connected = 1;

            if (((vu1 && vu1_connected) || (vu2 && vu2_connected) || (vu3 && vu3_connectedL + vu3_connectedR > 0))&& (bus27_vu1 != 0 || bus27_vu2 != 0)) {
                source_L = 1;
                source_R = 1;
                bus_volt_L = 28.5;
                bus_volt_R = 28.5;
                apu_start_bus = 28.5;
                bat_source_1 = 0;   
                bat_source_2 = 0;
                bat_source_3 = 0;
                bat_source_4 = 0;

                vu1_amp = (bus27_amp_left + bus27_amp_right) * vu1_connected / (vu1_connected + vu2_connected + vu3_connectedL + vu3_connectedR);
                vu2_amp = (bus27_amp_left + bus27_amp_right) * vu2_connected / (vu1_connected + vu2_connected + vu3_connectedL + vu3_connectedR);
                vu3_amp = (bus27_amp_left + bus27_amp_right) * (vu3_connectedL + vu3_connectedR) / (vu1_connected + vu2_connected + vu3_connectedL + vu3_connectedR);

                bat_amp_1 = 0;
                bat_amp_2 = 0;
                bat_amp_3 = 0;
                bat_amp_4 = 0;
            }

            else {
                if (bat_works_1 + bat_works_2 + bat_works_3 + bat_works_4) {
                    source_L = 3;
                    source_R = 3;
                    bus_volt_L = (bat_volt_1 * bat_works_1 + bat_volt_2 * bat_works_2 + bat_volt_3 * bat_works_3 + bat_volt_4 * bat_works_4) / (bat_works_1 + bat_works_2 + bat_works_3 + bat_works_4);
                    bus_volt_R = bus_volt_L;
                    apu_start_bus = bus_volt_L;
                    bat_source_1 = bat_works_1;
                    bat_source_2 = bat_works_2;
                    bat_source_3 = bat_works_3;
                    bat_source_4 = bat_works_4;

                    vu1_amp = 0;
                    vu2_amp = 0;
                    vu3_amp = 0;

                    bat_amp_1 = (bus27_amp_left + bus27_amp_right) * bat_works_1 / (bat_works_1 + bat_works_2 + bat_works_3 + bat_works_4);
                    bat_amp_2 = (bus27_amp_left + bus27_amp_right) * bat_works_2 / (bat_works_1 + bat_works_2 + bat_works_3 + bat_works_4);
                    bat_amp_3 = (bus27_amp_left + bus27_amp_right) * bat_works_3 / (bat_works_1 + bat_works_2 + bat_works_3 + bat_works_4);
                    bat_amp_4 = (bus27_amp_left + bus27_amp_right) * bat_works_4 / (bat_works_1 + bat_works_2 + bat_works_3 + bat_works_4);
                }

                else {
                    source_L = 0;
                    source_R = 0;
                    bus_volt_L = 0;
                    bus_volt_R = 0;
                    apu_start_bus = 0;
                    bat_source_1 = 0;
                    bat_source_2 = 0;
                    bat_source_3 = 0;
                    bat_source_4 = 0;
                }
            }
        }

        else {
            buses_connected = 0;
            apu_start_bus = 0;

            if (vu1 && bus27_vu1) {
                source_L = 1;
                bus_volt_L = 28.5;
                bat_source_1 = 0;
                bat_source_3 = 0;
                vu1_amp = bus27_amp_left;
                vu3_amp = 0;
                bat_amp_1 = 0;
                bat_amp_3 = 0;
            }

            else if (vu3 && bus27_vu1) {
                source_L = 2;
                bus_volt_L = 28.5;
                bat_source_1 = 0;
                bat_source_3 = 0;
                vu1_amp = 0;
                vu3_amp = bus27_amp_left;
                bat_amp_1 = 0;
                bat_amp_3 = 0;
            }

            else if (bat_works_1 + bat_works_3 > 0) {
                bus_volt_L = (bat_volt_1 * bat_works_1 + bat_volt_3 * bat_works_3) / (bat_works_1 + bat_works_3);
                bus_volt_R = bus_volt_L;    
                apu_start_bus = bus_volt_L;
                bat_source_1 = bat_works_1;
                bat_source_2 = bat_works_2;
                bat_source_3 = bat_works_3;
                bat_source_4 = bat_works_4;

                vu1_amp = 0;
                vu2_amp = 0;
                vu3_amp = 0;

                bat_amp_1 = (bus27_amp_left + bus27_amp_right) * bat_works_1 / (bat_works_1 + bat_works_2 + bat_works_3 + bat_works_4);
                bat_amp_2 = (bus27_amp_left + bus27_amp_right) * bat_works_2 / (bat_works_1 + bat_works_2 + bat_works_3 + bat_works_4);
                bat_amp_3 = (bus27_amp_left + bus27_amp_right) * bat_works_3 / (bat_works_1 + bat_works_2 + bat_works_3 + bat_works_4);
                bat_amp_4 = (bus27_amp_left + bus27_amp_right) * bat_works_4 / (bat_works_1 + bat_works_2 + bat_works_3 + bat_works_4);
                
            }

            else {
                source_L = 0;
                bus_volt_L = 0;
                bat_source_1 = 0;
                bat_source_3 = 0;
                vu1_amp = 0;
                vu3_amp = 0;
                bat_amp_1 = 0;
                bat_amp_3 = 0;
            }

            if (vu2 && bus27_vu2) {
                source_R = 1;
                bus_volt_R = 28.5;
                bat_source_2 = 0;
                bat_source_4 = 0;
                vu2_amp = bus27_amp_right;
                bat_amp_2 = 0;
                bat_amp_4 = 0;
            }

            else if (vu3 && bus27_vu2 == -1) {
                source_R = 2;
                bus_volt_R = 28.5;
                bat_source_2 = 0;
                bat_source_4 = 0;
                vu2_amp = 0;
                vu3_amp += bus27_amp_right;
                bat_amp_2 = 0;
                bat_amp_4 = 0;
            }

            else if ((bat_works_2 + bat_works_4) > 0) {
                bus_volt_R = (bat_volt_2 * bat_works_2 + bat_volt_4 * bat_works_4) / (bat_works_2 + bat_works_4);
                source_R = 3;
                bat_source_2 = bat_works_2;
                bat_source_4 = bat_works_4;
                vu2_amp = 0;
                bat_amp_2 = bus27_amp_right * bat_works_2 / (bat_works_2 + bat_works_4);
                bat_amp_4 = bus27_amp_right * bat_works_4 / (bat_works_2 + bat_works_4);
            }

            else {
                source_R = 0;
                bus_volt_R = 0;
                bat_source_2 = 0;
                bat_source_4 = 0;
                vu2_amp = 0;
                bat_amp_2 = 0;
                bat_amp_4 = 0;
            }
        }

        bus27_volt_left = bus_volt_L;
        bus27_volt_right = bus_volt_R;

        bus27_source_left = source_L;
        bus27_source_right = source_R;

        vu_res_to_L = vu3_connectedL;
        vu_res_to_R = vu3_connectedR;

        apu_start_bus = apu_start_bus;


    }
    

   
}

