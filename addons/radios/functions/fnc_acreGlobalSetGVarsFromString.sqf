/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_paramsStrings"];

private _paramsArray = _paramsStrings splitString ",";
private _paramsOutputs = if (count _paramsArray == 8) then {
    [
        "_enabled",
        "",
        "",
        "",
        "_addCommonChannelName",
        "_addCommonChannelNumber",
        "_addCommonChannelAllMR",
        "_addCommonChannelAllLR"
    ]
} else {
    [
        "_enabled",
        "_addCommonChannelName",
        "_addCommonChannelNumber",
        "_addCommonChannelAllMR",
        "_addCommonChannelAllLR"
    ]
};

_paramsArray params _paramsOutputs;

[QGVAR(enabled), [_enabled] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelName), _addCommonChannelName, true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelAllMR), [_addCommonChannelAllMR] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelAllLR), [_addCommonChannelAllLR] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelNumber), parseNumber _addCommonChannelNumber, true, true] call ACEFUNC(common,setSetting);
