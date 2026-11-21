#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * The function updates a list of saved markers on a per-terrain basis
 *
 * Arguments:
 * 0: The display that the marker list is on <DISPLAY>
 *
 * Examples:
 * [findDisplay 20261119] call potato_mapMarkers_fnc_ui_saveMarkersUpdateList;
 *
 * Public: No
 */
params ["_display"]; // Get the control for the list
private _ctrl = _display displayCtrl IDC_RECALL_MARKERS_LISTBOX;
private _savedMarkers = profileNamespace getVariable [QGVAR(savedMarkers), createHashMap];
private _terrainHash = _savedMarkers getOrDefault [worldName, createHashMap, true];
lbClear _ctrl;
private _saves = (keys _terrainHash);
_saves sort true;
{
    private _idx = _ctrl lbAdd _x;
    _ctrl lbSetData [_idx, _x];
} forEach _saves;
_ctrl lbSetCurSel 0;
