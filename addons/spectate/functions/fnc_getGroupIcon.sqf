/*
 * Author: AACO
 * Function used to get the vehicle icon for provided object (cached)
 *
 * Arguments:
 * 0: Object to get icon of <OBJECT/STRING>
 *
 * Return Value:
 * Icon of vehicle <STRING>
 *
 * Examples:
 * [my_car] call potato_spectate_fnc_getBoundingBox;
 *
 * Public: Yes
 */

#include "script_component.hpp"
#define DEFAULT_TEXTURE QPATHTOF(data\infantry.paa)
TRACE_1("Params",_this);

params [["_group", grpNull, [grpNull]]];

if (isNull _group) exitWith { DEFAULT_TEXTURE };

private _cachedValue = _group getVariable QGVAR(markerTexture);

if (isNil "_cachedValue") then {
    private _lookup = if (_group getVariable [QEGVAR(markers,addMarker), false]) then {
        _group getVariable [QEGVAR(markers,markerTexture), ""]
    } else {
        private _leader = leader _group;
        if (_leader getVariable [QEGVAR(markers,addMarker), false]) then {
            _leader getVariable [QEGVAR(markers,markerTexture), ""]
        } else {
            ""
        }
    };

    _cachedValue = GVAR(groupIconCache) getVariable _lookup;
    if (isNil "_cachedValue") then {
        _cachedValue = DEFAULT_TEXTURE;
    };

    _group setVariable [QGVAR(markerTexture), _cachedValue];
};

_cachedValue
