#include "..\CfgMissileTypesNato.hpp"

class CfgAmmo {
    // Milan - problem with SCALOS aiming
    class gm_missile_milan_base;
    class gm_missile_milan_heat_dm82: gm_missile_milan_base {
        maneuvrability = 0;
        class ace_missileguidance: ACEGVAR(missileguidance,type_Milan) {
            enabled = 1;
            initialPitch = 0.4;
        };
    };
    class gm_missile_milan_heat_dm82_ace_mg: gm_missile_milan_heat_dm82 {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
        };
    };

    class gm_missile_milan_heat_dm92: gm_missile_milan_base {
        maneuvrability = 0;
        class ace_missileguidance: ACEGVAR(missileguidance,type_Milan) {
            enabled = 1;
            initialPitch = 0.4;
        };
    };
    class gm_missile_milan_heat_dm92_ace_mg: gm_missile_milan_heat_dm92 {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
        };
    };
};
