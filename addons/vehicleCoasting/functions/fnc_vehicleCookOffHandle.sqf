#include "../script_component.hpp"
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
* [_unit] call lmd_coast_fnc_driverDeathHandle;
*//***************************************************************************/
params [["_vehicle", objNull, [objNull]]];
TRACE_2("params",_vehicle,typeOf _vehicle);

if !(alive _vehicle && local _vehicle) exitWith {
    TRACE_2("invalid vehicle",alive _vehicle,local _vehicle);
};
diag_log text (str _vehicle + " lt: " + str (_vehicle getHitPointDamage "hitltrack") + " rt: "
        + str (_vehicle getHitPointDamage "hitrtrack") + " e: "
        + str (_vehicle getHitPointDamage "hitengine"));
private _driver = driver _vehicle;
// Make it happen more often
if !(isPlayer _driver && random 1 > 0.95) then {
    TRACE_1("Murdering",_driver);
    _driver setDamage [1, false];
};
if (speed _vehicle < 4 || alive _driver ||
    _vehicle getVariable [QGVAR(ddETime), 0] >  CBA_missionTime ||
    !(_vehicle isKindOf "LandVehicle")) exitWith {
    TRACE_2("invalid vehicle",speed _vehicle,alive _driver);
};
_vehicle setEffectiveCommander _driver;
_vehicle disableBrakes true;

private _freeRunLen = 20 + random 40; // Max runtime
if (_vehicle getHitPointDamage "hitrtrack" >  0.8 ||
        {_vehicle getHitPointDamage "hitltrack" >  0.8}) then {
    _vehicle setHitPointDamage ["hitrtrack", 0.4, false];
    _vehicle setHitPointDamage ["hitltrack", 0.4, false];
    _freeRunLen = 1 + random 2;
};

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
        params ["_vic"];
        if (speed _vic < 4) exitWith {
            #ifdef DEBUG_MODE_DRAW_EH
            GVAR(dev_traceHash) deleteAt str _vic;
            #endif
        };
        TRACE_2("adding EH",_this,typeOf _vic);
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
