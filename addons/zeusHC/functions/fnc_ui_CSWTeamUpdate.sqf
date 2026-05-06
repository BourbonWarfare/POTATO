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
TRACE_1("Updating UI",_this);
params ["_args", ["_idcUpdate", -1]];
_args params ["_ctrl", "_newValue"];

private _display = ctrlParent _ctrl;

switch (_idcUpdate) do {
    case IDC_CSWTEAM_SIDE: {
        _display setVariable [QGVAR(side), [west,east,resistance]#_newValue];
    };
    /*case IDC_CSWTEAM_MISSIONTYPE: {
        private _ctrlAmmo = _display displayCtrl IDC_CSWTEAM_AMMO_SLIDE;
        private _ctrlAmmoTxt = _display displayCtrl IDC_CSWTEAM_AMMO_TXT;
        if (_newValue mod 2 == 0) then {
            _ctrlAmmo sliderSetRange [50, 600];
            _ctrlAmmo sliderSetPosition 200;
            _ctrlAmmo sliderSetSpeed [50, 5, 5];
            _ctrlAmmoTxt ctrlSetText "Round Count: 200";
        } else {
            _ctrlAmmo sliderSetRange [1, 20];
            _ctrlAmmo sliderSetPosition 3;
            _ctrlAmmo sliderSetSpeed [3, 1, 1];
            _ctrlAmmoTxt ctrlSetText "Round Count: 003";
        };
    };
    case IDC_CSWTEAM_AMMO_SLIDE: {
        private _textCtrl = _display displayCtrl IDC_CSWTEAM_AMMO_TXT;
        private _leadingZero = if (_newValue < 10) then {
            "00"
        } else {
            ["", "0"] select (_newValue < 100)
        };
        _textCtrl ctrlSetText format ["Round Count: %2%1", _newValue, _leadingZero];
    };*/
    default {};
};
