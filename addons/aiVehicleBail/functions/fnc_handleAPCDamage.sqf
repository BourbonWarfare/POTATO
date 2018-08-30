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
 * [potato_aiVehicleBail_fnc_handleAPCDamage, btr2, "Hit_Engine", 12]] call CBA_fnc_execNextFrame
 *
 *
 * Public: No
 */
#include "script_component.hpp"

params["_vehicle", "_selection", "_hitIndex"];

if !(alive _vehicle) exitWith {
    private _eventHandler = _vehicle getVariable[QGVAR(handle_damage), nil];
    if !(isNil {_eventHandler}) then {
        _vehicle removeEventHandler ["handleDamage", _eventHandler];
    };
};

_selection = toLower _selection;

private _type = [_vehicle, _selection] call FUNC(determineGenericSelectionType);

switch (true) do {
    case (_selection isEqualTo GET_VEHICLE_HITPOINT(_vehicle, QGVAR(left_back_wheel_name))):    { _type = "wheel" };
    case (_selection isEqualTo GET_VEHICLE_HITPOINT(_vehicle, QGVAR(left_middle_wheel_name))):  { _type = "wheel" };
    case (_selection isEqualTo GET_VEHICLE_HITPOINT(_vehicle, QGVAR(left_front_wheel_name))):   { _type = "wheel" };
    case (_selection isEqualTo GET_VEHICLE_HITPOINT(_vehicle, QGVAR(left_front_wheel_2_name))): { _type = "wheel" };
    case (_selection isEqualTo GET_VEHICLE_HITPOINT(_vehicle, QGVAR(right_back_wheel_name))):   { _type = "wheel" };
    case (_selection isEqualTo GET_VEHICLE_HITPOINT(_vehicle, QGVAR(right_middle_wheel_name))): { _type = "wheel" };
    case (_selection isEqualTo GET_VEHICLE_HITPOINT(_vehicle, QGVAR(right_front_wheel_name))):  { _type = "wheel" };
    case (_selection isEqualTo GET_VEHICLE_HITPOINT(_vehicle, QGVAR(right_front_wheel_2_name))):{ _type = "wheel" };
    default { }
};
if (_type == "exit") exitWith {};

private _canMove = _vehicle getVariable[QGVAR(can_move), true];
private _canShoot = _vehicle getVariable[QGVAR(can_shoot), true];

switch (true) do {
    case (_type isEqualTo "engine"): { _canMove = ((_vehicle getHitIndex _hitIndex) < 1) };
    case (_type isEqualTo "turret"): { _canShoot = ((_vehicle getHitIndex _hitIndex) < 1) };
};

[_vehicle, _canMove, _canShoot] call FUNC(handleBail);

