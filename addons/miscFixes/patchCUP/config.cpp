#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchCWR

#if __has_include("\CUP\Vehicles\CUP_Vehicles_LoadOrder\config.bin")
#else
#define PATCH_SKIP "CUP-Vehicles"
#endif

#ifdef PATCH_SKIP
POTATO_PATCH_NOT_LOADED(ADDON,PATCH_SKIP)
#else
class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "CUP_Vehicles_LoadOrder" };
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class DefaultEventHandlers;
class CfgVehicles {
    class Tank;
    class Tank_F: Tank {
        class EventHandlers;
    };
	class CUP_Leopard2_Base: Tank_F {
        class EventHandlers: EventHandlers {	
            init="";
            fired="_this call (uinamespace getvariable 'BIS_fnc_effectFired');";
            killed="_this call (uinamespace getvariable 'BIS_fnc_effectKilled');";
			class CUP_TrackedVehicles_Leopard2 {
				init = " \
					[_this select 0] call CUP_fnc_initNumbers; \
					_this call CUP_fnc_tankAmmoStoreInit; \
					if (local (_this select 0)) then {[(_this select 0), """", [], false] call bis_fnc_initVehicle;}; \
				";
				Fired = "[_this, ""recoil_source"", ""CUP_Vcannon_L55_veh""] call CUP_fnc_cannonAnimate;";
			};
		};
    };
    class CUP_M60A3_Base: Tank_F {
        class EventHandlers: DefaultEventHandlers {
            init="";
            fired="_this call (uinamespace getvariable 'BIS_fnc_effectFired');";
            killed="_this call (uinamespace getvariable 'BIS_fnc_effectKilled');";
            class CUP_TrackedVehicles_M60 {
                init = "_this call CUP_fnc_tankAmmoStoreInit;";
                Fired = "[_this, ""recoil_source"", ""CUP_Vcannon_M68_veh""] call CUP_fnc_cannonAnimate;";
            };
        };
    };
};



#endif
