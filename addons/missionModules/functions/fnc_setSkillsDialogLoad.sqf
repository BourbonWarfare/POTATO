/*
 * Author: AACO
 * Function used to set controls to the current settings
 * should only be called from UI events
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

waitUntil {dialog}; // wait until the dialog is fully loaded before we do any population

// set master enable/disable status
GET_CTRL(SET_SKILLS_MASTER_BX_IDC) cbSetChecked GVAR(aiSkill_set);

// set sub skills
{
    _x params ["", "_minVar", "_maxVar", "_minIdc", "_maxIdc"];

    sliderSetPosition [_minIdc, _minVar];
    sliderSetPosition [_maxIdc, _maxVar];

    GET_CTRL(_minIdc) ctrlSetTooltip ([_minVar, 1, 2] call CBA_fnc_formatNumber);
    GET_CTRL(_maxIdc) ctrlSetTooltip ([_maxVar, 1, 2] call CBA_fnc_formatNumber);

    sliderSetRange [_minIdc, 0, 1];
    sliderSetRange [_maxIdc, 0, 1];

    sliderSetSpeed [_minIdc, 0.1, 0.05];
    sliderSetSpeed [_maxIdc, 0.1, 0.05];
} forEach SUB_SKILLS;

// set behaviors
{
    _x params ["", "_enabled", "_idc"];
    GET_CTRL(_idc) cbSetChecked _enabled;
} forEach AI_BEHAVIORS;
