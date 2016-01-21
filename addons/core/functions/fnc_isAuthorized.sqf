//potato_core_fnc_isAuthorized

#include "script_component.hpp"
TRACE_1("params",_this);

if (!hasInterface) exitWith {false};

isServer || 
{serverCommandAvailable "#kick"} ||
{(getPlayerUID player) in AUTHORIZED_USERS}
// {missionNamespace getVariable [QGVAR(playerIsAuthorized), false]}
