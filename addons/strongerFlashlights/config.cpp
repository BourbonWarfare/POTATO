class CfgPatches
{
	class ADDON
	{
		weapons[]=
		{
//Base
			"GVAR(Vanilla_HG_LED_flashlight_Flood)",
			"GVAR(Vanilla_HG_LED_flashlight_Beam)",
			"GVAR(Vanilla_HG_LED_flashlight)",
//CUP flashlight
			"GVAR(CUP_LED_flashlight_Flood)",
			"GVAR(CUP_LED_flashlight_Beam)",
			"GVAR(CUP_LED_flashlight)"
		};
		units[]=
		{
		};
		requiredVersion=0.1;
		requiredAddons[]={"cup_weapons_east_attachments", "cup_weapons_west_attachments", "ace_laserpointer"};
		author = "Carl, Chesheire";
		authorUrl="";
	};
};

#include "CfgWeapons.hpp"