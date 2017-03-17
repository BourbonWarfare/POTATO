#include "script_component.hpp"
TRACE_1("",QUOTE(ADDON));

[
    missionnamespace,
    "arsenalOpened",
    {
        INFO("arsenalOpened EH");
        #ifdef DISABLE_COMPILE_CACHE
        call ACE_PREP_RECOMPILE;
        #endif
        _this call FUNC(arsenalOpened);
    }
] call bis_fnc_addscriptedeventhandler;
