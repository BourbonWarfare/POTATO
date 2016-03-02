//potato_core_fnc_isAuthorized

#include "script_component.hpp"
TRACE_1("params",_this);

if (!hasInterface) exitWith {false};

isServer || 
GVAR(playerAuth) ||
{serverCommandAvailable "#kick"}
