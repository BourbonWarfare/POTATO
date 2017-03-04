/*
 * Author: AACO
 * Function used to handle list clicks
 * Should only be called from events
 *
 * Arguments:
 * 1: List index <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [nil,42] call potato_spectate_fnc_ui_handleListClick;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["", "_index"];
private _object	= missionNamespace getVariable [LIST tvData _index, objNull];

if (!isNull _object && {_object != GVAR(camTarget)}) then {
    [_object] call FUNC(setFocus);
    playsound "ReadoutClick";
};
