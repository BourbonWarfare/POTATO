#include "script_component.hpp"
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
