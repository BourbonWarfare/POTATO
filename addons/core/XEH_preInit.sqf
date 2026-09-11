#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "initSettings.inc.sqf"

if (isMultiplayer && isServer) then {
    [{getClientStateNumber > 9}, {
        [QGVAR(briefingEnd), CBA_missionTime] call CBA_fnc_globalEventJIP;
    }] call CBA_fnc_waitUntilAndExecute;
};
// potato_time - network syncronized CBA_missionTime
// Based on in part CBA Common adoon's init_perFrameHandler.sqf - GNU GPLv2
GVARMAIN(missionTime) = 0;
if (isMultiplayer) then {
    if (isServer) then { // just broadcast CBA_missionTime every N seconds
        GVAR(lastSend) = -10;
        [QFUNC(missionTimeServer), {
            GVARMAIN(missionTime) = CBA_missionTime;
            if (GVARMAIN(missionTime) - GVAR(lastSend) >= POTATO_TIME_UPDATERATE) then {
                publicVariable QGVARMAIN(missionTime);
                GVAR(lastSend) = GVARMAIN(missionTime);
            };
        }] call CBA_fnc_compileFinal;
        [{call FUNC(missionTimeServer)}, 10] call CBA_fnc_addPerFrameHandler;
    } else {
        GVAR(MTUpdate) = time;
        GVAR(MTLast) = diag_tickTime;
        [QFUNC(missionTimeClient), {
            if (time > GVAR(MTUpdate)) then {
                //IGNORE_PRIVATE_WARNING ["_tickTime"];
                GVARMAIN(missionTime) = GVARMAIN(missionTime) + _tickTime - GVAR(MTLast);
                GVAR(MTUpdate) = time;
            };
        GVAR(MTLast) = _tickTime;
        }] call CBA_fnc_compileFinal;
        [{call FUNC(missionTimeClient)}] call CBA_fnc_addPerFrameHandler;
    };
} else {
    [{GVARMAIN(missionTime) = CBA_missionTime}] call CBA_fnc_addPerFrameHandler;
};
// End potato_time
ADDON = true;
