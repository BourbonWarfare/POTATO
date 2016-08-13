/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);
params ["_object",["_channelString","0,0,0",["",false]]];
if (_channelString isEqualType true && {_channelString}) exitWith { LOG("channels not set, or in strange state, exiting early"); };

[{
    params ["_object","_channelString"];
    (_channelString splitString ",") params [
        ["_sr", "0", [""]],
        ["_mr", "0", [""]],
        ["_lr", "0", [""]]
    ];

    _object setVariable [QGVAR(srChannel), (parseNumber _sr) + 1, true];
    _object setVariable [QGVAR(mrChannel), (parseNumber _mr) + 1, true];
    _object setVariable [QGVAR(lrChannel), (parseNumber _lr) + 1, true];
}, _this] call CBA_fnc_execNextFrame;
