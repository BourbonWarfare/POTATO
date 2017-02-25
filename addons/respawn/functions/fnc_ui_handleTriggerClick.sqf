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

[false] call FUNC(changeRespawnState);

ctrlShow [ADMIN_MAP_IDC, true];
ctrlSetFocus ADMIN_MAP;
