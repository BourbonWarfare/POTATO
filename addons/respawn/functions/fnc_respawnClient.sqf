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

// validate
if (isNull _group) exitWith { WARNING("Respawn group null, exiting"); };
if (_unitType == "") exitWith { WARNING("Respawn unit type empty, exiting"); };

// store the player pre-switch
private _oldUnit = player;

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
    _newUnits setVariable [QEGVAR(markers, addMarker), true, true];
    _newUnits setVariable [QEGVAR(markers, markerText), "M", true];
    _newUnits setVariable [QEGVAR(markers, markerTexture), "\A3\ui_f\data\map\markers\nato\b_med.paa", true];
    _newUnits setVariable [QEGVAR(markers, markerColor), [1,0.753,0.796,1], true];
    _newUnits setVariable [QEGVAR(markers, markerSize), 16, true];
};

// do the swap
selectPlayer _newUnit;
[_newUnit] joinSilent _group;
deleteGroup _tempGroup;

// if the unit is the leader, force the selection
if (_isLeader) then {
    _group selectLeader _newUnit;
};

// if the old unit was a spectator, remove it
if (typeOf _oldUnit == QEGVAR(spectate,spectator)) then {
    deleteVehicle _oldUnit;
};

// assign the unit's color team
_newUnit assignTeam _colorTeam;
