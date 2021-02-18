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

private _factions = GVAR(factionClassList);

private _display = ctrlParent _control;
private _factionCtrl = ctrlIDC _control;
private _classCtrl = _factionCtrl + 3;
private _classCtrlCtrl = _display displayCtrl _classCtrl;

private _ctrl = _display displayCtrl _classCtrl;

lbClear _ctrl;

private _classes = _factions select _selectedIndex select 1;
{
    private _displayName = getText (configfile >> "CfgVehicles" >> _x >> "displayName");
    _ctrl lbAdd _displayName;
    _ctrl lbSetData [_forEachIndex,_x];
} forEach _classes;
_ctrl lbSetCurSel PID_DEFAULT_CLASS;
_ctrl ctrlCommit 0;
