#include "\z\potato\addons\missileGuidanceCompat\script_component.hpp"
#undef COMPONENT
#define COMPONENT missileGuidanceCompat_patchCWR

#if __has_include("\cwr3\general\cwr3_intro\config.bin")
#else
#define PATCH_SKIP "CWR3"
#endif

#ifdef PATCH_SKIP
POTATO_PATCH_NOT_LOADED(ADDON,PATCH_SKIP)
#else
class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "cwr3_weapon_config"};
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};


class CfgMagazines {
	class CA_LauncherMagazine;
	class cwr3_redeye_m: CA_LauncherMagazine {
		ammo = QEGVAR(missileGuidanceCompat,redeye);
	};
};

#endif
