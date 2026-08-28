#include "script_component.hpp"

class CfgPatches {
	class ADDON	{
		units[] = {
			"POTATO_I_LT_01_HAT_F"
		};
		weapons[] =	{
			"POTATO_LAHAT"
		};
		magazines[] = {
			"2Rnd_120mm_LG_missiles"
		};
		requiredAddons[] = {
			"A3_Armor_F_Tank_LT_01"
		};
		requiredVersion = REQUIRED_VERSION;
		skipWhenMissingDependencies = 1;
		author = "Potato";
		authors[] = {"blah2355"};
		authorUrl = "https://github.com/BourbonWarfare/POTATO";
		VERSION_CONFIG;
	};
};

#include "CfgAmmo.hpp"
#include "CfgMagazines.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
