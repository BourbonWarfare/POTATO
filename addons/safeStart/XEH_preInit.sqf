#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "initSettings.inc.sqf"

// We Start game safe at preInit
GVAR(safeStartEnabled) = true;
GVAR(safeStartForceEnd) = getMissionConfigValue [QEGVAR(missionTesting,SSForceEnd), false];
GVAR(safeStartSafetyOn) = false;

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

// Remove me after a few months, just need to reset the box size since it's getting saved???
if (profileNamespace getVariable [QUOTE(TRIPLES(igui,GVAR(grid),w)), -1] > 0) then {
    profileNamespace setVariable [QUOTE(TRIPLES(igui,GVAR(grid),w)), nil];
    profileNamespace setVariable [QUOTE(TRIPLES(igui,GVAR(grid),h)), nil];
};

ADDON = true;
