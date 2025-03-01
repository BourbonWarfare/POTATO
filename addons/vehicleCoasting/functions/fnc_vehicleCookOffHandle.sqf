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
* [_unit] call potato_vehicleCoasting_fnc_driverDeathHandle;
*//***************************************************************************/
params [["_vehicle", objNull, [objNull]]];
TRACE_2("params",_vehicle,typeOf _vehicle);

if !(alive _vehicle && local _vehicle &&
    !((getObjectID _vehicle) in GVAR(activeVehicles))) exitWith {
    TRACE_3("invalid vehicle",alive _vehicle,local _vehicle,alive driver _vehicle);
};
#ifdef DEBUG_MODE_FULL
diag_log text (str _vehicle + " lt: " + str (_vehicle getHitPointDamage "hitltrack") + " rt: "
        + str (_vehicle getHitPointDamage "hitrtrack") + " e: "
        + str (_vehicle getHitPointDamage "hitengine"));
#endif
private _driver = driver _vehicle;
// Make it happen more often
if (!isPlayer _driver && random 1 > 0.8) then {
    TRACE_1("Murdering",_driver);
    _driver setDamage [1, false];
};
if (speed _vehicle < 4 || alive _driver ||
    !(_vehicle isKindOf "LandVehicle")) exitWith {
    TRACE_3("invalid vehicle",speed _vehicle,alive _driver,typeOf _vehicle);
};
if (random 1 < POTATO_VEHICLEC_COASTING_COOKOFF_CHANCE) then {
    [_vehicle, _driver] call FUNC(addCoastingVehicle);
    [_vehicle] call FUNC(forceBail);
};
