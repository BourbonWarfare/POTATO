#include "script_component.hpp"
/*
 * Arguments:
 * 0: Type <NUMBER> - 0: Bar, 1: Text
 * 1: Stat data array <ARRAY>
 *
 * Public: No
 */

params ["_type", "_statData"];
_statData params ["", "_cfg"];

private _recoil = getText (_cfg >> "recoil");

if (_type == 0) then {
    private _recoil = getArray (configFile >> "CfgRecoils" >> _recoil >> "muzzleOuter");
    _recoil params [["_x", 0], ["_y", 0]];
    if (_x isEqualType "") then { _x = parseNumber _x; };
    if (_y isEqualType "") then { _y = parseNumber _y; };
    linearConversion [0, 2, vectorMagnitude [_x, _y], 0, 1, true]
} else {
    _recoil
};
