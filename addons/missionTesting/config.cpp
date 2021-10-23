class CfgPatches
{
	class potato_missiontesting
	{
		units[]=
		{
			"potato_missiontesting_missionTesting"
		};
		weapons[]={};
		requiredVersion=1.9400001;
		requiredAddons[]=
		{
			"potato_core"
		};
		author="Potato";
		authors[]=
		{
			"BadWolf"
		};
		authorUrl="https://github.com/BourbonWarfare/POTATO";
		version="1.3.0.0";
		versionStr="1.3.0.0";
		versionAr[]={1,3,0,0};
	};
};
class potato_missiontesting_displayMissionTesting
{
	idd=9999;
	movingEnable=1;
	enableSimulation=1;
	enableDisplay=1;
};
class potato_missiontesting_displayBreifings
{
	idd=9998;
	movingEnable=1;
	enableSimulation=1;
	enableDisplay=1;
};
class Extended_PreStart_EventHandlers
{
	class potato_missiontesting
	{
		init="call compile preprocessFileLineNumbers '\z\potato\addons\missiontesting\XEH_preStart.sqf'";
	};
};
class Extended_PreInit_EventHandlers
{
	class potato_missiontesting
	{
		init="call compile preprocessFileLineNumbers '\z\potato\addons\missiontesting\XEH_preInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class potato_missiontesting
	{
		init="call compile preprocessFileLineNumbers '\z\potato\addons\missiontesting\XEH_postInit.sqf'";
	};
};
class Extended_Init_EventHandlers
{
	class potato_missiontesting_missionTesting
	{
		class localInit
		{
			clientInit="call potato_missiontesting_fnc_openMenuFromZues";
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
						"potato_missiontesting_missionTesting"
					};
				};
				class potato_missiontesting_missionTesting
				{
					text="Mission Testing Attributes";
					action="edit3DENMissionAttributes ""potato_missiontesting_missionTestingInfo"";";
				};
			};
		};
	};
};
class Cfg3DEN
{
	class Attributes
	{
		class Default;
		class Title: Default
		{
			class Controls
			{
				class Title;
			};
		};
		class TitleWide: Default
		{
			class Controls
			{
				class Title;
			};
		};
	};
	class Mission
	{
		class potato_missiontesting_missionTestingInfo
		{
			displayName="Mission Testing Information";
			display="Display3DENEditAttributes";
			class AttributeCategories
			{
				class MissionGeneraInfo
				{
					displayName="General Information";
					collapsed=0;
					class Attributes
					{
						class potato_missiontesting_missionType
						{
							displayName="Mission Type:";
							property="potato_missiontesting_missionType";
							control="combo";
							defaultValue=0;
							typeName="NUMBER";
							class Values
							{
								class SELECT
								{
									name="SELECT";
									value=0;
								};
								class COOP
								{
									name="COOP";
									value=1;
								};
								class TVT
								{
									name="TVT";
									value=2;
								};
								class COTVT
								{
									name="COTVT";
									value=3;
								};
								class SPCL
								{
									name="SPCL";
									value=4;
								};
							};
						};
						class potato_missiontesting_missionVersion
						{
							displayName="Mission Version:";
							control="EditShort";
							property="potato_missiontesting_missionVersion";
							defaultValue=1;
							typeName="STRING";
						};
					};
				};
				class MissionPlayerCount
				{
					displayName="Player Count";
					collapsed=0;
					class Attributes
					{
						class potato_missiontesting_playerCountMinimum
						{
							displayName="Player Count Minimum:";
							property="potato_missiontesting_playerCountMinimum";
							control="EditShort";
							defaultValue="20";
							typeName="STRING";
						};
						class potato_missiontesting_playerCountRecommended
						{
							displayName="Player Count Recommended:";
							property="potato_missiontesting_playerCountRecommended";
							control="EditShort";
							defaultValue="40";
							typeName="STRING";
						};
						class potato_missiontesting_playerCountMaximum
						{
							displayName="Player Count Maximum:";
							property="potato_missiontesting_playerCountMaximum";
							control="EditShort";
							defaultValue="60";
							typeName="STRING";
						};
					};
				};
				class MissionTags
				{
					displayName="Mission Tags";
					collapsed=0;
					class Attributes
					{
						class potato_missiontesting_missionTag1
						{
							displayName="Mission Tag 1:";
							control="combo";
							property="potato_missiontesting_missionTag1";
							expression="_this setVariable ['%s', _value];";
							typeName="NUMBER";
							defaultValue=99;
							class Values
							{
								class SELECT
								{
									name="SELECT";
									value=99;
								};
								class NONE
								{
									name="NONE";
									value=0;
								};
								class NIGHT
								{
									name="NIGHT";
									value=1;
								};
								class DASKDAWN
								{
									name="DUSK/DAWN";
									value=2;
								};
								class MSV
								{
									name="MSV";
									value=3;
								};
								class TVT1
								{
									name="TVT1";
									value=4;
								};
								class TVT2
								{
									name="TVT2";
									value=5;
								};
								class AH
								{
									name="AH";
									value=6;
								};
								class FOG
								{
									name="FOG";
									value=7;
								};
								class BriefOnMap
								{
									name="BRIEF ON MAP";
									value=8;
								};
							};
						};
						class potato_missiontesting_missionTag2: potato_missiontesting_missionTag1
						{
							displayName="Mission Tag 2:";
							property="potato_missiontesting_missionTag2";
						};
						class potato_missiontesting_missionTag3: potato_missiontesting_missionTag1
						{
							displayName="Mission Tag 3:";
							property="potato_missiontesting_missionTag3";
						};
					};
				};
				class MissionFlags
				{
					displayName="Mission Flags";
					collapsed=0;
					class Attributes
					{
						class potato_missiontesting_missionFlagCustomScripting
						{
							displayName="Custom Scripting:";
							control="Checkbox";
							property="potato_missiontesting_missionFlagCustomScripting";
							defaultValue="false";
							expression="_this setVariable ['%s',_value];";
						};
						class potato_missiontesting_missionFlagCustomLoadout
						{
							displayName="Custom Loadout:";
							control="Checkbox";
							property="potato_missiontesting_missionFlagCustomLoadout";
							defaultValue="false";
							expression="_this setVariable ['%s',_value];";
						};
						class potato_missiontesting_missionFlagCustomVicLoadout
						{
							displayName="Custom Vehicle Loadout:";
							control="Checkbox";
							property="potato_missiontesting_missionFlagCustomVicLoadout";
							defaultValue="false";
							expression="_this setVariable ['%s',_value];";
						};
						class potato_missiontesting_missionFlagUnitSpecificBriefing
						{
							displayName="Unit Specific Briefings:";
							control="Checkbox";
							property="potato_missiontesting_missionFlagUnitSpecificBriefing";
							defaultValue="false";
							expression="_this setVariable ['%s',_value];";
						};
					};
				};
				class MissionMakerNotes
				{
					displayName="Mission Maker Notes";
					collapsed=0;
					class Attributes
					{
						class potato_missiontesting_missionMakerNotesForTesters
						{
							attributeSave="_value call potato_briefing_fnc_convertNewLineToHTML";
							attributeLoad="[_this,_value] call potato_briefing_fnc_convertHTMLToNewLine";
							displayName="Any other notes for Mission Testers:";
							control="EditMulti5";
							property="potato_missiontesting_missionMakerNotesForTesters";
							defaultValue="''";
						};
					};
				};
			};
		};
	};
};
class CfgVehicles
{
	class Logic;
	class Module_F: Logic
	{
		class ArgumentsBaseUnits;
		class ModuleDescription;
		class AttributesBase
		{
			class Edit;
			class Combo;
		};
	};
	class potato_missiontesting_missionTesting: Module_F
	{
		author="potato";
		category="potato";
		scope=1;
		scopeCurator=2;
		isTriggerActivated=0;
		isGlobal=1;
		displayName="Open Mission Testing Menu";
	};
};
