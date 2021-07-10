#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "initSettings.sqf"

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
    [] call FUNC(missionTimeWarning);
}] call CBA_fnc_addEventHandler;

[QGVAR(curatorHint_TimeKeeper_15min), {
        ["Time Keeper", "15 mins to mission end", 30] call BIS_fnc_curatorHint;
}] call CBA_fnc_addEventHandler;

[QGVAR(curatorHint_TimeKeeper_end), {
        ["Time Keeper", "Mission Time has expired", 30] call BIS_fnc_curatorHint;
}] call CBA_fnc_addEventHandler;

ADDON = true;
