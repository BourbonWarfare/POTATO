#include "script_component.hpp"

params ["_newPlayer", "_oldPlayer"];
TRACE_2("params",_newPlayer,_oldPlayer);

if !(ACEGVAR(common,settingsInitFinished)) exitWith {
    TRACE_1("delaying for settings",_this);
    ACEGVAR(common,runAtSettingsInitialized) pushBack [FUNC(addBriefingToUnit), _this];
};

if (isNull _newPlayer) exitWith {};
if (!alive _newPlayer) exitWith {};
if (_newPlayer getVariable [QGVAR(briefingAdded), false]) exitWith {};

_newPlayer setVariable [QGVAR(briefingAdded), true];

if (GVAR(brief_addCredits)) then { [_newPlayer] call FUNC(addCredits); };
if (GVAR(brief_addOrbat)) then { [_newPlayer] call FUNC(addOrbat); };

private _side = side (group _newPlayer);

private _sideBriefMission = "";
private _sideBriefSituation = "";
private _sideBriefAdministration = "";
private _groupBrief = (group _newPlayer) getVariable [QGVAR(briefing), ""];
private _playerBrief = _newPlayer getVariable [QGVAR(briefing), ""];

switch (_side) do {
case (west):{
        _sideBriefMission = getMissionConfigValue [QGVAR(briefWestMission), ""];
        _sideBriefSituation = getMissionConfigValue [QGVAR(briefWestSituation), ""];;
        _sideBriefAdministration = getMissionConfigValue [QGVAR(briefWestAdministration), ""];;
    };
case (east):{
        _sideBriefMission = getMissionConfigValue [QGVAR(briefEastMission), ""];
        _sideBriefSituation = getMissionConfigValue [QGVAR(briefEastSituation), ""];;
        _sideBriefAdministration = getMissionConfigValue [QGVAR(briefEastAdministration), ""];;
    };
case (independent):{
        _sideBriefMission = getMissionConfigValue [QGVAR(briefIndependentMission), ""];
        _sideBriefSituation = getMissionConfigValue [QGVAR(briefIndependentSituation), ""];;
        _sideBriefAdministration = getMissionConfigValue [QGVAR(briefIndependentAdministration), ""];;
    };
case (civilian):{
        _sideBriefMission = getMissionConfigValue [QGVAR(briefCivilianMission), ""];
        _sideBriefSituation = getMissionConfigValue [QGVAR(briefCivilianSituation), ""];;
        _sideBriefAdministration = getMissionConfigValue [QGVAR(briefCivilianAdministration), ""];;
    };
    default {
        diag_log text format ["[POTATO] Unknown Side? %1", _side];
    };
};

TRACE_5("",count _sideBriefAdministration,count _sideBriefMission,count _sideBriefSituation,count _groupBrief,count _playerBrief);

if (_sideBriefAdministration != "") then {
    _newPlayer createDiaryRecord ["diary", ["Administration",_sideBriefAdministration]];
};
if (_sideBriefMission != "") then {
    _newPlayer createDiaryRecord ["diary", ["Mission",_sideBriefMission]];
};
if (_sideBriefSituation != "") then {
    _newPlayer createDiaryRecord ["diary", ["Situation",_sideBriefSituation]];
};
if (_groupBrief != "") then {
    _newPlayer createDiaryRecord ["diary", ["Group Brief",_groupBrief]];
};
if (_playerBrief != "") then {
    _newPlayer createDiaryRecord ["diary", ["Player Brief",_playerBrief]];
};
