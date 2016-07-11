/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup",["_params", [], [[],true]]];
if (_params isEqualType true && {_params}) exitWith { LOG("data not set, or in strange state, exiting early"); };

_params params [
    ["_westData", [], [[]]],
    ["_eastData", [], [[]]],
    ["_indyData", [], [[]]],
    ["_civData", [], [[]]]
];

_westData params [
    ["_westSr", [], [[]]],
    ["_westMr", [], [[]]],
    ["_westLr", [], [[]]],
    ["_westBabel", [], [[]]],
    ["_westSharedMr", false, [false]],
    ["_westSharedLr", false, [false]]
];
[QGVAR(westSRChannelNames), _westSr, true] call ACEFUNC(common,setSetting);
[QGVAR(westMRChannelNames), _westMr, true] call ACEFUNC(common,setSetting);
[QGVAR(westLRChannelNames), _westLr, true] call ACEFUNC(common,setSetting);
[QGVAR(westDefaultLanguages), _westBabel, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelWestMR), _westSharedMr, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelWestLR), _westSharedLr, true] call ACEFUNC(common,setSetting);

_eastData params [
    ["_eastSr", [], [[]]],
    ["_eastMr", [], [[]]],
    ["_eastLr", [], [[]]],
    ["_eastBabel", [], [[]]],
    ["_eastSharedMr", false, [false]],
    ["_eastSharedLr", false, [false]]
];
[QGVAR(eastSRChannelNames), _eastSr, true] call ACEFUNC(common,setSetting);
[QGVAR(eastMRChannelNames), _eastMr, true] call ACEFUNC(common,setSetting);
[QGVAR(eastLRChannelNames), _eastLr, true] call ACEFUNC(common,setSetting);
[QGVAR(eastDefaultLanguages), _eastBabel, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelEastMR), _eastSharedMr, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelEastLR), _eastSharedLr, true] call ACEFUNC(common,setSetting);

_indyData params [
    ["_indySr", [], [[]]],
    ["_indyMr", [], [[]]],
    ["_indyLr", [], [[]]],
    ["_indyBabel", [], [[]]],
    ["_indySharedMr", false, [false]],
    ["_indySharedLr", false, [false]]
];
[QGVAR(indySRChannelNames), _indySr, true] call ACEFUNC(common,setSetting);
[QGVAR(indyMRChannelNames), _indyMr, true] call ACEFUNC(common,setSetting);
[QGVAR(indyLRChannelNames), _indyLr, true] call ACEFUNC(common,setSetting);
[QGVAR(indyDefaultLanguages), _indyBabel, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelIndyMR), _indySharedMr, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelIndyLR), _indySharedLr, true] call ACEFUNC(common,setSetting);

_civData params [
    ["_civSr", [], [[]]],
    ["_civMr", [], [[]]],
    ["_civLr", [], [[]]],
    ["_civBabel", [], [[]]],
    ["_civSharedMr", false, [false]],
    ["_civSharedLr", false, [false]]
];
[QGVAR(civSRChannelNames), _civSr, true] call ACEFUNC(common,setSetting);
[QGVAR(civMRChannelNames), _civMr, true] call ACEFUNC(common,setSetting);
[QGVAR(civLRChannelNames), _civLr, true] call ACEFUNC(common,setSetting);
[QGVAR(civDefaultLanguages), _civBabel, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelCivMR), _civSharedMr, true] call ACEFUNC(common,setSetting);
[QGVAR(addCommonChannelCivLR), _civSharedLr, true] call ACEFUNC(common,setSetting);
