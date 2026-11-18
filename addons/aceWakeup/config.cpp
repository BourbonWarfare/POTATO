#include "script_component.hpp"

class CfgFunctions {
    class overwrite_ace_medical_status {
        tag = "ace_medical_status";
        class ace_medical_status {
            class hasStableVitals {
                file = "\potato_ace_wakeup\functions\fnc_hasStableVitals.sqf";
            };
        };
    };
};

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "ace_medical" };\
        author = "Potato";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};