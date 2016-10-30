/*
 * Author: AACO
 * Gets container information from an array of classnames
 *
 * Arguments:
 * 0: Array of containers to select <ARRAY>
 * 1: The array containing the container specific loadout array information <ARRAY>
 * 2: The array containing all the containers and their available space <ARRAY>
 * 3: Does the container class needed to be looked up in CfgWeapons (optional, default: true) <BOOL>
 *
 * Return Value:
 * NONE
 *
 * Example:
 * [_configUniform, _uniformArray, _containersArray] call potato_assignGear_getContainerInfo;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params ["_unitClassname"];

private _cleanedClassname = GVAR(classnameCache) getVariable _unitClassname;
if (isNil "_cleanedClassname") then { // cache classname lookups
    _cleanedClassname = _unitClassname;
    {
        private _prefixLength = count _x;
        if ((toLower (_unitClassname select [0, _prefixLength])) == _x) exitWith {
            _cleanedClassname = _unitClassname select [_prefixLength];
        };
        nil
    } count GVAR(prefixes);  // count used here for speed, make sure nil is above this line

    GVAR(classnameCache) setVariable [_unitClassname, _cleanedClassname];
};

_cleanedClassname
