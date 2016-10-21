#include "script_component.hpp"

ADDON = false;

#include "XEH_PREP.hpp"

// We Start game safe at preInit
GVAR(safeStartEnabled) = true;

// Register events
["potato_safeStartOn", {
    GVAR(safeStartEnabled) = true;
    [true] call FUNC(toggleTimer);
}] call CBA_fnc_addEventHandler;

["potato_safeStartOff", {
    GVAR(safeStartEnabled) = false;
    [false] call FUNC(toggleTimer);
}] call CBA_fnc_addEventHandler;

["ace_settingChanged", {
    params ["_name", "_value"];

    if (_name == QGVAR(showTimer) && missionNamespace getVariable [QGVAR(startTime_PV), -1] != -1) then {
        if (_value) then {
            [TIMER_LAYER, QGVAR(safeStartTimerRscTitle)] call FUNC(createDisplay);
        } else {
            TIMER_LAYER cutFadeOut 0;
        };
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
