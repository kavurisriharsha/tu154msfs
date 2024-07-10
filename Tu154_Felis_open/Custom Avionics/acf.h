typedef struct {

    int absu_course_out; // flying outside the course limits
    int absu_gs_out; // flying outside the glideslope limits
    int absu_use_second_nav; // АБСУ перешло на второй КурсМП

    float frame_time;
    float absu_at_dif_left; // разность скоростей для индикации на ПКП
    float absu_at_dif_right; // разность скоростей для индикации на ПКП
    float absu_at_power_cc; // потребление тока АБСУ

    float absu_power_cc; // потребление тока АБСУ
    
} acf_t;