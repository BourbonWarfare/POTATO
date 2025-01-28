#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function will initialize all local markers, should be used on mission
 * start but can be run again later.
 *
 * Example:
 * [] call potato_markers_fnc_initLocalMarkers;
 *
 * Public: No
 */
TRACE_1("initializing local markers",_this);

{
    {
        if (local _x) then {[_x] call FUNC(addMarkerInfoToHash);};
    } forEach units _x;
    if (local leader _x) then {[_x] call FUNC(addMarkerInfoToHash)};
} forEach allGroups;
