/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

INFO_2("%1 - [InitState %2] Creating radio presets", diag_frameNo, GVAR(initState));

//Setup babble languages:
{
    _x call ACRE_FUNC(babelAddLanguageType);
} forEach GVAR(availableLanguages);

// copy radio presets
TRACE_3("west base presets",GVAR(westPresetSR),GVAR(westPresetMR),GVAR(westPresetLR));
[RADIO_SR, GVAR(westPresetSR), WEST_SR] call ACRE_FUNC(copyPreset);
[RADIO_MR, GVAR(westPresetMR), WEST_MR] call ACRE_FUNC(copyPreset);
[RADIO_LR, GVAR(westPresetLR), WEST_LR] call ACRE_FUNC(copyPreset);

TRACE_3("east base presets",GVAR(eastPresetSR),GVAR(eastPresetMR),GVAR(eastPresetLR));
[RADIO_SR, GVAR(eastPresetSR), EAST_SR] call ACRE_FUNC(copyPreset);
[RADIO_MR, GVAR(eastPresetMR), EAST_MR] call ACRE_FUNC(copyPreset);
[RADIO_LR, GVAR(eastPresetLR), EAST_LR] call ACRE_FUNC(copyPreset);

TRACE_3("indy base presets",GVAR(indyPresetSR),GVAR(indyPresetMR),GVAR(indyPresetLR));
[RADIO_SR, GVAR(indyPresetSR), INDY_SR] call ACRE_FUNC(copyPreset);
[RADIO_MR, GVAR(indyPresetMR), INDY_MR] call ACRE_FUNC(copyPreset);
[RADIO_LR, GVAR(indyPresetLR), INDY_LR] call ACRE_FUNC(copyPreset);

TRACE_3("civ base presets",GVAR(civPresetSR),GVAR(civPresetMR),GVAR(civPresetLR));
[RADIO_SR, GVAR(civPresetSR), CIV_SR] call ACRE_FUNC(copyPreset);
[RADIO_MR, GVAR(civPresetMR), CIV_MR] call ACRE_FUNC(copyPreset);
[RADIO_LR, GVAR(civPresetLR), CIV_LR] call ACRE_FUNC(copyPreset);

// setup default channel names
{
    [RADIO_MR, WEST_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(westMRChannelNames);
{
    [RADIO_LR, WEST_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(westLRChannelNames);

{
    [RADIO_MR, EAST_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(eastMRChannelNames);
{
    [RADIO_LR, EAST_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(eastLRChannelNames);

{
    [RADIO_MR, INDY_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(indyMRChannelNames);
{
    [RADIO_LR, INDY_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(indyLRChannelNames);

{
    [RADIO_MR, CIV_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(civMRChannelNames);
{
    [RADIO_LR, CIV_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(civLRChannelNames);

// set common channel after we pre-set the default channel names (avoid the name from getting overriden)
if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelWestMR)) then {
    [RADIO_MR, WEST_MR, false] call FUNC(addSharedChannel);
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelWestLR)) then {
    [RADIO_LR, WEST_LR, true] call FUNC(addSharedChannel);
};

if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelEastMR)) then {
    [RADIO_MR, EAST_MR, false] call FUNC(addSharedChannel);
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelEastLR)) then {
    [RADIO_LR, EAST_LR, true] call FUNC(addSharedChannel);
};

if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelIndyMR)) then {
    [RADIO_MR, INDY_MR, false] call FUNC(addSharedChannel);
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelIndyLR)) then {
    [RADIO_LR, INDY_LR, true] call FUNC(addSharedChannel);
};

if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelCivMR)) then {
    [RADIO_MR, CIV_MR, false] call FUNC(addSharedChannel);
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelCivLR)) then {
    [RADIO_LR, CIV_LR, true] call FUNC(addSharedChannel);
};

GVAR(initState) = 1;
LOG("Radios Initilized");
