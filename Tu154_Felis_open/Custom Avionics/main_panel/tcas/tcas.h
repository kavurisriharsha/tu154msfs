typedef struct {

    int range_set; // дистанция на дисплее. 0 = 3, 1 = 5, 2 = 10, 3 = 15 nm
    int mode_set; // режим TCAS. -1 = test, 0 - stby, 1 = alt off, 2 = alt on, 3 = TA, 4 = TARA
    int screen_mode; // режим отображения на экране.  -1 = ошибка, 0 = код ответчика, 1 = above mode, 2 = FL mode, 3 = FLT ID, 4 = PLN BIT, 5 = test, 6 = range set, 11-14 = code set, 100 = no power
    int level_mode; // 1 = above, 0 = normal, -1 = below
    int fl_mode; // fl mode. 0 = absolute, 1 = relative
    int flt_id; // flight ID. 0 = cover, 1 = show / change code
    int ra_scale_set; // RA mode scale set. 0 = none.
    int traffic_det; // появление желтых или красных меток

} tcas_t;