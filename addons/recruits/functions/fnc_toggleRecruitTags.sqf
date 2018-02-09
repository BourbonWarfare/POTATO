/*
 * Author: AACO
 * Function used to show recruit tags to clients
 *
 * Arguments:
 * 0: Start displaying the recruit tags <BOOL>
 *
 * Examples:
 * [true] call potato_recruits_fnc_toggleRecruitTags;
 * [false] call potato_recruits_fnc_toggleRecruitTags;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_enable"];

if ([player] call FUNC(isNotMember)) exitWith { LOG("Player not in squad.xml, exiting"); };

if (_enable) then {
    if !(isNil QGVAR(drawId)) exitWith { LOG("Tried to start drawing the recruit tags while it was already running"); };

    GVAR(drawId) = addMissionEventHandler ["Draw3D", {call FUNC(drawRecruitTags)}];
} else {
    if (isNil QGVAR(drawId)) exitWith { LOG("Tried to stop drawing the recruit tags while it was already stopped"); };

    removeMissionEventHandler ["Draw3D", GVAR(drawId)];
    GVAR(drawId) = nil;
};
