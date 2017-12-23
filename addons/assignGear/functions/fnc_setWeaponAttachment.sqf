/*
 * Author: PabstMirror, AACO
 * Adds attachements to a weapon array
 *
 * Arguments:
 * 0: Weapon array to add the attachement to <ARRAY>
 * 1: Config path of the attachement <CONFIG>
 * 2: Attachement classname <STRING>
 * 3: Should we check the optic (optional, default: true) <BOOL>
 *
 * Return Value:
 * NONE
 *
 * Example:
 * [_weaponArray, _config, _classname, _doOpticCheck] call potato_assignGear_fnc_setWeaponAttachement;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params ["_weaponArray", "_config", "_classname", ["_doOpticCheck", true, [true]]];

private _typeNumber = getNumber (_config >> "itemInfo" >> "type");

// muzzle
if (_typeNumber == MUZZLE_TYPE) exitWith {
    _weaponArray set [LAW_MUZZLE_INDEX, _classname];
};

// optic
if (_typeNumber == OPTIC_TYPE) exitWith {
    if (!GVAR(allowMagnifiedOptics) && {_doOpticCheck} && {[_classname] call FUNC(isOpticMagnified)}) then {
        diag_log text format ["[POTATO-assignGear] allowMagnifiedOptics is false, not adding %1", _classname];
        _classname = "";
    };

    _weaponArray set [LAW_OPTIC_INDEX, _classname];
};

// pointer
if (_typeNumber == POINTER_TYPE) exitWith {
    _weaponArray set [LAW_POINTER_INDEX, _classname];
};

// bipod
if (_typeNumber == BIPOD_TYPE) exitWith {
    _weaponArray set [LAW_BIPOD_INDEX, _classname];
};

diag_log text format ["[POTATO-assignGear] - Attachment [%1] has unknown type", _classname];
