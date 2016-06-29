/*
 *
 */
#include "script_component.hpp"
TRACE_1("params",_this);

[GVAR(radioInterference)] call ACRE_FUNC(setInterference);
[GVAR(terrainInterference)] call (ACRE_FUNC(setLossModelScale);

//Setup babble languages:
GVAR(languages) = missionNamespace getVariable [QGVAR(availableLanguages), GVAR(defaultLanguages)];
{
  _x call ACRE_FUNC(babelAddLanguageType);
} forEach GVAR(languages);

// copy radio presets
["ACRE_PRC343", GVAR(westPresetSR), "west343"] call ACRE_FUNC(copyPreset);
["ACRE_PRC148", GVAR(westPresetMR), "west148"] call ACRE_FUNC(copyPreset);
["ACRE_PRC117F", GVAR(westPresetLR), "west117"] call ACRE_FUNC(copyPreset);

["ACRE_PRC343", GVAR(eastPresetSR), "east343"] call ACRE_FUNC(copyPreset);
["ACRE_PRC148", GVAR(eastPresetMR), "east148"] call ACRE_FUNC(copyPreset);
["ACRE_PRC117F", GVAR(eastPresetLR), "east117"] call ACRE_FUNC(copyPreset);

["ACRE_PRC343", GVAR(indyPresetSR), "indy343"] call ACRE_FUNC(copyPreset);
["ACRE_PRC148", GVAR(indyPresetMR), "indy148"] call ACRE_FUNC(copyPreset);
["ACRE_PRC117F", GVAR(indyPresetLR), "indy117"] call ACRE_FUNC(copyPreset);

["ACRE_PRC343", GVAR(civPresetSR), "civ343"] call ACRE_FUNC(copyPreset);
["ACRE_PRC148", GVAR(civPresetMR), "civ148"] call ACRE_FUNC(copyPreset);
["ACRE_PRC117F", GVAR(civPresetLR), "civ117"] call ACRE_FUNC(copyPreset);

// setup default channel names
{
    ["ACRE_PRC148", "west148", _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(westMRChannelNames);
{
    ["ACRE_PRC117F", "west117", _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(westLRChannelNames);

{
    ["ACRE_PRC148", "east148", _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(eastMRChannelNames);
{
    ["ACRE_PRC117F", "east117", _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(eastLRChannelNames);

{
    ["ACRE_PRC148", "indy148", _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(indyMRChannelNames);
{
    ["ACRE_PRC117F", "indy117", _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(indyLRChannelNames);

{
    ["ACRE_PRC148", "civ148", _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(civMRChannelNames);
{
    ["ACRE_PRC117F", "civ117", _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
} forEach GVAR(civLRChannelNames);

// set common channel after we pre-set the default channel names (avoid the name from getting overriden)
if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelWestMR)) then {
    // set channel data here
    ["ACRE_PRC148", "west148", GVAR(addCommonChannelNumber), "label", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelWestLR)) then {
    // set channel data here
    ["ACRE_PRC117F", "west117", GVAR(addCommonChannelNumber), "name", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};

if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelEastMR)) then {
    // set channel data here
    ["ACRE_PRC148", "east148", GVAR(addCommonChannelNumber), "label", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelEastLR)) then {
    // set channel data here
    ["ACRE_PRC117F", "east117", GVAR(addCommonChannelNumber), "name", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};

if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelIndyMR)) then {
    // set channel data here
    ["ACRE_PRC148", "indy148", GVAR(addCommonChannelNumber), "label", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelIndyLR)) then {
    // set channel data here
    ["ACRE_PRC117F", "indy117", GVAR(addCommonChannelNumber), "name", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};

if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelCivMR)) then {
    // set channel data here
    ["ACRE_PRC148", "civ148", GVAR(addCommonChannelNumber), "label", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelCivLR)) then {
    // set channel data here
    ["ACRE_PRC117F", "civ117", GVAR(addCommonChannelNumber), "name", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
};

GVAR(initilized);
