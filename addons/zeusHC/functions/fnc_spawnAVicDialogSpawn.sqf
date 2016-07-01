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

// set current indices for next run
GVAR(lastVicFactionIndex) = lbCurSel SPAWN_VIC_FACTIONS_IDC;
GVAR(lastVicIndex) = lbCurSel SPAWN_VIC_LIST_IDC;

private _vehicleClass = lbData [SPAWN_VIC_LIST_IDC, lbCurSel SPAWN_VIC_LIST_IDC];
TRACE_1("Vehicle class", _vehicleClass);
private _side = switch (getNumber (configFile >> "CfgVehicles" >> _vehicleClass >> "side")) do { case 0: {east}; case 1: {west}; case 2: {resistance}; default {civilian}; };

[
    [GVAR(vicSpawnLocation), _vehicleClass, _side],
    QFUNC(spawnAVicSpawnLocal)
] call FUNC(hcPassthroughSpawn);

// last thing, close dialog with success
closeDialog 1;
