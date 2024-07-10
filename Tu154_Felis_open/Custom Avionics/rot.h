typedef struct {

    float srpbz_brightness; // ручка яркости

    rot_console_t* console; 
    rot_gn430_t* gn430;
    rot_kln90_t* kln90;
    rot_ovhd_t* ovhd;

} rot_t;

typedef struct {

    int nav_1_course; // курс нав 1
    float nav_1_course_1; // курс нав 1
    float nav_1_course_10; // курс нав 1
    float nav_1_course_100; // курс нав 1
    int nav_2_course; // курс нав 2
    float nav_2_course_1; // курс нав 2
    float nav_2_course_10; // курс нав 2
    float nav_2_course_100; // курс нав 2
    float wind_set; // установка ветра

} rot_console_t;

typedef struct {

    int LB_angle; // поворот левой большой ручки GN430
    int LS_angle; // поворот левой малой ручки GN430
    int RB_angle; // поворот правой большой ручки GN430
    int RS_angle; // поворот правой малой ручки GN430

} rot_gn430_t;

typedef struct {

    int 3D_L_Angle; // поворот левой ручки КЛН90
    int 3D_R_Angle; // поворот правой ручки КЛН90
    int power_knob; // вытягивание ручки питания
    int power_knob_angle; // поворот ручки питания КЛН90
    int scan_knob; // вытягивание ручки scan

} rot_kln90_t;


typedef struct {

    float tks_lat_set; // ручка установки широты
    int vhf_1_left; // левая крутилка радио
    int vhf_1_right; // правая крутилка радио
    int vhf_2_left; // левая крутилка радио
    int vhf_2_right; // правая крутилка радио
    int nav_1_left; // левая крутилка
    int nav_1_right; // правая крутилка
    int nav_2_left; // левая крутилка
    int nav_2_right; // правая крутилка

} rot_ovhd_t;
