/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

[GVAR(radioInterference)] call ACRE_FUNC(setInterference);
[GVAR(terrainInterference)] call ACRE_FUNC(setLossModelScale);

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
    TRACE_1("West MR preset data",((((([ARR_2(RADIO_MR,WEST_MR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(westMRChannelNames);
{
    [RADIO_LR, WEST_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("West LR preset data",((((([ARR_2(RADIO_LR,WEST_LR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(westLRChannelNames);

{
    [RADIO_MR, EAST_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("East MR preset data",((((([ARR_2(RADIO_MR,EAST_MR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(eastMRChannelNames);
{
    [RADIO_LR, EAST_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("East LR preset data",((((([ARR_2(RADIO_LR,EAST_LR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(eastLRChannelNames);

{
    [RADIO_MR, INDY_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("Indy MR preset data",((((([ARR_2(RADIO_MR,INDY_MR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(indyMRChannelNames);
{
    [RADIO_LR, INDY_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("Indy LR preset data",((((([ARR_2(RADIO_LR,INDY_LR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(indyLRChannelNames);

{
    [RADIO_MR, CIV_MR, _forEachIndex + 1, "label", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("Civ MR preset data",((((([ARR_2(RADIO_MR,CIV_MR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
} forEach GVAR(civMRChannelNames);
{
    [RADIO_LR, CIV_LR, _forEachIndex + 1, "name", _x] call ACRE_FUNC(setPresetChannelField);
    TRACE_1("Civ LR preset data",((((([ARR_2(RADIO_LR,CIV_LR)] call ACRE_FUNC(getPresetData)) select 1)) select 0) select 1) select _forEachIndex);
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

private _groupLanguages = (group player) getVariable [QGVAR(assignedLanguages),[]];
GVAR(playerLanguages) = player getVariable [QGVAR(assignedLanguages), _groupLanguages];

TRACE_1("",playerSide);
private _presetArray = switch (playerSide) do {
    case west: { [WEST_SR, WEST_MR, WEST_LR, GVAR(westDefaultLanguages)] };
    case east: { [EAST_SR, EAST_MR, EAST_LR, GVAR(eastDefaultLanguages)] };
    case independent: { [INDY_SR, INDY_MR, INDY_LR, GVAR(indyDefaultLanguages)] };
    default { [CIV_SR, CIV_MR, CIV_LR, GVAR(civDefaultLanguages)] }; // should just be civs
};

_presetArray params ["_sr", "_mr", "_lr", "_babel"];

GVAR(sideLanguages) = _babel;

[RADIO_SR, _sr] call ACRE_FUNC(setPreset);
[RADIO_MR, _mr] call ACRE_FUNC(setPreset);
[RADIO_LR, _lr] call ACRE_FUNC(setPreset);

GVAR(initialized) = true;
LOG("Radios Initilized");

//TODO: build some kind of signal briefing
