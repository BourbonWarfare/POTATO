/*
 * Author: AACO
 * Function used to create a cache of spawnable units
 *
 * Example:
 * [] call potato_zeusHC_fnc_buildACache;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

GVAR(buildFactionCache) = [[], []];
private _configEntries = "(configName _x) isKindOf 'Man' && getNumber (_x >> 'scope') > 1" configClasses (configFile >> "CfgVehicles");

{
    private _faction = getText (_x >> 'faction');
    if (_faction in GVAR(groupFactionWhiteList)) then {
        private _newItem = [configName _x, getText (_x >> "displayName"), getText (_x >> "icon")];
        private _cacheIndex = (GVAR(buildFactionCache) select 0) find _faction;
        if (_cacheIndex < 0) then {
            _cacheIndex = (GVAR(buildFactionCache) select 0) pushBack _faction;
            (GVAR(buildFactionCache) select 1) pushBack [];
        };
        ((GVAR(buildFactionCache) select 1) select _cacheIndex) pushBack _newItem;
    };
    nil
} count _configEntries;
