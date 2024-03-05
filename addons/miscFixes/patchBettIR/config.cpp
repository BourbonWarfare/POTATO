#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchBettIR

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "BettIR_Core"};
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class BettIR_Config {
    class CompatibleNightvisionGoggles {
        class CUP_NVG_PVS14_WP: CUP_NVG_PVS14 {};
        class CUP_NVG_PVS15_black_WP: CUP_NVG_PVS15_black {};
        class CUP_NVG_GPNVG_black_WP: CUP_NVG_GPNVG_black {};
    };
};