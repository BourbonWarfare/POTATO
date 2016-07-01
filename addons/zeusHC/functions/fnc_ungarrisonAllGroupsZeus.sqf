/*
 * Author: AACO`
 * logic called when an ungarrison all groups module is placed
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_logic"];
if (isNull _logic) exitWith {};

private _ownerToGroups = [[],[]];

{
    private _noPlayers = true;
    {
        if (isPlayer _x) exitWith { _noPlayers = false; };
    } forEach (units _x);

    if (_noPlayers) then {
        private _groupOwner = groupOwner _x;
        private _index = (_ownerToGroups select 0) find _groupOwner;

        if (_index > -1) then {
            ((_ownerToGroups select 1) select _index) pushBack _x;
        } else {
            (_ownerToGroups select 0) pushBack _groupOwner;
            (_ownerToGroups select 1) pushBack [_x];
        };
    };
} forEach allGroups;

{
    private _groups = (_ownerToGroups select 1) select _forEachIndex;
    [_groups] remoteExecCall [QFUNC(ungarrisonGroupBulk), _x];
} forEach (_ownerToGroups select 0);

deleteVehicle _logic;
