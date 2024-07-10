typedef struct {
    
    int main_gear_flaps; // не взлетное положение закрылков или не выпущенны шасси
    int main_pressure; // разгерметизация или перенаддув кабины
    int speaker_auasp; // предельный угол атаки или перегрузки
    int speaker_fuel; // остаток топлива 2500 в баке 1
    int speaker_speed; // предельная скорость
    int speaker_absu; // отключение режимов или отказы АБСУ
    
} alarm_t;