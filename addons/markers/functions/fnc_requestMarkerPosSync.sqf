#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function requests the last recorded locations of markers in the marker
 * cache from the server (which should have the most accurate positions).
 * Not recommended to be run often as it may require sending a large amount of
 * data over the network
 *
 * Example:
 * [] call potato_markers_fnc_resquestMarkerPosSync;
 *
 * Public: No
 */
 if (isServer) exitWith {};
[clientOwner] remoteExecCall [QFUNC(markerPosSync), 2];
