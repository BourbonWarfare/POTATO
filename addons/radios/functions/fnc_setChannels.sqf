/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_object","_params"];

if (_object isEqualType grpNull) then {
    if (isServer) then {
        _this pushBack true;
        [FUNC(setChannelsLocal), _this] call CBA_fnc_execNextFrame;
    };
} else {
    if (local _object) then {
        [FUNC(setChannelsLocal), _this] call CBA_fnc_execNextFrame;
    };
};
