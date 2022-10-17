#include "script_component.hpp"

#ifndef POTATO_LEAN_RHS_CUP_HLC

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = { "potato_fakeNVG", "potato_arifle_RPK" };
        magazines[] = {
            "200Rnd_65x39_cased_Box_Tracer_Red",
            "200Rnd_65x39_cased_Box_Tracer_Green", "100Rnd_65x39_cased_Box_Tracer_Yellow",
            "100Rnd_65x39_cased_Box_Tracer_Red", "100Rnd_65x39_cased_Box_Tracer_Green",
            "150Rnd_762x54_Box_Tracer_Red", "150Rnd_762x54_Box_Tracer_Yellow",
            "100Rnd_762x54_Box_Tracer_Green", "100Rnd_762x54_Box_Tracer_Red",
            "100Rnd_762x54_Box_Tracer_Yellow"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core", "ace_ui", "ace_fortify","CUP_Weapons_LoadOrder", "CUP_Vehicles_LoadOrder", "CUP_Creatures_People_LoadOrder","Chernarus"
        };
        author = "Potato";
        authors[] = {"PabstMirror", "AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
    BWC_CONFIG(potato_fortify);
};

// Undo ACE's changes to system messages text brightness
class RscChatListDefault {
    colorBackground[] = {0,0,0,0.3};
    colorMessageProtocol[] = {0.65,0.65,0.65,0.9};
};

#include "CfgAmmo.hpp"
#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
//#include "CfgFontFamilies.hpp"

#endif
