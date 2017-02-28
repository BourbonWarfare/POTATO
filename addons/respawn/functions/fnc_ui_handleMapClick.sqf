/*
 * Author: AACO
 * Function used to handle map clicks
 * Should only be called from events
 *
 * Arguments:
 * 2: X screen coordinate <NUMBER>
 * 3: Y screen coordinate <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [nil,1,2,3] call potato_respawn_fnc_ui_handleMapClick;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("Params",_this);

params ["", "", "_x", "_y"];

private _position = if (isNull GVAR(mapHighlighted)) then {
    ADMIN_MAP ctrlMapScreenToWorld [_x, _y]
} else {
    getPos GVAR(mapHighlighted)
};

["potato_adminMsg", ["Triggered respawn", profileName]] call CBA_fnc_globalEvent;
[_position] call FUNC(triggerRespawn);
[] call FUNC(closeAdminRespawn);
