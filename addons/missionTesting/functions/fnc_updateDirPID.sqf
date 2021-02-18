/*
 * Author: BadWolf, Pabo
 * Function is called once when the Breifings dialog is opened.
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_runWeaponsTest;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_control", "_newValue"];

private _ctrlIDC = ctrlIDC _control;
private _unit = nil;

switch (_ctrlIDC) do {
    case PID_DIR_SLIDER_1_IDC: {_unit = GVAR(DummyUnits) select 0;};
    case PID_DIR_SLIDER_2_IDC: {_unit = GVAR(DummyUnits) select 1;};
    case PID_DIR_SLIDER_3_IDC: {_unit = GVAR(DummyUnits) select 2;};
};

private _dirPlayer = getDir ACE_PLAYER;

_unit setDir  0 - _newValue + (_dirPlayer - 180);

if(_ctrlIDC == PID_DIR_SLIDER_1_IDC) then {[] call FUNC(updatePositionPID);};
