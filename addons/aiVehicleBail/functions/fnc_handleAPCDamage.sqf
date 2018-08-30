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
 * [potato_aiVehicleBail_handleAPCDamage, btr2, "Hit_Engine", 12]] call CBA_fnc_execNextFrame
 *
 *
 * Public: No
 */
#include "script_component.hpp"

params["_unit", "_selection", "_hitIndex"];

if !(alive _unit) exitWith {
    private _eventHandler = _unit getVariable[QGVAR(handle_damage), nil];
    if !(isNil _eventHandler) then {
        _unit removeEventHandler ["handleDamage", _eventHandler];
    };
};

_selection = toLower _selection;

private _type = "";

_type = [_unit, _selection] call FUNC(determineGenericSelectionType);

switch (true) do {
    //case (_selection isEqualTo GET_VEHICLE_HITPOINT(_unit, QGVAR(left_track_name))):     { _type = "track" };
    //case (_selection isEqualTo GET_VEHICLE_HITPOINT(_unit, QGVAR(right_track_name))):    { _type = "track" };
    default { _type = "exit"; }
};
if (_type == "exit") exitWith {};

private _canMove = _unit getVariable[QGVAR(can_move), true];
private _canShoot = _unit getVariable[QGVAR(can_shoot), true];

switch (true) do {
    case (_type isEqualTo "engine"): { _canMove = ((_unit getHitIndex _hitIndex) < 1) };
    case (_type isEqualTo "turret"): { _canShoot = ((_unit getHitIndex _hitIndex) < 1) };
};

[_unit, _canMove, _canShoot] call FUNC(handleBail);

