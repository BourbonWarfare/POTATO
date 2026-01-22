#include "..\script_component.hpp"
/**************************************************************//*
* This function handles updates to the mission delay slide bar.
* It also updates the number next to the slider.
*
* Arguments:
* _display - The display to initialize
*
* [_display] call lmd_fnc_ui_initRoundTypes
*//**************************************************************/
params [["_display", displayNull, [displayNull]]];

if (isNull _display) exitWith {};

private _control = _display displayCtrl IDC_ARTILLERY_ROUNDTYPE;

lbClear _control;
{
    private _configBase = configFile >> "CfgMagazines" >> _x;
    private _displayName = getText (_configBase >> "displayName");

    private _caliber = getNumber (configFile >> "CfgAmmo" >> (getText (_configBase >> "ammo")) >> "ace_rearm_caliber");
    if (_x in ["CUP_30Rnd_105mmHE_M119_M", "CUP_30Rnd_105mmWP_M119_M"]) then {
        _caliber = 105;
    };
    if (_x in ["CUP_30Rnd_122mmHE_D30_M", "CUP_30Rnd_122mmWP_D30_M"]) then {
        _caliber = 122;
    };
    private _caliberStr = str _caliber;
    if (_caliber <= 0) then {
        private _magazineArr = _x splitString "_";
        private _possibleCalibers = (_magazineArr select {"mm" in toLowerANSI _x}) apply {parseNumber _x};
        private _findIdx = _possibleCalibers findIf {_x > 0};
        _caliber = if (_findIdx >= 0) then {
            _caliberStr = str (_possibleCalibers#_findIdx);
            _possibleCalibers#_findIdx
        } else {
            _caliberStr = "???";
            110
        };
    };
    private _idx = _control lbAdd format ["%1 | %2", _caliberStr + "mm", _displayName];
    _control lbSetValue [_idx, _caliber];
    _control lbSetData [_idx, _x];
} forEach GVAR(artilleryAmmoTypes);
lbSortByValue _control;
