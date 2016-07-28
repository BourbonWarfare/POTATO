/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_radio","_preset",["_isLongRange",false,[false]]];

private _label = if (_isLongRange) then { "name" } else { "label" };

[_radio, _preset, GVAR(addCommonChannelNumber), RADIO_TX, GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
[_radio, _preset, GVAR(addCommonChannelNumber), RADIO_RX, GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
[_radio, _preset, GVAR(addCommonChannelNumber), _label, GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);

TRACE_3("shared data",_radio,_preset,((((([ARR_2(_radio,_preset)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select (GVAR(addCommonChannelNumber) - 1));
