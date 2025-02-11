#include "script_component.hpp"

GVAR(ehAdded) = false;

[QGVAR(updateAISettings), {
    TRACE_1("updateAISettings EH",_this);

    //If EH is not installed, add it now
    if (!GVAR(ehAdded)) exitWith {
        TRACE_1("Adding Man Init EH",GVAR(ehAdded));
        GVAR(ehAdded) = true;
        ["CaManBase", "init", {call FUNC(manInitEH)}, true, [], true] call CBA_fnc_addClassEventHandler;
    };

    //Update all local unit's skills
    {
        if (local _x) then {
            [_x] call FUNC(setSkillsLocal);
        };
    } forEach allUnits;
}] call CBA_fnc_addEventHandler;

["CBA_settingsInitialized", {
    TRACE_1("CBA_settingsInitialized eh",GVAR(aiSkill_set));
    if (GVAR(aiSkill_set)) then {
        [QGVAR(updateAISettings), []] call CBA_fnc_localEvent;
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(banzi), {
    params ["_group"];
    TRACE_1("banzi eh",_group);

    TRACE_4("",behaviour leader _group,combatMode _group,speedMode _group,formation _group);
    _group setBehaviour "AWARE";
    _group setCombatMode "RED";
    _group setSpeedMode "FULL";
    _group setFormation "LINE";
    _group allowFleeing 0;

    {
        TRACE_1("member",_x);
        _x disableAI "AUTOCOMBAT";
        _x disableAI "COVER";
        _x disableAI "SUPPRESSION";
        _x setUnitPosWeak "UP";
    } forEach (units _group);
}] call CBA_fnc_addEventHandler;

// cleanup safe start TP actions
["potato_safeStartOff", {
    {
        private _actionIDs = _x getVariable [QGVAR(tpActions), []];
        private _object = _x;
        {
            [_object, _x] call BIS_fnc_holdActionRemove;
        } forEach _actionIDs;
    } forEach GVAR(tpActionCleanup);

    {
        _x setMarkerAlphaLocal 0;
    } forEach GVAR(ssTPZones);
}] call CBA_fnc_addEventHandler;

["potato_safeStartOn", {
    {
        _x setMarkerAlphaLocal SAFESTART_MARKER_ALPHA_NOTSELECT;
    } forEach GVAR(ssTPZones);
}] call CBA_fnc_addEventHandler;
