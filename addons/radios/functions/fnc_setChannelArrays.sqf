/*
 *
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_side"];

// build a list of SR/MR/LR channels from ACE settings/mission settings
private _populatedSR = [];
private _populatedMR = [];
private _populatedLR = [];
switch (_side) do {
    case (west): {
        _populatedSR = GVAR(westSRChannelNames);
        _populatedMR = GVAR(westMRChannelNames);
        _populatedLR = GVAR(westLRChannelNames);
    };
    case (east): {
        _populatedSR = GVAR(eastSRChannelNames);
        _populatedMR = GVAR(eastMRChannelNames);
        _populatedLR = GVAR(eastLRChannelNames);
    };
    case (independent): {
        _populatedSR = GVAR(indySRChannelNames);
        _populatedMR = GVAR(indyMRChannelNames);
        _populatedLR = GVAR(indyLRChannelNames);
    };
    default {
        _populatedSR = GVAR(civSRChannelNames);
        _populatedMR = GVAR(civMRChannelNames);
        _populatedLR = GVAR(civLRChannelNames);
    };
};

TRACE_3("prefill",_populatedSR,_populatedMR,_populatedLR); // log channel info
// populate channel info
GVAR(srList) = [_populatedSR, 16] call FUNC(fillChannelArray);
GVAR(mrList) = [_populatedMR, 20] call FUNC(fillChannelArray);
GVAR(lrList) = [_populatedLR, 20] call FUNC(fillChannelArray);
