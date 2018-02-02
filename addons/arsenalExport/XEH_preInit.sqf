#include "script_component.hpp"
TRACE_1("",QUOTE(ADDON));

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

// Add at pre-Init so it works in 3den
["ace_arsenal_displayOpened", {
    INFO("ACE arsenalOpened EH");
    #ifdef DISABLE_COMPILE_CACHE
    call ACE_PREP_RECOMPILE;
    #endif
    params ["_display"];
    [_display, true] call FUNC(arsenalOpened);
}] call CBA_fnc_addEventHandler;


[
    missionnamespace,
    "arsenalOpened",
    {
        INFO("BIS arsenalOpened EH");
        #ifdef DISABLE_COMPILE_CACHE
        call ACE_PREP_RECOMPILE;
        #endif
        params ["_display"];
        [_display, false] call FUNC(arsenalOpened);
    }
] call bis_fnc_addscriptedeventhandler;

ADDON = true;
