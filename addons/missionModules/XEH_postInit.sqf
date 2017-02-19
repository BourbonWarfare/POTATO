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

[QGVAR(banzi), {
    params ["_group"];
    TRACE_1("banzi eh", _group);

    TRACE_4("",behaviour _unit,combatMode _group,speedMode _group,formation _group);
    _group setBehaviour "AWARE";
    _group setCombatMode "RED";
    _group setSpeedMode "FULL";
    _group setFormation "LINE";
    _group allowFleeing 0;

    {
        TRACE_1("member",_x);
        _x disableAI "AUTOCOMBAT";
        _x disableAI "COVER";
        _x setUnitPosWeak "UP";
    } forEach (units group _unit);
}] call CBA_fnc_addEventHandler;
