/*
 * Author: Bismarck
 * Function used to return the highest available leader to JIP unit's location to
 *
 * Arguments:
 * 0: Target side to use for leader search <SIDE>
 *
 * Examples:
 * [west] call potato_jipat_fnc_getCurLeaderSide;
 * [east] call potato_jipat_fnc_getCurLeaderSide;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_side", west, [west]]];

private ["_unitCheckStrings","_leader"];

_strSide = switch (_side) do {
    case west: {"BLU_"};
    case east: {"OPF_"};
    case resistance: {"IND_"};
};

_masterC2 = [
    "COY_CO",
    "COY_XO",
    "1PLT_CO",
    "2PLT_CO",
    "1PLT_SGT",
    "2PLT_SGT",
    "ASL_SL",
    "BSL_SL",
    "CSL_SL",
    "DSL_SL",
    "ESL_SL",
    "FSL_SL",
    "WSL_SL"
];

_unitCheckStrings = [];
_leader = objNull;
{
    _unitCheckStrings pushBack ("UNIT_" + _strSide + _x);
} forEach _masterC2;


scopeName "base";
{
    if ((!isNil _x) && {alive (call compile _x)}) then {
        _leader = call compile _x;
        breakTo "base";
    };
} forEach _unitCheckStrings;

_leader
