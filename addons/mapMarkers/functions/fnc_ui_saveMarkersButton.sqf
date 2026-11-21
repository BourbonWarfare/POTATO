#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function handles all button presses that have effects beyond closing the
 * base save marker UI. Usually results in opening another dialog to handle further
 * input clarification, except when there as an error with the input given.
 *
 * Arguments:
 * 0: The control of the button that is being clicked <CONTROL>
 *
 * Examples:
 * Should be called by onButtonClick UI EH
 *
 * Public: No
 */
params ["_buttonCtrl"];
private _display = ctrlParent _buttonCtrl;
switch (ctrlIDC _buttonCtrl) do {
    case IDC_RECALL_MARKERS_BUTTON_CLEAR: {
        private _dialog = createDialog [QGVAR(saveMarkersConfirmBox), true];
        _dialog setVariable ["type", IDC_RECALL_MARKERS_BUTTON_CLEAR];
        (_dialog displayCtrl IDC_RECALL_MARKERS_CONFIRM_TEXT) ctrlSetText CONFIRM_TEXT_CLEAR;
    };
    case IDC_RECALL_MARKERS_BUTTON_LOAD: {
        private _lbCtrl = _display displayCtrl IDC_RECALL_MARKERS_LISTBOX;
        private _name = _lbCtrl lbData (lbCurSel _lbCtrl);
        if (_name == "") exitWith {};
        private _dialog = createDialog [QGVAR(saveMarkersConfirmBox), true];
        _dialog setVariable ["type", IDC_RECALL_MARKERS_BUTTON_LOAD];
        _dialog setVariable ["name", _name];
        (_dialog displayCtrl IDC_RECALL_MARKERS_CONFIRM_TEXT) ctrlSetText format [CONFIRM_TEXT_LOAD, _name];
    };
    case IDC_RECALL_MARKERS_BUTTON_SAVE: {
        private _lbCtrl = _display displayCtrl IDC_RECALL_MARKERS_LISTBOX;
        private _name = _lbCtrl lbData (lbCurSel _lbCtrl);
        if (_name == "") exitWith {
            createDialog [QGVAR(saveMarkersAsBox), true];
        };
        private _dialog = createDialog [QGVAR(saveMarkersConfirmBox), true];
        _dialog setVariable ["type", IDC_RECALL_MARKERS_BUTTON_SAVE];
        _dialog setVariable ["name", _name];
        (_dialog displayCtrl IDC_RECALL_MARKERS_CONFIRM_TEXT) ctrlSetText CONFIRM_TEXT_SAVE_OVER;
    };
    case IDC_RECALL_MARKERS_BUTTON_SAVEAS: {
        private _lbCtrl = _display displayCtrl IDC_RECALL_MARKERS_LISTBOX;
        private _name = _lbCtrl lbData (lbCurSel _lbCtrl);
        private _dialog = createDialog [QGVAR(saveMarkersAsBox), true];
        (_dialog displayCtrl IDC_RECALL_MARKERS_SAVEAS_TEXT) ctrlSetText _name;
    };
    case IDC_RECALL_MARKERS_BUTTON_DELETE: {
        private _lbCtrl = _display displayCtrl IDC_RECALL_MARKERS_LISTBOX;
        private _name = _lbCtrl lbData (lbCurSel _lbCtrl);
        if (_name == "") exitWith {};
        private _dialog = createDialog [QGVAR(saveMarkersConfirmBox), true];
        _dialog setVariable ["type", IDC_RECALL_MARKERS_BUTTON_DELETE];
        _dialog setVariable ["name", _name];
        (_dialog displayCtrl IDC_RECALL_MARKERS_CONFIRM_TEXT) ctrlSetText CONFIRM_TEXT_DELETE;
    };
};
