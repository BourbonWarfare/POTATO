/*
 * Author: BadWolf
 * Function called when the side is changed in the Mission Report Tab of the Testing menu, and displays the updated information in the respective control.
 *
 * Arguments:
 * 0: side <INTERGER>
 *
 * Examples:
 * [0] call potato_missionTesting_fnc_changeSideReport; // Will output the West Mission Breifing and the Weapons report to the respective controls on the display.
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params["_side"];

private _idc = [1021,1051,1053,1055,1060];
private _situtation = nil;
private _mission = nil;
private _admin = nil;
private _weaponsReport = nil;
private _zuesIntent = getMissionConfigValue [QEGVAR(breifing,zeusintent), ""];
// for _reportArray = ["zuesIntent","situtation","Mission","Admin","WeaponsReport"]
private _reportArray = [];
switch (_side) do {
    case 0: {
        _situtation = getMissionConfigValue [QEGVAR(breifing,briefWestSituation), ""];
        _mission = getMissionConfigValue [QEGVAR(breifing,briefWestMission), ""];
        _admin = getMissionConfigValue [QEGVAR(breifing,briefWestAdministration), ""];
        _weaponsReport = GVAR(westClasses) joinString "<br/>";
    };
    case 1: {
        _situtation = getMissionConfigValue [QEGVAR(breifing,briefEastSituation), ""];
        _mission = getMissionConfigValue [QEGVAR(breifing,briefEastMission), ""];
        _admin = getMissionConfigValue [QEGVAR(breifing,brieEastAdministration), ""];
        _weaponsReport = GVAR(eastClasses) joinString "<br/>";
    };
    case 2: {
        _situtation = getMissionConfigValue [QEGVAR(breifing,briefIndependentSituation), ""];
        _mission = getMissionConfigValue [QEGVAR(breifing,briefIndependentMission), ""];
        _admin = getMissionConfigValue [QEGVAR(breifing,briefIndependentAdministration), ""];
        _weaponsReport = GVAR(indyClasses) joinString "<br/>";
    };
    case 3: {
        _situtation = getMissionConfigValue [QEGVAR(breifing,briefCivilianSituation), ""];
        _mission = getMissionConfigValue [QEGVAR(breifing,briefCivilianMission), ""];
        _admin = getMissionConfigValue [QEGVAR(breifing,briefCivilianAdministration), ""];
        _weaponsReport = GVAR(civiClasses) joinString "<br/>";
    };
};
private _reportArray = [_zuesIntent,_situtation,_mission,_admin,_weaponsReport];
{
    private _ctrl =  (finddisplay 9999) displayCtrl _x;
    private _text = _reportArray select _forEachIndex;
    _ctrl ctrlSetStructuredText parseText _text;
    _ctrl ctrlCommit 0;
    private _ctrlHeight = ctrlTextHeight _ctrl;
    private _ctrlPos = ctrlPosition _ctrl;
    _ctrlPos set [3,_ctrlHeight + 0.05];
    _ctrl ctrlSetPosition _ctrlPos;
    _ctrl ctrlCommit 0;
}forEach _idc;
