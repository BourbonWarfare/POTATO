/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_paramsStrings"];

private _paramsArray = _paramsStrings splitString ",";

// TODO: remove BWC eventually
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

//IGNORE_PRIVATE_WARNING ["_enabled", "_addCommonChannelName", "_addCommonChannelNumber", "_addCommonChannelAllMR", "_addCommonChannelAllLR"];
_paramsArray params _paramsOutputs;

missionNamespace setVariable [QGVAR(enabled), [_enabled] call CFUNC(parseBool), true];
missionNamespace setVariable [QGVAR(addCommonChannelName), _addCommonChannelName, true];
missionNamespace setVariable [QGVAR(addCommonChannelAllMR), [_addCommonChannelAllMR] call CFUNC(parseBool), true];
missionNamespace setVariable [QGVAR(addCommonChannelAllLR), [_addCommonChannelAllLR] call CFUNC(parseBool), true];
missionNamespace setVariable [QGVAR(addCommonChannelNumber), parseNumber _addCommonChannelNumber, true];
