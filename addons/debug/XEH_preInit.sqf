#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

if (isServer) then {
    [QGVAR(recieveMessage), {call FUNC(recieveMessage)}] call CBA_fnc_addEventHandler;
    GVAR(outPutLogs) = false;
    ["potato_safeStartOff", {
        call FUNC(printLog);
    }] call CBA_fnc_addEventHandler;
};

#ifdef ENABLE_DEBUG_NETWORK_MARKERS
[player] call FUNC(addMarkerInfoEvent);
[QCVAR(briefingEnd), {
    [player] call FUNC(addMarkerInfoEvent);
    [{local player}, {
        [player] call FUNC(addMarkerInfoEvent);
    }, [], 10, {
        [player] call FUNC(addMarkerInfoEvent);
    }] call CBA_fnc_waitUntilAndExecute;
    // 15 seconds after briefing end
    [{[player, true] call FUNC(addMarkerInfoEvent);}, 15, 15] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;
#endif

ADDON = true;
