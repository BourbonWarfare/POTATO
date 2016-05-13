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
