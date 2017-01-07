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

params [["_next", false, [false]]];

private _allUnits = allUnits;

if (count (_allUnits - [GVAR(camTarget)]) > 0) then {
    private _index = (_allUnits find GVAR(camTarget)) max 0;

    if (_next) then {
        _index = _index + 1;

        if (_index > count _allUnits - 1) then {
            _index = 0;
        };
    } else {
        _index = _index - 1;

        if (_index < 0) then {
            _index = count _allUnits - 1;
        };
    };

    if (_index >= 0 && _index <= count _allUnits - 1) then {
        [_allUnits select _index] call FUNC(setFocus);
    };
};
