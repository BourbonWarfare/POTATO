#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This fucntion enable all AI options on every enemy and set them to
* move towards the players.
*
* Arguments:
* None
*
* Return:
* none
*
* Example:
* [] call bw_fnc_autoEndSessionAI;
*//***************************************************************************/
// Useful for reinforcemetns
GVAR(endOfMission) = true;

// Free everyone from their prisons and set them to attack
private _playerCentroid = [] call FUNC(findPlayerCentroid);
{
    if (local _x && !isPlayer _x) then {
        _x enableAI "ALL";
        if (_x == leader _x) then {
            private _grp = group _x;
            for "_i" from (count waypoints _grp - 1) to 0 step -1 do {
                deleteWaypoint [_grp, _i];
            };
            private _wp = _grp addWaypoint [getPosATL _x, 0];
            _grp setCurrentWaypoint _wp;
            _wp setWaypointBehaviour "AWARE";
            _wp = _grp addWaypoint [_playerCentroid, 100];
            _wp setWaypointCompletionRadius 500;
            _wp setWaypointSpeed "FULL";
            _wp = _grp addWaypoint [_playerCentroid, 100];
            _wp setWaypointCompletionRadius 500;
            _wp setWaypointType "SAD";
        };
    };
} forEach allUnits;
