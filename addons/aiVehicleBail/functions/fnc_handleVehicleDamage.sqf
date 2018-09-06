/*
 * Author: Brandon (TCVM)
 * Determines if the current damage done to the vehicle is enough to bail them out. Must be called next frame in order to avoid RHS errors
 *
 * Arguments:
 * 0: The vehicle
 * 1: The selection which got hit
 * 2: The index of what got hit
 *
 * Return Value:
 * None
 *
 * Example:
 * [potato_aiVehicleBail_fnc_handleTankDamage, tank1, "Hit_Engine", 12]] call CBA_fnc_execNextFrame
 *
 *
 * Public: No
 */
#include "script_component.hpp"

params["_vehicle", "_hitPoint", "_hitIndex", "_injurer"];

if !(alive _vehicle) exitWith {
    private _eventHandler = _vehicle getVariable[QGVAR(handle_damage), nil];
    if !(isNil "_eventHandler") then {
        _vehicle removeEventHandler ["handleDamage", _eventHandler];
    };
};

_hitPoint = toLower _hitPoint;

private _type = "exit";
switch (true) do {
    case (_hitPoint in (ENGINE_HITPOINTS select 0)):   { _type = (ENGINE_HITPOINTS select 1) };
    case (_hitPoint in (HULL_HITPOINTS select 0)):     { _type = (HULL_HITPOINTS select 1) };
    case (_hitPoint in (TURRET_HITPOINTS select 0)):   { _type = (TURRET_HITPOINTS select 1) };
    case (_hitPoint in (TRACK_HITPOINTS select 0)):    { _type = (TRACK_HITPOINTS select 1) };
    case (_hitPoint in (WHEEL_HITPOINTS select 0)):    { _type = (WHEEL_HITPOINTS select 1) };
    default { _type = "exit"; }
};
if (_type == "exit") exitWith {};

private _canMove = _vehicle getVariable[QGVAR(can_move), true];
private _canShoot = _vehicle getVariable[QGVAR(can_shoot), true];

switch (true) do {
    case (_type isEqualTo "engine"): { _canMove = ((_vehicle getHitIndex _hitIndex) < 1) };
    case (_type isEqualTo "turret"): { _canShoot = ((_vehicle getHitIndex _hitIndex) < 1) };
};

// Ignore multiple hits at the same time
private _ignoreHit = false;
private _multHit = _vehicle getVariable [QGVAR(hit_time), nil];
if (isNil "_multHit") then {
    _vehicle setVariable[QGVAR(hit_time), [time, _injurer]];
} else {
    if (time <= (_multHit select 0) + CONST_TIME && {_injurer == (_multHit select 1)}) then {
        _ignoreHit = true;
    } else {
        _vehicle setVariable[QGVAR(hit_time), [time, _injurer]];
    };
};
if (_ignoreHit) exitWith {
    diag_log text format["[POTATO] Ignoring multiple hits done to vehicle [%1] by [%2]", _vehicle, _injurer];
};

[_vehicle, _canMove, _canShoot] call FUNC(handleBail);

