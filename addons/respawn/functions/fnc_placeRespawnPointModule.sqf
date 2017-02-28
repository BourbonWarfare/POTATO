/*
 * Author: AACO
 * Function called when respawn point placed in 3DEN/Zeus.
 * Gives it a name if it needs one.
 * Should only be called from the zeus module workflow
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [logicObj] call potato_respawn_fnc_placeRespawnPointModule;
 *
 * Public: No
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
