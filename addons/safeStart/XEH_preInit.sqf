#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

[
    QGVAR(showTimer),
    "CHECKBOX",
    ["Show SafeStart Timer", "False disables the on screen timer, can use to make clean recordings."],
    "POTATO UI",
    true,
    0,
    {
        if (missionNamespace getVariable [QGVAR(startTime_PV), -1] != -1) then {
            if (_this) then {
                [QGVAR(timerRscTitle)] call CFUNC(createRscTitle);
            } else {
                QGVAR(timerRscTitle) cutFadeOut 0;
            };
        };
    }
] call cba_settings_fnc_init;

[
    QGVAR(enabled),
    "CHECKBOX",
    ["Enable safe start at mission start", "Enables safe start at the start of the mission."],
    "POTATO Admin",
    false,
    1
] call cba_settings_fnc_init;

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

ADDON = true;
