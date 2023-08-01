#include "\z\potato\addons\miscFixes\script_component.hpp"
#undef COMPONENT
#define COMPONENT miscFixes_patchRHSAFRF

#ifdef POTATO_LEAN_RHS_CUP_HLC
#define PATCH_SKIP POTATO_LEAN_RHS_CUP_HLC
#endif
#if __has_include("\rhsafrf\addons\rhs_main\config.bin")
#else
#define PATCH_SKIP "RHS AFRF"
#endif

#ifdef PATCH_SKIP
POTATO_PATCH_NOT_LOADED(ADDON,PATCH_SKIP)
#else
class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = { "potato_core", "rhs_main_loadorder" };
        author = "Bourbon Warfare";
        authorUrl = "https://github.com/BourbonWarfare/POTATO";
        VERSION_CONFIG;
    };
};

class CfgWeapons {
    class ItemCore;
    class Vest_Camo_Base: ItemCore {
        class ItemInfo;
    };
    class rhs_vydra_3m: Vest_Camo_Base {
        class ItemInfo: ItemInfo {};
    };
    class rhs_vydra_3m_bwArmorMod: rhs_vydra_3m {
        displayName = "Vydra-3M [coop plot armor]";
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
	class rhs_6b23: Vest_Camo_Base
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ca.paa";
		dlc = "RHS_AFRF";
		scope = 2;
		displayName = "$STR_RHS_6B23_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23";
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_co.paa"};
		descriptionShort = "Armor Level 4 - nerfed";
		class ItemInfo: ItemInfo
		{
			hiddenSelections[] = {"Camo1","Camo2"};
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23";
			containerClass = "Supply20";
			mass = 60;
			class HitpointsProtectionInfo
			{
				class Neck
				{
					HitpointName = "HitNeck";
					armor = 8;
					PassThrough = 0.4;
				};
				class Chest
				{
					HitpointName = "HitChest";
					armor = 15;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 15;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 15;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class rhs_6b23_crew: rhs_6b23
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_crew_ca.paa";
		displayName = "$STR_RHS_6B23CREW_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh46";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh46";
			containerClass = "Supply90";
			mass = 70;
		};
	};
	class rhs_6b23_engineer: rhs_6b23
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_engineer_ca.paa";
		displayName = "$STR_RHS_6B23ENGINEER_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_engineer";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_engineer";
			containerClass = "Supply80";
			mass = 65;
		};
	};
	class rhs_6b23_medic: rhs_6b23
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_medic_ca.paa";
		displayName = "$STR_RHS_6B23MEDIC_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_medic";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_medic";
			containerClass = "Supply130";
			mass = 80;
		};
	};
	class rhs_6b23_rifleman: rhs_6b23
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_rifleman_ca.paa";
		displayName = "$STR_RHS_6B23RIFLEMAN_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_rifleman";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_rifleman";
			containerClass = "Supply80";
			mass = 65;
		};
	};
	class rhs_6b23_crewofficer: rhs_6b23
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_crewofficer_ca.paa";
		displayName = "$STR_RHS_6B23CREWOFFICER_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_crewofficer";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_crewofficer";
			containerClass = "Supply60";
			mass = 65;
		};
	};
	class rhs_6b23_sniper: rhs_6b23
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_sniper_ca.paa";
		displayName = "$STR_RHS_6B23SNIPER_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_sniper";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_sniper";
			containerClass = "Supply80";
			mass = 65;
		};
	};
	class rhs_6b23_6sh92: rhs_6b23
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_6sh92_ca.paa";
		displayName = "$STR_RHS_6B236SH92_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92";
			containerClass = "Supply100";
			mass = 75;
			class HitpointsProtectionInfo
			{
				class Neck
				{
					HitpointName = "HitNeck";
					armor = 12;
					PassThrough = 0.3;
				};
				class Chest
				{
					HitpointName = "HitChest";
					armor = 15;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 15;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 15;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class rhs_6b23_6sh92_vog: rhs_6b23_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_6sh92_vog_ca.paa";
		displayName = "$STR_RHS_6B236SH92VOG_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_vog";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_vog";
			containerClass = "Supply120";
			mass = 80;
		};
	};
	class rhs_6b23_6sh92_vog_headset: rhs_6b23_6sh92_vog
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_6sh92_vog_headset_ca.paa";
		displayName = "$STR_RHS_6B236SH92VOGHEADSET_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_vog_headset";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_vog_headset";
		};
	};
	class rhs_6b23_6sh92_headset: rhs_6b23_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_6sh92_headset_ca.paa";
		displayName = "$STR_RHS_6B236SH92HEADSET_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_headset";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_headset";
		};
	};
	class rhs_6b23_6sh92_headset_mapcase: rhs_6b23_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_6sh92_headset_mapcase_ca.paa";
		displayName = "$STR_RHS_6B236SH92HEADSETMAPCASE_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_headset_mapcase";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_headset_mapcase";
			containerClass = "Supply120";
			mass = 80;
		};
	};
	class rhs_6b23_6sh92_radio: rhs_6b23_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_6sh92_radio_ca.paa";
		displayName = "$STR_RHS_6B236SH92RADIO_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_radio";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_radio";
		};
	};
	class rhs_6sh46: Vest_Camo_Base
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh46_ca.paa";
		dlc = "RHS_AFRF";
		scope = 2;
		displayName = "$STR_RHS_6SH46_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh46";
		hiddenSelectionsTextures[] = {};
		descriptionShort = "No Armor";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh46";
			containerClass = "Supply40";
			mass = 15;
			class HitpointsProtectionInfo
			{
				class Body
				{
					hitpointName = "HitBody";
					armor = 0;
					passThrough = 1;
				};
			};
		};
	};
	class rhs_vest_commander: Vest_Camo_Base
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_vest_commander_ca.paa";
		dlc = "RHS_AFRF";
		scope = 2;
		displayName = "$STR_RHS_MAPCASEANDHOLSTER_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_commander";
		hiddenSelectionsTextures[] = {};
		descriptionShort = "No Armor";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_commander";
			containerClass = "Supply40";
			mass = 20;
			class HitpointsProtectionInfo
			{
				class Body
				{
					hitpointName = "HitBody";
					armor = 0;
					passThrough = 1;
				};
			};
		};
	};
	class rhs_vest_pistol_holster: rhs_vest_commander
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_vest_pistol_holster_ca.paa";
		displayName = "$STR_RHS_HOLSTER_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_pistol_holster";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_pistol_holster";
			containerClass = "Supply20";
			mass = 5;
		};
	};
	class rhs_6b23_digi: rhs_6b23
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMER_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_crew: rhs_6b23_crew
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_crew_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMERCREW_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_engineer: rhs_6b23_engineer
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_engineer_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMERENGINEER_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_medic: rhs_6b23_medic
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_medic_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMERMEDIC_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_rifleman: rhs_6b23_rifleman
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_rifleman_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMERRIFLEMAN_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_crewofficer: rhs_6b23_crewofficer
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_crewofficer_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMERCREWOFFICER_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_sniper: rhs_6b23_sniper
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_sniper_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMERSNIPER_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_6sh92: rhs_6b23_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_6sh92_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMER6SH92_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_6sh92_vog: rhs_6b23_6sh92_vog
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_6sh92_vog_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMER6SH92VOG_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_6sh92_vog_headset: rhs_6b23_6sh92_vog_headset
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_6sh92_vog_headset_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMER6SH92VOGHEADSET_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_6sh92_headset: rhs_6b23_6sh92_headset
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_6sh92_headset_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMER6SH92HEADSET_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_6sh92_headset_mapcase: rhs_6b23_6sh92_headset_mapcase
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_6sh92_headset_mapcase_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMER6SH92HEADSETMAPCASE_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_6sh92_radio: rhs_6b23_6sh92_radio
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_6sh92_radio_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMER6SH92RADIO_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_6sh92_Spetsnaz: rhs_6b23_6sh92_radio
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_6sh92_Spetsnaz_ca.paa";
		displayName = "$STR_RHS_6B23EMR6SH92RADIOSPNZ_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_radio_spetsnaz";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_radio_spetsnaz";
			containerClass = "Supply100";
			mass = 70;
			class HitpointsProtectionInfo
			{
				class Neck
				{
					HitpointName = "HitNeck";
					armor = 8;
					PassThrough = 0.4;
				};
				class Chest
				{
					HitpointName = "HitChest";
					armor = 15;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 15;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 15;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_6sh92_Vog_Radio_Spetsnaz: rhs_6b23_6sh92_radio
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_6sh92_Vog_Radio_Spetsnaz_ca.paa";
		displayName = "$STR_RHS_6B23EMR6SH92VOGRADIOSPNZ_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_vog_radio_spetsnaz";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_vog_radio_spetsnaz";
			containerClass = "Supply120";
			mass = 75;
		};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_6sh92_headset_spetsnaz: rhs_6b23_6sh92_radio
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_6sh92_headset_spetsnaz_ca.paa";
		displayName = "$STR_RHS_6B23EMR6SH92HEADSETSPNZ_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_headset_spetsnaz";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_headset_spetsnaz";
		};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_6sh92_spetsnaz2: rhs_6b23_6sh92_radio
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_6sh92_spetsnaz2_ca.paa";
		displayName = "$STR_RHS_6B23EMR6SH92SPNZ_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_spetsnaz";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_spetsnaz";
		};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_digi_6sh92_Vog_Spetsnaz: rhs_6b23_6sh92_radio
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_6sh92_Vog_Spetsnaz_ca.paa";
		displayName = "$STR_RHS_6B23EMR6SH92VOGSPNZ_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_vog_spetsnaz";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_6sh92_vog_spetsnaz";
			containerClass = "Supply120";
			mass = 75;
		};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b23_ML: rhs_6b23
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ML_ca.paa";
		displayName = "$STR_RHS_6B23ML_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_ML_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_ML_co.paa"};
	};
	class rhs_6b23_ML_crew: rhs_6b23_crew
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ML_crew_ca.paa";
		displayName = "$STR_RHS_6B23MLCREW_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_ML_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_ML_co.paa"};
	};
	class rhs_6b23_ML_engineer: rhs_6b23_engineer
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ML_engineer_ca.paa";
		displayName = "$STR_RHS_6B23MLENGINEER_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_ML_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_ML_co.paa"};
	};
	class rhs_6b23_ML_medic: rhs_6b23_medic
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ML_medic_ca.paa";
		displayName = "$STR_RHS_6B23MLMEDIC_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_ML_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_ML_co.paa"};
	};
	class rhs_6b23_ML_rifleman: rhs_6b23_rifleman
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ML_rifleman_ca.paa";
		displayName = "$STR_RHS_6B23MLRIFLEMAN_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_ML_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_ML_co.paa"};
	};
	class rhs_6b23_ML_crewofficer: rhs_6b23_crewofficer
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ML_crewofficer_ca.paa";
		displayName = "$STR_RHS_6B23MLCREWOFFICER_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_ML_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_ML_co.paa"};
	};
	class rhs_6b23_ML_sniper: rhs_6b23_sniper
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ML_sniper_ca.paa";
		displayName = "$STR_RHS_6B23MLSNIPER_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_ML_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_ML_co.paa"};
	};
	class rhs_6b23_ML_6sh92: rhs_6b23_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ML_6sh92_ca.paa";
		displayName = "$STR_RHS_6B23ML6SH92_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_ML_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_ML_co.paa"};
	};
	class rhs_6b23_ML_6sh92_vog: rhs_6b23_6sh92_vog
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ML_6sh92_vog_ca.paa";
		displayName = "$STR_RHS_6B23ML6SH92VOG_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_ML_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_ML_co.paa"};
	};
	class rhs_6b23_ML_6sh92_vog_headset: rhs_6b23_6sh92_vog_headset
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ML_6sh92_vog_headset_ca.paa";
		displayName = "$STR_RHS_6B23ML6SH92VOGHEADSET_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_ML_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_ML_co.paa"};
	};
	class rhs_6b23_ML_6sh92_headset: rhs_6b23_6sh92_headset
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ML_6sh92_headset_ca.paa";
		displayName = "$STR_RHS_6B23ML6SH92HEADSET_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_ML_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_ML_co.paa"};
	};
	class rhs_6b23_ML_6sh92_headset_mapcase: rhs_6b23_6sh92_headset_mapcase
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ML_6sh92_headset_mapcase_ca.paa";
		displayName = "$STR_RHS_6B23ML6SH92HEADSETMAPCASE_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_ML_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_ML_co.paa"};
	};
	class rhs_6b23_ML_6sh92_radio: rhs_6b23_6sh92_radio
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ML_6sh92_radio_ca.paa";
		displayName = "$STR_RHS_6B23ML6SH92RADIO_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_ML_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_ML_co.paa"};
	};
	class rhs_6b23_vydra_3m: rhs_6b23_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_vydra_3m_ca.paa";
		displayName = "$STR_RHS_6B23VYDRA3M_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_vydra_3m";
		hiddenSelections[] = {"Camo1","Camo2","Camo3"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_co.paa","rhsafrf\addons\rhs_infantry\data\crew_equip_co.paa"};
		class ItemInfo: ItemInfo
		{
			hiddenSelections[] = {"Camo1","Camo2","Camo3"};
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_vydra_3m";
			containerClass = "Supply100";
			mass = 75;
			class HitpointsProtectionInfo
			{
				class Neck
				{
					HitpointName = "HitNeck";
					armor = 8;
					PassThrough = 0.4;
				};
				class Chest
				{
					HitpointName = "HitChest";
					armor = 15;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 15;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 15;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class rhs_6b23_digi_vydra_3m: rhs_6b23_vydra_3m
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_digi_vydra_3m_ca.paa";
		displayName = "$STR_RHS_6B23EMRVYDRA3M_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_vydra_3m";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa","rhsafrf\addons\rhs_infantry\data\crew_equip_co.paa"};
	};
	class rhs_6b23_ML_vydra_3m: rhs_6b23_vydra_3m
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_ML_vydra_3m_ca.paa";
		displayName = "$STR_RHS_6B23MLVYDRA3M_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b23_vydra_3m";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_ML_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_ML_co.paa","rhsafrf\addons\rhs_infantry\data\crew_equip_co.paa"};
	};
	class rhs_6b23_6sh116: rhs_6b23_digi
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_6sh116_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMER6SH116_NAME";
		model = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b23_6sh116";
		hiddenSelections[] = {"Camo1","Camo2","Camo3"};
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b23_6sh116";
			hiddenSelections[] = {"Camo1","Camo2","Camo3"};
			containerClass = "Supply140";
			mass = 80;
			class HitpointsProtectionInfo
			{
				class Neck
				{
					HitpointName = "HitNeck";
					armor = 8;
					PassThrough = 0.3;
				};
				class Chest
				{
					HitpointName = "HitChest";
					armor = 15;
					PassThrough = 0.3;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 15;
					PassThrough = 0.3;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 15;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry2\data\rhs_6sh116_co.paa","rhsafrf\addons\rhs_infantry2\data\rhs_6sh116_gear1_co.paa"};
	};
	class rhs_6b23_6sh116_flora: rhs_6b23_6sh116
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_6sh116_flora_ca.paa";
		displayName = "$STR_RHS_6B23FLORA6SH116_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_co.paa","rhsafrf\addons\rhs_infantry2\data\rhs_6sh116_flora_co.paa","rhsafrf\addons\rhs_infantry2\data\rhs_6sh116_gear1_flora_co.paa"};
	};
	class rhs_6b23_6sh116_od: rhs_6b23_6sh116
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_6sh116_od_ca.paa";
		displayName = "$STR_RHS_6B23OD6SH116_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_olive_co.paa","rhsafrf\addons\rhs_infantry2\data\rhs_6sh116_od_co.paa","rhsafrf\addons\rhs_infantry2\data\rhs_6sh116_gear1_od_co.paa"};
	};
	class rhs_6b23_6sh116_vog: rhs_6b23_6sh116
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_6sh116_vog_ca.paa";
		displayName = "$STR_RHS_6B23EMRSUMMER6SH116VOG_NAME";
		model = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b23_6sh116_vog";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b23_6sh116_vog";
			mass = 85;
			containerClass = "Supply160";
		};
	};
	class rhs_6b23_6sh116_vog_flora: rhs_6b23_6sh116_vog
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_6sh116_vog_flora_ca.paa";
		displayName = "$STR_RHS_6B23FLORA6SH116VOG_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_co.paa","rhsafrf\addons\rhs_infantry2\data\rhs_6sh116_flora_co.paa","rhsafrf\addons\rhs_infantry2\data\rhs_6sh116_gear1_flora_co.paa"};
		model = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b23_6sh116_vog";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b23_6sh116_vog";
		};
	};
	class rhs_6b23_6sh116_vog_od: rhs_6b23_6sh116_vog
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b23_6sh116_vog_od_ca.paa";
		displayName = "$STR_RHS_6B23OD6SH116VOG_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_olive_co.paa","rhsafrf\addons\rhs_infantry2\data\rhs_6sh116_od_co.paa","rhsafrf\addons\rhs_infantry2\data\rhs_6sh116_gear1_od_co.paa"};
		model = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b23_6sh116_vog";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b23_6sh116_vog";
		};
	};
	class rhs_6b13: rhs_6b23
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_ca.paa";
		displayName = "$STR_RHS_6B13_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b13";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b13_vsr_co.paa","rhsafrf\addons\rhs_infantry2\data\gearpack1_6sh92_vsr_co.paa"};
		descriptionShort = "Armor Level 6";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b13";
			containerClass = "Supply20";
			mass = 80;
			class HitpointsProtectionInfo
			{
				class Neck
				{
					HitpointName = "HitNeck";
					armor = 10;
					PassThrough = 0.3;
				};
				class Chest
				{
					HitpointName = "HitChest";
					armor = 15;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 15;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 15;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class rhs_6b13_crewofficer: rhs_6b13
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_crewofficer_ca.paa";
		displayName = "$STR_RHS_6B13CREWOFFICER_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b13_crewofficer";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b13_crewofficer";
			containerClass = "Supply40";
			mass = 85;
		};
	};
	class rhs_6b13_6sh92: rhs_6b13
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_6sh92_ca.paa";
		displayName = "$STR_RHS_6B136SH92_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b13_6sh92";
		descriptionShort = "Armor Level 6";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b13_6sh92";
			containerClass = "Supply100";
			mass = 95;
			class HitpointsProtectionInfo
			{
				class Neck
				{
					HitpointName = "HitNeck";
					armor = 10;
					PassThrough = 0.3;
				};
				class Chest
				{
					HitpointName = "HitChest";
					armor = 15;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 15;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 15;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class rhs_6b13_6sh92_vog: rhs_6b13_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_6sh92_vog_ca.paa";
		displayName = "$STR_RHS_6B136SH92VOG_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b13_6sh92_vog";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b13_6sh92_vog";
			containerClass = "Supply120";
			mass = 100;
		};
	};
	class rhs_6b13_6sh92_headset_mapcase: rhs_6b13_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_6sh92_headset_mapcase_ca.paa";
		displayName = "$STR_RHS_6B136SH92HEADSETMAPCASE_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b13_6sh92_headset_mapcase";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b13_6sh92_headset_mapcase";
			containerClass = "Supply120";
			mass = 100;
		};
	};
	class rhs_6b13_6sh92_radio: rhs_6b13_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_6sh92_radio_ca.paa";
		displayName = "$STR_RHS_6B136SH92RADIO_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b13_6sh92_radio";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6b13_6sh92_radio";
		};
	};
	class rhs_6b13_EMR: rhs_6b13
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_EMR_ca.paa";
		displayName = "$STR_RHS_6B13EMRSUMMER_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b13_emr_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b13_EMR_6sh92: rhs_6b13_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_EMR_6sh92_ca.paa";
		displayName = "$STR_RHS_6B13EMR6SH92_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b13_emr_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b13_EMR_6sh92_vog: rhs_6b13_6sh92_vog
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_EMR_6sh92_vog_ca.paa";
		displayName = "$STR_RHS_6B13EMR6SH92VOG_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b13_emr_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b13_EMR_6sh92_headset_mapcase: rhs_6b13_6sh92_headset_mapcase
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_EMR_6sh92_headset_mapcase_ca.paa";
		displayName = "$STR_RHS_6B13EMR6SH92HEADSETMAPCASE_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b13_emr_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b13_EMR_6sh92_radio: rhs_6b13_6sh92_radio
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_EMR_6sh92_radio_ca.paa";
		displayName = "$STR_RHS_6B13EMR6SH92RADIO_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b13_emr_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6b13_Flora: rhs_6b13
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_Flora_ca.paa";
		displayName = "$STR_RHS_6B13FLORA_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b13_Flora_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_co.paa"};
	};
	class rhs_6b13_Flora_crewofficer: rhs_6b13_crewofficer
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_Flora_crewofficer_ca.paa";
		displayName = "$STR_RHS_6B13FLORACREWOFFICER_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b13_Flora_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_co.paa"};
	};
	class rhs_6b13_Flora_6sh92: rhs_6b13_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_Flora_6sh92_ca.paa";
		displayName = "$STR_RHS_6B13FLORA6SH92_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b13_Flora_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_co.paa"};
	};
	class rhs_6b13_Flora_6sh92_vog: rhs_6b13_6sh92_vog
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_Flora_6sh92_vog_ca.paa";
		displayName = "$STR_RHS_6B13FLORA6SH92VOG_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b13_Flora_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_co.paa"};
	};
	class rhs_6b13_Flora_6sh92_headset_mapcase: rhs_6b13_6sh92_headset_mapcase
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_Flora_6sh92_headset_mapcase_ca.paa";
		displayName = "$STR_RHS_6B13FLORA6SH92HEADSETMAPCASE_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b13_Flora_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_co.paa"};
	};
	class rhs_6b13_Flora_6sh92_radio: rhs_6b13_6sh92_radio
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b13_Flora_6sh92_radio_ca.paa";
		displayName = "$STR_RHS_6B13FLORA6SH92RADIO_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b13_Flora_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_co.paa"};
	};
	class rhs_6b43: rhs_6b23
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b43_ca.paa";
		displayName = "$STR_RHS_6B43_NAME";
		model = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b43_m";
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6B43_co.paa"};
		descriptionShort = "Armor Level 6";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b43_m";
			containerClass = "Supply20";
			mass = 80;
			class HitpointsProtectionInfo
			{
				class Neck
				{
					HitpointName = "HitNeck";
					armor = 15;
					PassThrough = 0.3;
				};
				class Chest
				{
					HitpointName = "HitChest";
					armor = 15;
					PassThrough = 0.1;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 15;
					PassThrough = 0.1;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 15;
					passThrough = 0.3;
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.3;
				};
			};
		};
	};
	class rhs_6sh92: Vest_Camo_Base
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_ca.paa";
		dlc = "RHS_AFRF";
		scope = 2;
		displayName = "$STR_RHS_6SH92_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92";
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_co.paa"};
		descriptionShort = "No Armor";
		class ItemInfo: ItemInfo
		{
			hiddenSelections[] = {"Camo1","Camo2"};
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92";
			containerClass = "Supply100";
			mass = 15;
			class HitpointsProtectionInfo
			{
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 3;
					passThrough = 0.6;
				};
				class Body
				{
					hitpointName = "HitBody";
					armor = 0;
					passThrough = 0.8;
				};
			};
		};
	};
	class rhs_6sh92_vog: rhs_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_vog_ca.paa";
		displayName = "$STR_RHS_6SH92VOG_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92_vog";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92_vog";
			containerClass = "Supply120";
			mass = 20;
		};
	};
	class rhs_6sh92_vog_headset: rhs_6sh92_vog
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_vog_headset_ca.paa";
		displayName = "$STR_RHS_6SH92VOGHEADSET_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92_vog_headset";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92_vog_headset";
		};
	};
	class rhs_6sh92_headset: rhs_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_headset_ca.paa";
		displayName = "$STR_RHS_6SH92HEADSET_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92_headset";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92_headset";
		};
	};
	class rhs_6sh92_radio: rhs_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_radio_ca.paa";
		displayName = "$STR_RHS_6SH92RADIO_NAME";
		model = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92_radio";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry\gear\vests\rhs_6sh92_radio";
		};
	};
	class rhs_6sh92_digi: rhs_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_digi_ca.paa";
		displayName = "$STR_RHS_6SH92EMRSUMMER_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6sh92_digi_vog: rhs_6sh92_vog
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_digi_vog_ca.paa";
		displayName = "$STR_RHS_6SH92EMRSUMMERVOG_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6sh92_digi_vog_headset: rhs_6sh92_vog_headset
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_digi_vog_headset_ca.paa";
		displayName = "$STR_RHS_6SH92EMRSUMMERVOGHEADSET_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6sh92_digi_headset: rhs_6sh92_headset
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_digi_headset_ca.paa";
		displayName = "$STR_RHS_6SH92EMRSUMMERHEADSET_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6sh92_digi_radio: rhs_6sh92_radio
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_digi_radio_ca.paa";
		displayName = "$STR_RHS_6SH92EMRSUMMERRADIO_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_digi_co.paa","rhsafrf\addons\rhs_infantry\data\gearpack1_6sh92_digi_co.paa"};
	};
	class rhs_6sh92_vsr: rhs_6sh92
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_vsr_ca.paa";
		displayName = "$STR_RHS_6SH92VSR_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_olive_co.paa","rhsafrf\addons\rhs_infantry2\data\gearpack1_6sh92_vsr_co.paa"};
	};
	class rhs_6sh92_vsr_vog: rhs_6sh92_vog
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_vsr_vog_ca.paa";
		displayName = "$STR_RHS_6SH92VSRVOG_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_olive_co.paa","rhsafrf\addons\rhs_infantry2\data\gearpack1_6sh92_vsr_co.paa"};
	};
	class rhs_6sh92_vsr_vog_headset: rhs_6sh92_vog_headset
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_vsr_vog_headset_ca.paa";
		displayName = "$STR_RHS_6SH92VSRVOGHEADSET_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_olive_co.paa","rhsafrf\addons\rhs_infantry2\data\gearpack1_6sh92_vsr_co.paa"};
	};
	class rhs_6sh92_vsr_headset: rhs_6sh92_headset
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_vsr_headset_ca.paa";
		displayName = "$STR_RHS_6SH92VSRHEADSET_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_olive_co.paa","rhsafrf\addons\rhs_infantry2\data\gearpack1_6sh92_vsr_co.paa"};
	};
	class rhs_6sh92_vsr_radio: rhs_6sh92_radio
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6sh92_vsr_radio_ca.paa";
		displayName = "$STR_RHS_6SH92VSRRADIO_NAME";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry\data\6b23_olive_co.paa","rhsafrf\addons\rhs_infantry2\data\gearpack1_6sh92_vsr_co.paa"};
	};
	class rhs_6b5: rhs_6b23
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_ca.paa";
		displayName = "$STR_RHS_6B5_OLIVE_NAME";
		model = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b5_rifleman";
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_co.paa"};
		descriptionShort = "Armor Level 5";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b5_rifleman";
			containerClass = "Supply80";
			mass = 132;
			class HitpointsProtectionInfo
			{
				class Neck
				{
					HitpointName = "HitNeck";
					armor = 10;
					PassThrough = 0.5;
				};
				class Chest
				{
					HitpointName = "HitChest";
					armor = 15;
					PassThrough = 0.2;
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 15;
					PassThrough = 0.2;
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 15;
					passThrough = 0.2;
				};
				class Body
				{
					hitpointName = "HitBody";
					armor = 15;
					passThrough = 0.5;
				};
			};
		};
	};
	class rhs_6b5_officer: rhs_6b5
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_officer_ca.paa";
		displayName = "$STR_RHS_6B5_OFFICER_OLIVE_NAME";
		model = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b5_officer";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b5_officer";
			containerClass = "Supply120";
			mass = 142;
		};
	};
	class rhs_6b5_medic: rhs_6b5
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_medic_ca.paa";
		displayName = "$STR_RHS_6B5_MEDIC_OLIVE_NAME";
		model = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b5_medic";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b5_medic";
			containerClass = "Supply140";
			mass = 152;
		};
	};
	class rhs_6b5_sniper: rhs_6b5
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_sniper_ca.paa";
		displayName = "$STR_RHS_6B5_SNIPER_OLIVE_NAME";
		model = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b5_sniper";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b5_sniper";
			containerClass = "Supply90";
			mass = 137;
		};
	};
	class rhs_6b5_rifleman: rhs_6b5
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_rifleman_ca.paa";
		displayName = "$STR_RHS_6B5_RIFLEMAN_OLIVE_NAME";
		model = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b5_6sh46_rifleman";
		class ItemInfo: ItemInfo
		{
			uniformModel = "rhsafrf\addons\rhs_infantry2\gear\vests\rhs_6b5_6sh46_rifleman";
			containerClass = "Supply130";
			mass = 147;
		};
	};
	class rhs_6b5_khaki: rhs_6b5
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_khaki_ca.paa";
		Scope = 2;
		displayName = "$STR_RHS_6B5_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_khaki_co.paa"};
	};
	class rhs_6b5_officer_khaki: rhs_6b5_officer
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_officer_khaki_ca.paa";
		displayName = "$STR_RHS_6B5_OFFICER_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_khaki_co.paa"};
	};
	class rhs_6b5_medic_khaki: rhs_6b5_medic
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_medic_khaki_ca.paa";
		displayName = "$STR_RHS_6B5_MEDIC_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_khaki_co.paa"};
	};
	class rhs_6b5_sniper_khaki: rhs_6b5_sniper
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_sniper_khaki_ca.paa";
		displayName = "$STR_RHS_6B5_SNIPER_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_khaki_co.paa"};
	};
	class rhs_6b5_rifleman_khaki: rhs_6b5_rifleman
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_rifleman_khaki_ca.paa";
		displayName = "$STR_RHS_6B5_RIFLEMAN_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_khaki_co.paa"};
	};
	class rhs_6b5_vsr: rhs_6b5
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_vsr_ca.paa";
		Scope = 2;
		displayName = "$STR_RHS_6B5_VSR_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_vsr_co.paa"};
	};
	class rhs_6b5_officer_vsr: rhs_6b5_officer
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_officer_vsr_ca.paa";
		displayName = "$STR_RHS_6B5_OFFICER_VSR_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_vsr_co.paa"};
	};
	class rhs_6b5_medic_vsr: rhs_6b5_medic
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_medic_vsr_ca.paa";
		displayName = "$STR_RHS_6B5_MEDIC_VSR_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_vsr_co.paa"};
	};
	class rhs_6b5_sniper_vsr: rhs_6b5_sniper
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_sniper_vsr_ca.paa";
		displayName = "$STR_RHS_6B5_SNIPER_VSR_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_vsr_co.paa"};
	};
	class rhs_6b5_rifleman_vsr: rhs_6b5_rifleman
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_rifleman_vsr_ca.paa";
		displayName = "$STR_RHS_6B5_RIFLEMAN_VSR_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_vsr_co.paa"};
	};
	class rhs_6b5_ttsko: rhs_6b5
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_ttsko_ca.paa";
		Scope = 2;
		displayName = "$STR_RHS_6B5_TTsKO_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_ttsko_co.paa"};
	};
	class rhs_6b5_officer_ttsko: rhs_6b5_officer
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_officer_ttsko_ca.paa";
		displayName = "$STR_RHS_6B5_OFFICER_TTsKO_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_ttsko_co.paa"};
	};
	class rhs_6b5_medic_ttsko: rhs_6b5_medic
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_medic_ttsko_ca.paa";
		displayName = "$STR_RHS_6B5_MEDIC_TTsKO_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_ttsko_co.paa"};
	};
	class rhs_6b5_sniper_ttsko: rhs_6b5_sniper
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_sniper_ttsko_ca.paa";
		displayName = "$STR_RHS_6B5_SNIPER_TTsKO_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_ttsko_co.paa"};
	};
	class rhs_6b5_rifleman_ttsko: rhs_6b5_rifleman
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_rifleman_ttsko_ca.paa";
		displayName = "$STR_RHS_6B5_RIFLEMAN_TTsKO_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_ttsko_co.paa"};
	};
	class rhs_6b5_spetsodezhda: rhs_6b5
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_spetsodezhda_ca.paa";
		Scope = 2;
		displayName = "$STR_RHS_6B5_BG_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_bg_co.paa"};
	};
	class rhs_6b5_officer_spetsodezhda: rhs_6b5_officer
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_officer_spetsodezhda_ca.paa";
		displayName = "$STR_RHS_6B5_OFFICER_BG_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_bg_co.paa"};
	};
	class rhs_6b5_medic_spetsodezhda: rhs_6b5_medic
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_medic_spetsodezhda_ca.paa";
		displayName = "$STR_RHS_6B5_MEDIC_BG_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_bg_co.paa"};
	};
	class rhs_6b5_sniper_spetsodezhda: rhs_6b5_sniper
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_sniper_spetsodezhda_ca.paa";
		displayName = "$STR_RHS_6B5_SNIPER_BG_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_bg_co.paa"};
	};
	class rhs_6b5_rifleman_spetsodezhda: rhs_6b5_rifleman
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b5_rifleman_spetsodezhda_ca.paa";
		displayName = "$STR_RHS_6B5_RIFLEMAN_BG_NAME";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry2\data\6b5_bg_co.paa"};
	};
	class rhs_6b45: rhs_6b43
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b45_ca.paa";
		dlc = "RHS_AFRF";
		scope = 2;
		displayName = "$STR_RHS_6B45_NAME";
		model = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_desert_6b45";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry3\ratnik\data\6b45_co.paa"};
		descriptionShort = "Armor Level 6";
		class ItemInfo: ItemInfo
		{
			hiddenSelections[] = {"Camo"};
			uniformModel = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_desert_6b45";
			containerClass = "Supply20";
			mass = 80;
			class HitpointsProtectionInfo
			{
				class Neck
				{
					HitpointName = "HitNeck";
					armor = 9;
					PassThrough = 0.3;
					simulation = "RHS_Gost_3";
				};
				class Chest
				{
					HitpointName = "HitChest";
					armor = 15;
					PassThrough = 0.1;
					simulation = "RHS_Gost_6";
				};
				class Diaphragm
				{
					HitpointName = "HitDiaphragm";
					armor = 15;
					PassThrough = 0.1;
					simulation = "RHS_Gost_6";
				};
				class Abdomen
				{
					hitpointName = "HitAbdomen";
					armor = 15;
					passThrough = 0.1;
					simulation = "RHS_Gost_6";
				};
				class Body
				{
					hitpointName = "HitBody";
					passThrough = 0.1;
					simulation = "RHS_Gost_6";
				};
			};
		};
	};
	class rhs_6b45_desert: rhs_6b45
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b45_desert_ca.paa";
		dlc = "RHS_AFRF";
		displayName = "$STR_RHS_6B45_DES_NAME";
		model = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_desert_6b45";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry3\ratnik\data\6b45_desert_co.paa"};
	};
	class rhs_6b45_grn: rhs_6b45
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b45_grn_ca.paa";
		dlc = "RHS_AFRF";
		displayName = "$STR_RHS_6B45_VOG_NAME";
		model = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_emr_6b45_new_VOG";
		hiddenSelections[] = {"Camo","Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry3\ratnik\data\6b45_co.paa","rhsafrf\addons\rhs_infantry3\ratnik\data\pouchs_117_co.paa","rhsafrf\addons\rhs_infantry3\ratnik\data\pouchs_118_co.paa"};
		class ItemInfo: ItemInfo
		{
			hiddenSelections[] = {"Camo","Camo1","Camo2"};
			uniformModel = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_emr_6b45_new_VOG";
			containerClass = "Supply160";
			mass = 95;
		};
	};
	class rhs_6b45_holster: rhs_6b45
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b45_holster_ca.paa";
		dlc = "RHS_AFRF";
		displayName = "$STR_RHS_6B45_HOLSTER_NAME";
		model = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_emr_6b45_new_holster";
		hiddenSelections[] = {"Camo","Camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry3\ratnik\data\6b45_co.paa","rhsafrf\addons\rhs_infantry3\ratnik\data\pouchs_118_co.paa"};
		class ItemInfo: ItemInfo
		{
			hiddenSelections[] = {"Camo","Camo1"};
			uniformModel = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_emr_6b45_new_holster";
			containerClass = "Supply20";
			mass = 85;
		};
	};
	class rhs_6b45_light: rhs_6b45
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b45_light_ca.paa";
		dlc = "RHS_AFRF";
		displayName = "$STR_RHS_6B45_LIGHT_NAME";
		model = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_emr_6b45_new_low";
		hiddenSelections[] = {"Camo","Camo1"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry3\ratnik\data\6b45_co.paa","rhsafrf\addons\rhs_infantry3\ratnik\data\pouchs_117_co.paa"};
		class ItemInfo: ItemInfo
		{
			hiddenSelections[] = {"Camo","Camo1"};
			uniformModel = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_emr_6b45_new_low";
			containerClass = "Supply60";
			mass = 85;
		};
	};
	class rhs_6b45_mg: rhs_6b45
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b45_mg_ca.paa";
		dlc = "RHS_AFRF";
		displayName = "$STR_RHS_6B45_MG_NAME";
		model = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_emr_6b45_new_PK";
		hiddenSelections[] = {"Camo","Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry3\ratnik\data\6b45_co.paa","rhsafrf\addons\rhs_infantry3\ratnik\data\pouchs_117_co.paa","rhsafrf\addons\rhs_infantry3\ratnik\data\pouchs_118_co.paa"};
		class ItemInfo: ItemInfo
		{
			hiddenSelections[] = {"Camo","Camo1","Camo2"};
			uniformModel = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_emr_6b45_new_PK";
			containerClass = "Supply160";
			mass = 95;
		};
	};
	class rhs_6b45_off: rhs_6b45
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b45_off_ca.paa";
		dlc = "RHS_AFRF";
		displayName = "$STR_RHS_6B45_OFF_NAME";
		model = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_emr_6b45_new_light_off";
		hiddenSelections[] = {"Camo","Camo1","Camo2","Camo3"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry3\ratnik\data\6b45_co.paa","rhsafrf\addons\rhs_infantry3\ratnik\data\pouchs_117_co.paa","rhsafrf\addons\rhs_infantry3\ratnik\data\pouchs_118_co.paa","rhsafrf\addons\rhs_infantry3\ratnik\data\azart_co.paa"};
		class ItemInfo: ItemInfo
		{
			hiddenSelections[] = {"Camo","Camo1","Camo2"};
			uniformModel = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_emr_6b45_new_light_off";
			containerClass = "Supply120";
			mass = 90;
		};
	};
	class rhs_6b45_rifleman: rhs_6b45
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b45_rifleman_ca.paa";
		dlc = "RHS_AFRF";
		displayName = "$STR_RHS_6B45_RIFLE1_NAME";
		model = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_emr_6b45_new_light_var";
		hiddenSelections[] = {"Camo","Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry3\ratnik\data\6b45_co.paa","rhsafrf\addons\rhs_infantry3\ratnik\data\pouchs_117_co.paa","rhsafrf\addons\rhs_infantry3\ratnik\data\pouchs_118_co.paa"};
		class ItemInfo: ItemInfo
		{
			hiddenSelections[] = {"Camo","Camo1","Camo2"};
			uniformModel = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_emr_6b45_new_light_var";
			containerClass = "Supply120";
			mass = 90;
		};
	};
	class rhs_6b45_rifleman_2: rhs_6b45
	{
		author = "$STR_RHS_AUTHOR_FULL";
		picture = "\rhsafrf\addons\rhs_inventoryicons\data\vests\rhs_6b45_rifleman_2_ca.paa";
		dlc = "RHS_AFRF";
		displayName = "$STR_RHS_6B45_RIFLE2_NAME";
		model = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_emr_6b45_new_shovel";
		hiddenSelections[] = {"Camo","Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"rhsafrf\addons\rhs_infantry3\ratnik\data\6b45_co.paa","rhsafrf\addons\rhs_infantry3\ratnik\data\pouchs_117_co.paa","rhsafrf\addons\rhs_infantry3\ratnik\data\pouchs_118_co.paa"};
		class ItemInfo: ItemInfo
		{
			hiddenSelections[] = {"Camo","Camo1","Camo2"};
			uniformModel = "rhsafrf\addons\rhs_infantry3\ratnik\rhs_emr_6b45_new_shovel";
			containerClass = "Supply120";
			mass = 90;
		};
	};	
};

#endif
