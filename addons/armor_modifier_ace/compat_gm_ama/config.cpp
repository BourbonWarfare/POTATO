#include "\z\potato\addons\armor_modifier_ace\script_component.hpp"
#undef COMPONENT
#define COMPONENT compat_gm_ama

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_armor_modifier_ace",
            "gm_characters_gc_characters",
            "gm_characters_ge_characters",
            "gm_core_characters"
        };
        skipWhenMissingDependencies = 1;
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
