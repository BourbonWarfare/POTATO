#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Handles setting up and closing the UI for the zeus cargo airdrop dialog.
 *
 * Arguments:
 * parameters passed by UI
 *
 * Return Value:
 * Nothing
 *
 * Public: No
 */
params ["_isClosing", "_eventArgs"];

if !(_isClosing isEqualType false) exitWith {
    private _display = createDialog [QGVAR(zeusParadropCargo)];
    _display setVariable [QGVAR(wps), _isClosing];
};

if (_isClosing) then {
    _eventArgs params ["_display", ["_exitCode", 0]];
    private _map = _display displayCtrl IDC_AIRDROP_MAP;
    _map ctrlRemoveEventHandler ["Draw", _display getVariable [QGVAR(mapEH), -1]];
    if (_exitCode != 1) exitWith {};
    private _wps = _display getVariable [QGVAR(wps), []];
    {_x set [2, 0]} forEach _wps;
    private _ctrl = _display displayCtrl IDC_AIRDROP_SPAWNVIC;
    private _drops = [];
    for "_i" from 1 to ((lnbSize _ctrl)#0 - 1) do {
        _drops pushBack [_ctrl lnbData [_i, 0],(_ctrl lnbText [_i, 1]) == "y"];
    };
    _ctrl = _display displayCtrl IDC_AIRDROP_PLANETYPE;
    [[
        _ctrl lbData ((lbSelection _ctrl)#0),
        _wps,
        _display getVariable [QGVAR(side), AIRDROP_DEFAULT_SIDE],
        [], // units to drop
        _drops
    ], QFUNC(createParadrop)] call EFUNC(zeusHC,hcPassthrough);
} else { // initialize the display to sync menu values
    _eventArgs params ["_display"];
    // Setup map drawing
    private _mapCtrl = _display displayCtrl IDC_AIRDROP_MAP;
    [{
        params ["_display"];
        private _mapCtrl = _display displayCtrl IDC_AIRDROP_MAP;
        private _waypoints = _display getVariable [QGVAR(wps), [[0,0,0],[0,0,0],[0,0,0],[0,0,0]]];
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
                [AIRDROP_WP_TEXT]#_forEachIndex, 2
            ];
            if (_lastWP isNotEqualTo [0,0,0]) then {
                _map drawLine [_lastWP, _x, [1,0,0,1], 3]
            };
            _lastWP = _x;
        } forEach _wps;
    }];
    _display setVariable [QGVAR(mapEH), _mapEH];
    [_display, IDC_AIRDROP_MAP] call EFUNC(markers,addMarkersToDisplay);
    // Fill vehicle list
    private _ctrl = _display displayCtrl IDC_AIRDROP_DROPOPTIONS;
    private _cfgVehicles = configFile >> "CfgVehicles";
    // Check for supply
    {
        private _type = configName _x;
        private _boxName = getText (_x >> "boxCustomName");
        if (_boxName == "") then {_boxName = getText (_cfgVehicles >> _type >> "displayName")};
        private _idx = _ctrl lbAdd _boxName;
        _ctrl lbSetTooltip [_idx, _type];
        _ctrl lbSetData [_idx, _type];
    } forEach (configProperties [missionConfigFile >> "CfgLoadouts" >> "SupplyBoxes", "isClass _x"]);
    // Add vehicles
    if (isNil QEGVAR(zeusHC,vehicleList)) then {EGVAR(zeusHC,vehicleList) = [];};
    {
        _x params ["_type", "_side"];
        // defaults to west
        private _cfg = _cfgVehicles >> _type;
        if (_type isKindOf "air" || _side != AIRDROP_DEFAULT_SIDE) then {continue};
        private _idx = _ctrl lbAdd getText (_cfg >> "displayName");
        _ctrl lbSetTooltip [_idx, _type];
        _ctrl lbSetData [_idx, _type];
    } forEach EGVAR(zeusHC,vehicleList);
    {
        _x params ["_type", "_side"];
        private _cfg = _cfgVehicles >> _type;
        private _idx = _ctrl lbAdd getText (_cfg >> "displayName");
        _ctrl lbSetTooltip [_idx, _type];
        _ctrl lbSetData [_idx, _type];
    } forEach AIRDROP_DEF_VEHICLES;
    _ctrl lbSetCurSel 0;
    // Spawn list init
    _ctrl = _display displayCtrl IDC_AIRDROP_SPAWNVIC;
    _ctrl lnbAddRow ["Type", "Chute Failure"];
    // Add drop vehicles
    _ctrl = _display displayCtrl IDC_AIRDROP_PLANETYPE;
    {
        _x params ["_type", "_side"];
        // defaults to west
        private _cfg = _cfgVehicles >> _type;
        if (!(_type isKindOf "air") || _side != AIRDROP_DEFAULT_SIDE ||
            {!(isClass (_cfg >> "VehicleTransport" >> "Carrier"))}) then {continue};
        private _idx = _ctrl lbAdd getText (_cfg >> "displayName");
        _ctrl lbSetTooltip [_idx, _type];
        _ctrl lbSetData [_idx, _type];
    } forEach EGVAR(zeusHC,vehicleList);
    _ctrl lbSetCurSel 0;
    {
        _x params ["_type", "_side"];
        private _cfg = _cfgVehicles >> _type;
        private _idx = _ctrl lbAdd getText (_cfg >> "displayName");
        _ctrl lbSetTooltip [_idx, _type];
        _ctrl lbSetData [_idx, _type];
    } forEach AIRDROP_DEF_VEHICLES;

};
