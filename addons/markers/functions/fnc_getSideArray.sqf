/*
 * Author: AACO
 * Helper function used to get an array of sides markers should be displayed for
 *
 * Examples:
 * [] call potato_markers_fnc_getSideArray;
 *
 * Public: No
 */

#include "..\script_component.hpp"
TRACE_1("Params",_this);

switch (side (group player)) do {
    case west: { GVAR(viewBluForMarkers) };
    case east: { GVAR(viewOpForMarkers) };
    case resistance: { GVAR(viewIndyMarkers) };
    case civilian: { GVAR(viewCivMarkers) };
    default { [] };
}
