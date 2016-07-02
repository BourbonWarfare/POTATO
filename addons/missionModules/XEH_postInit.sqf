#include "script_component.hpp"

GVAR(ehAdded) = false;

[QGVAR(UpdateAISettings), {
    TRACE_1("UpdateAISettings EH",_this);
    
    //If EH is not installed, add it now
    if (!GVAR(ehAdded)) exitWith {
        TRACE_1("Adding Man Init EH", GVAR(ehAdded));
        GVAR(ehAdded) = true;
        ["CaManBase", "init", {_this call FUNC(manInitEH)}, true, [], true] call CBA_fnc_addClassEventHandler;
    };
    
    //Update all local unit's skills
    {
        if (local _x) then {
            [_x] call FUNC(setSkillsLocal);
        };
    } forEach allUnits;
}] call CBA_fnc_addEventHandler;

["ace_settingsInitialized", {
    TRACE_1("ace_settingsInitialized eh", GVAR(aiSkill_set));
    if (GVAR(aiSkill_set)) then {
        [QGVAR(UpdateAISettings), []] call CBA_fnc_localEvent;
    };
}] call CBA_fnc_addEventHandler;
