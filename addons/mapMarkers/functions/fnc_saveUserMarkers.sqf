#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Saves the currently placed user markers under a given save name.
 *
 *
 * Arguments:
 * _saveName - The name of the save entry to be looked up later,
                unique per terrain (default "DEFAULT_SAVE_NAME") <STRING>
 *
 * Examples:
 * ["Fuck Yeah Markers"] call potato_mapMarkers_fnc_saveUserMarkers
 *
 * Public: No
 */
params [["_saveName", "DEFAULT_SAVE_NAME", [""]]];
private _markers = [false] call FUNC(collectMarkers); // JSON markers use a lot less space
_markers = values _markers;
private _savedMarkers = profileNamespace getVariable [QGVAR(savedMarkers), createHashMap];
private _terrainHash = _savedMarkers getOrDefault [worldName, createHashMap, true];
_terrainHash set [_saveName, str _markers];
profileNamespace setVariable [QGVAR(savedMarkers), _savedMarkers];
