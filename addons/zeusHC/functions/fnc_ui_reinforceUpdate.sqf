#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This is run when IDCs are updated in the CSW team dialogue
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
//TRACE_1("Updating Convoy UI",_this);
params ["_args", ["_idcUpdate", -1]];
_args params ["_ctrl", ["_newValue", 0]];

private _display = ctrlParent _ctrl;

switch (_idcUpdate) do {
    case IDC_CONVOY_SIDE: {
        private _newSide = [west,east,resistance]#_newValue;
        _display setVariable [QGVAR(side), _newSide];
        if (isNil QGVAR(vehicleList)) then {GVAR(vehicleList) = [];};
        private _ctrl = _display displayCtrl IDC_CONVOY_VICLIST;
        lnbClear _ctrl;
        private _cfgVehicles = configFile >> "CfgVehicles";
        private _itr = 0;
        {
            _x params ["_type", "_side"];
            if (_type isKindOf "AIR" || _side != _newSide) then {continue};
            private _cfg = _cfgVehicles >> _type;
            _ctrl lbAdd getText (_cfg >> "displayName");
            _ctrl lbSetToolTip [_itr, _type];
            _ctrl lbSetData [_itr, _type];
            _itr = _itr + 1;
        } forEach GVAR(vehicleList);
        _ctrl = _display displayCtrl IDC_CONVOY_SPAWNLIST;
        lnbClear _ctrl;
        _ctrl lnbAddRow ["Vehicle", "Dismounts"];
    };
    case IDC_CONVOY_DISMOUNTCNT: {
        private _textCtrl = _display displayCtrl IDC_CONVOY_DISMOUNTCNTTXT;
        private _leadingZero = ["", "0"] select (_newValue < 10);
        _textCtrl ctrlSetText format ["Max Dismounts: %2%1", _newValue, _leadingZero];
    };
    case IDC_CONVOY_ADDVICDSMNT;
    case IDC_CONVOY_ADDVIC: {
        private _spawnCtrl = _display displayCtrl IDC_CONVOY_SPAWNLIST;
        if ((lnbSize _spawnCtrl) #0 > 6) exitWith {
            [ace_player, "Maximum of 6 (six) vehicles, 4 (four) recommended at most"] call BIS_fnc_showCuratorFeedbackMessage;
        };
        private _vicCtrl = _display displayCtrl IDC_CONVOY_VICLIST;
        if (lbSize _vicCtrl < 1) exitWith {
            [ace_player, "No vehicles to add."] call BIS_fnc_showCuratorFeedbackMessage;
        };
        private _vicSel = lbCurSel _vicCtrl;
        private _dismounts = _idcUpdate == IDC_CONVOY_ADDVICDSMNT;
        private _spawnRow = _spawnCtrl lnbAddRow [_vicCtrl lbText _vicSel, ["", "Y"] select _dismounts];
        _spawnCtrl lnbSetData [[_spawnRow, 0], _vicCtrl lbData _vicSel];
        _spawnCtrl lnbSetTooltip [[_spawnRow, 0], _vicCtrl lbData _vicSel];
    };
    case IDC_CONVOY_REMOVEVIC: {
        private _spawnCtrl = _display displayCtrl IDC_CONVOY_SPAWNLIST;
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
