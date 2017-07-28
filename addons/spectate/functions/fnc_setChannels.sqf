/*
 * Author: AACO
 * Function used to set chat channels, allows global for admins (group cannot be turned off)
 *
 * Arguments:
 * 0: Set to <BOOL>
 *
 * Examples:
 * [false] call potato_spectate_fnc_setChannels; // turn channels off
 * [true] call potato_spectate_fnc_setChannels; // turn channels on
 *
 * Public: No
 */

#include "script_component.hpp"
TRACE_1("Params",_this);

params [["_set", false, [false]]];

{
    _x enableChannel _set;
} forEach ([
    [GLOBAL_CHANNEL_INDEX, SIDE_CHANNEL_INDEX, COMMAND_CHANNEL_INDEX, VEHICLE_CHANNEL_INDEX, DIRECT_CHANNEL_INDEX],
    [SIDE_CHANNEL_INDEX, COMMAND_CHANNEL_INDEX, VEHICLE_CHANNEL_INDEX, DIRECT_CHANNEL_INDEX]
] select (call CFUNC(isAuthorized)));
