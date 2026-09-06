#include "script_component.hpp"
/*
 * Arguments:
 * 0: Data <ARRAY>
 *
 * Return Value:
 * <ARRAY>
 *
 * Examples:
 * [_data] call potato_core_fnc_stringArrayToSideArray
 */
TRACE_1("params",_this);

params ["_array"];

{
    if (_x isEqualType "") then {
        private _side = call compile _x;
        if (_side isEqualType west) then {
            _array set [_forEachIndex,_side]
        };
    };
} forEach _array;

_array
