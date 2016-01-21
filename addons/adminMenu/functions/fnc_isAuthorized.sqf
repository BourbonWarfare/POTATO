//potato_adminMenu_fnc_isAuthorized

#include "script_component.hpp"
TRACE_1("params",_this);

if (!hasInterface) exitWith {false};

isServer || 
{serverCommandAvailable "#kick"} ||
{missionNamespace getVariable [QGVAR(playerIsAuthorized), false]}
