/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

GVAR(sideChannelArray) params [
    ["_westChanged", [], [[]]],
    ["_eastChanged", [], [[]]],
    ["_indyChanged", [], [[]]],
    ["_civChanged", [], [[]]]
];

([
    _westChanged,
    GVAR(westSRChannelNames),
    GVAR(westMRChannelNames),
    GVAR(westLRChannelNames)
] call FUNC(acreGetChannelArrays)) params ["_westSR","_westMR","_westLR"];

([
    _eastChanged,
    GVAR(eastSRChannelNames),
    GVAR(eastMRChannelNames),
    GVAR(eastLRChannelNames)
] call FUNC(acreGetChannelArrays)) params ["_eastSR","_eastMR","_eastLR"];

([
    _indyChanged,
    GVAR(indySRChannelNames),
    GVAR(indyMRChannelNames),
    GVAR(indyLRChannelNames)
] call FUNC(acreGetChannelArrays)) params ["_indySR","_indyMR","_indyLR"];

([
    _civChanged,
    GVAR(civSRChannelNames),
    GVAR(civMRChannelNames),
    GVAR(civLRChannelNames)
] call FUNC(acreGetChannelArrays)) params ["_civSR","_civMR","_civLR"];

[
    [_westSR,_westMR,_westLR,GVAR(westDefaultLanguages),GVAR(addCommonChannelWestMR),GVAR(addCommonChannelWestLR)], // west
    [_eastSR,_eastMR,_eastLR,GVAR(eastDefaultLanguages),GVAR(addCommonChannelEastMR),GVAR(addCommonChannelEastLR)], // east
    [_indySR,_indyMR,_indyLR,GVAR(indyDefaultLanguages),GVAR(addCommonChannelIndyMR),GVAR(addCommonChannelIndyLR)], // indy
    [_civSR,_civMR,_civLR,GVAR(civDefaultLanguages),GVAR(addCommonChannelCivMR),GVAR(addCommonChannelCivLR)] // civ
]
