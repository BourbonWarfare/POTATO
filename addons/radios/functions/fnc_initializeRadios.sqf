/*
 *
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

[GVAR(radioInterference)] call ACRE_FUNC(setInterference);
[GVAR(terrainInterference)] call ACRE_FUNC(setLossModelScale);

//Setup babble languages:
GVAR(languages) = missionNamespace getVariable [QGVAR(availableLanguages), GVAR(defaultLanguages)];
{
    _x call ACRE_FUNC(babelAddLanguageType);
} forEach GVAR(languages);

// copy radio presets
["ACRE_PRC343", GVAR(westPresetSR), WEST_SR] call ACRE_FUNC(copyPreset);
["ACRE_PRC148", GVAR(westPresetMR), WEST_MR] call ACRE_FUNC(copyPreset);
["ACRE_PRC117F", GVAR(westPresetLR), WEST_LR] call ACRE_FUNC(copyPreset);

["ACRE_PRC343", GVAR(eastPresetSR), EAST_SR] call ACRE_FUNC(copyPreset);
["ACRE_PRC148", GVAR(eastPresetMR), EAST_MR] call ACRE_FUNC(copyPreset);
["ACRE_PRC117F", GVAR(eastPresetLR), EAST_LR] call ACRE_FUNC(copyPreset);

["ACRE_PRC343", GVAR(indyPresetSR), INDY_SR] call ACRE_FUNC(copyPreset);
["ACRE_PRC148", GVAR(indyPresetMR), INDY_MR] call ACRE_FUNC(copyPreset);
["ACRE_PRC117F", GVAR(indyPresetLR), INDY_LR] call ACRE_FUNC(copyPreset);

["ACRE_PRC343", GVAR(civPresetSR), CIV_SR] call ACRE_FUNC(copyPreset);
["ACRE_PRC148", GVAR(civPresetMR), CIV_MR] call ACRE_FUNC(copyPreset);
["ACRE_PRC117F", GVAR(civPresetLR), CIV_LR] call ACRE_FUNC(copyPreset);

// setup default channel names
TRACE_1("pre",[ARR_2("ACRE_PRC148",WEST_MR)] call ACRE_FUNC(getPresetData));
{
    ["ACRE_PRC148", WEST_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(westMRChannelNames);
TRACE_1("post",[ARR_2("ACRE_PRC148",WEST_MR)] call ACRE_FUNC(getPresetData));
{
    ["ACRE_PRC117F", WEST_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(westLRChannelNames);

{
    ["ACRE_PRC148", EAST_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(eastMRChannelNames);
{
    ["ACRE_PRC117F", EAST_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(eastLRChannelNames);

{
    ["ACRE_PRC148", INDY_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(indyMRChannelNames);
{
    ["ACRE_PRC117F", INDY_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(indyLRChannelNames);

{
    ["ACRE_PRC148", CIV_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(civMRChannelNames);
{
    ["ACRE_PRC117F", CIV_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(civLRChannelNames);

// set common channel after we pre-set the default channel names (avoid the name from getting overriden)
if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelWestMR)) then {
    // set channel data here
    ["ACRE_PRC148", WEST_MR, GVAR(addCommonChannelNumber), "label", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelWestLR)) then {
    // set channel data here
    ["ACRE_PRC117F", WEST_LR, GVAR(addCommonChannelNumber), "name", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};

if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelEastMR)) then {
    // set channel data here
    ["ACRE_PRC148", EAST_MR, GVAR(addCommonChannelNumber), "label", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelEastLR)) then {
    // set channel data here
    ["ACRE_PRC117F", EAST_LR, GVAR(addCommonChannelNumber), "name", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};

if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelIndyMR)) then {
    // set channel data here
    ["ACRE_PRC148", INDY_MR, GVAR(addCommonChannelNumber), "label", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelIndyLR)) then {
    // set channel data here
    ["ACRE_PRC117F", INDY_LR, GVAR(addCommonChannelNumber), "name", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};

if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelCivMR)) then {
    // set channel data here
    ["ACRE_PRC148", CIV_MR, GVAR(addCommonChannelNumber), "label", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelCivLR)) then {
    // set channel data here
    ["ACRE_PRC117F", CIV_LR, GVAR(addCommonChannelNumber), "name", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};

GVAR(initialized) = true;
LOG("Radios Initilized");
