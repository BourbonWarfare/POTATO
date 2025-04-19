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
#define POTATO_MARKER_ERROR_MARKSLCT 10
#define POTATO_MARKER_ERROR_CACHE    20
#define POTATO_MARKER_ERROR_UNITSLCT 30
/*
 * Author: Lambda.Tiger
 * Handle opening and closing of the marker dialog
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Examples:
 * [false] call potato_adminMenu_uihook_handleMarkerDialogUI;
 *
 * Public: No
 */
params [
    ["_display", displayNull, [displayNull]],
    ["_exitCode", -1, [0, configNull]]
];
 TRACE_2("params",_display,_exitCode);

if (_exitCode isEqualType configNull) then {_exitCode = -1};
switch (_exitCode) do {
    case -1: { // opening
        private _markerControl = UI_TAB_MARKERS_MARKERS;
        private _selectedMarkerIndex = lbCurSel _markerControl;
        TRACE_2("Editing marker:",GVAR(editMarker),_selectedMarkerIndex);
        if (GVAR(editMarker)) then { // we need an active marker
            if (_selectedMarkerIndex < 0) exitWith {_display closeDisplay POTATO_MARKER_ERROR_MARKSLCT};
            // Find hashkey and make sure it exists
            private _hashKey = _markerControl lbData _selectedMarkerIndex;
            private _markerArray = EGVAR(markers,markerHash) getOrDefault [_hashKey, []];
            if (_markerArray isEqualTo []) exitWith {_display closeDisplay POTATO_MARKER_ERROR_CACHE};
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
            (_display displayCtrl POTATO_MARKER_OK_IDC) ctrlSetText "Update";
        } else {
            // find the unit and make sure it's valid
            private _selectedUnit = missionNamespace getVariable [
                UI_TAB_MARKERS_PLAYERS lbData (lbCurSel UI_TAB_MARKERS_PLAYERS),
                objNull
            ];
            if (isNull _selectedUnit) then {_display closeDisplay POTATO_MARKER_ERROR_UNITSLCT};
            (_display displayCtrl POTATO_MARKER_UNIT_IDC) ctrlShow true;
            (_display displayCtrl POTATO_MARKER_OK_IDC) ctrlSetText "Create";
        };
    };
    case 1: { // ok
        // Gather dialog parameters
        private _text = ctrlText (_display displayCtrl POTATO_MARKER_TEXT_IDC);
        private _size = switch(lbCurSel (_display displayCtrl POTATO_MARKER_SIZE_IDC)) do {
            case 0: {16};
            case 2: {32};
            default {24};
        };
        private _iconIdx = lbCurSel (_display displayCtrl POTATO_MARKER_ICON_IDC);
        private _colorIdx = lbCurSel (_display displayCtrl POTATO_MARKER_COLOR_IDC);

        TRACE_5("Closing Dialog:",GVAR(editMarker),_text,_size,_colorIdx,_iconIdx);
        if (GVAR(editMarker)) then { // Editing existing marker
            private _markerControl = UI_TAB_MARKERS_MARKERS;
            private _selectedMarkerIndex = lbCurSel _markerControl;
            private _hashKey = _markerControl lbData _selectedMarkerIndex;
            [_hashKey, _text, _size, _colorIdx, _iconIdx] remoteExecCall [QEFUNC(markers,updateMarker)];
            ["potato_adminMsg",
                [format ["Edited marker %1 (%2)", _text, _hashKey], profileName]
            ] call CBA_fnc_GlobalEvent;
        } else { //  Creating new marker
            private _selectedUnit = missionNamespace getVariable [
                UI_TAB_MARKERS_PLAYERS lbData (lbCurSel UI_TAB_MARKERS_PLAYERS),
                objNull
            ];
            private _hashKey = if (cbChecked (_display displayCtrl POTATO_MARKER_UNIT_IDC)) then {
                str side _selectedUnit + groupId group _selectedUnit
            } else {
                str side _selectedUnit + str _selectedUnit
            };
            private _markerArray = [
                _hashKey,
                getPosATL _selectedUnit, _selectedUnit, side _selectedUnit,
                _text, _colorIdx, _iconIdx, _size
            ];
            EGVAR(markers,markerCache) setVariable [POTATO_MARKER_JIP_PREFIX + _hashKey, _markerArray, true];
            _markerArray remoteExecCall [QEFUNC(markers,addMarker)];
            ["potato_adminMsg",
                [format ["Created new marker %1 (%2)", _text, _hashKey], profileName]
            ] call CBA_fnc_GlobalEvent;
        };
        call FUNC(reloadMarkersTab);
    };
    case POTATO_MARKER_ERROR_MARKSLCT: { // Invalid marker - not marker selected
        ["potato_adminMsg",
            ["Could not find a selected marker", "Marker Dialog", profileName]
        ] call CBA_fnc_localEvent;

    };
    case POTATO_MARKER_ERROR_CACHE: { // Invalid marker - no hash
        ["potato_adminMsg",
            ["Could not find selected marker in cache", "Marker Dialog", profileName]
        ] call CBA_fnc_localEvent;

    };
    case POTATO_MARKER_ERROR_UNITSLCT: { // Invalid Unit
        ["potato_adminMsg",
            ["No valid unit selected to add marker to", "Marker Dialog", profileName]
        ] call CBA_fnc_localEvent;

    };
    default {};
};
