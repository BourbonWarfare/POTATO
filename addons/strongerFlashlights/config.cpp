class CfgPatches
{
	class ADDON
	{
		weapons[]=
		{
//Base
			QGVAR(Vanilla_HG_LED_flashlight_Flood),
			QGVAR(Vanilla_HG_LED_flashlight_Beam),
			QGVAR(Vanilla_HG_LED_flashlight),
//CUP flashlight
			QGVAR(CUP_LED_flashlight_Flood),
			QGVAR(CUP_LED_flashlight_Beam),
			QGVAR(CUP_LED_flashlight)
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