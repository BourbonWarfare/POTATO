/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_ctrlGroup","_side"];

// build a list of SR/MR/LR channels from ACE settings/mission settings
private _populatedSR = [];
private _populatedMR = [];
private _populatedLR = [];

(switch (_side) do {
    case (west): {
        [
            GVAR(westSRChannelNames),
            GVAR(westMRChannelNames),
            GVAR(westLRChannelNames)
        ]
    };
    case (east): {
        [
            GVAR(eastSRChannelNames),
            GVAR(eastMRChannelNames),
            GVAR(eastLRChannelNames)
        ]
    };
    case (independent): {
        [
            GVAR(indySRChannelNames),
            GVAR(indyMRChannelNames),
            GVAR(indyLRChannelNames)
        ]
    };
    default {
        [
            GVAR(civSRChannelNames),
            GVAR(civMRChannelNames),
            GVAR(civLRChannelNames)
        ]
    };
}) params ["_populatedSR","_populatedMR","_populatedLR"];

TRACE_3("prefill",_populatedSR,_populatedMR,_populatedLR); // log channel info

// populate channel info
_ctrlGroup setVariable [QGVAR(srList), [_populatedSR, 16] call FUNC(fillChannelArray)];
_ctrlGroup setVariable [QGVAR(mrList), [_populatedMR, 20] call FUNC(fillChannelArray)];
_ctrlGroup setVariable [QGVAR(lrList), [_populatedLR, 20] call FUNC(fillChannelArray)];
