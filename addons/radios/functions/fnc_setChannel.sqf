/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_group","_radioClass","_channelVar"];

private _groupChannel = _group getVariable [_channelVar,1];
private _playerChannel = player getVariable [_channelVar, _groupChannel];

private _radio = [_radioClass] call ACRE_FUNC(getRadioByType);
if (!(isNil "_radio") && {_radio != ""}) then {
    systemChat format ["[%1] is set to CH [%2]", _radio, _playerChannel];
    [_radio, _playerChannel] call ACRE_FUNC(setRadioChannel);
};
