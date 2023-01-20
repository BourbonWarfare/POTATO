#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchFallujah

#if __has_include("\fallujah_hou\dum_istan2.p3d")
#else
#define PATCH_SKIP "Fallujah"
#endif

#ifdef PATCH_SKIP
POTATO_PATCH_NOT_LOADED(ADDON,PATCH_SKIP)
#else
class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "fallujah_hou" };
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgVehicles {
    class Building;
    class NonStrategic: Building {
        class DestructionEffects;
    };    
    class HouseBase: NonStrategic {};    
    class House: HouseBase {
        class DestructionEffects: DestructionEffects {
            class Smoke1 {
                type="HouseDestructionSmoke3";
            };
            class Smoke2: Smoke1 {
                type="HouseDestructionSmoke4";
            };
            class Smoke3: Smoke1 {
                type="HouseDestrSmokeLong";
            };
        };
    };
};

#endif
