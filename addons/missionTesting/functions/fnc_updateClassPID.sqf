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
private _display = ctrlParent _control;
private _unit = nil;

switch (_ctrlIDC) do {
    case PID_CLASS_1_IDC: {_unit = GVAR(DummyUnits) select 0;};
    case PID_CLASS_2_IDC: {_unit = GVAR(DummyUnits) select 1;};
    case PID_CLASS_3_IDC: {_unit = GVAR(DummyUnits) select 2;};
};

TRACE_1("_unit",_unit);

private _class = lbData [_ctrlIDC,_selectedIndex];

private _dir = getDir _unit;
private _pos = getPosASLW _unit;
private _stance = unitPos _unit;

TRACE_1("_class",_class);

deleteVehicle _unit;

_newUnit = _class createVehicle _pos;
_newUnit enableSimulation false;
_newUnit setunitPos _stance;
_newUnit setDir _dir;

TRACE_1("_newUnit",_newUnit);

switch (_ctrlIDC) do {
    case PID_CLASS_1_IDC: {GVAR(DummyUnits) set [0,_newUnit];};
    case PID_CLASS_2_IDC: {GVAR(DummyUnits) set [1,_newUnit];};
    case PID_CLASS_3_IDC: {GVAR(DummyUnits) set [2,_newUnit];};
};

[5] call FUNC(updatePositionPID);
private _stanceIDC = _ctrlIDC + 3;
private _stanceCtrl = _display displayCtrl _stanceIDC;
private _stanceIndex = lbCurSel _stanceCtrl;
[_stanceCtrl,_stanceIndex] call FUNC(updateStancePID);
