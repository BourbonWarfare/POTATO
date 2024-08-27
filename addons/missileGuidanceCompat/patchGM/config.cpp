#include "\z\potato\addons\missileGuidanceCompat\script_component.hpp"
#undef COMPONENT
#define COMPONENT missileGuidanceCompat_patchGM

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_missileGuidanceCompat",
            "gm_weapons_ammo",
            "gm_weapons_launchers_fagot",
            "gm_weapons_launchers_hot",
            "gm_weapons_launchers_maljutka",
            "gm_weapons_launchers_milan"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgAmmo {
    class gm_missile_saclos_base;
    // Bastion
    class gm_missile_bastion_base: gm_missile_saclos_base {
        maneuvrability = 0;
        #include "../CfgMissileBastion.hpp"
    };
    class gm_missile_bastion_heat_9M117: gm_missile_bastion_base {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
            pitchRate = 25;
            yawRate = 25;
            lineGainP = 6;
            lineGainD = 5;
            showTrail = 0;
        };
    };
    class gm_missile_bastion_heat_9M117M: gm_missile_bastion_base {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
            pitchRate = 25;
            yawRate = 25;
            lineGainP = 6;
            lineGainD = 5;
            showTrail = 0;
        };
    };
    // Fagot missile
    class gm_missile_fagot_base: gm_missile_saclos_base {
        maneuvrability = 0;
        #include "../CfgMissileFagot.hpp"
    };
    class gm_missile_fagot_heat_9m111: gm_missile_fagot_base {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
            showTrail = 0;
            pitchRate = 25;
            yawRate = 25;
            initialPitch = 0;
            lineGainP = 7;
            lineGainD = 4;
        };
    };
    // HOT missile
    class gm_missile_hot_base: gm_missile_saclos_base {
        maneuvrability = 0;
        #include "../CfgMissileHOT.hpp"
    };
    class gm_missile_hot_heat_dm72: gm_missile_hot_base {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
            pitchRate = 40;
            yawRate = 40;
        };
    };
    class gm_missile_hot_heat_dm102: gm_missile_hot_base {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
        };
    };
    // Malyutka
    class gm_missile_maljutka_base: gm_missile_saclos_base {
        maneuvrability = 0;
        #include "../CfgMissileMalyutka.hpp"
    };
    class gm_missile_maljutka_heat_9m14: gm_missile_maljutka_base {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
            showTrail = 1;
        };
    };
    class gm_missile_maljutka_heat_9m14m: gm_missile_maljutka_base {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
            showTrail = 1;
        };
    };
    // Milan
    class gm_missile_milan_base: gm_missile_saclos_base {
        maneuvrability = 0;
        #include "../CfgMissileMilan.hpp"
    };
    class gm_missile_milan_heat_dm82: gm_missile_milan_base {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
        };
    };
    class gm_missile_milan_heat_dm92: gm_missile_milan_base {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
        };
    };
    // AA Missiles
    class gm_rocket_72mm_HE_9m32m_base;
    class gm_rocket_72mm_HE_9m32m: gm_rocket_72mm_HE_9m32m_base {
        maneuvrability = 0;
        #include "../CfgMissileStrela.hpp"
    };
    class gm_rocket_70mm_HE_m585_base;
    class gm_rocket_70mm_HE_m585: gm_rocket_70mm_HE_m585_base {
        class ace_missileguidance { // from main CfgAmmo.hpp
            enabled = 1;

            pitchRate = 27;          // Minium flap deflection for guidance
            yawRate = 27;            // Maximum flap deflection for guidance

            canVanillaLock = 1;          // Can this default vanilla lock? Only applicable to non-cadet mode

            // Guidance type for munitions
            defaultSeekerType = "IR";
            seekerTypes[] = { "IR" };

            flareDistanceFilter = 100;
            flareAngleFilter = 2.0; // can filter out flares that are >= flareAngleFilter to known target velocity

            defaultSeekerLockMode = "LOBL";
            seekerLockModes[] = { "LOBL" };

            defaultNavigationType = "ProportionalNavigation";
            navigationTypes[] = { "ProportionalNavigation" };

            seekLastTargetPos = 0;      // seek last target position [if seeker loses LOS of target, continue to last known pos]
            seekerAngle = 45;           // Angle from the shooter's view that can track the missile
            seekerAccuracy = 0.4;         // seeker accuracy multiplier

            seekerMinRange = 75;
            seekerMaxRange = 4500;      // Range from the missile which the seeker can visually search

            // Attack profile type selection
            defaultAttackProfile = "DIR";
            attackProfiles[] = {"DIR"};
        };
    };
};
