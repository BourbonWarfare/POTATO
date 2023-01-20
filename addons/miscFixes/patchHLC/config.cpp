#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchHLC

#if __has_include("\hlc_core\XEH_preInit.sqf")
#else
#define PATCH_SKIP "HLC"
#endif

#ifdef PATCH_SKIP
POTATO_PATCH_NOT_LOADED(ADDON,PATCH_SKIP)
#else
class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "hlcweapons_G36" };
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgWeapons {
    // add zeroing to iron sighted G36es
    class hlc_G36_base;
    class hlc_rifle_G36V : hlc_G36_base {
        discreteDistance[] = {100, 200, 300, 400, 500};
        discreteDistanceInitIndex = 1;
    };
};

#endif
