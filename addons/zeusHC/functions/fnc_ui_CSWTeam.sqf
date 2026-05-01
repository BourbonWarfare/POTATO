#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function is run by opening the CSW Team dialogue
 *
 * Arguments:
 * 0: Whether the module is opening or closing, in some cases an array of WPs
 * 1: Arguments provided for the event
 *
 *
 * Examples:
 * Should be called ui update events from the csw_team dialogue
 *
 * Public: No
 */
TRACE_1("CSW Team Dialogue",_this);
params ["_isClosing", "_eventArgs"];

if (_isClosing isEqualType []) exitWith {
    private _display = createDialog [QGVAR(csw_team)];
    _display setVariable [QGVAR(wps), _isClosing];
};

if (_isClosing) then {
    _eventArgs params ["_display", ["_exitCode", 0]];
    private _map = _display displayCtrl IDC_CSWTEAM_MAP;
    _map ctrlRemoveEventHandler ["Draw", _display getVariable [QGVAR(mapEH), -1]];
    if (_exitCode != 1) exitWith {};
    [[
        _display getVariable [QGVAR(wps), []],
        _display getVariable [QGVAR(side), west],
        lbCurSel (_display displayCtrl IDC_CSWTEAM_MISSIONTYPE)//,
        //sliderPosition (_display displayCtrl IDC_CSWTEAM_AMMO_SLIDE)
    ], QFUNC(CSWTeam_Spawn)] call FUNC(hcPassthrough);
} else { // initialize the display to sync menu values
    _eventArgs params ["_display"];
    private _mapCtrl = _display displayCtrl IDC_CSWTEAM_MAP;
    [{
        params ["_display"];
        private _mapCtrl = _display displayCtrl IDC_CSWTEAM_MAP;
        private _waypoints = _display getVariable [QGVAR(wps), [[0,0,0]]];
        private _center = _waypoints#0 vectorAdd _waypoints#1 vectorAdd _waypoints#2;
        private _initPos = _center vectorMultiply (1/3);
        _mapCtrl ctrlMapAnimAdd [0, 0.3, _initPos];
        ctrlMapAnimCommit _mapCtrl;
    }, _display] call CBA_fnc_execNextFrame;
    private _mapEH = _mapCtrl ctrlAddEventHandler ["Draw", {
        params ["_map"];
        private _display = ctrlParent _map;
        private _scale = 6.4 * worldSize / 8192 * ctrlMapScale _map;
        private _wps = _display getVariable [QGVAR(wps), []];
        private _lastWP = [0,0,0];
        {
            _map drawIcon [
                "\A3\ui_f\data\map\markers\military\dot_CA.paa",
                [0.8,0,0,1], _x, 25 / _scale, 25 / _scale, 0,
                [CSWTEAM_WP_TEXT]#_forEachIndex, 2
            ];
            if (_lastWP isNotEqualTo [0,0,0]) then {
                _map drawLine [_lastWP, _x, [1,0,0,1], 3]
            };
            _lastWP = _x;
        } forEach _wps;
    }];
    [_display, IDC_CSWTEAM_MAP] call EFUNC(markers,addMarkersToDisplay);
    _display setVariable [QGVAR(mapEH), _mapEH];
};
