#include "script_component.hpp"

TRACE_1("uihook_checkSettings",_this);

[QGVAR(checkSettings), clientOwner] call CBA_fnc_serverEvent;
