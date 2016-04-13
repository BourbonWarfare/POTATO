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
TRACE_2("playerVehicleChanged eh",_player,_mortarVeh);

if (isNull _player) exitWith {};
if (isNull _mortarVeh) exitWith {};
if (!(_mortarVeh isKindOf QGVAR(mortar))) exitWith {};


TRACE_1("starting PFEH", _this);
[{
    params ["_args", "_pfID"];
    _args params ["_player", "_mortarVeh"];

    if ((!alive _player) || {!alive _mortarVeh} || {ACE_player != _player}) exitWith {
        TRACE_2("exiting PFEH, null/change",_player,_mortarVeh);
        [_pfID] call CBA_fnc_removePerFrameHandler;
    };

    if ((vehicle _player) != _mortarVeh) exitWith {
        TRACE_1("exiting PFEH - clean getout", _this);
        [_pfID] call CBA_fnc_removePerFrameHandler;

        if (((_player distance _mortarVeh) < 5) &&
                {[_mortarVeh, _player] call FUNC(canPickupWeapon)} &&
                {[_player, _mortarVeh, []] call ACEFUNC(common,canInteractWith)}) then {
            private _weaponDir = _mortarVeh weaponDirection (currentWeapon _mortarVeh);
            private _azimuth = (_weaponDir select 0) atan2 (_weaponDir select 1);
            TRACE_1("CAN pickup - set dir",_mortarVeh,_azimuth);
            _player setDir _azimuth;
            [_mortarVeh, _player] call FUNC(doPickupWeapon);
        } else {
            TRACE_1("CANNOT pickup",_mortarVeh);
        };
    };
}, 0.1, [_player, _mortarVeh]] call CBA_fnc_addPerFrameHandler;
