typedef struct {
    int parking_brake; // Parking brake handle
    int emerg_gear_ext; // Emergency gear extension handle
    
    int gear_lever; // Gear lever. -1 - retract0 - neutral+1 - extend
    int elev_trimm_switcher; // Elevator trim switch. -1 - dive0 - neutral+1 - climb
    int stab_man_cap; // Stabilizer manual control cap
    int stab_manual; // Manual stabilizer control. 0 - neutral+1 - climb
    int stab_setting; // Stabilizer trim setting. 0 - Z1 - S2 - P
    int ail_trimm_sw; // Aileron trim switch
    int rudd_trimm_sw; // Rudder trim switch
    int contr_force_cap; // Control force cap
    int contr_force_set; // Control force setting. -1 - flight0 auto+1 - takeoff-landing

    float ctr_27_L_cc; // Network load
    float ctr_27_R_cc; // Network load

    float ctr_115_1_cc; // Network load
    float ctr_115_2_cc; // Network load
    float ctr_115_3_cc; // Network load

    float ctr_36L_cc; // Network load 
    float ctr_36R_cc; // Network load

    float control_force_pos; // position of the loader RV. 0 - disabled, 1 - enabled
    float control_force_pos_rud; // position of the LV loader. 0 - disabled, 1 - enabled

    float nosewheel_lever; // Nosewheel lever
    float yoke_pitch; // Yoke pitch
    float yoke_roll; // Yoke roll
    float pedals; // Pedals
    float brake_L; // Left pedal brake
    float brake_R; // Right pedal brake
    float brake_emerg; // Emergency brake
    float brake_emerg_L; // Emergency brake left
    float brake_emerg_R; // Emergency brake right
    float spoilers_lever; // Spoilers lever
    float throttle_1; // Throttle 1
    float throttle_2; // Throttle 2
    float throttle_3; // Throttle 3
    float throttle_1_ENG; // Throttle 1 ENG
    float throttle_2_ENG; // Throttle 2 ENG
    float throttle_3_ENG; // Throttle 3 ENG
    float revers_L; // Reverse lever left
    float revers_R; // Reverse lever right
    float fuel_cutoff_1; // Fuel cutoff lever 1
    float fuel_cutoff_2; // Fuel cutoff lever 2
    float fuel_cutoff_3; // Fuel cutoff lever 3
    float throttle_lock; // Throttle lock lever
    float flaps_lever; // Flaps lever. 0-45

} controls_t;