#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

// We Start game safe at preInit
GVAR(safeStartEnabled) = true;
GVAR(safeStartWarningEnabled) = true;

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
            [QGVAR(timerRscTitle)] call CFUNC(createRscTitle);
        } else {
            QGVAR(timerRscTitle) cutFadeOut 0;
        };
    };
}] call CBA_fnc_addEventHandler;

ADDON = true;
