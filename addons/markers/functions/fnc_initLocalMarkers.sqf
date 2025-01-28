#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function will initialize both markers for a unit, and for their
 * group if they are the leader of said group. This should be called
 * upon initialization, and only called once.
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
