/*
 * Author: AACO
 * Function used to switch the camera focus
 *
 * Arguments:
 * 0: Select the next or the previous focus <BOOL>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [] call potato_spectate_fnc_switchFocus;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_next", false, [false]]];

private _allUnits = allUnits;

if ((_allUnits - [GVAR(camTarget)]) isNotEqualTo []) then {
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
