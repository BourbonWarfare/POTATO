/*
 * Author: AACO
 * Function used to handle map clicks
 * Should only be called from events
 *
 * Arguments:
 * 1: Button index <NUMBER>
 * 2: X screen coordinate <NUMBER>
 * 3: Y screen coordinate <NUMBER>
 *
 * Return Value:
 * Nothing
 *
 * Examples:
 * [nil,1,2,3] call potato_spectate_fnc_ui_handleMapClick;
 *
 * Public: No
 */

#include "script_component.hpp"

TRACE_1("Params",_this);

params ["", "_button", "_x", "_y"];

private _position = if (isNull GVAR(mapHighlighted)) then {
    (ctrlPosition ADMIN_MAP) params ["_ctrlX", "_ctrlY"];
    ADMIN_MAP ctrlMapScreenToWorld [_x - _ctrlX, _y - _ctrlY]
} else {
    getPos GVAR(mapHighlighted)
};

[_position] call FUNC(triggerRespawn);
[] call FUNC(closeAdminRespawn);
