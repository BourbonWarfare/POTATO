#include "script_component.hpp"

TRACE_1("params",_this);

params ["_object"];

private _canCollect = true;
private _deadPos = getPos _object;
{
    private _distance = _x vectorDistanceSqr _deadPos;
    if (_distance < GVAR(minDistanceSqr)) exitWith {
        _canCollect = false;
    };

    if (_distance < GVAR(maxDistanceSqr) && {([objNull, "VIEW"] checkVisibility [_x, _deadPos]) > 0.25}) exitWith {
        _canCollect = false;
    };
} forEach ([[], FUNC(getPlayerEyePoses), missionNamespace, QGVAR(cache), 2.5] call ACEFUNC(common,cachedCall));

_canCollect
