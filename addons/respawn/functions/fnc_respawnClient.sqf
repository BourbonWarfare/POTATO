/*
 * Author: AACO
 * Respawns a player with the configuration given from the server.
 *
 * Arguments:
 * 0: Group <GROUP>
 * 1: Unit classname <STRING>
 * 2: Unit position <ARRAY>
 * 3: Color team to join <STRING>
 * 4: Rank of the unit <STRING>
 * 5: Is the unit a group leader <BOOL>
 * 6: Is the unit a medic <BOOL>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [createGroup west, 'b_soldier_f', [0,0,0], 'MAIN', 'private', false, false] call potato_respawn_fnc_respawnClient;
 *
 * Public: No
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"
TRACE_1("params",_this);

params [
    ["_group", grpNull, [grpNull]],
    ["_unitType", "", [""]],
    ["_position", [0,0,0], [[]]],
    ["_colorTeam", "MAIN", [""]],
    ["_rank", "private", [""]],
    ["_isLeader", false, [false]],
    ["_isMedic", false, [false]]
];

// make sure respawn is closed
[] call FUNC(closeClientRespawn);

// store the player pre-switch
private _oldUnit = player;
private _zeusModule = getAssignedCuratorLogic _oldUnit;

// validate
if (isNull _group) exitWith { WARNING("Respawn group null, exiting"); };
if (_unitType == "" || {!isClass (configFile >> "CfgVehicles" >> _unitType)}) exitWith { WARNING("Respawn unit type empty/invalid, exiting"); };
if !(_oldUnit isKindOf QEGVAR(spectate,spectator)) exitWith { WARNING("Trying to respawn non spectator"); };

// kill spectator
if (EGVAR(spectate,running)) then {
    [] call EFUNC(spectate,exit);
};

// create temp group and new unit
private _tempGroup = createGroup (side _group);
private _newUnit = _tempGroup createUnit [_unitType, _position, [], 0, "NONE"];

// if unit is medic add marker attributes
if (_isMedic) then {
    _newUnit setVariable [QEGVAR(markers,addMarker), true, true];
    _newUnit setVariable [QEGVAR(markers,markerText), "M", true];
    _newUnit setVariable [QEGVAR(markers,markerTexture), QPATHTOEF(markers,data\medical.paa), true];
    _newUnit setVariable [QEGVAR(markers,markerColor), [1,0.753,0.796,1], true];
    _newUnit setVariable [QEGVAR(markers,markerSize), 16, true];
};

// do the swap
selectPlayer _newUnit;
[_newUnit] joinSilent _group;
deleteGroup _tempGroup;

// if the old unit was a spectator, remove it
if (typeOf _oldUnit == QEGVAR(spectate,spectator)) then {
    deleteVehicle _oldUnit;
};

// clean out possibly cached names
[_newUnit] call ACEFUNC(common,setName);
_newUnit setVariable [QEGVAR(spectate,cachedNamed), nil, true];

// transfer zeus if spectator had it
if !(isNull _zeusModule) then {
    [_newUnit, _zeusModule] remoteExec [QEFUNC(spectate,transferZeus), SERVER_CLIENT_ID];
};

// do anything else that needs a delay
[_newUnit, _group, _rank, _isLeader] spawn {
    sleep 10;
    // validate objects
    params [
        ["_newUnit", objNull, [objNull]],
        ["_group", grpNull, [grpNull]],
        ["_rank", "private", [""]],
        ["_isLeader", false, [false],
        ["_colorTeam", "MAIN", [""]]
    ];
    if (isNull _newUnit || isNull _group) exitWith { WARNING("Group or unit null on delayed execution"); };

    // if the unit is the leader, force the selection
    if (_isLeader) then {
        _group selectLeader _newUnit;
    };

    // set new unit rank, fix rating
    _newUnit setRank _rank; // note setRank will be EG in 1.68
    _newUnit addRating (25000 - (rating _newUnit));

    // assign the unit's color team
    _newUnit assignTeam _colorTeam;
};
