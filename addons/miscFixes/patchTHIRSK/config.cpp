#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchTHIRSK

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "THIRSK_Clouds" };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CBA_Extended_EventHandlers;
class CfgVehicles {
    class THIRSK_WeatherPreSet;
    class TH_SNOWING1: THIRSK_WeatherPreSet { XEH_ENABLED; }; // "Snowing Strenght 1" 3237942199
    class TH_SNOWING2: THIRSK_WeatherPreSet { XEH_ENABLED; }; // "Snowing Strenght 2" 3237942199
    class TH_SNOWING3: THIRSK_WeatherPreSet { XEH_ENABLED; }; // "Snowing Strenght 3" 3237942199
    class TH_SNOWING4: THIRSK_WeatherPreSet { XEH_ENABLED; }; // "Snowing Strenght 4" 3237942199
    class TH_FOG1: THIRSK_WeatherPreSet { XEH_ENABLED; }; // "Fog Strenght 1" 3237942199
    class TH_FOG2: THIRSK_WeatherPreSet { XEH_ENABLED; }; // "Fog Strenght 2" 3237942199
    class TH_FOG3: THIRSK_WeatherPreSet { XEH_ENABLED; }; // "Fog Strenght 3" 3237942199
    class TH_SNOWSTORM1: THIRSK_WeatherPreSet { XEH_ENABLED; }; // "Snowstorm" 3237942199
};
