#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* Spawn a group of units, and send them towards a position.
*
* Arguments:
* _endPosATL - End position to aim for (Array, default [0, 0, 0]).
* _startPosATL - Starting position of the group (Array, default [0, 0, 0]).
* _squadSize - Number of units in reinforcing squads (SCALAR, default 10).
* _side - The side of the attacking forces (SIDE, default LMD_ENMY_SIDE).
* _group - The group units are spawned into. Should not be passed, used for recursion (GROUP).
*
* Return:
* None
*
* Example:
* [getPosATL player, [2,1,0], 4, east] call lmd_fnc_spawnUnitsWP;
*//***************************************************************************/
params [
    ["_endPosATL", [0, 0, 0], [[]]],
    ["_starPosATL", [0, 0, 0], [[]]],
    ["_squadSize", 4, [4]],
    ["_side", east, [east]],
    ["_group", grpNull, [grpNull]]
];

if (_squadSize == 0 || _endPosATL isEqualTo [0, 0, 0]) exitWith {};
if (isNull _group) then {
    _group = createGroup [_side, true];
};
if !(local _group) exitWith {
    [_this] remoteExecCall [QFUNC(spawnUnitsWP), _group];
};
// Choose the unit type
private _type = switch (_squadSize mod 6) do {
    case 1: {selectRandom ["ftl", "ftl", "sl"]};
    case 2: {selectRandom ["rifleman", "rifleman", "lat"]};
    case 3: {selectRandom ["ar", "ar", "ar",  "ar", "mmgg"]};
    case 4: {selectRandom ["rifleman", "rifleman_04"]};
    default {selectRandom ["rifleman", "rifleman_04", "rifleman_03", "rifleman_04"]};
};
private _sideStr = switch (_side) do {
    case (west): {"potato_nolambs_w_"};
    case (resistance): {"potato_nolambs_i_"};
    default {"potato_nolambs_e_"};
};
private _unit = _group createUnit [_sideStr + _type, _starPosATL, [], 0, "NONE"];
//diag_log formatText ["Squad size idx: %1 (%2) | %3", _squadSize mod 6, _squadSize, _type];
_squadSize = _squadSize - 1;
if (_squadSize == 0) then {
    _group selectLeader _unit;
};
if (_squadSize > 0) then { // recurse
    [{_this call FUNC(spawnUnitsWP)},
        [_endPosATL, _starPosATL, _squadSize, _side, _group],
        PGVAR(zeusHC,delayBetweenUnitCreation) * (1 + random 1)] call CBA_fnc_waitAndExecute;
} else { // it's waypoint time
    private _wp = _group addWaypoint [_endPosATL, 25];
    _wp setWaypointCompletionRadius 100;
    _wp = _group addWaypoint [_endPosATL, 100];
    _wp setWaypointType "SAD";
    _group setSpeedMode "FULL";
    _wp = _group addWaypoint [waypointPosition _wp, 0];
    _wp setWaypointStatements ["true", "[group this, getPosATL this, 100] spawn lambs_wp_fnc_taskCQB;"]
};
