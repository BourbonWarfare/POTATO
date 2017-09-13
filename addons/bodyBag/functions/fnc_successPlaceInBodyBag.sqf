/*
 * Author: KoffeinFlummi, Glowbal
 * Callback when the treatment fails
 *
 * Arguments:
 * 0: The medic <OBJECT>
 * 1: The patient <OBJECT>
 * 2: SelectionName <STRING>
 * 3: Treatment classname <STRING>
 * 4: Items available <ARRAY<STRING>>
 *
 * Return Value:
 * None
 *
 * Example:
 * [bob, kevin, "selectionname", "classname", ["bandage"]] call ACE_medical_fnc_treatment_failure
 *
 * Public: No
 */

#include "script_component.hpp"

(_this select 0) params ["_caller", "_target"];

[_caller] call FUNC(resetAnimation);

if (local _target) then {
    [_caller, _target] call FUNC(actionPlaceInBodyBag);
} else {
    TRACE_1("running where local", local _target);
    [_caller, _target] remoteExecCall [QFUNC(actionPlaceInBodyBag), _target];
};
