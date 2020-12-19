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

params ["_control", "_selectedIndex"];

private _ctrlIDC = ctrlIDC _control;
private _unit = nil;

switch (_ctrlIDC) do {
    case PID_STANCE_1_IDC: {_unit = GVAR(DummyUnits) select 0;};
    case PID_STANCE_2_IDC: {_unit = GVAR(DummyUnits) select 1;};
    case PID_STANCE_3_IDC: {_unit = GVAR(DummyUnits) select 2;};
};

private _stance = lbData [_ctrlIDC,_selectedIndex];
_unit enableSimulation true;
_unit setunitPos _stance;
_unit enableSimulation false;

[] call FUNC(updatePositionPID);
