#include "..\script_component.hpp"
/***************************************************************************//*
* Author: Lambda.Tiger
*
* Description:
* This function handles the dialog opening and closing, as well as the initial
* call from the waypointinng function. If an array of waypoints is passed, it
* is used to open the dialogue. The function on open intializes the dialogue
* and adds all draw EHs to it. On close if _exitCode is 0, executes the
* reinforce wave funciton.
*
* Arguments:
* _isClosing - A bool of whether the display is opening or closing, and also
*              an array of waypoints for the module to use.
* _eventArgs - Arguments passed by the onOpen or onClosed EH.
*
* Return:
* The number of patroling units spawned
*
* Example:
* called by map function
*//***************************************************************************/
params ["_isClosing", "_eventArgs"];

if !(_isClosing isEqualType false) exitWith {
    private _display = createDialog [QGVAR(convoySpawn)];
    _display setVariable [QGVAR(wps), _isClosing];
};

if (_isClosing) then {
    _eventArgs params ["_display", ["_exitCode", 0]];
    private _map = _display displayCtrl IDC_CONVOY_MAP;
    _map ctrlRemoveEventHandler ["Draw", _display getVariable [QGVAR(mapEH), -1]];
    if (_exitCode != 1) exitWith {};
    private _wps = _display getVariable [QGVAR(wps), []];
    {_x set [2, 0]} forEach _wps;
    _wps set [2, [_wps#2, lbCurSel (_display displayCtrl IDC_CONVOY_FINALWPACT)]];
    private _ctrl = _display displayCtrl IDC_CONVOY_SPAWNLIST;
    private _vics = [];
    private _maxUnits = sliderPosition (_display displayCtrl IDC_CONVOY_DISMOUNTCNT);
    for "_i" from 1 to ((lnbSize _ctrl)#0 - 1) do {
        _vics pushBack [_ctrl lnbData [_i, 0],(_ctrl lnbText [_i, 1]) == "y"];
    };
    _ctrl = _display displayCtrl IDC_CONVOY_FINALWPACT;
    [
        _wps,
        _vics,
        sliderPosition (_display displayCtrl IDC_CONVOY_DISMOUNTCNT),
        cbChecked (_display displayCtrl IDC_CONVOY_FINDROAD),
        _ctrl lbValue (lbCurSel _ctrl),
        cbChecked (_display displayCtrl IDC_CONVOY_LAMBS),
        _display getVariable [QGVAR(side), east]
    ] call FUNC(convoySpawn);
} else { // initialize the display to sync menu values
    _eventArgs params ["_display"];
    // Setup map drawing
    private _mapCtrl = _display displayCtrl IDC_CONVOY_MAP;
    [{
        params ["_display"];
        private _mapCtrl = _display displayCtrl IDC_CONVOY_MAP;
        private _waypoints = _display getVariable [QGVAR(wps), [[0,0,0],[0,0,0],[0,0,0]]];
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
                [CONVOY_WP_TEXT]#_forEachIndex, 2
            ];
            if (_lastWP isNotEqualTo [0,0,0]) then {
                _map drawLine [_lastWP, _x, [1,0,0,1], 3]
            };
            _lastWP = _x;
        } forEach _wps;
    }];
    _display setVariable [QGVAR(mapEH), _mapEH];
    [_display, IDC_CONVOY_MAP] call EFUNC(markers,addMarkersToDisplay);
    // Fill vehicle list
    if (isNil QGVAR(vehicleList)) then {GVAR(vehicleList) = [];};
    private _ctrl = _display displayCtrl IDC_CONVOY_VICLIST;
    private _cfgVehicles = configFile >> "CfgVehicles";
    private _itr = 0;
    {
        _x params ["_type", "_side"];
        // defaults to opfor
        if (_type isKindOf "air" || _side != east) then {continue};
        private _cfg = _cfgVehicles >> _type;
        _ctrl lbAdd getText (_cfg >> "displayName");
        _ctrl lbSetToolTip [_itr, _type];
        _ctrl lbSetData [_itr, _type];
        _itr = _itr + 1;
    } forEach GVAR(vehicleList);
    _ctrl lbSetCurSel 0;
    // Spawn list init
    _ctrl = _display displayCtrl IDC_CONVOY_SPAWNLIST;
    _ctrl lnbAddRow ["Vehicle", "Dismounts"];

};
