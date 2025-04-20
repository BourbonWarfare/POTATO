#include "script_component.hpp"

if (isServer) then {
    [QGVAR(addToCurator), LINKFUNC(addToCuratorServer)] call CBA_fnc_addEventHandler;
};

GVAR(playerStartingSide) = sideUnknown;
GVAR(playerAuth) = false;
GVAR(playerTech) = false;

if (hasInterface) then {
    ["unit", {
        if (isNull player) exitWith {};
        if (GVAR(playerStartingSide) isEqualTo sideUnknown) then {
            TRACE_1("Setting start playerside",playerSide);
            GVAR(playerStartingSide) = playerSide;
        };
        if ((getPlayerUID player) in AUTHORIZED_USERS) then {
            if (!GVAR(playerAuth)) then {
                GVAR(playerAuth) = true;
                diag_log text format ["[POTATO-core]: Player UID [%1] in admin list", getPlayerUID player];
            };
        };
        if ((getPlayerUID player) in TECH_USERS) then {
            if (!GVAR(playerTech)) then {
                GVAR(playerTech) = true;
                diag_log text format ["[POTATO-core]: Player UID [%1] in tech list", getPlayerUID player];
            };
        };
    }, true] call CBA_fnc_addPlayerEventHandler;


    // Cleanup chat
    addMissionEventHandler ["HandleChatMessage", {
        if (missionNamespace getVariable [QGVAR(skipChatHandler), false]) exitWith {}; // way to disable system if it causes problem with a mission
        params ["_channel", "_owner", "_from", "_text", "_person", "_name", "_strID", "_forcedDisplay", "_isPlayerMessage", "_sentenceType", "_chatMessageType", "_chatComposition"];
        INFO_1("ChatMessage: %1",_this);
        private _returnValue = nil;
        // Block player messages, not on breifing, who are not spectators
        if ((isPlayer _person) && {CBA_missionTime > 0} && {getNumber (configOf _person >> "isPlayableLogic") != 1}) then {
            if (_sentenceType == 0) exitWith {}; // probably a scripted `globalChat` or `sideChat` message
            if ((_text select [0,5]) == "force") then {
                // _returnValue = _text select [5]; // optionally clean up text
            } else {
                INFO_2("hiding player chat [%1: %2]",_name,_text);
                _returnValue = true; // block
                if (_person == player) then {
                    // Chats from inside the EH don't seem to trigger the EH but they say not to
                    [{
                        systemChat "POTATO [Your message was blocked, to send in channel start with 'force']";
                        systemChat "POTATO [Use admin message (hit escape) for help with Problems/JIP]";
                    }] call CBA_fnc_execNextFrame;
                };
            };
          } else {
                if ((_channel == 16) && {GVAR(hideSystemPlayerConnecting)} && {_chatComposition isNotEqualTo []} && {
                    _chatComposition params ["_stringID"];
                    (toLower _stringID) in ["$str_mp_connecting", "$str_mp_connect", "$str_mp_connection_loosing", "$str_mp_disconnect"]
                }) then {
                    INFO_1("hiding connection info [%1]",_chatComposition);
                    _returnValue = true;
                };
          };
          _returnValue // don't use exitWith in eh
    }];
};

["potato_adminMsg", {
    params ["_msg", ["_from", "?"], ["_to", ""]];
    if (hasInterface) then {
        if ((_to == profileName) || {_to == "#ALL"} || {(GVAR(showNotifcations)) && {[] call FUNC(isAuthorized)}}) then {
            systemChat format ["POTATO [%1>%2]: %3", _from, _to, _msg];
        };
    };
    if (isServer) then {
        diag_log text format ["[POTATO] potato_adminMsg EH: %1", _this];
    };
}] call CBA_fnc_addEventHandler;

["potato_missionHint", {
    //side is 0-dead, 1-dead+alive or actuall side like east/west
    params ["_msg", ["_side", 1, [sideEnemy, 0]], ["_rankMin", 0]];
    TRACE_3("potato_missionHint eh",_msg,_side,_rankMin);
    if (hasInterface) then {
        if ((_side isEqualTo 1) || {(!alive player) && {_side isEqualTo 0}} || {_side isEqualTo GVAR(playerStartingSide)}) then {
            private _playerRank = if (alive player) then {rankId player} else {999};
            if (_playerRank >= _rankMin) then {
                hint _msg;
            };
        };
    };
    if (isServer) then {
        diag_log text format ["[POTATO] potato_missionHint EH: %1", _this];
    };
}] call CBA_fnc_addEventHandler;

call FUNC(playerJipHint);
