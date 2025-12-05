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
    private _kickback = getArray (configFile >> "CfgRecoils" >> _recoil >> "kickBack");
    private _h = _kickback param [0, 0];
    if (_h isEqualType "") then { _h = parseNumber _h; };
    linearConversion [0, 0.1, _h, 0, 1, true]
} else {
    _recoil
};
