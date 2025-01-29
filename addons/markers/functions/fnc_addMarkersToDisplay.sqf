/*
 * Author: AACO
 * Function used to add the draw marker EH to the map/gps controls
 *
 * Arguments:
 * 0: Display the map control lives on <DISPLAY>
 * 0: Map or GPS IDC <NUMBER>
 *
 * Examples:
 * [(findDisplay 12), 52] call potato_markers_fnc_addMarkersToDisplay; // add markers to main map
 * [(findDisplay 133), 101] call potato_markers_fnc_addMarkersToDisplay; // add markers to GPS
 *
 * Public: No
 */

#include "..\script_component.hpp"
TRACE_1("params",_this);

params ["_display","_idc"];
TRACE_2("IDs",_display,_idc);

if !(GVAR(settingsInitialized)) exitWith { GVAR(settingsDelayedFunctions) pushBack [FUNC(addMarkersToDisplay),_this]; };

private _installedVarName = format ["%1_%2_%3",QGVAR(displays),_idc,"EHInstalled"];
if (GVAR(skipInstallingEH) || {_display getVariable [_installedVarName, false]}) exitWith {};
_display setVariable [_installedVarName, true];

(_display displayCtrl _idc) ctrlAddEventHandler ["Draw", {_this call FUNC(drawMarkers)}];
