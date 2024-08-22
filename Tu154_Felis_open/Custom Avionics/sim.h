typedef struct {
    int avionics_power_on;
    int rel_genera0;
    int rel_genera1;
    int rel_genera2;
    int generator_on0;
    int generator_on1;
    int generator_on2;
    int APU_generator_on;

    int parkbrake;


    int view_is_external;

    float ENGN_N1_0;
    float ENGN_N1_1;
    float ENGN_N1_2;

    float groundspeed;
    float local_x;
    float local_y;
    float local_z;

    float view_x;
    float view_y;
    float view_z;

    float wing1l_fla1def;
    float wing1r_fla1def;


    float wing3l_ail1def;
    float wing3r_ail1def;

    float wing1l_spo1def;
    float wing1r_spo1def;

    float wing2l_spo2def;
    float wing2r_spo2def;

    float hstab1_elv1def;
    float hstab2_elv1def;
    float vstab2_rud1def;

    float acf_gear_deploy0;
    float acf_gear_deploy1;
    float acf_gear_deploy2;




} sim_t;