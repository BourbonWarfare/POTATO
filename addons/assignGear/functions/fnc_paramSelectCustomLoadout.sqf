#include "script_component.hpp"
/*
 * Author: Lambda.Tiger
 * Initialized custom loadout config path params. This function is intended
 * to be called by mission params for bwmf missions. Params define the custom
 * loadout to be selected, or -1 for the loadout defined by the side config.
 *
 * If a custom loadout selected, the thousands place is used to pick a side
 * for the loadout to correlate to. Specifically, any of the potato side
 * factions. Thereafter, the loadout index is used to select a loadout from
 * either the mission or normal config. Preference for found loadouts is
 * given in the following order:
 * - The faction for loadouts (CfgLoadouts >> faction) matching the given index
 * - The root loadouts (CfgLoadouts) for loadouts matching the given index
 * - The config file under configFile >> "potato_assignGear_loadouts"
 * If it fails to find one, it will default to the standard loadout path,
 * missionConfigFile >> "CfgLoadouts" >> _faction.
 *
 * Arguments:
 * 0: Custom loadout param value. This should be < 0 for default, in the range
 *    [0 999] for west, [1000 1999] for east, [2000 2999] for indi, and
 *    [3000 3999] for civilian (SCALAR, default -1).
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [25] call potato_assignGear_fnc_paramSelectCustomLoadout;
 *
 * Public: Yes
 */
TRACE_1("",_this);
params [["_loadoutIndex", -1, [123]]];

if (_loadoutIndex < 0) exitWith {
    TRACE_1("Exit with default loadouts",_loadoutIndex);
};

// Choose faciton dependent on _loadoutIndex thousands place
private _faction = switch (floor (_loadoutIndex / 1000)) do {
    case 1: {"potato_e"};
    case 2: {"potato_i"};
    case 3: {"CIV_F"};
    default {"potato_w"};
};
private _loadoutSubIndex = _loadoutIndex mod 1000;
private _baseConfig = missionConfigFile >> "CfgLoadouts";
// Handle default return of 0 without having to make users see behind the curtains
private _condition = "private _item = _x >> 'index'; isNumber _item && getNumber _item == _loadoutSubIndex";
// Filter down through the possible locations for loadout files in the following order:
// "CfgLoadouts" >> faction subconfig => "CfgLoadouts" => configFile >> "potato_aassignGear_loadouts"
private _matchingConfigFiles = _condition configClasses (_baseConfig >> _faction);
_matchingConfigFiles append (_condition configClasses _baseConfig);
_matchingConfigFiles append (_condition configClasses (configFile >> QGVAR(loadouts)));
// Grab the proper config or default
private _configFile = if (_matchingConfigFiles isEqualTo []) then {
    TRACE_3("Could not find loadout",_faction,_loadoutIndex,_loadoutSubIndex);
    missionConfigFile >> "CfgLoadouts" >> _faction
} else {
    _matchingConfigFiles#0
};

GVAR(customLoadoutPaths) set [_faction, _configFile];
