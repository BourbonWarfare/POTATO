/*
 * Author: AACO
 * Function used to
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_spectate_fnc_;
 *
 * Public: No
 */

#include "script_component.hpp"
#define DEFAULT_TEXTURE "\A3\ui_f\data\map\vehicleicons\iconMan_ca.paa"
TRACE_1("Params",_this);

params [["_object", objNull, [objNull]]];

if (isNull _object) exitWith { DEFAULT_TEXTURE };

private _objectType = typeOf _object;
private _cachedValue = GVAR(vehicleIconCache) getVariable _objectType;

if (isNil "_cachedValue") then {
    private _vehicleValue = getText (configfile >> "CfgVehicles" >> _objectType >> "icon");
    private _vehicleIconValue = getText (configfile >> "CfgVehicleIcons" >> _vehicleValue);

    if (_vehicleIconValue == "") then {
        if (_vehicleValue != "" && {((toLower _vehicleValue) find ".paa") > -1}) then {
            _cachedValue = _vehicleValue;
        } else {
            _cachedValue = DEFAULT_TEXTURE;
        };
    } else {
        _cachedValue = _vehicleIconValue;
    };

    GVAR(vehicleIconCache) setVariable [_objectType, _cachedValue];
};

_cachedValue
