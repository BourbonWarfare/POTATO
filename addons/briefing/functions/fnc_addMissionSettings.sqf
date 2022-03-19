/*
 * Author: tanaKa
 * Function used to add mission settings to a player's diary
 *
 * Arguments:
 * 0: Unit to add to the credits to <OBJECT>
 *
 * Examples:
 * [player] call potato_briefing_fnc_addMissionSettings;
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_unit);
params ["_unit"];

private _miniArsenal = getMissionConfigValue ["potato_missionTesting_miniArsenal","N/A"];
private _vdLimit = getMissionConfigValue ["potato_missionTesting_maxViewDistance","N/A"];
private _missionTimeLimit = getMissionConfigValue ["potato_missionTesting_missionTimeLength","N/A"];
private _ssTimeLimit = getMissionConfigValue ["potato_missionTesting_SSTimeGiven","N/A"];
private _medicalSystem = getMissionConfigValue ["potato_missionTesting_medSystem","N/A"];
switch (_medicalSystem) do {
	case 1:
	{
		_medicalSystem = "CCPs and FHs";
	};
	case 0:
	{
		_medicalSystem = "MEV";
	};
	case 99:
	{
		_medicalSystem = "Not Setup Correctly";
	};
};
private _forwardDeploy = getMissionConfigValue ["potato_missionTesting_forwardDeploy","N/A"];
private _patches = getMissionConfigValue ["potato_missionTesting_armPatches","N/A"];
switch (_patches) do {
	case 0:
	{
		_patches = "Roles";
	};
	case 1:
	{
		_patches = "Groups";
	};
	case 2:
	{
		_patches = "Teams";
	};
	case -1:
	{
		_patches = "Disabled";
	};
};
private _radios = getMissionConfigValue ["potato_missionTesting_radioSystem","N/A"];
switch (_patches) do {
	case 0:
	{
		_radios = "Squad Nets";
	};
	case 1:
	{
		_radios = "Fireteam Nets";
	};
	case 2:
	{
		_radios = "No GI Radios";
	};
};

_unit createDiarySubject ["ms","Mission Settings"];
_unit createDiaryRecord ["ms", ["Settings", format ["
<font size=14>Time Limits</font><br/>
Recommended SS Time: %4 <br/>
Mission Time Limit: %1 <br/>
<br/>
<font size=14>Other</font><br/>
View Distance Limit: %2 <br/>
Medical System: %3 <br/>
Forward Deploy Enabled: %5 <br/>
MiniArsenal Enabled: %6 <br/>
Arm Patch Type: %7 <br/>
Radio System: %8
", _missionTimeLimit, _vdLimit, _medicalSystem, _ssTimeLimit, _forwardDeploy, _miniArsenal, _patches,_radios]]];
