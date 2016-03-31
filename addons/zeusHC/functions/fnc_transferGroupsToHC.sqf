#include "script_component.hpp"

if (true) exitWith {diag_log text format ["[POTATO] - Disabled for now"];

TRACE_1("Params",_this);

params [["_force", false]];

//Check the script is run in multiplayer only
if (!isMultiplayer) exitWith { diag_log text format ["[POTATO] Not in multiplayer, exiting %1",QFUNC(transferGroupsToHC)]; };
if (!isServer) exitWith { diag_log text format ["[POTATO] Not executing on server, exiting %1",QFUNC(transferGroupsToHC)]; };

private _allHCs = entities "HeadlessClient_F";
if (_allHCs isEqualTo []) exitWith { diag_log text format ["[POTATO] No headless clients found, exiting %1", QFUNC(transferGroupsToHC)]; };

private _hcIDs = [];
{ _hcIDs pushBack (owner _x); nil } count _allHCs;

private _timeBetweenTransfers = if (isNil QGVAR(timeBetweenTransfers)) then { 0.5 } else { GVAR(timeBetweenTransfers) };

// remove empty groups
{ if ((units _x) isEqualTo []) then { deleteGroup _x; }; nil } count allGroups;

//loop all groups
{
    if (!((groupOwner _x) in _hcIDs) && (_force || _x getVariable [QGVAR(addGroupToHC), false])) then {
        [_x] remoteExecCall [QFUNC(transferGroupLocal), [_allHCs] call FUNC(getSpawnMachineId)];
    };

    sleep _timeBetweenTransfers;
    nil
} count allGroups;
