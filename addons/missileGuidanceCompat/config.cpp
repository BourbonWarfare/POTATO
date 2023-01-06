#include "script_component.hpp"

#ifndef POTATO_LEAN_RHS_CUP_HLC

class CfgPatches {
    class ADDON {
        units[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"potato_core", "ace_missileguidance", "CUP_Weapons_LoadOrder", "cwr3_weapon_config"};
        author = "Potato";
        authors[] = {"Dani (TCVM)"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgEventHandlers.hpp"

class ace_missileguidance_SeekerTypes {
    class SACLOS {
        functionName = QFUNC(seekerType_SACLOS_fix);
    };
};


#endif
