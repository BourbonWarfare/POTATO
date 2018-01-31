#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "initSettings.sqf"

if (hasInterface) then {
    // Register events
    ["potato_safeStartOn", {
        [GVAR(showMessage)] call FUNC(toggleRecruitInfo);
        [GVAR(showTags)] call FUNC(toggleRecruitTags);
    }] call CBA_fnc_addEventHandler;

    ["potato_safeStartOff", {
        [false] call FUNC(toggleRecruitInfo);
        [false] call FUNC(toggleRecruitTags);
    }] call CBA_fnc_addEventHandler;
};

ADDON = true;
