#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function requests the last recorded locations of markers in the marker
 * cache from the server (which should have the most accurate positions).
 *
 * Example:
 * [] call potato_markers_fnc_resquestMarkerPosSync;
 *
 * Public: No
 */
 if (isServer) exitWith {};
[clientOwner] remoteExecCall [QFUNC(markerPosSync), 2];
