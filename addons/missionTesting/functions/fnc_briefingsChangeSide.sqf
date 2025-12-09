/*
 * Author: BadWolf
 * Function is called by bottons and on load of the breifings page to update the informaiton.
 *
 * Arguments:
 * 0: Side <NUMBER>
 *
 * Examples:
 * [0] call potato_missionTesting_fnc_briefingsChangeSide;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params["_side"];

GVAR(yStartCoord) = 0;

private _situation = nil;
private _mission = nil;
private _admin = nil;
private _sideBriefEnemyInfo = "";
private _sideBriefIntent = "";
private _weaponsReport = nil;
private _zuesIntent = getMissionConfigValue [QEGVAR(briefing,zeusintent), ""];
private _reportArray = [];

if (!isNil QGVAR(TestRan)) then {
        TRACE_1("Test Ran Already",_this);
    } else {
        [] call FUNC(runWeaponsTest);
};

switch (_side) do {
    case 0: {
        _situation = getMissionConfigValue [QEGVAR(briefing,briefWestSituation), ""];
        _mission = getMissionConfigValue [QEGVAR(briefing,briefWestMission), ""];
        _admin = getMissionConfigValue [QEGVAR(briefing,briefWestAdministration), ""];
        _sideBriefEnemyInfo = getMissionConfigValue [QEGVAR(briefing,briefWestEnemyInfo), ""];
        _sideBriefIntent = getMissionConfigValue [QEGVAR(briefing,briefWestIntent), ""];
        _weaponsReport = GVAR(westClasses) joinString "<br/>";
    };
    case 1: {
        _situation = getMissionConfigValue [QEGVAR(briefing,briefEastSituation), ""];
        _mission = getMissionConfigValue [QEGVAR(briefing,briefEastMission), ""];
        _admin = getMissionConfigValue [QEGVAR(briefing,briefEastAdministration), ""];
        _sideBriefEnemyInfo = getMissionConfigValue [QEGVAR(briefing,briefEastEnemyInfo), ""];
        _sideBriefIntent = getMissionConfigValue [QEGVAR(briefing,briefEastIntent), ""];
        _weaponsReport = GVAR(eastClasses) joinString "<br/>";
    };
    case 2: {
        _situation = getMissionConfigValue [QEGVAR(briefing,briefIndependentSituation), ""];
        _mission = getMissionConfigValue [QEGVAR(briefing,briefIndependentMission), ""];
        _admin = getMissionConfigValue [QEGVAR(briefing,briefIndependentAdministration), ""];
        _sideBriefEnemyInfo = getMissionConfigValue [QEGVAR(briefing,briefIndependentEnemyInfo), ""];
        _sideBriefIntent = getMissionConfigValue [QEGVAR(briefing,briefIndependentIntent), ""];
        _weaponsReport = GVAR(indyClasses) joinString "<br/>";
    };
    case 3: {
        _situation = getMissionConfigValue [QEGVAR(briefing,briefCivilianSituation), ""];
        _mission = getMissionConfigValue [QEGVAR(briefing,briefCivilianMission), ""];
        _admin = getMissionConfigValue [QEGVAR(briefing,briefCivilianAdministration), ""];
        _sideBriefEnemyInfo = getMissionConfigValue [QEGVAR(briefing,briefCivilianEnemyInfo), ""];
        _sideBriefIntent = getMissionConfigValue [QEGVAR(briefing,briefCivilianIntent), ""];
        _weaponsReport = GVAR(civiClasses) joinString "<br/>";
    };
};

private _controls = [];
for "_i" from 0 to 13 do {
    _controls pushBack (DISPLAY_BRIEF displayCtrl (IDC_BREIFING + _i));
};
private _textArray = [
    "Zues Intent",_zuesIntent,
    "Situation",_situation,
    "Mission",_mission,
    "Administration",_admin,
    "Enemy Info",_sideBriefEnemyInfo,
    "Side Intent",_sideBriefIntent,
    "WEAPONS REPORT",_weaponsReport
];

{
    private _ctrlClass = ctrlClassName _x;
    private _text = _textArray select _forEachIndex;
    _x ctrlSetPosition [0,GVAR(yStartCoord),0.63,0.05];
    private _ctrlHeight = nil;
    if(_ctrlClass == "RscStructuredText") then {
        _x ctrlSetStructuredText parseText _text;
    } else {
        _x ctrlSetText _text;
        _x ctrlSetFontHeight 0.07;
        _x ctrlSetTextColor [1,0.5,0,1];
    };
    _x ctrlCommit 0;
    if(_ctrlClass == "RscStructuredText") then {
        _ctrlHeight = ctrlTextHeight _x;
    } else {
        _ctrlHeight = 0.1;
    };
    private _ctrlPos = ctrlPosition _x;
    _ctrlPos set [3,_ctrlHeight + 0.05];
    _x ctrlSetPosition _ctrlPos;
    _x ctrlCommit 0;
    GVAR(yStartCoord) = GVAR(yStartCoord) + _ctrlHeight;
    INCREMENT_YCOORD;
    if (_forEachIndex == 11) then {GVAR(yStartCoord) = 0;};
}forEach _controls;
