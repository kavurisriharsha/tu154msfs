typedef struct {

    int crew_num; // экипаж в кабине
    int zone_1; // пассажиры
    int zone_2; // пассажиры
    int cabin_num; // экипаж в салоне
    int zone_4; // пассажиры
    int zone_5; // пассажиры
    int zone_6; // пассажиры
    int cargo_1; // багаж 1
    int cargo_2; // багаж 2
    int kitchens; // загрузка кухонь
    int various; // прочее
    int main_dist; // дистанция до основного АП
    int alt_dist; // дистанция до запасного АП
    int main_fl; // эшелон до основного
    int alt_fl; // эшелон до запасного
    int nav_fuel; // навигацонный запас
    int taxi_fuel; // топливо на руление
    int tank_1; // топливо в баке
    int tank_4; // топливо в баке
    int tank_2L; // топливо в баке
    int tank_2R; // топливо в баке
    int tank_3L; // топливо в баке
    int tank_3R; // топливо в баке
    int load_fuel_btn; // кнопка загрузки топлива
    int load_fast_btn; // кнопка загрузки быстро
    int load_slow_btn; // кнопка загрузки медленно
    float paylod_set; // Нужно загрузить
    float cg_set; // Нужно загрузить

} payload_t;