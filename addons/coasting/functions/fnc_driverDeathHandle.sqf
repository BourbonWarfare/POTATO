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
    !(_unit isKindOf "CAManBase")) exitWith {};

_vehicle = vehicle _unit;

if (!local _vehicle) exitWith {
    TRACE_1("Not local",_vehicle);
    [QGVAR(driverDeathHandle), [_vehicle], _vehicle] call CBA_fnc_targetEvent;
};

if (!(_vehicle isKindOf "LandVehicle") ||
    _unit != driver _vehicle ||
    speed _vehicle < 4 ||
    !alive _vehicle) exitWith {
    TRACE_3("ExitHandle",driver _vehicle,_unit,speed _vehicle);
};
TRACE_3("Continuing",_unit,_vehicle,speed _vehicle);

_vehicle setEffectiveCommander _unit;
if (_vehicle getHitPointDamage "hitengine" > 0.8) then {
    _vehicle setHitPointDamage ["hitengine", 0.8, false];
};

private _freeRunLen = 40 + random 10; // Max runtime
if (_vehicle getHitPointDamage "hitrtrack" >  0.8 ||
        {_vehicle getHitPointDamage "hitltrack" >  0.8}) then {
    _vehicle setHitPointDamage ["hitrtrack", 0.4, false];
    _vehicle setHitPointDamage ["hitltrack", 0.4, false];
    _freeRunLen = 1 + random 2;
};
_vehicle disableBrakes true;

if (_vehicle getVariable [QGVAR(ddETime), 0] >  CBA_missionTime) exitWith {
    TRACE_3("Exit timing",CBA_missionTime,_vehicle getVariable [ARR_2(QGVAR(ddETime),0)]);
};
_vehicle setVariable [QGVAR(ddETime), CBA_missionTime + _freeRunLen];

#ifdef DEBUG_MODE_FULL
[getPosASL _unit, "orange"] call ACEFUNC(frag,dev_sphereDraw);
diag_log text (str _vehicle + " lt: " + str (_vehicle getHitPointDamage "hitltrack") + " rt: "
        + str (_vehicle getHitPointDamage "hitrtrack") + " e: "
        + str (_vehicle getHitPointDamage "hitengine"));
#endif
#ifdef DEBUG_MODE_DRAW
[
    {
        params ["_vAr", "_h"];
        _vAr = _vAr#0;
        if (_vAr getVariable [QGVAR(ddLDraw), CBA_missionTime - 0.1] > CBA_missionTime) exitWith {};
        if (speed _vAr < 1 || _vAr getVariable QGVAR(ddETime) < CBA_missionTime) exitWith {
            [_h] call CBA_fnc_removePerFrameHandler;
        };
        private _pos = getPosATL _vAr vectorAdd [0, 0, 1];
        private _vDir = _vAr vectorModelToWorld [0, 1, 0];
        [_pos, _pos vectorAdd _vDir] call FUNC(addLine);
        private _f = _vDir vectorMultiply -(getMass _vAr)/1000;
        [_pos, _pos vectorAdd vectorDir _vAr, false, [0.8, 0, 0, 1]] call FUNC(addLine);
    },
    0.2,
    [_vehicle]
] call CBA_fnc_addPerFrameHandler;
#endif

[
    FUNC(driverDeathInit),
    [_vehicle, getCenterOfMass _vehicle, [500, 200]  select (_vehicle isKindOf "Tank")],
    1 + random 1
] call CBA_fnc_waitAndExecute;
