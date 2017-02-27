/*
 * Author: AACO
 * desc
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_;
 */

#include "script_component.hpp"
TRACE_1("params",_this);

params [["_logic", objNull, [objNull]]];

if (isNull _logic) exitWith { ERROR("Null object provided to function"); };

if (_logic getVariable [QGVAR(rpName), ""] == "") then {
    _logic setVariable [QGVAR(rpName), format ["Respawn Point: %1", GVAR(respawnPointCount)], true];
    GVAR(respawnPointCount) = GVAR(respawnPointCount) + 1;
};

true
