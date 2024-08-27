/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_radio", "_preset", ["_isLongRange", false, [false]]];

private _label = ["label", "name"] select _isLongRange;
private _channelNumber = missionNamespace getVariable [QGVAR(addCommonChannelNumber), DEFAULT_COMMON_CH_NUM];
private _channelFreq = missionNamespace getVariable [QGVAR(addCommonChannelFreq), DEFAULT_COMMON_CH_FREQ];
private _channelName = missionNamespace getVariable [QGVAR(addCommonChannelName), DEFAULT_COMMON_CH_NAME];

[_radio, _preset, _channelNumber, RADIO_TX, _channelFreq] call ACRE_FUNC(setPresetChannelField);
[_radio, _preset, _channelNumber, RADIO_RX, _channelFreq] call ACRE_FUNC(setPresetChannelField);
[_radio, _preset, _channelNumber, _label, _channelName] call ACRE_FUNC(setPresetChannelField);
