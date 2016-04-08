#include "script_component.hpp"
TRACE_1("params",_this);

params [["_unit", objNull, [objNull]],
        ["_direction", 0, [0]],
        ["_distance", 15, [0]],
        ["_height", 0, [0]]];

private _position = getPos _unit;
_position set [2, (_position select 2) + _height];

private _positionASL = eyePos _unit;
private _relativePosition = [_position, _distance, _direction] call BIS_fnc_relPos;
private _intersects = lineIntersectsObjs [_positionASL, ATLTOASL _relativePosition];

if (({_x isKindOf "house"} count _intersects) > 0) then { true } else { false };
