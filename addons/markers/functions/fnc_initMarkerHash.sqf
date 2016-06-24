/*
 * Author: AACO
 * Function used to scan all active groups/players and try to add them to the
 * marker hash
 *
 * Examples:
 * [] call potato_markers_fnc_initMarkerHash;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

private _sideArray = [] call FUNC(getSideArray);

TRACE_2("sides",_sideArray,playerSide);

{
    if (!(isNull _x) && {side _x in _sideArray}) then {
        [_x] call FUNC(addMarkerInfoToHash);

        {
            [_x] call FUNC(addMarkerInfoToHash);
        } forEach (units _x);
    };
} forEach allGroups;
