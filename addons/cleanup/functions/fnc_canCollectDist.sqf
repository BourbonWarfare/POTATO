#include "script_component.hpp"

TRACE_1("params",_this);

params ["_object"];

private _canCollect = true;
private _deadEyePos = eyePos _object;
{
    if (_x vectorDistanceSqr _deadEyePos <= GVAR(minDistanceSqr)) exitWith {
        _canCollect = false;
    };
} forEach ([[], FUNC(getPlayerEyePoses), missionNamespace, QGVAR(cache), 2.5] call ACEFUNC(common,cachedCall))

_canCollect
