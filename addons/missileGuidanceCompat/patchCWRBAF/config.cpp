#include "\z\potato\addons\missileGuidanceCompat\script_component.hpp"
#undef COMPONENT
#define COMPONENT missileGuidanceCompat_patchCWRBAF

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_missileGuidanceCompat", "cwr3_static_uk"};
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgAmmo {
    class MissileBase;
    class CUP_M_Stinger_AA: MissileBase {
        class ace_missileguidance;
    };
    class GVAR(M_javelin_AA): CUP_M_Stinger_AA {
        class ace_missileguidance: ace_missileguidance {
            enabled = 1;
            pitchRate = 45;
            yawRate = 45;

            canVanillaLock = 0;
            showTrail = 1;

            defaultSeekerType = "SACLOS";
            seekerTypes[] = { "SACLOS" };

            defaultSeekerLockMode = "LOAL";
            seekerLockModes[] = { "LOAL", "LOBL" };

            defaultNavigationType = "Line";
            navigationTypes[] = { "Line" };

            lineGainP = 30;
            lineGainD = 16;

            initialPitch = 2;

            seekLastTargetPos = 0;
            seekerAngle = 30;
            seekerAccuracy = 1;
            seekerMinRange = 75;
            seekerMaxRange = 6000;

            correctionDistance = 30;
            offsetFromCrosshair[] = { 0, 0, 0 };

            defaultAttackProfile = "BEAM";
            attackProfiles[] = {"BEAM"};
        };
    };
};

class CfgMagazines {
    class CA_LauncherMagazine;
    class cwr3_javelin_m: CA_LauncherMagazine {
        ammo = QGVAR(M_javelin_AA);
    };
};

class CfgWeapons {
    class CUP_launch_FIM92Stinger_Loaded;
    class cwr3_launch_javelin: CUP_launch_FIM92Stinger_Loaded {
        opticsZoomMin = 0.25 / 6; // 6x zoom
        canLock = 0;
        cmImmunity = 0.95;
    };
};
