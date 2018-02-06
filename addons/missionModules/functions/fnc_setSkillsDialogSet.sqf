/*
 * Author: AACO
 * Function used to update settings with new values from the UI
 * should only be called from UI events
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

// master enable/disable
[QGVAR(aiSkill_set), cbChecked GET_CTRL(SET_SKILLS_MASTER_BX_IDC), 2, "server"] remoteExecCall ["CBA_settings_fnc_set", SERVER_CLIENT_ID];

// sub skills
{
    _x params ["_subSkill", "", "", "_minIdc", "_maxIdc"];

    [format [QGVAR(aiSkill_%1_min), _subSkill], sliderPosition _minIdc, 2, "server"] remoteExecCall ["CBA_settings_fnc_set", SERVER_CLIENT_ID];
    [format [QGVAR(aiSkill_%1_max), _subSkill], sliderPosition _maxIdc, 2, "server"] remoteExecCall ["CBA_settings_fnc_set", SERVER_CLIENT_ID];
} forEach SUB_SKILLS;

// behaviors
{
    _x params ["_behavior", "_enabled", "_idc"];
    [format [QGVAR(aiSkill_%1), _behavior], cbChecked GET_CTRL(_idc), 2, "server"] remoteExecCall ["CBA_settings_fnc_set", SERVER_CLIENT_ID];
} forEach AI_BEHAVIORS;

[QGVAR(updateAISettings), []] call CBA_fnc_globalEvent;

// last thing, close dialog with success
closeDialog 1;
