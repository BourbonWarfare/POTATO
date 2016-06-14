/*
 * Author: AACO`
 * logic called when a fix nearest group module is placed
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_logic"];
if (isNull _logic) exitWith {};

private _nearestAiGroup = grpNull;
private _nearestAiGroupDistance = -1;
{
    private _noPlayers = true;
    {
        if (isPlayer _x) exitWith { _noPlayers = false; };
    } forEach (units _x);

    if (_noPlayers) then {
        private _distance = _x distance _logic;

        if (_distance < _nearestAiGroupDistance || {isNull _nearestAiGroup}) then {
            _nearestAiGroup = _x;
            _nearestAiGroupDistance = _distance;
        };
    };
} forEach allGroups;

if (isNull _nearestAiGroup) then {
    ["No group could be found to fix", owner _logic] call FUNC(sendCuratorHint);
} else {
    [_nearestAiGroup] remoteExecCall [QFUNC(fixGroup), groupOwner _nearestAiGroup];
};

deleteVehicle _logic;
