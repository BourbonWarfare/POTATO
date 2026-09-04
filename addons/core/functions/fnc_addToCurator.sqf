#include "script_component.hpp"
/*
 * Arguments:
 * Array of object <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [objects] call potato_core_fnc_addToCurator
 */
TRACE_1("addToCurator",_this);

if (ace_zeus_autoAddObjects) exitWith {};

[QGVAR(addToCurator), _this] call CBA_fnc_serverEvent;
