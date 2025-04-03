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

    class gm_missile_milan_heat_dm92;
    class gm_missile_milan_heat_dm92_ace_mg: gm_missile_milan_heat_dm92 {
        maneuvrability = 0;
        class ace_missileguidance: ACEGVAR(missileguidance,type_Milan) {
            enabled = 1;
            initialPitch = 0.4;
        };
    };
};
