#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This is run when controls are updated in the zeus cargo drop dialog
 *
 * Arguments:
 * 0: The UI changed control
 * 1: The UI elements IDC
 *
 * Examples:
 * Should be called by module callback
 *
 * Public: No
 */
TRACE_1("Updating cargo paraddrop UI",_this);
params ["_args", ["_idcUpdate", -1]];
_args params ["_ctrl", ["_newValue", 0]];

private _display = ctrlParent _ctrl;

switch (_idcUpdate) do {
    case IDC_AIRDROP_SIDE: {
        private _newSide = [west,east,resistance,civilian]#_newValue;
        _display setVariable [QGVAR(side), _newSide];
        if (isNil QEGVAR(zeusHC,vehicleList)) then {EGVAR(zeusHC,vehicleList) = [];};
        private _ctrl = _display displayCtrl IDC_AIRDROP_DROPOPTIONS;
        lnbClear _ctrl;
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
            private _cfg = _cfgVehicles >> _type;
            if (_type isKindOf "air" || _side != _newSide) then {continue};
            private _idx = _ctrl lbAdd getText (_cfg >> "displayName");
            _ctrl lbSetTooltip [_idx, _type];
            _ctrl lbSetData [_idx, _type];
        } forEach EGVAR(zeusHC,vehicleList);
        // Default vehicles
        {
            _x params ["_type", "_side"];
            private _cfg = _cfgVehicles >> _type;
            private _idx = _ctrl lbAdd getText (_cfg >> "displayName");
            _ctrl lbSetTooltip [_idx, _type];
            _ctrl lbSetData [_idx, _type];
        } forEach AIRDROP_DEF_VEHICLES;
        _ctrl = _display displayCtrl IDC_AIRDROP_SPAWNVIC;
        lnbClear _ctrl;
        _ctrl lnbAddRow ["Type", "Chute Failure"];
        // Add drop vehicles
        _ctrl = _display displayCtrl IDC_AIRDROP_PLANETYPE;
        {
            _x params ["_type", "_side"];
            private _cfg = _cfgVehicles >> _type;
            if (!(_type isKindOf "air") || _side != _newSide ||
                {!(isClass (_cfg >> "VehicleTransport" >> "Carrier"))}) then {continue};
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
    };
    case IDC_AIRDROP_ADDVIC_PARAFAIL;
    case IDC_AIRDROP_ADDVIC: {
        private _spawnCtrl = _display displayCtrl IDC_AIRDROP_SPAWNVIC;
        private _vicCtrl = _display displayCtrl IDC_AIRDROP_DROPOPTIONS;
        if (lbSize _vicCtrl < 1) exitWith {
            [ace_player, "Nothing selected to add."] call BIS_fnc_showCuratorFeedbackMessage;
        };
        private _vicSel = lbCurSel _vicCtrl;
        private _dismounts = _idcUpdate == IDC_AIRDROP_ADDVIC_PARAFAIL;
        private _spawnRow = _spawnCtrl lnbAddRow [_vicCtrl lbText _vicSel, ["", "Y"] select _dismounts];
        _spawnCtrl lnbSetData [[_spawnRow, 0], _vicCtrl lbData _vicSel];
        _spawnCtrl lnbSetTooltip [[_spawnRow, 0], _vicCtrl lbData _vicSel];
    };
    case IDC_AIRDROP_REMOVEVIC: {
        private _spawnCtrl = _display displayCtrl IDC_AIRDROP_SPAWNVIC;
        if ((lnbSize _spawnCtrl)#0 <= 1) exitWith {
            [ace_player, "No valid entries to remove"] call BIS_fnc_showCuratorFeedbackMessage;
        };
        private _currRow = lnbCurSelRow _spawnCtrl;
        if (_currRow == 0) exitWith {
            [ace_player, "Invalid entry selected"] call BIS_fnc_showCuratorFeedbackMessage;
        };
        if (_currRow < 0) then {
           _currRow = (lnbSize _spawnCtrl)#0 - 1;
           _spawnCtrl lnbSetCurSelRow _currRow;
        };
        _spawnCtrl lnbDeleteRow _currRow;
    };
    default {};
};
