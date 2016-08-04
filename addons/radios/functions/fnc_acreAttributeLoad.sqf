/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

if (!isServer) exitWith {};

params ["_ctrlGroup",["_params", [], [[],true]]];
if (_params isEqualType true && {_params}) exitWith { LOG("data not set, or in strange state, exiting early"); };

_params params [
    ["_westData", [], [[]]],
    ["_eastData", [], [[]]],
    ["_indyData", [], [[]]],
    ["_civData", [], [[]]]
];

[
    0,
    _westData,
    QGVAR(westSRChannelNames),
    QGVAR(westMRChannelNames),
    QGVAR(westLRChannelNames),
    QGVAR(westDefaultLanguages),
    QGVAR(addCommonChannelWestMR),
    QGVAR(addCommonChannelWestLR)
] call FUNC(acreSetAcreConfiguration);

[
    1,
    _eastData,
    QGVAR(eastSRChannelNames),
    QGVAR(eastMRChannelNames),
    QGVAR(eastLRChannelNames),
    QGVAR(eastDefaultLanguages),
    QGVAR(addCommonChannelEastMR),
    QGVAR(addCommonChannelEastLR)
] call FUNC(acreSetAcreConfiguration);

[
    2,
    _indyData,
    QGVAR(indySRChannelNames),
    QGVAR(indyMRChannelNames),
    QGVAR(indyLRChannelNames),
    QGVAR(indyDefaultLanguages),
    QGVAR(addCommonChannelIndyMR),
    QGVAR(addCommonChannelIndyLR)
] call FUNC(acreSetAcreConfiguration);

[
    3,
    _civData,
    QGVAR(civSRChannelNames),
    QGVAR(civMRChannelNames),
    QGVAR(civLRChannelNames),
    QGVAR(civDefaultLanguages),
    QGVAR(addCommonChannelCivMR),
    QGVAR(addCommonChannelCivLR)
] call FUNC(acreSetAcreConfiguration);
