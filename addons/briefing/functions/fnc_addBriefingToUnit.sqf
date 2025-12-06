/*
 * Author: PabstMirror
 * Function used to add unit and group briefings as well as the OrBat
 * and credits to a player's diary
 *
 * Arguments:
 * 0: Unit to add to the briefings to <OBJECT>
 *
 * Examples:
 * [player] call potato_briefing_fnc_addBriefingToUnit;
 *
 * Public: Yes
 */

#include "script_component.hpp"

params ["_newPlayer"];
TRACE_1("params",_newPlayer);

if (isNull _newPlayer) exitWith {};
if (!alive _newPlayer) exitWith {};
if (_newPlayer getVariable [QGVAR(briefingAdded), false]) exitWith {};

private _side = side (group _newPlayer);
if (_side == sideLogic) exitWith {};

_newPlayer setVariable [QGVAR(briefingAdded), true];

if (missionNamespace getVariable [QGVAR(brief_addCredits), false]) then { [_newPlayer] call FUNC(addCredits); };
if (missionNamespace getVariable [QGVAR(brief_addOrbat), false]) then { [_newPlayer] call FUNC(addOrbat); };
[_newPlayer] call FUNC(addMedicalNotes);

private _sideBriefMission = "";
private _sideBriefSituation = "";
private _sideBriefAdministration = "";
private _sideBriefEnemyInfo = "";
private _sideBriefIntent = "";
private _playerBrief = _newPlayer getVariable [QGVAR(briefing), ""];
private _groupBrief = (group _newPlayer) getVariable [QGVAR(briefing), ""];

switch (_side) do {
    case (west): {
        _sideBriefMission = getMissionConfigValue [QGVAR(briefWestMission), ""];
        _sideBriefSituation = getMissionConfigValue [QGVAR(briefWestSituation), ""];
        _sideBriefAdministration = getMissionConfigValue [QGVAR(briefWestAdministration), ""];
        _sideBriefEnemyInfo = getMissionConfigValue [QGVAR(briefWestEnemyInfo), ""];
        _sideBriefIntent = getMissionConfigValue [QGVAR(briefWestIntent), ""];
    };
    case (east): {
        _sideBriefMission = getMissionConfigValue [QGVAR(briefEastMission), ""];
        _sideBriefSituation = getMissionConfigValue [QGVAR(briefEastSituation), ""];
        _sideBriefAdministration = getMissionConfigValue [QGVAR(briefEastAdministration), ""];
        _sideBriefEnemyInfo = getMissionConfigValue [QGVAR(briefEastEnemyInfo), ""];
        _sideBriefIntent = getMissionConfigValue [QGVAR(briefEastIntent), ""];
    };
    case (independent): {
        _sideBriefMission = getMissionConfigValue [QGVAR(briefIndependentMission), ""];
        _sideBriefSituation = getMissionConfigValue [QGVAR(briefIndependentSituation), ""];
        _sideBriefAdministration = getMissionConfigValue [QGVAR(briefIndependentAdministration), ""];
        _sideBriefEnemyInfo = getMissionConfigValue [QGVAR(briefIndependentEnemyInfo), ""];
        _sideBriefIntent = getMissionConfigValue [QGVAR(briefIndependentIntent), ""];
    };
    case (civilian): {
        _sideBriefMission = getMissionConfigValue [QGVAR(briefCivilianMission), ""];
        _sideBriefSituation = getMissionConfigValue [QGVAR(briefCivilianSituation), ""];
        _sideBriefAdministration = getMissionConfigValue [QGVAR(briefCivilianAdministration), ""];
        _sideBriefEnemyInfo = getMissionConfigValue [QGVAR(briefCivilianEnemyInfo), ""];
        _sideBriefIntent = getMissionConfigValue [QGVAR(briefCivilianIntent), ""];
    };
    default {
        diag_log text format ["[POTATO-briefing] Unknown Side? %1", _side];
    };
};

TRACE_7("",count _sideBriefIntent,count _sideBriefEnemyInfo,count _sideBriefAdministration,count _sideBriefMission,count _sideBriefSituation,count _groupBrief,count _playerBrief);

if (_sideBriefIntent != "") then {
    _newPlayer createDiaryRecord ["diary", ["Intent", _sideBriefIntent]];
};
if (_sideBriefEnemyInfo != "") then {
    _newPlayer createDiaryRecord ["diary", ["Enemy Info", _sideBriefEnemyInfo]];
};
if (_sideBriefAdministration != "") then {
    _newPlayer createDiaryRecord ["diary", ["Administration", _sideBriefAdministration]];
};
if (_sideBriefMission != "") then {
    _newPlayer createDiaryRecord ["diary", ["Mission", _sideBriefMission]];
};
if (_sideBriefSituation != "") then {
    _newPlayer createDiaryRecord ["diary", ["Situation", _sideBriefSituation]];
};
if (_groupBrief != "") then {
    _newPlayer createDiaryRecord ["diary", ["Group Brief", _groupBrief]];
};
if (_playerBrief != "") then {
    _newPlayer createDiaryRecord ["diary", ["Player Brief", _playerBrief]];
};
