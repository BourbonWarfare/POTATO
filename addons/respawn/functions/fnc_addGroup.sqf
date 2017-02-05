/*
 * Author: AACO
 * desc
 *
 * Arguments:
 * Nothing
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_;
 */

#include "script_component.hpp"
TRACE_1("params",_this);

// if we're not on the server, pass to the server
if !(isServer) exitWith {
    _this remoteExecCall [QFUNC(addGroup), SERVER_CLIENT_ID];
};

params [
    "_factionData",
    "_groupData",
    "_configData",
    "_configText",
    "_configColor",
    "_configTexture"
];

if (!isNil QGVAR(currentFaction) && {GVAR(currentFaction) != _factionData}) then {
    [] call FUNC(resetGroupInfo);
};
GVAR(currentFaction) = _factionData;

(GVAR(factionsToInfo) getVariable _factionData) params [
    "_factionDisplayName",
    "",
    "",
    "_factionPrefix"
];

(GVAR(groupsToInfo) getVariable _groupData) params [
    "_groupDisplayName",
    "_unitsArray"
];

private _newUnits = [];
{
    _x params [
        "_unitData",
        "_unitDisplayName",
        "_unitType"
    ];

    _newUnits pushBack [
        _unitData,
        _unitDisplayName,
        _factionPrefix + _unitType,
        objNull
    ];
} forEach _unitsArray;

private _newGroup = [
    _factionData,
    _factionDisplayName,
    _groupData,
    _groupDisplayName,
    _configData,
    _configText,
    _configColor,
    _configTexture,
    _newUnits
];

GVAR(activeGroups) pushBack _newGroup;
_newGroup remoteExecCall [QFUNC(addGroupClient), GVAR(registeredClients)];
