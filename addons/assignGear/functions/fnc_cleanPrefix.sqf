/*
 * Author: AACO
 * Gets container information from an array of classnames (cached)
 *
 * Arguments:
 * 0: Unit classname <STRING>
 *
 * Return Value:
 * Cleaned classname <STRING>
 *
 * Example:
 * ["potato_w_rifleman"] call potato_assignGear_fnc_cleanPrefix;
 *
 * Public: No
 */

#include "script_component.hpp"

params [["_unitClassname", "", [""]]];
TRACE_1("cleanPrefix",_unitClassname);

if (_unitClassname == "") exitWith {ERROR("_unitClassname is empty string"); _unitClassname };

private _cleanedClassname = GVAR(classnameCache) getOrDefaultCall [_unitClassname, {
    private _cleanedClassname = _unitClassname;
    {
        private _prefixLength = count _x;
        if ((_unitClassname select [0, _prefixLength]) == _x) exitWith {
            _cleanedClassname = _unitClassname select [_prefixLength]; // Select everything after the prefix
        };
        nil
    } count GVAR(prefixes);  // count used here for speed, make sure nil is above this line

    _cleanedClassname;
}, true];

_cleanedClassname
