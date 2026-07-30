#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function creates paradrop, relevant vehicles/groups, and waypoints.
 * It starts by creating the vehicle at ~250m AGL up from the goal pos and
 * about 5km away. This altitude is used as the goal altitude (ASL) for the
 * duration of flight. The function then creates a pilot, and cargo as
 * requested. Vehicle cargo that doesn't fit in the helicopter is held
 * "virtually." The pilot is finally given waypoints
 *
 * Arguments:
 * 0: _dropVic - Cfg vehicles type of the drop vic (STRING, default "")
 * 1: _wps - Array of 4 waypoints giving: (ARRAY, default [])
 *   0: Inbound direction position AGL
 *   1: Drop start position AGL
 *   2: Drop direction position AGL
 *   3: Efil direction position AGL
 * 2: _side - The side of the vehicle/pilot (SIDE, default side ace_player)
 * 3: _groupTypes - Array of types of groups (ARRAY, default [])
 * 4: _vicTypes - Array of vehicle types and whether the drop fails (ARRAY, default [])
 *
 * Return Value:
 * Nothing
 *
 * TODO:
 * - Handle infantry drops
 *
 * Public: No
 */
TRACE_1("create paradrop",_this);
params [
    ["_dropVic", "", [""]],
    ["_wps", [], [[]]],
    ["_side", side ace_player, [west]],
    ["_groupTypes", [], [[]]],
    ["_vicTypes", [], [[]]]
];

if (_dropVic == "" || _wps isEqualTo [] ||
    (_groupTypes isEqualTo [] && _vicTypes isEqualTo [])) exitWith {};

_wps params ["_initHeadingAGL", "_startDropAGL", "_dropHeadingAGL", "_exfilHeadingAGL"];

// Create the vehicle
private _initDir = _initHeadingAGL getDir _startDropAGL;
private _secondDir = _dropHeadingAGL getDir _startDropAGL;
private _dropVic = createVehicle [_dropVic, (_startDropAGL getPos [-4000, _initDir]) getPos [1500, _secondDir], [], 0, "FLY"];
private _initVel = velocityModelSpace _dropVic;
_dropVic setDir _initDir;
private _newPosASL = getPosASL _dropVic;
_newPosASL set [2, 250 + (AGLToASL _startDropAGL)#2];
private _barrAlt = _newPosASL#2;
_dropVic setPosASL _newPosASL;
_dropVic flyInHeight 100;
_dropVic flyInHeightASL [_barrAlt, _barrAlt, _barrAlt];
_dropVic setVelocityModelSpace _initVel;
_dropVic limitSpeed 220;

// creating cargo
private _newPosAGL = ASLToAGL _newPosASL;
private _virtualCargo = [];
{
    private _vic = createVehicle [_x#0, _newPosAGL, [], 0, "CAN_COLLIDE"];
    private _canCarry = _dropVic canVehicleCargo _vic;
    if (_canCarry#0 && _canCarry#1) then {
        _vic setVariable [QGVAR(failDrop), _x#1];
        _dropVic setVehicleCargo _vic;
    } else {
        deleteVehicle _vic;
        _virtualCargo pushBack _x;
    };
} forEach _vicTypes;
_dropVic setVariable [QGVAR(virtualCargo), _virtualCargo];

// create the pilot
private _pilotType = switch (_side) do {
    case (east): {"potato_e_pilot"};
    case (resistance): {"potato_i_pilot"};
    default {"potato_w_pilot"};
};
private _group = createGroup [_side, true];
private _pilot = _group createUnit [_pilotType, _newPosAGL, [], 0, "CAN_COLLIDE"];
_pilot moveInDriver _dropVic;
_dropVic setEffectiveCommander _pilot;
_group setVariable ["lambs_danger_disableGroupAI", true];
_pilot setVariable ["lambs_danger_disableAI", true];
// 2.22 content
//{_pilot disableAI _x} forEach ["HEARING", "AUTOCOMBAT", "CHECKVISIBLE", "AUTOTARGET", "TARGET"];
{_pilot disableAI _x} forEach ["AUTOCOMBAT", "CHECKVISIBLE", "AUTOTARGET", "TARGET"];
// Add those waypoints
private _wp = _group addWaypoint [_startDropAGL getPos [1500, _secondDir], 0];
_wp setWaypointBehaviour "CARELESS";
_wp setWaypointSpeed "FULL";
_wp = _group addWaypoint [_startDropAGL getPos [300, _secondDir], 0];
_wp setWaypointCompletionRadius 100;
_wp = _group addWaypoint [_startDropAGL, 0];
_wp setWaypointCompletionRadius 100;
_wp = _group addWaypoint [_startDropAGL, 0];
_wp setWaypointStatements ["true", format [QUOTE(if (local vehicle this) then {[ARR_3(vehicle this,2,%1)] call FUNC(dropDynamicCargo)}), _dropHeadingAGL getDir _exfilHeadingAGL]];
_wp = _group addWaypoint [_startDropAGL getPos [-2000, _secondDir], 0];
_wp setWaypointCompletionRadius 100;
