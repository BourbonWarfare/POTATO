#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function sends a hashmap of marker hashkeys and positions to
 * a client in an effort to sync marker positions.
 *
 * Arugments:
 * 0: The clientID of the client to be updated
 *
 * Example:
 * [9] call potato_markers_fnc_markerPosSync;
 *
 * Public: No
 */
params ["_clientID", -1, [-1]];
if (!isServer || _clientID < 3) exitWith {};

private _newMarkerPosHash = createHashMap;
{
    _newMarkerPosHash set [_x, _y#5];
} forEach GVAR(markerHash);
GVAR(markerPosSync) = _newMarkerPosHash;

_clientID publicVariableClient QGVAR(markerPosSync);
