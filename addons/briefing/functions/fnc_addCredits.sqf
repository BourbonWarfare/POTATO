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

private _missionName = getMissionConfigValue ["onLoadName", getMissionConfigValue ["briefingName", "???"]];
private _authorName = getMissionConfigValue ["author", "???"];
private _worldName = getText (configFile >> "CfgWorlds" >> worldName >> "description");

private _missionFrameworkDate = getMissionConfigValue ["bwmfDate", "Pre-March2016"];
private _potatoVersion = getText (configFile >> "CfgPatches" >> "potato_core" >> "versionStr");

_unit createDiaryRecord ["diary", ["Credits", format ["
<font size=16>%1</font><br/>
<font size=13>by %2</font><br/>
<font size=13>on %3</font><br/>
<br/>
Bourbon Warfare Mission Framework<br/>
BWMF Version: %4<br/>
<br/>
<br/>
POTATO Version: %5
", _missionName, _authorName, _worldName, _missionFrameworkDate, _potatoVersion]]];
