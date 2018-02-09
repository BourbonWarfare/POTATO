/*
 * Author: PabstMirror
 * Function used to set skills on a local unit
 * should only be called from events
 *
 * Public: No
 */

#include "script_component.hpp"

params ["_unit"];
TRACE_1("params",_unit);

if (local _unit) then {
    [FUNC(setSkillsLocal), [_unit]] call CBA_fnc_execNextFrame;
};
