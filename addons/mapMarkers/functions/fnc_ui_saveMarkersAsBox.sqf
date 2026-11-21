#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles a closing "save as" dialog. It checks to see if the
 * new name is valid, and then if it overlaps with an existing entry opens
 * the confirm dialog on the next frame. If the name does not overlap it saves
 * and updates the main display list of saved marker groups.
 *
 * Arguments:
 * 0: The "Save As" display that is closing <DISPLAY>
 *
 * Examples:
 * Should be called by display close UI EH
 *
 * Public: No
 */
params ["_display"];
private _name = ctrlText (_display displayCtrl IDC_RECALL_MARKERS_SAVEAS_TEXT);
if (_name == "") exitWith {};
private _savedMarkers = profileNamespace getVariable [QGVAR(savedMarkers), createHashMap];
private _terrainHash = _savedMarkers getOrDefault [worldName, createHashMap, true];
if (_name in keys _terrainHash) exitWith {
    [{
        params ["_name"];
        private _dialog = createDialog [QGVAR(saveMarkersConfirmBox), true];
        _dialog setVariable ["type", IDC_RECALL_MARKERS_BUTTON_SAVE];
        _dialog setVariable ["name", _name];
        private _ctrl = _dialog displayCtrl IDC_RECALL_MARKERS_CONFIRM_TEXT;
        _ctrl ctrlSetText CONFIRM_TEXT_SAVE_OVER;
    }, [_name]] call CBA_fnc_execNextFrame;
};
[_name] call FUNC(saveUserMarkers);
[findDisplay IDD_RECALL_MARKERS_MAIN] call FUNC(ui_saveMarkersUpdateList);
