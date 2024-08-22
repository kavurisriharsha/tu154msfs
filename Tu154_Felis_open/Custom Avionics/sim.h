typedef struct {
    float ENGN_N1_0;
    float ENGN_N1_1;
    float ENGN_N1_2;
    int avionics_power_on;
    int rel_genera0;
    int rel_genera1;
    int rel_genera2;
    int generator_on0;
    int generator_on1;
    int generator_on2;
    int APU_generator_on;

    int view_is_external;
    float groundspeed;
    float local_x;
    float local_y;
    float local_z;

    float view_x;
    float view_y;
    float view_z;
} sim_t;