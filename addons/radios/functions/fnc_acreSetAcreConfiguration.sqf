/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_sideIndex", 3, [3]],
    ["_channelData", [], [[]]],
    "_srVarName",
    "_mrVarName",
    "_lrVarName",
    "_babelVarName",
    "_sharedMrVarName",
    "_sharedLrVarName"
];

_channelData params [
    ["_sr", [], [[]]],
    ["_mr", [], [[]]],
    ["_lr", [], [[]]],
    ["_babel", [], [[]]],
    ["_sharedMr", false, [false]],
    ["_sharedLr", false, [false]]
];

if !(_sr isEqualTo []) then {
    (GVAR(sideChannelArray) select _sideIndex) set [0, true];
    [_srVarName, _sr, true, true] call ACEFUNC(common,setSetting);
};

if !(_mr isEqualTo []) then {
    (GVAR(sideChannelArray) select _sideIndex) set [1, true];
    [_mrVarName, _mr, true, true] call ACEFUNC(common,setSetting);
};

if !(_lr isEqualTo []) then {
    (GVAR(sideChannelArray) select _sideIndex) set [2, true];
    [_lrVarName, _lr, true, true] call ACEFUNC(common,setSetting);
};

[_babelVarName, _babel, true, true] call ACEFUNC(common,setSetting);
[_sharedMrVarName, _sharedMr, true, true] call ACEFUNC(common,setSetting);
[_sharedLrVarName, _sharedLr, true, true] call ACEFUNC(common,setSetting);
