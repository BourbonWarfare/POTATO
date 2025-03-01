#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchSOG

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "loadorder_f_vietnam" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgMissions {
  class Cutscenes { // restore the load menus
        class Stratis_intro1 {
            directory = "a3\map_stratis_scenes_f\scenes\introExp.Stratis";
        };
        class Altis_intro1 {
            directory = "a3\missions_f_orange\scenes\introOrange.Altis";
        };
        class Credits {
            directory = "A3\missions_f\data\scenes\credits1.Altis";
        };
        class Malden_intro {
            directory = "a3\Map_Malden_Scenes_F\scenes\Malden_intro.Malden";
        };
        class Tanoa_intro1 {
            directory = "a3\map_tanoa_scenes_f\scenes\tanoa_intro1.tanoa";
        };
        class Enoch_intro1 {
            directory = "a3\Map_Enoch_Scenes_F\Scenes\Enoch_intro1.Enoch";
        };
    };
};

class CfgMagazines {
    class vn_22mm_lume_mag;
    class vn_22mm_m22_smoke_mag: vn_22mm_lume_mag {
        displayName = "M22 22mm SMOKE [Filled Smoke]";
        ammo = "G_40mm_Smoke";
    };
    class 1Rnd_Smoke_Grenade_shell;
    class vn_40mm_m680_smoke_w_mag: 1Rnd_Smoke_Grenade_shell {
        displayName = "M680 40mm Smoke W [Filled Smoke]";
        ammo = "G_40mm_Smoke";
    };
};

class CfgMagazineWells {
    class potato_sog_22mmGL {
        ADDON[] = {"vn_22mm_m22_smoke_mag"};
    };
};

class CfgWeapons {
    class UGL_F;
    class Rifle_Base_F;
    class vn_rifle: Rifle_Base_F {
        class vn_ugl: UGL_F {
            // SOG mag proxies are different from vanilla so these look bad, but removing them could break old missions
            // magazineWell[] = {"CBA_40mm_M203","CBA_40mm_EGLM"};
        };
        class vn_ugl_p: UGL_F {
            // magazineWell[] = {"CBA_40mm_M203","CBA_40mm_EGLM"};
        };
        class vn_22mm_gl_muzzle: vn_ugl {
            // 40mm magWells don't make sense, but removing them could break old missions
            // This will add the m22 smoke to ALL 22mm rifle grenades (e.g. L1A1)
            magazineWell[] = {"CBA_40mm_M203","CBA_40mm_EGLM","potato_sog_22mmGL"};
        };
    };
};
