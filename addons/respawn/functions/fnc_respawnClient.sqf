/*
 * Author: AACO
 * desc
 *
 * Arguments:
 * 0: Group <GROUP>
 *
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call potato_respawn_fnc_respawnClient;
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

// store the player pre-switch
private _oldUnit = player;

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
private _newUnit = _tempGroup createUnit [_unitType, _position, [], 75, "NONE"];

// set new unit rank, fix rating
_newUnit setRank _rank;
_newUnit addRating (25000 - (rating _newUnit));

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

// if the unit is the leader, force the selection
if (_isLeader) then {
    _group selectLeader _newUnit;
};

// assign the unit's color team
_newUnit assignTeam _colorTeam;
