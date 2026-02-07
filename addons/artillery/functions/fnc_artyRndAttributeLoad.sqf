#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function initializes the magazine addition interface. It starts by
 * gathering every vehicle compatible with AI artillery, then finds their
 * "primary" weapon (usually the artillery weapon). The function then adds
 * a key event handler and fills the listbox with a list of all artillery.
 * If a magazine is in the saved list of artillery magazines it is highlighted
 * and a "*" mark is added in the third column.
 *
 * Arguments:
 * _ctrlGroup - The attribute control group, CONTROL
 *
 * Example:
 * Called by attribute BIS EH
 *
 * Based on ACE 3 Object Arsenal Context by mharis001: https://github.com/acemod/ACE3/blob/master/addons/
 * Public: No
 */
params ["_ctrlGroup"];
missionNamespace setVariable [QGVAR(artyRoundUIFocused), true];

private _magazines = vehicles select {
	1 == getNumber ((configOf _x) >> "artilleryScanner")
};
_magazines = _magazines apply {
	private _cfg = (configOf _x) >> "Turrets";
	private _turret = 0;
	while {getNumber ((_cfg select _turret) >> "primaryGunner") == 0} do {_turret = _turret + 1;};
	compatibleMagazines ((_x weaponsTurret [_turret])#0)
};

_magazines = flatten _magazines;
_magazines = _magazines arrayIntersect _magazines;
private _cfg = configFile >> "CfgMagazines";
_magazines = _magazines apply {
	[getText (_cfg >> _x >> "displayName"), _x, ""]
};
(ctrlParent _ctrlGroup) displayAddEventHandler ["KeyDown", {call FUNC(artyRndAttributeKevEvent)}];
private _ctrl = _ctrlGroup controlsGroupCtrl ARTILLERY_EDITOR_ROUND_LISTBOX;
{
//IGNORE_PRIVATE_WARNING["_value"];
    private _idx = _value find (_x#1);
    if (_idx >= 0) then {
        _x set [2, "*"];
        _value deleteAt _idx;
    };
    _ctrl lnbAddRow _x;

    if (_x#2 == "") then {
        _ctrl lnbSetColor [[_forEachIndex, 0], [1, 1, 1, 0.6]];
        _ctrl lnbSetColor [[_forEachIndex, 1], [1, 1, 1, 0.6]];
    };
} forEach _magazines;
_ctrl lnbSetCurSelRow 0;
