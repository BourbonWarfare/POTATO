/*
 * Author: AACO
 * Helper function to check if a unit is facing a wall, results not guaranteed
 *
 * Arguments:
 * 0: Unit to check <OBJECT>
 * 1: Direction to check (optional default 0) <NUMBER>
 * 2: Distance to check (optional default 0) <NUMBER>
 *
 * Return Value:
 * True if the object is facing a wall, false otherwise <BOOL>
 *
 * Examples:
 * [_unit, 0, 0] call potato_zeusHC_fnc_garrisonIsFacingWall
 * [_unit, _degree] call potato_zeusHC_fnc_garrisonIsFacingWall
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [["_unit", objNull, [objNull]],
        ["_direction", 0, [0]],
        ["_distance", 15, [0]]];

private _positionASL = eyePos _unit;
private _relativePosition = _unit getRelPos [_distance, _direction];
private _intersects = lineIntersectsObjs [_positionASL, ATLTOASL _relativePosition];

(({_x isKindOf "house"} count _intersects) > 0)
