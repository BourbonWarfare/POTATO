/*
 * Author: AACO
 * Adds a group to the master array and sends the update out to all the registered clients
 *
 * Arguments:
 * 0: Faction data lookup <STRING>
 * 1: Group data lookup <STRING>
 * 2: Config data lookup <STRING>
 * 3: Config marker text <STRING>
 * 4: Config marker color <ARRAY>
 * 5: Config marker texture <STRING>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * ['blu_f', 'PlatoonLead', 'OnePlt', '1Plt', [1,1,1,1], '/A3/path/texture.paa'] call potato_respawn_fnc_addGroup;
 *
 * Public: No
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

(GVAR(factionsToInfo) get _factionData) params [
    "_factionDisplayName",
    "",
    "",
    "_factionPrefix"
];

(GVAR(groupsToInfo) get _groupData) params [
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
