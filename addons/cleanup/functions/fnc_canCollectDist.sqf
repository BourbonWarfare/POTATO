/*
 * Author: AACO
 * Function used check if an object can be cleanup based on distance from players
 *
 * Arguments:
 * 0: Object to check <OBJECT>
 *
 * Examples:
 * [player] call potato_cleanup_fnc_canCollectDist;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_object"];

private _canCollect = true;
private _deadPos = getPos _object;
{
    if (_x vectorDistanceSqr _deadPos < GVAR(minDistanceSqr)) exitWith {
        _canCollect = false;
    };
} forEach ([[], FUNC(getPlayerEyePoses), missionNamespace, QGVAR(cache), 2.5] call ACEFUNC(common,cachedCall));

_canCollect
