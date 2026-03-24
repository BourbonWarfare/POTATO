#include "..\..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function updates the menu to the current set operationtype
*
* Arguments:
* - _display - The menu display variable
*
* Example
* _display call bw_fnc_updateMenuOptions;
*//***************************************************************************/
#define DESELECTED_ZONE_ALPHA 0.4
params ["_display"];

if (GVAR(mainMenuMapClickEH) >= 0) then {
    removeMissionEventHandler ["MapSingleClick", GVAR(mainMenuMapClickEH)];
    GVAR(mainMenuMapClickEH) = -1;
};

// Common elements first
private _control = _display displayCtrl IDC_MISSION_OPERATIONTYPE;
_control lbSetCurSel GET_MENU_OPTION(operationType);
_control = _display displayCtrl IDC_MISSION_ENEMYTYPE;
_control lbSetCurSel GET_MENU_OPTION(enemyType);
_control = _display displayCtrl IDC_MISSION_DROPDOWN;
_control lbSetCurSel GET_MENU_OPTION(density);
_control = _display displayCtrl IDC_MISSION_AISKILLMIN;
_control sliderSetPosition GET_MENU_OPTION(AIskillMin);
_control = _display displayCtrl IDC_MISSION_AISKILLMAX;
_control sliderSetPosition GET_MENU_OPTION(AIskillMax);
_control = _display displayCtrl IDC_MISSION_OPTION0;
_control sliderSetPosition GET_MENU_OPTION(option0);
_control = _display displayCtrl IDC_MISSION_OPTION0_TEXT;
_control ctrlSetText format ["Min Units Per Building: %1", round (8 * GET_MENU_OPTION(option0))];
_control = _display displayCtrl IDC_MISSION_OPTION1;
_control sliderSetPosition GET_MENU_OPTION(option1);
_control = _display displayCtrl IDC_MISSION_OPTION1_TEXT;
_control ctrlSetText format ["Max Units: %1", round (BW_AI_MAX_SPAWN * GET_MENU_OPTION(option1))];
_control = _display displayCtrl IDC_MISSION_OPTION2;
_control sliderSetPosition GET_MENU_OPTION(option2);
_control = _display displayCtrl IDC_MISSION_OPTION3;
_control sliderSetPosition GET_MENU_OPTION(option3);
_control = _display displayCtrl IDC_MISSION_OPTION4;
_control sliderSetPosition GET_MENU_OPTION(option4);
_control = _display displayCtrl IDC_MISSION_OPTION5;
_control sliderSetPosition GET_MENU_OPTION(option5);
_control = _display displayCtrl IDC_MISSION_OPTION6;
_control sliderSetPosition GET_MENU_OPTION(option6);

_control = _display displayCtrl IDC_MISSION_MAP;
private _markerAlpha = [0, DESELECTED_ZONE_ALPHA] select (BW_TRAINING_OPERATION_ZONE == GET_MENU_OPTION(operationType));
private _maxZoneMarker = 0;
for "_i" from 0 to BW_ZONE_MAX_CHECK do {
    private _mark = BW_ZONE_BASE_STRING + (str _i);
    if (getMarkerPos _mark isEqualTo [0, 0, 0]) exitWith {_maxZoneMarker = _i};
    _mark setMarkerAlphaLocal _markerAlpha;
};

private _maxMoutMarker = 0;
_markerAlpha = [0, DESELECTED_ZONE_ALPHA] select (BW_TRAINING_OPERATION_MOUT == GET_MENU_OPTION(operationType));
for "_i" from 0 to BW_MOUT_MAX_CHECK do {
    private _mark = BW_MOUT_BASE_STRING + (str _i);
    if (getMarkerPos _mark isEqualTo [0, 0, 0]) exitWith {_maxZoneMarker = _i};
    _mark setMarkerAlphaLocal _markerAlpha;
};

