#include "script_component.hpp"

[
    {
        ACEGVAR(common,settingsInitFinished) && {diag_tickTime > (_this select 0)}
    }, {
        if (GVAR(enabled)) then {
            [] call FUNC(makeSafe);
        };
    }, [diag_tickTime + 1]
] call CBA_fnc_waitUntilAndExecute;

[] spawn {
    sleep 1;

    if ((missionNamespace getVariable [QGVAR(startTime_PV), -1]) != -1) then {
        //Mission was safed at game start:
        [] call FUNC(showTimer);
        TRACE_1("safestart on at start", GVAR(safeStartEnabled));
    } else {
        GVAR(safeStartEnabled) = false;
        TRACE_1("safestart off at start", GVAR(safeStartEnabled));

        if (isServer) then { //backwards compatibilty
            missionNamespace setVariable ["PABST_ADMIN_SAFESTART_public_isSafe", false, true];
        };
    };
};

["safeStartOn", {
    GVAR(safeStartEnabled) = true;
    [] call FUNC(showTimer);
}] call ace_common_fnc_addEventHandler;
