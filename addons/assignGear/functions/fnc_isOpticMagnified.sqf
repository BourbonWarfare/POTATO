/*
 * Author: AACO
 * Checks if the given optic classname is considered magnified (cached)
 *
 * Arguments:
 * 0: Optic classname to check <STRING>
 *
 * Example:
 * ["optic_Aco"] call potato_assignGear_fnc_isOpticMagnified;
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params [["_opticClassname", "", [""]]];

if (_opticClassname == "") exitWith { ERROR("No optic classname provided"); false };

private _isMagnified = GVAR(magnifiedOpticCache) getVariable _opticClassname;
if (isNil "_isMagnified") then { // cache magnification check
    TRACE_1("Looking up key: ", _opticClassname);
    private _minZoom = 999; //FOV, so smaller is more zoomed in

    {
        if (isNumber (_x >> "opticsZoomMin")) then {
            _minZoom = _minZoom min (getNumber (_x >> "opticsZoomMin"));
        } else {
            if (isText (_x >> "opticsZoomMin")) then { _minZoom = _minZoom min (call compile getText (_x >> "opticsZoomMin")); };
        };
        nil
    } count configProperties [configFile >> "CfgWeapons" >> _opticClassname >> "ItemInfo" >> "OpticsModes"]; // count used here for speed, make sure nil is above this line

    _isMagnified = _minZoom < MAG_OPTIC_ZOOM_THRESHOLD;
    GVAR(magnifiedOpticCache) setVariable [_opticClassname, _isMagnified];
};

_isMagnified