switch (GET_MENU_OPTION(operationType)) do {
    case BW_TRAINING_OPERATION_MOUT: {
        GVAR(missionSelectedZone) = BW_MOUT_BASE_STRING + str (floor random _maxMoutMarker);
        if (GVAR(mainMenuMapClickEH) < 0) then {
            GVAR(mainMenuMapClickEH) = addMissionEventHandler ["MapSingleClick", {
                params ["", "_pos"];
                for "_i" from 0 to BW_MOUT_MAX_CHECK do {
                    private _mark = BW_MOUT_BASE_STRING + (str _i);
                    if (getMarkerPos _mark isEqualTo [0, 0, 0]) exitWith {};
                    if (_pos inArea _mark) exitWith {
                        GVAR(missionSelectedZone) setMarkerAlphaLocal DESELECTED_ZONE_ALPHA;
                        GVAR(missionSelectedZone) = _mark;
                        _mark setMarkerAlphaLocal 0.8;
                    };
                };
            }];
        };
        _control ctrlMapAnimAdd [0, 0.1, getMarkerPos GVAR(missionSelectedZone)];
        ctrlMapAnimCommit _control;
        BW_MISSION_SET_OPTIONS_DEFAULT(_display,_control);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_DROPDOWN);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_OPTION3);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_OPTION4);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_OPTION5);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_OPTION6);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_DROPDOWN_TEXT);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_OPTION3_TEXT);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_OPTION4_TEXT);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_OPTION5_TEXT);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_OPTION6_TEXT);
        BW_MISSION_SET_MOUT_TEXT(_display,_control);
        _control = _display displayCtrl IDC_MISSION_OPTION2;
        SET_MENU_OPTION(option2,0);
        _control sliderSetPosition GET_MENU_OPTION(option2);
    };
    case BW_TRAINING_OPERATION_ZONE: {
        GVAR(missionSelectedZone) = "";
        if (GVAR(mainMenuMapClickEH) < 0) then {
            GVAR(mainMenuMapClickEH) = addMissionEventHandler ["MapSingleClick", {
                params ["", "_pos"];
                for "_i" from 0 to BW_ZONE_MAX_CHECK do {
                    private _mark = BW_ZONE_BASE_STRING + (str _i);
                    if (getMarkerPos _mark isEqualTo [0, 0, 0]) exitWith {};
                    if (_pos inArea _mark) exitWith {
                        GVAR(missionSelectedZone) setMarkerAlphaLocal DESELECTED_ZONE_ALPHA;
                        GVAR(missionSelectedZone) = _mark;
                        _mark setMarkerAlphaLocal 0.8;
                    };
                };
            }];
        };
        GVAR(missionSelectedZone) = BW_ZONE_BASE_STRING + str (floor random _maxZoneMarker);
        _control ctrlMapAnimAdd [0, 0.4, getMarkerPos GVAR(missionSelectedZone)];
        GVAR(missionSelectedZone) setMarkerAlphaLocal 0.8;
        ctrlMapAnimCommit _control;
        BW_MISSION_SET_OPTIONS_DEFAULT(_display,_control);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_DROPDOWN);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION3);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION4);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION5);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION6);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_DROPDOWN_TEXT);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION3_TEXT);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION4_TEXT);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION5_TEXT);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION6_TEXT);
        BW_MISSION_SET_DROPDOWN_DENSITY(_display,_control);
        BW_MISSION_SET_DROPDOWN_DENSITY_TEXT(_display,_control);
        BW_MISSION_SET_ZONE_TEXT(_display,_control);
    };
    case BW_TRAINING_OPERATION_ZONE_DRAW: {
        GVAR(missionSelectedZone) = "";
        if (GVAR(mainMenuMapClickEH) < 0) then {
            GVAR(mainMenuMapClickEH) = addMissionEventHandler ["MapSingleClick", {
                params ["", "_pos"];
                if (GVAR(nextMapClickTime) > diag_tickTime) exitWith {};
                private _markerPos = getMarkerPos GVAR(missionFirstPositionMarker);
                if (_pos distance2D _markerPos < 10) exitWith {};
                GVAR(nextMapClickTime) = diag_tickTime + BW_MAP_CLICK_HOLD_OFF;
                if (markerBrush GVAR(missionFirstPositionMarker) == "Border") then {
                    deleteMarkerLocal GVAR(missionFirstPositionMarker);
                    GVAR(missionFirstPositionMarker) = "";
                    _markerPos = [0, 0, 0];
                };
                if (_markerPos isEqualTo [0, 0, 0]) then {
                    private _newMarker = createMarkerLocal [name player + str floor random 100, _pos];
                    _newMarker setMarkerTypeLocal "mil_dot_noShadow";
                    _newMarker setMarkerColorLocal "ColorBlue";
                    GVAR(missionFirstPositionMarker) = _newMarker;
                } else {
                    private _marker = GVAR(missionFirstPositionMarker);
                    switch (GET_MENU_OPTION(density)) do {
                        case BW_TRAINING_DENSITY_UNIFORM: { // circle: corner - corner
                            _pos = (_pos vectorAdd _markerPos) apply {_x / 2};
                            _marker setMarkerPosLocal _pos;
                            _pos = (_pos vectorDiff _markerPos) apply {abs _x};
                            _marker setMarkerShapeLocal "ELLIPSE";
                        };
                        case BW_TRAINING_DENSITY_SINGLE: { // circle: center - corner
                            _pos = (_pos vectorDiff _markerPos) apply {abs _x};
                            _marker setMarkerShapeLocal "ELLIPSE";
                        };
                        case BW_TRAINING_DENSITY_MULTI: { // rectangle: corner-corner
                            _pos = (_pos vectorAdd _markerPos) apply {_x / 2};
                            _marker setMarkerPosLocal _pos;
                            _pos = (_pos vectorDiff _markerPos) apply {abs _x};
                            _marker setMarkerShapeLocal "RECTANGLE";
                        };
                        case BW_TRAINING_DENSITY_SINGLEMARKED: { // rectangle: center-corner
                            _pos = (_pos vectorDiff _markerPos) apply {abs _x};
                            _marker setMarkerShapeLocal "RECTANGLE";
                        };
                        default { // circle: center-radius
                            _pos = (_pos vectorDiff _markerPos) apply {abs _x};
                            _pos set [2, 0];
                            private _radius = vectorMagnitude _pos;
                            _pos = [_radius, _radius];
                            _marker setMarkerShapeLocal "ELLIPSE";
                        };
                    };
                    _marker setMarkerSizeLocal [_pos#0, _pos#1];
                    _marker setMarkerBrushLocal "Border";
                    private _size = markerSize _marker;
                    if (4 * (_size#0 + _size#1) > 4800 ||
                        sqrt (_size#0 * _size#1) > 600 ) then {
                        ["Notif", ["Custom Zone", "Drawn Zone is too big"]] call BIS_fnc_showNotification;
                        deleteMarkerLocal _marker;
                    } else {
                        GVAR(missionSelectedZone) = _marker;
                    };
                };
            }];
        };
        _display displayCtrl IDC_MISSION_MAP ctrlMapCursor ["Arrow", "Track"];
        _control ctrlMapAnimAdd [0, 0.4, getMarkerPos (BW_ZONE_BASE_STRING + str (floor random _maxZoneMarker))];
        ctrlMapAnimCommit _control;
        BW_MISSION_SET_OPTIONS_DEFAULT(_display,_control);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_DROPDOWN);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION3);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION4);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION5);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION6);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_DROPDOWN_TEXT);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION3_TEXT);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION4_TEXT);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION5_TEXT);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION6_TEXT);
        BW_MISSION_SET_DROPDOWN_DRAWTYPE(_display,_control);
        BW_MISSION_SET_DROPDOWN_DRAWTYPE_TEXT(_display,_control);
        BW_MISSION_SET_ZONE_TEXT(_display,_control);
    };
    case BW_TRAINING_OPERATION_DEFEND: {
        GVAR(missionSelectedZone) = "";
        if (GVAR(mainMenuMapClickEH) < 0) then {
            GVAR(mainMenuMapClickEH) = addMissionEventHandler ["MapSingleClick", {
                params ["", "_pos"];
                if (GVAR(nextMapClickTime) > diag_tickTime) exitWith {};
                private _markerPos = getMarkerPos GVAR(missionFirstPositionMarker);
                GVAR(nextMapClickTime) = diag_tickTime + BW_MAP_CLICK_HOLD_OFF;
                if (markerBrush GVAR(missionFirstPositionMarker) == "Border") then {
                    deleteMarkerLocal GVAR(missionFirstPositionMarker);
                    GVAR(missionFirstPositionMarker) = "";
                    _markerPos = [0, 0, 0];
                };
                if (_markerPos isEqualTo [0, 0, 0]) then {
                    private _newMarker = createMarkerLocal [name player + str floor random 100, _pos];
                    _newMarker setMarkerShapeLocal "ELLIPSE";
                    private _rad = GET_MENU_OPTION(option0);
                    _newMarker setMarkerSizeLocal [_rad, _rad]; // find place
                    _newMarker setMarkerBrushLocal "Border";
                    _newMarker setMarkerColorLocal "ColorBlue";
                    GVAR(missionFirstPositionMarker) = _newMarker;
                    GVAR(missionSelectedZone) = _newMarker;
                } else {
                    _pos set [2, 0];
                    GVAR(missionFirstPositionMarker) setMarkerPosLocal _pos;
                };
            }];
        };
        _display displayCtrl IDC_MISSION_MAP ctrlMapCursor ["Arrow", "Track"];
        ctrlMapAnimCommit _control;
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_DROPDOWN);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION3);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION4);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_OPTION5);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_OPTION6);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_DROPDOWN_TEXT);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION3_TEXT);
        BW_DEFADE_CONTROL(_display,_control,IDC_MISSION_OPTION4_TEXT);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_OPTION5_TEXT);
        BW_FADE_CONTROL(_display,_control,IDC_MISSION_OPTION6_TEXT);
        BW_MISSION_SET_OPTIONS_DEFEND(_display,_control);
    };
    case BW_TRAINING_OPERATION_MECH: { // To be completed

    };
    default {};
};
