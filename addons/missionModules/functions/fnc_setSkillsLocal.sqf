#include "script_component.hpp"

params ["_unit"];
TRACE_1("params",_unit);

{
    _x params ["_skill","_inputMin","_inputMax"];
    ([_inputMin,_inputMax,0,1] call EFUNC(core,ensureBoundedMinMax)) params ["_min","_max"];

    _unit setSkill [_skill, [_min,_max] call EFUNC(core,getBoundedRandom)];
} forEach SUB_SKILLS;

if (GVAR(aiSkill_COVER)) then {
    _unit enableAI "COVER";
} else {
    _unit disableAI "COVER";
};

if (GVAR(aiSkill_AUTOCOMBAT)) then {
    _unit enableAI "AUTOCOMBAT";
} else {
    _unit disableAI "AUTOCOMBAT";
};

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
