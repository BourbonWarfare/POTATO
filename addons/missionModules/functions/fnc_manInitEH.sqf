#include "script_component.hpp"

params ["_unit"];
TRACE_1("params",_unit);

// only run this after the settings are initialized
if !(ACEGVAR(common,settingsInitFinished)) exitWith {
    ACEGVAR(common,runAtSettingsInitialized) pushBack [FUNC(manInitEH), _this];
};
if (!GVAR(aiSkill_set)) exitWith {TRACE_1("disabled", GVAR(aiSkill_set));};

if (!local _unit) exitWith {};

[_unit] call FUNC(setSkillsLocal);
