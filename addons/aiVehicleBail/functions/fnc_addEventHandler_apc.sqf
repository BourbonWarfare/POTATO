/*
 * Author: Brandon (TCVM)
 * Adds the event handler to an APC
 *
 * Arguments:
 * 0: The vehicle in which to add the event handler to
 *
 * Return Value:
 * None
 *
 * Example:
 * [btr2] call potato_aiVehicleBail_fnc_addEventHandler_apc;
 *
 * Public: No
 */
#include "script_component.hpp"
params["_vehicle"];

if !(GVAR(enableCrewBailing)) exitWith {};

private _hitPoint = _vehicle getVariable[QGVAR(engine_name), ""];
if (_hitPoint isEqualTo "") then {
    _hitPoint = toLower getText (configFile >> "CfgVehicles" >> typeof _vehicle >> "HitPoints" >> "HitLBWheel" >> "Name");
    _vehicle setVariable [QGVAR(left_back_wheel_name), _hitPoint, true];
    
    _hitPoint = toLower getText (configFile >> "CfgVehicles" >> typeof _vehicle >> "HitPoints" >> "HitLMWheel" >> "Name");
    _vehicle setVariable [QGVAR(left_middle_wheel_name), _hitPoint, true];
    
    _hitPoint = toLower getText (configFile >> "CfgVehicles" >> typeof _vehicle >> "HitPoints" >> "HitLFWheel" >> "Name");
    _vehicle setVariable [QGVAR(left_front_wheel_name), _hitPoint, true];
    
    _hitPoint = toLower getText (configFile >> "CfgVehicles" >> typeof _vehicle >> "HitPoints" >> "HitLF2Wheel" >> "Name");
    _vehicle setVariable [QGVAR(left_front_wheel_2_name), _hitPoint, true];
    
    _hitPoint = toLower getText (configFile >> "CfgVehicles" >> typeof _vehicle >> "HitPoints" >> "HitRBWheel" >> "Name");
    _vehicle setVariable [QGVAR(right_back_wheel_name), _hitPoint, true];
    
    _hitPoint = toLower getText (configFile >> "CfgVehicles" >> typeof _vehicle >> "HitPoints" >> "HitRLWheel" >> "Name");
    _vehicle setVariable [QGVAR(right_middle_wheel_name), _hitPoint, true];
    
    _hitPoint = toLower getText (configFile >> "CfgVehicles" >> typeof _vehicle >> "HitPoints" >> "HitRFWheel" >> "Name");
    _vehicle setVariable [QGVAR(right_front_wheel_name), _hitPoint, true];
    
    _hitPoint = toLower getText (configFile >> "CfgVehicles" >> typeof _vehicle >> "HitPoints" >> "HitLF2Wheel" >> "Name");
    _vehicle setVariable [QGVAR(right_front_wheel_2_name), _hitPoint, true];

    [_vehicle] call FUNC(setGenericSelectionVars);

    _vehicle setVariable[QGVAR(handle_damage), _vehicle addEventHandler["HandleDamage", {
        params ["_vehicle", "_selection", "_damage", "", "", "_hitIndex"];
        [LINKFUNC(handleAPCDamage), [_vehicle, _selection, _hitIndex]] call CBA_fnc_execNextFrame;
        _damage
    }], true];
    
};

