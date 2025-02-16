#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function is the PFEH handler that handles both the slowing and eventual
* stopping of the uncontrolled vehicle the event handler is attached to
*
* Arguments:
* None
*
* Return:
* None
*
* Example:
* [] call potato_vehicleCoasting_fnc_coastVehicle;
*//***************************************************************************/
private _vehicles = GVAR(activeVehicles);
TRACE_1("Coast handler",CBA_missionTime);
{
    _y params ["_vic", "_minTime", "_endTime"];
    TRACE_3("coasting",_vic,_minTime,_endTime);
    private _spd = abs speed _vic;
    if (CBA_missionTime < _minTime && alive _vic) then {continue};
    TRACE_5("data",_spd,!local _vic,!alive _vic,brakesDisabled _vic,_endTime < CBA_missionTime);
    if (!local _vic ||
        !alive _vic ||
        _spd < 1 ||
        !(brakesDisabled _vic) ||
        _endTime < CBA_missionTime) exitWith {
        TRACE_2("exitPFEH",_spd,_vic);
        #ifdef DEBUG_MODE_FULL
        diag_log text ("null:" + str (isNull _vic) + " spd:" + str _spd);
        #endif
        #ifdef DEBUG_MODE_DRAW_EH
        GVAR(dev_traceHash) deleteAt str _vic;
        #endif
        _vic disableBrakes false;
        _vic sendSimpleCommand "KEY DOWN";
        GVAR(activeVehicles) deleteAt _x;
    };
    /*if (_spd < 15 + random 10 && count (crew _vic select {!isPlayer _x && alive _x}) > 0) then {
        private _randValue = linearConversion [15, 30, _spd, 0.8, 0, true];
        {
            if (_randValue < random 1) then {
                unassignVehicle _x;
                _x leaveVehicle _vic;
                _x action ["eject", _vic];
            };
        } forEach crew _vic;
    };*/
    //private _force = _vic vectorModelToWorld [0, 1, 0];
} forEach GVAR(activeVehicles);

if (GVAR(activeVehicles) isEqualTo createHashMap) then {
    GVAR(loopRunning) = false;
} else {
    [{call FUNC(coastVehicles)}, 0, COAST_LOOP_INTERVAL] call CBA_fnc_waitAndExecute;
};
