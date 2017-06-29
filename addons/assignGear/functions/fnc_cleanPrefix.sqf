/*
 * Author: AACO
 * Gets container information from an array of classnames
 *
 * Arguments:
 * 0: Unit classname <STRING>
 *
 * Return Value:
 * Cleaned classname <STRING>
 *
 * Example:
 * ["B_Soldier_F"] call potato_assignGear_fnc_cleanPrefix;
 *
 * Public: No
 */

#include "script_component.hpp"

params ["_unitClassname"];
TRACE_1("cleanPrefix",_unitClassname);

private _cleanedClassname = GVAR(classnameCache) getVariable _unitClassname;
if (isNil "_cleanedClassname") then { // cache classname lookups
    _cleanedClassname = _unitClassname;
    {
        private _prefixLength = count _x;
        if ((_unitClassname select [0, _prefixLength]) == _x) exitWith {
            _cleanedClassname = _unitClassname select [_prefixLength]; // Select everything after the prefix
        };
        nil
    } count GVAR(prefixes);  // count used here for speed, make sure nil is above this line

    if (_unitClassname == "") exitWith {ERROR("_unitClassname is empty string");};
    GVAR(classnameCache) setVariable [_unitClassname, _cleanedClassname];
};

_cleanedClassname
