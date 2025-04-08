#include "script_component.hpp"
TRACE_1("",QUOTE(ADDON));

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

if (is3DENPreview || is3DEN || {
    QACEFUNC(arsenal,onPause) in getMissionConfigValue ["onPauseScript", []]
    }) then {
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
        missionNamespace,
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


    ["ace_arsenal_statsToggle", {
        params ["_display", "_showStats"];
        private _ctrlGroup = _display displayCtrl IDC_CTRLGROUP;
        _ctrlGroup ctrlShow _showStats;
    }] call CBA_fnc_addEventHandler;
};


ADDON = true;
