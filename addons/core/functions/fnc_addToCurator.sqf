// #define DEBUG_MODE_FULL
#include "script_component.hpp"

TRACE_1("addToCurator",_this);

if (ace_zeus_autoAddObjects) exitWith {};

[QGVAR(addToCurator), _this] call CBA_fnc_serverEvent;
