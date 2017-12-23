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


#define SR_NAMES "Alpha","Bravo","Charlie","1st Platoon","Delta","Echo","Foxtrot","2nd Platoon","Golf","Hotel","India","3rd Platoon","COY","Air","Armor","Fire Support"
#define MR_NAMES "PLTNET 1","PLTNET 2","PLTNET 3","COY","CAS","ARMOR","FIRES"
#define LR_NAMES "PLTNET 1","PLTNET 2","PLTNET 3","COY","CAS","ARMOR","FIRES"

(switch (_side) do {
    case (west): {
        [
            missionNamespace getVariable [QGVAR(westSRChannelNames), [SR_NAMES]],
            missionNamespace getVariable [QGVAR(westMRChannelNames), [MR_NAMES]],
            missionNamespace getVariable [QGVAR(westLRChannelNames), [LR_NAMES]]
        ]
    };
    case (east): {
        [
            missionNamespace getVariable [QGVAR(eastSRChannelNames), [SR_NAMES]],
            missionNamespace getVariable [QGVAR(eastMRChannelNames), [MR_NAMES]],
            missionNamespace getVariable [QGVAR(eastLRChannelNames), [LR_NAMES]]
        ]
    };
    case (independent): {
        [
            missionNamespace getVariable [QGVAR(indySRChannelNames), [SR_NAMES]],
            missionNamespace getVariable [QGVAR(indyMRChannelNames), [MR_NAMES]],
            missionNamespace getVariable [QGVAR(indyLRChannelNames), [LR_NAMES]]
        ]
    };
    default {
        [
            missionNamespace getVariable [QGVAR(civSRChannelNames), [SR_NAMES]],
            missionNamespace getVariable [QGVAR(civMRChannelNames), [MR_NAMES]],
            missionNamespace getVariable [QGVAR(civLRChannelNames), [LR_NAMES]]
        ]
    };
}) params ["_populatedSR","_populatedMR","_populatedLR"];

TRACE_3("prefill",_populatedSR,_populatedMR,_populatedLR); // log channel info

// populate channel info
_ctrlGroup setVariable [QGVAR(srList), [_populatedSR, 16] call FUNC(fillChannelArray)];
_ctrlGroup setVariable [QGVAR(mrList), [_populatedMR, 20] call FUNC(fillChannelArray)];
_ctrlGroup setVariable [QGVAR(lrList), [_populatedLR, 20] call FUNC(fillChannelArray)];
