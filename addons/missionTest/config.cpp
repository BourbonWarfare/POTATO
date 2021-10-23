class CfgPatches
{
	class ADDON
	{
		units[]={};
		weapons[]={};
		requiredVersion=1.9400001;
		requiredAddons[]=
		{
			"potato_core"
		};
		author="Potato";
		authorUrl="https://github.com/BourbonWarfare/POTATO";
		version="1.3.0.0";
		versionStr="1.3.0.0";
		versionAr[]={1,3,0,0};
	};
};
class Cfg3DEN
{
	class EventHandlers
	{
		class potato_missionTest
		{
			onMissionSave="call compile preprocessFileLineNumbers ""\z\potato\addons\missionTest\functions\fnc_onMissionSave.sqf""";
			onMissionLoad="call compile preprocessFileLineNumbers ""\z\potato\addons\missionTest\functions\fnc_onMissionLoad.sqf""";
		};
	};
};
class ctrlMenuStrip;
class display3DEN
{
	class Controls
	{
		class MenuStrip: ctrlMenuStrip
		{
			class Items
			{
				class potato
				{
					items[]+=
					{
						"potato_missionTest_fixFloating",
						"potato_missionTest_vehicleReport"
					};
				};
				class potato_missionTest_fixFloating
				{
					text="Fix Floating Units";
					action="call compile preprocessFileLineNumbers ""\z\potato\addons\missionTest\functions\fnc_fixFloating.sqf"";";
				};
				class potato_missionTest_vehicleReport
				{
					text="Vehicle Crew Capacity";
					action="call compile preprocessFileLineNumbers ""\z\potato\addons\missionTest\functions\fnc_vehicleReport.sqf"";";
				};
			};
		};
	};
};
