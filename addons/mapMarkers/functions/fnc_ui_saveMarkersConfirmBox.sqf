#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles a closing confirm window and completes relevant tasks
 * if the user confirms their current action. Finally it updates the list of
 * saved markers on the main display.
 *
 * Arguments:
 * 0: The confirm box display that is closing <DISPLAY>
 * 1: Exit code given by exit button (1 for yes, 0 for no) <NUMBER>
 *
 * Examples:
 * Should be called by display close
 *
 * Public: No
 */
params ["_display", "_exitCode"];

if (_exitCode != 1) exitWith {};
private _type = _display getVariable ["type", ""];
private _name = _display getVariable ["name", ""];

switch (_type) do {
    case IDC_RECALL_MARKERS_BUTTON_CLEAR: {
        private _markerString = format ["_USER_DEFINED #%1", clientOwner];
        private _len = count _markerString;
        private _marks = allMapMarkers select {_x select [0,_len]  == _markerString || _x select [0,20] == "_USER_DEFINED #-1234"};
        {
            deleteMarker _x;
        } forEach _marks;
    };
    case IDC_RECALL_MARKERS_BUTTON_LOAD: {
        [_name] call FUNC(loadUserMarkers);
    };
    case IDC_RECALL_MARKERS_BUTTON_SAVE: {
        [_name] call FUNC(saveUserMarkers);
    };
    case IDC_RECALL_MARKERS_BUTTON_DELETE: {
        if (_name == "") exitWith {};
        private _savedMarkers = profileNamespace getVariable [QGVAR(savedMarkers), createHashMap];
        private _terrainHash = _savedMarkers getOrDefault [worldName, createHashMap, true];
        _terrainHash deleteAt _name;
        profileNamespace setVariable [QGVAR(savedMarkers), _savedMarkers];
    };
};
[findDisplay IDD_RECALL_MARKERS_MAIN] call FUNC(ui_saveMarkersUpdateList);
