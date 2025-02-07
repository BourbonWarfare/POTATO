#include "script_component.hpp"

#ifndef DEBUG_MODE_FULL
if (hasInterface) exitWith {}; // ignore for mission makers
#endif

["CBA_settingsInitialized", {
    TRACE_3("CBA_settingsInitialized",GVAR(enable),GVAR(hideInsteadOfDelete),GVAR(allowVehicles));
    if !(GVAR(enable)) exitWith {};

    GVAR(cells) = createHashMap;
    GVAR(run) = true;

    [{
        TRACE_1("cleanup",GVAR(run));
        if (GVAR(run)) then {
            call FUNC(cleanupPFH);
        };
    }, CLEANUP_FREQUENCY] call CBA_fnc_addPerFrameHandler;

    [{
        params ["_args"];
        _args params ["_lastUpdate"];

        private _dt = CBA_missionTime - _lastUpdate;
        _args set [0, CBA_missionTime];

        TRACE_2("update",GVAR(run),_dt);
        if (GVAR(run)) then {
            [_dt] call FUNC(updateCellPFH);
        };
    }, UPDATE_FREQUENCY, [CBA_missionTime]] call CBA_fnc_addPerFrameHandler;

    addMissionEventHandler ["EntityKilled", { call FUNC(onKill); }];

    #ifdef DEBUG_MODE_FULL
    findDisplay 12 displayCtrl 51 ctrlAddEventHandler ["Draw", {
        call FUNC(debugPFH);
    }];
    #endif

}] call CBA_fnc_addEventHandler;