/*
 * Author: PabstMirror, AACO
 * Function used to set skills on a local unit
 * should only be called from events
 *
 * Public: No
 */

#include "script_component.hpp"

params ["_unit"];
TRACE_1("params",_unit);

if (!GVAR(aiSkill_set)) exitWith { LOG("Exiting early, not set"); };

{
    _x params ["_skill", "_inputMin", "_inputMax"];
    ([_inputMin, _inputMax, 0, 1] call EFUNC(core,ensureBoundedMinMax)) params ["_min", "_max"];

    _unit setSkill [_skill, [_min, _max] call EFUNC(core,getBoundedRandom)];
} forEach SUB_SKILLS;

{
    _x params ["_behavior", "_enabled"];

    if (_enabled) then {
        _unit enableAI _behavior;
    } else {
        _unit disableAI _behavior;
    };
} forEach AI_BEHAVIORS;

TRACE_1("ai sills set",_unit);

#ifdef DEBUG_MODE_FULL
[_unit] spawn {
    sleep 1;
    params ["_unit"];

    diag_log text format ["Unit %1 - Local %2", _unit, local _unit];
    {
        _x params ["_skill","_inputMin","_inputMax"];
        diag_log text format ["Skill [%1] = [%2] from range [%3-%4]",_skill, _unit skill _skill, _inputMin, _inputMax];
    } forEach SUB_SKILLS;
};
#endif
