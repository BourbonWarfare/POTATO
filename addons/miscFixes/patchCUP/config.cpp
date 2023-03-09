#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchCUP

#if __has_include("\CUP\Vehicles\CUP_Vehicles_LoadOrder\config.bin")
#else
#define PATCH_SKIP "CUP Vehicles"
#endif

#ifdef PATCH_SKIP
POTATO_PATCH_NOT_LOADED(ADDON,PATCH_SKIP)
#else
class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "CUP_Weapons_LoadOrder", "CUP_Vehicles_LoadOrder", "CUP_Creatures_People_LoadOrder" };
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
    // Fix Leo/Paton tank smoke not working - should be fixed in next cup release
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

class CfgRecoils
{
	class recoil_m240
	{
		muzzleOuter[] = {0.9,1.3,0.35,0.25};
		kickBack[] = {0.015,0.02};
		permanent = 0.05;
		temporary = 0.005;
	};
	class recoil_pkm
	{
		muzzleOuter[] = {1.1,0.8,0.4,0.2};
		kickBack[] = {0.015,0.03};
		permanent = 0.1;
		temporary = 0.005;
	};
	class recoil_SAW
	{
		muzzleOuter[] = {0.8,1.4,0.35,0.25};
		kickBack[] = {0.015,0.02};
		permanent = 0.08;
		temporary = 0.009;
	};
};

class CfgWeapons {
    class CUP_arifle_RPK74;
    class potato_arifle_RPK: CUP_arifle_RPK74 {
        // CUP_arifle_RPK74 is actually a chambered in 7.62 and just called RPK in-game
        // CUP_arifle_RPK74_45 is the 5.45 version and is called RPK-74 in game
        // so this isn't needed anymore
        scope = 1;
        UiPicture = "\A3\weapons_f\data\UI\icon_mg_CA.paa"; // STHUD/DUI Compat
    };

    // Add "plot armor" to some vests /* From V_PlateCarrier2_rgr */
    class ItemCore;
    class CUP_Vest_Camo_Base;
    class CUP_V_B_ALICE: CUP_Vest_Camo_Base {
        class ItemInfo;
    };
    class rhsgref_alice_webbing_bwArmorMod: CUP_V_B_Alice { // must keep old classname, but this is now based on CUP
        displayName = "ALICE Webbing [coop plot armor]";
        descriptionShort = "Armor Level IV";
        class ItemInfo: ItemInfo {
            class HitpointsProtectionInfo {
                class Chest {
                    HitpointName = "HitChest";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Diaphragm {
                    HitpointName = "HitDiaphragm";
                    armor = 20;
                    PassThrough = 0.2;
                };
                class Abdomen {
                    hitpointName = "HitAbdomen";
                    armor = 20;
                    passThrough = 0.2;
                };
                class Body {
                    hitpointName = "HitBody";
                    passThrough = 0.2;
                };
            };
        };
    };

	class CUP_lmg_M240: Rifle_Long_Base_F { // Applies good cool m240 custom recoil values defined in cfgrecoil
			recoil = "recoil_m240";
	};
	
	class CUP_lmg_PKM: Rifle_Long_Base_F { // Applies good cool PKM custom recoil values defined in cfgrecoil
			recoil = "recoil_pkm";
	};
	
	class CUP_lmg_minimipara: CUP_saw_base { // Applies good cool M249 custom recoil values defined in cfgrecoil
			recoil = "recoil_SAW";
	};
};

#endif
