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
#define MUZZLE_NUMBER 101
#define MUZZLE_INDEX 1
#define OPTIC_NUMBER 201
#define OPTIC_INDEX 3
#define POINTER_NUMBER 301
#define POINTER_INDEX 2
#define BIPOD_NUMBER 302
#define BIPOD_INDEX 6

TRACE_1("params",_this);
params ["_weaponArray", "_config", "_classname", ["_doOpticCheck", true, [true]]];

private _typeNumber = getNumber (_config >> "itemInfo" >> "type");

// muzzle
if (_typeNumber == MUZZLE_NUMBER) exitWith {
    _weaponArray set [MUZZLE_INDEX, _classname];
};

// optic
if (_typeNumber == OPTIC_NUMBER) exitWith {
    if (!GVAR(allowMagnifiedOptics) && {_doOpticCheck}) then {
        private _minZoom = 999; //FOV, so smaller is more zoomed in
        {
            if (isNumber (_x >> "opticsZoomMin")) then {_minZoom = _minZoom min (getNumber (_x >> "opticsZoomMin"));};
            if (isText (_x >> "opticsZoomMin")) then {_minZoom = _minZoom min (call compile getText (_x >> "opticsZoomMin"));};
            nil
        } count configProperties [_config >> "ItemInfo" >> "OpticsModes"]; // count used here for speed, make sure nil is above this line

        if (_minZoom < 0.25) then {
            diag_log text format ["[POTATO-assignGear] allowMagnifiedOptics is false, not adding %1 (opticsZoomMin %2)", _classname, _minZoom];
            _classname = "";
        };
    };

    _weaponArray set [OPTIC_INDEX, _classname];
};

// pointer
if (_typeNumber == POINTER_NUMBER) exitWith {
    _weaponArray set [POINTER_INDEX, _classname];
};

// bipod
if (_typeNumber == BIPOD_NUMBER) exitWith {
    _weaponArray set [BIPOD_INDEX, _classname];
};

diag_log text format ["[POTATO-assignGear] - Attachment [%1] has unknown type", _classname];
