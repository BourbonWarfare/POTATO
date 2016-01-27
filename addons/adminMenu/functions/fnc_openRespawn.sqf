//potato_adminMenu_fnc_openRespawn

#include "script_component.hpp"
TRACE_1("params",_this);

disableSerialization;

if (!([] call EFUNC(core,isAuthorized))) exitWith {
    systemChat "Not Authorized";
};

private _debugMsg = format ["Opens Respawn"];
["potato_adminMsg", [_debugMsg, profileName]] call ACEFUNC(common,globalEvent);

createDialog "respawnMenuDialog";
