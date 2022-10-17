/*
 * Author: AACO
 * Function used check if a unit is a member or not
 *
 * Arguments:
 * 0: Display the recruit message <OBJECT>
 *
 * Examples:
 * [player] call potato_recruits_fnc_isNotMember;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_unit"];

private _squadParams = squadParams _unit;

if (_squadParams isEqualTo []) exitWith { true };
if ((_squadParams select 0) isEqualTo []) exitWith { true };
((_squadParams select 0) select 1) != "COALITION"
