//potato_adminMenu_fnc_openRespawn

#include "script_component.hpp"
TRACE_1("params",_this);

(findDisplay 49) closeDisplay 1;

if (!([] call EFUNC(core,isAuthorized))) exitWith {
    systemChat "Not authorized";
};

private _debugMsg = [] call {
    if (!isNil QEGVAR(spectate,enabled) && {EGVAR(spectate,enabled)}) exitWith {
        [] call EFUNC(respawn,openAdminRespawn);
        "Opens POTATO respawn"
    };
    if (isClass (missionConfigFile >> "respawnMenuDialog")) exitWith {
        [] spawn { createDialog "respawnMenuDialog"; };
        "Opens framework respawn"
    };
    "Failed to open respawn; POTATO and framework options not found"
};

["potato_adminMsg", [_debugMsg, profileName]] call CBA_fnc_globalEvent;
