#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function should be called upon any ACE cook-off or engine fire event
* to attempt to start
*
*
* Arguments:
* _vehicle - A vehicle suffering a cook-off or engine fire event
*
* Return:
* None
*
* Example:
* [_vehicle] call potato_vehicleCoasting_fnc_driverDeathHandle;
*//***************************************************************************/
params [["_vehicle", objNull, [objNull]]];

if (isNull _vehicle) exitWith {};

{
    if (alive _x) then {
        [QACEGVAR(vehicle_damage,bailOut), [_vehicle, _x], _x] call CBA_fnc_targetEvent;
    };
} forEach crew _vehicle;