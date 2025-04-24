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
};
