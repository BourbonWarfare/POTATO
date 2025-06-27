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
    class rhs_ammo_ap_penetrator: Sh_125mm_APFSDS {};
    
    // 3BM42 - used by T-72B (original)
    class rhs_ammo_3bm42_penetrator: rhs_ammo_ap_penetrator {
        hit = 520; // was 250
    };
    
    // 3BM42M "Mango" - used by T-72B (1985)
    class rhs_ammo_3bm42m_penetrator: rhs_ammo_ap_penetrator {
        hit = 542.2; // was 270
    };
    
    // 3BM46 - used by T-72B3  
    class rhs_ammo_3bm46_penetrator: rhs_ammo_ap_penetrator {
        hit = 626.8; // was 300
    };
    
    // 3BM69 - used by T90+
    class rhs_ammo_3bm69_penetrator: rhs_ammo_ap_penetrator {
        hit = 858.16; // was 300
    };
};
