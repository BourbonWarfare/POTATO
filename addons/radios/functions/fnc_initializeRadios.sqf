/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

INFO_2("%1 - [InitState %2] Creating radio presets",diag_frameNo,GVAR(initState));

//Setup babble languages:
{
    _x call ACRE_FUNC(babelAddLanguageType);
} forEach GVAR(availableLanguages);

// copy radio presets
TRACE_3("west base presets",GVAR(westPresetSR),GVAR(westPresetMR),GVAR(westPresetLR));
[RADIO_SR, missionNamespace getVariable [QGVAR(westPresetSR), DEFAULT_WEST_PRESET], WEST_SR] call ACRE_FUNC(copyPreset);
[RADIO_MR, missionNamespace getVariable [QGVAR(westPresetMR), DEFAULT_WEST_PRESET], WEST_MR] call ACRE_FUNC(copyPreset);
[RADIO_LR, missionNamespace getVariable [QGVAR(westPresetLR), DEFAULT_WEST_PRESET], WEST_LR] call ACRE_FUNC(copyPreset);

TRACE_3("east base presets",GVAR(eastPresetSR),GVAR(eastPresetMR),GVAR(eastPresetLR));
[RADIO_SR, missionNamespace getVariable [QGVAR(eastPresetSR), DEFAULT_EAST_PRESET], EAST_SR] call ACRE_FUNC(copyPreset);
[RADIO_MR, missionNamespace getVariable [QGVAR(eastPresetMR), DEFAULT_EAST_PRESET], EAST_MR] call ACRE_FUNC(copyPreset);
[RADIO_LR, missionNamespace getVariable [QGVAR(eastPresetLR), DEFAULT_EAST_PRESET], EAST_LR] call ACRE_FUNC(copyPreset);

TRACE_3("indy base presets",GVAR(indyPresetSR),GVAR(indyPresetMR),GVAR(indyPresetLR));
[RADIO_SR, missionNamespace getVariable [QGVAR(indyPresetSR), DEFAULT_INDY_PRESET], INDY_SR] call ACRE_FUNC(copyPreset);
[RADIO_MR, missionNamespace getVariable [QGVAR(indyPresetMR), DEFAULT_INDY_PRESET], INDY_MR] call ACRE_FUNC(copyPreset);
[RADIO_LR, missionNamespace getVariable [QGVAR(indyPresetLR), DEFAULT_INDY_PRESET], INDY_LR] call ACRE_FUNC(copyPreset);

TRACE_3("civ base presets",GVAR(civPresetSR),GVAR(civPresetMR),GVAR(civPresetLR));
[RADIO_SR, missionNamespace getVariable [QGVAR(civPresetSR), DEFAULT_CIV_PRESET], CIV_SR] call ACRE_FUNC(copyPreset);
[RADIO_MR, missionNamespace getVariable [QGVAR(civPresetMR), DEFAULT_CIV_PRESET], CIV_MR] call ACRE_FUNC(copyPreset);
[RADIO_LR, missionNamespace getVariable [QGVAR(civPresetLR), DEFAULT_CIV_PRESET], CIV_LR] call ACRE_FUNC(copyPreset);

// setup default channel names
{
    [RADIO_MR, WEST_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach (missionNamespace getVariable [QGVAR(westMRChannelNames), [DEFAULT_MR_NAMES]]);
{
    [RADIO_LR, WEST_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach (missionNamespace getVariable [QGVAR(westLRChannelNames), [DEFAULT_LR_NAMES]]);

{
    [RADIO_MR, EAST_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach (missionNamespace getVariable [QGVAR(eastMRChannelNames), [DEFAULT_MR_NAMES]]);
{
    [RADIO_LR, EAST_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach (missionNamespace getVariable [QGVAR(eastLRChannelNames), [DEFAULT_LR_NAMES]]);

{
    [RADIO_MR, INDY_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach (missionNamespace getVariable [QGVAR(indyMRChannelNames), [DEFAULT_MR_NAMES]]);
{
    [RADIO_LR, INDY_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach (missionNamespace getVariable [QGVAR(indyLRChannelNames), [DEFAULT_LR_NAMES]]);

{
    [RADIO_MR, CIV_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach (missionNamespace getVariable [QGVAR(civMRChannelNames), [DEFAULT_MR_NAMES]]);
{
    [RADIO_LR, CIV_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach (missionNamespace getVariable [QGVAR(civLRChannelNames), [DEFAULT_LR_NAMES]]);

// set common channel after we pre-set the default channel names (avoid the name from getting overriden)
private _addCommonChannelAllMR = missionNamespace getVariable [QGVAR(addCommonChannelAllMR), DEFAULT_COMMON_CH_ENABLED];
private _addCommonChannelAllLR = missionNamespace getVariable [QGVAR(addCommonChannelAllLR), DEFAULT_COMMON_CH_ENABLED];

if (_addCommonChannelAllMR || missionNamespace getVariable [QGVAR(addCommonChannelWestMR), DEFAULT_COMMON_CH_ENABLED]) then {
    [RADIO_MR, WEST_MR, false] call FUNC(addSharedChannel);
};
if (_addCommonChannelAllLR || missionNamespace getVariable [QGVAR(addCommonChannelWestLR), DEFAULT_COMMON_CH_ENABLED]) then {
    [RADIO_LR, WEST_LR, true] call FUNC(addSharedChannel);
};

if (_addCommonChannelAllMR || missionNamespace getVariable [QGVAR(addCommonChannelEastMR), DEFAULT_COMMON_CH_ENABLED]) then {
    [RADIO_MR, EAST_MR, false] call FUNC(addSharedChannel);
};
if (_addCommonChannelAllLR || missionNamespace getVariable [QGVAR(addCommonChannelEastLR), DEFAULT_COMMON_CH_ENABLED]) then {
    [RADIO_LR, EAST_LR, true] call FUNC(addSharedChannel);
};

if (_addCommonChannelAllMR || missionNamespace getVariable [QGVAR(addCommonChannelIndyMR), DEFAULT_COMMON_CH_ENABLED]) then {
    [RADIO_MR, INDY_MR, false] call FUNC(addSharedChannel);
};
if (_addCommonChannelAllLR || missionNamespace getVariable [QGVAR(addCommonChannelIndyLR), DEFAULT_COMMON_CH_ENABLED]) then {
    [RADIO_LR, INDY_LR, true] call FUNC(addSharedChannel);
};

if (_addCommonChannelAllMR || missionNamespace getVariable [QGVAR(addCommonChannelCivMR), DEFAULT_COMMON_CH_ENABLED]) then {
    [RADIO_MR, CIV_MR, false] call FUNC(addSharedChannel);
};
if (_addCommonChannelAllLR || missionNamespace getVariable [QGVAR(addCommonChannelCivLR), DEFAULT_COMMON_CH_ENABLED]) then {
    [RADIO_LR, CIV_LR, true] call FUNC(addSharedChannel);
};

GVAR(initState) = 1;
LOG("Radios Initilized");
