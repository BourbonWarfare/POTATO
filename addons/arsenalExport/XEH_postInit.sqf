#include "script_component.hpp"
TRACE_1("",QUOTE(ADDON));

[
    missionnamespace,
    "arsenalOpened",
    {
        INFO("arsenalOpened EH");
        call ACE_PREP_RECOMPILE;
        _this call FUNC(arsenalOpened);
    }
] call bis_fnc_addscriptedeventhandler;
