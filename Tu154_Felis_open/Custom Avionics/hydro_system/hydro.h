typedef struct {

    float gs_press_1; // давление в ГС1
    float gs_press_2; // давление в ГС2
    float gs_press_3; // давление в ГС3
    float gs_press_4; // давление в аварийной тормозной системе
    float gs_qty_1; // остаток масла в системе
    float gs_qty_2; // остаток масла в системе
    float gs_qty_3; // остаток масла в системе
    float gs_qty_12_show; // остаток масла в гидробаке
    float gs_qty_3_show; // остаток масла в гидробаке
    float gs_pump_2_cc; // ток насосной станции
    float gs_pump_3_cc; // ток насосной станции
    float gs_bak_qty_1; // остаток масла в баке
    float gs_bak_qty_2; // остаток масла в баке
    float gs_bak_qty_3; // остаток масла в баке

} hydro_t;