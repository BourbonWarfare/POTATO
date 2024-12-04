#include "\z\potato\addons\missileGuidanceCompat\script_component.hpp"
#undef COMPONENT
#define COMPONENT missileGuidanceCompat_patchCUP

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_missileGuidanceCompat", "A3_Weapons_F"};
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "../CfgMissileTypesNato.hpp"

class CfgAmmo {
    class Sh_82mm_AMOS;
    class Sh_155mm_AMOS;
    class Sh_82mm_AMOS_guided;
    class R_230mm_HE;

    class GVAR(82mm_laser_active): Sh_82mm_AMOS {
        maneuvrability = 0;
        artilleryLock = 0;
        simulation = "shotMissile";
        initTime = 0;
        thrustTime = 0;
        thrust = 0;
        manualControl = 0;
        artilleryCharge = 0.5;
        airFriction = 0;
        sideAirFriction = 0.2;
        autoSeekTarget = 0;
        laserLock = 0;
        lockType = 0;
        weaponLockSystem = 0;
        hit = 95;
        warheadName = "HE";
        submunitionAmmo = "ammo_Penetrator_Titan_AT_long";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitSpeed = 1000;
        submunitionParentSpeedCoef = 0.0;
        submunitionInitialOffset[] = {0,0,-0.2};
        triggerOnImpact = 1;
        deleteParentWhenTriggered = 0;
        indirectHit = 30;
        indirectHitRange = 3.5;
        dangerRadiusHit = 160;
        suppressionRadiusHit = 32;
        CraterEffects = "ArtyShellCrater";
        explosionEffects = "ATRocketExplosion";
        class ace_missileguidance: GVAR(laser_artillery) {
            enabled = 1;
        };
        class EventHandlers {
            init = QUOTE([ARR_7(ARG_1(getShotParents ARG_1(_this,0),0),'','','',typeOf ARG_1(_this,0),nil,ARG_1(_this,0))] call ace_missileguidance_fnc_onFired);
        };
    };

    class GVAR(155mm_laser_active): Sh_155mm_AMOS {
        maneuvrability = 0;
        artilleryLock = 0;
        simulation = "shotMissile";
        initTime = 0;
        thrustTime = 0;
        thrust = 0;
        manualControl = 0;
        artilleryCharge = 0.5;
        airFriction = 0;
        sideAirFriction = 0.2;
        autoSeekTarget = 0;
        laserLock = 0;
        lockType = 0;
        weaponLockSystem = 0;
        hit = 95;
        warheadName = "HE";
        submunitionAmmo = "ammo_Penetrator_120mm";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitSpeed = 1000;
        submunitionParentSpeedCoef = 0.0;
        submunitionInitialOffset[] = {0,0,-0.2};
        triggerOnImpact = 1;
        deleteParentWhenTriggered = 0;
        indirectHit = 30;
        indirectHitRange = 3.5;
        dangerRadiusHit = 160;
        suppressionRadiusHit = 32;
        CraterEffects = "ArtyShellCrater";
        explosionEffects = "ATRocketExplosion";
        class ace_missileguidance: GVAR(laser_artillery) {
            enabled = 1;
        };
        class EventHandlers {
            init = QUOTE([ARR_7(ARG_1(getShotParents ARG_1(_this,0),0),'','','',typeOf ARG_1(_this,0),nil,ARG_1(_this,0))] call ace_missileguidance_fnc_onFired);
        };
    };

    class GVAR(230mm_laser_active): R_230mm_HE {
        maneuvrability = 0;
        artilleryLock = 0;
        simulation = "shotMissile";
        initTime = 0;
        thrustTime = 0;
        thrust = 0;
        manualControl = 0;
        artilleryCharge = 0.5;
        airFriction = 0;
        sideAirFriction = 0.2;
        autoSeekTarget = 0;
        laserLock = 0;
        lockType = 0;
        weaponLockSystem = 0;
        hit = 95;
        warheadName = "HE";
        submunitionAmmo = "ammo_Penetrator_120mm";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitSpeed = 1000;
        submunitionParentSpeedCoef = 0.0;
        submunitionInitialOffset[] = {0,0,-0.2};
        triggerOnImpact = 1;
        deleteParentWhenTriggered = 0;
        indirectHit = 30;
        indirectHitRange = 3.5;
        dangerRadiusHit = 160;
        suppressionRadiusHit = 32;
        CraterEffects = "ArtyShellCrater";
        explosionEffects = "ATRocketExplosion";
        class ace_missileguidance: GVAR(laser_artillery) {
            enabled = 1;
        };
        class EventHandlers {
            init = QUOTE([ARR_7(ARG_1(getShotParents ARG_1(_this,0),0),'','','',typeOf ARG_1(_this,0),nil,ARG_1(_this,0))] call ace_missileguidance_fnc_onFired);
        };
    };

    class Sh_82mm_AMOS_LG: Sh_82mm_AMOS_guided {
        submunitionAmmo = QGVAR(82mm_laser_active);
        submunitionDirectionType = "SubmunitionModelDirection";
        class EventHandlers {
            init = QUOTE([ARR_3({ ARG_1(velocity ARG_1(_this,0),2) < 0 },{ triggerAmmo ARG_1(_this,0); },_this)] call CBA_fnc_waitUntilAndExecute;);
        };
    };
    class Sh_155mm_AMOS_LG: Sh_82mm_AMOS_LG {
        submunitionAmmo = QGVAR(155mm_laser_active);
        submunitionDirectionType = "SubmunitionModelDirection";
        class EventHandlers {
            init = QUOTE([ARR_3({ ARG_1(velocity ARG_1(_this,0),2) < 0 },{ triggerAmmo ARG_1(_this,0); },_this)] call CBA_fnc_waitUntilAndExecute;);
        };
    };
    class R_230mm_LG: R_230mm_HE {
        submunitionAmmo = QGVAR(230mm_laser_active);
        submunitionDirectionType = "SubmunitionModelDirection";
        class EventHandlers {
            init = QUOTE([ARR_3({ ARG_1(velocity ARG_1(_this,0),2) < 0 },{ triggerAmmo ARG_1(_this,0); },_this)] call CBA_fnc_waitUntilAndExecute;);
        };
    };
};