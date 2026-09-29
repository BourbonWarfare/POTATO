#include "script_component.hpp"
#define POTATO_TIME_SYNC_RATE 10
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
// Based on in part CBA Common addon's init_perFrameHandler.sqf - GNU GPLv2
0 spawn {isNil {
    GVARMAIN(missionTime) = 0;
    if (isMultiplayer) then {
        if (isServer) then {
            GVAR(lastSend) = -POTATO_TIME_SYNC_RATE;
            [QFUNC(missionTimeServer), {
                GVARMAIN(missionTime) = CBA_missionTime;
                if (GVARMAIN(missionTime) - GVAR(lastSend) >= POTATO_TIME_SYNC_RATE) then {
                    publicVariable QGVARMAIN(missionTime);
                    GVAR(lastSend) = GVARMAIN(missionTime);
                };
            }] call CBA_fnc_compileFinal;
            [{call FUNC(missionTimeServer)}] call CBA_fnc_addPerFrameHandler;
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
};};
// End potato_time
ADDON = true;
