/*
 * Author: BadWolf
 * Function is called by bottons and on load of the breifings page to update the informaiton.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_briefingsSideChanged;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params["_side"];

GVAR(yStartCoord) = 0.01;

private _situtation = nil;
private _mission = nil;
private _admin = nil;
private _weaponsReport = nil;
private _zuesIntent = getMissionConfigValue [QEGVAR(briefing,zeusintent), ""];
// for _reportArray = ["zuesIntent","situtation","Mission","Admin","WeaponsReport"]
private _reportArray = [];

[] call FUNC(runWeaponsReport);

switch (_side) do {
    case 0: {
        _situtation = getMissionConfigValue [QEGVAR(briefing,briefWestSituation), ""];
        _mission = getMissionConfigValue [QEGVAR(briefing,briefWestMission), ""];
        _admin = getMissionConfigValue [QEGVAR(briefing,briefWestAdministration), ""];
        _weaponsReport = GVAR(westClasses) joinString "<br/>";
    };
    case 1: {
        _situtation = getMissionConfigValue [QEGVAR(briefing,briefEastSituation), ""];
        _mission = getMissionConfigValue [QEGVAR(briefing,briefEastMission), ""];
        _admin = getMissionConfigValue [QEGVAR(briefing,brieEastAdministration), ""];
        _weaponsReport = GVAR(eastClasses) joinString "<br/>";
    };
    case 2: {
        _situtation = getMissionConfigValue [QEGVAR(briefing,briefIndependentSituation), ""];
        _mission = getMissionConfigValue [QEGVAR(briefing,briefIndependentMission), ""];
        _admin = getMissionConfigValue [QEGVAR(briefing,briefIndependentAdministration), ""];
        _weaponsReport = GVAR(indyClasses) joinString "<br/>";
    };
    case 3: {
        _situtation = getMissionConfigValue [QEGVAR(briefing,briefCivilianSituation), ""];
        _mission = getMissionConfigValue [QEGVAR(briefing,briefCivilianMission), ""];
        _admin = getMissionConfigValue [QEGVAR(briefing,briefCivilianAdministration), ""];
        _weaponsReport = GVAR(civiClasses) joinString "<br/>";
    };
};

private _ctrlCreateZeuzIntentTitle = DISPLAY_BRIEF ctrlCreate [QUOTE(RscText),-1,BRIEFINGS_GROUP_L];
private _ctrlCreateZeuzIntentText = DISPLAY_BRIEF ctrlCreate [QUOTE(RscStructuredText),-1];
private _ctrlCreateSituationTitle = DISPLAY_BRIEF ctrlCreate [QUOTE(RscText),-1,BRIEFINGS_GROUP_L];
private _ctrlCreateSituationText = DISPLAY_BRIEF ctrlCreate [QUOTE(RscStructuredText),-1];
private _ctrlCreateMissionTitle = DISPLAY_BRIEF ctrlCreate [QUOTE(RscText),-1,BRIEFINGS_GROUP_L];
private _ctrlCreateMissionText= DISPLAY_BRIEF ctrlCreate [QUOTE(RscStructuredText),-1];
private _ctrlCreateAdministrationTitle = DISPLAY_BRIEF ctrlCreate [QUOTE(RscText),-1,BRIEFINGS_GROUP_L];
private _ctrlCreateAdministrationText = DISPLAY_BRIEF ctrlCreate [QUOTE(RscStructuredText),-1];
private _ctrlCreateWeaponsReportTitle = DISPLAY_BRIEF ctrlCreate [QUOTE(RscText),-1,BRIEFINGS_GROUP_R];
private _ctrlCreateWeaponsReport = DISPLAY_BRIEF ctrlCreate [QUOTE(RscStructuredText),-1];

private _controls = [
    _ctrlCreateZeuzIntentTitle
    ,_ctrlCreateZeuzIntentText
    ,_ctrlCreateSituationTitle
    ,_ctrlCreateSituationText
    ,_ctrlCreateMissionTitle
    ,_ctrlCreateMissionText
    ,_ctrlCreateAdministrationTitle
    ,_ctrlCreateAdministrationText
];
private _textArray = ["Zues Intent",_zuesIntent,"Situtation",_situtation,"Mission",_mission,"Administration",_admin];

{
    private _ctrlClass = ctrlClassName _x;
    private _text = _textArray select _forEachIndex;
    _x ctrlSetPosition [0,GVAR(yStartCoord)];
    if(_ctrlClassName == "RscStructuredText") then {
        _x ctrlSetStructuredText parseText _text;
    } else {
        _x ctrlSetText _text;
    };
    _ctrl ctrlCommit 0;
    private _ctrlHeight = ctrlTextHeight _x;
    private _ctrlPos = ctrlPosition _x;
    _ctrlPos set [3,_ctrlHeight + 0.05];
    _x ctrlSetPosition _ctrlPos;
    _x ctrlCommit 0;
    GVAR(yStartCoord) = GVAR(yStartCoord) + _ctrlHeight;
    INCREMENT_YCOORD;
}forEach _controls;
