/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

private _group = group player;

GVAR(playerLanguages) call ACRE_FUNC(babelSetSpokenLanguages);

private _groupSRChannel = _group getVariable [QGVAR(srChannel),1];
private _playerSRChannel = player getVariable [QGVAR(srChannel), _groupSRChannel];

private _groupMRChannel = _group getVariable [QGVAR(mrChannel),1];
private _playerMRChannel = player getVariable [QGVAR(mrChannel), _groupMRChannel];

private _groupLRChannel = _group getVariable [QGVAR(lrChannel),1];
private _playerLRChannel = player getVariable [QGVAR(lrChannel), _groupLRChannel];

TRACE_4("Player ACRE config",GVAR(playerLanguages),_playerSRChannel,_playerMRChannel,_playerLRChannel);
private _radio343 = ["ACRE_PRC343"] call ACRE_FUNC(getRadioByType);
if (!(isNil "_radio343") && {_radio343 != ""}) then {
    systemChat format ["[%1] is set to CH [%2]", _radio343, _playerSRChannel];
    [_radio343, _playerSRChannel] call ACRE_FUNC(setRadioChannel);
};

private _radio148 = ["ACRE_PRC148"] call ACRE_FUNC(getRadioByType);
if (!(isNil "_radio148") && {_radio148 != ""}) then {
    systemChat format ["[%1] is set to CH [%2]", _radio148, _groupMRChannel];
    [_radio148, _playerMRChannel] call ACRE_FUNC(setRadioChannel);
};

private _radio117 = ["ACRE_PRC117F"] call ACRE_FUNC(getRadioByType);
if (!(isNil "_radio117") && {_radio117 != ""}) then {
    systemChat format ["[%1] is set to CH [%2]", _radio117, _groupLRChannel];
    [_radio117, _playerLRChannel] call ACRE_FUNC(setRadioChannel);
};
