/*
 * Author: AACO
 * Function used to
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_spectate_fnc_;
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
