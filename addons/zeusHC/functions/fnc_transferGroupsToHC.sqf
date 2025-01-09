#include "script_component.hpp"
/*
 * Author: AACO
 * Function to transfer all AI to HC in a load balanced fasion.
 * Must be called on the server
 *
 * Arguments:
 * 0: Force all units onto the headless clients? If false, will only move groups with the potato_zeusHC_addGroupToHC flag set <BOOL>
 *
 * Examples:
 * [true] call potato_zeusHC_fnc_transferGroupsToHC; //move them all
 * [] call potato_zeusHC_fnc_transferGroupsToHC; //only move flagged
 *
 * Public: Yes
 */

params [["_force", false]];
TRACE_1("transferGroupsToHC",_force);


waitUntil { time > 0 };

//Check the script is run in multiplayer only
if (!isMultiplayer) exitWith {
    diag_log text format ["[POTATO] Not in multiplayer, exiting %1",QFUNC(transferGroupsToHC)];
    diag_log text format ["[POTATO] Broadcasting aiTransfered var (SKIPPED)"];
    missionNamespace setVariable [QGVAR(aiTransfered), true, true];
};
if (!isServer) exitWith { ERROR("transferGroupsToHC should only be called on server"); };

private _allHCs = entities "HeadlessClient_F";
if (_allHCs isEqualTo []) exitWith {
    diag_log text format ["[POTATO] No headless clients found, exiting %1", QFUNC(transferGroupsToHC)];
    diag_log text format ["[POTATO] Broadcasting aiTransfered var (SKIPPED)"];
    missionNamespace setVariable [QGVAR(aiTransfered), true, true];
};

private _hcIDs = _allHCs apply { owner _x };

private _timeBetweenTransfers = if (isNil QGVAR(timeBetweenTransfers)) then { 0.5 } else { GVAR(timeBetweenTransfers) };
TRACE_1("Time between transfers",_timeBetweenTransfers);

//loop all groups
{
    if (!(isPlayer (leader _x)) && ((units _x) isNotEqualTo []) && !((groupOwner _x) in _hcIDs) && (_force || _x getVariable [QGVAR(addGroupToHC), false])) then {
        private _newOwner = [] call FUNC(getSpawnMachineId);
        private _status = _x setGroupOwner _newOwner;
        INFO_3("Group [%1] moved to [%2] with status [%3]",_x,_newOwner,_status);

        sleep _timeBetweenTransfers;
    };
} forEach allGroups;


diag_log text format ["[POTATO] Broadcasting aiTransfered var (Transfer Done)"];
missionNamespace setVariable [QGVAR(aiTransfered), true, true];

