#include "..\CfgMissileTypesNato.hpp"

class CfgAmmo {
    // Milan - problem with SCALOS aiming
    class gm_missile_milan_heat_dm82;
    class gm_missile_milan_heat_dm82_ace_mg: gm_missile_milan_heat_dm82 {
        maneuvrability = 0;
        class ace_missileguidance: ACEGVAR(missileguidance,type_Milan) {
            enabled = 1;
            initialPitch = 0.4;
        };
    };

    // Add 9m14p for 9P133
    class gm_missile_maljutka_base;
    class gm_missile_maljutka_heat_9m14m: gm_missile_maljutka_base {
        class ace_missileguidance;
    };
    class GVARMAIN(gm_missile_maljutka_heat_9m14p): gm_missile_maljutka_heat_9m14m {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;

            pitchRate = 30;
            yawRate = 30;
            lineGainP = 12;
            lineGainD = 4;
            defaultSeekerType = "SACLOS";
            seekerTypes[] = { "SACLOS" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL", "LOBL" };
        };
    };

    class gm_missile_milan_heat_dm92;
    class gm_missile_milan_heat_dm92_ace_mg: gm_missile_milan_heat_dm92 {
        maneuvrability = 0;
        class ace_missileguidance: ACEGVAR(missileguidance,type_Milan) {
            enabled = 1;
            initialPitch = 0.4;
        };
    };
};
