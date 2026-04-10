#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* Spawns a single patrol in the marker zone, the patrol is given waypoints
* either around the perimeter of, or scattered within the given marker.
* If not marker is given, nothing happens
*
* Arguments:
* _marker - Marker that sets bounds for buildings to be garrisoned (STRING, default "").
* _patrolSize - Number of units in the patrol (SCALAR, 5).
* _sidePatrol - Side of the buildings garrison (SIDE, default east).
* _perimiterOffset - Parametric offset around the perimiter (SCALAR, default 0).
* _patrolPerimeter - Should the patrol walk around the perimieter (BOOL, default false).
* _group - The group units are spawned into. Should not be passed, used for recursion (GROUP).
*
* Return:
* None
*
* Example:
* [getPosATL player, "zone_0", 3, 10, east] call bw_fnc_spawnPatrol;
*//***************************************************************************/
params [
    ["_marker", "", [""]],
    ["_patrolSize", 5, [5]],
    ["_sidePatrol", east, [east]],
    ["_perimiterOffset", random 10, [1]],
    ["_patrolPerimeter", false, [false]],
    ["_group", grpNull, [grpNull]]
];

if (_marker == "" || _patrolSize <= 0) exitWith {};
// Make the group and add waypoints
if (isNull _group) then {
    _group = createGroup [_sidePatrol, true];
};

if !(local _group) exitWith {
    [_this] remoteExecCall [QFUNC(spawnPatrol), _group];
};

private _type = switch (_patrolSize mod 6) do {
    case 1: {selectRandom ["_rifleman_02", "_rifleman_03", "_msamg"]};
    case 2: {selectRandom ["_rifleman", "_rifleman_04", "_lat", "_msamg"]};
    case 3: {selectRandom ["_ar", "_ar", "_ar",  "_ar", "_mmgg"]};
    case 4: {selectRandom ["_sm", "_rifleman_02"]};
    case 5: {selectRandom ["_ftl", "_ftl", "_sl"]};
    default {selectRandom ["_rifleman", "_rifleman_03", "_rifleman_04"]};
};
private _sideType = switch (_sidePatrol) do {
    case east: {"e"};
    case west: {"w"};
    case resistance: {"i"};
    default {"e"};
};
private _unit = _group createUnit ["potato_nolambs_" + _sideType + _type, BW_UNIT_SPAWN_POS, [], 0, "NONE"];

if (_patrolSize == 5) then {
    _group selectLeader _unit;
};
_patrolSize = _patrolSize - 1;

if (_patrolSize > 0) then { // Recurse
    [{_this call FUNC(spawnPatrol)},
        [_marker, _patrolSize, _sidePatrol, _perimiterOffset, _patrolPerimeter, _group],
        PGVAR(zeusHC,delayBetweenUnitCreation) * (1 + random 1)] call CBA_fnc_waitAndExecute;
} else { // add either a ring of waypoints or scattered waypoints
    private _posATL = getMarkerPos _marker;
    // We need a bit of info to find the perimeter
    private _zoneDims = getMarkerSize _marker;
    private _markerRotation = markerDir _marker;
    private _cosRotation = cos(_markerRotation);
    private _sinRotation = sin(_markerRotation);
    private _matrixRotate = [
        [_cosRotation, -_sinRotation, 0],
        [_sinRotation,  _cosRotation, 0],
        [           0,             0, 1]
    ];
    private _directionConst = selectRandom [-1, 1];
    for "_j" from 0 to 6 do {
        // the terrible loop of perimeter waypoints, must end close to 2*pi
        private _wp = if (_patrolPerimeter) then {
            private _parVar = deg (_perimiterOffset + _directionConst * _j);
            private _sinVar = abs(sin(_parVar)) * sin(_parVar);
            private _cosVar = abs(cos(_parVar)) * cos(_parVar);
            private _rectPos = [[
                _zoneDims#0 * (_cosVar + _sinVar),
                _zoneDims#1 * (_cosVar - _sinVar),
                0
            ]];
            _rectPos = _rectPos matrixMultiply _matrixRotate;
            _group addWaypoint [_posATL vectorAdd (_rectPos#0), 10]
        } else { // easy scatter waypoints
            _group addWaypoint [[_marker] call FUNC(posInMarker), 20]
        };
        if (surfaceIsWater waypointPosition _wp && _j != 6) then {
            deleteWaypoint _wp;
        };
        if (_j == 6) then {
            _wp setWaypointType "CYCLE";
        };
    };
    private _movePos = getWPPos [_group, 1];
    _movePos set [2, 0];
    {
        _x setVehiclePosition [_movePos, [], 10, "NONE"];
    } forEach units _group;
    _group setVariable ["lambs_danger_disableGroupAI", true];
    _group setBehaviour "SAFE";
    _group setSpeedMode "LIMITED";
};
