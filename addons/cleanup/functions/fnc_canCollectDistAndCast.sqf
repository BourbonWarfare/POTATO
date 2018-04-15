/*
 * Author: AACO
 * Function used check if an object can be cleanup based on distance from players
 * and if the players could see the object
 *
 * Arguments:
 * 0: Object to check <OBJECT>
 *
 * Examples:
 * [player] call potato_cleanup_fnc_canCollectDistAndCast;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_object"];

private _canCollect = true;
(getPosWorld _object) params ["_x", "_y", "_z"];
(boundingBoxReal _object) params ["_p1", "_p2"];
private _deadPos = [_x, _y, _z + ((abs (_p2#2 - _p1#2)) / 2)];

{
    private _distance = _x vectorDistanceSqr _deadPos;
    TRACE_6("",_object,_deadPos,_distance,GVAR(minDistanceSqr),GVAR(maxDistanceSqr),[ARR_2(_object,"VIEW")] checkVisibility [ARR_2(_x,_deadPos)]);
    if (_distance < GVAR(minDistanceSqr)) exitWith {
        _canCollect = false;
    };

    if (_distance < GVAR(maxDistanceSqr) && {([_object, "VIEW"] checkVisibility [_x, _deadPos]) > 0}) exitWith {
        _canCollect = false;
    };
} forEach ([[], FUNC(getPlayerEyePoses), missionNamespace, QGVAR(cache), 2.5] call ACEFUNC(common,cachedCall));

_canCollect
