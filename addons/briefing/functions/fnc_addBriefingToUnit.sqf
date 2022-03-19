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

TRACE_1("params",_newPlayer);
params ["_newPlayer"];

if (isNull _newPlayer) exitWith {};
if (!alive _newPlayer) exitWith {};
if (_newPlayer getVariable [QGVAR(briefingAdded), false]) exitWith {};

private _side = side (group _newPlayer);
if (_side == sideLogic) exitWith {};

_newPlayer setVariable [QGVAR(briefingAdded), true];

if (missionNamespace getVariable [QGVAR(brief_addCredits), false]) then { [_newPlayer] call FUNC(addCredits); };
if (missionNamespace getVariable [QGVAR(brief_addOrbat), false]) then { [_newPlayer] call FUNC(addOrbat); };
[_newPlayer] call FUNC(addMedicalNotes);
[_newPlayer] call FUNC(addMissionSettings);

private _sideBriefMission = "";
private _sideBriefSituation = "";
private _sideBriefAdministration = "";
private _playerBrief = _newPlayer getVariable [QGVAR(briefing), ""];
private _groupBrief = (group _newPlayer) getVariable [QGVAR(briefing), ""];

switch (_side) do {
    case (west): {
        _sideBriefMission = getMissionConfigValue [QGVAR(briefWestMission), ""];
        _sideBriefSituation = getMissionConfigValue [QGVAR(briefWestSituation), ""];
        _sideBriefAdministration = getMissionConfigValue [QGVAR(briefWestAdministration), ""];
    };
    case (east): {
        _sideBriefMission = getMissionConfigValue [QGVAR(briefEastMission), ""];
        _sideBriefSituation = getMissionConfigValue [QGVAR(briefEastSituation), ""];
        _sideBriefAdministration = getMissionConfigValue [QGVAR(briefEastAdministration), ""];
    };
    case (independent): {
        _sideBriefMission = getMissionConfigValue [QGVAR(briefIndependentMission), ""];
        _sideBriefSituation = getMissionConfigValue [QGVAR(briefIndependentSituation), ""];
        _sideBriefAdministration = getMissionConfigValue [QGVAR(briefIndependentAdministration), ""];
    };
    case (civilian): {
        _sideBriefMission = getMissionConfigValue [QGVAR(briefCivilianMission), ""];
        _sideBriefSituation = getMissionConfigValue [QGVAR(briefCivilianSituation), ""];
        _sideBriefAdministration = getMissionConfigValue [QGVAR(briefCivilianAdministration), ""];
    };
    default {
        diag_log text format ["[POTATO-briefing] Unknown Side? %1", _side];
    };
};

TRACE_5("",count _sideBriefAdministration,count _sideBriefMission,count _sideBriefSituation,count _groupBrief,count _playerBrief);

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
