#include "script_component.hpp"

GVAR(logs) = [];

if (hasInterface) then {
    ["potato_adminMsg", {
        if ([] call EFUNC(core,isAuthorized)) then {
            TRACE_1("Adding Log", _this);
            params ["_msg", ["_from", "?"], ["_to", ""]];
            GVAR(logs) pushBack [time, _msg, _from, _to];

            if (!isNull (findDisplay 49)) then {
                //If they have it open, update chat log now:
                [findDisplay 49] call FUNC(mouseCatch);
            };
        };
    }] call CBA_fnc_addEventHandler;

    // Cleanup chat
    addMissionEventHandler ["HandleChatMessage", {
        params ["_channel", "_owner", "_from", "_text", "_person", "_name", "_strID", "_forcedDisplay", "_isPlayerMessage", "_sentenceType", "_chatMessageType"];
        private _returnValue = nil;
        if (isPlayer _person) then {
            if ((_text select [0,5]) == "force") then {
                // _returnValue = _text select [5]; // optionally clean up text
            } else {
                _returnValue = true; // block
                if (_person == player) then {
                    systemChat "Your message was blocked, start message with 'force' to send in channel";
                    systemChat "Use admin message (hit escape) for help with Problems/JIP";
                };
            };
        } else {
            if ((_channel == 16) && {(_text select [0,7]) isEqualTo "Player "}) then { // connected/disconnected msg (but not connecting...?)
                _returnValue = true; // block
            };
        };
        _returnValue // don't use exitWith in eh
    }];
};

if (isServer) then {
    [{
        private _authorName = getMissionConfigValue ["author", "???"];
        private _authorPresent = (allUnits findIf {(name _x) == _authorName}) > -1;
        ["potato_adminMsg", [format ["-Mision Maker [Present: %1]", _authorPresent], _authorName]] call CBA_fnc_globalEvent;
    }, [], 1] call CBA_fnc_waitAndExecute;
};
