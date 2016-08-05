#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core","potato_assignGear","acre_api", "acre_sys_signal", "acre_sys_prc117f", "acre_sys_prc148", "acre_sys_prc343"};
        author[] = {"AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "ACE_Settings.hpp"
#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"
