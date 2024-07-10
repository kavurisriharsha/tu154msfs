typedef struct {

    int mode_set; // режим работы экрана. 0 - выкл, 1 - карта высот, 2 - вид сбоку, 3 - часы, 4 - процесс включения
    int distance_set; // дистанция для рисования карты, км. 0 = 10, 1 = 20, 2 = 40, 3 = 80, 4 = 160, 5 = 320, 6 = 640
    float taws_cc; // потребление тока системой СРПБЗ
    int taws_message; // сообщения СРПБЗ. 0 - none, 1 - Pull UP, 2 - alt callout, 3 - Pull Up, 4 - Terrain, 5 - Terrain Ahead, 6 - Too low, Terrain, 7 - Alt collout, 8 - Too low, Gear, 9 - Too low, Flaps, 10 - Check altitude, 11 - Sink Rate, 12 - Don't sink, 13 - Glideslope
    int taws_english; // язык системы. 0 - русский, 1 - английский
    float gs_msg_int; // интервал сигнала ГЛИССАДА
    float gs_msg_vol; // громкость сигнала ГЛИССАДА
    int taws_alt_left; // сравни высоту на левом высотомере
    int taws_alt_right; // сравни высоту на правом высотомере

} taws_t;