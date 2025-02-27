#include "script_component.hpp"

#ifdef GLUE
  #undef GLUE
#endif
#define GLUE(var1,var2) var1##var2
#ifdef PATHTOF
    #undef PATHTOF
#endif
#define PATHTOF(var) GLUE(\z\potato\addons\markers\,var)
#ifdef QPATHTOF
    #undef QPATHTOF
#endif
#define QPATHTOF(var) QUOTE(PATHTOF(var))
#include "\z\potato\addons\markers\defaultMarkerDefines.hpp"
/*
 * Author: Lambda.Tiger
 * Attach marker to a unit based on currrent selections in the admin menu;
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Examples:
 * [false] call potato_adminMenu_uihook_openMarkersEditUI;
 *
 * Public: No
 */
params [
    ["_display", displayNull, [displayNull]],
    ["_exitCode", -1, [0, configNull]]
];
systemChat format ["func params: %1 %2", _display, _exitCode];
if (_exitCode isEqualType configNull) then {_exitCode = -1};
switch (_exitCode) do {
    case -1: { // opening
        private _markerControl = UI_TAB_MARKERS_MARKERS;
        private _selectedMarkerIndex = lbCurSel _markerControl;
        if (GVAR(editMarker) && _selectedMarkerIndex >= 0) then { // we need an active marker
            private _hashKey = _markerControl lbData _selectedMarkerIndex;
            private _markerArray = EGVAR(markers,markerHash) getOrDefault [_hashKey, []];
            if (_markerArray isEqualTo []) exitWith {10 closeDisplay _display};
            _markerArray params ["", "_text", "_icon", "_color", "_size"];

            // Setup the display for the current marker
            (_display displayCtrl POTATO_MARKER_TEXT_IDC) ctrlSetText _text;
            private _colorIdx = COLOR_INDEX_ARRAY find _color;
            if (_colorIdx >= 0 && _colorIdx < 8) then {
                (_display displayCtrl POTATO_MARKER_COLOR_IDC) lbSetCurSel _colorIdx;
            };
            switch (_size) do {
                case 16: {(_display displayCtrl POTATO_MARKER_SIZE_IDC) lbSetCurSel 0};
                case 32: {(_display displayCtrl POTATO_MARKER_SIZE_IDC) lbSetCurSel 2};
                default {(_display displayCtrl POTATO_MARKER_SIZE_IDC) lbSetCurSel 1};
            };
            private _iconIdx = [UNIT_MARKERS_STRINGS] find _icon;
            if (_iconIdx >= 0 && _iconIdx < 20) then {
                (_display displayCtrl POTATO_MARKER_ICON_IDC) lbSetCurSel _iconIdx;
            };
            (_display displayCtrl POTATO_MARKER_UNIT_IDC) ctrlShow false;
            (_display displayCtrl POTATO_MARKER_OK_IDC) ctrlSetStructuredText text "Update<br/?Marker";
        } else {
            (_display displayCtrl POTATO_MARKER_UNIT_IDC) ctrlShow true;
            (_display displayCtrl POTATO_MARKER_OK_IDC) ctrlSetStructuredText text "Create/nMarker";
        };
    };
    case 1: { // ok
        private _text = ctrlText (_display displayCtrl POTATO_MARKER_TEXT_IDC);
        private _size = switch(lbCurSel (_display displayCtrl POTATO_MARKER_SIZE_IDC)) do {
            case 0: {16};
            case 2: {32};
            default {24};
        };

        private _iconIdx = lbCurSel (_display displayCtrl POTATO_MARKER_TEXT_IDC);
        private _colorIdx = lbCurSel (_display displayCtrl POTATO_MARKER_COLOR_IDC);
        if (GVAR(editMarker)) then {
            private _markerControl = UI_TAB_MARKERS_MARKERS;
            private _selectedMarkerIndex = lbCurSel _markerControl;
            private _hashKey = _markerControl lbData _selectedMarkerIndex;
            [_hashKey, _text, _size, _color, _icon] remoteExecCall EFUNC(markers,updateMarker);
        } else {
            private _selectedUnit = missionNamespace getVariable [
                UI_TAB_MARKERS_PLAYERS lbData (lbCurSel UI_TAB_MARKERS_PLAYERS),
                objNull
            ];
            private _hashKey = if (cbChecked (_display displayCtrl POTATO_MARKER_UNIT_IDC)) then {
                str side _selectedUnit + groupId group _selectedUnit
            } else {
                str side _selectedUnit + str _selectedUnit
            };
            EGVAR(markers,markerCache) setVariable [POTATO_MARKER_JIP_PREFIX + _hashKey, _markerArray, true];
            [
                _hashKey,
                getPosATL _selectedUnit, _selectedUnit, side _selectedUnit,
                _text, _colorIdx, _iconIdx, _size
            ] remoteExecCall [QEFUNC(markers,addMarker)];
        };
    };
    case 10: { // Invalid marker
        private _markerControl = UI_TAB_MARKERS_MARKERS;
        private _selectedMarkerIndex = lbCurSel _markerControl;
        WARNING_2("Failed to edit marker index %1 (%2)",_selectedMarkerIndex,_markerControl lbData _selectedMarkerIndex);
    };
    default {};
};
