#include "\z\potato\addons\customGear\script_component.hpp"
#undef COMPONENT
#define COMPONENT customGear_wieselHAT


class CfgPatches {
	class ADDON	{
		units[] = {"POTATO_I_LT_01_HAT_F"};
		weapons[] =	{"POTATO_LAHAT"};
		magazines[] = {"2Rnd_120mm_LG_missiles"};
		requiredAddons[] = { "potato_core" };
		requiredVersion = REQUIRED_VERSION;
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
