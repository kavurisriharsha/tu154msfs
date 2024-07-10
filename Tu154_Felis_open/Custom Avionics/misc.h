typedef struct {

    float rv5_alt_left; // высота на левом высотомере
    float rv5_alt_right; // высота на правом высотомере
    int rv5_dh_signal_left; // сигнал DH
    int rv5_dh_signal_right; // сигнал DH
    float cg_pos_actual; // актуальное положение CG
    float weight_actual; // актуальная масса
    float water_level; // уровень воды

} misc_t;