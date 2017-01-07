/*
 * Author: AACO
 * Function used to
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_spectate_fnc_;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_object", objNull, [objNull]]];

if (isNull _object) exitWith { [1,1,1] };

private _objectType = typeOf _object;
private _cachedValue = GVAR(boundingBoxCache) getVariable _objectType;

if (isNil "_cachedValue") then {
    (boundingBoxReal _object) params ["_p1", "_p2"];
    _cachedValue = [
        abs ((_p2 select 0) - (_p1 select 0)), // max width
        abs ((_p2 select 1) - (_p1 select 1)), // max length
        abs ((_p2 select 2) - (_p1 select 2)) // max height
    ];

    GVAR(boundingBoxCache) setVariable [_objectType, _cachedValue];
};

_cachedValue
