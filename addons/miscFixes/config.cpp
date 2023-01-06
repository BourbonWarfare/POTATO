#include "script_component.hpp"

#ifdef POTATO_LEAN_RHS_CUP_HLC
#define PATCH_SKIP POTATO_LEAN_RHS_CUP_HLC
#endif

#if __has_include("\CUP\Vehicles\CUP_Vehicles_Core\basicDefines.hpp")
#else
#define PATCH_SKIP "CUP Vehicles"
#endif

#ifdef PATCH_SKIP
PATCH_NOT_LOADED(ADDON,PATCH_SKIP)
#else
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
            "potato_core", "ace_ui", "ace_fortify", "ace_missileguidance",
            "rhs_main_loadorder",
            "CUP_Weapons_LoadOrder", "CUP_Vehicles_LoadOrder", "CUP_Creatures_People_LoadOrder"
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

class ace_missileguidance_SeekerTypes {
    class SACLOS {
        functionName = QFUNC(seekerType_SACLOS_fix);
    };
};


#include "CfgAmmo.hpp"
#include "CfgEden.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "CfgFontFamilies.hpp"

#endif
