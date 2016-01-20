#include "script_component.hpp"

[] spawn {
    sleep 1;

    if ((missionNamespace getVariable [QGVAR(startTime_PV), -1]) != -1) then {
        //Mission was safed at game start:
        [] call FUNC(showTimer);
        TRACE_1("safestart on at start", GVAR(safeStartEnabled));
    } else {
        GVAR(safeStartEnabled) = false;
        TRACE_1("safestart off at start", GVAR(safeStartEnabled));
    };
};

["safeStartOn", {
    GVAR(safeStartEnabled) = true;
    [] call FUNC(showTimer);
}] call ace_common_fnc_addEventHandler;
