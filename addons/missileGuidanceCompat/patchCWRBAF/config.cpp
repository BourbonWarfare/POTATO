#include "\z\potato\addons\missileGuidanceCompat\script_component.hpp"
#undef COMPONENT
#define COMPONENT missileGuidanceCompat_patchCWRBAF

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_missileGuidanceCompat", "cwr3_static_uk", "cwr3_javelin_uk"};
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "\z\potato\addons\missileGuidanceCompat\CfgMissileTypesNato.hpp"

class CfgAmmo {
    class CUP_M_Stinger_AA;
    class GVAR(M_javelin_AA): CUP_M_Stinger_AA {
        class ace_missileguidance: ACEGVAR(missileguidance,type_RBS70) {
            enabled = 1;
            lineGainP = 30;
            lineGainD = 16;
            seekerMaxRange = 6000;
        };
    };
    class GVAR(blowpipe_a): CUP_M_Stinger_AA {
        class ace_missileguidance: ACEGVAR(missileguidance,type_Blowpipe) {
            enabled = 1;
        };
    };
};

class CfgMagazines {
    class CA_LauncherMagazine;
    class cwr3_javelin_m: CA_LauncherMagazine {
        ammo = QGVAR(M_javelin_AA);
    };
    class GVAR(blowpipe_m): cwr3_javelin_m {
        displayName = "Blowpipe";
        displayNameShort = "Blowpipe";
        descriptionShort = "Range : 3500 m<br/>Type : ground-air<br/>Used in : Blowpipe";
        author = "CWR III (BW Config)";
        ammo = QGVAR(blowpipe_a);
    };
};

class CfgWeapons {
    class CUP_launch_FIM92Stinger_Loaded;
    class cwr3_launch_javelin: CUP_launch_FIM92Stinger_Loaded {
        opticsZoomMin = 0.25 / 6; // 6x zoom
        canLock = 0;
        cmImmunity = 0.95;
    };
    class GVAR(blowpipe): cwr3_launch_javelin {
        displayName = "Blowpipe";
        descriptionShort = "Blowpipe<br/>MCLOS Guided";
        author = "CWR III (BW Config)";
        baseWeapon = QGVAR(blowpipe);
        scope = 2;
        canLock = 0;
        magazines[] = { QGVAR(blowpipe_m) };
    };
};
