#include "script_component.hpp"

GVAR(playerStartingSide) = sideUnknown;
GVAR(playerDataHash) = [[],[]];
GVAR(openEndMission) = false;

if (isServer) then {
    TRACE_1("Setting up Server EHs", time);

    GVAR(playerIsAuthorized) = true;
    GVAR(zeusCenter) = createCenter sideLogic;

    // ["pabstOnPlayerConnect", "onPlayerConnected", {
        // GVAR(playerDataHash) params ["_dataUIDS", "_dataArray"];
        // _index = _dataUIDS find _uid;
        // TRACE_4("Connect", _uid, _name, _jip, _index);

        // if (_index == -1) then {
            // _index = _dataUIDS pushBack _uid;
            // _dataArray set [_index, [true, _name, _owner, _jip, []]];
        // } else {
            // (_dataArray select _index) set [0, true];
            // (_dataArray select _index) set [3, _jip];
        // };

        // GVAR(playerOwnerID) = _owner;
        // _owner publicVariableClient QGVAR(playerOwnerID);
        // if (_uid in AUTHORIZED_USERS) then {
            // _owner publicVariableClient QGVAR(playerIsAuthorized);
        // };
    // }] call BIS_fnc_addStackedEventHandler;

    // addMissionEventHandler ["HandleDisconnect", {
        // params ["_unit", "", "_uid", "_name"];
        // GVAR(playerDataHash) params ["_dataUIDS", "_dataArray"];
        // _index = _dataUIDS find _uid;
        // TRACE_4("DC", _unit, _uid, _name, _index);

        // if (_index == -1) exitWith {};
        // (_dataArray select _index) set [0, false];
        // if (!isNull _unit) then {
            // _group = group _unit;
            // _unitClassname = typeOf _unit;
            // _loadout = _unit getVariable ["F_Gear", _unitClassname];
            // (_dataArray select _index) set [4, [_group, _unitClassname]];
        // };
    // }];
};

if (hasInterface) then {
    ["playerChanged", {
        if (isNull ace_player) exitWith {};
        if (GVAR(playerStartingSide) isEqualTo sideUnknown) then {
            TRACE_1("Setting start playerside",playerSide);
            GVAR(playerStartingSide) = playerSide;
        };
    }] call ace_common_fnc_addEventHandler;

    ["potato_adminMsg", {
        params ["_msg", ["_from", "?"], ["_forceShow", false]];
        if (_forceShow || {(GVAR(showNotifcations)) && {[] call FUNC(isAuthorized)}}) then {
            systemChat format ["POTATO [%1]: %2", _from, _msg];
        };
    }] call ace_common_fnc_addEventHandler;
};
