#include "elec.h"
#include "../acf.h"

void update_115(elec_t* elec, acf_t* acf) {
    if (acf->frame_time > 0) {
        if (elec->gen1_work == 1 && elec->gen2_work && elec->gen3_work) {
            float bus1_volt = 0;
            float bus2_volt = 0;
            float bus3_volt = 0;

            float bus1_em_volt = 0;
            float bus2_em_volt = 0;

            /*float bus1_amp = elec->bus115_1_amp;
            float bus2_amp = elec->bus115_2_amp;
            float bus3_amp = elec->bus115_3_amp;

            float bus1_em_amp = elec->bus115_em_1_amp;
            float bus2_em_amp = elec->bus115_em_2_amp;*/

            int gen1_work = elec->gen1_work == 1;
            int gen2_work = elec->gen2_work == 1;
            int gen3_work = elec->gen3_work == 1;
            int gen4_work = elec->gen4_work == 1;
            int gpu_work = elec->gpu_work == 1;

            /*float gen1_volt = elec->gen1_volt;
            float gen2_volt = elec->gen2_volt;
            float gen3_volt = elec->gen3_volt;
            float gen4_volt = elec->gen4_volt;*/
        }
    }
}