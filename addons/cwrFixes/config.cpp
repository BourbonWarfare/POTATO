#include "script_component.hpp"

#ifdef POTATO_LEAN_RHS_CUP_HLC
#define PATCH_SKIP POTATO_LEAN_RHS_CUP_HLC
#endif
#if __has_include("\cwr3\general\cwr3_intro\XEH_preInit.sqf")
#else
#define PATCH_SKIP "CWR3"
#endif

#ifdef PATCH_SKIP
PATCH_NOT_LOADED(ADDON,PATCH_SKIP)
#else
class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        magazines[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core", "cwr3_intro", "cwr3_vehicle_m41", "cwr3_vehicle_f4"
        };
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"

#endif
