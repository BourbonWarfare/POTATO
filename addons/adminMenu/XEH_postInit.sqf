#include "script_component.hpp"

[QGVAR(resetGear), {
    params ["_unit"];
    diag_log text format ["[POTATO] Reseting Gear on %1 [%2]", (name _unit), _unit];
    if ((isNull _unit) || {!alive _unit} || {!local _unit}) exitWith {};

    removeAllWeapons _unit;
    removeGoggles _unit;
    removeHeadgear _unit;
    removeVest _unit;
    removeUniform _unit;
    removeAllAssignedItems _unit;
    removeBackpack _unit;

    [{
        diag_log text format ["[POTATO] Calling F_fnc_assignGearMan"];
        _this call F_fnc_assignGearMan;
    }, [_unit], 0.5] call ACEFUNC(common,waitAndExecute);
}] call ACEFUNC(common,addEventHandler);


// GVAR(playerDataHash) = [[],[]];
GVAR(openEndMission) = false;

if (isServer) then {
    TRACE_1("Setting up Server EHs", time);
    GVAR(zeusCenter) = createCenter sideLogic;

    // GVAR(playerIsAuthorized) = true;

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
