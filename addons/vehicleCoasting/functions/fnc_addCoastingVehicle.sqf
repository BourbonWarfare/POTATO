#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function initializes a CBA perframe event handler to slow the run away
* vehicle and eventually stop it all together.
*
* Arguments:
* _vehicle - The uncontrolled vehicle (OBJECT)
* _driver - The vehicle's driver (OBJECT)
*
* Return:
* None
*
* Example:
* [cursorObject, driver cursorObject] call potato_vehicleCoasting_fnc_addCoastingVehicle;
*//***************************************************************************/
params [
    ["_vehicle", objNull],
    ["_driver", objNull]
];
TRACE_1("Adding",_this);
if (isNull _vehicle || (getObjectID _vehicle) in GVAR(activeVehicles)) exitWith {
    TRACE_2("Bad or active vehicle",isNull _vehicle,(getObjectID _vehicle) in GVAR(activeVehicles));
};

_vehicle setEffectiveCommander _driver;
_vehicle disableBrakes true;

private _freeRunLen = 20 + random 40; // Max runtime
// Simulate broken tracks running out
if (_vehicle getHitPointDamage "hitrtrack" >  0.8 ||
        {_vehicle getHitPointDamage "hitltrack" >  0.8}) then {
    _vehicle setHitPointDamage ["hitrtrack", 0.4 min (_vehicle getHitPointDamage "hitrtrack"), false];
    _vehicle setHitPointDamage ["hitltrack", 0.4 min (_vehicle getHitPointDamage "hitltrack"), false];
    _freeRunLen = 2 + random 3;
};

if (_vehicle isKindOf "Car_F") then {
    _freeRunLen = _freeRunLen / 2;
};

private _startTime = 1 + random 1;
#ifdef DEBUG_MODE_DRAW_EH
GVAR(dev_traceHash) set [str _vehicle, [_vehicle, _startTime, CBA_missionTime + _freeRunLen]];
#endif

private _endTime = CBA_missionTime + _freeRunLen;
private _minTime = CBA_missionTime + _freeRunLen * 0.2;
[{
    params ["_vic", "_minTime", "_endTime"];
    if (speed _vic < 4) exitWith {
        TRACE_2("vehicle slowed",_this,speed _vic);
        #ifdef DEBUG_MODE_DRAW_EH
        GVAR(dev_traceHash) deleteAt str _vic;
        #endif
    };
    TRACE_2("adding EH",_this,typeOf _vic);
    GVAR(activeVehicles) set [getObjectID _vic, [_vic, _minTime, _endTime]];
    if !(GVAR(loopRunning)) then {
        GVAR(loopRunning) = true;
        call FUNC(coastVehicles);
    };
}, [_vehicle, _minTime, _endTime], _startTime] call CBA_fnc_waitAndExecute;
