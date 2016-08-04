/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_prefillData","_channelCount"];

private _arrayToFill = [];
for "_i" from 0 to (_channelCount - 1) do {
    if (_i < (count _prefillData) && {(_prefillData select _i) != ""}) then {
        _arrayToFill pushBack (_prefillData select _i);
    } else {
        _arrayToFill pushBack (format ["Channel %1", _i + 1]);
    };
};

_arrayToFill
