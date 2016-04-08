#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_force", false]];

waitUntil { time > 0 };

//Check the script is run in multiplayer only
if (!isMultiplayer) exitWith { diag_log text format ["[POTATO] Not in multiplayer, exiting %1",QFUNC(transferGroupsToHC)]; };
if (!isServer) exitWith { diag_log text format ["[POTATO] Not executing on server, exiting %1",QFUNC(transferGroupsToHC)]; };

private _allHCs = entities "HeadlessClient_F";
if (_allHCs isEqualTo []) exitWith { diag_log text format ["[POTATO] No headless clients found, exiting %1", QFUNC(transferGroupsToHC)]; };

private _hcIDs = [];
{ _hcIDs pushBack (owner _x); nil } count _allHCs;

private _timeBetweenTransfers = if (isNil QGVAR(timeBetweenTransfers)) then { 0.5 } else { GVAR(timeBetweenTransfers) };
TRACE_1("Time between transfers", _timeBetweenTransfers);

//loop all groups
{
    if (!(isPlayer (leader _x)) && !((units _x) isEqualTo []) && !((groupOwner _x) in _hcIDs) && (_force || _x getVariable [QGVAR(addGroupToHC), false])) then {
        private _status = _x setGroupOwner ([] call FUNC(getSpawnMachineId));
        TRACE_2("Group moved with status",_x,_status);

        sleep _timeBetweenTransfers;
    };
    nil
} count allGroups;
