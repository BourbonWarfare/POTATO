// PabstMirror
// To Use:
//     call compile preprocessFileLineNumbers "\z\potato\addons\noRadar\dumpVehicles.sqf";


_key = diag_frameno;

diag_log text format ["START: %1", _key];

_baseCfg = configFile >> "CfgVehicles";
_radarUnits = [];
for "_i" from 0 to (count _baseCfg)-1 do {
    _entryCfg = _baseCfg select _i;

    if(isClass _entryCfg) then {
        _className = configName _entryCfg;
        _parent = inheritsFrom _entryCfg;

        if (!(_className isKindOf "CAManBase")) then {
            _radar = getNumber (_entryCfg >> "radarType");
            _scope = getNumber (_entryCfg >> "scope");
            _dName = getText (_entryCfg >> "displayName");
            if ((_scope == 2) && (_radar in [2,4])) then {
                _radarUnits pushBack _className;
                diag_log text format ["#~!~#DumpedVehicle:#~!~#%1_R8#~!~#%2#~!~#%3[R8]#~!~#%1#~!~#", _className, _radar, _dName, _className];
            };
        };
    };
};

_radarAddons = [];
{
    private _className = _x;
    {
        if ((_x != "") && {!(_x in _radarAddons)}) then {
            diag_log text format ["#~!~#DumpedPatch:#~!~#%1#~!~#", _x];
            _radarAddons pushBack _x;
        };
    } forEach (unitAddons _className);
} forEach _radarUnits;

diag_log text format ["DONE: %1", _key];
hint "done";
