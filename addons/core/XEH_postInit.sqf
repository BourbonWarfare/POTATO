#include "script_component.hpp"

GVAR(playerStartingSide) = sideUnknown;

if (hasInterface) then {
    ["playerChanged", {
        if (isNull ace_player) exitWith {};
        if (GVAR(playerStartingSide) isEqualTo sideUnknown) then {
            TRACE_1("Setting start playerside",playerSide);
            GVAR(playerStartingSide) = playerSide;
        };
    }] call ace_common_fnc_addEventHandler;
};

if (hasInterface && {alive player}) then {
    private _test = [player] call FUNC(isAuthorized);
    diag_log text format ["[POTATO]: Player [%1]: Auth Test: %2 ", player, _test];
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
}] call ace_common_fnc_addEventHandler;

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
}] call ace_common_fnc_addEventHandler;
