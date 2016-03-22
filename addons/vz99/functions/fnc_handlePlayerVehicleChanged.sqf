/*
 * Author: PabstMirror
 * Handles player getting into new vehicle.
 *
 * Arguments:
 * 0: Player <OBJECT>
 * 1: New Vehicle <OBJECT>
 *
 * Return Value:
 * No
 *
 * Example:
 * [
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_player", "_mortarVeh"];
TRACE_2("playerVehicleChanged eh",_player,_newVehicle);

if (isNull _mortarVeh) exitWith {};
if (!(_mortarVeh isKindOf QGVAR(mortar))) exitWith {};


TRACE_1("starting PFEH", _this);
[{
    params ["_args", "_pfID"];
    _args params ["_mortarVeh"];

    if ((vehicle ACE_player) != _mortarVeh) then {
        TRACE_1("exiting PFEH", _this);
        [_pfID] call CBA_fnc_removePerFrameHandler;
    } else {





    };
}, 0, [_mortarVeh]] call CBA_fnc_addPerFrameHandler;
