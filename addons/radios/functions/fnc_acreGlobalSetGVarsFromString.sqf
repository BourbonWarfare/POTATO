/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_paramsStrings"];

(_paramsStrings splitString ",") params [
    "_enabled",
    "_radioInterference",
    "_omnidirectionalAntenna",
    "_terrainInterference",
    "_addCommonChannelName",
    "_addCommonChannelNumber",
    "_addCommonChannelAllMR",
    "_addCommonChannelAllLR"
];

[QGVAR(enabled), [_enabled] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelName), _addCommonChannelName, true, true] call ACEFUNC(common,setSetting);
[QGVAR(radioInterference), [_radioInterference] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
[QGVAR(terrainInterference), parseNumber _terrainInterference, true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelAllMR), [_addCommonChannelAllMR] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelAllLR), [_addCommonChannelAllLR] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelNumber), parseNumber _addCommonChannelNumber, true, true] call ACEFUNC(common,setSetting);
[QGVAR(omnidirectionalAntenna), [_omnidirectionalAntenna] call CFUNC(parseBool), true, true] call ACEFUNC(common,setSetting);
