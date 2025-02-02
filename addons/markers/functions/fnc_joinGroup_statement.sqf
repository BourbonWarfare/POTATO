#include "..\script_component.hpp"
/*
 * Author: Lambda.Tiger
 * This function will join a player silently to another and
 * drop any marker they had before leaving
 *
 * Arguments:
 * ACE action args
 *
 * Example:
 * [ACE action args] call potato_markers_fnc_joinGroup_statement;
 *
 * Public: No
 */
private _hashKey = groupId group _player;
[_player] joinSilent group _target;

if (!GVAR(groupAndUnitEnabled)) exitWith {};
private _markerArray = GVAR(markerHash) getOrDefault [_hashKey, [objNull]];
if (_markerArray#0 == _player && _hashKey != "") then {
    [_hashKey] remoteExecCall [QFUNC(transferMarker)];
};

