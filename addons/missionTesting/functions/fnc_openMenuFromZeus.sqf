/*
 * Author: BadWolf
 * Function is called by the user at the time that they want to use the checklist. This is only called if opened from Zeus.
 *
 * Arguments:
 *
 * Examples:
 * [_logic] call potato_missionTesting_fnc_openMenuFromZeus;
 *
 * Public: No
 */

#include "script_component.hpp"

params ["_logic"];
TRACE_1("Params",_this);

if (!local _logic) exitWith {};
if (!GVAR(missionTestingActive)) then {
    [objNull, "Activate Mission Testing in Admin Menu"] call BIS_fnc_showCuratorFeedbackMessage;
} else {
    [] call FUNC(displayMenu);
};
deleteVehicle _logic;
