/*
 * Author: PabstMirror
 * Function used to add credits to a player's diary
 *
 * Arguments:
 * 0: Unit to add to the credits to <OBJECT>
 *
 * Examples:
 * [player] call potato_briefing_fnc_addCredits;
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_unit);
params ["_unit"];

private _missionName = getText (missionConfigFile >> "MissionSQM" >> "Mission" >> "Intel" >> "briefingName");
private _authorName = getMissionConfigValue ["author", "???"];
private _worldName = getText (configFile >> "CfgWorlds" >> worldName >> "description");
private _missionFrameworkDate = getMissionConfigValue ["cmfVers", "Framework Version Unknown"];
private _potatoVersion = getText (configFile >> "CfgPatches" >> "potato_core" >> "versionStr");
private _cmfDate = getMissionConfigValue ["cmfDate", "Date Unknown"];

(date call bis_fnc_sunriseSunsetTime) params ["_sunRise", "_sunSet"];


_unit createDiaryRecord ["diary", ["Credits", format ["
<font size=16>%1</font><br/>
<font size=13>by %2</font><br/>
<font size=13>on %3</font><br/>
<br/>
[Sunrise: %7 - Sunset: %8]<br/>
<br/>
<br/>
COALITION Mission Framework (CMF)<br/>
CMF Version: %4<br/>
CMF Date: %6<br/>
POTATO Version: %5
", _missionName, _authorName, _worldName, _missionFrameworkDate, _potatoVersion, _cmfDate
, [_sunRise, "HH:MM"] call BIS_fnc_timeToString, [_sunSet, "HH:MM"] call BIS_fnc_timeToString]]];
