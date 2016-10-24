/*
 * Author: AACO
 * Function used to convert a number or string to a side object
 * Note: using values used in CfgVehicles laid out here: https://community.bistudio.com/wiki/CfgVehicles_Config_Reference#side
 *
 * Arguments:
 * 0: The number or string to convert <NUMBER/STRING>
 *
 * Return Value:
 * The matched side, or sideUnknown if a match wasn't found: <SIDE>
 *
 * Examples:
 * [1] call potato_core_fnc_toSide; // returns west
 * [99] call potato_core_fnc_toSide; // returns sideUnknown
 * ["east"] call potato_core_fnc_toSide; // returns east
 *
 * Public: Yes
 */

#include "script_component.hpp"

TRACE_1("params",_this);
params [["_toConvert", 0 [0,""]]];

if (_toConvert isEqualType 0) then {
    if (_toConvert == -1) exitWith { sideEmpty };
    if (_toConvert == 0) exitWith { east };
    if (_toConvert == 1) exitWith { west };
    if (_toConvert == 2) exitWith { independent };
    if (_toConvert == 3) exitWith { civilian };
    if (_toConvert == 4) exitWith { sideUnknown }; // best match to 'neutral'
    if (_toConvert == 5) exitWith { sideEnemy };
    if (_toConvert == 6) exitWith { sideFriendly };
    if (_toConvert == 7) exitWith { sideLogic };
};

if (_toConvert isEqualType "") then {
    _toConvert = toLower _toConvert;

    if (_toConvert == "no_side") exitWith { sideEmpty };
    if (_toConvert == "east" || _toConvert == "opfor") exitWith { east };
    if (_toConvert == "west" || _toConvert == "blufor") exitWith { west };
    if (_toConvert == "independent" || _toConvert == "resistance" || _toConvert == "guerilla") exitWith { independent };
    if (_toConvert == "civilian") exitWith { civilian };
    if (_toConvert == "neutral" || _toConvert == "unknown") exitWith { sideUnknown };  // best match to 'neutral'
    if (_toConvert == "enemy") exitWith { sideEnemy };
    if (_toConvert == "friendly") exitWith { sideFriendly };
    if (_toConvert == "logic") exitWith { sideLogic };
};

sideUnknown
