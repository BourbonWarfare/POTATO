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

if (isNil "pidHashMap") then {
    player setVariable ["pidHashMap", createHashMap];
};
private _pidMap = player getVariable "pidHashMap";
TRACE_1("pidHashMap BEFORE",_pidMap);
{
    private _index = lbCurSel _x;
    _pidMap set [_x,_index];
} forEach PID_ALL_SIDE_IDCS;
{
    private _index = lbCurSel _x;
    _pidMap set [_x,_index];
} forEach PID_ALL_ClASS_IDCS;
{
    private _index = lbCurSel _x;
    _pidMap set [_x,_index];
} forEach PID_ALL_STANCE_IDCS;
{
    private _index = sliderPosition _x;
    _pidMap set [_x,_index];
} forEach PID_ALL_DIR_IDCS;

ACE_Player setVariable ["pidHashMap",_pidMap];
TRACE_1("pidHashMap AFTER",_pidMap);

