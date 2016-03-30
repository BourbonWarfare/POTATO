#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_force", false]];

//Check the script is run in multiplayer only
if (!isMultiplayer) exitWith { diag_log QUOTE([POTATO] Not in multiplayer, exiting FUNC(transferGroupsToHC)); };
if (!isServer) exitWith { diag_log QUOTE([POTATO] Not executing on server, exiting FUNC(transferGroupsToHC)); };

private _allHCs = entities "HeadlessClient_F";
if (_allHCs isEqualTo []) exitWith { diag_log QUOTE([POTATO] No headless clients found, exiting FUNC(transferGroupsToHC)); };
{ _hcIDs pushBack (owner _x); nil } count _allHCs;

private _timeBetweenTransfers = if (isNil QGVAR(timeBetweenTransfers)) then { 0.5 } else { GVAR(timeBetweenTransfers) };

// remove empty groups
{ if ((units _x) isEqualTo []) then { deleteGroup _x; }; nil } count allGroups;

//loop all groups
{
    if (!((groupOwner _x) in _hcIDs) && (_force || _x getVariable [GVAR(addGroupToHC), false])) then {
        [_x] remoteExecCall [QFUNC(transferGroupLocal), [_allHCs] call FUNC(getSpawnMachineId)];
    };

    sleep _timeBetweenTransfers;
    nil
} count allGroups;
