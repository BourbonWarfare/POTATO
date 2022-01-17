/*
 * Author: BadWolf
 *
 *
 * Arguments:
 *
 * Examples:
 * [] call potato_missionTesting_fnc_runWeaponsTest;
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [""];

if (isNil "pidHashMap") exitWith {false};

private _pidHash = player getVariable "pidHashMap";

{
    private _index = _pidHash get [_x];
    lbSetCurSel [_x,_index];
} forEach PID_ALL_SIDE_IDCS;
{
    private _index = _pidHash get [_x];
    lbSetCurSel [_x,_index];
} forEach PID_ALL_ClASS_IDCS;
{
    private _index = _pidHash get [_x];
    lbSetCurSel [_x,_index];
} forEach PID_ALL_STANCE_IDCS;
{
    private _index = _pidHash get [_x];
    sliderSetPosition [,_index];
} forEach PID_ALL_DIR_IDCS;
