#include "../script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function should be called upon death of a unit to check if the
* unit is driving a vehicle and provide a chance of the vehicle going out
* of control. For debug mode, LMD_debug is required.
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
    alive _unit ||
    !(_unit isKindOf "CAManBase")) exitWith {
    TRACE_3("Invalid",isNull objectParent _unit,alive _unit,_unit isKindOf "CAManBase");
};

private _vehicle = vehicle _unit;

if (!local _vehicle) exitWith {
    TRACE_1("Not local",_vehicle);
    [QGVAR(driverDeathHandle), [_vehicle], _vehicle] call CBA_fnc_targetEvent;
};
diag_log text (str _vehicle + " lt: " + str (_vehicle getHitPointDamage "hitltrack") + " rt: "
        + str (_vehicle getHitPointDamage "hitrtrack") + " e: "
        + str (_vehicle getHitPointDamage "hitengine"));

if (!(_vehicle isKindOf "LandVehicle") ||
    speed _vehicle < 4 ||
    !alive _vehicle ||
    _unit != driver _vehicle) exitWith {
    TRACE_4("ExitHandle",typeOf _vehicle,speed _vehicle,_unit,driver _vehicle);
};
if (_vehicle getVariable [QGVAR(ddETime), 0] >  CBA_missionTime) exitWith {
    TRACE_2("Exit timing",CBA_missionTime,_vehicle getVariable [ARR_2(QGVAR(ddETime),0)]);
};
TRACE_3("Continuing",_unit,_vehicle,speed _vehicle);

_vehicle setEffectiveCommander _unit;
/*if (_vehicle getHitPointDamage "hitengine" > 0.8) then {
    _vehicle setHitPointDamage ["hitengine", 0.8, false];
};*/

private _freeRunLen = 20 + random 40; // Max runtime
if (_vehicle getHitPointDamage "hitrtrack" >  0.8 ||
        {_vehicle getHitPointDamage "hitltrack" >  0.8}) then {
    _vehicle setHitPointDamage ["hitrtrack", 0.4, false];
    _vehicle setHitPointDamage ["hitltrack", 0.4, false];
    _freeRunLen = 1 + random 2;
};
_vehicle disableBrakes true;

if (_vehicle isKindOf "Car_F") then {
    _freeRunLen = _freeRunLen / 3;
};

private _startTime = 1 + random 1;
#ifdef DEBUG_MODE_DRAW_EH
GVAR(dev_traceHash) set [str _vehicle, [_vehicle, _startTime, CBA_missionTime + _freeRunLen]];
#endif

_vehicle setVariable [QGVAR(ddETime), CBA_missionTime + _freeRunLen];
[
    {
        if (speed _vic < 4) exitWith {
            #ifdef DEBUG_MODE_DRAW_EH
            GVAR(dev_traceHash) deleteAt str _vic;
            #endif
        };
        TRACE_1("adding EH",_this);

        private _eh = [
            FUNC(driverDeathPFEH),
            0.21,
            _this
        ] call CBA_fnc_addPerFrameHandler;
        _vic setVariable [QGVAR(ddPFEH), _eh];
    },
    [_vehicle],
    _startTime
] call CBA_fnc_waitAndExecute;
