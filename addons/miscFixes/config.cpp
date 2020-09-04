#include "script_component.hpp"

#ifndef POTATO_LEAN_CONFIGS

class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = { "potato_fakeNVG", "potato_arifle_RPK" };
        magazines[] = {
            "potato_75Rnd_762x39mm_tracer", "200Rnd_65x39_cased_Box_Tracer_Red",
            "200Rnd_65x39_cased_Box_Tracer_Green", "100Rnd_65x39_cased_Box_Tracer_Yellow",
            "100Rnd_65x39_cased_Box_Tracer_Red", "100Rnd_65x39_cased_Box_Tracer_Green",
            "150Rnd_762x54_Box_Tracer_Red", "150Rnd_762x54_Box_Tracer_Yellow",
            "100Rnd_762x54_Box_Tracer_Green", "100Rnd_762x54_Box_Tracer_Red",
            "100Rnd_762x54_Box_Tracer_Yellow"
        };
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "potato_core", "ace_ui",
            "rhs_c_weapons", "rhsusf_c_weapons",
            "CUP_Weapons_AK", "hlcweapons_G36",
            "rhsgref_c_troops"
            ,"Chernarus", "torabora"
            , "bg21_famas_prplredux"
        };
        author = "Potato";
        authors[] = {"PabstMirror", "AACO"};
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};


// Fix CELLE font error: (reqAddon: "mbg_celle2")
// class CfgLocationTypes {
//     class MBG_celle2_icon_A7 {
//         font = "PuristaMedium";
//     };
// };

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
#include "CfgFontFamilies.hpp"

#endif
