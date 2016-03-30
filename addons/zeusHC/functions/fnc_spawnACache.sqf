#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_configEntries"];

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
} count _configEntries;
