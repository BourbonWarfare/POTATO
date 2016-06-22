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

private _sideArray = switch (playerSide) do {
    case west: { GVAR(viewBluForMarkers) };
    case east: { GVAR(viewOpForMarkers) };
    case resistance: { GVAR(viewIndyMarkers) };
    case civilian: { GVAR(viewCivMarkers) };
    default { [] };
};

{
    if (!(isNull _x) && {side _x in _sideArry}) then {
        [_x] call FUNC(addMarkerInfoToHash);

        {
            [_x] call FUNC(addMarkerInfoToHash);
        } forEach (units _x);
    };
} forEach allGroups;
