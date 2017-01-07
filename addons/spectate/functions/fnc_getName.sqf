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
params [["_unit", objNull, [objNull]]];

private _returnName = "";
if !(isNull _unit) then {
    if (_unit getVariable [QGVAR(deadName), ""] != "") then {
        _returnName = _unit getVariable QGVAR(deadName);
    } else {
        if (isPlayer _unit) then {
            _returnName = name _unit;
        } else {
            _returnName = format ["AI: %1", name _unit];
        };
    };
};

_returnName select [0, NAME_MAX_CHARACTERS]
