#include "script_component.hpp"
/*
 * Author: PabstMirror
 * Handles player jipping, sends hint on last group
 */


if (isServer) then {
    GVAR(playerMap) = createHashMap;
    [QGVAR(playerConnected), {
        params ["_player", "_profileName"];
        private _msg = if (_profileName in GVAR(playerMap)) then {
            (GVAR(playerMap) get _profileName) params ["_lastSide", "_lastGroup"];
            private _sideText = switch (_lastSide) do {
                case blufor: { "B" };
                case opfor: { "O" };
                case independent: { "I" };
                case civilian: { "C" };
                default { "?" };
            };
            format ["has JIPed; last in [%1-%2]", _sideText, _lastGroup]
        } else {
            private _lastSide = side group _player;
            private _lastGroup = groupId group _player;
            GVAR(playerMap) set [_profileName, [_lastSide, _lastGroup]];
            format ["has JIPed"];
        };
        INFO_2("playerConnected: %1: [%2]",_profileName,_msg);
        if (CBA_missionTime < 60) exitWith {};
        ["potato_adminMsg", [_msg, _profileName]] call CBA_fnc_globalEvent;
    }] call CBA_fnc_addEventHandler;
};


if (hasInterface) then {
    [{
        ["unit", {
            params ["_player"];
            if ((!alive _player) || {_player isKindOf "VirtualMan_F"}) exitWith {};
            if (missionNamespace getVariable [QGVAR(playerConnectedSent), false]) exitWith {};
            GVAR(playerConnectedSent) = true;
            TRACE_2("playerConnected",_player,profileName);
            [QGVAR(playerConnected), [_player, profileName]] call CBA_fnc_serverEvent;
        }, true] call CBA_fnc_addPlayerEventHandler;
    }, [], 1] call CBA_fnc_waitAndExecute;
};
