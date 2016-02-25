#include "script_component.hpp"

params ["_unit"];
TRACE_1("params",_unit);

// only run this after the settings are initialized
if !(EGVAR(common,settingsInitFinished)) exitWith {
    EGVAR(common,runAtSettingsInitialized) pushBack [FUNC(setSkills), _this];
};
if (!GVAR(aiSkill_set)) exitWith {TRACE_1("disabled", GVAR(aiSkill_set));};

if (!local _unit) exitWith {};

[_unit] call FUNC(setSkillsLocal);
