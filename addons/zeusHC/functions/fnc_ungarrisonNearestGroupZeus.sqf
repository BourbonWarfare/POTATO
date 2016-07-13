/*
 * Author: AACO`
 * logic called when a ungarrison nearest group module is placed
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params ["_logic"];
if (isNull _logic) exitWith {};

private _nearestAiGroup = [_logic] call FUNC(getNearestAIGroup);

if (isNull _nearestAiGroup) then {
    ["No group could be found to ungarrison", owner _logic] call FUNC(sendCuratorHint);
} else {
    [_nearestAiGroup] remoteExecCall [QFUNC(ungarrisonGroup), groupOwner _nearestAiGroup];
};

deleteVehicle _logic;
