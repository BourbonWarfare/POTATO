/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_object","_params"];

TRACE_2("",_object,local _object);
if (_object isEqualType grpNull) then {
    if (isServer) then {
        _this pushBack true;
        [FUNC(setLanguagesLocal), _this] call CBA_fnc_execNextFrame;
    };
} else {
    if (local _object) then {
        [FUNC(setLanguagesLocal), _this] call CBA_fnc_execNextFrame;
    };
};
