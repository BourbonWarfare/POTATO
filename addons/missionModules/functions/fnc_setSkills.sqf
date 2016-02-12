#include "script_component.hpp"

params ["_unit"];
TRACE_1("params",_unit);

// only run this after the settings are initialized
if !(EGVAR(common,settingsInitFinished)) exitWith {
    EGVAR(common,runAtSettingsInitialized) pushBack [FUNC(setSkills), _this];
};

if (GVAR(aiSkill_general) == -1) exitWith {TRACE_1("disabled", GVAR(aiSkill_general));};

{
    _unit setSkill [_x, GVAR(aiSkill_general)];
} forEach ["general", "commanding", "courage"];
{
    _unit setSkill [_x, GVAR(aiSkill_aimingAccuracy)];
} forEach ["aimingAccuracy"];
{
    _unit setSkill [_x, GVAR(aiSkill_weaponHandling)];
} forEach ["aimingShake", "aimingSpeed", "reloadSpeed"];
{
    _unit setSkill [_x, GVAR(aiSkill_spotting)];
} forEach ["spotDistance", "spotTime"];

TRACE_1("ai sills set",_unit);
