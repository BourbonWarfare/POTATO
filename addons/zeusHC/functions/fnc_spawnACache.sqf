/*
 * Author: AACO
 * Function used to create a cache of spawnable vehicles
 *
 * Example:
 * [] call potato_zeusHC_fnc_spawnACache;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

GVAR(spawnVicCache) = [[], []];

private _filter = [];
{
    _filter pushBack format ["(configName _x) isKindOf '%1'", _x];
    nil
} count ["Air","Car","Tank","Wheeled_APC","Wheeled_APC_F","Boat_F"];

private _relivantUnits = (format ["(%1) && getNumber (_x >> 'scope') > 1", _filter joinString " || "]) configClasses (configFile >> "CfgVehicles");

if (isNil QGVAR(vicFactionBlackList)) then {
    GVAR(vicFactionBlackList) = [];
};
TRACE_1("black list",GVAR(vicFactionBlackList));

{
    private _faction = getText (_x >> 'faction');
    if !(_faction in GVAR(vicFactionBlackList) || _faction == "") then {
        private _newItem = [configName _x, getText (_x >> "displayName"), getText (_x >> "icon")];
        private _cacheIndex = (GVAR(spawnVicCache) select 0) find _faction;
        if (_cacheIndex < 0) then {
            _cacheIndex = (GVAR(spawnVicCache) select 0) pushBack _faction;
            (GVAR(spawnVicCache) select 1) pushBack [];
        };
        ((GVAR(spawnVicCache) select 1) select _cacheIndex) pushBack _newItem;
    };
    nil
} count _relivantUnits;
