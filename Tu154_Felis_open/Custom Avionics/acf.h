typedef struct {

    int absu_course_out; // flying outside the course limits
    int absu_gs_out; // flying outside the glideslope limits
    int absu_use_second_nav; // АБСУ перешло на второй КурсМП.
    
    int hardware_cockpit; // Самолет подготовлен для железного кокпита

    float frame_time; // время между кадрами. при прокрутке назад, не принимает отрицательного значения. при FPS меньше 10 - ставит время кадра = 0.1
    float absu_at_dif_left; // разность скоростей для индикации на ПКП
    float absu_at_dif_right; // разность скоростей для индикации на ПКП
    float absu_at_power_cc; // потребление тока АБСУ

    float absu_power_cc; // потребление тока АБСУ
    
} acf_t;