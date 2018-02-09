/*
 * Author: AACO
 * Function used to update tooltips to new values and update min/maxes
 * should only be called from UI events
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_value", "_controlSubSkill", "_isMax"];

// find correct skill
{
    _x params ["_subSkill", "_minVar", "_maxVar", "_minIdc", "_maxIdc"];
    if (_controlSubSkill == _subSkill) exitWith {
        if (_isMax) then {
            GET_CTRL(_maxIdc) ctrlSetTooltip ([_value, 1, 2] call CBA_fnc_formatNumber);

            private _minValue = sliderPosition _minIdc;
            if (_value < _minValue) then {
                sliderSetPosition [_minIdc, _value];
                GET_CTRL(_minIdc) ctrlSetTooltip ([_value, 1, 2] call CBA_fnc_formatNumber);
            };
        } else {
            GET_CTRL(_minIdc) ctrlSetTooltip ([_value, 1, 2] call CBA_fnc_formatNumber);

            private _maxValue = sliderPosition _maxIdc;
            if (_value > _maxValue) then {
                sliderSetPosition [_maxIdc, _value];
                GET_CTRL(_maxIdc) ctrlSetTooltip ([_value, 1, 2] call CBA_fnc_formatNumber);
            };
        };
    };
} forEach SUB_SKILLS;
