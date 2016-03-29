#include "script_component.hpp"

// set current faction for next run
GVAR(lastGroupFactionIndex) = lbCurSel BUILD_GROUP_FACTIONS_IDC;

// get items in the to spawn bin
private _unitsToAdd = [];
for "_index" from 0 to ((lbSize BUILD_GROUP_TO_ADD_IDC) - 1) do {
    _unitsToAdd pushBack [lbData [BUILD_GROUP_TO_ADD_IDC, _index],
                          lbText [BUILD_GROUP_TO_ADD_IDC, _index],
                          lbPicture [BUILD_GROUP_TO_ADD_IDC, _index]];
};

// very much todo
GVAR(lastGroupUnitArray) = _unitsToAdd;
TRACE_1("Spawn message",[] call FUNC(getSpawnMachineId));

[GVAR(buildSpawnLocation),_unitsToAdd] remoteExecCall [QFUNC(buildAGroupSpawnServer), SERVER_CLIENT_ID];

// last thing, close dialog with success
closeDialog 1;
