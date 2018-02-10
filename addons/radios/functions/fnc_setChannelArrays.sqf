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
            missionNamespace getVariable [QGVAR(westSRChannelNames), [DEFAULT_SR_NAMES]],
            missionNamespace getVariable [QGVAR(westMRChannelNames), [DEFAULT_MR_NAMES]],
            missionNamespace getVariable [QGVAR(westLRChannelNames), [DEFAULT_LR_NAMES]]
        ]
    };
    case (east): {
        [
            missionNamespace getVariable [QGVAR(eastSRChannelNames), [DEFAULT_SR_NAMES]],
            missionNamespace getVariable [QGVAR(eastMRChannelNames), [DEFAULT_MR_NAMES]],
            missionNamespace getVariable [QGVAR(eastLRChannelNames), [DEFAULT_LR_NAMES]]
        ]
    };
    case (independent): {
        [
            missionNamespace getVariable [QGVAR(indySRChannelNames), [DEFAULT_SR_NAMES]],
            missionNamespace getVariable [QGVAR(indyMRChannelNames), [DEFAULT_MR_NAMES]],
            missionNamespace getVariable [QGVAR(indyLRChannelNames), [DEFAULT_LR_NAMES]]
        ]
    };
    default {
        [
            missionNamespace getVariable [QGVAR(civSRChannelNames), [DEFAULT_SR_NAMES]],
            missionNamespace getVariable [QGVAR(civMRChannelNames), [DEFAULT_MR_NAMES]],
            missionNamespace getVariable [QGVAR(civLRChannelNames), [DEFAULT_LR_NAMES]]
        ]
    };
}) params ["_populatedSR","_populatedMR","_populatedLR"];

TRACE_3("prefill",_populatedSR,_populatedMR,_populatedLR); // log channel info

// populate channel info
_ctrlGroup setVariable [QGVAR(srList), [_populatedSR, 16] call FUNC(fillChannelArray)];
_ctrlGroup setVariable [QGVAR(mrList), [_populatedMR, 20] call FUNC(fillChannelArray)];
_ctrlGroup setVariable [QGVAR(lrList), [_populatedLR, 20] call FUNC(fillChannelArray)];
