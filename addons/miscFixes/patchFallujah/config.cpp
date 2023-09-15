#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchFallujah

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "fallujah_hou" };
        skipWhenMissingDependencies = 1;
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
