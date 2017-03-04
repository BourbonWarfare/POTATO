/*
 * Author: AACO
 * Function used to get the group icon for provided group (cached)
 *
 * Arguments:
 * 0: Group to get icon of <GROUP>
 *
 * Return Value:
 * Icon of group <STRING>
 *
 * Examples:
 * [group player] call potato_spectate_fnc_getGroupIcon;
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
