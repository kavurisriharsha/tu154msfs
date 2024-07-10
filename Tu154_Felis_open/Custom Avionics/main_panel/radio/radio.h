typedef struct {
    int nav1_cs_flag; // Course flag
    int nav2_cs_flag; // Course flag
    int nav1_gs_flag; // Glide slope flag
    int nav2_gs_flag; // Glide slope flag

    float adf_bear_1; // ADF beacon bearing
    float adf_bear_2; // ADF beacon bearing
    float vor_bear_1; // VOR beacon bearing
    float vor_bear_2; // VOR beacon bearing
    float vor_dme_1; // Distance to VOR
    float vor_dme_2; // Distance to VOR
    float nav1_cs; // Course deviation indicator
    float nav1_gs; // Glide slope deviation
    float nav2_cs; // Course deviation indicator
    float nav2_gs; // Glide slope deviation

    
    float vhf1_cc; // Current consumption by the radio station
    float vhf2_cc; // Current consumption by the radio station
    
    float ark15_L_cc; // Current consumption by ARK
    float ark15_R_cc; // Current consumption by ARK
    
    float nav1_pow_cc; // Current consumption by KursMP
    float nav2_pow_cc; // Current consumption by KursMP
    float radar_cc; // Current consumption by radar Groza
    float rsbn_cc; // Current consumption by RSBN
    
} radio_t;