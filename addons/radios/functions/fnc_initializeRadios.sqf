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
TRACE_3("",GVAR(westPresetSR),GVAR(westPresetMR),GVAR(westPresetLR));
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
{
    ["ACRE_PRC148", WEST_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("West MR preset data",((((([ARR_2("ACRE_PRC148",WEST_MR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(westMRChannelNames);
{
    ["ACRE_PRC117F", WEST_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("West LR preset data",((((([ARR_2("ACRE_PRC117F",WEST_LR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(westLRChannelNames);

{
    ["ACRE_PRC148", EAST_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("East MR preset data",((((([ARR_2("ACRE_PRC148",EAST_MR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(eastMRChannelNames);
{
    ["ACRE_PRC117F", EAST_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("East LR preset data",((((([ARR_2("ACRE_PRC117F",EAST_LR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(eastLRChannelNames);

{
    ["ACRE_PRC148", INDY_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("Indy MR preset data",((((([ARR_2("ACRE_PRC148",INDY_MR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(indyMRChannelNames);
{
    ["ACRE_PRC117F", INDY_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("Indy LR preset data",((((([ARR_2("ACRE_PRC117F",INDY_LR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(indyLRChannelNames);

{
    ["ACRE_PRC148", CIV_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("Civ MR preset data",((((([ARR_2("ACRE_PRC148",CIV_MR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(civMRChannelNames);
{
    ["ACRE_PRC117F", CIV_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("Civ LR preset data",((((([ARR_2("ACRE_PRC117F",CIV_LR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(civLRChannelNames);

// set common channel after we pre-set the default channel names (avoid the name from getting overriden)
if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelWestMR)) then {
    ["ACRE_PRC148", WEST_MR, GVAR(addCommonChannelNumber), "frequencyTX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC148", WEST_MR, GVAR(addCommonChannelNumber), "frequencyRX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC148", WEST_MR, GVAR(addCommonChannelNumber), "label", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("shared west MR data",((((([ARR_2("ACRE_PRC148",WEST_MR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select (GVAR(addCommonChannelNumber) - 1));
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelWestLR)) then {
    ["ACRE_PRC117F", WEST_LR, GVAR(addCommonChannelNumber), "frequencyTX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC117F", WEST_LR, GVAR(addCommonChannelNumber), "frequencyRX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC117F", WEST_LR, GVAR(addCommonChannelNumber), "name", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("shared west LR data",((((([ARR_2("ACRE_PRC117F",WEST_LR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select (GVAR(addCommonChannelNumber) - 1));
};

if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelEastMR)) then {
    ["ACRE_PRC148", EAST_MR, GVAR(addCommonChannelNumber), "frequencyTX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC148", EAST_MR, GVAR(addCommonChannelNumber), "frequencyRX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC148", EAST_MR, GVAR(addCommonChannelNumber), "label", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("shared east MR data",((((([ARR_2("ACRE_PRC148",EAST_MR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select (GVAR(addCommonChannelNumber) - 1));
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelEastLR)) then {
    ["ACRE_PRC117F", EAST_LR, GVAR(addCommonChannelNumber), "frequencyTX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC117F", EAST_LR, GVAR(addCommonChannelNumber), "frequencyRX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC117F", EAST_LR, GVAR(addCommonChannelNumber), "name", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("shared east LR data",((((([ARR_2("ACRE_PRC117F",EAST_LR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select (GVAR(addCommonChannelNumber) - 1));
};

if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelIndyMR)) then {
    ["ACRE_PRC148", INDY_MR, GVAR(addCommonChannelNumber), "frequencyTX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC148", INDY_MR, GVAR(addCommonChannelNumber), "frequencyRX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC148", INDY_MR, GVAR(addCommonChannelNumber), "label", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("shared indy MR data",((((([ARR_2("ACRE_PRC148",INDY_MR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select (GVAR(addCommonChannelNumber) - 1));
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelIndyLR)) then {
    ["ACRE_PRC117F", INDY_LR, GVAR(addCommonChannelNumber), "frequencyTX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC117F", INDY_LR, GVAR(addCommonChannelNumber), "frequencyRX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC117F", INDY_LR, GVAR(addCommonChannelNumber), "name", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("shared indy LR data",((((([ARR_2("ACRE_PRC117F",INDY_LR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select (GVAR(addCommonChannelNumber) - 1));
};

if (GVAR(addCommonChannelAllMR) || GVAR(addCommonChannelCivMR)) then {
    ["ACRE_PRC148", CIV_MR, GVAR(addCommonChannelNumber), "frequencyTX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC148", CIV_MR, GVAR(addCommonChannelNumber), "frequencyRX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC148", CIV_MR, GVAR(addCommonChannelNumber), "label", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("shared civ MR data",((((([ARR_2("ACRE_PRC148",CIV_MR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select (GVAR(addCommonChannelNumber) - 1));
};
if (GVAR(addCommonChannelAllLR) || GVAR(addCommonChannelCivLR)) then {
    ["ACRE_PRC117F", CIV_LR, GVAR(addCommonChannelNumber), "frequencyTX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC117F", CIV_LR, GVAR(addCommonChannelNumber), "frequencyRX", GVAR(addCommonChannelFreq)] call ACRE_FUNC(setPresetChannelField);
    ["ACRE_PRC117F", CIV_LR, GVAR(addCommonChannelNumber), "name", GVAR(addCommonChannelName)] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("shared civ LR data",((((([ARR_2("ACRE_PRC117F",CIV_LR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select (GVAR(addCommonChannelNumber) - 1));
};

private _groupLanguages = (group player) getVariable [QGVAR(assignedLanguages),[]];
GVAR(playerLanguages) = player getVariable [QGVAR(assignedLanguages), _groupLanguages];

TRACE_1("",playerSide);
switch (playerSide) do {
    case west: {
        if (GVAR(playerLanguages) isEqualTo []) then {
            GVAR(playerLanguages) = GVAR(westDefaultLanguage);
        };
        ["ACRE_PRC343", WEST_SR] call ACRE_FUNC(setPreset);
        ["ACRE_PRC148", WEST_MR] call ACRE_FUNC(setPreset);
        ["ACRE_PRC117F", WEST_LR] call ACRE_FUNC(setPreset);
    };
    case east: {
        if (GVAR(playerLanguages) isEqualTo []) then {
            GVAR(playerLanguages) = GVAR(eastDefaultLanguage);
        };
        ["ACRE_PRC343", EAST_SR] call ACRE_FUNC(setPreset);
        ["ACRE_PRC148", EAST_MR] call ACRE_FUNC(setPreset);
        ["ACRE_PRC117F", EAST_LR] call ACRE_FUNC(setPreset);
    };
    case independent: {
        if (GVAR(playerLanguages) isEqualTo []) then {
            GVAR(playerLanguages) = GVAR(indyDefaultLanguage);
        };
        ["ACRE_PRC343", INDY_SR] call ACRE_FUNC(setPreset);
        ["ACRE_PRC148", INDY_MR] call ACRE_FUNC(setPreset);
        ["ACRE_PRC117F", INDY_LR] call ACRE_FUNC(setPreset);
    };
    default { // should just be civs
        if (GVAR(playerLanguages) isEqualTo []) then {
            GVAR(playerLanguages) = GVAR(civDefaultLanguage);
        };
        ["ACRE_PRC343", CIV_SR] call ACRE_FUNC(setPreset);
        ["ACRE_PRC148", CIV_MR] call ACRE_FUNC(setPreset);
        ["ACRE_PRC117F", CIV_LR] call ACRE_FUNC(setPreset);
    };
};

GVAR(initialized) = true;
LOG("Radios Initilized");

//TODO: build some kind of signal briefing
