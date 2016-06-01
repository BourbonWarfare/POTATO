/*
 * Author: AACO
 * Function used to get all the setting from the UI and send them to the HC/Server
 * Saves the last run data
 * Should only be called from UI events
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

// set current faction for next run
GVAR(lastGroupFactionIndex) = lbCurSel BUILD_GROUP_FACTIONS_IDC;

// get items in the to spawn bin
private _unitsToSave = [];
private _unitsToAdd = [];
for "_index" from 0 to ((lbSize BUILD_GROUP_TO_ADD_IDC) - 1) do {
    _unitsToSave pushBack [lbData [BUILD_GROUP_TO_ADD_IDC, _index],
                           lbText [BUILD_GROUP_TO_ADD_IDC, _index],
                           lbPicture [BUILD_GROUP_TO_ADD_IDC, _index]];

    _unitsToAdd pushBack lbData [BUILD_GROUP_TO_ADD_IDC, _index];
};

GVAR(lastGroupUnitArray) = _unitsToSave;

[
    [GVAR(buildSpawnLocation), _unitsToAdd],
    QFUNC(buildAGroupSpawnLocal)
] call FUNC(hcPassthrough);

// last thing, close dialog with success
closeDialog 1;
