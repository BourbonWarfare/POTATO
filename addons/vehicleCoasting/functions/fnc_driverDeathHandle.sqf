#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function should be called upon death of a unit to check if the
* unit is driving a vehicle and provide a chance of the vehicle going out
* of control..
*
* Arguments:
* _unit - A unit that died
*
* Return:
* None
*
* Example:
* [_unit] call lmd_coast_fnc_driverDeathHandle;
*//***************************************************************************/
params [["_unit", objNull, [objNull]]];
TRACE_2("params",_unit,typeOf _unit);
if (isNull objectParent _unit ||
    {!(_unit isKindOf "CAManBase")}) exitWith {
    TRACE_2("Invalid",isNull objectParent _unit,_unit isKindOf "CAManBase");
};

private _vehicle = vehicle _unit;

if (!local _vehicle) exitWith {
    TRACE_1("Not local",_vehicle);
};
#ifdef DEBUG_MODE_FULL
diag_log formatText [
    "%1 lt: %2 rt: %3",
    str _vehicle,
    _vehicle getHitPointDamage "hitltrack",
    _vehicle getHitPointDamage "hitrtrack"
];
#endif

private _driver = driver _vehicle;
if (!(_vehicle isKindOf "LandVehicle") ||
    speed _vehicle < 4 ||
    !alive _vehicle ||
    _unit != _driver ||
    (getObjectID _vehicle) in GVAR(activeVehicles)) exitWith {
    TRACE_5("ExitHandle",typeOf _vehicle,speed _vehicle,_unit,_driver,alive _driver);
};

TRACE_3("Continuing",_unit,_vehicle,speed _vehicle);
if (random 1 < POTATO_VEHICLEC_COASTING_DRIVER_CHANCE) then {
    TRACE_2("Chance success",_unit,_vehicle);
    [_vehicle, _driver] call FUNC(addCoastingVehicle);
};
