#include "..\script_component.hpp"
/*
 * Author: Lambda.Tigers
 * Function used to reinitialize the marker hash
 *
 *
 * Examples:
 * [] call potato_markers_fnc_reinitMarkerHash;
 *
 * Public: Yes
 */

// reset markers and
GVAR(markerHash) = createHashMap;
GVAR(drawHash) = createHashMap;

// method to reinit marker hash
