/*
 * Author: AACO
 * Function used to show recruit info to clients
 *
 * Arguments:
 * 0: Display the recruit message <BOOL>
 * 0: Display the recruit tags <BOOL>
 *
 * Examples:
 * [true] call potato_safeStart_fnc_toggleRecruitInfo;
 * [false] call potato_safeStart_fnc_toggleRecruitInfo;
 *
 * Public: Yes
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_enable"];

if ((((squadParams player) select 0) select 1) != "Bourbon Warfare") exitWith { LOG("Player not in squad.xml, exiting"); };

if (_enable) then {
    if !(isNil QGVAR(drawId)) exitWith { LOG("Tried to start the recruit info tracker while it was already running"); };

    if (GVAR(showMessage)) then {
        GVAR(oldSquad) = [];
        [QGVAR(message)] call CFUNC(createRscTitle);
    };

    GVAR(drawId) = addMissionEventHandler ["Draw3D", FUNC(updateRecruitInfo)];
} else {
    if (isNil QGVAR(drawId)) exitWith { LOG("Tried to stop the recruit info tracker while it was already stopped"); };

    removeMissionEventHandler ["Draw3D", GVAR(drawId)];
    GVAR(drawId) = nil;

    GVAR(oldSquad) = [];
    QGVAR(message) cutFadeOut 1;
};
