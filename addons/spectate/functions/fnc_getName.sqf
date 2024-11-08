/*
 * Author: AACO
 * Function used to get the name of a player, or AI prefixed name of a non player
 *
 * Arguments:
 * 0: Object to get name of <OBJECT>
 *
 * Return Value:
 * Unit name <STRING>
 *
 * Examples:
 * [player] call potato_spectate_fnc_getName;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_unit", objNull, [objNull]]];

private _returnName = "";

if !(isNull _unit) then {
    _returnName = _unit getVariable [QGVAR(cachedName), ""];
    if (_returnName == "" || _returnName == "AI: ") then {
        if (_unit getVariable [QGVAR(deadName), ""] != "") then {
            _returnName = _unit getVariable QGVAR(deadName);
        } else {
            if (isPlayer _unit) then {
                _returnName = name _unit;
            } else {
                _returnName = format ["AI: %1", name _unit];
            };
        };

        _returnName = _returnName select [0, NAME_MAX_CHARACTERS];
        _unit setVariable [QGVAR(cachedName), _returnName];
    };
};

_returnName
