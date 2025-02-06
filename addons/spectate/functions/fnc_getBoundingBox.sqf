/*
 * Author: AACO
 * Function used to find the max width/length/height (cached)
 *
 * Arguments:
 * 0: Object to get max specs <OBJECT>
 *
 * Return Value:
 * Max width/length/height of provided object <ARRAY>
 *
 * Examples:
 * [my_car] call potato_spectate_fnc_getBoundingBox;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_object", objNull, [objNull]]];

if (isNull _object) exitWith { [1,1,1] };

private _objectType = typeOf _object;
private _cachedValue = GVAR(boundingBoxCache) getOrDefaultCall [_objectType, {
    (boundingBoxReal _object) params ["_p1", "_p2"];
    [
        abs ((_p2 select 0) - (_p1 select 0)), // max width
        abs ((_p2 select 1) - (_p1 select 1)), // max length
        abs ((_p2 select 2) - (_p1 select 2)) // max height
    ]
}, true];

_cachedValue
