/*
 * Author: AACO
 * Function used to show recruit info to clients
 *
 * Arguments:
 * 0: Start displaying the recruit information <BOOL>
 *
 * Examples:
 * [true] call potato_recruits_fnc_toggleRecruitInfo;
 * [false] call potato_recruits_fnc_toggleRecruitInfo;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_enable"];

if ([player] call FUNC(isNotMember)) exitWith { LOG("Player not in squad.xml, exiting"); };

if (_enable) then {
    if !(isNil QGVAR(updateInfoId)) exitWith { LOG("Tried to start the recruit info tracker while it was already running"); };

    GVAR(oldSquad) = [];
    [QGVAR(message)] call CFUNC(createRscTitle);
    GVAR(updateInfoId) = [FUNC(updateRecruitInfo), 5] call CBA_fnc_addPerFrameHandler;
} else {
    if (isNil QGVAR(updateInfoId)) exitWith { LOG("Tried to stop the recruit info tracker while it was already stopped"); };

    [GVAR(updateInfoId)] call CBA_fnc_removePerFrameHandler;
    GVAR(updateInfoId) = nil;
    QGVAR(message) cutFadeOut 1;
};
