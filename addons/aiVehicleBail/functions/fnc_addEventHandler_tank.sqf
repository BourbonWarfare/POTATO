/*
 * Author: Brandon (TCVM)
 * Adds the event handler to a tank
 *
 * Arguments:
 * 0: The vehicle in which to add the event handler to
 *
 * Return Value:
 * None
 *
 * Example:
 * [tank2] call potato_aiVehicleBail_fnc_addEventHandler_tank;
 *
 * Public: No
 */
#include "script_component.hpp"
params["_vehicle"];

_vehicle allowCrewInImmobile true;

if !(GVAR(enableCrewBailing)) exitWith {};

private _hitPoint = _vehicle getVariable[QGVAR(engine_name), ""];
if (_hitPoint isEqualTo "") then {
    _hitPoint = toLower getText (configFile >> "CfgVehicles" >> typeof _vehicle >> "HitPoints" >> "HitLTrack" >> "Name");
    _vehicle setVariable [QGVAR(left_track_name), _hitPoint, true];
    
    _hitPoint = toLower getText (configFile >> "CfgVehicles" >> typeof _vehicle >> "HitPoints" >> "HitRTrack" >> "Name");
    _vehicle setVariable [QGVAR(right_track_name), _hitPoint, true];

    [_vehicle] call FUNC(setGenericSelectionVars);

    _vehicle setVariable[QGVAR(handle_damage), _vehicle addEventHandler["HandleDamage", {
        params ["_vehicle", "_selection", "_damage", "", "", "_hitIndex"];
        [LINKFUNC(handleTankDamage), [_vehicle, _selection, _hitIndex]] call CBA_fnc_execNextFrame;
        _damage
    }], true];
    
};

