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
* _artyPosATL - The position about to generate an artillery pieze (ARRAY, default [0,0,0]).
* _artilleryClass - Classname of the artillery piece (STRING, "").
* _sideArty - Side of the artillery piece (SIDE, default east).
*
* Return:
* None
*
* Example:
* [getPosATL player, "zone_0", 3, 10, east] call bw_fnc_createArtyGun;
*//***************************************************************************/
params [
    ["_artyPosATL", [0,0,0], [[]]],
    ["_artilleryClass", "", [""]],
    ["_sideArty", east, [east]]
];

if (_artyPosATL isEqualTo [] || _artilleryClass == "") exitWith {};

private _arty = createVehicle [_artilleryClass, _artyPosATL, [], 15, "NONE"];
if (!alive _arty) exitWith {
    diag_log formatText ["Failed to create arty piece (%1) at %2", _artilleryClass, _artyPosATL];
};

private _iter = 0;
while {isOnRoad _arty && _iter < 100} do {
    _arty setVehiclePosition [_artyPosATL, [], 20, "NONE"];
    _iter = _iter + 1;
};

if (!alive _arty) exitWith {
    deleteVehicle _arty;
    diag_log formatText ["Broke artillery piece near %1", _artyPosATL];
};

private _sideType = switch (_sideArty) do {
    case east: {"e"};
    case west: {"w"};
    case resistance: {"i"};
    default {"e"};
};
private _group = createGroup [_sideArty, true];
private _unit = _group createUnit ["potato_nolambs_" + _sideType + "_rifleman", BW_UNIT_SPAWN_POS, [], 0, "CAN_COLLIDE"];
_unit moveInGunner _arty;
copyToClipboard QFUNC(registerArtilleryUnits);
[[0,0,0], _arty] call FUNC(registerArtilleryUnits);
