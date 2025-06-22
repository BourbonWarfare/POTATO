#include "\z\potato\addons\missileGuidanceCompat\CfgMissileTypesWarsaw.hpp"

class CfgAmmo {
    class ShellBase;
    class ammo_Penetrator_Base: ShellBase {
        delete submunitionConeType;
        delete submunitionDirectionType;
        delete submunitionInitialOffset;
        delete submunitionParentSpeedCoef;
        delete submunitionInitSpeed;
        delete deleteParentWhenTriggered;
        delete triggerTime;
        submunitionAmmo = "";
    };

    class M_Titan_AT;
    class rhs_ammo_atgmBase_base: M_Titan_AT {
        class EventHandlers;
    };
    class rhs_ammo_9m113: rhs_ammo_atgmBase_base {
        maneuvrability = 14;
        class ace_missileguidance: ACEGVAR(missileguidance,DOUBLES(type,Konkurs)) {
            enabled = 0;
        };
        class EventHandlers: EventHandlers {
            class RHS_Guidance {
                fired = "_this call RHS_fnc_saclosGuide";
            };
        };
    };
    class rhs_ammo_9m113m: rhs_ammo_9m113 {
        class ace_missileguidance: ace_missileguidance {
            enabled = 0;
        };
    };
    
    // Base Classes
    class Sh_125mm_APFSDS;
    class rhs_ammo_bm_base: Sh_125mm_APFSDS {};
    class rhs_ammo_3bm_base: rhs_ammo_bm_base {};
    
    // 3BM42 - used by T-72B (original)
    class rhs_ammo_3bm42: rhs_ammo_3bm_base {
        caliber = 19.2157; // was 0.1
        hit = 520; // was nil
    };
    
    // 3BM42M "Mango" - used by T-72B (1985)
    class rhs_ammo_3bm42m: rhs_ammo_3bm_base {
        caliber = 24.7619; // was 0.1
        hit = 542.2; // was nil
    };
    
    // 3BM46 - used by T-72B3
    class rhs_ammo_3bm46: rhs_ammo_3bm_base {
        caliber = 26.7059; // was 0.1
        hit = 626.8; // was nil
    };
    
    // 3BM69 - used by T90
    class rhs_ammo_3bm69: rhs_ammo_3bm_base {
        caliber = 33.6842; // was 0.1
        hit = 858.16; // was nil
    };
};
