/*
 * Author: Dani (TCVM)
 * Determines if the current damage done to the vehicle is enough to bail them out. Must be called next frame in order to avoid RHS errors
 *
 * Arguments:
 * 0: The vehicle
 * 1: The selection which got hit
 * 2: The index of what got hit
 * 3: The damage that the new part took
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

params["_vehicle", "_hitPoint", "_hitIndex", "_injurer", "_oldDamage", "_newDamage", "_projectile"];
TRACE_4("handleVehicleDamage",_vehicle,_hitPoint,_hitIndex,_injurer);

if !(alive _vehicle) exitWith {
    private _eventHandler = _vehicle getVariable[QGVAR(handle_damage), nil];
    if !(isNil "_eventHandler") then {
        _vehicle removeEventHandler ["HandleDamage", _eventHandler];
    };
};

_hitPoint = toLower _hitPoint;
private _type = GVAR(hitpointTypes) getVariable [_hitPoint, "exit"];
if (_type == "exit") exitWith {};

private _canMove = _vehicle getVariable[QGVAR(can_move), true];
private _canShoot = _vehicle getVariable[QGVAR(can_shoot), true];

switch (true) do {
    case (_type isEqualTo "engine"): { _canMove = ((_vehicle getHitIndex _hitIndex) < 1) };
    case (_type isEqualTo "turret"): { _canShoot = ((_vehicle getHitIndex _hitIndex) < 1) };
};

// Ignore multiple hits at the same time
private _ignoreHit = false;
private _ignoreBailCheck = false;
private _multHit = _vehicle getVariable [QGVAR(hit_time), nil];
if (isNil "_multHit") then {
    _vehicle setVariable[QGVAR(hit_time), [time, _injurer, [_hitPoint]]];
} else {
    private _hitPointInOldArray = _hitPoint in (_multHit select 2);
    private _withinTime = time <= (_multHit select 0) + CONST_TIME && { _injurer == (_multHit select 1) };
    if (_hitPointInOldArray && _withinTime) then {
        _ignoreHit = true;
    } else {
        // If the hitpoint isnt in the old array then that means that the time expired and a new array should be generated
        if !(_hitPointInOldArray) then {
            private _oldHitPoints = _multHit select 2;
            _oldHitPoints pushBack _hitPoint;
            _vehicle setVariable[QGVAR(hit_time), [time, _injurer, _oldHitPoints]];
            _ignoreBailCheck = true;
        } else {
            _vehicle setVariable[QGVAR(hit_time), [time, _injurer, [_hitPoint]]];
        };
    };
};
if (_ignoreHit) exitWith {
    diag_log text format["[POTATO] Ignoring multiple hits done to vehicle [%1] by [%2].", _vehicle, _injurer];
};

if !(_ignoreBailCheck) then {
    [_vehicle, _canMove, _canShoot] call FUNC(handleBail);
    if !(GVAR(enableCookoffMultihit)) then {
        [_vehicle, _hitIndex, _oldDamage, _newDamage, _projectile] call FUNC(handleCookoff);
    };
};
if (GVAR(enableCookoffMultihit)) then {
        [_vehicle, _hitIndex, _oldDamage, _newDamage, _projectile] call FUNC(handleCookoff);
    };

